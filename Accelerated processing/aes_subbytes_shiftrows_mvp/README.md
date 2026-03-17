# AES SubBytes + ShiftRows Naive Baseline

This folder is a minimal FPGA-focused AES project derived from the working
`fpga_template` flow. The goal is not to implement full AES yet. The goal is to
get a real `make report` flow working on code that matches the project topic:
the first two AES round steps, `SubBytes` and `ShiftRows`.

## Why Docker / oneAPI are used

- The Docker image gives a repeatable Linux environment with Intel oneAPI and
  the FPGA compiler installed.
- `make fpga_emu` is useful for correctness checks.
- `make report` generates the optimization report and RTL without needing a real
  FPGA board attached.
- The report is where we inspect initiation interval, throughput-oriented
  structure, loops, and resource trade-offs.

## What this baseline does

- Processes many independent 16-byte AES states in a single FPGA kernel.
- Applies `SubBytes` using the AES S-box.
- Applies `ShiftRows` using AES row rotations.
- Uses straightforward nested loops inside the kernel.
- Does not request a specific initiation interval.
- Does not apply explicit loop unrolling or other FPGA tuning hints.

This is closer to `CTR` style parallelism than `CBC` encryption, because each
block in the MVP is independent. That is intentional for the first milestone:
it gives us something measurable and easy to reason about in the FPGA report.

## Why the `q.single_task(...)` line matters

In the original template, the important line was:

```cpp
q.single_task<VectorAddID>(VectorAdd{a, b, c, kVectSize}).wait();
```

That line launches the FPGA kernel. The code inside the functor's
`operator()()` is what the compiler turns into hardware and what appears in the
report.

In this MVP, the equivalent line is:

```cpp
q.single_task<AesSubBytesShiftRowsID>(
    AesSubBytesShiftRowsKernel{input, output, kBlockCount});
```

So yes: that kernel launch is the key handoff from host code to synthesized
FPGA hardware.

## Files

- `src/aes_subbytes_shiftrows.cpp`: host code plus the FPGA kernel.
- `include/exception_handler.hpp`: small SYCL async exception helper.
- `CMakeLists.txt`: reused FPGA build flow from Intel's template.

## Build inside Docker

From `Accelerated processing` on the Windows host:

```powershell
docker build -t oneapi-fpga-dev:2025 .
docker run --rm -it `
  -v "${PWD}:/workspaces/accelerated-processing" `
  -w /workspaces/accelerated-processing `
  oneapi-fpga-dev:2025 bash
```

Inside the container:

```bash
source /opt/intel/oneapi/setvars.sh --force
cd aes_subbytes_shiftrows_mvp
rm -rf build
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make fpga_emu
./aes_subbytes_shiftrows.fpga_emu
make report
```

The report will be generated at:

```text
aes_subbytes_shiftrows_mvp/build/aes_subbytes_shiftrows.report.prj/reports/report.html
```

## Reading the report for this project

For this MVP, the most relevant report questions are:

- What initiation interval did the compiler achieve for the outer block loop?
- How was the S-box implemented: as ROM / lookup structure?
- What resources grow when we replicate work over many blocks?
- How does the report describe throughput versus single-state latency?

## How to talk about speed at this stage

There are two different "speed" numbers here:

- `fpga_emu` timing: useful for a baseline correctness run and a rough software
  smoke test, but not representative of real FPGA hardware.
- `make report`: the right place to inspect expected FPGA throughput, loop II,
  and structural bottlenecks.

So for the baseline write-up:

- Document the emulator timing as a baseline run result.
- Use the report to discuss FPGA-oriented speed characteristics.
- Do not claim emulator timing is the final FPGA performance number.

## Current baseline status

- Baseline kernel: implemented and verified against a CPU reference.
- `make fpga_emu`: passes.
- `make report`: passes.
- Emulator baseline on 4096 AES states: about `1.19 ms`, which is about
  `3.44e6 states/s` or `52.4 MiB/s` on the emulator target.
- Report summary: kernel estimated at `2805 ALUTs`, `6523 FFs`, `35 RAMs`, and
  `8 MLABs` before global interconnect is added.
- Report loop view: the outer block loop is pipelined, but the bottleneck view
  flags control dependency / loop feedback as the main occupancy limiter in the
  naive version.
- Next optimization step: inspect the report, identify the slowest loop /
  bottleneck, then make one targeted improvement and compare before/after.

## Natural next steps

1. Record the baseline emulator timing and report observations.
2. Try one improvement at a time, for example loop unrolling or a pipelining hint.
3. Compare the new report against the naive baseline and document what changed.
4. Add `MixColumns` and then `AddRoundKey` after the first comparison loop is working.
