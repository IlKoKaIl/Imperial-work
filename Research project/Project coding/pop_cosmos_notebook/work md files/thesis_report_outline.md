# Thesis Report Outline

temp title:

**Understanding Galaxy Evolution: Extending Pop-Cosmos with Far-Infrared/Submillimetre Validation**

## Core Story

Pop-cosmos is mainly validated from optical to near-infrared COSMOS data. I test whether it still works when pushed into far-infrared/submillimetre wavelengths, where dust-obscured star formation dominates and the model is less directly constrained. The main result I want to show is that the baseline FSPS/pop-cosmos far-IR treatment overpredicts bright SPIRE counts, especially at 350/500 um. Keeping each galaxy's total infrared luminosity `L_IR` fixed but changing the FIR dust SED shape improves the comparison. This suggests the extension needed is mainly dust SED shape/temperature, not simply changing total luminosity or SFR.

The final report should also tell the story of how the project developed. I started with the idea of extending pop-cosmos into the FIR/submm regime, then realised that the wavelength range already contained a strong enough data test to make the extension scientifically meaningful. That shifted the project from a extension idea across the em spectrum into a more constrained range with submm and FIR: where does the baseline model still work, where does it fail, and what physical change improves it?

So the overall arc is: pop-cosmos gives a good baseline, FIR/submm counts expose the weakness, and a fixed-`L_IR` dust-shape change shows what kind of extension is actually needed.

## Proposed Structure

### 1. Introduction

Aim:

- introduce pop-cosmos and why synthetic galaxy catalogues are useful
- explain why multi-wavelength validation matters
- motivate FIR/submm counts as a clean observed-space test
- frame the project as a model-extension exercise rather than only a comparison exercise

What this section should set up:

- the report isn't just about improving counts
- it's about checking whether a population model trained on optical/NIR data still behaves well when asked to predict dust-dominated emission
- this creates a natural bridge from the original pop-cosmos scope to a wider validation framework

### 2. Data and Inputs

Data/model inputs:

- pop-cosmos / FSPS outputs from Boris: galaxy properties, redshift, `L_IR`, and SED information
- Wang COSMOS catalogue: useful matched-object FIR photometry, but not a corrected number-count table
- published SPIRE count datasets: Clements/H-ATLAS, Oliver/HerMES, Pearson Dark Field, Glenn/Varnish P(D)

How I plan to use them:

| Source type                             | Role in report                        |
| --------------------------------------- | ------------------------------------- |
| Published corrected differential counts | main population-level benchmark       |
| P(D) counts                             | faint-end sensitivity check           |
| Wang, Valiante, real data sets to match | matched-object / catalogue diagnostic |

Possible figure:

- shows flux coverage of the observed count datasets
  intend to setup catalogue where all sources are independant to use for my chi sq model.

![1786109179075](image/thesis_report_outline/1786109179075.png)

This section should also explain why the data mix matters.

- the corrected counts are the cleanest benchmark for the population-level comparison
- the matched-object catalogues are useful for diagnostics and sanity checks
- together they help separate a physical mismatch from catalogue specific issues

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

Count bins are not perfectly independent, P(D) points are correlated, and some surveys may share systematics. So the evaluator should support the physics argument, not replace it.

This section should also make clear why fixing `L_IR` matters.

- if `L_IR` stays fixed, the comparison isolates dust SED shape rather than total energy budget
- that makes the test much cleaner physically
- if the counts improve under a different dust shape, then the problem is t simply the overall luminosity scale, but how the emission is distributed across FIR/submm wavelengths

### 4. Baseline Result: Where Pop-Cosmos Fails

What I want to show:

- earlier checks suggest pop-cosmos behaves sensibly in optical/NIR-adjacent tests
- FIR/submm counts expose a systematic mismatch

Main result:

Baseline FSPS/pop-cosmos overpredicts bright SPIRE counts, especially at 350 and 500 um.

potential figure:

![1786109312318](image/thesis_report_outline/1786109312318.png)

- 
- shows the mismatch by wavelength and flux range

Interpretation:

- too much long-wavelength bright flux suggests the far-IR SED is too cold / too long-wavelength-heavy
- this matches the supervisor interpretation that the issue is likely dust SED shape rather than just `L_IR`
- the mismatch is useful because it is structured, not random; it points to the wavelength regime where the current prescription is weakest
- this is the point where the report can transition from diagnosis to extension

### 5. Model Extension Test: Change FIR Dust Shape

Main experiment:

Keep the same galaxies and same `L_IR`, but replace the FIR dust SED shape.

Why this is useful:

- isolates SED shape from total luminosity
- gives a clear post-hoc extension test
- directly compares to observed SPIRE counts

Main result to show:

- modified blackbody temperature grid
- intermediate warm dust works better than very cold or very hot dust
- this supports dust temperature/shape as the main model lever
- it shows that a relatively simple physical change already improves the comparison without changing the galaxy population itself


This section should make the project's turning point explicit.

- the baseline model identifies the problem
- the fixed-`L_IR` dust-shape test shows a targeted improvement
- the result suggests the next version of pop-cosmos should focus on more flexible dust emission rather than simply adjusting luminosities

### 6. Wang Discrepancy and Data Caveats

issue:

Wang-derived raw counts still sit away from published corrected counts, even after the area correction.

Current explanation:

- Wang is a deblended photometry catalogue, not a number-count paper
- COSMOS is a small field, so bright rare sources are vulnerable to field variance
- XID+ may split bright SPIRE emission across several prior objects
- prior selection, SNR cuts, and missing completeness corrections may change the raw counts

Figure:

- `fig10_wang_raw_count_context.png`
- ![1786121441296](image/thesis_report_outline/1786121441296.png)
- shows area/SNR/prior-row effects

Things still to check:

- whether Wang discusses recovered vs true counts in simulations
- whether bright SPIRE sources are split between priors
- whether papers citing Wang use `master.dat` for number counts or only photometry/SED work

### 7. Conclusions / Discussion

Potential final claims:

1. Pop-cosmos can be tested beyond optical/NIR using observed FIR/submm counts.
2. The baseline far-IR treatment overpredicts bright 350/500 um counts.
3. The mismatch is consistent with dust that is too cold / too long-wavelength-bright.
4. Changing FIR SED shape at fixed `L_IR` improves the comparison.
5. The exact best dust template isn't uniquely determined yet.
6. A stronger future extension would vary Draine & Li / CIGALE-style dust parameters.

The conclusion should also point toward what I would potentially recommend to the pop-cosmos team.
