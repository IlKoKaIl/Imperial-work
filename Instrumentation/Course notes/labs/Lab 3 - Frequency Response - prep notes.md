# Lab 3 Frequency Response - Prep Notes

## 1) What this lab is really about
- You measure frequency response functions (FRFs) of a full sensor chain and of individual blocks.
- You use those block FRFs to infer the FRF of a block you cannot measure directly (the sounder).
- You interpret gain and phase physically (attenuation/amplification, delay/lead, resonances).

## 2) Core FRF definitions (must know)
- FRF of a device:
  - $G(f)=\dfrac{X(f)}{Y(f)}$ where $Y$ is input and $X$ is output.
- Polar form:
  - $G(f)=\left|G(f)\right|e^{j\phi(f)}$
- dB conversion:
  - $G_{\mathrm{dB}} = 20\log_{10}\!\left(\left|G\right|\right)$
  - $\left|G\right| = 10^{G_{\mathrm{dB}}/20}$

## 3) Block chain in this lab
- Sounder: voltage $\to$ sound pressure ($G_1$)
- Microphone: sound pressure $\to$ voltage ($G_2$)
- High-pass filter: voltage $\to$ voltage ($G_3$)
- Pre-amp: voltage $\to$ voltage ($G_4$)

Overall system FRF:
- $G_{\mathrm{sys}} = G_1G_2G_3G_4$
- $\left|G_{\mathrm{sys}}\right|=\left|G_1\right|\left|G_2\right|\left|G_3\right|\left|G_4\right|$
- $\phi_{\mathrm{sys}}=\phi_1+\phi_2+\phi_3+\phi_4$

Microphone/reference relations shown in Section 4.4:
- Desired microphone FRF: $G_{\mathrm{electret}}(f)=\dfrac{A(f)}{SP(f)}$
- Bode-analyser measured ratio in that setup: $\dfrac{A(f)}{B(f)}$
- Reference mic FRF: $G_{\mathrm{ref}}(f)=\dfrac{B(f)}{SP(f)}$
- Therefore: $G_{\mathrm{electret}}(f)=\left(\dfrac{A(f)}{B(f)}\right)G_{\mathrm{ref}}(f)$

Inferred sounder FRF (what lab asks you to derive):
- $\left|G_1\right|=\dfrac{\left|G_{\mathrm{sys}}\right|}{\left|G_2\right|\left|G_3\right|\left|G_4\right|}$
- $\phi_1=\phi_{\mathrm{sys}}-(\phi_2+\phi_3+\phi_4)$

Note: the exact equation text in a few figure regions was not machine-readable in the PDF extraction, but these are the standard relations implied by Sections 3.2 and 4.5.

## 4) Key solved calculations from the handout

### A) Example in lab text: $-18\,\mathrm{dB}$
- $\left|\dfrac{V_{\mathrm{out}}}{V_{\mathrm{in}}}\right|=10^{-18/20}=0.126$
- So output amplitude is ~1/8 of input amplitude.
- If $V_{\mathrm{in}}=0.8\,\mathrm{V}$ (Bode peak setting), then $V_{\mathrm{out}}\approx0.101\,\mathrm{V}$.

### B) Pre-amp gain interpretation
- $20\,\mathrm{dB}$ means:
  - $\left|G\right|=10^{20/20}=10$
- So pre-amp multiplies input amplitude by ~10 in its flat region.
- Handout says flat to about $10\,\mathrm{kHz}$; at $100\,\mathrm{kHz}$ gain is only $\sim5$ (about $14\,\mathrm{dB}$).

### C) Electret sensitivity conversion from appendix
- Given sensitivity: $-60\,\mathrm{dB}$ re $1\,\mathrm{V}/\mu\mathrm{bar}$ at $1\,\mathrm{kHz}$
- Linear:
  - $10^{-60/20}=0.001\,\mathrm{V}/\mu\mathrm{bar}=1\,\mathrm{mV}/\mu\mathrm{bar}$
- Convert to $\mathrm{V}/\mathrm{Pa}$ using $1\,\mu\mathrm{bar}=0.1\,\mathrm{Pa}$:
  - $0.001\,\mathrm{V}/\mu\mathrm{bar}=0.01\,\mathrm{V}/\mathrm{Pa}=10\,\mathrm{mV}/\mathrm{Pa}$
- With $\pm3\,\mathrm{dB}$ tolerance:
  - factor range $10^{-3/20}$ to $10^{+3/20}$ is $0.707$ to $1.413$
  - sensitivity range is about $0.707$ to $1.413\,\mathrm{mV}/\mu\mathrm{bar}$
- Figure 4-7 spreadsheet assumptions (visible annotations):
  - flat region uses $x=1\,\mathrm{mV}/\mu\mathrm{bar}$
  - $50\,\mathrm{Hz}$ point uses $x-3\,\mathrm{dB}=0.708\,\mathrm{mV}/\mu\mathrm{bar}$
  - $13\,\mathrm{kHz}$ point also uses $0.708\,\mathrm{mV}/\mu\mathrm{bar}$
  - very-low and very-high anchor values use $0.010\,\mathrm{mV}/\mu\mathrm{bar}$
  - linear interpolation is used between A$\to$B and $13\,\mathrm{kHz}\to100\,\mathrm{kHz}$

### D) High-pass filter equations you may need
- First-order passive high-pass (series $C$, shunt $R$, output across $R$):
  - $H(j\omega)=\dfrac{j\omega RC}{1+j\omega RC}$
  - $f_c=\dfrac{1}{2\pi RC}$
  - at $f=f_c$: $\left|H\right|=\dfrac{1}{\sqrt{2}}$ ($-3\,\mathrm{dB}$), phase $+45^\circ$
- Rearranged design formulas:
  - $C=\dfrac{1}{2\pi R f_c}$
  - $R=\dfrac{1}{2\pi C f_c}$
- Shape facts:
  - Below $f_c$: slope is about $+20\,\mathrm{dB/dec}$
  - Above $f_c$: tends to $0\,\mathrm{dB}$ gain
- From Figure 4-4, the shown filter cutoff appears roughly in the $\sim50\,\mathrm{Hz}$ region (consistent with electret low-end bandwidth value).

### E) Plausibility check in Section 4.5
- Given (handout): peak sounder gain $\sim0.20\,\mu\mathrm{bar}/\mathrm{mV}$ near $3200\,\mathrm{Hz}$
- For $1\,\mathrm{V}$ drive ($1000\,\mathrm{mV}$):
  - pressure at mic location (assumed $1\,\mathrm{cm}$) is $0.20\times1000=200\,\mu\mathrm{bar}$
  - $200\,\mu\mathrm{bar}=20\,\mathrm{Pa}$ (since $1\,\mu\mathrm{bar}=0.1\,\mathrm{Pa}$)
- If pressure amplitude scales as $1/r$, then at $1\,\mathrm{m}$ (100x farther):
  - $20\,\mathrm{Pa}/100=0.2\,\mathrm{Pa}$
- SPL at $1\,\mathrm{m}$:
  - $L_p=20\log_{10}\!\left(\dfrac{0.2}{20\times10^{-6}}\right)=80\,\mathrm{dB\ SPL}$

Useful discussion point:
- This can be an overestimate due to strong near-field coupling, resonance bias, and uncertainty in synthesized microphone FRF.

## 5) What to say about each measured plot
- Whole system FRF:
  - Includes all component dynamics, so resonances are mixed.
  - Low-frequency and very-high-frequency points can be noise-dominated (poor SNR).
- Pre-amp FRF:
  - Approximately flat (good) over audio-relevant lower band.
  - Rolls off at high frequency; finite bandwidth.
- Filter FRF:
  - Should look like first-order high-pass if implemented as RC high-pass.
  - Cutoff is the $-3\,\mathrm{dB}$ point on magnitude plot.
- Microphone FRF:
  - Not measured directly in this lab due lack of reference instrumentation mic.
  - Synthesized from datasheet (approximation).
- Sounder FRF:
  - Derived indirectly by dividing out known blocks from system FRF.

## 6) Spreadsheet workflow (fast checklist)
- Export Bode data for:
  - whole system, pre-amp, filter (magnitude + phase)
- Use linear magnitudes for multiplication/division.
- Build synthesized microphone magnitude from datasheet assumptions:
  - $Mag_{\mathrm{mic}}=1\,\mathrm{mV}/\mu\mathrm{bar}$ in flat band
  - $Mag_{\mathrm{mic}}=0.708\,\mathrm{mV}/\mu\mathrm{bar}$ at $50\,\mathrm{Hz}$ and $13\,\mathrm{kHz}$
  - use linear ramps to/from $0.010\,\mathrm{mV}/\mu\mathrm{bar}$ outside the band (Figure 4-7 style)
- Compute:
  - $Mag_{\mathrm{sounder}}=\dfrac{Mag_{\mathrm{system}}}{Mag_{\mathrm{mic}}\,Mag_{\mathrm{filter}}\,Mag_{\mathrm{preamp}}}$
  - $\phi_{\mathrm{sounder}}=\phi_{\mathrm{system}}-(\phi_{\mathrm{mic}}+\phi_{\mathrm{filter}}+\phi_{\mathrm{preamp}})$
- Plot all 5 magnitudes on same frequency axis (linear + log views).

## 7) Interview-style questions you are likely to get
- Why use swept-sine for electronic FRF measurement?
  - Better SNR at each frequency, but slower than impulse/noise methods.
- Why are resonances obvious in the full chain response?
  - Resonance peaks come from component dynamics and multiply through chain.
- Why can low/high end of plots look random?
  - Very low output -> poor SNR; measurement floor dominates.
- Why $20\log_{10}$ and not $10\log_{10}$?
  - Because gain is an amplitude ratio (voltage/pressure), not power ratio.
- Why is microphone treated as band-pass-like?
  - Datasheet bandwidth is finite ($50\,\mathrm{Hz}$ to $13\,\mathrm{kHz}$), so sensitivity falls outside that band.
- Biggest uncertainty in derived sounder FRF?
  - Synthesized microphone FRF and coupling assumptions.

## 8) 2-minute pre-lab memory cram
- $G=\dfrac{\text{output}}{\text{input}}$, chain gains multiply, phases add.
- dB $\leftrightarrow$ linear: $A=10^{\mathrm{dB}/20}$.
- High-pass RC: $f_c=\dfrac{1}{2\pi RC}$, $-3\,\mathrm{dB}$ at cutoff.
- Sounder FRF is indirect: divide system FRF by mic/filter/preamp FRFs.
- Don't over-trust extreme frequency points (SNR limits).

