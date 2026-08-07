# FIR Intro / Literature Context Draft

This is a rough front-end draft for the thesis. It is meant to explain why the FIR number-count work matters before getting into the code/results.

## Draft Thesis Opening

Galaxy evolution models are usually judged by whether they reproduce the observed galaxy population across cosmic time. A model can look good in the optical or near-infrared, but still fail in the far-infrared if it handles dust-obscured star formation incorrectly. This matters because a large fraction of star formation is hidden by dust and re-emitted at far-infrared/sub-mm wavelengths.

For this project, I use pop-cosmos as the model being tested. Pop-cosmos generates a synthetic galaxy population and predicts spectral energy distributions (SEDs) for each object. The important question is not only whether the model gives reasonable physical parameters like stellar mass, SFR, or `L_IR`, but whether it predicts the actual observed fluxes that surveys would measure.

The main validation test here is therefore done in observed space:

> predict SPIRE 250/350/500 um fluxes from pop-cosmos, turn those fluxes into differential number counts, and compare them against published corrected Herschel count measurements.

This is useful because number counts avoid some of the model-dependence involved in converting real observed fluxes back into derived quantities like `L_IR` or SFR. In simple terms, I am asking: if pop-cosmos made a sky, would Herschel have seen the right number of galaxies at each brightness?

## Why FIR / Sub-mm Counts Are A Good Test

The far-infrared is a strong out-of-sample test for pop-cosmos because the original COSMOS constraints mostly stop around the optical/near-IR/mid-IR regime. The long-wavelength dust emission is therefore less directly constrained.

SPIRE number counts are especially useful because they compress a large amount of survey information into a simple observable:

- `S` is the observed flux density, basically how bright a source looks in a band
- `dN/dS` is the number of sources per flux bin, per area on the sky
- `S^2.5 dN/dS` is the Euclidean-normalised version, which is commonly used so the shape of the counts is easier to compare

Differential counts are better than integral counts for the formal comparison because each flux bin is closer to being an independent measurement. Integral counts `N(>S)` are still useful visually, but the errors are correlated because every bright source is also included in every fainter threshold.

## Pop-Cosmos / FSPS Context

The baseline pop-cosmos SEDs come from FSPS-style stellar population modelling, with energy balance fixing the total dust luminosity `L_IR`. Boris's feedback was that the far-IR dust temperature is effectively not very flexible in the current setup. So the model can have a plausible total infrared luminosity while still putting that luminosity into the wrong part of the far-IR SED.

This is the core physical idea of the project:

> keep each galaxy's original pop-cosmos `L_IR`, but test whether a different FIR SED shape predicts more realistic SPIRE counts.

That means the project is not just changing luminosities until the plots match. It is testing whether the shape/temperature of the dust emission is the part of the model that needs improvement.

## Observational Count Data Used

The count comparison uses published number-count tables rather than recalculating counts directly from catalogues. This is better for the thesis because the published tables already include survey-specific corrections like completeness, reliability, flux boosting/deboosting, and selection effects.

Current count sources:

| source | role in thesis | how I use it |
|---|---|---|
| Clements et al. 2010 / H-ATLAS | bright/wide-area SPIRE counts | anchors the brighter end, where rare sources matter |
| Oliver et al. 2010 / HerMES | resolved differential counts | middle comparison between deep and wide surveys |
| Pearson et al. 2025 / SPIRE Dark Field | very deep resolved/prior counts | tests the fainter Herschel regime |
| Glenn et al. 2010 / P(D) | statistical faint-end counts | sensitivity check below normal source extraction |
| Varnish et al. 2025 / P(D) | deep Dark Field statistical counts | sensitivity check, not the cleanest formal score |
| Wang et al. catalogue | matched-object diagnostic | useful for per-object flux residuals, but not the main corrected count table |

My current default is:

- main formal score: Clements + Oliver + Pearson
- P(D): sensitivity check
- Wang: matched-object diagnostic / sanity check

That choice still needs supervisor sign-off, but it feels like the cleanest thesis structure.

## Dust SED / Template Context

The first simple experiment used ALESS, an empirical average SED for sub-mm galaxies. The idea was: if real dusty star-forming galaxies have a different FIR shape from the baseline FSPS SED, replacing the far-IR bump with an ALESS-like shape should change the SPIRE counts.

The later and stronger version is the modified-blackbody / Casey-like grid. This is more thesis-friendly because it lets the dust SED change in a controlled way:

- temperature changes where the dust peak sits
- the mid-IR slope changes how broad/hot the SED looks
- the total `L_IR` is preserved for every galaxy

So the model-extension question becomes:

> what FIR SED shape, at fixed pop-cosmos `L_IR`, best reproduces observed SPIRE counts?

This also connects naturally to CIGALE / Dale / Draine-Li style dust models. Those are more complete SED modelling frameworks or template families that could be tested later. For this thesis, the Casey-like grid is a useful controlled evaluator experiment, while CIGALE-style comparisons are a strong next-step or future-work direction unless supervisors want them added now.

## Current Thesis Gap / Contribution

The useful contribution is not just "I compared some plots". The thesis is closer to:

> I built an observed-space evaluator for pop-cosmos at FIR/sub-mm wavelengths, showed that the baseline FSPS dust SED overpredicts SPIRE number counts, and tested physically motivated FIR SED changes while keeping the original galaxy population and `L_IR` fixed.

This gives the pop-cosmos team a concrete diagnostic:

- the issue is strongest at long SPIRE wavelengths and bright fluxes
- the mismatch points more toward FIR SED shape / dust temperature than simply wrong `L_IR`
- a warmer/broader FIR dust treatment improves the external count comparison
- the exact best template is not unique, so the result should be framed as a stable direction rather than one final dust model

## Citation / Reading TODO

Use these as the core literature spine:

| paper/topic | why it matters |
|---|---|
| pop-cosmos paper / Boris notebook | model being tested |
| FSPS | baseline SED modelling context |
| Draine & Li / Dale & Helou / CIGALE dust models | template-model context for FIR dust emission |
| Clements et al. 2010 | H-ATLAS bright/wide SPIRE counts |
| Oliver et al. 2010 | HerMES resolved SPIRE counts |
| Pearson et al. 2025 | SPIRE Dark Field deep counts |
| Glenn et al. 2010 | P(D) method and faint statistical counts |
| Varnish et al. 2025 | newer Dark Field P(D) faint-end result |
| Wang catalogue paper | COSMOS deblended FIR/mm matched-object comparison |
| Bethermin papers | stacking/model context and how counts constrain galaxy evolution models |

## Simple Story Version

Very short version I can say in a meeting:

> Pop-cosmos is calibrated mainly at shorter wavelengths, so I tested it in the far-IR using observed SPIRE number counts. The baseline FSPS dust SED predicts too many bright long-wavelength sources. If I keep each galaxy's `L_IR` fixed but change the FIR dust shape, the counts improve, especially with warmer/broader Casey-like templates. So the main recommendation is that pop-cosmos needs more flexible FIR dust SED modelling, not just more validation plots.
