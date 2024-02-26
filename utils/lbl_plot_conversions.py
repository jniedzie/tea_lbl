from lbl_paths import merged_histograms_path

import ROOT

canvas = ROOT.TCanvas("canvas", "canvas", 1200, 1200)
canvas.Divide(3, 3)


skim = "initial"
# skim = "skimmed_lblSelections_onlyNee"

def addPlot(file_data, file_lbl, plot_name, iPad, x_min, x_max, y_min, y_max, logy=False, rebin=1, photon=True):
    canvas.cd(iPad)
    ROOT.gStyle.SetOptStat(0)
    ROOT.gPad.SetLogy(logy)
    ROOT.gPad.SetLeftMargin(0.15)

    base_name = "convertedPhoton_" if photon else "conversionElectron_"

    hists = {
        "converted_data": file_data.Get(base_name+plot_name),
        "converted_lbl": file_lbl.Get(base_name+plot_name),
        "unconverted_data": file_data.Get("un"+base_name+plot_name),
        "unconverted_lbl": file_lbl.Get("un"+base_name+plot_name),
    }

    legend = ROOT.TLegend(0.15, 0.7, 0.9, 0.9)
    colors = [ROOT.kRed, ROOT.kGreen+1, ROOT.kOrange+1, ROOT.kBlue]

    if plot_name == "et":
        print(f"data unconverted: {hists['unconverted_data'].Integral()}, converted: {hists['converted_data'].Integral()}, conversion fraction: {hists['converted_data'].Integral()/(hists['unconverted_data'].Integral()+hists['converted_data'].Integral()):.4f}")
        print(f"LbL MC unconverted: {hists['unconverted_lbl'].Integral()}, converted: {hists['converted_lbl'].Integral()}, conversion fraction: {hists['converted_lbl'].Integral()/(hists['unconverted_lbl'].Integral()+hists['converted_lbl'].Integral()):.4f}")

    for i, (name, hist) in enumerate(hists.items()):
        hist.Rebin(rebin)
        hist.Scale(rebin/hist.Integral())
        hist.Sumw2(False)
        hist.SetLineColor(colors[i])

        if i == 0:
            hist.Draw()
            hist.GetYaxis().SetRangeUser(y_min, y_max)
            hist.GetXaxis().SetRangeUser(x_min, x_max)
        else:
            hist.Draw("same")

        legend.AddEntry(hist, name, "l")

    return legend


def main():
    file_data = ROOT.TFile.Open(merged_histograms_path.format("collisionData", skim))
    file_lbl = ROOT.TFile.Open(merged_histograms_path.format("lbl", skim))

    addPlot(file_data, file_lbl, "et", 1, 0, 35, 1e-3, 10, logy=True, rebin=2)
    addPlot(file_data, file_lbl, "eta", 2, -4, 4, 0, 1, logy=False, rebin=4)
    addPlot(file_data, file_lbl, "phi", 3, -4, 4, 0, 1, logy=False, rebin=4)

    addPlot(file_data, file_lbl, "pt", 4, 0, 35, 1e-3, 1, logy=True, rebin=2, photon=False)
    addPlot(file_data, file_lbl, "eta", 5, -4, 4, 0, 1, logy=False, rebin=4, photon=False)
    addPlot(file_data, file_lbl, "phi", 6, -4, 4, 0, 1, logy=False, rebin=4, photon=False)

    addPlot(file_data, file_lbl, "nMissHits", 7, 0, 10, 0, 1, logy=False, rebin=1, photon=False)
    addPlot(file_data, file_lbl, "hOverE", 8, 0, 0.4, 1e-3, 2, logy=True, rebin=2, photon=False)
    legend = addPlot(file_data, file_lbl, "deltaEtaAtVertex", 9, 0, 0.1, 1e-3, 2, logy=True, rebin=1, photon=False)

    canvas.cd(1)
    legend.Draw()

    canvas.Update()
    canvas.SaveAs("../plots/conversions.pdf")


if __name__ == "__main__":
    main()


# data unconverted: 21483902, converted: 50076, conversion fraction: 0.0023
# LbL MC unconverted: 16728, converted: 440, conversion fraction: 0.0256
