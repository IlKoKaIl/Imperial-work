# AES CTR Full Pipeline Compile Test

This folder is a combined FPGA compile-test project that integrates:

- `SubBytes`
- `ShiftRows`
- `MixColumns`
- `AddRoundKey`

inside a CTR-style streaming kernel.

## What this project is for

This project is intended as a structural full-round FPGA compile test so that
you can:

- check that both halves can live in one design
- run `fpga_emu`
- generate `make report`
- use it as a possible real FPGA compile candidate

## Important limitation

This is **not yet a standards-accurate AES-128 or AES-256 implementation**.

It currently reuses the same 16-byte round key in every round instead of using
a real AES key schedule. So:

- it is useful for FPGA pipeline / compile / integration testing
- it is useful for showing a full four-step structural design
- it should **not** be presented as a final correct AES-256 implementation

If you mention it in the presentation, describe it as:

`a combined full-round structural compile test`

## Current validation status

Validated in Docker:

- `make fpga_emu`: passes
- encrypt + decrypt structural test: `PASSED`
- `make report`: passes

Observed emulator timings on the current build:

- encrypt kernel: about `1.14 ms`
- decrypt kernel: about `0.037 ms`

Current report summary:

- two kernels: encrypt and decrypt
- each kernel estimated at about `31910 ALUTs`, `45448 FFs`, `68 RAMs`,
  `1751 MLABs`
- hyper-optimized handshaking: `Off`

So this combined design is heavier and less cleanly scheduled than the smaller
SubBytes + ShiftRows MVP. That is expected: this full structural compile test is
mainly for integration and possible hardware compilation, not for being the most
optimized design in the repo.

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
cd aes_ctr_full_pipeline_compile_test
rm -rf build
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make fpga_emu
./aes_ctr_full_pipeline_compile_test.fpga_emu
make report
```

The report will be generated at:

```text
aes_ctr_full_pipeline_compile_test/build/aes_ctr_full_pipeline_compile_test.report.prj/reports/report.html
```
