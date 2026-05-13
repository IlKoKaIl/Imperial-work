# 2023 Past Paper Q1 Solution Notes

These are exam-style notes for Question 1 of `2023 paper.pdf`.

## Q1(i) Sensor Terms

### (a) Offset

**Offset** means the sensor output is nonzero even when the true input is zero.

Example:

If a temperature sensor reads `0.2 V` at `0 deg C`, then `0.2 V` is an offset.

Calibration model:

$$
y = mx + c
$$

Here $c$ is the offset.

### (b) Saturation

**Saturation** means the sensor output stops increasing normally when the input gets too large.

The sensor has reached a limit, so the output clips or flattens.

Example:

A magnetic sensor might be linear for small magnetic fields, but above some field the output becomes almost constant.

### (c) Loading

**Loading** means the act of measuring changes the thing being measured.

Example:

A voltmeter with finite input resistance connected across a source draws current. This changes the measured voltage.

For a source with source resistance $R_s$ and meter/load resistance $R_L$:

$$
V_L = V_s \frac{R_L}{R_s+R_L}
$$

To reduce loading in voltage measurements, use:

$$
R_L \gg R_s
$$

## Q1(ii) Real Op-Amp Bode Plot, Stability, Bandwidth, CMRR

Given:

$$
A_0 = 10^5
$$

$$
f_{OL}=10\,\text{Hz}
$$

$$
f_T = 1\,\text{MHz}
$$

The DC open-loop gain in dB is:

$$
20\log_{10}(10^5)=100\,\text{dB}
$$

### (a) Bode Plot and Stability

The magnitude plot:

- starts at $100\,\text{dB}$
- is flat until about $10\,\text{Hz}$
- rolls off at approximately $-20\,\text{dB/decade}$
- crosses $0\,\text{dB}$ at $1\,\text{MHz}$

The phase plot:

- phase lag is $-90^\circ$ from $100\,\text{Hz}$ to $10^5\,\text{Hz}$
- after $10^5\,\text{Hz}$, phase decreases by $45^\circ$ per decade

At the gain crossover frequency:

$$
f = 1\,\text{MHz}
$$

This is one decade above $10^5\,\text{Hz}$, so the phase is:

$$
-90^\circ - 45^\circ = -135^\circ
$$

The **phase margin** is:

$$
180^\circ - 135^\circ = 45^\circ
$$

So:

$$
\text{phase margin} = 45^\circ
$$

The phase reaches $-180^\circ$ two decades above $10^5\,\text{Hz}$:

$$
f = 10^7\,\text{Hz}
$$

At $10^7\,\text{Hz}$, the gain has rolled off by another decade beyond $1\,\text{MHz}$:

$$
0\,\text{dB} - 20\,\text{dB} = -20\,\text{dB}
$$

So the **gain margin** is:

$$
20\,\text{dB}
$$

Both margins are positive, so the op-amp is stable when used with feedback.

### (b) Closed-Loop Bandwidth

Feedback fraction:

$$
\beta = 0.1
$$

Closed-loop gain is approximately:

$$
G \approx \frac{1}{\beta}=10
$$

The gain-bandwidth product is:

$$
G B \approx 1\,\text{MHz}
$$

Therefore:

$$
B = \frac{1\,\text{MHz}}{10}=100\,\text{kHz}
$$

Answer:

$$
B \approx 100\,\text{kHz}
$$

### (c) CMRR

Differential gain:

$$
A_D = 10^5
$$

Common-mode gain:

$$
A_{CM}=10
$$

CMRR is:

$$
\text{CMRR}=20\log_{10}\left(\frac{A_D}{A_{CM}}\right)
$$

Substitute:

$$
\text{CMRR}=20\log_{10}\left(\frac{10^5}{10}\right)
$$

$$
\text{CMRR}=20\log_{10}(10^4)
$$

$$
\text{CMRR}=80\,\text{dB}
$$

## Q1(iii) Noise

### (a) Flicker Noise Frequency Characteristics

Flicker noise is also called $1/f$ noise.

Its noise power spectral density increases at low frequency:

$$
S(f) \propto \frac{1}{f}
$$

So it is most important at low frequencies and becomes less important at high frequencies.

For voltage or current noise amplitude density, this often appears as:

$$
e_n(f) \propto \frac{1}{\sqrt{f}}
$$

### (b) Why RMS Flicker Noise Remains Finite

Ideal $1/f$ noise would diverge if we integrated all the way down to:

$$
f=0
$$

But real experiments do not measure for infinite time.

A finite measurement time $T$ gives an approximate low-frequency cutoff:

$$
f_{\min} \sim \frac{1}{T}
$$

So the RMS noise remains finite because the experiment never truly includes frequencies down to exactly $0\,\text{Hz}$.

### (c) Ratio of Flicker Noise Power

For $1/f$ noise:

$$
P_n \propto \int_{f_{\min}}^{f_{\max}}\frac{1}{f}\,df
$$

This gives:

$$
P_n \propto \ln\left(\frac{f_{\max}}{f_{\min}}\right)
$$

Use:

$$
f_{\max}=10\,\text{kHz}=10^4\,\text{Hz}
$$

For a measurement time $T$:

$$
f_{\min}\sim \frac{1}{T}
$$

So:

$$
P_n \propto \ln(f_{\max}T)
$$

For 24 hours:

$$
T_1=24\times3600=86400\,\text{s}
$$

For 5 minutes:

$$
T_2=5\times60=300\,\text{s}
$$

Ratio:

$$
\frac{P_{24h}}{P_{5min}}
=
\frac{\ln(10^4\times86400)}{\ln(10^4\times300)}
$$

$$
\frac{P_{24h}}{P_{5min}}
=
\frac{\ln(8.64\times10^8)}{\ln(3.0\times10^6)}
$$

$$
\frac{P_{24h}}{P_{5min}}\approx 1.38
$$

So the 24-hour measurement has about:

$$
1.4
$$

times more flicker noise power than the 5-minute measurement.

### (d) Input Voltage for Output SNR of 20 dB

Given:

$$
R = 10\,\text{k}\Omega
$$

$$
T=300\,\text{K}
$$

$$
f_L=100\,\text{Hz}
$$

$$
f_H=100\,\text{kHz}
$$

$$
F=2
$$

Bandwidth:

$$
B=f_H-f_L=100000-100=99900\,\text{Hz}
$$

Thermal RMS noise voltage:

$$
v_n=\sqrt{4k_BTRB}
$$

Substitute:

$$
v_n=\sqrt{4(1.38\times10^{-23})(300)(10^4)(99900)}
$$

$$
v_n\approx 4.1\,\mu\text{V}
$$

Output SNR:

$$
20\,\text{dB}
$$

As a power ratio:

$$
\text{SNR}_{out}=10^{20/10}=100
$$

Noise factor:

$$
F=\frac{\text{SNR}_{in}}{\text{SNR}_{out}}
$$

So:

$$
\text{SNR}_{in}=F\text{SNR}_{out}=2\times100=200
$$

For voltage amplitudes:

$$
\text{SNR}_{in}=\frac{V_s^2}{v_n^2}
$$

Therefore:

$$
V_s=v_n\sqrt{\text{SNR}_{in}}
$$

$$
V_s=(4.1\,\mu\text{V})\sqrt{200}
$$

$$
V_s\approx 58\,\mu\text{V RMS}
$$

### (e) Temperature for SNR of 26 dB

Thermal noise power is proportional to temperature:

$$
P_n \propto T
$$

If the signal is unchanged:

$$
\text{SNR}\propto \frac{1}{T}
$$

Required SNR increase:

$$
26\,\text{dB}-20\,\text{dB}=6\,\text{dB}
$$

As a power ratio:

$$
10^{6/10}=3.98
$$

So the temperature must decrease by this factor:

$$
T_{new}=\frac{300}{3.98}
$$

$$
T_{new}\approx 75\,\text{K}
$$

### (f) Shot Noise Voltage Across Resistor

Applied voltage:

$$
10\,\text{V}
$$

Diode forward voltage:

$$
0.6\,\text{V}
$$

Resistor:

$$
R=10\,\Omega
$$

Current:

$$
I=\frac{10-0.6}{10}=0.94\,\text{A}
$$

Shot noise current:

$$
i_n=\sqrt{2eIB}
$$

where:

$$
e=1.60\times10^{-19}\,\text{C}
$$

and:

$$
B=1\,\text{MHz}=10^6\,\text{Hz}
$$

Substitute:

$$
i_n=\sqrt{2(1.60\times10^{-19})(0.94)(10^6)}
$$

$$
i_n\approx 5.5\times10^{-7}\,\text{A}
$$

Noise voltage across the resistor:

$$
v_n=i_nR
$$

$$
v_n=(5.5\times10^{-7})(10)
$$

$$
v_n\approx 5.5\,\mu\text{V RMS}
$$

## Q1(iv) 16-Bit Digitiser

Given:

$$
N=16
$$

Resolution:

$$
\Delta = 152.6\,\mu\text{V}
$$

Sampling rate:

$$
f_s=4\times10^6\,\text{samples/s}
$$

### (a) Maximum Input Signal

For a unipolar 16-bit digitiser:

$$
2^{16}=65536
$$

Maximum range:

$$
V_{range}=2^{16}\Delta
$$

$$
V_{range}=65536(152.6\times10^{-6})
$$

$$
V_{range}\approx 10.0\,\text{V}
$$

Answer:

$$
V_{max}\approx 10\,\text{V}
$$

### (b) Maximum Quantisation Error

Maximum quantisation error is half an LSB:

$$
\pm\frac{\Delta}{2}
$$

$$
\pm\frac{152.6\,\mu\text{V}}{2}
$$

$$
\pm76.3\,\mu\text{V}
$$

### (c) RMS Quantisation Noise

For uniform quantisation error:

$$
v_{q,\text{RMS}}=\frac{\Delta}{\sqrt{12}}
$$

$$
v_{q,\text{RMS}}=\frac{152.6\,\mu\text{V}}{\sqrt{12}}
$$

$$
v_{q,\text{RMS}}\approx 44.1\,\mu\text{V}
$$

### (d) Nyquist Frequency

$$
f_N=\frac{f_s}{2}
$$

$$
f_N=\frac{4\times10^6}{2}=2\times10^6\,\text{Hz}
$$

Answer:

$$
f_N=2\,\text{MHz}
$$

### (e) Properly Sampled Frequencies

Signals below the Nyquist frequency are properly sampled.

Nyquist frequency:

$$
2\,\text{MHz}
$$

Listed frequencies:

$$
1\,\text{MHz},\quad 1.5\,\text{MHz},\quad 2.5\,\text{MHz},\quad 3\,\text{MHz}
$$

Properly sampled:

$$
1\,\text{MHz},\quad 1.5\,\text{MHz}
$$

Improperly sampled:

$$
2.5\,\text{MHz},\quad 3\,\text{MHz}
$$

### (f) Alias Frequencies

Sampling frequency:

$$
f_s=4\,\text{MHz}
$$

For frequencies between $f_N$ and $f_s$, the alias is:

$$
f_{alias}=f_s-f
$$

For $2.5\,\text{MHz}$:

$$
f_{alias}=4-2.5=1.5\,\text{MHz}
$$

For $3\,\text{MHz}$:

$$
f_{alias}=4-3=1\,\text{MHz}
$$

Answers:

$$
2.5\,\text{MHz}\rightarrow 1.5\,\text{MHz}
$$

$$
3\,\text{MHz}\rightarrow 1\,\text{MHz}
$$

## Q1 Quick Templates

### Sensor Definition Questions

Use this structure:

1. Define the term.
2. Give one physical example.
3. If relevant, give the formula.

### Op-Amp Bode Questions

Use this structure:

1. Convert gain to dB.
2. Find gain crossover: where gain is $0\,\text{dB}$.
3. Read phase there.
4. Phase margin:

$$
\text{PM}=180^\circ+\phi_{\text{at }0\,\text{dB}}
$$

5. Find phase crossover: where phase is $-180^\circ$.
6. Read gain there.
7. Gain margin is how far below $0\,\text{dB}$ the gain is at $-180^\circ$ phase.

### Noise Questions

Thermal noise:

$$
v_n=\sqrt{4k_BTRB}
$$

Shot noise:

$$
i_n=\sqrt{2eIB}
$$

Noise factor:

$$
F=\frac{\text{SNR}_{in}}{\text{SNR}_{out}}
$$

Use power SNR for noise factor. If working with voltage amplitudes, square the ratio.

### Digitiser Questions

Resolution:

$$
\Delta=\frac{V_{range}}{2^N}
$$

Maximum error:

$$
\pm\frac{\Delta}{2}
$$

RMS quantisation noise:

$$
\frac{\Delta}{\sqrt{12}}
$$

Nyquist:

$$
f_N=\frac{f_s}{2}
$$

# 2023 Past Paper Q2 Solution Notes

## Q2(i) Difference Amplifier

The circuit is a **difference amplifier**. It subtracts one input voltage from another and then applies a gain.

For the matched resistor case shown:

$$
V_o=\frac{R_f}{R_i}(V_B-V_A)
$$

So the circuit amplifies the difference between the two inputs.

### How to Derive It

Use the ideal op-amp rules:

1. With negative feedback:

$$
V_+=V_-
$$

2. No current enters either input:

$$
i_+=i_-=0
$$

### Non-Inverting Side

The $+$ input is connected to a voltage divider from $V_B$ to ground.

So:

$$
V_+ = V_B\frac{R_f}{R_i+R_f}
$$

Since ideal op-amp feedback gives:

$$
V_-=V_+
$$

we also have:

$$
V_- = V_B\frac{R_f}{R_i+R_f}
$$

### Inverting Side

At the inverting node, no current enters the op-amp. So current through $R_i$ must equal current through $R_f$.

Current from $V_A$ into the node:

$$
\frac{V_A-V_-}{R_i}
$$

Current from the node to output:

$$
\frac{V_- - V_o}{R_f}
$$

Set them equal:

$$
\frac{V_A-V_-}{R_i}=\frac{V_- - V_o}{R_f}
$$

Rearrange:

$$
V_o = V_- - \frac{R_f}{R_i}(V_A-V_-)
$$

Substitute:

$$
V_- = V_B\frac{R_f}{R_i+R_f}
$$

After simplification:

$$
V_o=\frac{R_f}{R_i}(V_B-V_A)
$$

### How to Read Op-Amp Circuits Quickly

Use this exam method:

1. Check if there is negative feedback. If yes, use $V_+=V_-$.
2. Check whether $V_+$ is grounded. If yes, then $V_-\approx0$ and it is a virtual ground.
3. Check where the input enters:
   - input to $-$ terminal through resistor: probably inverting amplifier
   - input to $+$ terminal: probably non-inverting amplifier
   - multiple inputs into $-$ terminal: summing amplifier
   - two inputs, one on each side with matched resistors: difference amplifier
4. Use KCL at the input node because op-amp input current is zero.
5. Current through input resistor usually equals current through feedback resistor.

Useful formulas:

$$
\text{Inverting:}\quad V_o=-\frac{R_f}{R_{in}}V_{in}
$$

$$
\text{Non-inverting:}\quad V_o=\left(1+\frac{R_f}{R_g}\right)V_{in}
$$

$$
\text{Summing:}\quad V_o=-R_f\left(\frac{V_1}{R_1}+\frac{V_2}{R_2}+\cdots\right)
$$

$$
\text{Difference:}\quad V_o=\frac{R_f}{R_i}(V_B-V_A)
$$

## Q2(ii) Magnetoresistor Bridge

Given:

$$
R=1\,\text{k}\Omega
$$

The magnetoresistor has resistance:

$$
R+\Delta R
$$

where:

$$
\Delta R = 2\times10^5 B
$$

with $B$ in tesla.

Maximum resistance change:

$$
\Delta R_{\max}=\pm20\,\Omega
$$

Bridge supply voltage:

$$
V_s=5\,\text{V}
$$

### Q2(ii)(a) Wheatstone Bridge Output

We arrange the four magnetoresistors so that two increase and two decrease for the same field direction.

This maximises the bridge imbalance.

One midpoint voltage is:

$$
V_1 = 5\frac{R-\Delta R}{(R+\Delta R)+(R-\Delta R)}
$$

Since the denominator is:

$$
2R
$$

we get:

$$
V_1=\frac{5}{2}\left(1-\frac{\Delta R}{R}\right)
$$

The other midpoint voltage is:

$$
V_2 = 5\frac{R+\Delta R}{(R-\Delta R)+(R+\Delta R)}
$$

So:

$$
V_2=\frac{5}{2}\left(1+\frac{\Delta R}{R}\right)
$$

Bridge output:

$$
\Delta V = V_2-V_1
$$

Substitute:

$$
\Delta V =
\frac{5}{2}\left(1+\frac{\Delta R}{R}\right)
-
\frac{5}{2}\left(1-\frac{\Delta R}{R}\right)
$$

The constant parts cancel:

$$
\Delta V = 5\frac{\Delta R}{R}
$$

Now substitute:

$$
\Delta R = 2\times10^5 B
$$

and:

$$
R=1000\,\Omega
$$

So:

$$
\Delta V = 5\frac{2\times10^5B}{1000}
$$

$$
\Delta V = 1000B
$$

Answer:

$$
\Delta V = 1000B\ \text{V/T}
$$

### Q2(ii)(b) Choose Amplifier Gain

Earth's field:

$$
B=65\,\mu\text{T}=65\times10^{-6}\,\text{T}
$$

Bridge output:

$$
\Delta V = 1000B
$$

$$
\Delta V=1000(65\times10^{-6})
$$

$$
\Delta V=0.065\,\text{V}
$$

Desired output:

$$
V_o=0.65\,\text{V}
$$

Required gain:

$$
G=\frac{0.65}{0.065}=10
$$

For the difference amplifier:

$$
G=\frac{R_f}{R_i}
$$

So choose:

$$
\frac{R_f}{R_i}=10
$$

Example values:

$$
R_i=10\,\text{k}\Omega,\quad R_f=100\,\text{k}\Omega
$$

### Q2(ii)(c) Static Sensitivity Plot

Before amplification:

$$
\Delta V = 1000B
$$

With amplifier gain 10:

$$
V_o = 10(1000B)
$$

$$
V_o=10000B
$$

So the amplified sensitivity is:

$$
10000\,\text{V/T}
$$

Since:

$$
\Delta R_{\max}=20\,\Omega
$$

and:

$$
\Delta R=2\times10^5B
$$

saturation occurs when:

$$
20 = 2\times10^5B
$$

$$
B=1.0\times10^{-4}\,\text{T}
$$

$$
B=100\,\mu\text{T}
$$

So:

- from $-100\,\mu\text{T}$ to $+100\,\mu\text{T}$, the output is linear
- above $+100\,\mu\text{T}$, it saturates
- below $-100\,\mu\text{T}$, it saturates

At saturation:

$$
V_o=10000(100\times10^{-6})
$$

$$
V_o=1.0\,\text{V}
$$

So sketch:

```text
Vout
 +1 V |             _________
      |            /
      |           /
  0 V |----------/---------- B
      |         /
      |        /
 -1 V |_______/

       -100uT   0   +100uT
```

Important labels:

- slope in linear region: $10000\,\text{V/T}$
- saturation fields: $\pm100\,\mu\text{T}$
- saturation output: $\pm1\,\text{V}$
- Earth's field $65\,\mu\text{T}$ gives $0.65\,\text{V}$

### Q2(ii)(d) Measurement Bandwidth

Open-loop gain:

$$
A=10^5
$$

Open-loop bandwidth:

$$
B_{OL}=10\,\text{Hz}
$$

Gain-bandwidth product:

$$
A B_{OL}=10^5\times10
$$

$$
=10^6\,\text{Hz}
$$

The measurement amplifier has closed-loop gain:

$$
G=10
$$

So:

$$
G B_{CL}=10^6\,\text{Hz}
$$

Therefore:

$$
B_{CL}=\frac{10^6}{10}
$$

$$
B_{CL}=100\,\text{kHz}
$$

Answer:

$$
\boxed{100\,\text{kHz}}
$$

## Q2 Quick Templates

### Difference Amplifier Recognition

If you see two inputs and matched resistor ratios:

$$
\frac{R_f}{R_i}
$$

on both sides, it is probably a difference amplifier.

Use:

$$
V_o=\frac{R_f}{R_i}(V_B-V_A)
$$

### Wheatstone Bridge Small-Signal Pattern

If opposite arms increase/decrease by $\Delta R$, the bridge output is usually proportional to:

$$
\frac{\Delta R}{R}
$$

For a fully active bridge with four changing resistors:

$$
\Delta V \approx V_s\frac{\Delta R}{R}
$$

### Static Sensitivity Sketch Pattern

For a sensor with linear response then saturation:

1. Find the linear slope.
2. Find the input where saturation begins.
3. Find the output value at saturation.
4. Draw straight line in the middle and flat plateaus outside.

# 2023 Past Paper Q3 Solution Notes

## Q3(i) Laplace Transform of Unit Ramp

The unit ramp is:

$$
y(t)=t
$$

The Laplace transform definition is:

$$
Y(s)=\int_0^\infty y(t)e^{-st}\,dt
$$

So:

$$
Y(s)=\int_0^\infty t e^{-st}\,dt
$$

Use integration by parts:

$$
\int u\,dv = uv-\int v\,du
$$

Choose:

$$
u=t,\qquad dv=e^{-st}\,dt
$$

Then:

$$
du=dt
$$

and:

$$
v=-\frac{1}{s}e^{-st}
$$

So:

$$
\int_0^\infty t e^{-st}\,dt
=
\left[-\frac{t}{s}e^{-st}\right]_0^\infty
+
\frac{1}{s}\int_0^\infty e^{-st}\,dt
$$

The first term is zero:

$$
\left[-\frac{t}{s}e^{-st}\right]_0^\infty=0
$$

because $t e^{-st}\to0$ as $t\to\infty$.

Now:

$$
\int_0^\infty e^{-st}\,dt
=
\left[-\frac{1}{s}e^{-st}\right]_0^\infty
$$

$$
=0-\left(-\frac{1}{s}\right)
$$

$$
=\frac{1}{s}
$$

Therefore:

$$
Y(s)=\frac{1}{s}\frac{1}{s}
$$

Final answer:

$$
\boxed{\mathcal{L}\{t\}=\frac{1}{s^2}}
$$

## Q3(ii) Two First-Order Amplifiers in Series With Ramp Input

Each amplifier has impulse response:

$$
g(t)=e^{-t}
$$

The transfer function of each amplifier is the Laplace transform of its impulse response:

$$
G(s)=\mathcal{L}\{e^{-t}\}
$$

Using the standard pair:

$$
e^{-at}\leftrightarrow \frac{1}{s+a}
$$

with $a=1$:

$$
G(s)=\frac{1}{s+1}
$$

Two identical amplifiers in series means multiply transfer functions:

$$
G_{\text{total}}(s)=\frac{1}{s+1}\frac{1}{s+1}
$$

$$
G_{\text{total}}(s)=\frac{1}{(s+1)^2}
$$

Input is unit ramp:

$$
y(t)=t
$$

From Q3(i):

$$
Y(s)=\frac{1}{s^2}
$$

Since:

$$
X(s)=G_{\text{total}}(s)Y(s)
$$

we get:

$$
X(s)=\frac{1}{s^2(s+1)^2}
$$

Now use partial fractions:

$$
\frac{1}{s^2(s+1)^2}
=
\frac{A}{s}
+
\frac{B}{s^2}
+
\frac{C}{s+1}
+
\frac{D}{(s+1)^2}
$$

The decomposition is:

$$
X(s)=
-\frac{2}{s}
+
\frac{1}{s^2}
+
\frac{2}{s+1}
+
\frac{1}{(s+1)^2}
$$

Use inverse Laplace pairs:

$$
\frac{1}{s}\leftrightarrow 1
$$

$$
\frac{1}{s^2}\leftrightarrow t
$$

$$
\frac{1}{s+1}\leftrightarrow e^{-t}
$$

$$
\frac{1}{(s+1)^2}\leftrightarrow te^{-t}
$$

Therefore:

$$
x(t)=-2+t+2e^{-t}+te^{-t}
$$

Final answer:

$$
\boxed{x(t)=t-2+(t+2)e^{-t},\qquad t>0}
$$

Quick sense check:

- As $t$ becomes large, $e^{-t}\to0$.
- So:

$$
x(t)\approx t-2
$$

The output eventually follows the ramp, but delayed/lagged by about 2 time units because two first-order systems are in series.

## Q3(iii) Block Diagram With Differentiator and Integrator

The diagram has:

- $G_1$: ideal differentiator
- $G_2$: ideal integrator

So:

$$
G_1(s)=s
$$

and:

$$
G_2(s)=\frac{1}{s}
$$

Therefore:

$$
G_1(s)G_2(s)=1
$$

### Q3(iii)(a) Find Whole-System Transfer Function

Read the diagram from right to left for the feedback path.

The output is:

$$
X(s)
$$

The first feedback branch goes through gain 2, then through $G_1$:

$$
2X(s)G_1(s)
$$

The second feedback branch goes through gain 2, then gain 25, then through $G_2$:

$$
50X(s)G_2(s)
$$

These are added at the lower summing junction, then subtracted from $Y(s)$ at the upper summing junction.

So the signal before the gain $1/16$ is:

$$
Y(s)-2X(s)G_1(s)-50X(s)G_2(s)
$$

After the gain $1/16$, this equals $X(s)$:

$$
X(s)=\frac{1}{16}\left[Y(s)-2X(s)G_1(s)-50X(s)G_2(s)\right]
$$

Multiply by 16:

$$
16X(s)=Y(s)-2X(s)G_1(s)-50X(s)G_2(s)
$$

Collect the $X(s)$ terms:

$$
16X(s)+2X(s)G_1(s)+50X(s)G_2(s)=Y(s)
$$

Factor out $X(s)$:

$$
X(s)\left[16+2G_1(s)+50G_2(s)\right]=Y(s)
$$

So the transfer function is:

$$
\frac{X(s)}{Y(s)}=\frac{1}{16+2G_1(s)+50G_2(s)}
$$

Now use the ideal blocks:

$$
G_1(s)=s
$$

and:

$$
G_2(s)=\frac{1}{s}
$$

Substitute:

$$
G(s)=\frac{1}{16+2s+\frac{50}{s}}
$$

Multiply top and bottom by $s$:

$$
G(s)=\frac{s}{16s+2s^2+50}
$$

Factor out 2:

$$
G(s)=\frac{s}{2(s^2+8s+25)}
$$

Final answer:

$$
\boxed{G(s)=\frac{s}{2(s^2+8s+25)}}
$$

Exam note:

- The top summing junction subtracts the full feedback signal from the input.
- The gain $1/16$ comes after the top summing junction, so apply it after forming the error signal.
- The numerator $s$ means the system has a zero at $s=0$, so a constant/DC input does not produce a permanent output.

### Q3(iii)(b) Show Output for $y(t)=30u(t)$

Input:

$$
y(t)=30u(t)
$$

Laplace transform:

$$
Y(s)=\frac{30}{s}
$$

Use:

$$
X(s)=G(s)Y(s)
$$

Substitute:

$$
X(s)=
\frac{s}{2(s^2+8s+25)}
\frac{30}{s}
$$

Cancel $s$:

$$
X(s)=\frac{15}{s^2+8s+25}
$$

Complete the square in the denominator:

$$
s^2+8s+25=(s+4)^2+9
$$

Since:

$$
9=3^2
$$

we write:

$$
X(s)=\frac{15}{(s+4)^2+3^2}
$$

Factor out 5:

$$
X(s)=5\frac{3}{(s+4)^2+3^2}
$$

Use the inverse Laplace pair:

$$
\frac{b}{(s+a)^2+b^2}
\leftrightarrow
e^{-at}\sin(bt)
$$

Here:

$$
a=4,\qquad b=3
$$

Therefore:

$$
x(t)=5e^{-4t}\sin(3t)
$$

Final answer:

$$
\boxed{x(t)=5e^{-4t}\sin(3t),\qquad t>0}
$$

Plain meaning:

- The $e^{-4t}$ term makes the output decay.
- The $\sin(3t)$ term makes it oscillate.
- So this is a decaying oscillation, meaning the system is stable.

## Q3 Quick Templates

### Impulse Response to Transfer Function

If the impulse response is $g(t)$, then:

$$
G(s)=\mathcal{L}\{g(t)\}
$$

### Series Systems

Systems in series multiply:

$$
G_{\text{total}}(s)=G_1(s)G_2(s)
$$

### Input to Output

Always use:

$$
X(s)=G(s)Y(s)
$$

### Common Inputs

Step:

$$
u(t)\leftrightarrow\frac{1}{s}
$$

Ramp:

$$
t\leftrightarrow\frac{1}{s^2}
$$

Impulse:

$$
\delta(t)\leftrightarrow1
$$

### Damped Sine Inverse Laplace

$$
\frac{b}{(s+a)^2+b^2}
\leftrightarrow
e^{-at}\sin(bt)
$$

If there is a multiplier outside, keep it:

$$
5\frac{3}{(s+4)^2+3^2}
\leftrightarrow
5e^{-4t}\sin(3t)
$$
