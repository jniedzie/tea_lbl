import ROOT
from array import array
import numpy as np
from lbl_params import cep_scaling_min_acoplanarity, n_acoplanarity_bins, total_uncertainty_lbl_run2
from lbl_paths import skim

legend_header = "  #gamma#gamma#rightarrow#gamma#gamma"
# legend_header = "  #gamma#gamma#rightarrow#gamma#gamma (0n0n)"
# legend_header = "  #gamma#gamma#rightarrow#gamma#gamma (0n0n, 0n1n, 1n0n, 1n1n)"

input_file_path = f"../combine/significance_histograms_{skim}_nBins{n_acoplanarity_bins}.root"

min_aco = 1e-3
y_max = 22
ratio_max = 3.4

def transform_hist(hist):

    bins = [1e-3]
    for i in range(1, hist.GetNbinsX()+1):
        bins.append(hist.GetBinLowEdge(i) + hist.GetBinWidth(i))

    new_hist = ROOT.TH1D(hist.GetName(), hist.GetTitle(), hist.GetNbinsX(), array('d', bins))

    print(f"new bins: {bins}")
    
    for i in range(1, hist.GetNbinsX()+1):
        new_hist.SetBinContent(i, hist.GetBinContent(i))
        new_hist.SetBinError(i, hist.GetBinError(i))
        
    new_hist.SetBinErrorOption(ROOT.TH1.kPoisson)

    return new_hist


def hist_to_graph(hist):

    n = hist.GetNbinsX()
    x = []
    y = []
    ex = []
    ey_up = []
    ey_down = []

    for i in range(1, n+1):
        bin_low_edge = hist.GetBinLowEdge(i)
        bin_up_edge = hist.GetBinLowEdge(i) + hist.GetBinWidth(i)

        print(
            f"bin_low_edge: {bin_low_edge:.1e}, bin_up_edge: {bin_up_edge:.1e}")

        if bin_low_edge == 0:
            bin_low_edge = min_aco

        bin_center_log = 10**((np.log10(bin_low_edge) +
                              np.log10(bin_up_edge)) / 2)

        x.append(bin_center_log)
        y.append(hist.GetBinContent(i))
        ex.append(0)
        ey_up.append(hist.GetBinErrorUp(i))
        ey_down.append(hist.GetBinErrorLow(i))
        
        if y[-1] == 0:
            y[-1] = -999
            ey_up[-1] = 0
            ey_down[-1] = 0

    return ROOT.TGraphAsymmErrors(n, array('d', x), array('d', y), array('d', ex), array('d', ex), array('d', ey_down), array('d', ey_up))


def main():
    ROOT.gROOT.SetBatch(True)
    file = ROOT.TFile.Open(input_file_path)
    hist_data = file.Get("data_obs")
    hist_cep = file.Get("cep")
    hist_qed = file.Get("qed")
    hist_qed_sl = file.Get("qed_starlight")
    hist_lbl = file.Get("lbl")

    hist_data.SetBinErrorOption(ROOT.TH1.kPoisson)
    hist_cep.SetBinErrorOption(ROOT.TH1.kPoisson)
    hist_qed.SetBinErrorOption(ROOT.TH1.kPoisson)
    hist_qed_sl.SetBinErrorOption(ROOT.TH1.kPoisson)
    hist_lbl.SetBinErrorOption(ROOT.TH1.kPoisson)

    hist_data = transform_hist(hist_data)
    
    # for i in range(1, hist_data.GetNbinsX()+1):
    #     if hist_data.GetBinContent(i) == 0:
    #         hist_data.SetBinContent(i, -999)
    #         hist_data.SetBinError(i, 0)
    
    hist_cep = transform_hist(hist_cep)
    hist_qed = transform_hist(hist_qed)
    hist_qed_sl = transform_hist(hist_qed_sl)
    hist_lbl = transform_hist(hist_lbl)

    graph_data = hist_to_graph(hist_data)

    hist_data.SetLineColor(ROOT.kBlack)
    hist_data.SetMarkerColor(ROOT.kBlack)
    hist_data.SetMarkerStyle(20)

    graph_data.SetLineColor(ROOT.kBlack)
    graph_data.SetMarkerColor(ROOT.kBlack)
    graph_data.SetMarkerStyle(20)

    hist_cep.SetFillColor(ROOT.kAzure-4)
    hist_lbl.SetFillColor(ROOT.kOrange+1)
    hist_qed.SetFillColor(ROOT.kYellow)
    hist_qed.SetLineColor(ROOT.kYellow)
    hist_qed_sl.SetFillColor(ROOT.kYellow)

    stack = ROOT.THStack("stack", "stack")
    stack.Add(hist_cep)
    stack.Add(hist_qed)
    stack.Add(hist_qed_sl)
    stack.Add(hist_lbl)

    sum_hist = hist_cep.Clone()
    sum_hist.Add(hist_lbl)
    sum_hist.Add(hist_qed)
    sum_hist.Add(hist_qed_sl)
    sum_hist.SetFillStyle(3004)
    sum_hist.SetFillColor(ROOT.kBlack)

    sum_hist.SetBinErrorOption(ROOT.TH1.kPoisson)

    for i in range(1, sum_hist.GetNbinsX()+1):
        bin_content = sum_hist.GetBinContent(i)
        stat_error = sum_hist.GetBinError(i)
        syst_error = bin_content * (total_uncertainty_lbl_run2-1)

        # print(f"bin: {i}, content: {bin_content}, stat_error: {stat_error}, syst_error: {syst_error}")
        
        # value = sum_hist.GetXaxis().GetBinCenter(i)
        # if value > cep_scaling_min_acoplanarity:
        # sum_hist.SetBinError(i, (stat_error**2 + syst_error**2)**(1/2))
        # sum_hist.SetBinError(i, stat_error)
        # else:
        sum_hist.SetBinError(i, syst_error)

    # ============================================================================
    canvas = ROOT.TCanvas("canvas", "canvas", 800, 600)
    canvas.cd()

    pad1 = ROOT.TPad("pad1", "pad1", 0, 0.3, 1, 1.0)
    pad1.SetBottomMargin(0.017)
    pad1.Draw()
    pad1.cd()
    pad1.SetLogx()

    stack.Draw("hist")
    sum_hist.Draw("e2same")
    graph_data.Draw("PEsame")

    stack.SetTitle("")
    stack.GetYaxis().SetTitle("Events")
    stack.GetYaxis().SetTitleSize(20)
    stack.GetYaxis().SetTitleFont(43)
    stack.GetYaxis().SetTitleOffset(1.55)

    stack.GetYaxis().SetLabelFont(43)
    stack.GetYaxis().SetLabelSize(20)

    stack.SetMaximum(y_max)
    stack.SetMinimum(0)
    stack.GetXaxis().SetLabelSize(0)

    canvas.cd()
    pad2 = ROOT.TPad("pad2", "pad2", 0, 0.0, 1, 0.3)
    pad2.SetTopMargin(0.017)
    pad2.SetBottomMargin(0.3)
    pad2.Draw()
    pad2.cd()
    pad2.SetLogx()
    ROOT.gStyle.SetOptStat(0)

    ratio_band = sum_hist.Clone()
    
    ratio_band.SetBinErrorOption(ROOT.TH1.kPoisson)
    
    ratio_band.Divide(sum_hist)

    ratio_band.SetTitle("")
    ratio_band.GetYaxis().SetTitle("Data / MC")
    ratio_band.GetYaxis().SetNdivisions(505)
    ratio_band.GetYaxis().SetTitleSize(20)
    ratio_band.GetYaxis().SetTitleFont(43)
    ratio_band.GetYaxis().SetTitleOffset(1.55)
    ratio_band.GetYaxis().SetLabelFont(43)
    ratio_band.GetYaxis().SetLabelSize(15)

    ratio_band.GetXaxis().SetLabelFont(43)
    ratio_band.GetXaxis().SetLabelSize(20)
    ratio_band.GetXaxis().SetMoreLogLabels()
    ratio_band.GetXaxis().SetNoExponent()
    ratio_band.GetXaxis().SetRangeUser(1e-3, 1)
    ratio_band.GetXaxis().SetNdivisions(505)
    ratio_band.GetXaxis().SetLabelOffset(0.03)

    ratio_band.GetXaxis().SetTitleSize(20)
    ratio_band.GetXaxis().SetTitleFont(43)
    ratio_band.GetXaxis().SetTitleOffset(1.2)
    ratio_band.GetXaxis().SetTitle("A^{#gamma#gamma}_{#phi}")
    
    ratio_band.Draw("e2")
    ratio_band.GetXaxis().SetRangeUser(1e-3, 0.1)
    
    ratio_band.SetMinimum(0.0)
    ratio_band.SetMaximum(ratio_max)

    ratio = hist_data.Clone()
    ratio.SetBinErrorOption(ROOT.TH1.kPoisson)
    
    ratio.Divide(sum_hist)
    ratio = hist_to_graph(ratio)
    ratio.SetMarkerStyle(20)
    ratio.SetMarkerColor(ROOT.kBlack)
    ratio.SetMarkerSize(0.8)
    ratio.Draw("PE0same")

    pave = ROOT.TPaveText(1e-3-3e-4, -0.5, 1e-3+5e-4, -0.2, "NB")  # "NB" option for no border
    pave.SetFillColor(ROOT.kWhite)  # Set the fill color to white
    pave.SetTextColor(ROOT.kBlack)
    pave.SetTextFont(43)
    pave.SetTextSize(15)  # Set the text size
    pave.AddText("0")  # Add the new label text
    pave.SetTextAlign(22)  # Center alignment
    # pave.Draw()

    canvas.Update()
    canvas.RedrawAxis()

    # ============================================================================

    pad1.cd()
    legend = ROOT.TLegend(0.27, 0.50, 0.89, 0.89)
    # legend.SetHeader(legend_header)
    
    legend.SetBorderSize(0)
    legend.AddEntry(hist_data, "Data", "PE")
    legend.AddEntry(hist_lbl, "#gamma#gamma #rightarrow #gamma#gamma (SUPERCHIC 3.03)", "F")
    legend.AddEntry(hist_qed_sl, "#gamma#gamma #rightarrow e^{+}e^{-} (SUPERCHIC 3.03 and STARLIGHT 3.13 averaged)", "F")
    # legend.AddEntry(hist_qed, "QED+FSR (SuperChic+PHOTOS)", "F")
    # legend.AddEntry(hist_qed_sl, "QED (Starlight)", "F")
    legend.AddEntry(hist_cep, "gg #rightarrow #gamma#gamma (SUPERCHIC 3.03, scaled to data)", "F")
    legend.Draw()

    # add CMS Preliminary label on top of the plot
    label = ROOT.TLatex()
    label.SetTextSize(0.045)
    label.DrawLatexNDC(0.12, 0.92, "CMS")
    label.SetTextFont(52)
    label.DrawLatexNDC(0.2, 0.92, "Preliminary")
    label.SetTextSize(0.035)
    label.SetTextFont(42)
    label.DrawLatexNDC(0.6, 0.92, "1.6 nb^{-1} (PbPb @ 5.02 TeV)")

    canvas.SaveAs(input_file_path.replace("../combine/", "../plots/").replace(".root", ".pdf"))
    canvas.SaveAs(input_file_path.replace("../combine/", "../plots/").replace(".root", ".C"))


if __name__ == "__main__":
    main()
