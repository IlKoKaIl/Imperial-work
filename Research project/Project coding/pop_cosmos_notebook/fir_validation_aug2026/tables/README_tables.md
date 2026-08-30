# Tables

## The scatter finding
| file | contents |
|---|---|
| `paradox_decomposition.csv` | Mean-offset and scatter contributions to the count excess, per band |
| `paradox_decomposition_residuals.csv` | The same with the unexplained residual made explicit (0.00 / 0.20 / 0.15 dex) |
| `scatter_budget_decomposition.csv` | Model vs deblending contributions to the measured spread |
| `jin_wang_per_object_scatter.csv` | Per-object residual against both Wang and Jin |
| `model_variant_scatter_comparison.csv` | Spread by template variant, showing it is flat |
| `model_scatter_noise_deconvolved.csv` | Spread after removing catalogue measurement noise |
| `scatter_injection_count_inflation.csv` | Count inflation from injecting the model's spread into observed fluxes |
| `scatter_vs_measured_excess.csv` | Injected inflation compared to the measured excess |

## Model comparison and robustness
| file | contents |
|---|---|
| `block_bootstrap_model_ranking.csv` | Median offset and 95% CI per model, resampling sky fields |
| `table_D_model_family_common.csv` | Legacy common-point snapshot; superseded for final numbers by `validation_unified_scorecard.csv` |
| `table_E_fsps_by_band_regime.csv` | Baseline offset by band and flux regime |
| `validation_unified_scorecard.csv` | Final thesis-facing scorecard: all models rescored on the same 174-point set, plus the clean 74-point subset |
| `validation_error_floor_sensitivity.csv` | Effect of the assumed systematic error floor |
| `validation_fsps_persource_offsets.csv` | Baseline offset per count source (the 7/7 sign test) |
| `count_source_decision_sensitivity.csv` | Ranking under five different source-selection treatments |

## Template degeneracy
| file | contents |
|---|---|
| `casey_alpha_degeneracy.csv` | Casey alpha=2.5 vs 3.0 difference in predicted counts |
| `aless_casey_degeneracy.csv` | ALESS-50% vs Casey difference in predicted counts |
| `aless_hybrid_fraction_constraint.csv` | Constraint on the ALESS mixing fraction |

## Redshift
| file | contents |
|---|---|
| `z_resolved_excess_localisation.csv` | Reduction in excess when each redshift bin is removed |
| `model_dust_temperature_vs_redshift.csv` | Model cold-dust fraction by redshift bin |

## Catalogue systematics
| file | contents |
|---|---|
| `wang_deficit_decomposition.csv` | Flux-bias and slope terms in the raw-count deficit |
| `wang_jin_vs_published.csv` | Both catalogues against published counts |
| `wang_jin_deficit_by_regime.csv` | The same resolved by flux regime |
| `wang_jin_snr3_regime.csv` | With matched signal-to-noise cuts |

## Bibliography
| file | contents |
|---|---|
| `thesis_bibliography.csv` | Anchor papers with DOIs and citation counts |
