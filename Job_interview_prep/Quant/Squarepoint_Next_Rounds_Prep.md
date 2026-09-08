# Squarepoint Next Rounds Prep

Use this after the first HackerRank/codepair round. Treat the notes from `Notes quant n pupil.txt` as candidate-reported signal, not guaranteed truth.

## What To Expect

Likely next-round shape:

- CV/background opener.
- Probability and statistics with a Quant Researcher.
- Linear regression theory: OLS, ridge, lasso, assumptions, inference vs prediction.
- Classic quant brainteasers: coins, dice, cards, conditional probability, expected values.
- Finance intuition: liquidity, order books, transaction costs, volatility, Sharpe, stocks/bonds/options.
- Possibly another HackerRank codepair: easy-medium arrays, heaps, binary search, DP, prefix sums, sorting/counting.
- Final-style round: thesis/project depth, day-to-day role fit, why quant finance.

Public signal is consistent with this: Glassdoor/WSO-style reports mention 3-6 rounds, live coding, probability/statistics, finance intuition, and some final CV/fit discussion. Official Squarepoint pages emphasise a systematic scientific approach, large-scale data analysis, research/trading/ML collaboration, and technology connecting research to trading.

Sources:

- https://www.squarepoint-capital.com/
- https://www.squarepoint-capital.com/about
- https://www.squarepoint-capital.com/early-careers
- https://www.squarepoint-capital.com/experienced-professionals
- https://www.glassdoor.co.uk/Interview/Squarepoint-Capital-Junior-Quant-Researcher-Interview-Questions-EI_IE1442647.0,19_KO20,45.htm
- https://www.wallstreetoasis.com/company/squarepoint-capital/interview
- https://www.interviewquery.com/interview-guides/squarepoint-capital-quantitative-analyst

## Priority Order

If time is tight, do not spread evenly.

1. Linear regression and assumptions.
2. Probability brainteasers with expectation/Bayes/variance.
3. Finance basics: volatility, Sharpe, liquidity, order book, transaction costs.
4. CV/thesis/project answers.
5. One coding maintenance block every 1-2 days.
6. PCA, gradient descent, Kalman filter only after the above.

## 3-Day Sprint

### Day 1 - Regression + Probability

- Derive OLS and ridge from scratch.
- Explain lasso and why it has no simple closed form in general.
- Do 8 probability questions aloud.
- Prepare 2-minute thesis answer.

### Day 2 - Finance + Coding

- Review liquidity, bid-ask spread, order book, volatility, Sharpe, transaction costs.
- Do one coding set: `Top K Frequent`, `Subarray Sum Equals K`, `Sort Characters by Frequency` or equivalent.
- Do one pandas/sklearn drill on a CSV or synthetic data.
- Prepare `COVID` and `Higgs` answers.

### Day 3 - Mock

- 30 min probability/stats mock aloud.
- 30 min finance intuition mock aloud.
- 45 min coding mock if another codepair is possible.
- Redo the 3 weakest questions.
- Prepare 4 questions to ask.

## Linear Regression Core

### OLS Derivation

Problem:

```text
min_beta ||y - X beta||^2
```

Expand and differentiate:

```text
L(beta) = (y - X beta)^T (y - X beta)
dL/dbeta = -2 X^T y + 2 X^T X beta
```

Set gradient to zero:

```text
X^T X beta = X^T y
beta_hat = (X^T X)^(-1) X^T y
```

Conditions:

- Need `X^T X` invertible for the simple closed form.
- If features are collinear, `X^T X` becomes singular or ill-conditioned.
- Prediction can still work with correlated features, but coefficient interpretation/inference becomes unstable.

Interview line:

> "OLS finds coefficients that minimize squared residuals. For inference I care about assumptions on errors; for prediction I care more about out-of-sample performance and leakage."

### Ridge Regression

Problem:

```text
min_beta ||y - X beta||^2 + lambda ||beta||^2
```

Solution:

```text
beta_ridge = (X^T X + lambda I)^(-1) X^T y
```

What ridge does:

- Shrinks coefficients toward zero.
- Reduces variance at the cost of some bias.
- Helps when features are highly correlated.
- Makes the matrix better conditioned.

Good line:

> "Ridge does not usually set coefficients exactly to zero; it stabilizes them."

### Lasso

Problem:

```text
min_beta ||y - X beta||^2 + lambda ||beta||_1
```

What to say:

- Lasso uses an L1 penalty.
- It can drive coefficients exactly to zero, so it performs feature selection.
- It is not differentiable at zero, so unlike OLS/ridge there is no simple general closed-form inverse formula.
- In special orthonormal cases it behaves like soft-thresholding.

### Assumptions: Inference vs Prediction

For inference, classical OLS wants:

- Linear specification in parameters.
- Independent errors.
- Exogeneity: `E[epsilon | X] = 0`.
- Homoskedasticity for standard textbook standard errors.
- No severe multicollinearity for stable coefficient estimates.
- Normal errors mainly for exact small-sample t/F tests, not for point estimates.

For prediction:

- The main question is whether it generalises out of sample.
- Heteroskedasticity or non-normal errors may be acceptable if validation is strong.
- Leakage, regime change, and unstable relationships are often bigger practical problems.

### R-Squared

```text
R^2 = 1 - SSE / SST
```

Meaning:

- Fraction of target variance explained relative to predicting the mean.
- Can be negative out of sample.
- High `R^2` does not prove causality or trading usefulness.

## PCA / Dimensionality Reduction

PCA answer:

> "PCA finds orthogonal directions of maximum variance after centering the data. The first principal component explains the most variance, the next explains the most remaining variance subject to being orthogonal."

Key points:

- Mean-center first.
- Often use covariance/eigendecomposition or SVD.
- Useful for compression, denoising, visualisation, and handling correlated features.
- Components are linear combinations, so interpretability can be worse.
- PCA is unsupervised: high variance directions are not always most predictive.

## Gradient Descent

Short answer:

> "Gradient descent iteratively moves parameters in the direction that reduces the loss."

```text
theta <- theta - eta * grad L(theta)
```

Know:

- Learning rate too high can diverge.
- Learning rate too low can be slow.
- SGD uses noisy mini-batch gradients, which is cheaper and can help escape shallow regions.
- Adam adapts learning rates per parameter and is a strong neural-net default.

## Kalman Filter

Short answer:

> "A Kalman filter is a Bayesian updating method for a linear dynamical system with Gaussian noise. It alternates between predicting the hidden state forward and updating it when a noisy observation arrives."

Two steps:

- Predict: use the state transition model.
- Update: combine prediction with measurement, weighted by uncertainty.

Finance intuition:

- Useful for estimating hidden state from noisy time series.
- Examples: trend estimation, pairs trading hedge ratio, latent fair value, noisy signal smoothing.
- It assumes linear-Gaussian structure unless extended/unscented variants are used.

## Probability / Stats Questions

### Variance Of A Sum

For three random variables:

```text
Var(X + Y + Z)
= Var(X) + Var(Y) + Var(Z)
  + 2Cov(X,Y) + 2Cov(X,Z) + 2Cov(Y,Z)
```

If independent, the covariance terms are zero.

### Dice Sum Divisible By X

Method:

- Work modulo `x`.
- Count residue combinations among the three dice.
- For `x = 3`, residues are balanced, so probability is `1/3`.
- For `x = 2`, parity is balanced, so probability is `1/2`.

Say:

> "I would reduce the dice faces modulo x and convolve/count the residues."

### At Least One Run Of 3 Heads In 10 Tosses

Use complement:

- Count sequences with no `HHH`.
- Recurrence `a_n = a_{n-1} + a_{n-2} + a_{n-3}`.
- Base: `a_0 = 1`, `a_1 = 2`, `a_2 = 4`.
- `a_10 = 504`.

```text
P(at least one HHH in 10 tosses) = 1 - 504 / 1024 = 65 / 128 ~= 0.508
```

### Expected Tosses To Get HHH

For a fair coin, expected tosses to get 3 heads in a row:

```text
2^(3+1) - 2 = 14
```

State method if deriving:

- Let `E0`, `E1`, `E2` be expected remaining tosses with current streak of 0, 1, 2 heads.
- Write first-step equations.
- Solve.

### Average Max Of Two Uniforms

If `X, Y ~ U(0,1)`:

```text
P(max(X,Y) <= t) = t^2
f_max(t) = 2t
E[max] = integral_0^1 2t^2 dt = 2/3
```

### 999 Fair Coins And 1 Double-Headed Coin

Prior double-headed: `1/1000`.

After 10 heads:

```text
P(D | 10H)
= (1 * 1/1000) / (1 * 1/1000 + (1/2)^10 * 999/1000)
= 1024 / (1024 + 999)
~= 0.506
```

Key lesson:

> "Even very strong evidence only just overcomes the tiny prior."

### Best Fit Line For Points `(0,0)`, `(0,1)`, `(1,1)`

Each point equally likely. Regress `y` on `x`.

```text
E[X] = 1/3
E[Y] = 2/3
E[XY] = 1/3
Cov(X,Y) = 1/3 - (1/3)(2/3) = 1/9
Var(X) = 1/3 - 1/9 = 2/9
beta = Cov(X,Y) / Var(X) = 1/2
alpha = E[Y] - beta E[X] = 1/2
```

Answer:

```text
y = 1/2 + x/2
```

### Even Number Of Heads In N Tosses

For coin with `P(H)=p`, `P(T)=q`:

```text
P(even heads in n tosses) = (1 + (q - p)^n) / 2
```

If `p = 1/3`, `q = 2/3`:

```text
P(even heads) = (1 + (1/3)^n) / 2
```

### First Card Greater Than Second Card

With ranks only, ties possible.

```text
P(tie) = 3/51 = 1/17
P(first > second) = (1 - P(tie)) / 2 = 8/17
```

If suits impose a total order and no ties, answer is `1/2`.

### Red / Blue Candy Expected Draws

Bag: 3 red, 3 blue. Red is eaten, blue is replaced.

When `r` red remain, probability next draw is red:

```text
p = r / (r + 3)
E[draws to next red] = 1/p = (r + 3)/r
```

Total:

```text
r = 3: 2
r = 2: 5/2
r = 1: 4
total = 8.5
```

### 55 Or More Heads In 100 Tosses

Use normal approximation:

```text
X ~ Binomial(100, 0.5)
mean = 50
sd = 5
P(X >= 55) ~= P(N(50,25) >= 54.5)
z = 0.9
tail ~= 0.184
```

Say:

> "With continuity correction, about 18 percent."

## Finance Mini Sheet

### Volatility

> "Volatility is usually the standard deviation of returns over a chosen horizon."

Scaling:

```text
monthly vol ~= daily vol * sqrt(21)
annual vol ~= daily vol * sqrt(252)
```

Assumes returns are roughly independent with stable variance.

### Sharpe Ratio

```text
Sharpe = E[R - R_f] / sigma_R
```

Scaling:

```text
annual Sharpe ~= daily Sharpe * sqrt(252)
```

Careful:

- This scaling assumes iid-ish returns.
- Autocorrelation, changing volatility, and fat tails can break the clean scaling.

### Liquidity

> "Liquidity is the ability to trade size quickly without moving the price too much."

Signs of good liquidity:

- Tight bid-ask spread.
- Deep order book.
- High volume.
- Low market impact.
- Stable execution across normal order sizes.

### Order Book Liquidity

Terms:

- Bid: best price buyers are willing to pay.
- Ask: best price sellers are willing to accept.
- Spread: `ask - bid`.
- Depth: quantity available at price levels.
- Market order: prioritises execution certainty, pays spread/impact.
- Limit order: controls price, risks non-execution.

### Transaction Costs

Costs include:

- Bid-ask spread.
- Fees/commissions.
- Slippage.
- Market impact.
- Borrow/funding costs where relevant.

Good quant line:

> "A signal is not tradable just because it predicts returns. It must survive realistic costs, capacity, and risk constraints."

### Stocks, Bonds, Options

Stock:

- Ownership claim on a company.
- Payoff comes from price appreciation and possibly dividends.

Bond:

- Debt claim.
- Pays coupons and principal if the issuer does not default.
- Price falls when yields rise, all else equal.

Option:

- Right but not obligation to buy/sell an underlying.
- Call benefits from upside; put benefits from downside.
- Value depends on underlying price, strike, time, rates, dividends, and volatility.

### Skewing / Market Making Intuition

If a trader says they are "skewing" quotes:

- They adjust bid/ask prices asymmetrically.
- Usually because of inventory, risk, or directional view.
- If long inventory, they may quote more aggressively to sell and less aggressively to buy.
- If short inventory, reverse.

## Mean-Variance Optimisation

Basic setup:

```text
min_w w^T Sigma w
subject to 1^T w = 1
and optionally mu^T w = target return
```

Lagrangian with only budget constraint:

```text
L = w^T Sigma w - lambda(1^T w - 1)
dL/dw = 2 Sigma w - lambda 1 = 0
w = (lambda/2) Sigma^{-1} 1
```

Use constraint to solve `lambda`.

Interview intuition:

> "Mean-variance optimisation balances expected return against covariance risk. The covariance terms matter because diversification depends on how assets move together."

Practical caveat:

> "The optimiser is very sensitive to estimated means, so naive plug-in portfolios can be unstable."

## Coding Maintenance

Likely patterns from your notes:

- Frequency sorting.
- Number of pairs with difference `k`.
- Minimum subarray/window with at least `k` occurrences.
- Priority queue.
- Difference array.
- Binary search debugging.
- DP similar to LIS/Fibonacci.
- Subarray sums.
- Palindromes in binary strings.

Do these:

- `Top K Frequent Elements`.
- `Sort Characters by Frequency`.
- `Kth Largest Element`.
- `Subarray Sum Equals K`.
- `Minimum Size Subarray Sum`.
- `Longest Palindromic Substring` or `Palindromic Substrings`.
- `Longest Increasing Subsequence`.

## Pandas / Sklearn Drill

Be able to do this out loud:

1. Load data with `pandas`.
2. Inspect with `head`, `info`, `describe`, missing values.
3. Split train/test.
4. Fit baseline linear/logistic regression.
5. Fit Random Forest or XGBoost-style tree model if available.
6. Report metric: RMSE/MAE for regression, AUC/precision/recall for classification.
7. Plot residuals or prediction vs actual.
8. Explain overfitting and leakage checks.

Minimal code shape:

```python
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error, r2_score
from sklearn.linear_model import Ridge

df = pd.read_csv("data.csv")
X = df.drop(columns=["target"])
y = df["target"]

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=0
)

model = Ridge(alpha=1.0)
model.fit(X_train, y_train)
pred = model.predict(X_test)

print(mean_squared_error(y_test, pred, squared=False))
print(r2_score(y_test, pred))
```

## CV / Thesis Answers

### Thesis

> "My thesis is about testing whether simulated galaxy populations match telescope observations. The transferable part is model validation: compare predicted distributions to real data, diagnose where assumptions fail, and be honest about uncertainty."

If asked for more:

- Pop-Cosmos gives simulated galaxy properties.
- FSPS turns physical assumptions into predicted light/SEDs.
- Redshift shifts emitted light to longer observed wavelengths.
- Current issue: reasonable at 250 microns, overpredicting brighter sources at 350/500 microns.
- You are testing alternative or hybrid SED assumptions.

Quant link:

> "In finance, the domain changes, but the modelling discipline is similar: build a model, test it out of sample, find misspecification, and avoid fooling yourself."

### COVID Forecasting

> "I used UK COVID and mobility data to forecast deaths or hospital demand over future horizons. The key issues were lagged features, time-aware validation, leakage avoidance, and regime change."

Good follow-up:

> "Short-horizon forecasts were better. Longer-horizon forecasts degraded because the pandemic changed through waves, policies, vaccines, and reporting changes."

### Higgs Boson Detection

> "I classified particle events as signal or background using tabular physics features and tree-based models. The key lesson was that the classifier was only useful if it improved the downstream likelihood fit."

Quant link:

> "That maps to quant trading because a signal should be judged by the final objective, not only by an intermediate metric."

### A4 1D CNN

> "I trained a 1D CNN in PyTorch to classify detector waveforms. CNNs made sense because local time-shape patterns mattered."

Good learning:

> "More complexity was not automatically better; the baseline CNN was already strong, so evaluation mattered more than adding layers."

## Video Recommendations

Watch only what patches a weakness.

### Must Watch

- StatQuest videos page: Linear Regression, Ridge/Lasso, PCA, ROC/AUC.
  https://statquest.org/video-index/
- 3Blue1Brown: Bayes theorem, geometry of changing beliefs.
  https://www.youtube.com/watch?v=HZGCoVF3YvM
- Harvard Stat 110: expectation, conditioning, counting.
  https://stat110.hsites.harvard.edu/
- MIT OCW Portfolio Management lecture.
  https://ocw.mit.edu/

### Finance Basics

- Khan Academy Finance and Capital Markets: stocks, bonds, options, risk/reward.
  https://www.khanacademy.org/economics-finance-domain/core-finance
- Sharpe ratio explainer.
  https://www.youtube.com/watch?v=fWnyg0UeQkg

### Optional If Asked About Kalman / State Space

- Kalman filter intuition plus finance application paper.
  https://arxiv.org/abs/1811.11618

## Questions To Ask

- How does the DQA role evolve after the first few months?
- What separates a good DQA from an excellent one?
- How much of the work is live desk support versus research tooling?
- What kinds of data or modelling problems do DQAs usually touch?
- Which technical skill would you advise me to sharpen most before joining?
- How do researchers, traders, and DQAs collaborate day to day?
