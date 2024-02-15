from lbl_helpers import load_histograms, get_cep_scale
from lbl_helpers import input_aco_histograms
from lbl_params import luminosity, luminosity_err, photon_scale_factor
from ROOT import sqrt
# skim = "skimmed_allSelections"
# skim = "skimmed_allSelections_photonEt2p5"
# skim = "skimmed_allSelections_photonEt2p0"
# skim = "skimmed_allSelections_swissCross0p99"
skim = "skimmed_allSelections_hadCrack"

def get_cross_section(n_events, n_events_err):
    
    Eff =  0.13637176050044683
    Eff_Error = 0.008228099665106424
    
    correction_factor = photon_scale_factor * Eff
    print(f"{correction_factor=}")
    # correction_factor = 0.08033586859838121
    correction_factor_err = 0.015651991297853243
    
    cross_section = n_events / \
        (correction_factor * luminosity/1000.)
    cross_section_syst = cross_section * \
        sqrt((correction_factor_err/correction_factor)
             ** 2 + (luminosity_err/luminosity)**2)
    cross_section_stat = n_events_err / \
        (correction_factor * luminosity/1000.)
        
    return cross_section, cross_section_stat, cross_section_syst

def main():
    print("\n\n============================================================")
    print(f"Number of raw events for A < 0.01:")
    n_passing_lbl = input_aco_histograms["lbl"].Integral(
        1, input_aco_histograms["lbl"].FindFixBin(0.01)-1)
    print(f"lbl: {n_passing_lbl:.0f}")
    print("============================================================\n\n")

    cep_scale = get_cep_scale(skim)
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

   
    cross_section, cross_section_stat, cross_section_syst = get_cross_section(data_minus_background, data_minus_background_err)
    cross_section_mc, cross_section_mc_stat, cross_section_mc_syst = get_cross_section(integrals["lbl"], integral_errors["lbl"])

    print("\n\n============================================================")
    print(
        f"Measured cross-section: {cross_section:.0f} +/- {cross_section_stat:.0f} (stat) +/- {cross_section_syst:.0f} (syst) nb")
    print(
        f"Expected cross-section: {cross_section_mc:.0f} +/- {cross_section_mc_stat:.0f} (stat) +/- {cross_section_mc_syst:.0f} (syst) nb")
    print("============================================================\n\n")


if __name__ == "__main__":
    load_histograms(skim)
    main()
