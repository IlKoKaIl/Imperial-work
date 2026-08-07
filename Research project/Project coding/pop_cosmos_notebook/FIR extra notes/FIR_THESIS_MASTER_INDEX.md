# FIR Thesis Master Index

This is the "where is everything?" file for the FIR/pop-cosmos thesis work.

## Start Here

If I only have 10 minutes, read these in order:

1. `outputs/popcosmos_thesis_evaluator_snapshot.md`
2. `FIR_THESIS_EXECUTION_PLAN.md`
3. `FIR_THESIS_DECISION_CHECKLIST.md`
4. `FIR_RESULTS_CHAPTER_DRAFT.md`
5. `FIR_SUPERVISOR_DECISION_NOTE.md`

The one-line thesis story:

> I use observed SPIRE number counts as an external evaluator for pop-cosmos and show that the baseline FSPS far-IR SED shape likely overpredicts bright long-wavelength counts; warmer/broader FIR SED variants improve the comparison while keeping each galaxy's original `L_IR` fixed.

## Writing Drafts

| file | what it is for |
|---|---|
| `FIR_INTRO_LITERATURE_DRAFT.md` | rough introduction / literature framing |
| `FIR_METHODS_CHAPTER_DRAFT.md` | methods chapter draft |
| `FIR_RESULTS_CHAPTER_DRAFT.md` | results chapter draft |
| `FIR_DISCUSSION_CHAPTER_DRAFT.md` | discussion / limitations / recommendations draft |
| `FIR_THESIS_METHODS_RESULTS_DRAFT.md` | older combined methods/results draft, still useful for wording |

## Planning / Supervisor Files

| file | what it is for |
|---|---|
| `FIR_THESIS_EXECUTION_PLAN.md` | August-November execution plan |
| `FIR_THESIS_DECISION_CHECKLIST.md` | what to freeze, what to ask supervisors, what to stop doing |
| `FIR_SUPERVISOR_DECISION_NOTE.md` | paste-ready questions for Dave/Boris |
| `FIR_EVALUATOR_SCORING_NOTE.md` | formal score / chi-square / overfitting note |
| `FIR_COUNT_SOURCE_ROADMAP.md` | which count sources matter and whether to add more |
| `FIR_WANG_COUNT_SOURCE_AUDIT.md` | why Wang is separate from corrected count papers |
| `FIR_THESIS_FIGURE_INDEX.md` | figure list, captions, and where each plot fits |
| `FIR_VIVA_STORYBOARD.md` | viva / presentation storyline |
| `FIR_EVALUATOR_RUNBOOK.md` | how to rerun the pipeline |

## Core Outputs

| output | what it is |
|---|---|
| `outputs/popcosmos_thesis_evaluator_snapshot.md` | cleanest current numerical recap |
| `outputs/popcosmos_formal_evaluator_summary.md` | thesis-facing formal evaluator summary |
| `outputs/thesis_figure_package/README.md` | stable thesis/viva figure package |
| `outputs/thesis_figure_package/manifest.csv` | source file and caption list for packaged figures |
| `outputs/wang_master_catalog_discrepancy_note.md` | Wang area/catalogue sanity note |
| `outputs/wang_raw_count_context_note.md` | why Wang raw counts are diagnostic, not the formal count product |

## Stable Figure Package

The cleanest plot folder is:

- `outputs/thesis_figure_package/`

Current packaged figures:

| figure | use |
|---|---|
| `fig01_external_count_source_coverage.png` | shows why the selected count sources cover useful flux ranges |
| `fig02_model_family_score_comparison.png` | main model-ranking result |
| `fig03_fsps_flux_regime_residual_heatmap.png` | shows where FSPS fails most strongly |
| `fig04_casey_like_count_comparison.png` | strongest current model-extension result |
| `fig05_leave_one_source_out.png` | overfitting guard |
| `fig06_pd_sensitivity.png` | P(D) sensitivity / caveat |
| `fig07_source_to_source_tension.png` | shows observed count products do not all prefer exactly the same template |
| `fig08_chi_square_dof_check.png` | score-method sanity check |
| `fig09_formal_evaluator_summary.png` | formal resolved/prior score summary |
| `fig10_wang_raw_count_context.png` | optional Wang raw-count context / appendix figure |

## Pipeline Commands

Quick refresh, when heavy grids already exist:

```bash
python run_fir_evaluator_pipeline.py --mode summary
```

Full rebuild, if changing the template grids:

```bash
python run_fir_evaluator_pipeline.py --mode full
```

The summary pipeline currently refreshes the evaluator outputs, Wang sanity checks, Wang raw-count context plot, count-source coverage plot, thesis snapshot, and thesis figure package.

## Current Scientific Position

comments:

- baseline FSPS/pop-cosmos overpredicts SPIRE counts compared with corrected published counts
- the mismatch is worse at longer wavelength and bright flux
- changing only the FIR SED shape at fixed `L_IR` improves the comparison
- Casey-like warm/broader dust templates are the strongest current model-extension direction
- the result is robust enough to be a thesis story, but not enough to claim one unique dust template

What I should not overclaim:

- not "I found the true dust temperature"
- not "ALESS is the correct answer"
- not "P(D) points are independent data bins"
- not "Wang alone proves the count mismatch"
- not "high chi-square automatically means overfitting"

## Remaining Decision Gates

Need supervisor sign-off on:

1. whether the formal score should include P(D), or whether P(D) should stay as a sensitivity check
2. whether to describe the score as `chi2/N` or use a simple `chi2/(N-k)` correction
3. whether Clements is enough for the bright-end anchor, or whether to add a larger H-ATLAS / Valiante source
4. whether Casey-like templates are enough for the thesis, or whether to add proper CIGALE / Dale / Draine-Li dust models

## Next Writing Move

Turn the four chapter drafts into actual thesis prose:

1. intro / literature context
2. methods
3. results
4. discussion

My current instinct:

- finish the FIR story first
- only add CIGALE/radio/X-ray if they directly strengthen the final argument
- do not start a whole new validation branch until the FIR chapter is written
