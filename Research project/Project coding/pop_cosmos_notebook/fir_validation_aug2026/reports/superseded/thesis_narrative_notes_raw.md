##### LINES 1-362 #####
# Research Log Slice Analysis

## THREAD
Validating pop-cosmos star formation rate predictions against empirical main-sequence relations and literature starburst statistics at z~1–2.

## MOTIVATION
Pop-cosmos SFR estimates must be compared to independent benchmarks (Speagle et al. 2014) and observational catalogs (Rodighiero et al. 2011) to verify the model's consistency before extending to far-infrared wavelengths.

## OUTCOME

| Task | Result | Status |
|------|--------|--------|
| Task 1: MS comparison to Speagle+2014 | Pop-cosmos SFRs systematically ~0.5 dex lower than Speagle baseline; trend consistent with MS behavior; offset largest at z<0.5, converges by z~3 | WORKED |
| Task 2: Starburst definition (ΔMS ≥0.6) | At z~1–2, starbursts rare by count (~0.3–0.6%), but contribute 6–7% of total SFR; high-mass slice (z~1.5–2.5) yields ~0.7–1.6% count, ~13–27% SFR share | WORKED |
| Task 2 literature comparison (Rodighiero+2011) | Pop-cosmos SFR share near target (~12.8% vs ~10% literature); number fraction lower (~0.7% vs ~2% literature); differences attributed to sample selection and MS definition | WORKED |
| Task 3: SFR definition audit | Documented pop-cosmos (100 Myr-averaged), Speagle (empirical fit, ~0.2 dex intrinsic width), COSMOS2020 (LePhare/EAZY, optical-only bias noted) | WORKED |

## THESIS_VALUE

| Item | Classification | Justification |
|------|---|---|
| Speagle MS offset (–0.5 dex median) | MAIN | Core validation result, redshift dependence important |
| Per-redshift residuals (z-binned ΔMS) | MAIN | Needed to show systematic trend, not random noise |
| Starburst fractions (0.26–0.7%) | APPENDIX | Supports broader SFR physics, but not primary focus |
| SFR definition audit (pop-cosmos vs Speagle vs COSMOS2020) | APPENDIX | Explains why comparisons are not 1:1, needed for methods |
| Rodighiero+2011 literature comparison | ONE_SENTENCE | Context for starburst tail; full literature matching deferred |
| Visual Speagle overplot (Task 1 visual) | MAIN | Direct visual validation replaces table-only result |

## FIGURES

- `log10(SFR)` vs `log10(M*)` hexbin plot (Task 1 visual cell): pop-cosmos density, Speagle MS line at median z, best-fit comparison line in bin 1≤z<2.

## TURNING_POINT

**Decision on sample size:** "Increase generated sample size (for example 5x to 10x more than 10,000 base samples)" — moved from N=2155 to N=7686 to stabilize tail counts and reduce small-number noise in starburst statistics.

## QUOTABLE

From motivation (Task 3 / wavelength dependence section): "Different telescopes see different parts of galaxy light. Dust can hide star formation in optical data, but infrared/sub-mm can reveal it." *(Captures the rationale for later multi-wavelength validation.)*

##### LINES 363-719 #####
# Research Log Analysis (Lines 363–719)

## THREAD
Testing whether starburst fractions in the pop-cosmos model remain consistent when real galaxies are filtered by far-infrared detection using the Wang 2024 long-wavelength catalog.

## MOTIVATION
pop-cosmos uses optical/NIR-derived SFRs, which can miss dusty star formation. The question: does adding a long-wavelength detection filter (SPIRE/SCUBA, SNR≥3) change the starburst fraction, and by how much?

## OUTCOME
**WORKED** — First pop-cosmos × Wang ID-matched comparison completed; starburst fractions computed for all-matched, long-detected, and not-long-detected subsets in two redshift/mass bins.

## THESIS_VALUE
**APPENDIX** — Methodological validation, shows setup works, but numbers flagged as suspect and require recalibration.

## FIGURES
- Script output (CSV): starburst fractions per bin subset (Bin A: 37,149 matched, 0.0215% SB fraction; Bin B: 15,807 matched, 0.0190% SB fraction); long-detected subsets show no qualitative shift.
- Comparison table: pop-cosmos mock (earlier, ~7–13% SB share) vs. real data + Wang match (~0.17–0.26% SB share) — orders of magnitude lower.

## TURNING_POINT
**SUSPENSION FOR RECALIBRATION** —

> "This is prob a calibration/definition mismatch signal (selection + MS baseline + SFR conventions), not a final physics conclusion yet. Next step: test alternative MS baseline choices and IMF/SFR harmonization before drawing physical conclusions."

Student recognizes the result is implausibly low and pauses inference pending control checks.

## QUOTABLE
"We likely got very low starburst/SFR-share numbers because this was a much stricter and different comparison than before, not because starbursts disappear physically."

Captures the student's reasoning: acknowledges data artifact over astrophysics.

##### LINES 720-1063 #####
# RESEARCH LOG SLICE ANALYSIS

## THREAD
Testing whether pop-cosmos SFR estimates are systematically lower than independent methods (LePhare, EAZY), and whether long-wavelength detections reveal dusty star-forming galaxies missed in optical/NIR.

## MOTIVATION
Low starburst fractions in early matched-sample tests raised the question: is the model predicting genuinely low SFR, or are the SFR estimates offset below independent benchmarks? This drives the need for direct SFR comparison and IR-based sensitivity testing.

## OUTCOME
- Direct SFR comparison (LePhare, EAZY vs pop-cosmos): **WORKED**. Pop-cosmos sits systematically lower (+0.22–0.36 dex with LePhare, +0.08–0.17 dex with EAZY) across Bin A and B and narrower redshift slices.
- Wang long-wavelength flux correlation with pop-cosmos SFR: **WORKED** (partial). Detected that long-wavelength objects are higher SFR and higher mass, but no direct SFR comparison yet (Wang file lacks SFR column).
- Narrower redshift binning test: **WORKED**. Pattern holds in z-slices 1.0–1.5 and 1.5–2.0, offsetting stronger in lower bin.
- Rodighiero optical/NIR stress test: **ABANDONED** (superseded by simpler direct SFR approach).
- Spec-z benchmarking setup: **NULL**. Spec-z field not found in local files; deferred pending external compilation.
- Mass/luminosity function (`1/V_max`): **ABANDONED**. Identified as sensible future step but deprioritized pending sample-definition lock-down.

## THESIS_VALUE
- Direct SFR offsets vs LePhare/EAZY: **MAIN**. Establishes systematic bias in model SFR predictions. Direct method comparison most defensible.
- Wang long-wavelength flux correlation: **APPENDIX**. Qualitative confirmation that high-SFR/high-mass objects have brighter MIR/FIR, but not a standalone result.
- Narrower redshift bins: **MAIN** (if included in final comparison table). Validates offset is not binning artifact.
- Speagle MS caveats (quenched contamination, sigma clipping rules): **ONE_SENTENCE**. Important methodological guardrail; mention during methods.
- Boris MIR/IRAC data handoff: **ONE_SENTENCE**. Enables next validation phase; state as setup.

## FIGURES
- No figures explicitly created in this slice; tables of SFR offsets by bin and wavelength detection mentioned but filenames not given.

## TURNING_POINT
"This week I switched to a simpler comparison idea: same matched galaxies, compare the SFR values directly between methods, do not go through the starburst threshold first." — Pivots from starburst-label transitions to direct SFR offset as the cleaner diagnostic of model bias.

## QUOTABLE
"LePhare is systematically higher in SFR than pop-cosmos on the same matched galaxies. EAZY is also higher than pop-cosmos, but the offset is smaller. So the very low pop-cosmos starburst fractions are at least partly consistent with pop-cosmos sitting lower in SFR than the COSMOS2020 estimators." — Frames the offset discovery as an *explanation* for low starburst fractions, anchoring the thesis narrative to a concrete comparison result.

##### LINES 1064-1403 #####
# Research Log Slice Analysis

**THREAD**  
Inventory and evaluate which MIR bands (Ch1–Ch4, MIPS24) are available and usable for pop-cosmos validation against COSMOS2020 observations.

**MOTIVATION**  
Professor asked whether model fluxes could be loaded for validation; need to assess coverage, data quality, and residuals to determine which bands are reliable starting points.

**OUTCOME**  
- Ch1/Ch2: high coverage (95%, 81%), small median residuals (+0.020, −0.012 mag), tight scatter → **WORKED**
- Ch3/Ch4: lower coverage (55%, 22%), larger residuals and scatter, sensitive to IRAC vs SPLASH choice → **WORKED** (but noisier)
- MIPS24: 0% coverage in current file → **NULL**

**THESIS_VALUE**  
- Ch1/Ch2 validation: **MAIN** — core sanity check on model pipeline behavior.
- Ch3/Ch4 evaluation: **MAIN** — establishes extension bands as exploratory, sets stage for FIR scaling.
- Coverage inventory: **ONE_SENTENCE** — explains why Ch1/Ch2 are primary and Ch3/Ch4 secondary.
- Boris's seven figures: **APPENDIX** — internal consistency checks; support method but are not direct data-model comparisons.

**FIGURES**  
- `fig1_speculator_vs_stored.png` — Speculator vs stored Ch1/Ch2 photometry; tight 1:1 agreement.
- `fig2_residuals_vs_properties.png` — Speculator−Stored residuals vs redshift, mass, dust, AGN; mild systematic structure.
- `fig3_coverage_map.png` — Model wavelength coverage vs redshift; shows Ch1/Ch2 well-covered, Ch3/Ch4 patchy, MIPS24 absent.
- `fig4_color_magnitude.png` — Predicted Ch1 distribution, Ch1−Ch2 color, IRAC color-color; sensible galaxy population structure.
- `fig5_speculator_vs_photulator.png` — Speculator vs Photulator for Ch1/Ch2; essentially perfect agreement.
- `fig6_example_seds.png` — Example SEDs with IRAC/MIPS filters; illustrates why longer wavelengths harder to model.
- `fig7_photulator_vs_stored.png` — Photulator−Stored residuals vs redshift; small offsets but redshift-dependent systematics visible.

**TURNING_POINT**  
"My current view is: Ch1/Ch2 = strong validation/sanity-check bands; Ch3/Ch4 = promising extension bands, but noisier and more sensitive to which observed product I use; MIPS24 = potentially very useful next target if Boris can synthesise it properly."  
→ Establishes the three-tier validation strategy that structures the rest of the project.

**QUOTABLE**  
"Ch1 and Ch2 are close enough to the fitted regime that they let me check whether the modelling pipeline is behaving sensibly; Ch3 and Ch4 start to push further out in wavelength, so they are more like a real extension test."

##### LINES 1404-1743 #####
# Research Log Extract: IRAC Validation & Obscured-SFR Groundwork

## THREAD
Validating pop-cosmos IRAC Ch1/Ch2 predictions against COSMOS2020 observations, then establishing methodology for comparing model SFRs to FIR/IR-derived obscured star formation.

## MOTIVATION
Direct observed-vs-model comparison for the two nearest-IR bands was missing; Boris's earlier plots were internal consistency checks. Also: student needed to understand how recent pop-cosmos papers handle mass/SFR estimates (not classic 1/Vmax) before designing an IR-based SFR validation workflow.

## OUTCOME

**IRAC validation:**
- Ch1: N=423,272, median residual +0.020 mag, MAD 0.084 mag — WORKED
- Ch2: N=414,272, median residual −0.012 mag, MAD 0.041 mag — WORKED
- Both bands track observed magnitudes well; Ch2 is tighter and cleaner than Ch1
- Residuals stable across most redshift range; high-z tail (z>5) noisier and has fewer objects

**Redshift histogram check:**
- Main pile-up at z~0.8–1.2, not z~3.5 — WORKED
- Worst 5% residuals concentrated at very high z (z>5, low counts) and low z for Ch1 (z~0.2–0.5) — WORKED

**Pop-cosmos methodology review:**
- Recent papers do NOT use classical per-galaxy 1/Vmax weighting — WORKED
- Instead: apply completeness cuts, normalize to COSMOS area/counts, histogram/integrate properties in redshift bins — WORKED

**IMF & Kennicutt groundwork:**
- Adopted Chabrier as working standard (matches COSMOS2020 SED fits)
- Retrieved Kennicutt 1998 IR calibration (Salpeter): L_IR [L☉] ≈ 5.8×10⁹ × SFR [M☉/yr] — WORKED
- Identified pop-cosmos SFR as 100 Myr average (bins 0–30 & 30–100 Myr) — WORKED
- Selected Jin et al. 2018 super-deblended COSMOS catalog as next comparison source (has direct L_IR, FIR-derived SFRs) — WORKED

## THESIS_VALUE

| Item | Status |
|------|--------|
| IRAC direct validation plots (Ch1, Ch2, residuals vs z) | MAIN — core validation result |
| Ch2 is tighter than Ch1 | MAIN — key model-quality finding |
| Redshift histogram check (worst residuals at z>5) | APPENDIX — supports high-z caveats |
| Pop-cosmos ≠ 1/Vmax methodology note | ONE_SENTENCE — clarify methods before SFR work |
| IMF choice (Chabrier) & Kennicutt setup | APPENDIX — documents SFR conversion recipe |
| Jin 2018 selection as validation comparison | APPENDIX — explains next-step catalog choice |

## FIGURES

- `outputs/popcosmos_irac_redshift_histograms.png` — Full matched-sample redshift distribution for Ch1 and Ch2; shows main pile-up z~0.8–1.2
- `outputs/popcosmos_irac_worst_residual_redshift_histograms.png` — Worst-residual (top 5%) redshift subsets; concentration at z>5 and low-z

(Note: No observed-vs-model scatter plots explicitly named, but referred to as "three plots" made during this work.)

## TURNING_POINT

"So if I want the cleanest simple validation statement right now, it is probably: pop-cosmos does a decent job in both IRAC Ch1 and Ch2, and the agreement looks especially strong in Ch2."

This anchored the validation confidence level before moving to SFR comparisons.

Also: decision to use **Jin et al. 2018 super-deblended** (not Wang 2024) for obscured-SFR test because it has direct L_IR column, not just deblended fluxes.

## QUOTABLE

"So the safe workflow is: (1) write the Kennicutt relation in its original Salpeter form; (2) convert it to a Chabrier-equivalent form before comparing across modern catalogs. So I am not going to mix IMF conventions silently."

*Reasoning:* Clear articulation that IMF conversions must be explicit and tracked, not silent; shows methodological care around literature constants.

##### LINES 1744-2083 #####
# Research Log Analysis (Lines 1744–2083)

## THREAD
Testing whether pop-cosmos model infrared luminosity (`L_IR`) tracks observed-frame star-formation rate and long-wavelength detections sensibly.

## MOTIVATION
The student needed a quantitative bridge from optical/NIR fitting to FIR-side validation. Direct comparison to an observed `L_IR` catalog didn't yet exist, so they first checked whether the model-derived `L_IR` from FSPS posterior medians correlated with pop-cosmos SFR and showed expected behavior in long-wavelength-detected subsets.

## OUTCOME
**WORKED** — Model `L_IR` correlates strongly with pop-cosmos SFR (ρ = 0.82–0.95 across bins). Long-wavelength-detected galaxies sit systematically higher in model `L_IR` (~0.65 dex above non-detections), consistent with physics. However, single-band flux correlations are weak (ρ = 0.16–0.23), and model `L_IR` sits 0.3–0.6 dex above the simple Kennicutt reference line. A follow-up redshift diagnostic revealed this discrepancy is partly redshift-dependent (observed vs. rest-frame bandpass shifting).

## THESIS_VALUE
**MAIN** — Validates that model FIR predictions respond sensibly to SFR and observational data before building the full obscured-SFR comparison.

## FIGURES
- `popcosmos_lir_vs_sfr.png` — Model `L_IR` vs. pop-cosmos SFR; dense cloud sits above Kennicutt reference line
- `popcosmos_lir_offset_by_redshift.png` — Median offset from Kennicutt grows z=0.25→1.75, then declines; offset peaks ~0.44 dex at z~1.75
- `popcosmos_wang_lir_vs_flux.png` — Wang-matched subset: long-detected galaxies shifted to higher `L_IR`; single-band flux trends weak but positive
- `popcosmos_wang_lir_fluxratio_vs_redshift.png` — `L_IR` / Wang flux ratio rises with redshift (ρ = 0.63–0.75); explains part of single-band scatter

## TURNING_POINT
"This is the first real step from 'pop-cosmos optical/NIR fit' to 'does pop-cosmos imply sensible FIR-side dusty emission?'" — Confirms the model is ready for external FIR validation; pivot is to find an observed `L_IR` or IR-SFR catalog for direct comparison.

## QUOTABLE
"What assumptions is the Kennicutt model making??, pop cosmos wrong in FIR?.." — Captures the productive confusion that a 0.3–0.6 dex offset is large enough to matter, but too systematic to ignore without understanding its source.

##### LINES 2084-2442 #####
# RESEARCH LOG SLICE ANALYSIS (lines 2084–2442)

## THREAD
Testing whether pop-cosmos model L_IR reconciles with observed single-band FIR flux correlations across redshift bins.

## MOTIVATION
Wang et al. single-band (250 µm, 850 µm) correlations with model L_IR showed weak scatter; student needed to understand whether this reflected model failure or rest-frame SED effects at different redshifts.

## OUTCOME
- **Redshift binning analysis**: WORKED. Median flux ratios increase monotonically with z for both 250 µm and 850 µm bands.
- **Interpretation of weak correlations**: SUPERSEDED. Recognized as partly expected given that a single observed-frame band traces different rest-frame SED regions across the sample; reframed as sanity check rather than validation.
- **Planning reset toward apples-to-apples comparisons**: WORKED. Identified that Wang comparison is useful but not cleanest final metric.

## THESIS_VALUE

**Redshift binning results**: APPENDIX — shows the observed-frame effect drives part of scatter; supports interpretation but not primary narrative.

**Reframing of Wang test**: MAIN — critical pivot point that clears a conceptual logjam; student recognized that weak single-band correlations do not falsify pop-cosmos.

**Ranked priority list for next comparisons**: ONE_SENTENCE — use to frame transition to proper external datasets (VLA-COSMOS 3 GHz, Jin et al. FIR catalog) in methods/results.

## FIGURES
- `outputs/popcosmos_wang_lir_fluxratio_redshift_bins.csv` — median flux ratios by redshift bin for 250 µm and 850 µm; shows monotonic increase with z.

## TURNING_POINT
**"This makes me less worried that the low direct Spearman coefficients automatically mean pop-cosmos is failing."** — Student recognized that weak L_IR vs single-band correlations need not indicate model failure; redirected effort toward same-quantity comparisons (observed L_IR vs model L_IR). This reframing unlocked the planning reset.

## QUOTABLE
**"The main question now is not 'what else can I plot?' but: what comparison is actually close to apples-to-apples."** — Captures the student's own shift from exploratory to hypothesis-driven validation strategy.

##### LINES 2443-2808 #####
# Research Log Analysis: Lines 2443–2808

---

## THREAD
Cataloging public benchmark datasets and literature for multi-wavelength validation of pop-cosmos, then pivoting validation strategy from physical quantities to observed-frame counts with possible agentic automation.

---

## MOTIVATION
Needed high-quality observed FIR/submm/radio/X-ray data to compare against model predictions. Also responding to advisor feedback that validation need not require dust-template conversions — direct flux counts are cleaner. Separately exploring whether AI agents could automate repetitive benchmark-building and model-intervention loops.

---

## OUTCOME

**Data discovery: WORKED**
- Identified Wang et al. 2024 (deblended 24–500 µm + 850 µm COSMOS), Jin et al. 2018 (super-deblended FIR/(sub)mm), Delhaize 2017 (infrared-radio correlation), Civano 2016 / Marchesi 2016 (Chandra COSMOS catalogs), VLA-COSMOS 3 GHz AGN catalog.
- Each already ALMA-validated or provides ready-made AGN/SFR flags; no need to rebuild data curation.

**Strategy rerank: WORKED**
- Shifted priority from `L_IR`/`SFR_IR` physical comparison to **observed-flux number counts** as primary validation.
- Ranked: (1) observed counts, (2) physical quantities, (3) AGN validation.

**AI agent conceptualization: ABANDONED** (for this thesis)
- Sketched agentic pipeline (data/literature agent → benchmark builder → analysis agent → critic → report) and parameter-intervention loop.
- Recognized scope creep: agent architecture belongs in separate methodology paper, not thesis. Kept one concrete use case (number-counts validation loop) as possible extension, not core.

---

## THESIS_VALUE

| Item | Value | Justification |
|------|-------|---|
| Public benchmark catalogs (Wang, Jin, VLA, Chandra) | MAIN | Concrete observed comparison targets. |
| Observed-count strategy shift | ONE_SENTENCE | Frames validation approach; motivates results section. |
| AI agent pipeline sketch | CUT | Out of scope; premature for this thesis. |
| Parameter-intervention loop idea | APPENDIX | Possible future direction; too speculative here. |

---

## FIGURES
None in this slice.

---

## TURNING_POINT

**May 25 entry:**
> "the validation does not have to be only on physical quantities like `L_IR` or SFR. It can also be on observed quantities like number counts."

Advisor feedback that redirected entire validation strategy away from template-dependent `L_IR` conversions toward direct observed-frame flux comparisons. This decouples thesis from SED-fitting assumptions.

---

## QUOTABLE

> "The cleanest final FIR comparison is still **observed `L_IR` vs model `L_IR`**" → *Student initially committed to physical-space validation.*

> "This gives me the AI/recursive-improvement story without making the project fragile." → *Student recognized tension between agentic automation and scientific rigor; chose human-in-the-loop over unsupervised agent.*

##### LINES 2809-3147 #####
# Research Log Extract: Lines 2809–3147

## THREAD
Testing diagnostic reweighting and agentic evaluation loops to identify which galaxy populations cause pop-cosmos/far-infrared observational mismatch without retraining the model.

## MOTIVATION
Student recognized that blanket pass/fail validation is less useful than diagnosis: "Instead of just asking whether pop-cosmos passes or fails, I ask what type of galaxy would need to change for it to pass." Sought a bridge from validation to actionable model critique and an employer-friendly ML angle.

## OUTCOME

**Post-hoc reweighting:** WORKED (conceptual prototype)
- Designed method: fix pop-cosmos, reweight high-dust/high-SFR/AGN/z-sliced galaxy subpopulations, recompute FIR number counts, score against observed benchmarks.
- Established that reweighting is diagnostic, not a new physical truth.

**Recursive evaluator loop:** WORKED (design phase)
- Specified AlphaEvolve-inspired loop: propose intervention → run → score → log → iterate.
- Identified scoring metrics: number-count χ² mismatch, median residuals, Spearman correlation, starburst fraction/SFR share.
- Mapped reweightable parameters: dust, L_IR, SFR, AGN weights; z-splits; SNR/completeness cuts.

**Baseline validation summary:** WORKED (quantified)
- Pop-cosmos main sequence shape is plausible; normalization systematically low, especially z<1 (median ΔMS = −0.5 to −0.7 dex; ~3–5.5× too low in SFR).
- Starburst fraction underpredicted (~0.3–0.7% vs. classical ~2%), but starburst SFR share is plausible (~6–13%).

## THESIS_VALUE

**Post-hoc reweighting:** MAIN — Core diagnostic method bridging validation to population-level inference.

**Evaluator loop design:** MAIN — Procedural framework for systematic population testing and scoring.

**Baseline quantification (Speagle, starbursts):** MAIN — Establishes what the model gets wrong, motivating intervention.

## FIGURES

No plots generated in this slice. Embedded reference table shows evaluator loop example (baseline vs. high-dust/SFR/AGN reweights) and Delta_MS by redshift bin (z=0–4, N up to 1023, ΔMS range −0.7 to −0.2 dex).

## QUOTABLE

"Maybe pop-cosmos has the right *type* of dusty galaxy, but not enough of them."
— Captures the reweighting diagnostic logic succinctly.

"The shape is okay-ish, but the normalization is low, especially at low redshift."
— Clear summary of main-sequence finding.

##### LINES 3148-3514 #####
# THREAD
Testing whether pop-cosmos's weak FIR tail can be explained by using an ALESS submillimeter-galaxy template SED to predict observed fluxes from the model's integrated infrared luminosity.

# MOTIVATION
Prior sections found that pop-cosmos SFR is lower than COSMOS2020 and lacks a strong starburst tail, and raw FIR flux correlations are weak. The question: if high-SFR pop-cosmos galaxies have submillimeter-like dust geometry (ALESS shape), do their predicted fluxes match Wang observations?

# OUTCOME
NULL (incomplete). Generated predicted fluxes for high-SFR galaxies by scaling ALESS template to pop-cosmos `L_IR`, but no quantitative comparison or evaluation against Wang data is present in this slice.

# THESIS_VALUE
APPENDIX — validates methodology for FIR prediction, but results not yet analyzed.

# FIGURES
- `popcosmos_aless_template_shape.png` — ALESS average/bright/faint rest-frame SED; peaks ~87 µm.
- `popcosmos_aless_scaled_seds_by_sfr.png` — templates scaled to pop-cosmos `L_IR` by SFR threshold.
- `popcosmos_aless_predicted_flux_distributions.png` — predicted observed fluxes (24–850 µm).
- `popcosmos_aless_wang_observed_vs_template_flux.png` — predicted vs. Wang observed; not yet summarized.
- Summary CSVs output but contents not quoted.

# TURNING_POINT
Yes. The shift from raw single-band FIR validation to template-based prediction:
> "I am not rebuilding pop-cosmos. I am asking which types of galaxies would need to become more/less common for pop-cosmos to match the longer-wavelength data."

This reframes the task from "is the model right?" to "what reweighting would close the gap?"

# QUOTABLE
"pop-cosmos seems strong in the fitted optical/NIR/IRAC regime and broadly sensible in how SFR maps to model `L_IR`, but the high-SFR / dusty / FIR-bright tail is the place to investigate."

##### LINES 3515-3894 #####
# Research Log Extract: Lines 3515–3894

## THREAD
Testing whether pop-cosmos/FSPS SEDs can predict observed far-infrared fluxes, and whether ALESS template provides a useful comparison for high-SFR objects.

## MOTIVATION
To move from template-patching (ALESS) to actual model SEDs, establishing whether pop-cosmos predicts the right FIR brightness and enabling quantitative comparison to Wang observed data.

## OUTCOME
- ALESS-scaled predictions: underpredicts Wang 250/850 µm for `SFR >= 10` (median log ratio −0.17 to −0.47 dex); improves for `SFR >= 100` (~−0.09 dex). **WORKED**
- Full FSPS SED prediction at 250 µm: obtained Boris's `fsps_map_median_full.h5` file; matches 6,221 pop-cosmos to Wang detections; median underprediction 0.16 dex; Spearman correlation 0.235 (weak). **WORKED**
- Bright-end 250 µm counts: FSPS predicts ~1.8–2× more sources than Wang at 10–20 mJy; ALESS underpredicts further. **WORKED**
- Top-5 SFR galaxies: FSPS/ALESS flux ratios range 0.28–0.69; show ALESS is rough template, not true pop-cosmos shape. **WORKED**

## THESIS_VALUE
- Full-FSPS 250 µm comparison: **MAIN** — direct model validation against observations.
- ALESS-template comparison: **APPENDIX** — shows why SFR-only cuts insufficient; motivates refined subset selection.
- Bright-end count mismatch table: **MAIN** — quantifies prediction error as function of flux threshold.
- Top-5 SED shapes: **APPENDIX** — illustrates scatter in FIR morphology, not all SMG-like.

## FIGURES
- `popcosmos_full_sed_top5_vs_aless.png` — Rest-frame FSPS SEDs (5 highest-SFR) overlaid with ALESS templates scaled to each L_IR.
- `popcosmos_full_sed_top5_shape_normalized.png` — Same, normalized to compare shape only.
- `popcosmos_full_sed_250_counts.png` — Cumulative 250 µm number counts: FSPS, ALESS, Wang observed.
- `popcosmos_full_sed_wang_250_compare.png` — Predicted vs. observed F250 scatter plot.
- `popcosmos_aless_predicted_flux_distributions.png` — Distribution of predicted 250/850 µm fluxes by SFR cut (earlier slice).

## TURNING_POINT
**"Use the full FSPS SED as the main model prediction. Use ALESS as a comparison/check, not as the main model."** This marks shift from template-patching toward genuine population synthesis validation, enabling systematic decomposition of count mismatch by redshift/SFR/dust.

## QUOTABLE
**"Even for the most extreme SFR objects, the assumed FIR shape matters a lot."** — Captures the insight that SFR rank alone does not select ALESS-like objects; morphological selection needed.

**"Validate pop-cosmos beyond optical/NIR using observed FIR quantities."** — Student's summary of thesis aim; connects FIR validation to broader model assessment.

##### LINES 3895-4252 #####
# Research Log Extract (18 June – 22 June)

## THREAD
Diagnosing why pop-cosmos/FSPS FIR SEDs peak at wrong wavelength compared to observed galaxies.

## MOTIVATION
Optical/NIR validation showed `L_IR` is approximately correct, but FIR number counts and SED shapes suggested a systematic problem. Dave and Boris's feedback identified the specific issue: FSPS applies a default dust temperature from energy-balance closure that does not match far-IR data, even though COSMOS photometry only constrains to IRAC.

## OUTCOME

**WORKED**: 
- Pop-cosmos peaks ~135–160 μm (cooler), ALESS ~80–100 μm (warmer)
- Top 5 SFR sources are luminous (log L_IR 12.8–14.1), so cooler peaks are not a low-luminosity artifact
- Bright-count mismatch grows with wavelength (250→350→500→850 μm), signature of excess cold dust
- Per-object median FSPS flux slightly underestimates Wang, but FSPS predicts too many bright sources overall—a selection/scatter effect
- Extreme-SFR tail (>1000 M☉/yr, N=5) shows elevated AGN-like flags; likely contaminated by attenuation/AGN degeneracy

**SUPERSEDED**: 
- 30–100 μm narrow spikes identified as nebular fine-structure lines ([OIII] etc.); cosmetic for broad-band comparison, not the main issue

## THESIS_VALUE

| Item | Classification | Justification |
|------|---|---|
| FIR peak wavelength mismatch | MAIN | Core validation failure; motivates temperature model fix |
| Bright-count ladder at 350/500/850 μm | MAIN | Quantifies the redshift of flux into long wavelengths |
| Extreme-SFR tail with high AGN flags | APPENDIX | Signals contamination; justifies separate treatment or exclusion |
| Nebular line features | CUT | Identified but negligible for photometry |
| Per-object vs bright-count paradox | ONE_SENTENCE | Explain as selection/scatter effect; motivates next diagnostic |

## FIGURES

- `popcosmos_full_sed_multiband_counts.png` — FSPS (blue) vs ALESS (orange) vs Wang (black) number counts at 250/350/500/850 μm; mismatch grows at longer wavelengths
- `popcosmos_full_sed_wang_multiband_compare.png` (equal axes) — Per-object FSPS vs Wang flux; diagonal line is perfect match
- `popcosmos_full_sed_sfr_rank_samples.png` — High/median/low-SFR objects; high-SFR peaks red-shifted
- `popcosmos_full_sed_sfr_rank_samples_normalized.png` — Shape-only comparison; SED shape does not strongly correlate with SFR rank
- `popcosmos_full_sed_fsps_vs_aless_predictions.png` — FSPS vs ALESS predictions per object; FSPS consistently above at 350+ μm

## TURNING_POINT

> "the model may have roughly the right total dust luminosity, but puts it at the wrong wavelengths."  
> "FIR validation is finding something optical/NIR validation could not see."

This reframes the failure: not a normalization problem, but a shape problem. Led to explicit next steps: replace FIR bump template, score by counts, loop.

## QUOTABLE

> "pop-cosmos gets these SEDs from FSPS with energy balance. Energy balance fixes total L_IR. But the dust temperature / far-IR shape is basically not fitted by COSMOS data. COSMOS only really constrains out to IRAC, not the far-IR."

(Boris, quoted by student) — Crystallizes why optical validation missed this: the far-IR is unconstrained in the training data.

##### LINES 4253-4592 #####
# Research Log Extract: Validation Against External FIR Number Counts

**THREAD:**  
Assembling external far-infrared number-count datasets (H-ATLAS, HerMES, SPIRE Dark Field) to compare pop-cosmos predictions against real observed counts across multiple surveys.

**MOTIVATION:**  
Wang/COSMOS alone is too small to constrain the bright and faint tails of the number-count distribution; external surveys cover different areas and depths, allowing the model to be validated across the full flux range and avoiding selection-bias artifacts unique to any single field.

**OUTCOME:**  
- Added Jin et al. 2018 super-deblended COSMOS catalogue (195k sources, FIR fluxes 250–850 μm with priors-based deblending) — WORKED
- Generated median SEDs by SFR bins and AGN parameter — WORKED  
- Produced Wang bright-cut residual plot (model vs. observed flux for SNR ≥ 3, flux ≥ 5 mJy) — WORKED  
- Computed FSPS vs. ALESS comparison across wavelengths — WORKED  
- Assembled external count data: Clements 2010 (H-ATLAS 14 deg²), Valiante 2016 (H-ATLAS DR1 161.6 deg²), Oliver 2010 (HerMES), Pearson 2025 (SPIRE Dark Field) — WORKED  
- Generated first overlay plot (pop-cosmos, Wang, and external counts as N(>S) per deg²) — WORKED

**THESIS_VALUE:**  

| Item | Value | Justification |
|------|-------|---|
| Jin deblended catalogue + cross-match | MAIN | Second independent per-object catalogue validates SED predictions |
| Median SEDs by SFR | MAIN | Bulk population shape confirms cold FIR feature is not noise |
| AGN parameter split | MAIN | AGN enrichment explains hot mid-IR excess; lines up with intuition |
| Wang bright-cut bias plot | MAIN | Model brightness distribution differs from observed; model may misplace FIR light |
| FSPS vs. ALESS comparison | MAIN | Quantifies wavelength-dependent cold-dust offset |
| External count assembly | MAIN | Enables full validation across flux range and areas |
| First external overlay | MAIN | FSPS closer to external counts than ALESS at 250 μm; story more nuanced than global overprediction |
| Flux limit / Eddington bias note | APPENDIX | Selection effects and confusion dominate below ~10 mJy |

**FIGURES:**  
- `popcosmos_full_sed_median_sfr_seds.png` — Median νLν/L_IR by SFR bin (low/normal/high/extreme)  
- `popcosmos_full_sed_agn_parameter_median_seds.png` — Median SED split by AGN-like parameter; shows mid-IR hot continuum in high-AGN tail  
- `popcosmos_full_sed_wang_brightcut_flux_bias.png` — Log₁₀(model/Wang) vs. Wang flux; FSPS often below Wang detections  
- `popcosmos_full_sed_fsps_vs_aless_binned_bias.png` — Log₁₀(FSPS/ALESS) vs. ALESS flux; FSPS systematically higher at 350/500/850 μm  
- First external counts overlay (N(>S) per deg² across Clements H-ATLAS, Oliver HerMES, Pearson Dark Field, Wang, pop-cosmos FSPS/ALESS)

**TURNING_POINT:**  
> "that means the model may be putting FIR brightness on the wrong objects, not just being globally high or low."

This reframes the validation problem from global flux balance to per-object SED realism and shifts focus toward external counts that sample different areas and depths.

**QUOTABLE:**  
> "So Wang alone is not enough for number-count validation, especially rare bright objects."  
(Motivates the decision to incorporate H-ATLAS and wider-area surveys.)

##### LINES 4593-4976 #####
# RESEARCH LOG SLICE EXTRACTION

## THREAD
Standardizing external far-infrared galaxy number-count data into differential format for model comparison.

## MOTIVATION
Prof. Clements feedback: differential counts `dN/dS` are superior to integral counts `N(>S)` for model comparisons because each flux bin has independent errors, whereas integral counts reuse sources across thresholds (correlated errors). Need a unified comparison baseline before plotting pop-cosmos predictions.

## OUTCOME
**WORKED** — Compiled four literature differential-count datasets into single standardized CSV:
- Clements/H-ATLAS 2010
- Oliver/HerMES 2010  
- Pearson/SPIRE Dark Field 2025 (SUSSEXtractor + XID tables)
- Varnish/SPIRE Dark Field II 2025 (P(D) Table 4)

All converted to common unit: `S^2.5 dN/dS [Jy^1.5 deg^-2]`

Fixed unit conversion bug on Pearson data (had used `(1e-3)^2.5` instead of `(1e-3)^1.5` because Pearson already Euclidean-normalized).

## FIGURES
- [external_spire_differential_counts_fullrange.png](../outputs/external_spire_differential_counts_fullrange.png) — Compiled external SPIRE differential counts, all literature datasets on same axes.

## THESIS_VALUE
**MAIN** — This is the observational ruler for the central number-count validation.

## TURNING_POINT
"Number counts feel like the best route because they test observed fluxes directly, without having to turn real 250/350/500 um fluxes into more model-dependent physical quantities like `L_IR` or SFR."

This reframes the validation strategy away from SED-shape fits toward population-level flux distributions.

---

## THREAD (Second sequence)
Clarifying Wang et al. 2025 deblended catalogue limitations and correcting COSMOS survey area for number-count normalization.

## MOTIVATION
Wang provides observed SPIRE fluxes via XID+ progressive deblending, but counts are prior-selected and potentially incomplete. Must establish whether raw Wang catalogue counts are suitable as a direct comparison to pop-cosmos predictions, or whether published differential counts from dedicated surveys are cleaner.

## OUTCOME
**WORKED** — Identified Wang systematic limitations:
- Prior-selected (COSMOS2020/radio), not blind extraction
- SNR ≥ 3 cut removes faint/uncertain sources
- Faint SPIRE flux underestimation: ~10% at 250 μm, ~15% at 350 μm, ~25% at 500 μm
- Survey area correction: effective area is 1.278 deg² (COSMOS2020/Farmer FLAG_COMBINED = 0), not 2.0 deg²
  - Current Wang count curves artificially low by factor 2.0/1.278 ≈ 1.56

## THESIS_VALUE
**APPENDIX** — Use Wang primarily for per-object flux matching; label any population counts as "raw catalogue" with caveats, not completeness-corrected results.

## QUOTABLE
"Wang is not a blind source catalogue … it is an XID+ deblended catalogue … this is good because Herschel has poor resolution and lots of blending but it also means Wang counts are affected by the prior list, SED-predicted source selection, deblending assumptions, and completeness."

##### LINES 4977-5321 #####
# Research Log Analysis (Lines 4977–5321)

**THREAD:** Testing whether pop-cosmos FIR SED shape is too cold by swapping dust templates and measuring effect on far-infrared number counts.

**MOTIVATION:** Pop-cosmos showed elevated bright-end 350/500 µm counts compared to external surveys; the hypothesis is that the FSPS dust SED is too cold/rigid. ALESS templates (empirical SMG SEDs with ~40 K dust) offered a warmer alternative to bracket the problem space.

**OUTCOME:**
- ALESS/FSPS hybrid SED method — **WORKED.** Hybrid SED (25/50/75% ALESS mixture) moves bright 350/500 µm counts downward toward Wang/external data. Rest-frame hybrid implementation verified FSPS integral matches stored L_IR to 0.999994 median ratio.
- Area correction discovered — **WORKED.** Wang survey area is 1.278 deg² (not 2.0 deg²); old Wang curves underestimated counts by ~56%.
- Wang catalogue characterization — **WORKED.** Identified Wang as raw XID+ deblended catalogue (not a published corrected count table), with SNR≥3 cut that suppresses faint detections especially at 350/500/850 µm.
- Template evaluator workflow design — **ABANDONED** (deferred; replaced by focused hybrid tests first).

**THESIS_VALUE:**
- Hybrid SED experiment: **MAIN.** Directly tests the hypothesis and quantifies lever arm.
- ALESS/FSPS variants: **MAIN.** Shows empirical templates bracket plausible FIR shapes.
- Area/Wang catalogue notes: **APPENDIX.** Explains why Wang disagreed; clarifies data source limitations.
- Template options survey (CIGALE, Dale, Draine, Casey, THEMIS): **APPENDIX.** Documents alternatives considered for final evaluator.

**FIGURES:**
- `popcosmos_aless_variant_differential_counts.png` — Differential counts: FSPS vs ALESS (average/bright/faint) at 250/350/500 µm.
- `popcosmos_hybrid_sed_differential_counts.png` — Differential counts for α = 0.25/0.50/0.75 hybrids (FSPS + α·ALESS).
- `popcosmos_restframe_hybrid_sed_examples.png` — Rest-frame SED visualization: FSPS (blue), ALESS (dashed yellow), 50% hybrid (orange).
- `popcosmos_restframe_hybrid_sed_differential_counts.png` — Final hybrid count comparison with Wang reference.

**TURNING_POINT:** 
> "pop-cosmos is strong in the optical/near-IR where it was designed and constrained… the extension exposes a specific weakness: the FIR dust SED shape/temperature is too rigid/cold for some populations… empirical/template dust layers can improve or bracket the mismatch without rebuilding the whole galaxy catalogue."

This reframed the problem from "model is wrong globally" to "a swappable dust-template layer can fix the FIR extension."

**QUOTABLE:**
> "the hybrid moves in the right direction… this supports the idea that the FIR SED shape / dust temperature is the thing to fix"

(Student's own assessment that FIR dust temperature/shape is the actionable lever, supported by the hybrid experiment.)

##### LINES 5322-5688 #####
# Research Log Slice Analysis

**THREAD**  
Building a differential-count evaluator to compare pop-cosmos model predictions against published far-infrared galaxy counts, and using it to select between FSPS and ALESS dust templates.

**MOTIVATION**  
Differential counts span orders of magnitude and are closer to independent than cumulative counts. Chi-square comparison in log space with a small error floor lets the evaluator weight large and small counts fairly without tiny paper uncertainties dominating.

**OUTCOME**  
- Evaluator code built and tested across five published count sources (Clements, Glenn, Oliver, Pearson SUSSEX, Pearson XID) — **WORKED**
- Area assumption (1.278 vs 2.0 deg²) strongly affects model ranking — **IDENTIFIED AS CRITICAL**
- Leave-one-source-out validation shows 25% ALESS selected in all held-out runs, with stable preference for modest ALESS correction — **WORKED**
- Split by count type (resolved/prior vs P(D) statistical) reveals 25% ALESS optimal for resolved counts, 50% ALESS for P(D) — **WORKED**

**THESIS_VALUE**

| Item | Rating | Justification |
|------|--------|---------------|
| Evaluator design & chi-square methodology | MAIN | Core validation method for SED selection |
| Wang/Farmer area correction (1.278 deg²) | MAIN | Critical for accurate model ranking |
| Leave-one-source-out cross-validation | MAIN | Demonstrates stability of template choice |
| Heatmap (all sources vs all templates) | APPENDIX | Shows granular source-by-source fits |
| Count-type split (resolved vs P(D)) | MAIN | Reveals different regimes prefer different fractions |
| Overlay plots (model vs observed curves) | MAIN | Visualizes where models succeed/fail |
| Pure ALESS rejection | ONE_SENTENCE | Extreme; too low overall counts |

**FIGURES**  
- `popcosmos_differential_count_evaluator_heatmap.png` — reduced χ² per source per template variant
- `popcosmos_differential_count_area_corrected_overlay.png` — observed vs model differential-count curves across bands
- `popcosmos_differential_count_leave_one_source_out.png` — held-out validation: chosen model tested on hidden source
- `popcosmos_differential_count_evaluator_regime_summary.png` — χ² split by count type (resolved vs P(D))

**TURNING_POINT**  
Area assumption drives ranking reversal: "with 1.278 deg², a modest ALESS correction looks best; with 2.0 deg², FSPS looks best — this means I need to settle the correct area before claiming template X is better."

**QUOTABLE**  
"the answer seems to be somewhere between FSPS and ALESS, not simply replacing FSPS with ALESS" — captures the conclusion that a hybrid/modest correction is preferable to either extreme, grounding the template selection in a physical middle ground rather than a forced choice.

##### LINES 5689-6028 #####
# THESIS NARRATIVE: August 3rd Research Log

## THREAD
Wang catalogue sanity check — verifying whether discrepancies between Wang matched-object counts and published differential counts reflect bugs or genuine differences in what each product measures.

**MOTIVATION**
Wang curve appeared systematically lower than other external count curves; needed to isolate whether this was a data-handling error (wrong area, wrong sample definition, unit mismatch) or a property of the catalogue itself.

**OUTCOME: WORKED**
- Old area value (2.0 deg²) was wrong; correct area is 1.278 deg² — this alone caused ~1.56× underestimate
- Wang `master.dat` contains 2791 radio-only sources (negative COSMOS2020 IDs) not matchable to pop-cosmos; positive-ID subset is 128387/131178 rows
- Wang Table 4 is a deblended point-source catalogue, not a published corrected number-count table; formal comparisons should use corrected differential counts (Clements/Oliver/Pearson)
- SNR>3 cut at bright fluxes (20 mJy) removes <3% of sources; impact grows at fainter fluxes and longer wavelengths
- Wang documentation confirms SPIRE faint-flux underestimation: ~10% at 250 μm, 15% at 350 μm, 25% at 500 μm

**THESIS_VALUE: APPENDIX**  
Diagnostic; explains why Wang raw ≠ published counts.

---

## THREAD
Bethermin/SIDES model check — understanding the physics motivation for multi-template dust SED treatment instead of fixed FSPS far-IR shape.

**MOTIVATION**
Wang cites SIDES for validation; Dave mentioned this direction through Pearson. Needed to understand whether SIDES and Bethermin papers justify moving away from single-SED assumption.

**OUTCOME: WORKED**
- SIDES (2 deg² simulated dusty extragalactic sky) uses 2SFM galaxy model + abundance matching; validates that Herschel/SPIRE single-dish sources can be blends
- Published literature flags that Herschel counts at 350/500 μm in the 5–50 mJy range can be biased high by ~2× from blending/resolution
- Bethermin 2SFM model splits galaxies into normal star-forming and starburst modes with different dust temperatures — motivates multi-template approach

**THESIS_VALUE: ONE_SENTENCE**  
Cite as motivation for dust-temperature family over fixed FSPS bump.

---

## THREAD
Modified-blackbody temperature grid — testing whether count mismatch can be resolved by adjusting dust temperature (physical parameter) rather than ad-hoc ALESS mixing.

**MOTIVATION**
Previous ALESS hybrid (25–50% mixing) helped; is this a useful redshift effect or a sign that FIR SED shape is the real lever? Cleaner approach: hold `L_IR` fixed, vary dust temperature via modified blackbody (MBB) with β=1.8, score each against published counts.

**OUTCOME: WORKED**
- Temperature grid: 20, 25, 30, 35, 40, 45, 50 K
- Best fit: **MBB 35 K** (rough χ² ≈ 4.50)
  - MBB 30 K: χ² ≈ 5.79
  - MBB 25 K: χ² ≈ 21.93
  - MBB 40 K: χ² ≈ 13.00
  - Hotter and colder both penalized
- Both resolved/prior and P(D) statistical count types prefer ~35 K
- At 20 mJy: MBB 35 K gives 1113 / 494 / 127 deg⁻² (250/350/500); comparable to Wang matched positive-ID counts (842 / 466 / 113 deg⁻²)
- Previous ALESS 25% hybrid scored χ² ≈ 3.92; MBB 35 K does not beat it but is simpler physics

**THESIS_VALUE: MAIN**  
Core result: dust temperature (~35 K) is the physical knob. Justifies moving from ad-hoc mixing to template-family approach. Caveat: toy model (no PAH, no AGN, single temperature).

**FIGURES**
- [popcosmos_mbb_temperature_grid_shapes.png](outputs/popcosmos_mbb_temperature_grid_shapes.png) — MBB SED shapes at different T; rest-frame, normalized to same `L_IR`
- [popcosmos_mbb_temperature_grid_counts.png](outputs/popcosmos_mbb_temperature_grid_counts.png) — Euclidean-normalized differential counts for each T vs. published SPIRE data
- [popcosmos_mbb_temperature_grid_score_summary

##### LINES 6029-6391 #####
# Research Log Analysis: Lines 6029–6391

## THREAD
Determining which dust SED templates and observational benchmarks belong in the thesis validation, and disentangling pop-cosmos physics from catalogue-construction artifacts in the Wang COSMOS data.

## MOTIVATION
- Casey-like curves were exploratory; need to rank them against physics-based alternatives (Draine & Li / CIGALE).
- Wang COSMOS counts sit persistently low compared to published corrected tables (Clements, Oliver, Pearson), raising the question whether this is a pop-cosmos failure or a Wang catalogue property.
- Chi-square scoring is useful only if sources are independent; mixing overlapping surveys and correlated P(D) knots inflates false confidence.
- Valiante H-ATLAS provides wide-area bright-end counts not available in COSMOS; critical for testing the regime where pop-cosmos predictions are most strained.

## OUTCOME

| Item | Status | Note |
|------|--------|------|
| Casey-like curves | SUPERSEDED | Rank them lower; treat as toy check only. Warmer dust improves counts but less physics-grounded than Draine & Li. |
| Wang mismatch resolved | WORKED | Wang sits low due to XID+ deblending spreading bright sources across faint priors + small COSMOS area. Not a corrected published count table. Use as diagnostic only. |
| Chi-square evaluator cleaned | WORKED | Isolated truly independent sources: Valiante (wide-area bright), Oliver (mid-flux), Pearson Dark Field XID (deep). Dropped overlapping/correlated sources. |
| Valiante H-ATLAS DR1 added | WORKED | 39 rows (area-weighted GAMA 9/12/15). Published corrected differential counts at 250/350/500 μm. File: `valiante_2016_hatlas_dr1_number_counts_area_weighted.csv`. |
| Jin vs. Wang vs. FSPS check | WORKED | 80,518 coordinate matches. Jin confirms Wang sits low at 350/500 μm; FSPS vs. Jin ratio (`1.31x`–`1.45x`) less extreme than FSPS vs. Wang, supporting deblending-artifact interpretation. |

## THESIS_VALUE

| Finding | Class | Justification |
|---------|-------|---|
| Casey curves ranked lower | APPENDIX | Useful as proof-of-concept but less defensible physically. |
| Wang diagnostic interpretation | ONE_SENTENCE | Explains why Wang appears in residual plots but not main chi-square; XID+ catalogue ≠ corrected number-count product. |
| Clean independent evaluator (Valiante + Oliver + Pearson XID) | MAIN | Removes scoring noise; still finds intermediate ALESS–FSPS blend (~25–50% ALESS) best. Makes chi-square comparison honest. |
| Wang/Jin agreement at 250 μm, divergence at 350/500 μm | ONE_SENTENCE | Supports claim that wavelength-dependent deblending bias (not pop-cosmos alone) explains Wang low counts. |
| Reduced chi² values (25% ALESS ≈ 3.34; FSPS ≈ 8.43) | MAIN | Quantifies that warmer dust improves long-wavelength counts at fixed *L*_IR. |

## FIGURES

| Filename | Content |
|----------|---------|
| `valiante_2016_hatlas_dr1_number_counts_quicklook.png` | Valiante H-ATLAS DR1 (250/350/500 μm) by GAMA field. 13 flux bins per band. |
| `external_spire_differential_counts_july21_3dex.png` | Compiled external counts with Valiante added. |
| `popcosmos_clean_independent_count_evaluator_heatmap.png` | Chi-square heatmap using only Valiante, Oliver, Pearson XID (no overlaps or P(D)). |
| `popcosmos_differential_count_area_corrected_overlay.png` | Wang raw catalogue counts vs. pop-cosmos models: still low, now interpreted as catalogue artifact. |
| `popcosmos_wang_jin_fsps_flux_scatter.png` | Scatter: Wang, Jin, FSPS flux by band. Shows Jin ≈ Wang at 250 μm; Jin > Wang at 350/500 μm. |
| `popcosmos_wang_jin_fsps_ratio_summary.png` | Median flux ratios (Wang/Jin, FSPS/Jin, FSPS/Wang). Quantifies wavelength-dependent divergence. |

## TURNING_POINT

> "Wang is probably best used as a matched-object diagnostic. Published corrected differential counts should stay as the main population-level benchmark."

This decision cleanly separated pop-cosmos model validation (use only Valiante, Oliver, Pearson) from per-object photometry checks (use Wang/Jin for resid