import ROOT

input_file_path = "../combine/significance_histograms_skimmed_lblSelections_final_andZDC_nBins400.root"

def main():
    file = ROOT.TFile.Open(input_file_path)
    hist_data = file.Get("data_obs")
    hist_cep = file.Get("cep")
    hist_qed = file.Get("qed")
    hist_lbl = file.Get("lbl")
    
    hist_data.SetLineColor(ROOT.kBlack)
    hist_data.SetMarkerColor(ROOT.kBlack)
    hist_data.SetMarkerStyle(20)
    
    hist_cep.SetFillColor(ROOT.kAzure-4)
    hist_lbl.SetFillColor(ROOT.kOrange+1)
    hist_qed.SetFillColor(ROOT.kYellow)
    
    stack = ROOT.THStack("stack", "stack")
    stack.Add(hist_cep)
    stack.Add(hist_qed)
    stack.Add(hist_lbl)
    
    canvas = ROOT.TCanvas("canvas", "canvas", 800, 800)
    stack.Draw("hist")
    hist_data.Draw("PEsame")
    
    # set Y axis range
    stack.SetMaximum(25)
    stack.SetMinimum(0)
    
    legend = ROOT.TLegend(0.6, 0.6, 0.9, 0.9)
    legend.AddEntry(hist_data, "Data", "PE")
    legend.AddEntry(hist_cep, "CEP", "F")
    legend.AddEntry(hist_lbl, "LBL", "F")
    legend.AddEntry(hist_qed, "QED", "F")
    legend.Draw()
    
    canvas.SaveAs("../plots/significance_histograms_skimmed_lblSelections_final_andZDC_nBins400.pdf")

if __name__ == "__main__":
    main()