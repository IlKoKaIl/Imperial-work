# Squarepoint Next Rounds Maths / Stats Prep

Current context: today is Sunday 2026-09-13 and the interview is Tuesday 2026-09-15.

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
| Ridge, lasso, shrinking$\beta$                          | `Ridge Regression`, `Lasso Regression`              |
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

You have inputs $X$ and an output $y$.

The model says:

$$
\hat{y} = \beta_0 + \beta_1 x_1 + \beta_2 x_2 + \cdots + \beta_p x_p
$$

In matrix form:

$$
\hat{y} = X\beta
$$

Each row of $X$ is one observation. Each column is one feature. $\beta$ contains the coefficients.

The error/residual is:

$$
e = y - \hat{y} = y - X\beta
$$

## OLS Objective

OLS means ordinary least squares.

It chooses $\beta$ to minimise the sum of squared residuals:

$$
\min_{\beta} \|y - X\beta\|^2
$$

Why square errors?

- Big errors are punished more.
- The maths is smooth and gives a closed form.
- If noise is Gaussian, OLS is also the maximum likelihood estimator.

### OLS Derivation

Start:

$$
L(\beta) = \|y - X\beta\|^2
          = (y - X\beta)^T(y - X\beta)
$$

Expand:

$$
L(\beta) = y^T y - 2\beta^T X^T y + \beta^T X^T X\beta
$$

Differentiate with respect to $\beta$:

$$
\frac{\partial L}{\partial \beta}
= -2X^T y + 2X^T X\beta
$$

Set the gradient to zero:

$$
-2X^T y + 2X^T X\beta = 0
$$

$$
X^T X\beta = X^T y
$$

If $X^T X$ is invertible:

$$
\hat{\beta} = (X^T X)^{-1}X^T y
$$

Say this aloud:

> "OLS sets the gradient of squared error to zero. This gives the normal equations. If the feature covariance matrix is invertible, I can solve for $\beta$ in closed form."

### Ridge Regression

Ridge adds a penalty for large coefficients:

$$
\min_{\beta} \|y - X\beta\|^2 + \lambda \|\beta\|_2^2
$$

The solution is:

$$
\hat{\beta}_{\text{ridge}} = (X^T X + \lambda I)^{-1}X^T y
$$

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

$$
\min_{\beta} \|y - X\beta\|^2 + \lambda \|\beta\|_1
$$

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

$$
x_2 \approx x_1
$$

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
Can I interpret coefficients and confidence intervals?
```

Prediction asks:

```text
Does the model perform well on new data?
```

For inference, the classical assumptions matter more:

- Correct linear specification.
- Exogeneity: $\mathbb{E}[\varepsilon \mid X] = 0$.
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

$$
R^2 = 1 - \frac{\text{SSE}}{\text{SST}}
$$

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

$$
\operatorname{Var}(X) = \mathbb{E}[X^2] - \mathbb{E}[X]^2
$$

Covariance measures how two variables move together:

$$
\operatorname{Cov}(X,Y) = \mathbb{E}[XY] - \mathbb{E}[X]\mathbb{E}[Y]
$$

For a sum of three random variables:

$$
\operatorname{Var}(X+Y+Z)
= \operatorname{Var}(X) + \operatorname{Var}(Y) + \operatorname{Var}(Z)
+ 2\operatorname{Cov}(X,Y)
+ 2\operatorname{Cov}(X,Z)
+ 2\operatorname{Cov}(Y,Z)
$$

If independent, covariance terms are zero.

### Normal Distribution

Know:

- Symmetric bell-shaped distribution.
- Defined by mean and variance.
- Sums/averages often become approximately normal by the CLT.
- Standard normal has mean `0` and variance `1`.

Standardisation:

$$
Z = \frac{X - \mu}{\sigma}
$$

### CLT

The central limit theorem says averages of many independent, not-too-heavy-tailed variables become approximately normal.

Important:

- The original data does not need to be normal.
- Independence and finite variance matter.
- It justifies normal approximations for sums, like coin toss counts.

### Chi-Squared Distribution

If:

$$
Z_1, \ldots, Z_k \stackrel{\text{iid}}{\sim} N(0,1)
$$

Then:

$$
Z_1^2 + \cdots + Z_k^2 \sim \chi^2_k
$$

Uses:

- Variance inference for normal data.
- Goodness-of-fit tests.
- Chi-squared tests of independence in contingency tables.

Mean and variance:

$$
\mathbb{E}[\chi^2_k] = k,
\qquad
\operatorname{Var}(\chi^2_k) = 2k
$$

## Worked Probability Questions From The Notes

### Dice Sum Divisible By X

Question: roll 3 fair dice. What is the probability the sum is divisible by `x`?

General method:

1. Reduce each die face modulo `x`.
2. Count triples whose residues sum to `0 mod x`.
3. Divide by `6^3 = 216`.

Useful simple cases:

$$
x=2: \quad P(\text{sum divisible by }2)=\frac{1}{2}
$$

$$
x=3: \quad P(\text{sum divisible by }3)=\frac{1}{3}
$$

For `x = 3`, each die has residues `0,1,2` exactly twice, so sums are evenly distributed modulo 3.

### At Least One Run Of 3 Heads In 10 Tosses

Use the complement:

$$
P(\text{at least one HHH}) = 1 - P(\text{no HHH})
$$

Let `a_n` be the number of length `n` sequences with no `HHH`.

The sequence can end in:

- `T`
- `HT`
- `HHT`

So:

$$
a_n = a_{n-1} + a_{n-2} + a_{n-3}
$$

Base cases:

$$
a_0 = 1,\qquad a_1 = 2,\qquad a_2 = 4
$$

This gives:

$$
a_{10}=504
$$

$$
P(\text{at least one HHH})
= 1 - \frac{504}{1024}
= \frac{65}{128}
\approx 0.508
$$

### Expected Tosses To Get HHH

Let:

$E_0$ = expected tosses when the current H streak is 0.

$E_1$ = expected tosses when the current H streak is 1.

$E_2$ = expected tosses when the current H streak is 2.

Equations:

$$
E_0 = 1 + \frac{1}{2}E_1 + \frac{1}{2}E_0
$$

$$
E_1 = 1 + \frac{1}{2}E_2 + \frac{1}{2}E_0
$$

$$
E_2 = 1 + \frac{1}{2}\cdot 0 + \frac{1}{2}E_0
$$

Solving gives:

$$
E_0 = 14
$$

Shortcut for `k` heads in a row with a fair coin:

$$
E = 2^{k+1} - 2
$$

For $k=3$, $E=14$.

### Max Of Two Uniforms

Let $X,Y \sim U(0,1)$.

For the maximum to be at most `t`, both variables must be at most `t`:

$$
P(\max(X,Y) \le t)
= P(X \le t, Y \le t)
= t^2
$$

So the density is:

$$
f(t) = 2t
$$

Expected max:

$$
\mathbb{E}[\max(X,Y)]
= \int_0^1 t \cdot 2t \, dt
= \frac{2}{3}
$$

### 999 Fair Coins And 1 Double-Headed Coin

Prior:

$$
P(D)=\frac{1}{1000},
\qquad
P(F)=\frac{999}{1000}
$$

Likelihood of seeing 10 heads:

$$
P(10H \mid D)=1,
\qquad
P(10H \mid F)=\left(\frac{1}{2}\right)^{10}
$$

Bayes:

$$
P(D \mid 10H)
= \frac{1 \cdot \frac{1}{1000}}
{1 \cdot \frac{1}{1000}
+ \left(\frac{1}{2}\right)^{10}\frac{999}{1000}}
= \frac{1024}{1024+999}
\approx 0.506
$$

### Bayes With Fair And Biased Coin

General template:

$$
P(A \mid \text{data})
=
\frac{P(\text{data}\mid A)P(A)}
{P(\text{data}\mid A)P(A)+P(\text{data}\mid B)P(B)}
$$

Example: one fair coin and one biased coin with $P(H)=p$, equal prior, observe $h$ heads and $t$ tails.

$$
P(\text{biased}\mid \text{data})
=
\frac{p^h(1-p)^t \cdot \frac{1}{2}}
{p^h(1-p)^t \cdot \frac{1}{2}
+ \left(\frac{1}{2}\right)^{h+t}\cdot \frac{1}{2}}
$$

### Best Fit Line For Three Points

Points are equally likely:

$$
(0,0),\quad (0,1),\quad (1,1)
$$

Fit:

$$
y = \alpha + \beta x
$$

For simple linear regression:

$$
\beta = \frac{\operatorname{Cov}(X,Y)}{\operatorname{Var}(X)}
$$

$$
\alpha = \mathbb{E}[Y] - \beta \mathbb{E}[X]
$$

Compute:

$$
\mathbb{E}[X] = \frac{1}{3},
\qquad
\mathbb{E}[Y] = \frac{2}{3},
\qquad
\mathbb{E}[XY] = \frac{1}{3}
$$

$$
\operatorname{Cov}(X,Y)
= \frac{1}{3} - \left(\frac{1}{3}\right)\left(\frac{2}{3}\right)
= \frac{1}{9}
$$

$$
\operatorname{Var}(X)
= \frac{1}{3} - \left(\frac{1}{3}\right)^2
= \frac{2}{9}
$$

$$
\beta = \frac{1/9}{2/9} = \frac{1}{2},
\qquad
\alpha = \frac{2}{3} - \frac{1}{2}\cdot \frac{1}{3}
= \frac{1}{2}
$$

Answer:

$$
y = \frac{1}{2} + \frac{x}{2}
$$

### Even Number Of Heads

For `n` tosses of a coin with:

$$
P(H)=p,
\qquad
P(T)=q=1-p
$$

Probability of an even number of heads:

$$
P(\text{even}) = \frac{1 + (q-p)^n}{2}
$$

If `p = 1/3` and `q = 2/3`:

$$
P(\text{even}) = \frac{1 + \left(\frac{1}{3}\right)^n}{2}
$$

Sanity check: as `n` gets large, the probability tends to `1/2`.

### First Card Greater Than Second

If rank ties count as ties:

$$
P(\text{same rank}) = \frac{3}{51} = \frac{1}{17}
$$

By symmetry:

$$
P(\text{first}>\text{second})
= P(\text{second}>\text{first})
$$

So:

$$
P(\text{first}>\text{second})
= \frac{1 - 1/17}{2}
= \frac{8}{17}
$$

If every card has a total order and there are no ties, answer is `1/2`.

### Red / Blue Candy Expected Draws

Bag starts with 3 red and 3 blue. Red is eaten. Blue is put back.

When `r` red remain, probability the next draw is red:

$$
p = \frac{r}{r+3}
$$

Expected draws to get the next red:

$$
\mathbb{E}[\text{draws to next red}]
= \frac{1}{p}
= \frac{r+3}{r}
$$

Sum over `r = 3, 2, 1`:

$$
r=3:\frac{6}{3}=2,
\qquad
r=2:\frac{5}{2}=2.5,
\qquad
r=1:\frac{4}{1}=4
$$

$$
\text{total}=2+2.5+4=8.5
$$

### 55 Or More Heads In 100 Tosses

Let:

$$
X \sim \operatorname{Binomial}(100, 0.5)
$$

Mean and standard deviation:

$$
\mu = np = 50
$$

$$
\sigma = \sqrt{npq} = \sqrt{25} = 5
$$

Use continuity correction:

$$
P(X \ge 55)
\approx P(N(50,25) \ge 54.5)
$$

$$
z = \frac{54.5-50}{5}=0.9
$$

Tail probability:

$$
P(Z \ge 0.9) \approx 0.184
$$

Answer: about `18%`.

### Create Probability 0.7 From Coin Tosses

If the coin is fair, one practical exact method for $0.7 = \frac{7}{10}$:

1. Toss 4 times to generate a number from `0` to `15`.
2. If the number is `0` to `9`, accept the block.
3. Return success if the number is `0` to `6`.
4. If the number is `10` to `15`, reject and repeat.

Why it works:

- Accepted numbers `0..9` are equally likely.
- Seven of them are success.
- So success probability is `7/10`.

Expected tosses:

$$
P(\text{accept})=\frac{10}{16}
$$

$$
\mathbb{E}[\text{blocks}]
= \frac{1}{10/16}
= 1.6
$$

$$
\mathbb{E}[\text{tosses}]
= 4 \times 1.6
= 6.4
$$

For any target probability $p$ with a fair coin:

- Generate fair binary digits for a uniform random number $U \in [0,1]$.
- Return success if $U < p$.
- For rational probabilities, rejection sampling with enough bits is often easier to explain.

If the coin is biased with unknown bias, first use the von Neumann trick to create fair bits:

$$
HT \rightarrow 1,
\qquad
TH \rightarrow 0,
\qquad
HH \text{ or } TT \rightarrow \text{reject}
$$

### The e Growth Question

Reported question: many assets give $n$ times return after $n$ years. Which $n$ is best, where $n$ can be any positive real?

Compare annualised growth:

$$
\text{growth per year} = n^{1/n}
$$

Maximise:

$$
f(n)=n^{1/n}
$$

$$
\log f(n)=\frac{\log n}{n}
$$

Differentiate:

$$
\frac{d}{dn}\left(\frac{\log n}{n}\right)
= \frac{1-\log n}{n^2}
$$

Set to zero:

$$
1-\log n=0
\quad\Rightarrow\quad
\log n=1
\quad\Rightarrow\quad
n=e
$$

Answer:

> "The best annualised return occurs at $n=e$."

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

If daily volatility is $\sigma_{\text{daily}}$:

$$
\sigma_{\text{monthly}}
\approx \sigma_{\text{daily}}\sqrt{21}
$$

$$
\sigma_{\text{annual}}
\approx \sigma_{\text{daily}}\sqrt{252}
$$

This square-root scaling assumes returns are roughly independent with stable variance.

### Sharpe Ratio

Sharpe measures return per unit of risk:

$$
\text{Sharpe}
= \frac{\mathbb{E}[R - R_f]}{\sigma_R}
$$

Annualisation:

$$
\text{Sharpe}_{\text{annual}}
\approx
\text{Sharpe}_{\text{daily}}\sqrt{252}
$$

Caveat:

- Autocorrelation, fat tails, and changing volatility make this less reliable.

### Liquidity And Order Books

Liquidity means:

> "Can I trade the size I want quickly without moving the price too much?"

Order book basics:

- Bid: best price someone is willing to buy at.
- Ask: best price someone is willing to sell at.
- Spread: $\text{ask} - \text{bid}$.
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

You choose portfolio weights $w$.

Portfolio variance:

$$
\operatorname{Var}(\text{portfolio}) = w^T \Sigma w
$$

Where $\Sigma$ is the covariance matrix of asset returns.

Minimum-variance portfolio:

$$
\min_w \; w^T \Sigma w
$$

subject to:

$$
\mathbf{1}^T w = 1
$$

Lagrangian:

$$
\mathcal{L}
= w^T \Sigma w - \lambda(\mathbf{1}^T w - 1)
$$

Differentiate:

$$
\frac{\partial \mathcal{L}}{\partial w}
= 2\Sigma w - \lambda \mathbf{1}
= 0
$$

Rearrange:

$$
w = \frac{\lambda}{2}\Sigma^{-1}\mathbf{1}
$$

Use $\mathbf{1}^T w = 1$:

$$
w =
\frac{\Sigma^{-1}\mathbf{1}}
{\mathbf{1}^T\Sigma^{-1}\mathbf{1}}
$$

If also targeting expected return, add:

$$
\mu^T w = \text{target}
$$

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

$$
\min_{\theta} L(\theta)
$$

Update:

$$
\theta \leftarrow \theta - \eta \nabla L(\theta)
$$

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
