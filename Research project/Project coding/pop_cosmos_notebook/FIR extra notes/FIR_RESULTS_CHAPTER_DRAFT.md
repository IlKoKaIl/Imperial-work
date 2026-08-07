# Results Chapter Draft: FIR/SPIRE Number-Count Evaluator

This is a working Results draft for the FIR/SPIRE part of the thesis.

It is written around the current output of:

```text
python run_fir_evaluator_pipeline.py --mode summary
```

The main figure copies are in:

```text
outputs/thesis_figure_package/
```

## Results Overview

The observed-space SPIRE evaluator shows that the baseline FSPS/pop-cosmos far-infrared SED overpredicts published SPIRE differential number counts. The discrepancy is strongest at the bright end and becomes more severe at longer SPIRE wavelengths.

Changing only the far-infrared SED shape, while preserving each galaxy's original pop-cosmos `L_IR`, improves the number-count comparison. The best current model family is a Casey-like modified blackbody plus mid-infrared power-law template, with a characteristic dust temperature around `30 K`.

The important result is not that this exact template is uniquely correct. The robust result is:

> the SPIRE number counts prefer a warmer/broader far-infrared dust SED than the baseline FSPS/pop-cosmos treatment at fixed `L_IR`.

## External Count Coverage

![External SPIRE count source coverage](outputs/thesis_figure_package/fig01_external_count_source_coverage.png)

The evaluator combines several published SPIRE count products. The external count-source coverage plot shows that the selected data span the relevant flux range:

- Pearson probes the deep detected/prior-extracted regime, around `10-100 mJy`.
- Oliver covers an intermediate HerMES resolved-count regime, around `20-400 mJy`.
- Clements provides the main current bright/wide H-ATLAS anchor, around `30-800 mJy`.
- Glenn and Varnish P(D) products extend to much fainter fluxes, but are statistical constraints rather than simple source-extraction bins.

This motivates the adopted split between formal resolved/prior count comparisons and P(D) sensitivity checks. For the main thesis result, Clements, Oliver, and Pearson provide the cleanest direct published differential count comparison. Glenn and Varnish are still valuable as faint-end robustness tests.

## Formal Evaluator Result

![Formal evaluator summary](outputs/thesis_figure_package/fig09_formal_evaluator_summary.png)

The thesis-facing formal score uses the corrected resolved/prior differential count products:

- Clements et al. 2010
- Oliver et al. 2010
- Pearson et al. 2025 SUSSEXtractor
- Pearson et al. 2025 XID

I keep the P(D) products separate as a faint-end sensitivity check because their spline points are correlated statistical constraints rather than simple independent detected-source bins.

With this setup, the current best formal model is:

| model | family | formal chi2/(N-k) | median log10(model/obs) | P(D) chi2/N |
|---|---|---:|---:|---:|
| Casey T30K alpha=3.0 | Casey-like | 3.35 | -0.00 | 4.37 |
| Casey T30K alpha=2.5 | Casey-like | 3.67 | -0.10 | 2.17 |
| 25% ALESS | FSPS/ALESS hybrid | 3.71 | +0.09 | 6.53 |
| 50% ALESS | FSPS/ALESS hybrid | 4.28 | -0.12 | 3.99 |
| FSPS baseline | baseline | 7.36 | +0.27 | 13.33 |

So under the formal resolved/prior score, baseline FSPS is about `2.2x` worse than the current best model. This is the cleanest score to defend in the thesis because it avoids letting correlated P(D) knots drive the headline result.

The useful scientific statement is:

> corrected resolved/prior SPIRE counts prefer a warm/broader Casey-like FIR dust template over baseline FSPS, while P(D) counts support the same broad family but shift the exact preferred parameter slightly.

## Overall Model-Family Ranking

![Model family score comparison](outputs/thesis_figure_package/fig02_model_family_score_comparison.png)

The pooled model-family score is still useful as a sanity check because it combines resolved/prior counts and P(D) counts. It ranks the current models as:

| model | family | N | rough reduced chi2 | median log10(model/obs) |
|---|---|---:|---:|---:|
| Casey T30K alpha=2.5 | Casey-like | 148 | 3.36 | -0.03 |
| Casey T30K alpha=3.0 | Casey-like | 148 | 3.48 | +0.07 |
| 25% ALESS | FSPS/ALESS hybrid | 149 | 4.17 | +0.12 |
| 50% ALESS | FSPS/ALESS hybrid | 149 | 4.20 | -0.06 |
| MBB 35 K | modified blackbody | 147 | 4.26 | -0.11 |
| FSPS baseline | baseline | 149 | 8.40 | +0.31 |
| ALESS | empirical template | 149 | 13.33 | -0.41 |

The baseline FSPS model has a median positive residual of `+0.31 dex` in the pooled score, meaning that it predicts too many SPIRE counts overall. In rough multiplicative terms, this is about a factor of two high. The best Casey-like pooled model has a median residual close to zero.

The pure ALESS template overcorrects in the opposite direction. It reduces the long-wavelength excess but becomes too faint overall. This is why the most useful interpretation is not "replace FSPS with ALESS", but rather:

> the FIR shape needs more flexibility, and the preferred correction is intermediate between the current cold FSPS-like shape and a very hot/empirical SMG-like shape.

## Where The Baseline FSPS Model Fails

![FSPS flux-regime residuals](outputs/thesis_figure_package/fig03_fsps_flux_regime_residual_heatmap.png)

The flux-regime residuals show that the FSPS mismatch is not uniform. It is mildest at 250 um and low/intermediate fluxes, and strongest at the bright end and longer wavelengths.

For the FSPS baseline:

| band | flux regime | median log10(model/obs) | rough factor |
|---|---|---:|---:|
| 250 um | 10-30 mJy | +0.11 | 1.3x high |
| 250 um | 30-100 mJy | +0.20 | 1.6x high |
| 250 um | 100-300 mJy | +0.69 | 4.9x high |
| 350 um | 100-300 mJy | +0.82 | 6.6x high |
| 500 um | 100-300 mJy | +1.08 | 11.9x high |

This supports the qualitative supervisor-meeting conclusion:

> FSPS does reasonably at 250 um low/mid fluxes, but overpredicts the bright end, especially at 350 and 500 um.

Physically, this points toward the far-infrared SED shape. A colder SED can shift too much luminosity into the long-wavelength SPIRE bands, producing too many bright 350/500 um sources even if the total `L_IR` is not wildly wrong.

## Casey-Like Template Grid

![Casey-like count comparison](outputs/thesis_figure_package/fig04_casey_like_count_comparison.png)

The Casey-like grid tests a more physical family of dust SEDs than a direct FSPS/ALESS blend. Each template is normalised to the original pop-cosmos `L_IR`, then redshifted and converted into predicted SPIRE counts.

The best region of the grid is around:

- `T ~ 30 K`
- mid-infrared power-law index `alpha ~ 2.5-3.0`

The exact preferred `alpha` depends on which count set is included:

| score group | best model | rough reduced chi2 |
|---|---|---:|
| all scored counts | Casey T30K alpha=2.5 | 3.36 |
| resolved/prior counts only | Casey T30K alpha=3.0 | 3.29 |
| P(D) statistical counts only | Casey T30K alpha=2.5 | 2.17 |

This is a useful result because it is stable at the family level but not overprecise at the parameter level. The data prefer a warm/broader dust SED, but the current analysis should not claim a uniquely measured dust temperature.

## Leave-One-Source-Out Check

![Leave-one-source-out validation](outputs/thesis_figure_package/fig05_leave_one_source_out.png)

To check whether the improvement is only tuning to one observed count product, I performed a leave-one-source-out test. For each observed count source, the best model was selected using all other sources and then evaluated on the held-out source.

The selected warm-dust correction beats the FSPS baseline on every held-out source:

| held-out source | selected model | held-out chi2 | FSPS chi2 |
|---|---|---:|---:|
| Clements | Casey T30K alpha=2.5 | 2.77 | 12.35 |
| Glenn P(D) | Casey T30K alpha=2.5 | 2.15 | 12.15 |
| Oliver | Casey T30K alpha=2.5 | 0.41 | 3.46 |
| Pearson SUSSEX | Casey T30K alpha=2.5 | 6.45 | 8.20 |
| Pearson XID | Casey T30K alpha=2.5 | 1.94 | 2.06 |
| Varnish P(D) | Casey T30K alpha=3.0 | 5.06 | 14.19 |

This does not mean the selected model is always the best possible model for each held-out source. Pearson and Varnish show some tension. However, it does show that the warm-dust correction generalises better than baseline FSPS across multiple count products.

This is the main guard against the worry that the evaluator is just fitting one dataset.

## P(D) Sensitivity

![P(D) sensitivity](outputs/thesis_figure_package/fig06_pd_sensitivity.png)

Including P(D) counts changes the exact best template parameter but not the broad conclusion. Resolved/prior counts alone prefer `Casey T30K alpha=3.0`, while the combined score and P(D)-only score prefer `Casey T30K alpha=2.5`.

Because P(D) products are statistical map-level constraints and their spline points are correlated, the safest thesis presentation is probably:

- use Clements/Oliver/Pearson as the main formal score
- show Glenn/Varnish P(D) as a sensitivity check

This keeps the statistical interpretation cleaner while still using P(D) as an important faint-end constraint.

## Source-To-Source Tension

![Source-to-source tension](outputs/thesis_figure_package/fig07_source_to_source_tension.png)

Different observed count products do not pick exactly the same best model:

| source | best model | FSPS/best chi2 ratio |
|---|---|---:|
| Clements | Casey T30K alpha=3.0 | 5.5 |
| Oliver | Casey T30K alpha=2.5 | 8.4 |
| Pearson SUSSEX | 25% ALESS | 1.5 |
| Pearson XID | 25% ALESS | 1.9 |
| Glenn P(D) | Casey T30K alpha=2.5 | 5.6 |
| Varnish P(D) | MBB 35 K | 6.6 |

This tension is scientifically useful. It suggests that the result should be presented as a stable direction rather than a single final dust template. Every count product prefers some SED-shape change over baseline FSPS, but the exact preferred shape depends on the measurement method and flux regime.

## Chi-Square Wording Check

![Chi-square dof check](outputs/thesis_figure_package/fig08_chi_square_dof_check.png)

The current score uses:

```text
chi2 / N_points
```

A simple degrees-of-freedom correction:

```text
chi2 / (N_points - k)
```

does not change the model ranking. This is because the number of count points is much larger than the number of simple template parameters.

For thesis wording, the safest phrase is:

> rough chi-square-style evaluator

rather than claiming a fully formal likelihood model. A high chi-square means that the model does not match the data within the adopted errors, or that the errors/model assumptions are incomplete. It does not automatically mean overfitting.

## Wang Matched-Object Role

Wang is not used as the main number-count truth table. It is instead useful for object-level diagnostics.

![Wang raw count context](outputs/thesis_figure_package/fig10_wang_raw_count_context.png)

The Wang `master.dat` catalogue:

- is a deblended point-source catalogue
- uses prior positions
- has fluxes in `mJy`
- covers the COSMOS2020/Farmer `FLAG_COMBINED=0` area of `1.278 deg2`
- includes both positive COSMOS2020 IDs and negative radio-prior IDs

This means raw Wang counts are affected by prior selection, deblending assumptions, area choice, and SNR cuts. They should not be mixed directly with published corrected number-count tables without modelling those effects.

The raw-count context plot makes this concrete. It compares Wang cumulative counts under different assumptions with direct published integral-count points from Clements and Pearson. The useful bookkeeping results are:

- using the Wang `1.278 deg2` area instead of the rough `2 deg2` COSMOS area lifts raw count densities by about `1.56x`
- applying `SNR>=3` barely changes the bright counts above about `20-50 mJy`, but matters more at faint cuts
- including negative radio-prior rows can lift the raw Wang curve
- Wang naturally gets weak at the rare bright end because COSMOS is a small field compared with wide count surveys

So the Wang disagreement is not mainly a hidden unit problem. The catalogue fluxes are in `mJy`. The issue is that Wang raw counts are not the same measurement product as corrected published population counts.

The thesis use of Wang should be:

- matched-object residuals
- high-SFR / AGN-ish source checks
- redshift or SFR residual trends

## Results Summary

The current FIR/SPIRE results support four main conclusions:

1. Baseline FSPS/pop-cosmos overpredicts published SPIRE counts.
2. The mismatch is strongest at the bright end and at longer wavelengths.
3. Changing the FIR SED shape at fixed `L_IR` improves the observed-count comparison.
4. The best current formal model family is a warm/broader Casey-like dust SED around `30 K`, but the exact template is not unique.

The thesis recommendation is therefore:

> pop-cosmos should include a more flexible far-infrared dust SED treatment when predicting long-wavelength observables.

## Open Decisions Before Finalising

Before this becomes final thesis text, I should confirm:

- whether P(D) results should be in the headline score or shown separately
- whether `chi2/N` or `chi2/(N-k)` should be used in final wording
- whether the current Clements bright-end anchor is enough
- whether the Casey-like grid is enough, or if a CIGALE/Dale/Draine-Li comparison is needed
