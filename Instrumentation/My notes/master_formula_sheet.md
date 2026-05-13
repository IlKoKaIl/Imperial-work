# (*A)Instrumentation Master Formula Sheet

This is a working memory sheet. Rebuild it from memory every few days, then check against this file.

## Measurement, Calibration, Sensors

| Topic               | Formula / fact                                   | Use                              |
| ------------------- | ------------------------------------------------ | -------------------------------- |
| Absolute error      | `error = measured value - true value`          | Measurement uncertainty language |
| Static sensitivity  | $S = \frac{d(\text{output})}{d(\text{input})}$ | Sensor slope                     |
| Linear calibration  | $y = mx + c$                                   | Slope `m`, offset `c`        |
| Decibels, power     | $L_{dB} = 10 \log_{10}(P_2/P_1)$               | Power ratios                     |
| Decibels, amplitude | $L_{dB} = 20 \log_{10}(V_2/V_1)$               | Voltage/current amplitude ratios |
| Loading divider     | $V_L = \frac{V_s R_L}{R_s+R_L}$                | Source/load impedance            |

## Fundamental Circuit Relations

| Topic                    | Formula / fact                                             | Use                                                |
| ------------------------ | ---------------------------------------------------------- | -------------------------------------------------- |
| Ohm's law                | $V=IR$                                                   | Resistors and voltage drops                        |
| Current definition       | $i=\frac{dQ}{dt}$                                        | Current is rate of charge flow                     |
| Power definition         | $P=IV$                                                   | Electrical power                                   |
| Power in resistor        | $P=I^2R$                                                 | Use when current is known                          |
| Power in resistor        | $P=\frac{V^2}{R}$                                        | Use when voltage across resistor is known          |
| Series resistance        | $R_{total}=R_1+R_2+\cdots$                               | Same current through each resistor                 |
| Parallel resistance      | $\frac{1}{R_{total}}=\frac{1}{R_1}+\frac{1}{R_2}+\cdots$ | Same voltage across each branch                    |
| Two parallel resistors   | $R_{total}=\frac{R_1R_2}{R_1+R_2}$                       | Fast parallel calculation                          |
| Capacitor charge         | $Q=CV$                                                   | Charge stored on capacitor                         |
| Capacitor current        | $i=C\frac{dV_C}{dt}$                                     | Time-domain capacitor behaviour                    |
| Capacitor impedance      | $Z_C=\frac{1}{j\omega C}=-\frac{j}{\omega C}$            | Frequency-domain capacitor behaviour               |
| Capacitor switching fact | capacitor voltage cannot jump instantly                    | DC steady state: ideal capacitor acts open circuit |
| Inductor voltage         | $V_L=L\frac{di}{dt}$                                     | Time-domain inductor behaviour                     |
| Inductor impedance       | $Z_L=j\omega L$                                          | Frequency-domain inductor behaviour                |
| Inductor switching fact  | inductor current cannot jump instantly                     | DC steady state: ideal inductor acts short circuit |
| Voltage divider          | $V_{out}=V_{in}\frac{R_{bottom}}{R_{top}+R_{bottom}}$    | Divider node voltage                               |
| Impedance divider        | $V_{out}=V_{in}\frac{Z_{out}}{Z_1+Z_2}$                  | AC/filter voltage divider                          |
| Wheatstone bridge midpoint | $V_A=V_s\frac{R_2}{R_1+R_2}$                           | One side of bridge is a voltage divider            |
| Wheatstone bridge midpoint | $V_B=V_s\frac{R_4}{R_3+R_4}$                           | Other side of bridge is a voltage divider          |
| Wheatstone bridge output | $V_{out}=V_A-V_B$                                        | Sign depends on which midpoint is subtracted       |
| Active bridge small signal | $V_{out}\approx V_s\frac{\Delta R}{R}$                 | Four active arms: two increase, two decrease       |

## Transmission Lines and Digital Signals

| Topic                    | Formula / fact                            | Use                           |
| ------------------------ | ----------------------------------------- | ----------------------------- |
| Wavelength               | $\lambda = \frac{v}{f}$                 | Decide if line effects matter |
| Rule of thumb            | line matters when$L \gtrsim \lambda/10$ | Transmission-line trigger     |
| Characteristic impedance | $Z_0 = \sqrt{L'/C'}$                    | Cable impedance               |
| Propagation speed        | $v = \frac{1}{\sqrt{L'C'}}$             | Cable delay                   |
| Reflection coefficient   | $\Gamma = \frac{Z_L-Z_0}{Z_L+Z_0}$      | Reflections at load           |
| Nyquist frequency        | $f_N = \frac{f_s}{2}$                   | Sampling limit                |
| Quantisation step        | $\Delta = \frac{V_{range}}{2^N}$        | ADC resolution                |
| Number of ADC levels     | $N_{levels}=2^N$                        | $N$ is the number of bits     |
| ADC voltage range        | $V_{range}=V_{max}-V_{min}$             | Full-scale input span         |
| ADC dynamic range        | $\text{DR}=\frac{V_{range}}{\Delta}\approx2^N$ | Ratio of largest range to smallest step |
| ADC dynamic range in dB  | $\text{DR}_{dB}=20\log_{10}(2^N)\approx6.02N\,\text{dB}$ | Amplitude dynamic range for an ideal ADC |
| Max quantisation error   | $\pm \frac{\Delta}{2}$                  | ADC uncertainty               |
| RMS quantisation noise   | $\frac{\Delta}{\sqrt{12}}$              | Noise estimate                |

## Fourier and Filters

| Topic                        | Formula / fact                                                              | Use                                                       |
| ---------------------------- | --------------------------------------------------------------------------- | --------------------------------------------------------- |
| Angular frequency            | $\omega = 2\pi f$                                                         | Convert Hz to rad/s                                       |
| Fourier transform            | $F(\omega)=\int_{-\infty}^{\infty} f(t)e^{-j\omega t}\,dt$                | Time domain to frequency domain                           |
| Euler identity               | $e^{jx}=\cos x+j\sin x$                                                   | Simplify Fourier integrals                                |
| Euler identity               | $e^{-jx}=\cos x-j\sin x$                                                  | Simplify Fourier integrals                                |
| Exponential integral         | $\int e^{kt}\,dt=\frac{e^{kt}}{k}$                                        | Integrate Fourier kernels                                 |
| Top-hat Fourier transform    | $F(\omega)=\frac{2\sin(\omega a)}{\omega}$                                | Pulse bandwidth                                           |
| Top-hat sinc form            | $F(\omega)=2a\frac{\sin(\omega a)}{\omega a}=2a\,\mathrm{sinc}(\omega a)$ | Same result, shows sinc shape                             |
| Top-hat zero-frequency limit | $F(0)=2a$                                                                 | Area under pulse                                          |
| Top-hat first zeros          | $\omega=\pm\frac{\pi}{a}$                                                 | Main bandwidth scale                                      |
| Pulse-width rule             | shorter pulse$\Rightarrow$ broader spectrum                               | Time-bandwidth intuition                                  |
| Gaussian pulse shape         | $v(t)=V_0e^{-t^2/(2\sigma^2)}$                                            | $V_0$ is peak amplitude; $\sigma$ is width parameter  |
| Gaussian FWHM                | $\mathrm{FWHM}=2\sqrt{2\ln2}\,\sigma\approx2.35\sigma$                    | Convert quoted pulse width to$\sigma$                   |
| Gaussian area                | $\int_{-\infty}^{\infty}e^{-t^2/(2\sigma^2)}\,dt=\sqrt{2\pi}\sigma$        | Area under Gaussian pulse                                |
| Gaussian pulse charge        | $Q=\frac{V_0}{R}\sqrt{2\pi}\sigma$                                        | For voltage pulse $v(t)=V_0e^{-t^2/(2\sigma^2)}$ across resistor $R$ |
| Perfect sharp edge           | requires frequency components extending to infinity                         | Finite-bandwidth instruments cannot make perfect top-hats |
| RC time constant             | $\tau = RC$                                                               | Transient speed                                           |
| RC cutoff                    | $f_c = \frac{1}{2\pi RC}$, $\omega_c=\frac{1}{RC}$                      | Filter corner                                             |
| Low-pass gain                | $G(\omega)=\frac{1}{1+j\omega RC}$                                        | Output across capacitor                                   |
| High-pass gain               | $G(\omega)=\frac{j\omega RC}{1+j\omega RC}$                               | Output across resistor                                    |
| Capacitor current            | $i=C\frac{dV_C}{dt}$                                                      | Capacitor transient equation                              |
| First-order step             | $1-e^{-t/\tau}$ shape                                                     | Charging response                                         |
| Integrating factor           | For$\frac{dy}{dt}+p(t)y=q(t)$, use $\mu(t)=e^{\int p(t)\,dt}$           | Solve first-order ODEs                                    |
| IF product trick             | $\mu\left(\frac{dy}{dt}+py\right)=\frac{d}{dt}(\mu y)$ when $\mu'=p\mu$ | Why IF works                                              |
| dB gain                      | $20\log_{10}|G|$                                                            | Bode magnitude                                            |

## Complex Numbers and Frequency Response

| Topic                   | Formula / fact                                     | Use                                                                  |
| ----------------------- | -------------------------------------------------- | -------------------------------------------------------------------- |
| Laplace variable        | $s=\sigma+j\omega$                               | $\sigma$ gives growth/decay; $\omega$ gives sinusoidal frequency |
| Frequency response      | $G(j\omega)=G(s)\big|_{s=j\omega}$               | Use for steady sinusoidal input                                      |
| Complex number          | $z=a+jb$                                         | $a$ real part, $b$ imaginary part                                |
| Magnitude               | $|z|=\sqrt{a^2+b^2}$                             | Amplitude gain                                                       |
| Phase                   | $\arg(z)=\tan^{-1}\left(\frac{b}{a}\right)$      | Use$\operatorname{atan2}(b,a)$ if quadrant matters                 |
| Euler identity          | $e^{j\theta}=\cos\theta+j\sin\theta$             | Convert exponential to real/imaginary parts                          |
| Negative Euler identity | $e^{-j\theta}=\cos\theta-j\sin\theta$            | Common for delays/Fourier/Laplace                                    |
| Exponential phase       | $\arg(e^{j\theta})=\theta$                       | If already in exponential form, phase is the exponent angle          |
| Product phase           | $\arg(AB)=\arg(A)+\arg(B)$                       | Phases add when multiplying                                          |
| Ratio phase             | $\arg\left(\frac{A}{B}\right)=\arg(A)-\arg(B)$   | Denominator phase is subtracted                                      |
| Power phase             | $\arg(A^n)=n\arg(A)$                             | Example:$(1+j\omega)^2$ doubles phase                              |
| Pure delay              | $G(s)=e^{-sT}$, so $G(j\omega)=e^{-j\omega T}$ | Lossless delay line                                                  |
| Delay magnitude         | $|e^{-j\omega T}|=1$                             | Delay does not change amplitude                                      |
| Delay phase             | $\arg(e^{-j\omega T})=-\omega T$                 | Delay gives phase lag increasing with frequency                      |

## Op-Amps, ADC/DAC, Differential Signals

| Topic                                  | Formula / fact                                                             | Use                                                                |
| -------------------------------------- | -------------------------------------------------------------------------- | ------------------------------------------------------------------ |
| Ideal op-amp rule 1                    | $V_+ \approx V_-$ with negative feedback                                 | Virtual short                                                      |
| Ideal op-amp rule 2                    | input currents approximately zero                                          | KCL at input node                                                  |
| Inverting amplifier                    | $\frac{V_{out}}{V_{in}}=-\frac{R_f}{R_{in}}$                             | Input goes to$-$ terminal through $R_{in}$                     |
| Non-inverting amplifier                | $\frac{V_{out}}{V_{in}}=1+\frac{R_f}{R_g}$                               | Input goes to$+$ terminal; $R_g$ goes from $-$ to ground     |
| Inverting summing amplifier            | $V_{out}=-R_f\left(\frac{V_1}{R_1}+\frac{V_2}{R_2}+\cdots\right)$        | Add weighted inputs at virtual ground                              |
| Difference amplifier, matched          | $V_{out}=\frac{R_f}{R_i}(V_B-V_A)$                                       | Requires matched resistor ratios                                   |
| Difference amplifier, unity gain       | $V_{out}=V_B-V_A$                                                        | If$R_f=R_i$                                                      |
| Feedback gain                          | $G=\frac{A}{1+\beta A}\approx\frac{1}{\beta}$                            | Closed-loop gain (A = Open loop gain and B = feedback ratio))      |
| Gain-bandwidth product                 | $A_{OL}B_{OL}\approx G_{CL}B_{CL}\approx \text{constant}$                | Op-amp constant set by open-loop curve; higher closed-loop gain means lower bandwidth |
| Unity-gain frequency                   | $\text{GBW}\approx f_T$                                                  | Frequency where open-loop gain is about 1                          |
| Phase margin idea                      | At gain $=0\,\mathrm{dB}$, how far is phase from $-180^\circ$?           | Safety margin before feedback becomes positive                    |
| Phase margin formula                   | $\text{PM}=\phi_{0\,\mathrm{dB}}-(-180^\circ)=\phi_{0\,\mathrm{dB}}+180^\circ$ | Example: if $\phi_{0\,\mathrm{dB}}=-135^\circ$, PM $=45^\circ$ |
| Gain margin idea                       | At phase $=-180^\circ$, how far is gain from $0\,\mathrm{dB}$?           | Safety margin before loop gain reaches 1                          |
| Gain margin formula                    | $\text{GM}_{\mathrm{dB}}=0\,\mathrm{dB}-G_{\phi=-180^\circ,\mathrm{dB}}$ | Example: if $G=-20\,\mathrm{dB}$, GM $=20\,\mathrm{dB}$          |
| Stability margins                      | stable if $\text{PM}>0^\circ$ and $\text{GM}>0\,\mathrm{dB}$             | Both margins should be positive                                   |
| Differential signal                    | $V_D=V_+-V_-$                                                            | Difference signal                                                  |
| Common-mode signal                     | $V_{CM}=\frac{V_++V_-}{2}$                                               | Shared signal                                                      |
| CMRR:<br />common-mode rejection ratio | $20\log_{10}\left(\frac{A_D}{A_{CM}}\right)$                             | Difference amp quality                                             |
| TIA current-to-voltage gain            | $V_{out}=-i_{in}R_f$                                                     | Transimpedance amplifier                                           |
| TIA range choice                       | $R_f\lesssim\frac{V_S}{i_{max}}$                                         | Avoid op-amp clipping at supply rails                              |
| Load resistor readout                  | $V_{out}=i_{in}R_L$                                                      | Simple current-to-voltage conversion                               |
| Sensor capacitance bandwidth limit     | $\tau=RC$, $f_c=\frac{1}{2\pi RC}$                                     | Large$R$ and large $C$ make readout slow                       |
| Bandwidth intuition                    | larger$\tau$ means lower bandwidth                                       | Slow time response cannot follow fast signals                      |
| TIA advantage                          | low input impedance virtual ground + low output impedance op-amp drive     | Reduces sensor-capacitance loading and output loading              |

## Phase Detector and LTI Systems

| Topic                              | Formula / fact                                                                                           | Use                                                         |
| ---------------------------------- | -------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------- |
| Average over one period            | $\langle V\rangle=\frac{1}{T}\int_0^T V(t)\,dt$                                                        | Mean/DC value of a waveform                                 |
| Phase detector square-wave average | $\langle V_{out}\rangle=\frac{1}{T}\left[\int_0^{T/2}V_{in}(t)\,dt-\int_{T/2}^{T}V_{in}(t)\,dt\right]$ | Reference is$+1$ for half-cycle and $-1$ for half-cycle |
| PSD same-frequency output          | $\langle V_{out}\rangle = \frac{2A}{\pi}\cos\phi$                                                      | Phase-sensitive detector                                    |
| Sine phase expansion               | $\sin(\omega t+\phi)=\sin(\omega t)\cos\phi+\cos(\omega t)\sin\phi$                                    | Used to derive PSD output                                   |
| Sine integral                      | $\int \sin(\omega t+\phi)\,dt=-\frac{1}{\omega}\cos(\omega t+\phi)$                                    | Direct integration form                                     |
| Period relation                    | $T=\frac{2\pi}{\omega}$, so $\omega=\frac{2\pi}{T}$                                                  | Convert period/angular frequency                            |
| First-order LTI                    | $a_1\frac{dx}{dt}+a_0x=b_0y$                                                                           | Thermometer/RC analogies                                    |
| Static sensitivity                 | $K_s=\frac{b_0}{a_0}$                                                                                  | Final output/input ratio                                    |
| Time constant                      | $\tau=\frac{a_1}{a_0}$                                                                                 | Settling speed                                              |
| Second-order normalized            | $\frac{d^2x}{dt^2}+2\xi\omega_0\frac{dx}{dt}+\omega_0^2x=\text{forcing}$                               | Damped systems                                              |
| Natural frequency                  | $\omega_0^2=\frac{a_0}{a_2}$                                                                           | Second-order systems                                        |
| Damping ratio                      | $\xi=\frac{a_1}{2\sqrt{a_0a_2}}$                                                                       | Overshoot/oscillation                                       |

## Laplace, Transfer Functions, Stability

| Topic                 | Formula / fact                                    | Use                          |
| --------------------- | ------------------------------------------------- | ---------------------------- |
| Laplace definition    | $F(s)=\int_0^\infty f(t)e^{-st}\,dt$            | Time to `s` domain         |
| Transfer function     | $G(s)=\frac{X(s)}{Y(s)}$                        | Output/input in `s` domain |
| Step input            | $u(t) \leftrightarrow \frac{1}{s}$              | Step response                |
| Impulse input         | $\delta(t) \leftrightarrow 1$                   | Impulse response             |
| Exponential           | $e^{-at}u(t) \leftrightarrow \frac{1}{s+a}$     | Inverse Laplace              |
| Differentiator        | $G(s)=s$ with zero initial conditions           | Block diagrams               |
| Integrator            | $G(s)=\frac{1}{s}$ with zero initial conditions | Block diagrams               |
| Stability             | all poles must have$\operatorname{Re}(s)<0$     | LTI stability                |
| Pure imaginary poles  | sustained oscillation / marginal case             | Boundary case                |
| Right-half-plane pole | unstable exponential growth                       | Instability                  |

## Noise and Lock-In Amplifier

| Topic                           | Formula / fact                                                                                    | Use                                                  |
| ------------------------------- | ------------------------------------------------------------------------------------------------- | ---------------------------------------------------- |
| Boltzmann constant              | $k_B=1.38\times10^{-23}\,\mathrm{J/K}$                                                          | Use in thermal noise                                 |
| Thermal noise voltage           | $v_n=\sqrt{4k_BTRB}$                                                                            | Resistor RMS noise                                   |
| Thermal noise density           | $e_n=\sqrt{4k_BTR}$                                                                             | V/$\sqrt{\mathrm{Hz}}$                             |
| Shot noise current              | $i_n=\sqrt{2eIB}$                                                                               | Current noise                                        |
| Elementary charge               | $e=1.60\times10^{-19}\,\mathrm{C}$                                                              | Use in shot noise                                    |
| Silicon diode forward drop      | $V_D\approx0.6\,\mathrm{V}$                                                                     | Approximate voltage lost across forward-biased diode |
| Diode + series resistor current | $I\approx\frac{V_{supply}-V_D}{R}$                                                              | DC current for shot-noise calculation                |
| Current noise to voltage noise  | $v_n=i_nR$                                                                                      | Noise voltage across resistor                        |
| SNR                             | $SNR=\frac{P_s}{P_n}$ or amplitude ratio squared                                                | Signal quality                                       |
| SNR in dB                       | $10\log_{10}\left(\frac{P_s}{P_n}\right)=20\log_{10}\left(\frac{A_s}{A_n}\right)$               | dB conversion                                        |
| Noise factor                    | $F=\frac{SNR_{in}}{SNR_{out}}$                                                                  | Amplifier degradation                                |
| Flicker noise                   | approximately `1/f` noise                                                                       | Low-frequency problem                                |
| Flicker noise power density     | $S_f(f)\propto\frac{1}{f}$                                                                      | Noise power per Hz grows at low frequency            |
| Flicker noise power             | $P_f\propto\int_{f_{\min}}^{f_{\max}}\frac{1}{f}\,df=\ln\left(\frac{f_{\max}}{f_{\min}}\right)$ | Total noise power over a bandwidth                   |
| Finite measurement low cutoff   | $f_{\min}\sim\frac{1}{T_{\text{meas}}}$                                                         | Longer measurements include lower frequencies        |
| Flicker power with time         | $P_f\propto\ln(f_{\max}T_{\text{meas}})$                                                        | Since$f_{\min}\sim1/T_{\text{meas}}$               |
| Lock-in idea                    | multiply by reference + low-pass filter                                                           | Extract known-frequency signal                       |
