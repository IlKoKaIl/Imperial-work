# Viva preparation

Deck: [Pop-Cosmos Thesis Viva Presentation](https://docs.google.com/presentation/d/15WvfGK206IasnRL8tsbf1KktDqq8Nwm65yEeE2bEl2c/edit)

Main talk: slides 1-22. Slides 23-26 are backup material for questions.

Target speaking time: about 12.5-13.5 minutes. Slides 11-12 and 17-18 are quick progressive reveals, not four separate long explanations. This leaves at least a minute of safety inside the 15-minute limit.

Useful timing checkpoints:

- Reach the analysis pipeline on slide 7 at about 3 minutes.
- Reach the headline count result on slide 12 at about 6 minutes.
- Reach the fixed-LIR intervention on slide 15 at about 8 minutes.
- Reach the scatter explanation on slide 18 at about 10.5 minutes.
- Start the recommendation on slide 21 by about 12 minutes.

## One-sentence thesis

pop-cosmos extrapolates into the right broad FIR regime, but its dust SED is too cold, too uniform and too scattered to reproduce observed 250-500 um galaxy populations accurately.

## Three conclusions to remember

- Baseline FSPS overpredicts published counts in the main 30-100 mJy range by about 1.7x at 250/350 um and 3.6x at 500 um.
- Low-AGN model galaxies peak near 126 um at LIR = 10^12 Lsun, rather than the observed relation near 92 um, and the model misses the observed luminosity-temperature trend.
- Warmer FIR shapes improve the counts, but several different templates work similarly. This identifies the direction of the correction, not a unique final dust model.

## Numbers worth knowing

| Quantity                       | Value                                  |
| ------------------------------ | -------------------------------------- |
| Full pop-cosmos catalogue      | 429,669 galaxies                       |
| Effective Farmer area          | 1.278 deg^2                            |
| Calibration wavelength range   | about 0.3-4.5 um                       |
| FIR validation bands           | 250, 350, 500 um                       |
| Main comparison range          | 30-100 mJy                             |
| Baseline excess in that range  | 1.7x, 1.7x, 3.6x                       |
| Full-score median residuals    | +0.25, +0.41, +0.55 dex                |
| Low-AGN z <= 2 physical sample | 2,805 galaxies                         |
| Peak at LIR = 10^12 Lsun       | model 126 um, observed 92 um           |
| Matched model scatter          | about 0.42-0.51 dex                    |
| Wang-Jin scatter               | about 0.12-0.15 dex                    |
| Independent-field bootstrap    | +0.29 dex, interval +0.16 to +0.52 dex |

## Short definitions

**SED**

The amount of energy a galaxy emits as a function of wavelength.

**LIR**

The total infrared luminosity integrated over 8-1000 um. It fixes the total infrared energy, not where in wavelength that energy appears.

**Flux density**

The brightness received at Earth in a particular observing band, usually measured here in mJy.

**Differential counts**

The surface density of sources in a flux interval. dN/dS is counts per sky area per flux density.

**Euclidean normalisation**

Multiplying dN/dS by S^2.5 flattens the simple non-evolving Euclidean expectation. It changes the display, not the underlying count information.

**P(D)**

Probability of deflection. It uses the distribution of map-pixel brightness values to infer counts below the individual-source confusion limit.

**Energy balance**

Energy absorbed from stellar light by dust is re-emitted in the infrared. This constrains total LIR but does not uniquely constrain dust temperature or SED shape.

**Dex**

A base-10 logarithmic difference. +0.30 dex is about a factor of 2, +0.55 dex is about a factor of 3.5, and -0.30 dex is about half.

## Likely viva questions

### What kind of ML model is pop-cosmos?

It is a probabilistic generative population model. A score-based diffusion model learns the joint distribution of redshift and galaxy physical parameters. An emulator of a 16-parameter FSPS model generates SEDs and photometry, and optimal transport compares simulated and observed catalogues during calibration. I did not retrain that model in this project. I validated and perturbed its FIR output.

### Why use observed counts instead of SFR or LIR?

Published SFR and LIR values already depend on templates, priors, IMF choices and timescales. Counts stay closer to the observed fluxes and avoid comparing one model-derived physical estimate with another.

### Why differential instead of cumulative counts?

Cumulative N(>S) bins reuse the same bright sources at every threshold, so their errors are strongly correlated. Differential bins are cleaner for comparing shapes and localising the flux range of a mismatch, although adjacent differential bins can still share systematics.

### Why is the dust too cold if LIR is correct?

LIR fixes the area under the infrared SED. A cold SED puts more of that fixed energy at longer wavelengths. It can therefore overproduce 350 and 500 um flux without changing total LIR.

### Does a warmer template solve the model?

It improves the mean count mismatch, but not uniquely. Different warmer templates score similarly, and the large per-object scatter remains. A physical galaxy-dependent dust family is still needed.

### Why not train the template on all count data?

That risks fitting survey-specific corrections and cosmic variance. A stronger design tunes on one independent field or survey family, then evaluates on held-out fields.

### Is the chi-square formal?

No. Published bins within a survey share calibration, completeness and deblending corrections, and full covariance matrices are generally unavailable. The score is useful for ranking controlled variants, but the median log residual and independent-field block bootstrap are the safer headline summaries.

### Why were Wang raw counts low?

An early plot used 2.0 deg^2 rather than the 1.278 deg^2 Farmer footprint. Correcting this raises the surface density by 1.56x. The remaining difference is expected because Wang and Jin are prior-selected deblended catalogues, not published completeness-corrected population count products. They are better used for matched-object tests.

### Could Wang deblending cause the model scatter?

It cannot explain most of it. Wang and Jin agree with each other to roughly 0.12-0.15 dex, while pop-cosmos differs from either catalogue by about 0.42-0.51 dex.

### Could AGN cause the cold-dust count excess?

The hot branch is strongly AGN-associated, but the cold and flat luminosity-peak relation remains in the low-AGN sample. AGN is a separate modelling issue rather than the full explanation for the population count excess.

### Could gravitational lensing explain the bright-end mismatch?

No. Lensing raises observed bright counts. Removing lensed objects would lower the observed curve and make the model overprediction worse. It matters for interpreting the sparsest bright bins, but not as a solution.

### Why do published plots use points but the model uses lines?

Each published point represents one finite flux bin with an uncertainty. The model catalogue can be evaluated over many closely spaced bins or interpolated, so it is drawn as a continuous curve.

### Are the error bars percentiles?

No. They are the published count uncertainties, which can include Poisson noise, completeness, flux boosting and field-to-field effects depending on the paper. The model line has no plotted observational error bars.

### Why not integrate the full SPIRE bandpass?

This work samples the nominal band-centre wavelength consistently for every SED. It is adequate for this first population-level diagnosis, but full transmission-curve integration is a clear precision improvement for later work.

### Why use median posterior parameters?

They were the available catalogue product and are adequate for a first population test. The weakness is that a median can be misleading for bimodal parameters such as fAGN. Propagating full posterior samples is the correct next step, especially for the AGN and extreme-SFR tails.

### What is genuinely new in this thesis?

The work turns an optical-calibrated population model into testable FIR observed quantities, builds a consistent external count benchmark, identifies a wavelength-dependent count excess, ties it to an overly cold and uniform FIR SED, resolves the apparent count-versus-object contradiction through scatter, and proposes a concrete physical extension.

## Caveats to say plainly

- The alternative SEDs are diagnostic interventions, not proof that ALESS, MBB or Casey is the correct universal model.
- The count covariance is incomplete, so the rough chi-square is not a formal likelihood.
- Wang and Jin share the COSMOS field and related priors, so their agreement is a deblending control rather than an independent sky test.
- The AGN analysis uses fitted posterior medians, not external AGN confirmation.
- The brightest bins contain few objects and are sensitive to cosmic variance and lensing.
- Nominal SPIRE wavelengths were sampled instead of integrating the full bandpasses.

## Backup slides

### 23. Backup divider

Skip this during the main talk. It marks the end clearly if the deck is left open during questions.

### 24. Raw Wang counts

Use if asked why the early Wang curve looked low. The initial 2.0 deg^2 normalisation underestimated surface density. Using the 1.278 deg^2 Farmer footprint raises it by a factor of 1.56. The remaining difference reflects prior selection and incomplete population-count corrections, which is why Wang and Jin are used primarily for matched-object residuals.

### 25. Lensing and the Valiante bright end

Use if asked whether gravitational lensing explains the bright excess. Lensing raises observed bright counts, so removing lensed sources would lower the observed curve and worsen the model overprediction. The Valiante uptick is present in the published table, but sparse objects and large uncertainties prevent a strong wavelength-trend claim.

### 26. Redshift-resolved excess

Use if asked which epoch drives the discrepancy. The dominant contribution shifts toward higher redshift with longer observed wavelength. Present this as a localisation diagnostic, not proof that the redshift distribution itself is wrong.

## Delivery reminders

- Practise once without stopping and once with a timer.
- Treat slides 11-12 and 17-18 as two builds. Do not restart the explanation after advancing.
- Aim to reach slide 12 by about 6 minutes and slide 18 by about 10.5 minutes.
- Do not explain every point or curve. State what the axes mean, identify the relevant curve, then give the conclusion.
- Pause after the 1.7x and 3.6x result. It is the main observational result.
- If a question is unclear, restate what you think is being asked before answering.
- If you do not know, say what is known, identify the missing information, and describe the test you would run.

## Rapid implementation answers

Use these if a question moves from the scientific result to how it was coded.

### How did the FSPS SED become an observed SPIRE flux?

For each galaxy and observed band, I calculated the corresponding rest-frame wavelength as
the observed wavelength divided by one plus redshift. I log-interpolated the galaxy's stored
FSPS luminosity density at that wavelength, used the WMAP9 luminosity distance, and converted
the result to observed flux density in mJy. The 19 GB SED file was processed in batches of
2,048 rows and the compact predictions were cached. I sampled the nominal 250, 350 and
500 um wavelengths rather than integrating the full filter transmission curves.

### Where did the SED information come from?

The large HDF5 product supplied by Boris contains the common rest-frame wavelength grid,
the attenuated FSPS SED for each galaxy, LIR, redshift, catalogue index, source row and model
parameters. The wavelength grid was converted from Angstroms to micrometres by dividing by
10,000. The median parameter column, index 2, was used where posterior summaries were needed.

### How were number counts calculated?

I placed predicted fluxes into the same flux bins as the published data. The number in each
bin was divided by the bin width and catalogue sky area to obtain differential counts. I then
multiplied by flux to the power 2.5 to match the Euclidean-normalised form used by the papers.
This rescaling makes the count shape easier to see but does not add information.

### Why is the model a line while observations are points?

Each observed point is one published finite flux bin with a quoted uncertainty. The synthetic
catalogue can be counted on a finer grid, so its prediction is joined into a curve. The line
does not mean that the model is known without uncertainty.

### How were the ALESS hybrids constructed?

The empirical ALESS shape and each FSPS SED were placed on the same rest-frame wavelength
grid and normalised consistently to the galaxy's existing LIR. I mixed their luminosity-density
shapes at 25, 50 and 75 percent ALESS contribution, then redshifted the result and recalculated
the SPIRE fluxes. Redshift, population weights and total LIR were not changed.

### What did the modified-blackbody test change?

It replaced the FIR shape with a simple temperature-controlled curve while keeping LIR fixed.
Temperatures from 20 to 50 K were tested at an assumed emissivity index of 1.8. It was a
diagnostic of whether dust temperature is the useful physical lever, not a complete dust model.

### How were Wang and Jin matched?

Wang sources with positive COSMOS2020 Farmer identifiers were matched to the pop-cosmos
catalogue by identifier. Jin uses COSMOS2015 identifiers, so the COSMOS2020 Farmer bridge
column was used first, with a coordinate match within one arcsecond as a sanity check. Sky
area is irrelevant for the per-object flux ratios because the same galaxies are compared.

### What is the object residual and scatter?

The residual is log base ten of predicted flux divided by observed flux. Zero is perfect,
negative means the model is too faint, and positive means it is too bright. The median gives
the systematic offset. The 16th to 84th percentile half-width gives the observed scatter.
The median catalogue flux-error contribution was converted to log units and removed in
quadrature to quote the noise-deconvolved scatter.

### Why can the typical galaxy be too faint while counts are too high?

The per-object residual distribution is broad and the underlying population contains many more
faint galaxies than bright galaxies. More common faint galaxies are therefore moved into the
model-bright tail than rare bright galaxies are moved out. At 500 um and a 20 mJy threshold,
the model predicts 422 bright objects, Wang measures 134, and only 21 are bright in both.
Call this Eddington-like redistribution, not pure measurement-noise Eddington bias and not
Malmquist bias.

### What exactly does the block bootstrap do?

It treats Valiante, Oliver and Pearson as three complete independent survey-family blocks.
New three-block combinations are repeatedly sampled with replacement, so a survey may appear
more than once or be absent, and the median model-to-observation offset is recalculated. The
horizontal range contains the middle 95 percent of those resampled offsets. The green band on
slide 20 is different. It is the measured 0.12 dex inter-survey scatter, not the bootstrap
range or a confidence interval. Because only three independent blocks exist, the bootstrap is
a robustness check rather than precise probability calibration.

### What does slide 20 establish?

Only the baseline FSPS claim is said to have the same positive direction. Its full bootstrap
range is above zero, from about plus 0.16 to plus 0.52 dex, so no one survey family creates the
overprediction. Alternative SED models appear on both sides of zero. Their position shows
whether they overpredict or underpredict, and closeness to zero is better.

### Is Wang-Jin agreement visible on slide 17?

No. Slide 17 plots Wang flux against the pop-cosmos prediction. The Wang-Jin statement comes
from the separate matched-catalogue analysis, where their scatter is about 0.12 to 0.15 dex,
compared with about 0.42 to 0.51 dex between pop-cosmos and either catalogue. Backup slide 24
shows their raw count curves, but it is not the direct object-level scatter result.

### What does fAGN mean here?

AGN is the physical active galactic nucleus. fAGN is the fitted model parameter controlling
the AGN contribution to the SED. A high value means the fitted model assigns more emission to
the AGN component. It is not an independently observed AGN flag or an AGN probability. In the
available catalogue I calculated fAGN by exponentiating the stored lnfAGN posterior median.

### What would the proposed extension actually do?

It would keep the learned optical population and the energy-balance estimate of total LIR,
but replace the nearly fixed FIR bump with a galaxy-dependent physical dust family. Dust
temperature and warm-dust contribution could vary with luminosity and other galaxy properties.
One independent survey family could constrain those settings, while other sky fields test
whether both number counts and individual flux residuals improve out of sample.

## Wording traps

- Say that the dust is too cold and too uniform in the low-AGN sample. Do not claim every
  individual galaxy is too cold.
- Say that warmer templates identify the direction of improvement. Do not claim that counts
  uniquely select ALESS, a modified blackbody or the Casey-inspired curve.
- Say that the block-bootstrap range is descriptive. Do not present it as a well-calibrated
  formal 95 percent confidence interval based on only three independent blocks.
- Say that Wang and Jin control for catalogue extraction in the same COSMOS field. They are
  not independent sky surveys.
- Distinguish the two main failures. The mean FIR shape is too cold, while broad per-object
  scatter separately inflates the bright tail. Changing only the mean template cannot solve
  both.
