# Quant Interview Statistics Cheat Sheet

This is the joint frequentist + Bayesian sheet. Use it like an answer bank: define terms clearly, write the general formula, then adapt to the question.

## Reading Probability Notation

For posterior questions:

$$
p(\theta\mid d)
$$

means probability/belief about parameter or model $\theta$ after seeing data $d$.

Bayes theorem:

$$
p(\theta\mid d)
=
\frac{p(d\mid\theta)p(\theta)}{p(d)}.
$$

Read it as:

- left side: what we want to infer;
- $p(d\mid\theta)$: likelihood, how probable the data are if $\theta$ were true;
- $p(\theta)$: prior, what we believed before the data;
- $p(d)$: evidence, normalising constant and model comparison score.

For model comparison:

$$
Z_M=p(d\mid M)=\int p(d\mid\theta,M)\pi(\theta\mid M)\,d\theta.
$$

If model $M$ has no free parameter, there is no integral and the evidence is just the likelihood under that model.

## Likelihood Setup

Likelihood is the probability model for the observed data, viewed as a function of unknown parameters.

Single observed vector:

$$
L(\theta)=p(x\mid\theta).
$$

Independent observations:

$$
L(\theta)=p(x_1,\ldots,x_n\mid\theta)=\prod_{i=1}^n p(x_i\mid\theta).
$$

Use the product when the question gives repeated independent observations. Do not add a product if the question already gives the joint density of the whole observed vector.

Log rules:

$$
\log\prod_i a_i=\sum_i\log a_i,\qquad
\log(a^b)=b\log a.
$$

Constants that do not depend on the parameter can be dropped for MLE/MAP, but not if you are asked for a normalised density or evidence.

## MLE

MLE finds the parameter value that makes the observed data most likely:

$$
\hat{\theta}_{\mathrm{MLE}}=\arg\max_\theta L(\theta).
$$

Workflow:

1. Write $L(\theta)$.
2. Take $\ell(\theta)=\log L(\theta)$ or $q(\theta)=-\log L(\theta)$.
3. Differentiate with respect to the unknown parameter(s), not the observed data.
4. Set derivative to zero.
5. Check constraints and state the estimate.

Differentiate with respect to the symbols you are trying to estimate. If data are written as $x_i,k_i,t_i$, those are fixed observations.

Common MLEs:

| Model | MLE |
|---|---|
| Bernoulli/binomial probability | $\hat{p}=k/n$ |
| Poisson rate with repeated counts | $\hat{\lambda}=\bar{k}$ |
| Exponential lifetime | $\hat{\tau}=\bar{t}$ |
| Exponential rate | $\hat{\lambda}=n/\sum_i t_i$ |
| Gaussian mean | $\hat{\mu}=\bar{x}$ |
| Gaussian variance MLE | $\hat{\sigma}^2=(1/n)\sum_i(x_i-\bar{x})^2$ |

## Method Of Moments

Method of moments equates:

$$
\text{sample moment from data}
=
\text{theoretical moment from model}.
$$

First moment:

$$
\bar{x}=\frac{1}{n}\sum_i x_i
\qquad\text{and}\qquad
E_\theta[X]=g(\theta).
$$

Set

$$
g(\hat{\theta})=\bar{x}
$$

and solve for $\hat{\theta}$.

Second raw moment:

$$
\frac{1}{n}\sum_i x_i^2=E_\theta[X^2].
$$

Use as many moments as there are unknown parameters.

## Bias, Variance, Consistency

Bias:

$$
\mathrm{bias}(\hat{\theta})=E[\hat{\theta}]-\theta.
$$

Unbiased:

$$
E[\hat{\theta}]=\theta.
$$

Variance:

$$
\mathrm{Var}(X)=E[X^2]-E[X]^2.
$$

For independent variables:

$$
\mathrm{Var}\left(\sum_i a_iX_i\right)=\sum_i a_i^2\mathrm{Var}(X_i).
$$

Consistency:

$$
\hat{\theta}_n\xrightarrow{p}\theta.
$$

Intuition: as sample size grows, the estimator concentrates on the true value.

## Hypothesis Testing

Basic objects:

$$
H_0=\text{null model},\qquad H_1=\text{alternative model}.
$$

Type I error:

$$
\alpha=P(\text{reject }H_0\mid H_0).
$$

Type II error:

$$
\beta=P(\text{fail to reject }H_0\mid H_1).
$$

Power:

$$
1-\beta=P(\text{reject }H_0\mid H_1).
$$

p-value:

$$
p=P(\text{test statistic at least as extreme as observed}\mid H_0).
$$

Likelihood-ratio statistic:

$$
t=-2\log\frac{L(H_0)}{L(H_1)}.
$$

For nested models, large $t$ usually means $H_0$ fits much worse than the more flexible model.

Stock answer:

> Choose a test statistic, choose significance $\alpha$, find or simulate the null distribution under $H_0$, define the critical region with probability $\alpha$ under $H_0$, compute $t_{\mathrm{obs}}$, and reject $H_0$ if $t_{\mathrm{obs}}$ lies in the critical region.

Use simulations/toys when the null distribution is not given or a standard approximation is not justified.

Use Wilks/chi-square when the question says so or regular large-sample conditions are plausible.

## Confidence Interval Vs Credible Interval

Frequentist confidence interval:

> Random procedure with long-run coverage. The parameter is fixed.

Correct phrase:

$$
P_\theta(\theta\in C(X))=1-\alpha.
$$

Bayesian credible interval:

> Posterior probability statement after seeing the data. The parameter is treated as uncertain.

Correct phrase:

$$
\int_C p(\theta\mid d)\,d\theta=1-\alpha.
$$

Do not say a frequentist 95 percent CI means a 95 percent probability the fixed parameter is inside this realised interval.

## Bayesian Posterior

Posterior:

$$
p(\theta\mid d)\propto p(d\mid\theta)\pi(\theta).
$$

MAP:

$$
\hat{\theta}_{\mathrm{MAP}}=\arg\max_\theta p(\theta\mid d).
$$

Usually:

$$
\frac{d}{d\theta}\log p(\theta\mid d)=0.
$$

MLE maximises likelihood. MAP maximises posterior, so it includes the prior.

Posterior mean:

If $p(\theta\mid d)$ is normalised,

$$
E[\theta\mid d]=\int \theta p(\theta\mid d)\,d\theta.
$$

If only a kernel $h(\theta)\propto p(\theta\mid d)$ is known,

$$
E[\theta\mid d]=
\frac{\int \theta h(\theta)\,d\theta}
{\int h(\theta)\,d\theta}.
$$

Posterior variance:

$$
\mathrm{Var}(\theta\mid d)
=E[\theta^2\mid d]-E[\theta\mid d]^2.
$$

Local curvature approximation:

$$
\mathrm{Var}(\theta\mid d)\approx
\left[
-\left.\frac{d^2}{d\theta^2}\log p(\theta\mid d)\right|_{\theta=\hat{\theta}_{\mathrm{MAP}}}
\right]^{-1}.
$$

## Priors

Uniform prior:

- Usually used for a location parameter or bounded probability when no value is preferred.

Jeffreys/log-uniform prior:

$$
\pi(\theta)\propto \frac{1}{\theta}
$$

- Often used for positive scale/rate parameters.
- Use only if it makes sense and the posterior normalises.

Evidence/model comparison requires proper priors:

$$
\int \pi(\theta)\,d\theta=1.
$$

Improper priors can be okay for parameter estimation but are not okay for Bayes factors unless handled very carefully.

## Conjugacy

A conjugate prior gives a posterior in the same family after multiplying by the likelihood.

Beta-binomial:

$$
p(k\mid n,q)\propto q^k(1-q)^{n-k}
$$

and

$$
\pi(q)\propto q^{\alpha-1}(1-q)^{\beta-1}
$$

give

$$
p(q\mid k,n)\propto q^{k+\alpha-1}(1-q)^{n-k+\beta-1}.
$$

So the posterior is

$$
q\mid k,n\sim \mathrm{Beta}(\alpha+k,\beta+n-k).
$$

Normal likelihood plus normal prior gives normal posterior.

Poisson likelihood plus gamma prior gives gamma posterior.

## Evidence And Bayes Factors

Evidence:

$$
Z_M=p(d\mid M)=\int p(d\mid\theta,M)\pi(\theta\mid M)\,d\theta.
$$

Bayes factor:

$$
B_{01}=\frac{Z_0}{Z_1}.
$$

Posterior odds:

$$
\frac{p(M_0\mid d)}{p(M_1\mid d)}
=
B_{01}\frac{p(M_0)}{p(M_1)}.
$$

If model priors are equal, posterior odds equal the Bayes factor.

Occam penalty:

> Evidence averages likelihood over the prior. A flexible model is penalised if only a small part of its prior range fits the data well.

## Regression

Linear regression model:

$$
Y=X\beta+\epsilon,\qquad \epsilon\sim N(0,\sigma^2I).
$$

OLS:

$$
\hat{\beta}=\arg\min_\beta \|Y-X\beta\|_2^2.
$$

Solution if $X^TX$ is invertible:

$$
\hat{\beta}=(X^TX)^{-1}X^TY.
$$

Gaussian noise link:

> Maximising the Gaussian likelihood is equivalent to minimising sum of squared residuals.

Assumptions to mention:

- independent observations;
- linear conditional mean or useful linear approximation;
- zero-mean errors;
- constant variance if using standard OLS inference;
- no severe multicollinearity for stable coefficients;
- train/test split for prediction claims.

Ridge:

$$
\min_\beta \|Y-X\beta\|_2^2+\lambda\|\beta\|_2^2.
$$

Shrinks coefficients, helps multicollinearity, usually keeps all features.

Lasso:

$$
\min_\beta \|Y-X\beta\|_2^2+\lambda\|\beta\|_1.
$$

Shrinks and can set coefficients to zero, useful for feature selection.

## ML/Data Reasoning

Overfitting:

> Model captures noise/idiosyncrasies of training data, so training error is low but test error is worse.

Avoid using:

- train/test split;
- cross-validation;
- regularisation;
- simpler model;
- more data;
- early stopping;
- leakage checks.

Data leakage:

> Information unavailable at prediction time leaks into training features or validation.

Classification metrics:

- Accuracy: good only if classes are balanced and costs are similar.
- Precision: of predicted positives, how many are true positives.
- Recall: of actual positives, how many are found.
- ROC/AUC: ranking quality over thresholds.
- Log loss: rewards calibrated probabilities.

Cross-validation:

> Estimate out-of-sample performance by repeatedly training on one part of the data and validating on held-out data.

Use time-aware splits for time series.

## Probability Essentials

Bayes:

$$
P(A\mid B)=\frac{P(B\mid A)P(A)}{P(B)}.
$$

Total probability:

$$
P(B)=P(B\mid A)P(A)+P(B\mid A^c)P(A^c).
$$

Expectation:

$$
E[g(X)]=\sum_x g(x)P(X=x)
$$

or

$$
E[g(X)]=\int g(x)f(x)\,dx.
$$

Linearity:

$$
E[aX+bY]=aE[X]+bE[Y].
$$

No independence needed for linearity.

Covariance:

$$
\mathrm{Cov}(X,Y)=E[XY]-E[X]E[Y].
$$

Independence implies zero covariance, but zero covariance does not always imply independence.

CLT:

For iid variables with mean $\mu$ and variance $\sigma^2$,

$$
\bar{X}\approx N\left(\mu,\frac{\sigma^2}{n}\right)
$$

for large $n$.

Common distributions:

| Distribution | Mean | Variance | Watch for |
|---|---:|---:|---|
| Bernoulli$(p)$ | $p$ | $p(1-p)$ | indicator variables |
| Binomial$(n,p)$ | $np$ | $np(1-p)$ | number of successes |
| Poisson$(\lambda)$ | $\lambda$ | $\lambda$ | counts/rates |
| Exponential rate $\lambda$ | $1/\lambda$ | $1/\lambda^2$ | waiting times |
| Normal$(\mu,\sigma^2)$ | $\mu$ | $\sigma^2$ | sums, errors, CLT |

## Interview Habits

When stuck:

1. Name the random variables.
2. State what is observed and what is unknown.
3. Write the simplest formula.
4. Check independence before multiplying probabilities.
5. Say what is fixed and what is variable.
6. Solve a smaller case.
7. Explain assumptions out loud.

Good phrase:

> I will treat the observed data as fixed and write the likelihood as a function of the unknown parameter.

Good phrase:

> If the observations are independent, the joint likelihood is the product of the individual densities.

Good phrase:

> For MAP I maximise the posterior, so the prior contributes an extra term compared with MLE.

