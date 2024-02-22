from lbl_params import luminosity, luminosity_err, get_scale_factor

import ROOT

events_ZDC = 16068  # with ZDC cut
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
            f"${value/1000:.1f} \pm {stat/1000:.1f} (stat) \pm {syst/1000:.1f} (syst) \mu b$")

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

    output_hist.SetMarkerStyle(20)
    output_hist.SetMarkerSize(1.0)
    output_hist.SetMarkerColor(ROOT.kBlack)

    output_hist.SetLineColor(ROOT.kBlack)

    return output_hist


def save_canvas(hist, title):
    canvas = ROOT.TCanvas(title, title, 800, 600)
    canvas.cd()
    ROOT.gStyle.SetOptStat(0)
    ROOT.gPad.SetLogy()
    hist.Draw("PE")
    hist.SetTitle(title)
    hist.GetYaxis().SetRangeUser(1, 300)
    canvas.SaveAs(f"../plots/cross_section_{hist.GetName()}.pdf")


def main():

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


if __name__ == "__main__":
    main()
