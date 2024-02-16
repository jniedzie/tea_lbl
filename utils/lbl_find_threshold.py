import ROOT

input_path = "/nfs/dust/cms/user/jniedzie/light_by_light/ntuples/qed/merged_skimmed_qedSelections_histograms.root"
# input_path = "./skimmed_qedSelections_qed_histograms.root"

canvas = ROOT.TCanvas("canvas", "canvas", 800, 600)


def get_threshold(hist, fraction=0.99):
    total = hist.Integral()
    threshold = 0

    for i in range(1, hist.GetNbinsX()):
        if hist.Integral(1, i) / total > fraction:
            threshold = hist.GetBinLowEdge(i)
            break

    print(f"Threshold: {threshold}")
    return threshold


def main():
    file = ROOT.TFile.Open(input_path)
    hist = file.Get("leadingGenPhoton_energy")
    hist_barrel = file.Get("leadingGenPhotonBarrel_energy")
    hist_barrelEndcap = file.Get("leadingGenPhotonBarrelEndcap_energy")
    # hist = file.Get("genPhoton_et")

    canvas.cd()
    ROOT.gPad.SetLogy()
    ROOT.gStyle.SetOptStat(0)

    # fun = ROOT.TF1("fun", "[0]", 0, 5)
    # fun.SetParameter(0, 1)
    # hist.Fit("fun", "R", "", 0.5, 10)

    hist.Draw()
    hist.SetTitle("")
    hist.GetXaxis().SetTitle("Leading gen-photon energy [GeV]")
    hist.GetYaxis().SetTitle("Events")
    # hist.GetXaxis().SetRangeUser(0, 5)

    hist_barrel.SetLineColor(ROOT.kGreen+1)
    hist_barrel.Draw("same")

    hist_barrelEndcap.SetLineColor(ROOT.kCyan+1)
    hist_barrelEndcap.Draw("same")

    threshold = get_threshold(hist, 0.99)
    line = ROOT.TLine(threshold, 0, threshold, hist.GetMaximum())
    line.SetLineColor(ROOT.kBlue)
    line.SetLineWidth(2)
    line.Draw()
    
    threshold = get_threshold(hist_barrel, 0.99)
    line_barrel = ROOT.TLine(threshold, 0, threshold, hist.GetMaximum())
    line_barrel.SetLineColor(ROOT.kGreen+1)
    line_barrel.SetLineWidth(2)
    line_barrel.Draw()
    
    threshold = get_threshold(hist_barrelEndcap, 0.99)
    line_barrelEndcap = ROOT.TLine(threshold, 0, threshold, hist.GetMaximum())
    line_barrelEndcap.SetLineColor(ROOT.kCyan+1)
    line_barrelEndcap.SetLineWidth(2)
    line_barrelEndcap.Draw()

    legend = ROOT.TLegend(0.7, 0.7, 0.9, 0.9)
    legend.AddEntry(hist, "All photons", "l")
    legend.AddEntry(hist_barrel, "Barrel photons", "l")
    legend.AddEntry(hist_barrelEndcap, "Barrel+Endcap photons", "l")
    legend.Draw()

    canvas.Update()
    canvas.SaveAs("../plots/threshold.pdf")


if __name__ == "__main__":
    main()
