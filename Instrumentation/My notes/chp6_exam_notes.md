# Chapter 6 Exam Notes: Fourier Theory of Signals

Sources:

- `Instrumentation/Course notes/chp6.pdf`
- `Instrumentation/Course notes/Problem sheets + solutions/Problem Sheet 3.pdf`

Purpose: compact exam notes for Fourier transforms, spectra, bandwidth, pulse-width questions, and PS3 Q1/Q2.

## 1. Big Idea

Fourier theory says a signal can be described in two equivalent ways:

| View | Meaning | Example symbol |
|---|---|---|
| Time domain | How the signal changes with time | $f(t)$ |
| Frequency domain | What frequencies are present in the signal | $F(\omega)$ |

Definitions:

- $t$: time, in seconds.
- $f(t)$: signal amplitude as a function of time.
- $\omega$: angular frequency, in radians per second.
- $f$: ordinary frequency, in hertz.
- $\omega = 2\pi f$.
- $F(\omega)$: Fourier transform of $f(t)$, showing frequency content.

Plain words:

- A waveform is not just a shape in time. It is also a mixture of frequencies.
- Slow smooth signals mainly need low frequencies.
- Sharp edges, fast pulses, and sudden jumps require high frequencies.
- Real instruments have limited bandwidth, so they cannot reproduce infinitely sharp features perfectly.

## 2. Periodic Signals and Fourier Series

A periodic signal repeats after a fixed time $T$.

$$
f(t+T)=f(t)
$$

Definitions:

- $T$: period of the repeating signal, in seconds.
- $f_0$: fundamental frequency, in Hz.
- $\omega_0$: fundamental angular frequency, in rad/s.

$$
f_0 = \frac{1}{T}
$$

$$
\omega_0 = 2\pi f_0
$$

Fourier series idea:

- A periodic waveform can be built from sinusoids at integer multiples of the fundamental frequency.
- These are called harmonics.

Harmonics:

$$
f_0,\;2f_0,\;3f_0,\;4f_0,\ldots
$$

Plain words:

- The fundamental gives the main repetition rate.
- Higher harmonics add shape/detail.
- A pure sine wave has only one frequency.
- A square-ish wave needs many high harmonics because it has sharp corners.

## 3. Fourier Transform

For a non-periodic signal, such as a single pulse, use the Fourier transform.

$$
F(\omega)=\int_{-\infty}^{\infty} f(t)e^{-j\omega t}\,dt
$$

Definitions:

- $j$: imaginary unit, $j^2=-1$.
- $e^{-j\omega t}$: complex sinusoid used to test how much frequency $\omega$ is present.
- $dt$: small time interval in the integral.

Plain words:

- The transform checks how strongly the signal matches each possible sinusoidal frequency.
- If $F(\omega)$ is large at some $\omega$, that frequency is important in the signal.
- If $F(\omega)$ is zero at some $\omega$, that frequency is absent.

Useful properties:

| Property | Meaning |
|---|---|
| Linearity | Transform of a sum is the sum of transforms. |
| Time shift | Delaying a signal changes phase in frequency space. |
| Narrow in time | Broad in frequency. |
| Broad in time | Narrow in frequency. |

## 4. Top-Hat Pulse

A top-hat pulse is equal to 1 for a finite time and zero outside that time:

$$
f(t)=P_a(t)=
\begin{cases}
1, & |t|\leq a \\
0, & |t|>a
\end{cases}
$$

Definitions:

- $a$: half-width of the pulse in seconds.
- Full pulse width is $2a$.
- $P_a(t)$: notation for this top-hat pulse.

Because $f(t)=1$ only from $-a$ to $+a$, the Fourier transform becomes:

$$
F(\omega)=\int_{-a}^{a} e^{-j\omega t}\,dt
$$

Derivation:

$$
F(\omega)=\left[\frac{e^{-j\omega t}}{-j\omega}\right]_{-a}^{a}
$$

$$
F(\omega)=\frac{e^{-j\omega a}-e^{j\omega a}}{-j\omega}
$$

Using $e^{jx}-e^{-jx}=2j\sin x$:

$$
F(\omega)=\frac{2\sin(\omega a)}{\omega}
$$

Key results:

| Quantity | Result | Meaning |
|---|---|---|
| Transform | $F(\omega)=\dfrac{2\sin(\omega a)}{\omega}$ | Sinc-like frequency spectrum |
| Value at zero frequency | $F(0)=2a$ | Equal to pulse area |
| First zeros | $\omega=\pm\dfrac{\pi}{a}$ | Sets main bandwidth scale |

Why $F(0)=2a$:

At $\omega=0$, the Fourier transform is just the area of the pulse:

$$
F(0)=\int_{-a}^{a}1\,dt=2a
$$

## 5. Bandwidth and Pulse Duration

Bandwidth means the range of frequencies needed to represent a signal or passed by an instrument.

For the top-hat pulse:

- The first zero occurs at $\omega=\pi/a$.
- Smaller $a$ means shorter pulse.
- Smaller $a$ makes $\pi/a$ larger.
- Therefore shorter pulses require larger bandwidth.

Exam phrase:

> A perfect top-hat pulse has discontinuous edges, so it requires infinitely high frequency components. Real instruments have finite bandwidth, so a perfect top-hat pulse is physically impossible.

Plain words:

- To make a pulse edge vertical, the signal must change in zero time.
- Zero-time change needs infinitely high frequencies.
- Since instruments cannot pass infinite frequency, real pulse edges are always rounded.

## 6. Gaussian Pulse and Time-Bandwidth Product

A Gaussian pulse has the form:

$$
f(t)=Ae^{-b^2t^2}
$$

Definitions:

- $A$: amplitude scale.
- $b$: parameter controlling pulse width.
- Smaller pulse duration means larger frequency bandwidth.

For a Gaussian optical pulse, the useful result from PS3 is:

$$
\Delta t\,\Delta f \approx 0.44
$$

Definitions:

- $\Delta t$: pulse duration, usually full-width at half-maximum in time.
- $\Delta f$: frequency bandwidth, usually full-width at half-maximum in frequency.

Plain words:

- Gaussian pulses are special because their Fourier transform is also Gaussian.
- They have a minimum possible time-bandwidth product.
- If you want a very short laser pulse, you must allow a broad range of optical frequencies.

## 7. How Chapter 6 Connects To PS3

PS3 is not only Chapter 6. It mixes topics:

| PS3 question | Main topic | Notes to use |
|---|---|---|
| Q1 | Top-hat Fourier transform and bandwidth | `chp6_exam_notes.md` |
| Q2 | Gaussian pulse and time-bandwidth product | `chp6_exam_notes.md` |
| Q3 | RC low-pass/high-pass filters | `chp7-8_exam_notes.md` |
| Q4 | ADC resolution/dynamic range/quantisation | `chp4-5_exam_notes.md` |
| Q5 | Nyquist and aliasing | `chp4-5_exam_notes.md` |

Recommended order:

1. Read Chapter 6 notes before PS3 Q1/Q2.
2. For PS3 Q3, skim only the low-pass/high-pass sections of `chp7-8_exam_notes.md`.
3. For PS3 Q4/Q5, use the ADC/sampling sections of `chp4-5_exam_notes.md`.

You do not need to fully read Chapters 7-8 before starting PS3. Just jump to the filter sections when you reach Q3.

## 8. Exam Method Templates

Top-hat transform template:

1. Write the interval where the pulse is non-zero.
2. Replace the infinite integral with limits $-a$ to $+a$.
3. Integrate $e^{-j\omega t}$.
4. Simplify using the sine identity.
5. Interpret first zero and bandwidth.

Bandwidth explanation template:

- Shorter pulse $\Rightarrow$ smaller $a$.
- First zero $\omega=\pi/a$ moves outward.
- Frequency content spreads wider.
- Therefore short pulses require high bandwidth.

Gaussian time-bandwidth template:

$$
\Delta f = \frac{0.44}{\Delta t}
$$

Use this when pulse duration is given and bandwidth is requested.
