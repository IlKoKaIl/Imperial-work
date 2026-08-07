# Archived August 3rd post-MBB notes

This file keeps the verbose notes that originally lived in `supervisor_meeting_prep.md` after the modified-blackbody section.

I moved them out because the main meeting-prep file was getting too bloated for the final thesis story.

---

### August 3rd: what to keep from here after supervisor feedback

I should not get lost in everything below.

Short version:

> Stop treating the post-MBB work like a list of things I must defend. The useful result is that changing FIR dust shape matters. The next useful work is Wang + cleaner evaluator/data handling, not adding every possible template family.

Main supervisor direction / current priority:

- Casey-style curves are useful, but they are still parametric templates
- if I want a stronger physics-based dust model, Draine & Li / CIGALE-style dust templates are probably better
- but adding a full new dust-library comparison may be too much right now
- the most useful thing for the next pass is probably:
  - understand why Wang raw counts still sit off from the corrected count papers
  - keep chi-square as a simple scorecard, but be clear it is not a perfect likelihood
  - add/clean only the count data that really helps, e.g. Valiante / H-ATLAS bright-end counts

For now I should treat the work below like this:

| thing | use now? | comment |
| ---- | ---- | ---- |
| MBB temperature grid | yes | simple physical dust-temperature lever |
| Casey-like grid | maybe / appendix | useful toy template, but not as physics-based as Draine & Li |
| big combined evaluator plots | maybe | useful internally, but do not over-defend exact best template |
| leave-one-source-out | yes conceptually | good answer to "are you just tuning to one paper?" |
| Wang raw-count context | yes | this is now a main loose end |
| runbooks / chapter drafts | later | too much for this week |

If I only have time for one direction now:

> investigate Wang, because that is the active supervisor question and it affects how I explain the mismatch in `outputs/popcosmos_differential_count_area_corrected_overlay.png`.

Current Wang question:

> Is Wang low because of the catalogue method, e.g. bright SPIRE sources being split/deblended into multiple fainter prior sources, or because bright/rare sources are missing/selected out?

Things to check for Wang, without opening a huge new branch:

- read Wang sections on prior construction, XID+ deblending, completeness, and flux recovery
- check if they compare output counts to input/truth counts in simulations
- check whether bright SPIRE detections can be split between multiple COSMOS priors
- search later papers that use the Wang catalogue and see if anyone uses it for number counts
- if nobody uses Wang for counts, that supports treating it as photometry/matched-object data, not a formal number-count benchmark

Possible quick search terms:

- `"Wang 2024" COSMOS super-deblended number counts`
- `"COSMOS2020 Farmer" XID+ SPIRE counts`
- `"master.dat" Wang COSMOS Herschel counts`
- papers citing Wang that use the catalogue for Herschel/SPIRE number counts

Chi-square stance:

- useful as a simple scorecard
- not a perfect final statistical likelihood
- count bins can be correlated
- P(D) spline points are definitely correlated
- some datasets may overlap or use related Herschel fields
- so the thesis should say "chi-square-style evaluator" unless I build a cleaner covariance-aware version

What to say if asked whether chi-square is still useful:

> Yes, as a ranking / diagnostic tool. But I should not oversell it as a fully independent likelihood unless I handle covariance, overlapping surveys, and P(D) correlations properly.

Data direction:

- do not blindly add lots more papers
- add data only if it fills a clear gap
- most useful gap is bright/wide SPIRE counts:
  - Valiante / H-ATLAS
  - more H-ATLAS bright-end count tables if available
- published corrected differential counts are better than recomputing counts from raw catalogues, unless I can also model completeness/reliability/flux boosting

Main story I should keep:

> The observed counts show that FIR SED shape matters. The baseline pop-cosmos/FSPS far-IR shape overpredicts long-wavelength bright counts. Simple warmer dust changes improve this at fixed `L_IR`, but the exact template choice should be treated cautiously.

Current action plan:

1. Keep the MBB result as the main simple dust-physics extension.
2. Treat Casey-like results as optional / parked.
3. Investigate why Wang raw counts remain off from corrected external counts.
4. Clean evaluator language: scorecard, not perfect likelihood.
5. Only add Valiante / extra H-ATLAS if it clearly helps the bright-end comparison.

Everything below is detailed work from the rabbit-hole branch. It is preserved for later, but I should not present it as the main path unless asked.

<details>
<summary>Archived / lower-priority August 3rd details after the MBB section</summary>

### August 3rd parked / rough: Casey-like dust-template grid

I added one more model family after the simple modified-blackbody grid.

New code:

- `pop_cosmos_notebook/popcosmos_casey_like_template_grid.py`

New outputs:

- `outputs/popcosmos_casey_like_template_grid_shapes.png`
- `outputs/popcosmos_casey_like_template_grid_score_heatmap.png`
- `outputs/popcosmos_casey_like_template_grid_counts.png`
- `outputs/popcosmos_casey_like_template_grid_pooled_summary.csv`
- `outputs/popcosmos_casey_like_template_grid_regime_summary.csv`

Why I tried this model family:

- Casey 2012 uses a modified blackbody for the cold dust peak plus a mid-IR power-law tail
- this is closer to a real dusty-galaxy SED than a pure single-temperature blackbody
- the mid-IR power law roughly stands in for warmer dust / compact star formation / possible AGN-ish heating
- I am not doing a full CIGALE fit yet, just testing a simple literature-motivated template shape

Updated caution:

- this is useful as a controlled toy extension
- but it is still parametric, not a full physical dust model
- if I need a stronger physics-based extension, Draine & Li / CIGALE dust libraries would be more defensible
- so I should not make Casey the main thesis claim unless supervisors are happy with it

Source:

- Casey 2012, FIR SED fitting with greybody + mid-IR power law: https://academic.oup.com/mnras/article/425/4/3094/1749031

Simple methodology:

- keep every pop-cosmos galaxy and its `L_IR` fixed
- throw away only the far-IR bump shape
- replace it with a Casey-like dust shape
- normalise the new shape so the 8-1000 um integral is still the same `L_IR`
- redshift it and predict observed `250/350/500 um` fluxes
- rebuild differential counts
- score against the same external count evaluator

Plots:

![Casey-like template shapes](outputs/popcosmos_casey_like_template_grid_shapes.png)

How to read the Casey shape plot:

- x-axis = rest-frame wavelength
- y-axis = template SED shape before/after normalisation
- `T` controls the dust peak position
- `alpha` controls the mid-IR power-law side
- this is more flexible than pure MBB because it has both a cold dust peak and a warmer/mid-IR tail

![Casey-like score heatmap](outputs/popcosmos_casey_like_template_grid_score_heatmap.png)

How to read the Casey score heatmap:

- rows/columns are Casey template parameters, usually `T` and `alpha`
- colour = evaluator score
- lower score = better template
- this plot is asking which Casey-like SED shape best matches the observed SPIRE counts after keeping each galaxy's `L_IR` fixed
- this is not the same as the earlier source-vs-model heatmap

![Casey-like count comparison](outputs/popcosmos_casey_like_template_grid_counts.png)

How to read the Casey count comparison:

- x-axis = observed flux density in `mJy`
- y-axis = `S^2.5 dN/dS` in `Jy^1.5 deg^-2`
- points = observed count papers
- curves = selected Casey-like model predictions
- this lets me see whether the best score also looks sensible as a count curve

Main result:

| model                | rough reduced chi2 | median log10(model/obs) |
| -------------------- | -----------------: | ----------------------: |
| Casey T30K alpha=2.5 |               3.36 |                   -0.03 |
| Casey T30K alpha=3.0 |               3.48 |                    0.07 |
| 25% ALESS            |               4.17 |                    0.12 |
| 50% ALESS            |               4.20 |                   -0.06 |
| MBB 35 K             |               4.26 |                   -0.11 |
| FSPS                 |               8.40 |                    0.31 |
| ALESS                |              13.33 |                   -0.41 |

comments:

- this is interesting, but probably not the thing to over-focus on right now
- the best model is no longer just "mix in ALESS"
- a literature-parametric dust shape with `T ~ 30 K` and a mid-IR tail does better than FSPS, pure ALESS, and pure MBB
- the median model/obs offset is basically zero for the best Casey-like model
- this is less ad-hoc than "I blended two SEDs until it looked nicer", but still not as physically grounded as Draine & Li/CIGALE
- after adding Varnish with approximate errors, the preferred alpha shifted from `3.0` to `2.5`
- that is fine: the stable result is the `T ~ 30 K` Casey-like family, not one exact alpha value

Best by count type:

| regime                  | best model           | rough reduced chi2 |
| ----------------------- | -------------------- | -----------------: |
| all scored counts       | Casey T30K alpha=2.5 |               3.36 |
| resolved/prior counts   | Casey T30K alpha=3.0 |               3.29 |
| P(D) statistical counts | Casey T30K alpha=2.5 |               2.17 |

This is also a nice overfitting check:

- resolved/prior counts and P(D) counts do not pick exactly the same alpha
- but they both prefer the same broad family: around `30 K` with a mid-IR tail
- so the result is not just one paper pulling the model into a random shape
- P(D) pulls a little more toward `alpha=2.5`, while resolved/prior counts still like `alpha=3.0`

### August 3rd parked / rough: combined model-family score summary

I reran the combined model-family summary after adding the Casey-like grid.

Important transition:

- before this point, the evaluator mostly compared only `FSPS`, `ALESS`, and ALESS-hybrid columns
- from this point onward, the evaluator also includes MBB and Casey-like dust-template families
- so if an older heatmap only has `FSPS`, `25% ALESS`, `50% ALESS`, `75% ALESS`, `ALESS`, that is expected
- it is an early first-pass plot, not the final full model-family plot

Code:

- `pop_cosmos_notebook/popcosmos_model_family_score_summary.py`

Outputs:

- `outputs/popcosmos_model_family_score_comparison.png`
- `outputs/popcosmos_model_family_score_summary.csv`
- `outputs/popcosmos_model_family_regime_summary.csv`
- `outputs/popcosmos_model_family_best_by_regime.csv`

Plot:

![Current FIR model-family evaluator summary](outputs/popcosmos_model_family_score_comparison.png)

How to read this plot:

- each point/bar is one model variant scored against the published differential-count evaluator
- lower rough reduced chi-square = better
- this is the broad model-ranking plot
- it does not show individual flux bins directly
- it answers "which model family performs best overall?"

What this combines now:

- baseline FSPS
- FSPS/ALESS hybrids
- pure ALESS
- pure modified-blackbody temperature grid
- Casey-like modified blackbody + mid-IR power-law grid

Current rough story:

> The exact best template should not be overclaimed, but the direction is stable: pop-cosmos does not need a totally different galaxy population first. It needs a more flexible/warm FIR dust SED shape at fixed `L_IR`.

How I would say it simply:

- FSPS/pop-cosmos is the baseline
- ALESS was a useful empirical bracket
- MBB showed the dust-temperature lever directly
- Casey-like templates are an exploratory next step because they are more structured than an ALESS/FSPS blend
- the evaluator prefers a warmer/broader FIR shape, not pure ALESS and not unchanged FSPS

Possible appendix / extra framing if I keep this:

> I built an observed-space evaluator for FIR/sub-mm model extensions. Across several published differential-count datasets, warmer dust-template changes improve the match more consistently than the baseline pop-cosmos far-IR SED. Casey-like curves are a useful parametric test, but I should treat them as exploratory unless I replace them with a more physical Draine & Li / CIGALE-style dust library.

Next thing to ask:

- is this Casey-like grid a good enough "model extension" for the thesis?
- or should I now compare proper CIGALE/Dale/Draine-Li templates using the same evaluator?

### August 3rd: question to ask about setting up the evaluator

One thing I should ask Boris/Dave clearly:

> How should I set up the final evaluator so it is not just "tuning the model until it matches one dataset"?

My concern:

- chi-square on differential counts is a good start
- but if I only optimise against one set of SPIRE counts, I could accidentally overfit to that survey
- I want the result to be physically meaningful, not just a curve-fitting exercise
- Dave said this is less of a problem if the data is large / broad enough, but I should still set it up carefully

Possible evaluator structure:

- use corrected published **differential counts** as the main score
- score several datasets separately, not only one combined curve
- check if the same type of model change helps across `250/350/500 um`
- hold out one count paper at a time and see if the preferred model still works
- keep Wang as a matched-object sanity check, not the main count truth
- add physical guardrails, e.g. dust temperatures / SED shapes should stay in a sensible galaxy range

Question version I can ask:

> Is chi-square over differential counts enough for the final model comparison, or should I combine it with hold-out tests and physical priors so the evaluator rewards models that are both statistically better and astrophysically sensible?

Also ask:

> Which observed data should carry the most weight: resolved Herschel counts, P(D) counts, Wang matched COSMOS fluxes, or some split between them?

### August 3rd useful but optional: full model-family leave-one-source-out check

I made the overfitting check a bit more serious.

Before, the leave-one-source-out test only used the early FSPS/ALESS hybrid models.

Now it uses the full current model family:

- baseline FSPS
- ALESS hybrids
- pure ALESS
- MBB temperature grid
- Casey-like template grid

New code:

- `pop_cosmos_notebook/popcosmos_model_family_leave_one_out.py`

New outputs:

- `outputs/popcosmos_model_family_per_source_scores.csv`
- `outputs/popcosmos_model_family_leave_one_source_out.csv`
- `outputs/popcosmos_model_family_leave_one_source_out.png`

Plot:

![Full model-family leave-one-source-out check](outputs/popcosmos_model_family_leave_one_source_out.png)

How to read this full leave-one-source-out plot:

- this is the same idea as the early hold-out test, but now using FSPS, ALESS hybrids, pure ALESS, MBB, and Casey-like templates
- for each observed count source, the model is chosen using all the other sources
- then the chosen model is tested on the hidden source
- if the chosen model still beats FSPS on the hidden source, that supports the result not being just one-paper tuning

What the test does:

- hold out one observed count source
- choose the best fixed template using all the other count sources
- test that chosen model on the held-out source
- compare it to:
  - the best possible model on that held-out source
  - baseline FSPS

Simple read:

> If the model only works because I tuned to one paper, it should fall apart when that paper is held out.

Result after including Varnish with approximate symmetric errors:

| held-out source | model picked from other sources | held-out chi2 | best possible held-out chi2 | FSPS chi2 |
| --------------- | ------------------------------- | ------------: | --------------------------: | --------: |
| Clements        | Casey T30K alpha=2.5            |          2.77 |                        2.24 |     12.35 |
| Glenn P(D)      | Casey T30K alpha=2.5            |          2.15 |                        2.15 |     12.15 |
| Oliver          | Casey T30K alpha=2.5            |          0.41 |                        0.41 |      3.46 |
| Pearson SUSSEX  | Casey T30K alpha=2.5            |          6.45 |                        5.49 |      8.20 |
| Pearson XID     | Casey T30K alpha=2.5            |          1.94 |                        1.07 |      2.06 |
| Varnish P(D)    | Casey T30K alpha=3.0            |          5.06 |                        2.14 |     14.19 |

comments:

- selected model beats FSPS on every held-out source
- the chosen model is not always the best possible model for that held-out source
- that is actually useful: it shows the external papers are not identical and there is real source-to-source tension
- Casey T30K alpha=2.5 is picked most often after adding Varnish
- when Varnish itself is held out, the other sources pick `alpha=3.0`, but Varnish alone prefers `MBB 35 K`
- Pearson SUSSEX is still the hardest held-out source to fit

Main interpretation:

> The warm/broader dust-template correction is not just one-paper curve fitting. It generalises better than FSPS across held-out count sources, but the exact best template still depends on which count product is used.

Important Varnish note:

- Varnish is now included in the chi-square score as a sensitivity test
- I converted the published lower/upper log bounds into one conservative symmetric log error
- I also kept a small `0.08 dex` floor, because some Varnish spline knots have lower=best=upper
- this lets the evaluator use Varnish, but I should still treat it carefully because P(D) points are correlated
- code change is in `pop_cosmos_notebook/compile_external_spire_differential_counts.py`
- updated compiled table is `catalog data/external_number_counts/external_spire_differential_counts_compiled.csv`

This is a good question to ask:

> Is this conservative Varnish-error conversion acceptable for a sensitivity test, or should I keep Varnish out of the formal chi-square because the P(D) spline points are correlated?

### August 3rd: chi-square wording sanity

Need to be careful with this wording.

`reduced chi2 >> 1` does **not** automatically mean overfitting.

It usually means:

- model does not match the data within the quoted errors
- or the errors are too small
- or the model is missing physics/systematics

Overfitting is more like:

- model looks great on the data used to choose it
- but performs badly on held-out data

So for the thesis I should say:

- chi-square is the main goodness-of-fit score
- leave-one-source-out is the overfitting guard
- physical priors/guardrails stop the evaluator choosing nonsense templates

Simple wording:

> A high reduced chi-square tells me the model/count comparison is not fully explained by the adopted errors. To check overfitting, I use held-out count sources and ask whether the preferred dust-template change still improves over FSPS when evaluated on data it was not selected from.

### August 3rd useful but optional: source-to-source tension summary

I made one more summary plot to make the evaluator story easier to explain.

New code:

- `pop_cosmos_notebook/popcosmos_model_family_source_tension.py`

New outputs:

- `outputs/popcosmos_model_family_source_tension_summary.csv`
- `outputs/popcosmos_model_family_key_model_matrix.csv`
- `outputs/popcosmos_model_family_source_tension.png`

Plot:

![Model-family source tension](outputs/popcosmos_model_family_source_tension.png)

How to read this plot:

- left panel = source-vs-model score heatmap using the full model family
- rows = observed count source
- columns = selected key models
- printed number = raw rough reduced chi-square
- colour = `log10` of that raw score
- lower/yellower = better
- right panel = how much worse FSPS is compared with the best model for each source

This plot is not asking "what flux is being compared?"

Instead it asks:

> after using all usable flux bins in this paper/table, which model scores best?

What this plot asks:

> Do all observed count papers prefer the exact same dust template?

Answer:

> No. But they mostly prefer the same broad direction.

Best model by source:

| source         | count type     | best model           | best chi2 | FSPS chi2 | FSPS / best |
| -------------- | -------------- | -------------------- | --------: | --------: | ----------: |
| Clements       | resolved/prior | Casey T30K alpha=3.0 |      2.24 |     12.35 |        5.52 |
| Oliver         | resolved/prior | Casey T30K alpha=2.5 |      0.41 |      3.46 |        8.38 |
| Pearson SUSSEX | resolved/prior | 25% ALESS            |      5.49 |      8.20 |        1.49 |
| Pearson XID    | resolved/prior | 25% ALESS            |      1.07 |      2.06 |        1.93 |
| Glenn P(D)     | P(D)           | Casey T30K alpha=2.5 |      2.15 |     12.15 |        5.64 |
| Varnish P(D)   | P(D)           | MBB 35 K             |      2.14 |     14.19 |        6.63 |

comments:

- every source prefers something better than baseline FSPS
- exact best model changes by source
- Pearson prefers the empirical ALESS-ish correction
- Clements / Oliver / Glenn prefer Casey-like `30 K`
- Varnish P(D) slightly prefers the simple `MBB 35 K`
- this is not a contradiction, it is telling me the count products are not identical

Simple thesis interpretation:

> The stable result is not one magic template. The stable result is that baseline FSPS is not the preferred long-wavelength dust shape. Published SPIRE counts consistently favour a warmer/broader FIR correction, while the exact preferred template depends on the count extraction method and flux range.

Why this helps:

- it stops me overclaiming "Casey T30 alpha=2.5 is the truth"
- it supports saying "dust SED flexibility is the lever"
- it gives a clean response if someone asks why different papers do not agree perfectly

Question to ask:

> For the thesis, should I present the source-to-source tension as a limitation of the evaluator, or as part of the result showing that the exact SED parameters are not uniquely identifiable from counts alone?

### August 3rd: flux-regime diagnostic

I made a diagnostic for the note:

> FSPS does okay until the bright end.

New code:

- `pop_cosmos_notebook/popcosmos_model_family_flux_regime_diagnostics.py`

New outputs:

- `outputs/popcosmos_model_family_flux_regime_residuals.csv`
- `outputs/popcosmos_model_family_flux_regime_summary.csv`
- `outputs/popcosmos_model_family_flux_regime_residual_heatmap.png`
- `outputs/popcosmos_model_family_flux_regime_chi2.png`

Flux bins I used:

- `10-30 mJy`
- `30-100 mJy`
- `100-300 mJy`

Plots:

![Flux-regime residual heatmap](outputs/popcosmos_model_family_flux_regime_residual_heatmap.png)

![Flux-regime chi2 comparison](outputs/popcosmos_model_family_flux_regime_chi2.png)

Important:

- this is the plot where flux ranges are explicitly on the axis
- this is the one to use for the statement "FSPS gets worse at bright flux and longer wavelength"
- do not use the source-vs-model heatmap for that statement

How to read the heatmap:

- red / positive = model predicts too many counts / too much flux
- blue / negative = model is too low
- values are median `log10(model / observed)`
- so `+0.30 dex` means model is high by about factor 2
- `+1.0 dex` means model is high by about factor 10

FSPS result:

| band | flux regime | FSPS median log10(model/obs) | rough chi2 |
| ---- | ----------- | ---------------------------: | ---------: |
| 250  | 10-30 mJy   |                        +0.11 |       3.93 |
| 250  | 30-100 mJy  |                        +0.20 |       3.20 |
| 250  | 100-300 mJy |                        +0.69 |      15.22 |
| 350  | 10-30 mJy   |                        +0.23 |       9.79 |
| 350  | 30-100 mJy  |                        +0.23 |       5.84 |
| 350  | 100-300 mJy |                        +0.82 |      17.93 |
| 500  | 10-30 mJy   |                        +0.36 |      11.90 |
| 500  | 30-100 mJy  |                        +0.55 |      10.54 |
| 500  | 100-300 mJy |                        +1.08 |      23.13 |

comments:

- FSPS is high almost everywhere in the SPIRE count comparison
- but the bright end is definitely the worst part
- the effect gets worse with wavelength:
  - `250 um` bright end is high by about `0.69 dex`, roughly factor 5
  - `350 um` bright end is high by about `0.82 dex`, roughly factor 7
  - `500 um` bright end is high by about `1.08 dex`, roughly factor 12
- so the simple sentence should be:

> FSPS is not terrible at 250 um low/mid fluxes, but it increasingly overpredicts counts at longer wavelengths and especially at the bright end.

What the corrected templates do:

- Casey / MBB / ALESS-like corrections reduce the bright-end overprediction
- none of them is perfect in every band/regime
- Casey `T30K alpha=2.5` is the most balanced current option:
  - much better than FSPS at the bright end
  - not as extreme as pure ALESS
  - still has some 350/500 bright-end excess

Simple thesis interpretation:

> The baseline FSPS far-IR SED is too cold / too long-wavelength bright. This is clearest for rare bright SPIRE sources, especially at 350 and 500 um. Warmer/broader dust templates reduce that bright-end excess while keeping the original pop-cosmos `L_IR` fixed.

Question to ask:

> Should I make the bright-end residual the main headline result, or present it as one diagnostic inside the broader differential-count evaluator?

### August 3rd archive / later: generated evaluator snapshot

From here onward is mostly housekeeping / generated docs / detailed implementation notes.
Useful later, but probably too much for the next meeting.

I made one generated snapshot file so the current evaluator result is not scattered across loads of plots and CSVs.

New code:

- `pop_cosmos_notebook/popcosmos_thesis_evaluator_snapshot.py`

New output:

- `outputs/popcosmos_thesis_evaluator_snapshot.md`

What it contains:

- current best model ranking
- best model by count regime
- source-to-source tension table
- leave-one-source-out check
- FSPS flux-regime residuals
- Wang role / area note
- caveats and supervisor questions

Main headline from the snapshot:

> The exact best dust template is not unique, but the direction is stable. Published SPIRE differential counts prefer a warmer/broader FIR dust SED than the baseline FSPS/pop-cosmos far-IR treatment, while keeping each galaxy's original `L_IR` fixed.

This is probably the cleanest one-file recap to use before meetings / thesis planning.

### August 3rd: evaluator runbook / rerun script

I also made a small runbook so the FIR evaluator is not just a pile of scripts that only makes sense to me right now.

New files:

- `pop_cosmos_notebook/FIR_EVALUATOR_RUNBOOK.md`
- `pop_cosmos_notebook/run_fir_evaluator_pipeline.py`
- `outputs/fir_evaluator_pipeline_summary.log`

Simple idea:

- `--mode summary` reruns the normal downstream evaluator / plots / snapshot
- `--mode full` also reruns the heavier SED model grids
- the clean meeting recap is still `outputs/popcosmos_thesis_evaluator_snapshot.md`

I checked the summary runner and it finished cleanly.

### August 3rd: asking for advice on the evaluator

I should ask for advice on how to set up the evaluator properly.

Main concern:

> I do not want this to become "keep changing the dust SED until it matches one dataset".

What I want instead:

- use the evaluator as a scorecard for physically sensible model variants
- keep pop-cosmos `L_IR` fixed where possible
- only compare dust SED choices that have some literature / physical motivation
- use published differential counts because they already include completeness / reliability corrections
- use held-out count sources to check that the improvement is not just curve fitting

Current evaluator idea:

- compare model vs observed differential SPIRE counts in 250/350/500 um
- use chi-square or reduced chi-square across flux bins
- also look at leave-one-source-out checks
- keep Wang mostly as a matched-object sanity check, not the main population-count truth

Questions to ask Boris/Dave:

- Should the main score be chi-square in linear count space, or log-count space?
- Should P(D) results like Glenn/Varnish be included in the formal chi-square, or shown separately because their bins are correlated?
- Which external count papers should be treated as the main comparison set vs extra cross-checks?
- What flux range should I score, especially at the faint end where confusion / completeness becomes messy?
- How should I count the number of free parameters for reduced chi-square if I compare template families like ALESS, MBB, and Casey-like dust models?
- Is leave-one-source-out enough as an overfitting guard, or should I hold out a whole paper / wavelength / flux regime?
- Are the physical guardrails reasonable: fixed `L_IR`, limited dust temperatures, limited beta/alpha ranges, no arbitrary per-band scaling?

Simple phrasing for the email:

> I am trying to set the evaluator up so it rewards physically plausible improvements, not just curve-fitting to one count dataset. Right now I am using differential counts and chi-square-style residuals, with held-out count sources as an overfitting check. Does this sound like the right structure, and which count datasets / flux ranges should be part of the main score?

### August 3rd: Wang / counts / evaluator sanity pass

I did a quick sanity pass on the Wang paper + the count sources again.

Sources checked:

- Wang COSMOS XID+ paper: https://www.aanda.org/articles/aa/full_html/2024/08/aa49055-23/aa49055-23.html
- Glenn HerMES P(D): https://arxiv.org/abs/1009.5675
- Bethermin 2012: https://www.aanda.org/articles/aa/full_html/2012/06/aa18698-11/aa18698-11.html
- Bethermin 2017 / SIDES: https://www.aanda.org/articles/aa/full_html/2017/11/aa30866-17/aa30866-17.html

#### Wang check

Main conclusion:

> Wang is a deblended point-source catalogue, not a corrected population number-count paper.

So the Wang catalogue is still useful, but probably not as the main number-count truth.

Useful things from Wang:

- matched-object flux sanity checks
- does pop-cosmos predict the right objects to be bright/faint?
- do the residuals change with band, redshift, SFR, `L_IR`, AGN-ish params?

Less ideal use:

- treating raw Wang catalogue counts as if they were published corrected number counts

Why:

- Wang Table 4 is the released CDS catalogue
- flux columns like `F250`, `F350`, `F500`, `F850` are in `mJy`
- uncertainty columns like `s_F250` are also in `mJy`
- the area tied to the COSMOS2020/Farmer `FLAG_COMBINED=0` selection is `1.278 deg^2`, not the rough full COSMOS `~2 deg^2`
- Wang uses priors and XID+ deblending, so the catalogue has selection effects from the prior construction
- their SPIRE prior step uses a predicted `S250 > 7 mJy` branch, plus X-ray/radio additions
- they also mention uncertainty scaling for MIPS/SPIRE because the raw XID+ errors are underestimated

Local `master.dat` sanity check:

| thing                                   |      value |
| --------------------------------------- | ---------: |
| rows in Wang master table               |     131178 |
| positive COSMOS2020 IDs                 |     128387 |
| negative radio-only IDs                 |       2791 |
| effective COSMOS2020/Farmer area to use | 1.278 deg2 |

Detection-ish counts in the local table:

| band | positive flux+err rows | SNR>=3 rows | median SNR |
| ---- | ---------------------: | ----------: | ---------: |
| 250  |                  14868 |        7946 |       3.35 |
| 350  |                  14865 |        5255 |       1.84 |
| 500  |                  14855 |        2305 |       0.98 |
| 850  |                  14869 |         915 |       0.96 |

This is probably why Wang looks different from the external counts:

- by 500/850 um, loads of Wang priors have low SNR
- raw prior-catalogue counts are not the same thing as corrected source counts
- small COSMOS area means rare bright sources are noisy / cosmic-variance sensitive
- Wang is best used as a matched-object diagnostic, while Clements/Oliver/Pearson/Glenn/Varnish are better for population counts

For positive COSMOS2020 IDs only, using `1.278 deg2`:

| band | flux cut | raw N above cut | SNR>=3 N above cut | SNR>=3 per deg2 |
| ---- | -------: | --------------: | -----------------: | --------------: |
| 250  |   10 mJy |            3849 |               3668 |            2870 |
| 250  |   20 mJy |            1085 |               1076 |             842 |
| 250  |   50 mJy |              47 |                 47 |            36.8 |
| 350  |   10 mJy |            2609 |               2367 |            1852 |
| 350  |   20 mJy |             609 |                596 |             466 |
| 350  |   50 mJy |              12 |                 12 |            9.39 |
| 500  |   10 mJy |            1019 |                860 |             673 |
| 500  |   20 mJy |             147 |                144 |             113 |
| 500  |   50 mJy |               1 |                  1 |            0.78 |

comments:

- a `10 mJy` cut is still not a magic clean line, but it is more sane than going very faint
- at `50 mJy`, COSMOS has very few objects, especially at 350/500
- so Wang cannot strongly constrain rare bright counts by itself
- this makes the corrected wide/deep count papers more important

#### Count sources currently in evaluator

The compiled differential-count table now has:

| source                             | role                                  | status   |
| ---------------------------------- | ------------------------------------- | -------- |
| Clements 2010 H-ATLAS              | bright/wide-ish resolved counts       | included |
| Oliver 2010 HerMES                 | mid-range HerMES counts               | included |
| Pearson 2025 Table 3 SUSSEXtractor | SPIRE Dark Field resolved extraction  | included |
| Pearson 2025 Table 4 XID           | SPIRE Dark Field prior/XID extraction | included |
| Glenn 2010 HerMES P(D)             | deep statistical P(D) counts          | included |
| Varnish 2025 Dark Field II P(D)    | very deep statistical P(D) counts     | included |

The compiler standardises everything to:

> `S^2.5 dN/dS` in `Jy^1.5 deg^-2`

Bookkeeping file updated:

- `catalog data/external_number_counts/external_count_source_inventory.csv`

#### Bethermin papers

How I think about these now:

- Bethermin 2012 may be useful as another published observed count source if there are clean tables worth adding
- Bethermin 2017 / SIDES is more of a model/simulation reference than another observed dataset
- Wang uses SIDES-like simulations to validate deblending, and SIDES was designed to reproduce things like counts / P(D) / CIB statistics

So:

> Bethermin is useful context for model/evaluator design, but I should not mix a simulated model prediction into the same "observed data" column unless I clearly label it as a model comparison.

Possible next move:

- add Bethermin 2012 observed counts if the paper has a clean table matching SPIRE 250/350/500
- keep Bethermin 2017/SIDES as literature support for why counts/P(D)/CIB are standard evaluator quantities

#### Evaluator setup after this check

Best current structure:

1. Main formal score:

   - use published differential counts
   - probably score in log-count space because the counts span huge dynamic range
   - compare 250/350/500 together
2. Keep score groups separate:

   - resolved/prior extracted counts
   - P(D) statistical counts
   - Wang matched-object checks
3. Avoid overfitting:

   - do not tune to only one paper
   - use leave-one-source-out
   - compare by wavelength and flux regime
   - keep physical guardrails on templates
4. Be careful with reduced chi-square:

   - `chi2 >> 1` means bad fit / underestimated errors / missing systematics
   - it does not automatically mean overfitting
   - overfitting is tested by held-out performance
5. P(D) caveat:

   - Glenn/Varnish are very useful faint-end constraints
   - but their spline points are not just simple independent catalogue bins
   - so I can show "with and without P(D)" or treat them as sensitivity tests

Simple thesis story from this:

> I am moving from "does pop-cosmos match one catalogue?" to "which physically motivated dust-SED changes improve pop-cosmos against several corrected observed-space benchmarks?" Wang helps diagnose objects. Published differential counts test the population.

#### Concrete next actions

Immediate:

- keep Wang out of the main formal count score for now
- use Wang for matched-object residual plots / AGN / high-SFR checks
- keep the main count evaluator on Clements/Oliver/Pearson, with Glenn/Varnish as P(D) sensitivity tests
- rerun the final snapshot both with and without P(D) so I can show whether the headline result changes

Medium:

- check if Bethermin 2012 has clean observed count tables worth adding
- decide final scoring flux range, probably avoiding ultra-faint confused bins and tiny-number very bright bins unless clearly labelled
- write the evaluator section of thesis like a method:
  - inputs
  - unit conversion
  - scoring
  - model families
  - overfitting guard
  - caveats

Question to ask:

> Should the final formal score use only resolved/prior extracted differential counts, and then show P(D) counts separately as a faint-end sensitivity check?

#### Quick P(D) sensitivity result

I made a small "with P(D) vs without P(D)" check.

New code:

- `pop_cosmos_notebook/popcosmos_model_family_pd_sensitivity.py`

New outputs:

- `outputs/popcosmos_model_family_pd_sensitivity.csv`
- `outputs/popcosmos_model_family_pd_sensitivity.png`

Plot:

![P(D) sensitivity](outputs/popcosmos_model_family_pd_sensitivity.png)

Best models:

| score group                  | best model           | rough reduced chi2 | median log(model/obs) |
| ---------------------------- | -------------------- | -----------------: | --------------------: |
| all scored counts            | Casey T30K alpha=2.5 |               3.36 |                 -0.03 |
| resolved/prior counts only   | Casey T30K alpha=3.0 |               3.29 |                 -0.00 |
| P(D) statistical counts only | Casey T30K alpha=2.5 |               2.17 |                 +0.03 |

comments:

- P(D) does move the exact preferred `alpha` a bit
- but it does not change the broad story
- both with and without P(D), the evaluator prefers a Casey-like warm/broader FIR SED around `30 K`
- this is good for thesis wording because I can say the result is stable in broad physical direction, but I should not overclaim one exact template parameter

### August 3rd: Bethermin 2012 source check

I checked the Bethermin 2012 HerMES paper more carefully.

Paper:

- https://www.aanda.org/articles/aa/full_html/2012/06/aa18698-11/aa18698-11.html

I also downloaded the arXiv source into:

- `catalog data/external_number_counts/bethermin_2012_source/`

What the paper is:

- HerMES deep number counts at `250/350/500 um`
- uses COSMOS + GOODS-N
- resolved/prior extraction above about `20 mJy`
- stacking below the confusion limit
- reaches down to about `2 mJy`
- gives redshift-sliced counts, which is more information than just total counts

Why it is interesting:

- it is exactly the kind of work Dave/Boris are pointing me toward:
  - observed-space counts
  - below confusion limit
  - model comparison
  - CIB / redshift information
- they say the counts alone are not enough to constrain evolution models, because models can match counts but get redshift distributions wrong
- that is useful thesis framing for me:

> number counts are the first evaluator, but redshift/object diagnostics are the next layer.

Why I am not adding it to the formal evaluator yet:

- I found the arXiv source
- it has the paper text, figures, and correction/uncertainty tables
- but I did **not** find a simple total-count numeric table like Clements / Oliver / Pearson
- the actual total count curves seem to be in the plots / figure data, not as a clean published table in the source
- adding it now would probably mean digitising the plot or hunting for an old HeDaM release

So current decision:

> Do not add Bethermin 2012 as a formal chi-square dataset yet. Use it as literature/method support unless I find a clean machine-readable count table.

Useful notes from the paper:

- their SPIRE maps are confusion limited
- they cut resolved analysis at `20 mJy`, about `4 sigma`
- they discuss Eddington bias explicitly
- they compare well to Oliver / Clements / Glenn
- they confirm deep counts down to `2 mJy`
- they emphasise that redshift distributions are needed because counts alone can be misleading

Bookkeeping added:

- `catalog data/external_number_counts/external_count_source_decision_matrix.csv`

This file separates count sources into:

- formal evaluator
- P(D) sensitivity
- context / future add
- model reference

Current clean source decision:

| source                      | current role                            |
| --------------------------- | --------------------------------------- |
| Clements / Oliver / Pearson | formal resolved/prior count score       |
| Glenn / Varnish P(D)        | faint-end sensitivity score             |
| Wang                        | matched-object sanity checks            |
| Bethermin 2012              | method/context unless clean table found |
| Bethermin 2017 SIDES        | model/simulation context                |
| Valiante H-ATLAS DR1        | possible future bright-tail extension   |

Good thesis line:

> The evaluator is built mainly on published corrected differential counts, while stacking/P(D) papers like Bethermin, Glenn, and Varnish motivate why faint-end and redshift-aware checks matter.

### August 3rd: chi-square / degrees-of-freedom check

I made a small check for the statistics wording.

New code:

- `pop_cosmos_notebook/popcosmos_evaluator_chi2_dof_check.py`

New outputs:

- `outputs/popcosmos_evaluator_chi2_dof_check.csv`
- `outputs/popcosmos_evaluator_chi2_dof_check.md`
- `outputs/popcosmos_evaluator_chi2_dof_check.png`

Plot:

![Chi-square dof check](outputs/popcosmos_evaluator_chi2_dof_check.png)

What the evaluator currently does:

```text
chi2 = sum((log10(model) - log10(observed))^2 / sigma_log^2)
rough reduced chi2 = chi2 / N_points
```

That is fine as a scorecard.

But if I want to be more formal, reduced chi-square should be closer to:

```text
reduced chi2 = chi2 / (N_points - k)
```

where `k` is the number of fitted/free template parameters.

Simple `k` check I used:

| model family                   | simple k |
| ------------------------------ | -------: |
| FSPS baseline                  |        0 |
| pure ALESS fixed template      |        0 |
| FSPS/ALESS hybrid fraction     |        1 |
| modified blackbody temperature |        1 |
| Casey-like template            |        2 |

Result:

| score group             | best model after simple dof correction | chi2/(N-k) |
| ----------------------- | -------------------------------------- | ---------: |
| all scored counts       | Casey T30K alpha=2.5                   |       3.40 |
| resolved/prior counts   | Casey T30K alpha=3.0                   |       3.35 |
| P(D) statistical counts | Casey T30K alpha=2.5                   |       2.35 |

comments:

- subtracting these simple template parameters barely changes the ranking
- that is because the number of count points is much larger than `k`
- the result is still the same broad Casey-like `~30 K` dust SED family
- this is reassuring, but I should still call it a **rough chi-square score** unless Boris/Dave want a stricter likelihood treatment

Important wording:

> A high chi-square does not mean overfitting. It means the model is not matching the data within the adopted errors, or the errors/model assumptions are incomplete. Overfitting is tested by held-out count sources and by keeping physical guardrails on the template family.

Question to ask:

> For the thesis, is it okay to call this a rough reduced chi-square score, or should I explicitly subtract a small number of template parameters for each model family?

### August 3rd: wrapping this work into thesis docs

I started turning the current FIR/evaluator work into report-friendly notes, so it is not all scattered across plots and scripts.

New thesis-facing docs:

- `pop_cosmos_notebook/FIR_THESIS_METHODS_RESULTS_DRAFT.md`
- `pop_cosmos_notebook/FIR_THESIS_FIGURE_INDEX.md`

What the methods/results draft does:

- explains the current thesis claim
- separates the roles of Wang / published counts / P(D) / Bethermin / SIDES
- explains the model variants in simple report-style language
- describes the count evaluator and chi-square score
- summarises the main results:
  - FSPS is too high in SPIRE counts
  - bright end is worst
  - mismatch worsens toward 350/500 um
  - Casey-like `~30 K` dust templates are currently best
- lists limitations and next thesis work

What the figure index does:

- lists the main plots worth using in the report/viva
- gives draft captions
- says what each plot is useful for
- separates core figures from older/supporting plots

Current clean story to carry forward:

> pop-cosmos/FSPS overpredicts bright long-wavelength SPIRE counts. The most useful fix so far is not changing total `L_IR`, but changing the far-IR dust SED shape. Published differential counts prefer a warmer/broader Casey-like dust template around `30 K`, while Wang is better kept as a matched-object sanity check.

This pass is probably "good enough" to pause on for now.

### August 3rd: Wang discrepancy note cleaned up

I made one more small bookkeeping output for the Wang catalogue:

- `outputs/wang_master_catalog_discrepancy_note.md`

This is basically a quick answer to:

> why does Wang not always sit with the other number-count papers?

Main points:

- Wang `master.dat` is a deblended point-source catalogue, not a corrected published number-count table
- the fluxes are in `mJy`
- `F250/F350/F500/F850` are the median deblended fluxes
- `s_F250/s_F350/s_F500/s_F850` are the flux errors
- the area I should use for the COSMOS2020/Farmer selection is `1.278 deg2`, not the rough `2 deg2` full COSMOS area
- negative IDs are radio-prior sources, so I should not blindly mix them with positive COSMOS2020 IDs unless I say exactly what sample I am using

Quick raw-count sanity check, using positive COSMOS2020 IDs and `1.278 deg2`:

| band   | flux cut |    N | N / deg2 |
| ------ | -------: | ---: | -------: |
| 250 um |  >10 mJy | 3849 |   3011.7 |
| 250 um |  >50 mJy |   47 |     36.8 |
| 350 um |  >10 mJy | 2609 |   2041.5 |
| 350 um |  >50 mJy |   12 |      9.4 |
| 500 um |  >10 mJy | 1019 |    797.3 |
| 500 um |  >50 mJy |    1 |      0.8 |
| 850 um |  >10 mJy |    9 |      7.0 |

comments:

- this makes the 850 um Wang comparison feel very weak as a raw number-count check
- 500 um also gets tiny at the bright end
- 250 um is the most useful Wang band for raw sanity checks
- the Wang disagreement is not automatically a pop-cosmos failure because Wang is a prior-selected/deblended catalogue with its own selection effects
- I think the clean thesis setup is still:
  - published corrected differential counts = formal population evaluator
  - Wang = matched-object diagnostics / residual checks / weird-source checks

Simple wording:

> Wang tells me whether the right matched COSMOS objects are bright. The published count papers tell me whether the simulated population as a whole has the right observed long-wavelength counts.

### August 3rd: count-source roadmap / should I keep adding papers?

I made a small helper plot to see what flux range each external SPIRE count source actually covers.

New files:

- `pop_cosmos_notebook/FIR_COUNT_SOURCE_ROADMAP.md`
- `outputs/external_count_source_flux_coverage.csv`
- `outputs/external_count_source_flux_coverage.png`

![External count source flux coverage](outputs/external_count_source_flux_coverage.png)

Simple read:

- Pearson covers the deep detected/prior-extracted bit, roughly `10-100 mJy`
- Oliver covers a middle HerMES resolved-count range, roughly `20-400 mJy`
- Clements is the main bright/wide anchor, roughly `30-800 mJy`
- Glenn and Varnish go much fainter, but those are P(D) statistical constraints, not ordinary independent detected-source bins

comments:

- I think the current count set is probably enough for the main thesis story
- adding more papers could easily make things messier unless the new paper fills a clear gap
- the only obvious next source worth adding would be a larger H-ATLAS / Valiante-style bright-end count source
- that would be useful only if Dave/Boris want a stronger rare bright-source test

Current practical decision:

> Freeze the count sources for now: Clements/Oliver/Pearson as the main resolved/prior evaluator, Glenn/Varnish as P(D) sensitivity, Wang as matched-object diagnostics.

Question to ask:

> Is the current Clements H-ATLAS SDP bright-end anchor enough, or should I add a larger H-ATLAS / Valiante count table specifically to strengthen the rare bright-end comparison?

### August 3rd: thesis execution plan

Made a more practical thesis plan:

- `pop_cosmos_notebook/FIR_THESIS_EXECUTION_PLAN.md`

This is basically me trying to stop the project from becoming infinite.

Main idea:

> I think the FIR/SPIRE evaluator is already enough to become the first proper thesis result. The next work should mostly be freezing the result, writing it clearly, and only adding extra data if it fills a very specific gap.

Minimum thesis story:

1. pop-cosmos was calibrated mostly in optical/NIR
2. FIR/SPIRE counts are a clean out-of-sample test
3. baseline FSPS/pop-cosmos overpredicts bright long-wavelength counts
4. the mismatch gets worse at 350/500 um and at high flux
5. changing the FIR dust SED shape at fixed `L_IR` improves the comparison
6. Casey-like `~30 K` templates are currently the cleanest demonstration
7. Wang is kept as matched-object diagnostics, not the main number-count truth

What is already done enough:

- count data compiled
- Wang units/area checked
- FSPS baseline tested
- ALESS/hybrid tested
- MBB grid tested
- Casey-like grid tested
- chi-square/evaluator built
- P(D) sensitivity checked
- leave-one-source-out checked
- figure index and methods/results draft started

Decision gates:

- P(D) in formal score or sensitivity only?
- add larger H-ATLAS / Valiante or freeze Clements as bright-end anchor?
- add proper CIGALE/Dale/Draine-Li templates or leave as future work?
- postpone radio/X-ray until FIR story is written?

My current instinct:

- main score = Clements / Oliver / Pearson
- P(D) = sensitivity check
- Wang = matched-object diagnostic
- Valiante / bigger H-ATLAS only if supervisors want stronger bright-end coverage
- CIGALE-style models are good future/optional work, but not needed before writing the FIR chapter draft

Next 7 days:

1. send supervisors the evaluator setup questions
2. freeze the count-source set unless they ask for H-ATLAS/Valiante
3. turn the methods draft into real thesis text
4. clean the top 4 figures
5. maybe make one final Wang matched-object diagnostic if it helps the discussion

Simple thesis/viva line:

> pop-cosmos is not just being checked against another derived physical quantity. I am testing it in observed space, using number counts, and using the mismatch to identify which part of the model needs more flexibility.

### August 3rd: summary pipeline smoke test

I reran the lightweight summary pipeline:

```text
python run_fir_evaluator_pipeline.py --mode summary
```

It completed successfully in about `17 s`.

This refreshes:

- external SPIRE count compilation
- Wang catalogue checks
- count-source coverage plot
- hybrid/ALESS differential-count evaluator
- model-family score summary
- chi-square / degrees-of-freedom check
- P(D) sensitivity check
- leave-one-source-out check
- source-tension plot
- flux-regime diagnostics
- thesis evaluator snapshot

Headline stayed the same:

| score group                | best current model   |
| -------------------------- | -------------------- |
| all counts                 | Casey T30K alpha=2.5 |
| resolved/prior counts only | Casey T30K alpha=3.0 |
| P(D) counts only           | Casey T30K alpha=2.5 |

comments:

- good sign: the new roadmap/coverage additions did not break the reproducible workflow
- this is probably the command to run before meetings when I want the latest summary
- if I change the heavy template grids, then I need `--mode full`, but for normal writing/results refresh the summary mode is enough

### August 3rd: supervisor decision note + methods draft

Made two more writing/helpful docs:

- `pop_cosmos_notebook/FIR_SUPERVISOR_DECISION_NOTE.md`
- `pop_cosmos_notebook/FIR_METHODS_CHAPTER_DRAFT.md`

The supervisor note is basically a paste-ready thing for Dave/Boris.

It asks for sign-off on:

- should P(D) be in the formal chi-square or just sensitivity?
- should I use `chi2/N` or `chi2/(N-k)` wording?
- is Clements enough for the bright-end count anchor?
- are Casey-like templates enough, or do I need proper CIGALE / Dale / Draine-Li comparisons?

My current defaults in that note:

- main formal score = Clements / Oliver / Pearson
- P(D) = sensitivity check
- Wang = matched-object diagnostic
- Valiante / bigger H-ATLAS only if they want stronger bright-end coverage
- CIGALE templates are optional/future unless Casey-like grid feels too toy-like

The methods draft is more thesis style.

It explains:

- why I use observed-space number counts
- what pop-cosmos quantities are used
- what the external count data are
- why Wang is separate
- how templates are normalised to fixed `L_IR`
- how rest-frame SEDs become observed SPIRE fluxes
- what differential counts mean
- how the chi-square-style evaluator works
- how P(D), leave-one-source-out, and flux-regime checks are used

This feels like the right next writing move:

> get approval on the evaluator choices, then turn the methods draft into actual thesis text.

### August 3rd: results draft + stable figure package

Made the first FIR results chapter draft:

- `pop_cosmos_notebook/FIR_RESULTS_CHAPTER_DRAFT.md`

Also made a stable figure folder:

- `outputs/thesis_figure_package/`
- `outputs/thesis_figure_package/README.md`
- `outputs/thesis_figure_package/manifest.csv`

Why:

- the normal `outputs/` folder has loads of exploratory plots
- the figure package gives clean thesis/viva names like:
  - `fig01_external_count_source_coverage.png`
  - `fig02_model_family_score_comparison.png`
  - `fig03_fsps_flux_regime_residual_heatmap.png`
  - `fig04_casey_like_count_comparison.png`
  - `fig05_leave_one_source_out.png`

What the Results draft says:

- baseline FSPS overpredicts SPIRE counts
- the mismatch is worst at bright fluxes and longer wavelengths
- Casey-like `~30 K` templates currently give the best overall score
- pure ALESS overcorrects, so the answer is not just "use ALESS"
- leave-one-source-out supports that the improvement is not just one-paper tuning
- different observed count sources still disagree, so I should present a stable direction, not one magic template

Simple result wording:

> The FIR number-count mismatch points to SED shape / dust temperature as the useful model lever. Keeping `L_IR` fixed but changing the far-IR SED shape improves the comparison to observed SPIRE counts.

I also added `prepare_fir_thesis_figure_package.py` to the summary pipeline, so the figure package refreshes automatically.

Validation:

- reran `python run_fir_evaluator_pipeline.py --mode summary`
- passed in about `26 s`
- figure package was generated as the final pipeline step
- headline result still unchanged: all-count score prefers `Casey T30K alpha=2.5`

### August 3rd: discussion draft + viva storyboard

Made two more writing docs:

- `pop_cosmos_notebook/FIR_DISCUSSION_CHAPTER_DRAFT.md`
- `pop_cosmos_notebook/FIR_VIVA_STORYBOARD.md`

The Discussion draft is the "so what?" section.

It frames the result as:

- pop-cosmos/FSPS is not wrong in a random way
- the mismatch pattern points to FIR SED shape / dust temperature
- number counts were useful because they stay in observed space
- Wang is useful for matched-object diagnosis, not the main count truth
- P(D) is useful but needs caveats because the spline points are correlated
- the best template is not unique, so phrase the result as a stable physical direction

Current recommendation wording:

> pop-cosmos should include a more flexible far-infrared dust SED treatment when predicting long-wavelength observables.

The viva storyboard gives:

- 6-slide version
- 10-slide version
- likely viva questions
- one-minute summary

Simple viva line:

> Observed SPIRE counts turn the FIR mismatch into a useful model diagnostic: pop-cosmos needs more flexible dust SED shapes, not just more validation plots.

### August 3rd: intro/lit draft + master index

Made two final wrap-up docs so the FIR work is easier to navigate:

- `pop_cosmos_notebook/FIR_INTRO_LITERATURE_DRAFT.md`
- `pop_cosmos_notebook/FIR_THESIS_MASTER_INDEX.md`

The intro/lit draft is basically the front-end story:

- why optical/NIR validation is not enough
- why FIR/sub-mm counts are a useful out-of-sample test
- why differential counts are better for the formal evaluator
- what each observed count source is doing
- why Wang is a matched-object diagnostic rather than the main corrected count truth
- how ALESS / Casey-like / CIGALE-style dust templates fit into the model-extension idea

The master index is the "where is everything?" file.

It links:

- writing drafts
- planning docs
- supervisor question note
- runbook
- thesis figure package
- current evaluator snapshot

comments:

- this basically wraps the current FIR package into something thesis-shaped
- next sensible move is not more random plotting, it is supervisor sign-off on the evaluator choices and then turning the drafts into proper thesis prose

### August 3rd: Wang / count-source audit note

Made one more small audit note:

- `pop_cosmos_notebook/FIR_WANG_COUNT_SOURCE_AUDIT.md`

Main point:

> Wang is useful, but it is not the same kind of thing as Clements / Oliver / Pearson corrected number counts.

Quick notes:

- Wang `master.dat` fluxes are in `mJy`
- the cleaner COSMOS2020/Farmer area is `1.278 deg2`
- positive IDs are COSMOS2020 objects, negative IDs are radio-prior sources
- Wang is prior-selected and deblended with XID+
- the SPIRE maps are confusion dominated
- the paper itself says faint SPIRE fluxes can be slightly underestimated, getting worse from 250 to 500 um
- so raw Wang counts can sit away from external count papers for catalogue/method reasons, not only because pop-cosmos is wrong

What this means for the thesis:

- use Clements / Oliver / Pearson as the main corrected count evaluator
- use Glenn / Varnish P(D) as a faint-end sensitivity check
- use Wang for matched-object residuals and weird-source checks
- use Bethermin 2012 / SIDES as context for stacking, P(D), and model-validation style

Nice extra thing:

- Wang used CIGALE with Draine/Dale dust-emission models to build flux predictions for priors
- so our idea of testing alternative dust templates is not random; it is directly connected to how FIR catalogue/deblending work is done in the literature

### August 3rd: formal evaluator scoring note

Made the scoring setup more thesis-facing:

- `pop_cosmos_notebook/FIR_EVALUATOR_SCORING_NOTE.md`
- `outputs/popcosmos_formal_evaluator_summary.md`
- `outputs/popcosmos_formal_evaluator_summary.png`

What I am using as the clean default:

| role                       | data                                             |
| -------------------------- | ------------------------------------------------ |
| formal score               | Clements / Oliver / Pearson SUSSEX / Pearson XID |
| faint-end sensitivity      | Glenn / Varnish P(D)                             |
| matched-object diagnostics | Wang                                             |

Main logic:

- use differential counts because flux bins are closer to independent
- use `chi2/(N-k)` for the thesis-facing score, but still call it a rough chi-square-style evaluator
- do not treat P(D) spline knots as simple independent bins unless Dave/Boris say that is okay
- do not treat Wang raw counts as the main count truth

Current formal read:

> resolved/prior differential counts prefer a Casey-like warm/broader dust SED over baseline FSPS. P(D) changes details but not the broad direction.

Overfitting note:

> high chi-square does not mean overfitting. It means model/data mismatch or incomplete errors/model assumptions. Overfitting is checked with leave-one-source-out, by not tuning per paper/band, and by keeping the template changes physically constrained.

### August 3rd: aligned chapter drafts with formal score

Did a cleanup pass on the thesis chapter drafts so they all say the same thing now.

Updated:

- `pop_cosmos_notebook/FIR_METHODS_CHAPTER_DRAFT.md`
- `pop_cosmos_notebook/FIR_RESULTS_CHAPTER_DRAFT.md`
- `pop_cosmos_notebook/FIR_DISCUSSION_CHAPTER_DRAFT.md`
- `pop_cosmos_notebook/FIR_THESIS_FIGURE_INDEX.md`

Main fix:

> The Results/Methods now lead with the formal resolved/prior evaluator, not the pooled all-count score.

So the story is:

- formal score = Clements / Oliver / Pearson resolved-or-prior differential counts
- P(D) = faint-end sensitivity check
- Wang = matched-object diagnostic
- pooled all-count score = useful sanity check, not the first thing I would defend

New figure added to the stable figure package:

- `outputs/thesis_figure_package/fig09_formal_evaluator_summary.png`

Current wording to use:

> Corrected resolved/prior SPIRE counts prefer a warm/broader Casey-like FIR dust template over baseline FSPS, while P(D) counts support the same broad family but shift the exact preferred parameter slightly.

comments:

- this is cleaner for the thesis because it avoids letting correlated P(D) spline knots drive the headline
- the headline model is now `Casey T30K alpha=3.0` for the formal score, while the pooled/P(D) sanity checks prefer nearby `Casey T30K alpha=2.5`
- that difference is small enough to be a nuance, not a contradiction

### August 3rd: wrap-up / freeze checklist

Made one last planning file to stop the FIR work from turning into infinite extra plots:

- `pop_cosmos_notebook/FIR_THESIS_DECISION_CHECKLIST.md`

The point is basically:

> this FIR package is good enough to start freezing; the next useful thing is supervisor sign-off, not more random analysis.

What I would freeze for now:

- formal score uses Clements / Oliver / Pearson resolved-or-prior differential counts
- P(D) stays as a faint-end sensitivity check
- Wang stays as a matched-object diagnostic
- pop-cosmos `L_IR` stays fixed, and only the FIR SED shape changes
- the main result is warm/broader Casey-like dust templates improving over baseline FSPS

Main things to ask:

- should P(D) be in the headline score or kept separate?
- should I report `chi2/(N-k)` or keep simpler `chi2/N` wording?
- is Clements enough for the bright end, or do I need a bigger H-ATLAS / Valiante source?
- is the Casey-like grid enough, or do I need proper CIGALE / Dale / Draine-Li templates?
- should Wang get one clean diagnostic plot, or mostly stay in caveats?

comments:

- the thesis story now feels like model criticism / model improvement, not just validation
- I should stop adding papers/plots unless they answer one of the decision questions

### August 3rd: Wang / P(D) / Bethermin source check

Did a quick re-check of the Wang paper + local CDS ReadMe + the P(D)/Bethermin papers.

Main Wang thing:

> the Wang mismatch is probably not a unit mistake.

Why:

- Wang `master.dat` is an object catalogue, not a corrected number-count table
- `F250`, `F350`, `F500`, `F850` are in `mJy`
- the clean COSMOS2020/Farmer area is `1.278 deg2`, not a casual `2 deg2`
- Wang's SPIRE priors use predicted fluxes, including around `S250 > 7 mJy`
- the paper says SPIRE output counts are close to true above about `10 mJy`, but faint counts below that can fall low

So if Wang sits away from Clements / Oliver / Pearson:

- that does not immediately mean one is wrong
- Wang is prior-selected, deblended, small area, and raw-count derived
- Clements / Oliver / Pearson are published corrected count products
- best use of Wang is still per-object residuals and weird-source checks

P(D) / Glenn / Varnish:

- P(D) looks below the usual source detection/confusion limit by fitting the pixel-brightness distribution
- very useful for faint-end sensitivity
- but fitted P(D) spline points should not be treated like fully independent bins unless I know the covariance

Bethermin:

- Bethermin 2012 is useful for stacking / below-confusion count context
- Bethermin 2017 / SIDES is more model/simulation context than an observed table
- both support the idea that number counts, P(D), CIB, etc. are standard model-validation observables

comments:

- this strengthens the current evaluator setup: corrected differential counts for formal score, P(D) as sensitivity, Wang as diagnostic
- the next thesis work should be turning this into clean method/results text, not adding another data source unless it fills a bright-end gap

### August 3rd: Wang raw-count context plot

Made a small plot just for the Wang-count confusion:

- `pop_cosmos_notebook/outputs/wang_raw_count_context.png`
- `pop_cosmos_notebook/outputs/wang_raw_count_context_note.md`

What it shows:

- Wang raw cumulative counts using positive COSMOS2020 IDs and `1.278 deg2`
- the same rows divided by rough `2 deg2`, just to show how much the old area assumption moves things
- Wang with `SNR>=3`
- all Wang prior rows, including the negative radio-prior IDs
- direct published integral-count points from Clements and Pearson

Simple read:

- the Wang units are fine, they are `mJy`
- area choice alone moves the raw count density by about `1.56x`
- SNR cut does not change bright counts much, but matters more near faint cuts
- adding radio-prior rows can lift the raw Wang curve
- Wang is small-area and prior/deblend selected, so it naturally gets weak at the rare bright end

comments:

- this is not a formal evaluator plot
- it is useful if someone asks "why does Wang not line up with the corrected count papers?"
- it supports keeping Wang as a diagnostic and using corrected differential counts for the formal model score
- also added it to the thesis figure package as `fig10_wang_raw_count_context.png`, probably appendix/context rather than main result

### August 3rd: quick plot-reading cheat sheet

This is mostly for me because I got mixed up between the different heatmaps.

#### First-pass evaluator heatmap

File:

- `outputs/popcosmos_differential_count_evaluator_heatmap.png`

Columns:

- `FSPS`
- `25% ALESS`
- `50% ALESS`
- `75% ALESS`
- `ALESS`

Rows:

- count source / paper table, e.g. Clements, Oliver, Pearson, Glenn, Varnish

What one box means:

> one rough reduced chi-square score for that model against all usable flux bins in that source.

So it is not one flux value.

The printed number is raw rough reduced chi-square.

The colour is `log10(raw rough reduced chi-square)`.

That is why a printed `3.1` can have a colour near `0.5` on the colourbar:

`log10(3.1) = 0.49`

How to read:

- lower printed number = better
- `~1` = good-ish
- `2-5` = imperfect but usable
- `>10` = bad mismatch
- this plot only compares the early FSPS/ALESS hybrid family

#### Differential-count overlay

Files:

- `outputs/popcosmos_differential_count_area_corrected_overlay.png`
- later also `outputs/popcosmos_casey_like_template_grid_counts.png`

Axes:

- x-axis = flux density `S` in `mJy`
- y-axis = `S^2.5 dN/dS` in `Jy^1.5 deg^-2`

What it shows:

- points = observed published number counts
- curves = model predictions
- curve above points = model predicts too many galaxies
- curve below points = model predicts too few galaxies

This is the plot to visually inspect count-curve shape.

#### Model-family score plot

File:

- `outputs/popcosmos_model_family_score_comparison.png`

What it shows:

- one overall score for each model family
- includes FSPS, ALESS hybrids, MBB, Casey-like templates
- lower score = better
- not one flux bin; it pools many count-table points

Main read:

> Casey-like `T ~ 30 K` models score better than baseline FSPS.

#### Source-to-source tension plot

File:

- `outputs/popcosmos_model_family_source_tension.png`

What it shows:

- left = heatmap of source vs model score
- right = how much worse FSPS is than the best model for each source

Again:

- rows are papers/tables
- columns are models
- printed number is raw rough reduced chi-square
- colour is `log10` of that score

Main read:

> different papers do not pick the exact same best template, but every source prefers something better than FSPS.

#### Flux-regime residual heatmap

File:

- `outputs/popcosmos_model_family_flux_regime_residual_heatmap.png`

This is the one where flux range is actually on the axis.

Values:

`log10(model / observed)`

How to read:

- `0` = perfect
- `+0.3` = model high by about `2x`
- `+1.0` = model high by `10x`
- negative = model too low

Main read:

> FSPS is not awful at 250 um low/mid flux, but it gets worse at bright flux and at 350/500 um.

#### Leave-one-source-out plot

Files:

- `outputs/popcosmos_differential_count_leave_one_source_out.png`
- `outputs/popcosmos_model_family_leave_one_source_out.png`

What it does:

- hide one paper/table
- choose best model using the other papers
- test on hidden paper

Why:

> checks whether I am just tuning to one dataset.

Main read:

> the warm/broader dust correction beats FSPS on held-out sources, but it is not always the exact best possible model for each source.

#### Wang raw-count context plot

File:

- `outputs/thesis_figure_package/fig10_wang_raw_count_context.png`

What it shows:

- raw Wang cumulative counts
- effect of `1.278 deg2` vs old `2 deg2`
- effect of SNR cut
- effect of including radio-prior rows
- direct published integral points from Clements/Pearson for context

Main read:

> Wang is not a unit mistake. It is a different kind of data product, so use it for diagnostics, not as the formal count truth.

#### What I should present tomorrow

Old pre-feedback version. After the supervisor comments, I should probably use this only as context and not as the final meeting plan.

If I only show three things:

1. `fig09_formal_evaluator_summary.png`
   - old formal score summary
   - useful internally, but do not over-defend the Casey-like best model
2. `fig03_fsps_flux_regime_residual_heatmap.png`
   - where FSPS fails: bright end and longer wavelengths
3. `fig10_wang_raw_count_context.png`
   - why Wang raw counts are diagnostic, not the main count benchmark

One-sentence story:

> The evaluator compares pop-cosmos predictions to published SPIRE number counts in observed space. FSPS is too high, especially for bright 350/500 um counts. Warmer dust SED shapes improve the comparison at fixed `L_IR`, but the exact template family should be treated cautiously. Wang is best used to diagnose individual COSMOS sources rather than as the formal count table.

</details>
