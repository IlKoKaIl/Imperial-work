# Repeated Problems Map

Scope: compared the Part 1 problem sheet against the frequentist half of the mock, 2022, 2023, 2024, and 2025 papers. For past papers this means Q1-Q2 only; Q3-Q4 are mostly Bayesian and were not used as the main comparison set.

## Strong Repeats

| Part 1 problem | Past-paper repeat | Match strength | What repeated |
|---|---|---:|---|
| 1.3 Poisson third central moment | 2022 Q1(ii)(c) | Exact/core repeat | Third central moment of Poisson; use expectation sum and provided series identities. |
| 1.8 Maxwell-Boltzmann distribution | 2023 Q1(i)-(ii)(a) | Near exact repeat | First algebraic moment $E[v]$ and proof that $\bar v$ is unbiased for $\mu_1$. |
| 1.10 Exponential lifetime MLE | Mock Q2(ii)-(iii), 2023 Q2(ii)-(iii) | Strong structural repeat | Normalise exponential lifetime pdf, write likelihood for decay times, derive $\hat{\tau}=\bar t$. |

## Topic Repeats Without Exact Wording

| Part 1 problem/topic | Related past-paper questions | What to learn |
|---|---|---|
| Poisson distribution, 1.3 | 2022 Q1(ii), 2025 Q2(i)-(ii) | Poisson MLE, repeated Poisson likelihood, constant-rate estimator, central moment tricks. |
| Exponential decay, 1.10 | Mock Q2, 2023 Q2, 2025 Q1 | Exponential normalisation, MLE/MoM for rate/lifetime, sums of exponential variables, bias of reciprocal estimators. |
| Hypothesis testing / p-values, 1.9 | Mock Q2(i)-(ii)(d), 2023 Q2(i)-(ii)(d), 2025 Q2(iii) | Type I/II errors, p-values, critical regions, power, KS-style and likelihood-ratio test descriptions. |
| Method of moments and bias | 2023 Q1, 2024 Q2, 2025 Q1 | Equate model moment to sample moment; then check bias using expectation, variance, or Jensen. |
| Likelihood from independent observations | Mock Q2, 2022 Q2, 2023 Q2, 2024 Q1-Q2, 2025 Q1-Q2 | Product over iid observations, take log or negative log, differentiate with respect to unknown parameters. |
| Nested likelihood-ratio tests | 2024 Q1(iii)(b), 2025 Q2(iii)(b), 2022 Q2(c)-(d) | Define $H_0/H_1$, use likelihood ratio, choose $\alpha$, simulate/derive $t$ under $H_0$, reject for large $t$, calculate power under $H_1$. |

## Past-Paper Frequentist Pattern

| Paper | Q1 pattern | Q2 pattern |
|---|---|---|
| Mock | Bernoulli/binomial moments, MoM, MLE, bias, good estimator | Type I/II, faulty-test conditional statement, exponential normalisation/CDF/KS, exponential MLE, Neyman interval |
| 2022 | Binomial moments; Poisson MoM/MLE/third central moment | Gaussian MLE for $\mu,\sigma$; Gaussian straight-line fit; Neyman/profiling; goodness of fit |
| 2023 | Maxwell-Boltzmann moment; unbiasedness; MoM; bias; good estimator | Almost the mock Q2 structure: Type I/II, exponential normalisation/CDF/KS, exponential MLE, Neyman |
| 2024 | Gaussian polynomial least squares; nested linear-vs-quadratic test; power | Rayleigh normalisation/moment; MoM; likelihood/MLE; bias via Jensen |
| 2025 | Exponential decay mean/MoM; sum of exponentials; MLE; bias; good estimator | Poisson MLE; repeated Poisson likelihood/MLE; Neyman/profile interval; likelihood-ratio hypothesis test and power |

## Practice Problems Not Yet Seen Directly In Q1-Q2

These are the best candidates for "unseen but plausible" practice because they are on the Part 1 sheet but have not appeared directly in Q1-Q2 of the available papers.

| Part 1 problem | Why it could matter | Priority |
|---|---|---:|
| 1.2 Zero correlation does not mean independence | Clean conceptual proof about expectation, covariance, independence, and counterexamples. This has not appeared directly, but it is exam-friendly. | Medium-high |
| 1.4 Cauchy distribution from ratio of Gaussians | Change-of-variables / marginalisation style derivation. Harder and not yet seen, so it could be an "unseen derivation" if they give hints. | Medium |
| 1.6 Convergence to uniform distribution | Connects to convergence in distribution and CDF reasoning. Not yet seen directly. | Medium |
| 1.7 Convergence to Dirac delta | Same convergence theme; useful for consistency/asymptotic intuition. | Medium |
| 1.9 Phone call / 5 sigma p-value | Not exact, but p-values, tail probabilities, and significance language recur in testing questions. | Medium |
| 1.1 Kolmogorov axioms | Foundational definition question. Could appear as a short conceptual part, but less represented in past exams. | Low-medium |
| 1.5 Lying friend | Bayes-rule conditional probability. Not Q1-Q2 frequentist, but similar thinking appears in faulty-test and theft-alarm questions. | Medium for Bayesian/conditional probability |

## Revision Implication

Do not spend equal time on every Part 1 problem.

Priority order from repeat evidence:

1. 1.3, 1.8, 1.10: direct repeat evidence.
2. 1.9 and hypothesis-testing language: frequent test-procedure recurrence.
3. 1.2, 1.4, 1.6, 1.7: plausible unseen Part 1 material; use as targeted drills after current past-paper weak spots.
4. 1.1 and 1.5: short conceptual review, not long algebra sessions.

Exam-risk guess: the most likely "new but from the practice sheet" style would be either a covariance/independence proof from 1.2, a convergence-in-distribution question from 1.6/1.7, or a ratio/change-of-variables derivation like 1.4. If time is tight, do the opening setup and method for each rather than perfecting every line.
