# Thesis narrative notes: reading of supervisor_meeting_prep.md

Full read of all 6,390 lines, February to August 2026, organised as a story rather than a
list. Every figure named below has been checked to exist on disk (31 of 31 confirmed).

The one-line version of the whole project:

> pop-cosmos was validated where it was trained, then pushed into the far-infrared where it
> was not, and the extension found a specific, physical failure that the training data could
> not have revealed.

That sentence works because the early chapters establish credibility. Don't cut them.

---

## The arc, in six acts

### Act 1 (Feb–Mar): does the model reproduce known relations?
**Motivation.** Before pushing into new wavelengths, check the model against something
established. Speagle+2014 main sequence was the obvious ruler.

**Found.** pop-cosmos SFRs sit systematically low: median ΔMS ≈ −0.53 dex, worst at low
redshift (−0.68 at z<0.5) and converging by z~3 (−0.19). Confirmed independently against
LePhare (+0.22 to +0.36 dex) and EAZY (+0.08 to +0.17 dex) on the same matched galaxies.

**Narrative role.** Establishes that a systematic offset exists and is not a binning
artifact. Also sets up the honesty theme: the student found a discrepancy and chased its
cause rather than reporting it as a result.

**Dead end worth one sentence.** The starburst-fraction work (ΔMS ≥ 0.6 dex) gave
implausibly low numbers (~0.3% vs ~2% in Rodighiero+2011). The student correctly diagnosed
this as a definition/selection mismatch rather than physics, and paused. Your own words:
*"We likely got very low starburst numbers because this was a much stricter and different
comparison than before, not because starbursts disappear physically."* That instinct is
worth showing.

**Figures:** SFR–M* hexbin with Speagle line overlaid. APPENDIX at most.

### Act 2 (Mar–Apr): does the model work where it was trained?
**Motivation.** Dave asked whether model fluxes could be loaded and checked. This is the
control experiment for everything later.

**Found.** IRAC Ch1: N=423,272, median residual +0.020 mag, MAD 0.084. Ch2: N=414,272,
−0.012 mag, MAD 0.041. Both track observations well; Ch2 tighter. Ch3/Ch4 noisier with
lower coverage (55%, 22%). MIPS24 unavailable.

**Narrative role.** This is the load-bearing control. Without it, "the far-IR is wrong" could
just be "the model is wrong". With it, you can say the model is sound where constrained and
fails specifically where it is not. **Keep this, compressed, in the main text** — one
paragraph and possibly one panel. It is what makes the later result diagnostic rather than
merely negative.

Your framing was already right: *"Ch1 and Ch2 are close enough to the fitted regime that
they let me check whether the modelling pipeline is behaving sensibly; Ch3 and Ch4 start to
push further out in wavelength, so they are more like a real extension test."*

**Figures:** `popcosmos_irac_redshift_histograms.png` (APPENDIX). Boris's `fig1`–`fig7`
(`fig1_speculator_vs_stored.png`, `fig3_coverage_map.png`, `fig6_example_seds.png` are the
useful ones) are internal consistency checks — APPENDIX, and credit Boris.

### Act 3 (Apr–May): the first far-IR attempt, and why it failed
**Motivation.** Bridge from optical fitting to far-IR. First attempt compared model `L_IR`
against Kennicutt and against single-band Wang fluxes.

**Found.** Model `L_IR` correlates strongly with SFR (rho 0.82–0.95), so the internal
physics is coherent. But `L_IR` sits 0.3–0.6 dex above the Kennicutt line, peaking ~0.44 dex
at z~1.75, and single-band flux correlations were weak (rho 0.16–0.23).

**Narrative role.** This is the most instructive dead end in the log, and it deserves a
short subsection. The weak correlations looked like model failure but were not: a single
observed band samples different rest-frame wavelengths across a redshift range. Your
realisation — *"This makes me less worried that the low direct Spearman coefficients
automatically mean pop-cosmos is failing"* — is exactly the kind of reasoning an examiner
wants to see. It also motivates why you needed a statistic that does not require
rest-frame interpretation.

**Figures:** `popcosmos_lir_vs_sfr.png` and `popcosmos_lir_offset_by_redshift.png`. One of
them in the main text as the "first attempt" figure, or both in an appendix.

### Act 4 (late May): the turning point
Two supervisor interventions changed the project, and both should be visible in the report:

1. **May 25, Dave:** *"the validation does not have to be only on physical quantities like
   L_IR or SFR. It can also be on observed quantities like number counts."*
   This decoupled the thesis from dust-template and IMF assumptions.
2. **Later, Dave:** differential counts rather than integral counts, because integral bins
   re-use sources and therefore have correlated errors.

Your own restatement is the cleanest version and should be paraphrased in the Methods
motivation: *"Number counts feel like the best route because they test observed fluxes
directly, without having to turn real 250/350/500 µm fluxes into more model-dependent
physical quantities like L_IR or SFR."*

**Also here:** the scope narrowed from FIR + radio + X-ray to FIR alone. State it plainly as
a scoping decision with the reason (each regime needed its own systematics work), not as an
omission.

**Cut entirely:** the agentic-pipeline / AlphaEvolve-style automation sketch. You already
concluded it was scope creep and belongs elsewhere. Don't reopen it; at most one clause in
Further Work.

### Act 5 (June): finding the actual physics
**Motivation.** With counts as the metric, compare properly. First with the ALESS template
as a stand-in, then with the real FSPS SEDs.

**Found — and this is the core of the thesis:**
- pop-cosmos far-IR SEDs peak at ~135–160 µm; ALESS submillimetre galaxies peak at ~80–100 µm.
  The model's dust is colder.
- The bright-count mismatch **grows with wavelength** (250 → 350 → 500 → 850 µm). That
  ladder is the signature of excess cold dust, and it is the single most persuasive piece of
  evidence in the log.
- The top-5 SFR objects have log `L_IR` 12.8–14.1, so the cold peak is not a
  low-luminosity artifact.

**The key quote in the entire log** (Boris, recorded by you):

> "pop-cosmos gets these SEDs from FSPS with energy balance. Energy balance fixes total
> L_IR. But the dust temperature / far-IR shape is basically not fitted by COSMOS data.
> COSMOS only really constrains out to IRAC, not the far-IR."

That is the thesis's central mechanism and belongs early in the Introduction, in your own
words.

And your own framing of the result, which is the sentence the Results section should build
toward: *"the model may have roughly the right total dust luminosity, but puts it at the
wrong wavelengths."* Plus: *"FIR validation is finding something optical/NIR validation
could not see."*

**Figures (strong):**
- `popcosmos_full_sed_multiband_counts.png` — the wavelength ladder. MAIN.
- `popcosmos_full_sed_top5_shape_normalized.png` — shape-only FSPS vs ALESS. MAIN or APPENDIX.
- `popcosmos_full_sed_median_sfr_seds.png` — median SED by SFR bin; shows the cold feature is
  population-wide, not a few objects. MAIN.
- `popcosmos_full_sed_agn_parameter_median_seds.png` — high-AGN tail peaks ~33 µm vs ~135 µm.
  Good APPENDIX figure and pre-empts an obvious viva question.

**Cut:** the 30–100 µm narrow spikes. You correctly identified them as nebular fine-structure
lines, cosmetic for broadband work. One clause at most.

**Flag as unresolved-then-resolved:** the per-object vs count contradiction first appears
here (line 4406). Present it as the puzzle it was; the resolution is the scatter finding
from the August work.

### Act 6 (July–Aug): making it quantitative
**Motivation.** Show the diagnosis is right by fixing the SED shape at fixed `L_IR` and
scoring against published counts.

**Found:**
- ALESS/FSPS hybrids move the bright 350/500 µm counts the right way. Rest-frame
  implementation verified: FSPS integral / stored `L_IR` = 0.999994.
- Modified blackbody grid (20–50 K, beta=1.8): best at **35 K**. Physically interpretable,
  and both resolved and P(D) count types prefer ~35 K independently.
- Leave-one-source-out: 25% ALESS chosen in every held-out run.
- The **area correction was critical** — 1.278 deg² (Farmer `FLAG_COMBINED`) not 2.0 deg²,
  a factor 1.56. With the wrong area the ranking reverses. Your note is the honest version:
  *"I need to settle the correct area before claiming template X is better."*
- Clean-independent source set (Valiante wide-area bright, Oliver mid-flux, Pearson XID deep)
  still prefers a 25–50% ALESS blend. Reduced chi-sq: 25% ALESS ~3.34 vs FSPS ~8.43.

**Narrative role.** This is Results proper. The MBB grid is the better story than the ALESS
mixing because a temperature is a physical parameter and a mixing fraction is not — even
though ALESS 25% scored marginally better (3.92 vs 4.50). Say that plainly.

Your conclusion is well put and should survive to the report: *"the answer seems to be
somewhere between FSPS and ALESS, not simply replacing FSPS with ALESS."*

**Figures (strong):**
- `popcosmos_mbb_temperature_grid_shapes.png` + `popcosmos_mbb_temperature_grid_counts.png` —
  the template experiment. **These two are the missing Fig 3** in the figure plan.
- `popcosmos_differential_count_area_corrected_overlay.png` — your original overlay. MAIN
  (superseded by the new version with residual panel, but the original is the honest
  ancestor).
- `popcosmos_differential_count_leave_one_source_out.png` — cross-validation. MAIN.
- `popcosmos_clean_independent_count_evaluator_heatmap.png` — APPENDIX.
- `external_spire_differential_counts_july21_3dex.png` — the compiled observational ruler.
  MAIN, probably as the Data section figure.
- `popcosmos_wang_jin_fsps_ratio_summary.png` — Wang/Jin/FSPS ratios. APPENDIX or Fig 7 support.

---

## Things in the log I would deliberately leave out

| item | why |
|---|---|
| Agentic pipeline / AlphaEvolve loop sketch | Scope creep; you already ruled it out |
| Nebular line spikes at 30–100 µm | Diagnosed as cosmetic |
| Radio and X-ray dataset survey (VLA, Chandra) | Belongs to the abandoned scope; one sentence in scoping |
| 1/Vmax mass-function attempt | Abandoned before producing anything |
| Spec-z benchmarking setup | Never completed, field missing from local files |
| Rodighiero optical/NIR stress test | Superseded by the direct SFR comparison |
| Early Wang starburst-fraction numbers (0.02%) | Known artifact; would confuse a reader |

---

## Recurring caveats to state once, in Methods

These appear repeatedly in the log and an examiner will look for them:
1. Wang is an XID+ prior-based deblended catalogue, not a corrected count product. Use it
   for per-object work only.
2. Wang faint-flux underestimation: ~10% at 250 µm, ~15% at 350, ~25% at 500.
3. SNR>3 removes <3% at 20 mJy but much more at faint fluxes and long wavelengths.
4. The 1.278 deg² area, and why 2.0 deg² was wrong.
5. IMF conventions: Kennicutt is Salpeter, convert to Chabrier explicitly. Your own rule —
   *"I am not going to mix IMF conventions silently"* — is worth stating.
6. SPIRE counts at 350/500 µm in the 5–50 mJy range can be biased high by ~2x from blending
   (SIDES / Béthermin).

---

## How this maps onto the report

Suggested shape, with the earlier acts compressed but present:

1. **Introduction** — obscured star formation; pop-cosmos; the energy-balance gap (Boris's
   point, in your words); counts as the statistic; scope narrowing.
2. **Data** — model outputs; the nine published count tables and independence criteria;
   Wang and Jin as per-object references.
   *Figure: compiled external counts.*
3. **Methods** — flux prediction; template families (ALESS hybrid, MBB grid, Casey);
   the evaluator, error floor, block bootstrap; the caveat list above.
   *Figure: MBB template shapes.*
4. **Results**
   - 4.1 Validation where the model was trained (IRAC, compressed to a paragraph).
   - 4.2 First far-IR attempt and why single-band correlations mislead (short).
   - 4.3 The count comparison: the headline result.
   - 4.4 The cause: SED shape and the wavelength ladder.
   - 4.5 The template experiment: MBB 35 K, hybrids, degeneracy.
   - 4.6 The scatter finding (August work).
   - 4.7 Robustness: bootstrap, leave-one-out, area sensitivity, source-selection sensitivity.
5. **Discussion** — two independent problems; what counts can and cannot constrain; the
   ~30 mJy reliability ceiling in a COSMOS-sized field; comparison to Schreiber+2017.
6. **Conclusions** — against the aims; recommendations to the pop-cosmos team.

The strongest single narrative device available: **open the Results with the IRAC agreement,
then immediately show the count mismatch.** Same model, same pipeline, one regime works and
one does not. That contrast does more work than either result alone.
