# Bayesian Recall Sheet

Rebuild this from memory first. Watch notation conventions carefully.

## Core Bayes

For parameters $\theta$ and data $d$:

$$
p(\theta \mid d)=\frac{p(d \mid \theta)\pi(\theta)}{p(d)}
$$

- $p(d \mid \theta)$: likelihood when viewed as function of $\theta$ with data fixed.
- $\pi(\theta)$: prior.
- $p(\theta \mid d)$: posterior.
- $p(d)=\int p(d \mid \theta)\pi(\theta)\,d\theta$: evidence or marginal likelihood.

Likelihood vs sampling distribution:

- Sampling distribution: function of possible data with parameters fixed.
- Likelihood: same mathematical object viewed as a function of parameters with observed data fixed.

## Posterior Summaries

- MAP: maximise posterior, usually by maximising $\log p(\theta \mid d)$.
- Posterior mean: $E[\theta \mid d]=\int \theta\,p(\theta \mid d)\,d\theta$.
- Posterior variance: $E[\theta^2 \mid d]-E[\theta \mid d]^2$.
- Curvature approximation near MAP: $\sigma_\theta^{-2}=-\frac{d^2}{d\theta^2}\log p(\theta \mid d)$ at the MAP.
- Credible interval: posterior probability statement, not repeated-experiment coverage.

## Gaussian Unknown Mean and Sigma

Common setup: repeated independent measurements $x_1,\dots,x_n$ of a true quantity $\mu$, with Gaussian measurement error of unknown standard deviation $\sigma$.

Data model:

$$
x_i\mid \mu,\sigma \sim \mathcal{N}(\mu,\sigma^2).
$$

Likelihood:

$$
p(\{x_i\}\mid \mu,\sigma)
=
\prod_{i=1}^n
\frac{1}{\sqrt{2\pi}\sigma}
\exp\left[-\frac{(x_i-\mu)^2}{2\sigma^2}\right].
$$

Bayesian posterior:

$$
p(\mu,\sigma\mid \{x_i\})
\propto
p(\{x_i\}\mid \mu,\sigma)\pi(\mu)\pi(\sigma).
$$

Read the question by identifying:

- unknowns to infer: $\mu,\sigma$;
- observed data: $\{x_i\}$;
- likelihood: Gaussian measurement model;
- priors: whatever the question specifies, often factorised as $\pi(\mu)\pi(\sigma)$.

Gaussian integral and completing-square memory hook:

When marginalising over $\mu$, aim to rewrite

$$
\sum_{i=1}^n (x_i-\mu)^2
$$

as

$$
n(\mu-\bar{x})^2+n\sigma_x^2,
$$

where

$$
\sigma_x^2=\frac{1}{n}\sum_{i=1}^n x_i^2-\bar{x}^2.
$$

You want the $n(\mu-\bar{x})^2$ form because the integral over $\mu$ then becomes a standard Gaussian-shaped integral centred at $\bar{x}$:

$$
\int_{-\infty}^{\infty}
\exp\left[-\frac{n(\mu-\bar{x})^2}{2\sigma^2}\right]\,d\mu
=
\sqrt{2\pi}\frac{\sigma}{\sqrt{n}}.
$$

The general form to remember is

$$
\int_{-\infty}^{\infty}
\exp\left[-\frac{(x-a)^2}{2s^2}\right]\,dx
=
\sqrt{2\pi}s.
$$

This comes from the normalised Gaussian pdf: since

$$
\frac{1}{\sqrt{2\pi}s}
\exp\left[-\frac{(x-a)^2}{2s^2}\right]
$$

integrates to $1$, the exponential part alone must integrate to $\sqrt{2\pi}s$.

## Priors

- Uniform prior is often acceptable for a bounded probability or location parameter.
- Scale-like parameters often motivate log-uniform/Jeffreys-style priors such as $\pi(\sigma)\propto 1/\sigma$.
- For evidence/model comparison, priors must be proper and normalised.
- If the paper specifies a prior form, use that form even if another prior could be argued.

Prior choice cheat sheet:

| Parameter type | Typical prior | When/why |
|---|---|---|
| Location parameter, e.g. mean/true length $\mu$ | Uniform prior $\pi(\mu)\propto 1$ | Shifting the origin/units should not change prior preference; no preferred location. |
| Scale parameter, e.g. $\sigma,\lambda,\tau$ when positive | Jeffreys/log-uniform prior $\pi(\theta)\propto 1/\theta$ | Equal weight per multiplicative scale; no preferred order of magnitude. |
| Probability $q\in[0,1]$ with no prior preference | Uniform/Beta$(1,1)$ | Every value of $q$ equally weighted before data. |
| Probability $q\in[0,1]$ with pseudo-count information | Beta prior $\pi(q)\propto q^{\alpha-1}(1-q)^{\beta-1}$ | Conjugate to binomial; $\alpha,\beta$ encode prior successes/failures shape. |
| Model comparison/evidence | Proper normalised prior over finite range | Evidence requires an actual normalised prior volume. |

Improper priors such as $\pi(\mu)\propto 1$ or $\pi(\sigma)\propto 1/\sigma$ can be fine for parameter inference if the posterior normalises, but they cannot be used directly for evidence/model comparison.

## Conjugacy

A conjugate prior gives a posterior in the same family after multiplying by the likelihood.

Binomial likelihood:

$$
p(n \mid N,q)\propto q^n(1-q)^{N-n}
$$

Beta convention 1:

- Prior: $\pi(q)\propto q^{a-1}(1-q)^{b-1}$.
- Posterior: $q^{a+n-1}(1-q)^{b+N-n-1}$, so $a\to a+n$, $b\to b+N-n$.
- Uniform prior: $a=b=1$.

For beta-binomial questions with $M$ successes in $N$ trials:

$$
p(M\mid N,q)\propto q^M(1-q)^{N-M}
$$

and

$$
\pi(q)\propto q^{\alpha-1}(1-q)^{\beta-1}
$$

gives

$$
p(q\mid M,N)\propto q^{M+\alpha-1}(1-q)^{N-M+\beta-1}.
$$

So the posterior is another beta distribution with updated parameters

$$
\alpha\to \alpha+M,\qquad \beta\to \beta+N-M.
$$

Reading beta-prior shapes:

- $\alpha=\beta=1$: uniform prior.
- $\alpha>1,\ \beta>1$: peaked inside the interval; if $\alpha=\beta$ it is symmetric around $q=1/2$.
- $\alpha<1$ gives extra weight near $q=0$.
- $\beta<1$ gives extra weight near $q=1$ because $(1-q)^{\beta-1}$ diverges as $q\to 1$.
- Larger $\alpha$ relative to $\beta$ shifts mass toward larger $q$; larger $\beta$ relative to $\alpha$ shifts mass toward smaller $q$.

MAP and curvature template:

If

$$
p(q\mid M,N)\propto q^C(1-q)^D,
$$

then

$$
\log p(q\mid M,N)=C\log q+D\log(1-q)+\mathrm{const}.
$$

The MAP solves

$$
\frac{d}{dq}\log p(q\mid M,N)=\frac{C}{q}-\frac{D}{1-q}=0,
$$

so

$$
q_{\mathrm{MAP}}=\frac{C}{C+D}.
$$

The second derivative is

$$
\frac{d^2}{dq^2}\log p(q\mid M,N)
=
-\frac{C}{q^2}-\frac{D}{(1-q)^2}.
$$

The local Gaussian inverse variance uses the negative curvature at the peak:

$$
\sigma_q^{-2}\simeq
-\left.\frac{d^2}{dq^2}\log p(q\mid M,N)\right|_{q=q_{\mathrm{MAP}}}.
$$

Beta/Dirichlet exponent convention used in some papers:

- Prior: $\pi(q)\propto q^x(1-q)^y$.
- Posterior exponents: $x\to x+n$, $y\to y+N-n$.
- Uniform prior: $x=y=0$.

Poisson rate kernel:

- For a single observed count $n$, $L(\lambda)\propto \lambda^n e^{-\lambda}$.
- With prior kernel $\pi(\lambda)\propto \lambda^c$, posterior kernel is $\lambda^{n+c}e^{-\lambda}$.
- If the question gives a prior, use exactly that exponent convention.

## Sequential Updating

Updating with $d_1$ then $d_2$ gives the same posterior as updating once with both datasets, when the same likelihood assumptions are used:

$$
p(\theta \mid d_1,d_2)\propto p(d_2 \mid \theta,d_1)p(d_1 \mid \theta)\pi(\theta)
$$

For conditionally independent datasets:

$$
p(\theta \mid d_1,d_2)\propto p(d_2 \mid \theta)p(d_1 \mid \theta)\pi(\theta)
$$

Product rules used in sequential updating:

$$
p(A,B)=p(B\mid A)p(A)
$$

Equally valid reversed ordering:

$$
p(A,B)=p(A\mid B)p(B).
$$

This is the same joint probability written in two different orders. It says: probability of both things = probability of one thing, times probability of the other after the first is known.

and, conditioning on a parameter/model,

$$
p(A,B\mid \theta)=p(B\mid A,\theta)p(A\mid \theta).
$$

Equally valid reversed ordering:

$$
p(A,B\mid \theta)=p(A\mid B,\theta)p(B\mid \theta).
$$

So for two datasets,

$$
p(d_1,d_2\mid \theta)=p(d_2\mid d_1,\theta)p(d_1\mid \theta)
$$

and

$$
p(d_1,d_2)=p(d_2\mid d_1)p(d_1).
$$

Also:

$$
p(d_1,d_2)=p(d_1\mid d_2)p(d_2).
$$

Use whichever ordering matches the update being described.

Second update as conditional Bayes:

$$
p(\theta\mid d_2,d_1)
=
\frac{p(d_2\mid \theta,d_1)p(\theta\mid d_1)}
{p(d_2\mid d_1)}.
$$

Read this as: after $d_1$ is already known, update using the new data $d_2$. The prior for this update is $p(\theta\mid d_1)$, not the original $\pi(\theta)$.

Bayes with background information:

$$
p(A\mid B,C)=\frac{p(B\mid A,C)p(A\mid C)}{p(B\mid C)}.
$$

For the second update, take $A=\theta$, $B=d_2$, and $C=d_1$:

$$
p(\theta\mid d_2,d_1)
=
\frac{p(d_2\mid \theta,d_1)p(\theta\mid d_1)}
{p(d_2\mid d_1)}.
$$

Roles:

- posterior: $p(\theta\mid d_2,d_1)$, what we know about $\theta$ after old and new data;
- likelihood: $p(d_2\mid\theta,d_1)$, probability of the new data if $\theta$ is true and old data are already known;
- prior for this update: $p(\theta\mid d_1)$, old posterior reused as the new prior;
- evidence: $p(d_2\mid d_1)$, normalisation for the second update.

Memory version:

$$
p(\theta\mid \text{new data},\text{old info})
=
\frac{
p(\text{new data}\mid \theta,\text{old info})
p(\theta\mid \text{old info})
}{
p(\text{new data}\mid \text{old info})
}.
$$

For sequential updating, the old info is $d_1$ and the new data is $d_2$, so the likelihood for the second update is $p(d_2\mid \theta,d_1)$ rather than $p(d_1,d_2\mid \theta)$. The joint likelihood appears only after substituting the first posterior and using the product rule.

## Evidence and Model Comparison

Evidence for model $M$:

$$
p(d \mid M)=\int p(d \mid \theta,M)\pi(\theta \mid M)\,d\theta
$$

Posterior odds:

$$
\frac{p(M_0 \mid d)}{p(M_1 \mid d)}
=
\frac{p(d \mid M_0)}{p(d \mid M_1)}
\frac{p(M_0)}{p(M_1)}
$$

If prior model probabilities are equal, posterior odds equal the Bayes factor.

Occam penalty: evidence rewards good fit but averages over prior volume, so a flexible model is penalised if only a small part of its prior space fits the data.

## Hierarchical and SBI

- Latent variables are unobserved quantities needed to describe the data-generating process.
- Hierarchical posterior: write joint model, condition on observed data, then integrate/sum over latent variables.
- SBI / likelihood-free inference: use simulations to approximate $p(\theta\mid d_{\mathrm{obs}})$ when the likelihood is unavailable or too expensive.
- Basic SBI recipe: draw $\theta_j\sim\pi(\theta)$, simulate $d_j\sim p(d\mid\theta_j)$, compare $d_j$ or summaries $s(d_j)$ to $d_{\mathrm{obs}}$, and use the accepted/weighted $\theta_j$ values as an approximate posterior.
- ABC: the simplest SBI method; accept/weight simulations with $\rho(s(d_j),s(d_{\mathrm{obs}}))<\epsilon$.
- Modern SBI alternatives: neural posterior estimation, neural likelihood estimation, likelihood-ratio estimation, normalising flows. These learn an approximate posterior/likelihood/ratio from simulations.
- Sketch memory: vertical slice at fixed $\theta$ gives a sampling distribution $p(d\mid\theta)$; horizontal slice near observed data gives posterior over $\theta$.
- Compression: reduce data to sufficient or near-sufficient summaries when raw data are too large for SBI. Risk: bad summaries lose information.
- SBI challenges: simulation cost, high-dimensional data, choosing summaries/tolerance, approximation error, validating coverage/calibration.

Gaussian compression trick:

For

$$
p(\{x_i\}\mid \mu)
\propto
\exp\left[-\frac{1}{2}\sum_i\frac{(x_i-\mu)^2}{\sigma_i^2}\right],
$$

expand the square. Terms depending only on $x_i$ can be ignored for the posterior of $\mu$ because they cancel into the evidence. The mixed term is

$$
\mu\sum_i\frac{x_i}{\sigma_i^2},
$$

so the data enter the posterior through the compressed statistic

$$
X=\sum_i\frac{x_i}{\sigma_i^2}.
$$

Taxi-style problem:

- If licences run from $1$ to $N$ and one observed licence is $n$, then $p(n \mid N)=1/N$ for $N\ge n$, zero otherwise.
- With a uniform truncated prior on $N$, posterior kernel is $p(N \mid n)\propto 1/N$ for $N\ge n$.
- The MLE is $\hat{N}=n$, but the Bayesian posterior exposes the long upper tail.
