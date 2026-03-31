"""
Cross-match synthetic MIR photometry from generate_spectra_cosmos2020.py
with the COSMOS2020 Farmer catalog and pop-cosmos mcmc_summaries.

Usage:
  python crossmatch_cosmos2020.py --mir_path test_cosmos2020_1000.h5
"""

import h5py
import numpy as np
from astropy.table import Table
import argparse


# Paths
COSMOS2020_PATH = '/Users/bl/Astrodata/COSMOS2020_FARMER_R1_v2.2_p3.fits'
POPCOSMOS_PATH = '/Users/bl/Astrodata/COSMOS2020_popcosmos/mcmc_summaries.h5'


def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument('--mir_path', type=str, required=True,
                        help='Path to output from generate_spectra_cosmos2020.py')
    return parser.parse_args()


def load_mir_output(path):
    """Load our synthetic MIR photometry output."""
    f = h5py.File(path, 'r')
    data = {
        'index_farmer': f['metadata/index_farmer'][:],
        'ra': f['metadata/ra'][:],
        'dec': f['metadata/dec'][:],
        'z': f['metadata/z_median'][:],
        'theta': f['theta'][:],
        'start': int(f.attrs['start']),
        'end': int(f.attrs['end']),
        'source': f.attrs['source'],
    }
    # Speculator magnitudes and coverage flags
    for ch in ['Ch1', 'Ch2', 'Ch3', 'Ch4', 'MIPS24']:
        data[f'spec_mag_{ch}'] = f[f'speculator/mag_{ch}'][:]
        data[f'spec_cov_{ch}'] = f[f'speculator/coverage_{ch}'][:]

    # Photulator (if present)
    if 'photulator' in f:
        for ch in ['Ch1', 'Ch2']:
            data[f'phot_mag_{ch}'] = f[f'photulator/mag_{ch}'][:]

    # Stored model values from mcmc_summaries
    data['stored_mag_Ch1'] = f['validation/stored_mag_Ch1'][:]
    data['stored_mag_Ch2'] = f['validation/stored_mag_Ch2'][:]
    f.close()
    return data


def match_cosmos2020(mir_data, cosmos_path=COSMOS2020_PATH):
    """Cross-match with COSMOS2020 Farmer catalog using index_farmer == ID.

    The COSMOS2020 Farmer catalog has sequential 1-indexed IDs, so
    index_farmer - 1 gives the 0-indexed row position directly.
    """
    cosmos = Table.read(cosmos_path)
    idx_in_cosmos = mir_data['index_farmer'] - 1  # ID is 1-indexed
    matched = cosmos[idx_in_cosmos]

    # Verify match
    assert np.all(matched['ID'] == mir_data['index_farmer']), \
        "ID mismatch -- catalog may not have sequential IDs"

    return matched


def match_popcosmos(mir_data, popcosmos_path=POPCOSMOS_PATH):
    """Cross-match with mcmc_summaries.h5.

    Our output preserves the row ordering from mcmc_summaries[start:end],
    so we can slice directly.
    """
    f = h5py.File(popcosmos_path, 'r')
    start = mir_data['start']
    end = mir_data['end']
    source = mir_data['source']

    # Verify alignment via index_farmer
    pc_farmer = f['metadata/index_farmer'][start:end]
    assert np.all(pc_farmer == mir_data['index_farmer']), \
        "Row alignment mismatch with mcmc_summaries.h5"

    pc_data = {
        'index_v2': f['metadata/index_v2'][start:end],
        'magcut_r': f['metadata/magcut_r'][start:end],
        'magcut_Ch1': f['metadata/magcut_Ch1'][start:end],
    }

    # Physical parameters (median = percentile index 2)
    for param in ['log10M_formed', 'log10Z', 'z', 'log10SFR', 'log10sSFR',
                  'age', 'log10M_remain', 'dust2']:
        if param in f[source]:
            pc_data[param] = f[f'{source}/{param}'][start:end, 2]

    # Model fluxes for all 26 bands (median)
    for band in ['u', 'g', 'r', 'i', 'z', 'y', 'Y', 'J', 'H', 'Ks',
                 'IB427', 'IB464', 'IA484', 'IB505', 'IA527', 'IB574',
                 'IA624', 'IA679', 'IB709', 'IA738', 'IA767', 'IB827',
                 'NB711', 'NB816', 'Ch1', 'Ch2']:
        key = f'{source}/flux_{band}'
        if key in f:
            pc_data[f'model_flux_{band}'] = f[key][start:end, 2]

    f.close()
    return pc_data


def main():
    args = parse_args()

    # Load our MIR predictions
    mir = load_mir_output(args.mir_path)
    n_gal = len(mir['index_farmer'])
    print(f"Loaded {n_gal} galaxies from {args.mir_path}")

    # Cross-match with COSMOS2020 Farmer catalog
    print(f"\nCross-matching with COSMOS2020 ({COSMOS2020_PATH})...")
    cosmos = match_cosmos2020(mir)
    print(f"  Matched {len(cosmos)} rows via index_farmer == ID")

    # Cross-match with mcmc_summaries
    print(f"\nCross-matching with mcmc_summaries ({POPCOSMOS_PATH})...")
    pc = match_popcosmos(mir)
    print(f"  Matched via row slice [{mir['start']}:{mir['end']}]")

    # --- Example comparisons ---

    # 1. Model vs observed IRAC photometry
    # COSMOS2020 fluxes are in µJy; convert to AB mag
    print("\n=== Model vs Observed IRAC Photometry ===")
    for ch_num, ch_name in [(1, 'Ch1'), (2, 'Ch2'), (3, 'Ch3'), (4, 'Ch4')]:
        # Observed (Farmer deblended)
        obs_flux = np.array(cosmos[f'IRAC_CH{ch_num}_FLUX'], dtype=float)  # µJy
        obs_valid = np.array(cosmos[f'IRAC_CH{ch_num}_VALID'], dtype=bool)
        obs_mag = np.where((obs_flux > 0) & obs_valid,
                           -2.5 * np.log10(obs_flux) + 23.9,  # µJy to AB
                           np.nan)

        # Observed (SPLASH)
        splash_flux = np.array(cosmos[f'SPLASH_CH{ch_num}_FLUX'], dtype=float)
        splash_mag = np.where(splash_flux > 0,
                              -2.5 * np.log10(splash_flux) + 23.9,
                              np.nan)

        # Our Speculator prediction
        spec_mag = mir[f'spec_mag_{ch_name}']
        spec_cov = mir[f'spec_cov_{ch_name}']

        # Compare where both are valid
        mask = spec_cov & np.isfinite(spec_mag) & np.isfinite(obs_mag)
        if np.sum(mask) > 0:
            resid = spec_mag[mask] - obs_mag[mask]
            print(f"  {ch_name} (Speculator vs IRAC_FARMER): N={np.sum(mask)}, "
                  f"median={np.median(resid):.3f}, MAD={np.median(np.abs(resid - np.median(resid))):.3f}")
        else:
            print(f"  {ch_name} (Speculator vs IRAC_FARMER): no valid pairs")

        mask_sp = spec_cov & np.isfinite(spec_mag) & np.isfinite(splash_mag)
        if np.sum(mask_sp) > 0:
            resid = spec_mag[mask_sp] - splash_mag[mask_sp]
            print(f"  {ch_name} (Speculator vs SPLASH):      N={np.sum(mask_sp)}, "
                  f"median={np.median(resid):.3f}, MAD={np.median(np.abs(resid - np.median(resid))):.3f}")

    # 2. Pop-cosmos model Ch1/Ch2 vs observed
    print("\n=== Pop-cosmos Model Flux vs Observed ===")
    for ch_num, ch_name in [(1, 'Ch1'), (2, 'Ch2')]:
        model_flux = pc.get(f'model_flux_{ch_name}')
        if model_flux is None:
            continue
        # model flux is in maggies; convert to AB mag
        model_mag = np.where(model_flux > 0, -2.5 * np.log10(model_flux), np.nan)

        obs_flux = np.array(cosmos[f'IRAC_CH{ch_num}_FLUX'], dtype=float)
        obs_valid = np.array(cosmos[f'IRAC_CH{ch_num}_VALID'], dtype=bool)
        obs_mag = np.where((obs_flux > 0) & obs_valid,
                           -2.5 * np.log10(obs_flux) + 23.9, np.nan)

        mask = np.isfinite(model_mag) & np.isfinite(obs_mag)
        if np.sum(mask) > 0:
            resid = model_mag[mask] - obs_mag[mask]
            print(f"  {ch_name} (pop-cosmos model vs observed): N={np.sum(mask)}, "
                  f"median={np.median(resid):.3f}, MAD={np.median(np.abs(resid - np.median(resid))):.3f}")

    # 3. Summary table for a few objects
    print("\n=== Sample objects ===")
    print(f"{'idx_farmer':>10} {'z':>6} {'logM':>6} "
          f"{'spec_Ch1':>8} {'obs_Ch1':>8} {'splash_Ch1':>10} "
          f"{'spec_Ch3':>8} {'obs_Ch3':>8}")
    for i in range(min(10, n_gal)):
        obs_ch1 = cosmos[f'IRAC_CH1_FLUX'][i]
        obs_ch1_mag = -2.5 * np.log10(float(obs_ch1)) + 23.9 if float(obs_ch1) > 0 else np.nan
        spl_ch1 = cosmos[f'SPLASH_CH1_FLUX'][i]
        spl_ch1_mag = -2.5 * np.log10(float(spl_ch1)) + 23.9 if float(spl_ch1) > 0 else np.nan
        obs_ch3 = cosmos[f'IRAC_CH3_FLUX'][i]
        obs_ch3_mag = -2.5 * np.log10(float(obs_ch3)) + 23.9 if float(obs_ch3) > 0 else np.nan

        print(f"{mir['index_farmer'][i]:>10d} {mir['z'][i]:>6.3f} {mir['theta'][i,0]:>6.2f} "
              f"{mir['spec_mag_Ch1'][i]:>8.3f} {obs_ch1_mag:>8.3f} {spl_ch1_mag:>10.3f} "
              f"{mir['spec_mag_Ch3'][i]:>8.3f} {obs_ch3_mag:>8.3f}")


if __name__ == '__main__':
    main()
