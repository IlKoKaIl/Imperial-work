# Quant Interview Prep

Start here. This folder is for Squarepoint-style quant prep: coding, probability/statistics, regression/ML, puzzles, and behavioural/resume stories.

## Main Files

- [study-plan.md](study-plan.md): the working plan.
- [interview-stats-cheatsheet.md](interview-stats-cheatsheet.md): joint frequentist + Bayesian + regression notes for interview questions.
- [coding-tracker.md](coding-tracker.md): NeetCode/Blind 75 tracker.
- [resources.md](resources.md): what to read and what to skip.

## What To Prioritise

Do not begin by reading all of Wasserman, ESL, Bishop, Joshi, and Xinfeng. That is a trap. Use questions as the syllabus.

Priority order:

1. Coding practice: arrays/hash maps, two pointers, sliding window, binary search, stacks, trees, graphs, heaps, basic DP.
2. Probability: conditional probability, Bayes, expectation/variance, covariance, distributions, CLT, joint normal.
3. Statistics: likelihood, MLE, MAP, priors, posterior/evidence, confidence intervals, p-values, hypothesis tests.
4. Regression/ML: OLS, assumptions, overfitting, regularisation, cross-validation, leakage, classification metrics.
5. Behavioural/resume: explain projects, choices, mistakes, impact, and why Squarepoint.

## What To Read From Your Old Statistical Methods Notes

Use these first:

- `Statistical Methods/Exam Prep/recall-sheet-frequentist.md`
- `Statistical Methods/Exam Prep/recall-sheet-bayesian.md`
- `Statistical Methods/Exam Prep/theory-answer-bank.md`
- `Statistical Methods/Exam Prep/exam-procedures.md`

Do not reread the full course PDFs unless a practice question exposes a gap. Your old exam questions are useful because they already drill the same core statistical instincts: likelihood setup, MLE/MAP, priors, evidence, hypothesis testing, and confidence/credible interval language.

## Wasserman CMU Notes

The CMU page is 36-705 Intermediate Statistics, based around chapters 1-12 of *All of Statistics*. Read selectively:

Must read or skim carefully:

- Lecture 1: random variables, CDF/PDF/PMF, expectation, variance, covariance, conditional expectation, common distributions, multivariate normal.
- Lecture 5: LLN/CLT and convergence, mainly conceptually.
- Lecture 13: estimators, method of moments, MLE, Bayes estimators.
- Lecture 16: hypothesis tests, Type I/II error, power, Wald/LRT.
- Lecture 17: goodness-of-fit, permutation tests, multiple testing.
- Lecture 18: confidence sets, inverting tests, pivots.
- Lecture 20: Monte Carlo and bootstrap.
- Lecture 23: linear regression, least squares, overfitting, LASSO.
- Lecture 24: Bayesian inference, priors, credible sets, Jeffreys prior, priors as regularisers.
- Lecture 25: model selection, CV, AIC, BIC, Bayesian model selection.

Optional if time:

- Lecture 26: nonparametric regression, kernels, bias-variance, curse of dimensionality.
- Lecture 27: KL/TV/Hellinger distances and model misspecification.

Skip unless specifically needed:

- Detailed proofs of concentration/Rademacher/VC theory.
- Long technical asymptotic proofs.
- Advanced high-dimensional theory derivations.

Sources:

- CMU 36-705 page: https://www.stat.cmu.edu/~larry/%3Dstat705/
- Squarepoint Early Careers: https://www.squarepoint-capital.com/early-careers
- Squarepoint Open Opportunities: https://www.squarepoint-capital.com/open-opportunities

