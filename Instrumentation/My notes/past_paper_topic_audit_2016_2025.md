# Past Paper Topic Audit (2016-2025)

Sources:

- `Instrumentation/Past papers/2016 paper.pdf`
- `Instrumentation/Past papers/2017 paper.pdf`
- `Instrumentation/Past papers/2018 paper.pdf`
- `Instrumentation/Past papers/2019 paper.pdf`
- `Instrumentation/Past papers/2020 paper.pdf`
- `Instrumentation/Past papers/2022 paper.pdf`
- `Instrumentation/Past papers/2023 paper.pdf`
- `Instrumentation/Past papers/2024 paper.pdf`
- `Instrumentation/Past papers/2025 paper.pdf`

Note: I did not find a 2021 paper in the folder. This audit records what is asked, not the solutions.

## Executive Summary

The papers are very pattern-based. The most common exam style is not "recite chapter facts"; it is an integrated instrumentation chain:

`sensor/detector -> cable/impedance -> amplifier/filter -> ADC/noise -> transfer function/system response`

Most repeated areas:

| Rank | Topic family | Years seen | What they usually ask |
|---|---:|---|
| 1 | Laplace, transfer functions, stability, step/impulse response | 2016-2025, every paper | Derive $G(s)$, identify poles, determine stability, inverse Laplace |
| 2 | Op-amps and feedback circuits | 2016-2025, every paper | Ideal rules, derive output, real op-amp limits, gain-bandwidth, CMRR |
| 3 | Noise and SNR | 2016-2023, plus 2025 SNR | Thermal, shot, flicker, noise factor, cooling, bandwidth |
| 4 | Transmission lines/coax | 2016-2019, 2022, 2025 | $Z_0$, delay, reflections, termination, attenuation |
| 5 | ADC/DAC/sampling/aliasing | 2018, 2019, 2022, 2023, 2025 | Nyquist, aliasing, quantisation error/noise, DAC output |
| 6 | PMT/SiPM photon detectors | 2016-2018, 2020, 2022, 2025 | Photon energy, QE, gain, charge/current, single photoelectron response |
| 7 | RC filters and Bode plots | 2017-2020, 2024, partly 2025 | Gain, cutoff, transient response, loading, design choices |
| 8 | Bridges/sensor readout | 2016, 2017, 2020, 2023 | Thevenin/Norton, Wheatstone bridge, magnetoresistor |
| 9 | Phase-sensitive detection/rectification | 2016, 2024 | Synchronous rectifier, averaging, PSD output |

Main implication:

- Problem sheets are useful, but past papers combine topics more aggressively.
- The best prep is not just "do PS1 then PS2"; it is being able to connect detector physics, impedance/cables, op-amps, noise, ADCs, and transfer functions in one answer.

## By-Year Record

### 2016

Section A:

- Ideal op-amp properties and golden rules.
- Op-amp differentiator: show $V_{out}=-RC\,dV_{in}/dt$ and sketch output.
- PMT with QE, dynode gain, optical power, output voltage.
- Noise across PMT load resistor: likely shot/thermal/dark-current discussion.
- Flicker noise frequency characteristics and time dependence.
- Pole-zero plot for LTI system: derive differential equation and impulse response.

Section B:

- Coaxial cable: characteristic impedance, propagation time, short-circuit reflection.
- Source/load maximum power transfer and transformer matching.
- Optical doublet/refraction/transmission: less common, optics-heavy.
- Op-amp circuit output expression.
- Magnetoresistor Wheatstone bridge, sensitivity, saturation, amplifier gain, bandwidth.
- Laplace time-shift proof, waveform transform, feedback transfer function, stability.
- Full-wave rectifier, Fourier series of rectified waveform, LTI discussion, precision rectifier.

Knowledge needed:

- Ch 4-5, 6, 7-8, 9-11, 15-18, 19-21, plus bridge/sensor basics.

### 2017

Section A:

- Thevenin and Norton equivalents for a Wheatstone bridge.
- Ideal op-amp properties and golden rules.
- Op-amp integrator: show $V_{out}=-(1/RC)\int V_{in}\,dt$.
- Sketch output for piecewise input.
- Real-world op-amp properties.

Section B:

- RC circuit impedance, current, gain magnitude, phase, cutoff, Bode plot.
- Filter improvement: roll-off steepness, pass-band flatness, knee sharpness.
- Thermal noise and cooling to improve SNR.
- Laplace definition and first-derivative property.
- LRC circuit with initial capacitor voltage; differential equation and inverse Laplace.
- PMT gain, charge per photon, coax characteristic impedance, cable delay, single-photoelectron voltage, dark current.
- Block diagram transfer function with differentiator/integrator, stability, oscillation, step response.

Knowledge needed:

- Strong RC/filter/Bode skills, Laplace with initial conditions, PMT+cable chain, op-amp basics.

### 2018

Section A:

- PMT gain, charge per photon, single-photoelectron current.
- Coax cable $Z_0$, delay, single-photoelectron voltage.
- Ideal op-amp golden rules.
- Multi-input op-amp output expression and waveform sketch.
- Real-world op-amp properties.

Section B:

- RC transient with initially charged capacitor and step input.
- RC AC cutoff and Bode plot.
- Rectangular input through filter.
- Flicker noise properties and mitigation.
- Laplace integral property.
- Parallel LRC circuit with current source and initial conditions.
- Nyquist theorem, aliasing, alias frequencies.
- Sampling/switch circuit qualitative behaviour.
- 3-bit flash ADC: resolution, dynamic range, quantisation error/noise, circuit, pros/cons.
- Feedback block system: transfer function, impulse responses, stability range, oscillation, step response.

Knowledge needed:

- PMT and cable calculations, RC transient/filter, ADC/sampling, Laplace and stability.

### 2019

Section A:

- Coax cable $Z_0$, delay, reflection.
- Time-bandwidth product for Gaussian pulse.
- Weighted-resistor DAC using ideal op-amp.
- DAC output values, number of levels, pros/cons.

Section B:

- RC transient with initial capacitor voltage.
- RC AC cutoff and Bode plot.
- Rectangular signal through RC filter.
- Thermal and shot noise for diode/resistor.
- Laplace transform of finite pulse using step/time shift.
- RC/current-source transient with initial capacitor voltage.
- Input/output impedance definitions.
- Ideal op-amp and negative-impedance-style circuit.
- Flicker noise vs thermal noise and total noise over bandwidth.
- Block transfer function, zeros/poles, stability, step response.

Knowledge needed:

- Fourier/time-bandwidth, DAC/op-amp summing, RC transient, noise, Laplace pulse methods.

### 2020

Section A:

- Thevenin and Norton equivalent circuits, including numerical values.
- Ideal op-amp current/load circuit.
- Real-world op-amp properties.

Section B:

- Switched RC transient with initial steady state.
- Transfer function definition and impulse response importance.
- Inverse Laplace of a rational transfer function; zeros/poles/stability.
- Laplace transform of finite ramp.
- LRC circuit with impulse input and initial conditions.
- PMT gain, charge per photon, single-photoelectron voltage, dark current.
- Thermal noise, flicker noise, noise figure, total noise.
- Sketch overall noise power vs frequency.
- Multi-feedback block diagram: transfer function, differentiator/integrator blocks, stability, step response.

Knowledge needed:

- Circuit equivalents, RC/LRC transients, noise, PMT, block diagrams.

### 2022

Question 1:

- PMT single-photoelectron Gaussian pulse: calculate gain from pulse area/load resistor.
- Coax cable: characteristic impedance, delay, reflection from mismatch.
- Amplifier gain in dB, input-referred noise density, bandwidth, SNR.
- Choose digitiser speed and resolution.

Question 2:

- 5-bit DAC with op-amp.
- Ideal op-amp golden rules.
- Derive DAC output expression.
- Feedback resistor for output range, LSB voltage, dynamic range.
- Input-bias compensation resistor.
- Sampled sine fed to DAC: time-domain staircase and frequency spectrum.

Question 3:

- Laplace time-delay property.
- Bode plot for pure time delay.
- Negative-feedback transfer function.
- Evaluate transfer function from impulse responses.
- Step response.
- Sinusoidal response using transfer/frequency response similarity.

Knowledge needed:

- This paper strongly integrates PMT+cable+amplifier+digitiser, DAC, and transfer functions.

### 2023

Question 1:

- Sensor terms: offset, saturation, loading.
- Real op-amp Bode plot, gain margin, phase margin, closed-loop bandwidth.
- CMRR in dB.
- Flicker noise explanation and finite RMS in real measurements.
- Thermal noise, noise factor, SNR in dB, cooling for SNR improvement.
- Shot noise in diode/resistor.
- 16-bit digitiser: max range, quantisation error/noise, Nyquist, aliasing.

Question 2:

- Ideal op-amp difference/differential amplifier.
- Magnetoresistor Wheatstone bridge.
- Bridge output vs magnetic field.
- Amplifier design for Earth-field output.
- Static sensitivity plot with saturation.
- Op-amp gain-bandwidth effect on measurement bandwidth.

Question 3:

- Laplace transform of unit ramp.
- Two first-order amplifiers in series with ramp input.
- Block system with differentiator/integrator.
- Transfer function and given time-domain output.

Knowledge needed:

- This is a very exam-representative modern paper: mixed conceptual definitions, calculations, and system response.

### 2024

Question 1:

- RC low-pass complex gain.
- Bode plot with key features.
- Choose $R,C$ for anti-alias filter, phase detector averaging, and subwoofer.
- Loaded RC filter: derive complex gain and explain loading across frequency.
- Gaussian sensor response, low-pass filtering, digitisation, frequency-domain sketch.

Question 2:

- Multi-block op-amp/RC circuit analysis.
- Show phase-shifted output for sinusoidal input.
- Synchronous rectifier: name and describe.
- Sketch input/reference/output.
- Advantage over diode bridge.
- Add averaging to make phase-sensitive detector.
- Derive $\langle V\rangle=(2A/\pi)\cos\phi$.

Question 3:

- Block transfer function with $G_0$, differentiator, integrator, amplifier gains, positive/negative feedback.
- Convert impulse response $8te^{-2t}$ to $G_0(s)$.
- Stability and oscillation.
- Unit-step response.

Knowledge needed:

- Filters and PSD are much more prominent here than in 2022/2023.
- PS8-style block systems remain very high yield.

### 2025

Question 1:

- Scintillator + optical fibres + SiPM detector chain.
- Energy threshold: light yield, collection efficiency, QE/PDE, noise, gain, threshold, attenuation, electronics.
- Explain SiPM operation and compare with PMT using key parameters.
- SiPM output resistance/capacitance connected to 50 ohm transmission line and 50 ohm amplifier.
- Characteristic impedance, reflections, cable attenuation in dB/m.
- Single-photoelectron voltage estimate at amplifier output.
- ADC: max input, dynamic range, quantisation error/noise, SNR.
- Fast digitiser: Shannon-Nyquist theorem, Nyquist frequency, filtering needed.

Question 2:

- Transimpedance amplifier (TIA) for photosensor current readout.
- Derive voltage output.
- Compare SNR with simple load resistor.
- Explain why TIA is advantageous using input/output impedance.
- Feedback resistor trade-off: sensitivity vs range.
- Programmable-gain TIA idea.
- Bandwidth advantage for high-capacitance photosensor.

Question 3:

- First-order sensor differential equation.
- Derive transfer function form with static sensitivity and time constant.
- Physical meaning of $K_s$ and $\tau$.
- Step response and time to 95%.
- Cascade of first-order sensor, ideal amplifier, and first-order output transducer.
- Transfer function, whether amplifier position matters mathematically vs physically.
- Step response.

Knowledge needed:

- 2025 is very sensor-chain focused: SiPM, transmission line, ADC, TIA, first-order sensor dynamics.

## What Is Most Common?

### 1. Transfer Functions, Laplace, Stability

This appears essentially every year.

Typical tasks:

- Define Laplace transform.
- Prove a property: derivative, integral, or time shift.
- Convert impulse response $g(t)$ to $G(s)$.
- Combine block diagrams into a transfer function.
- Use differentiator $G(s)=s$ and integrator $G(s)=1/s$.
- Find poles/zeros.
- Decide stability from pole locations.
- Determine step or impulse response by inverse Laplace.

Need to know:

- `chp15-16_study_notes.md`
- `chp17-18_study_notes.md`
- `ps8_q3a_equation_rearrangement.md`

Priority: extremely high.

### 2. Op-Amps and Feedback

Appears every year in some form.

Typical tasks:

- State ideal op-amp properties and golden rules.
- Use KCL at virtual-ground/summing nodes.
- Derive output of inverting/summing/difference circuits.
- Discuss real-world op-amp limits.
- Use gain-bandwidth idea.
- Use phase/gain margins.
- Use CMRR.
- Design amplifier gains using resistor ratios.

Need to know:

- `chp9-12_study_notes.md`
- Problem Sheets 4 and 5.

Priority: extremely high.

### 3. Noise

Very frequent, especially 2016-2023 and still relevant in 2025 via SNR.

Typical tasks:

- Thermal noise: $v_n=\sqrt{4k_BTRB}$.
- Shot noise: $i_n=\sqrt{2eIB}$.
- Convert current noise to voltage noise.
- Use bandwidth correctly.
- Use SNR in dB.
- Use noise factor/noise figure.
- Explain flicker noise and why DC noise stays finite in real measurements.
- Explain mitigation: narrowing bandwidth, cooling, modulation/lock-in.

Need to know:

- `chp19-21_exam_notes.md`
- Problem Sheet 9.

Priority: very high.

### 4. Transmission Lines and Coax

Common in detector-readout questions.

Typical tasks:

- Define $Z_0$ physically.
- Calculate $Z_0=\sqrt{L'/C'}$.
- Calculate $v=1/\sqrt{L'C'}$ and delay $t=L/v$.
- Calculate reflection coefficient $\Gamma=(Z_L-Z_0)/(Z_L+Z_0)$.
- Explain polarity/sign of reflected pulse.
- Use dB attenuation for cable losses.

Need to know:

- `chp4-5_exam_notes.md`
- Problem Sheet 2.

Priority: high.

### 5. ADC/DAC, Sampling, Aliasing

Common in modern papers.

Typical tasks:

- ADC levels: $2^N$.
- Step size/resolution.
- Dynamic range in dB.
- Max quantisation error and RMS quantisation noise.
- Nyquist frequency $f_N=f_s/2$.
- Alias frequencies.
- Flash ADC/DAC circuits and weighted-resistor DAC output.
- Sketch sampled/staircase waveforms and spectra.

Need to know:

- `chp4-5_exam_notes.md`
- `chp9-12_study_notes.md`
- Problem Sheets 3 and 5.

Priority: high.

### 6. PMT/SiPM and Photon Detector Chains

Very common, and the 2025 paper makes SiPMs central.

Typical tasks:

- Photon energy $E=hc/\lambda$.
- Photon rate $\dot{N}=P/E$.
- QE/PDE factors.
- PMT dynode gain and charge per photon.
- Single photoelectron charge/current/voltage.
- Dark current.
- SiPM operation and comparison with PMT.
- Detector threshold factors.

Need to know:

- `chp1-3_exam_notes.md`
- `chp4-5_exam_notes.md`
- Noise notes for SNR.

Priority: high, especially for modern papers.

### 7. RC Filters, Bode Plots, First-Order Systems

Common and often integrated with sampling or sensors.

Typical tasks:

- Derive low-pass/high-pass complex gain.
- Find cutoff frequency.
- Sketch Bode magnitude/phase.
- Explain loading effects.
- Choose $R,C$ for an application.
- Step response and time constants.
- First-order sensor transfer function and time to 95%.

Need to know:

- `chp7-8_exam_notes.md`
- `chp13-14_study_notes.md`
- `chp15-16_study_notes.md`

Priority: high.

## Are Problem Sheets Representative?

Short answer: yes, but not perfectly.

They are good for learning the individual methods:

- PS1: sensor performance, PMT, thermometer.
- PS2: transmission lines and matching.
- PS3: Fourier, RC, ADC/sampling.
- PS4/PS5: op-amps, ADC/DAC, real op-amp limits.
- PS6: PSD and LTI systems.
- PS7/PS8: Laplace, transfer functions, stability.
- PS9: noise.

What past papers add:

- Integrated chains: detector + cable + amplifier + ADC + noise.
- More emphasis on explaining physical meaning, not just calculating.
- More modern sensor readout: SiPMs and TIA in 2025.
- Repeated reuse of block-diagram transfer functions with new constants.
- More "sketch and annotate" tasks: Bode plots, static sensitivity, time responses, spectra.

## Highest-Yield Revision Order From Past Papers

1. Transfer functions and stability: block diagrams, poles, inverse Laplace.
2. Op-amp KCL and feedback: inverting/summing/difference/TIA, real op-amp bandwidth.
3. Noise calculations: thermal, shot, flicker, SNR, noise factor.
4. Transmission lines: $Z_0$, delay, reflection, attenuation.
5. ADC/DAC/sampling: quantisation and aliasing.
6. PMT/SiPM: photon energy, gain, charge/current/voltage, dark current.
7. RC filters and first-order sensors: cutoff, Bode, loading, step response.
8. Phase-sensitive detection/lock-in: especially because 2024 asked it directly.

## What To Add To Your Current Notes

Useful additions before timed papers:

- A one-page "detector readout chain" template:
  - photon energy -> photon rate -> detector gain -> charge/current -> cable/reflection -> amplifier gain/noise -> ADC.
- A TIA mini-note:
  - $V_{out}\approx -i_{in}R_f$.
  - Larger $R_f$ gives higher sensitivity but lower current range.
  - TIA input is near virtual ground, so it handles high-capacitance current sources better than a load resistor.
- A sketch-practice sheet:
  - RC Bode plot.
  - static sensitivity with saturation.
  - impulse/step responses for stable/unstable poles.
  - sampled sine/staircase and alias spectrum.

## Exam Strategy Based On Papers

When reading a question, first classify it:

- "Detector chain": write photon/charge/current/noise/ADC pipeline.
- "Circuit": use ideal op-amp rules or impedance divider.
- "Cable": use $Z_0$, delay, reflection coefficient.
- "Filter": write transfer function, cutoff, Bode limits.
- "System": write $G(s)=X(s)/Y(s)$, combine blocks, find poles.
- "Noise": identify thermal/shot/flicker, bandwidth, SNR units.

Do not start with algebra until the pipeline is clear.

