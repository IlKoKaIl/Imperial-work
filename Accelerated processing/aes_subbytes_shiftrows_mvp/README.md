# AES SubBytes + ShiftRows Naive Baseline

This folder is a minimal FPGA-focused AES project derived from the working
`fpga_template` flow. The goal is not to implement full AES yet. The goal is to
get a real `make report` flow working on code that matches the project topic:
the first two AES round steps, `SubBytes` and `ShiftRows`.

## AES at a high level

AES is a symmetric block cipher that operates on a 128-bit state, usually shown
as a `4 x 4` matrix of bytes. For AES-256, encryption uses a 256-bit key and a
sequence of rounds that repeatedly transform the state.

At a high level, a normal AES round applies four steps:

1. `SubBytes`: replace each byte using a fixed substitution table called the
   S-box.
2. `ShiftRows`: rotate each row of the state by a different byte offset.
3. `MixColumns`: combine bytes within each column using finite-field
   arithmetic.
4. `AddRoundKey`: XOR the state with the round key.

In the full project, the group is covering all four steps. This MVP focuses on
the first two steps only, so we can establish a baseline and understand how the
FPGA compiler maps them into hardware before adding the rest of the round.

## Scope of this part of the project

This part of the project covers:

- `SubBytes`
- `ShiftRows`

Why these two are a sensible first slice:

- `SubBytes` is the more logic-heavy step here because it performs byte-wise
  lookup through the AES S-box.
- `ShiftRows` is mostly data reordering, so it is useful for understanding the
  cost of movement versus lookup.
- Together they already let us study loop structure, throughput, initiation
  interval, and resource usage in the report.

The other two steps, `MixColumns` and `AddRoundKey`, can be added later by the
full group implementation and compared against this baseline.

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

In plain terms:

- `fpga_emu` tells you how fast the emulated version runs on the host-side
  emulator target. It is useful for checking correctness and for a rough
  "did this code change make the emulated run faster?" comparison.
- `make report` tells you what kind of FPGA hardware the compiler thinks it
  would build: how much hardware it needs, how well the loops pipeline, what II
  it can achieve, and what structural bottlenecks are limiting throughput.

So for the baseline write-up:

- Document the emulator timing as a baseline run result.
- Use the report to discuss FPGA-oriented speed characteristics.
- Do not claim emulator timing is the final FPGA performance number.

## Latency, throughput, and II

These three ideas are related but not the same:

- `Latency`: how long one AES state takes to go from input to output
- `Throughput`: how often completed AES states come out
- `II` (initiation interval): how many clock cycles pass before the pipeline can
  accept a new loop iteration

A helpful analogy is a laundry pipeline:

- washing, drying, and folding are different stages
- latency is the total time for one batch to go all the way through
- throughput is how often a finished batch comes out
- pipelining means loading a new batch into the washer while the previous batch
  is already drying

For FPGA loops, lower `II` usually means better throughput:

- `II = 1`: a new iteration can start every clock cycle
- `II = 2`: a new iteration can start every 2 cycles
- `II = 69`: a new iteration can start every 69 cycles

So a low `II` is usually what we want for throughput-oriented designs.

However, lower `II` is not automatically "best" in every situation. A lower II
may require much more hardware, may reduce clock quality, or may fail to scale
well because of memory dependencies. The real goal is a good trade-off:

- low enough `II` for strong throughput
- acceptable hardware cost
- no major new bottlenecks

That is why this project compares `II` together with resource usage, rather
than treating either one in isolation.

## Where the baseline report numbers came from

The baseline report numbers can be read directly from the generated HTML report,
but they can also be extracted from the report's generated JSON / NDJSON files.

The numbers currently recorded for the naive baseline came from the report's
`Kernel Summary` and `Estimated Resource Usage` output:

- `1402 ALMs`
- `2805 ALUTs`
- `6523 FFs`
- `8 MLABs`
- `35 RAMs`

If you open the HTML report, these show up in the summary / estimated resource
usage section. Programmatically, they also exist in:

```text
build/aes_subbytes_shiftrows.report.prj/reports/resources/json/summary.ndjson
```

That is how they were gathered previously. So yes, normally you can just open
the HTML page and read them there.

## How to read the three resource rows

The `Compile Estimated Kernel Resource Utilization Summary` usually shows three
rows for this design:

1. `Global interconnect`
   This is compiler-generated infrastructure that helps connect the kernel to
   memory and the rest of the generated system. It does not map to a line in
   our source code, so it has no source location.
2. `AesSubBytesShiftRowsID`
   This is the main kernel row. It maps directly back to
   `aes_subbytes_shiftrows.cpp:86`, so this is the row we should mainly compare
   when judging whether our code changes made the kernel itself bigger or
   smaller.
3. `Compile Estimated: Kernel System`
   This is the total estimated system cost, which is roughly the kernel row
   plus interconnect overhead.

So for presentation and before/after comparisons:

- use `AesSubBytesShiftRowsID` as the main per-kernel comparison row
- mention `Kernel System` if you want the full design total
- treat `Global interconnect` as supporting overhead, not the main story

The percentages in the `Area Estimates` page are still useful, but in this
project they stay below `1%` because the target FPGA is large relative to our
small MVP. That does **not** mean the optimization had no cost. The important
thing is the relative change:

- ALMs went from `1402` to `2950`
- ALUTs went from `2805` to `5901`
- FFs went from `6523` to `11521`
- MLABs went from `8` to `31`

So even though both versions still show `<1%` of the whole device, the unrolled
version clearly consumes much more hardware than the naive baseline.

## What the resource names mean

These names are FPGA hardware resource categories:

- `ALMs`: adaptive logic modules, the device's coarse logic building blocks
- `ALUTs`: lookup-table logic used to implement combinational logic
- `FFs`: flip-flops, used to store values between clock cycles
- `MLABs`: small on-chip memory blocks
- `RAMs`: larger on-chip memory blocks
- `DSPs`: dedicated arithmetic blocks

For this project, the important question is not just "is the percentage small?"
but "did the optimization need much more logic or memory to get its result?"

## Which report views matter most for this work

There are many report views, but for this project the most useful ones are:

1. `Summary`
   Use this for overall resource usage and quick kernel facts.
2. `Loops Analysis`
   Use this to see whether loops are pipelined and what II the compiler reports.
3. `Bottlenecks`
   Use this to identify what is currently limiting throughput or occupancy.
4. `Fmax II Report` / schedule-related loop views
   Use these when comparing before/after optimization to see why II changes.
5. `Area Analysis`
   Use this when an optimization improves throughput but costs more hardware.

For your presentation, these are much more useful than trying to show every
viewer in the report.

## Current baseline status

- Baseline kernel: implemented and verified against a CPU reference.
- `make fpga_emu`: passes.
- `make report`: passes.
- Emulator baseline on 4096 AES states: about `1.19 ms`, which is about
  `3.44e6 states/s` or `52.4 MiB/s` on the emulator target.
- Report summary: kernel estimated at `1402 ALMs`, `2805 ALUTs`, `6523 FFs`,
  `8 MLABs`, and `35 RAMs` before global interconnect is added.
- Report loop view: the outer block loop is pipelined, but the bottleneck view
  flags control dependency / loop feedback as the main occupancy limiter in the
  naive version.
- Next optimization step: inspect the report, identify the slowest loop /
  bottleneck, then make one targeted improvement and compare before/after.

## Improvement 1: unroll the tiny inner loops

### What changed

The first optimization experiment keeps the outer loop over AES states the same,
but adds `#pragma unroll` to the fixed-size inner loops:

- the `SubBytes` loop over 16 bytes
- the `ShiftRows` loop over 4 rows
- the `ShiftRows` loop over 4 columns

This experiment is controlled by the compile flag:

```text
-DAES_UNROLL_INNER_LOOPS
```

Example build:

```bash
cmake .. -DCMAKE_BUILD_TYPE=Release -DUSER_FLAGS=-DAES_UNROLL_INNER_LOOPS
make fpga_emu
make report
```

Or from PowerShell:

```powershell
.\run_aes_subbytes_shiftrows_report.ps1 -UserFlags "-DAES_UNROLL_INNER_LOOPS"
```

### Why this looked promising

These loops have fixed small trip counts, so unrolling is a natural first FPGA
 experiment to try. The idea is to replace loop control with more parallel
 hardware and reduce per-state work.

### What actually happened

The emulator got much faster, but the FPGA report got worse.

| Version | Emulator time | Emulator throughput | ALMs | ALUTs | FFs | MLABs | RAMs | Outer loop II |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Naive baseline | 1.19 ms | 3.44e6 states/s | 1402 | 2805 | 6523 | 8 | 35 | >= 1 |
| Inner loops unrolled | 0.043 ms | 9.52e7 states/s | 2950 | 5901 | 11521 | 31 | 32 | ~69 |

Other report changes:

- Hyper-optimized handshaking changed from `On` to `Off`
- The report now flags memory dependency as the main issue on the outer loop

### Simple interpretation

This is a good example of why the emulator alone is not enough.

- On the emulator, unrolling looked like a big speedup.
- On the FPGA report, unrolling more than doubled logic usage and made the outer
  loop throughput much worse because the compiler introduced a severe memory
  dependency on the feedback path.

So this experiment is useful, but it is **not** a good final optimization for
FPGA throughput. It is still worth documenting because it shows:

1. `#pragma unroll` can help software-style execution
2. the same change can hurt FPGA throughput badly
3. the report is the right place to judge FPGA performance trade-offs

## Improvement 2: direct fusion without buffering

### What changed

The next idea was to fuse `SubBytes` and `ShiftRows` into one loop so that we
could remove the temporary `substituted[16]` array completely:

- take the source byte index implied by `ShiftRows`
- apply the AES S-box immediately
- write directly to output

This is a valid mathematical transformation because `ShiftRows` is only a byte
permutation, so:

```text
ShiftRows(SubBytes(state)) == per-output-byte S-box lookup from a permuted source index
```

This first fusion attempt used a single inner loop that both read global input
and wrote global output directly.

Example build:

```powershell
.\run_aes_subbytes_shiftrows_report.ps1 -UserFlags "-DAES_FUSE_SUBBYTES_SHIFTROWS -DAES_TARGET_OUTER_II_1"
```

### Why it looked promising

This is the kind of structural simplification an FPGA engineer would try early:

- fewer nested loops
- no temporary `substituted` array
- less control overhead
- less obvious intermediate storage

### What actually happened

The result was mixed:

- emulator got even faster: about `0.0385 ms`
- estimated area dropped a lot: `1656 ALUTs`, `4927 FFs`, `10 RAMs`, `17 MLABs`
- but the fused inner loop became the new bottleneck with `II ~ 95`
- hyper-optimized handshaking turned `Off`

Why it failed:

- the compiler now had to do a global load, ROM lookup, pointer computation,
  and global store in the same pipelined loop body
- that created a strong load/store memory dependency on the loop feedback path
- so the loop became small in area but poor for throughput

This is another good project result:

- reducing area alone is not enough
- a structurally "cleaner" expression of the algorithm can still produce a bad
  hardware schedule if memory dependencies get worse

## Improvement 3: buffered fused load-compute-store

### What changed

This version keeps the fused mathematical form, but changes the structure to a
more FPGA-friendly load-compute-store pattern:

1. load one 16-byte AES state from global memory into a local `state[16]`
2. run the fused `SubBytes + ShiftRows` computation using only the local buffer
3. write the final bytes back to global output

This is controlled by:

```text
-DAES_BUFFERED_FUSED_SUBBYTES_SHIFTROWS -DAES_TARGET_OUTER_II_1
```

Example build:

```powershell
.\run_aes_subbytes_shiftrows_report.ps1 -UserFlags "-DAES_BUFFERED_FUSED_SUBBYTES_SHIFTROWS -DAES_TARGET_OUTER_II_1"
```

### Why this is more FPGA-aware

The direct fused version failed because one loop was trying to do:

- global load
- S-box ROM lookup
- global store

all on the same loop-carried path.

Buffering one AES state locally breaks that feedback path into cleaner stages:

- the load loop only reads global memory
- the fused compute loop reads from local state and writes output
- the compiler can pipeline those loops much more effectively

This is a common FPGA pattern: separate off-chip memory access from the core
compute stage when the direct expression creates a bad dependency chain.

### What happened

This version is the best overall result so far.

Emulator result:

- about `0.0445 ms`
- about `9.21e7 states/s`
- about `1406 MiB/s`

Report result:

- `2378 ALUTs`
- `5675 FFs`
- `26 RAMs`
- `8 MLABs`
- hyper-optimized handshaking stayed `On`
- the inner load loop is back to about `II ~ 1`
- the fused compute/store loop is also about `II ~ 1`

The main bottleneck returned to a control dependency on the outer loop, which
is much healthier than the `II ~ 95` memory dependency seen in the direct fused
version.

### Why this is a real improvement

Compared with the naive baseline:

- emulator is much faster
- ALUTs are lower: `2805 -> 2378`
- FFs are lower: `6523 -> 5675`
- RAMs are lower: `35 -> 26`
- MLABs stay the same: `8 -> 8`
- throughput-oriented loop structure remains healthy instead of collapsing

Compared with the failed unroll version:

- area is much lower
- handshaking stays on
- loops stay near `II ~ 1`
- report behavior is much more consistent with a good FPGA implementation

### Comparison table

The report JSON exposes `ALUTs`, `FFs`, `RAMs`, and `MLABs` directly. Earlier
manual notes from the HTML also included `ALMs`, but the automated comparison
below focuses on the resource columns that are consistent across all scripted
runs.

| Version | Emulator time | ALUTs | FFs | RAMs | MLABs | Key loop / bottleneck | Hyper-optimized handshaking |
| --- | --- | --- | --- | --- | --- | --- | --- |
| Naive baseline | 1.19 ms | 2805 | 6523 | 35 | 8 | outer block loop at `II >= 1` | On |
| Inner loops unrolled | 0.043 ms | 5901 | 11521 | 32 | 31 | outer loop degraded to `II ~ 69`, memory dependency | Off |
| Direct fused, no buffering | 0.0385 ms | 1656 | 4927 | 10 | 17 | fused inner loop degraded to `II ~ 95`, memory dependency | Off |
| Buffered fused load-compute-store | 0.0445 ms | 2378 | 5675 | 26 | 8 | inner loops back to `II ~ 1`, outer loop limited mainly by control dependency | On |

### Presentation-ready takeaway

This gives a strong and honest optimization story:

1. `#pragma unroll` made the emulator fast, but harmed the FPGA schedule.
2. direct fusion reduced area, but created a load/store feedback dependency.
3. buffering one AES state locally recovered the pipeline and produced the best
   overall design so far.

That is exactly the kind of FPGA lesson worth presenting:

- not every "simpler" or "more parallel" source change helps hardware
- memory structure matters as much as arithmetic structure
- a good FPGA optimization balances throughput and area instead of chasing only
  one metric

## Natural next steps

1. Record the baseline emulator timing and report observations.
2. Present the three design variants as a short optimization case study:
   naive baseline, failed over-unroll, successful buffered fusion.
3. If time allows, add `MixColumns` and then `AddRoundKey` to extend the full
   round with the same methodology.
4. For the presentation, emphasize that `CTR` mode is more naturally compatible
   with this block-level pipelined structure than `CBC` encryption.
