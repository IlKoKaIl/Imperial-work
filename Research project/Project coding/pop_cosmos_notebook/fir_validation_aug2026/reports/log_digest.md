########## LINES 1-362 ##########
# Research-Log Slice Summary

## DECISIONS

- **MS comparison baseline**: Speagle+2014 relation; offset metric `Δ_MS = log₁₀(SFR_popcosmos) − log₁₀(SFR_speagle)`.
- **Comparison sample cuts**: finite SFR/sSFR only; log₁₀(sSFR) > −11; 8.5 ≤ log₁₀(M*) ≤ 11.5; 0 ≤ z < 4.
- **Starburst definition**: Δ_MS ≥ 0.6 dex (~4× above MS baseline).
- **Redshift bin for starburst focus**: 1.0 ≤ z < 2.0 (and 1.5 ≤ z < 2.5 for high-mass subset).
- **Sample scaling**: rerun at 10k, 50k, 100k samples to stabilize tail statistics.
- **SFR definition used**: pop-cosmos Thorp+2025 — 100 Myr-averaged absolute SFR (Msun/yr); sSFR corrected to remaining mass.
- **Literature reference**: Rodighiero+2011 (z~2 Herschel/PACS; number fraction ~2%, SFR share ~10%).
- **Comparison caveat**: existing setup differs from Rodighiero in sample selection, MS reference, and SFR estimator; direct replication would require matching their cuts exactly.

## NUMBERS

**Task 1: MS comparison (seed 7, N = 2155 SF galaxies, 0 ≤ z < 4)**
- Median Δ_MS = −0.531 dex (pop-cosmos predicts ~3× lower SFR)
- Robust scatter ~0.460 dex; 16–84 half-width ~0.439 dex

**Per-redshift bins:**
| z-range | N | median Δ_MS | slope_fit | slope_speagle |
|---------|---|------------|-----------|---------------|
| [0.0, 0.5) | 127 | −0.682 | 1.018 | 0.596 |
| [0.5, 1.0) | 547 | −0.737 | 0.838 | 0.664 |
| [1.0, 2.0) | 1023 | −0.531 | 0.775 | 0.721 |
| [2.0, 3.0) | 375 | −0.283 | 0.720 | 0.769 |
| [3.0, 4.0) | 83 | −0.194 | 0.821 | 0.789 |

**Task 2: Starburst fractions (1.0 ≤ z < 2.0; 9 ≤ log₁₀M ≤ 11.5)**

| n_samples | N(z-bin) | N_starburst | number fraction | SFR share |
|-----------|----------|-------------|-----------------|-----------|
| 10k | 791 | 5 | 0.632% | 6.71% |
| 50k | 3844 | 12 | 0.312% | 6.04% |
| 100k | 7686 | 20 | 0.260% | 7.28% |

**High-mass subset (1.5 ≤ z < 2.5; M ≥ 10):**

| n_samples | N(z,M-bin) | N_starburst | number fraction | SFR share |
|-----------|-----------|-------------|-----------------|-----------|
| 10k | 126 | 2 | 1.587% | 26.86% |
| 50k | 632 | 4 | 0.633% | 13.83% |
| 100k | 1303 | 9 | 0.691% | 12.82% |

**Comparison to Rodighiero+2011 (z~2, mass-selected SF):**
- Literature: number fraction ~2%; SFR share ~10%
- pop-cosmos (100k, z~2 high-mass): number fraction ~0.7%; SFR share ~12.8%
- SFR share close

########## LINES 363-719 ##########
# Research Log Slice Summary

## DECISIONS
- **Data sources**: pop-cosmos posterior summaries (median values per galaxy), Wang 2024 long-wavelength catalog (24–850 µm deblended photometry), Speagle MS baseline (external).
- **Sample matching**: inner join on COSMOS ID; 114,048 galaxies matched from 429,669 pop-cosmos and 128,387 Wang rows.
- **Starburst definition**: Δ_MS ≥ 0.6 dex above Speagle MS, where Δ_MS = log₁₀(SFR_pop) − log₁₀(SFR_Speagle).
- **Long-wavelength flag**: SNR ≥ 3 in any of 250, 350, 500, or 850 µm (SPIRE/SCUBA).
- **Method**: Used pop-cosmos SFR for all matched galaxies; Wang catalog serves as detection label only (not for SFR recalculation in this pass).

## NUMBERS
**Catalog overlap:**
- pop-cosmos valid IDs: 429,669
- Wang positive IDs: 128,387
- Matched rows: 114,048 (26.5% of pop-cosmos; 88.8% of Wang)
- Long-wavelength detected fraction: 5.65%

**Bin A** (1 ≤ z < 2, 9 ≤ log₁₀M ≤ 11.5):
- All matched: N = 37,149, N_SB = 8, starburst fraction = 0.0215%, SFR share = 0.2628%
- Long-detected: N = 2,673, N_SB = 2, starburst fraction = 0.0748%, SFR share = 0.2761%
- Not long-detected: N = 34,476, N_SB = 6, starburst fraction = 0.0174%, SFR share = 0.2596%

**Bin B** (1.5 ≤ z < 2.5, log₁₀M ≥ 10):
- All matched: N = 15,807, N_SB = 3, starburst fraction = 0.0190%, SFR share = 0.1695%
- Long-detected: N = 1,494, N_SB = 0, starburst fraction = 0.0000%, SFR share = 0.0000%
- Not long-detected: N = 14,313, N_SB = 3, starburst fraction = 0.0210%, SFR share = 0.2057%

## OPEN
- Starburst fractions are 30–70× lower than prior mock run (7.3% → 0.26% for Bin A; 12.8% → 0.17% for Bin B) and below expected literature range (8–14%).
- Likely causes: sample change (mock vs. real ID-matched subset), external MS baseline (Speagle) may sit above this data, SFR definition mismatches across datasets, median posterior suppression of extremes, detection/matching cuts removing rare starbursts.
- **Next step**: test alternative MS baselines and IMF/SFR harmonization before interpreting physics.

## FIGURES
None explicitly created in this slice; papers referenced are pop-cosmos (arXiv:2509.20430), ALPINE-ALMA (A&A 2020, aa38487-20), and Ex-MORA (arXiv:2408.14546).

## SUPERVISOR
None in this slice.

## CAVEATS
- Results are "prob a calibration/definition mismatch signal, not a final physics conclusion yet."
- Long-wavelength subsets have very small N_SB counts (≤2 per bin); fractions are unreliable.
- SFR definitions differ across pop-cosmos (model-based, 100 Myr average) and Wang IR photometry; direct comparison without recalibration is premature.
- Wang is used as a label only; SFR is not recomputed from IR data in this run.

########## LINES 720-1063 ##########
# Research Log Extract: Pop-Cosmos Galaxy Model Validation (Lines 720–1063)

## DECISIONS
- Switched from starburst-threshold-first approach to direct SFR comparison on matched galaxies (simpler, more direct)
- Used LePhare and EAZY SFR from COSMOS2020 as comparison baselines against pop-cosmos SFR
- Narrowed redshift bins (`1.0–1.5`, `1.5–2.0`) to test whether broad-bin patterns held
- Limited sigma clipping to baseline-fitting only; excluded it from starburst counting to preserve tail
- Kept Speagle MS relation for star-forming-selected samples only (caveat on quenched contamination)
- Wang long-wavelength flux matching by ID as a proxy test (not yet true SFR-vs-SFR comparison due to file limitations)

## NUMBERS
**Direct SFR offsets (matched sample):**
- LePhare − pop-cosmos: +0.224 dex median (factor 1.67×) overall; +0.318 dex (2.08×) in Bin A; +0.260 dex (1.82×) in Bin B
- EAZY − pop-cosmos: +0.082 dex (1.21×) overall; +0.138 dex (1.37×) in Bin A; +0.122 dex (1.32×) in Bin B

**Narrower redshift bins:**
- `1.0–1.5 z`: LePhare +0.358 dex (2.28×), EAZY +0.170 dex (1.48×)
- `1.5–2.0 z`: LePhare +0.256 dex (1.80×), EAZY +0.091 dex (1.23×)

**Wang long-wavelength flux correlation (Bin A):**
- 24 µm: N=17,571, median log₁₀SFR_pop=1.18, ρ=0.53
- 250 µm: N=2,569, median log₁₀SFR_pop=1.43, ρ=0.19
- 350 µm: N=1,875, median log₁₀SFR_pop=1.45, ρ=0.16
- 500 µm: N=834, median log₁₀SFR_pop=1.45, ρ=0.11
- 850 µm: N=294, median log₁₀SFR_pop=1.57, ρ=0.14
- Long-detected vs not: SFR median 1.425 vs 0.862 dex; mass median 10.742 vs 10.143 dex

**Boris's MIR file:**
- `cosmos2020_mir_photometry.h5`: 429,669 galaxies (matches pop-cosmos sample size); predicts Ch1, Ch2, Ch3, Ch4, MIPS24
- `cosmos2020_fsps_subset.h5`: 1,000-galaxy sanity-check file

## OPEN
- Cannot yet perform Wang direct SFR-vs-SFR comparison: current `master.dat` file has long-wavelength fluxes but no direct SFR column
- Spectroscopic redshift benchmarking blocked: no spec-z field in current COSMOS2020 Farmer or pop-cosmos mcmc_summaries files; need external spec-z compilation
- Mass/luminosity function (`1/V_max`) deferred pending: clear parent selection band, magnitude limit definition, consistent `z_max` calculation, completeness/masking treatment
- IR-based SFR estimate for matched sources still needed to finalize starburst label-transition test (Rodighiero-style optical/NIR-only comparison)
- Whether low pop-cosmos starburst fractions are due to SFR method offset vs true model limitation (SFR offset is consistent but does not prove root cause)

## FIGURES
- Planned: starburst transition matrix (non-SB → SB and SB → non-SB when switching from optical/NIR to IR SFR)
- Planned: long-detected vs not-long-detected ΔMS_pop distribution comparison across SNR thresholds
- Planned: direct SFR scatter plots (LePhare, EAZY, Wang vs pop-cosmos on matched sample)

## SUPERVISOR
- Dave/Prof Clements: suggested simpler direct SFR comparison instead of threshold-first starburst test (adopted

########## LINES 1064-1403 ##########
# DECISIONS
- Using COSMOS2020 Farmer catalog bands: IRAC Ch1–4, SPLASH Ch1–4 as observed reference.
- Using Boris HDF5 file: speculator predictions (Ch1–4, MIPS24), photulator predictions (Ch1–2), stored pop-cosmos validation values (Ch1–2).
- Residual definition: `model_mag - observed_mag` (positive = model fainter, negative = model brighter).
- Ch1/Ch2 treated as primary validation bands (high coverage, tight residuals); Ch3/Ch4 as exploratory extension (patchy coverage, larger scatter).
- Deferring MIPS24 (current coverage ~0%).

# NUMBERS
**Ch1 / Ch2 vs COSMOS2020 IRAC (stored pop-cosmos model):**
- Ch1: N = 423,272, median residual +0.020 mag, MAD 0.084 mag
- Ch2: N = 414,272, median residual −0.012 mag, MAD 0.041 mag

**Ch3 / Ch4 vs IRAC (speculator predictions):**
- Ch3: N = 150,712, median residual +0.507 mag, MAD 0.889 mag
- Ch4: N = 55,394, median residual +0.866 mag, MAD 1.037 mag

**Ch3 / Ch4 vs SPLASH (speculator predictions):**
- Ch3: N = 71,800, median residual −0.181 mag, MAD 0.629 mag
- Ch4: N = 5,442, median residual −0.703 mag, MAD 0.740 mag

**Coverage in Boris file:**
- Ch1: 94.8%, Ch2: 80.9%, Ch3: 55.4%, Ch4: 22.3%, MIPS24: 0%

**Internal synthetic-pipeline agreement:**
- Speculator vs stored (Ch1/Ch2): offsets ~−0.024 to −0.052 mag
- Speculator vs Photulator (Ch1/Ch2): near-perfect agreement on 1:1 line
- Photulator vs stored (Ch1/Ch2): offsets ~−0.026 to −0.058 mag

# OPEN
- Is Ch2 in original pop-cosmos stored model output or only in new synthetic MIR file?
- For Ch3/Ch4: which observed product is the primary reference — IRAC_* or SPLASH_*?
- Are stored_mag_Ch1/Ch2 values from mcmc_summaries or re-derived during MIR synthesis?
- Why is MIPS24 coverage currently 0% — wavelength coverage, emulator coverage, or not yet populated?
- Should main validation plots use magnitudes, fluxes, or residuals normalized by photometric uncertainty?

# FIGURES
- **fig1_speculator_vs_stored.png**: Ch1/Ch2 speculator predictions vs stored photometry; point clouds near 1:1 line, residual histograms; shows strong internal consistency.
- **fig2_residuals_vs_properties.png**: Speculator–Stored residuals for Ch1/Ch2 vs redshift, stellar mass, dust2, lnfAGN; mostly near 0 with mild systematic structure.
- **fig3_coverage_map.png**: Model wavelength coverage overlap with observed filters vs redshift; explains patchiness at longer wavelengths (Ch3/Ch4 limited, MIPS24 not covered).
- **fig4_color_magnitude.png**: Ch1 magnitude distribution, Ch1–Ch2 color vs redshift, IRAC color-color plane; shows structured population trends.
- **fig5_speculator_vs_photulator.png**: Ch1/Ch2 speculator vs photulator with residuals vs redshift; two fast methods agree nearly perfectly.
- **fig6_example_seds.png**: Example galaxy SEDs at different redshifts with IRAC/MIPS filter curves overlaid; visual explanation of filter placement and wavelength-dependent modeling difficulty.
- **fig7_photulator_vs_stored.png**: Photulator–Stored residuals for Ch1/Ch2 vs redshift; generally good but some redshift-dependent structure at high-z.

# CAVEATS
- Figures 1–7 are mostly internal consistency checks (synthetic pipeline vs stored model), not direct observed COSMOS2020 comparisons.
- Ch3/Ch4 residuals are large and sensitive to which observed product (IRAC vs SPLASH) is used as reference

########## LINES 1404-1743 ##########
# Research Log Slice Summary

## DECISIONS
- Took pop-cosmos model magnitudes (Ch1/Ch2) from Boris's MIR file; observed IRAC fluxes from COSMOS2020 Farmer
- Converted observed fluxes to AB magnitudes and plotted model vs. observed directly, then residuals vs. redshift
- Defined residual as `model - observed` (positive = model fainter; negative = model brighter)
- For worst-residual histograms, selected top 5% in absolute residual as threshold
- Chose **Chabrier IMF** as standard comparison baseline (matches COSMOS2020 LePhare setup; flagged need to convert Kennicutt 1998 Salpeter calibration explicitly)
- Selected Jin et al. 2018 super-deblended catalog as next validation step for obscured-SFR test (has direct L_IR column; Wang 2024 lacks it)

## NUMBERS
- **Ch1**: N = 423,272; median residual +0.020 mag; MAD 0.084 mag
- **Ch2**: N = 414,272; median residual −0.012 mag; MAD 0.041 mag
- **Ch1 worst 5% threshold**: |residual| ≥ 0.674 mag; count 21,164
- **Ch2 worst 5% threshold**: |residual| ≥ 0.543 mag; count 20,714
- Peak sample redshift: z ~ 0.9−1.0 (Ch1: 25,341 galaxies; Ch2: 24,730 galaxies)
- Kennicutt 1998 IR calibration (Salpeter): L_IR [L☉] ≈ 5.8 × 10⁹ SFR [M☉/yr⁻¹]
- Pop-cosmos SFR definition: average over most recent 100 Myr (bins 0−30 Myr + 30−100 Myr)

## OPEN
- How to properly invert Kennicutt SFR → L_IR conversion without full integrated IR luminosity (not just one FIR band)
- Whether z > 5 worst-residual concentration is real model problem or noise from low sample counts there
- Whether low-z (0.2−0.5) Ch1 worst-residual feature is significant
- Comparison of pop-cosmos 100 Myr SFR average to IR-calibrated SFR catalogs (different timescale definitions)

## FIGURES
- IRAC matched-sample redshift histograms (Ch1, Ch2) — shows main pile-up z ~ 0.8−1.2; not at z ~ 3.5
- IRAC worst-residual redshift histograms (Ch1, Ch2) — shows highest worst-residual fractions at z > 5 and (Ch1) z ~ 0.2−0.5

## SUPERVISOR
None explicitly in this slice (log entries are self-directed follow-up to an earlier meeting note about IRAC validation and obscured-SFR tests).

## CAVEATS
- Residual plot high-z tail is less reliable / noisier due to fewer objects; do not overclaim stability there
- Kennicutt 1998 relation applies only to **integrated L_IR**, not single FIR bands; cannot convert raw 250 µm flux directly to SFR
- IMF convention mismatch: Kennicutt original is Salpeter; must convert explicitly to Chabrier before comparing to modern COSMOS catalogs
- Pop-cosmos SFR is a **100 Myr average**, not an instantaneous obscured-SFR tracer like IR luminosity — not directly comparable without accounting for timescale difference

########## LINES 1744-2083 ##########
# Research Log Slice Summary

## DECISIONS
- Merged `fsps_lir_scalars.h5` (model-derived L_IR) onto pop-cosmos using Farmer ID; verified index and redshift match exactly.
- Applied same broad SF-like cuts as prior work: `8.5 ≤ log₁₀M ≤ 11.5`, `z < 4`, `log₁₀sSFR > -11`.
- Used simple Kennicutt 1998 calibration as quick reference line, not final truth (acknowledged: AGN torus enabled in FSPS, IMF conventions not yet harmonized).
- Treated L_IR vs observed Wang band flux as redshift-dependent diagnostic (ratio trend) rather than absolute calibration (mixed units).

## NUMBERS
**Main sample (all_sf_like, N=354,562):**
- Median z = 1.40; median log₁₀SFR = 0.20; median log₁₀L_IR = 10.31
- Median offset from Kennicutt line = +0.32 dex; ρ(logSFR, logL_IR) = 0.95

**Bin A (1 ≤ z < 2, 9 ≤ logM ≤ 11.5, N=107,628):**
- Median z = 1.42; median log₁₀SFR = 0.33; median log₁₀L_IR = 10.51
- Offset = +0.42 dex; ρ = 0.92

**Bin B (1.5 ≤ z < 2.5, logM ≥ 10, N=19,300):**
- Median z = 1.89; median log₁₀SFR = 1.25; median log₁₀L_IR = 11.54
- Offset = +0.60 dex; ρ = 0.82

**Redshift-bin offsets (from Kennicutt):**
- z ~ 0.25: +0.21 dex | z ~ 0.75: +0.27 dex | z ~ 1.25: +0.38 dex | z ~ 1.75: +0.44 dex (peak)
- z ~ 2.25: +0.33 dex | z ~ 2.75: +0.26 dex | z ~ 3.25: +0.25 dex | z ~ 3.75: +0.23 dex

**Wang matched sample (Bin A, N=37,149):**
- Long-detected (N=2,673): median log₁₀L_IR = 11.78, median log₁₀SFR = 1.42
- Not long-detected (N=34,476): median log₁₀L_IR = 11.13, median log₁₀SFR = 0.86
- Difference: 0.65 dex (~factor 4–5)

**Wang single-band Spearman correlations (L_IR vs flux, Bin A):**
- 250 μm: ρ = 0.23 (N=2,569) | 350 μm: ρ = 0.22 (N=1,875) | 500 μm: ρ = 0.17 (N=834) | 850 μm: ρ = 0.16 (N=294)

**L_IR/F_band ratio vs redshift (Spearman ρ):**
- 250 μm: ρ = 0.75 (N=5,896, median z=1.03)
- 350 μm: ρ = 0.68 (N=3,787, median z=1.17)
- 500 μm: ρ = 0.65 (N=1,603, median z=1.32)
- 850 μm: ρ = 0.63 (N=588, median z=1.66)

## OPEN
- What assumptions drive the simple Kennicutt calibration, and is pop-cosmos wrong in the FIR? (flagged as question mid-text)
- Why is direct single-band flux to total L_IR correlation only weak-to-moderate despite physical expectation? (author notes not surprising due to redshift, SED shape, dust temp, K-corrections, but left open)
-

########## LINES 2084-2442 ##########
# Research Log Extract: Pop-Cosmos FIR Validation — May 2026

## DECISIONS

- **Redshift-binned analysis**: Computed median `L_IR`/flux ratios at six redshift bins (z ∼ 0.25–2.75) for 250 μm and 850 μm from Wang catalog to isolate redshift-dependent scatter in single-band correlations.
- **Wang as diagnostic, not main test**: Downgraded Wang single-band comparisons from primary validation to sanity-check role after recognizing observed-frame convolution across redshift range.
- **Next data source priority**: Ranked six candidate catalogs by effort/yield for apples-to-apples external comparison. **VLA-COSMOS 3 GHz AGN catalog** selected as quickest route (contains observed `L_TIR_SF`, `SFR_IR`, AGN flags, radio luminosity in one file).
- **FIR-first second option**: Jin et al. 2018 super-deblended COSMOS value-added catalog identified as best pure-FIR validation target if observed `L_IR` column exists.

## NUMBERS

**250 μm median flux ratios (to `L_IR`):**
- z ∼ 0.25: 9.67
- z ∼ 0.75: 10.24
- z ∼ 1.25: 10.62
- z ∼ 1.75: 10.89
- z ∼ 2.25: 11.00
- z ∼ 2.75: 11.21

**850 μm median flux ratios (to `L_IR`):**
- z ∼ 0.25: 10.08
- z ∼ 0.75: 10.64
- z ∼ 1.25: 11.17
- z ∼ 1.75: 11.54
- z ∼ 2.25: 11.58
- z ∼ 2.75: 11.72

**VLA-COSMOS 3 GHz AGN catalog**: 7,903 radio sources with optical/NIR counterparts.

**Reference benchmark** (Delhaize et al. 2017): infrared-radio correlation $q_{\mathrm{TIR}}(z) = (2.88 \pm 0.03)(1+z)^{-0.19 \pm 0.01}$.

## OPEN

- Whether Jin et al. 2018 value-added catalog includes observed `L_IR` or IR-based SFR column and matching scheme relative to COSMOS2020/Farmer IDs — needs inspection post-download.
- Whether Boris can populate model `MIPS24` fluxes for same-band validation.
- Handling of AGN contamination in radio-selected subsets and interpretation of selection bias in VLA sample.
- What treatment of Herschel completeness and noise is needed if number-counts comparison is attempted later.

## FIGURES

- (Implicit) Redshift-binned median ratios plots for 250 μm and 850 μm — showed monotonic increase with redshift, supporting observed-frame effect interpretation.

## SUPERVISOR

- Prof. Clements' hypothesis that scatter in `L_IR` vs single-band flux is partly redshift/observed-frame effect (not primary model failure) — supported by binned analysis; author now less worried about low Spearman coefficients.

## CAVEATS

- **Wang comparison is not final validation**: Direct single-band flux plots are useful sanity check but distorted by redshift-dependent observed-frame convolution — should not be over-interpreted as direct model-vs-data mismatch.
- **Radio-selected subset bias**: VLA-COSMOS 3 GHz catalog is not representative of full pop-cosmos sample; selection effects must be acknowledged in any comparison.
- **Deblended FIR catalogs are complex**: Jin et al. catalog matching may be less straightforward than standard optical catalogs; column structure must be verified carefully.

########## LINES 2443-2808 ##########
# Research-Log Extract: Pop-Cosmos FIR Validation & Agentic Model Diagnosis

## DECISIONS

- **Public-data strategy**: Prioritize Jin 2018 super-deblended and VLA-COSMOS 3 GHz catalogs over raw Wang 2024 as primary observed-frame comparisons; Wang retained for sanity checks.
- **Validation hierarchy** (revised May 25): Shift from physical quantities (L_IR, SFR) to observed-space metrics first—number counts at fixed flux thresholds—to reduce dust-template and IMF assumptions.
- **Benchmark source preference**: HerMES SPIRE 250/350/500 µm and S2CLS 850 µm number counts as primary observed benchmarks; VLA AGN catalog includes ready-computed L_TIR_SF and SFR_IR.
- **AI-assisted workflow** (conceptual stage): Human-in-the-loop agentic pipeline for benchmark parsing, analysis proposal, and model-intervention testing—not autonomous agent research.
- **Model modification scope**: Post-hoc reweighting or small calibration layer preferred over full pop-cosmos retraining; parameter-intervention loop to diagnose which model regimes disagree with observed counts.

## NUMBERS

- Chandra COSMOS Legacy: 4016 X-ray sources, 97% with optical/IR counterparts and photometric redshifts.
- HerMES / SPIRE reference papers cited but specific count-bin values not extracted in this slice.

## OPEN

- Whether VLA-COSMOS 3 GHz or Jin 2018 catalog loads and runs first.
- Concrete choice of flux thresholds and completeness rules for observed number-count binning.
- Which model parameters (dust, AGN fraction, SFH, SFR ratio, FIR flux limits) should be targeted in intervention loop.
- Whether to pursue full parameter-intervention diagnostics or settle for baseline validation + single calibration layer.
- How to formalize "apples-to-apples" checks: unit matching, selection overlap, AGN contamination flags.

## FIGURES

- Planned: population-level observed vs. model-predicted counts at 250/350/500/850 µm (binned by flux).
- Planned (if agentic pipeline used): diagnostic plots showing agreement/disagreement across redshift, dust, AGN-fraction regimes.
- Planned: model-intervention-loop logging table (intervention type → metric change → interpretation).

## SUPERVISOR

**Prof Clements feedback** (May 25):
- Validation need not be limited to physical quantities; observed-space metrics (e.g. number counts above flux limits) are equally valid and reduce assumption stack.
- Suggests moving population-level observed-flux validation higher in priority, deferring physical-quantity conversions.

## CAVEATS

- **Wang 2024** deblended fluxes validated against ALMA in original paper, but are not the cleanest direct observed-L_IR dataset; useful as sanity check, not primary comparison.
- Number-count comparisons require explicit statement of flux thresholds, survey area, completeness corrections, and selection criteria (SNR cut, negative-ID exclusions); missing these can produce spurious agreement/disagreement.
- **AI agent work is not yet real code**: descriptions are conceptual; agentic validation must remain human-supervised with explicit scientific judgment gates—agent hallucination risk noted.
- Reweighting or calibration-layer approach does not replace validation; it diagnoses failure modes but does not retrain the underlying generative model.

########## LINES 2809-3147 ##########
# Research Log Extract (lines 2809–3147)

## DECISIONS

- **Next-steps workflow**: Build `benchmarks/` folder; start with Wang 250 μm counts as single benchmark; create script to compute observed counts first, model predictions later.
- **Validation strategy**: Keep pop-cosmos frozen; use post-hoc reweighting and evaluator-loop approach rather than retraining.
- **Reweighting scope**: Test weights on high-dust, high-L_IR, high-SFR, high-lnfAGN populations; also redshift bins, SNR cuts, completeness assumptions.
- **Evaluator metric**: Start with simple average absolute fractional error in number-count bins; later expand to sum-of-squares χ²-style scorer.
- **Data sources**: References to AI Cosmologist (2504.03424), AlphaEvolve (DeepMind blog), Kosmos AI Scientist (2511.02824) as templates for structured validation loops.

## NUMBERS

**Main-sequence (Speagle) comparison:**
- Median Δ_MS = −0.531 dex (pop-cosmos ~3.4× lower than Speagle overall)
- By redshift bin:
  - z 0.0–0.5: −0.682 dex (4.8× low)
  - z 0.5–1.0: −0.737 dex (5.5× low)
  - z 1.0–2.0: −0.531 dex (3.4× low)
  - z 2.0–3.0: −0.283 dex (1.9× low)
  - z 3.0–4.0: −0.194 dex (1.6× low)

**Starburst fractions (Δ_MS ≥ 0.6 dex):**
- z 1–2, 10k run: 0.632% by number; 6.710% SFR share
- z 1–2, 100k run: 0.260% by number; 7.280% SFR share
- z~2 high-mass slice, 100k: 0.691% by number; 12.821% SFR share

## OPEN

- Clarify exactly where pop-cosmos model goes wrong vs. observed FIR/radio/X-ray data.
- What is the primary cause of the FIR number-count mismatch: dust content, SFR normalization, AGN contribution, or redshift-dependent K-correction?
- Does reweighting high-dust or high-SFR galaxies substantially improve agreement with observed 250 μm counts?
- Which existing pop-cosmos evaluation metrics (Δ_MS, starburst fraction, IRAC residuals) correlate with FIR mismatch?
- Can the loop identify a single population shift, or is the solution multi-dimensional?

## FIGURES

- Proposed evaluator-loop results table: columns for test name, what changed, score improvement (yes/partly/no), interpretation.
- Example number-count comparison: observed [100, 50, 20] vs. model [70, 45, 10] in flux bins.

## SUPERVISOR

None recorded in this slice.

## CAVEATS

- **Post-hoc reweighting is diagnostic, not truth**: Reweighting does not prove a physical solution; it identifies which population shift would improve model–data agreement.
- **Reweighting is not retraining**: The changes are applied to abundance/weights only; the underlying pop-cosmos code and SPS parameters remain fixed.
- **Evaluator loop is not autonomous science**: The agent proposes changes, the evaluator scores them, but the human must interpret and validate what improvements mean.
- **Main-sequence offset is large at low-z**: pop-cosmos SFR is systematically low vs. Speagle, worst at z < 1; this may dominate other mismatches.
- **Starburst fraction is low by number**: pop-cosmos produces ~0.3–0.7% starbursts (vs. ~2% literature), but those starbursts are SFR-heavy; unclear if this is a model bug or selection artifact.

########## LINES 3148-3514 ##########
# RESEARCH LOG SLICE DIGEST

## DECISIONS

- **ID matching method**: Farmer ID cross-reference between pop-cosmos and COSMOS2020; matched all 429,669 valid rows.
- **Coordinate validation**: Median separation threshold acceptable at 0.0345 arcsec; checked through p99 (0.2888 arcsec).
- **SFR comparison sources**: LePhare and EAZY template fits from COSMOS2020 catalog; compared against pop-cosmos definitions.
- **Starburst definition**: Used catalog-specific thresholds; compared starburst fraction and SFR share across three catalogs (pop-cosmos, LePhare, EAZY).
- **IRAC validation**: Median residual (model − observed) for Ch1 and Ch2; flagged high-z outliers (worst 5%).
- **FIR validation approach**: New FSPS `L_IR` from Boris; benchmarked against Kennicutt 1998 reference and raw Wang flux correlations.
- **Wang detection split**: Stratified by long-wavelength detection status in Bin A (1 ≤ z < 2, 9 ≤ logM ≤ 11.5); Bin B (1.5 ≤ z < 2.5, logM ≥ 10).
- **Redshift trend analysis**: Computed `log10(L_IR) − log10(F_band)` correlation with redshift to explain weak single-band flux correlations.
- **ALESS template method**: Assume high-SFR pop-cosmos galaxies follow ALESS average FIR SED shape; scale `8–1000 µm` integral to match model `L_IR`; predict observed fluxes at 24, 100, 160, 250, 350, 500, 850 µm; compare to Wang detections (SNR ≥ 3).

---

## NUMBERS

**Catalog matching:**
- Valid pop-cosmos rows with ID: 429,669
- Match fraction: 100%
- Median coordinate separation: 0.0345 arcsec; p90: 0.1016 arcsec; p99: 0.2888 arcsec

**SFR offsets (pop-cosmos vs COSMOS2020):**
- LePhare median offset: +0.224 dex (≈1.67× higher)
  - Bin A: +0.318 dex (≈2.08×)
- EAZY median offset: +0.082 dex (≈1.21× higher)
  - Bin A: +0.138 dex (≈1.37×)

**Starburst fractions & SFR share (Bin A):**
- pop-cosmos: 0.008% fraction, 0.20% SFR share
- LePhare: 4.99% fraction, 28.50% SFR share
- EAZY: 0.246% fraction, 4.63% SFR share

**Starburst fractions & SFR share (Bin B):**
- pop-cosmos: 0.016% fraction, 0.16% SFR share
- LePhare: 3.32% fraction, 19.41% SFR share
- EAZY: 0.833% fraction, 6.23% SFR share

**IRAC model vs observed:**
- Ch1 (N=423,272): median offset +0.020 mag, MAD 0.084 mag; worst 5%: |residual| ≥ 0.674 mag
- Ch2 (N=414,272): median offset −0.012 mag, MAD 0.041 mag; worst 5%: |residual| ≥ 0.543 mag

**Model `L_IR` vs pop-cosmos SFR (Spearman ρ):**
- All SF-like: ρ = 0.949
- Bin A: ρ = 0.923
- Bin B (z~2 high-mass): ρ = 0.824

**Model `L_IR` vs Kennicutt 1998 offset:**
- All SF-like: +0.322 dex (≈2.1×)
- Bin A: +0.420 dex
- Bin B: +0.599 dex (≈4.0×)

**Wang long-wavelength detection (Bin A):**
- All matched (N=37,149): median log

########## LINES 3515-3894 ##########
# Research Log Slice Extract

## DECISIONS

- **SED template source**: Switched from ALESS-only scaling to full FSPS SEDs from Boris's `fsps_map_median_full.h5` (rest-frame wavelength, attenuated spectrum, L_IR, redshift).
- **Wang match criteria**: Detections with SNR ≥ 3 only; matched by COSMOS ID.
- **Wavelength unit conversion**: Converted `wave_rest` from Ångstrom to microns (÷10⁴).
- **Row alignment verification**: Confirmed `index` matches `mcmc_summaries.h5 metadata/index_farmer` and `z` matches pop-cosmos median redshift.
- **Top-SFR sample**: Selected 5 highest-SFR objects for detailed SED comparison.
- **Number-count bins**: Raw (not SNR-corrected) counts at F₂₅₀ > 3, 10, 20, 50 mJy.

## NUMBERS

**Predicted fluxes (ALESS template scaled to median L_IR by SFR cut):**
- SFR ≥10: N=74,910; median z=2.62; median F₂₅₀=1.04 mJy; median F₈₅₀=0.29 mJy
- SFR ≥30: N=23,205; median z=2.86; median F₂₅₀=1.71 mJy; median F₈₅₀=0.65 mJy
- SFR ≥100: N=2,163; median z=2.97; median F₂₅₀=4.86 mJy; median F₈₅₀=1.96 mJy

**ALESS vs Wang observed (SFR ≥10):** ALESS underestimates across all bands; median log₁₀(pred/obs) = −0.17 to −0.49.

**ALESS vs Wang (SFR ≥100):** Much closer agreement; median log₁₀(pred/obs) = −0.13 to +0.09.

**Top 5 galaxies (FSPS F₂₅₀ vs ALESS F₂₅₀):**
- ID 159228 (z=1.87, SFR=4759): FSPS 605.2 mJy / ALESS 874.8 mJy (ratio 0.69)
- ID 789292 (z=4.43, SFR=1060): FSPS 3.8 / ALESS 13.7 mJy (ratio 0.28)
- ID 382337 (z=4.88, SFR=1058): FSPS 1.9 / ALESS 6.9 mJy (ratio 0.28)
- ID 464408 (z=2.58, SFR=1046): FSPS 9.3 / ALESS 22.5 mJy (ratio 0.41)
- ID 889339 (z=2.19, SFR=1037): FSPS 38.2 / ALESS 128.3 mJy (ratio 0.30)

**Full FSPS vs Wang 250μm (N=6,221 matched):**
- Median observed F₂₅₀: 11.35 mJy
- Median FSPS predicted: 7.75 mJy
- Median ALESS predicted: 5.97 mJy
- Median log₁₀(FSPS/Wang): −0.163 dex (factor ~0.69 low)
- Spearman ρ (FSPS vs Wang): 0.235; (ALESS vs Wang): 0.319

**Number counts at bright ends:**
- F₂₅₀ > 10 mJy: FSPS predicts 6,762; Wang observed 3,668 (1.8× overprediction)
- F₂₅₀ > 20 mJy: FSPS predicts 2,247; Wang observed 1,076 (2× overprediction)
- F₂₅₀ > 50 mJy: FSPS predicts 313; Wang observed 47 (6.7× overprediction, small-number regime)

## OPEN

- **

########## LINES 3895-4252 ##########
## DECISIONS
- **FIR SED shape analysis**: Compared pop-cosmos/FSPS predictions to ALESS template and Wang observed catalog across 250/350/500/850 µm bands; identified dust-temperature mismatch as the core issue, not total-luminosity normalization.
- **Data source & matching**: Used Wang catalogue with SNR ≥ 3 detection cut (bright end); tested with and without SNR cut to verify the cut was not driving the mismatch.
- **SFR tail treatment**: Flagged extreme-SFR objects (>300 M☉/yr) as potentially AGN-contaminated or attenuation-confused; planned to treat them separately in final results.
- **SED shape comparison**: Normalized SEDs by luminosity to isolate shape differences across SFR bins (high, median, low).
- **Axes standardization**: Re-plotted Wang-vs-model comparisons with equal log ranges (10⁻³ to 10³ mJy) on x and y to avoid visual bias.

## NUMBERS
- **Top-5 luminosities**: log L_IR = 14.10, 13.19, 13.03, 12.79, 13.40 L☉; corresponding FIR peaks at 88.7, 135.5, 135.5, 135.5, 30.2 µm.
- **Extreme-SFR tail**: SFR > 300 M☉/yr: N=84, median z=2.94, median log L_IR=12.82; SFR > 1000: N=5, median z=2.58, median log L_IR=13.19.
- **Bright-count table (>10 mJy)**:
  - 250 µm: FSPS=6634, ALESS=3230, Wang=3668
  - 350 µm: FSPS=6557, ALESS=1619, Wang=2367
  - 500 µm: FSPS=3676, ALESS=493, Wang=860
  - 850 µm: FSPS=521, ALESS=26, Wang=9
- **Median fluxes per detected object** (250/350/500/850 µm): Wang 11.35/11.31/10.13/3.59 mJy; FSPS 7.75/8.43/5.93/2.96 mJy; ALESS 5.97/4.21/2.11/0.87 mJy.
- **Log flux ratios (250/350/500/850 µm)**: FSPS/Wang = −0.163/−0.136/−0.224/−0.091; ALESS/Wang = −0.286/−0.432/−0.669/−0.612.

## FIGURES
- **SFR-rank SED samples**: Absolute and normalized SEDs for top-10 high-SFR, median-SFR, and low-SFR objects; shows shape convergence around ~135 µm in mid-to-high-SFR bins.
- **Multiband FIR/sub-mm counts** (250/350/500/850 µm): FSPS (blue), ALESS (orange), Wang with SNR≥3 (black solid), Wang finite flux (grey dotted); demonstrates FSPS overprediction at long wavelengths.
- **Wang multiband comparison, equal axes**: Per-object predicted vs. observed flux in 250/350/500/850 µm; log range 10⁻³ to 10³ mJy on both axes.
- **FSPS vs. ALESS predictions** (density plot): Removes Wang; shows FSPS sits systematically above ALESS at 350/500/850 µm, confirming colder dust shifts flux redward.

## OPEN
- Characterization of FSPS-bright/Wang-faint objects: who are the sources the model predicts as bright but Wang does not detect?
- Reconciliation of the apparent contradiction: per-object medians show FSPS slightly low, but counts show FSPS overpredicts bright sources (likely scatter and tail behavior).
- Extension to external count datasets: Clements et al. 2010 and other observed count points beyond Wang.
- Warm-dust template substitution experiment: swap cold FSPS far-IR shape for warmer template while preserving L_IR; measure count improvement.
- AGN contamination in the top-SFR tail: formal separation of truly high-SFR objects

########## LINES 4253-4592 ##########
## DECISIONS
- Added Jin et al. 2018 super-deblended COSMOS catalogue (195,107 sources) as second per-object observed reference alongside Wang; uses radio/MIPS/optical priors for FIR deblending.
- Switched from individual-object SEDs to median SED shapes (binned by SFR and AGN parameter) to test whether cold FIR signature is bulk population feature, not outliers.
- Applied Wang flux cuts (5 mJy exploratory; 10 mJy conservative) and SNR ≥ 3 to address Eddington bias and deblending uncertainty.
- Converted model number counts to per-deg² surface density (`N(>S)`) for comparison across H-ATLAS/HerMES/COSMOS surveys with different footprints.
- Selected external count papers: Clements 2010 H-ATLAS (bright/wide), Valiante 2016 H-ATLAS DR1 (rare bright tail), Oliver 2010 HerMES (middle bridge), Pearson 2025 SPIRE Dark Field (faint/deep).

## NUMBERS
**Jin et al. catalogue detection counts (SNR ≥ 3):**
- 250 μm: 12,490 sources; 7,166 with flux ≥ 10 mJy
- 350 μm: 6,881 sources; 5,388 with flux ≥ 10 mJy
- 500 μm: 3,806 sources; 3,139 with flux ≥ 10 mJy
- 850 μm: 1,059 sources; 100 with flux ≥ 10 mJy

**Wang flux-limit notes:**
- SPIRE confusion noise: 6.8 mJy (250 μm), 6.3 mJy (350 μm), 5.8 mJy (500 μm)
- Faint-source underestimation: ~10%, 15%, 25% at 250/350/500 μm respectively

**SED median samples:**
- Low SFR (0.1–1): bulk sample
- Normal (1–10): bulk sample
- High (30–300): bulk sample
- Extreme (>1000): N=5 only

**Peak wavelengths:**
- Low-fAGN: ~135 μm
- High-fAGN: ~33 μm
- Most SFR slices: FIR peak ~135 μm

## OPEN
- Standardize differential-count units across Clements/Pearson/HerMES before final overplot.
- Reconcile per-object Wang residuals (FSPS too faint for detected galaxies) with number-count residuals (FSPS overpredicts bright sources) — suggests mismatch in which objects get FIR brightness assigned, not just global bias.
- Verify whether high-fAGN SED peak shift (135 → 33 μm) reflects true AGN contribution or model parameterization artifact.
- Determine if Clements/H-ATLAS bright-end counts exceeding current model curves indicate missing population or systematic difference.
- Extreme-SFR median SED (N=5): undersample warning; do not over-trust.

## FIGURES
- **Median SED by SFR** (`popcosmos_full_sed_median_sfr_seds.png`): bulk-population νLν/L_IR shape across four SFR bins; confirms cold FIR peak (~135 μm) is not random object artifact.
- **AGN-parameter median SED** (`popcosmos_full_sed_agn_parameter_median_seds.png`): low vs. high fAGN split; shows hot mid-IR continuum (3–30 μm) and emission-line structure ([S III] 33.48, [Si II] 34.82, [Ne III] 36.0 μm) in AGN-like component.
- **Wang bright-cut residual** (`popcosmos_full_sed_wang_brightcut_flux_bias.png`): log₁₀(model/Wang) sliced by observed flux; FSPS and ALESS both faint relative to Wang detections, especially at high flux.
- **FSPS vs ALESS sliced bias** (`popcosmos_full_sed_fsps_vs_aless_binned_bias.png`): FSPS exceeds ALESS at 350/500/850 μm, strongest at

########## LINES 4593-4976 ##########
# Research Log Slice Extract

## DECISIONS
- Switch from integral counts N(>S) to differential counts dN/dS (or S^2.5 dN/dS) per Prof. Clements feedback — differential bins have independent errors; integral counts are correlated across thresholds.
- Adopt Euclidean-normalized format S^2.5 dN/dS [Jy^1.5 deg^-2] as standard unit across all external datasets for model comparison.
- Compile external SPIRE counts from four published papers into single standardized table: Clements/H-ATLAS 2010, Oliver/HerMES 2010, Pearson/Dark Field 2025 (SUSSEXtractor and XID separately), Varnish/Dark Field II 2025 (P(D) Table 4).
- Use Varnish Table 4 (P(D) differential counts) as faint-flux comparison despite spline-fitting artifacts; do not mix with direct extraction counts.
- For Wang comparisons: use stricter COSMOS2020/Farmer area of 1.278 deg^2 (not full 2 deg^2); treat Wang as prior-selected deblended photometry, not completeness-corrected source counts.
- Prioritize number-count comparisons over per-object SED matches — observed-flux space is cleaner than model-dependent quantities like L_IR or SFR.

## NUMBERS
- Wang catalogue: 131,178 total rows; 128,387 with positive COSMOS2020 IDs; 2,791 radio-only.
- COSMOS2020/Farmer effective area: 1.278 deg^2 (not 2.0 deg^2).
- Coordinate bounding box: ~1.69 deg^2 (not effective masked area).
- Wang flux-bias corrections: ~10% at 250 µm, ~15% at 350 µm, ~25% at 500 µm for faint sources.
- Area correction factor: 2.0 / 1.278 ≈ 1.56× (Wang raw counts should move upward by ~56%).
- Pearson unit conversion: value × 1e7 × (1e-3)^1.5 / 3282.806 (from mJy^1.5 sr^-1 to Jy^1.5 deg^-2).
- HerMES P(D) number-count break: ~10–20 mJy.

## OPEN
- Clarify whether pop-cosmos FIR problems stem from total IR luminosity, SED shape/dust temperature, AGN contamination, or source selection/blending.
- Reconcile Wang raw counts (post-area correction) with external differential-count papers — currently sit below Clements/Oliver/Varnish despite correction.
- Decide which SED-shape / per-object tests are main thesis evidence vs. supporting diagnostics.
- Check whether extreme-SFR / high-fAGN population needs separate treatment to avoid distorting overall interpretation.
- Determine best route to improve pop-cosmos FIR prediction: rebuild whole catalogue or add better dust-temperature prescription layer.
- ALESS/template extension: develop as simple extension option rather than side plot.

## FIGURES
- `external_spire_differential_counts_fullrange.png` — compiled external SPIRE differential counts (all four papers, same axes/units); sanity plot, not yet model comparison.
- `popcosmos_full_sed_external_counts_overlay_corrected.png` — cumulative-count overlay (Clements fixed, Pearson SUSSEX/XID separate, Oliver derived from differential); useful for intuition but differential version is primary.

## SUPERVISOR
- Prof. Clements: use differential counts dN/dS instead of integral N(>S) — each bin has independent errors; integral counts reuse same sources so errors are correlated.
- Indicated S^2.5 dN/dS (Euclidean-normalised) format is better for model comparisons.

## CAVEATS
- Varnish P(D) Table 4: some rows at extremely faint fluxes and odd lower/upper limits due to fitted spline result — do not mix with direct extraction counts.
- Wang fluxes: prior-selected, SNR≥3 applied, deblending-dependent, completeness not corrected — use for per-object matched tests, not as final source-count validation.
- Wang faint SPIRE fluxes systematically underestimated (up to ~25% at 500 µm).
- External published differential-count

########## LINES 4977-5321 ##########
# Research Log Slice Summary

## DECISIONS
- Reran external SPIRE differential-count plot with restricted y-axis for clarity
- Used three ALESS template variants (average, optically bright, optically faint) as empirical alternatives to FSPS
- Converted ALESS SEDs by: scaling 8–1000 μm integral to each object's L_IR, redshifting to observed band, converting to flux
- Hybrid SED mixing: α ∈ {0.25, 0.50, 0.75} between FSPS (α=0) and ALESS (α=1)
- Corrected hybrid method: normalized FSPS and ALESS on common rest-frame wavelength grid before predicting observed fluxes
- Discovered Wang survey area is 1.278 deg² (not 2.0 deg² used in old plots) → old Wang counts artificially low by ~56%
- Wang `master.dat` treated as raw deblended catalogue, not published corrected counts; SNR≥3 cut applied

## NUMBERS
Bright-count summary at 20 mJy, per deg², Wang-matched sample:

| Band | FSPS | ALESS avg | 50% hybrid | Wang SNR≥3 |
|------|------|-----------|-----------|-----------|
| 250 μm | 1102 | 284 | 596 | 538 |
| 350 μm | 852 | 132 | 358.5 | 298 |
| 500 μm | 334.5 | 38.5 | 132 | 72 |

Raw Wang detection counts from `master.dat` (1.278 deg²):
- 250 μm: SNR≥3 = 7,946; F≥20 mJy = 1,500
- 350 μm: SNR≥3 = 5,255; F≥20 mJy = 858
- 500 μm: SNR≥3 = 2,305; F≥20 mJy = 232
- 850 μm: SNR≥3 = 915; F≥20 mJy = 0

FSPS integral check: median (FSPS integral / L_IR) = 0.999994 → flux-mixing and rest-frame hybrid methods agree within <0.001%

## OPEN
- Lensing: deferred
- Radio counts: deferred
- Exact Wang survey area confirmation and selection cut
- Why Wang sits low vs external published counts: partly explained by area correction, raw-catalogue status, SNR cut, and confusion limits, but full accounting incomplete
- Which dust-SED template family best reproduces observed long-wavelength data (Casey 2012, Dale 2014, Draine & Li, THEMIS, Schreiber 2016, CIGALE grids) — workflow planned but not yet run
- 500 μm still underestimated by 50% ALESS hybrid relative to Wang; may need warmer SED shape

## FIGURES
- External SPIRE differential counts (y-axis restricted range)
- ALESS template variant differential counts (FSPS vs faint/average/bright ALESS)
- Hybrid FSPS/ALESS SED differential counts (α = 0.25, 0.50, 0.75)
- Rest-frame hybrid SED examples (blue FSPS, dashed yellow ALESS, orange 50/50 hybrid on same wavelength grid)
- Rest-frame hybrid SED differential counts (corrected flux prediction method)

## SUPERVISOR
None explicitly recorded in this slice.

## CAVEATS
- ALESS variants "are not the final answer, but they bracket what happens if the dust SED is warmer / shaped differently"
- Wang `master.dat` is raw/deblended catalogue photometry, not a published corrected source-count table
- Wang SNR≥3 cut removes significant flux especially at 350/500/850 μm
- SPIRE is confusion dominated; faint fluxes can be underestimated
- Field differences and cosmic variance (COSMOS is small) contribute to Wang vs external-count discrepancies — do not over-interpret as pure pop-cosmos physics
- 50% ALESS hybrid close to Wang at 250/350 μm in this simple 20 mJy check, but 500 μm residual suggests model needs further refinement

########## LINES 5322-5688 ##########
# DECISIONS

- Compare model vs. observed in **log space** (orders of magnitude span); use differential counts (closer to independent than cumulative).
- **Error floor** `0.08 dex` to prevent tiny paper errors dominating the score.
- Metric: reduced chi-square on differential counts; `chi2 ~ 1` is acceptable, `chi2 >> 1` indicates mismatch or missing physics, not overfitting.
- **Area:** settled on Wang/Farmer `1.278 deg²` for model counts; published surveys already area-normalised.
- Glenn et al. 2010 P(D) counts: used **Table 4, spline model, no FIRAS prior** (want SPIRE-data-driven version); treated as correlated knot values, not independent bins.
- **Leave-one-source-out validation:** hold one survey, choose best model from others, test on held-out source (to avoid overfitting to single plot).
- Split evaluator by count type: resolved/prior (Clements, Oliver, Pearson) vs. P(D) statistical (Glenn).

---

# NUMBERS

**Reduced χ² with `1.278 deg²` area (123 points, Clements/Oliver/Pearson/Pearson/Glenn pooled):**
- 25% ALESS: **3.92**
- 50% ALESS: **4.26**
- FSPS: **7.75**
- 75% ALESS: **8.48**
- ALESS: **14.06**

**Reduced χ² split by count regime (all 134 points):**
- Resolved/prior only: 25% ALESS = **3.68**
- P(D) statistical only: 50% ALESS = **4.39**

**Cumulative counts at 20 mJy (sources deg⁻²):**

| Band | FSPS  | 25% ALESS | 50% ALESS | ALESS | Wang SNR≥3 |
|------|-------|-----------|-----------|-------|-----------|
| 250  | 1724.6| 1307.5    | 932.7     | 444.4 | 841.9     |
| 350  | 1333.3| 905.3     | 561.0     | 206.6 | 466.4     |
| 500  | 523.5 | 327.1     | 206.6     | 60.3  | 112.7     |

**Best model per external source (leave-one-out):** every held-out run selected **25% ALESS** as best on training sources; Clements/Oliver held-out best was 50% ALESS but 25% was close; Glenn preferred 50% ALESS.

---

# OPEN

- **Exact best ALESS fraction:** robust region is `25–50%`; resolved counts prefer ~25%, P(D) prefers ~50%.
- **Should P(D) and resolved counts be treated separately** in final evaluator, or combined?
- **How to structure final evaluator to avoid "just fitting the count curve"?** Need statistically defensible setup that maintains physical sensibility of SED change.
- Need to add **at least one non-ALESS dust family** for comparison.

---

# FIGURES

- `popcosmos_differential_count_evaluator_heatmap.png` — rows = observed sources (Clements, Glenn, Oliver, Pearson variants), columns = model variants (FSPS to ALESS); cells = reduced χ² (color = log₁₀); shows 25–50% ALESS generally better than pure FSPS, pure ALESS too extreme.
- `popcosmos_differential_count_area_corrected_overlay.png` — x-axis flux (mJy), y-axis Euclidean-normalised counts (Jy^1.5 deg⁻²); points = observed, curves = models; shows count shapes vs. data across bands.
- `popcosmos_differential_count_leave_one_source_out.png` — bar plot (lower = better); each run holds out one survey, trains on others, tests on held-out; all runs selected 25% ALESS; Clements/Oliver held-out best was 50%, Glenn preferred 50%, but 25% was competitive.
- `popcosmos_differential_count_evaluator_regime_summary.png` — split by count type (resolved/prior vs. P(D)); all-counts best = 25% ALESS (3.

########## LINES 5689-6028 ##########
## DECISIONS
- Returned to Wang et al. 2024 catalogue after noticing discrepancy with other external count curves.
- Corrected area used in analysis from `2.0 deg²` (old scripts) to `1.278 deg²` (Wang/COSMOS2020 Farmer FLAG_COMBINED=0).
- For per-object validation, use only Wang sources with positive COSMOS2020 IDs (128,387 of 131,178 rows) to match pop-cosmos IDs, excluding 2,791 radio-only priors.
- Adopted modified blackbody (MBB) approach instead of ALESS/FSPS mixing: fixed `L_IR` per galaxy, varied dust temperature on grid `[20, 25, 30, 35, 40, 45, 50 K]` with `β = 1.8` emissivity slope.
- Evaluated MBB across both resolved/prior and P(D) statistical count types; kept differential count papers as formal benchmark, Wang matched fluxes as diagnostic only.

## NUMBERS
**Wang catalogue sanity:**
- Wang master.dat: 131,178 rows; 128,387 positive COSMOS2020 IDs; 2,791 negative (radio-only).
- Area correction: using `1.278 deg²` instead of `2.0 deg²` raises Wang/model agreement by ~1.56×.
- SNR>3 cut at 20 mJy: 99.2% (250 μm), 97.9% (350 μm), 98.0% (500 μm) pass; not the main issue for bright counts.
- Wang-noted faint SPIRE underestimation: ~10% (250 μm), 15% (350 μm), 25% (500 μm).

**Wang positive-ID matched counts (SNR>3, ≥20 mJy):**
- 250 μm: 841.9 deg⁻²
- 350 μm: 466.4 deg⁻²
- 500 μm: 112.7 deg⁻²

**Modified blackbody grid results:**

| Model | Reduced χ² | Median log₁₀(model/obs) |
|-------|----------:|------------------------:|
| MBB 35 K | 4.50 | −0.11 |
| MBB 30 K | 5.79 | +0.18 |
| MBB 40 K | 13.00 | −0.42 |
| MBB 25 K | 21.93 | +0.52 |

- Best temperature: **35 K** (χ² = 4.50), lower than 25% ALESS (χ² ≈ 3.92) and 50% ALESS (χ² ≈ 4.26).
- Both count types (resolved/prior and P(D)) prefer 35 K.
- MBB 35 K at ≥20 mJy: 250 μm = 1112.7 deg⁻², 350 μm = 493.7 deg⁻², 500 μm = 126.8 deg⁻².

## OPEN
- **Wang in thesis plots:** should raw Wang counts appear only as sanity-check reference, with formal count comparison using published differential counts only?
- **Wang radio-only sources:** for per-object validation, keep positive COSMOS2020 IDs only, or include a method for negative-ID radio-only sources when comparing to pop-cosmos?
- **Dust template family:** move beyond toy single-temperature MBB to Casey-style (MBB + mid-IR power law), CIGALE, Dale, or Draine–Li variants.

## FIGURES
- `outputs/popcosmos_mbb_temperature_grid_shapes.png` — rest-frame modified-blackbody SED shapes for T ∈ [20, 50 K]; shows peak shift with temperature.
- `outputs/popcosmos_mbb_temperature_grid_counts.png` — Euclidean-normalized differential counts (S^2.5 dN/dS) vs. observed flux; compares MBB model curves to published SPIRE data points; 35 K is closest.
- `outputs/popcosmos_mbb_temperature_grid_score_summary.png` — reduced χ² goodness-of-fit score for each temperature; shows 35 K minimum.

## SUPERVISOR
- Dave indicated direction through Pear

########## LINES 6029-6391 ##########
# Research Log Extract: Lines 6029–6391

## DECISIONS

- **Casey-like curves**: Treated as exploratory appendix check only; parametric (modified blackbody + mid-IR tail) but less physics-based than Draine & Li / CIGALE. Deprioritized in favor of dust-template work.
- **Data sources for chi-square evaluator**: Cleaned to three independent main sources (Valiante H-ATLAS DR1, Oliver HerMES, Pearson Dark Field XID) to reduce correlated bins; Clements/Glenn/Varnish kept as backup/sensitivity checks only.
- **Wang COSMOS**: Repositioned as matched-object diagnostic only, not a corrected published number-count table. Reason: XID+ deblending can redistribute flux across priors; small COSMOS area adds bright-end noise; raw catalogue counts differ from published corrected counts.
- **Wang validation**: Cross-checked against Jin super-deblended catalogue (COSMOS, 80,518 coordinate matches <1 arcsec) to isolate whether mismatch is pop-cosmos physics or catalogue methodology.
- **Extra data addition**: Valiante H-ATLAS DR1 added (published corrected differential counts, Tables 5/8/9 for 250/350/500 μm) as main wide-area bright-end source.

## NUMBERS

**Valiante H-ATLAS DR1:**
- 13 flux bins per band per GAMA field
- 117 raw rows total
- 39 rows in area-weighted GAMA9/GAMA12/GAMA15 average

**Wang deblending bias (median, per Wang 2024):**
- 250 μm: ~10%
- 350 μm: ~15%
- 500 μm: ~25%

**Wang prior density (sources per beam):**
- 250 μm: ~0.34
- 500 μm: ~1.34

**Clean chi-square scores (83 pooled bins, reduced χ²):**
- 25% ALESS: 3.34 (best)
- 50% ALESS: 3.60
- 75% ALESS: 7.06
- FSPS: 8.43
- ALESS: 11.87

**Wang vs Jin vs FSPS median flux ratios (SNR ≥3):**

| Band   | Wang/Jin | FSPS/Jin | FSPS/Wang |
|--------|----------|----------|-----------|
| 250 μm | 0.91×    | 0.97×    | 1.14×     |
| 350 μm | 0.69×    | 0.81×    | 1.31×     |
| 500 μm | 0.49×    | 0.65×    | 1.45×     |

## OPEN

- **Wang count mismatch root cause**: Specific mechanisms to check:
  - Does XID+ split one bright SPIRE source into several fainter priors?
  - Are bright/rare sources missing due to prior-selection bias?
  - Do SNR/quality cuts remove bright or confused objects?
  - Do Wang simulations compare recovered counts to input/truth?
  - Later papers using Wang: do they use `master.dat` for number counts or only photometry/SFR/SED?
- **Wang bright-source beam test**: Planned—for each bright Wang SPIRE source, count/sum nearby priors within one beam; test whether one external bright source becomes multiple fainter Wang priors.
- **Dust template uniqueness**: Exact best template not yet uniquely determined; physics direction clear (warmer/more flexible), specifics open.
- **Béthermin et al. 2012 / Jin et al. 2018**: Potential additional COSMOS/GOODS-N count or photometry sources; utility not yet assessed.

## FIGURES

- `outputs/valiante_2016_hatlas_dr1_number_counts_quicklook.png` — Valiante H-ATLAS counts by GAMA field (250/350/500 μm); 13 bins each.
- `outputs/external_spire_differential_counts_july21_3dex.png` — External counts compilation with Valiante integrated.
- `outputs/popcosmos_full_sed_external_counts_overlay_corrected.png` — Wang / pop-cosmos corrected overlay (full SED).
- `outputs/popcosmos_differential_count_area_corrected_overlay.png` — Differential counts with raw Wang overplotted.