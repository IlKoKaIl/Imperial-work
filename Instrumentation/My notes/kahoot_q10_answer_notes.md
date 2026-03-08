# Kahoot Quiz (10 Questions) - Correct Answers + Short Explanations

Use this as your presenter crib sheet during setup/review.

## Q1

**Question:** When an impulse is applied to an unstable system, what happens to the resulting transients?  
**Correct answer:** They increase with time, so the quiescent condition is never returned to.  
**Why:** Unstable systems have at least one mode that grows with time, so impulse response does not decay back to rest.

## Q2

**Question:** Feedback amplifier: what happens when a negative feedback system experiences a phase change at the output going to \(-180^\circ\)?  
**Correct answer:** It goes into unstable positive feedback.  
**Why:** At \(-180^\circ\), the sign of feedback effectively flips. With sufficient loop gain (\(|A\beta|\ge 1\)), this drives instability.

## Q3

**Question:** For a general transfer function, what do we call the values of \(s\) that make the denominator \(Q(s)=0\)?  
**Correct answer:** Poles.  
**Why:** By definition, poles are roots of the denominator of \(G(s)=P(s)/Q(s)\).

## Q4

**Question:** When examining the roots of a transfer function’s denominator in the complex plane, what indicates a stable system?  
**Correct answer:** Roots in the \(\sigma<0\) side of the plane.  
**Why:** Negative real parts give decaying exponentials \(e^{\sigma t}\), so transients die out.

## Q5

**Question:** What is the physical meaning of a transfer function having purely imaginary roots?  
**Correct answer:** The system will exhibit sustained oscillation, which is still stable (course convention).  
**Why:** Purely imaginary roots give constant-amplitude sinusoids (no decay, no growth). In these notes this is treated as stable boundary behavior.

## Q6

**Question:** Which mathematical tool is useful for analysing circuits for initial value problems, such as when a switch is thrown?  
**Correct answer:** Laplace Transform.  
**Why:** Laplace is one-sided (\(0\to\infty\)) and naturally handles initial conditions in derivative transforms.

## Q7

**Question:** In an electrical circuit, what is the mathematical expression for the voltage across the inductor?  
**Correct answer:** \(v_L = L\,\dfrac{di}{dt}\).  
**Why:** This is the constitutive law for an ideal inductor.

## Q8

**Question:** In a switched series RLC circuit connected to a constant DC voltage source, what happens to current for big values of \(t\)?  
**Correct answer:** It tends to zero.  
**Why:** At long time, capacitor behaves like open circuit for DC steady state, so current goes to zero.

## Q9 (added)

**Question:** Which pole sets are stable according to these notes? (multi-select)  
**Options:** \(\{-1,-3\}\), \(\{+0.5,-2\}\), \(\{\pm j4\}\), \(\{0\}\), \(\{-0.2\pm j3\}\)  
**Correct answers:** \(\{-1,-3\}\), \(\{\pm j4\}\), \(\{0\}\), \(\{-0.2\pm j3\}\).  
**Why:**  
- Any pole with \(\Re(s)>0\) is unstable (\(\{+0.5,-2\}\) fails).  
- Negative-real poles are stable.  
- In these notes, purely imaginary poles and \(s=0\) are treated as stable boundary cases (bounded, non-growing output).

## Q10 (added)

**Question:** If \(f(0^+)=5\), what is \(\mathcal{L}\{f'(t)\}\)?  
**Correct answer:** \(sF(s)-5\).  
**Why:** Full first-derivative rule is
\[
\mathcal{L}\{f'(t)\}=sF(s)-f(0^+).
\]
Substitute \(f(0^+)=5\Rightarrow sF(s)-5\).

---

## Fast reminder for delivery

- Transfer function definition: \(G(s)=\dfrac{\text{output}}{\text{input}}\).
- Pole test for stability: check real part of denominator roots.
- One right-half-plane pole is enough for instability.
