from lbl_helpers import load_histograms, get_cep_scale
from lbl_helpers import input_aco_histograms
from lbl_params import luminosity, luminosity_err, get_scale_factor
from lbl_params import crossSections, nGenEvents, luminosity_err

# skim = "skimmed_allSelections"
# skim = "skimmed_allSelections_photonEt2p5"
# skim = "skimmed_allSelections_photonEt2p0"
# skim = "skimmed_allSelections_swissCross0p99"
# skim = "skimmed_allSelections_hadCrack"
# skim = "skimmed_allSelections_hadCrack_noZDC"
skim = "skimmed_lblSelections_final"


def get_cross_section(n_events, n_events_err, photon=True):

    if photon:
        Eff = 0.1352
        Eff_Error = 0.0030
    else:
        Eff = 0.0717
        Eff_Error = 0.000782

    scale_factor, sf_error = get_scale_factor(photon=photon)
    
    correction_factor = scale_factor * Eff
    correction_factor_err = correction_factor * ((sf_error/scale_factor)**2 + (Eff_Error/Eff)**2)**0.5

    print(
        f"Correction factor: {correction_factor:.4f} +/- {correction_factor_err:.4f}")

    cross_section = n_events / (correction_factor * luminosity/1000.)

    cross_section_syst = cross_section * ((correction_factor_err/correction_factor)**2 + (luminosity_err/luminosity)**2)**0.5

    cross_section_stat = n_events_err / (correction_factor * luminosity/1000.)

    return cross_section, cross_section_stat, cross_section_syst


def get_cep_norm():
    cep_normalization, cep_normalization_err = get_cep_scale(skim)

    print(f"{cep_normalization=:.5f} +/- {cep_normalization_err:.5f}")

    scale_factor, scale_factor_error = get_scale_factor(photon=True)
    n_events = nGenEvents['cep']
    cross_section = crossSections['cep']

    value = cep_normalization / cross_section/scale_factor*n_events/luminosity
    n_event_err = n_events**0.5

    print(f"SF: {scale_factor:.2f} +/- {scale_factor_error:.2f}")
    print(f"N events: {n_events:.2f} +/- {n_event_err:.2f}")
    print(f"Cross section: {cross_section:.2f}")
    print(f"Luminosity: {luminosity:.2f} +/- {luminosity_err:.2f}")

    error = value * ((cep_normalization_err/cep_normalization)**2 +
                     (scale_factor_error/scale_factor)**2 +
                     (n_event_err/n_events)**2 +
                     (luminosity_err/luminosity)**2)**0.5

    return value, error


def main():
    print("\n\n============================================================")
    print(f"Number of raw events for A < 0.01:")
    n_passing_lbl = input_aco_histograms["lbl"].Integral(
        1, input_aco_histograms["lbl"].FindFixBin(0.01)-1)
    print(f"lbl: {n_passing_lbl:.0f}")
    print("============================================================\n\n")

    cep_scale, _ = get_cep_scale(skim)
    print(f"{cep_scale=}")
    input_aco_histograms["cep"].Scale(cep_scale)

    integrals = {}
    integral_errors = {}

    for process, histogram in input_aco_histograms.items():
        integrals[process] = histogram.Integral(
            1, histogram.FindFixBin(0.01)-1)

        integral_errors[process] = 0
        for i in range(1, histogram.FindFixBin(0.01)):
            integral_errors[process] += histogram.GetBinError(i)**2
        integral_errors[process] = integral_errors[process]**(1/2)

    print("\n\n============================================================")
    print("Number of scaled events for A < 0.01:")
    for (process, integral) in integrals.items():
        print(f"{process}: {integral:.3f} +- {integral_errors[process]:.3f}")
    print("============================================================\n\n")

    total_background = integrals["cep"]+integrals["qed"]
    total_background_err = (
        integral_errors["cep"]**2+integral_errors["qed"]**2)**(1/2)

    data_minus_background = integrals["collisionData"]-total_background
    data_minus_background_err = (
        integral_errors["collisionData"]**2+total_background_err**2)**(1/2)

    print("\n\n============================================================")
    print(
        f"total background: {total_background:.3f} +- {total_background_err:.3f}")
    print(
        f"collisionData - background: {data_minus_background:.3f} +- {data_minus_background_err:.3f}")
    print("============================================================\n\n")

    expected_significance = integrals["lbl"]
    expected_significance /= (integrals["lbl"]+total_background)**(1/2)

    observed_significance = (integrals["collisionData"]-total_background)
    observed_significance /= (integrals["collisionData"])**(1/2)

    print("\n\n============================================================")
    print(f"Expected naive significance: {expected_significance:.2f}")
    print(f"Observed naive significance: {observed_significance:.2f}")
    print("============================================================\n\n")

    cross_section, cross_section_stat, cross_section_syst = get_cross_section(
        data_minus_background, data_minus_background_err)
    cross_section_mc, cross_section_mc_stat, cross_section_mc_syst = get_cross_section(
        integrals["lbl"], integral_errors["lbl"])

    print("\n\n============================================================")
    print(
        f"Measured LbL cross-section: {cross_section:.0f} +/- {cross_section_stat:.0f} (stat) +/- {cross_section_syst:.0f} (syst) nb")
    print(
        f"Expected LbL cross-section: {cross_section_mc:.0f} +/- {cross_section_mc_stat:.0f} (stat) +/- {cross_section_mc_syst:.0f} (syst) nb")
    print("============================================================\n\n")

    cep_norm, cep_norm_err = get_cep_norm()
    print(f"\n\n{cep_norm} +/- {cep_norm_err}\n\n")
    
    # n_qed_data = 16068  # with ZDC cut
    n_qed_data = 20161  # no ZDC cut
    n_qed_data_err = n_qed_data**0.5
    cross_section_qed, cross_section_qed_stat, cross_section_qed_syst = get_cross_section(n_qed_data, n_qed_data_err, photon=False)
    
    print("\n\n============================================================")
    print(
        f"Measured QED cross-section: {cross_section_qed:.0f} +/- {cross_section_qed_stat:.0f} (stat) +/- {cross_section_qed_syst:.0f} (syst) nb")
    # print(
        # f"Expected QED cross-section: {cross_section_mc:.0f} +/- {cross_section_mc_stat:.0f} (stat) +/- {cross_section_mc_syst:.0f} (syst) nb")
    print("============================================================\n\n")
    


if __name__ == "__main__":
    load_histograms(skim)
    main()
