# Chapters 19-21 Exam Notes: Noise and Lock-In Amplifiers

Sources:

- `Instrumentation/Course notes/chp19-21.pdf`
- `Instrumentation/Course notes/Problem sheets + solutions/Problem Sheet 9.pdf`

Purpose: compact notes for noise calculations and lock-in amplifier questions.

## 1. Noise Basics

Noise is unwanted random signal added to the measurement.

Two broad types:

- Intrinsic noise: fundamental/internal to component or measurement process.
- Extrinsic noise/interference: picked up from environment.

Noise usually has:

- Amplitude characteristic: RMS value or distribution.
- Frequency characteristic: how noise power is distributed across frequency.

Bandwidth matters:

- More measurement bandwidth means more total noise.
- Narrowing bandwidth is a major way to improve SNR.

## 2. Thermal Noise

Thermal noise is caused by random thermal motion of charge carriers in a resistor.

RMS voltage noise:

`$v_n=\sqrt{4k_BTRB}$`

where:

- `$k_B$`: Boltzmann constant, `1.38e-23 J/K`.
- `$T$`: temperature in K.
- `$R$`: resistance in ohm.
- `$B$`: measurement bandwidth in Hz.

Noise voltage density:

`$e_n=\sqrt{4k_BTR}$` in `V/sqrt(Hz)`.

Plain words:

- Higher resistance gives more thermal voltage noise.
- Higher temperature gives more thermal noise.
- Wider bandwidth gives more RMS noise.

PS9 Q1 method:

1. Convert temperature to kelvin.
2. Insert `$R` and `$B`.
3. Compute RMS voltage.

## 3. Shot Noise

Shot noise occurs because charge arrives in discrete packets.

RMS current noise:

`$i_n=\sqrt{2eIB}$`

where:

- `$e$`: electron charge, `1.60e-19 C`.
- `$I$`: DC current.
- `$B$`: bandwidth.

Convert current noise to voltage noise across resistor:

`$v_n=i_nR$`

Plain words:

- More DC current means more shot noise.
- Shot noise is common in diodes, PMTs, photodetectors, and vacuum-tube sensors.

## 4. Signal-to-Noise Ratio and Noise Factor

SNR:

`$SNR=P_s/P_n$`

In dB:

`$SNR_{dB}=10log_{10}(P_s/P_n)$`

For amplitude ratios:

`$SNR_{dB}=20log_{10}(A_s/A_n)$`

Noise factor:

`$F=SNR_{in}/SNR_{out}$`

Meaning:

- `$F=1$`: amplifier adds no noise. Ideal lower limit.
- Real amplifiers have `$F>1$`.

## 5. Amplifier Noise

If amplifier gain is `$G$`:

- Signal output amplitude = `$G$` times input signal.
- Input noise from source also gets amplified.
- Amplifier may add its own noise.

For ideal amplifier:

- Only source noise matters.

For real amplifier:

- Use noise factor/noise figure to account for SNR degradation.

Noise figure in dB:

`$NF=10log_{10}F$`

## 6. Flicker Noise

Flicker noise is low-frequency noise with approximately `1/f` behavior.

Key fact:

- Noise power per Hz increases as frequency approaches zero.

Why DC measurements are not instantly impossible:

- Real measurement has finite duration.
- Finite duration sets an effective low-frequency cutoff.
- You never measure exactly at zero frequency for infinite time.

Common fix:

- Modulate a low-frequency/DC signal up to a higher frequency where flicker noise is lower.
- Use phase-sensitive detection/lock-in to recover it.

## 7. Lock-In Amplifier

A lock-in amplifier extracts a weak signal at a known reference frequency.

Core steps:

1. Multiply input by reference at same frequency.
2. Low-pass filter the product.
3. Keep only the DC/slow term related to the signal amplitude and phase.

Why it works:

- Signal is coherent with reference.
- Broadband/random noise averages down.
- Narrow bandwidth reduces total noise.

Connection to phase-sensitive detector:

- Lock-in amplifier is a practical phase-sensitive detector plus filtering and amplification.

## 8. Modulation Strategy

For low-frequency/DC signals:

- Modulate signal to a known higher frequency.
- Avoid low-frequency flicker noise.
- Detect with lock-in at modulation frequency.

Plain words:

- Move the signal away from noisy low-frequency region.
- Use the reference to pick out only the moved signal.

## Problem Sheet 9 Focus

High-yield question types:

- Thermal noise voltage from resistor.
- Shot noise current from diode/photocurrent.
- Convert current noise to voltage noise and apply amplifier gain.
- Compare thermal vs shot noise dominance.
- Use noise factor in SNR calculations.
- Explain flicker noise and lock-in detection qualitatively.

Thermal vs shot comparison method:

1. Write thermal voltage noise: `$v_{th}=\sqrt{4k_BTRB}$`.
2. Write shot current noise: `$i_{shot}=\sqrt{2eIB}$`.
3. Convert shot current to voltage across `$R$`: `$v_{shot}=i_{shot}R$`.
4. Compare squared values to avoid square roots.

Cooling effect:

- Thermal noise scales as `$\sqrt{T}$` in voltage amplitude.
- Thermal noise power scales with `$T$`.
- Large SNR improvements by cooling may require very low temperatures.
