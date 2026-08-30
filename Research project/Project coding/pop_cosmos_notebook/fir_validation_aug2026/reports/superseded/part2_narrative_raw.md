##### P2 LINES 1-181 #####
# Analysis Notes Extract

**THREAD:** Whether SPIRE count mismatch reflects pop-cosmos physics failure or Wang/Valiante data handling.

**MOTIVATION:** Validate whether FIR prediction failure is model physics (dust SED) vs. upstream photometry/deblending artifacts.

**OUTCOME:**
- WORKED: FSPS baseline SED is too cold; peak wavelength ~136 μm explains long-wavelength excess
- WORKED: Warmer templates (Casey T30K, ALESS 50%) reduce count mismatch; 0.87–1.07× vs. 1.88× for FSPS
- WORKED: Mismatch localized to 350/500 μm bright end (14.57× high at 500 μm, 100–300 mJy bin)
- WORKED: Count comparison method (bins vs. individual objects) validated per plot type

**NUMBERS:**
- Median FIR SED peak: 136 μm
- FSPS median log₁₀(model/obs): +0.275 (1.88× high); χ²/N = 6.64
- Casey T30K a=2.5: −0.062 (0.87×); χ²/N = 2.24
- 500 μm, 100–300 mJy: 14.57× high; 250 μm, 10–30 mJy: 1.24× high
- Bootstrap: model ranking survives correlated surveys (robustness tested)

**THESIS_VALUE:**
- FSPS cold-dust diagnosis: MAIN — physical explanation for count excess
- Template comparison table: MAIN — quantifies improvement from warmer SEDs
- Count overlay plot: MAIN — shows failure mode (bright-end 500 μm)
- Bootstrap robustness: APPENDIX — validates method; does not change conclusions
- Wang/Valiante deblending check: ONE_SENTENCE — confirms not primary driver

**FIGURES:**
- `popcosmos_count_overlay_thesis.png` — Observed vs. model counts (250/350/500 μm); shows FSPS high, especially bright end
- `fsps_fir_sed_diagnostic.png` — Rest-frame SED shapes; population peak wavelength ~136 μm; illustrates cold-dust effect
- `bootstrap_forest_plot.png` — Model ranking robustness across correlated survey blocks

**EVIDENCE_TABLE:**

| Model | Median log₁₀(model/obs) | Factor | χ²/N | Status |
|---|---|---|---|---|
| FSPS baseline | +0.275 | 1.88× | 6.64 | Too high |
| Casey T30K a=2.5 | −0.062 | 0.87× | 2.24 | Better |
| Casey T30K a=3.0 | +0.030 | 1.07× | 2.39 | Better |
| ALESS 50% | −0.079 | 0.83× | 2.90 | Better |
| ALESS 25% | +0.107 | 1.28× | 3.29 | Intermediate |
| ALESS pure | −0.444 | 0.36× | 9.14 | Too low |

**OPEN:**
- Which dust model (ALESS, Casey, Draine/CIGALE) best represents pop-cosmos galaxies physically?
- Does residual scatter in per-galaxy FIR fluxes (mentioned as promoting faint → bright bins) quantify independently from SED shape?

**QUOTABLE:**
- "pop-cosmos was not trained on 250/350/500 μm, so these bands are a useful out-of-sample validation."
- "the counts prefer a warmer/broader FIR SED at fixed L_IR; they don't uniquely select between ALESS, Casey-like, or a future Draine/CIGALE-style physical dust model."

##### P2 LINES 182-352 #####
# EXTRACTION FROM STUDENT ANALYSIS (Lines 182–352)

## THREAD
Reconciling apparent contradiction: per-object model appears too faint while number counts predict too many bright sources.

## MOTIVATION
Diagnostic investigation after detecting conflicting signals in validation against published SPIRE counts and Wang/Jin catalogues.

## OUTCOME
- **WORKED**: Paradox is real and explained by model scatter promoting faint galaxies into bright bins (Eddington-like bias in predictions).
- **WORKED**: Scatter is intrinsic to model, not caused by Wang deblending noise.
- **WORKED**: Wang/Jin per-object comparisons are diagnostic-grade; raw counts unsuitable for bright-bin comparisons above ~30 mJy.
- **WORKED**: Cold SED shape (separate from scatter) explains template-dependent improvements.
- **ABANDONED**: Exact emissivity index / "best" Casey α — data do not stably choose.
- **SUPERSEDED** (deprioritized): Draine/Li, CIGALE grids, redshift-resolved counts, AGN checks → listed as future work.

## NUMBERS

**500 μm, 11,403 matched galaxies:**
- Model predicts >20 mJy: **422** galaxies
- Wang measured >20 mJy: **134** galaxies
- Both agree bright: **21** galaxies
- Over-predicted (model bright, Wang faint): **401**

**Per-object mean offset vs. scatter (dex):**

| Band | Mean Offset | Count Effect (Mean) | Count Effect (Scatter) | Net Predicted | Measured | Residual |
|------|----------:|---:|---:|---:|---:|---:|
| 250 μm | −0.163 | −0.361 | +0.549 | +0.188 | +0.190 | +0.002 |
| 350 μm | −0.235 | −0.621 | +0.731 | +0.110 | +0.310 | +0.200 |
| 500 μm | −0.183 | −0.575 | +0.855 | +0.280 | +0.430 | +0.150 |

**Model scatter (dex) — not deblending-dominated:**

| Band | Model vs. Wang | Model vs. Jin | Wang-vs-Jin | Deblending % of Variance |
|---:|---:|---:|---:|---:|
| 250 μm | 0.501 | 0.512 | 0.130 | 6.7% |
| 350 μm | 0.441 | 0.466 | 0.119 | 7.3% |
| 500 μm | 0.436 | 0.423 | 0.154 | 12.5% |

**Wang flux-corrected vs. published (500 μm, 10–30 mJy):** 0.86–0.97×.  
**Jin vs. published (same):** 1.03–1.05×.

## THESIS_VALUE

Per item from status table:

- **Published SPIRE counts:** MAIN — core validation result.
- **Per-object vs. count paradox:** MAIN — cleanest resolved finding; demonstrates dual failure mode (SED + scatter).
- **Cold SED diagnostic:** APPENDIX — supports interpretation but not central to paradox resolution.
- **Wang vs. Jin deblending check:** APPENDIX — closes systematics concern.
- **FSPS warm/intermediate templates:** APPENDIX — shows direction but templates not uniquely chosen.
- **Wang raw counts:** ONE_SENTENCE — diagnostic only; exclude from bright-bin formal comparison.
- **Valiante bright spike:** ONE_SENTENCE — exists in data; sensitivity confirms robustness.
- **Chi-square / evaluator:** ONE_SENTENCE — use as scorecard; block-bootstrap safer than naive.
- **Exact emissivity / Casey α:** CUT — data do not stably choose; do not quote as measured.
- **Draine/Li, CIGALE, redshift slices, AGN:** CUT — listed as future work unless time permits.

## FIGURES

- `scatter_mechanism_explained.png` — Scatter promoting faint galaxies into bright bins; illustrates Eddington-like effect.
- `paradox_resolution.png` — Three panels: (left) per-object residual distribution peaked slightly left of zero (FSPS faint on average); (middle) bar decomposition (blue: mean offset negative, orange: scatter positive, black: net effect); (right) per-model scatter magnitude in dex.
- `wang_jin_ratio_vs_flux.png` — Diagnostic: Wang/Jin agreement across flux.
- `wang_jin_count_diagnosis.png` — Sanity check comparing raw Wang, flux-corrected Wang, Jin raw against published counts; shows COSMOS sparsity above ~30 mJy.

## EVIDENCE_TABLE

**Complete vs. Incomplete Status:**

| Item | Status | Comment |
|------|--------|---------|
| Published SPIRE count comparison | Complete | FSPS overpredicts, especially 350/500 μm bright bins. |
| Per-object vs. count paradox | Complete & important | Large scatter promotes faint into bright. |
| Wang vs. Jin deblending check | Complete enough | Deblending scatter ≪ model scatter. |
| Cold SED diagnostic | Complete enough | FIR peak too redward; supports cold-dust interpretation. |
| Valiante bright spike | Closed enough | Exists in table; sensitivity tests robust. |
| Wang raw counts | Closed-ish | Use diagnostic only; exclude from bright-count formal benchmark. |
| Exact emissivity / Casey α | Not complete | Do not quote; data unstable. |
| D

##### P2 LINES 353-524 #####
# Analysis Notes Extraction

## THREAD
Validating pop-cosmos FIR number counts against far-infrared observations (Wang, Valiante, Jin) across 250/350/500 μm; identifying where model predictions exceed measurements.

## MOTIVATION
Establish whether discrepancies reflect fundamental SED/dust-physics issues, bright-end population problems, or observational catalogue/correction methodologies.

## OUTCOME
- **WORKED**: Valiante bright-end uptick confirmed present in prepared tables (not introduced by evaluator); ratio 2.17–2.75 across bands.
- **WORKED**: Wang/Jin flux consistency checked (median ratios 0.81–1.00); systematic offsets visible at long wavelengths.
- **NULL**: Scatter alone does not explain 350/500 μm residuals (~0.15–0.20 dex persists after accounting for 250 μm fit).
- **SUPERSEDED**: Older Wang/Jin repeated checks archived; meeting-prep section now canonical.

## NUMBERS
| Regime | Band | Model excess (dex) | Notes |
|--------|------|---|---|
| 10–30 mJy | 250 | +0.11 | mild |
| 30–100 mJy | 250 | +0.20 | mild/moderate |
| 100–300 mJy | 250 | +0.69 | bright problem |
| 10–30 mJy | 350 | +0.23 | – |
| 30–100 mJy | 350 | +0.23 | – |
| 100–300 mJy | 350 | +0.82 | strong |
| 10–30 mJy | 500 | +0.36 | – |
| 30–100 mJy | 500 | +0.55 | – |
| 100–300 mJy | 500 | +1.08 | strongest |

Valiante uptick ratios (244.2 → 300 mJy): 250 μm 2.75×, 350 μm 2.53×, 500 μm 2.17×.

## THESIS_VALUE
- **Bright-end overprediction systematic**: MAIN — quantifies failure mode across all SPIRE bands.
- **Long-wavelength worsening (250→500)**: MAIN — suggests dust SED shape or cold component issue.
- **Wang catalogue caveats**: APPENDIX — raw counts are prior-selected, not completeness-corrected.
- **Valiante bright bins as separate regime**: APPENDIX — rare/lensed/local population; do not pool into smooth SED interpretation.
- **Scatter explains 250 μm, not longer waves**: ONE_SENTENCE — clarifies limitation of template-tuning fixes.
- **L_IR energy-balance as validation**: CUT — only confirms code normalization; adds no independent constraint.

## FIGURES
- `outputs/valiante_2016_hatlas_dr1_number_counts_quicklook.png` — hand-entered Valiante DR1 (Tables 5, 8, 9) across GAMA9/12/15, 161.6 deg²; shows bright-bin uptick in all three SPIRE bands.
- `image/supervisor_meeting_prep_aug16_wang_valiante_sequel/1786910472681.png` — visual quicklook of same.

## EVIDENCE_TABLE
(Reproduced from slice, compacted):

| Source | Band | Flux regime | Result | Reason |
|--------|------|-------------|--------|--------|
| Wang raw | 250 | faint/mid | usable | enough detections |
| Wang raw | 350/500 | bright | sparse | small area, beam, deblending |
| Wang vs Jin | 250 | SNR≥3 | median ~1.00 | sensible flux/matching |
| Wang vs Jin | 350 | SNR≥3 | median ~0.87 | long-wave offset |
| Wang vs Jin | 500 | SNR≥3 | median ~0.81 | strongest offset |
| Valiante | 250/350/500 | bright | last bin up | rare/lensed/local or correction artifact |
| pop-cosmos FSPS | 250 | 10–100 mJy | +0.11–0.20 dex high | mild |
| pop-cosmos FSPS | 250–500 | 100–300 mJy | +0.69–1.08 dex high | bright/long-wave failure |

## OPEN
- Does Valiante bright uptick reflect real physics (rare low-z, lensing, field variance) or method artifact (binning, matrix inversion uncertainty)?
- Is long-wavelength excess (350/500 worse than 250) a dust emissivity/temperature issue, or does it track bright-end population mismatch?
- Does Casey-style template adjustment reduce scatter or address the systematic model-high offset?
- How much of Wang/Valiante disagreement stems from catalogue selection vs. intrinsic cosmic variance?

## QUOTABLE
- "Do not say the exact Casey alpha is measured. Preferred alpha changes with source selection; the safe claim is 'warmer ~30 K style templates improve the counts.'"
- "The uptick is already in the Valiante prepared source table, not introduced later by the pop-cosmos evaluator."
- "Bright bins may include rare local galaxies, lensed systems, or correction/binning effects. Do not overinterpret one bright bin as a smooth SED failure."

##### P2 LINES 525-564 #####
# HYPOTHESIS 5: Cross-Source Agreement Against FSPS

**THREAD**  
If multiple independent observational surveys (Clements, Oliver, Pearson, Valiante) show consistent deviation from FSPS predictions, the discrepancy likely lies in pop-cosmos model assumptions rather than individual catalogue errors.

**MOTIVATION**  
Triangulation across independent sources strengthens the case for systemic model failure over instrumental or calibration artifacts in any single dataset.

**OUTCOME**  
- Analysis framework set up: WORKED
- Cross-source comparison by band and flux regime: IN PROGRESS (evidence list structure defined but outcome not stated)

**NUMBERS**  
None reported in this slice.

**THESIS_VALUE**  
MAIN — Core logic for validating model failure; structures the entire multi-source comparison argument.

**FIGURES**  
- `popcosmos_wang_jin_fsps_flux_scatter.png` — Flux scatter plot
- `popcosmos_wang_jin_fsps_ratio_summary.png` — Ratio summary across sources
- `popcosmos_wang_jin_fsps_ratio_summary.csv` — Tabular ratios
- `popcosmos_wang_jin_fsps_match_audit.csv` — Match audit by source/band
- `popcosmos_model_family_flux_regime_summary.csv` — Model performance by regime
- `popcosmos_differential_count_evaluator_regime_summary.csv` — Differential counts by regime

**QUOTABLE**  
> "then the mismatch is more likely in pop-cosmos assumptions than in one observational catalogue."  
(Captures the inferential logic cleanly.)

**OPEN**  
- No explicit findings or quantitative results reported for this hypothesis in the slice.
- Status of cross-source comparison analysis unclear (setup present, outcome absent).