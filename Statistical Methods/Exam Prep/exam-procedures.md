# Exam Procedure Templates

These are answer skeletons to memorise. Adapt notation to the question.

## Full Paper Pacing

For a 2 hour, 4 question paper:

1. Spend 3 minutes scanning all questions and noting the obvious route for each.
2. Give each question about 27 minutes.
3. Leave 9 minutes for unfinished definitions, missing units, and checking signs/logs.
4. If stuck for more than 3 minutes, write the general formula/procedure and move on.
5. Never leave a procedural question blank: examiners often award marks for clear steps even without final algebra.

## Moment or Distribution Derivation

1. State support and PDF/PMF.
2. Write the expectation/moment integral or sum.
3. Substitute any given identity.
4. Simplify to the requested result.
5. If estimating, equate model moment to sample moment and solve.

## MLE Derivation

1. For independent data, write $L(\theta)=\prod_i p(x_i \mid \theta)$.
2. Write $q(\theta)=-\ln L(\theta)$.
3. Drop constants only after saying they do not depend on the parameter.
4. Differentiate, set derivative to zero, solve.
5. Check parameter constraints and state the final estimator.

## Bias Derivation

1. Start from $\mathrm{bias}(\hat{\theta})=E[\hat{\theta}]-\theta$.
2. Substitute the estimator.
3. Use linearity of expectation for sample means.
4. For nonlinear estimators, do not move expectation through the nonlinear function.
5. Use the provided inequality/Jensen hint if present.

## Gaussian Least Squares / Normal Equations

1. Write Gaussian likelihood for $y_i$ with known $x_i$ and known error.
2. Show $-\ln L$ is constant plus weighted sum of squared residuals.
3. Define design matrix $X$ with columns for basis functions.
4. State normal equations: $(X^T W X)\hat{a}=X^T W y$.
5. For known common $\delta$, $W=\delta^{-2}I$, so common factors cancel.

## Frequentist Hypothesis Test

1. Define $H_0$ and $H_1$.
2. Choose a test statistic that separates the hypotheses.
3. Define the critical region and size $\alpha$.
4. Generate or derive the test-statistic distribution under $H_0$.
5. Reject $H_0$ if $t_{\mathrm{obs}}$ falls in the critical region.
6. To calculate power, generate/derive the distribution under $H_1$ and compute probability of falling in the same critical region.

Nested likelihood-ratio test template:

Use this for questions asking whether a simpler fitted model should be rejected in favour of a more flexible fitted model, e.g. linear vs quadratic, constant rate vs time-varying rate.

1. State hypotheses:
   $$
   H_0=\text{simpler model},\qquad H_1=\text{more flexible model}.
   $$
   Example: $H_0$ is the best-fit linear model $y=b_0+b_1x$; $H_1$ is the best-fit quadratic model $y=a_0+a_1x+a_2x^2$.
2. Choose the likelihood-ratio statistic:
   $$
   t=-2\ln\left(\frac{L(\widehat{\theta}_0)}{L(\widehat{\theta}_1)}\right),
   $$
   where $\widehat{\theta}_0$ are the MLEs under $H_0$ and $\widehat{\theta}_1$ are the MLEs under $H_1$.
3. Explain direction of the test: for nested models, the flexible model can fit at least as well, so usually $L(\widehat{\theta}_1)\ge L(\widehat{\theta}_0)$. Large $t$ means the simple model fits much worse, so large $t$ is the critical region.
4. Choose the test size, for example $\alpha=0.05$.
5. Compute the observed statistic from the real data:
   $$
   t_{\mathrm{obs}}=-2\ln\left(\frac{L_{\mathrm{obs}}(\widehat{\theta}_0)}{L_{\mathrm{obs}}(\widehat{\theta}_1)}\right).
   $$
6. Get the distribution of $t$ under $H_0$, either from simulation/pseudo-experiments using the fitted null model, or from Wilks/chi-square if the conditions are valid.
7. Compute the tail probability under $H_0$:
   $$
   p=P(t\ge t_{\mathrm{obs}}\mid H_0).
   $$
8. Decision rule: if $p<\alpha$, reject $H_0$ in favour of $H_1$; otherwise fail to reject $H_0$.
9. For power, generate/derive the distribution of the same $t$ under $H_1$ and calculate the probability of landing in the same critical region:
   $$
   1-\beta=P(t\in w\mid H_1).
   $$

Poisson good-fit / rate-shape version:

Use this for questions like "test if $H_0$ is a good description of the data, based on a likelihood-ratio statistic" with Poisson counts.

1. State the hypotheses:
   $$
   H_0=\text{constant-rate/given-fit model},\qquad H_1=\text{alternative/time-varying/better-fit model}.
   $$
2. Choose the size/significance of the test, e.g.
   $$
   \alpha=0.05.
   $$
3. Use the given likelihood-ratio statistic, for example
   $$
   t=-2\ln\left(\frac{L(H_1)}{L(H_0)}\right)
   $$
   or the exact ordering stated in the question. Explain which direction is more extreme from the definition of $t$.
4. Generate the distribution of $t$ under $H_0$ using Poisson pseudo-experiments:
   - set the Poisson means to the $H_0$ values, e.g. $\lambda_i=T$ for every bin/measurement;
   - repeatedly simulate fake counts $k_i^{\mathrm{toy}}\sim\mathrm{Pois}(\lambda_i)$;
   - for each toy dataset, calculate the same test statistic $t$.
5. Determine the critical region $w$ from this $H_0$ distribution so that
   $$
   P(t\in w\mid H_0)=\alpha.
   $$
   For most goodness-of-fit likelihood-ratio tests this is the large-$t$ tail, but follow the sign/order of the statistic in the question.
6. Compute the observed statistic $t_{\mathrm{obs}}$ from the real data.
7. Decision rule:
   $$
   t_{\mathrm{obs}}\in w\quad\Rightarrow\quad \text{reject }H_0.
   $$
   If rejected, say the fit/model is not a good description of the data. If not in $w$, fail to reject $H_0$.
8. Power: generate the distribution of $t$ under $H_1$ using Poisson toys with the $H_1$ means, then calculate
   $$
   1-\beta=P(t\in w\mid H_1)
   =
   1-P(t\in W-w\mid H_1).
   $$

Critical marks to hit: say how to generate the toy distributions under both hypotheses, define the critical region using $\alpha$, calculate $t_{\mathrm{obs}}$, and apply the reject/fail-to-reject rule.

Mark-scoring words for 2024-style linear vs quadratic:

> Take $H_0$ to be the linear model and $H_1$ to be the second-order polynomial. Use $t=-2\ln[L(\hat b_0,\hat b_1)/L(\hat a_0,\hat a_1,\hat a_2)]$. Since the quadratic model contains the linear model as the special case $a_2=0$, large $t$ means the linear model is much worse. Choose a size such as $\alpha=0.05$, calculate $t_{\mathrm{obs}}$ from the data, and find $P(t>t_{\mathrm{obs}}\mid H_0)$ using simulations generated under the fitted linear model. Reject the linear model if this probability is below $\alpha$. To calculate power, repeat the simulation under the alternative model and find the probability of falling in the same rejection region.

## Neyman Construction

Core idea:

> Test every possible parameter value and keep the values that could reasonably have produced the observed data.

Equivalently, a Neyman confidence interval is the set of parameter values that the data do not reject at the chosen confidence level.

Let $\theta$ be the parameter or vector of parameters being constrained, e.g. $\theta=\tau$ or $\theta=(m,c)$.

1. Choose a test statistic, often
   $$
   t(\theta)=-2\ln\left[\frac{L(\theta)}{L(\hat{\theta})}\right].
   $$
2. Calculate the observed statistic $t_{\mathrm{obs}}(\theta)$ from the data. For a multi-parameter region, this is evaluated over a grid of $\theta$ values.
3. For each candidate parameter value $\theta$, obtain the distribution
   $$
   f(t;\theta)
   $$
   assuming that value is true, usually by simulation/pseudo-experiments or an analytic approximation.
4. Choose an ordering rule and define the accepted region in $t$ for each $\theta$. For a statistic such as $t=-2\ln[L(\theta)/L(\hat{\theta})]$, large values mean worse agreement, so the accepted region is usually the non-extreme/small-$t$ part of the distribution.
5. For each $\theta$, define the acceptance region in $t$. For a 68 percent construction this region has probability 0.68 under $f(t;\theta)$; for a 95 percent construction it has probability 0.95.
6. For each value of $\theta$, determine whether the observed value $t_{\mathrm{obs}}(\theta)$ lies inside that accepted region. Equivalently, for a large-$t$ tail statistic compute
   $$
   p(\theta)=\int_{t_{\mathrm{obs}}(\theta)}^\infty f(t;\theta)\,dt
   $$
   which is the probability, assuming $\theta$ is true, of getting a test statistic outside/more extreme than the observed one. Keep $\theta$ if $p(\theta)>1-\mathrm{CL}$, e.g. $p(\theta)>0.32$ for 68 percent or $p(\theta)>0.05$ for 95 percent.
7. The union of all kept parameter values is the confidence interval/region.

Memory hook:

> Propose, simulate, cut, compare, keep.

- Propose a parameter value $\theta$.
- Simulate or derive what the test statistic would look like if that $\theta$ were true.
- Cut out the most typical 68 percent or 95 percent of outcomes.
- Compare the observed data's statistic to that accepted region.
- Keep $\theta$ if the observed statistic is typical enough.

Exam wording:

> Choose a statistic such as $t(\theta)=-2\ln[L(\theta)/L(\hat{\theta})]$. Compute $t_{\mathrm{obs}}(\theta)$ from the real data. For each grid/trial value of $\theta$, generate $f(t;\theta)$ assuming $\theta$ is true. Define the accepted 68 percent or 95 percent region of that distribution. For each value of $\theta$, check whether $t_{\mathrm{obs}}(\theta)$ lies inside the accepted region; equivalently keep values with tail probability above $1-\mathrm{CL}$. The union of kept values is the confidence interval or confidence region.

Do not describe a confidence interval as "the probability the parameter is inside." In frequentist language, it is the set of parameter values that would not be rejected by this data under the chosen construction.

## Bayesian Posterior Setup

1. State the sampling distribution/likelihood.
2. State and justify the prior.
3. Multiply: $\text{posterior}\propto \text{likelihood}\times\text{prior}$.
4. Keep or ignore normalisation depending on what is asked.
5. For MAP, differentiate log posterior.
6. For mean/variance, write the normalised integral or use the provided integral identity.

Gaussian unknown-mean/unknown-sigma template:

If repeated independent measurements $x_i$ satisfy

$$
x_i\mid \mu,\sigma\sim \mathcal{N}(\mu,\sigma^2),
$$

then

$$
p(\mu,\sigma\mid\{x_i\})
\propto
\left[
\prod_{i=1}^n
\frac{1}{\sqrt{2\pi}\sigma}
\exp\left(-\frac{(x_i-\mu)^2}{2\sigma^2}\right)
\right]
\pi(\mu)\pi(\sigma).
$$

Use this whenever the question asks for the posterior of a true value and unknown measurement scatter from repeated Gaussian measurements.

## Prior Choice Template

- Location parameter such as a true length/mean $\mu$: use $\pi(\mu)\propto 1$ if no location is preferred.
- Scale parameter such as a standard deviation $\sigma$ or positive rate/lifetime parameter: use Jeffreys/log-uniform $\pi(\theta)\propto 1/\theta$ when no order of magnitude is preferred.
- Probability parameter $q\in[0,1]$: use uniform/Beta$(1,1)$ if no preference, or Beta$(\alpha,\beta)$ if prior pseudo-count information is given.
- Evidence/model comparison: make sure the prior is proper and normalised over a stated range.

## Bayesian Sequential Updating

Use this when the question gives datasets $d_1$ and $d_2$ and asks whether updating in stages matches analysing both together.

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

For this question, $d_1$ is old info once the first update has happened, and $d_2$ is the new data.

1. First update:
   $$
   p(\theta\mid d_1)=\frac{p(d_1\mid\theta)\pi(\theta)}{p(d_1)}.
   $$
2. Treat $p(\theta\mid d_1)$ as the prior for the second update:
   $$
   p(\theta\mid d_2,d_1)
   =
   \frac{p(d_2\mid\theta,d_1)p(\theta\mid d_1)}
   {p(d_2\mid d_1)}.
   $$
   This uses $p(d_2\mid\theta,d_1)$ because the second update asks how likely the new data $d_2$ are after $d_1$ is already known.
3. Use product rules:
   $$
   p(d_1,d_2\mid\theta)=p(d_2\mid d_1,\theta)p(d_1\mid\theta),
   $$
   $$
   p(d_1,d_2)=p(d_2\mid d_1)p(d_1).
   $$
4. Substitute and simplify:
   $$
   p(\theta\mid d_1,d_2)
   =
   \frac{p(d_1,d_2\mid\theta)\pi(\theta)}
   {p(d_1,d_2)}.
   $$

Meaning: updating with $d_1$ then $d_2$ gives the same posterior as analysing $(d_1,d_2)$ together.

## Conjugate Prior Answer

1. Define conjugacy: prior and posterior have same functional form after seeing data.
2. Write likelihood kernel in the parameter.
3. Write prior kernel.
4. Multiply kernels and collect exponents.
5. State updated hyperparameters and the convention used.

For binomial data with $M$ successes in $N$ trials:

$$
p(M\mid N,q)\propto q^M(1-q)^{N-M}.
$$

With beta prior

$$
\pi(q)\propto q^{\alpha-1}(1-q)^{\beta-1},
$$

the posterior is

$$
p(q\mid M,N)\propto q^{M+\alpha-1}(1-q)^{N-M+\beta-1}.
$$

For two independent batches, add successes and failures:

$$
M=M_1+M_2,\qquad N=N_1+N_2.
$$

Then the final posterior is

$$
p(q\mid M_1,M_2,N_1,N_2)
\propto
q^{M_1+M_2+\alpha-1}
(1-q)^{N_1+N_2-M_1-M_2+\beta-1}.
$$

## Evidence / Bayes Factor Answer

1. State $Z_M=p(d \mid M)=\int L(\theta)\pi(\theta)\,d\theta$.
2. Ensure the prior is normalised and proper.
3. If model has no free parameters, evidence is the likelihood under that model.
4. Compute Bayes factor $B_{01}=Z_0/Z_1$.
5. Posterior odds equal Bayes factor only if model prior probabilities are equal.
6. Mention Occam penalty if comparing simple and flexible models.

## Hierarchical Model Answer

1. Identify observed data, parameters, known constants, and latent variables.
2. State the generative model in conditional factors.
3. Draw or describe the DAG with plates for repeated observations.
4. Write the joint probability.
5. Condition on observed data.
6. Marginalise latent variables with integrals/products.

## ABC / SBI Answer

Use this for "write notes on SBI", "ABC", or "likelihood-free inference" questions.

Core idea:

> SBI estimates a posterior by simulating data from the model instead of writing down/evaluating an analytic likelihood.

Mark-scoring answer:

1. State the target posterior:
   $$
   p(\theta\mid d_{\mathrm{obs}}).
   $$
2. Explain when SBI is useful: the likelihood $p(d\mid\theta)$ is unavailable, intractable, or expensive, but we can simulate data from the model.
3. Draw parameter values from the prior:
   $$
   \theta_j\sim \pi(\theta).
   $$
4. For each draw, simulate fake data:
   $$
   d_j\sim p(d\mid \theta_j)
   $$
   using the simulator.
5. Compare simulated data to observed data, often after compression to summaries $s(d)$:
   $$
   \rho(s(d_j),s(d_{\mathrm{obs}}))<\epsilon.
   $$
6. In ABC, keep or weight simulations close to the observed data. The retained $\theta_j$ values approximate $p(\theta\mid d_{\mathrm{obs}})$.
7. Sketch description: show many simulated $(\theta,d)$ pairs. A vertical slice at fixed $\theta$ shows the sampling distribution $p(d\mid\theta)$; a horizontal slice near $d_{\mathrm{obs}}$ shows the posterior over $\theta$.
8. Mention challenges: high-dimensional data, need for compression/summary statistics, tolerance choice $\epsilon$, simulation cost, approximation error if summaries are not sufficient.
9. Mention modern alternatives/extensions if asked: neural density estimation, neural posterior estimation, neural likelihood estimation, likelihood-ratio estimation, normalising flows. These learn an approximate posterior/likelihood/ratio from simulations instead of simple accept/reject ABC.

One-paragraph version:

> Simulation-based inference is used when the likelihood is hard to evaluate but the experiment can be simulated. Draw $\theta$ from the prior, simulate data $d$ from the model, and compare the simulated data or compressed summaries to the observed data. In ABC, simulations close to the observed data are accepted or weighted, and the distribution of their $\theta$ values approximates the posterior. A sketch of simulated $(\theta,d)$ pairs can show vertical slices as sampling distributions and a horizontal slice near $d_{\mathrm{obs}}$ as the posterior. Main challenges are simulation cost, high-dimensional data, tolerance choice, and information loss from compression. Neural SBI methods can replace the accept/reject step by learning an approximate posterior, likelihood, or likelihood ratio.

## Bayesian Compression Answer

Use this when asked why data can be compressed or when a Gaussian likelihood is split into terms.

1. Write the likelihood and expand the exponent.
2. Separate terms into:
   - data-only terms;
   - parameter-only terms;
   - mixed data-parameter terms.
3. In the posterior, data-only multiplicative factors cancel against the evidence or become constants independent of the parameter.
4. Keep only the terms that affect the parameter dependence.
5. The data only need to be retained through the combinations that appear in the mixed terms. These are sufficient statistics for that model.

For Gaussian mean inference with known $\sigma_i$:

$$
p(\{x_i\}\mid \mu)
\propto
\exp\left[
-\frac{1}{2}\sum_i\frac{(x_i-\mu)^2}{\sigma_i^2}
\right].
$$

Expanding gives a mixed term

$$
\mu\sum_i\frac{x_i}{\sigma_i^2},
$$

so the data can be compressed into

$$
X=\sum_i\frac{x_i}{\sigma_i^2}
$$

for the posterior of $\mu$, along with known constants such as $\sum_i1/\sigma_i^2$.
