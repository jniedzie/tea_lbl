from lbl_cep_scale_calculator import load_histograms, get_cep_scale, scale_lbl_and_qed_histograms
from lbl_cep_scale_calculator import input_histograms
from lbl_params import n_acoplanarity_bins, uncertainty_on_zero
from lbl_params import systematic_uncertainty
from lbl_paths import processes
from Logger import info
import ROOT
import os

# skim = "skimmed_allSelections"
skim = "skimmed_allSelections_swissCross0p99"

output_path = f"../combine/significance_histograms_{skim}"
output_path += f"_nBins{n_acoplanarity_bins}.root"


def save_output_histograms():
    output_dir = os.path.dirname(output_path)
    os.system(f"mkdir -p {output_dir}")
    output_file = ROOT.TFile(output_path, "recreate")
    output_file.cd()

    scale_lbl_and_qed_histograms()

    for process in processes:
        scale = 1

        if process == "cep":
            scale = get_cep_scale(skim)
            print(f"{scale=}")

        input_histograms[process].Scale(scale)

        for i in range(1, input_histograms[process].GetNbinsX()):
            if input_histograms[process].GetBinContent(i) == 0:
                input_histograms[process].SetBinError(i, uncertainty_on_zero)

        name = process if process != "collisionData" else "data_obs"
        input_histograms[process].SetName(name)
        print(f"saving {name}")
        input_histograms[process].Write()

    output_file.Close()


def add_datacard_header(file, observed_rate):
    file += "imax 1  number of channels\n"
    file += "jmax 2  number of backgrounds\n"
    file += "kmax *  number of nuisance parameters\n"
    file += f"shapes * * {output_path.replace('../combine/', '')} "
    file += " $PROCESS $PROCESS_$SYSTEMATIC\n"
    file += "bin bin1\n"
    file += f"observation {observed_rate}\n"
    file += "bin            bin1  bin1 bin1\n"
    file += "process        lbl  cep  qed\n"
    file += "process        0      1     2\n"
    return file


def add_datacard_rates(file, rates):
    file += f"rate            {rates['lbl']} {rates['cep']} {rates['qed']}\n"
    return file


def add_datacard_nuisances(file):
    file += "bck_syst     lnN    -  "
    file += f"{systematic_uncertainty}  {systematic_uncertainty}\n"
    file += "bin1   autoMCStats  10\n"
    return file


def save_datacard():
    rates = {}
    for process in processes:
        rates[process] = input_histograms[process].Integral()

    output_file = ""
    output_file = add_datacard_header(output_file, rates["collisionData"])
    output_file = add_datacard_rates(output_file, rates)
    output_file = add_datacard_nuisances(output_file)

    outfile = open(output_path.replace(".root", ".txt"), "w")
    outfile.write(output_file)


def main():
    info(f"Storing datacard/root file in: {output_path}")
    load_histograms(skim)
    save_output_histograms()
    save_datacard()


if __name__ == "__main__":
    main()
