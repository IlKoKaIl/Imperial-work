# Chapters 7-8 Exam Notes: RC Circuits and Filters

Sources:

- `Instrumentation/Course notes/chp7-8.pdf`
- Related filter questions in Problem Sheets 3-5 and past papers.

Purpose: compact exam notes for RC transient response, low-pass/high-pass filters, Bode plots, filter loading, and the filter parts of PS3/PS4.

## 0. What Chapters 7-8 Are Really About

These chapters teach one big instrumentation idea:

> Circuits do not treat all frequencies equally.

An RC circuit can be analysed in two complementary ways:

| View | Used when | Main tool |
|---|---|---|
| Time domain | Step inputs, switches, transients | $i=C\dfrac{dV}{dt}$ and differential equations |
| Frequency domain | Sinusoidal steady-state, Bode plots, filters | $Z_C=\dfrac{1}{j\omega C}$ and voltage dividers |

Definitions:

- Transient response: the temporary behaviour after something changes, such as a switch closing.
- Steady-state response: the long-term response after transients have died away.
- Filter: a system that changes signal amplitude/phase depending on frequency.
- Passive filter: made from $R$, $C$, and $L$ only; it cannot amplify, so maximum gain is $0\,\mathrm{dB}$.
- Active filter: uses an active device such as an op-amp; it can buffer and amplify.

## 1. Core Components

### Resistor

A resistor obeys Ohm's law:

$$
V=IR
$$

Definitions:

- $V$: voltage across the resistor, in volts.
- $I$: current through the resistor, in amperes.
- $R$: resistance, in ohms.

A resistor dissipates electrical energy as heat.

### Capacitor

A capacitor stores charge and electric-field energy.

$$
Q=CV
$$

Definitions:

- $Q$: charge stored, in coulombs.
- $C$: capacitance, in farads.
- $V$: voltage across the capacitor, in volts.

Current-voltage relation:

$$
I=C\frac{dV}{dt}
$$

Important physical rule:

- Capacitor voltage cannot jump instantly.
- If it jumped instantly, $dV/dt$ would be infinite and would require infinite current.

## 2. Impedance in AC Circuits

For sinusoidal steady-state analysis, components are represented by complex impedances.

Capacitor impedance:

$$
Z_C=\frac{1}{j\omega C}
$$

Definitions:

- $Z_C$: capacitor impedance, in ohms.
- $j$: imaginary unit, $j^2=-1$.
- $\omega$: angular frequency, in rad/s.
- $C$: capacitance, in farads.

Plain words:

- At low frequency, $\omega$ is small, so $Z_C$ is large: capacitor acts like an open circuit.
- At high frequency, $\omega$ is large, so $Z_C$ is small: capacitor acts like a short circuit.
- This frequency-dependent behaviour is why RC circuits can filter signals.

## 3. Voltage Divider Method

For two impedances in series:

$$
V_{out}=V_{in}\frac{Z_{out}}{Z_1+Z_2}
$$

Definitions:

- $V_{in}$: input voltage.
- $V_{out}$: output voltage.
- $Z_{out}$: impedance across which the output voltage is measured.
- $Z_1$ and $Z_2$: series impedances.

This is the main method for deriving filter transfer functions.

## 4. RC Low-Pass Filter

Circuit:

- Resistor and capacitor in series.
- Output is measured across the capacitor.

```text
Vin -- R --+-- Vout
           |
           C
           |
          ground
```

Transfer function:

$$
G(\omega)=\frac{V_{out}}{V_{in}}=\frac{Z_C}{R+Z_C}
$$

Substitute $Z_C=1/(j\omega C)$:

$$
G(\omega)=\frac{1}{1+j\omega RC}
$$

Equivalent rationalised form:

$$
G(\omega)=\frac{1-j\omega RC}{1+(\omega RC)^2}
$$

Magnitude:

$$
|G(\omega)|=\frac{1}{\sqrt{1+(\omega RC)^2}}
$$

Phase:

$$
\phi=-\tan^{-1}(\omega RC)
$$

Cutoff frequency:

$$
\omega_c=\frac{1}{RC}
$$

$$
f_c=\frac{1}{2\pi RC}
$$

At cutoff:

$$
|G|=\frac{1}{\sqrt{2}}
$$

This is the $-3\,\mathrm{dB}$ point.

Plain words:

- Low frequency: capacitor impedance is large, so most voltage appears across capacitor. Output follows input.
- High frequency: capacitor impedance is small, so it pulls output toward ground. Output becomes small.
- Therefore it passes low frequencies and rejects high frequencies.
- The output lags the input because the phase is negative.

## 5. RC High-Pass Filter

Circuit:

- Capacitor and resistor in series.
- Output is measured across the resistor.

```text
Vin -- C --+-- Vout
           |
           R
           |
          ground
```

Transfer function:

$$
G(\omega)=\frac{V_{out}}{V_{in}}=\frac{R}{R+Z_C}
$$

Substitute $Z_C=1/(j\omega C)$:

$$
G(\omega)=\frac{j\omega RC}{1+j\omega RC}
$$

Magnitude:

$$
|G(\omega)|=\frac{\omega RC}{\sqrt{1+(\omega RC)^2}}
$$

Phase:

$$
\phi=90^\circ-\tan^{-1}(\omega RC)
$$

Cutoff frequency:

$$
\omega_c=\frac{1}{RC}
$$

$$
f_c=\frac{1}{2\pi RC}
$$

Plain words:

- Low frequency/DC: capacitor blocks current, so output is near zero.
- High frequency: capacitor impedance is small, so signal reaches the resistor. Output follows input.
- Therefore it rejects DC/low frequencies and passes high frequencies.
- A high-pass filter is also called a CR circuit when the capacitor comes before the resistor and output is across the resistor.

## 6. Step Responses and Time Constant

Time constant:

$$
\tau=RC
$$

Definitions:

- $\tau$: time constant, in seconds.
- $R$: resistance, in ohms.
- $C$: capacitance, in farads.

Low-pass output for a step input $V_{in}=V_0u(t)$:

$$
V_{out}(t)=V_C(t)=V_0\left(1-e^{-t/RC}\right)
$$

High-pass output for a step input:

$$
V_{out}(t)=V_R(t)=V_0e^{-t/RC}
$$

Definitions:

- $V_0$: step amplitude.
- $u(t)$: unit step, equal to 0 before $t=0$ and 1 after $t=0$.

Useful time-constant facts:

| Time | Low-pass charging value |
|---|---|
| $t=\tau$ | about $63\%$ of final value |
| $t=2\tau$ | about $86\%$ of final value |
| $t=3\tau$ | about $95\%$ of final value |
| $t=5\tau$ | about $99\%$ of final value |

Plain words:

- A low-pass filter responds slowly to a sudden step because the capacitor needs time to charge.
- A high-pass filter gives a spike/decay for a step because it reacts to the sudden change, then blocks DC.

Initial condition rule:

- A first-order differential equation needs one initial condition.
- For capacitors, the key initial condition is usually the initial capacitor voltage.
- If the capacitor is initially uncharged, $V_C(0)=0$.
- If the capacitor was already charged, the transient can look different, including a negative spike when the input is switched back to zero.

### Solving the Low-Pass Step With an Integrating Factor

For the low-pass circuit, the output is the capacitor voltage:

$$
V_{out}=V_C
$$

Kirchhoff's voltage law gives:

$$
V_0=iR+V_{out}
$$

The capacitor current relation is:

$$
i=C\frac{dV_C}{dt}=C\frac{dV_{out}}{dt}
$$

Substitute this into Kirchhoff's law:

$$
V_0=RC\frac{dV_{out}}{dt}+V_{out}
$$

Rearrange into standard first-order form:

$$
\frac{dV_{out}}{dt}+\frac{1}{RC}V_{out}=\frac{V_0}{RC}
$$

Standard integrating-factor method:

For:

$$
\frac{dy}{dt}+p(t)y=q(t)
$$

use:

$$
\mu(t)=e^{\int p(t)\,dt}
$$

For the RC equation:

$$
p(t)=\frac{1}{RC}
$$

so:

$$
\mu(t)=e^{t/(RC)}
$$

The trick works because:

$$
\frac{d}{dt}\left(\mu y\right)=\mu\frac{dy}{dt}+y\frac{d\mu}{dt}
$$

and the integrating factor is chosen so that:

$$
\frac{d\mu}{dt}=p\mu
$$

Therefore:

$$
\mu\left(\frac{dy}{dt}+py\right)=\frac{d}{dt}(\mu y)
$$

In this case:

$$
e^{t/(RC)}\left(\frac{dV_{out}}{dt}+\frac{1}{RC}V_{out}\right)
=
\frac{d}{dt}\left(V_{out}e^{t/(RC)}\right)
$$

This is why the left-hand side becomes one neat derivative.

### High-Pass Step Derivation Skeleton

For the high-pass/CR circuit, output is across the resistor:

$$
V_{out}=V_R=iR
$$

With a DC step applied for $t>0$:

$$
V_0=V_R+V_C
$$

Differentiate both sides. Since $V_0$ is constant for $t>0$:

$$
0=\frac{dV_R}{dt}+\frac{dV_C}{dt}
$$

Using $V_R=iR$ and $i=C\dfrac{dV_C}{dt}$ gives:

$$
0=R\frac{di}{dt}+\frac{i}{C}
$$

or:

$$
RC\frac{di}{dt}+i=0
$$

Trial solution:

$$
i(t)=Ae^{st}
$$

Substitution gives:

$$
s=-\frac{1}{RC}
$$

If the capacitor is initially uncharged, then at $t=0$ it behaves like a short and:

$$
i(0)=\frac{V_0}{R}
$$

so:

$$
i(t)=\frac{V_0}{R}e^{-t/RC}
$$

Therefore:

$$
V_{out}(t)=V_R(t)=V_0e^{-t/RC}
$$

## 7. Bode Plot Essentials

Magnitude in decibels:

$$
G_{dB}=20\log_{10}|G|
$$

Why 20:

- Voltage gain is an amplitude ratio.
- Power is proportional to voltage squared, so amplitude ratios use $20\log_{10}$.

First-order slopes:

| Filter | Region | Slope |
|---|---|---|
| Low-pass | Above cutoff | $-20\,\mathrm{dB/decade}$ |
| High-pass | Below cutoff | $+20\,\mathrm{dB/decade}$ |

Definitions:

- One decade means frequency changes by a factor of 10.
- One octave means frequency changes by a factor of 2.
- $-20\,\mathrm{dB/decade}$ means the voltage gain falls by a factor of 10 for each factor-of-10 increase in frequency.
- $20\,\mathrm{dB/decade}$ is approximately $6\,\mathrm{dB/octave}$.

At cutoff:

$$
|G|=\frac{1}{\sqrt{2}}
$$

$$
G_{dB}=20\log_{10}\left(\frac{1}{\sqrt{2}}\right)\approx -3\,\mathrm{dB}
$$

## 8. Integration and Differentiation Approximations

Low-pass as an integrator:

If $\omega RC \gg 1$, then:

$$
G(\omega)=\frac{1}{1+j\omega RC}\approx \frac{1}{j\omega RC}
$$

Since division by $j\omega$ corresponds to integration, the output approximately integrates the input.

High-pass as a differentiator:

If $\omega RC \ll 1$, then:

$$
G(\omega)=\frac{j\omega RC}{1+j\omega RC}\approx j\omega RC
$$

Since multiplication by $j\omega$ corresponds to differentiation, the output approximately differentiates the input.

Plain words:

- Low-pass filters smooth signals, so in the right limit they act like integrators.
- High-pass filters respond to changes, so in the right limit they act like differentiators.
- A high-pass differentiator turns a square wave into alternating positive/negative spikes.
- A low-pass integrator can turn a square wave into a triangle-like waveform if the time constant is long compared with the input period.

## 9. Filter Types

| Type | Passes | Rejects | Typical use |
|---|---|---|---|
| Low-pass | Low frequencies | High frequencies | Smoothing, anti-alias filtering |
| High-pass | High frequencies | DC/low frequencies | AC coupling, removing offsets |
| Band-pass | A middle band | Low and high extremes | Selecting a frequency range |
| Band-stop/notch | Everything except one band | A narrow unwanted band | Removing mains hum |

Filter order:

- A first-order filter has one energy-storage element and roll-off of about $20\,\mathrm{dB/decade}$.
- Higher-order filters roll off more steeply.
- Each extra first-order pole adds another $-20\,\mathrm{dB/decade}$ to high-frequency roll-off.

Ideal filter characteristics:

- Flat pass-band: wanted frequencies pass with constant gain.
- Sharp knee: transition from pass to reject happens over a narrow frequency range.
- Fast roll-off: unwanted frequencies are strongly attenuated soon after cutoff.
- Real filters compromise between flatness, sharpness, roll-off, complexity, and loading.

Anti-aliasing connection:

- A low-pass anti-alias filter should attenuate frequencies above the Nyquist frequency before sampling.
- A first-order RC filter only rolls off at $20\,\mathrm{dB/decade}$, so it may not remove high-frequency components strongly enough.
- Any remaining components above Nyquist can still alias after sampling.

## 10. Cascaded Filters and Loading

Chaining two first-order low-pass filters can ideally give a second-order response:

$$
\text{roll-off} \approx -40\,\mathrm{dB/decade}
$$

But this only works cleanly if the second stage does not load the first.

Loading means one circuit stage draws enough current from the previous stage to change its expected voltage or transfer function.

Good design rule:

- Source impedance should be low.
- Load/input impedance should be high.
- If the next stage has very high input impedance, it does not significantly load the filter.

Why op-amps help:

- An op-amp input has very high impedance.
- So an op-amp can buffer a filter stage.
- Active filters can also provide gain, unlike passive RC filters.

PS4 relevance:

- In PS4 Q2, the op-amp input is assumed to have very high impedance.
- Therefore the high-pass input filter and the non-inverting amplifier can be analysed separately.
- Total gain is approximately:

$$
G_{\text{total}}(\omega)=G_{\text{filter}}(\omega)\,G_{\text{amp}}
$$

## 11. RLC Quick Reference

Inductor impedance:

$$
Z_L=j\omega L
$$

Definitions:

- $L$: inductance, in henries.
- $Z_L$: inductor impedance, in ohms.

Resonant angular frequency:

$$
\omega_0=\frac{1}{\sqrt{LC}}
$$

Series RLC total impedance:

$$
Z=R+j\omega L-\frac{j}{\omega C}
$$

KVL for the series RLC circuit:

$$
v_R+v_L+v_C=v_{in}
$$

For a step input, the current obeys:

$$
L\frac{d^2i}{dt^2}+R\frac{di}{dt}+\frac{1}{C}i=0
$$

Damping ratio:

$$
\xi=\frac{R}{2}\sqrt{\frac{C}{L}}
$$

At resonance:

- Capacitive and inductive reactances cancel in a series RLC circuit.
- This happens when $\omega L=\dfrac{1}{\omega C}$.
- The circuit may produce a peak or notch depending on where the output is taken.
- At very low frequency, the capacitor dominates and $|Z|$ is large.
- At very high frequency, the inductor dominates and $|Z|$ is large.
- Near resonance, impedance is smallest and current is largest.

## 12. PS3 Q3 Method

PS3 Q3 asks about a low-pass filter and converting it to a high-pass filter.

Method for low-pass step response:

1. Identify that output is across the capacitor.
2. Use the known capacitor charging equation.
3. For input $V_0u(t)$, write:

$$
V_{out}(t)=V_0\left(1-e^{-t/RC}\right)
$$

Method to make high-pass filter:

- Swap where the output is taken.
- For a standard high-pass, put capacitor in series first and measure output across the resistor.

Method for high-pass complex gain:

1. Write $Z_C=1/(j\omega C)$.
2. Use voltage divider:

$$
G(\omega)=\frac{R}{R+Z_C}
$$

3. Simplify:

$$
G(\omega)=\frac{j\omega RC}{1+j\omega RC}
$$

4. Limiting values:

$$
|G|\to 0 \quad \text{as} \quad \omega\to 0
$$

$$
|G|\to 1 \quad \text{as} \quad \omega\to \infty
$$

5. Cutoff:

$$
\omega_c=\frac{1}{RC}
$$

6. Below cutoff, high-pass gain rises at:

$$
+20\,\mathrm{dB/decade}
$$

## 13. How Chapters 7-8 Connect To PS3

You do not need to fully read Chapters 7-8 before starting PS3.

Use only these parts for PS3:

| PS3 part | Need from these notes |
|---|---|
| Q3(a) | Low-pass step response |
| Q3(b) | High-pass circuit arrangement |
| Q3(c) | High-pass transfer function |
| Q3(d) | Low/high frequency limits |
| Q3(e) | Cutoff frequency $\omega_c=1/RC$ |
| Q3(f) | $20\,\mathrm{dB/decade}$ Bode slope |

If you get stuck, start with the voltage-divider formula. Most RC filter questions collapse once the correct output impedance is chosen.

## 14. PS4 Q2 Method: High-Pass Input Plus Non-Inverting Amplifier

PS4 Q2 combines a high-pass filter with a non-inverting amplifier.

High-pass input filter:

$$
G_{\text{HP}}(\omega)=\frac{j\omega R_{in}C_{in}}{1+j\omega R_{in}C_{in}}
$$

Magnitude:

$$
|G_{\text{HP}}|=\frac{\omega R_{in}C_{in}}{\sqrt{1+(\omega R_{in}C_{in})^2}}
$$

Cutoff:

$$
\omega_c=\frac{1}{R_{in}C_{in}}
$$

$$
f_c=\frac{1}{2\pi R_{in}C_{in}}
$$

Non-inverting amplifier gain:

$$
G_{\text{amp}}=1+\frac{R_f}{R_0}
$$

Total magnitude gain:

$$
|G_{\text{total}}|=|G_{\text{HP}}|\,G_{\text{amp}}
$$

Why this circuit is useful:

- The high-pass input blocks DC offsets.
- The op-amp amplifies the remaining AC signal.
- This is useful for small AC signals riding on unwanted DC background.
- At high frequency the circuit may also roll off due to real op-amp bandwidth, producing an upper cutoff.
- With both a lower and upper cutoff, the full system behaves like a band-pass amplifier.

PS4 Q2 exam steps:

1. Calculate the input high-pass cutoff from $R_{in}$ and $C_{in}$.
2. Calculate $|G_{\text{HP}}|$ at the requested frequency.
3. Calculate the non-inverting op-amp gain $1+R_f/R_0$.
4. Multiply filter gain by amplifier gain.
5. For the Bode sketch, show low-frequency high-pass rise, mid-band flat gain, then high-frequency roll-off.
