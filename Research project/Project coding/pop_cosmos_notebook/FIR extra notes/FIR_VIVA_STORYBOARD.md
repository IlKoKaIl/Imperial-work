# FIR Viva Storyboard

This is a draft slide/story plan for presenting the FIR/SPIRE part of the thesis.

It is not meant to be a full talk yet. It is the spine of the argument.

## Core Message

> I used observed SPIRE number counts as an out-of-sample test of pop-cosmos. The baseline FSPS far-IR SED overpredicts bright long-wavelength counts, and a warmer/broader FIR dust SED improves the comparison while keeping `L_IR` fixed.

## 6-Slide Version

### Slide 1: Why Test FIR?

Question:

> pop-cosmos is calibrated mainly in optical/NIR, but does it predict the dust-obscured universe?

Say:

- optical/NIR validation is not enough for dusty star formation
- FIR/sub-mm light is where dust-reprocessed emission appears
- number counts are observed-space tests, not derived physical quantities

Visual:

- simple schematic if needed
- or no plot, just thesis motivation

### Slide 2: The Evaluator

Question:

> how do I test pop-cosmos against SPIRE observations?

Say:

- keep pop-cosmos galaxies fixed
- keep each galaxy's `L_IR` fixed
- change FIR SED shape
- predict observed 250/350/500 um fluxes
- compare differential counts

Visual:

- `fig01_external_count_source_coverage.png`

Key line:

> This is an evaluator loop: change SED assumption, forward-model observables, score against real counts.

### Slide 3: Baseline FSPS Problem

Question:

> where does the original model fail?

Say:

- FSPS is not equally wrong everywhere
- low/mid 250 um is not terrible
- bright 350/500 um is where the mismatch becomes large

Visual:

- `fig03_fsps_flux_regime_residual_heatmap.png`

Key line:

> The mismatch pattern points to FIR SED shape / dust temperature, not just a random normalisation issue.

### Slide 4: Testing Dust SED Shapes

Question:

> what change improves the model?

Say:

- pure ALESS overcorrects
- simple hybrids improve but are empirical
- Casey-like templates are more physically interpretable
- best current region is around `T ~ 30 K`

Visual:

- `fig02_model_family_score_comparison.png`
- or `fig04_casey_like_count_comparison.png`

Key line:

> The exact best template is not the point; the stable direction is warmer/broader than baseline FSPS.

### Slide 5: Robustness / Not Just Curve Fitting

Question:

> am I just fitting one dataset?

Say:

- used multiple count products
- leave-one-source-out test
- selected warm-dust correction beats FSPS on every held-out source
- different papers still have tension, so I do not claim one magic template

Visual:

- `fig05_leave_one_source_out.png`

Key line:

> The improvement generalises better than FSPS, even though external count sources do not all prefer the exact same template.

### Slide 6: Recommendation

Question:

> what should pop-cosmos change?

Say:

- long-wavelength predictions need flexible FIR dust SED treatment
- possible next models: Casey-like, Dale, Draine-Li/CIGALE-style
- Wang should be used for matched-object diagnostics
- radio/X-ray can be future independent checks

Visual:

- maybe no new plot
- optional `fig07_source_to_source_tension.png`

Key line:

> The model is not broken everywhere; the FIR dust SED shape is the lever to improve.

## 10-Slide Version

1. Thesis question / motivation
2. Why observed-space number counts
3. Data sources and flux coverage
4. How the forward model works
5. Baseline FSPS count mismatch
6. Flux-regime residuals: where FSPS fails
7. Template family comparison
8. Casey-like grid result
9. Robustness: leave-one-source-out + P(D)
10. Recommendation and next work

## Likely Viva Questions

### Why use number counts instead of `L_IR` or SFR?

Because counts are closer to what is observed. Converting observed FIR fluxes into `L_IR` requires assuming an FIR template, and the FIR template is exactly what I am testing.

### Why keep `L_IR` fixed?

Because I wanted to isolate SED shape. If both `L_IR` and shape change at the same time, it is harder to tell which lever fixed the counts.

### Does the best `30 K` template mean dust is exactly 30 K?

No. It means the count evaluator currently prefers that region of a simple template family. The safer result is a family-level preference for a warmer/broader SED than baseline FSPS.

### Why not use Wang as the main counts?

Wang is a deblended point-source catalogue built from priors. It is great for matched-object diagnostics, but raw counts from it depend on prior selection, deblending assumptions, SNR cuts, and COSMOS area.

### What does high chi-square mean?

It means model/data mismatch relative to the adopted errors, or incomplete error/systematics treatment. It does not automatically mean overfitting.

### How did you check overfitting?

Leave-one-source-out: pick the best model using all but one count source, then test on the held-out source. The warm-dust correction beats FSPS on every held-out source.

### Why treat P(D) carefully?

P(D) points come from map-level statistical fits and spline constraints. They are useful faint-end information, but their bins are correlated, so I should not pretend they are fully independent source-count bins.

### What would you do next?

Get supervisor sign-off, possibly add a larger H-ATLAS bright-end source if needed, and possibly test a small set of CIGALE/Dale/Draine-Li templates. Only then move to radio/X-ray.

## One-Minute Version

pop-cosmos was mostly constrained at shorter wavelengths, so I tested whether it predicts FIR/sub-mm observables. I built an observed-space evaluator using published SPIRE differential number counts. The baseline FSPS far-IR SED overpredicts counts, especially bright 350/500 um sources. I then kept each galaxy's `L_IR` fixed and changed only the FIR dust SED shape. Warmer/broader templates, especially Casey-like models around `30 K`, improve the counts substantially. The exact best template is not unique, but the direction is stable. The recommendation is that pop-cosmos needs a more flexible FIR dust SED treatment before using it for long-wavelength predictions.

## Final Slide Sentence

> Observed SPIRE counts turn the FIR mismatch into a useful model diagnostic: pop-cosmos needs more flexible dust SED shapes, not just more validation plots.
