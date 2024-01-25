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
    print(f"LbL path: {input_path.format('lbl', skim)}")
    hist_lbl = file_lbl.Get("diphoton_acoplanarity")

    file_qed = ROOT.TFile(input_path.format("qed", skim), "READ")
    hist_qed = file_qed.Get("diphoton_acoplanarity")

    file_cep = ROOT.TFile(input_path.format("cep", skim), "READ")
    hist_cep = file_cep.Get("diphoton_acoplanarity")

    hist_lbl.Scale(lbl_scale*luminosity/n_lbl_events)
    hist_qed.Scale(qed_scale*luminosity/n_qed_events)
    
    cep_scale = get_cep_scale(hist_data, hist_lbl, hist_qed, hist_cep)
    print(f"scale: {cep_scale}")
    
    
if __name__ == "__main__":
    main()
