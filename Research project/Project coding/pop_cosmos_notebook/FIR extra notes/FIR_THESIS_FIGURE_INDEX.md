# FIR Thesis Figure Index

This is a working figure/caption list for the thesis and viva. Not every plot here needs to go into the final report.

## Core Figures

### 1) Current Model-Family Score Summary

File:

- `outputs/popcosmos_model_family_score_comparison.png`

![Current model-family score summary](outputs/popcosmos_model_family_score_comparison.png)

Use:

- main result figure
- shows baseline FSPS vs ALESS hybrids vs MBB vs Casey-like templates

Draft caption:

> Comparison of far-IR dust SED model variants using the published SPIRE differential-count evaluator. The score is a log-space chi-square-style residual across 250, 350, and 500 um counts. The best current models are Casey-like templates around `T ~ 30 K`, while the baseline FSPS/pop-cosmos SED is substantially worse.

Main talking point:

> The exact best template is not unique, but the evaluator consistently prefers a warmer/broader dust SED than baseline FSPS.

### 2) Casey-Like Template Grid

Files:

- `outputs/popcosmos_casey_like_template_grid_shapes.png`
- `outputs/popcosmos_casey_like_template_grid_score_heatmap.png`
- `outputs/popcosmos_casey_like_template_grid_counts.png`

![Casey-like template shapes](outputs/popcosmos_casey_like_template_grid_shapes.png)

![Casey-like score heatmap](outputs/popcosmos_casey_like_template_grid_score_heatmap.png)

![Casey-like count comparison](outputs/popcosmos_casey_like_template_grid_counts.png)

Use:

- methods/results figure
- shows that the best result is not just an arbitrary ALESS/FSPS blend

Draft caption:

> Casey-like far-IR SED grid used as a physically motivated template extension. Each template is normalised to preserve the original pop-cosmos `L_IR`, then redshifted to predict SPIRE fluxes and differential counts. The best scoring region is around `T ~ 30 K`, with a mid-IR power-law tail.

Main talking point:

> This is the current strongest model-extension demonstration because it is more physically motivated than simply mixing FSPS with ALESS.

### 3) FSPS Flux-Regime Residual Heatmap

Files:

- `outputs/popcosmos_model_family_flux_regime_residual_heatmap.png`
- `outputs/popcosmos_model_family_flux_regime_chi2.png`

![Flux-regime residual heatmap](outputs/popcosmos_model_family_flux_regime_residual_heatmap.png)

![Flux-regime chi-square comparison](outputs/popcosmos_model_family_flux_regime_chi2.png)

Use:

- diagnostic/result figure
- supports "FSPS does okay until bright end" in a precise way

Draft caption:

> Median log residuals between model and observed SPIRE differential counts, split by wavelength and flux regime. Positive residuals mean the model predicts too many counts. The FSPS baseline increasingly overpredicts counts at longer wavelengths and at the bright end, reaching roughly an order-of-magnitude excess at bright 500 um.

Main talking point:

> The mismatch is not flat. It gets worse at longer wavelength and high flux, which points to far-IR SED shape / dust temperature.

### 4) P(D) Sensitivity

File:

- `outputs/popcosmos_model_family_pd_sensitivity.png`

![P(D) sensitivity](outputs/popcosmos_model_family_pd_sensitivity.png)

Use:

- robustness/caveat figure
- shows whether the result depends on including P(D) statistical counts

Draft caption:

> Sensitivity of the model ranking to the inclusion of P(D) statistical count constraints. Resolved/prior counts alone prefer a Casey-like `T30K alpha=3.0` model, while P(D) counts and the full combined score prefer `T30K alpha=2.5`. The exact parameter changes slightly, but the preferred physical family remains similar.

Main talking point:

> P(D) changes the exact alpha, not the broad conclusion.

### 5) Leave-One-Source-Out Validation

File:

- `outputs/popcosmos_model_family_leave_one_source_out.png`

![Leave-one-source-out validation](outputs/popcosmos_model_family_leave_one_source_out.png)

Use:

- overfitting guard
- helps answer the "are we just tuning to one dataset?" concern

Draft caption:

> Leave-one-source-out test for the count evaluator. For each observed count source, the best model is selected using all other sources and then evaluated on the held-out source. The selected warm-dust correction beats the FSPS baseline on every held-out source, although it is not always the held-out oracle model.

Main talking point:

> The improvement is not just one-paper curve fitting, but the count products still have real tension.

### 6) Source-To-Source Tension

File:

- `outputs/popcosmos_model_family_source_tension.png`

![Source-to-source tension](outputs/popcosmos_model_family_source_tension.png)

Use:

- robustness/caveat figure
- shows which papers prefer which model

Draft caption:

> Best-fitting model family for each external count source. All sources prefer a model variant over baseline FSPS, but the exact preferred template differs between count products. This motivates presenting the result as a stable physical direction rather than a unique dust template.

Main talking point:

> Not one magic template. Stable direction: baseline FSPS is too cold / too long-wavelength bright.

### 7) Chi-Square / Dof Check

File:

- `outputs/popcosmos_evaluator_chi2_dof_check.png`

![Chi-square dof check](outputs/popcosmos_evaluator_chi2_dof_check.png)

Use:

- methods appendix / supervisor discussion
- probably not a main thesis figure unless statistics discussion becomes important

Draft caption:

> Comparison between the current rough score `chi2/N` and a simple degrees-of-freedom correction `chi2/(N-k)`, where `k` is the number of template hyperparameters. The correction barely changes the ranking because the number of count points is much larger than the number of template parameters.

Main talking point:

> The result is stable to a simple dof correction, but the score should still be described as diagnostic unless a stricter likelihood model is built.

### 8) Formal Resolved/Prior Evaluator Summary

File:

- `outputs/popcosmos_formal_evaluator_summary.png`

![Formal evaluator summary](outputs/popcosmos_formal_evaluator_summary.png)

Use:

- thesis-facing main-score figure
- useful because it separates the defendable formal score from the P(D) sensitivity check

Draft caption:

> Formal FIR evaluator summary using corrected resolved/prior SPIRE differential counts as the main score. The bar values show a simple chi-square-style score with a degrees-of-freedom correction, while P(D) scores are shown separately as a sensitivity check. The best formal score prefers a Casey-like template around `T ~ 30 K`, while baseline FSPS remains worse.

Main talking point:

> This is probably the cleanest figure to use when explaining the evaluator setup: formal score first, P(D) sensitivity second.

## Supporting / Historical Figures

### External Count Source Coverage

File:

- `outputs/external_count_source_flux_coverage.png`

![External count source coverage](outputs/external_count_source_flux_coverage.png)

Use:

- methods / data-source justification
- useful if asked why these count papers were chosen

Draft caption:

> Flux-density coverage of the external SPIRE count sources used in the evaluator. Resolved/prior count products cover the directly detected regime, while P(D) analyses extend to much fainter flux densities as statistical constraints. This motivates treating Clements/Oliver/Pearson as the main formal count score and Glenn/Varnish as faint-end sensitivity checks.

Main talking point:

> The current data set already covers the main SPIRE flux range. The only obvious gap worth adding later is a larger wide-area H-ATLAS bright-end source if supervisors want stronger rare-source constraints.

### Rest-Frame Hybrid SED Method Check

Files:

- `outputs/popcosmos_restframe_hybrid_sed_examples.png`
- `outputs/popcosmos_restframe_hybrid_sed_differential_counts.png`

Use:

- methods background
- shows transition from ALESS/FSPS mixing idea toward more physical Casey-like templates

Draft caption:

> Rest-frame SED hybrid test between the baseline FSPS far-IR shape and the ALESS empirical template. Each hybrid is normalised to preserve `L_IR` before predicting SPIRE counts. This motivated the later move toward physically parameterised dust templates.

### Full SED External Counts Overlay

Files:

- `outputs/popcosmos_full_sed_external_counts_overlay_corrected.png`
- `outputs/popcosmos_full_sed_external_counts_overlay.png`

Use:

- historical context / meeting discussion
- probably not final report unless cleaned

Draft caption:

> Early cumulative-count comparison between pop-cosmos, ALESS-scaled variants, Wang raw catalogue counts, and external SPIRE count data. This plot motivated switching to corrected differential counts and a formal evaluator.

### Wang Matched-Object Plots

Files:

- `outputs/thesis_figure_package/fig10_wang_raw_count_context.png`
- `outputs/popcosmos_full_sed_wang_multiband_compare.png`
- `outputs/popcosmos_full_sed_wang_brightcut_flux_bias.png`
- `outputs/popcosmos_wang_lir_fluxratio_vs_redshift.png`

Use:

- object-level diagnostics
- useful if there is a section on why Wang is not the formal count score
- `wang_raw_count_context.png` is a catalogue/count-context plot rather than a matched-object residual plot

Draft caption:

> Wang matched-object diagnostics. Unlike the published number-count tables, Wang is a deblended point-source catalogue and is most useful for per-object residuals, redshift trends, and population checks.

Extra caption for the raw-count context plot:

> Raw cumulative counts from the Wang COSMOS deblended catalogue under different area and selection assumptions, compared with direct published integral-count points from Clements and Pearson. The plot shows that Wang is useful context but should not be treated as a corrected population-count product.

## Suggested Final Report Figure Set

If space is tight, use:

1. `popcosmos_model_family_score_comparison.png`
2. `popcosmos_casey_like_template_grid_counts.png`
3. `popcosmos_model_family_flux_regime_residual_heatmap.png`
4. `popcosmos_model_family_leave_one_source_out.png`
5. one Wang matched-object diagnostic if needed

If there is room for robustness/caveats:

6. `popcosmos_model_family_pd_sensitivity.png`
7. `popcosmos_model_family_source_tension.png`

For viva slides:

- lead with the score summary
- show flux-regime heatmap to explain where FSPS fails
- show Casey-like counts to explain the model extension
- show leave-one-source-out to answer overfitting concerns
