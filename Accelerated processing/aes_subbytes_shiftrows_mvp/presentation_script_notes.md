# AES SubBytes + ShiftRows Presentation Script Notes

## Purpose

These notes are for the presentation script, not for the code itself.
They focus on:

- what AES is doing at a high level
- what `SubBytes` and `ShiftRows` do
- why FPGA acceleration is interesting
- what we implemented
- what the report showed
- what optimization actually helped

## Suggested 10-minute structure

If both of you are presenting, a clean split is:

1. AES overview and motivation
2. Why FPGA and why throughput matters
3. Your half: `SubBytes` + `ShiftRows`
4. Partner's half: `MixColumns` + `AddRoundKey`
5. Optimization results and trade-offs
6. Final takeaway

For your part, aim for about 4 minutes.

## Slide 1: Project overview

### Main message

We studied how AES could be accelerated using FPGA techniques, with attention to
throughput, latency, and resource trade-offs.

### Speaker notes

"Our project looks at accelerating AES encryption using hardware techniques.
We are especially interested in FPGA-style optimization, where performance does
not only depend on arithmetic speed, but also on pipelining, loop structure,
memory access, and hardware resource usage.

We focused mainly on AES-256 and on the trade-off between latency, throughput,
and area. We also kept in mind that AES modes behave differently: CTR is much
more parallel-friendly than CBC because CTR allows independent block
processing."

## Slide 2: AES at a high level

### Main message

AES operates on a 128-bit block represented as a `4 x 4` matrix of bytes.
Each round applies four transformations.

### Speaker notes

"AES works on a 128-bit state, which is usually shown as a 4 by 4 byte matrix.
In a standard round, AES applies four steps:

1. SubBytes
2. ShiftRows
3. MixColumns
4. AddRoundKey

In our group, we split the round into two studies. My part focuses on the first
two steps: SubBytes and ShiftRows. My partner focuses on the second half:
MixColumns and AddRoundKey."

## Slide 3: Theory of SubBytes

### Main message

`SubBytes` is the nonlinear part of the round. Each byte is replaced by a value
from a fixed substitution table called the S-box.

### Speaker notes

"SubBytes takes each byte in the AES state and replaces it using a fixed lookup
table called the S-box.

This step is important because it introduces nonlinearity into AES. That
nonlinearity is a major reason AES is secure.

From a hardware point of view, SubBytes is interesting because it behaves like a
table lookup. On FPGA, that means the compiler may implement it using ROM-like
or memory-style structures rather than pure arithmetic logic."

### Theory bullets for slide

- input: 16 bytes
- output: 16 substituted bytes
- operation type: byte-wise lookup
- hardware concern: how the S-box lookup is implemented and accessed

## Slide 4: Theory of ShiftRows

### Main message

`ShiftRows` is a permutation step. It does not change byte values; it changes
their positions.

### Speaker notes

"ShiftRows rotates each row of the AES state by a different offset.

- row 0 shifts by 0
- row 1 shifts by 1
- row 2 shifts by 2
- row 3 shifts by 3

So unlike SubBytes, ShiftRows is not a lookup-heavy or arithmetic-heavy step.
It is mainly data movement and permutation.

That makes it useful in an FPGA study because it lets us compare the cost of
byte lookup against the cost of data reordering."

### Theory bullets for slide

- no arithmetic change to the byte values
- only rearranges positions
- important for diffusion across the AES round
- hardware concern: indexing, data movement, and pipeline-friendly structure

## Slide 5: How these steps can be sped up

### Main message

The first opportunities for FPGA acceleration come from pipelining, reducing
memory dependencies, and restructuring loops.

### Speaker notes

"At a high level, there are a few ways to speed up a design like this on FPGA.

First, we want pipelining, which means starting new work before previous work
has fully finished.

Second, we want a low initiation interval, or II. II tells us how often a new
loop iteration can begin. An II of 1 is ideal for throughput because it means a
new iteration can start every clock cycle.

Third, we want to avoid harmful memory dependencies. Even if a code change
looks simpler, it can hurt the schedule if it creates a long feedback path
through memory operations.

Finally, we can use more area when it buys useful parallelism, but more area is
only good if it improves the hardware schedule."

### Simple analogy

"A good mental model is a laundry pipeline:

- latency is how long one batch takes from wash to dry to fold
- throughput is how often completed batches come out
- pipelining means loading the next batch into the washer while the previous
  batch is already drying

That is why II matters so much. A lower II means we can feed new work into the
pipeline more frequently."

## Slide 6: Naive baseline implementation

### Main message

The naive baseline implemented `SubBytes` and `ShiftRows` as straightforward
nested loops.

### Speaker notes

"Our baseline was intentionally simple. We used a single-work-item FPGA kernel
that processed many independent AES states.

For each state:

1. run SubBytes over all 16 bytes
2. store the substituted state temporarily
3. run ShiftRows on that temporary state
4. write the final output

This gave us a clean baseline before applying any aggressive FPGA-specific
optimization."

### Baseline numbers

- emulator time: about `1.19 ms`
- resource summary: `1402 ALMs`, `2805 ALUTs`, `6523 FFs`, `8 MLABs`, `35 RAMs`
- outer loop pipelined
- report showed a healthy starting point with no catastrophic II problem

## Slide 7: First failed optimization - unrolling inner loops

### Main message

Naively unrolling the small loops made the emulator much faster, but harmed the
FPGA design.

### Speaker notes

"The first idea was to unroll the small fixed loops, which seems natural on
FPGA because unrolling often creates more parallel hardware.

This made the emulator look much faster, but the report told a different story.
Area increased sharply, hyper-optimized handshaking turned off, and the outer
loop II became much worse.

So this was a good example of why emulator timing alone is not enough for FPGA
evaluation."

### Key numbers

- emulator time: `1.19 ms -> 0.043 ms`
- ALUTs: `2805 -> 5901`
- FFs: `6523 -> 11521`
- MLABs: `8 -> 31`
- outer loop II degraded badly

### Line to say

"This optimization looked good in software-style timing, but it was a poor FPGA
trade-off because it spent much more hardware and made the pipeline schedule
worse."

## Slide 8: Second failed optimization - direct fusion

### Main message

Fusing `SubBytes` and `ShiftRows` without buffering reduced area, but created a
bad load/store dependency.

### Speaker notes

"The next idea was to fuse the two steps mathematically:

- choose the source byte implied by ShiftRows
- apply the S-box immediately
- write straight to output

This looked promising because it removed the temporary substituted array.

But in the report, the fused inner loop became the bottleneck. The compiler had
to perform a global load, a ROM lookup, and a global store in the same loop.
That created a strong memory dependency and the loop II exploded to around 95."

### Main lesson

"So here we learned that reducing area is not enough if the new structure harms
the memory schedule."

## Slide 9: Best optimization - buffered fused design

### Main message

The best variant used a buffered fused load-compute-store pattern.

### Speaker notes

"The successful version kept the fusion idea, but changed the structure.

Instead of directly reading and writing global memory in the same inner loop, we
did this:

1. load one AES state into a local 16-byte buffer
2. perform the fused SubBytes + ShiftRows transform using the local buffer
3. write the result back out

This is more FPGA-aware because it separates off-chip memory access from the
core transform."

### Best result numbers

- emulator time: about `0.0445 ms`
- kernel resources: `1189 ALMs`, `2378 ALUTs`, `5675 FFs`, `8 MLABs`, `26 RAMs`
- hyper-optimized handshaking: `On`
- loops pipelined with `II = 1`

### From your current loop screenshot

These are the most useful lines to mention:

- outer block loop at `aes_subbytes_shiftrows.cpp:100`: pipelined, `II = 1`
- local load loop at `aes_subbytes_shiftrows.cpp:111`: pipelined, `II = 1`
- fused compute/store loop at `aes_subbytes_shiftrows.cpp:115`: pipelined, `II = 1`

### One-line interpretation

"This was the best version because it reduced resource usage compared with the
naive baseline while keeping a healthy pipeline structure."

## Slide 10: What the final result means

### Main message

The main lesson is that FPGA optimization is about balancing throughput and
hardware cost, not maximizing one metric alone.

### Speaker notes

"The biggest lesson from this work is that FPGA optimization is not simply about
making code shorter, or unrolling everything, or using more area.

The best result came from restructuring memory access so that the compiler could
build a better pipeline.

So the real trade-off is:

- throughput
- II
- resource usage
- memory dependency structure

That is why the report was central to the project."

## Short theory summary for your slide bullets

You can condense the theory into these bullets:

- `SubBytes`: byte-wise nonlinear S-box lookup
- `ShiftRows`: row rotation / byte permutation
- acceleration ideas: pipelining, low II, careful memory structure
- FPGA lesson: more hardware is only useful if it improves throughput

## If you get asked "why CTR is easier than CBC?"

Suggested answer:

"CTR mode is easier to parallelize because each block can be processed
independently once the counter values are known. CBC encryption is more serial
because each plaintext block depends on the previous ciphertext block. So CTR is
more naturally compatible with block-level FPGA pipelining and parallel block
processing."

## If you get asked "what does II mean?"

Suggested answer:

"II, or initiation interval, is how many clock cycles pass before a new loop
iteration can begin. A lower II generally means better throughput. An II of 1
means the pipeline can start new work every cycle."

## Is it worth compiling on a real FPGA with only half the AES round?

Short answer: yes, it can still be useful, but only if it is easy to do.

### Why it is useful

- it gives stronger evidence than report-only analysis
- you may get fitter-backed results and possibly real device execution
- it still works as a valid microbenchmark for the first two AES round steps

### Why it may not be worth it tonight

- full FPGA compiles can take a long time
- board setup issues can waste time right before the presentation
- your current report-based story is already strong enough for a 10-minute talk

### Recommendation

If the hardware flow is already working and you can launch the compile with very
little risk, do it for the best variant only.

Use it as a bonus result, not as the core of the presentation.

If there is any setup uncertainty, skip it and present the current report-based
results confidently.

## Best final message to leave the audience with

"For these AES steps, the best optimization was not the most aggressive one. The
best result came from restructuring memory access to preserve a good pipeline,
showing that FPGA performance depends as much on schedule and data movement as
on raw logic replication."
