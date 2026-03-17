# Foundation interview notes

## 1) What I need to be able to do in the interview
Main goal: start from what I actually did in the labs, then build into the general theory if asked.

That means I should be able to:
- say what circuit I built,
- say why I built it,
- sketch it fast,
- explain the main equation used,
- say what each symbol means,
- describe what I expect to see on the instrument,
- explain how I would choose $R$ and $C$ if given a target cutoff.

---

## 2) Quick symbols and terms

- $R$: resistance in ohms.
- $C$: capacitance in farads.
- $V_{in}$: input voltage.
- $V_{out}$: output voltage.
- $f$: frequency in Hz.
- $\omega$: angular frequency in rad/s, where
$$
\omega = 2\pi f
$$
- $j$: imaginary unit, $j^2=-1$.
- $H(j\omega)$ or $G(j\omega)$: transfer function in frequency domain.
- Transfer function: output divided by input as a function of frequency:
$$
H(j\omega)=\frac{V_{out}(j\omega)}{V_{in}(j\omega)}
$$
- Why it matters: it tells me how much each frequency is amplified/attenuated, and how much phase shift it gets.
- Bode plot: magnitude and phase of the transfer function versus frequency.
- LP / low-pass: passes low frequencies, attenuates high frequencies.
- HP / high-pass: passes high frequencies, attenuates low frequencies, including DC.
- $f_c$: cutoff frequency.
- $f_s$: sampling frequency.
- $f_N$: Nyquist frequency:
$$
f_N=\frac{f_s}{2}
$$
- $f_a$: aliased frequency, the false frequency seen after sampling.

---

## 3) One core RC rule used again and again

This is the main design rule that shows up across the labs.

For a first-order RC filter:
$$
f_c=\frac{1}{2\pi RC}
$$

Where:
- $f_c$ is cutoff frequency,
- $R$ is resistance,
- $C$ is capacitance.

This means:
- bigger $R$ or bigger $C$ gives bigger $RC$, so lower cutoff,
- smaller $R$ or smaller $C$ gives smaller $RC$, so higher cutoff.

If I need to choose component values, I just rearrange:
$$
R=\frac{1}{2\pi f_c C}
$$
$$
C=\frac{1}{2\pi f_c R}
$$

### 3.1 How I choose $R$ and $C$ in practice
1. Decide the target cutoff frequency $f_c$.
2. Choose one convenient component value first.
3. Solve for the other using $f_c=\dfrac{1}{2\pi RC}$.
4. Round to a standard resistor/capacitor value.
5. Recalculate the actual cutoff using the rounded values.

### 3.2 Quick example
Suppose I want:
$$
f_c=1000\ \mathrm{Hz}
$$
and I choose:
$$
R=10\ \mathrm{k}\Omega
$$
Then:
$$
C=\frac{1}{2\pi (10^4)(1000)}\approx 15.9\ \mathrm{nF}
$$

So I might choose a standard capacitor close to that, like $15\ \mathrm{nF}$ or $16\ \mathrm{nF}$ if available, then recalculate the real cutoff.

---

## 4) Lab 1: sampling, aliasing, anti-alias low-pass filter

### 4.1 What I did in Lab 1
- Looked at sampled signals and aliasing.
- Built or used an anti-alias low-pass filter before digitisation.
- Used the Bode Analyzer / instrument plots to understand cutoff and response.

### 4.2 Circuit from the lab
This is the kind of low-pass RC filter used for anti-aliasing:

![Lab 1 anti-alias low-pass filter](interview_assets/crops/lab1_anti_alias_filter.png)

Quick sketch:
```text
Vin -- R --+-- Vout
           |
           C
           |
          GND
```

Why this is low-pass:
- at low frequency, capacitor impedance is large, so little current goes through the capacitor and most signal appears at the output,
- at high frequency, capacitor impedance becomes small, so high-frequency signal is shunted to ground.

### 4.3 Capacitor impedance idea
The key equation is:
$$
Z_C=\frac{1}{j\omega C}
$$

This is one of the most important equations to remember.

What it means:
- when $\omega$ is small, $|Z_C|$ is large,
- when $\omega$ is large, $|Z_C|$ is small.

So the capacitor resists low-frequency change more than high-frequency change.

### 4.4 Low-pass transfer function
For the RC low-pass:
$$
H_{LP}(j\omega)=\frac{V_{out}}{V_{in}}=\frac{1}{1+j\omega RC}
$$

Magnitude:
$$
\left|H_{LP}(j\omega)\right|=\frac{1}{\sqrt{1+(\omega RC)^2}}
$$

Key points:
- at low frequency, gain is close to 1,
- at high frequency, gain falls toward 0,
- at cutoff ($w$ = 1/RC) denominator becomes $1 + j$ ($1+j = \sqrt{2}$), gain is $1/\sqrt{2}$ of the passband value, which is $-3$ dB.

Cutoff:
$$
f_c=\frac{1}{2\pi RC}
$$

This is the Lab 1 equation I definitely need to know cold.

### 4.5 How I choose $R$ and $C$ for the Lab 1 low-pass
If the lab or question gives me a target cutoff:
$$
f_c=\frac{1}{2\pi RC}
$$

I can solve either way:
$$
R=\frac{1}{2\pi f_c C}
$$
or
$$
C=\frac{1}{2\pi f_c R}
$$

Example:
if I want $f_c=1\ \mathrm{kHz}$ and choose $R=10\ \mathrm{k}\Omega$, then
$$
C\approx 15.9\ \mathrm{nF}
$$

### 4.6 Nyquist and aliasing
Nyquist frequency is:
$$
f_N=\frac{f_s}{2}
$$

To avoid aliasing, I need:
$$
f_s\ge 2f_{max}
$$

Where:
- $f_s$ is sampling frequency,
- $f_{max}$ is the highest signal frequency present before sampling.

If I do not satisfy this, higher frequencies fold back into lower frequencies.

### 4.7 What aliasing really means
Aliasing means the sampled system cannot tell the difference between some different analog frequencies.

General aliasing formula:
$$
f_a = |n f_s - f|,\qquad n\in\mathbb{Z}
$$

Where:
- $f$ is the real input frequency,
- $f_a$ is the apparent frequency after sampling,
- $n$ is an integer chosen so the aliased result lands in the observable band.

Common first case:
$$
f_a=f_s-f \qquad \text{for } \frac{f_s}{2}<f<f_s
$$

Example:
if
$$
f_s=1000\ \mathrm{Hz},\qquad f=950\ \mathrm{Hz}
$$
then
$$
f_a=1000-950=50\ \mathrm{Hz}
$$

### 4.8 How to describe $f_a=f_s-f$ in words
This equation is basically the signal folding back after it crosses Nyquist.

Good way to say it:
- as the true frequency goes up past $f_s/2$, the sampled system makes it appear to come back down,
- so the spectrum looks like it reflects or mirrors back,
- that is why $f_a=f_s-f$ feels like the frequency is shifting backwards.

So on an instrument, I may increase the true frequency but see the measured frequency decrease.

### 4.9 Why square waves are a problem for sampling
A square wave is not just one frequency. It contains many odd harmonics.

Fourier series of a square wave:
$$
x(t)=\frac{4}{\pi}\left(\sin \omega t+\frac{1}{3}\sin 3\omega t+\frac{1}{5}\sin 5\omega t+\cdots\right)
$$

So even if the fundamental is below Nyquist, some higher harmonics can still be above Nyquist.

Important interview point:
- for a perfect square wave, there are infinitely many odd harmonics,
- so with any finite sampling frequency, some harmonics will always be above Nyquist,
- that means some aliasing or loss of high-frequency content is unavoidable.

That is why sampled square waves often look:
- rounded,
- broken,
- less sharp than the original,
- or weird on instruments if harmonics alias back.

### 4.10 Why anti-alias filtering helps
The anti-alias low-pass filter removes high-frequency content before sampling.

So:
- it makes the digitised signal more truthful,
- it reduces false low-frequency components caused by aliasing,
- but it also removes some sharp edges and high harmonics.

So the signal looks less like a perfect square, but it is a more valid sampled signal.

### 4.11 What I expect the Bode plot to look like for Lab 1 low-pass
- low frequencies: flat gain near 0 dB,
- around cutoff: starts rolling off,
- above cutoff: falls at about $-20\ \mathrm{dB/decade}$ for a first-order RC low-pass,
- phase moves from about $0^\circ$ toward $-90^\circ$.

---

## 5) Lab 2: microphone, DC blocking high-pass, pre-amp

### 5.1 What I did in Lab 2
- Worked with an electret microphone.
- Removed the DC bias from the microphone output using a high-pass filter.
- Amplified the small AC signal using an op-amp pre-amp.

### 5.2 Why the microphone output needs filtering
The electret microphone output is not pure AC audio.
It contains:
- a DC bias level,
- a small AC sound signal sitting on top of that DC level.

I do not want to amplify the DC part.
I want to block DC and keep the sound signal.

So I use a high-pass coupling stage.

### 5.3 High-pass circuit from the lab
This is the mic coupling / DC-blocking stage:

![Lab 2 microphone high-pass circuit](interview_assets/crops/lab2_mic_hp_circuit.png)

Quick sketch:
```text
Vin -- C --+-- Vout
           |
           R
           |
          GND
```

Output is taken across the resistor, which is why this is a high-pass filter.

### 5.4 Why the high-pass blocks DC
Again:
$$
Z_C=\frac{1}{j\omega C}
$$

At DC:
$$
\omega=0 \quad \Rightarrow \quad |Z_C|\to\infty
$$

So the capacitor acts like an open circuit.
That means no DC current flows through it, so DC is blocked.

At higher frequency:
- $|Z_C|$ becomes smaller,
- AC can pass through to the resistor and output.

That is the clean explanation for the viva question.

### 5.5 High-pass transfer function
For the RC high-pass:
$$
H_{HP}(j\omega)=\frac{V_{out}}{V_{in}}=\frac{j\omega RC}{1+j\omega RC}
$$

Magnitude:
$$
\left|H_{HP}(j\omega)\right|=\frac{\omega RC}{\sqrt{1+(\omega RC)^2}}
$$

Key points:
- at very low frequency, gain tends to 0,
- at high frequency, gain tends to 1,
- at cutoff, gain is $1/\sqrt{2}$ of the passband value, which is $-3$ dB.

Cutoff:
$$
f_c=\frac{1}{2\pi RC}
$$

### 5.6 How I choose $R$ and $C$ for the high-pass
Same formula as before:
$$
f_c=\frac{1}{2\pi RC}
$$

If I know the lowest frequency I want to keep, I choose the cutoff around there or below there, depending on the design goal.

Example:
if I want about
$$
f_c=50\ \mathrm{Hz}
$$
and I choose
$$
R=10\ \mathrm{k}\Omega
$$
then
$$
C=\frac{1}{2\pi (10^4)(50)}\approx 318\ \mathrm{nF}
$$

So a standard capacitor like $330\ \mathrm{nF}$ would be a sensible nearby choice.

### 5.7 What I expect the high-pass Bode plot to look like
- low frequencies: small gain,
- near cutoff: transition region,
- high frequencies: flat passband,
- slope below cutoff is about $+20\ \mathrm{dB/decade}$ for a first-order high-pass,
- phase moves from about $+90^\circ$ at very low frequency toward $0^\circ$ at high frequency.

### 5.8 Pre-amp circuit from the lab
This is the amplifier stage:

![Lab 2 pre-amp circuit](interview_assets/crops/lab2_preamp_circuit.png)

The important thing is that it is an inverting op-amp amplifier.

### 5.9 Inverting pre-amp gain
The gain is:
$$
A_v=\frac{V_{out}}{V_{in}}=-\frac{R_f}{R_{in}}
$$

Where:
- $R_f$ is the feedback resistor,
- $R_{in}$ is the input resistor.

Non-inverting:
$$
A_v=\frac{V_{out}}{V_{in}}=1 + \frac{R_f}{R_{in}}
$$


The minus sign means:
- the output is inverted,
- so there is a $180^\circ$ phase shift between input and output.

Example:
if
$$
R_f=100\ \mathrm{k}\Omega,\qquad R_{in}=10\ \mathrm{k}\Omega
$$
then
$$
A_v=-10
$$

In dB that is:
$$
20\log_{10}(10)=20\ \mathrm{dB}
$$

### 5.10 Ideal op-amp ideas I should know
Under negative feedback, the usual ideal assumptions are:
$$
i_+\approx i_-\approx 0
$$
$$
V_+\approx V_-
$$

Meaning:
- almost no current goes into the op-amp inputs,
- the two input nodes sit at almost the same voltage when feedback is working properly.

For an inverting amplifier with non-inverting input grounded:
- $V_+$ is at 0 V,
- so $V_-$ is approximately 0 V too,
- this is called virtual ground.

### 5.11 Bandwidth point from the lab
The pre-amp does not amplify all frequencies equally forever.

From the lab notes:
- the gain is roughly flat at about $20$ dB up to around $10\ \mathrm{kHz}$,
- then it starts to roll off.

So if asked:
"Would the pre-amp amplify 100 kHz the same as 1 kHz?"

Answer:
- no,
- because the op-amp stage has finite bandwidth,
- so high-frequency gain drops.

---

## 6) Lab 3: frequency response functions and Bode analysis

### 6.1 What I did in Lab 3
- Measured frequency response of the full chain and individual blocks.
- Measured the high-pass filter on its own.
- Measured the pre-amp on its own.
- Used those results to reason about the whole system.
- Used known/synthesised microphone data to infer the sounder response.

### 6.2 What "frequency response" means
Frequency response tells me how a system treats different frequencies.

In simple words:
- for each input frequency, how much output do I get?
- and how much phase shift is there?

That is why transfer function is useful:
$$
H(j\omega)=\frac{\text{output}}{\text{input}}
$$

It turns a system into something I can analyse frequency-by-frequency.

### 6.3 Whole-chain model from the lab
The system is treated as 4 blocks:
- sounder,
- microphone,
- filter,
- amplifier.

So the whole transfer function is:
$$
G(j\omega)=G_1(j\omega)G_2(j\omega)G_3(j\omega)G_4(j\omega)
$$

This means:
- magnitudes multiply,
- phases add.

So:
$$
|G|=|G_1||G_2||G_3||G_4|
$$
$$
\phi=\phi_1+\phi_2+\phi_3+\phi_4
$$

This is one of the main Lab 3 ideas.

### 6.4 Why this matters
If I know the whole system response and I know some individual block responses, I can divide things out and estimate the missing block.

That is exactly the logic used to infer the sounder response.

### 6.5 Bode Analyzer idea
The Bode Analyzer applies a sine wave and checks the ratio of output to input across frequency.

So if one channel is $A(f)$ and the reference/input channel is $B(f)$:
$$
G_{measured}(f)=\frac{A(f)}{B(f)}
$$

That is why I always need to be clear what is physically connected to channel A and channel B.

### 6.6 Why swept sine is used
The lab notes mention different ways to excite a system:
- swept sine,
- impulse,
- white noise.

Swept sine is usually used here because:
- it gives good signal-to-noise ratio,
- I test one frequency at a time,
- but it is slower.

### 6.7 High-pass filter measured in Lab 3
The filter isolated in Lab 3 is this:

![Lab 3 high-pass filter circuit](interview_assets/crops/lab3_hp_filter_circuit.png)

Its expected response is the standard first-order high-pass:
$$
H_{HP}(j\omega)=\frac{j\omega RC}{1+j\omega RC}
$$

So I expect:
- low frequency attenuation,
- a transition near cutoff,
- a flat high-frequency region.

### 6.8 Lab 3 filter Bode plot
Example measured response:

![Lab 3 filter Bode response](interview_assets/crops/lab3_filter_bode.png)

How to find the cutoff on the graph:
- first identify the flat passband gain,
- then go down by 3 dB from that level,
- the frequency at that point is the cutoff frequency.

And for a first-order RC filter, that should agree with:
$$
f_c=\frac{1}{2\pi RC}
$$

### 6.9 Pre-amp in Lab 3
The pre-amp response should be:
- mostly flat over the useful band,
- then roll off at higher frequency because of limited bandwidth.

So if I see it flat over the working region, that is good.
If I see strong peaks in the pre-amp alone, that would be suspicious.

### 6.10 Resonances in the whole system
In the whole-system Bode plot, peaks can appear.
These are resonances.

Simple explanation:
- at some frequencies, the system naturally responds more strongly,
- so the output becomes larger at those frequencies.

In Lab 3 the whole system can show resonant peaks because it includes:
- the sounder,
- the microphone,
- the mechanical/acoustic path,
- the filter,
- the amplifier.

### 6.11 Why some parts of the curve look random
At very low or very high frequency, the output can become very small.

Then:
- the real signal is weak,
- noise becomes comparable,
- the measured points look messy or random.

So bad-looking extremes do not always mean the theory is wrong.
Sometimes it is just poor signal-to-noise ratio.

### 6.12 Why the microphone response is tricky
The lab points out that to measure microphone frequency response properly, I would ideally want a reference microphone with known flat response.

Without that, microphone response is not directly measured perfectly.
So the lab uses microphone datasheet information as an approximation.

### 6.13 Sounder response inference
If the whole system is:
$$
G_{sys}=G_{sounder}G_{mic}G_{filter}G_{preamp}
$$
then the sounder can be inferred from:
$$
G_{sounder}=\frac{G_{sys}}{G_{mic}G_{filter}G_{preamp}}
$$

This is a key Lab 3 idea:
- if I cannot measure one block directly,
- I can estimate it by dividing out the other known blocks.

### 6.14 dB conversion I should know for Lab 3
Magnitude in dB:
$$
G_{\mathrm{dB}}=20\log_{10}|G|
$$

Back to linear magnitude:
$$
|G|=10^{G_{\mathrm{dB}}/20}
$$

Important quick fact:
- $-3$ dB corresponds to amplitude ratio $1/\sqrt{2}\approx 0.707$.

---

## 7) Low-pass versus high-pass: the quick comparison

### 7.1 Low-pass
Circuit:
```text
Vin -- R --+-- Vout
           |
           C
           |
          GND
```

Output is across the capacitor.

Behavior:
- low frequencies pass,
- high frequencies are attenuated.

Transfer function:
$$
H_{LP}(j\omega)=\frac{1}{1+j\omega RC}
$$

### 7.2 High-pass
Circuit:
```text
Vin -- C --+-- Vout
           |
           R
           |
          GND
```

Output is across the resistor.

Behavior:
- high frequencies pass,
- low frequencies, including DC, are attenuated.

Transfer function:
$$
H_{HP}(j\omega)=\frac{j\omega RC}{1+j\omega RC}
$$

### 7.3 Why simply swapping $R$ and $C$ changes the filter type
Because the output node changes.

The same two components are there, but:
- if I measure output across the capacitor, I get low-pass behavior,
- if I measure output across the resistor, I get high-pass behavior.

That comes from frequency-dependent voltage division.

---

## 8) Transient response and why it links to the filter equations

This is still useful because an interviewer might move from frequency-domain thinking to time-domain thinking.

### 8.1 Time constant
For a first-order RC circuit:
$$
\tau=RC
$$

Time constant tells me how quickly the circuit responds in time.

### 8.2 Low-pass step response
$$
V_{out}(t)=V\left(1-e^{-t/RC}\right)
$$

Meaning:
- output rises gradually,
- at $t=\tau$, it has reached about $63.2\%$ of its final value,
- around $5\tau$, it is basically settled.

### 8.3 High-pass step response
$$
V_{out}(t)=Ve^{-t/RC}
$$

Meaning:
- a step input gives a pulse-like output that decays,
- because the high-pass passes change, not steady DC.

### 8.4 Why this connects to the lab
Same $RC$ controls:
- cutoff frequency in frequency domain,
- response speed in time domain.

So changing $R$ or $C$ changes both.

---

## 9) Quick "draw this now" sketches

### 9.1 Anti-alias low-pass
```text
Vin -- R --+-- Vout
           |
           C
           |
          GND
```

### 9.2 Mic DC-blocking high-pass
```text
Vin -- C --+-- Vout
           |
           R
           |
          GND
```

### 9.3 Inverting op-amp pre-amp
```text
Vin -- Rin --(-) op-amp ---- Vout
              |      ^
              +--Rf--+
          (+) tied to ground
```

---

## 10) Rapid-fire viva answers

### 10.1 Why did I add a filter after the microphone?
To remove the DC bias from the mic output and keep the AC sound signal.

### 10.2 Why does the high-pass remove DC?
Because
$$
Z_C=\frac{1}{j\omega C}
$$
and at DC, $\omega=0$, so capacitor impedance tends to infinity and behaves like an open circuit.

### 10.3 What is the RC cutoff frequency?
$$
f_c=\frac{1}{2\pi RC}
$$

### 10.4 What does $-3$ dB mean?
It means the amplitude is down to:
$$
\frac{1}{\sqrt{2}}\approx 0.707
$$
of the passband value.

### 10.5 What is transfer function?
It is output divided by input as a function of frequency.
It tells me how each frequency is changed by the system.

### 10.6 What is aliasing?
It is when high-frequency components appear as false lower frequencies after sampling.

### 10.7 Why use an anti-alias filter?
To remove frequency content above Nyquist before sampling.

### 10.8 Why are square waves hard to sample perfectly?
Because they contain infinitely many odd harmonics, and some will always be above Nyquist for any finite sample rate.

### 10.9 What is the gain of an inverting amplifier?
$$
A_v=-\frac{R_f}{R_{in}}
$$

### 10.10 What does the negative sign in op-amp gain mean?
It means the output is inverted, so there is a $180^\circ$ phase shift.

### 10.11 In Lab 3, how do responses of blocks combine?
For cascaded blocks:
- magnitudes multiply,
- phases add.

### 10.12 Why can the ends of a Bode plot look messy?
Because output becomes small there and noise can dominate.

---

## 11) Very short memory sheet

1. Capacitor impedance:
$$
Z_C=\frac{1}{j\omega C}
$$

2. RC cutoff:
$$
f_c=\frac{1}{2\pi RC}
$$

3. Low-pass:
$$
H_{LP}(j\omega)=\frac{1}{1+j\omega RC}
$$

4. High-pass:
$$
H_{HP}(j\omega)=\frac{j\omega RC}{1+j\omega RC}
$$

5. Nyquist:
$$
f_N=\frac{f_s}{2}
$$

6. Aliasing:
$$
f_a=|n f_s-f|
$$

7. Inverting amplifier:
$$
A_v=-\frac{R_f}{R_{in}}
$$

8. dB magnitude:
$$
G_{\mathrm{dB}}=20\log_{10}|G|
$$

9. Whole-chain Lab 3 idea:
$$
G_{sys}=G_1G_2G_3G_4
$$

If I can explain each of those in plain words and sketch the LP filter, HP filter, and inverting op-amp, I should be in a much better place.
