# FIR Thesis Decision Checklist

This is the practical "do I freeze this or keep working?" note.

Main idea:

> The FIR work is now good enough to become a thesis chapter. The next risk is not lack of plots, it is scope creep.

## What I Would Freeze Now

These feel stable enough to build the thesis around:

- formal evaluator uses corrected resolved/prior SPIRE differential counts
- P(D) counts are shown as a faint-end sensitivity check
- Wang is used as a matched-object diagnostic, not the main number-count truth
- pop-cosmos galaxy population and each object's `L_IR` stay fixed
- the tested lever is the far-IR SED shape
- baseline FSPS overpredicts SPIRE counts overall
- Casey-like warm/broader dust templates improve the formal score
- exact best template is not unique, so do not overclaim one dust temperature

Simple thesis line:

> Observed SPIRE counts show that pop-cosmos probably needs a more flexible FIR dust SED treatment, not just a different luminosity normalisation.

## Decisions To Ask Dave / Boris

These are the main sign-off questions.

### 1. Formal Score Setup

My default:

- formal score = Clements / Oliver / Pearson SUSSEX / Pearson XID
- P(D) = sensitivity check
- Wang = matched-object diagnostic

Question:

> Is this split defensible for the thesis, or should P(D) be included in the headline score?

### 2. Score Wording

My default:

- use log-space chi-square-style score
- report rough `chi2/(N-k)` where `k` is the number of template parameters
- keep saying "rough evaluator" rather than pretending it is a perfect statistical likelihood

Question:

> Is `chi2/(N-k)` the right headline score, or should I keep the simpler `chi2/N` wording?

### 3. Bright-End Count Coverage

Current bright-end anchor:

- Clements / H-ATLAS SDP

Question:

> Is Clements enough for the rare bright source comparison, or should I add a larger H-ATLAS / Valiante count source?

### 4. Dust Template Scope

Current model variants:

- FSPS baseline
- ALESS empirical template
- FSPS/ALESS hybrid
- modified blackbody grid
- Casey-like modified blackbody + mid-IR power-law grid

Question:

> Is the Casey-like grid enough as the main model-extension demonstration, or do I need proper CIGALE / Dale / Draine-Li templates before thesis submission?

### 5. Wang Diagnostic

Current role:

- useful for object-by-object residuals
- not ideal as corrected number-count truth

Question:

> Is one clean Wang matched-object plot worth keeping as a diagnostic figure, or should Wang stay mostly in the caveats/methods discussion?

## Risks And How I Am Handling Them

| risk | how I handle it |
|---|---|
| overfitting to a few count papers | use physical template families, keep `L_IR` fixed, check leave-one-source-out |
| P(D) points are correlated | keep P(D) as sensitivity unless supervisors say otherwise |
| Wang sits away from other count curves | treat Wang as matched-object diagnostic, not the main count source |
| exact best template shifts slightly | claim broad direction, not one exact dust temperature |
| rare bright sources / lensing / cosmic variance | discuss as caveats; add larger bright-end counts only if needed |
| thesis gets too broad | finish FIR chapter first; leave radio/X-ray as future work unless FIR is stable |

## What I Should Stop Doing For Now

- do not keep adding random count papers unless they fill a clear gap
- do not start radio/X-ray until the FIR chapter is written enough to defend
- do not tune templates separately by wavelength, band, or paper
- do not present ALESS as "the answer"
- do not treat high chi-square as overfitting; it usually means model/data mismatch or incomplete errors

## Minimum Submit-Ready Path

If time gets tight, the shortest path is:

1. get supervisor sign-off on the evaluator split
2. freeze the count-source set
3. freeze the figure package
4. turn Methods / Results / Discussion drafts into thesis prose
5. keep one short section on future work: CIGALE/Dale/Draine-Li, radio, X-ray, high-SFR/AGN tail

That would still tell a complete story.

## Current Personal Read

My instinct right now:

- keep the formal score conservative
- keep P(D) important but separate
- use Casey-like templates as the main result
- mention CIGALE/Dale/Draine-Li as a natural next step unless supervisors think the thesis needs them
- avoid opening a new wavelength branch until the FIR chapter is basically written

comments:

- the work is no longer just validation; it is now a small model-criticism / model-improvement loop
- that is probably the strongest technical angle for the thesis and for explaining the project to non-astronomy people
