from lbl_params import luminosity, luminosity_err, get_scale_factor

import ROOT

events_ZDC = 19689  # with ZDC cut
events_noZDC = 20161  # no ZDC cut

Eff = 0.0717
Eff_Error = 0.000782

input_path = "../utils/output_ZDC.root"

# xnxn_input_path = "../utils/output_new.root"
xnxn_input_path = "../utils/output_ZDC_weighted.root"
# xnxn_input_path = "../utils/output_ZDC0.9scaled.root"
# xnxn_input_path = "../utils/output_ZDC1.1scaled.root"

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
        7: 7,
    }

    bin_labels = {
        1: "0n0n",
        2: "0nXn",
        3: "0n1n",
        4: "1nXn",
        5: "1n1n",
        6: "XnXn",
        7: "Inclusive",
    }

    data_error = 0.03

    events = {}

    for i in range(1, len(bin_mapping)+1):
        index = bin_mapping[i]
        label = bin_labels[index]

        n_events = input_hist.GetBinContent(index)
        
        print(f"{label}: {n_events:.0f}")
        
        n_events_err = input_hist.GetBinError(index)
        value, stat, syst = get_cross_section(n_events, n_events_err)

        print(
            f"{label} &  ${value/1000:.3f} \pm {stat/1000:.1f}~(stat) \pm {syst/1000:.1f}~(syst) \mu b$ \\\\")

        # err = (stat**2 + syst**2)**0.5
        err = data_error * value
        output_hist.SetBinContent(i, value)
        output_hist.SetBinError(i, err)
        output_hist.GetXaxis().SetBinLabel(i, label)

        events[label] = [n_events, n_events_err]

    # events["0nXn"] = (events["0nXn_0n0n"][0] - events["0n0n"][0],
    #                   (events["0nXn_0n0n"][1]**2 + events["0n0n"][1]**2)**0.5)

    # events["1nXn"] = (events["1nXn_0n1n"][0] - events["0n1n"][0],
    #                   (events["1nXn_0n1n"][1]**2 + events["0n1n"][1]**2)**0.5)

    # events["XnXn"] = (events["Inclusive"][0] -
    #                   events["0nXn_0n0n"][0], events["0nXn_0n0n"][1])

    superchic_ratios = {
        "0n0n": (0.766, 0.0096),
        "0n1n": (2 * 0.032, 2 * 0.00039),
        "1n1n": (0.0045, 0.00006),
        "1nXn": (2 * 0.0149, 2 * 0.00018),
        "0nXn": (2 * 0.093, 2 * 0.0011),
        "XnXn": (0.0485, 0.00061),
    }

    # old, read directly from plots
    # starlight_ratios = {
    #     "0n0n": (0.62, 0.01),
    #     "1n1n": (0.01, 0.01),
    #     "0nXn": (0.32, 0.01),
    #     "XnXn": (0.06, 0.01),
    # }

    # new, from Oliver
    starlight_ratios = {
        "0n0n": (0.745, 0.01),
        "1n1n": (0.0037, 0.001),
        "0nXn": (0.191, 0.01),
        "XnXn": (0.059, 0.005),
    }

    # hardcoded updated ratios (with EMD corrections)
    data_ratios = {
        "0n0n": (0.75, 0.08),
        "0nXn": (0.198, 0.003),
        "0n1n": (0.046, 0.001),
        "XnXn": (0.062, 0.002),
        "1nXn": (0.038, 0.001),
        "1n1n": (0.006, 0.0),
        "Inclusive": (0, 0),
    }

    nice_labels = {
        "0nXn_0n0n": "0nXn + Xn0n + 0n0n",
        "1nXn_0n1n": "1nXn + Xn1n + 0n1n + 1n0n",
        "0n1n": "0n1n + 1n0n",
        "0nXn": "0nXn + Xn0n",
        "1nXn": "1nXn + Xn1n",
    }

    # sort events by first value, decreasing
    events = dict(
        sorted(events.items(), key=lambda item: item[1][0], reverse=True))

    ratio_hist_data = ROOT.TH1D("ratio_data", "ratio_data", 6, 0, 6)
    ratio_hist_superchic = ROOT.TH1D("ratio_superchic", "ratio_superchic", 6, 0, 6)
    ratio_hist_starlight = ROOT.TH1D("ratio_starlight", "ratio_starlight", 6, 0, 6)

    emd_shifts = {
        "0n0n": 0.110,
        "0nXn": -0.104,
        "0n1n": -0.0532,
        "XnXn": -0.0063,
        "1nXn": -0.00437,
        "1n1n": -0.0014546,
        "Inclusive": 0.0,
    }

    bin_swap = {
        3: 4,
        4: 3,
    }

    print("\n\n============================================================")
    for i, (key, value) in enumerate(events.items()):
        ratio = value[0] / events["Inclusive"][0]
        error = ratio * ((value[1]/value[0])**2 + (events["Inclusive"][1]/events["Inclusive"][0])**2)**0.5

        ratio += emd_shifts[key]
        error = (error**2 + (0.02*emd_shifts[key])**2)**0.5

        # error = value[1]

        label = nice_labels[key] if key in nice_labels else key

        print(f"{label} & ${100*ratio:.2f} \pm {100*error:.2f} $", end="")

        if key in superchic_ratios:
            print(
                f" & ${100*superchic_ratios[key][0]:.1f} \pm {100*superchic_ratios[key][1]:.1f} $", end="")
        else:
            print(" & -- ", end="")

        if key in starlight_ratios:
            print(
                f" & ${100*starlight_ratios[key][0]:.1f} \pm {100*starlight_ratios[key][1]:.1f} $\\\\")
        else:
            print(" & -- \\\\")

        index = i

        if i in bin_swap:
            index = bin_swap[i]
            

        ratio_hist_data.SetBinContent(index, ratio)
        ratio_hist_data.SetBinError(index, error)
        # ratio_hist_data.SetBinContent(index, data_ratios[key][0])
        # ratio_hist_data.SetBinError(index, data_ratios[key][1])
        ratio_hist_superchic.GetXaxis().SetBinLabel(index, label)

        if key in superchic_ratios:
            ratio_hist_superchic.SetBinContent(index, superchic_ratios[key][0])
            ratio_hist_superchic.SetBinError(index, superchic_ratios[key][1])

        if key in starlight_ratios:
            ratio_hist_starlight.SetBinContent(index, starlight_ratios[key][0])
            ratio_hist_starlight.SetBinError(index, starlight_ratios[key][1])




    canvas_ratios = ROOT.TCanvas("ratios", "ratios", 800, 600)
    canvas_ratios.cd()
    ROOT.gStyle.SetOptStat(0)
    canvas_ratios.SetLogy()
    ROOT.gPad.SetLeftMargin(0.15)
    ROOT.gPad.SetBottomMargin(0.25)

    ratio_hist_superchic.SetTitle("")
    ratio_hist_superchic.SetMarkerStyle(21)
    ratio_hist_superchic.SetMarkerSize(1.2)
    ratio_hist_superchic.SetMarkerColor(ROOT.kRed+2)
    ratio_hist_superchic.SetLineColor(ROOT.kRed+2)
    ratio_hist_superchic.GetXaxis().SetLabelSize(0.06)
    ratio_hist_superchic.GetXaxis().SetLabelOffset(0.01)
    ratio_hist_superchic.GetXaxis().SetTitle("Neutron multiplicity category")
    ratio_hist_superchic.GetXaxis().SetTitleSize(0.055)
    ratio_hist_superchic.GetXaxis().SetTitleOffset(1.8)
    ratio_hist_superchic.GetXaxis().CenterTitle()
    
    
    ratio_hist_superchic.GetYaxis().SetTitle("De-excitation ratio to inclusive")
    ratio_hist_superchic.GetYaxis().CenterTitle()
    ratio_hist_superchic.GetYaxis().SetLabelSize(0.05)
    ratio_hist_superchic.GetYaxis().SetTitleSize(0.06)
    ratio_hist_superchic.GetYaxis().SetLabelOffset(0.01)

    ratio_hist_superchic.GetYaxis().SetRangeUser(1e-3, 1)

    ratio_hist_superchic.Draw("PE")

    ratio_hist_starlight.SetMarkerStyle(21)
    ratio_hist_starlight.SetMarkerSize(1.2)
    ratio_hist_starlight.SetMarkerColor(ROOT.kGreen+2)
    ratio_hist_starlight.SetLineColor(ROOT.kGreen+2)
    ratio_hist_starlight.Draw("PE SAME")

    ratio_hist_data.SetMarkerStyle(20)
    ratio_hist_data.SetMarkerSize(1.0)
    ratio_hist_data.SetMarkerColor(ROOT.kBlack)
    ratio_hist_data.SetLineColor(ROOT.kBlack)
    ratio_hist_data.Draw("PE same")

    legend = ROOT.TLegend(0.6, 0.75, 0.89, 0.89)
    legend.AddEntry(ratio_hist_data, "Data", "PEL")
    legend.AddEntry(ratio_hist_superchic, "SUPERCHIC 4.2", "PEL")
    legend.AddEntry(ratio_hist_starlight, "STARLIGHT 3.13", "PEL")
    legend.SetBorderSize(0)
    
    legend.Draw()

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
    lumi_text.DrawLatexNDC(
        0.88, 0.92, f"{luminosity/1000:.2f} nb^{{-1}} (PbPb @ 5.02 TeV)")

    canvas_ratios.SaveAs("../plots/qed_ratios.pdf")
    canvas_ratios.SaveAs("../plots/qed_ratios.C")

    print("============================================================\n\n")

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
    lumi_text.DrawLatexNDC(
        0.88, 0.92, f"{luminosity/1000:.2f} nb^{{-1}} (PbPb @ 5.02 TeV)")

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

    qed_zdc_file = ROOT.TFile.Open(input_path)

    hist_max = qed_zdc_file.Get("hZDC_sum_peak_maxData")
    hist_sum = qed_zdc_file.Get("hZDC_sum_peakData")

    # hist_max = qed_zdc_file.Get("hZDC_sum_maxData")
    # hist_sum = qed_zdc_file.Get("hZDC_sumData")

    # hist_cross_section_max = get_cross_section_histogram(hist_max, "max")
    # hist_cross_section_sum = get_cross_section_histogram(hist_sum, "sum")

    # save_canvas(
    #     hist_cross_section_max,
    #     "QED cross-section, X = max_{n}(ZDC^{+}, ZDC^{-})",
    # )
    # save_canvas(
    #     hist_cross_section_sum,
    #     "QED cross-section, X = #Sigma_{n}(ZDC^{+}, ZDC^{-})",
    # )

    qed_xnxn_file = ROOT.TFile.Open(xnxn_input_path)
    hist_xnxn = qed_xnxn_file.Get("hZDC_xnxnData")
    hist_xnxn_cross_section = get_xnxn_cross_section_histogram(
        hist_xnxn, "xnxn")

    save_canvas(hist_xnxn_cross_section, "")


if __name__ == "__main__":
    main()
