# Chapter 13-14 Study Notes (Detailed, Beginner-Friendly, Problem Sheet 6 Ready)

Sources:
- `Instrumentation/Course notes/chp13-14.pdf`
- `Instrumentation/Course notes/Problem Sheet 6.pdf`

This file keeps the visual style (screenshots/figures) but adds fuller explanations, first-use symbol definitions, and a clear formula reference so you can solve Problem Sheet 6 later.

## How To Use This File

- Read each section in order once.
- Use the `Key Formula Table` as a quick lookup.
- Use the `Problem Sheet 6 Readiness` section before attempting questions.

## Symbols, Units, And Meanings (first-use glossary)

| Symbol | Meaning | Typical units |
|---|---|---|
| `Vout` | Output voltage of a circuit block | `V` (volts) |
| `Vin` | Input voltage of a circuit block | `V` |
| `A` | Signal amplitude (in Chapter 13 phase detector input) | `V` |
| `phi` | Phase difference between two signals | `rad` (radians) |
| `omega` | Angular frequency (`omega = 2*pi*f`) | `rad/s` |
| `Delta_omega` | Frequency difference between two signals | `rad/s` |
| `f` | Frequency | `Hz` |
| `R` | Electrical resistance | `ohm` |
| `C` | Electrical capacitance | `F` (farads) |
| `tau` | Time constant | `s` |
| `x(t)` | System output as a function of time | depends on system |
| `y(t)` | System input (forcing function) | depends on system |
| `Ks` | Static sensitivity (steady output/input ratio) | output-unit per input-unit |
| `omega0` | Natural angular frequency of a second-order system | `rad/s` |
| `xi` | Damping ratio (dimensionless) | no units |
| `Q` | Heat energy transferred | `J` (joules) |
| `dQ/dt` | Heat transfer rate (thermal power) | `W` (`J/s`) |
| `kappa` | Thermal conductivity (glass wall in PS6 Q2) | `W/(m*K)` |
| `A_surf` | Surface area for heat transfer | `m^2` |
| `d` | Wall thickness | `m` |
| `m` | Mass | `kg` |
| `c` | Specific heat capacity | `J/(kg*K)` |
| `T(t)` | Thermometer/mercury temperature | `degC` or `K` (differences are equivalent) |
| `T0` | Heat-bath temperature (step input) | `degC` or `K` |

## Key Formula Table

| Topic | Formula | What it means |
|---|---|---|
| Phase detector (same frequency) | `<Vout> = (2A/pi) cos(phi)` | DC output depends on phase difference only |
| Phase detector average (integral form) | `<Vout> = (1/T) [int_0^{T/2} Vin dt - int_{T/2}^{T} Vin dt]` | Multiply by `+1/-1` square reference then average |
| Product identity used in mixing | `sin(a)sin(b) = 0.5[cos(a-b)-cos(a+b)]` | Gives difference and sum frequencies |
| Phase detector (frequency mismatch) | `Vout ~ (2A/pi) cos(Delta_omega t)` for small `Delta_omega` | Low-pass keeps difference-frequency term |
| LTI general model | `a0 x + a1 dx/dt + ... + an d^n x/dt^n = b0 y` | Linear time-invariant differential equation form |
| Zero-order static sensitivity | `Ks = b0/a0` | Immediate output scaling |
| First-order model | `a1 dx/dt + a0 x = b0 y` | Exponential settling behavior |
| First-order time constant | `tau = a1/a0` | Speed of settling (`63.2%` at `t=tau`) |
| First-order step response | `x(t) = Ks [x0 + (x_inf - x0)(1 - exp(-t/tau))]` | Standard RC-like curve |
| Second-order model | `a2 d2x/dt2 + a1 dx/dt + a0 x = b0 y` | Oscillatory/settling dynamics |
| Normalized second-order form | `d2x/dt2 + 2 xi omega0 dx/dt + omega0^2 x = forcing` | Makes damping/frequency roles explicit |
| Natural frequency | `omega0^2 = a0/a2` | Base oscillation scale |
| Damping ratio | `xi = a1/(2 sqrt(a0 a2))` | Controls overshoot vs sluggish response |
| Thermal conduction (PS6 Q2) | `dQ/dt = (kappa A_surf/d) (T0 - T)` | Heat flow through bulb wall |
| Thermal first-order ODE | `m c dT/dt = (kappa A_surf/d) (T0 - T)` | Energy balance for thermometer |
| Thermal time constant | `tau_th = (m c d)/(kappa A_surf)` | Thermometer response speed |
| Thermal-electrical analogy | `R_th = d/(kappa A_surf)`, `C_th = m c` | Equivalent RC system |

## Chapter 13: Phase Sensitive Detector (PSD)

## 13.1 Rectification idea and why PSD exists

![Figure 13.1](chp13-14_diagrams/fig_13_1_p1.png)

Plain words:
- Rectification means turning an AC waveform that changes sign into a waveform that stays one sign (or mostly one sign).
- For a sinusoid, this often means flipping negative half-cycles upward.
- This is useful whenever we care about signal magnitude/envelope, not sign.
- In instrumentation, rectification is part of phase-sensitive measurement, where we use a known reference to extract weak signals.

![Figure 13.2](chp13-14_diagrams/fig_13_2_p1.png)

Plain words:
- A bridge rectifier uses four diodes so current through the load always flows in one direction.
- Practical issue: each conducting diode drops voltage (roughly `0.6 V` for silicon), which is a big penalty for small signals.
- That loss motivates synchronous (switching) rectification using active circuits.

## 13.2 Synchronous rectifier principle

![Figure 13.3](chp13-14_diagrams/fig_13_3_p2.png)

![Figure 13.4](chp13-14_diagrams/fig_13_4_p2.png)

Plain words:
- Instead of passive diode conduction, we multiply input by a square-wave reference.
- The square wave acts like a `+1/-1` gain selector: when reference is positive keep sign, when negative flip sign.
- If reference frequency matches input frequency and phase is aligned, output becomes a rectified version with maximum average value.
- This is phase-sensitive: output depends strongly on phase relation between input and reference.

## 13.3 PSD output with phase difference

![Equation context (13.1)](chp13-14_text_snippets/phase_detector_formula_eq13_1.png)

![Figure 13.5](chp13-14_diagrams/fig_13_5_p3.png)

Plain words:
- Keep `omega_in = omega_ref = omega`; only vary phase `phi`.
- After multiply-then-average, output is:
- `<Vout> = (2A/pi) cos(phi)`.
- So:
- `phi = 0` gives maximum positive output.
- `phi = pi/2` gives near zero output.
- `phi = pi` gives maximum negative output.
- This is why PSD can measure phase (or sign) very sensitively.

## 13.4 PSD output with frequency difference

![Equation context (13.2)](chp13-14_text_snippets/mixing_sum_diff_eq13_2.png)

![Equation context (13.3)](chp13-14_text_snippets/frequency_difference_output_eq13_3.png)

![Figure 13.6](chp13-14_diagrams/fig_13_6_p4.png)

Plain words:
- Let input frequency be `omega + Delta_omega`, reference be `omega`.
- Multiplication creates terms at sum and difference frequencies.
- The low-pass stage rejects high-frequency sum terms and keeps low-frequency difference term if it is inside filter bandwidth.
- If `Delta_omega` is small: output oscillates slowly as `cos(Delta_omega t)`.
- If `Delta_omega` is too large for filter bandwidth: output averages to near zero.
- This is the basis of lock-in style detection: only near-reference content survives.

## Chapter 14: Linear Systems

## 14.1 LTI system concept and properties

![Equation context (14.1)](chp13-14_text_snippets/lti_general_equation_eq14_1.png)

![Figure 14.1](chp13-14_diagrams/fig_14_1_p5.png)

![Figure 14.2](chp13-14_diagrams/fig_14_2_p5.png)

Plain words:
- LTI means Linear Time-Invariant.
- Linear: scaling and superposition work (responses add).
- Time-invariant: same input shape gives same behavior regardless of when it is applied.
- Frequency preservation: sinusoid in -> sinusoid out at the same frequency (only amplitude and phase change).
- Superposition: for a sum of sinusoids, compute each output separately and add.
- This is why Fourier/Bode methods work for instrumentation models.

## 14.2 Zero-order and first-order behavior

![Figure 14.3](chp13-14_diagrams/fig_14_3_p6.png)

Plain words:
- Zero-order model has no derivative terms, so output tracks input instantly in the idealized math model.
- Real instruments are almost never perfectly zero-order, but static sensitivity `Ks` is still useful.

![Equation context (14.2)](chp13-14_text_snippets/first_order_equation_eq14_2.png)

![Figure 14.4](chp13-14_diagrams/fig_14_4_p6.png)

![Equation context (first-order response)](chp13-14_text_snippets/first_order_time_response.png)

![Figure 14.5](chp13-14_diagrams/fig_14_5_p7.png)

Plain words:
- First-order systems include one derivative term and show exponential approach to steady state.
- They are memory systems: present rate of change depends on current error to target.
- Time constant `tau` sets response speed; at `t=tau`, output reaches `63.2%` of total step change.
- Typical measurement workflow: wait multiple time constants before reading/calibration to reduce transient error.

## 14.3 Second-order behavior and damping

![Equation context (14.3)](chp13-14_text_snippets/second_order_equation_eq14_3.png)

![Equation context (14.5)](chp13-14_text_snippets/standard_second_order_eq14_5.png)

![Figure 14.6](chp13-14_diagrams/fig_14_6_p7.png)

![Figure 14.7](chp13-14_diagrams/fig_14_7_p9.png)

Plain words:
- Second-order systems can overshoot and oscillate, unlike first-order systems.
- `omega0` sets natural oscillation scale; `xi` controls damping.
- Cases:
- `xi = 0`: undamped oscillation.
- `0 < xi < 1`: underdamped (oscillatory decay).
- `xi = 1`: critically damped (fastest no-overshoot case).
- `xi > 1`: overdamped (slow, no oscillation).
- Instrument design tradeoff is usually speed vs overshoot/ringing.

## Problem Sheet 6 Readiness

## Q1: Phase detector integral and closed form

What the question asks:
- Write average output integral when `Vin = A sin(omega t + phi)` and reference is a square wave at same `omega`.
- Show `<Vout> = (2A/pi) cos(phi)`.

Minimal setup to use:
- Period `T = 2*pi/omega`.
- Reference square wave is `+1` on first half-cycle and `-1` on second half-cycle.
- Therefore:
- `<Vout> = (1/T) [int_0^{T/2} A sin(omega t + phi) dt - int_{T/2}^{T} A sin(omega t + phi) dt]`.
- Evaluate to `(2A/pi) cos(phi)` (sign can flip if reference polarity is defined opposite).

Memorize vs derive:
- Memorize: final form `(2A/pi) cos(phi)` and why phase `pi/2` gives zero.
- Derive in exam: write piecewise integral from square-wave sign, integrate sine, simplify using trig identities.

## Q2 Seminar: thermometer transient + electrical analogy

What the question asks:
- Derive heat-flow equation through glass wall.
- Solve temperature response `T(t)` after step immersion into bath `T0`.
- Identify thermal equivalents of electrical `R`, `C`, and voltage.

Derivation skeleton:
- Conduction through wall:
- `dQ/dt = (kappa A_surf/d) (T0 - T)`.
- Energy storage in mercury:
- `dQ/dt = m c dT/dt`.
- Equate:
- `m c dT/dt = (kappa A_surf/d) (T0 - T)`.
- Rearranged first-order form:
- `dT/dt + (1/tau_th) T = (1/tau_th) T0`,
- where `tau_th = (m c d)/(kappa A_surf)`.
- For `T(0)=0`: `T(t) = T0 [1 - exp(-t/tau_th)]`.

Thermal-electrical mapping:
- Temperature difference `Delta T` <-> voltage `V`.
- Heat flow rate `dQ/dt` <-> current `I`.
- Thermal resistance `R_th = d/(kappa A_surf)` <-> electrical resistance.
- Thermal capacitance `C_th = m c` <-> electrical capacitance.
- Equivalent circuit behavior is first-order RC charging.

Memorize vs derive:
- Memorize: `R_th`, `C_th`, `tau_th = R_th C_th`, and exponential step form.
- Derive in exam: start from conduction law + energy balance, then solve linear first-order ODE.

## Quick Revision Checklist

- I can explain why PSD output depends on `cos(phi)`.
- I can write the PSD average integral over one reference period.
- I can explain sum/difference frequencies from signal multiplication.
- I can classify `xi` cases (`underdamped`, `critical`, `overdamped`).
- I can derive `dQ/dt = (kappa A_surf/d)(T0-T)` and map thermal to RC.
- I can define every symbol and unit before using it in a derivation.
