# FIR validation work, August 2026

New analysis and write-ups from the validation session. Everything here was produced from
the catalogues and code already in `Project coding/`, so nothing needs re-running to read it.

## Start here

| file | what it is |
|---|---|
| `email_to_dave.md` | The message to send. Two results, the cause, and how the Wang question was closed. |
| `figures/scatter_mechanism_explained.png` | Attach this to the email. The whole argument in one plot. |
| `reports/OPEN_ISSUES_ASSESSMENT.md` | Which loose ends are actually still open, and which turned out not to matter. |

## Reports

- `reports/OPEN_ISSUES_ASSESSMENT.md` — status of every open item, with the sensitivity
  evidence behind "this decision doesn't change the conclusion".
- `reports/PARADOX_RESOLVED_AND_FIGURE_PLAN.md` — the scatter finding in full, plus the
  seven-figure plan for the report and what to cut.
- `reports/PLAIN_EXPLANATION_AND_REPLY.md` — longer version of the email with the full
  decomposition tables.
- `reports/FIR_VALIDATION_REPORT.md` — independent re-derivation of the original headline
  result, and four things to tighten.
- `reports/WANG_DISCREPANCY_RESOLVED.md` — why raw deblended counts sit below published
  counts, resolved by flux regime. Note the struck-through pooled table near the top: those
  numbers are superseded, kept only to show the slope derivation.
- `reports/log_digest.md` — structured digest of all 6,391 lines of
  `supervisor_meeting_prep.md` (decisions, numbers, open items, figures, feedback, caveats).
  Useful as an index into your own log.

## Figures

Seven thesis figures plus the email plot. `figures/README_figures.md` maps each one to its
place in the report.

## Tables

CSVs behind every number quoted in the reports. `tables/README_tables.md` says which is which.

## LaTeX

`latex/main.tex` and `latex/references.bib` — title page, layperson's summary, abstract and
introduction written; later sections stubbed with TODO notes. Two bibliography entries are
flagged `DOI UNVERIFIED` and need checking on ADS.

The prose is an AI-assisted draft and must be rewritten in your own words before submission.

## Two things not to write

1. **Don't quote a best-fit emissivity index.** The preferred value moves between 2.5 and 3.0
   depending on which count sources are included. The counts constrain the dust temperature
   (~30 K), not the index.
2. **Don't say the scatter explains the whole count excess.** It fully accounts for 250 µm,
   but only about a third to two-thirds at 350 and 500 µm. The remainder is where the
   cold-dust problem sits. See `tables/paradox_decomposition_residuals.csv`.
