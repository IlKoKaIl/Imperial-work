# pop-cosmos Supervisor Prep Tasks

## Task 1: Quantitative MS comparison to Speagle+2014

Method implemented in notebook:

- Speagle relation:
  - `log10 SFR(M*, t) = (0.84 - 0.026 t) log10 M* - (6.51 - 0.11 t)`
  - `t` is Universe age in Gyr (Giga year, 1 Billion)
  - Gives us the expected SFR for a galaxy given mass at a given cosmic time.
- Comparison sample:
  - finite values only
  - `log10sSFR_selected > -11`
  - `8.5 <= log10M_selected <= 11.5`
  - `0 <= z < 4`
- Residual used: If its 0, pop cosmos matches Speagle and +/- means pop cosmos predicts higher/lower SFR respectively
  - `Delta_MS = log10SFR_popcosmos - log10SFR_speagle`

Seeded run summary (`np.random.seed(7)`, `torch.manual_seed(7)`):

- Overall SF sample size: `N = 2155`
- Median `Delta_MS = -0.531 dex (dex is log10, so 10x so -0.53 is about 3x smaller)`
- Robust scatter `~ 0.460 dex`
- 16-84 half-width `~ 0.439 dex`

Per-redshift bins from notebook table:

- `[0.0, 0.5)`: `N=127`, median `Delta_MS=-0.682`, slope fit `1.018`, Speagle slope `0.596`
- `[0.5, 1.0)`: `N=547`, median `Delta_MS=-0.737`, slope fit `0.838`, Speagle slope `0.664`
- `[1.0, 2.0)`: `N=1023`, median `Delta_MS=-0.531`, slope fit `0.775`, Speagle slope `0.721`
- `[2.0, 3.0)`: `N=375`, median `Delta_MS=-0.283`, slope fit `0.720`, Speagle slope `0.769`
- `[3.0, 4.0)`: `N=83`, median `Delta_MS=-0.194`, slope fit `0.821`, Speagle slope `0.789`

Interpretation for discussion:

- Trend with mass and redshift is consistent with main seq behavior.
- Compared to Speagle’s expected SFR values, pop-cosmos sample gives lower SFR overall. The difference is biggest at low redshift, and it becomes smaller by around redshift 3.”.

## Task 2: Starburst definition applied to plot

Method implemented in notebook:

- Start bin: `1.0 <= z < 2.0`
- Starburst cut: `Delta_MS >= 0.6 dex` (relative to Speagle baseline)
- Plot added: non-starbursts (gray), starbursts (red), MS line, and `+0.6 dex` threshold line.

Measured how far each galaxy is above normal main seq line
`Delta_MS = log10SFR_galaxy - log10SFR_MS`

decided its starburst is >= 0.6dex (~4x greater)

run summary:

- In `1.0 <= z < 2.0`, `9 <= log10M <= 11.5`:

  - `N=791`, starbursts `N=5` (`0.63%` by number)
  - starburst SFR share `6.71%`

Interpretation for discussion:

* Starbursts are a **small fraction by number** (about **0.6%** in my run).
* But they still contribute a noticeable amount to total star formation (about **6–7%** SFR share in that bin).

## Task 3: What SFR means in each source

### pop-cosmos (Alsing+2024 / Thorp+2025)

- SFH is 7-bin piecewise-constant.
- First two bins fixed at `0-30 Myr` and `30-100 Myr`.
- Free SFH parameters are adjacent-bin SFR ratios `Delta log10(SFR)_k`.
- SFR definition (Thorp+2025 Appendix C):
  - `SFR/M_form = (M_form,1/M_form + M_form,2/M_form) / 0.1 Gyr`
  - i.e. SFR averaged over the latest 100 Myr.
- In this notebook:
  - `log10SFR_selected` = this 100 Myr-averaged absolute SFR in `Msun/yr`.
  - `log10sSFR_selected` is corrected to use mass remaining (`M_remain`) not mass formed.

### Speagle et al. (2014)

- Empirical, homogenized literature MS fit:
  - `log10 SFR(M*, t) = (0.84 - 0.026 t) log10 M* - (6.51 - 0.11 t)`.
- Not tied to one SPS model and not specifically the same 100 Myr SFH-bin definition.
- Reported intrinsic MS width is about `0.2 dex` after deconvolution.

### COSMOS2020 catalog SFR parameters (Weaver+2022 release docs)

- LePhare/BC03 columns at `zPDF`:
  - `lp_SFR_med`, `lp_SFR_best` (plus confidence limits)
  - based on BC03 templates, Chabrier IMF, BC03 tau+delayed SFHs.
- EAZY/FSPS columns:
  - `ez_sfr` (and percentiles)
- Important note in release docs:
  - LePhare SFR/sSFR are computed without IR, so uncertainties can be large.

## Feb 24, 2026 meeting follow-up

Notes from supervisor and actions:

Slope notes:

    At each redshift bin we fit`log10(SFR) = a log10(M*) + c`
    `slope_fit` = measured a from pop cosmos data in that bin
    `slope_speagle` = expected a from Speagle at that bin's median redsfhit/time

    So if slope fit is close to speagle they match well.

### 1) Add visual Speagle comparison plot (not only summary numbers)

Currently:

- have quantitative comparison numbers from Task 1:
- `N = 2155`
- median `Delta_MS = -0.531 dex`

to add:

- Make a direct visual plot in the same style as the existing `log10(SFR)` vs `log10(M*)` plot, but with Speagle as reference.
- Recommended figure setup:
  - keep pop-cosmos points/background as before
  - overplot Speagle MS as one or more lines (at representative redshifts, or in the selected redshift bin)
  - optionally add `pop-cosmos - Speagle` residual coloring for quick visual offset check

Goal:

- Easy side-by-side visual comparison with the previous MS plot, not just table/stat outputs.
- Added a new Task 1 visual cell in `catalogue_generation.ipynb`:

  - `Task 1 visual: pop-cosmos vs Speagle in 1 <= z < 2`
  - Uses the same `log10(SFR)` vs `log10(M*)` plane, with:
    - pop-cosmos density (hexbin)
    - Speagle MS line at median redshift of the bin
    - pop-cosmos best-fit line for direct visual comparison

explanation:

- We now have a picture where the old galaxy cloud and the Speagle “expected trend line” are in the same graph.
- This makes it easy to see by eye whether our galaxies mostly sit above, below, or on the reference line.
- In short: this is the visual version of the `Delta_MS` numbers.

### 2) Starburst test with larger mock sample

Issue in current run:

- In `1 <= z < 2` and `9 <= log10M <= 11.5`, only `5` starbursts were found.
- This is too small for stable tail/statistical interpretation.

What to add:

- Increase generated sample size (for example 5x to 10x more than 10,000 base samples).
- Re-run starburst classification (`Delta_MS >= 0.6`) and update:
  - starburst number fraction
  - starburst contribution to SFR
  - optional z~2 high-mass check

Goal:

- Improve tail statistics and reduce noise from small-number counts.

Status (implemented in notebook):

- Added a larger-sample rerun cell in `catalogue_generation.ipynb`:
  - `Task 2 rerun with larger sample size`
  - Runs starburst summary at `n_samples = 10,000`, `50,000`, and `100,000` with the same cuts/definition.

Latest rerun outputs:

- `10,000` samples:
  - `N(1<=z<2)=791`, `N_SB=5`, starburst fraction `0.632%`, starburst SFR share `6.710%`
  - `N(1.5<=z<2.5, M>=10)=126`, `N_SB=2`, fraction `1.587%`, SFR share `26.862%`
- `50,000` samples:
  - `N(1<=z<2)=3844`, `N_SB=12`, starburst fraction `0.312%`, starburst SFR share `6.041%`
  - `N(1.5<=z<2.5, M>=10)=632`, `N_SB=4`, fraction `0.633%`, SFR share `13.829%`
- `100,000` samples:
  - `N(1<=z<2)=7686`, `N_SB=20`, starburst fraction `0.260%`, starburst SFR share `7.280%`
  - `N(1.5<=z<2.5, M>=10)=1303`, `N_SB=9`, fraction `0.691%`, SFR share `12.821% (look at d.p accuracy)`

Quick read:

- Larger sample improved tail stability and reduced small-number noise, especially in the z~2 high-mass slice.

Brief explanation:

- With only a few starburst galaxies, percentages can jump around a lot.
- Increasing sample size gives us more rare objects in the tail, so the final percentages are more trustworthy.
- Here, the starburst counts increased from `5` (10k) to `20` (100k), and the SFR-share estimates became less noisy.

Matches literature ?

 **yes.., mostly consistent on SFR share; lower on number fraction**.

Source:

- arXiv: https://arxiv.org/abs/1108.0933

latest results:

- `(1 <= z < 2)`: starburst fraction `~sim 0.26%-0.63%`, SFR share `~6%-7%`
- 1.5 <= z < 2.5  fraction: ~0.63%-1.59%, SFR share ~13%-27%
  (100k run: 0.69%, 12.8%)

Literature target (Rodighiero+2011 at z~2, mass-selected SF sample:

- number fraction ~2%
- SFR density share <~ 10%

So:

- **SFR share:** at 100k value (~12.8% in the z~2 high-mass slice) is close-ish, slightly high.
- **number fraction:** at value (~0.7%) is lower than 2%

### Why not exact?

setup differs from that paper in several ways:

- different parent sample/selection (`Ch1<26`, pop-cosmos mock, spitzer/irac channel 1 ~3.6 micron near-IR on brighter than mag 26 galaxies in the band)
- different MS reference (Speagle baseline)
- your extra SF cuts and mass/redshift cuts are not exactly their selection pipeline
- finite-sample tail noise still matters, even at 100k

If we want a closer comparison, next step is: replicate their selection as closely as possible (their z range, mass completeness, SF selection, and MS definition), then recompute.

#### 3) What did Rodighiero+2011 do?

- Used **Herschel/PACS** data + optical/near-IR data in **COSMOS + GOODS-South**.
- Focused on **z = 1.5 to 2.5** (cosmic peak of star formation).
- Looked at **mass-selected star-forming galaxies**.
- Defined starbursts as galaxies with SFR **>4x above MS** (equivalent to `Delta_MS >= 0.6 dex`).
- Reported ``~2%`` by number and about ``~10%`` of SFR density at ``z~2``.

#### 4) Why our setup is not exactly the same (main differences)

- **Sample definition**:
  - Ours: pop-cosmos mock with `Ch1 < 26`
  - Paper: observed PACS-based sample in COSMOS/GOODS-S
- **MS reference**:
  - Ours: offset computed against **Speagle** relation (external baseline)

$$
\Delta MS = \log_{10}(\mathrm{SFR}_{\text{your galaxy}}) \;-\; \log_{10}(\mathrm{SFR}_{\text{Speagle}}(M, z))
$$

- Paper: MS defined from their own z~2 observed SFR-M* distribution
- **Cuts**:
  - Ours: global pre-cuts (`log10sSFR > -11`, `8.5<=logM<=11.5`, `0<=z<4`) + Task 2 bin cuts
  - Paper: their own star-forming/mass-complete cuts at z~2
- **SFR estimator origin**:
  - Ours: pop-cosmos model-derived SFR
  - Paper: observational SFR workflow tied to Herschel/PACS data

### 3) Open follow-up: wavelength dependence and external catalogs

Question to investigate:

- Are starburst conclusions changing because of wavelength coverage / selection?
- Need to trace what wavelength information the current SFR inference is sensitive to, and compare with longer-wavelength-selected catalogs.

where to go ?:

- Compare against longer-wavelength datasets (for example HERMES, H-ATLAS) after applying cuts to match pop-cosmos selection as closely as possible.
- Start with matched redshift and mass cuts, then compare starburst fraction and SFR contribution.

Brief motivation.

- Different telescopes see different parts of galaxy light.
- Dust can hide star formation in optical data, but infrared/sub-mm can reveal it.
- So we should check whether our starburst conclusion changes when we use catalogs that are more sensitive to dusty star-forming galaxies.

Data needs:

- Download external catalogs and prepare matched subsamples.
- If local files are not already available, provide/confirm data access location and preferred catalog versions.

#### Longer-wavelength expansion (new: where to get data + comparison plan)

Core equations for the comparison (use same definitions across datasets):

$$
\Delta_{\mathrm{MS}} = \log_{10}\!\big(\mathrm{SFR}_{\mathrm{gal}}\big) - \log_{10}\!\big(\mathrm{SFR}_{\mathrm{MS}}(M_\star,z)\big)
$$

$$
\text{Starburst if } \Delta_{\mathrm{MS}} \ge 0.6
$$

$$
f_{\mathrm{SB}}^{N} = \frac{N(\Delta_{\mathrm{MS}} \ge 0.6)}{N_{\mathrm{SF}}}
$$

$$
f_{\mathrm{SB}}^{\mathrm{SFR}} = \frac{\sum_{\Delta_{\mathrm{MS}} \ge 0.6}\mathrm{SFR}_i}{\sum_{\mathrm{SF}}\mathrm{SFR}_i}
$$

Optional IR conversion check (if catalogs provide total IR luminosity):

$$
\mathrm{SFR}_{\mathrm{IR}} \approx 10^{-10}\,L_{\mathrm{IR}} \quad (\text{in } M_\odot\,\mathrm{yr}^{-1} \text{ for } L_{\mathrm{IR}} \text{ in } L_\odot,\ \text{IMF-dependent})
$$

Plain-language meaning of the above:

- **Distance from the main sequence**

  $$
  \Delta_{\mathrm{MS}}
  $$

  measures “distance from the normal star‑forming trend.”
- **Starburst threshold**

  $$
  \Delta_{\mathrm{MS}} \ge 0.6
  $$

  means roughly

  $$
  \sim 4\times
  $$

  above that trend (starburst region).
- **Starburst fraction by number**

  $$
  f_{\mathrm{SB}}^{N}
  $$

  = “Out of all star‑forming galaxies, what percent are starbursts?”
- **Starburst fraction by SFR contribution**

  $$
  f_{\mathrm{SB}}^{\mathrm{SFR}}
  $$

  = “Out of total star formation, what percent is produced by starbursts?”

---

### Papers and likely data access points

1) **pop-cosmos: Star formation over 12 Gyr...**
   Link: https://arxiv.org/pdf/2509.20430
   Likely data path (pop-cosmos public releases):

- Galaxy posterior products: https://zenodo.org/records/17426655
- Mock catalogs: https://zenodo.org/records/15622325
- Code/tools: https://github.com/Cosmo-Pop

2) **ALPINE-ALMA [CII] survey: nature/LF/SFH of dusty galaxies up to z~6**
   Link: https://www.aanda.org/articles/aa/full_html/2020/11/aa38487-20/aa38487-20.html
   Useful catalog/data entry points:

- ALPINE products portal: https://cesam.lam.fr/a2c2s/
- ALPINE data-processing/catalog paper indicates CDS catalog access:
  http://cdsarc.u-strasbg.fr/viz-bin/cat/J/A+A/643/A2

3) **Ex-MORA survey (5 sigma source catalog and redshift distribution)**
   Link: https://arxiv.org/abs/2408.14546
   Current status:

- arXiv comment notes the fully reduced mosaic will be shared upon publication.
- For now, use source tables in paper/supplement and track publication repository link when posted.

---

### Short relevant notes from the 3 papers (simple terms)

1) **pop-cosmos: Star formation over 12 Gyr (arXiv:2509.20430)**

- Uses a deep IR-selected COSMOS sample and a generative SPS model.
- Reports SFRD peaking near

  $$
  z \approx 1.3
  $$
- Shows SF/Q classification can shift depending on whether you use

  $$
  \mathrm{sSFR}
  $$

  cuts or color cuts.
- Relevance for us:

  - solid pop-cosmos baseline for SFR/starburst comparisons.

2) **ALPINE continuum paper (A&A 2020, aa38487-20)**

- Characterizes 56 ALMA Band-7 serendipitous continuum sources in COSMOS/ECDFS.
- Derives IR luminosity functions and SFRD up to

  $$
  z \sim 6
  $$
- Finds dusty-obscured SF remains important at high redshift; UV/optical-only estimates can be lower.
- Reports a meaningful contribution from optically/near-IR dark sources at high

  $$
  z
  $$

  (e.g. contribution to high-z SFRD discussed in paper).
- Relevance for us:

  - direct long-wavelength benchmark for how much SF can be missed by optical/NIR selection.

3) **Ex-MORA (arXiv:2408.14546)**

- 2 mm ALMA blank-field survey in COSMOS-Web targeting dusty high-z systems.
- Reports a high-redshift-heavy sample with median around

  $$
  z \sim 3.6
  $$

  and many sources at

  $$
  z > 3
  $$
- Shows rest-optical methods miss a substantial fraction of dusty high-z galaxies.
- Relevance for us:

  - strong motivation to test starburst fractions under longer-wavelength selection.

---

### Practical methodology to compare with pop-cosmos

Step 1: Build a harmonized sample definition

- Match redshift bins first (for example

  $$
  1.5 \le z < 2.5
  $$

  and higher-z bins if needed).
- Apply a common mass floor where all datasets are reasonably complete.
- Keep a consistent star-forming selection rule across datasets.

Step 2: Harmonize SFR/Mass conventions

- Confirm Intial mass Function (IMF, implied dist of stellar masses when stars form) assumptions and convert if needed (Chabrier/Kroupa/Salpeter differences).
- Align stellar mass and SFR units/scales before computing offsets.
- Use one MS baseline consistently (e.g., Speagle or dataset-native MS), and report which was used.

Step 3: Compute the same summary metrics in each dataset

$$
f_{\mathrm{SB}}^{N} \quad \text{and} \quad f_{\mathrm{SB}}^{\mathrm{SFR}}
$$

- Median/dispersion of
  $$
  \Delta_{\mathrm{MS}}
  $$
- Optional: split by mass bins to check mass dependence of starburst incidence.

Step 4: Report wavelength-sensitive differences explicitly

- Compare optical/NIR-selected versus IR/sub-mm-selected samples at matched cuts.
- Flag where dusty systems appear in IR/sub-mm but are weak/missed in optical selections.

---

## First implemented comparison (pop-cosmos vs Wang 2024)

### Some motivation

Wang gives deblended far-IR/sub-mm photometry in COSMOS (24–850 µm).

* longer wavelengths are sensitive to dusty star formation.
* optical/NIR can miss dusty systems.
* we wanted to test if starburst fractions/SFR share change when looking at long-λ-detected subsamples.

So Wang is our first “longer-wavelength lens” on the same COSMOS population.

### Files used

- pop-cosmos:
  - `catalog data/real pop-cosmos data/mcmc_summaries.h5.gz`
  - `catalog data/real pop-cosmos data/README_v2_2_0.txt`
- Wang 2024:
  - `catalog data/wang/master.dat.gz`
  - `catalog data/wang/ReadMe.txt`

### Script walkthrough

- The script reads two catalogs:

  - pop-cosmos posterior summaries
  - Wang long-wavelength deblended catalog
- It keeps one representative value per pop-cosmos galaxy (median posterior).
- It matches galaxies between the two catalogs by shared COSMOS ID.
- It marks whether each matched galaxy is detected at long wavelengths (SPIRE/SCUBA) using SNR.
- It computes

  $$
  \Delta_{\mathrm{MS}} = \log_{10}\mathrm{SFR}_{\mathrm{pop}} - \log_{10}\mathrm{SFR}_{\mathrm{Speagle}}(M_\star,z)
  $$

  and flags starbursts with

  $$
  \Delta_{\mathrm{MS}} \ge 0.6.
  $$
- It then reports starburst fractions for:

  - all matched galaxies in each bin
  - long-

    $$
    \lambda
    $$

    detected subset
  - not-long-

    $$
    \lambda
    $$

    detected subset

### run notes

Method (first pass):

1. Decompress and load pop-cosmos summaries.
2. Use median posterior values (50th percentile) for:
   - $$
     \log_{10}M_\star,\ \log_{10}\mathrm{SFR},\ \log_{10}\mathrm{sSFR},\ z
     $$
3. Load Wang master catalog via CDS schema from `ReadMe.txt`.
4. Join on COSMOS ID:
   - pop-cosmos `index_farmer` ↔ Wang `ID`
5. Define long-wavelength detection flag:
   - SPIRE/SCUBA detected if any of

     $$
     250,350,500,850\,\mu\mathrm{m}
     $$

     has (singal to noise ratio = F_lambda/sigma_lamba)
     meaning measured flux density at given wavelenght/ uncertainty on that flux
     3 => flux is three times greater than noise

     $$
     \mathrm{SNR}\ge 3
     $$

     .
6. Compute:
   - $$
     \Delta_{\mathrm{MS}} = \log_{10}\mathrm{SFR}_{\mathrm{pop}} - \log_{10}\mathrm{SFR}_{\mathrm{Speagle}}(M_\star,z)
     $$
   - starburst if
     $$
     \Delta_{\mathrm{MS}}\ge 0.6
     $$
   - fractions in the same bins used previously.

### First-pass results

What is happening:

So all matched is all galaxies in both catalog after cuts,

long_detect is only matched galaxies with the Wang long-lamba detection and not long is its compliment

So we do not recompute SFR from wang yet, we use pop cosmos SFR for all matched galaxies. wang is just used as a tag for the 250-800um or not.

using external baseline speagle that is strict +0.6 dex and script is using median posterior values per galaxy, so extreme tails are being

Data linkage:

- pop-cosmos rows (valid COSMOS IDs): `429,669`
- Wang rows used (positive COSMOS IDs): `128,387`
- Matched rows (inner join on ID): `114,048`
- Long-detected fraction (SPIRE/SCUBA, SNR>=3): `5.65%`

Bin A (`1 <= z < 2`, `9 <= log10M <= 11.5`):

- All matched: `N=37,149`, `N_SB=8`, starburst fraction `0.0215%`, SFR share `0.2628%`
- Long-detected: `N=2,673`, `N_SB=2`, starburst fraction `0.0748%`, SFR share `0.2761%`
- Not long-detected: `N=34,476`, `N_SB=6`, starburst fraction `0.0174%`, SFR share `0.2596%`

Bin B (`1.5 <= z < 2.5`, `log10M >= 10`):

- All matched: `N=15,807`, `N_SB=3`, starburst fraction `0.0190%`, SFR share `0.1695%`
- Long-detected: `N=1,494`, `N_SB=0`, starburst fraction `0.0000%`, SFR share `0.0000%`
- Not long-detected: `N=14,313`, `N_SB=3`, starburst fraction `0.0210%`, SFR share `0.2057%`

### Comparison to previous findings ?

Previous pop-cosmos mock (my 100k run)

* **1<=z<2**: starburst SFR share **7.28%(Fraction: 0.26%)**
* **1.5<=z<2.5, M>=10**: starburst SFR share **12.82%(Fraction:0.691%)**

These were in the ballpark of the expected literature range

### New pop-cosmos × Wang matched real-data run

From the CSV:

* **1<=z<2** all matched: starburst SFR share **0.2628%**
* **1.5<=z<2.5, M>=10** all matched: **0.1695%**
* long-λ detected subsets are also very low.

So Wang-matched run is **much lower** than your earlier mock result and lower than the expected 8–14% figure.

### Interpretation

- Under current Speagle-based

  $$
  \Delta_{\mathrm{MS}}
  $$

  settings, starburst fractions are extremely low in this matched real-data run.
- This is prob a calibration/definition mismatch signal (selection + MS baseline + SFR conventions), not a final physics conclusion yet.
- Next step: test alternative MS baseline choices and IMF/SFR harmonization before drawing physical conclusions.

We likely got very low starburst/SFR-share numbers because this was a much stricter and different comparison than before, not because starbursts disappear physically.

Ideas ?

* We changed sample: earlier was a mock-generated pop-cosmos sample; now it is a real-data ID-matched subset with Wang, which can remove part of the extreme high-SFR tail.
* We used an external baseline (Speagle)
  If our sample sits below Speagle normalization, very few galaxies pass the starburst cut .**Δ**MS≥**0.6.**
* SFR definitions are not identical across datasets/papers (model-based 100 Myr average vs IR-based observational SFRs), so offsets are expected.
* Detection/matching choices (e.g., SNR threshold, matched IDs only, quality cuts) can strongly reduce rare starbursts.
* Using median posterior values also suppresses extremes.

## Plain-language clarifications

### 1) What does `all_matched, N = 37,149` mean?

- `all_matched` means galaxies that are in **both** pop-cosmos and Wang after matching by ID.
- Then we apply the bin cuts (`1 <= z < 2`, `9 <= log10M <= 11.5`, and SF quality cuts).
- `N = 37,149` is the number of galaxies left in that bin after those steps.

### 2) Why is Wang smaller than pop-cosmos?

- pop-cosmos has more total objects (`429,669` valid IDs).
- Wang is a smaller long-wavelength-focused catalog (`128,387` positive IDs).
- Matched overlap is `114,048`.

Match fractions:

$$
\frac{114048}{429669} \approx 26.5\%
$$

of pop-cosmos has a Wang match, and

$$
\frac{114048}{128387} \approx 88.8\%
$$

of Wang has a pop-cosmos match.

### 3) What are we comparing in this first pass?

Starburst classification is from pop-cosmos + Speagle:

$$
\Delta_{\mathrm{MS}} = \log_{10}(\mathrm{SFR}_{\mathrm{pop}}) - \log_{10}(\mathrm{SFR}_{\mathrm{Speagle}}(M_\star,z))
$$

$$
\text{starburst if } \Delta_{\mathrm{MS}} \ge 0.6
$$

Wang is used as a **label** only:

- long-wavelength detected (`SNR >= 3` in any of `250,350,500,850` um)
- not long-wavelength detected

Important: we did **not** recalculate SFR from Wang IR photometry in this run.

### 4) How incidence is tested

We recompute starburst fraction in each subgroup:

$$
f_{\mathrm{SB}}^{N} = \frac{N(\Delta_{\mathrm{MS}} \ge 0.6)}{N_{\mathrm{group}}}
$$

Bin A results:

$$
f_{\mathrm{SB}}^{N}(\text{all matched}) = \frac{8}{37149} = 0.0215\%
$$

$$
f_{\mathrm{SB}}^{N}(\text{long-detected}) = \frac{2}{2673} = 0.0748\%
$$

$$
f_{\mathrm{SB}}^{N}(\text{not long-detected}) = \frac{6}{34476} = 0.0174\%
$$

So yes, we do recalculate the fraction in the same bin; `all_matched` is the baseline.

### 5) Why are matched-sample rates so low vs earlier mock runs?

- Different parent sample (real matched subset vs mock generation).
- External MS baseline (Speagle) can shift offsets lower.
- Median posterior values reduce extreme-tail objects.
- Matching and cuts can remove rare high-SFR galaxies.

### 6) What this means right now

- Similar all-vs-long-detected values do **not** yet prove success or failure on dusty galaxies.
- It is a first-pass consistency check; final dust validation needs IR-based SFR comparison on the same matched galaxies.
