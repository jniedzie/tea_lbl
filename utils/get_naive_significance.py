import ROOT

input_path = "/nfs/dust/cms/user/jniedzie/light_by_light/ntuples/{}/merged_skimmed_allSelectionshistograms.root"


luminosity = 1647.228136  # μb^-1

cep_scale = 0.0012475821798342804

lbl_scale = 2.59 * 0.8477 * 0.9322 * 0.9771**2 * 0.8643 * 1.0006  # xsec * SFs
n_lbl_events = 466000

qed_scale = 8827.220 * 0.8477 * 0.9322 * 0.952**2 * 0.8643 * 1.0006  # xsec * SFs
n_qed_events = 59260000


def main():
    file_data = ROOT.TFile(input_path.format("collisionData"), "READ")
    hist_data = file_data.Get("diphoton_acoplanarity")

    file_lbl = ROOT.TFile(input_path.format("lbl"), "READ")
    hist_lbl = file_lbl.Get("diphoton_acoplanarity")

    file_qed = ROOT.TFile(input_path.format("qed"), "READ")
    hist_qed = file_qed.Get("diphoton_acoplanarity")

    file_cep = ROOT.TFile(input_path.format("cep"), "READ")
    hist_cep = file_cep.Get("diphoton_acoplanarity")

    hist_lbl.Scale(lbl_scale*luminosity/n_lbl_events)
    hist_qed.Scale(qed_scale*luminosity/n_qed_events)
    hist_cep.Scale(cep_scale)

    integral_data = hist_data.Integral(1, hist_data.FindFixBin(0.01)-1)
    integral_lbl = hist_lbl.Integral(1, hist_lbl.FindFixBin(0.01)-1)
    integral_cep = hist_cep.Integral(1, hist_cep.FindFixBin(0.01)-1)
    integral_qed = hist_qed.Integral(1, hist_qed.FindFixBin(0.01)-1)

    print(f"N data events: {integral_data}")
    print(f"N LbL events: {integral_lbl}")
    print(f"N CEP events: {integral_cep}")
    print(f"N QED events: {integral_qed}")

    total_background = integral_cep+integral_qed
    
    print(f"total background: {total_background}")
    
    print(f"Expected naive significance: {integral_lbl/(integral_lbl+total_background)**(1/2)}")
    print(f"Observed naive significance: {(integral_data-total_background)/(integral_data)**(1/2)}")


if __name__ == "__main__":
    main()
