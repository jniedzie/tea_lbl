from lbl_helpers import load_histograms, get_cep_scale, input_mass_histograms, add_uncertainties_on_zero
from lbl_helpers import input_aco_histograms, scale_non_cep_histograms, limit_histogram
from lbl_params import n_acoplanarity_bins, uncertainty_on_zero, n_mass_bins
from lbl_params import systematic_uncertainty_lbl, alp_mc_uncertainty
from lbl_paths import processes
from Logger import info
import ROOT
import os

# skim = "skimmed_lblSelections_final"
# skim = "skimmed_lblSelections_final_andZDC"
# skim = "skimmed_lblSelections_final_andZDC3n"
skim = "skimmed_lblSelections_final_andZDC2n"

output_path_aco = f"../combine/significance_histograms_{skim}"
output_path_aco += f"_nBins{n_acoplanarity_bins}.root"

output_path_mass = f"../combine/limits_histograms_{skim}"
output_path_mass += f"_nBins{n_mass_bins}.root"

max_aco = 0.1
n_events_sampling = 500
transition_point = 0.026

def sample_from_fit(hist):
    ROOT.gRandom.SetSeed(0)
    
    formula = f"[p0]*(x<={transition_point})+(exp([p1]+[p2]*x))*(x>{transition_point})"
    # formula = f"[p0]*(x<={transition_point})+([p0]*exp([p2]*(x-{transition_point})))*(x>{transition_point})"
    fit = ROOT.TF1("fit", formula, 0, max_aco)
    fit.SetParameters(7, 3, -31)
    hist.Fit(fit, "WW")

    new_hist = hist.Clone()
    new_hist.Reset()
    new_hist.FillRandom("fit", n_events_sampling)
    
    for i in range(1, new_hist.GetNbinsX()+1):
        new_hist.SetBinContent(i, new_hist.GetBinContent(i)/new_hist.GetBinWidth(i))
        new_hist.SetBinError(i, new_hist.GetBinError(i)/new_hist.GetBinWidth(i))
    
    new_hist.Scale(hist.Integral()/new_hist.Integral())

    canvas = ROOT.TCanvas("canvas", "canvas", 800, 600)
    hist.SetMarkerColor(ROOT.kRed)
    hist.SetMarkerStyle(20)
    hist.SetLineColor(ROOT.kRed)
    hist.Draw("PE") 
    
    hist.GetXaxis().SetRangeUser(0, 0.2)
    hist.GetYaxis().SetRangeUser(0, 10)
    
    new_hist.SetMarkerColor(ROOT.kBlack)
    new_hist.SetMarkerStyle(20)
    new_hist.SetLineColor(ROOT.kBlack)
    new_hist.Draw("PEsame")
    
    canvas.SaveAs("../plots/qed_fit.pdf")

    return new_hist


def save_output_histograms():
    output_dir = os.path.dirname(output_path_aco)
    os.system(f"mkdir -p {output_dir}")

    output_file_aco = ROOT.TFile(output_path_aco, "recreate")
    output_file_mass = ROOT.TFile(output_path_mass, "recreate")

    scale_non_cep_histograms()

    for process in processes:
        if process not in input_aco_histograms:
            continue

        if process == "cep":
            scale, _ = get_cep_scale(skim)
            print(f"CEP {scale=}")
            input_aco_histograms[process].Scale(scale)
            input_mass_histograms[process].Scale(scale)

        input_aco_histograms[process] = add_uncertainties_on_zero(
            input_aco_histograms[process])
        # input_mass_histograms[process] = add_uncertainties_on_zero(input_mass_histograms[process])

        name = process if process != "collisionData" else "data_obs"

        input_aco_histograms[process].SetName(name)
        input_mass_histograms[process].SetName(name)

        # hist = limit_histogram(input_aco_histograms[process], max_aco)

        print(f"saving {name}")

        output_file_aco.cd()
        input_aco_histograms[process].Write()
        # hist.Write()

        output_file_mass.cd()
        input_mass_histograms[process].Write()

    output_file_aco.Close()
    output_file_mass.Close()


def add_datacard_header(file, observed_rate, alp_name=""):

    if alp_name == "":
        histograms_path = output_path_aco.replace("../combine/", "")
    else:
        histograms_path = output_path_mass.replace("../combine/", "")

    file += "imax 1  number of channels\n"
    file += f"jmax {3 if alp_name!='' else 2}  number of backgrounds\n"
    file += "kmax *  number of nuisance parameters\n"
    file += f"shapes * * {histograms_path} "
    file += " $PROCESS $PROCESS_$SYSTEMATIC\n"
    file += "bin bin1\n"
    file += f"observation {observed_rate}\n"
    file += f"bin            {'bin1 ' if alp_name!='' else ''}bin1 bin1 bin1\n"
    file += f"process        {alp_name} lbl  cep  qed\n"
    file += f"process        0      1     2{'     3' if alp_name!='' else ''}\n"
    return file


def add_datacard_rates(file, rates, alp_name=""):
    file += f"rate           {rates[alp_name] if alp_name!='' else ''}  "
    file += f"{rates['lbl']} {rates['cep']} {rates['qed']}\n"
    return file


def add_datacard_nuisances(file, do_alp=False):
    if do_alp:
        file += "bck_syst     lnN    -  "
        file += f"{systematic_uncertainty_lbl}  {systematic_uncertainty_lbl}"
        file += f"  {systematic_uncertainty_lbl}\n"
        file += f"alp_mc     lnN  {alp_mc_uncertainty}  -  -  -\n"
    else:
        file += "bck_syst     lnN    -  "
        file += f"{systematic_uncertainty_lbl}  {systematic_uncertainty_lbl}\n"

    file += "bin1   autoMCStats  10\n"
    return file


def save_datacard():
    rates = {}
    for process in processes:
        if process not in input_aco_histograms:
            continue
        # hist = limit_histogram(input_aco_histograms[process], max_aco)
        # rates[process] = hist.Integral()
        rates[process] = input_aco_histograms[process].Integral()

    output_file = ""
    output_file = add_datacard_header(output_file, rates["collisionData"])
    output_file = add_datacard_rates(output_file, rates)
    output_file = add_datacard_nuisances(output_file)
    outfile = open(output_path_aco.replace(".root", ".txt"), "w")
    outfile.write(output_file)

    rates = {}
    for process in processes:
        if process not in input_aco_histograms:
            continue
        rates[process] = input_mass_histograms[process].Integral()

    for process in processes:
        if "alps" not in process:
            continue

        if process not in input_aco_histograms:
            continue

        output_file = ""
        output_file = add_datacard_header(
            output_file, rates["collisionData"], process)
        output_file = add_datacard_rates(output_file, rates, process)
        output_file = add_datacard_nuisances(output_file, True)
        outfile = open(output_path_mass.replace(
            ".root", f"{process}_.txt"), "w")
        outfile.write(output_file)


# def get_data_background_chi2():
#     data = input_aco_histograms["collisionData"]
#     backgrounds = [input_aco_histograms["qed"], input_aco_histograms["lbl"], input_aco_histograms["cep"]]
#     chi2 = 0
#     for i in range(1, data.GetNbinsX()+1):
#         data_bin = data.GetBinContent(i)
#         background_bin = backgrounds[0].GetBinContent(i) + backgrounds[1].GetBinContent(i) + backgrounds[2].GetBinContent(i)    
        
#         if data_bin != 0:
#             chi2 += (data_bin - background_bin)**2 / data_bin
#     return chi2

def main():
    info(f"Storing datacard/root file in: {output_path_aco}")
    load_histograms(skim)
    
    # replace the QED histogram with sampling from a fit
    # input_aco_histograms["qed"] = sample_from_fit(input_aco_histograms["qed"])
    
    save_output_histograms()
    
    # chi2 = get_data_background_chi2()
    # print(f"{chi2=}")

    save_datacard()


if __name__ == "__main__":
    main()


# combineCards.py limits_histograms_2015alps_5_.txt limits_histograms_skimmed_lblSelections_final_nBins200alps_5_.txt > card_alps_5.txt
# combineCards.py limits_histograms_2015alps_6_.txt limits_histograms_skimmed_lblSelections_final_nBins200alps_6_.txt > card_alps_6.txt
# combineCards.py limits_histograms_2015alps_9_.txt limits_histograms_skimmed_lblSelections_final_nBins200alps_9_.txt > card_alps_9.txt
# combineCards.py limits_histograms_2015alps_11_.txt limits_histograms_skimmed_lblSelections_final_nBins200alps_11_.txt > card_alps_11.txt
# combineCards.py limits_histograms_2015alps_14_.txt limits_histograms_skimmed_lblSelections_final_nBins200alps_14_.txt > card_alps_14.txt
# combineCards.py limits_histograms_2015alps_16_.txt limits_histograms_skimmed_lblSelections_final_nBins200alps_16_.txt > card_alps_16.txt
# combineCards.py limits_histograms_2015alps_22_.txt limits_histograms_skimmed_lblSelections_final_nBins200alps_22_.txt > card_alps_22.txt
# combineCards.py limits_histograms_2015alps_30_.txt limits_histograms_skimmed_lblSelections_final_nBins200alps_30_.txt > card_alps_30.txt
# combineCards.py limits_histograms_2015alps_50_.txt limits_histograms_skimmed_lblSelections_final_nBins200alps_50_.txt > card_alps_50.txt
# combineCards.py limits_histograms_2015alps_90_.txt limits_histograms_skimmed_lblSelections_final_nBins200alps_90_.txt > card_alps_90.txt
