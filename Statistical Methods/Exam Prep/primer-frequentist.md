# Frequentist Primer Notes

These are bridge notes for the first rebuild. They are not a replacement for attempts.

## Big Picture

Frequentist questions in these papers usually ask you to move from a sampling model to an estimator, uncertainty interval, or hypothesis test.

The common flow is:

1. Identify the distribution of the data.
2. Write a likelihood or moment.
3. Derive an estimator.
4. Comment on estimator quality or build a test/interval.

## Distributions

Bernoulli is one binary trial. Binomial is the number of successes in $N$ independent Bernoulli trials. Poisson is the count model for events in a fixed interval. Gaussian is the standard measurement-error model. Exponential is the waiting-time/decay-time model.

Memorise the mean and variance table in `recall-sheet-frequentist.md`; that table is more exam-useful than rereading the whole probability chapter.

## Method of Moments

Method of moments is usually the fastest estimator route.

Example pattern:

- Model says $E[X]=g(\theta)$.
- Data give sample mean $\bar{x}=(1/N)\sum_i x_i$.
- Set $\bar{x}=g(\hat{\theta})$.
- Solve for $\hat{\theta}$.

For binomial with $k$ successes out of $n$, $E[k]=np$, so $\hat{p}=k/n$.

## Maximum Likelihood

MLE means choose the parameter that makes the observed data most likely.

Generic route:

1. $L(\theta)=\prod_i p(x_i \mid \theta)$.
2. $q(\theta)=-\log L(\theta)$.
3. Drop constants independent of $\theta$.
4. Differentiate.
5. Set equal to zero.
6. Solve.

Key examples:

- Poisson repeated counts: $\hat{\lambda}=\bar{k}$.
- Exponential rate: $\hat{\lambda}=N/\sum_i t_i$.
- Exponential lifetime: $\hat{\tau}=\bar{t}$.
- Gaussian mean: $\hat{\mu}=\bar{x}$.
- Gaussian variance MLE: use $1/N$, not $1/(N-1)$.

## Bias

Bias asks whether the estimator is correct on average:

$$
\mathrm{bias}(\hat{\theta})=E[\hat{\theta}]-\theta
$$

Linear estimators based on sample means are often easier. Nonlinear estimators need care: $E[g(X)]$ is usually not $g(E[X])$.

When the question gives an inequality like $E[1/X]\ge 1/E[X]$ or hints about square roots, it is warning you that a nonlinear MLE is biased.

## Gaussian Fitting

If $y_i$ are independent Gaussian measurements with known errors, the likelihood becomes least squares.

For a model $y=Xa$, the normal equations are:

$$
(X^T W X)\hat{a}=X^T W y
$$

For equal known error, $W$ is proportional to the identity, so the common error factor cancels in the estimator.

## Hypothesis Tests

State:

- $H_0$: null hypothesis.
- $H_1$: alternative hypothesis.
- Type I error: reject $H_0$ when $H_0$ is true.
- Type II error: fail to reject $H_0$ when $H_1$ is true.
- Power: probability of rejecting $H_0$ when $H_1$ is true.

For procedural questions, marks come from clear steps even if there is little algebra.

## Neyman Construction

Neyman intervals are repeated-experiment confidence statements.

Recipe:

1. Pick statistic, often a likelihood-ratio statistic.
2. For each candidate parameter value, simulate or derive the statistic distribution assuming that value is true.
3. Choose the acceptance region containing the required confidence level.
4. Calculate the observed statistic for each candidate parameter value.
5. Keep parameter values whose observed statistic lies in the acceptance region.

That retained set is the confidence interval or confidence region.
