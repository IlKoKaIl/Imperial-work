# FIR Wang / Count-Source Audit

This is a bookkeeping note for the question:

> why does Wang sometimes sit away from the external SPIRE count papers, and should I worry?

Short answer:

> not automatically. Wang is a deblended COSMOS point-source catalogue. Clements / Oliver / Pearson are published corrected number-count measurements. They are related, but they are not the same kind of object.

## Wang Catalogue: What It Is

Wang et al. 2024 is a probabilistic progressive deblending catalogue for COSMOS.

The important method points:

- it uses XID+, a Bayesian/MCMC deblending framework
- it starts from COSMOS2020 plus radio priors
- it predicts which sources should matter at each new wavelength
- it moves progressively from MIPS 24 um to PACS, SPIRE 250/350/500 um, and SCUBA-2 850 um
- it releases point-source flux estimates and posterior information

So Wang is very useful for:

- matched-object flux checks
- "is this COSMOS object bright in the data and in pop-cosmos?"
- high-SFR / AGN / weird-source diagnostics
- seeing whether residuals depend on wavelength, SFR, redshift, or object type

But raw Wang counts are not automatically the right formal number-count benchmark, because the catalogue has prior-selection and deblending choices built into it.

## Wang Units / Area Check

From the local CDS `ReadMe.txt` for `master.dat`:

- `master.dat` has `131178` catalogue rows
- `F250`, `F350`, `F500`, and `F850` are median flux densities
- those fluxes are in `mJy`
- `s_F250`, `s_F350`, `s_F500`, and `s_F850` are one-sigma-style flux errors in `mJy`
- negative IDs are radio sources rather than normal positive COSMOS2020 IDs

From the Wang paper:

- the COSMOS2020 `FLAG_COMBINED=0` selected area is `1.278 deg2`
- this is smaller than the rough full COSMOS field of about `2 deg2`

So if I make raw Wang count densities, the cleaner default is:

> positive COSMOS2020 IDs only, divided by `1.278 deg2`, with the SNR/flux cut stated clearly.

Do not casually divide by `2 deg2`.

## August 3rd Paper Re-Check

I re-checked this against the Wang paper / arXiv version and the local CDS table description.

Useful details:

- Wang Table 4 is a catalogue-column description, not a corrected number-count table.
- `F_250/350/500` are explicitly listed as flux densities in `mJy`.
- the posterior samples for 250/350/500 um are also in `mJy`.
- the COSMOS2020 `FLAG_COMBINED=0` area is `1.278 deg2`.
- the SPIRE prior construction uses a predicted 250 um flux cut of `7 mJy`.
- the listed SPIRE confusion noise is about `6.8`, `6.3`, `5.8 mJy` at 250/350/500 um.
- their simulation check says output counts are close to the true counts above about `10 mJy`, but fall below the true counts at `<10 mJy`.

So the Wang/raw-count disagreement is probably not a hidden unit bug.

My current read:

> Wang is fine to use, but raw counts from `master.dat` are a derived sanity check, not the same object as the published corrected Clements / Oliver / Pearson number counts.

This matters because the Wang catalogue is built by prior selection and XID+ deblending. The external count papers already include their own completeness, reliability, flux boosting/deboosting, extraction, and area choices. So I should not force Wang to overlay the corrected count products perfectly.

## Wang Selection Details That Matter

The Wang catalogue is not just "all real SPIRE sources in COSMOS".

Important paper details:

- the SPIRE maps are confusion dominated
- the SPIRE prior list is built from predicted SPIRE fluxes using a CIGALE-trained deep-learning emulator
- one SPIRE prior branch includes sources with predicted `S250 > 7 mJy`
- X-ray/radio sources can also enter the prior list
- the paper reports small systematic underestimation at faint SPIRE fluxes, roughly increasing from 250 to 500 um
- the Wang team scale / treat flux uncertainties carefully because confusion and residual noise matter

This gives a very plausible reason why raw Wang curves do not always line up with published corrected count curves:

- Wang is prior-selected
- Wang is deblended
- Wang is small-area COSMOS
- faint SPIRE fluxes are near confusion
- 350/500 um are harder because the beam is larger and blending is worse
- raw catalogue counts do not include the same completeness/reliability/count corrections as published count tables

Extra nuance from the Wang simulation section:

- above `10 mJy`, Wang-style SPIRE output counts should be more trustworthy
- below `10 mJy`, the catalogue can undercount because deblended faint fluxes get biased/scattered low
- this supports Dave's earlier advice that number-count interpretation below about `10 mJy` is risky
- it also supports using Wang mostly for object-by-object flux residuals rather than as the headline count curve

## What The Current Local Wang Check Says

The current local output is:

- `outputs/wang_master_catalog_discrepancy_note.md`
- `outputs/wang_raw_count_context.png`
- `outputs/wang_raw_count_context_note.md`

Using positive COSMOS2020 IDs and `1.278 deg2`, the raw counts fall off quickly at long wavelength / high flux:

| band | >10 mJy raw N/deg2 | >50 mJy raw N/deg2 |
|---|---:|---:|
| 250 um | 3011.7 | 36.8 |
| 350 um | 2041.5 | 9.4 |
| 500 um | 797.3 | 0.8 |
| 850 um | 7.0 | 0.0 |

Simple read:

- 250 um Wang checks are meaningful because there are many detections
- 500 um has much thinner bright-end statistics
- 850 um is basically too sparse for raw counts in this file
- Wang is best kept as object-level diagnostics, not the main population-count truth

The new raw-count context plot compares Wang cumulative counts against direct published integral points from Clements and Pearson:

![Wang raw count context](outputs/wang_raw_count_context.png)

comments:

- using `1.278 deg2` instead of `2 deg2` lifts raw Wang count densities by about `1.56x`
- applying `SNR>=3` barely changes bright `>20-50 mJy` counts, but matters more near faint cuts
- including negative radio-prior rows can lift Wang by roughly `30-80%`, depending on band/flux cut
- Wang follows the deep-count regime better than the rare bright end, which is expected for a small COSMOS-area deblended catalogue

## External Count Sources In The Evaluator

The compiled external file currently contains:

| source | current role | rows in compiled table |
|---|---|---:|
| Clements et al. 2010 Table 1 | resolved/prior formal score, bright/wide anchor | 39 |
| Oliver et al. 2010 Table 2 | resolved/prior formal score, mid-flux HerMES | 18 |
| Pearson et al. 2025 Table 3 SUSSEXtractor | resolved formal score, deep Dark Field extraction | 44 |
| Pearson et al. 2025 Table 4 XID | prior/XID formal score, deep Dark Field extraction | 29 |
| Glenn et al. 2010 Table 4 P(D) no-FIRAS spline | P(D) sensitivity / faint-end | 23 |
| Varnish et al. 2025 Table 4 P(D) spline | P(D) sensitivity / faint-end | 43 |

The standard unit after compilation is:

> `S^2.5 dN/dS` in `Jy^1.5 deg^-2`

This is the thing being scored against the model differential counts.

## Glenn / P(D) Role

Glenn et al. 2010 is useful because it uses a P(D) fluctuation analysis.

In simple terms:

> P(D) looks at the distribution of pixel brightnesses in a confused map and infers the source counts statistically, even below normal source-detection limits.

For the thesis:

- good for faint-end sensitivity
- good to show that number-count validation does not only rely on detected catalogues
- but the fitted spline/count points are not as cleanly independent as simple resolved flux bins

So my current default is:

> include Glenn/Varnish as sensitivity checks, but ask supervisors before making P(D) part of the formal headline score.

Paper re-check:

- Glenn reaches roughly `2 mJy/beam`, below ordinary confusion-limited source detection.
- Glenn says P(D) counts are broadly consistent with individually detected SPIRE counts, but many galaxy-count models overpredict bright galaxies and do not match the faint-end slope.
- Varnish / Dark Field II also compares against Glenn and Bethermin, and reports that current literature models struggle with the deepest P(D) result.

Simple thesis usage:

> P(D) is excellent evidence that faint counts matter, but I should not treat all P(D) spline knots as independent bins unless I model their covariance properly.

## Bethermin 2012 / 2017 Role

Bethermin 2012:

- useful for stacking / prior-based deep count context
- useful for explaining how people probe below confusion
- useful literature support for number counts as galaxy-evolution constraints
- not currently in the formal evaluator because I do not have a clean total-count numeric table ready to use

Bethermin 2017 / SIDES:

- this is a simulated-sky / model context source, not an observed count table
- Wang uses SIDES-like simulations for deblending validation
- useful because SIDES is designed to reproduce observed statistics such as number counts, P(D), and CIB anisotropies

So for the thesis:

- Bethermin 2012 = method/literature context, possible future add if a clean table is found
- Bethermin 2017/SIDES = motivation for using count/P(D)-style observed statistics to validate models

Paper re-check:

- Bethermin 2012 uses stacking to reconstruct SPIRE counts down to about `2 mJy`, around ten times below the usual `5 sigma` confusion limit.
- Bethermin 2017/SIDES is not just a count table; it is a simulated sky/model framework that tries to reproduce number counts, redshift distributions, and CIB-related statistics.
- SIDES also highlights that finite angular resolution/blending can bias single-dish counts, especially around 350/500 um.

So this is useful for the thesis argument:

> number counts are not a toy metric; they are a standard way of testing infrared galaxy-evolution models, but the comparison has to respect extraction method and resolution effects.

## CIGALE / Dust-Template Link

One useful Wang detail:

- Wang used CIGALE runs with different assumptions, including Draine et al. and Dale et al. dust emission models, then trained a neural-network emulator to predict fluxes for deblending priors.

This supports our model-extension direction.

It means I can say:

> testing alternative dust-emission templates is not an artificial trick; it is already standard in FIR SED work and is also part of how the Wang catalogue constructs its priors.

For this thesis, the current Casey-like grid is a lightweight controlled version of that idea. A later CIGALE/Dale/Draine-Li comparison would be a natural extension if time/supervisors want it.

Extra detail:

- Wang used 16 CIGALE configurations from combinations of star-formation history, attenuation, dust emission, and AGN model choices.
- The dust-emission branch explicitly includes Draine et al. and Dale et al. templates.
- This gives me a good literature-backed reason to say that flexible FIR dust templates are a serious model lever, not just curve-fitting.

## How I Should Phrase The Wang Disagreement

Bad phrasing:

> Wang disagrees with the counts, so one of them is wrong.

Better phrasing:

> Wang is not a corrected population count product, so I should not expect its raw counts to perfectly overlay Clements/Oliver/Pearson. The useful Wang test is per-object: does pop-cosmos predict the right flux for the same COSMOS sources?

Best thesis usage:

- formal population evaluator = corrected published differential counts
- Wang = matched-object diagnostic and high-SFR/AGN/weird-source check
- P(D) = faint-end sensitivity check
- Bethermin/SIDES = literature and methodology context

## Sources Checked

- Wang et al. 2024 COSMOS XID+ catalogue paper: https://www.aanda.org/articles/aa/full_html/2024/08/aa49055-23/aa49055-23.html
- local Wang CDS `ReadMe.txt`: `../catalog data/wang/ReadMe.txt`
- Glenn et al. 2010 P(D) paper: https://academic.oup.com/mnras/article/409/1/109/1994744
- Bethermin et al. 2012: https://www.aanda.org/articles/aa/full_html/2012/06/aa18698-11/aa18698-11.html
- Bethermin et al. 2017 / SIDES: https://www.aanda.org/articles/aa/full_html/2017/11/aa30866-17/aa30866-17.html
