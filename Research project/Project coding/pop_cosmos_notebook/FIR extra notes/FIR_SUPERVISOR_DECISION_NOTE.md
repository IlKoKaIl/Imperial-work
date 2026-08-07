# FIR Evaluator Supervisor Decision Note

This is a short note I can paste into an email or use in a meeting.

## Short Update

I have now turned the FIR/SPIRE comparison into a reproducible evaluator.

The basic setup is:

1. keep the pop-cosmos galaxy population fixed
2. keep each galaxy's original `L_IR` fixed
3. change only the far-IR dust SED shape
4. predict observed 250/350/500 um SPIRE fluxes
5. rebuild differential number counts
6. compare to published corrected SPIRE counts

Current headline:

> The baseline FSPS/pop-cosmos FIR SED overpredicts SPIRE counts, especially at the bright end and at longer wavelengths. Warmer/broader dust SED variants improve the comparison at fixed `L_IR`.

Current best model family:

| score group | best model |
|---|---|
| all counts | Casey-like `T30K alpha=2.5` |
| resolved/prior counts only | Casey-like `T30K alpha=3.0` |
| P(D) counts only | Casey-like `T30K alpha=2.5` |

Baseline FSPS:

- rough reduced chi2: `8.40`
- median log10(model/observed): `+0.31 dex`

Best current model:

- rough reduced chi2: `3.36`
- median log10(model/observed): `-0.03 dex`

So the result is not that one exact template is definitely correct. The safer result is:

> published SPIRE differential counts prefer a warmer/broader FIR SED than the baseline FSPS/pop-cosmos treatment.

## Current Data Roles

My current default is:

| data source | role |
|---|---|
| Clements 2010 H-ATLAS | formal bright/wide resolved-count comparison |
| Oliver 2010 HerMES | formal mid-flux resolved-count comparison |
| Pearson 2025 SUSSEXtractor/XID | formal deep resolved/prior count comparison |
| Glenn 2010 P(D) | faint-end sensitivity check |
| Varnish 2025 P(D) | faint-end sensitivity check |
| Wang 2024 COSMOS XID+ | matched-object diagnostic, not formal number-count truth |
| Bethermin 2012 stacking | literature/method context |
| Bethermin 2017 SIDES | model/evaluator context |

## Decisions I Need Advice On

### 1. Should P(D) be part of the formal chi-square score?

My default:

- main formal score = Clements / Oliver / Pearson
- P(D) = sensitivity/robustness check

Reason:

- P(D) reaches below normal source extraction and is very useful
- but the spline points are correlated model-fit constraints, so treating them like independent differential-count bins feels a bit too strong

Question:

> Should Glenn/Varnish P(D) be included in the headline chi-square score, or shown separately as a faint-end sensitivity test?

### 2. Is `chi2/N` acceptable wording?

Current score:

```text
chi2 = sum((log10(model) - log10(observed))^2 / sigma_log^2)
rough reduced chi2 = chi2 / N_points
```

I also checked a simple:

```text
chi2 / (N_points - k)
```

where `k` is the number of template hyperparameters. The ranking barely changes.

Question:

> Is it okay to call this a rough reduced chi-square score, or should I use `chi2/(N-k)` everywhere?

### 3. Is Clements enough for the bright end?

The current count coverage is:

- Pearson: roughly `10-100 mJy`
- Oliver: roughly `20-400 mJy`
- Clements: roughly `30-800 mJy`
- Glenn/Varnish P(D): much fainter statistical constraints

Question:

> Is the Clements H-ATLAS SDP table enough as the bright-end anchor, or should I add a larger H-ATLAS / Valiante count source to strengthen the rare bright-source comparison?

### 4. Are Casey-like templates enough for the thesis demonstration?

Current model variants:

- FSPS baseline
- ALESS empirical template
- FSPS/ALESS hybrids
- modified blackbody temperature grid
- Casey-like modified blackbody + mid-IR power-law grid

The Casey-like grid is currently the strongest demonstration because it is more physically motivated than directly mixing FSPS and ALESS.

Question:

> Is this Casey-like template grid enough as a model-improvement demonstration, or should I try to add proper CIGALE / Dale / Draine-Li dust template comparisons?

## My Proposed Thesis Direction

I think the thesis can now be framed as:

> an observed-space validation of pop-cosmos, using SPIRE differential number counts to identify a missing flexibility in the FIR dust SED treatment.

I would then keep radio/X-ray as possible future work unless the FIR chapter is already written and stable.

## Files / Outputs

Useful current summary files:

- `outputs/popcosmos_thesis_evaluator_snapshot.md`
- `FIR_THESIS_METHODS_RESULTS_DRAFT.md`
- `FIR_THESIS_FIGURE_INDEX.md`
- `FIR_COUNT_SOURCE_ROADMAP.md`
- `FIR_THESIS_EXECUTION_PLAN.md`
