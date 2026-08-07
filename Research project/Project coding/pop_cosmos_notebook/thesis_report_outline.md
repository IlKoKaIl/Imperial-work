# Thesis Report Outline

Working title:

**Understanding Galaxy Evolution: Extending Pop-Cosmos with Far-Infrared/Submillimetre Validation**

Purpose:

- get feedback on the structure and style of the final report
- check whether the main story is clear enough
- decide which results are headline, caveat, appendix, or future work

## Core Story

Pop-cosmos is mainly constrained by optical to near-infrared COSMOS data. I test whether it still works when pushed into far-infrared/submillimetre wavelengths, where dust-obscured star formation dominates and the model is less directly constrained. The main result I want to show is that the baseline FSPS/pop-cosmos far-IR treatment overpredicts bright SPIRE counts, especially at 350/500 um. Keeping each galaxy's total infrared luminosity `L_IR` fixed but changing the FIR dust SED shape improves the comparison. This suggests the extension needed is mainly dust SED shape/temperature, not simply changing total luminosity or SFR.

## Proposed Structure

### 1. Introduction

Aim:

- introduce pop-cosmos and why synthetic galaxy catalogues are useful
- explain why multi-wavelength validation matters
- motivate FIR/submm counts as a clean observed-space test

Key idea:

> If pop-cosmos is physically consistent, it should not only reproduce optical/NIR data but also make reasonable predictions at dust-sensitive wavelengths it was not trained on.

### 2. Data and Inputs

Data/model inputs:

- pop-cosmos / FSPS outputs from Boris: galaxy properties, redshift, `L_IR`, and SED information
- Wang COSMOS catalogue: useful matched-object FIR photometry, but not a corrected number-count table
- published SPIRE count datasets: Clements/H-ATLAS, Oliver/HerMES, Pearson Dark Field, Glenn/Varnish P(D)

How I plan to use them:

| Source type | Role in report |
| --- | --- |
| Published corrected differential counts | main population-level benchmark |
| P(D) counts | faint-end sensitivity check |
| Wang `master.dat` | matched-object / catalogue diagnostic |

Possible figure:

- `fig01_external_count_source_coverage.png`
- shows flux coverage of the observed count datasets

### 3. Method

Pipeline:

1. Start from the pop-cosmos galaxy population.
2. Keep each galaxy's redshift and `L_IR`.
3. Choose an FIR SED shape.
4. Predict observed SPIRE fluxes at 250/350/500 um.
5. Build model differential number counts.
6. Compare to published observed differential counts.

SED cases:

- baseline FSPS/pop-cosmos FIR SED
- ALESS template / ALESS hybrids as an empirical bracket
- modified blackbody temperature grid as the main simple physics test
- Casey-like curves only as exploratory/backup
- possible future stronger version: Draine & Li / CIGALE dust templates

Evaluator:

- chi-square-style score in log count space
- used as a diagnostic scorecard, not a perfect likelihood
- compare by all counts, by band, by flux regime, and by data source

Important caveat:

> Count bins are not perfectly independent, P(D) points are correlated, and some surveys may share systematics. So the evaluator should support the physics argument, not replace it.

### 4. Baseline Result: Where Pop-Cosmos Fails

What I want to show:

- earlier checks suggest pop-cosmos behaves sensibly in optical/NIR-adjacent tests
- FIR/submm counts expose a systematic mismatch

Main result:

> Baseline FSPS/pop-cosmos overpredicts bright SPIRE counts, especially at 350 and 500 um.

Main figure:

- `fig03_fsps_flux_regime_residual_heatmap.png`
- shows the mismatch by wavelength and flux range

Interpretation:

- too much long-wavelength bright flux suggests the far-IR SED is too cold / too long-wavelength-heavy
- this matches the supervisor interpretation that the issue is likely dust SED shape rather than just `L_IR`

### 5. Model Extension Test: Change FIR Dust Shape

Main experiment:

> Keep the same galaxies and same `L_IR`, but replace the FIR dust SED shape.

Why this is useful:

- isolates SED shape from total luminosity
- gives a clean post-hoc extension test
- directly compares to observed SPIRE counts

Main result to show:

- modified blackbody temperature grid
- intermediate warm dust works better than very cold or very hot dust
- this supports dust temperature/shape as the main model lever

Possible figure:

- MBB temperature grid score/count plot from August 3rd work

How I will treat Casey-like curves:

> Casey-like curves support the same direction, but they are parametric. I will keep them as exploratory unless supervisors think they are worth including more strongly. A Draine & Li / CIGALE comparison would be more physical if time allows.

### 6. Wang Discrepancy and Data Caveats

Open issue:

> Wang-derived raw counts still sit away from published corrected counts, even after the area correction.

Current explanation:

- Wang is a deblended photometry catalogue, not a number-count paper
- COSMOS is a small field, so bright rare sources are vulnerable to field variance
- XID+ may split bright SPIRE emission across several prior objects
- prior selection, SNR cuts, and missing completeness corrections may change the raw counts

Figure:

- `fig10_wang_raw_count_context.png`
- shows area/SNR/prior-row effects

Things still to check:

- whether Wang discusses recovered vs true counts in simulations
- whether bright SPIRE sources are split between priors
- whether papers citing Wang use `master.dat` for number counts or only photometry/SED work

### 7. Conclusions / Discussion

Likely final claims:

1. Pop-cosmos can be tested beyond optical/NIR using observed FIR/submm counts.
2. The baseline far-IR treatment overpredicts bright 350/500 um counts.
3. The mismatch is consistent with dust that is too cold / too long-wavelength-bright.
4. Changing FIR SED shape at fixed `L_IR` improves the comparison.
5. The exact best dust template is not uniquely determined yet.
6. A stronger future extension would vary Draine & Li / CIGALE-style dust parameters.

## Figures to Include

Main:

- `fig01_external_count_source_coverage.png`
- `fig03_fsps_flux_regime_residual_heatmap.png`
- MBB temperature grid plot
- `fig10_wang_raw_count_context.png`

Backup / appendix:

- leave-one-source-out robustness plot
- P(D) sensitivity plot
- source-to-source tension plot
- Casey-like template plots if kept

## Feedback I Want

- Is the story focused enough around FIR dust SED shape/temperature?
- Should Wang stay outside the formal number-count evaluator?
- Is MBB enough as the main extension test, or should I add Draine & Li / CIGALE?
- How formal should the chi-square treatment be given correlated/non-independent count data?
- Is extra bright-end count data, e.g. Valiante / H-ATLAS, worth adding now?
