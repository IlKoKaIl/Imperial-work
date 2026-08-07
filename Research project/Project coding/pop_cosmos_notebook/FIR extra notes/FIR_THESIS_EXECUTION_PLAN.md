# FIR Thesis Execution Plan

This is the practical plan from August onward.

The aim is not to do every possible comparison. The aim is to finish a coherent thesis with enough evidence that the result feels real.

## One-Sentence Thesis Direction

> I use observed SPIRE number counts as an external evaluator for pop-cosmos and show that the current FSPS far-IR dust SED shape likely overpredicts bright long-wavelength counts; physically motivated warmer/broader dust SED variants improve the comparison while keeping each galaxy's original `L_IR` fixed.

## Minimum Viable Thesis

If I had to finish with the current work, the thesis can already be:

1. introduce pop-cosmos and why optical/NIR validation is not enough
2. explain observed-space validation using SPIRE number counts
3. show the baseline FSPS/pop-cosmos prediction
4. show where FSPS fails: bright end, worse at 350/500 um
5. test simple SED-shape changes at fixed `L_IR`
6. use an evaluator / scorecard across published corrected counts
7. show the best current direction: Casey-like `~30 K` warm/broader dust SED
8. discuss caveats: P(D), Wang catalogue role, cosmic variance, no unique template
9. recommend what pop-cosmos should improve next

That is a real thesis story. It is not just "I plotted some catalogues".

## What Is Already Ticked Off

| item | status | evidence |
|---|---|---|
| external SPIRE counts gathered | done | `external_spire_differential_counts_compiled.csv` |
| Pearson unit issue fixed | done | Pearson now converted to `Jy^1.5 deg^-2` |
| Wang units/area checked | done | `outputs/wang_master_catalog_discrepancy_note.md` |
| baseline FSPS counts built | done | `outputs/popcosmos_full_sed_*`, evaluator outputs |
| ALESS / hybrid test built | done | `popcosmos_restframe_hybrid_sed.py` |
| MBB grid built | done | `popcosmos_mbb_temperature_grid.py` |
| Casey-like grid built | done | `popcosmos_casey_like_template_grid.py` |
| evaluator scorecard built | done | `popcosmos_model_family_score_summary.py` |
| P(D) sensitivity checked | done | `popcosmos_model_family_pd_sensitivity.py` |
| leave-one-source-out check | done | `popcosmos_model_family_leave_one_out.py` |
| thesis draft started | done | `FIR_THESIS_METHODS_RESULTS_DRAFT.md` |
| figure index started | done | `FIR_THESIS_FIGURE_INDEX.md` |
| formal evaluator summary made | done | `outputs/popcosmos_formal_evaluator_summary.md` |
| freeze / decision checklist made | done | `FIR_THESIS_DECISION_CHECKLIST.md` |

## Main Result To Protect

The result should be phrased carefully:

> The exact best dust template is not unique, but the direction is stable: baseline FSPS is too bright in SPIRE counts, and the evaluator prefers a warmer/broader FIR SED at fixed `L_IR`.

Avoid overclaiming:

- not "I found the true dust temperature"
- not "ALESS is the correct answer"
- not "Wang proves the number counts are wrong"
- not "high chi-square means overfitting"

## Chapter / Report Shape

### 1. Introduction

Goal:

- why galaxy evolution simulations need multi-wavelength validation
- why dust-obscured star formation matters
- why FIR/sub-mm is a good out-of-sample test

Key citations:

- pop-cosmos paper / Boris work
- Herschel/SPIRE surveys
- number counts as model constraints

### 2. Data And Model

Goal:

- describe pop-cosmos catalogue / FSPS SEDs / `L_IR`
- describe SPIRE count data sources
- explain why Wang is separate

Core table:

- observational data role table from `FIR_THESIS_METHODS_RESULTS_DRAFT.md`

### 3. Forward Modelling Method

Goal:

- explain how a rest-frame FIR SED plus `L_IR` becomes observed 250/350/500 um flux
- explain differential counts
- explain evaluator score

Core equations:

```text
template shape -> normalise 8-1000 um integral to L_IR
redshift and distance -> observed flux density
predicted fluxes -> differential counts
chi2 = sum((log model - log observed)^2 / sigma_log^2)
```

### 4. Baseline Validation

Goal:

- show what FSPS/pop-cosmos predicts before changes
- show that the mismatch is strongest at the bright end and longer wavelengths

Core figures:

- model-family score summary
- flux-regime residual heatmap

### 5. SED-Shape Experiments

Goal:

- show ALESS/hybrid as initial empirical test
- show MBB/Casey-like as more physical dust-template tests
- argue that changing shape at fixed `L_IR` improves counts

Core figures:

- Casey-like count comparison
- Casey-like score heatmap

### 6. Robustness / Caveats

Goal:

- show P(D) sensitivity
- show leave-one-source-out
- explain source-to-source tension
- explain Wang matched-object role

Core figures:

- leave-one-source-out
- source tension or P(D) sensitivity
- optional Wang diagnostic

### 7. Discussion / Recommendations

Goal:

- what this says about pop-cosmos
- what kind of FIR dust model should be considered
- what should be checked next: CIGALE/Dale/Draine-Li, radio, X-ray, AGN/high-SFR tail

## August Plan

Main aim:

> Freeze the FIR evaluator story and convert it into thesis-quality methods/results text.

Useful wrap-up file:

- `FIR_THESIS_DECISION_CHECKLIST.md`

This is the file to use before adding more analysis. If a new task does not support one of those decision gates, it probably waits.

Tasks:

1. Ask supervisors to approve the score setup:
   - resolved/prior only vs resolved/prior plus P(D)
   - `chi2/N` wording vs `chi2/(N-k)`
   - whether Clements is enough bright-end coverage
2. Make final clean versions of the top 4 figures.
3. Write Methods and Baseline Results draft sections.
4. Decide whether to add a larger H-ATLAS / Valiante bright-end source.
5. Decide whether proper CIGALE/Dale/Draine-Li templates are needed or just discussed as future work.

End-of-August target:

- thesis has a real methods section draft
- thesis has a real first results section draft
- final count-source set is frozen

## September Plan

Main aim:

> Turn the model-extension work into a polished result and add one extra diagnostic only if it clearly helps.

Possible extra diagnostics:

- Wang matched-object residuals vs SFR / redshift / AGN-ish parameters
- high-SFR tail check
- redshift-aware count/residual split
- optional larger H-ATLAS bright-end count source

Avoid:

- starting too many new wavelength projects at once
- adding radio/X-ray unless the FIR chapter is already solid

End-of-September target:

- all main analysis plots frozen
- results/discussion draft exists
- any optional extension is either finished or cut

## October Plan

Main aim:

> Write, edit, and make the thesis feel like a single argument.

Tasks:

1. finish Introduction and Literature Review
2. finish Methods
3. finish Results
4. finish Discussion
5. clean figures/captions
6. check units and reproducibility
7. prepare viva slide storyline

End-of-October target:

- complete thesis draft
- supervisors can comment on structure rather than missing analysis

## November Buffer

Use only for:

- supervisor feedback
- final edits
- figure polish
- reference cleanup
- viva preparation

Do not plan new analysis for November unless it is absolutely tiny.

## Decision Gates

### Gate 1: P(D) in formal score?

Default:

- main score = Clements / Oliver / Pearson
- P(D) = sensitivity check

Reason:

- P(D) points are correlated model-fit constraints
- good for robustness, but awkward as independent chi-square bins

### Gate 2: Add Valiante / larger H-ATLAS?

Default:

- only add if supervisors say Clements is not enough for bright end

Reason:

- useful scientifically, but it costs time and may not change the story

### Gate 3: Add CIGALE/Dale/Draine-Li templates?

Default:

- mention as physically motivated next step
- only implement if current Casey-like model is considered too toy-like

Reason:

- it would strengthen the model-improvement angle, but could become a separate project

### Gate 4: Add radio/X-ray?

Default:

- postpone until FIR story is thesis-ready

Reason:

- radio/X-ray would be nice multi-wavelength validation, but the FIR chapter is already enough to carry the thesis if written well

## Risk List

| risk | mitigation |
|---|---|
| too many plots, no story | use figure index and keep only core figures |
| overclaiming template result | phrase as stable direction, not true template |
| count sources disagree | show source-to-source tension as a result/caveat |
| P(D) bins not independent | use as sensitivity or clearly caveat |
| Wang mismatch confusion | keep Wang as matched-object diagnostic |
| thesis becomes code-heavy | write observed-space method clearly in simple terms |
| November panic | freeze analysis by end of September |

## Next 7 Days

1. Send supervisors the evaluator setup questions.
2. Decide whether to freeze current count source set.
3. Convert `FIR_THESIS_METHODS_RESULTS_DRAFT.md` into a proper Methods chapter draft.
4. Clean the top 4 figures:
   - model-family score
   - Casey-like counts
   - flux-regime residual heatmap
   - leave-one-source-out
5. If time remains, make one Wang matched-object diagnostic that directly supports the discussion.

## Viva Story

Possible 6-slide flow:

1. pop-cosmos is calibrated in optical/NIR, so FIR is an out-of-sample test
2. forward model from `L_IR` + SED shape to observed SPIRE counts
3. baseline FSPS is too high at bright 350/500 um
4. changing FIR SED shape at fixed `L_IR` improves the counts
5. leave-one-source-out shows this is not just one-paper tuning
6. recommendation: pop-cosmos needs more flexible FIR dust SED treatment
