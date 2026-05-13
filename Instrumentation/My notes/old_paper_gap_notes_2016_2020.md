# Old-Paper Gap Notes: 2016-2020 Topics

Use this as a last-pass patch for topics that appear in older papers but were less central in 2022-2025.

## 1. Thevenin Equivalent

Thevenin's theorem says:

> Any linear circuit seen from two terminals can be replaced by one ideal voltage source $V_{th}$ in series with one resistance $R_{th}$.

Equivalent circuit:

```text
      Rth
---/\/\/\/---●
             |
            load
             |
--- Vth -----●
```

### Why Do This?

It makes a complicated source network look like:

```text
simple source + internal resistance
```

Then connecting a load is easy.

### Step 1: Remove the load

If the question asks for the Thevenin equivalent seen by a load $R_L$, first remove $R_L$.

The load terminals are now open-circuit.

Open-circuit means:

- no wire/resistor connecting the two terminals
- no current flows through the removed load

### Step 2: Find $V_{th}$

$V_{th}$ is the voltage across the open load terminals.

Plain words:

> What voltage would the circuit provide if nothing was connected to it?

Often this is found using a voltage divider.

Example:

```text
Vs --- R1 ---●--- R2 --- ground
             |
           Vth
```

Then:

$$
V_{th}=V_s\frac{R_2}{R_1+R_2}
$$

### Step 3: Find $R_{th}$

To find $R_{th}$, turn off independent sources and look into the terminals.

Rules:

- ideal voltage source becomes a short circuit
- ideal current source becomes an open circuit

### What Does “Short the Voltage Source” Mean?

An ideal voltage source fixes a voltage.

If we “turn it off”, its voltage becomes:

$$
0\,\text{V}
$$

An ideal $0\,\text{V}$ voltage source is just a wire.

So replacing a voltage source by a short means:

```text
before:  +| |−   voltage source
after:   ───    wire
```

What this accomplishes:

- It removes the source's voltage push.
- It lets you calculate only the resistance of the surrounding resistor network.
- The circuit topology can change because nodes connected by the wire become the same node.

### Why resistors become parallel after shorting

If shorting the source makes the top and bottom of two resistors connect to the same two nodes, then those resistors are parallel.

Parallel means:

- same top node
- same bottom node
- same voltage across them

### Step 4: Reconnect load

Once you have $V_{th}$ and $R_{th}$, reconnect $R_L$:

```text
Vth source -> Rth -> RL
```

Then:

$$
V_L=V_{th}\frac{R_L}{R_{th}+R_L}
$$

## 2. Norton Equivalent

Norton's theorem says:

> Any linear circuit seen from two terminals can be replaced by one ideal current source $I_N$ in parallel with one resistance $R_N$.

Equivalent circuit:

```text
      ↑ IN
      |
      ●---- load ----●
      |              |
      R_N            |
      |              |
      ●--------------●
```

Relationship with Thevenin:

$$
R_N=R_{th}
$$

$$
I_N=\frac{V_{th}}{R_{th}}
$$

So if you can find Thevenin, you can immediately find Norton.

How to find $I_N$ directly:

- Short the output terminals.
- Calculate current through the short.
- That short-circuit current is $I_N$.

Plain words:

> Thevenin is voltage-source form. Norton is current-source form. They describe the same external behaviour.

## 3. Maximum Power Transfer

For a source with voltage $V_s$ and source resistance $R_s$ connected to load $R_L$:

```text
Vs --- Rs --- RL --- ground
```

Current:

$$
I=\frac{V_s}{R_s+R_L}
$$

Voltage across load:

$$
V_L=IR_L
$$

Power in load:

$$
P_L=I^2R_L
$$

Substitute current:

$$
P_L=\left(\frac{V_s}{R_s+R_L}\right)^2R_L
$$

So:

$$
P_L=\frac{V_s^2R_L}{(R_s+R_L)^2}
$$

### Differentiate to Find Maximum

Treat $V_s$ and $R_s$ as constants.

Need to maximise:

$$
P_L \propto \frac{R_L}{(R_s+R_L)^2}
$$

Differentiate with respect to $R_L$:

$$
\frac{d}{dR_L}\left[\frac{R_L}{(R_s+R_L)^2}\right]=0
$$

This gives:

$$
R_L=R_s
$$

So maximum power transfer occurs when:

$$
\boxed{R_L=R_s}
$$

### Intuition

If $R_L$ is tiny:

- current is high
- but load voltage is tiny
- so load power is not maximum

If $R_L$ is huge:

- load voltage is high
- but current is tiny
- so load power is not maximum

Maximum is the balance:

$$
R_L=R_s
$$

### Difference Between Matching and Measuring

For maximum power:

$$
R_L=R_s
$$

For voltage measurement without loading:

$$
R_{in}\gg R_s
$$

These are different goals.

### Transmission-Line Impedance Matching

For a cable:

$$
Z_L=Z_0
$$

means no reflection at the load.

Reflection coefficient:

$$
\Gamma=\frac{Z_L-Z_0}{Z_L+Z_0}
$$

If $Z_L=Z_0$:

$$
\Gamma=0
$$

So:

- power matching avoids reflections
- voltage measurement avoids loading

## 4. Op-Amp Differentiator

Standard inverting differentiator:

```text
Vin --- C ---●----(-) op amp
             |
             Rf
             |
           Vout

V+ grounded
```

The inverting node is virtual ground:

$$
V_-\approx0
$$

No current enters the op-amp.

Current through capacitor:

$$
i_C=C\frac{dV_i}{dt}
$$

Why?

Capacitor charge is:

$$
Q=CV
$$

Current is rate of charge flow:

$$
i=\frac{dQ}{dt}
$$

If $C$ is constant:

$$
i=C\frac{dV}{dt}
$$

This current must flow through feedback resistor:

$$
i_R=\frac{0-V_o}{R_f}=-\frac{V_o}{R_f}
$$

Set currents equal:

$$
C\frac{dV_i}{dt}=-\frac{V_o}{R_f}
$$

Therefore:

$$
\boxed{V_o=-R_fC\frac{dV_i}{dt}}
$$

If $R_f=R$:

$$
V_o=-RC\frac{dV_i}{dt}
$$

Laplace form with zero initial conditions:

$$
G(s)=\frac{V_o(s)}{V_i(s)}=-sRC
$$

Not Gaussian. This has nothing to do with Gaussian pulses; it comes from capacitor current.

## 5. Op-Amp Integrator

Standard inverting integrator:

```text
Vin --- R ---●----(-) op amp
             |
             C
             |
           Vout

V+ grounded
```

Input current through resistor:

$$
i_R=\frac{V_i-0}{R}=\frac{V_i}{R}
$$

No current enters the op-amp, so this current charges the feedback capacitor.

Capacitor current:

$$
i_C=C\frac{d(V_- - V_o)}{dt}
$$

Since:

$$
V_-\approx0
$$

the capacitor voltage is:

$$
V_C=0-V_o=-V_o
$$

So:

$$
i_C=C\frac{d(-V_o)}{dt}=-C\frac{dV_o}{dt}
$$

Set:

$$
\frac{V_i}{R}=-C\frac{dV_o}{dt}
$$

Therefore:

$$
\frac{dV_o}{dt}=-\frac{1}{RC}V_i
$$

Integrate:

$$
\boxed{V_o(t)=-\frac{1}{RC}\int V_i(t)\,dt}
$$

Laplace form with zero initial conditions:

$$
G(s)=\frac{V_o(s)}{V_i(s)}=-\frac{1}{sRC}
$$

## 6. Fourier Top-Hat Transform

This is the standard Fourier integration example.

Fourier transform definition:

$$
F(\omega)=\int_{-\infty}^{\infty}f(t)e^{-j\omega t}\,dt
$$

Top-hat pulse:

$$
f(t)=1\quad \text{for } -a<t<a
$$

and:

$$
f(t)=0\quad \text{otherwise}
$$

Since it is zero outside $-a$ to $a$:

$$
F(\omega)=\int_{-a}^{a}e^{-j\omega t}\,dt
$$

Integrate:

$$
F(\omega)=\left[\frac{e^{-j\omega t}}{-j\omega}\right]_{-a}^{a}
$$

Substitute limits:

$$
F(\omega)=\frac{e^{-j\omega a}-e^{j\omega a}}{-j\omega}
$$

Use Euler:

$$
e^{jx}=\cos x+j\sin x
$$

$$
e^{-jx}=\cos x-j\sin x
$$

So:

$$
e^{-jx}-e^{jx}=-2j\sin x
$$

Therefore:

$$
F(\omega)=\frac{-2j\sin(\omega a)}{-j\omega}
$$

Final:

$$
\boxed{F(\omega)=\frac{2\sin(\omega a)}{\omega}}
$$

Alternative sinc form:

$$
F(\omega)=2a\frac{\sin(\omega a)}{\omega a}
$$

### Intuition

A top-hat has sharp edges.

Sharp edges require high-frequency components.

So a perfect rectangular pulse has frequency components extending forever.

Shorter pulse in time means broader spectrum.

## 7. Laplace With Initial Conditions

In many simple transfer-function questions, we assume **zero initial conditions**.

That means:

$$
x(0^+)=0
$$

and:

$$
x'(0^+)=0
$$

Then derivative transforms look simple:

$$
\mathcal{L}\left\{\frac{dx}{dt}\right\}=sX(s)
$$

But the full rule is:

$$
\mathcal{L}\left\{\frac{dx}{dt}\right\}=sX(s)-x(0^+)
$$

Second derivative:

$$
\mathcal{L}\left\{\frac{d^2x}{dt^2}\right\}=s^2X(s)-sx(0^+)-x'(0^+)
$$

### What is $x(0^+)$?

$x(0^+)$ means the value just after $t=0$.

It matters when there is stored energy at the start:

- capacitor has initial voltage
- inductor has initial current
- mechanical system has initial displacement/velocity

### How This Differs From Usual Q3 Transfer-Function Questions

For transfer functions:

$$
G(s)=\frac{X(s)}{Y(s)}
$$

we usually assume zero initial conditions.

Reason:

> A transfer function describes input-output behaviour of the system itself, not the extra response caused by stored initial energy.

So in many Q3-style problems:

$$
\mathcal{L}\left\{\frac{dx}{dt}\right\}=sX(s)
$$

because:

$$
x(0^+)=0
$$

### If Initial Conditions Are Nonzero

Example:

$$
\frac{dx}{dt}+ax=y(t)
$$

Laplace:

$$
sX(s)-x(0^+)+aX(s)=Y(s)
$$

So:

$$
(s+a)X(s)=Y(s)+x(0^+)
$$

The output has two contributions:

1. forced response from input $Y(s)$
2. natural response from initial condition $x(0^+)$

Exam phrase:

> Nonzero initial conditions add extra terms in the Laplace-domain equation. They represent stored energy already present in the system before the input is applied.

## 8. Last-Minute Recognition

If you see:

- **remove load, find equivalent circuit**: Thevenin/Norton.
- **maximum power**: set $R_L=R_s$.
- **long cable / reflection**: use $Z_0$ and $\Gamma$.
- **capacitor at op-amp input**: differentiator.
- **capacitor in feedback**: integrator.
- **rectangular pulse / sharp edge**: Fourier top-hat and broad spectrum.
- **initial capacitor voltage / initial inductor current**: use Laplace initial-condition terms.

