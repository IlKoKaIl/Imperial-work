# Squarepoint Next Rounds Maths / Stats Prep

Current context: today is Thursday 2026-09-10 and the interview is Tuesday 2026-09-15.

Use this as a teaching guide, not a checklist. The goal is to understand the core ideas well enough to explain them aloud, derive the simple formulas, and handle variations.

Treat `Notes quant n pupil.txt` as candidate-reported signal from reviews, not guaranteed interview content.

# What The Next Round Is Likely Testing

The signal from your notes points to:

- Linear regression from the ground up: OLS, ridge, lasso, assumptions, multicollinearity, R-squared.
- Probability brainteasers: coins, dice, cards, Bayes, expected values, normal/binomial approximation.
- Core statistics: variance/covariance, normal distribution, chi-squared distribution, CLT.
- Finance intuition: liquidity, order book liquidity, volatility, Sharpe, bonds, stocks, options, transaction costs, arbitrage, quote skewing.
- Some coding/data skills: pandas/numpy/sklearn, plots, priority queues, difference arrays, binary search, subarray sums, frequency sorting.
- CV/thesis discussion: explain projects clearly and connect them to modelling under uncertainty.

## Coverage Map From Your Notes

| Past-question theme from notes                            | Covered here                                            |
| --------------------------------------------------------- | ------------------------------------------------------- |
| Linear regression basics and closed form                  | `Linear Regression From Zero`, `OLS Derivation`     |
| Ridge, lasso, shrinking beta                              | `Ridge Regression`, `Lasso Regression`              |
| Necessary/sufficient assumptions, inference vs prediction | `Assumptions: Inference vs Prediction`                |
| R-squared definition                                      | `R-Squared`                                           |
| Multicollinearity problems                                | `Multicollinearity`                                   |
| Variance of sum with covariances                          | `Variance And Covariance`                             |
| Chi-squared distribution                                  | `Chi-Squared Distribution`                            |
| Normal distribution and CLT                               | `Normal Distribution`, `CLT`, `55 Or More Heads`  |
| Dice sum divisible by x                                   | `Dice Sum Divisible By X`                             |
| 3 heads in a row in 10 tosses                             | `At Least One Run Of 3 Heads`                         |
| Expected tosses to get 3 heads in a row                   | `Expected Tosses To Get HHH`                          |
| Expected max of two uniforms                              | `Max Of Two Uniforms`                                 |
| Double-headed coin Bayes question                         | `999 Fair Coins And 1 Double-Headed Coin`             |
| Best fit line through three points                        | `Best Fit Line For Three Points`                      |
| Even number of heads with unfair coin                     | `Even Number Of Heads`                                |
| Card comparison probability                               | `First Card Greater Than Second`                      |
| Red/blue candy expected draws                             | `Red / Blue Candy Expected Draws`                     |
| Estimate 55+ heads in 100 tosses                          | `55 Or More Heads`                                    |
| Fair/biased coin Bayes                                    | `Bayes With Fair And Biased Coin`                     |
| Create probability 0.7 from a coin                        | `Create Probability 0.7 From Coin Tosses`             |
| Asset gives n times return after n years, answer e        | `The e Growth Question`                               |
| Mean-variance optimisation with Lagrangian                | `Mean-Variance Optimisation`                          |
| PCA / dimensionality reduction                            | `PCA And Dimensionality Reduction`                    |
| Gradient descent methods                                  | `Gradient Descent`                                    |
| Kalman filter / Bayesian models                           | `Kalman Filter`                                       |
| Liquidity, order book liquidity                           | `Liquidity And Order Books`                           |
| Volatility, daily to monthly                              | `Volatility`                                          |
| Sharpe ratio                                              | `Sharpe Ratio`                                        |
| Stocks, bonds, options                                    | `Stocks, Bonds, Options`                              |
| Trading costs, arbitrage, skewing                         | `Transaction Costs`, `Arbitrage`, `Quote Skewing` |
| Pandas, numpy, matplotlib, sklearn                        | `Data Exploration And Sklearn Drill`                  |
| Priority queue, difference array, binary search           | `Coding Maintenance`                                  |
| Frequency sort, pairs difference k, subarray/window       | `Coding Maintenance`                                  |
| Smaller elements for query array                          | `Coding Maintenance`                                  |
| C++ concepts: reference/value, operator overload, virtual | `Programming Concepts`                                |
| Resume projects / thesis                                  | `CV And Thesis Answers`                               |

## How To Answer Maths Questions

Use this structure:

1. Restate the question.
2. Define variables.
3. Start with a simple case.
4. Write the formula.
5. Plug numbers in.
6. Check whether the answer is plausible.

Good interview phrase:

> "Let me define the variables first so I do not mix up the conditioning."

## Linear Regression From Zero

### What Linear Regression Is

You have inputs `X` and an output `y`.

The model says:

```text
prediction = beta_0 + beta_1 x_1 + beta_2 x_2 + ... + beta_p x_p
```

In matrix form:

```text
y_hat = X beta
```

Each row of `X` is one observation. Each column is one feature. `beta` contains the coefficients.

The error/residual is:

```text
residual = y - y_hat = y - X beta
```

## OLS Objective

OLS means ordinary least squares.

It chooses `beta` to minimise the sum of squared residuals:

```text
min_beta ||y - X beta||^2
```

Why square errors?

- Big errors are punished more.
- The maths is smooth and gives a closed form.
- If noise is Gaussian, OLS is also the maximum likelihood estimator.

### OLS Derivation

Start:

```text
L(beta) = ||y - X beta||^2
        = (y - X beta)^T (y - X beta)
```

Expand:

```text
L(beta) = y^T y - 2 beta^T X^T y + beta^T X^T X beta
```

Differentiate with respect to `beta`:

```text
dL/dbeta = -2 X^T y + 2 X^T X beta
```

Set the gradient to zero:

```text
-2 X^T y + 2 X^T X beta = 0
X^T X beta = X^T y
```

If `X^T X` is invertible:

```text
beta_hat = (X^T X)^(-1) X^T y
```

Say this aloud:

> "OLS sets the gradient of squared error to zero. This gives the normal equations. If the feature covariance matrix is invertible, I can solve for beta in closed form."

### Ridge Regression

Ridge adds a penalty for large coefficients:

```text
min_beta ||y - X beta||^2 + lambda ||beta||^2
```

The solution is:

```text
beta_ridge = (X^T X + lambda I)^(-1) X^T y
```

What ridge does:

- Shrinks coefficients towards zero.
- Reduces variance but adds bias.
- Helps with multicollinearity.
- Makes the matrix easier to invert.
- Does not usually make coefficients exactly zero.

Intuition:

> "Ridge is useful when OLS coefficients are too unstable. I accept a bit of bias to get a more stable model."

### Lasso Regression

Lasso adds an absolute-value penalty:

```text
min_beta ||y - X beta||^2 + lambda ||beta||_1
```

What lasso does:

- Shrinks coefficients.
- Can set some coefficients exactly to zero.
- Acts like feature selection.
- Has no simple general closed-form inverse solution because the absolute value is not differentiable at zero.

Ridge vs lasso:

- Ridge: stabilise all coefficients.
- Lasso: shrink and select features.
- Elastic net: mixture of ridge and lasso.

### Multicollinearity

Multicollinearity means features are strongly correlated.

Example:

```text
x_2 is almost the same as x_1
```

Problem:

- OLS struggles to decide which feature deserves the coefficient.
- Coefficients can become large and unstable.
- Standard errors increase.
- Individual coefficient interpretation becomes unreliable.
- Prediction may still be fine if the same relationship holds out of sample.

Fixes:

- Drop one of the correlated features.
- Use ridge.
- Use PCA.
- Collect more data.
- Focus on prediction rather than interpreting each coefficient.

### Assumptions: Inference vs Prediction

Separate two goals.

Inference asks:

```text
Can I interpret beta and confidence intervals?
```

Prediction asks:

```text
Does the model perform well on new data?
```

For inference, the classical assumptions matter more:

- Correct linear specification.
- Exogeneity: `E[epsilon | X] = 0`.
- Independent errors.
- Homoskedastic errors for textbook standard errors.
- No severe multicollinearity.
- Normal errors for exact small-sample t-tests and F-tests.

For prediction:

- Out-of-sample validation matters most.
- Non-normal errors are not fatal.
- Heteroskedasticity is not fatal if predictions are good and uncertainty is handled carefully.
- Leakage and regime change are often more dangerous.

Good line:

> "Violating assumptions can hurt inference before it hurts prediction. For prediction I care most about honest validation; for inference I care whether coefficient estimates and standard errors mean what I claim they mean."

### R-Squared

```text
R^2 = 1 - SSE / SST
```

Where:

```text
SSE = sum of squared residuals from the model
SST = sum of squared deviations from predicting the mean
```

Meaning:

- `R^2 = 0`: no better than predicting the mean.
- `R^2 = 1`: perfect fit.
- Out-of-sample `R^2` can be negative.
- High `R^2` does not imply causality or tradability.

## Core Probability And Statistics

### Variance And Covariance

Variance measures spread:

```text
Var(X) = E[X^2] - E[X]^2
```

Covariance measures how two variables move together:

```text
Cov(X,Y) = E[XY] - E[X]E[Y]
```

For a sum of three random variables:

```text
Var(X + Y + Z)
= Var(X) + Var(Y) + Var(Z)
  + 2Cov(X,Y) + 2Cov(X,Z) + 2Cov(Y,Z)
```

If independent, covariance terms are zero.

### Normal Distribution

Know:

- Symmetric bell-shaped distribution.
- Defined by mean and variance.
- Sums/averages often become approximately normal by the CLT.
- Standard normal has mean `0` and variance `1`.

Standardisation:

```text
Z = (X - mean) / sd
```

### CLT

The central limit theorem says averages of many independent, not-too-heavy-tailed variables become approximately normal.

Important:

- The original data does not need to be normal.
- Independence and finite variance matter.
- It justifies normal approximations for sums, like coin toss counts.

### Chi-Squared Distribution

If:

```text
Z_1, ..., Z_k are independent standard normals
```

Then:

```text
Z_1^2 + ... + Z_k^2 ~ chi-squared(k)
```

Uses:

- Variance inference for normal data.
- Goodness-of-fit tests.
- Chi-squared tests of independence in contingency tables.

Mean and variance:

```text
E[chi2_k] = k
Var(chi2_k) = 2k
```

## Worked Probability Questions From The Notes

### Dice Sum Divisible By X

Question: roll 3 fair dice. What is the probability the sum is divisible by `x`?

General method:

1. Reduce each die face modulo `x`.
2. Count triples whose residues sum to `0 mod x`.
3. Divide by `6^3 = 216`.

Useful simple cases:

```text
x = 2: probability = 1/2
x = 3: probability = 1/3
```

For `x = 3`, each die has residues `0,1,2` exactly twice, so sums are evenly distributed modulo 3.

### At Least One Run Of 3 Heads In 10 Tosses

Use the complement:

```text
P(at least one HHH) = 1 - P(no HHH)
```

Let `a_n` be the number of length `n` sequences with no `HHH`.

The sequence can end in:

- `T`
- `HT`
- `HHT`

So:

```text
a_n = a_(n-1) + a_(n-2) + a_(n-3)
```

Base cases:

```text
a_0 = 1
a_1 = 2
a_2 = 4
```

This gives:

```text
a_10 = 504
P(at least one HHH) = 1 - 504/1024 = 65/128 ~= 0.508
```

### Expected Tosses To Get HHH

Let:

```text
E0 = expected tosses when current H streak is 0
E1 = expected tosses when current H streak is 1
E2 = expected tosses when current H streak is 2
```

Equations:

```text
E0 = 1 + 0.5 E1 + 0.5 E0
E1 = 1 + 0.5 E2 + 0.5 E0
E2 = 1 + 0.5 * 0 + 0.5 E0
```

Solving gives:

```text
E0 = 14
```

Shortcut for `k` heads in a row with a fair coin:

```text
E = 2^(k+1) - 2
```

For `k = 3`, `E = 14`.

### Max Of Two Uniforms

Let `X, Y ~ U(0,1)`.

For the maximum to be at most `t`, both variables must be at most `t`:

```text
P(max(X,Y) <= t) = P(X <= t, Y <= t) = t^2
```

So the density is:

```text
f(t) = 2t
```

Expected max:

```text
E[max] = integral_0^1 t * 2t dt = 2/3
```

### 999 Fair Coins And 1 Double-Headed Coin

Prior:

```text
P(double-headed) = 1/1000
P(fair) = 999/1000
```

Likelihood of seeing 10 heads:

```text
P(10H | double-headed) = 1
P(10H | fair) = (1/2)^10
```

Bayes:

```text
P(double-headed | 10H)
= (1 * 1/1000) / (1 * 1/1000 + (1/2)^10 * 999/1000)
= 1024 / (1024 + 999)
~= 0.506
```

### Bayes With Fair And Biased Coin

General template:

```text
P(coin A | data) =
P(data | coin A) P(coin A)
/
[P(data | coin A) P(coin A) + P(data | coin B) P(coin B)]
```

Example: one fair coin and one biased coin with `P(H)=p`, equal prior, observe `h` heads and `t` tails.

```text
P(biased | data)
= [p^h (1-p)^t * 0.5]
/
[p^h (1-p)^t * 0.5 + (0.5)^(h+t) * 0.5]
```

### Best Fit Line For Three Points

Points are equally likely:

```text
(0,0), (0,1), (1,1)
```

Fit:

```text
y = alpha + beta x
```

For simple linear regression:

```text
beta = Cov(X,Y) / Var(X)
alpha = E[Y] - beta E[X]
```

Compute:

```text
E[X] = 1/3
E[Y] = 2/3
E[XY] = 1/3
Cov(X,Y) = 1/3 - (1/3)(2/3) = 1/9
Var(X) = 1/3 - (1/3)^2 = 2/9
beta = (1/9)/(2/9) = 1/2
alpha = 2/3 - (1/2)(1/3) = 1/2
```

Answer:

```text
y = 1/2 + x/2
```

### Even Number Of Heads

For `n` tosses of a coin with:

```text
P(H) = p
P(T) = q = 1 - p
```

Probability of an even number of heads:

```text
P(even) = [1 + (q - p)^n] / 2
```

If `p = 1/3` and `q = 2/3`:

```text
P(even) = [1 + (1/3)^n] / 2
```

Sanity check: as `n` gets large, the probability tends to `1/2`.

### First Card Greater Than Second

If rank ties count as ties:

```text
P(same rank) = 3/51 = 1/17
```

By symmetry:

```text
P(first > second) = P(second > first)
```

So:

```text
P(first > second) = (1 - 1/17) / 2 = 8/17
```

If every card has a total order and there are no ties, answer is `1/2`.

### Red / Blue Candy Expected Draws

Bag starts with 3 red and 3 blue. Red is eaten. Blue is put back.

When `r` red remain, probability the next draw is red:

```text
p = r / (r + 3)
```

Expected draws to get the next red:

```text
1/p = (r + 3)/r
```

Sum over `r = 3, 2, 1`:

```text
r = 3: 6/3 = 2
r = 2: 5/2 = 2.5
r = 1: 4/1 = 4
total = 8.5
```

### 55 Or More Heads In 100 Tosses

Let:

```text
X ~ Binomial(100, 0.5)
```

Mean and standard deviation:

```text
mean = np = 50
sd = sqrt(npq) = sqrt(25) = 5
```

Use continuity correction:

```text
P(X >= 55) ~= P(N(50,25) >= 54.5)
z = (54.5 - 50)/5 = 0.9
```

Tail probability:

```text
P(Z >= 0.9) ~= 0.184
```

Answer: about `18%`.

### Create Probability 0.7 From Coin Tosses

If the coin is fair, one practical exact method for `0.7 = 7/10`:

1. Toss 4 times to generate a number from `0` to `15`.
2. If the number is `0` to `9`, accept the block.
3. Return success if the number is `0` to `6`.
4. If the number is `10` to `15`, reject and repeat.

Why it works:

- Accepted numbers `0..9` are equally likely.
- Seven of them are success.
- So success probability is `7/10`.

Expected tosses:

```text
accept probability = 10/16
expected blocks = 1 / (10/16) = 1.6
expected tosses = 4 * 1.6 = 6.4
```

For any target probability `p` with a fair coin:

- Generate fair binary digits for a uniform random number `U` in `[0,1]`.
- Return success if `U < p`.
- For rational probabilities, rejection sampling with enough bits is often easier to explain.

If the coin is biased with unknown bias, first use the von Neumann trick to create fair bits:

```text
HT -> fair 1
TH -> fair 0
HH or TT -> reject and repeat
```

### The e Growth Question

Reported question: many assets give `n` times return after `n` years. Which `n` is best, where `n` can be any positive real?

Compare annualised growth:

```text
growth per year = n^(1/n)
```

Maximise:

```text
f(n) = n^(1/n)
log f(n) = log(n) / n
```

Differentiate:

```text
d/dn [log(n)/n] = (1 - log(n)) / n^2
```

Set to zero:

```text
1 - log(n) = 0
log(n) = 1
n = e
```

Answer:

> "The best annualised return occurs at `n = e`."

## Finance From The Ground Up

### Stocks, Bonds, Options

Stock:

- Ownership claim on a company.
- Payoff comes from price appreciation and dividends.
- Risk is that the company value falls.

Bond:

- Loan to a company or government.
- Pays coupons plus principal if no default.
- When yields rise, existing bond prices fall.

Option:

- Right but not obligation to buy or sell an asset.
- Call: right to buy.
- Put: right to sell.
- Value depends on spot, strike, time, rates, dividends, and volatility.

### Volatility

Volatility is the standard deviation of returns.

If daily volatility is `sigma_daily`:

```text
monthly vol ~= sigma_daily * sqrt(21)
annual vol ~= sigma_daily * sqrt(252)
```

This square-root scaling assumes returns are roughly independent with stable variance.

### Sharpe Ratio

Sharpe measures return per unit of risk:

```text
Sharpe = E[R - R_f] / sd(R)
```

Annualisation:

```text
annual Sharpe ~= daily Sharpe * sqrt(252)
```

Caveat:

- Autocorrelation, fat tails, and changing volatility make this less reliable.

### Liquidity And Order Books

Liquidity means:

> "Can I trade the size I want quickly without moving the price too much?"

Order book basics:

- Bid: best price someone is willing to buy at.
- Ask: best price someone is willing to sell at.
- Spread: `ask - bid`.
- Depth: how much quantity is available at each price level.
- Market order: trades immediately, but pays spread and impact.
- Limit order: controls price, but may not execute.

Good liquidity:

- Tight spread.
- Deep book.
- High volume.
- Low market impact.

### Transaction Costs

Costs include:

- Bid-ask spread.
- Exchange fees/commissions.
- Slippage.
- Market impact.
- Funding or borrow costs.

Interview line:

> "A signal is only useful if it survives realistic costs, capacity, and risk constraints."

### Arbitrage

Arbitrage means:

> "A riskless profit from inconsistent prices."

Simple example:

- Same asset trades at 100 in one venue and 101 in another.
- If you can buy at 100 and sell at 101 instantly with no cost/risk, that is arbitrage.

Reality:

- Costs, latency, funding, shorting constraints, and execution risk often remove the free profit.

### Quote Skewing

Skewing quotes means adjusting bid/ask asymmetrically.

Example:

- If a market maker is long inventory, they may lower both quotes or make the ask more attractive to encourage selling.
- If short inventory, they may skew to encourage buying.

Reason:

- Manage inventory risk.
- Reflect directional view.
- Account for flow or adverse selection.

## Mean-Variance Optimisation

You choose portfolio weights `w`.

Portfolio variance:

```text
Var(portfolio) = w^T Sigma w
```

Where `Sigma` is the covariance matrix of asset returns.

Minimum-variance portfolio:

```text
min_w w^T Sigma w
subject to 1^T w = 1
```

Lagrangian:

```text
L = w^T Sigma w - lambda(1^T w - 1)
```

Differentiate:

```text
dL/dw = 2 Sigma w - lambda 1 = 0
```

Rearrange:

```text
w = (lambda / 2) Sigma^(-1) 1
```

Use `1^T w = 1`:

```text
w = Sigma^(-1) 1 / (1^T Sigma^(-1) 1)
```

If also targeting expected return, add:

```text
mu^T w = target
```

Main caveat:

> "Mean estimates are noisy, so unconstrained mean-variance portfolios can be unstable."

## PCA And Dimensionality Reduction

PCA finds new features called principal components.

Steps:

1. Centre the data.
2. Find directions of largest variance.
3. Project data onto the top directions.

Useful for:

- Reducing correlated features.
- Compression.
- Denoising.
- Visualisation.

Caveat:

- PCA is unsupervised.
- A high-variance direction is not necessarily predictive.
- Components can be harder to interpret.

## Gradient Descent

Goal:

```text
minimise loss(theta)
```

Update:

```text
theta <- theta - learning_rate * gradient
```

Intuition:

- Gradient points uphill.
- Move in the negative gradient direction to go downhill.

Variants:

- Batch gradient descent: use all data each step.
- SGD: use one sample or small batch.
- Mini-batch: common practical compromise.
- Adam: adaptive learning rates, common in neural networks.

Things to mention:

- Learning rate too large can diverge.
- Learning rate too small is slow.
- Features often need scaling.

## Kalman Filter

A Kalman filter estimates a hidden state from noisy observations.

It assumes:

- Linear dynamics.
- Gaussian noise.
- State evolves over time.
- Observations are noisy measurements of the state.

Two repeated steps:

1. Predict the next state using the model.
2. Update the prediction using the new observation.

Finance intuition:

- Smooth noisy price signals.
- Estimate hidden fair value.
- Estimate time-varying hedge ratio.
- Track latent trend or volatility state.

Good line:

> "It is Bayesian updating for a linear-Gaussian time-series model."

## Data Exploration And Sklearn Drill

Be able to describe this workflow:

1. Load data.
2. Inspect shape, columns, types, missing values.
3. Plot distributions and target relationships.
4. Create train/test split.
5. Fit a simple baseline.
6. Fit a stronger model only if justified.
7. Evaluate on unseen data.
8. Check leakage and overfitting.

Minimal code:

```python
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.linear_model import Ridge
from sklearn.metrics import mean_squared_error, r2_score

df = pd.read_csv("data.csv")
print(df.head())
print(df.info())
print(df.describe())
print(df.isna().sum())

X = df.drop(columns=["target"])
y = df["target"]

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=0
)

model = Ridge(alpha=1.0)
model.fit(X_train, y_train)
pred = model.predict(X_test)

rmse = mean_squared_error(y_test, pred, squared=False)
r2 = r2_score(y_test, pred)

print(rmse, r2)
plt.scatter(y_test, pred)
plt.xlabel("Actual")
plt.ylabel("Predicted")
plt.show()
```

Pandas vs polars:

- Pandas is the default interview answer.
- Polars is faster/lazier for larger dataframes.
- In an interview, explain the data workflow more than library trivia.

## Coding Maintenance

These were mentioned in reports or adjacent notes. Keep them warm, but maths/stats is the main focus.

### Patterns

- Binary search debugging.
- Priority queue / heap.
- Difference array.
- Prefix sums.
- Frequency sorting.
- Two-pointer pair counting.
- Sliding window minimum length.
- DP: Fibonacci, LIS, palindromes.

### Specific Problem Templates

Sort array by frequency:

- Count with hashmap.
- Sort by frequency, then tie rule.
- Time: `O(n log n)` if sorting distinct values.

Pairs with difference `k`:

- Use set/hashmap.
- For each `x`, look for `x + k`.
- Handle `k = 0` separately if counting duplicates.

Minimum subarray/window with at least `k` of an element:

- Sliding window with frequency map.
- Expand right.
- When some count reaches `k`, shrink left while valid.

Elements smaller than query:

- Sort first array.
- For each query, binary search count of elements `< query`.
- Time: `O(n log n + m log n)`.

Difference array:

- For range updates, mark `diff[l] += val`, `diff[r+1] -= val`.
- Prefix sum reconstructs final values.

Priority queue:

- Python `heapq` is min-heap.
- Use negative values for max-heap.

## Programming Concepts

These appeared in one reported later round. Keep answers short.

Call by value:

- Function receives a copy.
- Changes inside do not affect original variable.

Call by reference:

- Function receives access/reference to original object.
- Changes can affect the original.

Operator overloading:

- Define custom behaviour for operators like `+`, `==`, `<` on user-defined classes.

Virtual function:

- In C++, allows runtime polymorphism.
- If called through a base pointer/reference, the derived implementation can run.

Pure virtual function:

- Function declared with `= 0`.
- Makes the class abstract.
- Derived class must implement it to be instantiable.

Linux basics:

- `ls`, `cd`, `pwd`, `grep`, `find`, `cat`, `less`, `head`, `tail`.
- `chmod` changes permissions.
- `ps`, `top`, `kill` inspect/control processes.
- Pipes pass output from one command to another: `cmd1 | cmd2`.

## CV And Thesis Answers

### Thesis / Pop-Cosmos

Short answer:

> "My thesis tests whether simulated galaxy populations match telescope observations. The transferable skill is model validation: compare predicted distributions to real data, diagnose where assumptions fail, and handle uncertainty carefully."

Useful details:

- Pop-Cosmos gives simulated galaxy properties.
- FSPS turns stellar population assumptions into predicted light.
- Redshift shifts emitted light into longer observed wavelengths.
- Current issue: predictions are more reasonable at 250 microns but overpredict bright sources at 350 and 500 microns.
- You are testing alternative or hybrid SED assumptions.

Quant link:

> "In finance, the objects are different, but the discipline is similar: build a model, test it on data, look for misspecification, and avoid fooling yourself."

### COVID Forecasting

Short answer:

> "I used UK COVID and mobility data to forecast deaths or hospital demand over future horizons. The hard parts were lagged features, time-aware validation, leakage avoidance, and regime change."

Quant link:

> "It is similar to financial forecasting because relationships can change over time, so validation over time matters."

### Higgs Boson Detection

Short answer:

> "I classified simulated particle events as signal or background using tabular physics features and tree-based models. The key lesson was that the classifier was useful only if it improved the downstream likelihood fit."

Quant link:

> "That maps to quant work because a signal should be judged by the final objective, not just an intermediate metric like AUC."

### A4 1D CNN

Short answer:

> "I trained a 1D CNN in PyTorch to classify detector waveforms. A CNN made sense because local time-shape patterns mattered."

Learning:

> "More complexity was not automatically better. The baseline CNN was already strong, so evaluation mattered more than adding layers."

## Video Recommendations

Use these to patch weak spots, not as a binge list.

Regression / PCA / metrics:

- StatQuest video index for Linear Regression, Ridge, Lasso, PCA, ROC/AUC: https://statquest.org/video-index/

Probability:

- 3Blue1Brown Bayes theorem: https://www.3blue1brown.com/lessons/bayes-theorem/
- Harvard Stat 110 homepage and YouTube links: https://stat110.hsites.harvard.edu/

Finance basics:

- Khan Academy Finance and Capital Markets: https://www.khanacademy.org/economics-finance-domain/core-finance
- MIT OCW finance/portfolio material: https://ocw.mit.edu/

Python ML:

- scikit-learn examples: https://scikit-learn.org/stable/auto_examples/index.html

Kalman filter:

- QuantStart Kalman filter intro: https://www.quantstart.com/articles/State-Space-Models-and-the-Kalman-Filter/

## Final Interview Checklist

Before the interview, make sure you can explain:

- OLS objective and derivation.
- Ridge vs lasso.
- What multicollinearity does.
- Why inference assumptions differ from prediction validation.
- Variance of a sum with covariance terms.
- Bayes theorem with coin examples.
- Expected value by states, especially 3 heads in a row.
- Normal approximation for binomial.
- Liquidity, volatility, Sharpe, order book, transaction costs.
- Your thesis in 60 seconds.
- One project where model validation mattered.
- One example of avoiding leakage or overfitting.

## Questions To Ask Them

- What does success look like for a Desk Quant Analyst in the first six months?
- How much of the work is live desk support versus research tooling?
- What kinds of statistical or modelling problems do DQAs commonly see?
- Which technical skill would you advise me to sharpen most before joining?
- How do researchers, traders, and DQAs collaborate day to day?
