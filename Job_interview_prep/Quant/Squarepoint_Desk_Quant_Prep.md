# Squarepoint Desk Quant Analyst Prep

Use this as the main plan. The other files are references.

---

## 1. What This Role Probably Is

**Simple answer**

> "Desk Quant Analyst is a hybrid quant/coding role close to researchers and traders. It is not pure software engineering and not pure theory. You need to be useful with data, code, stats, debugging, and live trading workflows."

Likely work:

- maintain and improve strategy code/config
- work with large datasets
- monitor live and historical trading behaviour
- support Quant Researchers and Traders
- check data/processes before market open
- debug weird issues quickly

What they probably test:

- coding fluency
- probability/statistics
- regression/ML basics
- clean reasoning under pressure
- resume/project depth
- some finance intuition, but likely not deep derivatives pricing

---

## 2. What Squarepoint Does

**Interview answer**

> "Squarepoint is a global quantitative investment manager. They use systematic, data-driven trading strategies across markets, with a strong research and technology platform."

Key company points:

- privately held
- founded from nQuant / Lehman / Barclays history
- independent since December 2014
- global offices
- systematic quant investment manager
- diversified across asset classes, trading frequencies, and global markets
- heavy use of backtests on historical market data
- technology is central because research connects directly to trading
- they execute at large scale, including millions of trades per day

Good phrase:

> "Squarepoint seems like a place where research, engineering, and trading are tightly connected."

Sources:

- [Squarepoint About](https://www.squarepoint-capital.com/about)
- [Squarepoint Early Careers](https://www.squarepoint-capital.com/early-careers)
- [Squarepoint Philosophy](https://www.squarepoint-capital.com/philosophy)
- [Squarepoint Open Opportunities](https://www.squarepoint-capital.com/open-opportunities)

---

## 3. How To Position Yourself

### My 30 Second Pitch

> "I am an Imperial physics student with applied ML, statistics, and coding experience. I have worked on forecasting, classification, boosted trees, CNNs, likelihood fits, and model validation. What attracts me to Desk Quant Analyst is the mix of quantitative reasoning and practical implementation close to trading."

### Why Squarepoint

> "I like that Squarepoint is systematic and scientific, but also very practical. The role seems close to researchers and traders, so the work is not just building models in isolation. It is about making data, code, and signals work reliably."

### Why Desk Quant Analyst

> "It fits me because I like the applied middle ground: understanding the model, writing/debugging code, handling data, and checking whether predictions work in the real world."

### Main Story To Tell

- Physics background = mathematical modelling under uncertainty.
- ML projects = applied model building and evaluation.
- Thesis = simulation vs real data, diagnosing mismatch.
- Internship = professional reliability and communication.
- IMC Prosperity = markets, strategy testing, risk, iteration.

---

## 4. Priority Order

Do not try to read every book.

### Must Do

1. LeetCode / NeetCode coding patterns.
2. Probability basics.
3. Statistics / inference.
4. Regression and ML basics.
5. Resume stories.

### Nice But Secondary

- system design videos
- finance brainteasers
- deeper ESL/Bishop reading
- advanced C++ if not required

### System Design Reality Check

**Simple**

> "For Desk Quant, system design is useful background, but coding/stats matter more."

Watch only these if time:

- URL shortener = hashing, storage, scaling basics
- rate limiter = queues, tokens, distributed limits
- Dropbox = file sync, metadata, consistency
- TicketMaster = concurrency, reservations, race conditions

What to learn from them:

- define requirements
- handle scale
- think about latency
- think about failure modes
- state tradeoffs clearly

Do not spend all weekend becoming a backend architect.

---

## 5. Time Plan Around Internship + Thesis

Assumption:

- internship: Mon-Fri 9-6
- Tuesday off
- thesis still needs time
- interview timing unknown / could be soon

### Weekday Default

Do this after work. Keep it tight.

1. 45 min coding
2. 30 min probability/statistics
3. 15 min review mistakes
4. 10 min one resume answer aloud

Total: about 1.5 hours.

### Tuesday Off

Use Tuesday as the heavy day.

1. 2 coding problems
2. 1 probability set
3. 1 statistics derivation
4. 1 mock interview block
5. 2-3 hours thesis

Do not spend the whole day passively reading.

### If Interview Is Tomorrow

Only do this:

1. Two Sum / Group Anagrams / Binary Search / Valid Parentheses
2. Bayes theorem + conditional probability
3. expectation / variance / covariance
4. MLE for Bernoulli, Gaussian mean, Poisson
5. explain OLS, ridge, lasso, overfitting
6. prepare "why Squarepoint" and 2 project stories

Sleep beats one extra chapter.

---

## 6. Coding Plan

### Interview Coding Style

Say this structure out loud:

1. "Let me restate the problem."
2. "A brute force way is..."
3. "We can improve using..."
4. "Time complexity is..."
5. "Let me test an edge case."

### First Problems

Do these first:

- Contains Duplicate
- Valid Anagram
- Two Sum
- Group Anagrams
- Top K Frequent Elements
- Product of Array Except Self
- Valid Palindrome
- Two Sum II
- Best Time to Buy and Sell Stock
- Longest Substring Without Repeating Characters
- Binary Search
- Search in Rotated Sorted Array
- Valid Parentheses
- Min Stack
- Reverse Linked List
- Merge Two Sorted Lists
- Invert Binary Tree
- Maximum Depth of Binary Tree
- Binary Tree Level Order Traversal
- Kth Largest Element

### Patterns To Know

**Hash map**

> "Use a dictionary when I need fast lookup or counting."

**Two pointers**

> "Use two indices moving through the data to avoid nested loops."

**Sliding window**

> "Maintain a valid window and update it as it moves."

**Binary search**

> "Use when the answer space or array is ordered."

**Stack**

> "Use when the most recent unresolved item matters."

**Heap**

> "Use when I repeatedly need the min/max or top K."

**BFS/DFS**

> "Use for tree/graph traversal."

**DP**

> "Use when the problem has overlapping subproblems and optimal substructure."

---

## 7. Probability Must-Knows

### Conditional Probability

> "Conditional probability is the probability of A given B has happened."

Formula:

$$
P(A|B)=\frac{P(A \cap B)}{P(B)}
$$

### Bayes Theorem

> "Bayes updates belief after seeing evidence."

Formula:

$$
P(A|B)=\frac{P(B|A)P(A)}{P(B)}
$$

### Expectation

> "Expectation is the long-run average value."

Linearity:

$$
E[X+Y]=E[X]+E[Y]
$$

Even if not independent.

### Variance

> "Variance measures spread around the mean."

Formula:

$$
Var(X)=E[X^2]-E[X]^2
$$

### Covariance / Correlation

> "Covariance measures whether two variables move together. Correlation is normalized covariance."

Formula:

$$
Corr(X,Y)=\frac{Cov(X,Y)}{\sigma_X\sigma_Y}
$$

### Joint Normal Conditional

If:

$$
X,Y \sim N(0,1), Corr(X,Y)=\rho
$$

Then:

$$
X|Y=y \sim N(\rho y, 1-\rho^2)
$$

Interview line:

> "For jointly normal variables, the conditional expectation is linear in the observed variable, and uncertainty shrinks by the unexplained variance."

### Common Distributions

**Bernoulli**

> "One yes/no trial."

**Binomial**

> "Number of successes in n independent Bernoulli trials."

**Poisson**

> "Count of events in a fixed interval."

**Exponential**

> "Waiting time between Poisson events."

**Normal**

> "Continuous bell-shaped distribution, common through CLT."

---

## 8. Stats / ML Must-Knows

### MLE

> "MLE chooses the parameter that makes the observed data most likely."

Workflow:

1. write likelihood
2. log it
3. differentiate
4. set to zero
5. check if maximum

### MAP

> "MAP is like MLE but includes a prior."

Formula idea:

$$
posterior \propto likelihood \times prior
$$

### OLS

> "OLS fits a linear regression by minimizing squared errors."

Formula:

$$
\hat{\beta}=(X^TX)^{-1}X^Ty
$$

### Ridge

> "Ridge regression is linear regression with an L2 penalty. It shrinks coefficients and helps with overfitting/multicollinearity."

### Lasso

> "Lasso uses an L1 penalty and can push some coefficients exactly to zero."

### Overfitting

> "Overfitting is when a model fits training noise but fails on unseen data."

Avoid with:

- train/test split
- cross-validation
- regularization
- simpler model
- more data
- leakage checks

### Cross-Validation

> "Cross-validation tests performance across multiple train/validation splits."

Why:

- less dependent on one lucky split
- helps tune hyperparameters

### AUC

> "AUC measures how well a classifier ranks positives above negatives across thresholds."

Use when:

- threshold not fixed yet
- classes may be imbalanced

---

## 9. Finance / Quant Basics

### Systematic Trading

> "Systematic trading means rules/models generate trading decisions, rather than a human making each trade manually."

### Backtest

> "A backtest tests a strategy on historical data to estimate how it would have performed."

Main risk:

> "A good backtest can still be fake-good if there is overfitting, leakage, transaction costs ignored, or regime change."

### Alpha

> "Alpha is predictive signal or excess return not explained by common risk factors."

Simple:

- find pattern
- test it
- control risk/costs
- deploy carefully

### Sharpe Ratio

> "Sharpe ratio is return per unit of risk."

Formula:

$$
Sharpe = \frac{E[R - R_f]}{\sigma_R}
$$

Simple:

> "Higher Sharpe means smoother return for the risk taken."

### Drawdown

> "Drawdown is the fall from a peak to a trough."

Why it matters:

- a strategy can have good average return but painful losses

### Transaction Costs

> "Trading is not free. Spreads, fees, slippage, and market impact can destroy a backtest."

Good line:

> "A signal is only useful if it survives costs and risk controls."

---

## 10. Resume Stories To Prepare

### Story 1: COVID Forecasting

> "I built forecasting models on UK COVID and mobility data. The hard part was time structure: avoiding leakage, using lags, and evaluating different forecast horizons."

What it shows:

- time-series thinking
- model comparison
- messy real data
- regime changes

### Story 2: Higgs / Boosted Trees

> "I classified particle events as signal or background using tabular physics features and tree-based models like Random Forest, Gradient Boosting, and XGBoost."

What it shows:

- classification
- tabular ML
- ROC/AUC
- optimizing final objective, not just accuracy

### Story 3: Thesis / Pop-Cosmos

> "I compare simulated galaxy predictions to telescope observations, then diagnose where model assumptions fail."

What it shows:

- scientific modelling
- uncertainty
- prediction vs reality
- validation mindset

### Story 4: IMC Prosperity

> "I worked on a trading-style competition where the goal was to design strategies, test them, and manage risk under uncertainty."

What it shows:

- markets interest
- fast iteration
- risk awareness
- not overfitting to a small sample

---

## 11. Behavioural Answers

### Why Quant?

> "I like problems where maths, data, and code directly affect decisions. Quant feels like a natural fit because it rewards clear thinking, testing ideas, and being honest about uncertainty."

### Why Squarepoint?

> "Squarepoint appeals to me because it is systematic, research-led, and technology-heavy. I like that the work connects research, data, code, and trading rather than sitting in one silo."

### Why Desk Quant Analyst?

> "I like that it seems hands-on and close to the desk. I would enjoy supporting researchers and traders, understanding strategy behaviour, debugging issues, and gradually building stronger quant intuition."

### Weakness / Gap

> "I am still building my finance-specific knowledge, but I have a strong physics/statistics base and I am actively preparing coding, probability, and market basics."

### Good Questions To Ask

- "How does the Desk Quant Analyst role differ from Junior Quant Researcher day to day?"
- "What kinds of problems would a DQA own in the first six months?"
- "How close is the role to live trading support versus research tooling?"
- "What makes someone successful in this role?"
- "Which technical skills should I sharpen most before starting?"

---

## 12. Practical Weekly Schedule

### Monday

- 45 min LeetCode arrays/hash maps
- 30 min probability
- 10 min error log

### Tuesday Off

- 2 LeetCode mediums
- 1 stats derivation
- 1 probability puzzle
- 1 resume mock
- thesis block

### Wednesday

- 45 min binary search / stack
- 30 min MLE/MAP
- 10 min error log

### Thursday

- 45 min trees/BFS/DFS
- 30 min regression/overfitting
- 10 min project answer aloud

### Friday

- 1 easy + 1 medium coding
- light probability recap

### Weekend

- one 90 min coding block
- one 60 min stats block
- one 30 min behavioural/project block
- one system design video max

---

## 13. What To Do Today

If you only have one evening:

1. Read sections 1-3.
2. Do `Two Sum`, `Valid Anagram`, `Binary Search`.
3. Review conditional probability and Bayes.
4. Review MLE workflow.
5. Practice "why Squarepoint" once aloud.

---

## 14. Keep / Update These Files

- `README.md`: folder map.
- `study-plan.md`: general quant plan.
- `interview-stats-cheatsheet.md`: stats answer bank.
- `coding-tracker.md`: mark LeetCode status.
- `Squarepoint_Desk_Quant_Prep.md`: main Squarepoint plan.

