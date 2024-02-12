from Logger import info
import ROOT
import os


backgrounds_input_path = "../combine/ged_final_histos_invmass5_diphoton_pt1.root"
alps_input_path = "../combine/ALPS_all_Mass.root"

output_path_mass = "../combine/limits_histograms_2015.root"

input_mass_histograms = {}

systematic_uncertainty = 1.24
alp_mc_uncertainty = 1.03


backgrounds_file = ROOT.TFile.Open(backgrounds_input_path)
alps_file = ROOT.TFile.Open(alps_input_path)

def load_histograms():
    input_mass_histograms["collisionData"] = backgrounds_file.Get("hinvmass_data")
    input_mass_histograms["cep"] = backgrounds_file.Get("hinvmass_cep_stack_2")
    input_mass_histograms["lbl"] = backgrounds_file.Get("hinvmass_lbyl_stack_3")
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
    file += f"{systematic_uncertainty}  {systematic_uncertainty}"
    file += f"  {systematic_uncertainty}\n"
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


def main():
    info(f"Storing datacard/root file in: {output_path_mass}")
    load_histograms()
    save_output_histograms()
    save_datacard()


if __name__ == "__main__":
    main()
