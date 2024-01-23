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
