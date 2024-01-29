from lbl_helpers import load_histograms, get_cep_scale, input_mass_histograms
from lbl_helpers import input_aco_histograms, scale_non_cep_histograms
from lbl_params import n_acoplanarity_bins, uncertainty_on_zero, n_mass_bins
from lbl_params import systematic_uncertainty, alp_mc_uncertainty
from lbl_paths import processes
from Logger import info
import ROOT
import os

skim = "skimmed_allSelections"

output_path_aco = f"../combine/significance_histograms_{skim}"
output_path_aco += f"_nBins{n_acoplanarity_bins}.root"

output_path_mass = f"../combine/limits_histograms_{skim}"
output_path_mass += f"_nBins{n_mass_bins}.root"


def add_uncertainties_on_zero(histogram):
    for i in range(1, histogram.GetNbinsX()):
        if histogram.GetBinContent(i) != 0:
            continue
        histogram.SetBinError(i, uncertainty_on_zero)

    return histogram


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
            scale = get_cep_scale(skim)
            print(f"CEP {scale=}")
            input_aco_histograms[process].Scale(scale)
            input_mass_histograms[process].Scale(scale)

        input_aco_histograms[process] = add_uncertainties_on_zero(input_aco_histograms[process])
        # input_mass_histograms[process] = add_uncertainties_on_zero(input_mass_histograms[process])

        name = process if process != "collisionData" else "data_obs"

        input_aco_histograms[process].SetName(name)
        input_mass_histograms[process].SetName(name)

        print(f"saving {name}")

        output_file_aco.cd()
        input_aco_histograms[process].Write()

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
        file += f"{systematic_uncertainty}  {systematic_uncertainty}"
        file += f"  {systematic_uncertainty}\n"
        file += f"alp_mc     lnN  {alp_mc_uncertainty}  -  -  -\n"
    else:
        file += "bck_syst     lnN    -  "
        file += f"{systematic_uncertainty}  {systematic_uncertainty}\n"

    file += "bin1   autoMCStats  10\n"
    return file


def save_datacard():
    rates = {}
    for process in processes:
        if process not in input_aco_histograms:
            continue
        rates[process] = input_aco_histograms[process].Integral()

    output_file = ""
    output_file = add_datacard_header(output_file, rates["collisionData"])
    output_file = add_datacard_rates(output_file, rates)
    output_file = add_datacard_nuisances(output_file)
    outfile = open(output_path_aco.replace(".root", ".txt"), "w")
    outfile.write(output_file)

    for process in processes:
        if "alps" not in process:
            continue

        if process not in input_aco_histograms:
            continue

        output_file = ""
        output_file = add_datacard_header(output_file, rates["collisionData"], process)
        output_file = add_datacard_rates(output_file, rates, process)
        output_file = add_datacard_nuisances(output_file, True)
        outfile = open(output_path_mass.replace(".root", f"{process}_.txt"), "w")
        outfile.write(output_file)


def main():
    info(f"Storing datacard/root file in: {output_path_aco}")
    load_histograms(skim)
    save_output_histograms()

    save_datacard()


if __name__ == "__main__":
    main()
