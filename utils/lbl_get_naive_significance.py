from lbl_cep_scale_calculator import load_histograms, get_cep_scale
from lbl_cep_scale_calculator import input_histograms

# skim = "skimmed_allSelections"
# skim = "skimmed_allSelections_track3validHits"
# skim = "skimmed_allSelections_maxDiphotonPt2"
# skim = "skimmed_allSelections_nTowers1"
# skim = "skimmed_allSelections_swissCross99"
# skim = "skimmed_allSelections_eta2p4"
# skim = "skimmed_allSelections_seedTime3p6"
# skim = "skimmed_allSelections_electron0missingHits1"
# skim = "skimmed_allSelections_trackEta2p2"
# skim = "skimmed_allSelections_HF7"
# skim = "skimmed_allSelections_HB3"
# skim = "skimmed_allSelections_trackPt1p0"
# skim = "skimmed_allSelections_trackPt0p5"
# skim = "skimmed_allSelections_HE1p2"
# skim = "skimmed_allSelections_EB1p0"
# skim = "skimmed_allSelections_EE3p5"
# skim = "skimmed_allSelections_EE4p0"
# skim = "skimmed_allSelections_EE3p3"
# skim = "skimmed_allSelections_EE3p7"
# skim = "skimmed_allSelections_hadronCrack"
# skim = "skimmed_allSelections_emCrack"
# skim = "skimmed_allSelections_HFedge3p0"
# skim = "skimmed_allSelections_diphotonMass4p5"
# skim = "skimmed_allSelections_eleIso5p0"
# skim = "skimmed_allSelections_eleIso2p0"
# skim = "skimmed_allSelections_eleIso0p01"
# skim = "skimmed_allSelections_caloEta2p2"
# skim = "skimmed_allSelections_EE7p5"
# skim = "skimmed_allSelections_swissCross99_EE3p5_EEeta2p2"
# skim = "skimmed_allSelections_swissCross99_EE3p5"
# skim = "skimmed_allSelections_EE3p5_EEeta2p2"
# skim = "skimmed_allSelections_EE3p4"
# skim = "skimmed_allSelections_EE3p6"
# skim = "skimmed_allSelections_EE3p5_trackPt0p4"
# skim = "skimmed_allSelections_EE3p5_1track"
# skim = "skimmed_allSelections_EE3p5_deadHEfix"
# skim = "skimmed_allSelections_deltaEtaEE0p8"
# skim = "skimmed_allSelections_EE3p5_deltaEtaEE0p25"
skim = "skimmed_allSelections_photonEt2p0"
# skim = "skimmed_allSelections_photonEt2p5"


def main():
    cep_scale = get_cep_scale(skim)
    input_histograms["cep"].Scale(cep_scale)

    integrals = {}
    for process, histogram in input_histograms.items():
        integrals[process] = histogram.Integral(
            1, histogram.FindFixBin(0.01)-1)

    for (process, integral) in integrals.items():
        print(f"{process}: {integral:.3f}")

    total_background = integrals["cep"]+integrals["qed"]
    print(f"total background: {total_background:.3f}")

    expected_significance = integrals["lbl"]
    expected_significance /= (integrals["lbl"]+total_background)**(1/2)

    observed_significance = (integrals["collisionData"]-total_background)
    observed_significance /= (integrals["collisionData"])**(1/2)

    print(f"Expected naive significance: {expected_significance:.2f}")
    print(f"Observed naive significance: {observed_significance:.2f}")


if __name__ == "__main__":
    load_histograms(skim)
    main()
