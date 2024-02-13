from ROOT import TGraph, TCanvas
import ROOT

conversion_file_path = "../utils/lbl_alp_cross_section_to_coupling.txt"


def getConversionTable():
    conversion_table = {}

    with open(conversion_file_path, "r") as file:
        for line in file.readlines():
            if "mass:" in line:
                mass = float(line.split(":")[-1].strip())
                conversion_table[mass] = {}
                continue

            cross_section = float(line.split(":")[0].strip())

            if cross_section < 0:
                continue

            coupling = float(line.split(":")[1].strip())
            conversion_table[mass][cross_section] = coupling

    return conversion_table


def main():
    conversion_table = getConversionTable()
    graphs = {}
    functions = {}

    for mass, values in conversion_table.items():
        print(f"mass: {mass}")
        graphs[mass] = TGraph()
        functions[mass] = ROOT.TF1(
            f"mass_{mass}", "pow(10, [0] * log10(x) + log10([1])) ", 1e-3, 1e4)

        for i, (cross_section, coupling) in enumerate(values.items()):
            graphs[mass].SetPoint(i, cross_section, coupling)

    colors = (
        ROOT.kGray+2,
        ROOT.kCyan+1,
        ROOT.kCyan,
        ROOT.kMagenta,
        ROOT.kViolet,
        ROOT.kBlue,
        ROOT.kGreen,
        ROOT.kYellow+1,
        ROOT.kOrange,
        ROOT.kRed,
    )

    starting_intersect = {
        5: 1e-5,
        6: 1e-5,
        9: 1e-5,
        11: 1e-5,
        14: 1e-5,
        16: 1e-4,
        22: 1e-4,
        30: 1e-4,
        50: 1e-4,
        90: 1e-4,
    }

    canvas = TCanvas("canvas", "canvas", 800, 600)
    canvas.cd()
    ROOT.gPad.SetLogx(True)
    ROOT.gPad.SetLogy(True)

    for i, (mass, graph) in enumerate(graphs.items()):
        graph.SetMarkerStyle(20)
        graph.SetMarkerColor(colors[i])
        graph.SetLineColor(colors[i])

        functions[mass].FixParameter(0, 0.498809)
        # functions[mass].SetParLimits(0, 0, 1)
        functions[mass].SetParameter(1, starting_intersect[mass])
        # functions[mass].SetParLimits(1, 0.8e-5, 2e-4)
        functions[mass].SetLineColor(colors[i])
        graph.Fit(functions[mass], "R")

        if i == 0:
            graph.Draw("AP")
            graph.GetXaxis().SetTitle("cross-section (nb)")
            graph.GetYaxis().SetTitle("coupling (1/GeV)")
            graph.GetYaxis().SetRangeUser(1e-6, 1e-1)
        else:
            graph.Draw("P same")

        functions[mass].Draw("same")

    canvas.Update()
    canvas.SaveAs("../plots/coupling_vs_cross_section.pdf")

    for mass, function in functions.items():
        print(f"mass: {mass}, {function.GetParameter(1)=}")


if __name__ == "__main__":
    main()
