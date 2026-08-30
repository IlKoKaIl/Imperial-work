# The per-object vs number-count paradox — resolved

This was an open item in your log. You state it at `supervisor_meeting_prep.md` line 4406:

> "counts can say FSPS makes too many bright sources overall, but the per-object Wang plot
> can still say FSPS is too faint for the galaxies Wang actually detects."

and immediately draw the right inference — *"the model may be putting FIR brightness on the
wrong objects, not just being globally high or low."* The analysis below confirms that
intuition and makes it quantitative. The answer **changes the physical interpretation of the
whole thesis**.

## The paradox, reproduced

| band | per-object median log10(FSPS/Wang) on Wang detections | N(>20 mJy) model / observed |
|---:|---:|---:|
| 250 | −0.163 dex (model 31% faint) | 2.06× |
| 350 | −0.235 dex (model 42% faint) | 2.83× |
| 500 | −0.183 dex (model 34% faint) | 4.68× |

Same objects, same bands, opposite conclusions. (The −0.163 dex matches your logged value
exactly.)

## The resolution: it is a selection asymmetry, and the driver is SCATTER

Condition on *Wang-detected* objects and the model looks faint. Condition on *model-bright*
objects and the sign flips completely:

| band | conditioned on Wang-detected | conditioned on model > 20 mJy |
|---:|---:|---:|
| 250 | **−0.163** | **+0.404** |
| 350 | **−0.235** | **+0.582** |
| 500 | **−0.183** | **+0.803** |

Of the objects the model puts above 20 mJy, **74% / 88% / 95%** are actually faint in Wang
(median true flux 13.4 / 8.2 / 4.9 mJy). The model is not uniformly too bright — it is
**scattering faint galaxies up into the bright bins**.

The model's per-object flux scatter is **0.51 / 0.45 / 0.45 dex** (noise-deconvolved; Wang's
own measurement noise is only 0.07–0.10 dex, so this is intrinsic to the model). Because the
counts are steep (α = 3.2–4.1), that scatter preferentially promotes the numerous faint
galaxies into the sparse bright bins.

## Quantitative decomposition — the two effects nearly cancel

Injecting the model's measured scatter into the *observed* fluxes and re-counting isolates
the scatter term:

| band | per-object mean offset | count effect of mean, (α−1)×offset | count effect of scatter | predicted net | **measured net** |
|---:|---:|---:|---:|---:|---:|
| 250 | −0.163 | −0.361 | +0.549 | +0.188 | **+0.19** |
| 350 | −0.235 | −0.621 | +0.731 | +0.110 | **+0.31** |
| 500 | −0.183 | −0.575 | +0.855 | +0.280 | **+0.43** |

The mean offset alone would make the model counts *too low* by 0.36–0.62 dex. Scatter
inflates them by 0.55–0.86 dex. The two largely cancel, leaving a modest net excess of the
size observed. The agreement is exact at 250 µm (+0.188 predicted vs +0.19 measured) but
**partial at the longer bands**: +0.11 vs +0.31 at 350 µm and +0.28 vs +0.43 at 500 µm, i.e.\
the decomposition accounts for roughly a third to two-thirds of the excess there, leaving
0.15–0.20 dex unexplained.

Do not write this up as "the decomposition reproduces the excess" — it does so only at
250 µm. Nor should the residual be described as growing monotonically with wavelength: it is
\dex{0.00}, \dex{0.20}, \dex{0.15} at 250, 350, 500 µm, i.e.\ absent at 250 µm and comparable
at the two longer bands.

The defensible framing is narrower. The scatter term is the dominant single contributor to the
bright-count excess and it fully accounts for the 250 µm result; at 350 and 500 µm a residual
of \dex{0.15}--\dex{0.20} remains, which is where the cold-SED problem plausibly contributes,
since a too-cold SED biases the longer bands more. That the residual appears only in the two
long-wavelength bands is consistent with the cold-dust interpretation but the band ordering
does not by itself establish it, and the decomposition carries its own uncertainty
(the scatter term comes from an injection test with its own model dependence). Present the
two mechanisms as complementary and independently evidenced — scatter by the conditioning
sign-flip, cold dust by the SED peak distribution — rather than resting either on this
arithmetic.

**Method note:** the closed-form lognormal boost `exp(½((α−1)σ ln10)²)` gives 31–219×, which
is absurd — it assumes an unbroken power law over infinite range. The direct injection test
is the valid estimate and is what is quoted above.

## Why this matters: warmer templates fix the mean, not the scatter

Per-object scatter by model variant (dex):

| model | 250 | 350 | 500 |
|---|---:|---:|---:|
| FSPS | 0.513 | 0.462 | 0.454 |
| ALESS 25% | 0.462 | 0.443 | 0.456 |
| ALESS 50% | 0.423 | 0.429 | 0.457 |
| ALESS 75% | 0.398 | 0.415 | 0.455 |
| ALESS pure | 0.383 | 0.426 | 0.495 |

**Scatter is essentially unchanged (~0.45 dex) across every variant.** The hybrids win on
counts by shifting the *mean* flux down, not by fixing the scatter. And after correcting Wang
upward for its known 13–19% low bias, **every** variant — including the count-winning ones —
is too faint per object (FSPS −0.17/−0.30/−0.27; ALESS-50% −0.19/−0.38/−0.42 dex).

So the honest conclusion is **two distinct problems**, not one:

1. **A shape/temperature problem** — the FIR SED is too cold (established: 64% of galaxies
   peak beyond 100 µm, median ~136 µm; excess grows with wavelength; warm templates improve
   counts). Fixable by a warmer template.
2. **A scatter problem** — the galaxy-to-galaxy FIR flux scatter is ~0.45 dex and is
   **not** fixed by any template change, because it comes from the `L_IR`/attenuation
   distribution rather than the SED shape. This is the *dominant* driver of the bright-count
   excess and it is untouched by the entire template grid.

This reframes the thesis from "pop-cosmos dust is too cold" to the more defensible and more
interesting **"pop-cosmos gets FIR counts wrong for two independent reasons, and only one of
them is fixable by changing the dust template."** That is a stronger contribution: it tells
the pop-cosmos team where to look (the L_IR scatter, not just the dust prescription).

## Caveats
- Wang is the only per-object reference used here; its deblending error is not in the quoted
  per-object σ, so some of the 0.45 dex may be Wang deblending scatter rather than model
  scatter. **The Jin catalogue can settle this** — it is an independent deblending of the
  same field, and repeating this measurement against Jin would separate the two. Worth doing
  before the claim goes in the thesis.
- The scatter-injection test perturbs observed fluxes symmetrically in log space; a genuinely
  asymmetric model error would not be captured exactly.
- α is measured over 10–150 mJy from the pooled published counts.

---

# Final figure plan for the thesis

Seven figures, in narrative order. Those marked **[have]** exist now.

1. **Fig 1 — The test, and the headline result.** **[have]**
   `popcosmos_count_overlay_thesis.png` — 3 bands × (counts + residual). Establishes the
   comparison and shows FSPS too bright, worsening with λ and flux. This is the paper's pitch
   as data.
2. **Fig 2 — Why the model fails: the SED is too cold.** **[have]**
   `fsps_fir_sed_diagnostic.png` — example SEDs by `L_IR` percentile + population peak
   histogram (median 136 µm, 64% cold, 20% warm tail). The physical cause.
3. **Fig 3 — The template experiment.** *(needs one panel built)*
   Count curves for the MBB/Casey/hybrid families + a χ² or offset summary panel. Shows
   warmer/broader FIR SEDs at fixed `L_IR` move counts the right way, and that the families
   are observationally degenerate: ALESS-50% and Casey T30K α=2.5 differ by a median of only
   0.05–0.09 dex per band over 10–300 mJy, comparable to the 0.12 dex inter-survey scatter
   (larger in the Poisson-limited bright bins). Report the dust temperature as the
   constrained quantity; the emissivity index α is *not* constrained — the preferred value
   moves between 2.5 and 3.0 depending on which count sources are included.
4. **Fig 4 — Statistical robustness.** *(needs building from saved CSV)*
   Block-bootstrap forest plot: median offset with 95% CI per model, resampling whole sky
   fields. FSPS excluded (CI +0.155 to +0.519); warm templates straddle zero. Replaces the
   χ²-table-only argument and pre-empts the correlated-errors objection.
5. **Fig 5 — The paradox and its resolution.** **[have]**
   `paradox_resolution.png` — scatter distribution, the mean-vs-scatter decomposition, and
   the flat scatter across variants. Your most novel result.
6. **Fig 6 — Where the excess lives in redshift.** **[have]**
   `z_resolved_fir_diagnosis.png` — cold fraction vs z, per-band excess localisation
   (250 µm from z<1, 500 µm from z≈1.5–2.5), z composition of the counts.
7. **Fig 7 — Catalogue systematics (defensive).** **[have]**
   `wang_jin_ratio_vs_flux.png` — why raw deblended counts sit low, flux-resolved; justifies
   using published counts as the benchmark and Wang as a diagnostic.

**Supplementary:** `wang_jin_count_diagnosis.png` (absolute-count version of Fig 7);
per-source residual tables; the leave-one-source-out bar plot from your existing pipeline.

**Cut from the thesis figure set:** the IRAC Ch1–Ch4 validation figures and the
Speagle/starburst-fraction work. They were essential to getting here but belong to the
earlier, broader scope (FIR + radio + X-ray). Keep one sentence in the introduction
explaining the narrowing, and put the IRAC residuals in an appendix as evidence the
optical/NIR model is sound where it was trained.
