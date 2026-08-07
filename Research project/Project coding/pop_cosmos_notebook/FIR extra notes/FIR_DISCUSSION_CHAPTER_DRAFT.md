# Discussion Chapter Draft: What The FIR/SPIRE Evaluator Means

This is a working Discussion draft for the FIR/SPIRE part of the thesis.

The Results chapter says what happened. This chapter is for:

- what the result means physically
- what it says about pop-cosmos
- what the limitations are
- what I would recommend next

## Main Interpretation

The SPIRE number-count comparison suggests that the current pop-cosmos/FSPS far-infrared SED treatment is not flexible enough for long-wavelength predictions.

The strongest evidence is not just that one score improves. It is the pattern of the residuals:

- FSPS is not equally wrong everywhere.
- The mismatch is mildest at 250 um and lower/intermediate fluxes.
- The mismatch becomes much worse at the bright end.
- The mismatch is strongest at 350 and 500 um.

This pattern points toward the far-infrared SED shape rather than only the total infrared luminosity scale.

In simple terms:

> pop-cosmos may be producing roughly plausible total dust luminosities, but distributing that luminosity across FIR/sub-mm wavelengths in a way that is too long-wavelength bright.

That is consistent with Boris's comment that the FSPS dust temperature is effectively frozen and not constrained by the optical/IRAC data.

## Why Number Counts Were Useful

The important methodological move was comparing in observed space.

Instead of asking:

> does pop-cosmos match an observed catalogue's derived `L_IR` or SFR?

the evaluator asks:

> does pop-cosmos predict the right number of observed SPIRE sources at a given flux density?

This avoids adding extra model dependence from converting FIR fluxes back into physical quantities. It also makes the comparison closer to what Herschel/SPIRE actually measured.

This is especially useful because FIR SED assumptions are exactly what the project is testing. If I converted observed 250 um fluxes into `L_IR` using an assumed template, then compared that to pop-cosmos `L_IR`, I would partly bake the answer into the data side.

## What The SED Experiments Show

The model experiments were deliberately controlled:

- the galaxy population was not changed
- redshifts were not changed
- `L_IR` was not changed
- only the FIR SED shape was changed

This makes the result easier to interpret.

Pure ALESS was too strong a correction. It often underpredicted the counts. Simple FSPS/ALESS hybrids improved the baseline, but were empirical rather than physically motivated.

The modified blackbody and Casey-like templates were more useful because they describe the dust SED in a more interpretable way. The current best region is Casey-like and around `T ~ 30 K`.

The safe interpretation is:

> SPIRE counts prefer a warmer/broader dust SED family than the baseline FSPS/pop-cosmos far-IR shape.

The unsafe interpretation would be:

> the true pop-cosmos dust temperature is exactly 30 K.

I should avoid the unsafe version.

## Why The Bright End Matters

The bright end is where the mismatch is clearest, but it is also the regime where care is most needed.

Bright SPIRE sources are rarer, so the result can be affected by:

- survey area
- cosmic variance
- lensing
- source blending
- local overdensities
- small-number statistics

The current bright-end anchor is mainly Clements / H-ATLAS SDP. This is useful, but a larger H-ATLAS / Valiante-style source could strengthen the rare bright-source comparison if supervisors think this is needed.

For the current thesis, the bright-end result should be phrased as:

> the strongest current residual appears at the bright long-wavelength end, and this motivates a more flexible FIR SED treatment.

not:

> the exact abundance of all rare bright sources is now solved.

## Why Wang Is Not The Main Count Truth

The Wang catalogue is very useful, but not in the same way as Clements/Oliver/Pearson number-count tables.

Wang is:

- COSMOS-only
- prior-selected
- deblended with XID+
- built around known source positions
- affected by SNR and prior-list choices
- small-area compared with wide surveys

So raw Wang counts can sit away from published number-count curves for reasons that are not purely model physics.

The raw Wang count-context diagnostic supports this. Changing only the assumed area from `2 deg2` to Wang's cleaner `1.278 deg2` moves the raw count density by about `1.56x`, and including radio-prior rows can lift the curve further. At the bright end, Wang also has small-number statistics because COSMOS is much smaller than wide surveys such as H-ATLAS.

The better use of Wang is matched-object diagnosis:

- are the same COSMOS objects bright in the model and in Wang?
- do residuals correlate with redshift?
- do high-SFR or AGN-like sources drive the mismatch?
- does the model fail for a specific population?

This is still valuable because it can explain which objects are responsible for the count mismatch.

## What P(D) Adds

P(D) analyses such as Glenn and Varnish are valuable because they probe below normal source-extraction limits. They use map-level flux fluctuations rather than direct detections of individual sources.

This means P(D) adds faint-end information, but with a caveat:

- the published spline points are correlated
- they are not simple independent source-count bins
- treating them as independent chi-square points may overstate the precision

The current analysis shows that including P(D) changes the exact preferred `alpha`, but not the broad conclusion. This makes P(D) a good robustness check.

For final thesis wording, my default should be:

> Clements/Oliver/Pearson define the main resolved/prior-count score; Glenn/Varnish P(D) are shown as a faint-end sensitivity check.

With that split, the formal resolved/prior score currently prefers `Casey T30K alpha=3.0`, while the pooled all-count and P(D)-only checks prefer `Casey T30K alpha=2.5`. This is a parameter-level difference, not a story-level difference.

## Source-To-Source Tension

Different observed count products prefer slightly different model variants.

This could be due to:

- field-to-field variance
- different survey depths and areas
- extraction method differences
- completeness and reliability corrections
- P(D) vs resolved-source methodology
- real differences between faint and bright source populations

This tension is not a failure of the thesis. It is part of the result.

It means I should present the conclusion as:

> a stable physical direction across several count products

rather than:

> one exact template that perfectly fits every survey.

The leave-one-source-out test helps here. The selected warm-dust correction beats FSPS on every held-out count source, even when it is not the exact best model for that source.

## What This Means For Pop-Cosmos

The main recommendation to the pop-cosmos team is:

> Long-wavelength predictions should not rely on a fixed, unconstrained FIR dust SED shape.

Possible improvements:

1. allow the FIR dust temperature or radiation-field parameters to vary
2. add a physically motivated dust SED family such as Casey-like, Dale, or Draine-Li templates
3. link dust temperature to galaxy properties such as `L_IR`, SFR surface density, compactness, or redshift
4. treat AGN/high-SFR tail sources separately
5. validate against observed-space quantities such as differential counts before interpreting physical quantities

The current work does not prove which implementation is best. It shows where the baseline model is weak and gives a practical evaluator for testing alternatives.

## Relation To CIGALE / Dust Template Literature

CIGALE and related SED-fitting tools already include multiple dust-emission models, including Draine-Li-style and other templates. This is relevant because it shows that flexible dust SED treatment is standard in SED modelling.

For this thesis, there are two possible levels:

### Minimum

Discuss CIGALE/Dale/Draine-Li as physically motivated future work.

This is enough if the Casey-like grid is accepted as a simple model-extension demonstration.

### Stronger Extension

Actually add a small set of CIGALE/Dale/Draine-Li-style templates into the same evaluator.

This would make the thesis stronger, but it could also become a new project. I should only do this if supervisors think the Casey-like grid is too toy-like.

## Limitations

### The Evaluator Is Diagnostic

The chi-square-style score is useful for ranking models, but it is not a full likelihood model.

Reasons:

- count products have different systematics
- P(D) points are correlated
- some errors are approximated
- field-to-field variance is not fully modelled
- model points are interpolated onto observed flux bins

So final wording should say:

> rough chi-square score

or:

> diagnostic scorecard

unless a more formal likelihood is added.

### Counts Alone Are Not Everything

Number counts are powerful, but they do not uniquely identify the underlying physical cause.

For example, similar count changes could come from:

- FIR SED shape
- dust temperature evolution
- high-SFR tail issues
- AGN contamination
- lensing at the bright end
- redshift distribution differences

This is why Wang matched-object checks and future redshift-aware diagnostics are useful.

### The Best Template Is Not Unique

The current formal score prefers Casey-like `T30K alpha=3.0`, while the pooled/P(D) checks prefer nearby Casey-like variants. This should be framed as a family-level preference rather than a precise parameter measurement.

### Bright-End Statistics Need Care

The strongest FSPS residual is at the bright end, but rare bright sources require large areas. If the thesis leans heavily on the bright-end claim, adding a larger H-ATLAS / Valiante source may be worth doing.

## Recommended Final Claim

The final claim should be something like:

> By comparing pop-cosmos predictions directly to observed SPIRE differential number counts, I find that the baseline FSPS far-infrared SED overpredicts bright long-wavelength counts. Holding each galaxy's `L_IR` fixed and changing only the FIR SED shape substantially improves the comparison, with the current evaluator preferring warm/broader Casey-like templates around 30 K. This suggests that the pop-cosmos FIR dust treatment needs additional SED-shape flexibility before it can be used reliably for long-wavelength predictions.

## What To Do Next

Near-term:

1. get supervisor sign-off on P(D) and chi-square wording
2. decide whether Clements is enough for bright-end counts
3. decide whether Casey-like templates are enough for the model-extension demonstration
4. make the top 4 figures final-quality
5. write the final Methods and Results sections

If there is extra time:

1. add one Wang matched-object residual diagnostic
2. inspect the high-SFR / AGN-like tail
3. add a larger H-ATLAS bright-end source
4. test a small CIGALE/Dale/Draine-Li template subset

Do not start radio/X-ray until the FIR chapter is stable.
