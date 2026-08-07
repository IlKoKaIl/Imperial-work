# Squarepoint Quant Interview Study Plan

Assumption: interview date unknown. Default pace is 2 focused hours on weekdays and 3-4 hours on one weekend day. If an interview date appears, compress the plan by keeping the diagnostic, coding, probability, regression, and behavioural pieces.

## Summary

Prepare by doing questions, not by reading books cover to cover.

Daily default:

1. 45 minutes coding.
2. 45 minutes probability/statistics.
3. 20 minutes quant puzzle or mental maths.
4. 20 minutes resume/behavioural story.
5. 10 minutes error log.

Acceptance criteria:

- You can solve most NeetCode Easy problems in 15-20 minutes and Mediums in 35-45 minutes.
- You can explain Bayes, likelihood vs posterior, MLE vs MAP, p-values, confidence intervals, OLS, regularisation, and cross-validation without notes.
- You have 8-10 polished resume stories with situation, action, technical detail, result, and reflection.
- You can talk through a probability problem calmly even when you do not immediately see the trick.

## Diagnostic Day

Do this first.

1. Coding: one NeetCode Medium from arrays/hash maps or two pointers.
2. Probability: one Bayes/conditional probability problem.
3. Statistics: explain linear regression from memory:
   - model;
   - assumptions;
   - OLS objective;
   - why overfitting happens;
   - how ridge/lasso/cross-validation help.
4. Resume: pick one technical project and explain it in 3 minutes.

Write misses in an error log:

| Date | Area | Question | Mistake | Fix | Redo Date |
|---|---|---|---|---|---|

## Week 1: Core Coding + Probability

Goal: remove rust and build fluency.

Coding:

- Arrays and hash maps.
- Two pointers.
- Sliding window.
- Binary search.
- Stacks/queues.

Stats/probability:

- Conditional probability and Bayes theorem.
- Law of total probability.
- Law of total expectation and variance.
- Expectation and variance shortcuts.
- Bernoulli, binomial, Poisson, Gaussian, exponential.
- Covariance/correlation and independence.

Deliverables:

- 12-15 coding problems logged.
- One-page probability formula recap.
- 10 short probability questions attempted out loud.

## Week 2: Statistical Inference

Goal: make MLE/MAP/testing automatic.

Coding:

- Trees.
- BFS/DFS.
- Heaps.
- Start graphs.

Stats:

- Likelihood setup: single observation vs independent product.
- MLE workflow.
- Method of moments.
- Bias, variance, consistency, standard error.
- MAP workflow.
- Priors and conjugacy.
- Posterior mean and variance.
- Fisher information and curvature.
- Confidence interval vs credible interval.
- Hypothesis tests, p-values, Type I/II error, power.

Deliverables:

- Derive MLE for Bernoulli, Poisson, Gaussian mean/variance, exponential rate.
- Derive MAP for beta-binomial and Poisson-gamma-style kernels.
- Explain p-value and confidence interval without mixing Bayesian language.

## Week 3: Regression, ML, Data Reasoning

Goal: answer practical modelling questions.

Coding:

- Graphs.
- Intervals.
- Linked list only enough to pass common questions.
- Basic dynamic programming.

ML/statistics:

- Linear regression and OLS.
- Matrix form: $\hat{\beta}=(X^TX)^{-1}X^Ty$.
- Gaussian noise link to least squares.
- Multicollinearity, residuals, heteroskedasticity.
- Ridge and lasso.
- Logistic regression.
- Bias-variance tradeoff.
- Train/test split, cross-validation, leakage.
- Classification metrics: precision, recall, ROC/AUC, log loss.
- Model selection: CV, AIC, BIC, Bayes factor.
- Bootstrap at the practical level.

Deliverables:

- Explain one model choice end to end: data, target, features, model, validation, risks.
- 10 ML interview questions answered in writing.

## Week 4: Interview Simulation

Goal: turn knowledge into interview performance.

Do 3 mixed mocks:

1. 45 minutes coding.
2. 30 minutes probability.
3. 30 minutes statistics/ML.
4. 20 minutes behavioural/resume.

For each mock:

- Speak aloud.
- Write assumptions before algebra.
- If stuck, state a simpler version first.
- Review mistakes same day.
- Redo missed questions 48 hours later.

## If The Interview Is Within 7 Days

Cut everything to this:

Day 1:

- Diagnostic.
- Arrays/hash maps.
- Conditional probability and Bayes.

Day 2:

- Two pointers/sliding window.
- Expectation, variance, distributions.
- Resume stories.

Day 3:

- Trees/graphs.
- MLE/MAP and priors.

Day 4:

- Linear regression, overfitting, cross-validation.
- 2 coding Mediums.

Day 5:

- Hypothesis tests, p-values, confidence intervals.
- Probability puzzle set.

Day 6:

- Full mock: coding + probability + stats + behavioural.

Day 7:

- Redo mistakes.
- Light formula recall.
- No heavy new reading.

## Weekly Review

Every Sunday:

1. Redo 3 missed coding problems.
2. Redo 3 missed stats/probability questions.
3. Update weak topics.
4. Pick next week based on misses, not vibes.

