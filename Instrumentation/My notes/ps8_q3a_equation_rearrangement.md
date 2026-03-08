# PS8 Q3(a): Equation Rearrangement (Slide-Ready)

Use these four lines in order.

## LaTeX version

1. Start from the block/summing equation:

$$
X(s)=Y(s)G_0(s)+7X(s)G_1(s)G_2(s)-3X(s)G_1(s)
$$

2. Move all $X(s)$ terms to the left:

$$
X(s)-7X(s)G_1(s)G_2(s)+3X(s)G_1(s)=Y(s)G_0(s)
$$

3. Factor out $X(s)$:

$$
X(s)\left[1+G_1(s)\left(3-7G_2(s)\right)\right]=Y(s)G_0(s)
$$

4. Divide by $Y(s)$ to get transfer function:

$$
\frac{X(s)}{Y(s)}=\frac{G_0(s)}{1+G_1(s)\left(3-7G_2(s)\right)}
$$

## Plain-text fallback (if slide app does not render LaTeX)

1) X(s) = Y(s)G0(s) + 7X(s)G1(s)G2(s) - 3X(s)G1(s)
2) X(s) - 7X(s)G1(s)G2(s) + 3X(s)G1(s) = Y(s)G0(s)
3) X(s)[1 + G1(s)(3 - 7G2(s))] = Y(s)G0(s)
4) X(s)/Y(s) = G0(s) / [1 + G1(s)(3 - 7G2(s))]

---

# PS8 Q3(b): Unity differentiator/integrator and Laplace steps

## Convention (important)

For any block:
$$
G_{\text{block}}(s)=\frac{\text{block output}}{\text{block input}}.
$$

If we call block input $U(s)$ and output $V(s)$:
$$
G_{\text{block}}(s)=\frac{V(s)}{U(s)}.
$$

In this section, for the differentiator/integrator examples, we use:
- input $\to x(t)$ / $X(s)$
- output $\to y(t)$ / $Y(s)$

So here:
$$
G(s)=\frac{Y(s)}{X(s)}.
$$

## What "unity differentiator" means

Time-domain definition:
$$
y(t)=\frac{d}{dt}x(t)
$$

Laplace (general):
$$
Y(s)=sX(s)-x(0^+)
$$

For transfer-function form we assume initially relaxed input/state, so $x(0^+)=0$:
$$
Y(s)=sX(s)\quad\Rightarrow\quad G_{\text{diff}}(s)=\frac{Y(s)}{X(s)}=s
$$

"Unity" means no extra constant gain factor in front (just $1\cdot d/dt$).

## What "unity integrator" means

Time-domain definition:
$$
y(t)=\int_0^t x(\tau)\,d\tau
$$

Laplace:
$$
Y(s)=\frac{X(s)}{s}
\quad\Rightarrow\quad
G_{\text{int}}(s)=\frac{Y(s)}{X(s)}=\frac{1}{s}
$$

Again, "unity" means no extra multiplier (just $1\cdot\int$).

## How to convert $g_0(t)$ to $G_0(s)$ (actual integration)

Given:
$$
g_0(t)=24t\,e^{-2t}
$$

For an LTI system, transfer function from impulse response is:
$$
G_0(s)=\mathcal{L}\{g_0(t)\}
$$

Yes: Laplace is one-sided, integrate from $0$ to $\infty$:
$$
G_0(s)=\int_0^\infty 24t\,e^{-2t}e^{-st}\,dt
=24\int_0^\infty t\,e^{-(s+2)t}\,dt
$$

Let $a=s+2$ (with $\Re(a)>0$):
$$
\int_0^\infty t\,e^{-at}\,dt=\frac{1}{a^2}
$$

So:
$$
G_0(s)=\frac{24}{(s+2)^2}
$$

## Q3(b) substitution line

Use:
$$
G_0(s)=\frac{24}{(s+2)^2},\quad
G_1(s)=s,\quad
G_2(s)=\frac{1}{s}
$$

Then put into part (a):
$$
G(s)=\frac{G_0(s)}{1+G_1(s)\left(3-7G_2(s)\right)}
=\frac{24}{(s+2)^2(3s-6)}
$$

## Q3(c): Stability and oscillation (with why)

Start from:
$$
G(s)=\frac{24}{(s+2)^2(3s-6)}
=\frac{8}{(s+2)^2(s-2)}.
$$

Poles are where the denominator is zero:
$$
s=-2 \text{ (double pole)},\qquad s=+2.
$$

### Why this means unstable

- A pole with $\Re(s)>0$ gives a term like $e^{\sigma t}$ with $\sigma>0$, which grows with time.
- Here, $s=+2$ is in the right-half plane, so output has a growing component $\propto e^{2t}$.
- One right-half-plane pole is enough to make the full system unstable.

### Why this does not oscillate sinusoidally

- Pure sinusoidal oscillation comes from nonzero imaginary part ($\omega\neq 0$), i.e. poles of form $s=\sigma\pm j\omega$.
- Here the poles are purely real ($\omega=0$), so the response is exponential terms, not sinusoidal terms.
- So this system is **unstable and non-oscillatory** (growth without sinusoidal ringing).

### Where this is taught in your notes

- `..\My notes\chp17-18_study_notes.md`:
- Section `2. Chapter 17 Core Ideas`
- Section `2.3 Poles, zeros, and root-location test`
- Rule used there: any pole with $\Re(s)>0$ implies instability.
- Also stated there: real positive pole gives non-oscillatory exponential growth.

## Q3(d): Time-domain response to a unit step (no skipped steps)

Input is a unit step:
$$
y(t)=u(t)\quad\Rightarrow\quad Y(s)=\frac{1}{s}.
$$

From part (b):
$$
G(s)=\frac{24}{(s+2)^2(3s-6)}=\frac{8}{(s+2)^2(s-2)}.
$$

So:
$$
X(s)=G(s)Y(s)=\frac{8}{s(s+2)^2(s-2)}.
$$

### Step 1: partial fraction form

Because denominator has one simple pole at $s=0$, one repeated pole at $s=-2$ (order 2), and one simple pole at $s=2$:
$$
\frac{8}{s(s+2)^2(s-2)}
=\frac{A}{s}+\frac{B}{s+2}+\frac{C}{(s+2)^2}+\frac{D}{s-2}.
$$

### Step 2: solve constants

Multiply both sides by $s(s+2)^2(s-2)$:
$$
8=A(s+2)^2(s-2)+Bs(s+2)(s-2)+Cs(s-2)+Ds(s+2)^2.
$$

1) Set $s=0$:
$$
8=A(2)^2(-2)\Rightarrow A=-1.
$$

2) Set $s=2$:
$$
8=D\cdot 2\cdot 4^2=32D\Rightarrow D=\frac14.
$$

3) Set $s=-2$:
$$
8=C(-2)(-4)=8C\Rightarrow C=1.
$$

4) Find $B$ using any other convenient value (e.g. $s=3$):
$$
8=A(25)(1)+B(3)(5)(1)+C(3)(1)+D(3)(25).
$$
Substitute $A=-1,\ C=1,\ D=\frac14$:
$$
8=-25+15B+3+\frac{75}{4}
\Rightarrow 15B=\frac{45}{4}
\Rightarrow B=\frac34.
$$

Hence:
$$
X(s)= -\frac{1}{s}+\frac{3}{4(s+2)}+\frac{1}{(s+2)^2}+\frac{1}{4(s-2)}.
$$

### Step 3: inverse Laplace term-by-term

Use basic pairs:
$$
\mathcal{L}^{-1}\!\left\{\frac{1}{s}\right\}=u(t),\quad
\mathcal{L}^{-1}\!\left\{\frac{1}{s+a}\right\}=e^{-at},\quad
\mathcal{L}^{-1}\!\left\{\frac{1}{(s+a)^2}\right\}=te^{-at},\quad
\mathcal{L}^{-1}\!\left\{\frac{1}{s-a}\right\}=e^{at}.
$$

So for $t>0$:
$$
x(t)= -1+\frac{3}{4}e^{-2t}+te^{-2t}+\frac14 e^{2t}.
$$

This matches the provided solution (same terms, re-ordered).

### Why this matters physically

- The $e^{2t}$ term is exactly the unstable mode identified in part (c) from pole $s=+2$.
- The $e^{-2t}$ terms decay (stable modes from pole $s=-2$).

### Where this is taught in your notes

- `..\My notes\chp15-16_study_notes.md`:
- Section `3.4 Transfer function definition and block algebra` ($X=GY$)
- Section `4.2 Worked style: series system with step input` (set up $X(s)$ then inverse transform)
- Section `4.4 Partial fractions: reliable exam workflow`
- `chp15-16.pdf`:
- Section `16.1` and `16.4` are the direct templates for this method.

## Plain-text fallback for slides

1) unity differentiator: y(t)=d/dt x(t) -> Y(s)=sX(s) -> Gdiff(s)=s  
2) unity integrator: y(t)=int_0^t x(tau)dtau -> Y(s)=X(s)/s -> Gint(s)=1/s  
3) G0(s)=L{24 t e^(-2t)}=24 int_0^inf t e^(-(s+2)t)dt=24/(s+2)^2  
4) substitute into part (a) to get G(s)=24/((s+2)^2(3s-6))
