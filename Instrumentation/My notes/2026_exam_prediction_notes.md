# 2026 Instrumentation Exam Prediction Notes

Source basis:
- Past papers available locally: 2016, 2017, 2018, 2019, 2020, 2022, 2023, 2024, 2025.
- Missing locally: 2021.
- Solved locally: 2022 and 2025.

Important caveat:
- This is a risk-weighted prediction, not a guarantee. The safest use is to prioritise theory memorisation and fast templates, not to ignore whole topics.

## 1. Big Pattern

The exam repeatedly asks integrated instrumentation-chain questions:

`sensor/detector -> cable/impedance -> amplifier/filter -> ADC/noise -> transfer function/system response`

Exact questions rarely repeat word-for-word, but the same question families return constantly.

## 2. Topics That Appear Almost Every Year

### Transfer Functions, Laplace, Stability

Likelihood for 2026: very high.

Common theory prompts:
- Define transfer function.
- Explain why impulse response is important.
- Use $G(s)=X(s)/Y(s)$.
- Interpret poles and stability.
- Explain step response vs impulse response.
- Use differentiator/integrator blocks: $G(s)=s$ and $G(s)=1/s$.
- Use initial conditions in Laplace derivative rules.

Must know:
- $Y(s)=1/s$ for a unit step.
- $Y(s)=1$ for an impulse.
- $X(s)=G(s)Y(s)$.
- Stable systems have poles in the left half-plane.
- Pure imaginary poles give sustained oscillation / marginal case.
- Right-half-plane poles give exponential growth / instability.

### Op-Amps And Feedback

Likelihood for 2026: very high.

Common theory prompts:
- State ideal op-amp assumptions and golden rules.
- Explain virtual ground.
- Derive inverting/summing/difference/TIA output.
- Explain finite open-loop gain and feedback.
- Explain gain-bandwidth, phase margin, gain margin, or unity-gain stability.
- Explain CMRR or common-mode rejection.

Must know:
- With negative feedback, $V_+\approx V_-$.
- Op-amp inputs draw approximately zero current.
- Inverting gain: $V_{out}/V_{in}=-R_f/R_{in}$.
- Non-inverting gain: $V_{out}/V_{in}=1+R_f/R_0$.
- TIA: $V_{out}=-i_{in}R_f$.
- Feedback reduces gain but improves control, bandwidth, and linearity.

### Noise And SNR

Likelihood for 2026: high.

Common theory prompts:
- Explain thermal noise and shot noise.
- Explain flicker noise and why real RMS stays finite.
- Explain noise factor/noise figure.
- Add independent noise sources in quadrature.
- Explain how bandwidth affects RMS noise.
- Explain why cooling reduces thermal noise.

Must know:
- Thermal noise: $v_n=\sqrt{4k_BTRB}$.
- Shot noise: $i_n=\sqrt{2eIB}$.
- Independent RMS noises add as $v_{tot}=\sqrt{v_1^2+v_2^2+\cdots}$.
- Noise factor uses power SNR: $F=SNR_{in}/SNR_{out}$.
- If using voltage SNRs, use $\sqrt{F}$.
- Flicker noise is approximately $1/f$ and dominates at low frequency.

### ADC, DAC, Sampling

Likelihood for 2026: high.

Common theory prompts:
- State Nyquist theorem.
- Explain aliasing.
- Explain quantisation and quantisation noise.
- Explain dynamic range in dB.
- Describe flash ADC or weighted-resistor DAC.

Must know:
- Number of levels: $2^N$.
- Resolution / LSB: range divided by $2^N$.
- Maximum quantisation error: $\pm LSB/2$.
- RMS quantisation noise: $LSB/\sqrt{12}$.
- Nyquist frequency: $f_N=f_s/2$.
- Proper sampling requires $f_s>2f_{max}$.

## 3. Topics Likely But Less Certain

### Transmission Lines And Cable Readout

Likelihood for 2026: medium-high.

Why:
- Very common historically and returned in 2025.
- They may avoid another full cable-heavy detector chain immediately after 2025, but characteristic impedance/reflection is still a favourite small part.

Common theory prompts:
- Define characteristic impedance.
- Explain matching and reflections.
- Explain why a matched load gives no reflection.
- Convert cable attenuation in dB to voltage ratio.

Must know:
- $Z_0$ is the voltage/current ratio of a travelling wave on a reflection-free line.
- $Z_0=\sqrt{L'/C'}$.
- Reflection coefficient: $\Gamma=(Z_L-Z_0)/(Z_L+Z_0)$.
- Matched load $Z_L=Z_0$ gives $\Gamma=0$.
- Positive attenuation in dB means voltage is reduced by $10^{dB/20}$.

### RC Filters, Bandwidth, Loading

Likelihood for 2026: medium-high.

Why:
- Very frequent from 2017-2020 and central in 2024.
- Less central in 2025 except TIA bandwidth, so it could return.

Common theory prompts:
- Derive low-pass or high-pass transfer function.
- Explain cutoff frequency and bandwidth.
- Sketch/interpret Bode plot.
- Explain loading.
- Explain why high capacitance plus large resistance lowers bandwidth.

Must know:
- Low-pass: $G(\omega)=1/(1+j\omega RC)$.
- High-pass: $G(\omega)=j\omega RC/(1+j\omega RC)$.
- $\tau=RC$.
- $f_c=1/(2\pi RC)$.
- Low cutoff means low bandwidth and slow time response.

### PMT/SiPM/Photon Detector Chain

Likelihood for 2026: medium.

Why:
- Very common historically and central in 2025.
- They may not repeat SiPM-heavy content immediately, but photon detector chains are a repeated favourite.

Common theory prompts:
- Explain PMT or SiPM operation.
- Compare PMT and SiPM.
- Explain dark count/dark current.
- Calculate charge from gain.
- Convert optical photons to charge/current/voltage.

Must know:
- Photon energy: $E=hc/\lambda$.
- Photon rate: $\dot{N}=P/E$.
- Charge from detector gain: $Q=Ge$.
- SiPM dark counts are pulses without real photons.
- PMTs are vacuum-tube photodetectors; SiPMs are solid-state avalanche microcell arrays.

### Phase-Sensitive Detection / Rectification / Lock-In

Likelihood for 2026: medium.

Why:
- Strongly asked in 2024, not in 2025.
- Could return as a smaller theory part, especially lock-in/noise-rejection style.

Common theory prompts:
- Explain synchronous rectifier.
- Compare with diode bridge.
- Explain phase detector averaging.
- Explain why output depends on phase.
- Explain lock-in amplifier principle.

Must know:
- PSD multiplies signal by reference then averages / low-pass filters.
- Same-frequency result: $\langle V_{out}\rangle=(2A/\pi)\cos\phi$ for square-wave reference.
- Lock-in rejects out-of-band noise by measuring only at known reference frequency.

### Bridge / Thevenin / Sensor Loading

Likelihood for 2026: medium.

Why:
- Thevenin/bridge appears in older papers and sensor definitions reappeared in 2023.
- Less visible in 2024/2025, so possible return.

Common theory prompts:
- Define loading, offset, saturation.
- Use Thevenin/Norton equivalent.
- Explain impedance bridging vs matching.
- Explain Wheatstone bridge sensitivity.

Must know:
- Loading means measurement device changes the quantity being measured.
- To measure voltage without loading, use high input impedance.
- For maximum power transfer, match impedances.
- Thevenin equivalent is voltage source $V_{th}$ in series with $R_{th}$.

## 4. Consecutive-Year Pattern

No reliable strict skipping rule exists.

What does repeat:
- Transfer functions/Laplace appear every year in some form.
- Op-amp/feedback appears every year in some form.
- Noise appears frequently, sometimes as a whole question and sometimes inside detector/SNR chains.
- ADC/sampling appears often in modern papers.

What tends not to repeat exactly:
- 2024 had phase detector derivation; 2025 did not.
- 2025 had TIA and SiPM chain; 2026 may use a different sensor/readout but ask the same style of reasoning.
- 2025 had first-order sensor static sensitivity/time constant; 2026 may instead use block diagrams, RC/RLC, or op-amp feedback for system dynamics.

Most likely 2026 move:
- Reuse the same families but change the physical wrapper.
- For example, instead of SiPM + TIA, they could use PMT + load resistor, photodiode + op-amp, bridge sensor + amplifier, or thermistor/strain gauge + ADC.

## 5. Theory Most Worth Memorising

### Tier 1: Must Know Cold

- Ideal op-amp golden rules and virtual ground.
- Transfer function definition and $X(s)=G(s)Y(s)$.
- Step, impulse, differentiator, integrator Laplace facts.
- Static sensitivity and time constant.
- Stability from poles.
- Thermal noise, shot noise, SNR in dB, independent noise quadrature.
- ADC resolution, quantisation error/noise, Nyquist theorem.
- Characteristic impedance and reflection coefficient.

### Tier 2: Very Likely Useful

- PMT vs SiPM operation and key parameters.
- Dark counts/dark current.
- Detector threshold chain: energy -> photons -> collection -> transport -> PDE/QE -> noise threshold.
- TIA vs load resistor theory.
- RC cutoff and bandwidth.
- Gain-bandwidth product and op-amp bandwidth.
- CMRR.
- Flicker noise and lock-in/phase-sensitive detection.

### Tier 3: Worth Skimming

- Thevenin/Norton statements.
- Wheatstone bridge qualitative behaviour.
- DAC weighted-resistor logic.
- Flash ADC comparator ladder.
- Phase detector integral derivation.
- Bode plot sketch features.

## 6. My Best Guess For 2026 Question Shapes

### Prediction A: Detector/Readout Chain

Possible wrapper:
- PMT, SiPM, photodiode, scintillator, radiation detector, optical sensor, or current-output sensor.

Likely theory:
- Explain sensor operation.
- Explain threshold/noise/dark current.
- Cable or impedance issue.
- Amplifier gain/noise.
- ADC/sampling issue.

Why likely:
- Strong modern trend in 2022/2025 and common historically.

Prepare:
- Detector-chain template.
- PMT/SiPM comparison.
- Noise + ADC + cable basics.

### Prediction B: Op-Amp Readout Circuit

Possible wrapper:
- TIA, summing amplifier, difference amplifier, instrumentation amplifier, bridge amplifier, or active filter.

Likely theory:
- State assumptions.
- Explain virtual ground.
- Derive $V_{out}$.
- Discuss sensitivity/range/bandwidth/loading.
- Real op-amp limit such as gain-bandwidth or saturation.

Why likely:
- Op-amps appear every year.
- 2025 TIA was new but the op-amp family will not disappear.

Prepare:
- KCL at virtual ground.
- TIA and load resistor comparison.
- Gain-bandwidth and saturation/clipping.

### Prediction C: System Dynamics / Transfer Function

Possible wrapper:
- First-order sensor, cascaded sensor/amplifier/transducer, feedback block diagram, RLC/RC system.

Likely theory:
- Derive $G(s)$.
- Identify $k_s$ and $\tau$.
- Step response.
- Stability from poles.
- Whether reordering blocks matters mathematically vs physically.

Why likely:
- Every paper has this family.
- 2025 used first-order sensor; 2026 could use a feedback/block diagram or RLC instead.

Prepare:
- $G(s)=X(s)/Y(s)$.
- $X(s)=G(s)Y(s)$.
- Unit step $Y(s)=1/s$.
- Partial fractions and inverse Laplace.

### Prediction D: Noise Theory

Possible wrapper:
- Resistor, diode, PMT, amplifier, bandwidth-limited measurement, lock-in measurement.

Likely theory:
- Compare thermal, shot, flicker.
- Use noise factor.
- Explain bandwidth/cooling effects.
- Add noise sources.
- Possibly lock-in / modulation to avoid low-frequency noise.

Why likely:
- 2025 only had moderate SNR/noise in the detector chain; a fuller noise theory part could return.

Prepare:
- Thermal/shot/flicker definitions.
- $v_n=\sqrt{4k_BTRB}$.
- $i_n=\sqrt{2eIB}$.
- Noise factor and dB conversions.

### Prediction E: Sampling / Filtering

Possible wrapper:
- Digitised sensor pulses, anti-aliasing, DAC/ADC, waveform analyser.

Likely theory:
- Nyquist theorem.
- Aliasing.
- Quantisation noise.
- Dynamic range.
- Why filtering is needed before ADC.

Why likely:
- Modern papers repeatedly include digitisation.

Prepare:
- $f_N=f_s/2$.
- LSB and quantisation noise.
- Anti-alias filter explanation.

## 7. If Short On Time

Memorise these theory answer skeletons:

### Static Sensitivity / Time Constant

Static sensitivity $k_s$ is the steady-state output/input ratio. In steady state $dx/dt=0$, so $x=k_sy$. The time constant $\tau$ describes speed of response; after one $\tau$ a first-order step response reaches $1-1/e\approx63\%$ of final value. The cutoff angular frequency is $\omega_c=1/\tau$.

### TIA vs Load Resistor

A load resistor converts current to voltage with $V=iR_L$, so high sensitivity needs large $R_L$. With sensor capacitance this gives large $\tau=R_LC$ and low bandwidth, and the output is high impedance and easily loaded. A TIA gives $V_{out}=-i_{in}R_f$, keeps the input near virtual ground, gives low input impedance for current measurement, and drives the next stage with low output impedance.

### Characteristic Impedance

$Z_0$ is the voltage/current ratio of a travelling wave on a reflection-free line. For a lossless line $Z_0=\sqrt{L'/C'}$. A matched load $Z_L=Z_0$ gives reflection coefficient $\Gamma=0$, so no pulse is reflected.

### Noise

Thermal noise is random charge motion in resistance, $v_n=\sqrt{4k_BTRB}$. Shot noise is due to discrete charge carriers, $i_n=\sqrt{2eIB}$. Flicker noise is approximately $1/f$ and dominates at low frequency. Independent RMS noise sources add in quadrature.

### ADC / Sampling

An $N$-bit ADC has $2^N$ levels. The LSB is range divided by $2^N$. Maximum quantisation error is $\pm LSB/2$, RMS quantisation noise is $LSB/\sqrt{12}$. Sampling rate must be at least twice the highest signal frequency; $f_N=f_s/2$.

### Transfer Function

$G(s)=X(s)/Y(s)$. For an input $Y(s)$, output is $X(s)=G(s)Y(s)$. Step input has $Y(s)=1/s$, impulse has $Y(s)=1$. Poles determine stability: left half-plane stable, right half-plane unstable, imaginary-axis poles oscillatory/marginal.

## 8. Sensor Families To Expect

The exam does not usually expect deep specialist sensor knowledge from nowhere. It gives a physical wrapper, then expects you to apply core instrumentation ideas: sensitivity, impedance, noise, bandwidth, gain, ADCs, and transfer functions.

### Most Plausible Sensor Wrappers

| Sensor/readout family | Why plausible | Theory to know |
|---|---|---|
| PMT / SiPM photon detector | Asked many times: PMT/SiPM, single-photoelectron charge, dark counts, cables, ADCs | Photon energy, QE/PDE, gain, charge $Q=Ge$, dark current/counts, cable/amplifier/ADC chain |
| Photodiode / photosensor current source | Natural follow-up to TIA/readout questions | Current source readout, load resistor vs TIA, shot noise, capacitance/bandwidth |
| Magnetoresistor / Hall-like magnetic sensor | Bridge/magnetoresistor questions appear in older papers and 2023 | Wheatstone bridge, sensitivity, saturation, differential output, instrumentation amplifier |
| Temperature sensor / thermistor / thermometer | Appears in problem sheets and first-order system theory | Static sensitivity, time constant, first-order response, calibration |
| Strain gauge / resistive bridge sensor | Classic instrumentation sensor, same maths as bridge questions | Resistance change, Wheatstone bridge, loading, amplification, CMRR |
| Capacitive or high-impedance sensor | Fits impedance/loading/bandwidth themes | $Q=CV$, input impedance, buffering, RC time constant, bandwidth |
| Generic first-order sensor | Very likely because 2025 did it explicitly and older papers use system dynamics | $G(s)=k_s/(\tau s+1)$, step response, bandwidth |

### Less Likely But Worth Recognising

| Sensor/readout family | Quick recognition |
|---|---|
| Lock-in / phase-sensitive detector | Weak signal at known frequency, multiply by reference and average |
| LVDT / inductive sensor | Coil/inductance changes, AC excitation, bridge/demodulation style reasoning |
| Piezoelectric sensor | Charge source, high impedance, needs charge amplifier/buffer |

### How To Handle An Unfamiliar Sensor

Use this script:

1. What physical quantity enters? Examples: light, magnetic field, temperature, strain, current, charge.
2. What electrical quantity comes out? Voltage, current, resistance, capacitance, charge, frequency.
3. What is the sensitivity? Output/input slope.
4. What limits the smallest detectable signal? Noise, dark counts, quantisation, threshold.
5. What limits the largest detectable signal? Saturation, clipping, ADC range, dynamic range.
6. What limits speed? Bandwidth, RC time constant, sensor time constant, cable/digitiser.
7. What readout is used? Bridge, load resistor, TIA, buffer, op-amp gain, ADC.

## 9. May 9 To May 14 Preparation Plan

Priority is not rereading everything. It is rebuilding the most repeated templates until they are automatic.

### May 9: Finish 2025 And Extract Templates

- Finish reviewing 2025, but do not sink the whole day into perfecting it.
- Write/recite template answers for:
  - SiPM/PMT detector chain.
  - TIA vs load resistor.
  - Static sensitivity/time constant.
  - Nyquist/ADC/SNR.
- Redo only the parts you got stuck on from a blank page.

### May 10: 2024 Paper

- Do 2024 under semi-timed conditions.
- Focus topics:
  - RC filters and loading.
  - Phase-sensitive detector.
  - PS8-style block transfer functions.
- After marking, write one-line triggers: "If I see X, I do Y."

### May 11: 2023 Paper

- Do 2023 or at least the theory-heavy parts.
- Focus topics:
  - Sensor definitions: offset, saturation, loading.
  - Real op-amp Bode/gain/phase margins.
  - Noise/flicker/ADC.
  - Bridge/magnetoresistor.

### May 12: 2022 Solved Paper

- Use 2022 solutions to calibrate marking style.
- Focus topics:
  - PMT + cable + digitiser.
  - DAC with op-amp.
  - Transfer functions / time delay.
- This is a good confidence-building paper because solutions exist.

### May 13: Emergency Consolidation

- No new papers unless calm.
- Rebuild formula sheet from memory.
- Recite the theory skeletons in Section 7.
- Redo 6 representative parts:
  - one op-amp KCL derivation,
  - one transfer function step response,
  - one noise/SNR calculation,
  - one ADC/sampling part,
  - one transmission-line reflection/attenuation part,
  - one sensor-theory explanation.

### May 14: Exam Morning

- Light recall only.
- Read master formula sheet and this prediction sheet.
- Do not start a new hard paper.

## 10. What Not To Do

- Do not reread all notes linearly.
- Do not try to redo every problem sheet.
- Do not memorise niche sensor facts without linking them to readout-chain ideas.
- Do not chase full marks on theory prose. Aim for the mark-bearing phrases: definition, physical meaning, formula, consequence.

## 11. Repeated Theory Prompts Across Past Papers

This is based on keyword/prompt recurrence across the local past papers: 2016, 2017, 2018, 2019, 2020, 2022, 2023, 2024, 2025.

| Prompt family | Years found | What this means for revision |
|---|---|---|
| Transfer function / Laplace / stability | 2016, 2017, 2018, 2019, 2020, 2022, 2023, 2024, 2025 | Non-negotiable. Appears every year in some form. |
| Op-amp ideal/golden rules | 2016, 2017, 2018, 2019, 2020, 2022, 2024 | Can repeat in consecutive/near-consecutive years. Memorise assumptions and KCL method. |
| RC filter / Bode / cutoff | 2017, 2018, 2019, 2020, 2022, 2023, 2024 | Very repeatable. 2024 was heavy, but the family is still high-yield. |
| PMT / SiPM / photoelectron | 2016, 2017, 2018, 2020, 2022, 2025 | Detector chain is a repeated exam wrapper. Exact sensor may change. |
| Characteristic impedance | 2016, 2017, 2018, 2019, 2022, 2025 | Exact definition has repeated many times, including after gaps. Keep it memorised. |
| ADC quantisation / dynamic range | 2018, 2022, 2023, 2024, 2025 | Modern papers ask digitisation repeatedly. |
| Input/output impedance/loading | 2019, 2020, 2022, 2023, 2024, 2025 | Very common theory explanation area. |
| Noise factor / SNR | 2022, 2023, 2025 | Likely to return as part of sensor/readout chain. |
| Thermal / shot noise | 2017, 2019, 2023 | Not in every year, but core formula knowledge remains high value. |
| Flicker noise | 2016, 2019, 2023 | Comes in theory/explanation chunks. |
| Bridge / magnetoresistor | 2016, 2017, 2023, 2024 | Possible return, especially as a sensor wrapper. |
| Thevenin / Norton | 2017, 2020 | Less frequent recently, but could return as a circuit-equivalent subpart. |
| Phase detector / rectifier | 2024 | Recent heavy appearance; less likely as a full repeat but still worth knowing. |
| Static sensitivity / time constant | 2016, 2023, 2025 | First-order sensor theory can return in many disguises. |

Conclusion:
- Consecutive-year repetition definitely happens at the topic-family level.
- Exact wording can repeat after gaps, e.g. characteristic impedance.
- The safest strategy is to memorise short theory skeletons for repeated families, not detailed prose for every niche sensor.
