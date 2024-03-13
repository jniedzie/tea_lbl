import ROOT
import random
from lbl_paths import base_path, merged_histograms_path


def get_gaus_formula(offset):
    return f"[{offset}]/([{offset+2}]*sqrt(2*TMath::Pi())) * exp(-pow((x-[{offset+1}])/(2*[{offset+2}]), 2))"

def get_gaus(name, scale, mean, sigma, offset):
    # define a gaussian function with explicit formula
    gaus = ROOT.TF1(name, get_gaus_formula(offset), 0, 20000)
    
    # gaus = ROOT.TF1("gaus"+str(random.randint(0, 1000)), "gaus(0)", 0, 20000)
    gaus.SetParameter(offset+0, scale) # amplitude
    gaus.SetParameter(offset+1, mean) # mean
    gaus.SetParameter(offset+2, sigma) # sigma
    gaus.SetParLimits(offset+2, 0.5*sigma, 1.5*sigma)
    
    return gaus

def get_total_function():
    pass

def fit_hist(hist):
    # ROOT.gPad.SetLogx()
    ROOT.gPad.SetLogy()
    hist.Rebin(5)
    hist.Scale(1/5)
    hist.Draw()
    hist.GetXaxis().SetRangeUser(200, 20000)
    
    
    
    exp_0 = ROOT.TF1("exp_0", "[0]/exp([1]*x)", 0, 20000)
    exp_0.SetParameter(0, 1.5e5)
    exp_0.SetParameter(1, 1e-5)
    hist.Fit(exp_0, "R0", "", 200, 1000)
    
    gaus_1 = get_gaus("gaus_1", 1.5e3, 2500, 1000, 2)
    hist.Fit(gaus_1, "R0", "", 1500, 4000)
    
    gaus_2 = get_gaus("gaus_2", 1.5e3, 5500, 1500, 5)
    hist.Fit(gaus_2, "R0", "", 4500, 6500)
    
    gaus_3 = get_gaus("gaus_3", 1.5e3, 800, 1500, 8)
    hist.Fit(gaus_3, "R0", "", 7500, 9000)
    
    print(f"integral: {hist.Integral(hist.GetXaxis().FindFixBin(0), hist.GetXaxis().FindFixBin(7000))/hist.Integral(hist.GetXaxis().FindFixBin(0), hist.GetXaxis().FindFixBin(20000))}")
    
    exp_0.Draw("same")
    gaus_1.Draw("same")
    gaus_2.Draw("same")
    gaus_3.Draw("same")
    
    
    # total_fun = ROOT.TF1("total_fun", f"[11]*([0]/exp([1]*x)+{get_gaus_formula(2)}+{get_gaus_formula(5)}+{get_gaus_formula(8)})", 0, 20000)
    # total_fun.FixParameter(0, exp_0.GetParameter(0))
    # total_fun.FixParameter(1, exp_0.GetParameter(1))
    
    # total_fun.FixParameter(2, gaus_1.GetParameter(2))
    # total_fun.FixParameter(3, gaus_1.GetParameter(3))
    # total_fun.FixParameter(4, gaus_1.GetParameter(4))
    
    # total_fun.FixParameter(5, gaus_2.GetParameter(5))
    # total_fun.FixParameter(6, gaus_2.GetParameter(6))
    # total_fun.FixParameter(7, gaus_2.GetParameter(7))
    
    # total_fun.FixParameter(8, gaus_3.GetParameter(8))
    # total_fun.FixParameter(9, gaus_3.GetParameter(9))
    # total_fun.FixParameter(10, gaus_3.GetParameter(10))
    
    # total_fun.FixParameter(11, 1)
    
    # hist.Fit(total_fun, "R0", "", 200, 9000)
    
    # print(f"\n\nvalue: {total_fun.Eval(2000)}")
    
    # total_fun.SetLineColor(ROOT.kBlack)
    # total_fun.Draw("same")
    # print(f"{total_fun.GetExpFormula()=}")
    
    thresholds = [0, 1600, 4000, 7000, 10000, 100000]
    
    line = ROOT.TLine()
    line.SetLineStyle(2)
    line.SetLineColor(ROOT.kBlack)
    for threshold in thresholds:
        if threshold == 0:
            continue
        line.DrawLine(threshold, 0, threshold, 1.5e3)
    
    print(f"\n\n{hist.GetName()}")
    print("from 0n to:")
    for i in range(0, len(thresholds)-1):
        print(f"\t{i}n: {exp_0.Integral(thresholds[i], thresholds[i+1])/exp_0.Integral(thresholds[0], thresholds[-1])}")
    
    print("from 1n to:")
    for i in range(0, len(thresholds)-1):
        print(f"\t{i}n: {gaus_1.Integral(thresholds[i], thresholds[i+1])/gaus_1.Integral(thresholds[0], thresholds[-1])}")
        
    print("from 2n to:")
    for i in range(0, len(thresholds)-1):
        print(f"\t{i}n: {gaus_2.Integral(thresholds[i], thresholds[i+1])/gaus_2.Integral(thresholds[0], thresholds[-1])}")
        
    print("from 3n to:")
    for i in range(0, len(thresholds)-1):
        print(f"\t{i}n: {gaus_3.Integral(thresholds[i], thresholds[i+1])/gaus_3.Integral(thresholds[0], thresholds[-1])}")
    

def main():
    ROOT.gStyle.SetOptStat(0)
    path = merged_histograms_path.format("collisionData", "initial")
    input_file = ROOT.TFile(path, "READ")

    hist_plus = input_file.Get("event_ZDCenergyPlus")
    hist_minus = input_file.Get("event_ZDCenergyMinus")

    canvas = ROOT.TCanvas("canvas", "canvas", 800, 1200)
    canvas.Divide(1, 2)

    canvas.cd(1)
    fit_hist(hist_plus)

    canvas.cd(2)
    fit_hist(hist_minus)

    canvas.SaveAs("../plots/zdc_energy.pdf")


if __name__ == "__main__":
    main()
