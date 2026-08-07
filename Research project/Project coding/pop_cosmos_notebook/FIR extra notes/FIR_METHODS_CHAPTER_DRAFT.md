# Methods Chapter Draft: FIR/SPIRE Observed-Space Validation

This is a working thesis Methods draft. It is not final polished text yet, but it is written in a report style rather than meeting-note style.

## Aim Of The Method

The aim of this part of the project is to test pop-cosmos outside the wavelength range where it was originally most directly constrained. Instead of converting observations into derived physical quantities such as `L_IR` or SFR, I compare the model to observed quantities: SPIRE flux-density number counts at 250, 350, and 500 um.

This is useful because number counts are closer to the actual measurement. They ask a simple question:

> how many sources are predicted above a given observed flux density, and does that match the sky?

The method keeps the pop-cosmos galaxy population fixed and changes only the far-infrared SED used to convert each galaxy's `L_IR` into observed SPIRE fluxes.

## Input Pop-Cosmos Quantities

The relevant pop-cosmos / FSPS quantities are:

| quantity | meaning | use here |
|---|---|---|
| `wave_rest` | rest-frame wavelength grid | defines the model SED wavelength axis |
| `spec_attenuated` | attenuated FSPS SED | baseline pop-cosmos SED shape |
| `L_IR` | total 8-1000 um infrared luminosity | normalisation fixed for each galaxy |
| `z` | galaxy redshift | redshifts the SED into observed frame |
| catalogue position / ID fields | source identity | matching and diagnostic bookkeeping |

The important modelling choice is that `L_IR` is not refitted in the main experiments. Instead, every alternative dust SED is scaled so that its 8-1000 um luminosity integral equals the original pop-cosmos `L_IR`.

This means the experiment is testing:

> is the total infrared luminosity wrong, or is the far-IR SED shape used to distribute that luminosity across wavelength wrong?

## Observational Count Data

The main evaluator uses published SPIRE differential number counts from:

| source | use |
|---|---|
| Clements et al. 2010 | H-ATLAS bright/wide resolved counts |
| Oliver et al. 2010 | HerMES resolved counts |
| Pearson et al. 2025 Table 3 | SPIRE Dark Field SUSSEXtractor counts |
| Pearson et al. 2025 Table 4 | SPIRE Dark Field XID counts |

The P(D) count products are treated separately or as sensitivity tests:

| source | use |
|---|---|
| Glenn et al. 2010 | HerMES P(D) statistical counts |
| Varnish et al. 2025 | SPIRE Dark Field P(D) statistical counts |

P(D) constraints are valuable because they probe below the normal source-extraction limit, but their published points are model-fit spline constraints and are not as independent as ordinary differential count bins.

## Wang Catalogue Role

The Wang et al. 2024 COSMOS XID+ catalogue is used differently from the published count tables.

The local `master.dat` catalogue has:

- `131178` rows
- `128387` positive COSMOS2020 IDs
- `2791` negative radio-prior IDs
- flux columns in `mJy`
- a relevant COSMOS2020/Farmer area of `1.278 deg2`

Wang is a deblended point-source catalogue, not a corrected population number-count table. It is therefore better suited for matched-object diagnostics:

- checking if the same COSMOS objects are bright in model and observations
- looking for residual trends with SFR, redshift, or AGN-like parameters
- identifying suspicious high-SFR / hot-dust sources

I do not use raw Wang counts as the main formal population-count score.

As a sanity check, I also compute raw Wang cumulative counts under a few area/selection assumptions. This is used only as a diagnostic context plot. It shows how much the Wang curve moves when using the `1.278 deg2` area instead of `2 deg2`, when applying `SNR>=3`, and when including negative radio-prior IDs.

## SED Model Variants

Each model variant changes only the shape of the far-infrared SED.

| model | description |
|---|---|
| FSPS baseline | original pop-cosmos/FSPS FIR SED |
| ALESS | empirical SMG-like template scaled to `L_IR` |
| FSPS/ALESS hybrids | weighted rest-frame mixture of FSPS and ALESS shapes |
| MBB grid | modified blackbody dust-temperature grid |
| Casey-like grid | modified blackbody plus mid-IR power-law tail |

The current thesis result should not claim that one template is uniquely correct. These templates are used as controlled perturbations to test which kind of FIR SED shape improves the observed counts.

## Template Normalisation

For each galaxy and each template:

1. define a rest-frame FIR SED shape
2. integrate the template over `8-1000 um`
3. scale the template so that the integral equals the galaxy's pop-cosmos `L_IR`

In simple notation:

```text
L_template_scaled(lambda) = A * L_template_shape(lambda)
```

where `A` is chosen so that:

```text
integral_8-1000um L_template_scaled(lambda) d(lambda) = L_IR_popcosmos
```

This keeps the energy scale fixed and isolates the effect of changing the FIR shape.

## From Rest-Frame SED To Observed Flux

After the template is normalised, it is redshifted and converted into observed flux density.

The observed wavelength is related to rest wavelength by:

```text
lambda_obs = lambda_rest * (1 + z)
```

For a fixed observed SPIRE band, for example 250 um, the corresponding rest-frame wavelength is:

```text
lambda_rest = 250 um / (1 + z)
```

The luminosity distance converts luminosity into observed flux. Conceptually:

```text
rest-frame SED + redshift + luminosity distance -> observed flux density
```

The output of this step is a predicted observed flux density for each pop-cosmos galaxy in each SPIRE band:

- `F250`
- `F350`
- `F500`

These are directly comparable to observed flux-density count data.

## Differential Number Counts

For each model and SPIRE band, predicted galaxy fluxes are binned into differential number counts.

The differential count is:

```text
dN/dS
```

where:

- `N` is the number of sources
- `S` is flux density
- `dN/dS` is the number of sources per flux-density bin, per sky area

Most SPIRE count papers plot Euclidean-normalised counts:

```text
S^2.5 dN/dS
```

The evaluator standardises all external count tables into:

```text
Jy^1.5 deg^-2
```

This unit standardisation was important because different papers report counts in different forms, for example per steradian, per square degree, in Jy, or in mJy.

## Evaluator Score

The model is compared to the observed counts in log space.

For each observed count point, the model count is interpolated to the same flux density. The residual is:

```text
residual = log10(model_count) - log10(observed_count)
```

The current score is:

```text
chi2 = sum((log10(model_count) - log10(observed_count))^2 / sigma_log^2)
```

Log space is used because number counts span several orders of magnitude. A linear-space score would be dominated by the largest bins and would make the faint/bright balance harder to interpret.

For the thesis-facing formal score, I use the corrected resolved/prior count products only:

- Clements et al.
- Oliver et al.
- Pearson SUSSEXtractor
- Pearson XID

and report a simple degrees-of-freedom corrected score:

```text
chi2 / (N_points - k)
```

where `k` is the number of simple template hyperparameters:

- fixed FSPS / ALESS templates: `0`
- FSPS/ALESS mixing fraction: `1`
- modified blackbody temperature: `1`
- Casey-like `T_dust` and `alpha`: `2`

This is still a diagnostic chi-square-style score, not a full likelihood model. The pooled all-count score and P(D)-only score are kept as sanity/sensitivity checks.

## Robustness Checks

The evaluator includes three checks against overinterpreting the result.

### P(D) Sensitivity

The score is computed with and without P(D) statistical counts.

Current result:

| score group | role | best model |
|---|---|---|
| resolved/prior counts only | formal thesis score | Casey-like `T30K alpha=3.0` |
| all counts | pooled sanity check | Casey-like `T30K alpha=2.5` |
| P(D) counts only | faint-end sensitivity | Casey-like `T30K alpha=2.5` |

The exact parameter changes slightly, but the preferred family remains similar.

### Leave-One-Source-Out

The model is selected using all but one observed count source, then tested on the held-out source.

The selected warm-dust correction beats FSPS on every held-out source, although it is not always the best possible model for that source. This supports the main result while also showing real source-to-source tension.

### Flux-Regime Residuals

Residuals are split by wavelength and flux range. This shows where FSPS fails most clearly:

- mild overprediction at 250 um low/mid fluxes
- stronger overprediction at bright 250 um
- increasingly severe overprediction at 350 and 500 um, especially at high flux

This is important because it turns the result from "the model is bad" into a more useful diagnosis:

> the problem is strongest in the bright long-wavelength FIR/sub-mm regime.

## Reproducibility

The current summary pipeline is:

```text
python run_fir_evaluator_pipeline.py --mode summary
```

This refreshes:

- external count compilation
- Wang catalogue checks
- count-source coverage plot
- differential-count evaluator
- model-family score summary
- thesis-facing formal evaluator summary
- P(D) sensitivity
- leave-one-source-out validation
- source-tension plot
- flux-regime diagnostics
- thesis evaluator snapshot

The heavier full pipeline is:

```text
python run_fir_evaluator_pipeline.py --mode full
```

This should only be needed when rebuilding the expensive model-count products.

## Method Summary

In one sentence:

> I forward-model pop-cosmos galaxies into observed SPIRE fluxes, rebuild number counts, and use published differential counts to evaluate whether changing the FIR dust SED shape improves the model while keeping `L_IR` fixed.
