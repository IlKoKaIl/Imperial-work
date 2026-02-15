# Chapter 9-12 Notes (Screenshot + Simple Explanations + Problem Sheet Focus)

Sources:

- `chp9-12.pdf`
- `Problem sheet 4.pdf`

How this file is structured:

- Screenshot from the handout (text paragraph or figure).
- Short simplified explanation in plain words.
- Explicit note on where it helps in Problem Sheet 4.

## Core Definitions (quick reference)

- `Vout = A(V+ - V-)`: basic op-amp relation.
- `A`: open-loop gain (very large, but finite in reality).
- `G`: closed-loop gain (actual gain with feedback).
- `beta`: feedback fraction (`Vfeedback / Vout`).
- Differential signal: `VD = V+ - V-`.
- Common-mode signal: `VCM = (V+ + V-)/2`.
- CMRR: `20 log10(AD/ACM)` in dB.

## Chapter 9: Negative Feedback and Standard Op-Amp Circuits

### Key handout text: feedback gain equation

![Closed-loop feedback gain text](chp9-12_text_snippets/feedback_gain_formula.png)

Plain words:

- High open-loop gain plus negative feedback gives stable, predictable gain.
- When `A` is huge, `G = A/(1+beta*A)` behaves like `1/beta`.
- This is why resistor ratios set gain in practical op-amp circuits.

Problem-sheet relevance:

- Directly needed for Q3 (Seminar I), especially parts (a)-(e).

### Key handout text: golden rules

![Golden rules text](chp9-12_text_snippets/golden_rules.png)

Plain words:

- Rule 1: feedback drives inputs close together (`V+ ~= V-`).
- Rule 2: almost no current enters either input.
- Together these let you use KCL quickly to derive gains.

Problem-sheet relevance:

- Q1 derivation.
- Q2 gain analysis.
- Q3 ideal amplifier steps.
- Q5 summing amplifier design.

### Diagram set: Chapter 9 circuits

![Figure 9.2](chp9-12_diagrams/fig_9_2_p1.png)

Simplified point:

- Think of op-amp as: huge gain block + input/output impedances + rail limits.

![Figure 9.3](chp9-12_diagrams/fig_9_3_p2.png)

Simplified point:

- Buffer has gain 1 but solves loading problems (high input Z, low output Z).

![Figure 9.4](chp9-12_diagrams/fig_9_4_p2.png)

Simplified point:

- This block diagram is the universal idea behind closed-loop control.

![Figure 9.6](chp9-12_diagrams/fig_9_6_p4.png)

Simplified point:

- Non-inverting gain is `1 + Rf/R0`.
- Feedback fraction is `beta = R0/(R0+Rf)`.

![Figure 9.7](chp9-12_diagrams/fig_9_7_p4.png)

Simplified point:

- Inverting node is virtual ground.
- `Gain = -Rf/Rin`.

![Figure 9.9](chp9-12_diagrams/fig_9_9_p5.png)

Simplified point:

- Capacitor location decides integrator vs differentiator behavior.

## Chapter 10: Differential Signals and Instrumentation Amplifier

### Key handout text: differential definition context

![Differential signal text](chp9-12_text_snippets/diff_and_common_mode_defs.png)

Plain words:

- Useful signal is often the voltage difference between two nodes.
- Absolute voltage of either node to ground may be irrelevant.
- This is common in bridge sensors.

Problem-sheet relevance:

- Conceptual background for Q4.

### Key handout text: CMRR definition

![CMRR definition text](chp9-12_text_snippets/cmrr_definition.png)

Plain words:

- `AD` should be large, `ACM` should be tiny.
- CMRR tells how strongly common-mode is rejected.
- `120 dB` means `AD/ACM = 10^6`.

Problem-sheet relevance:

- Exactly needed in Q4(b).

### Diagram set: Chapter 10

![Figure 10.1](chp9-12_diagrams/fig_10_1_p6.png)

Simplified point:

- Differential waveform can be small even when each individual line is large.

![Figure 10.2](chp9-12_diagrams/fig_10_2_p6.png)

Simplified point:

- Wheatstone bridge: tiny mismatch becomes measurable differential output.

![Figure 10.3](chp9-12_diagrams/fig_10_3_p7.png)

Simplified point:

- Noise picked up equally on both lines tends to cancel in differential measurement.

![Figure 10.4](chp9-12_diagrams/fig_10_4_p7.png)

Simplified point:

- Difference amplifier works but resistor matching and input loading are limitations.

![Figure 10.6](chp9-12_diagrams/fig_10_6_p8.png)

Simplified point:

- Instrumentation amplifier fixes input impedance and common-mode rejection issues.

![Figure 10.7](chp9-12_diagrams/fig_10_7_p8.png)

Simplified point:

- Real parts like AD620 package this architecture in one chip.

## Chapter 11: Real-World Op-Amp Limits and Stability

### Key handout text: gain-bandwidth product

![Gain-bandwidth text](chp9-12_text_snippets/gain_bandwidth_text.png)

Plain words:

- Gain and bandwidth trade against each other.
- If you design for larger closed-loop gain, usable frequency range shrinks.

Problem-sheet relevance:

- Helps for Q2(c) Bode sketch reasoning.

### Key handout text: stability criterion

![Stability criterion text](chp9-12_text_snippets/stability_criterion.png)

Plain words:

- At high frequency, phase lag can make feedback effectively positive.
- If denominator of closed-loop formula approaches zero, circuit can oscillate.

Problem-sheet relevance:

- Useful context for Q3(e): why finite open-loop behavior matters.

### Diagram set: Chapter 11

![Figure 11.1](chp9-12_diagrams/fig_11_1_p9.png)

Simplified point:

- Open-loop gain is not flat forever; it rolls off strongly with frequency.

![Figure 11.3](chp9-12_diagrams/fig_11_3_p10.png)

Simplified point:

- Positive gain and phase margins are what keep feedback stable.

## Chapter 12: ADC and DAC Concepts

### Key handout text: sample-and-hold motivation

![Sample-hold text](chp9-12_text_snippets/sample_hold_text.png)

Plain words:

- ADC needs a stable input during conversion.
- Sample-and-hold freezes the signal briefly so conversion is accurate.

### Diagram set: Chapter 12

![Figure 12.1](chp9-12_diagrams/fig_12_1_p11.png)

Simplified point:

- Switch + capacitor + buffer is the core sample-and-hold idea.

![Figure 12.2](chp9-12_diagrams/fig_12_2_p11.png)

Simplified point:

- Flash ADC is very fast but needs many comparators.

![Figure 12.3](chp9-12_diagrams/fig_12_3_p11.png)

Simplified point:

- DAC can be built as weighted summing of digital bits.

## Problem Sheet 4: Targeted Working Notes

## Q1 Inverting amplifier derivation

Use:

1. Virtual ground at inverting node.
2. `Iin = Vin/Rin`.
3. `If = -Vout/Rf`.
4. Set `Iin = If` to get:

`Vout/Vin = -Rf/Rin`

Memorize vs Derive:

- Memorize: inverting gain form `-Rf/Rin`, virtual ground idea, and sign convention (inverted output).
- Derive in exam: write KCL at the inverting node using `Iin = If` and show the gain in 3-4 lines.

## Q2 AC non-inverting amplifier with input high-pass

Treat as cascade:

- High-pass filter magnitude:
  `|Hhp| = (wRC)/sqrt(1 + (wRC)^2)` with `R = Rin`, `C = Cin`
- Amplifier gain:
  `Gamp = 1 + Rf/R0 = 51`

Given:

- `Rin = 100k`, `Cin = 0.1uF` -> `RC = 0.01 s`, `fc ~= 15.9 Hz`

At `10 kHz`:

- `|Hhp| ~= 1` -> total gain `~ 51`

At `10 Hz`:

- `wRC = 0.628`, `|Hhp| ~= 0.532` -> total gain `~ 27`

Bode highlight:

- low-corner around `15.9 Hz`
- high-corner at `80 kHz` (given)
- looks like a band-pass with gain plateau in between

Memorize vs Derive:

- Memorize: non-inverting gain `1 + Rf/R0`, HP magnitude `wRC/sqrt(1 + (wRC)^2)`, and corner `fc = 1/(2*pi*RC)`.
- Derive in exam: treat filter and amplifier as cascade, compute each gain block, then multiply magnitudes.

## Q3 Seminar I (most important)

Given non-inverting amplifier with divider `R0` to ground and `Rf` to output:

### (a) Derive `beta`

`V- = Vout * R0/(R0 + Rf)` so

`beta = R0/(R0 + Rf)`

### (b) Show ideal equation

With ideal feedback op-amp:

- `V+ ~= V-`
- `Vin = beta*Vout`
- `Vout/Vin = 1/beta = 1 + Rf/R0`

### (c) Show finite-`A` equation

`Vout = A(Vin - beta*Vout)`

`Vout(1 + beta*A) = A*Vin`

`Vout/Vin = A/(1 + beta*A)`

### (d) Numeric ideal gain (`R0=10k`, `Rf=990k`)

`Gideal = 1 + 990/10 = 100`

### (e) Gain error for `A = 10^9, 10^6, 10^3`

Use `beta = 0.01`.

`Greal = A/(1 + 0.01A)`

Error against ideal 100:

`error% = |100 - Greal|/100 * 100 = 100/(1 + 0.01A)`

Results:

- `A = 10^9` -> `~ 1e-5 %`
- `A = 10^6` -> `~ 1e-2 %`
- `A = 10^3` -> `~ 9.09 %` (about 10%)

Memorize vs Derive:

- Memorize: `beta = R0/(R0 + Rf)`.
- Memorize: `Gideal = 1/beta = 1 + Rf/R0`.
- Memorize: `Greal = A/(1 + beta*A)`.
- Memorize: `error% = |Gideal - Greal|/Gideal * 100`.
- Derive in exam: part (a) from divider at `V-`.
- Derive in exam: part (b) with `V+ ~= V-`.
- Derive in exam: part (c) from `Vout = A(Vin - beta*Vout)` then rearrange.
- Derive in exam: part (e) plug numbers after symbolic formula is done.

## Q4 Instrumentation amplifier + CMRR

Given `R1=R3=R4=25k`, `R2=1k`:

`AD = (R4/R3)(1 + 2R1/R2) = 51`

Given `CMRR = 120 dB`:

`AD/ACM = 10^(120/20) = 10^6`

`ACM = 51e-6`

For `VD=0.1 V` and `VCM=0`:

- `Vout = AD*VD = 5.1 V`

With large common-mode input:

- small extra term appears from `ACM*VCM`
- this is why CMRR matters for precision

Memorize vs Derive:

- Memorize: `CMRR(dB) = 20log10(AD/ACM)` and `AD = (R4/R3)(1 + 2R1/R2)` for this sheet.
- Derive in exam: convert dB to linear ratio first, solve for `ACM`, then compute output terms.

## Q5 Seminar II

Target:

`-A cos^3(wt)`

Identity:

`cos^3 x = (3 cos x + cos 3x)/4`

So:

`-A cos^3(wt) = -(A/4)[3cos(wt) + cos(3wt)]`

One elegant circuit:

- one inverting summing op-amp
- inputs: `3A cos(wt)` and `A cos(3wt)`
- equal input resistors `R`
- choose feedback resistor `Rf = R/4`

Then:

`Vout = -(Rf/R)[3A cos(wt) + A cos(3wt)] = -A cos^3(wt)`

Memorize vs Derive:

- Memorize: identity `cos^3 x = (3cos x + cos 3x)/4` and inverting-summer form `Vout = -Rf*sum(Vi/Ri)`.
- Derive in exam: transform target waveform with trig identity, then choose resistor ratios to implement weights.

## 60-second checklist before attempting the sheet

- I can derive inverting gain with KCL from virtual ground.
- I can write `beta = R0/(R0+Rf)` without looking up.
- I can move between ideal (`1/beta`) and finite (`A/(1+beta A)`) gain.
- I can compute high-pass magnitude and multiply by amplifier gain.
- I can convert CMRR dB to linear ratio and find `ACM`.
- I can build weighted sums with an inverting summing amplifier.
