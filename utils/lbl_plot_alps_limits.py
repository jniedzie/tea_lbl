import ROOT
import math

from lbl_params import reference_alp_cross_section
from lbl_helpers import get_alp_coupling

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
# cross_section_limits = {
#     5: (122.0525, 48.7266, 67.5791, 99.0, 148.3273, 214.5445),
#     6: (35.4081, 13.793, 18.7531, 26.75, 38.6922, 53.8532),
#     9: (11.8358, 5.4624, 7.4267, 10.5938, 15.4076, 21.6444),
#     11: (4.4112, 2.0457, 2.8371, 4.1562, 6.2437, 9.0664),
#     14: (3.0349, 1.3472, 1.8737, 2.7812, 4.2335, 6.2135),
#     16: (1.8193, 0.9075, 1.2889, 1.9688, 3.0988, 4.7007),
#     22: (0.8701, 0.5522, 0.8099, 1.2852, 2.115, 3.3617),
#     30: (0.7121, 0.333, 0.5164, 0.8789, 1.5445, 2.5581),
#     50: (0.6094, 0.1868, 0.3259, 0.6211, 1.1905, 1.8832),
#     90: (0.6661, 0.1957, 0.347, 0.668, 1.2857, 2.0254)
# }

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

# 2015 + 2018
# cross_section_limits = {
#     5: (28.8656, 16.3818, 22.8481, 34.375, 52.8727, 78.4993),
#     6: (6.2088, 3.4858, 4.8835, 7.375, 11.4024, 16.9574),
#     9: (2.2086, 1.3151, 1.8909, 2.9531, 4.7188, 7.2156),
#     11: (2.3425, 0.9062, 1.2993, 2.0, 3.148, 4.7294),
#     14: (1.2965, 0.5838, 0.8606, 1.3711, 2.2127, 3.4203),
#     16: (0.8875, 0.3346, 0.5456, 0.9414, 1.6169, 2.5999),
#     22: (0.5306, 0.2625, 0.418, 0.7148, 1.2391, 2.0204),
#     30: (0.4515, 0.1881, 0.3047, 0.5352, 0.9575, 1.6116),
#     90: (0.4459, 0.1322, 0.2325, 0.4453, 0.8607, 1.3503)
# }

# 2015 + 2018, new SFs and selections
# cross_section_limits = {
#     5: (26.7954, 15.4287, 21.6512, 32.3750, 49.5384, 72.6557,),
#     6: (5.5690, 3.4131, 4.8032, 7.2812, 11.2865, 16.8411),
#     9: (2.1312, 1.2524, 1.8131, 2.8125, 4.4941, 6.8086),
#     11: (2.3154, 0.8976, 1.2994, 2.0156, 3.1886, 4.8197),
#     14: (1.1418, 0.5603, 0.8302, 1.3281, 2.1646, 3.3798),
#     16: (1.0811, 0.3277, 0.5319, 0.9219, 1.6054, 2.6068),
#     22: (0.5572, 0.2639, 0.4256, 0.7344, 1.2788, 2.1064),
#     30: (0.4672, 0.1718, 0.2871, 0.5234, 0.9699, 1.5868),
#     90: (0.4760, 0.1396, 0.2475, 0.4766, 0.9211, 1.44503)
# }

# 2015 + 2018, final, all Aco
# cross_section_limits = {
#     5: (26.6107,15.3750,21.4795,32.0000,48.8370,71.7468,),
#     6: (5.5511,3.3838,4.7919,7.2188,11.2184,16.7105,),
#     9: (2.1235,1.2420,1.7980,2.7891,4.4344,6.7423,),
#     11: (2.2807,0.8914,1.2842,1.9844,3.1471,4.7485,),
#     14: (1.1240,0.5504,0.8215,1.3047,2.1264,3.3058,),
#     16: (1.0592,0.3235,0.5252,0.9102,1.5777,2.5538,),
#     22: (0.5449,0.2611,0.4184,0.7188,1.2574,2.0623,),
#     30: (0.4569,0.1679,0.2807,0.5117,0.9482,1.5513,),
#     90: (0.4642,0.1362,0.2415,0.4648,0.8984,1.4095, )
# }

# 2015 + 2018, final, SR
# cross_section_limits = {
#     5: (21.8837, 13.0005, 18.0032, 26.6250, 40.5278, 59.6396, ),
#     6: (5.5472, 3.1531, 4.4050, 6.5625, 10.0416, 14.8050, ),
#     9: (2.0288, 1.1497, 1.6406, 2.5156, 3.9395, 5.9395, ),
#     11: (2.1451, 0.8107, 1.1623, 1.7891, 2.8302, 4.3188, ),
#     14: (1.0900, 0.5076, 0.7521, 1.2031, 1.9800, 3.1209, ),
#     16: (0.8329, 0.3180, 0.5162, 0.8945, 1.5577, 2.5476, ),
#     22: (0.5466, 0.2430, 0.3945, 0.6836, 1.2122, 2.0178, ),
#     30: (0.4611, 0.1692, 0.2829, 0.5156, 0.9555, 1.5632, ),
#     90: (0.4643, 0.1362, 0.2415, 0.4648, 0.8984, 1.4095, )
# }

# 2015 + 2018, final, SR, and 3n, QED scale 2.4
# cross_section_limits = {
#     5: (23.9814, 13.2598, 18.5530, 27.3750, 41.6694, 60.9948, ),
#     6: (5.9123, 3.1721, 4.4514, 6.6562, 10.2116, 15.0694, ),
#     9: (1.8561, 1.1788, 1.6901, 2.6016, 4.0948, 6.1520, ),
#     11: (2.2188, 0.8107, 1.1623, 1.7891, 2.8374, 4.3218, ),
#     14: (1.0939, 0.5240, 0.7765, 1.2422, 2.0443, 3.2222, ),
#     16: (0.8012, 0.3241, 0.5296, 0.9219, 1.6054, 2.6068, ),
#     22: (0.5525, 0.2527, 0.4066, 0.7109, 1.2494, 2.0692, ),
#     30: (0.4626, 0.1705, 0.2850, 0.5195, 0.9627, 1.5750, ),
#     90: (0.4643, 0.1362, 0.2415, 0.4648, 0.8984, 1.4095,  )
# }

# 2015 + 2018, final, SR, and 3n, QED scale 2.7
# cross_section_limits = {
#     5: (24.3521, 13.2598, 18.5530, 27.3750, 41.5603, 60.9364, ),
#     6: (6.0090, 3.1721, 4.4514, 6.6562, 10.2116, 15.0302, ),
#     9: (1.8602, 1.1824, 1.6952, 2.6094, 4.1175, 6.1752, ),
#     11: (2.2473, 0.8036, 1.1521, 1.7734, 2.8196, 4.2871, ),
#     14: (1.0966, 0.5240, 0.7765, 1.2422, 2.0443, 3.2222, ),
#     16: (0.7976, 0.3255, 0.5318, 0.9258, 1.6122, 2.6178, ),
#     22: (0.5531, 0.2534, 0.4114, 0.7129, 1.2528, 2.0749, ),
#     30: (0.4627, 0.1705, 0.2850, 0.5195, 0.9668, 1.5750, ),
#     90: (0.4643, 0.1362, 0.2415, 0.4648, 0.8984, 1.4095,  )
# }

# 2015 + 2018, final, SC+SL, relaxed photon window
cross_section_limits = {
    5: (23.0219, 13.3809, 18.6111, 27.6250, 41.9399, 61.4929, ),
    6: (5.6454, 3.1870, 4.4723, 6.6875, 10.2861, 15.1539, ),
    9: (1.9312, 1.1569, 1.6508, 2.5312, 3.9842, 5.9857, ),
    11: (2.0954, 0.8423, 1.2134, 1.8750, 2.9737, 4.5294, ),
    14: (1.1689, 0.5076, 0.7521, 1.2031, 1.9800, 3.1209, ),
    16: (0.8599, 0.3200, 0.5229, 0.9102, 1.5849, 2.5921, ),
    22: (0.5565, 0.2431, 0.3972, 0.6914, 1.2261, 2.0477, ),
    30: (0.4708, 0.1705, 0.2850, 0.5195, 0.9627, 1.5750, ),
    90: (0.4746, 0.1409, 0.2478, 0.4746, 0.9173, 1.4391, ),
    100:(0.4746, 0.1409, 0.2478, 0.4746, 0.9173, 1.4391, ),
}

# 2015 + 2018, final, SC+SL, relaxed photon window, no CHE
# cross_section_limits = {
#     5: (35.4293, 12.4688, 18.1047, 28.5000, 46.2219, 71.8144, ),
#     6: (7.0686, 2.6016, 3.7963, 6.0000, 9.8266, 15.4170, ),
#     9: (2.0179, 1.0251, 1.5402, 2.5234, 4.2736, 6.8500, ),
#     11: (3.2434, 0.8062, 1.2246, 2.0234, 3.3946, 5.3987, ),
#     14: (2.0504, 0.5479, 0.8617, 1.4609, 2.4975, 3.9714, ),
#     16: (1.5463, 0.3800, 0.6428, 1.1445, 2.0113, 3.2623, ),
#     22: (0.7242, 0.2985, 0.4846, 0.8398, 1.4625, 2.3663, ),
#     30: (0.6424, 0.2047, 0.3407, 0.6094, 1.1097, 1.8472, ),
#     90: (0.4946, 0.1350, 0.2394, 0.4609, 0.8872, 1.3976,  )
# }


# observed
# ./findCoupling 02.88656 5000 50000 5 288.656
# ./findCoupling 00.62088 5000 50000 6 62.088
# ./findCoupling 00.22086 5000 50000 9 22.086
# ./findCoupling 00.23425 5000 50000 11 23.425
# ./findCoupling 00.12965 5000 50000 14 12.965
# ./findCoupling 00.08875 5000 50000 16 08.875
# ./findCoupling 00.05306 5000 50000 22 05.306
# ./findCoupling 00.04515 5000 50000 30 04.515
# ./findCoupling 00.04459 5000 50000 90 04.459

# expected
# ./findCoupling 03.4375 5000 50000 5 343.75
# ./findCoupling 00.7375 5000 50000 6 73.75
# ./findCoupling 00.29531 5000 50000 9 29.531
# ./findCoupling 00.20 5000 50000 11 20.
# ./findCoupling 00.13711 5000 50000 14 13.711
# ./findCoupling 00.09414 5000 50000 16 09.414
# ./findCoupling 00.07148 5000 50000 22 07.148
# ./findCoupling 00.05352 5000 50000 30 05.352
# ./findCoupling 00.04453 5000 50000 90 04.453

def get_xsec(mass, coupling):
    slope = 0.498809
    interstect = {
        5.0: 1.3352627780449595e-05,
        6.0: 1.459208443729578e-05,
        9.0: 1.8432339658251058e-05,
        11.0: 2.051773548082086e-05,
        14.0: 2.4387325416686648e-05,
        16.0: 2.643930742885861e-05,
        22.0: 3.323868088097294e-05,
        30.0: 4.4114845375054456e-05,
        50.0: 7.817673899208805e-05,
        90.0: 0.00019612635077675486,
        100.0: 0.000235,
    }
  
    cross_section = pow(10, (math.log10(coupling) - math.log10(interstect[mass]))/slope)
    scale = 1e-6

    return cross_section*scale

def main():
    ROOT.gROOT.SetBatch(True)
    
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

        # print(f"{mass}\t{get_alp_coupling(mass, cross_section_limits[mass][0]*scale)}")  # observed 
        print(f"{mass}\t{get_alp_coupling(mass, cross_section_limits[mass][3]*scale)}")  # expected

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

    exp_graph_2sigma.GetXaxis().SetTitleSize(0.05)
    exp_graph_2sigma.GetYaxis().SetTitleSize(0.05)
    exp_graph_2sigma.GetXaxis().SetLabelSize(0.04)
    exp_graph_2sigma.GetYaxis().SetLabelSize(0.04)
    exp_graph_2sigma.GetXaxis().SetTitleOffset(1.1)
    exp_graph_2sigma.GetYaxis().SetTitleOffset(1.1)
    
    ROOT.gPad.SetLeftMargin(0.12)
    ROOT.gPad.SetRightMargin(0.03)
    ROOT.gPad.SetBottomMargin(0.15)
    ROOT.gPad.SetTopMargin(0.10)

    exp_graph_2sigma.GetXaxis().SetTitle("m_{a} (GeV)")
    exp_graph_2sigma.GetYaxis().SetTitle(
        "#sigma_{#gamma#gamma #rightarrow a #rightarrow #gamma#gamma} (nb)")

    exp_graph_2sigma.GetXaxis().SetMoreLogLabels()

    # set x and y axes limits
    exp_graph_2sigma.GetXaxis().SetLimits(5, 100)
    exp_graph_2sigma.SetMaximum(4000)
    exp_graph_2sigma.SetMinimum(0.4)


    theory_lines = {}
    # line_styles = {
    #     0.05: (ROOT.kRed, 1),
    #     0.3: (ROOT.kMagenta, 1),
    #     0.1: (ROOT.kBlue, 1),        
    # }
    line_styles = {
        0.3: (ROOT.kRed, 2),
        0.1: (ROOT.kRed, 1),        
        0.05: (ROOT.kRed, 3),
    }
    

    legend_theory = ROOT.TLegend(0.25, 0.70, 0.5, 0.9)
    legend_theory.SetBorderSize(0)
    legend_theory.SetFillStyle(0)
    legend_theory.SetTextFont(42)
    legend_theory.SetTextSize(0.04)
    
    for coupling in [0.3, 0.1, 0.05]:
        theory_lines[coupling] = ROOT.TGraph()
        
        for i, mass in enumerate([5.0, 6.0, 9.0, 11.0, 14.0, 16.0, 22.0, 30.0, 50.0, 90., 100.]):
            theory_lines[coupling].SetPoint(i, mass, get_xsec(mass, coupling))
        
        theory_lines[coupling].SetLineColor(line_styles[coupling][0])
        theory_lines[coupling].SetLineStyle(line_styles[coupling][1])
        theory_lines[coupling].SetLineWidth(2)
        theory_lines[coupling].Draw("lsame")
        
        legend_theory.AddEntry(theory_lines[coupling], f"g_{{a#gamma}} = {coupling} (TeV^{{-1}})", "L")
    

    legend_theory.Draw()

    legend = ROOT.TLegend(0.55, 0.65, 0.9, 0.9)
    legend.SetBorderSize(0)
    legend.SetFillStyle(0)
    legend.SetTextFont(42)
    legend.SetTextSize(0.04)
    legend.AddEntry(obs_graph, "Observed", "L")
    legend.AddEntry(exp_graph, "Expected", "L")
    legend.AddEntry(exp_graph_1sigma, "68% expected", "F")
    legend.AddEntry(exp_graph_2sigma, "95% expected", "F")
    legend.Draw()
    
    # tex = ROOT.TLatex(0.15, 0.92, "#bf{CMS} #it{Preliminary}")
    tex = ROOT.TLatex(0.12, 0.92, "#bf{CMS}")
    tex.SetNDC()
    tex.SetTextFont(42)
    tex.SetTextSize(0.05)
    tex.SetLineWidth(2)
    tex.Draw()

    tex2 = ROOT.TLatex(0.48, 0.92, "#scale[0.8]{PbPb, (1.65 + 0.39) nb^{-1} (#sqrt{s_{NN}} = 5.02 TeV)}")
    tex2.SetNDC()
    tex2.SetTextFont(42)
    tex2.SetTextSize(0.05)
    tex2.SetLineWidth(2)
    tex2.Draw()
    
    canvas.cd()
    
    box = ROOT.TBox(75, 0.2, 85, 0.34)
    box.SetFillColor(ROOT.kWhite)
    # box.SetFillStyle(3004)
    box.Draw()

    canvas.Update()
    canvas.SaveAs("../plots/limits_cross_section.pdf")
    canvas.SaveAs("../plots/limits_cross_section.C")
    canvas.SaveAs("../plotting_macros/figures/Figure_008_b.pdf")


if __name__ == "__main__":
    main()
