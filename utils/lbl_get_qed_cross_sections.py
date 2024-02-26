from lbl_params import luminosity, luminosity_err, get_scale_factor

import ROOT

events_ZDC = 19809  # with ZDC cut
events_noZDC = 20161  # no ZDC cut

Eff = 0.0717
Eff_Error = 0.000782


def get_cross_section(n_events, n_events_err):
    scale_factor, sf_error = get_scale_factor(photon=False)

    correction_factor = scale_factor * Eff
    correction_factor_err = correction_factor * \
        ((sf_error/scale_factor)**2 + (Eff_Error/Eff)**2)**0.5

    cross_section = n_events / (correction_factor * luminosity/1000.)

    cross_section_syst = cross_section * \
        ((correction_factor_err/correction_factor)
         ** 2 + (luminosity_err/luminosity)**2)**0.5

    cross_section_stat = n_events_err / (correction_factor * luminosity/1000.)

    return cross_section, cross_section_stat, cross_section_syst


def get_cross_section_histogram(input_hist, name):
    output_hist = ROOT.TH1D(name, name, 5, 0, 5)

    for i in range(1, input_hist.GetNbinsX()+1):
        n_events = input_hist.GetBinContent(i)
        n_events_err = input_hist.GetBinError(i)
        value, stat, syst = get_cross_section(n_events, n_events_err)

        print(
            f"${value/1000:.1f} \pm {stat/1000:.1f} (stat) \pm {syst/1000:.1f} (syst) \mu b$ \\\\")

        err = (stat**2 + syst**2)**0.5
        output_hist.SetBinContent(i, value)
        output_hist.SetBinError(i, err)

    output_hist.Scale(1e-3)
    output_hist.SetTitle("")

    output_hist.GetYaxis().SetTitle(
        "#sigma(#gamma#gamma#rightarrow e^{+}e^{-}+Xn) [#mub/(bin width)]")
    output_hist.GetXaxis().SetBinLabel(1, "0n")
    output_hist.GetXaxis().SetBinLabel(2, "1n")
    output_hist.GetXaxis().SetBinLabel(3, "2n")
    output_hist.GetXaxis().SetBinLabel(4, "3n")
    output_hist.GetXaxis().SetBinLabel(5, "#geq 4n")

    output_hist.SetMarkerStyle(21)
    output_hist.SetMarkerSize(1.0)
    output_hist.SetMarkerColor(ROOT.kCyan+2)
    output_hist.SetLineColor(ROOT.kCyan+2)

    # make labels larger and adjust offset
    output_hist.GetXaxis().SetLabelSize(0.06)
    output_hist.GetXaxis().SetLabelOffset(0.01)

    output_hist.GetYaxis().SetLabelSize(0.05)
    output_hist.GetYaxis().SetTitleSize(0.06)
    output_hist.GetYaxis().SetLabelOffset(0.01)

    return output_hist


def get_xnxn_cross_section_histogram(input_hist, name):
    output_hist = ROOT.TH1D(name, name, 6, 0, 6)

    bin_mapping = {
        1: 6,
        2: 2,
        3: 1,
        4: 4,
        5: 3,
        6: 5,
    }

    bin_labels = {
        1: "0n0n",
        2: "0nXn",
        3: "0n1n",
        4: "1nXn",
        5: "1n1n",
        6: "XnXn",
    }

    for i in range(1, 7):
        index = bin_mapping[i]
        # index = i
        
        n_events = input_hist.GetBinContent(index)
        n_events_err = input_hist.GetBinError(index)
        value, stat, syst = get_cross_section(n_events, n_events_err)

        print(
            f"{bin_labels[index]} &  ${value/1000:.1f} \pm {stat/1000:.1f}~(stat) \pm {syst/1000:.1f}~(syst) \mu b$ \\\\")

        err = (stat**2 + syst**2)**0.5
        output_hist.SetBinContent(i, value)
        output_hist.SetBinError(i, err)
        output_hist.GetXaxis().SetBinLabel(i, bin_labels[index])

    output_hist.Scale(1e-3)
    output_hist.SetTitle("")

    output_hist.GetYaxis().SetTitle(
        "#sigma(#gamma#gamma#rightarrow e^{+}e^{-}+XnYn) [#mub]")

    
    output_hist.SetMarkerStyle(21)
    output_hist.SetMarkerSize(1.0)
    output_hist.SetMarkerColor(ROOT.kCyan+2)
    output_hist.SetLineColor(ROOT.kCyan+2)

    # make labels larger and adjust offset
    output_hist.GetXaxis().SetLabelSize(0.06)
    output_hist.GetXaxis().SetLabelOffset(0.01)

    output_hist.GetYaxis().SetLabelSize(0.05)
    output_hist.GetYaxis().SetTitleSize(0.06)
    output_hist.GetYaxis().SetLabelOffset(0.01)

    return output_hist


def save_canvas(hist, title):
    canvas = ROOT.TCanvas(title, title, 800, 600)
    canvas.cd()
    ROOT.gStyle.SetOptStat(0)
    ROOT.gPad.SetLogy()
    ROOT.gPad.SetLeftMargin(0.15)
    hist.Draw("PE")
    hist.SetTitle(title)
    hist.GetYaxis().SetRangeUser(1, 1000)

    # Add CMS Preliminary text at the top of the plot
    cms_text = ROOT.TLatex()
    cms_text.SetTextFont(61)
    cms_text.SetTextSize(0.05)
    cms_text.DrawLatexNDC(0.17, 0.92, "CMS")
    cms_text.SetTextFont(52)
    cms_text.DrawLatexNDC(0.17+0.08, 0.92, "Preliminary")

    # add the luminosity and energy information at the top-right of the plot
    lumi_text = ROOT.TLatex()
    lumi_text.SetTextAlign(31)
    lumi_text.SetTextSize(0.04)
    lumi_text.SetTextFont(42)
    lumi_text.DrawLatexNDC(0.88, 0.92, f"{luminosity/1000:.2f} nb^{{-1}} (PbPb @ 5.02 TeV)")

    ROOT.gPad.GetFrame().SetLineWidth(2)
    ROOT.gPad.GetFrame().SetBorderSize(2)
    ROOT.gPad.GetFrame().SetBorderMode(0)
    ROOT.gPad.GetFrame().SetFillColor(0)
    ROOT.gPad.GetFrame().SetFillStyle(0)
    ROOT.gPad.RedrawAxis()
    canvas.RedrawAxis()
    canvas.Update()
    canvas.SaveAs(f"../plots/qed_cross_section_{hist.GetName()}.pdf")


def main():
    ROOT.gROOT.SetBatch(True)

    events_ZDC_err = events_ZDC**0.5
    events_noZDC_err = events_noZDC**0.5

    sigma_ZDC, sigma_ZDC_stat, sigma_ZDC_syst = get_cross_section(
        events_ZDC, events_ZDC_err)
    sigma_noZDC, sigma_noZDC_stat, sigma_noZDC_syst = get_cross_section(
        events_noZDC, events_noZDC_err)

    print("\n\n============================================================")
    print(f"QED cross-section with ZDC: {sigma_ZDC/1000:.1f} +/-", end="")
    print(f"{sigma_ZDC_stat/1000:.1f} (stat) +/- {sigma_ZDC_syst/1000:.1f} (syst) nb")
    print(f"QED cross-section without ZDC: {sigma_noZDC/1000:.1f} +/-", end="")
    print(f"{sigma_noZDC_stat/1000:.1f} (stat) +/- {sigma_noZDC_syst/1000:.1f} (syst) nb")
    print("============================================================\n\n")

    qed_zdc_file = ROOT.TFile.Open("../utils/output_ZDC.root")

    hist_max = qed_zdc_file.Get("hZDC_sum_peak_maxData")
    hist_sum = qed_zdc_file.Get("hZDC_sum_peakData")

    # hist_max = qed_zdc_file.Get("hZDC_sum_maxData")
    # hist_sum = qed_zdc_file.Get("hZDC_sumData")

    hist_cross_section_max = get_cross_section_histogram(hist_max, "max")
    hist_cross_section_sum = get_cross_section_histogram(hist_sum, "sum")

    save_canvas(
        hist_cross_section_max,
        "QED cross-section, X = max_{n}(ZDC^{+}, ZDC^{-})",
    )
    save_canvas(
        hist_cross_section_sum,
        "QED cross-section, X = #Sigma_{n}(ZDC^{+}, ZDC^{-})",
    )

    qed_xnxn_file = ROOT.TFile.Open("../utils/output_new.root")
    hist_xnxn = qed_xnxn_file.Get("hZDC_xnxnData")
    hist_xnxn_cross_section = get_xnxn_cross_section_histogram(
        hist_xnxn, "xnxn")

    save_canvas(hist_xnxn_cross_section,"")


if __name__ == "__main__":
    main()
