# Chapters 1-3 Exam Notes: Performance, Sensors, Impedance

Sources:

- `Instrumentation/Course notes/chp1-3.pdf`
- `Instrumentation/Course notes/Problem sheets + solutions/Problem Sheet 1.pdf`

Purpose: compact notes for Problem Sheet 1 and exam-style sensor questions.

## 1. Measurement Performance

Core idea:

- An instrument never gives the unknowable "true value" exactly.
- The job is to estimate the measurement and its error/uncertainty well enough for the task.

Definitions:

| Term | Meaning | Exam-use wording |
|---|---|---|
| True value | Ideal/unknown actual value of the physical quantity | Usually cannot be known exactly |
| Error | Difference between measured value and true value | Can be systematic or random |
| Accuracy | Closeness to true value | Good accuracy means low total error |
| Precision | Repeatability/spread of repeated measurements | Precise measurements can still be offset |
| Resolution | Smallest distinguishable change | Limited by scale divisions, ADC bits, noise |
| Sensitivity | Change in output per change in input | Slope of calibration curve |
| Range | Input interval over which instrument is intended to work | Outside range may saturate or become nonlinear |
| Saturation | Output stops increasing properly even though input keeps increasing | Sensor has hit a physical/electronic limit |
| Offset | Non-zero output when true input should be zero | Correctable by zero calibration if stable |
| Linearity | Output proportional to input | Nonlinear sensors may need calibration curve |
| Hysteresis | Output depends on previous history | Common in mechanical systems |

Plain words:

- Accuracy asks: "Is it right?"
- Precision asks: "Does it repeat?"
- Sensitivity asks: "How much output do I get per input?"
- Resolution asks: "What is the smallest change I can see?"
- Saturation asks: "Where does the instrument stop behaving?"

## 2. Calibration

Calibration means comparing the instrument to a trusted reference and using that comparison to correct or quantify error.

Basic linear calibration:

$y = mx + c$

- $x$: input/true/reference value, e.g. actual temperature.
- $y$: instrument output, e.g. voltage, current, scale reading.
- $m$: gradient/slope of the calibration line. This is the instrument sensitivity.
- $c$: zero offset. This is the output when the true input is zero.

Plain words:

- Calibration turns raw instrument output into a meaningful physical value.
- If the output is linear, two things matter most: the slope and the offset.
- If the sensor is nonlinear, you need a calibration curve rather than one straight-line equation.

How to remove zero offset:

- Measure output when input should be zero.
- Subtract that baseline from future readings.
- Repeat if offset drifts with temperature/time.

Exam pattern:

1. Identify reference standard.
2. Measure several known inputs.
3. Fit calibration line or curve.
4. Correct offset and sensitivity.
5. State remaining uncertainty.

## 3. Decibels

Use decibels for ratios.

| Quantity | Formula |
|---|---|
| Power ratio | $L_{dB}=10\log_{10}\left(\frac{P_2}{P_1}\right)$ |
| Voltage/current amplitude ratio | $L_{dB}=20\log_{10}\left(\frac{V_2}{V_1}\right)$ |

Quick values:

- `+20 dB` amplitude = `x10`.
- `+40 dB` amplitude = `x100`.
- `-3 dB` power = half power; amplitude about `0.707`.

## 4. Loading and Impedance

Loading happens when connecting the instrument changes the thing being measured.

Voltage divider model:

$V_L = \frac{V_s R_L}{R_s+R_L}$

- $V_s$: source voltage before the load is connected. Think of this as the ideal/open-circuit source voltage.
- $V_L$: voltage actually appearing across the load after connection.
- $R_s$: source/output resistance. This is internal resistance of the signal source or previous circuit.
- $R_L$: load/input resistance. This is the resistance of whatever you connect to the source.

Why this equation matters:

- The source resistance and load resistance form a voltage divider.
- If $R_L$ is not much larger than $R_s$, the load "steals" voltage and changes the measurement.
- That measurement disturbance is called loading.

To measure voltage without loading:

- Make instrument input impedance much larger than source impedance.
- Rule: $R_{in} >> R_s$.

Why:

- In the divider equation, if $R_L$ is huge compared with $R_s$, then $R_s+R_L \approx R_L$.
- Therefore $V_L \approx V_s$.
- So the measuring instrument sees almost the original voltage and does not significantly disturb the circuit.

Example:

- If $R_s=1\,k\Omega$ and $R_{in}=1\,M\Omega$, almost all the voltage appears at the instrument input.
- If $R_s=1\,k\Omega$ and $R_{in}=1\,k\Omega$, the measured voltage is only half the source voltage.

To transfer maximum power:

- Match load to source: $R_L=R_s$.
- But efficiency is only 50% in the matched case for simple resistive source/load.

Why maximum power occurs at $R_L=R_s$:

- If $R_L$ is very small, current is large but the voltage across the load is small.
- If $R_L$ is very large, voltage is large but current is tiny.
- Maximum load power happens at the balance point between these two effects: $R_L=R_s$.

Important distinction:

- Maximum power transfer is not the same as best voltage measurement.
- For measurement, you usually want bridging: $R_{in} >> R_s$.
- For RF/transmission/power delivery, you often want matching: $R_L=R_s$ or $R_L=Z_0$.

Impedance bridging:

- Used for voltage signals.
- High input impedance load.
- Preserves voltage amplitude.
- Goal: measure the voltage while drawing as little current as possible.
- Typical instrumentation case: oscilloscope or voltmeter input connected to a sensor output.

Impedance matching:

- Used for RF/transmission/power transfer.
- Load equals source or line impedance.
- Avoids reflections and maximizes power transfer.
- Goal: deliver power cleanly or stop travelling-wave reflections.
- Typical case: coaxial cable terminated with its characteristic impedance, e.g. 50 ohm.

## 5. Sensors and Transducers

Sensor/transducer:

- A sensor detects a physical quantity.
- A transducer converts one form of energy/signal into another, often physical input to electrical output.

Plain words:

- A thermometer is a sensor because it detects temperature.
- A microphone is a transducer because it converts sound pressure into voltage.
- In instrumentation, the distinction is often blurred because most sensors also transduce the quantity into an electrical signal.

Temperature transducers:

- Mercury thermometer: thermal expansion changes column length.
- Thermistor/RTD: resistance changes with temperature.
- Semiconductor sensor: current/voltage changes with temperature.

Photon sensors:

- PMT = photomultiplier tube.
- SiPM = silicon photomultiplier.
- PMT: a photon hits a photocathode and releases a photoelectron; a dynode chain multiplies that electron into many electrons.
- SiPM: a solid-state photon sensor made from many avalanche photodiode microcells; detected photons create electrical pulses.

PMT parts:

- Photon: packet of light energy.
- Photocathode: light-sensitive surface that emits an electron when it absorbs a photon.
- Photoelectron: electron emitted from the photocathode.
- Dynode: electrode that emits several secondary electrons when struck by one electron.
- Anode: final collection electrode where the multiplied electron signal is collected.
- Quantum efficiency, $\eta$: fraction of incident photons that successfully produce photoelectrons.

Photomultiplier tube gain:

- If each dynode gives multiplication factor $g$ and there are $N$ dynodes, total gain is roughly $g^N$.
- Include quantum efficiency: detected photoelectrons per incident photon = $\eta$.
- Example: if $\eta=0.35$, then about 35% of incident photons produce a photoelectron.

Photon energy:

$E = \frac{hc}{\lambda}$

Terms:

- $E$: energy of one photon, in joules (J).
- $h$: Planck's constant, $6.626\times10^{-34}\,J\,s$.
- $c$: speed of light in vacuum, about $3.00\times10^8\,m/s$.
- $\lambda$: wavelength of the light, in metres.

Meaning:

- Shorter wavelength means higher photon energy.
- Green light at lower wavelength has more energy per photon than red light.

Photon rate from optical power:

$\dot{N}=\frac{P}{E}=\frac{P\lambda}{hc}$

Terms:

- $\dot{N}$: photon rate, photons per second.
- $P$: optical power, in watts. Since $1\,W=1\,J/s$, power divided by photon energy gives photons per second.

Photocurrent estimate:

$I = e \times \text{electron rate}$

Terms:

- $I$: current, in amperes (A).
- $e$: elementary charge, $1.602\times10^{-19}\,C$.
- Electron rate: electrons per second reaching the anode or output.

## Problem Sheet 1 Focus

High-yield question types:

- Explain saturation/offset for real sensors.
- Derive thermometer static sensitivity from thermal expansion.
- Use PMT quantum efficiency, photon energy, and dynode gain.
- Discuss interference/environmental effects.
- Compare measurement range, sensitivity, and saturation.

Thermometer static sensitivity from PS1:

- Mercury volume expansion: $dV/dT = 3\alpha V$.
- Bore cross-sectional area: $A=\pi r^2$.
- Column length change: $dV = A dl$.
- Therefore: $dl/dT = 3\alpha V/(\pi r^2)$.

Terms:

- $V$: bulb volume.
- $\alpha$: coefficient of linear expansion, in $K^{-1}$.
- $r$: bore radius.
- $l$: mercury column length.
- $T$: temperature.

Plain words:

- More bulb volume gives more expanding mercury, so higher sensitivity.
- Smaller bore radius means the same expanded volume makes the column rise further, so higher sensitivity.
- But higher sensitivity usually reduces usable range because the column reaches the end sooner.

PMT method:

1. Photon energy: $E=\frac{hc}{\lambda}$.
2. Incident photon rate: $\dot{N}=\frac{P}{E}$.
3. Detected photoelectron rate: $\eta\dot{N}$.
4. Dynode multiplication: $g^N$.
5. Output electron rate: $\eta\dot{N}g^N$.
6. Current: $I=e\eta\dot{N}g^N$.
