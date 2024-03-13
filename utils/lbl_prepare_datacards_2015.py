from Logger import info
import ROOT
import os
from lbl_params import total_uncertainty_lbl_run1, alp_mc_uncertainty


backgrounds_input_path = "../combine/ged_final_histos_invmass5_diphoton_pt1.root"
alps_input_path = "../combine/ALPS_all_Mass.root"

output_path_mass = "../combine/limits_histograms_2015.root"
output_path_aco = "../combine/significance_histograms_2015.root"

input_mass_histograms = {}


# backgrounds_file = ROOT.TFile.Open(backgrounds_input_path)
# alps_file = ROOT.TFile.Open(alps_input_path)

eta_range_scale = 0.91

def load_histograms():
    input_mass_histograms["collisionData"] = backgrounds_file.Get(
        "hinvmass_data")
    input_mass_histograms["cep"] = backgrounds_file.Get("hinvmass_cep_stack_2")
    input_mass_histograms["lbl"] = backgrounds_file.Get(
        "hinvmass_lbyl_stack_3")
    input_mass_histograms["qed"] = backgrounds_file.Get("hinvmass_qed_stack_1")

    input_mass_histograms["alps_5"] = alps_file.Get("hinvmass0")
    input_mass_histograms["alps_6"] = alps_file.Get("hinvmass1")
    input_mass_histograms["alps_9"] = alps_file.Get("hinvmass2")
    input_mass_histograms["alps_11"] = alps_file.Get("hinvmass3")
    input_mass_histograms["alps_14"] = alps_file.Get("hinvmass4")
    input_mass_histograms["alps_16"] = alps_file.Get("hinvmass5")
    input_mass_histograms["alps_22"] = alps_file.Get("hinvmass6")
    input_mass_histograms["alps_30"] = alps_file.Get("hinvmass7")
    input_mass_histograms["alps_90"] = alps_file.Get("hinvmass8")


def save_output_histograms():
    output_dir = os.path.dirname(output_path_mass)
    os.system(f"mkdir -p {output_dir}")

    output_file_mass = ROOT.TFile(output_path_mass, "recreate")
    output_file_mass.cd()

    for process, hist in input_mass_histograms.items():
        name = process if process != "collisionData" else "data_obs"
        info(f"saving {name}")
        hist.Print()
        hist.SetName(name)

        output_file_mass.cd()
        hist.Write()

    output_file_mass.Close()


def add_datacard_header(file, observed_rate, alp_name):

    histograms_path = output_path_mass.replace("../combine/", "")

    file += "imax 1  number of channels\n"
    file += "jmax 3  number of backgrounds\n"
    file += "kmax *  number of nuisance parameters\n"
    file += f"shapes * * {histograms_path} "
    file += " $PROCESS $PROCESS_$SYSTEMATIC\n"
    file += "bin bin1\n"
    file += f"observation {observed_rate}\n"
    file += "bin            bin1 bin1 bin1 bin1\n"
    file += f"process        {alp_name} lbl  cep  qed\n"
    file += "process        0      1     2     3\n"
    return file


def add_datacard_rates(file, rates, alp_name):
    file += f"rate           {rates[alp_name]}  "
    file += f"{rates['lbl']} {rates['cep']} {rates['qed']}\n"
    return file


def add_datacard_nuisances(file):
    file += "bck_syst     lnN    -  "
    file += f"{total_uncertainty_lbl_run1}  {total_uncertainty_lbl_run1}"
    file += f"  {total_uncertainty_lbl_run1}\n"
    file += f"alp_mc     lnN  {alp_mc_uncertainty}  -  -  -\n"
    file += "bin1   autoMCStats  10\n"

    return file


def save_datacard():
    rates = {}
    for process, hist in input_mass_histograms.items():
        rates[process] = hist.Integral()

    for process, hist in input_mass_histograms.items():
        if "alps" not in process:
            continue

        output_file = ""
        output_file = add_datacard_header(
            output_file, rates["collisionData"], process)
        output_file = add_datacard_rates(output_file, rates, process)
        output_file = add_datacard_nuisances(output_file)
        outfile = open(output_path_mass.replace(
            ".root", f"{process}_.txt"), "w")
        outfile.write(output_file)


def get_aco_histograms():

    background_y = (
        1.87,
        2.13,
        2.29,
        2.28,
        2.67,
        1.81,
        2.13,
        2.77,
        1.83,
        0.871,
        1.23,
        1.07,
        0.800,
        0.587,
        1.14,
        0.533,
        0.178,
        0.658,
        0.373,
        0.444,
    )

    lbl_y = (
        10.5 - background_y[0],
        2.60 - background_y[1],
        2.65 - background_y[2],
        2.54 - background_y[3],
        2.84 - background_y[4],
        1.97 - background_y[5],
        2.26 - background_y[6],
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    )

    data_y = (12, 2, 3, 1, 4, 3, 1, 4, 1, 1, 0, 3, 1, 1, 1, 0, 0, 0, 0, 0)
    daat_y_err = (3.46, 1.41, 1.73, 1, 2, 1.73, 1, 2, 1, 1, 1.84,
                  1.73, 1, 1, 1, 1.84, 1.84, 1.84, 1.84, 1.84)

    hist_data = ROOT.TH1F("data_obs", "data_obs", 20, 0, 0.1)
    hist_background = ROOT.TH1F("bkg", "bkg", 20, 0, 0.1)
    hist_lbl = ROOT.TH1F("lbl", "lbl", 20, 0, 0.1)

    for i in range(20):
        hist_data.SetBinContent(i+1, data_y[i])
        hist_data.SetBinError(i+1, daat_y_err[i])
        hist_background.SetBinContent(i+1, background_y[i])
        hist_lbl.SetBinContent(i+1, lbl_y[i])

    hist_data.Scale(eta_range_scale)
    hist_background.Scale(eta_range_scale)
    hist_lbl.Scale(eta_range_scale)

    return hist_data, hist_background, hist_lbl


def main():
    info(f"Storing datacard/root file in: {output_path_mass}")
    # load_histograms()
    # save_output_histograms()
    # save_datacard()

    hist_data, hist_background, hist_lbl = get_aco_histograms()

    output_file = ""
    output_file += "imax 1  number of channels\n"
    output_file += "jmax 1  number of backgrounds\n"
    output_file += "kmax *  number of nuisance parameters\n"
    output_file += f"shapes * * significance_histograms_2015.root "
    output_file += " $PROCESS $PROCESS_$SYSTEMATIC\n"
    output_file += "bin bin1\n"
    output_file += f"observation {hist_data.Integral()}\n"
    output_file += "bin            bin1 bin1 \n"
    output_file += f"process       lbl  bkg\n"
    output_file += "process        0      1\n"
    output_file += f"rate           {hist_lbl.Integral()}   {hist_background.Integral()}\n"
    output_file += "bck_syst     lnN    -  1.24\n"
    output_file += "bin1   autoMCStats  10\n"

    outfile = open(output_path_aco.replace(".root", ".txt"), "w")
    outfile.write(output_file)

    output_file_aco = ROOT.TFile(output_path_aco, "recreate")
    output_file_aco.cd()
    hist_data.Write()
    hist_background.Write()
    hist_lbl.Write()
    output_file_aco.Close()


if __name__ == "__main__":
    main()
