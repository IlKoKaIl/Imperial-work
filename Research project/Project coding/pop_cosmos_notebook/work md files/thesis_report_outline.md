# Thesis Report Outline

## Layperson's Summary: Writing Guide

This is a guide for writing the one-page layperson's article, not text to paste directly into
the report. The final version should be written in my own voice.

### Requirements from the report guidance

- Maximum one A4 page and fewer than `700` words.
- Aim at a typical A-level student: scientifically interested, but not an astronomer.
- Give the article its own engaging title.
- Focus on this specific project, not only general galaxy astronomy.
- Include the motivation, what I did, the main results and why they matter.
- Avoid specialist jargon. Explain any unavoidable technical term immediately.
- Write like a short popular-science article rather than a compressed abstract.
- References in the text are discouraged. Institutions or named projects can be mentioned.
- A figure can help, but it must be discussed in the text, remain legible and have a source in
  the caption if it is not my own.

Target about `500-600` words if using a figure, or `600-650` without one. This leaves space
for the title, caption and normal page margins.

### Possible titles

Choose something concrete and accurate rather than using the full technical thesis title:

- **When virtual galaxies shine too brightly**
- **Testing a simulated universe in hidden light**
- **What infrared light reveals about virtual galaxies**
- **Looking beyond visible light to test a galaxy model**

The first is the strongest popular-science title because it introduces the result without
requiring technical language.

### One-sentence message to build around

> I tested whether a model of nearly half a million galaxies, built mainly from visible and
> near-infrared observations, could correctly predict far-infrared light that it had not seen;
> it produced too many bright long-wavelength sources because its dust emission was too cold
> and its predictions varied too much from galaxy to galaxy.

Do not necessarily use this exact sentence. It is the logic every paragraph should support.

## Suggested Article Structure

### 1. Opening hook: galaxies hidden by dust (`60-80` words)

Start with a physical picture rather than the model name.

Points to convey:

- Much of a galaxy's young starlight is hidden by interstellar dust.
- The dust absorbs that light, warms up and re-emits the energy in the infrared.
- Looking only at visible light is therefore like judging a city while much of it is hidden
  behind fog.
- The wavelength at which the dust shines most strongly tells us about its temperature.

Possible opening direction: ask how we know a simulated galaxy is realistic when much of its
light emerges beyond human vision.

Avoid beginning with acronyms, catalogue names or a definition of galaxy evolution.

### 2. Why the model matters (`70-100` words)

Introduce pop-cosmos only after the reader understands the physical problem.

Explain:

- Modern surveys contain so many galaxies that astronomers need computer-generated galaxy
  populations to interpret them.
- `pop-cosmos` is a model that creates a statistical population of galaxies whose properties
  resemble the COSMOS survey.
- It was fitted mainly using optical and near-infrared light, up to about `4.5 micrometres`.
- My question was whether it remains reliable much farther into the infrared, at
  `250-500 micrometres`, where cool dust dominates.

Plain-language definition if needed:

> A micrometre is one millionth of a metre; the exact scale matters less here than the fact
> that the test wavelengths are tens to hundreds of times longer than those used to fit the
> model.

### 3. What I did (`90-120` words)

Describe the method as a fair prediction test, not as a list of software operations.

Core steps:

1. Start with the model galaxies and their predicted infrared energy and distance.
2. Use each galaxy's model spectrum to predict how bright it would look to Herschel at
   `250`, `350` and `500 micrometres`.
3. Count how many predicted galaxies fall into each brightness range.
4. Compare those predictions with published, completeness-corrected counts from real
   Herschel surveys covering several regions of the sky.
5. Keep the total infrared energy fixed while trying warmer alternative dust spectra. This
   isolates the distribution of the infrared light from the total amount of energy.

Useful plain-language replacement:

- Instead of "differential number counts," say "the number of galaxies found in each
  brightness range and area of sky."
- Instead of "SED," say "spectrum" or "how a galaxy's energy is spread across wavelengths."

Mention that the model first passed a control test close to the wavelengths used to fit it.
This makes the far-infrared failure a targeted result rather than evidence that the whole
pipeline is broken.

### 4. Main findings (`150-190` words)

This should be the longest part of the article. Present two linked but distinct findings.

#### Finding A: the dust spectrum is too cold

- The baseline model predicts too many galaxies in real far-infrared brightness bins.
- The mismatch is mildest at `250 micrometres` and strongest at `500 micrometres`.
- In the reliable `30-100 mJy` range, the baseline predicts about `1.7 times` too many sources
  at 250 and 350 micrometres and about `3.6 times` too many at 500 micrometres.
- The model dust emission typically peaks near `136 micrometres`.
- For a luminous galaxy of `10^12` solar luminosities, observations predict a peak near
  `92 micrometres`. A longer-wavelength peak means colder dust.
- Real observations also show more luminous galaxies becoming warmer. The model relation is
  almost flat, so it misses this luminosity-temperature trend.

The simple causal chain to explain:

> dust that is too cold shifts too much energy to long wavelengths, making too many model
> galaxies appear bright in the 350 and 500 micrometre bands.

#### Finding B: there is too much galaxy-to-galaxy scatter

- Individual predicted fluxes are spread widely around the measurements.
- Faint galaxies greatly outnumber bright ones, so even a modest fraction scattered upward
  can overfill the bright bins.
- Warmer spectra improve the average counts but do not remove this object-level scatter.

Do not call the two effects identical. The dust shape explains the wavelength trend; the
scatter is a second failure in how flux is assigned to individual galaxies.

### 5. What the modification showed (`60-90` words)

Explain the extension experiment without claiming a final dust model:

- I kept each galaxy's total infrared energy unchanged.
- I redistributed that energy using warmer empirical and simplified dust spectra.
- Intermediate warmer spectra matched the published counts much better than either the cold
  baseline or the hottest alternative.
- This shows the direction in which pop-cosmos should be improved.
- The available counts do not uniquely choose one dust model, so do not call a particular
  template the final answer.

### 6. Significance and final sentence (`70-100` words)

Return to the larger motivation:

- A model can reproduce the data used to build it while failing when asked to predict a new
  kind of light.
- Testing observed quantities outside the training range exposed physics that optical and
  near-infrared fitting could not constrain.
- A future version should allow dust temperature to depend on galaxy luminosity or
  compactness and carry the uncertainty in far-infrared predictions forward.
- This would make synthetic catalogues more reliable for interpreting obscured star formation
  and planning future infrared surveys.

End on the general lesson, not a list of limitations. Possible direction:

> Looking beyond the light used to build a model is not only a test of whether it works; it
> can reveal which missing physics needs to be added next.

## Figure Recommendation

### Best option: one new simplified project figure

Do not use the full six-panel evaluator plot in the lay summary. It contains specialist axes,
many templates and several survey datasets, which will consume space and be difficult for an
A-level reader.

Make one simple two-part figure later:

- **Left:** two infrared spectrum shapes at the same total energy, showing that the baseline
  peak lies at a longer wavelength than the warmer alternative. Label the direction "colder"
  and "warmer."
- **Right:** three bars showing the baseline excess in the `30-100 mJy` range:
  `1.7x` at 250, `1.7x` at 350 and `3.6x` at 500 micrometres.

Suggested caption idea:

> **The model assigns too much energy to long wavelengths.** Left: a colder infrared
> spectrum peaks farther to the right even when the total emitted energy is unchanged. Right:
> the baseline pop-cosmos prediction increasingly overestimates the number of real sources at
> longer wavelengths. Figure created from this project's model predictions and published
> Herschel source counts.

The article text must explicitly point the reader to the figure and say what they should
notice. If there is no time to make a genuinely simple figure, omit it rather than shrinking
one of the technical thesis plots until its labels are unreadable.

### Existing figures that can supply the data

- `../fir_validation_aug2026/figures/popcosmos_count_overlay_thesis.png`: count excess and
  wavelength trend.
- `../fir_validation_aug2026/figures/drew_casey_peak_relation.png`: missing observed
  luminosity-temperature relation.
- `../fir_validation_aug2026/figures/fsps_fir_sed_diagnostic.png`: distribution of model dust
  peaks.

These are useful source material, but none is ideal unchanged for a one-page outreach article.
An outside telescope image would look attractive but would add less explanatory value. If
one is used, it needs a credited source and should not replace the project result figure.

## Language Guide

| Avoid or define            | Plain-language version                                      |
| -------------------------- | ----------------------------------------------------------- |
| SED                        | spectrum; how energy is spread across wavelengths           |
| differential number counts | number of galaxies in each brightness range and area of sky |
| FIR/submillimetre          | far-infrared light from cool dust                           |
| flux density               | observed brightness in one wavelength band                  |
| energy balance             | dust re-emits the energy it absorbed from starlight         |
| dex                        | give the ordinary multiplicative factor instead             |
| posterior median           | the central model estimate                                  |
| FSPS                       | the baseline stellar and dust spectrum used by pop-cosmos   |
| model scatter              | predictions varying widely around the measured values       |

Use short sentences and active verbs: "I predicted," "I compared," "the model produced." A
small amount of first person is useful because this is an article about a specific research
project.

## Claims and Details to Leave Out

- Do not describe the work as validating radio or X-ray predictions. The completed report
  scope is FIR/SPIRE.
- Do not say the model was trained on the SPIRE measurements. They are an out-of-sample test.
- Do not claim energy balance or the total `L_IR` was independently validated.
- Do not say a particular ALESS, Casey or modified-blackbody template is the true dust model.
- Do not quote a measured Casey `alpha` or emissivity `beta`; `beta = 1.8` was fixed.
- Do not call all nine count tables independent. They reduce to three main independent
  survey/sky families, with the rest used as robustness checks.
- Do not lead with the sparse `>100 mJy` bins. Use the cleaner `10-100 mJy` range.
- Do not claim Wang and Jin are independent observations. They are different reductions of
  the same COSMOS maps.
- Do not introduce chi-square, P(D), XID+, Eddington bias, gravitational lensing or the AGN
  posterior unless absolutely needed. They belong in the technical report.
- Do not imply that warmer templates solve the per-object scatter problem.
- Do not overstate certainty. Use "suggests," "supports" and "points toward" where the result
  identifies a direction rather than a unique physical model.

---------------------------------------------------------------------------------------------------

# Technical Report: Section-by-Section Writing Guide

This is a planning document, not text to paste directly into the report. The final report
should be written in my own voice and should read as one argument rather than as a diary of
everything attempted.

## Report Rules and Drafting Order

### Requirements from the final-report guidance

- Use A4, one column, 12-point type and margins of at least 2 cm.
- The assessed word count is `8,000-10,000` words and must not exceed `10,000`.
- The title page, lay summary, contents, acknowledgements and bibliography are excluded from
  the word count. The abstract, captions and appendices are included.
- Aim for roughly `25-30` pages including figures and tables.
- Write for a physicist who is not an expert in galaxy SED fitting. Define field-specific
  language the first time it appears.
- Figures need readable axes and captions that explain both what was done and what the reader
  should notice.
- Methods must be reproducible, and the report must discuss uncertainties, selection effects,
  biases and limitations rather than only showing successful plots.
- The report should critically assess the modelling/statistical techniques used. A score alone
  is not a physical explanation.

### Suggested word budget

| Part                          | Working target |
| ----------------------------- | -------------: |
| Abstract                      |        200-300 |
| Introduction                  |    1,200-1,500 |
| Data                          |      800-1,000 |
| Methods                       |    1,300-1,600 |
| Results                       |    2,300-2,700 |
| Discussion                    |    1,300-1,600 |
| Conclusions                   |        400-600 |
| Captions and small appendices |        500-800 |

This gives room to land near `8,500-9,500` words without having to cut the central Results
argument at the end.

### Best drafting order

1. Write Data and Methods while the implementation details are fresh.
2. Write Results around the final figure order.
3. Write Discussion once the claims and caveats are fixed.
4. Write the Introduction to lead directly to the question the completed work actually answers.
5. Write Conclusions, then the Abstract.
6. Generate the contents page and final word count last.

So yes: leave the **Abstract until later**. Its job is to summarise the finished report, and it
is much easier to write accurately once the Results and Conclusions are stable.

## Front Matter

### Title page

Include the exact items requested by the course guidance:

- final project title;
- project code;
- my name and CID;
- supervisor and assessor names;
- final report word count;
- submission date;
- Imperial College London logo, if the template expects it. Do not use the College crest.

Working title:

> **Testing pop-cosmos Beyond Its Training Wavelengths: Far-infrared Galaxy Counts and Dust
> Spectral Energy Distributions**

This is more accurate than retaining radio and X-ray in the title when those extensions were
not completed.

### Abstract - write after Conclusions

Target `200-300` words in one self-contained paragraph or a small number of paragraphs.

Build it from five pieces:

1. **Context:** population models connect galaxy physics to large photometric surveys.
2. **Gap:** pop-cosmos is constrained mainly over `0.3-5 um`, so its far-infrared dust shape is
   an extrapolation even though energy balance fixes total infrared luminosity.
3. **Method:** turn model SEDs into observed SPIRE fluxes and compare differential counts and
   matched-object fluxes with published measurements at 250, 350 and 500 um.
4. **Main results:** give the two independent findings with one or two numbers: an overly
   cold/flat luminosity-peak relation and large per-object scatter that inflates bright counts.
5. **Conclusion:** warmer, luminosity-dependent dust shapes improve the population counts, but
   a template replacement alone does not fix the scatter.

Normally omit citations and figures from the abstract. Do not introduce results that are not
demonstrated in the main report.

### Contents

Generate this automatically after all headings are fixed. Use no more than three heading levels
in the contents page; the detailed planning headings in this file do not all need to survive.

---

# 1. Introduction: Writing Guide

**Purpose:** lead a non-specialist physicist from obscured star formation to one precise
question: how reliable are pop-cosmos predictions when extended into far-infrared wavelengths
that did not constrain the original model?

**Target:** `1,200-1,500` words. Do not turn this into a complete literature review.

## 1.1 Why far-infrared light matters

Explain in this order:

- Young stars emit ultraviolet/optical light.
- Interstellar dust absorbs some of it, warms up and reradiates the energy in the infrared.
- Far-infrared measurements therefore recover star formation that optical surveys can miss.
- The cosmic infrared background shows that obscured emission is a major part of the energy
  released over cosmic history.
- Herschel and its SPIRE instrument made large surveys at 250, 350 and 500 um possible.

Useful citations:

- `Dole_2006` for the cosmic infrared background and the importance of obscured emission.
- `Pilbratt_2010` for the Herschel observatory.
- `Griffin_2010` for SPIRE and its three bands.

Define `SED` here as the distribution of a galaxy's energy over wavelength. Define `flux density` as brightness measured in one observing band. Save detailed equations for Methods.

## 1.2 From individual galaxies to population models

Cover the following:

- Surveys such as COSMOS combine many wavelength bands over the same area of sky
  (`Scoville_2007`).
- SED-fitting tools infer quantities such as stellar mass, star-formation rate, dust attenuation
  and redshift from photometry. FSPS and Prospector provide relevant modelling context
  (`Conroy_2009`; `Leja_2017`).
- pop-cosmos goes beyond fitting one object at a time: it learns a probabilistic population
  distribution and can generate a synthetic catalogue with correlated galaxy properties
  (`Alsing_2024`; `Thorp_2024`).
- This makes it useful for survey simulation and forecasting, but also makes out-of-sample
  validation important: a plausible catalogue in the fitted bands is not automatically correct
  at unseen wavelengths.

Give the reader one compact paragraph on **how pop-cosmos works**, rather than only naming it:

1. It describes the joint distribution of galaxy redshift and physical parameters using a
   flexible score-based diffusion model. This allows correlated properties such as stellar
   mass, star-formation history, metallicity, dust attenuation and AGN contribution to be drawn
   together rather than from unrelated one-dimensional distributions.
2. A 16-parameter stellar-population-synthesis model converts each parameter vector into a
   rest-frame SED and photometry.
3. A survey data model adds calibration effects, photometric uncertainties and the same
   selection applied to COSMOS2020.
4. Synthetic and observed 26-band catalogues are compared using an optimal-transport distance,
   allowing the population and nuisance models to be calibrated together.

The important output for this thesis is therefore not simply a best-fitting curve. It is a
synthetic galaxy population in which every object has a redshift, physical parameters and a
predicted SED. Keep the mathematical details of diffusion training and optimal transport short;
the original pop-cosmos papers contain the full derivation (`Alsing_2024`; `Thorp_2024`). The
reader mainly needs to understand what was learned, what was generated and why an out-of-range
FIR prediction can still fail.

## 1.3 The far-infrared extrapolation problem

This is the key conceptual paragraph of the Introduction.

- The COSMOS photometry used to constrain pop-cosmos mainly reaches the IRAC range, roughly
  `0.3-5 um` in this project.
- Energy balance can fix the integrated dust luminosity `L_IR`: energy absorbed at short
  wavelengths is reradiated by dust.
- Energy balance does **not** uniquely specify where within `8-1000 um` that energy appears.
  Dust temperature and the detailed dust model control the SED peak and therefore the flux in
  each SPIRE band.
- The baseline FSPS implementation uses a restricted Draine and Li-style dust prescription
  (`Draine_2007`). Its far-infrared shape is therefore a model assumption rather than a direct
  COSMOS constraint.

This distinction prevents a common logical mistake: the thesis is not simply testing whether
the total infrared energy is sensible. It is testing whether the model distributes that energy
correctly over wavelength and over the galaxy population.

## 1.4 Why use observed number counts

Explain why the main comparison moved to number counts:

- Converting observed flux to SFR or `L_IR` introduces another SED model into the real data.
- Differential counts instead ask how many galaxies occur in each observed flux interval per
  unit sky area. They are close to the raw observable and can be compared across fields.
- Counts in separate flux bins are easier to compare statistically than cumulative counts,
  whose errors are correlated by construction.
- Euclidean-normalised counts, `S^2.5 dN/dS`, flatten the broad trend so differences in shape
  can be seen. Define this carefully in Methods rather than deriving it here.
- Herschel counts are affected by confusion, completeness, flux boosting and source blending,
  so published corrected counts are preferable to counting entries in a raw catalogue.

Useful citations:

- resolved counts: `Clements_2010`, `Oliver_2010`, `Valiante_2016`, `Pearson_2025`;
- fluctuation/P(D) counts below the individual-source limit: `Glenn_2010`, `Varnish_2025`;
- confusion and prior-based deblending: `Nguyen_2010`, `Roseboom_2010`, `Hurley_2017`.

## 1.5 Aim, questions and scope

State one main aim:

> Assess whether pop-cosmos can reproduce observed far-infrared galaxy populations beyond the
> wavelength range that constrained the model, and identify which physical/model assumptions
> drive any mismatch.

Turn it into three questions:

1. Does the baseline model reproduce published 250, 350 and 500 um differential counts?
2. If not, can the mismatch be linked to the model's far-infrared SED shape and its treatment of
   dust temperature?
3. Are count errors explained only by the average SED shape, or is there also too much
   object-to-object flux scatter?

End with a one-paragraph roadmap: Data, conversion to flux/counts, tests with alternative SED
families, physical diagnosis, then implications. Explicitly say the final scope is FIR/SPIRE;
radio and X-ray were possible extensions but are not claimed as completed validation.

### Introduction figure

A figure is optional. A simple original schematic could show:

`optical/near-IR fitted range -> energy balance fixes L_IR -> uncertain FIR shape -> SPIRE test`

Do not use a dense Results figure in the Introduction. If no clear schematic is made, use the
space for the causal explanation instead.

### Introduction checks

- [ ] The scientific motivation arrives before pop-cosmos implementation details.
- [ ] `SED`, `L_IR`, flux density and number counts are defined once.
- [ ] The fitted wavelength range and tested wavelength range are clearly separated.
- [ ] The problem is framed as validation, not as training a new ML model.
- [ ] The final paragraph contains explicit questions that Results later answer.

---

# 2. Data: Writing Guide

**Purpose:** identify exactly which model products and observations enter each analysis, their
selection, units and independence.

**Target:** `800-1,000` words plus one dataset table.

## 2.1 pop-cosmos catalogue and generated SEDs

Record enough detail to make the sample reproducible:

- the pop-cosmos catalogue release/model version and parent COSMOS field;
- number of generated objects used after each basic quality cut;
- fields used: redshift, object index, model parameters, `wave_rest`, `spec_attenuated` and
  stored `L_IR`;
- that the analysis uses central/median parameter estimates rather than full posterior draws;
- the supplied FSPS SED products and `fsps_lir_scalars.h5`, with credit to Boris where needed;
- wavelength units and conversion from Angstrom to micrometres;
- catalogue sky area used when turning synthetic objects into counts.

Then explain exactly **how these products were used in this project**:

1. Start from the stored central/median-style parameter vector and FSPS SED for each galaxy.
2. Use the stored redshift to move that SED into the observed frame and predict fluxes at the
   SPIRE wavelengths.
3. Count the generated objects in observed-flux bins and divide by the model catalogue area.
4. Compare those predictions with published corrected counts and, separately, with
   position-matched Wang/Jin fluxes.
5. In controlled experiments, keep each object's redshift and total `L_IR` fixed while replacing
   only the FIR SED shape. This isolates the effect of dust shape from changing the overall
   infrared luminosity or the learned galaxy population.

### Clarify the three uses of "percentile"

The report must keep these separate:

- **Posterior percentile for one galaxy:** `mcmc_summaries.h5` stores five marginal summaries
  for each parameter of each galaxy. The 50th percentile is the central estimate used in most
  analysis; it is not an average over galaxies. Confirm the exact ordering of all five columns
  with Boris before labelling them as 5/16/50/84/95 in the final report.
- **A galaxy at an `L_IR` percentile:** an example labelled 10th, 50th or 90th percentile in an
  SED diagnostic is one object selected near that position in the population's luminosity
  distribution. The 50th-percentile object is simply a median-luminosity example, not a median
  SED.
- **A population percentile band:** a median curve with a 16th-84th percentile envelope is
  calculated across many galaxies at each plotted wavelength or within each analysis bin. It
  describes galaxy-to-galaxy spread, unless the caption explicitly says it comes from posterior
  draws or bootstrap repeats.

`fsps_map_median_full.h5` contains one 16-parameter `theta` vector and one SED per galaxy. The
five marginal percentiles are not joint posterior samples and do not preserve correlations
between parameters. Do not imply the full posterior was propagated. Using the supplied central
SEDs is acceptable for this validation, but it may hide multimodality, particularly in the AGN
parameter.

Useful citations: `Alsing_2024`, `Thorp_2024`, `Thorp_2025_insights`, `Conroy_2009`.

## 2.2 Published SPIRE differential counts

Create one compact dataset table with columns:

`reference | field/sky area | bands | extraction method | flux range | role in this thesis`

Primary independent survey families:

- **Valiante et al. / H-ATLAS:** three wide GAMA fields, strong bright-count constraint;
- **Oliver et al. / HerMES:** separate multi-tier Herschel fields, useful middle-flux range;
- **Pearson Dark Field XID:** a deep North Ecliptic Pole field, useful faint resolved counts.

Robustness/overlap tables:

- Clements H-ATLAS SDP counts overlap the H-ATLAS family;
- Glenn and some Oliver/HerMES measurements overlap the HerMES family;
- Pearson SUSSEXtractor and XID use the same Dark Field maps;
- Varnish P(D) uses the central region of the same Dark Field.

This is why nine tables can be plotted but should not be treated as nine independent
experiments. The clean scorecard should use one representative from each independent sky/survey
family; the others test sensitivity to extraction method and depth.

Useful citations: `Valiante_2016`, `Oliver_2010`, `Pearson_2025`, `Clements_2010`,
`Glenn_2010`, `Varnish_2025`.

For Valiante specifically, record that Tables 5, 8 and 9 give inversion-corrected counts in the
GAMA9, GAMA12 and GAMA15 fields, covering about `161.6 deg^2` in total. Their quoted errors do
not include covariance between flux bins. This information is needed both for the main model
comparison and for the separate bright-bin uptick discussed later.

Suggested figure:

- `../outputs/external_spire_differential_counts_july21_3dex.png`

Use it to show wavelength and flux coverage, not to claim every coloured series is independent.

## 2.3 Wang and Jin COSMOS catalogues

Explain their separate role:

- Wang is a probabilistic, prior-based deblended COSMOS catalogue (`Wang_2024`; `Hurley_2017`).
- Jin is a super-deblended catalogue over the same general COSMOS field (`Jin_2018`).
- They provide object-level fluxes and uncertainties, useful for residual and scatter tests.
- They are **not independent sky fields**, and their raw catalogue entries are not substitutes
  for published completeness-corrected number-count tables.
- Use the appropriate valid areas for each catalogue/selection; do not apply one area to both by
  habit.

The Wang/Jin comparison is valuable because their agreement is much tighter than either
catalogue's agreement with pop-cosmos. That helps localise the large per-object scatter to the
model rather than one deblending pipeline.

## 2.4 Data-quality and selection limits

State before Results:

- which SNR cut is used for object-level comparisons and why;
- that published counts already include survey-specific completeness/reliability corrections;
- why the main quantitative count claim focuses on approximately `10-100 mJy`;
- why bins above about `100 mJy` need caution because of small numbers, lensing and a limited
  COSMOS area;
- that P(D) counts are statistical constraints below the source-detection limit and are not
  individual catalogued galaxies.

Useful citations: `Nguyen_2010`, `Clements_1999`, `Roseboom_2010`, `Glenn_2010`.

---

# 3. Methods: Writing Guide

**Purpose:** show how model spectra become observed fluxes and counts, and define the tests
before presenting which model performs best.

**Target:** `1,300-1,600` words. Put lengthy conversion checks in an appendix.

## 3.1 From a rest-frame SED to an observed flux

Describe the pipeline in physical order:

1. Select the galaxy's rest-frame attenuated FSPS SED and redshift.
2. Convert wavelength units consistently.
3. Evaluate the rest-frame luminosity density corresponding to an observed SPIRE wavelength,
   accounting for `(1+z)`.
4. Convert luminosity density to observed flux density using the luminosity distance and the
   required redshift factor.
5. Report flux density in mJy.

Include the actual equation and define every symbol and unit. State the cosmology used for
luminosity distance.

Important limitation: the current calculation samples/interpolates at the nominal SPIRE
wavelength rather than integrating the redshifted SED through the full instrument response.
Explain why this is adequate for a first population comparison and why bandpass integration is
a clear future improvement.

Reproducibility checks to mention:

- the integrated FSPS `8-1000 um` luminosity agrees with stored `L_IR` to about `0.999994` in
  the rest-frame hybrid check;
- all template variants are renormalised to the same `L_IR`, so their comparison changes shape,
  not total infrared energy.

When a median population SED is shown, state its construction separately: select the population,
place all SEDs on the same rest-frame wavelength grid, apply the stated normalisation, then take
the pointwise median and 16th-84th percentiles. This is different from plotting the single
galaxy whose `L_IR` happens to be at the 50th percentile.

## 3.2 Constructing differential number counts

Define:

- `S`: observed flux density in Jy or mJy;
- `dN/dS`: number of sources per flux interval per solid angle;
- `S^2.5 dN/dS`: Euclidean-normalised differential count;
- `deg^-2` and `sr^-1`, including the conversion `1 sr = (180/pi)^2 deg^2`;
- how model catalogue counts are divided by the catalogue area;
- how flux-bin widths enter `dN/dS`.

State that Euclidean normalisation is only a rescaling for visual comparison; it does not add
new galaxies or alter the ranking if applied consistently. Published values were converted to
the common unit `Jy^1.5 deg^-2` before plotting.

## 3.3 Alternative far-infrared SED families

Separate the experiments from the final physical interpretation:

- **FSPS baseline:** the existing pop-cosmos/FSPS dust shape.
- **ALESS:** an empirical average SED of luminous submillimetre galaxies
  (`Swinbank_2013`). It is a useful warm-shape bracket, not a universal galaxy model.
- **Rest-frame hybrids:** combine luminosity-density shapes on a common rest-frame grid and
  renormalise the result to the original galaxy `L_IR`. Do not describe a mixture of already
  observed count curves as a physical hybrid.
- **Modified blackbody grid:** vary dust temperature while fixing emissivity index `beta=1.8`.
  State that beta is assumed, not measured by the evaluator.
- **Casey-style model:** modified blackbody plus a mid-infrared power law (`Casey_2012`). Treat
  it as a diagnostic parameterisation, not a complete grain-physics replacement.

Suggested Methods figure:

- `../outputs/popcosmos_mbb_temperature_grid_shapes.png`

Its caption should say that the curves are deliberately normalised to equal integrated
`L_IR`, so it isolates where the same energy appears in wavelength.

## 3.4 Count evaluator and error treatment

Describe the evaluator as a **comparison tool**, not an ML model and not a training loop:

1. Interpolate each model count curve to the published flux points within their shared range.
2. Compare in logarithmic count space so fractional differences matter across the dynamic
   range.
3. Use published errors, with a stated dex error floor to prevent unrealistically tiny quoted
   uncertainties from dominating.
4. Sum the squared normalised residuals and report the rough reduced chi-square or median
   residual.

Report scorecards on a common point set. The current unified run has:

- `174` points across all nine published tables;
- `74` points in the cleaner three-family evaluation.

Explain that these are **table rows/flux bins**, not numbers of galaxies. Many bins share maps,
calibration and completeness corrections, so their covariance is not fully known. For that
reason:

- use median log residual as the most transparent primary summary;
- use reduced chi-square as a rough ranking diagnostic rather than a formal likelihood;
- repeat the conclusion with a larger error floor or source-family bootstrap;
- do not infer a uniquely correct dust model from the minimum score.

## 3.5 Object-level residuals and the scatter test

For position-matched Wang/Jin objects:

- define residual `log10(F_model/F_observed)`;
- use an explicit SNR threshold for reliable observed fluxes;
- report the median offset and robust 16-84 or MAD scatter;
- compare model-vs-Wang, model-vs-Jin and Wang-vs-Jin;
- test several SNR thresholds to see whether observational noise drives the scatter.

Then explain the count-promotion diagnostic: select model objects predicted above a flux cut and
ask how many are also observed above it. This reveals asymmetric upward scattering in a steep
source distribution. Call this an Eddington-like count effect; distinguish it from Malmquist
bias (`Clements_1999`).

## 3.6 Physical diagnostics

Two methods connect the count mismatch back to galaxy physics:

- measure each low-AGN model SED's far-infrared peak and compare `lambda_peak` against `L_IR`
  with the observed Drew and Casey relation (`Drew_2022`);
- split count residuals by redshift to test where the excess occurs in each SPIRE band.

State sample cuts, AGN threshold and fitted wavelength interval. The AGN parameter is a model
component fraction, not an AGN probability. Note that posterior medians may evade a bimodal
population prior; using full posterior draws is a valuable but potentially substantial extension
(`Thorp_2025_insights`).

---

# 4. Results: Writing Guide

**Purpose:** present observations in a deliberate order, with interpretation kept brief until
Discussion. Each subsection should answer one question and point to one main figure.

**Target:** `2,300-2,700` words.

## 4.1 Control test where the model is constrained

Start with IRAC Ch1/Ch2 to establish that the catalogue and comparison pipeline are not failing
everywhere.

Report:

- Ch1: `N=423,272`, median residual `+0.020 mag`, MAD `0.084 mag`;
- Ch2: `N=414,272`, median residual `-0.012 mag`, MAD `0.041 mag`;
- Ch3/Ch4 have lower coverage and are weaker controls.

Suggested figure:

- `../outputs/popcosmos_irac_redshift_histograms.png`

Main claim: pop-cosmos agrees well where the input photometry constrains it; the later FIR
mismatch is wavelength-dependent, not a universal catalogue failure.

## 4.2 Published far-infrared number counts

This is the headline observational result.

Suggested figure:

- `../fir_validation_aug2026/figures/popcosmos_count_overlay_thesis.png`

Describe what is plotted before interpreting it: published differential count points with
uncertainties, baseline FSPS curve, three SPIRE panels and a residual/ratio summary.

Report the robust `30-100 mJy` summary used in the lay section:

- baseline excess approximately `1.7x` at 250 um;
- `1.7x` at 350 um;
- `3.6x` at 500 um.

Also report the full independent-source median residuals if they remain in the final unified
scorecard: `+0.25`, `+0.41`, `+0.55 dex` at 250, 350 and 500 um. Make clear that the two summaries
use different pooling/ranges rather than presenting them as contradictory numbers.

The visual/empirical claim belongs here. The reason for it belongs in later subsections.

## 4.3 The baseline SED is too cold and too uniform

Use the independent SED-shape comparison rather than relying only on template scores.

Main figure:

- `../fir_validation_aug2026/figures/drew_casey_peak_relation.png`

Report:

- Drew and Casey find `lambda_peak = 92 um` around `L_IR=10^12 L_sun` and a negative slope,
  meaning more luminous systems are warmer (`Drew_2022`);
- low-AGN pop-cosmos objects peak around `126 um` at that luminosity;
- the model slope is nearly flat (`eta about +0.005`) rather than `-0.09 +/- 0.01`;
- the model also has an unusually narrow range of peak wavelengths.

The key result is not only a normalisation offset. The missing luminosity dependence means the
bright, luminous population remains too cold, exactly where long-wavelength counts are most
sensitive.

Supporting figures, probably appendix:

- `../fir_validation_aug2026/figures/fsps_fir_sed_diagnostic.png`
- `../outputs/popcosmos_full_sed_median_sfr_seds.png`

## 4.4 Controlled template experiments

Ask whether moving the fixed `L_IR` to warmer wavelengths changes the counts in the expected
direction.

Possible main/supporting figures:

- `../outputs/popcosmos_mbb_temperature_grid_shapes.png`
- `../outputs/popcosmos_mbb_temperature_grid_counts.png`
- the model-family curves in
  `../fir_validation_aug2026/figures/popcosmos_count_overlay_thesis.png`

Report that warmer ALESS/FSPS hybrids and an approximately `35 K` modified blackbody improve the
count comparison. Then immediately state the limit: several shapes score similarly within
inter-survey scatter, so counts identify a needed warmer/luminosity-dependent direction but do
not uniquely select a dust prescription.

Do not make the Casey alpha grid a central Results section unless it supplies a conclusion that
the simpler temperature experiment cannot. It is better placed in an appendix as a useful
parametric sensitivity test.

## 4.5 Per-object scatter is a second problem

Main figure:

- `../fir_validation_aug2026/figures/scatter_mechanism_explained.png`

Explain its panels in the caption and text:

- individual predicted and measured fluxes show intrinsic scatter of roughly `0.44-0.54 dex`;
- the measured source population falls steeply toward high flux;
- therefore many more common faint objects scatter upward across a bright threshold than rare
  bright objects scatter downward;
- among `422` galaxies predicted above `20 mJy`, only `21` are observed above that threshold;
  `401` are promoted by model scatter.

This resolves the apparent paradox that matched detections can have faint median model fluxes
while the full model catalogue still produces too many bright sources. A warmer mean template
can move the counts, but it does not by itself remove this object-to-object scatter.

Optional explanatory figure:

- `../fir_validation_aug2026/figures/paradox_resolution.png`

Use only one of these in the main report if they make the same argument.

## 4.6 Where the excess occurs in redshift

Suggested figure:

- `../fir_validation_aug2026/figures/z_resolved_fir_diagnosis.png`

Report the band-dependent localisation:

- much of the 250 um excess is at lower redshift, roughly `z<1`;
- the 500 um excess moves toward `z about 1.5-2.5`.

This is expected because the same observed band samples different rest-frame wavelengths as
redshift changes. Do not collapse this into one universal "bad redshift".

## 4.7 Observational side result: the Valiante bright-end uptick

Include this as a short, clearly labelled side finding. It is not evidence that pop-cosmos is
correct or incorrect; it is an unexpected feature found while checking the observational ruler
and is scientifically worth reporting.

Suggested figure:

- `../code python files/outputs/valiante_2016_hatlas_dr1_number_counts_quicklook.png`
- or the more interpretive `../fir_validation_aug2026/figures/lensing_bright_end_assessment.png`
  if only one can be included.

Explain the calculation:

- each point is a published Valiante flux bin, not an individual galaxy or a median object;
- the three GAMA fields were area-weighted using the published field areas;
- the rise is present directly in Tables 5, 8 and 9 and is therefore not introduced by the
  pop-cosmos evaluator or by a later unit conversion;
- the final `300 mJy` bin is higher than the `244.2 mJy` bin by about `2.75x`, `2.53x` and
  `2.17x` at 250, 350 and 500 um respectively;
- relative to a local bright-bin trend, the uptick is strongest statistically at 250 um and
  weakest at 500 um. Do not claim a significant wavelength trend: the three ratios are
  consistent within their uncertainties.

Safe interpretation:

- Valiante discuss larger field-to-field differences at the brightest fluxes and associate
  them with cosmic variance (`Valiante_2016`).
- Rare nearby galaxies, small-number statistics, lensing, binning and the inversion/correction
  procedure are all plausible contributors.
- Lensing may contribute, but a roughly 20% lensed fraction near the relevant bright regime is
  too small by itself to create a factor-of-two-to-three rise.
- Correlations between adjacent count bins are not included in the quoted table uncertainties,
  so the simple significance estimate should not be treated as a formal independent-bin test.

Use this result to motivate caution above roughly `100 mJy` and to show that validating the
observational inputs was part of the work. Keep it to a short subsection so it enriches rather
than interrupts the central pop-cosmos argument.

## 4.8 Robustness and alternative explanations

Keep this compact and organise it by question:

1. **Could one count survey drive the result?** Use the clean independent-family evaluator and
   block/source bootstrap. Suggested figure:
   `../fir_validation_aug2026/figures/bootstrap_forest_plot.png`.
2. **Could the Wang deblending be responsible for the scatter?** Wang and Jin agree with each
   other to about `0.12-0.15 dex`, while pop-cosmos scatters by about `0.42-0.51 dex` against
   either. Put the detailed ratio plot in an appendix.
3. **Could SNR selection explain it?** State whether the scatter remains under SNR cuts of
   3, 5, 7 and 10.
4. **Could AGN dominate the cold-dust result?** Show that the peak-relation result is measured
   on a low-AGN sample; discuss the AGN issue separately rather than mixing it into every plot.
5. **Could lensing dominate?** Restrict the central claim to the better-populated flux range and
   treat the sparse very bright bins, including the Valiante uptick, as a limitation/side
   finding rather than the main model constraint.

Appendix candidates:

- `../outputs/popcosmos_clean_independent_count_evaluator_heatmap.png`
- `../outputs/popcosmos_wang_jin_fsps_ratio_summary.png`
- `../outputs/popcosmos_differential_count_leave_one_source_out.png`
- `../fir_validation_aug2026/figures/lensing_bright_end_assessment.png`

### Results writing rule

For every subsection use this order:

1. state the question;
2. describe sample/axes/statistic;
3. report the result with uncertainty or scale;
4. give one sentence of immediate meaning;
5. defer broader physical claims to Discussion.

---

# 5. Discussion: Writing Guide

**Purpose:** turn the Results into a physical explanation, test alternatives, and say exactly
what should change in pop-cosmos.

**Target:** `1,300-1,600` words.

## 5.1 A coherent explanation for the count excess

Join the two independent lines of evidence:

- the observed `L_IR-lambda_peak` relation says luminous galaxies should be warmer;
- pop-cosmos is colder and nearly luminosity-independent;
- at fixed `L_IR`, a colder SED puts more power on the long-wavelength side of the peak;
- this raises 350/500 um fluxes and moves too many objects into bright count bins.

This is stronger than saying "ALESS fits better" because the mechanism is supported by an
observed physical relation (`Drew_2022`) and predicts the direction of the count error.

Compare with temperature evolution/SED literature where useful: `Schreiber_2017`,
`Draine_2007`, `Casey_2012`.

## 5.2 A mean SED correction is not the whole solution

Treat per-object scatter as a second failure mode:

- mean SED shape controls the location of the population count curve;
- excessive object-level scatter controls how galaxies leak between flux bins;
- because the underlying distribution is steep, unbiased scatter can still inflate the bright
  tail;
- changing one average template can improve counts while leaving individual predictions poor.

This distinction gives the thesis a more useful recommendation than simply replacing FSPS with
ALESS.

## 5.3 What the template tests do and do not establish

Say explicitly:

- ALESS and the MBB/Casey grids are controlled interventions at fixed `L_IR`.
- Their improvement shows that SED shape/temperature is an important lever.
- Similar count scores do not prove those models are physically equivalent.
- Broadband counts alone cannot uniquely determine grain composition, geometry, AGN heating,
  temperature distributions and redshift evolution.
- A Draine and Li parameter grid or a CIGALE-style comparison would be more physically grounded
  future work, but it is not necessary to claim that the baseline treatment is inadequate.

## 5.4 AGN and posterior limitations

Discuss the unusual mid-infrared SEDs and the pop-cosmos AGN component without letting this
overtake the FIR story:

- high model `f_AGN` is associated with hot mid-infrared emission;
- it is a fitted component fraction, not a probability that an object hosts an AGN;
- the low-AGN restriction makes the cold peak result harder to dismiss as torus contamination;
- the underlying AGN prior can be bimodal (`Thorp_2025_insights`), so evaluating only posterior
  medians may conceal uncertainty or mode switching;
- full posterior predictive SEDs are the principled extension if those draws become available.

## 5.5 Observational and modelling limitations

Give each limitation its likely effect, not just a list:

- **Bandpass approximation:** nominal-wavelength sampling may shift detailed fluxes; full filter
  convolution would improve accuracy.
- **Published-count covariance:** flux bins and tables sharing maps are not independent; this is
  why chi-square is used as a rough score and the three-family comparison is primary.
- **Confusion/deblending:** affects faint SPIRE sources, but Wang/Jin agreement indicates it
  cannot explain most model scatter (`Nguyen_2010`; `Wang_2024`; `Jin_2018`).
- **Small COSMOS area:** gives weak statistics for very bright/lensed sources.
- **Posterior medians:** ignore parameter uncertainty and non-Gaussian/bimodal posteriors.
- **Empirical template scope:** ALESS represents luminous submillimetre galaxies and is not a
  universal template (`Swinbank_2013`).
- **No full retraining:** the experiments replace or perturb the FIR extension after inference;
  they do not refit the population prior jointly with FIR data.

Add a brief discussion of the Valiante uptick here. The useful conclusion is not that its cause
has been solved, but that the feature survives direct checks of the published tables and all
three GAMA fields. It illustrates why the sparse bright end should not dominate model ranking,
why published-bin covariance matters, and why cosmic variance, lensing and local populations
must be considered before assigning every feature in a count plot to pop-cosmos physics.

## 5.6 Recommendations and future work

Prioritise actions that follow directly from the findings:

1. Allow dust-heating/temperature parameters to vary and introduce an observed
   `L_IR-lambda_peak` dependence instead of one effectively fixed cold shape.
2. Validate posterior-predictive flux scatter, not only mean counts.
3. Convolve spectra with actual survey bandpasses.
4. Use full posterior draws to propagate SED, redshift and AGN uncertainty.
5. Calibrate on one set of independent survey fields and validate on held-out fields before any
   recursive/evaluator-led optimisation.
6. Extend the same observed-space framework to radio and X-ray only after the FIR story is
   closed.

The recommendation to the pop-cosmos team should be concrete: preserve the useful population
model and energy balance, but make the far-infrared shape luminosity-dependent and explicitly
test its predictive scatter.

---

# 6. Conclusions: Writing Guide

**Purpose:** answer the three Introduction questions directly. Add no new evidence or citation
thread.

**Target:** `400-600` words.

Suggested structure:

1. One sentence restating the aim and why it matters.
2. One short paragraph on the successful IRAC control.
3. One short paragraph on the published-count mismatch and wavelength trend.
4. One short paragraph on the physical diagnosis: cold normalisation plus missing
   luminosity-temperature slope.
5. One short paragraph on the second problem: excessive per-object scatter and count promotion.
6. Final recommendation and broader implication for extrapolating generative population models
   beyond their constraining data.

End with the general lesson, not a list of future coding tasks: physically coherent latent
parameters do not guarantee reliable observables outside the training wavelength range, so
out-of-sample validation must test both distributions and individual predictions.

### Conclusion checklist

- [ ] Every stated aim from Introduction receives an answer.
- [ ] Numbers match the final unified Results tables.
- [ ] Template improvement is not presented as a unique physical solution.
- [ ] No radio/X-ray validation is claimed.
- [ ] No new figure, method or caveat is introduced.

---

# Back Matter

## Acknowledgements

Thank supervisors and anyone who supplied code/data or gave substantial technical input. Credit
Boris for the pop-cosmos/FSPS products and Dave/Boris for scientific guidance without assigning
them responsibility for the conclusions. Follow any course wording required for computational
tools and generative AI.

## Bibliography

Use one canonical file:

- `../fir_validation_aug2026/latex/references.bib`

`references_2.bib` was checked against this file and contained no unique citation keys, so it
does not need to remain as a second source. Before submission:

- remove or ignore unrelated entries from other projects;
- replace placeholder notes with verified volume/page/DOI information;
- standardise escaped accents and micrometre symbols;
- ensure every citation in the text appears in the bibliography and every printed reference is
  cited;
- read any paper used for an important physical claim beyond its abstract.

## Appendices

Use appendices to protect the main narrative, not to store every exploratory plot.

Possible structure:

- **Appendix A: count compilation and unit conversions** - source tables, conversion between
  mJy/Jy and sr/deg2, and independent-family classification.
- **Appendix B: evaluator robustness** - all-source heatmap, clean-source table, error-floor
  sensitivity, leave-one-source-out and bootstrap.
- **Appendix C: object-level and AGN diagnostics** - Wang/Jin comparison, SNR cuts and high/low
  AGN median SEDs.
- **Appendix D: alternative SED experiments** - ALESS variants, MBB grid details and Casey
  parameter scans.
- **Appendix E: secondary checks** - lensing bright end, early LIR/SFR plots and internal FSPS
  consistency checks if they are cited in the main report.

Appendices count toward the report word limit. Link to the code/data repository for full
machine-readable outputs instead of pasting large code listings.

---

# Main Figure Plan

Aim for about `7-9` main figures. Extra diagnostics belong in appendices.

| Order | Figure                                                                             | Main purpose                                                |
| ----: | ---------------------------------------------------------------------------------- | ----------------------------------------------------------- |
|     1 | `../outputs/external_spire_differential_counts_july21_3dex.png`                  | Observational count coverage and the external ruler         |
|     2 | `../outputs/popcosmos_irac_redshift_histograms.png`                              | Control: agreement in constrained IRAC bands                |
|     3 | `../fir_validation_aug2026/figures/popcosmos_count_overlay_thesis.png`           | Headline 250/350/500 um count mismatch                      |
|     4 | `../fir_validation_aug2026/figures/drew_casey_peak_relation.png`                 | Physical diagnosis: wrong peak and missing luminosity trend |
|     5 | `../outputs/popcosmos_mbb_temperature_grid_shapes.png` plus selected count panel | Controlled warmer-template experiment                       |
|     6 | `../fir_validation_aug2026/figures/scatter_mechanism_explained.png`              | Second finding: scatter promotes faint objects              |
|     7 | `../fir_validation_aug2026/figures/z_resolved_fir_diagnosis.png`                 | Redshift localisation of the excess                         |
|     8 | `../fir_validation_aug2026/figures/bootstrap_forest_plot.png`                    | Robustness across independent survey families               |
| 9 (optional) | `../code python files/outputs/valiante_2016_hatlas_dr1_number_counts_quicklook.png` or lensing assessment | Observational side finding: verified bright-bin uptick |

Before fixing this list, check whether Figure 1 and Figure 8 repeat information that can be
reported in a table. A figure should carry an argument, not merely prove that a calculation was
run.

# Citation Map

| Topic                             | Starting references                                                                                       |
| --------------------------------- | --------------------------------------------------------------------------------------------------------- |
| CIB and obscured star formation   | `Dole_2006`                                                                                             |
| Herschel and SPIRE                | `Pilbratt_2010`, `Griffin_2010`                                                                       |
| COSMOS                            | `Scoville_2007`                                                                                         |
| pop-cosmos                        | `Alsing_2024`, `Thorp_2024`, `Thorp_2025_insights`                                                  |
| FSPS/Prospector                   | `Conroy_2009`, `Leja_2017`                                                                            |
| Physical dust model               | `Draine_2007`                                                                                           |
| FIR SED parameterisation          | `Casey_2012`                                                                                            |
| Observed luminosity-peak relation | `Drew_2022`                                                                                             |
| Dust-temperature trends           | `Schreiber_2017`                                                                                        |
| Published SPIRE counts            | `Clements_2010`, `Oliver_2010`, `Glenn_2010`, `Valiante_2016`, `Pearson_2025`, `Varnish_2025` |
| Confusion/deblending              | `Nguyen_2010`, `Roseboom_2010`, `Hurley_2017`                                                       |
| COSMOS FIR catalogues             | `Wang_2024`, `Jin_2018`                                                                               |
| ALESS empirical SED               | `Swinbank_2013`                                                                                         |
| Flux boosting/Eddington-like bias | `Clements_1999`                                                                                         |

# Final Report Checklist

- [ ] The report tells one story: constrained-band success, FIR failure, physical cause, second
  scatter failure, and a targeted model recommendation.
- [ ] Data, Methods, Results and Discussion do not repeat the same explanation verbatim.
- [ ] Every headline number is generated by the final consistent pipeline and traceable to a
  CSV/script.
- [ ] Main count claims use independent survey families; overlapping products are robustness
  checks.
- [ ] The three meanings of percentile are clear in text and captions.
- [ ] The Valiante uptick is reported as a checked observational side finding, not claimed as a
  pop-cosmos result or a solved lensing detection.
- [ ] Figure captions define the sample, axes, units, uncertainty and intended takeaway.
- [ ] Limitations say the likely direction or consequence of each issue.
- [ ] The total is below `10,000` assessed words, including captions and appendices.
- [ ] The Abstract is written last and agrees exactly with Conclusions.
- [ ] The final submitted wording is my own.
