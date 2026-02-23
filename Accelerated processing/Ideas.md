# Accelerated Processing Project Ideas (1-Month Scope)

## Quick Recommendation
**Pick this unless your supervisor strongly prefers another topic:**

### 1) Streaming FFT Accelerator on Intel FPGA (oneAPI)
**Working title:**  
`Precision vs Throughput Trade-offs in a oneAPI FPGA FFT Accelerator`

**Why this is a strong fit**
- Clear acceleration story: FFT is compute-heavy and hardware-friendly.
- Easy to measure progress weekly: baseline, first kernel, optimized kernel, trade-off analysis.
- Report-friendly: bottlenecks, architecture design, and resource/latency analysis are all natural.
- Realistic in 1 month: bounded scope (single FFT size and controlled design variants).

**Core project scope**
- Implement and profile CPU baseline FFT (e.g., C++/oneMKL or Python baseline for reference).
- Implement FPGA kernel for fixed-size FFT (e.g., 1024-point radix-2 pipeline).
- Explore 2 to 3 design knobs:
  - Data type: `float32` vs fixed-point (for example `Q1.15`/`Q3.13` style).
  - Unroll/pipeline/reuse factors.
  - Batch size or streaming depth.
- Evaluate:
  - Latency per transform.
  - Throughput (transforms/s).
  - Accuracy/error vs CPU reference (MSE/SNR).
  - FPGA resource usage (ALMs, DSPs, BRAM) from compilation reports.

**Suggested weekly plan**
- Week 1:
  - Literature and algorithm review (FFT variants, bottlenecks).
  - CPU baseline implementation + profiling.
  - Initial architecture diagram (paper design).
- Week 2:
  - oneAPI FPGA kernel v1 (correctness first).
  - Validate output against CPU reference.
- Week 3:
  - Optimization pass (pipeline/unroll/memory access improvements).
  - Run at least 2 design variants.
- Week 4:
  - Final experiments and plots.
  - Presentation slides + report draft sections (method, results, discussion).

**Risk management**
- FPGA compile times are long: use emulator for debug, full compile only for stable checkpoints.
- If board access is limited: still complete with emulation + synthesis reports + CPU results.

---

## Strong Alternatives

### 2) AES-CTR/AES-GCM FPGA Pipeline (oneAPI)
**Why choose it**
- Very clean pipeline architecture and straightforward correctness checks.
- Strong latency/throughput metrics and easy comparison to CPU library.

**Scope**
- Baseline CPU AES.
- FPGA kernel with pipelined rounds and loop unrolling.
- Trade-offs: key size/mode, unroll factor, throughput vs resources.

**Risk level:** Low to medium.  
**Learning depth:** Good hardware mapping depth, less algorithmic complexity than FFT/graph.

### 3) Parallel Shortest Path (Delta-Stepping vs Dijkstra) on Multicore or GPU
**Why choose it**
- Strong algorithmic angle and modern relevance.
- Good if you want to focus more on parallel algorithms than FPGA toolchains.

**Scope**
- Implement baseline Dijkstra.
- Implement parallel delta-stepping.
- Compare across graph types/densities and analyze memory bottlenecks.

**Risk level:** Medium.  
**Learning depth:** High algorithmic depth, less direct FPGA architecture content unless you map hardware design on paper only.

---

## What to Avoid for 1 Month (Unless You Already Have Setup)
- Full H.264/MPEG decode acceleration.
- Full ray tracer acceleration.
- End-to-end blockchain proof-of-work system.

These are usually too broad for this module timescale unless heavily narrowed.

---

## Suggested Final Choice
If you want the best balance of **realism + technical depth + clean assessment narrative**, choose:

`Streaming FFT Accelerator on Intel oneAPI FPGA`

This gives you:
- Weekly visible progress.
- A clear hardware architecture story.
- Quantitative results that map directly to report/presentation marking criteria.
