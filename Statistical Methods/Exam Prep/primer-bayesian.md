# Bayesian Primer Notes

These are bridge notes for the first rebuild. Use them with worked examples.

## Big Picture

Bayesian questions usually ask you to write a posterior, summarise it, compare models, or describe a hierarchical/simulation-based setup.

The core move is always:

$$
\text{posterior}\propto \text{likelihood}\times\text{prior}
$$

Normalisation matters when calculating posterior means, probabilities, or evidence. It often does not matter for MAP estimates.

## Bayes Theorem

For parameters $\theta$ and data $d$:

$$
p(\theta \mid d)=\frac{p(d \mid \theta)\pi(\theta)}{p(d)}
$$

Names:

- $p(d \mid \theta)$: likelihood.
- $\pi(\theta)$: prior.
- $p(\theta \mid d)$: posterior.
- $p(d)$: evidence.

Likelihood vs sampling distribution is a viewpoint distinction: same expression, but sampling distribution varies the data with parameter fixed, while likelihood varies the parameter with observed data fixed.

## Priors

Use the prior specified by the paper. If asked to justify:

- Uniform prior: simple bounded ignorance for a location/probability parameter.
- $1/\sigma$ or $1/\lambda$ style prior: scale ignorance/log-uniform reasoning.
- Proper prior: needed for evidence, because evidence integrates likelihood times prior.

## Conjugate Priors

A conjugate prior gives a posterior in the same family as the prior.

For binomial data:

$$
L(q)\propto q^n(1-q)^{N-n}
$$

If prior is $q^{a-1}(1-q)^{b-1}$, posterior is:

$$
q^{a+n-1}(1-q)^{b+N-n-1}
$$

If prior is written as $q^x(1-q)^y$, posterior exponents are:

$$
x\to x+n,\qquad y\to y+N-n
$$

Check the convention in the question before quoting MAP formulas.

## Posterior Summaries

MAP:

1. Write posterior kernel.
2. Take log.
3. Differentiate.
4. Set to zero.
5. Check parameter range.

Posterior mean:

$$
\int \theta\,p(\theta \mid d)\,d\theta
$$

Curvature variance:

Approximate the posterior near the MAP as Gaussian. Then:

$$
\sigma^{-2}=-\left.\frac{d^2}{d\theta^2}\log p(\theta \mid d)\right|_{\theta=\hat{\theta}_{\mathrm{MAP}}}
$$

## Evidence and Model Comparison

Evidence is:

$$
Z=p(d \mid M)=\int p(d \mid \theta,M)\pi(\theta \mid M)\,d\theta
$$

For a model with no free parameter, the evidence is just the likelihood under that model.

Posterior odds:

$$
\frac{p(M_0 \mid d)}{p(M_1 \mid d)}
=
\frac{Z_0}{Z_1}\frac{p(M_0)}{p(M_1)}
$$

If model priors are equal, posterior odds equal the Bayes factor.

Evidence includes an Occam penalty because it averages likelihood over the whole prior space.

## Hierarchical Models

Hierarchical questions are about the generative process.

Recipe:

1. Identify unknown global parameter.
2. Identify latent variables.
3. Identify observed noisy measurements.
4. Write conditional factors.
5. Multiply into a joint probability.
6. Integrate over latent variables.

Do not panic about the DAG. The marks usually reward correctly identifying plates, observed variables, latent variables, known constants, and arrows.

## SBI and ABC

Simulation-based inference is used when the likelihood is hard but simulation is possible.

ABC algorithm:

1. Draw parameter from prior.
2. Simulate data.
3. Compare simulated data to observed data with a distance or summary statistic.
4. Accept or weight simulations close enough to the observation.
5. Use accepted parameters as an approximate posterior.

Challenges:

- Too much data makes matching hard.
- Tolerance choice changes the approximation.
- Bad summary statistics lose information.
- Simulations can be expensive.
