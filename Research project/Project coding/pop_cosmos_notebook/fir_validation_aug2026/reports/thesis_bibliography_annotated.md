# Thesis Bibliography — annotated, grouped by role in the argument

Every entry below was resolved to a verified DOI via Crossref (ADS bibcodes resolve to these DOIs). Citation counts are Crossref, retrieved this session. BibTeX for all 15 is in `thesis_references.bib`.


## The model under test

- **Alsing et al. (2024)** — *pop-cosmos: A Comprehensive Picture of the Galaxy Population from COSMOS Data*. The Astrophysical Journal Supplement Series 274, 12. [doi:10.3847/1538-4365/ad5c69](https://doi.org/10.3847/1538-4365/ad5c69) · 24 citations
  
  The paper you are extending. Establishes the population model, the 16-parameter FSPS SPS model, and — critically for you — that **dust emission is set purely by energy balance** with no free FIR-shape parameter. That single design fact is *why* an FIR count test has diagnostic power: nothing in the fit constrains the far-IR SED shape.

- **Thorp et al. (2024)** — *pop-cosmos: Scaleable Inference of Galaxy Properties and Redshifts with a Data-driven Population Model*. The Astrophysical Journal 975, 145. [doi:10.3847/1538-4357/ad7736](https://doi.org/10.3847/1538-4357/ad7736) · 13 citations
  
  Companion inference paper; cite for the redshift/parameter posteriors your `z_pop`, `L_IR` draws come from.

- **Leja et al. (2017)** — *Deriving Physical Properties from Broadband Photometry with Prospector: Description of the Model and a Demonstration of its Accuracy Using 129 Galaxies in the Local Universe*. The Astrophysical Journal 837, 170. [doi:10.3847/1538-4357/aa5ffe](https://doi.org/10.3847/1538-4357/aa5ffe) · 509 citations
  
  Prospector — the SED-inference machinery. Cite when explaining that FSPS+energy-balance dust is inherited from the Prospector framework, so the cold-FIR issue is not unique to pop-cosmos.


## FIR dust SED physics (your template families & their justification)

- **Draine et al. (2007)** — *Infrared Emission from Interstellar Dust. IV. The Silicate‐Graphite‐PAH Model in the Post‐
          Spitzer
          Era*. The Astrophysical Journal 657, 810-837. [doi:10.1086/511055](https://doi.org/10.1086/511055) · 1877 citations
  
  The physically-motivated dust-emission model (silicate-graphite-PAH, U_min/gamma/q_PAH). This is the 'proper' dust model your Casey-like grid is a simplified stand-in for — cite as the natural next step (your decision gate 4).

- **Casey et al. (2012)** — *Far-infrared spectral energy distribution fitting for galaxies near and far*. Monthly Notices of the Royal Astronomical Society 425, 3094-3103. [doi:10.1111/j.1365-2966.2012.21455.x](https://doi.org/10.1111/j.1365-2966.2012.21455.x) · 353 citations
  
  The template family you actually implemented: modified blackbody + mid-IR power law. Your T/alpha grid is a direct simplification of this. Core methods citation.

- **Swinbank et al. (2013)** — *An ALMA survey of sub-millimetre Galaxies in the Extended Chandra Deep Field South: the far-infrared properties of SMGs*. Monthly Notices of the Royal Astronomical Society 438, 1267-1287. [doi:10.1093/mnras/stt2273](https://doi.org/10.1093/mnras/stt2273) · 305 citations
  
  ALESS — the empirical SMG SED your hybrid brackets against. Cite for the ALESS average template.

- **Schreiber et al. (2017)** — *Dust temperature and mid-to-total infrared color  distributions for star-forming galaxies at 0 &lt;
          z
          &lt; 4*. Astronomy &amp; Astrophysics 609, A30. [doi:10.1051/0004-6361/201731506](https://doi.org/10.1051/0004-6361/201731506) · 213 citations
  
  Dust temperature rises with redshift and specific-SFR on the main sequence. Direct external support that FSPS's cold ~136µm-peaking population is too cold for real star-forming galaxies — arguably your single most useful physics citation.


## Observed SPIRE number counts (your evaluator benchmarks)

- **Clements et al. (2010)** — *Herschel-ATLAS: Extragalactic number counts from 250 to 500 microns*. Astronomy and Astrophysics 518, L8. [doi:10.1051/0004-6361/201014581](https://doi.org/10.1051/0004-6361/201014581) · 97 citations
  
  H-ATLAS SDP counts — your bright-end anchor (Clements). Note it is superseded in area by Valiante DR1.

- **Oliver et al. (2010)** — *HerMES: SPIRE galaxy number counts at 250, 350, and 500 μm*. Astronomy and Astrophysics 518, L21. [doi:10.1051/0004-6361/201014697](https://doi.org/10.1051/0004-6361/201014697) · 206 citations
  
  HerMES SPIRE counts at 250/350/500 — your independent mid-flux benchmark (Oliver). Also notes models historically overpredict bright SPIRE counts, which pre-figures your result.

- **Glenn et al. (2010)** — *HerMES: deep galaxy number counts from a P(D) fluctuation analysis of SPIRE Science Demonstration Phase observations*. Monthly Notices of the Royal Astronomical Society 409, 109-121. [doi:10.1111/j.1365-2966.2010.17781.x](https://doi.org/10.1111/j.1365-2966.2010.17781.x) · 105 citations
  
  HerMES P(D) fluctuation counts (Glenn) — your faint-end sensitivity source. The correlated-knot caveat you apply comes from the P(D) method itself.

- **Pearson et al. (2025)** — *The Herschel-SPIRE Dark Field I: the deepest Herschel image of the submillimetre Universe*. Monthly Notices of the Royal Astronomical Society 539, 336-346. [doi:10.1093/mnras/staf335](https://doi.org/10.1093/mnras/staf335) · 3 citations
  
  SPIRE Dark Field I (Pearson 2025) = your Pearson XID/SUSSEX source. Deepest resolved SPIRE counts; independent field (North Ecliptic Pole).

- **Varnish et al. (2025)** — *The Herschel-SPIRE Dark Field – II. A P(D) fluctuation analysis of the deepest Herschel image of the submillimetre universe*. Monthly Notices of the Royal Astronomical Society 539, 347-354. [doi:10.1093/mnras/staf318](https://doi.org/10.1093/mnras/staf318) · 2 citations
  
  SPIRE Dark Field II (Varnish 2025) = your Varnish P(D) source. Companion deep P(D) analysis.

- **Béthermin et al. (2010)** — *Submillimeter number counts at 250 μm, 350 μm and 500 μm in BLAST data*. Astronomy and Astrophysics 516, A43. [doi:10.1051/0004-6361/200913910](https://doi.org/10.1051/0004-6361/200913910) · 63 citations
  
  Bethermin submm counts — method/context citation for Euclidean-normalised differential counts.


## Catalogue & simulation context

- **Jin et al. (2018)** — *“Super-deblended” Dust Emission in Galaxies. II. Far-IR to (Sub)millimeter Photometry and High-redshift Galaxy Candidates in the Full COSMOS Field*. The Astrophysical Journal 864, 56. [doi:10.3847/1538-4357/aad4af](https://doi.org/10.3847/1538-4357/aad4af) · 174 citations
  
  Jin super-deblended COSMOS FIR catalogue — the independent flux reference in your Wang/Jin check that isolates the ~13-19% long-wave Wang offset.

- **Béthermin et al. (2017)** — *The impact of clustering and angular resolution on far-infrared and millimeter continuum observations*. Astronomy &amp; Astrophysics 607, A89. [doi:10.1051/0004-6361/201730866](https://doi.org/10.1051/0004-6361/201730866) · 163 citations
  
  SIDES — simulated FIR/submm sky. Cite as the standard way to forward-model counts and as context for what a physically complete count model looks like.
