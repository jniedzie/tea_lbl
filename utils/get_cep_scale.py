import ROOT

input_path = "/nfs/dust/cms/user/jniedzie/light_by_light/ntuples/{}/skimmed_allSelections/merged_skimmed_allSelectionshistograms.root"

def main():
    file_data = ROOT.TFile(input_path.format("collisionData"), "READ")
    hist_data = file_data.Get("diphoton_acoplanarity")
    
    file_lbl = ROOT.TFile(input_path.format("lbl"), "READ")
    hist_lbl = file_lbl.Get("diphoton_acoplanarity")
    
    file_qed = ROOT.TFile(input_path.format("qed"), "READ")
    hist_qed = file_qed.Get("diphoton_acoplanarity")
    
    file_cep = ROOT.TFile(input_path.format("cep"), "READ")
    hist_cep = file_cep.Get("diphoton_acoplanarity")
    
    hist_data_no_background = hist_data.Clone()
    hist_data_no_background.Add(hist_lbl, -1)
    hist_data_no_background.Add(hist_qed, -1)
    
    # get integral of data histogram above 0.02
    integral_data = hist_data.Integral(hist_data.FindBin(0.02), hist_data.GetNbinsX())
    integral_cep = hist_cep.Integral(hist_cep.FindBin(0.02), hist_cep.GetNbinsX())
    
    scale = integral_data / integral_cep
    
    print(f"scale: {scale}")
    print(f"N CEP events: {integral_cep}")
    
    
if __name__ == "__main__":
    main()