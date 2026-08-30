# Reply to Dave: which FIR loose ends are actually still open

Dave's point is right, and closing loose ends beats new development this late. But of the
four items in my initial reply, **two are already closed and two turn out not to matter**.
The genuinely open items are different, and one of them I closed today.

## Status of my four proposed items

### 1. Separating object-level flux checks from binned count comparisons — **CLOSED, and it produced the main result**

This was the right instinct but it isn't a bookkeeping tidy-up: the apparent conflict was
physics. Per-object I look too faint (−0.15 to −0.23 dex vs Wang); in counts I look too
bright (+0.19 to +0.43 dex). Both are correct and they're reconciled by the model's flux
**scatter**, not by keeping the comparisons apart.

Conditioning on *model-bright* rather than *observation-detected* objects flips the sign:

| band | conditioned on detection | conditioned on model > 20 mJy | frac of model-bright that are truly faint |
|---:|---:|---:|---:|
| 250 | −0.154 | **+0.404** | 74% |
| 350 | −0.227 | **+0.581** | 88% |
| 500 | −0.177 | **+0.780** | 95% |

With count slopes α = 3.2–4.1, a ~0.45 dex scatter promotes numerous faint galaxies into
sparse bright bins. Decomposition: the mean offset alone would push counts *low* by
0.36–0.62 dex, scatter pushes them *high* by 0.55–0.86 dex, and the residue matches the
measured excess (at 250 µm, predicted +0.188 vs measured +0.19).

So this doesn't get "cleaned up" — it gets **written up**. It's the most novel thing in the
project.

### 2. How to treat Valiante bright-end bins — **DOESN'T MATTER, and I can now show that**

I ran the model ranking under five different treatments:

| scenario | pts | best model | FSPS rank | FSPS offset |
|---|---:|---|---:|---:|
| all sources, 10–300 mJy | 174 | Casey T30K α=2.5 | 12/32 | +0.275 |
| drop Valiante entirely | 143 | Casey T30K α=2.5 | 12/32 | +0.268 |
| cap all at 100 mJy | 154 | Casey T30K α=3.0 | 11/32 | +0.245 |
| cap Valiante only at 100 mJy | 164 | Casey T30K α=3.0 | 12/32 | +0.256 |
| drop P(D) sources | 149 | Casey T30K α=3.0 | 12/32 | +0.252 |

FSPS ranks 11th–12th of 32 in every case and the offset moves by only 0.03 dex, far inside
the 0.12 dex inter-survey scatter. The winner is always a T30K Casey-like template, but note
the preferred emissivity index is *not* stable — α=2.5 for the first two scenarios, α=3.0 for
the other three. Those two templates differ by a median 0.10–0.15 dex in predicted counts
(up to 0.48 dex in the sparsest bright bins), i.e.\ comparable to or larger than the 0.12 dex
inter-survey scatter, so the data genuinely cannot choose between them. This does not affect
the conclusion — both are warm T30K templates and both sit far from baseline FSPS — but it
means **the emissivity index must not be quoted as a measured value.** The defensible
statement is that the counts prefer a warm (~30 K) template and cannot constrain α.
**So the source-selection choice is a non-decision for the conclusion, but it is not evidence
for a particular α.** Report it as a sensitivity table and move on — that's stronger than picking
one treatment and defending it.

### 3. Whether Wang raw counts belong in the main comparison — **ALREADY DECIDED, and now quantified**

Wang raw counts should be excluded from the formal comparison, and we now have the
measurement to justify it rather than a judgement call. Both Wang and Jin raw counts agree
with published corrected counts to within ~15% at 10–30 mJy but fall to 0.2–0.3× above
~30 mJy, because a COSMOS-sized field has single-digit source counts per bright bin.
Béthermin et al. (2012) is direct precedent: same field, same 24 µm-prior method, and they
apply explicit resolved-count and completeness corrections.

One sentence in Methods with those numbers closes it.

### 4. Finalising the independent count-source set — **ALREADY DONE, and it was superseded**

Your `external_spire_clean_independent_count_sources.csv` logic is sound (one field per
survey family; the three Valiante tables are different bands of the same sky, correctly
allowed). But the χ² framework it feeds has a deeper problem the source list can't fix:
**residuals are strongly autocorrelated within each source** (lag-1 up to +0.92). χ² treats
83 points as independent when they carry ~5 fields of information.

The block bootstrap over whole sky fields is the fix, and it's already run: FSPS excluded at
95% (median +0.29 dex, CI [+0.16, +0.52]); warm templates straddle zero. That is a stronger
claim than any χ² table and it makes the exact source-list membership much less critical.

## The item that was genuinely open — now closed

**Was the ~0.45 dex scatter the model's, or Wang's deblending?** This was the one thing that
could have undercut the headline finding, and Wang alone couldn't answer it. Cross-matching
pop-cosmos to **Jin 2018** (independent deblending, same field, 80,271 objects at 1″) settles
it:

| band | model scatter vs Wang | model scatter vs Jin | Wang-vs-Jin disagreement | deblending share of variance |
|---:|---:|---:|---:|---:|
| 250 | 0.501 | 0.512 | 0.130 | 6.7% |
| 350 | 0.441 | 0.466 | 0.119 | 7.3% |
| 500 | 0.436 | 0.423 | 0.154 | 12.5% |

The model scatter is the same against two independent reductions, while those reductions
agree with each other to 0.12–0.15 dex. Deblending accounts for ~9% of the variance.
**Intrinsic model scatter is 0.41–0.48 dex.** The sign-flip reproduces against Jin too
(+0.443 / +0.516 / +0.516 dex; 81–90% of model-bright objects truly faint).

## What I'd actually tell Dave

I'd agree with his framing and then reframe the list:

> Agreed — no new development. Of the loose ends I listed, the object-level vs count
> tension turned out not to be a bookkeeping issue but the main result: the model's
> ~0.45 dex per-object flux scatter inflates bright counts even though typical galaxies are
> underluminous, and warmer templates fix the mean but not the scatter. I've now confirmed
> that scatter is intrinsic to pop-cosmos rather than deblending error by repeating the
> comparison against Jin 2018, an independent deblending of the same field. The Valiante
> bright-end and count-source-membership questions turn out not to change any conclusion —
> I'll present those as sensitivity tables rather than decisions. What remains is writing,
> not analysis.

## Remaining genuine gaps, ranked

1. **Nothing blocking submission.** The result is defensible as it stands.
2. **Optional, ~1 day:** z-resolved comparison against Béthermin 2012's published
   per-redshift-slice counts. Converts my leave-one-z-bin-out diagnostic into a direct
   measurement. Highest scientific value of anything left.
3. **Optional, ~2 hours:** confirm the flux-scatter conclusion isn't driven by AGN
   (`TYPE_AGN` in Jin, AGN parameters in pop-cosmos). Cheap, and pre-empts a viva question.
4. **Not worth doing now:** Draine & Li / CIGALE dust families. Genuine future work, and the
   template degeneracy result already establishes that counts alone can't select among them.
   Over 10–300 mJy the ALESS-50% and Casey T30K α=2.5 predictions differ by a median of only
   0.05–0.09 dex per band, comparable to the 0.12 dex inter-survey scatter (differences grow
   to ~0.6 dex in the sparsest bright bins, where the model counts are Poisson-limited
   anyway). That is the honest reason not to pursue more template families.
