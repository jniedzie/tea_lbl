import ROOT

input_path = "/nfs/dust/cms/user/jniedzie/light_by_light/ntuples/{}/merged_skimmed_allSelectionshistograms.root"

luminosity = 1647.228136  # μb^-1

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
    
    hist_data_no_background = hist_data.Clone()
    hist_data_no_background.Add(hist_lbl, -1)
    hist_data_no_background.Add(hist_qed, -1)

    # get integral of data histogram above 0.02
    integral_data = hist_data_no_background.Integral(
        hist_data_no_background.FindBin(0.02), hist_data_no_background.GetNbinsX())
    integral_cep = hist_cep.Integral(
        hist_cep.FindBin(0.02), hist_cep.GetNbinsX())

    scale = integral_data / integral_cep

    print(f"scale: {scale}")
    print(f"N CEP events: {integral_cep}")


if __name__ == "__main__":
    main()
