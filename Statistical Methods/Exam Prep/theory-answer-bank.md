# Theory Answer Bank

Use this for short "state/describe/explain/devise/comment" questions. Aim for one sentence plus one formula/procedure where possible.

## Frequentist Definitions

Type I and Type II errors:

$$
\alpha=P(T\in w\mid H_0)
$$

is the Type I error: reject $H_0$ when $H_0$ is true.

$$
\beta=P(T\notin w\mid H_1)
$$

is the Type II error: fail to reject $H_0$ when $H_1$ is true.

Power:

$$
1-\beta=P(T\in w\mid H_1).
$$

It is the probability that the test rejects $H_0$ when the chosen alternative $H_1$ is true.

p-value:

For a large-$T$ critical region,

$$
p=P(T\ge T_{\mathrm{obs}}\mid H_0).
$$

It is the probability, assuming $H_0$, of seeing a result at least as extreme as observed.

Critical region:

$$
w=\{T:\text{ reject }H_0\}.
$$

Choose $w$ so that $P(T\in w\mid H_0)=\alpha$.

## Good Estimator Definitions

Bias:

$$
\mathrm{bias}(\hat{\theta})=E[\hat{\theta}]-\theta.
$$

Unbiased:

$$
E[\hat{\theta}]=\theta.
$$

Consistent:

$$
\hat{\theta}_N\xrightarrow[N\to\infty]{p}\theta,
$$

or equivalently

$$
P(|\hat{\theta}_N-\theta|>\epsilon)\to0
$$

for any $\epsilon>0$.

Efficient:

An estimator has the smallest variance among valid estimators, often saturating the Cramer-Rao bound:

$$
\mathrm{Var}(\hat{\theta})\ge \frac{1}{I(\theta)}.
$$

MSE:

$$
\mathrm{MSE}(\hat{\theta})=E[(\hat{\theta}-\theta)^2]
=\mathrm{Var}(\hat{\theta})+\mathrm{bias}(\hat{\theta})^2.
$$

## Conditional Probability Trap

If

$$
P(A\mid B)=x,
$$

then

$$
P(\neg A\mid B)=1-x.
$$

Do not infer

$$
P(A\mid \neg B)=1-x.
$$

Example faulty-test/theft-alarm wording: keep the condition after the bar fixed when taking complements.

Total probability for an observed alarm $A$:

$$
P(A)=P(A\mid G)P(G)+P(A\mid I)P(I).
$$

## Empirical CDF and KS Test

Empirical CDF:

For observed sorted data $t_{(1)}\le\cdots\le t_{(n)}$,

$$
F_{\mathrm{emp}}(t)=\frac{\#\{t_i\le t\}}{n}.
$$

It is a step function increasing by $1/n$ at each observed data point.

KS statistic:

$$
D=\max_t |F_{\mathrm{emp}}(t)-F(t)|.
$$

To test goodness of fit, compare $D_{\mathrm{obs}}$ to the distribution of $D$ under $H_0$. If $D_{\mathrm{obs}}$ lies in the critical tail, reject $H_0$; otherwise fail to reject.

If a plot shows $D_{95}$ with 95 percent of $H_0$ values below it, then reject at $\alpha=0.05$ if

$$
D_{\mathrm{obs}}>D_{95}.
$$

## Neyman Confidence Interval / Region

Use when asked to construct a 68 percent or 95 percent confidence interval/region.

Let $\theta$ mean the parameter or parameter vector being constrained. For example, $\theta=\tau$ for a lifetime interval, or $\theta=(m,c)$ for a confidence region in the $m,c$ plane.

1. Choose a test statistic for the data, often a profile likelihood-ratio statistic:
   $$
   t(\theta)=-2\ln\left[\frac{L(\theta)}{L(\hat{\theta})}\right].
   $$
   Here $\hat{\theta}$ is the best-fit/MLE value.
2. Calculate the observed value $t_{\mathrm{obs}}(\theta)$ from the real data. For a region, this value is evaluated for each grid point $\theta$.
3. For a grid/range of candidate parameter values $\theta$, derive or simulate the distribution
   $$
   f(t;\theta)
   $$
   assuming that candidate value $\theta$ is the true value.
4. Choose an ordering rule to define the accepted 68 percent region in $t$ for each $\theta$. For a statistic such as $t=-2\ln[L(\theta)/L(\hat{\theta})]$, large values mean worse agreement, so the accepted region is usually the non-extreme/small-$t$ part of the distribution.
5. For each value of $\theta$, determine whether the observed value $t_{\mathrm{obs}}(\theta)$ lies inside that 68 percent accepted region or not. Equivalently, for a large-$t$ tail statistic compute
   $$
   p(\theta)=\int_{t_{\mathrm{obs}}(\theta)}^\infty f(t;\theta)\,dt
   $$
   which is the probability, assuming $\theta$ is true, of getting a test statistic outside/more extreme than the observed one. Keep candidate values with
   $$
   p(\theta)>1-0.68=0.32.
   $$
   For 95 percent, use $p(\theta)>0.05$.
6. The union of all kept parameter values is the confidence interval/region.

Memory:

> Propose, simulate, cut, compare, keep.

Exam wording:

> Choose $t(\theta)=-2\ln[L(\theta)/L(\hat{\theta})]$. For each trial value $\theta$ on a grid, generate the distribution $f(t;\theta)$ assuming $\theta$ is true. Choose the accepted 68 percent region of that distribution. For each $\theta$, check whether $t_{\mathrm{obs}}(\theta)$ lies inside the 68 percent region. Equivalently, calculate the tail probability $p(\theta)=\int_{t_{\mathrm{obs}}}^{\infty}f(t;\theta)\,dt$ and keep values with $p(\theta)>0.32$. The union of kept values is the 68 percent confidence interval/region.

Do not say there is a 68 percent probability the fixed parameter is inside. Say the construction has 68 percent coverage.

## Likelihood-Ratio Hypothesis Test

Use for "devise a hypothesis test" questions.

1. Define
   $$
   H_0=\text{null/simple model},\qquad H_1=\text{alternative/flexible model}.
   $$
2. Choose the size, e.g. $\alpha=0.05$.
3. Use the given likelihood-ratio statistic, e.g.
   $$
   t=-2\ln\left[\frac{L(H_0)}{L(H_1)}\right].
   $$
   Follow the order in the question and state which direction is more extreme.
4. Generate the distribution of $t$ under $H_0$ using simulations/toys, or use Wilks/chi-square if justified.
5. Define the critical region $w$ so that
   $$
   P(t\in w\mid H_0)=\alpha.
   $$
6. Calculate $t_{\mathrm{obs}}$ from the real data.
7. If $t_{\mathrm{obs}}\in w$, reject $H_0$; otherwise fail to reject.
8. Power is found using the same critical region but toys under $H_1$:
   $$
   1-\beta=P(t\in w\mid H_1).
   $$

Poisson-toy wording for 2025-style questions:

> Under $H_0$, set $\lambda_i=T$ or to the null-model prediction, simulate many fake Poisson datasets, compute $t$ for each, and use this distribution to choose $w$. Under $H_1$, simulate using the alternative rates and count how often $t$ falls in the same $w$ to estimate the power.

Decision wording when the null distribution is given:

> Under $H_0$, the statistic $t$ follows the distribution given in the question, e.g. $\chi^2$ with the stated degrees of freedom. Choose a size $\alpha$, find the critical value $t_\alpha$ such that $P(t>t_\alpha\mid H_0)=\alpha$, compute $t_{\mathrm{obs}}$ from the real data, and reject $H_0$ if $t_{\mathrm{obs}}>t_\alpha$. Otherwise fail to reject $H_0$.

Decision wording when the null distribution is not given:

> Generate the distribution of $t$ under $H_0$ using pseudo-experiments/toys. For each toy dataset, compute the same test statistic. Choose a critical region $w$ with $P(t\in w\mid H_0)=\alpha$. Compute $t_{\mathrm{obs}}$ from the real data and reject $H_0$ if $t_{\mathrm{obs}}\in w$. For a usual likelihood-ratio goodness-of-fit statistic, $w$ is the large-$t$ tail.

## Bayesian Basics

Bayes theorem for parameters:

$$
p(\theta\mid d)=\frac{p(d\mid\theta)\pi(\theta)}{p(d)}.
$$

Terms:

- likelihood: $p(d\mid\theta)$, viewed as a function of $\theta$ with data fixed;
- prior: $\pi(\theta)$;
- posterior: $p(\theta\mid d)$;
- evidence: $p(d)=\int p(d\mid\theta)\pi(\theta)\,d\theta$.

Likelihood vs sampling distribution:

Same mathematical expression $p(d\mid\theta)$, different viewpoint.

- Sampling distribution: function of possible data $d$, with $\theta$ fixed.
- Likelihood: function of parameter $\theta$, with observed data $d$ fixed.

Jeffreys/log-uniform prior:

For a positive scale/rate parameter, a common non-informative choice is

$$
\pi(\theta)\propto \frac{1}{\theta}.
$$

For location parameters, use a uniform prior if no location is preferred.

For probability parameters $q\in[0,1]$, use uniform/Beta$(1,1)$ if no prior preference is given.

## Posterior Summaries

MAP:

Maximise the posterior:

$$
\frac{d}{d\theta}\log p(\theta\mid d)=0.
$$

Posterior mean:

If the posterior is normalised,

$$
E[\theta\mid d]=\int \theta p(\theta\mid d)\,d\theta.
$$

If $p(\theta\mid d)\propto h(\theta)$,

$$
E[\theta\mid d]=\frac{\int \theta h(\theta)\,d\theta}{\int h(\theta)\,d\theta}.
$$

Posterior variance:

$$
\mathrm{Var}(\theta\mid d)=E[\theta^2\mid d]-E[\theta\mid d]^2.
$$

Curvature approximation:

$$
\sigma_\theta^{-2}\simeq
-\left.\frac{d^2}{d\theta^2}\log p(\theta\mid d)\right|_{\theta=\theta_{\mathrm{MAP}}}.
$$

## Conjugate Priors

Definition:

> A conjugate prior is a prior that gives a posterior in the same functional family after multiplying by the likelihood.

Binomial likelihood:

$$
p(n\mid N,q)\propto q^n(1-q)^{N-n}.
$$

Beta prior:

$$
\pi(q)\propto q^{\alpha-1}(1-q)^{\beta-1}.
$$

Posterior:

$$
p(q\mid n,N)\propto q^{n+\alpha-1}(1-q)^{N-n+\beta-1}.
$$

Alternative convention used in some papers:

If

$$
\pi(q)\propto q^\alpha(1-q)^\beta,
$$

then posterior exponents are

$$
\alpha\to\alpha+n,\qquad \beta\to\beta+N-n.
$$

Beta prior shapes:

- $(1,1)$ in the $\alpha-1,\beta-1$ convention: uniform.
- Both parameters greater than 1: peaked inside.
- A small exponent on $(1-q)$ can put high weight near $q=1$.
- Symmetric parameters give a symmetric distribution around $q=1/2$.

## Sequential Updating

First update:

$$
p(\theta\mid d_1)=\frac{p(d_1\mid\theta)\pi(\theta)}{p(d_1)}.
$$

Second update uses the old posterior as the new prior:

$$
p(\theta\mid d_2,d_1)
=
\frac{p(d_2\mid\theta,d_1)p(\theta\mid d_1)}
{p(d_2\mid d_1)}.
$$

Product rule:

$$
p(d_1,d_2\mid\theta)=p(d_2\mid d_1,\theta)p(d_1\mid\theta).
$$

Therefore:

$$
p(\theta\mid d_1,d_2)
=
\frac{p(d_1,d_2\mid\theta)\pi(\theta)}
{p(d_1,d_2)}.
$$

Meaning: sequential updating and combined-data updating give the same result.

## Evidence and Bayes Factors

Evidence for model $M$:

$$
Z_M=p(d\mid M)=\int p(d\mid\theta,M)\pi(\theta\mid M)\,d\theta.
$$

If $M$ has no free parameters, there is no integral and the evidence is just the likelihood under that model.

Bayes factor:

$$
B_{01}=\frac{Z_0}{Z_1}=\frac{p(d\mid M_0)}{p(d\mid M_1)}.
$$

Posterior odds:

$$
\frac{p(M_0\mid d)}{p(M_1\mid d)}
=
B_{01}\frac{p(M_0)}{p(M_1)}.
$$

Condition for posterior odds to equal Bayes factor:

$$
p(M_0)=p(M_1).
$$

Prior requirement for evidence:

The parameter prior must be proper/normalised:

$$
\int \pi(\theta\mid M)\,d\theta=1.
$$

Improper priors such as a flat prior over an infinite range cannot be used directly for evidence/model comparison.

Occam penalty:

Evidence averages likelihood over prior volume. A flexible model is penalised if only a small part of its prior space fits well.

## Nested Models

Nested models:

> One model is a special case of another, obtained by fixing one or more parameters.

Example: a linear model is nested inside a quadratic model by setting $a_2=0$.

Example: a steady-state model $v=0$ is nested inside $v=Hr$ by setting $H=0$.

## Hierarchical Models and DAGs

Latent variable:

> A variable in the data-generating model that is not directly observed.

Example: true decay times $t_i$ are latent if measured times $\hat{t}_i$ have noise.

DAG symbols:

- open circle: unknown random variable/parameter;
- shaded circle: observed data;
- dot: known fixed quantity;
- diamond: deterministic quantity;
- plate: repeated structure.

Hierarchical posterior recipe:

1. Identify observed data, parameters, known constants, and latent variables.
2. Write conditional factors from the DAG.
3. Condition on observed data.
4. Integrate over latent variables:
   $$
   p(\theta\mid \hat{t})\propto
   \prod_i\int p(\hat{t}_i\mid t_i)p(t_i\mid\theta)\,dt_i\,\pi(\theta).
   $$

Conditional independence:

If $\mu\to t_i\to\hat{t}_i$, then

$$
p(\hat{t}_i\mid t_i,\mu)=p(\hat{t}_i\mid t_i).
$$

Once the true time is known, $\mu$ gives no extra information about the noisy measurement.

## SBI / ABC / Compression

SBI:

> Simulation-based inference estimates posteriors using simulations when the likelihood is unavailable or expensive.

ABC:

1. Draw $\theta_j\sim\pi(\theta)$.
2. Simulate $d_j\sim p(d\mid\theta_j)$.
3. Keep/weight simulations where simulated data match observed data:
   $$
   \rho(s(d_j),s(d_{\mathrm{obs}}))<\epsilon.
   $$
4. The retained $\theta_j$ values approximate $p(\theta\mid d_{\mathrm{obs}})$.

Sketch wording:

> In a scatter of simulated $(\theta,d)$ pairs, a vertical slice at fixed $\theta$ shows a sampling distribution; a horizontal slice near $d_{\mathrm{obs}}$ gives the posterior over $\theta$.

Challenges:

High-dimensional data, expensive simulations, tolerance choice, compression/summary-statistic information loss, validation/calibration.

Modern SBI alternatives:

Neural posterior estimation, neural likelihood estimation, likelihood-ratio estimation, normalising flows.

Compression:

If the posterior depends on data only through one combination, that combination is a sufficient statistic for the parameter.

For Gaussian mean with known errors:

$$
L(\mu)\propto
\exp\left[
-\sum_i\frac{x_i^2}{2\sigma_i^2}
+\mu\sum_i\frac{x_i}{\sigma_i^2}
-\frac{\mu^2}{2}\sum_i\frac{1}{\sigma_i^2}
\right].
$$

The data-only term cancels into the evidence. The data enter the posterior through

$$
X=\sum_i\frac{x_i}{\sigma_i^2}.
$$

## Taxi / German-Tank Style Problem

If one observed licence number is $n$ and total taxis are $N$:

$$
p(n\mid N)=\frac{1}{N},\qquad N\ge n,
$$

and zero otherwise.

With a uniform truncated prior:

$$
p(N\mid n)\propto \frac{1}{N},\qquad N\ge n.
$$

MLE:

$$
\hat{N}_{\mathrm{MLE}}=n
$$

because $1/N$ is largest for the smallest possible $N$.

Bayesian merit:

MLE gives one boundary estimate and tends to underestimate; the Bayesian posterior shows the long upper tail and uncertainty, and can include prior information.
