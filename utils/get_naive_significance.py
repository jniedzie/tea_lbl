import ROOT
from params import *

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
skim = "skimmed_allSelections_EE3p5_deltaEtaEE0p25"

input_path = "/nfs/dust/cms/user/jniedzie/light_by_light/ntuples/{}/merged_{}histograms.root"


def main():
    file_data = ROOT.TFile(input_path.format("collisionData", skim), "READ")
    hist_data = file_data.Get("diphoton_acoplanarity")

    file_lbl = ROOT.TFile(input_path.format("lbl", skim), "READ")
    hist_lbl = file_lbl.Get("diphoton_acoplanarity")

    file_qed = ROOT.TFile(input_path.format("qed", skim), "READ")
    hist_qed = file_qed.Get("diphoton_acoplanarity")

    file_cep = ROOT.TFile(input_path.format("cep", skim), "READ")
    hist_cep = file_cep.Get("diphoton_acoplanarity")

    hist_lbl.Scale(lbl_scale*luminosity/n_lbl_events)
    hist_qed.Scale(qed_scale*luminosity/n_qed_events)

    cep_scale = get_cep_scale(hist_data, hist_lbl, hist_qed, hist_cep)

    hist_cep.Scale(cep_scale)

    integral_data = hist_data.Integral(1, hist_data.FindFixBin(0.01)-1)
    integral_lbl = hist_lbl.Integral(1, hist_lbl.FindFixBin(0.01)-1)
    integral_cep = hist_cep.Integral(1, hist_cep.FindFixBin(0.01)-1)
    integral_qed = hist_qed.Integral(1, hist_qed.FindFixBin(0.01)-1)
    total_background = integral_cep+integral_qed

    print(f"N data events: {integral_data:.3f}")
    print(f"N LbL events: {integral_lbl:.3f}")
    print(f"N CEP events: {integral_cep:.3f}")
    print(f"N QED events: {integral_qed:.3f}")
    print(f"total background: {total_background:.3f}")
    print(
        f"Expected naive significance: {integral_lbl/(integral_lbl+total_background)**(1/2):.2f}")
    print(
        f"Observed naive significance: {(integral_data-total_background)/(integral_data)**(1/2):.2f}")


if __name__ == "__main__":
    main()
