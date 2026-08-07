# FIR Count Source Roadmap

This is a planning note for the SPIRE number-count side of the thesis.

The point is to avoid endlessly adding papers just because they exist. Each count source should have a clear job.

## Current Count Coverage

Generated helper files:

- `outputs/external_count_source_flux_coverage.csv`
- `outputs/external_count_source_flux_coverage.png`

![External count source flux coverage](outputs/external_count_source_flux_coverage.png)

Simple read:

- Pearson covers the deep detected/prior-extracted regime, roughly `10-100 mJy`.
- Oliver bridges the classic HerMES resolved-count regime, roughly `20-400 mJy`.
- Clements gives the current bright/wide anchor, roughly `30-800 mJy`.
- Glenn and Varnish P(D) push much fainter, but these are statistical spline constraints, not simple independent detected-source bins.

## What Is Already Enough

For a Masters thesis, the current observed-count set is already decent:

| role | sources |
|---|---|
| formal resolved/prior count evaluator | Clements, Oliver, Pearson SUSSEX, Pearson XID |
| faint-end sensitivity check | Glenn P(D), Varnish P(D) |
| matched-object diagnostic | Wang |
| method/literature support | Bethermin 2012 stacking, Bethermin 2017 SIDES |

This is enough to tell the main story:

> pop-cosmos/FSPS overpredicts long-wavelength SPIRE counts, especially the bright end. Changing the FIR dust SED shape at fixed `L_IR` improves the observed-count comparison.

## What Not To Do Unless Needed

Do not keep adding count papers just to make the plot look busier.

Reasons:

- different papers use different extraction methods, completeness corrections, areas, and flux bins
- P(D), stacking, prior-extraction, and blind extraction are not exactly the same kind of measurement
- adding more sources can make the thesis messier if the role of each source is not clear

So the default should be:

> freeze the current data sources unless a new source fills a specific gap.

## If I Add One More Source

The best next source would probably be a larger H-ATLAS / Valiante-style wide-area count source.

Why:

- the current suspected FSPS failure is strongest at the bright end
- rare bright sources need large area
- Clements is useful but only the early H-ATLAS SDP area
- a larger H-ATLAS source would test whether the bright-end excess remains against a better wide-area benchmark

Question to ask Dave/Boris:

> Is the current Clements H-ATLAS SDP bright-end anchor enough, or should I add a larger H-ATLAS / Valiante count table specifically to strengthen the rare bright-end comparison?

## How To Use Wang

Wang should stay separate from the published-count evaluator.

Use Wang for:

- matched-object residuals
- checking whether the right COSMOS objects are bright
- high-SFR / AGN-ish source diagnostics
- redshift or SFR residual trends

Do not use raw Wang catalogue counts as the main population-count truth unless I also model the catalogue selection, prior list, SNR cuts, and area carefully.

Paper/data re-check:

- Wang fluxes are in `mJy`, so the mismatch is not just a unit conversion mistake.
- Wang area should be `1.278 deg2` for the clean COSMOS2020/Farmer selected region.
- Wang's own simulations say 250 um output counts are close to the truth above about `10 mJy`, but fainter counts can be biased low.
- Therefore, if I show Wang raw counts, I should use them as a sanity check and keep the cut/area written directly on the plot.

Current diagnostic:

- `outputs/wang_raw_count_context.png`
- `outputs/wang_raw_count_context_note.md`

Simple read:

> Wang raw cumulative counts are useful context, but they should not replace corrected published differential counts in the formal evaluator.

## How To Use Bethermin

Bethermin 2012 is useful because it shows why stacking and redshift-sliced counts matter below the confusion limit.

But for now:

- I have not found a clean total-count numeric table to add directly to the evaluator
- it should be cited as method/context, not mixed into the formal score

Bethermin 2017 / SIDES is even more clearly model context:

- useful for saying counts, P(D), and CIB are standard model-validation quantities
- not an observed data source to score pop-cosmos against
- useful warning that angular resolution/blending can bias single-dish counts, especially around 350/500 um

Varnish / Dark Field II re-check:

- Varnish compares to Clements, Oliver, Bethermin 2012, Glenn 2010, and model curves including Bethermin/SIDES.
- They report good agreement with previous observed counts down to about `20 mJy`, then P(D) becomes the key tool at fainter fluxes.
- Their reduced-chi-square table for literature models is a useful example of the evaluator style Dave mentioned.

## Recommended Thesis Setup

Main score:

- Clements
- Oliver
- Pearson SUSSEX
- Pearson XID

Sensitivity/robustness:

- Glenn P(D)
- Varnish P(D)

Diagnostics:

- Wang matched-object comparisons
- high-SFR / AGN-ish SED checks

Possible extension only if asked:

- larger H-ATLAS / Valiante bright-end counts

## Practical Next Step

I think the next thesis work should be writing and tightening, not more data hunting, unless supervisors specifically want the larger H-ATLAS bright-end extension.

Good next concrete tasks:

1. freeze the current count-source set for the first thesis results chapter
2. write the evaluator method clearly
3. make final clean plots for the model-family score and flux-regime residuals
4. ask whether to add a larger H-ATLAS source before spending time on it
