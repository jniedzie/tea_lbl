import ROOT
from params import *

# skim = "skimmed_allSelections"
# skim = "skimmed_allSelections_track3validHits"
skim = "skimmed_allSelections_maxDiphotonPt2"

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
    print(f"scale: {cep_scale}")
    
    
if __name__ == "__main__":
    main()
