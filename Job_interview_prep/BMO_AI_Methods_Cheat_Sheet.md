# BMO AI Methods Cheat Sheet

Quick prep for exploratory AI interview.

Use this style:

> "Simple answer first, then one project example."

---

## 1. My AI Profile

**Interview answer**

> "My background is applied ML. I have done both production-facing AI work, like RAG/conversational agents, and academic applied ML projects involving forecasting, classification, CNNs, likelihood fits, and model evaluation."

**Good theme**

- I like applied AI that is useful, measurable, and reliable.
- I care about evaluation, not just model building.
- I can work across data, modelling, and implementation.

---

## 2. Core ML Concepts

### Supervised Learning

**Interview answer**

> "Supervised learning means training a model on examples where we already know the answer. The model learns to map inputs to outputs."

Examples:

- input: patient/history/mobility features
- output: future hospital beds or deaths
- input: particle event features
- output: signal or background

### Classification

**Interview answer**

> "Classification predicts a category."

Examples:

- Higgs project: signal vs background
- CNN project: fast vs slow waveform

### Regression

**Interview answer**

> "Regression predicts a number."

Examples:

- COVID project: future deaths / hospital beds
- thesis: predicted fluxes, SFR comparisons

### Train / Validation / Test

**Interview answer**

> "Train is for fitting the model, validation is for tuning choices, test is the final unseen check."

Important:

- Don't tune on the test set.
- Validation helps avoid fooling yourself.

### Overfitting

**Interview answer**

> "Overfitting is when a model memorizes training data but performs badly on new data."

Fixes:

- simpler model
- regularization
- more data
- validation checks
- early stopping

### Feature Engineering

**Interview answer**

> "Feature engineering means turning raw data into useful inputs for the model."

Example:

- COVID project: lags, rolling averages, future prediction horizons.

---

## 3. Common Models

### Linear Regression

**Interview answer**

> "Linear regression predicts a number using a weighted sum of features."

Good for:

- simple baseline
- interpretability

Weakness:

- struggles with nonlinear effects.

### Logistic Regression

**Interview answer**

> "Logistic regression is a simple classifier. It predicts the probability of a class."

Good for:

- baseline classification
- interpretable coefficients

### Gradient Descent

**Interview answer**

> "Gradient descent is an optimization method. It updates model parameters step by step to reduce the loss."

Simple version:

- calculate error
- see which direction reduces error
- take a small step
- repeat

Key terms:

- learning rate = step size
- loss function = what the model is trying to minimize

### SGD

**Interview answer**

> "Stochastic gradient descent is gradient descent using small batches or individual examples instead of the whole dataset each time."

In my COVID project:

- I tried `SGDRegressor`
- it was weaker than Random Forest / KNN
- why: `SGDRegressor` is basically a linear model, so it expects one fairly simple relationship between inputs and output
- COVID data changed by regime: lockdowns, waves, vaccines, reporting changes
- Random Forest handled this better because trees can split the data into different cases
- KNN handled short-term prediction well because it looks for similar past days instead of forcing one global line

### Ridge Regression

**Interview answer**

> "Ridge is linear regression with regularization. It keeps weights from getting too large."

Useful as:

- stable linear baseline
- less overfitting than plain linear regression

In my COVID project:

- Ridge worked well for some hospital bed forecasts.

### Lasso Regression

**Interview answer**

> "Lasso is linear regression with regularization that can push some feature weights to zero."

Useful for:

- feature selection
- sparse models

### KNN

**Interview answer**

> "KNN predicts using the most similar past examples."

Simple:

- find nearest examples
- average their values or vote

In my COVID project:

- KNN did well for short-horizon deaths.
- But it got worse at longer horizons because old similar days may not stay useful when the pandemic regime changes.

### SVM

**Interview answer**

> "An SVM tries to find the best boundary between classes, with the widest margin between groups."

Good for:

- smaller datasets
- clear class boundaries
- high-dimensional features

Kernel idea:

> "A kernel lets SVM draw nonlinear boundaries."

Simple weakness:

- can be slower and harder to tune on large datasets.

---

## 4. Tree Models

### Decision Tree

**Interview answer**

> "A decision tree makes predictions through a sequence of simple if-else splits."

Example:

- if feature A is high, go left
- else go right

Good:

- easy to understand
- handles nonlinear rules

Weakness:

- one tree can overfit.

### Random Forest

**Interview answer**

> "A random forest is many decision trees trained with randomness. Each tree is noisy, but averaging them gives a more stable prediction."

Key idea:

- many trees vote or average
- reduces overfitting compared to one tree

In my COVID project:

- Random Forest handled nonlinear lag interactions well.
- It was robust at longer prediction horizons.

### Boosting

**Interview answer**

> "Boosting builds models sequentially. Each new model tries to fix the mistakes of the previous ones."

Simple contrast:

- Random Forest = many independent trees averaged
- Boosting = trees built one after another

### Gradient Boosting

**Interview answer**

> "Gradient boosting is boosting where each new tree learns the remaining error from the previous model."

In my Higgs project:

- I used gradient boosting to separate Higgs signal from Z background.

### XGBoost

**Interview answer**

> "XGBoost is a fast, regularized version of gradient-boosted trees. It is very strong on tabular data."

Why it is popular:

- handles nonlinear patterns
- strong accuracy
- works well on structured data
- has regularization

In my Higgs project:

- I compared Gradient Boosting, Random Forest, and XGBoost.
- XGBoost was useful because the data was tabular event-level physics features.

---

## 5. Neural Networks

### Neural Network

**Interview answer**

> "A neural network learns layers of transformations from inputs to outputs."

Good for:

- images
- text
- signals
- complex nonlinear patterns

Weakness:

- needs more data
- less interpretable
- needs careful validation

### Activation Functions

**Interview answer**

> "Activation functions let neural networks learn nonlinear patterns. Without them, the network is basically just a linear model stacked multiple times."

Simple examples:

- `ReLU`: outputs zero for negative values, keeps positive values
- `Sigmoid`: squashes values between 0 and 1
- `Softmax`: turns output scores into class probabilities

### ReLU

**Interview answer**

> "ReLU is a simple activation function. It keeps positive signals and cuts negative ones to zero, which makes training faster and works well in many neural nets."

Why it is common:

- simple
- fast
- helps avoid very slow learning compared with older activations

### Optimizer

**Interview answer**

> "The optimizer is the rule the model uses to update its weights during training."

Simple version:

- model predicts
- calculate loss
- optimizer updates weights
- repeat many times

### Adam Optimizer

**Interview answer**

> "Adam is a popular optimizer for neural networks. It is like gradient descent, but it adapts the step size for each parameter."

Why people use it:

- usually trains faster than plain gradient descent
- less manual tuning
- works well as a default for many neural nets

### CNN

**Interview answer**

> "A CNN learns local patterns using convolution filters. In my A4 project, I used a 1D CNN on detector waveforms to classify fast vs slow scintillation signals."

In my A4 project:

- input = digitised waveform
- task = classify ES/PVT fast signal vs NS/ZnS slower signal
- model = PyTorch 1D CNN
- training = loss function + optimizer updated weights over batches
- learned features:
  - sharp early peak
  - longer tail
  - pulse density after trigger
- result:
  - about 98 percent accuracy
  - AUC around 0.996

### 1D CNN

**Interview answer**

> "A 1D CNN is like an image CNN, but for sequences or time signals instead of 2D images."

Why it fit A4:

- waveform is a sequence over time
- signal shape matters

### Dropout

**Interview answer**

> "Dropout randomly turns off some neurons during training to reduce overfitting."

### BatchNorm

**Interview answer**

> "Batch normalization helps stabilize training by keeping activations in a better range."

---

## 6. Metrics

### Accuracy

**Interview answer**

> "Accuracy is the fraction of predictions that are correct."

Good when:

- classes are balanced

### Precision / Recall

**Interview answer**

> "Precision asks: when the model says positive, how often is it right? Recall asks: out of real positives, how many did it find?"

Useful when:

- false positives and false negatives have different costs

### ROC / AUC

**Interview answer**

> "AUC measures how well the model ranks positives above negatives across thresholds."

In A4:

- AUC was about 0.996.

In Higgs:

- AUC helped measure signal/background separation.

### MAE / RMSE

**Interview answer**

> "MAE and RMSE measure regression error. MAE is average absolute error. RMSE penalizes large mistakes more."

In COVID:

- used for daily deaths / hospital bed forecasts.

### R2

**Interview answer**

> "R2 measures how much variance the model explains compared to a simple mean prediction."

Caveat:

- can become negative if model is worse than predicting the mean.

---

## 7. My Course Projects

## A1: Angular Distribution / Z Boson Style Fit

**Interview answer**

> "This was a statistical modelling project. I generated simulated angular data, then estimated a parameter using unbinned maximum likelihood, binned Poisson likelihood, and chi-squared fits."

Methods used:

- inverse CDF sampling
- accept/reject sampling idea
- unbinned MLE
- binned Poisson likelihood
- chi-squared fit
- uncertainty scaling

Good thing to say:

> "It gave me practice with likelihoods, uncertainty, and comparing fit methods."

Result idea:

- uncertainty scaled roughly like `1/sqrt(N)`
- unbinned MLE was a strong baseline

## A2: COVID Forecasting

**Interview answer**

> "This was a time-lagged forecasting project. We used UK COVID and Google mobility data to predict future deaths and hospital bed needs 1-4 weeks ahead."

Context:

- similar to work done for UK government during COVID
- repeated/extended as an applied ML project

Data:

- UK health data
- Google mobility data
- cases, admissions, hospital beds, deaths
- vaccination / behaviour proxies

Methods:

- lagged features
- rolling averages
- walk-forward evaluation
- Ridge
- KNN
- Random Forest
- SGDRegressor
- baselines

What I learned:

> "Short-term prediction worked better than long-term prediction. Past data becomes less reliable when the real-world regime changes."

Good BMO link:

> "This is relevant to finance because models can degrade when the world changes. Evaluation over time matters."

Quick model result:

- KNN/Ridge could work well short term.
- Random Forest was more robust at longer horizons.
- Errors grew after 2 weeks.

## A3: Higgs Boson Detection

**Interview answer (compact muon solenoid)**

> "This project used simulated CMS particle physics data to separate Higgs signal from Z background. The goal was not just classification accuracy, but improving the precision of a downstream likelihood fit."

Data:

- simulated LHC/CMS events
- channels: `et`, `mt`, `tt`
- processes:
  - background: Z
  - signal: ggH, VBF

Methods:

- pandas data loading
- handled `-9999` missing values
- selected numeric physics features
- Gradient Boosting
- Random Forest
- XGBoost
- ROC/AUC
- ML score histograms
- quantile binning
- Poisson likelihood fits
- Minuit
- isotonic probability calibration

Strong point:

> "The goal was not just to maximize AUC. The classifier output was used to build bins for a likelihood fit, so the real target was statistical precision."

Good BMO link:

> "That taught me to optimize for the final business/scientific objective, not just a generic ML metric."

## A4: 1D CNN Waveform Classification

**Interview answer**

> "I trained a 1D CNN in PyTorch to classify detector waveforms from scintillating materials. The model learned local time-patterns like early spikes and long tails."

Data:

- digitised waveform signals
- ES/PVT fast signals
- NS/ZnS slower signals

Methods:

- train/validation/test split
- normalization
- PyTorch Dataset/DataLoader
- Conv1D layers
- BatchNorm
- ReLU
- pooling
- dropout
- confusion matrix
- ROC/AUC

Result:

- about 98 percent accuracy
- AUC around 0.996

What I learned:

> "More model complexity did not help much. The baseline CNN was already strong, so evaluation mattered more than blindly adding layers."

---

## 8. RAG / LLM Work

**Interview answer**

> "In industry, I worked on RAG and conversational agents. RAG combines retrieval with generation: first fetch relevant documents, then use an LLM to answer grounded in that context."

RAG steps:

1. split documents into chunks
2. embed chunks
3. store in vector database
4. retrieve relevant chunks for a user query
5. send context to LLM
6. generate answer

Important issues:

- retrieval quality
- hallucination control
- latency
- evaluation
- user trust
- permissions / data access

Good BMO line:

> "In a bank, RAG needs strong governance: access control, auditability, evaluation, and human oversight for high-risk use cases."

---

## 9. Responsible AI

**Interview answer**

> "Responsible AI means making sure the model is useful, tested, monitored, and appropriate for the risk level."

Things to mention:

- data quality
- bias/fairness
- explainability
- privacy
- monitoring
- human-in-the-loop
- audit trails
- clear evaluation

Good BMO line:

> "For banking, I would expect responsible AI to matter as much as raw model performance."

---

## 10. If Asked To Compare Models

### Random Forest vs XGBoost

**Interview answer**

> "Random Forest averages many independent trees. XGBoost builds trees sequentially, each correcting previous errors. Random Forest is robust and easy to use. XGBoost often performs better but needs more tuning."

### SVM vs Tree Models

**Interview answer**

> "SVMs find a boundary with a large margin. Tree models split the feature space into rules. SVMs can be strong on smaller high-dimensional data, while boosted trees are usually very strong on tabular data."

### CNN vs Tree Models

**Interview answer**

> "CNNs are good when local structure matters, like images or waveforms. Tree models are usually better for tabular structured data."

### AUC vs Accuracy

**Interview answer**

> "Accuracy uses one threshold. AUC measures ranking quality across thresholds."

### Model Selection

**Interview answer**

> "I usually start with a simple baseline, then move to more complex models only if the baseline fails."

---

## 11. Best Interview Themes

Use these often:

- "I like applied AI, not just toy demos."
- "I care about evaluation and failure modes."
- "The right metric depends on the final objective."
- "Models can degrade when the real world changes."
- "Simple robust models often beat overcomplicated ones."
- "In regulated settings, governance and monitoring matter."

---

## 12. Quick One-Liners

**Decision tree**

> "A chain of if-else splits."

**Random forest**

> "Many trees averaged together."

**Boosting**

> "Models trained one after another to fix errors."

**XGBoost**

> "A fast, regularized boosted-tree method."

**SVM**

> "Finds the widest-margin boundary between classes."

**Gradient descent**

> "Step-by-step loss minimization."

**CNN**

> "Learns local patterns with filters."

**RAG**

> "Retrieve relevant context, then generate an answer."

**Overfitting**

> "Good on training data, bad on new data."

**AUC**

> "How well the model ranks positives above negatives."
