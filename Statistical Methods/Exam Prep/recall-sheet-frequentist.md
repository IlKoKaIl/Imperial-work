# Frequentist Recall Sheet

Keep this compact. Rebuild it from memory before reading it.

## Distributions and Moments

| Distribution | PDF/PMF Core | Mean | Variance / Useful Moment |
|---|---|---:|---:|
| Bernoulli $X \in \{0,1\}$ | $P(X=1)=p$ | $p$ | $p(1-p)$ |
| Binomial $k \sim \mathrm{Bin}(n,p)$ | $\binom{n}{k}p^k(1-p)^{n-k}$ | $np$ | $np(1-p)$ |
| Poisson $k \sim \mathrm{Pois}(\lambda)$ | $e^{-\lambda}\lambda^k/k!$ | $\lambda$ | $\lambda$ |
| Gaussian | normalisation times $\exp[-(x-\mu)^2/(2\sigma^2)]$ | $\mu$ | $\sigma^2$ |
| Exponential rate $\lambda$ | $\lambda e^{-\lambda t}$, $t \ge 0$ | $1/\lambda$ | $1/\lambda^2$ |
| Exponential lifetime $\tau$ | $(1/\tau)e^{-t/\tau}$ | $\tau$ | $\tau^2$ |
| Rayleigh | $(r/\sigma^2)\exp[-r^2/(2\sigma^2)]$ | not usually needed | $\mathrm{Var}(r)=((4-\pi)/2)\sigma^2$; use $E[r^2]=2\sigma^2$ |

If $T=t_1+t_2$ for two independent exponential rate-$\lambda$ variables, then $T \sim \mathrm{Gamma}(\text{shape}=2,\text{rate}=\lambda)$ with density $\lambda^2 T e^{-\lambda T}$.

For Maxwell-Boltzmann speed questions, the papers usually give the needed integral. Useful targets: $E[v]=2\sqrt{2kT/(m\pi)}$ and $E[v^2]=3kT/m$. For Poisson, the third central moment is $\lambda$.

## Estimators

- Method of moments: the model gives a theoretical moment as a formula involving the unknown parameter; the data give the matching sample moment as a number/expression from observations. Equate these two and solve for the unknown parameter.

  For the first moment:

  $$
  \text{model mean } E[X]=g(\theta)
  \qquad\text{and}\qquad
  \text{sample mean } \bar{x}=\frac{1}{N}\sum_i x_i.
  $$

  Then set

  $$
  g(\hat{\theta})=\bar{x}
  $$

  and rearrange to get $\hat{\theta}$. The hat appears because we are solving for the estimate of the parameter, not the true unknown value.

  Maxwell-Boltzmann example: part (i) gives the model first moment

  $$
  E[v]=\mu_1=2\sqrt{\frac{2kT}{m\pi}}.
  $$

  The data give

  $$
  \bar{v}=\frac{1}{n}\sum_i v_i.
  $$

  Method of moments sets

  $$
  2\sqrt{\frac{2k\hat{T}}{m\pi}}=\bar{v}
  $$

  and solves for the temperature estimate:

  $$
  \hat{T}=\frac{\pi m\bar{v}^2}{8k}.
  $$

  Leaving the answer in terms of $\bar{v}$ is expected because the actual observed speeds are not given.
Definition bank for good estimators:

| Property | Words | Formula/expression |
|---|---|---|
| Bias | Average offset of estimator from true parameter. | $\mathrm{bias}(\hat{\theta})=E[\hat{\theta}]-\theta$ |
| Unbiased | Estimator equals the true parameter on average. | $E[\hat{\theta}]=\theta$ or $\mathrm{bias}(\hat{\theta})=0$ |
| Consistent | Estimator converges to the true value as sample size grows. | $\hat{\theta}_N \xrightarrow[N\to\infty]{p} \theta$, or $P(|\hat{\theta}_N-\theta|>\epsilon)\to0$ for any $\epsilon>0$ |
| Efficient / minimum variance | Has the smallest variance among valid/unbiased estimators, often reaches the Cramer-Rao bound. | $\mathrm{Var}(\hat{\theta})\ge 1/I(\theta)$ and efficient if equality holds |
| Mean squared error | Average squared distance from true parameter. | $\mathrm{MSE}(\hat{\theta})=E[(\hat{\theta}-\theta)^2]=\mathrm{Var}(\hat{\theta})+\mathrm{bias}(\hat{\theta})^2$ |

Common estimators:

- Bernoulli/binomial: $\hat{p}=k/n$.
- Poisson repeated counts: $\hat{\lambda}=\bar{k}=(1/N)\sum_i k_i$.
- Exponential rate: $\hat{\lambda}=N/\sum_i t_i$.
- Exponential lifetime: $\hat{\tau}=\bar{t}$.
- Gaussian: $\hat{\mu}=\bar{x}$, $\hat{\sigma}^2_{\mathrm{MLE}}=(1/N)\sum_i (x_i-\bar{x})^2$.
- Rayleigh: $\hat{\sigma}=\sqrt{\sum_i r_i^2/(2N)}$; $\hat{\sigma}^2=\sum_i r_i^2/(2N)$.
- Linear/Gaussian least squares: minimise $\sum_i (y_i-\mathrm{model}_i)^2/\sigma_i^2$.

Bias warning: if $\hat{X}$ is unbiased for $X$, $g(\hat{X})$ is not necessarily unbiased for $g(X)$. Use Jensen when the question hints with square roots or reciprocals.

## Likelihood Pattern

1. Write product over independent observations.
2. Take $q=-\ln L$, dropping constants only if they do not affect the estimator.
3. Differentiate with respect to parameters.
4. Set derivatives to zero and solve.
5. State estimator and whether it is biased/consistent if asked.

## Hypothesis Tests and Intervals

Definition bank for tests:

| Quantity | Words | Formula/expression |
|---|---|---|
| Critical region $w$ | Set of test-statistic/data values where $H_0$ is rejected. | Reject $H_0$ if $T\in w$ |
| Size/significance $\alpha$ | Probability of rejecting $H_0$ when $H_0$ is true. | $\alpha=P(T\in w\mid H_0)=\int_w f(T\mid H_0)\,dT$ |
| Type I error | Reject $H_0$ when $H_0$ is true. | $\alpha=P(T\in w\mid H_0)$ |
| Type II error | Fail to reject $H_0$ when $H_1$ is true. | $\beta=P(T\notin w\mid H_1)=\int_{W-w} f(T\mid H_1)\,dT$ |
| Power | Probability of rejecting $H_0$ when $H_1$ is true. | $1-\beta=P(T\in w\mid H_1)=\int_w f(T\mid H_1)\,dT$ |
| p-value | Probability under $H_0$ of a result at least as extreme as observed. | For large-$T$ tests: $p=P(T\ge T_{\mathrm{obs}}\mid H_0)=\int_{T_{\mathrm{obs}}}^{\infty}f(T\mid H_0)\,dT$ |

- Likelihood-ratio statistic: commonly $t=-2\ln[L(\mathrm{null})/L(\mathrm{best})]$ or profile form $t(\theta)=-2\ln[L(\theta)/L(\hat{\theta})]$.
- Wilks: under regularity, profile likelihood-ratio statistic is asymptotically chi-square with degrees of freedom equal to constrained parameter count.
- Neyman construction memory hook: propose, simulate, cut, compare, keep. See `exam-procedures.md` for the full answer template.
