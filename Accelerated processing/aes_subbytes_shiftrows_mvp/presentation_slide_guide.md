# Slide Guide for SubBytes + ShiftRows Section

This guide is for **your section only**.

It assumes the presentation already includes:

- a general AES overview
- what the four AES round steps are
- some wider project motivation
- the separate note about the long serial chain / decrypt-side parallelization

So this section should now focus on:

- what *you* implemented
- what the FPGA report showed
- what you changed
- what improved

## Recommended length

Aim for **4 to 5 slides** for your section.

That is enough to show real engineering work without repeating the AES theory
slides the audience has already seen.

## Slide 1: My scope and why these steps matter

### Title

`My Contribution: SubBytes and ShiftRows`

### Goal of this slide

Set the scope clearly and avoid repeating too much AES background.

### What to put on the slide

- one short line:
  - `Focus: SubBytes + ShiftRows`
- one short line:
  - `Goal: improve throughput while keeping FPGA resource use reasonable`
- 3 bullets:
  - `SubBytes = nonlinear byte lookup through the AES S-box`
  - `ShiftRows = byte permutation / row rotation`
  - `Good FPGA target because it mixes lookup cost with data-movement cost`

### What to say

"My part focused on the first two AES round steps: SubBytes and ShiftRows.
SubBytes is the nonlinear lookup-heavy part, while ShiftRows is mainly data
movement. That made this a good small study for understanding how the FPGA
compiler handles lookup, memory access, and pipeline structure."

### Visual

Best option:
- a simple custom diagram of a 4x4 AES state with arrows showing row shifts

Do **not** use a complicated report diagram here.

## Slide 2: Naive baseline implementation

### Title

`Naive Baseline`

### Goal of this slide

Show the starting point before optimization.

### What to put on the slide

Left side:
- one short code snippet or pseudocode:
  - `SubBytes over 16 bytes`
  - temporary buffer
  - `ShiftRows`

Right side:
- your screenshots of:
  - `Kernel Summary`
  - `Clock Frequency Summary`
  - `Compile Estimated Kernel Resource Utilization Summary`

If needed, crop them tightly rather than putting the full browser page on the
slide.

### Numbers to include

- baseline emulator: `1.19 ms`
- baseline resources:
  - `1402 ALMs`
  - `2805 ALUTs`
  - `6523 FFs`
  - `8 MLABs`
  - `35 RAMs`

### What to say

"We started from a straightforward implementation of SubBytes followed by
ShiftRows. This gave us a clean baseline. The baseline already compiled and
produced a sensible FPGA report, so we could use it as a reference point for
later changes."

### Visual note

The screenshots you already have are exactly right for this slide.

## Slide 3: What matters in the report

### Title

`What We Measured on FPGA`

### Goal of this slide

Very briefly explain how you judged improvement.

### What to put on the slide

A 3-part bullet list:

- `II (initiation interval): how often new work can enter the pipeline`
- `Resource use: ALMs / ALUTs / FFs / RAMs / MLABs`
- `Pipelined loops and bottlenecks`

Then include your **Loop Analysis** screenshot for the optimized version or the
baseline version, whichever is clearer.

### What to say

"For FPGA, the important question is not just whether the code runs. We also
care about how the compiler schedules it into hardware.

The main metrics we used were initiation interval, which affects throughput,
resource usage, which tells us the hardware cost, and the report bottlenecks,
which explain why a design is or is not pipelining well."

### Use the loop screenshot you just showed me

That screenshot is a good one because it shows:

- `B1`: outer block loop, pipelined, `II = 1`
- `B3`: local load loop, pipelined, `II = 1`
- `B5`: fused compute/store loop, pipelined, `II = 1`

### One sentence to say directly from that screenshot

"In the final version, the important loops were all pipelined and scheduled at
II equal to 1, which is exactly what we want for throughput."

## Slide 4: Optimization attempts

### Title

`What We Tried`

### Goal of this slide

Show that you did not just get one result by luck. You explored alternatives
and learned from the failed ones.

### Best format

Use a simple comparison table that **you make yourself** in PowerPoint, not a
report screenshot.

### Suggested table

| Version | Emulator | Area trend | Pipeline result | Verdict |
| --- | --- | --- | --- | --- |
| Naive baseline | 1.19 ms | baseline | healthy | reference |
| Inner loops unrolled | 0.043 ms | much larger | worse II | bad trade-off |
| Direct fusion | 0.0385 ms | smaller | `II ~ 95` | bad trade-off |
| Buffered fused | 0.0445 ms | smaller than baseline | `II = 1` loops | best |

### What to say

"We tried three main versions.

First, naive unrolling looked attractive because it made the emulator much
faster, but the report showed much worse FPGA behavior and much higher area.

Second, direct fusion of SubBytes and ShiftRows reduced area, but created a
load/store dependency that destroyed the schedule.

Third, buffering one AES state locally before the fused transform gave the best
overall result."

### Important message

This is one of your strongest slides.

It shows:

- experimentation
- engineering reasoning
- real FPGA trade-off analysis

## Slide 5: Best final result

### Title

`Best Result: Buffered Fused Design`

### Goal of this slide

Finish your section with the clearest improvement story.

### What to put on the slide

Left side:
- a simple 3-box custom diagram:
  - `Load state`
  - `Fused SubBytes + ShiftRows`
  - `Store output`

Right side:
- final result bullets:
  - `0.0445 ms emulator`
  - `1189 ALMs`
  - `2378 ALUTs`
  - `5675 FFs`
  - `26 RAMs`
  - `8 MLABs`
  - `Hyper-Optimized Handshaking: On`
  - `key loops pipelined at II = 1`

### What to say

"The best result came from restructuring memory access rather than simply adding
more unrolling. We loaded one AES state into local storage, performed the fused
SubBytes and ShiftRows transform, and then wrote it back out. This reduced area
compared with the naive baseline while preserving a healthy pipeline."

### Final one-line takeaway

"The best FPGA optimization was the one that improved the memory and pipeline
structure, not the one that looked most aggressive in source code."

## Optional slide 6: Transition to partner or overall conclusion

### Title

`Takeaway for the Full AES Project`

### Purpose

Only use this if you need a transition slide before your partner speaks.

### What to put

- `SubBytes + ShiftRows: best result came from pipeline-friendly restructuring`
- `MixColumns + AddRoundKey: partner explores the second half`
- `Together: full AES acceleration is a throughput vs area problem`

### What to say

"For the first half of the AES round, the biggest lesson was that the best
optimization came from preserving a good pipeline. My partner will now show how
the second half behaves."

## Which screenshots to use

### Definitely use

1. `Kernel Summary`
2. `Clock Frequency Summary`
3. `Compile Estimated Kernel Resource Utilization Summary`
4. `Loop Analysis` for the final optimized version

### Probably do not use

- raw `System Viewer` tree screenshots
- very dense cluster diagrams
- report pages with too many compiler block names

Those are usually too low-level for a short talk.

## If you want one report diagram

If you really want one more technical visual from the report, use:

- `Schedule Viewer`

Why:

- it is better for showing pipeline/scheduling ideas
- it is more relevant to your final story than the raw system tree

If you try `System Viewer 2.0`, only use it if you can crop it to a very small
and understandable region. Otherwise it will look like compiler noise.

## Best visual alternative to the report diagrams

The best visual is probably not from the report at all.

Make your own simple diagram with three boxes:

```text
Global memory load -> local state buffer -> fused SubBytes + ShiftRows -> store
```

That is easier for the audience to understand than a compiler-generated block
diagram.

## Suggested order of your spoken section

1. scope
2. naive baseline
3. what metrics mattered
4. failed attempts
5. final best version
6. takeaway

## Time split

If you have about 4 minutes:

- Slide 1: 30 sec
- Slide 2: 45 sec
- Slide 3: 40 sec
- Slide 4: 70 sec
- Slide 5: 55 sec
- transition: 20 sec

## Most important sentence in your whole section

If you only remember one line, use this:

"For SubBytes and ShiftRows, the best result came from restructuring memory
access so the FPGA compiler could keep the pipeline healthy, rather than from
simply unrolling more work."
