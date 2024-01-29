import ROOT
from lbl_params import reference_alp_cross_section

# with 100 bins in mass spectrum, with uncertainties on zeros
# cross_section_limits = {
#     #    obs        -2σ       -1σ       exp       +1σ        +2σ
#     5:  (123.9224 , 45.4385 , 65.0553 , 97.7500 , 148.4026 , 215.2647 ),
#     6:  (37.4569  , 13.7744 , 18.8852 , 27.1250 , 39.3427  , 54.6778  ),
#     9:  (11.5574  , 5.5107  , 7.4520  , 10.6875 , 15.5014  , 21.6764  ),
#     11: (1.1479   , 2.0533  , 2.8478  , 4.1719  , 6.2505   , 9.0912   ),
#     14: (0.6264   , 1.3472  , 1.8737  , 2.7812  , 4.2335   , 6.2300   ),
#     16: (2.5596   , 1.2689  , 1.7496  , 2.5781  , 3.8627   , 5.6182   ),
#     22: (0.9501   , 0.5573  , 0.8173  , 1.2969  , 2.1343   , 3.3923   ),
#     30: (1.3181   , 0.5629  , 0.8429  , 1.3594  , 2.2155   , 3.3994   ),
#     50: (1.2758   , 1.8175  , 2.1586  , 2.1641  , 3.5270   , 6.4613   ),
#     90: (4.7949   , 2.1797  , 3.0311  , 4.3594  , 6.5141   , 9.6481   ),
# }

# with 100 bins in mass spectrum, no uncertainties on zeros
cross_section_limits = {
    5: (122.0525, 48.7266, 67.5791, 99.0, 148.3273, 214.5445),
    6: (35.4081, 13.793, 18.7531, 26.75, 38.6922, 53.8532),
    9: (11.8358, 5.4624, 7.4267, 10.5938, 15.4076, 21.6444),
    11: (4.4112, 2.0457, 2.8371, 4.1562, 6.2437, 9.0664),
    14: (3.0349, 1.3472, 1.8737, 2.7812, 4.2335, 6.2135),
    16: (1.8193, 0.9075, 1.2889, 1.9688, 3.0988, 4.7007),
    22: (0.8701, 0.5522, 0.8099, 1.2852, 2.115, 3.3617),
    30: (0.7121, 0.333, 0.5164, 0.8789, 1.5445, 2.5581),
    50: (0.6094, 0.1868, 0.3259, 0.6211, 1.1905, 1.8832),
    90: (0.6661, 0.1957, 0.347, 0.668, 1.2857, 2.0254)
}

# with 200 bins in mass spectrum, with uncertainties on zeros
# cross_section_limits = {
#     #    obs        -2σ       -1σ       exp       +1σ        +2σ
#     5:  (116.9964, 46.2612, 65.6164, 97.8750, 147.4220, 214.3087),
#     6:  (26.6379, 11.8752, 16.4928, 23.9375, 35.0057, 49.3226),
#     9:  (11.0318, 5.4946, 7.4302, 10.6562, 15.4561, 21.6130),
#     11: (1.0658, 2.0226, 2.8051, 4.1094, 6.1897, 8.9733),
#     14: (2.5406, 1.1719, 1.6595, 2.5000, 3.8851, 5.8308),
#     16: (2.8537, 1.1694, 1.6637, 2.5156, 3.8693, 5.7152),
#     22: (1.1706, 0.5878, 0.8691, 1.4062, 2.3592, 3.6621),
#     30: (2.6047, 1.4111, 1.8683, 2.6562, 3.8315, 5.6724),
#     50: (4.5030, 2.1951, 3.0968, 4.6250, 6.9663, 10.4874),
#     90: (4.1502, 3.2444, 4.2902, 6.0625, 9.1315, 13.4926),
# }

# with 200 bins in mass spectrum, no uncertainties on zeros
# cross_section_limits = {
#     #    obs        -2σ       -1σ       exp       +1σ        +2σ
#     5:  (115.4806, 48.2344, 66.8965, 98.0000, 146.8290, 211.7869),
#     6:  (27.0507, 12.3105, 16.6472, 23.8750, 34.6288, 48.7198),
#     9:  (11.9368, 5.4302, 7.3829, 10.5312, 15.2748, 21.4249),
#     11: (4.5146, 2.0149, 2.7782, 4.0938, 6.1498, 8.9301),
#     14: (2.2903, 1.1646, 1.6492, 2.4844, 3.8510, 5.7607),

#     16: (2.0063, 0.8036, 1.1556, 1.8047, 2.8837, 4.4502),
#     22: (0.8613, 0.5372, 0.7919, 1.2617, 2.0966, 3.3201),
#     30: (0.6919, 0.2825, 0.4564, 0.8125, 1.4667, 2.4629),
#     50: (0.6075, 0.1821, 0.3202, 0.6133, 1.1804, 1.8596),
#     90: (0.6661, 0.1957, 0.3470, 0.6680, 1.2857, 2.0254),
# }


def main():
    scale = reference_alp_cross_section * 1e3  # convert from μb to nb

    # crate a TGraph of obs cross section limit vs. mass
    obs_graph = ROOT.TGraph()
    obs_graph.SetLineColor(ROOT.kBlack)
    obs_graph.SetLineWidth(2)
    obs_graph.SetLineStyle(1)

    exp_graph = ROOT.TGraphAsymmErrors()
    exp_graph.SetLineColor(ROOT.kBlack)
    exp_graph.SetLineWidth(2)
    exp_graph.SetLineStyle(2)

    exp_graph_1sigma = ROOT.TGraphAsymmErrors()
    exp_graph_1sigma.SetLineWidth(0)
    exp_graph_1sigma.SetFillColorAlpha(ROOT.kGreen+1, 1.0)

    exp_graph_2sigma = ROOT.TGraphAsymmErrors()
    exp_graph_2sigma.SetLineWidth(0)
    exp_graph_2sigma.SetFillColorAlpha(ROOT.kYellow+1, 1.0)

    for i, mass in enumerate(cross_section_limits):
        obs_graph.SetPoint(i, mass, cross_section_limits[mass][0]*scale)

        exp_graph.SetPoint(i, mass, cross_section_limits[mass][3]*scale)

        exp_graph_1sigma.SetPoint(i, mass, cross_section_limits[mass][3]*scale)
        exp_graph_1sigma.SetPointError(
            i, 0, 0,
            (cross_section_limits[mass][3] -
             cross_section_limits[mass][2])*scale,
            (cross_section_limits[mass][4] -
             cross_section_limits[mass][3])*scale
        )

        exp_graph_2sigma.SetPoint(i, mass, cross_section_limits[mass][3]*scale)
        exp_graph_2sigma.SetPointError(
            i, 0, 0,
            (cross_section_limits[mass][3] -
             cross_section_limits[mass][1])*scale,
            (cross_section_limits[mass][5] -
             cross_section_limits[mass][3])*scale
        )

    canvas = ROOT.TCanvas("canvas", "", 800, 600)
    canvas.cd()
    canvas.SetLogx()
    canvas.SetLogy()

    exp_graph_2sigma.Draw("A3")
    exp_graph_1sigma.Draw("3same")
    exp_graph.Draw("Lsame")
    obs_graph.Draw("Lsame")

    exp_graph_2sigma.GetXaxis().SetTitle("m_{a} [GeV]")
    exp_graph_2sigma.GetYaxis().SetTitle(
        "#sigma_{pp #rightarrow a #rightarrow #gamma #gamma} [nb]")

    # set x and y axes limits
    exp_graph_2sigma.GetXaxis().SetLimits(5, 100)
    exp_graph_2sigma.SetMaximum(4000)
    exp_graph_2sigma.SetMinimum(0.4)

    legend = ROOT.TLegend(0.55, 0.65, 0.9, 0.9)
    legend.SetBorderSize(0)
    legend.SetFillStyle(0)
    legend.SetTextFont(42)
    legend.SetTextSize(0.04)
    legend.AddEntry(obs_graph, "Observed", "L")
    legend.AddEntry(exp_graph, "Expected", "L")
    legend.AddEntry(exp_graph_1sigma, "Expected #pm 1 #sigma", "F")
    legend.AddEntry(exp_graph_2sigma, "Expected #pm 2 #sigma", "F")
    legend.Draw()

    canvas.Update()
    canvas.SaveAs("../plots/limits_cross_section.pdf")


if __name__ == "__main__":
    main()
