# Chapter 9-12 Study Notes (Clear + Problem-Sheet Focus)

Sources:
- `chp9-12.pdf`
- `Problem sheet 4.pdf`

Goal of this version:
- Keep the ideas in simple words (not just screenshot text).
- Add exactly the knowledge needed for Problem Sheet 4.
- Give extra depth for Seminar Question I (Q3), as requested.

## 1. Fast Big Picture

You are learning one pipeline:
1. Take a small analog signal from real hardware.
2. Use op-amp circuits to amplify/filter/buffer it safely.
3. Handle differential signals and reject common noise.
4. Understand real op-amp limits (bandwidth, slew-rate, stability).
5. Convert between analog and digital (S/H, ADC, DAC).

## 2. Core Definitions (Minimal but Complete)

- `op-amp`: a high-gain differential amplifier with `Vout = A(V+ - V-)`.
- `open-loop gain A`: op-amp gain with no feedback.
- `closed-loop gain G`: final gain after feedback network is connected.
- `negative feedback`: send part of output back to inverting path to reduce error and stabilize gain.
- `single-ended signal`: measured relative to ground.
- `differential signal`: `VD = V+ - V-`.
- `common-mode signal`: `VCM = (V+ + V-)/2`.
- `CMRR`: how well common-mode is rejected, `CMRR(dB) = 20 log10(AD/ACM)`.
- `slew rate S`: max `|dVout/dt|`.
- `bandwidth B`: useful frequency range.

## 3. Golden Rules (When Using Negative Feedback)

Use these for most op-amp circuit questions in this chapter:

1. `V+ ~= V-` (virtual short).
2. Input currents are approximately zero.

Important:
- This is an approximation.
- It becomes very good when open-loop gain `A` is very large and circuit is stable.

## 4. Circuit Cookbook (What to Write in Exams)

### 4.1 Inverting amplifier

Setup: input through `Rin` to `-` input, feedback `Rf` from output to `-`, `+` input at ground.

Method:
1. By Rule 1, inverting node is virtual ground (`~0 V`).
2. Current in `Rin`: `Iin = Vin / Rin`.
3. Current in `Rf`: `If = (0 - Vout)/Rf = -Vout/Rf`.
4. By KCL and Rule 2, `Iin = If`.

Result:

`Vout/Vin = -Rf/Rin`

### 4.2 Non-inverting amplifier

Setup: input on `+`; divider (`Rf`, `R0`) feeds output back to `-`.

Result:

`Vout/Vin = 1 + Rf/R0`

Feedback fraction:

`beta = V-/Vout = R0/(R0 + Rf)`

and ideally `Gain ~= 1/beta`.

### 4.3 Summing amplifier (inverting)

`Vout = -Rf (V1/R1 + V2/R2 + ...)`

This is the key tool for Problem Sheet Q5.

### 4.4 Integrator and differentiator

- Integrator: capacitor in feedback path.
- Differentiator: capacitor in input path.
- Both are frequency-dependent active filters.

## 5. Differential Measurement and Instrumentation Amplifier

Why needed:
- Some sensors produce tiny `VD` on top of large `VCM`.
- Example type: Wheatstone bridge + strain gauges.

Difference amp ideal target:

`Vout = AD (V+ - V-)`

Real form:

`Vout = AD*VD + ACM*VCM`  (common modeling form)

Instrumentation amplifier advantage:
- Very high input impedance.
- Better resistor matching internally.
- Much better CMRR.

Given course formula:

`Vout = (V2 - V1) (R4/R3) (1 + 2R1/R2)`

## 6. Real-World Op-Amp Limits (Needed for Reasoning)

- Finite `A`: golden rule is approximate, not exact.
- Finite bandwidth: higher gain means lower usable frequency range (`G*B ~= constant`).
- Phase lag: can threaten stability at high frequency.
- Stability condition warning: avoid case where `1 + beta A` approaches zero.

## 7. Problem Sheet 4 Prep

## 7.1 Q1 (Inverting amplifier derivation)

Use the 4-step KCL method in Section 4.1.
Final line to show:

`Gain = Vout/Vin = -Rf/Rin`

## 7.2 Q2 (AC non-inverting amp with input high-pass)

Treat as two blocks in cascade:
1. High-pass input filter (`Rin`, `Cin`)
2. Non-inverting amplifier (`R0`, `Rf`)

Because op-amp input impedance is very high, the amplifier does not significantly load the filter.

Amplifier gain:

`Gamp = 1 + Rf/R0 = 1 + (1M/20k) = 51`

High-pass magnitude:

`|Hhp| = (wRC)/sqrt(1 + (wRC)^2)` where `R = Rin`, `C = Cin`

Given `Rin = 100k`, `Cin = 0.1 uF`:

`RC = 0.01 s`, `fc = 1/(2*pi*RC) ~= 15.9 Hz`

Total magnitude gain:

`|Gtotal| = Gamp * |Hhp|`

At `10 kHz`: `wRC >> 1`, so `|Hhp| ~= 1` and `|Gtotal| ~= 51`.

At `10 Hz`: `wRC = 2*pi*10*0.01 = 0.628`,
`|Hhp| ~= 0.532`, so `|Gtotal| ~= 51*0.532 ~= 27`.

Bode sketch guidance:
- Mid-band level: `20 log10(51) ~= 34.15 dB`
- Low corner near `15.9 Hz`
- High corner at `80 kHz` (given)
- Slope below low corner: `+20 dB/dec`
- Slope above 80 kHz: `-20 dB/dec`
- So overall shape is a band-pass response with gain.

## 7.3 Q3 Seminar I (Most Important)

Given:

`Gain = A/(1 + beta A)` and ideally `Gain ~= 1/beta`

For the non-inverting circuit with `R0` to ground and `Rf` to output:

### (a) Derive beta

Inverting input sees a divider of `Vout`:

`V- = Vout * R0/(R0 + Rf)`

So:

`beta = R0/(R0 + Rf)`

### (b) Show ideal equation (2)

Ideal high-gain feedback drives `V+ ~= V-`.
Since `V+ = Vin`, then:

`Vin = beta*Vout` -> `Vout/Vin = 1/beta`

Also:

`1/beta = (R0 + Rf)/R0 = 1 + Rf/R0`

which is standard non-inverting gain.

### (c) Show finite-gain equation (1)

Start from:

`Vout = A(V+ - V-) = A(Vin - beta Vout)`

Rearrange:

`Vout(1 + beta A) = A Vin`

So:

`Vout/Vin = A/(1 + beta A)`

### (d) Numeric ideal gain for `R0 = 10k`, `Rf = 990k`

`Gain_ideal = 1 + Rf/R0 = 1 + 990/10 = 100`

### (e) Error vs ideal for real finite A

Use:

`Greal = A/(1 + beta A)`, with `beta = 1/100 = 0.01`

Percentage error vs ideal (`Gideal = 100`):

`error% = |Gideal - Greal| / Gideal * 100 = 100/(1 + beta A)`

Values:
- `A = 10^9` -> error `~ 1e-5 %`
- `A = 10^6` -> error `~ 1e-2 %`
- `A = 10^3` -> error `~ 9.09 %` (about 10%)

This is the key conceptual point: finite open-loop gain matters only when `beta*A` is not very large.

## 7.4 Q4 (Instrumentation amplifier + CMRR)

Given `R1 = R3 = R4 = 25k`, `R2 = 1k`:

Differential gain:

`AD = (R4/R3)(1 + 2R1/R2) = 1*(1 + 50) = 51`

From `CMRR = 120 dB`:

`AD/ACM = 10^(120/20) = 10^6` -> `ACM = AD/10^6 = 51e-6`

If `VD = 0.1 V` and `VCM = 0`:

`Vout ~= AD*VD = 51*0.1 = 5.1 V`

If common-mode is large, small extra output appears from `ACM*VCM`.
Check which exact `VCM` convention your lecturer uses when matching final digits in the sheet.

## 7.5 Q5 Seminar II (Waveform synthesis)

Target:

`-A cos^3(wt)`

Use identity:

`cos^3 x = (3 cos x + cos 3x)/4`

So:

`-A cos^3(wt) = -(A/4)[3 cos(wt) + cos(3wt)]`

Elegant one-op-amp approach:
- Use one inverting summing amplifier.
- Feed `3A cos(wt)` and `A cos(3wt)` through equal input resistors `R`.
- Choose feedback resistor `Rf = R/4`.

Then:

`Vout = -(Rf/R)[3A cos(wt) + A cos(3wt)] = -A cos^3(wt)`

## 8. Diagram Guide (Simple Reading Notes)

Images are in `chp9-12_diagrams`. Use these as visual support, not as your main explanation source.

- `fig_9_2_p1.png`: op-amp model. Focus on `V+`, `V-`, output, and rails.
- `fig_9_7_p4.png`: inverting amplifier. Node `X` is virtual ground.
- `fig_9_9_p5.png`: integrator vs differentiator; capacitor position controls behavior.
- `fig_10_2_p6.png`: Wheatstone bridge gives tiny differential signal on large common level.
- `fig_10_6_p8.png`: instrumentation amp uses 3 op-amps for high Zin + high CMRR.
- `fig_11_1_p9.png`: open-loop gain drops with frequency.
- `fig_11_3_p10.png`: gain/phase margins explain stability safety.
- `fig_12_2_p11.png`: flash ADC uses many comparators in parallel.

## 9. 60-Second Revision Checklist

If you can do all items below quickly, you are ready for this sheet:

- Derive inverting and non-inverting gains from golden rules + KCL.
- Write `beta = R0/(R0 + Rf)` and use both ideal and finite gain formulas.
- Combine filter magnitude and amplifier gain in cascaded circuits.
- Compute `AD` and `ACM` from instrumentation-amp formula + CMRR.
- Use inverting summing amplifier equation for weighted waveform synthesis.

