# Sensor Theory Exam Notes

Purpose: quick recognition notes for sensor/theory questions in the Instrumentation exam.

Sources checked:

- `Complete notes chp1-21.pdf`, especially Chapters 1-3 and 10.
- Past papers `2016-2025`, excluding missing `2021`.

Past-paper pattern:

- PMT/photon detector questions appear repeatedly: `2016`, `2017`, `2018`, `2020`, `2022`, `2025`.
- SiPM appears strongly in `2025`.
- Magnetoresistor + Wheatstone bridge appears in `2016` and `2023`.
- General sensor terms appear in `2023`.
- First-order sensor dynamics appear in `2025`.
- Temperature sensors are in the notes but have appeared less directly in recent papers.

## 1. Universal Sensor Vocabulary

These can be asked for any sensor.

| Term | Meaning | Exam wording |
|---|---|---|
| Sensor | Device that detects a physical quantity. | Example: temperature, magnetic field, light. |
| Transducer | Converts one kind of signal/energy into another. | Sensor usually converts physical input to electrical output. |
| Static sensitivity | Output change per input change. | $S=\frac{d(\text{output})}{d(\text{input})}$ |
| Offset | Nonzero output when true input is zero. | PMT dark current can appear as an offset. |
| Saturation | Output stops increasing linearly at high input. | Sensor or electronics has hit a limit. |
| Range | Input interval where sensor is intended to work. | Outside range: nonlinear or saturated. |
| Resolution | Smallest input change that can be distinguished. | Limited by noise, ADC bits, or physical sensor limits. |
| Loading | Measurement changes the quantity being measured. | Finite input resistance draws current and changes voltage. |
| Bandwidth | Frequency range over which sensor follows input properly. | High bandwidth means it responds to fast changes. |
| Noise floor | Smallest signal hidden by noise. | Lower noise floor means better small-signal detection. |
| Dynamic range | Ratio between largest measurable signal and smallest resolvable signal. | Often given in dB. |

Exam template:

1. Say what physical quantity is being sensed.
2. Say what electrical output is produced.
3. Mention sensitivity, range/saturation, bandwidth, and noise.
4. Mention loading/readout if connected to electronics.

## 2. Temperature Sensors

These are mainly Chapter 2 material. They are less common in recent papers but easy theory marks if asked.

### Thermocouple

What it does:

- Measures temperature difference using a voltage.
- Two dissimilar metals form junctions.
- One junction is at a known reference temperature.
- The other junction is at the temperature to be measured.

Principle:

- A temperature difference creates a thermoelectric voltage.
- This is the Seebeck effect.

Approximate relationship:

$$
V \approx S(T_{\text{hot}}-T_{\text{ref}})
$$

where:

- $V$ is the thermocouple voltage.
- $S$ is the Seebeck coefficient, typically a few $\mu\text{V}/^\circ\text{C}$.
- $T_{\text{hot}}$ is the measured junction temperature.
- $T_{\text{ref}}$ is the reference junction temperature.

Advantages:

- Robust.
- Small.
- Wide range, roughly $-200^\circ\text{C}$ to $+1500^\circ\text{C}$.

Disadvantages:

- Very small voltage, so precision voltage measurement is needed.
- Needs reference junction/cold-junction compensation.
- Not usually the most accurate sensor.

How to recognise:

- Mentions two metals, junctions, generated voltage, temperature difference.

### Platinum RTD / PRTD

What it does:

- Measures temperature through resistance change of platinum.

Principle:

- Platinum resistance increases fairly linearly with temperature.

Approximate relationship:

$$
R(T)\approx R_0(1+\alpha\Delta T)
$$

where:

- $R_0$ is resistance at reference temperature.
- $\alpha$ is temperature coefficient of resistance.

Advantages:

- High accuracy.
- Good linearity.
- Useful over about $-200^\circ\text{C}$ to $+600^\circ\text{C}$.

Disadvantages:

- More expensive than thermistors.
- Can be slower.
- Need resistance measurement, usually with current excitation.

Exam danger:

- Current excitation can self-heat the sensor, causing loading-like error.

### Thermistor

What it does:

- Measures temperature through semiconductor resistance.

Principle:

- Resistance changes strongly with temperature.
- Usually resistance decreases as temperature increases for an NTC thermistor.

Course relationship:

$$
\frac{1}{T}=A+B\ln R+C(\ln R)^3
$$

where:

- $T$ is absolute temperature in kelvin.
- $R$ is resistance.
- $A$, $B$, and $C$ are calibration constants.

Advantages:

- Cheap.
- Small.
- Sensitive.

Disadvantages:

- Nonlinear.
- Smaller useful range than thermocouple.
- Needs calibration/look-up table or linearisation.

How to compare with RTD:

- Thermistor: more sensitive, cheaper, less linear.
- RTD: more accurate, more linear, wider high-accuracy use.

### AD590 IC Temperature Sensor

What it does:

- Produces a current proportional to absolute temperature.

Course fact:

$$
I \approx 1\,\mu\text{A/K}
$$

Advantages:

- Linear output.
- Easy to convert current to voltage using a resistor.
- Electronics handles much of the linearisation.

Disadvantages:

- Needs power supply.
- Limited range compared with thermocouple.

### Mercury / Liquid Thermometer

What it does:

- Converts temperature into liquid column length.

Useful PS1 formula:

$$
\frac{dV}{dT}=3\alpha V
$$

where:

- $V$ is bulb volume.
- $\alpha$ is coefficient of linear expansion.

If the bore area is:

$$
A=\pi r^2
$$

then:

$$
\frac{dl}{dT}=\frac{3\alpha V}{\pi r^2}
$$

Interpretation:

- Bigger bulb volume gives higher sensitivity.
- Smaller bore radius gives higher sensitivity.
- But higher sensitivity can reduce range.

## 3. Photon Detectors: PMT, SPAD, SiPM

This is very high yield.

### Photon Energy and Photon Rate

Photon energy:

$$
E=\frac{hc}{\lambda}
$$

where:

- $E$ is photon energy in joules.
- $h=6.626\times10^{-34}\,\text{J s}$.
- $c=3.00\times10^8\,\text{m/s}$.
- $\lambda$ is wavelength in metres.

Photon rate from optical power:

$$
\dot N=\frac{P}{E}=\frac{P\lambda}{hc}
$$

where:

- $P$ is optical power in watts.
- $\dot N$ is photons per second.

### PMT: Photomultiplier Tube

What it does:

- Detects very low light levels, down to single photons.
- Converts photons into an amplified electron signal.

How it works:

1. Photon hits photocathode.
2. Photocathode emits a photoelectron.
3. Photoelectron is accelerated to first dynode.
4. Dynode impact releases secondary electrons.
5. Repeated dynodes multiply the number of electrons.
6. Electrons arrive at anode.
7. Anode current through load resistor gives voltage signal.

Key terms:

- **Photocathode**: light-sensitive surface that emits electrons.
- **Photoelectron**: electron emitted by the photocathode.
- **Dynode**: electrode that multiplies electrons.
- **Anode**: final collection electrode.
- **Quantum efficiency (QE)**: fraction of incident photons producing detectable photoelectrons.

Quantum efficiency:

$$
N_{\text{photoelectrons}}=\eta N_{\text{photons}}
$$

where $\eta$ is QE.

Dynode gain:

If each dynode has multiplication factor $g$ and there are $N$ dynodes:

$$
G=g^N
$$

Important wording trap:

- If the question says each impact releases **7 additional electrons**, the total leaving that dynode is $8$ electrons including the incoming one.
- Then use $g=8$, not $7$.

Charge per detected photoelectron:

$$
Q=eG
$$

where:

- $e=1.60\times10^{-19}\,\text{C}$.
- $G$ is electron gain.

Charge per incident photon including QE:

$$
Q_{\text{per incident photon}}=\eta eG
$$

PMT output voltage with load resistor:

$$
V=iR_L
$$

If a single-photoelectron pulse has total charge $Q$ and duration approximately $\Delta t$:

$$
I\sim \frac{Q}{\Delta t}
$$

$$
V\sim \frac{Q}{\Delta t}R_L
$$

For a measured voltage pulse:

$$
Q=\int i(t)\,dt=\frac{1}{R_L}\int v(t)\,dt
$$

Gaussian pulse area:

$$
v(t)=V_0e^{-t^2/(2\sigma^2)}
$$

$$
\int_{-\infty}^{\infty}v(t)\,dt=V_0\sqrt{2\pi}\sigma
$$

Gaussian FWHM:

$$
\text{FWHM}=2\sqrt{2\ln2}\,\sigma\approx2.35\sigma
$$

Dark current:

- Current even with zero light.
- Mainly from thermal emission at photocathode.
- Acts like an offset.
- Adds noise.
- Reduces dynamic range.
- Cooling reduces dark current.

PMT advantages:

- High gain.
- Single-photon sensitivity.
- Large sensitive area possible.
- Low capacitance compared with many SiPMs.

PMT disadvantages:

- Needs high voltage, often 1-2 kV.
- Bulky/fragile vacuum tube.
- Magnetic-field sensitive.
- Dark current.

Past-paper asks:

- Calculate dynode gain.
- Calculate charge per photon using QE.
- Estimate current/voltage from single photoelectron pulse.
- Explain dark current.
- Combine with cable/transmission-line readout.

### SPAD: Single-Photon Avalanche Diode

What it does:

- Silicon device that can detect a single photon.

How it works:

1. A diode is reverse-biased above breakdown.
2. A photon creates an electron-hole pair.
3. The carrier triggers avalanche multiplication.
4. The avalanche gives a large electrical pulse.
5. A quenching resistor stops/resets the avalanche.

Key idea:

- In Geiger mode, one photon can trigger a full avalanche.
- A single SPAD cell is almost binary: it fires or does not fire.

Important limitation:

- One SPAD cell cannot distinguish one photon from several arriving at the same time; it gives the same-size pulse once it fires.

### SiPM: Silicon Photomultiplier

What it does:

- Solid-state photon detector made of many SPAD microcells in parallel.

How it works:

1. Each microcell is a SPAD in Geiger mode.
2. Each fired cell gives a standard pulse.
3. All cell outputs are summed.
4. Total output is proportional to number of fired cells.

Course facts:

- A small SiPM may contain thousands of SPAD microcells.
- Cells are typically $10$-$100\,\mu\text{m}$ across.
- Bias voltage is tens of volts.
- Gain can be comparable to PMT, around $10^6$.

Photon detection efficiency:

$$
\text{PDE} = \text{QE}\times \text{avalanche probability}\times \text{fill factor}
$$

where:

- QE is probability photon creates a carrier.
- Avalanche probability is probability carrier triggers Geiger avalanche.
- Fill factor is fraction of sensor area that is active.

SiPM advantages over PMT:

- Compact and robust.
- Low voltage compared with PMT.
- Not a vacuum tube.
- Can photon count with clear single-photoelectron peaks.
- Insensitive to magnetic fields compared with PMTs.

SiPM disadvantages:

- High dark count rate at room temperature.
- Correlated noise: optical/electrical crosstalk and afterpulsing.
- High capacitance.
- Saturates when many microcells have fired.

PMT vs SiPM comparison parameters:

| Parameter | PMT | SiPM |
|---|---|---|
| Gain | Very high, $10^6$-$10^8$ | High, often around $10^6$ |
| Bias voltage | High, kV scale | Lower, tens of V |
| Size/robustness | Bulky vacuum tube | Compact solid-state |
| Magnetic fields | Sensitive | Much less sensitive |
| Dark noise | Usually lower than SiPM | Often high at room temperature |
| Capacitance | Usually lower | Often high |
| Dynamic range | Large but can saturate | Limited by finite number of microcells |
| Photon counting | Possible | Very good, clear fired-cell counting |

2025-style SiPM detector chain:

```text
particle energy deposit
-> scintillator photons
-> optical collection into fibres
-> fibre transmission losses
-> coupling to SiPM
-> PDE
-> avalanche gain
-> output charge/current
-> cable attenuation/reflection
-> amplifier gain/noise
-> ADC quantisation/noise
```

Factors affecting detector threshold:

- Light yield of scintillator, photons per unit energy.
- Optical collection efficiency into fibres.
- Fibre attenuation/transmission.
- Coupling efficiency to SiPM.
- SiPM PDE.
- SiPM gain.
- Dark count/noise rate.
- Electronics noise.
- ADC resolution/quantisation noise.
- Trigger threshold choice.

Single-photoelectron SiPM signal:

If gain is $G$, charge from one fired microcell is:

$$
Q=eG
$$

If this charge appears on capacitance $C$:

$$
V=\frac{Q}{C}
$$

If then attenuated/amplified:

$$
V_{\text{out}}=V_{\text{sensor}}\times(\text{attenuation factor})\times(\text{amplifier gain})
$$

## 4. Magnetic and Resistive Sensors

### Magnetoresistor

What it does:

- Resistance changes with magnetic field.

Course/past-paper model:

$$
R(B)=R+\Delta R
$$

with:

$$
\Delta R = kB
$$

Example from 2023:

$$
k=2\times10^5\,\Omega/\text{T}
$$

and:

$$
|\Delta R|_{\max}=20\,\Omega
$$

Static sensitivity:

$$
\frac{dR}{dB}=k
$$

Saturation field:

$$
B_{\text{sat}}=\frac{\Delta R_{\max}}{k}
$$

Example:

$$
B_{\text{sat}}=\frac{20}{2\times10^5}=100\,\mu\text{T}
$$

### Wheatstone Bridge Readout

Use when resistance changes are small.

Treat as two voltage dividers:

$$
V_A=V_s\frac{R_2}{R_1+R_2}
$$

$$
V_B=V_s\frac{R_4}{R_3+R_4}
$$

Bridge output:

$$
V_{out}=V_A-V_B
$$

Fully active bridge approximation:

$$
V_{out}\approx V_s\frac{\Delta R}{R}
$$

Interpretation:

- Use opposite arms increasing/decreasing to maximise output.
- The bridge converts tiny $\Delta R$ into a differential voltage.
- A difference amplifier or instrumentation amplifier then amplifies it.

Exam chain:

```text
B field -> resistance change -> bridge voltage -> difference amplifier -> output voltage
```

### Strain Gauge

What it does:

- Resistance changes when stretched or compressed.

Principle:

- Strain changes length/cross-sectional area of resistive track.
- Resistance changes by small amount.
- Usually read with Wheatstone bridge.

Likely theory points:

- Sensitive to tiny mechanical deformation.
- Often differential bridge readout cancels common temperature effects.
- Needs amplification due small bridge output.

### Hall Probe

What it does:

- Measures magnetic field using Hall voltage.

Principle:

- Current through conductor/semiconductor in magnetic field experiences Lorentz force.
- Charges deflect sideways, building transverse voltage.

Basic relationship:

$$
V_H \propto IB
$$

where:

- $I$ is bias current.
- $B$ is magnetic field.

Advantages:

- Direct magnetic-field measurement.
- Solid-state and robust.

Limitations:

- Sensitivity and offset matter.
- Temperature dependence.
- Needs bias current.

## 5. Diodes, Rectifiers, and Shot Noise

These are not always “sensors”, but diode/noise theory has appeared.

Forward-biased diode approximation:

$$
V_D\approx0.6\,\text{V}
$$

Current through diode + series resistor:

$$
I\approx\frac{V_{\text{supply}}-V_D}{R}
$$

Shot noise current:

$$
i_n=\sqrt{2eIB}
$$

Voltage noise across resistor:

$$
v_n=i_nR
$$

Dark current / leakage current:

- Current with no intended signal.
- Adds shot noise.
- Can appear as offset.

Precision rectifier / super-diode:

- Uses op-amp feedback to compensate diode forward drop.
- Apparent turn-on voltage becomes roughly:

$$
\frac{V_D}{A}
$$

where $A$ is op-amp open-loop gain.

## 6. First-Order Sensor Dynamics

This is the 2025 Q3 style.

General first-order sensor equation:

$$
a_1\frac{dx}{dt}+a_0x=b_0y
$$

where:

- $y(t)$ is input/forcing physical quantity.
- $x(t)$ is sensor output/response.

Transfer function:

$$
G(s)=\frac{X(s)}{Y(s)}
$$

Taking Laplace with zero initial condition:

$$
(a_1s+a_0)X(s)=b_0Y(s)
$$

So:

$$
G(s)=\frac{b_0}{a_1s+a_0}
$$

Write in standard form:

$$
G(s)=\frac{K_s}{\tau s+1}
$$

where:

$$
K_s=\frac{b_0}{a_0}
$$

and:

$$
\tau=\frac{a_1}{a_0}
$$

Meanings:

- $K_s$ is static sensitivity: final output per input in steady state.
- $\tau$ is time constant: response speed.

Step response:

For unit step input:

$$
x(t)=K_s(1-e^{-t/\tau})
$$

Time to 95%:

$$
0.95=1-e^{-t_{95}/\tau}
$$

$$
t_{95}=-\tau\ln(0.05)\approx3\tau
$$

Bandwidth relation:

$$
\omega_c=\frac{1}{\tau}
$$

$$
f_c=\frac{1}{2\pi\tau}
$$

Plain words:

- Large $\tau$ means slow sensor and low bandwidth.
- Small $\tau$ means fast sensor and high bandwidth.

## 7. Readout Circuits That Often Attach to Sensors

### Load Resistor Current Readout

For a current-output sensor:

$$
V=iR_L
$$

Problem:

- To get large voltage, choose large $R_L$.
- But large $R_L$ with sensor capacitance gives large time constant:

$$
\tau=R_LC
$$

So bandwidth falls:

$$
f_c=\frac{1}{2\pi R_LC}
$$

### Transimpedance Amplifier

For a sensor acting like a current source:

$$
V_{out}=-i_{in}R_f
$$

Advantages:

- Input node is virtual ground, so input impedance is low.
- Good for current sources.
- Op-amp output impedance is low, so next stage loading is reduced.
- Better bandwidth with high-capacitance sensors than a simple large load resistor.

Trade-off:

- Larger $R_f$ gives larger signal/sensitivity.
- But output clips at supply rails for large current.

Range choice:

$$
R_f\lesssim\frac{V_s}{i_{\max}}
$$

### Cable / Transmission Line After Sensor

If sensor signal is fast and cable is long, use transmission-line ideas.

Characteristic impedance:

$$
Z_0=\sqrt{\frac{L'}{C'}}
$$

Propagation speed:

$$
v=\frac{1}{\sqrt{L'C'}}
$$

Reflection coefficient:

$$
\Gamma=\frac{Z_L-Z_0}{Z_L+Z_0}
$$

Matched load:

$$
Z_L=Z_0
$$

means no reflection at load.

Cable attenuation in dB:

For voltage attenuation $A_{\text{dB}}$:

$$
\frac{V_{\text{in}}}{V_{\text{out}}}=10^{A_{\text{dB}}/20}
$$

## 8. What To Memorise First

Highest yield:

1. PMT operation and formulas:

$$
E=\frac{hc}{\lambda},\quad Q=eG,\quad Q_{\text{incident photon}}=\eta eG
$$

2. SiPM vs PMT comparison:

- SiPM = many SPAD cells.
- Lower voltage, compact, high dark count, high capacitance.
- PMT = vacuum dynode chain, high voltage, low-light sensitivity.

3. Wheatstone bridge:

$$
V_A=V_s\frac{R_2}{R_1+R_2},\quad V_B=V_s\frac{R_4}{R_3+R_4},\quad V_{out}=V_A-V_B
$$

4. First-order sensor:

$$
G(s)=\frac{K_s}{\tau s+1},\quad K_s=\frac{b_0}{a_0},\quad \tau=\frac{a_1}{a_0}
$$

5. Noise:

$$
v_n=\sqrt{4k_BTRB},\quad i_n=\sqrt{2eIB}
$$

6. TIA:

$$
V_{out}=-i_{in}R_f
$$

## 9. If A Weird Sensor Appears

Use this template:

1. What physical input is it sensing?
2. What electrical quantity changes: voltage, current, resistance, charge, capacitance?
3. Is the output single-ended or differential?
4. Does it need a bridge, load resistor, TIA, or amplifier?
5. What limits it: offset, saturation, noise, bandwidth, loading, dynamic range?
6. If it is dynamic, can it be modelled as first-order with $K_s$ and $\tau$?

Most exam sensor questions are not asking deep detector physics. They are asking whether you can connect:

```text
physical input -> sensor output -> readout circuit -> noise/bandwidth/ADC limit
```

