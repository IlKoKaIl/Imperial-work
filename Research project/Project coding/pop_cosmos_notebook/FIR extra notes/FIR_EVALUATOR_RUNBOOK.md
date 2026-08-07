# FIR Evaluator Runbook

This is the current runbook for the pop-cosmos FIR/SPIRE number-count evaluator.

The goal is simple:

> keep the pop-cosmos galaxy population and `L_IR` fixed, change the far-IR dust SED shape, predict observed SPIRE counts, and compare to published corrected differential counts.

## Main Thesis Story Right Now

- baseline FSPS/pop-cosmos is too bright at long SPIRE wavelengths, especially the bright end
- the problem looks more like far-IR SED shape / dust temperature than total `L_IR`
- warmer/broader dust templates improve the external differential-count comparison
- the exact best template depends on the observed count source, so do not overclaim one magic template

Current headline result:

- best pooled model: `Casey T30K a=2.5`
- resolved/prior counts prefer: `Casey T30K a=3.0`
- P(D) statistical counts prefer: `Casey T30K a=2.5`
- baseline FSPS is worse than the best model across every held-out count source

The cleanest one-file recap is:

- `outputs/popcosmos_thesis_evaluator_snapshot.md`

The best map of all FIR thesis files is:

- `FIR_THESIS_MASTER_INDEX.md`

Intro / literature context draft:

- `FIR_INTRO_LITERATURE_DRAFT.md`

The cleanest count-source planning note is:

- `FIR_COUNT_SOURCE_ROADMAP.md`

Wang / count-source audit:

- `FIR_WANG_COUNT_SOURCE_AUDIT.md`

The cleanest thesis execution plan is:

- `FIR_THESIS_EXECUTION_PLAN.md`

Supervisor-facing decision note:

- `FIR_SUPERVISOR_DECISION_NOTE.md`

Methods chapter draft:

- `FIR_METHODS_CHAPTER_DRAFT.md`

Results chapter draft:

- `FIR_RESULTS_CHAPTER_DRAFT.md`

Discussion chapter draft:

- `FIR_DISCUSSION_CHAPTER_DRAFT.md`

Viva storyboard:

- `FIR_VIVA_STORYBOARD.md`

Stable thesis/viva figure package:

- `outputs/thesis_figure_package/README.md`

Optional Wang context figure now included in the package:

- `outputs/thesis_figure_package/fig10_wang_raw_count_context.png`

## Important Input Data

External count tables:

- `../catalog data/external_number_counts/external_count_source_decision_matrix.csv`
- `../catalog data/external_number_counts/external_spire_number_counts_starter.csv`
- `../catalog data/external_number_counts/external_spire_differential_counts_starter.csv`
- `../catalog data/external_number_counts/external_spire_glenn_2010_pd_counts.csv`
- `../catalog data/external_number_counts/external_spire_differential_counts_compiled.csv`

Wang catalogue sanity checks:

- `../catalog data/wang/master.dat.gz`
- `../catalog data/wang/ReadMe.txt`
- `../catalog data/wang/wang_2024_aa49055-23.html`

Pop-cosmos / FSPS inputs are loaded by the older model-count scripts. The expensive cached prediction file is:

- `outputs/popcosmos_restframe_hybrid_predictions.pkl`

## Script Order

### 1) Compile external counts

```bash
python compile_external_spire_differential_counts.py
```

Purpose:

- standardises Clements / Oliver / Pearson / Glenn / Varnish into `S^2.5 dN/dS`
- output unit is `Jy^1.5 deg^-2`
- Varnish P(D) uses a conservative approximate symmetric error from its published log lower/upper bounds

Main output:

- `../catalog data/external_number_counts/external_spire_differential_counts_compiled.csv`

### 2) Check Wang catalogue area / units

```bash
python popcosmos_wang_catalog_checks.py
python plot_wang_raw_count_context.py
```

Purpose:

- confirms Wang fluxes are in `mJy`
- records the `1.278 deg2` Wang/Farmer area
- records positive COSMOS2020 IDs vs negative radio-only prior IDs
- plots why Wang raw cumulative counts are diagnostic/context rather than the formal count product

Main outputs:

- `outputs/wang_master_catalog_area_summary.csv`
- `outputs/wang_master_catalog_detection_counts.csv`
- `outputs/wang_master_catalog_count_scenarios.csv`
- `outputs/wang_master_catalog_discrepancy_note.md`
- `outputs/wang_raw_count_context.png`
- `outputs/wang_raw_count_context_note.md`
- `outputs/wang_raw_count_context_area_selection_summary.csv`

### 3) Plot external count-source flux coverage

```bash
python plot_external_count_source_coverage.py
```

Purpose:

- shows which observed count source covers which SPIRE flux range
- helps decide whether to add more count papers or freeze the current set

Main outputs:

- `outputs/external_count_source_flux_coverage.csv`
- `outputs/external_count_source_flux_coverage.png`

### 4) Build baseline FSPS / ALESS hybrid counts

```bash
python popcosmos_restframe_hybrid_sed.py
python popcosmos_differential_count_evaluator.py
```

Purpose:

- predicts differential counts for FSPS, ALESS, and FSPS/ALESS hybrid templates
- scores them against published external differential counts

Main outputs:

- `outputs/popcosmos_restframe_hybrid_sed_differential_counts.csv`
- `outputs/popcosmos_differential_count_evaluator_scorecard.csv`
- `outputs/popcosmos_differential_count_area_corrected_overlay.png`

### 5) Build physical dust-template grids

```bash
python popcosmos_mbb_temperature_grid.py
python popcosmos_casey_like_template_grid.py
```

Purpose:

- tests modified blackbody temperature grid
- tests Casey-like modified blackbody + mid-IR power-law grid
- every galaxy keeps its original pop-cosmos `L_IR`

Main outputs:

- `outputs/popcosmos_mbb_temperature_grid_pooled_summary.csv`
- `outputs/popcosmos_casey_like_template_grid_pooled_summary.csv`
- `outputs/popcosmos_casey_like_template_grid_counts.png`
- `outputs/popcosmos_casey_like_template_grid_score_heatmap.png`

Runtime note:

- Casey grid is the slowest step, around a couple of minutes on this machine.

### 6) Summarise model-family evaluator

```bash
python popcosmos_model_family_score_summary.py
python popcosmos_evaluator_chi2_dof_check.py
python popcosmos_model_family_pd_sensitivity.py
python popcosmos_formal_evaluator_summary.py
python popcosmos_model_family_leave_one_out.py
python popcosmos_model_family_source_tension.py
python popcosmos_model_family_flux_regime_diagnostics.py
python popcosmos_thesis_evaluator_snapshot.py
```

Purpose:

- combines all model families
- checks the difference between `chi2/N` and a simple `chi2/(N-k)` dof correction
- checks whether the headline changes when P(D) counts are included/excluded
- writes a thesis-facing formal score using resolved/prior counts as the main evaluator
- checks overfitting with leave-one-source-out
- shows source-to-source tension
- splits residuals by flux regime
- writes the current thesis snapshot

Most useful outputs:

- `outputs/popcosmos_model_family_score_comparison.png`
- `outputs/popcosmos_evaluator_chi2_dof_check.md`
- `outputs/popcosmos_evaluator_chi2_dof_check.png`
- `outputs/popcosmos_model_family_pd_sensitivity.png`
- `outputs/popcosmos_formal_evaluator_summary.md`
- `outputs/popcosmos_formal_evaluator_summary.png`
- `outputs/popcosmos_model_family_leave_one_source_out.png`
- `outputs/popcosmos_model_family_source_tension.png`
- `outputs/popcosmos_model_family_flux_regime_residual_heatmap.png`
- `outputs/popcosmos_model_family_flux_regime_chi2.png`
- `outputs/popcosmos_thesis_evaluator_snapshot.md`

### 7) Prepare thesis figure package

```bash
python prepare_fir_thesis_figure_package.py
```

Purpose:

- copies the core thesis/viva figures into `outputs/thesis_figure_package/`
- writes a small README and manifest with stable figure names and draft captions

Main outputs:

- `outputs/thesis_figure_package/README.md`
- `outputs/thesis_figure_package/manifest.csv`

## Quick Rerun

If the heavy model grids have already been generated and I only want to refresh the summaries:

```bash
python run_fir_evaluator_pipeline.py --mode summary
```

If I want to rebuild the full chain:

```bash
python run_fir_evaluator_pipeline.py --mode full
```

## Current Caveats

- This evaluator is a diagnostic, not a final likelihood model.
- P(D) points are correlated, especially Glenn/Varnish.
- Varnish is included with approximate errors, so it should be treated as a sensitivity check.
- Wang is best used as a matched-object sanity check, not the formal number-count truth table.
- Reduced chi-square much bigger than 1 means mismatch / missing systematics / underestimated errors, not automatically overfitting.
- Overfitting is checked using leave-one-source-out and by requiring physically sensible SED shapes.

## Thesis-Friendly Wording

> Published SPIRE differential counts consistently prefer a warmer/broader far-IR dust SED than the baseline FSPS/pop-cosmos treatment at fixed `L_IR`. The exact best template varies between count products, but the broad physical direction is stable.

## Next Sensible Work

- ask whether the Casey-like grid is enough, or whether to add proper CIGALE/Dale/Draine-Li templates
- decide whether Varnish P(D) should stay in the formal score or become visual-only
- decide whether the bright-end residual should be a headline result or one diagnostic inside the broader evaluator story
- later: add radio counts as an independent wavelength check
