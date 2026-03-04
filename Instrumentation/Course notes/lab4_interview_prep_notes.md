# Lab 4 Interview Prep (my notes)

## What this lab is about
I build my own LabVIEW instrument to measure pre-amp gain vs frequency, instead of using the ready-made Bode Analyzer tool.

## What I should be able to explain clearly
- I know the difference between **Front Panel** and **Block Diagram**.
- I know what a **VI (Virtual Instrument)** is.
- I know the difference between a **Control** (input I set) and an **Indicator** (output I read).
- I know how LabVIEW executes code: **dataflow**, not top-to-bottom text order.
- I know why I use RMS and Divide to compute gain.
- I know how the **For Loop** automates a frequency sweep.

## Core terms (simple)
- `VI`: a LabVIEW program.
- `Express VI`: prebuilt LabVIEW block with a config dialog (quick way to build functionality).
- `Dataflow`: a block runs only when all required input data is available.
- `Error wire`: helps enforce operation order (e.g., function generator setup then scope read).
- `RMS`: effective signal level; good for amplitude comparison.
- `Gain`: output amplitude divided by input amplitude.

## Hardware and signal path I should remember
- FGEN drives pre-amp input.
- CH0 reads pre-amp input.
- CH1 reads pre-amp output.
- So my gain is based on CH1 relative to CH0.

## VI structure (what my program does)
1. Set function generator (`frequency`, `amplitude`).
2. Acquire two waveforms from oscilloscope (`CH0`, `CH1`).
3. Plot both waveforms.
4. Compute RMS(CH0) and RMS(CH1).
5. Divide RMS(CH1) by RMS(CH0) to get measured gain.
6. In loop version: repeat over many frequencies and plot gain vs frequency.

## Key formulas I might need

### 1) Linear gain from measured signals
$$
G = \frac{V_{\mathrm{out,rms}}}{V_{\mathrm{in,rms}}}
  = \frac{V_{\mathrm{CH1,rms}}}{V_{\mathrm{CH0,rms}}}
$$

### 2) Gain in dB (if they ask to compare with Bode-style plots)
$$
G_{\mathrm{dB}} = 20\log_{10}(G)
$$
and
$$
G = 10^{G_{\mathrm{dB}}/20}
$$

### 3) RMS definition
$$
V_{\mathrm{rms}} = \sqrt{\frac{1}{N}\sum_{k=1}^{N} v_k^2}
$$

### 4) Frequency at loop index \(i\)
$$
f_i = f_{\mathrm{start}} + f_{\mathrm{step}}\,i
$$
with
$$
i = 0,1,\dots,N_{\mathrm{steps}}-1
$$

### 5) Last frequency reached in sweep
$$
f_{\mathrm{last}} = f_{\mathrm{start}} + f_{\mathrm{step}}(N_{\mathrm{steps}}-1)
$$

Example from script:
- \(f_{\mathrm{start}}=1000\) Hz, \(f_{\mathrm{step}}=1000\) Hz, \(N_{\mathrm{steps}}=50\)
- Last point \(= 50{,}000\) Hz.

## Quick expected behavior (so I can sanity-check)
- At low/mid frequencies, pre-amp gain should be around design value (~10).
- At higher frequencies, gain should drop (finite bandwidth).
- So at 20 kHz and especially 60 kHz, I should expect less gain than low-frequency region.

## Why RMS divide works here
- Input and output are both sine waves at the same frequency.
- Ratio of RMS amplitudes equals ratio of amplitudes (same as gain).
- So RMS is a stable way to compute gain from sampled waveform data.

## Config details worth remembering
- Function generator type: sine.
- FGEN amplitude is set from front-panel control.
- Scope reads from `SCOPE CH0` and `SCOPE CH1`.
- Example scope setup shown in script: sample rate around 200 kS/s, record length 20 samples, AC coupling, range 10 V, probe 1x.

## Interview-style questions I might get (and how I answer)

### Q: Why did I build this in LabVIEW instead of just using Bode Analyzer?
A: I can customize the measurement workflow, automate exactly what I want, and extend it later (extra processing, logging, custom plots).

### Q: What is the execution order in LabVIEW?
A: Dataflow decides order. A block executes only when its inputs are available. Position on screen is not execution order.

### Q: Why wire error-out to error-in?
A: It enforces sequence and propagates instrument errors, so acquisition doesn't run before generation setup.

### Q: Why use a For Loop?
A: To automate the sweep and avoid manually changing frequency and rerunning many times.

### Q: What does the loop index do?
A: It increments each iteration, and I use it in \(f_i=f_{\mathrm{start}}+f_{\mathrm{step}}i\) to generate sweep frequencies.

### Q: Why does gain drop at high frequency?
A: The pre-amp has limited bandwidth, so high-frequency components are attenuated more.

## Common mistakes I should avoid
- Forgetting to wire `Measured Gain` to Divide output.
- Dividing CH0 by CH1 by mistake (inverts gain).
- Not changing amplitude-level blocks to RMS mode.
- Leaving loop as While Loop incorrectly instead of For Loop for fixed steps.
- Forgetting to disable "Clear data on each call" in Build XY Graph (loses trace history).
- Broken wires: use Ctrl+B to clean.

## Fast debug checklist if something looks wrong
1. Confirm hardware path: FGEN -> pre-amp input, CH0=input, CH1=output.
2. Check NI ELVIS device selection.
3. Check scope sources are `SCOPE CH0` and `SCOPE CH1`.
4. Confirm CH0/CH1 both enabled.
5. Check gain formula wiring: CH1 RMS / CH0 RMS.
6. Verify front-panel controls have sensible values.
7. Make sure loop inputs (`Number of Steps`, `Step Frequency`) are wired correctly.

## 30-second summary I can say at the end
I built a LabVIEW VI that controls ELVIS function generation, acquires input/output waveforms from CH0/CH1, computes RMS-based gain, and automates a full frequency sweep with a For Loop. The key idea is LabVIEW dataflow: each block runs only when inputs are available. My gain plot reproduces pre-amp bandwidth behavior, with gain near nominal at lower frequency and reduced gain at higher frequency.

