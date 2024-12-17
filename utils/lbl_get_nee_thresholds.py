import ROOT

# suffix = "eta2p9"
suffix = "eta3p15"

# sub_detector = "HFplus"
sub_detector = "HFminus"

variable = "energy"
# variable = "energyTransverse"

base_path = "/nfs/dust/cms/user/jniedzie/light_by_light/ntuples"
lbl_base_path = "/afs/desy.de/user/j/jniedzie/tea_lbl"

hist_file_name = "merged_allSelections_exceptHFnee_histograms"

samples = {
    "Empty Beams": (f"{base_path}/emptyBeams/{hist_file_name}_{suffix}.root",                       ROOT.kBlue),
    
    # "Zero Bias, Jeremi": (f"{base_path}/collisionDataZeroBias/{hist_file_name}_{suffix}.root", ROOT.kOrange),
    "Zero Bias": (f"{lbl_base_path}/calo_towers_HF_TnP_data_zeroBias_{suffix}.root",                ROOT.kRed),
    
    "B--W Data": (f"{lbl_base_path}/calo_towers_HF_TnP_bw_data_{suffix}.root",                      ROOT.kBlack),
    "B--W Data, 0n0n": (f"{lbl_base_path}/calo_towers_HF_TnP_bw_data_0n0n_{suffix}.root",           ROOT.kMagenta),
    "B--W MC": (f"{lbl_base_path}/calo_towers_HF_TnP_bw_mc_{suffix}.root",                          ROOT.kGreen+1),
}

variable_label = {
    "energy": "E",
    "energyTransverse": "E_{T}",
}

canvas = ROOT.TCanvas("canvas", "canvas", 800, 600)
legend = ROOT.TLegend(0.4, 0.65, 0.9, 0.9)
labels = []
files = []
hists = []
i_plot = 0

def get_threshold(hist, fraction=0.99):
    total = hist.Integral()
    
    if total == 0:
        print("Empty histogram")
        return 0
    
    threshold = 0

    for i in range(1, hist.GetNbinsX()):
        if hist.Integral(1, i) / total > fraction:
            threshold = hist.GetBinLowEdge(i)
            break

    print(f"Threshold: {threshold}")
    return threshold


def get_fraction_below_threshold(hist, threshold):
    total = hist.Integral()
    if total == 0:
        print("Empty histogram")
        return 0
    return hist.Integral(1, hist.FindBin(threshold)) / total

def plot_hist(file_path, hist_name, color, title):
    global i_plot
    
    files.append(ROOT.TFile.Open(file_path))
    
    if files[-1].Get(hist_name) is None or type(files[-1].Get(hist_name)) is ROOT.TObject:
        print(f"Could not find histogram {hist_name} in file {file_path}")
        return
    
    hists.append(files[-1].Get(hist_name).Clone())
    
    fixed_threshold = 8.0
    print(f"{title}: fraction below {fixed_threshold} GeV threshold for detector: {sub_detector} is {get_fraction_below_threshold(hists[-1], fixed_threshold):.4f}")
    
    if hists[-1].GetEntries() == 0:
        print(f"Empty histogram {hist_name} in file {file_path}")
        return
    
    hists[-1].Scale(1./hists[-1].GetEntries())
    hists[-1].SetTitle(f"{sub_detector} ({suffix})")
    hists[-1].SetLineColor(color)
    hists[-1].Draw("" if i_plot==0 else "same")
    
    hists[-1].GetXaxis().SetTitle(f"Leading tower {variable_label[variable]} [GeV]")
    hists[-1].GetYaxis().SetTitle("Events")
    
    threshold = get_threshold(hists[-1], 0.99)
    line = ROOT.TLine(threshold, 0, threshold, hists[-1].GetMaximum())
    line.SetLineColor(color)
    line.SetLineWidth(2)
    line.DrawClone()
    
    legend.AddEntry(hists[-1], f"{title} ({threshold:.1f} GeV)", "l")
    legend.Draw()
    
    hists[-1].GetXaxis().SetRangeUser(1, 15)
    hists[-1].GetYaxis().SetRangeUser(1e-4, 3e-1)
    
    i_plot += 1
    

def main():
    ROOT.gROOT.SetBatch(True)
    # ROOT.gPad.SetLogx()
    ROOT.gPad.SetLogy()
    ROOT.gStyle.SetOptStat(0)
    
    for title, (path, color) in samples.items():
        if base_path in path:
            hist_name = f"goodCaloTower{sub_detector}_{variable}"
        else:
            hist_name = "histo_name" if sub_detector == "HFplus" else "histo_name_HFm"
        plot_hist(path, hist_name, color, title)
    
    canvas.Update()
    canvas.SaveAs(f"../plots/nee_threshold_{sub_detector}_{variable}_{suffix}.pdf")

if __name__ == "__main__":
    main()
