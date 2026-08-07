# FIR / SPIRE Evaluator Thesis Draft

This is a working draft for the thesis/report. It is not final text, but it is written closer to report style than the meeting notes.

## Current Thesis Claim

The pop-cosmos optical/NIR-calibrated population can be tested at longer wavelengths by forward-modelling observed SPIRE number counts. In the current tests, the baseline FSPS/pop-cosmos far-IR SED shape overpredicts SPIRE counts, especially at the bright end and at longer wavelengths. Replacing only the far-IR dust SED shape, while keeping each galaxy's original `L_IR` fixed, substantially improves agreement with published differential counts.

The strongest current result is not that one exact template is "the truth". The more defensible result is:

> Published SPIRE differential counts prefer a warmer/broader far-IR dust SED than the baseline FSPS/pop-cosmos treatment at fixed `L_IR`.

## Observational Data Role

The evaluator separates observed data into three roles.

| data source | role in thesis | reason |
|---|---|---|
| Clements 2010 H-ATLAS | formal resolved/prior count score | bright/wide SPIRE counts with published corrections |
| Oliver 2010 HerMES | formal resolved/prior count score | classic HerMES resolved differential counts |
| Pearson 2025 SUSSEXtractor/XID | formal resolved/prior count score | deep SPIRE Dark Field extraction methods |
| Glenn 2010 P(D) | faint-end sensitivity score | statistical counts below normal extraction limits |
| Varnish 2025 P(D) | faint-end sensitivity score | deepest statistical SPIRE Dark Field constraint |
| Wang 2024 COSMOS XID+ | matched-object sanity check | point-source catalogue, useful for per-object residuals but not a corrected count table |
| Bethermin 2012 | method/context | stacking reaches below confusion and motivates redshift-aware counts, but no clean numeric total-count table found yet |
| Bethermin 2017 SIDES | model/context | simulated sky reference, not an observed-count dataset |

The key decision is to use published corrected differential counts for the formal population score, while using Wang for object-level diagnostics.

## Wang Catalogue Check

Wang et al. 2024 is a deblended point-source catalogue produced with XID+. The local `master.dat` table has:

- `131178` rows
- `128387` positive COSMOS2020 IDs
- `2791` negative radio-only IDs
- SPIRE/SCUBA flux columns in `mJy`
- the relevant COSMOS2020/Farmer `FLAG_COMBINED=0` area is `1.278 deg2`

This explains why raw Wang counts should not be treated as equivalent to published corrected number counts. Wang includes prior-selection effects, radio-only additions, SNR/flux choices, and a relatively small COSMOS area. It is better used to ask:

- are the right objects bright?
- do residuals depend on SFR, redshift, `L_IR`, or AGN-like parameters?
- does the model fail for a particular population?

### Why Wang Looks Different From Published Counts

The useful distinction is:

- Clements/Oliver/Pearson publish corrected number-count measurements.
- Wang publishes a deblended catalogue at prior positions.

So a raw count from Wang is not wrong, but it answers a slightly different question. It depends on the prior list, SNR cut, flux cut, field area, and deblending assumptions. This is especially important at the bright end because COSMOS is a small field, and at 500/850 um because the number of bright sources becomes tiny.

Using only positive COSMOS2020 IDs and the `1.278 deg2` Wang/Farmer area:

| band | cut | raw N | raw N / deg2 |
|---|---:|---:|---:|
| 250 um | >10 mJy | 3849 | 3011.7 |
| 250 um | >50 mJy | 47 | 36.8 |
| 350 um | >10 mJy | 2609 | 2041.5 |
| 350 um | >50 mJy | 12 | 9.4 |
| 500 um | >10 mJy | 1019 | 797.3 |
| 500 um | >50 mJy | 1 | 0.8 |
| 850 um | >10 mJy | 9 | 7.0 |

This supports using Wang as an object-level diagnostic rather than as the main population-count truth table.

## Model Variants

All variants keep the pop-cosmos galaxy population fixed. The test changes only the far-IR dust SED used to map `L_IR` into observed SPIRE fluxes.

| model family | simple description |
|---|---|
| FSPS baseline | original pop-cosmos/FSPS far-IR SED shape |
| ALESS empirical template | observed SMG-like far-IR template scaled to each galaxy's `L_IR` |
| FSPS/ALESS hybrids | rest-frame weighted mix between the FSPS and ALESS shapes |
| modified blackbody grid | simple dust-temperature family |
| Casey-like templates | modified blackbody plus mid-IR power-law tail |

For each galaxy:

1. take the model `L_IR`
2. choose a far-IR SED shape
3. normalise that SED so the 8-1000 um integral matches the original `L_IR`
4. redshift to observed frame
5. predict observed fluxes at 250, 350, and 500 um
6. rebuild differential counts
7. compare to published counts

## Count Evaluator

The evaluator works in observed space, not physical-converted space. It compares the model-predicted differential counts directly to published SPIRE differential counts.

Current score:

```text
chi2 = sum((log10(model_count) - log10(observed_count))^2 / sigma_log^2)
rough reduced chi2 = chi2 / N_points
```

Why log space:

- counts span orders of magnitude
- a linear score would be dominated by the largest bins
- log residuals are easier to interpret as multiplicative errors

Why differential counts:

- differential count bins are closer to independent than cumulative counts
- supervisor feedback said differential counts are better for model comparison

Important caveat:

This is a diagnostic scorecard, not a final likelihood model. A simple `chi2/(N-k)` correction gives the same ranking, but final thesis wording should still call this a rough chi-square score unless a stricter likelihood treatment is added.

## Main Results So Far

Current pooled ranking:

| model | rough reduced chi2 | median log10(model/obs) |
|---|---:|---:|
| Casey T30K alpha=2.5 | 3.36 | -0.03 |
| Casey T30K alpha=3.0 | 3.48 | +0.07 |
| 25% ALESS | 4.17 | +0.12 |
| 50% ALESS | 4.20 | -0.06 |
| MBB 35 K | 4.26 | -0.11 |
| FSPS baseline | 8.40 | +0.31 |
| ALESS | 13.33 | -0.41 |

Simple read:

- baseline FSPS is too high overall in SPIRE counts
- pure ALESS overcorrects and becomes too low
- the best models are intermediate, physically motivated warm/broader dust SEDs
- Casey-like `T ~ 30 K` templates are currently the cleanest model-extension demonstration

## Where FSPS Fails

The baseline FSPS result is not equally bad everywhere.

| band | flux regime | median log10(model/obs) | rough factor |
|---|---|---:|---:|
| 250 um | 10-30 mJy | +0.11 | 1.3x high |
| 250 um | 30-100 mJy | +0.20 | 1.6x high |
| 250 um | 100-300 mJy | +0.69 | 4.9x high |
| 350 um | 100-300 mJy | +0.82 | 6.6x high |
| 500 um | 100-300 mJy | +1.08 | 11.9x high |

This supports the meeting summary:

> FSPS does reasonably at 250 um low/mid fluxes, but increasingly overpredicts counts at longer wavelengths and especially at the bright end.

Physical interpretation:

- the baseline far-IR SED is likely too cold / too long-wavelength bright
- this affects bright long-wavelength counts strongly
- changing SED shape improves the counts without first changing the total `L_IR` normalisation

## Robustness Checks

### P(D) sensitivity

| score group | best model | rough reduced chi2 |
|---|---|---:|
| all counts | Casey T30K alpha=2.5 | 3.36 |
| resolved/prior counts only | Casey T30K alpha=3.0 | 3.29 |
| P(D) statistical counts only | Casey T30K alpha=2.5 | 2.17 |

The exact alpha changes slightly, but the broad result remains a Casey-like warm/broader dust SED around `30 K`.

### Leave-one-source-out

The selected warm-dust correction beats FSPS on every held-out count source. It is not always the best possible model on the held-out source, which is actually useful: it shows the result generalises, but the external count products still have real tension.

### Degrees-of-freedom check

Subtracting simple template parameter counts does not change the ranking. This supports using the current score as a diagnostic ranking metric, while being careful not to overstate it as a final formal likelihood.

## Current Limitations

- P(D) spline points are correlated and should probably be shown separately or treated as sensitivity constraints.
- Varnish errors are approximated from published log lower/upper values.
- Cosmic variance and field selection matter, especially for small areas and bright counts.
- Wang should not be mixed into the formal corrected-count score without careful selection/completeness modelling.
- Counts alone may not fully constrain galaxy evolution models; redshift distributions and per-object diagnostics are needed for the next layer.
- Current dust models are deliberately simple; comparison to full CIGALE/Dale/Draine-Li template families may be a natural extension.

## Thesis Story Shape

One possible chapter/story structure:

1. pop-cosmos works well where it was originally calibrated
2. far-IR/sub-mm counts provide an observed-space validation outside the fitted optical/IRAC regime
3. baseline FSPS overpredicts bright long-wavelength SPIRE counts
4. the mismatch points to dust SED shape / temperature, not necessarily total `L_IR`
5. physically motivated dust-template changes improve the counts
6. the exact best template is not unique, but the direction is stable
7. Wang matched-object checks and future radio/X-ray tests can diagnose which populations drive the residuals

## Next Thesis Work

Near-term:

- decide the final formal score set: resolved/prior only vs resolved/prior plus P(D)
- make final publication-style plots with consistent labels and captions
- write the methods section around the evaluator pipeline
- ask Boris/Dave whether `chi2/N` wording is acceptable or if `chi2/(N-k)` should be used throughout

Medium-term:

- add a redshift-aware diagnostic if time allows
- use Wang matched-object residuals to inspect high-SFR / AGN-ish sources
- consider comparing proper CIGALE/Dale/Draine-Li dust models using the same evaluator
- decide whether Valiante/H-ATLAS DR1 is needed for rare bright-tail constraints
