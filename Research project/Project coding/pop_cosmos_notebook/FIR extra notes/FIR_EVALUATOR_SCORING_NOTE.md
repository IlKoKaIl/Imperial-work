# FIR Evaluator Scoring Note

This note translates Dave's evaluator advice into the setup I should use in the thesis.

## Main Decision

Use differential counts as the main quantitative comparison.

Reason:

> differential bins are closer to independent measurements, while integral counts `N(>S)` reuse the same sources in many thresholds.

So the main score should be built from:

- published differential counts
- flux bins with quoted errors
- the same unit everywhere: `S^2.5 dN/dS` in `Jy^1.5 deg^-2`

## Formal Score Vs Sensitivity Checks

My current default:

| role | data |
|---|---|
| formal score | Clements, Oliver, Pearson SUSSEX, Pearson XID |
| faint-end sensitivity | Glenn P(D), Varnish P(D) |
| matched-object diagnostics | Wang |
| literature/method context | Bethermin 2012, Bethermin 2017/SIDES |

Why:

- Clements / Oliver / Pearson are published corrected count tables
- P(D) is powerful but the spline points are correlated/statistical, not simple independent source bins
- Wang is a prior-selected deblended catalogue, not a corrected number-count paper

August 3rd paper check:

- Wang Table 4 is a released object catalogue, not a corrected number-count table.
- Wang confirms `F_250/350/500` are in `mJy`, so the Wang mismatch is probably not a unit error.
- Wang's own simulations say SPIRE output counts are close above about `10 mJy`, but faint counts can fall below truth at `<10 mJy`.
- Glenn and Varnish P(D) are valuable because they reach faint fluxes statistically, but their spline/count points should not be treated as totally independent without covariance.

## Score Definition

Current score:

```text
chi2 = sum((log10(model_count) - log10(observed_count))^2 / sigma_log^2)
```

Then either:

```text
rough score = chi2 / N_points
```

or:

```text
simple reduced score = chi2 / (N_points - k)
```

where `k` is the number of simple template parameters.

My current preference for thesis wording:

> use `chi2/(N-k)` in the thesis-facing summary, but call it a rough chi-square-style evaluator unless supervisors want a stricter likelihood model.

## Does High Chi-Square Mean Overfitting?

No.

Simple version:

> high chi-square means the model and data disagree more than expected from the quoted errors.

It could mean:

- model physics is missing
- observational errors are underestimated
- count sources have unmodelled systematics
- bins/sources are not fully independent
- cosmic variance matters
- the model is genuinely wrong in that regime

Overfitting is a different question:

> did I tune the model so closely to this data set that it stops generalising?

Current overfitting guards:

- leave-one-count-source-out test
- compare separate count sources, not just one plot
- do not tune a different template per paper or per wavelength
- keep each galaxy's pop-cosmos `L_IR` fixed
- use physically interpretable template families
- keep Wang outside the formal score

Important wording:

> high chi-square is evidence that the model / uncertainties / comparison setup are not fully explaining the data. It is not by itself evidence that I overfit.

Overfitting would be if I tuned the FIR SED separately for every paper, flux bin, or wavelength until the curve sat on the points. The current setup is much more constrained: one template family, fixed `L_IR`, same forward model, and leave-one-source-out checks.

## Current Formal Result

The thesis-facing summary output is:

- `outputs/popcosmos_formal_evaluator_summary.md`
- `outputs/popcosmos_formal_evaluator_summary.csv`
- `outputs/popcosmos_formal_evaluator_summary.png`

Current simple read:

> resolved/prior differential counts prefer a Casey-like template around 30 K over baseline FSPS. P(D) changes details but not the broad direction.

## What To Ask Supervisors

Good short question:

> Does this scoring split make sense: Clements/Oliver/Pearson as the main corrected-count score, Glenn/Varnish P(D) as a sensitivity check, and Wang as matched-object diagnostics?

More technical question:

> Is `chi2/(N-k)` with simple template-parameter counts enough for thesis wording, or should I keep calling it a diagnostic `chi2/N` score?

Physics question:

> Is a Casey-like grid enough as the model-extension demonstration, or should I add a small CIGALE/Dale/Draine-Li template comparison?
