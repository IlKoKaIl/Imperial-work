# Squarepoint Round 2 Runbook - Interview on Tuesday 2026-09-01

Use this file as the daily plan. The other files are reference material.

You do not need to do all Blind 75. With job + thesis, the best plan is a focused 24-30 problem set, weighted toward DP, arrays, sliding window, binary search, and heap, with timed redoes.

## What The Signal Says

Recruiter notes:

- HackerRank pair coding.
- Coding focused.
- Likely 2-3 LeetCode medium style questions.
- Topics: data structures, two pointers, sliding window, max heap, DP, Fibonacci-style recurrence, binary search, tree search.
- Speak while working, clarify before coding, state time and space complexity.

Public interview signal:

- Glassdoor Desk Quant reports mention DSA, dynamic programming, two coding questions, binary search, and Python/C++ concept questions.
- Wall Street Oasis reports mention HackerRank, DP/probability, and medium LeetCode style coding.
- DevInterview and CodeJeet company aggregations both show Squarepoint leaning heavily toward arrays and DP, with most tracked questions around medium difficulty.
- Role descriptions emphasise programming, large datasets, live/historical monitoring, trading tools, and working with researchers/traders.

### Saturday 2026-08-29 - Highest Yield Catch-Up

- [X] Search in Rotated Sorted Array.
- [X] Longest Increasing Subsequence.
- [X] Kth Largest Element in an Array.
- [ ] 10 minutes behavioural aloud.

### Sunday 2026-08-30 - Traversal + Remaining DP

- [X] Binary Tree Level Order Traversal.
- [X] Validate Binary Search Tree.
- [X] Course Schedule.
- [X] Jump Game.
- [X] Minimum Path Sum.
- [ ] Redo one shaky DP problem, preferably Coin Change or LIS.

### Tuesday 2026-09-01 - Interview Day

1. 20-minute warmup only: Two Sum or Valid Parentheses.
2. Review DP template.
3. Review binary search template.
4. Review CV bullets and questions to ask.
5. No new hard problem.

## The Short Problem Set

| Topic                         | Problems                                                                                                                                         |
| ----------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------ |
| Arrays / hash maps            | Two Sum, Group Anagrams, Top K Frequent Elements, Product of Array Except Self                                                                   |
| Two pointers / sliding window | Container With Most Water, Longest Substring Without Repeating Characters, Longest Repeating Character Replacement, Subarray Product Less Than K |
| Binary search                 | Binary Search, Search in Rotated Sorted Array, Find Minimum in Rotated Sorted Array, Koko Eating Bananas                                         |
| Heap                          | Kth Largest Element in an Array, Last Stone Weight or reorganise around a max heap variant                                                       |
| Trees / graphs                | Binary Tree Level Order Traversal, Validate Binary Search Tree, Number of Islands, Course Schedule                                               |
| DP                            | Climbing Stairs, Min Cost Climbing Stairs, House Robber, Coin Change, Longest Increasing Subsequence, Decode Ways, Minimum Path Sum, Jump Game   |

### Mon 2026-08-24 - Set Baseline

- [ ] Read this runbook once.
- [X] Timed: Two Sum.
- [X] Timed: Group Anagrams.
- [X] Timed: Search in Rotated Sorted Array.
- [X] Untimed recurrence drill: Climbing Stairs -> Min Cost Climbing Stairs.
- [ ] Say 30-second "tell me about yourself" aloud twice.

### Tue 2026-08-25 - DP Day 1

- [X] House Robber.
- [X] Coin Change.
- [X] Decode Ways.
- [ ] For each DP: write `state`, `transition`, `base case`, `order`, `complexity`.
- [ ] 15 minutes: "why quant finance" and "why Squarepoint".

### Wed 2026-08-26 - Sliding Window / Two Pointers

- [X] Longest Substring Without Repeating Characters.
- [X] Longest Repeating Character Replacement.
- [X] Container With Most Water.
- [ ] Subarray Product Less Than K.
- [ ] Redo one missed DP problem from Tuesday without looking.
- [ ] Prepare 2-minute thesis / project explanation.

### Thu 2026-08-27 - Binary Search + Heap

- [X] Binary Search.
- [X] Koko Eating Bananas.
- [X] Find Minimum in Rotated Sorted Array.
- [ ] Kth Largest Element in an Array.
- [ ] Last Stone Weight, or implement a tiny max-heap pop/push drill if short on time.
- [ ] Practice explaining binary search invariants aloud.
- [ ] Complexity audit: write time/space for the last 8 problems.

### Fri 2026-08-28 - DP Day 2

- [X] Longest Increasing Subsequence.
- [X] Jump Game.
- [X] Minimum Path Sum.
- [ ] Coin Change redo if it was shaky.
- [ ] Optional stretch: Min Cost Climbing Stairs fast redo.
- [ ] Ask yourself: top-down memo or bottom-up table, and why?

## Main DP Problem Types

When you read a DP question, first decide what kind of answer it wants.

| Type                    | Question wording                               | DP meaning                                                                                       | Examples in this plan                                    |
| ----------------------- | ---------------------------------------------- | ------------------------------------------------------------------------------------------------ | -------------------------------------------------------- |
| Counting                | "How many ways...?"                            | `dp[i]` stores the number of valid ways to reach/state `i`. Usually add possibilities.       | Climbing Stairs, Decode Ways                             |
| Minimising / maximising | "Minimum cost", "maximum profit", "best score" | `dp[i]` stores the best value up to/ending at `i`. Usually use `min(...)` or `max(...)`. | Min Cost Climbing Stairs, House Robber, Minimum Path Sum |
| Feasibility             | "Can you...?", "is it possible...?"            | `dp[i]` stores true/false reachability. Sometimes can be greedy instead.                       | Jump Game                                                |
| Sequence / subsequence  | "Longest..." or "best ending at each element"  | `dp[i]` often means best answer ending at index `i`. Compare against previous indices.       | Longest Increasing Subsequence                           |
| Coin / knapsack style   | "Fewest coins", "make target", "choose items"  | State usually includes an amount/capacity. Transition tries each choice.                         | Coin Change                                              |
| Grid paths              | "Path through matrix/grid"                     | `dp[r][c]` stores answer to reach cell `(r, c)`. Transition uses neighbours.                 | Minimum Path Sum                                         |

## Behavioural Bullets

### Tell Me About Yourself

> "I am an Imperial physics student with a strong mix of mathematical modelling, statistics, machine learning, and coding. My projects have mostly involved taking noisy real data or simulations, building models, and then being quite rigorous about validation. That is what attracts me to Desk Quant Analyst: it sits close to research and trading, but it is also very hands-on with code, data, debugging, and production reliability."

### Why Quant Finance

> "I like work where maths, data, and code directly influence decisions. Quant finance appeals to me because the feedback loop is concrete: you form a hypothesis, test it on data, worry about uncertainty and leakage, then decide whether it survives costs and risk. That mix of modelling discipline and practical implementation suits me."

### Why Squarepoint

> "Squarepoint appeals to me because it is systematic, research-led, and technology-heavy. The Desk Quant Analyst role seems especially interesting because it is close to Quant Researchers and Traders, so I would be helping make models, data, tools, and trading workflows reliable rather than working on isolated analysis."

### Where My Interests Are

Use 2-3 of these depending on the conversation:

- Time-series and noisy-data modelling.
- Model validation and avoiding leakage.
- Building tools that make research more reliable.
- Debugging data/production issues.
- ML for structured/tabular data.
- Understanding how signals survive costs, risk, and regime change.

## Resume / Thesis Project Notes

Use these if Tom asks about your CV, thesis, ML coursework, or why your background fits quant finance.

### Thesis / Pop-Cosmos

Short answer:

> "My thesis is about modelling galaxy populations and testing whether simulated predictions match telescope observations. The transferable part is model validation: take a model, generate predictions, compare against real data distributions, then diagnose where the assumptions break."

Simple explanation:

- Telescopes measure galaxy fluxes in different wavelength bands.
- A galaxy model predicts an SED, meaning brightness as a function of wavelength.
- Pop-Cosmos gives a simulated catalogue of galaxies with properties like redshift, stellar mass, star formation rate, and dust.
- FSPS is a physics-based model that turns stellar population assumptions into predicted light.
- Redshift matters because light from far-away galaxies is stretched to longer wavelengths.
- You compare predicted number counts with observed survey number counts.

Current technical issue:

> "The model seems more reasonable around 250 microns but overpredicts brighter sources at 350 and 500 microns. I am testing whether alternative or hybrid SED assumptions improve the long-wavelength match."

Good quant finance link:

> "The astronomy details are domain-specific, but the skill is general: testing whether model outputs match real data, finding where assumptions fail, and being careful about uncertainty."

If they ask what was hard:

- Observational data is noisy and incomplete.
- Simulations can match one distribution but fail in another.
- Need to avoid over-interpreting a model that works in one wavelength band.
- The work is less about forcing a fit and more about diagnosing model misspecification.

### A1: Angular Distribution / Z Boson Style Fit

Short answer:

> "This was a statistical modelling project where I generated simulated angular data and estimated a parameter using unbinned maximum likelihood, binned Poisson likelihood, and chi-squared fits."

Technical points:

- Inverse CDF / accept-reject sampling ideas.
- Unbinned MLE.
- Binned Poisson likelihood.
- Chi-squared fitting.
- Uncertainty scaling roughly like `1 / sqrt(N)`.

Good quant finance link:

> "It gave me practice setting up likelihoods, estimating parameters, comparing fit methods, and explaining uncertainty, which maps well to statistical modelling in finance."

### A2: COVID Forecasting

Short answer:

> "This was a time-lagged forecasting project using UK COVID and google mobility data to predict future deaths or hospital bed demand over 1-4 week horizons."

Technical points:

- Used lagged features and rolling averages.
- Compared Ridge, KNN, Random Forest, SGDRegressor, and baselines.
- Needed walk-forward or time-aware evaluation.
- Avoiding leakage was important because future information must not enter training features.
- Short-horizon forecasts were easier; longer horizons degraded as regimes changed.

Model insight:

- `SGDRegressor` was weaker because it is basically linear.
- Random Forest handled nonlinear regime changes better.
- KNN could work short term because similar recent days were informative.

Good quant finance link:

> "This is close to financial forecasting in spirit: real-world time data changes regime, models degrade, and evaluation over time matters more than one clean train/test split."

### A3: Higgs Boson Detection

Short answer:

> "This project used simulated CMS particle physics data to classify events as Higgs signal or background. The key point was not just classification accuracy, but improving the precision of a downstream likelihood fit."

Technical points:

- Tabular event-level physics features.
- Signal: `ggH`, `VBF`; background: mainly `Z`.
- Handled missing sentinel values like `-9999`.
- Compared Gradient Boosting, Random Forest, and XGBoost.
- Used ROC/AUC, classifier score histograms, quantile binning, Poisson likelihood fits, Minuit, and calibration.

Good line:

> "The final objective was not simply AUC. The classifier output fed into a statistical fit, so the useful model was the one that improved downstream precision."

Good quant finance link:

> "That maps well to quant work because a model should be judged by the final objective, not a vanity metric. In trading, a signal is only useful if it survives costs, risk, and validation."

### A4: 1D CNN Waveform Classification

Short answer:

> "I trained a 1D CNN in PyTorch to classify detector waveforms. The model learned local time-patterns in the signal, such as sharp early peaks and slower tails."

Technical points:

- Input was digitised waveform data.
- Used train/validation/test split and normalization.
- Built PyTorch `Dataset` / `DataLoader`.
- Used Conv1D layers, BatchNorm, ReLU, pooling, dropout.
- Evaluated with confusion matrix, ROC/AUC, and accuracy.
- Result was around 98 percent accuracy and AUC around 0.996.

Good learning:

> "Adding complexity was not automatically helpful. The baseline CNN was already strong, so careful evaluation mattered more than adding layers."

Good quant finance link:

> "The broader lesson is to match the model to the data structure. CNNs make sense when local signal shape matters; tree models are usually stronger for tabular data."

### IMC Prosperity

Short answer:

> "IMC Prosperity was useful because it forced market-style thinking: testing strategies, iterating quickly, managing risk, and avoiding overfitting to a small sample."

Good quant finance link:

> "It gave me a first taste of converting a hypothesis into a trading-style rule, then asking whether it is robust rather than just lucky."

## ML Follow-Up One-Liners

Use these if they probe the models from your projects.

- Random Forest: many decision trees trained with randomness and averaged, strong robust baseline for tabular nonlinear data.
- XGBoost: regularised gradient boosting; very strong on structured/tabular data but needs tuning.
- KNN: predicts from nearby examples; can work short term but is sensitive to scaling and regime change.
- Ridge: linear regression with L2 regularisation; useful stable baseline.
- SGDRegressor: linear model trained with stochastic gradient descent; fast but limited if relationships are nonlinear.
- CNN: learns local patterns with filters; good for images, waveforms, and sequence-like signals.
- AUC: measures ranking quality across thresholds, useful when the threshold is not fixed.
- Overfitting: model learns training quirks and fails on new data.
- Leakage: model accidentally uses information that would not be available at prediction time.
- Model selection: start with a baseline, validate honestly, increase complexity only if it improves the real objective.

## Questions To Ask Tom Durant

Pick 3-4.

- What does success look like for a Desk Quant Analyst in the first six months?
- **How does the role split between live trading support, research tooling, and longer-term project work?**
- What kinds of problems do strong DQAs eventually own independently?
- **How do DQAs usually work with Quant Researchers and Traders day to day?**
- What technical skill would you advise someone at my stage to sharpen most before starting?
- What is the steepest learning curve for new DQAs?
- How is feedback or mentorship structured for early-career people on the desk?
