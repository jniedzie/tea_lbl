from params import *
import ROOT
import os

# skim = "skimmed_allSelections"
# skim = "skimmed_allSelections_track3validHits"
# skim = "skimmed_allSelections_maxDiphotonPt2"
# skim = "skimmed_allSelections_nTowers1"
# skim = "skimmed_allSelections_swissCross99"
# skim = "skimmed_allSelections_eta2p4"
# skim = "skimmed_allSelections_seedTime3p6"
# skim = "skimmed_allSelections_electron0missingHits1"
# skim = "skimmed_allSelections_trackEta2p2"
# skim = "skimmed_allSelections_HF7"
# skim = "skimmed_allSelections_HB3"
# skim = "skimmed_allSelections_trackPt1p0"
# skim = "skimmed_allSelections_trackPt0p5"
# skim = "skimmed_allSelections_HE1p2"
# skim = "skimmed_allSelections_EB1p0"
# skim = "skimmed_allSelections_EE3p5"
# skim = "skimmed_allSelections_EE4p0"
# skim = "skimmed_allSelections_EE3p3"
# skim = "skimmed_allSelections_EE3p7"
# skim = "skimmed_allSelections_hadronCrack"
# skim = "skimmed_allSelections_caloEta2p2"
# skim = "skimmed_allSelections_swissCross99_EE3p5_EEeta2p2"
# skim = "skimmed_allSelections_swissCross99_EE3p5"
# skim = "skimmed_allSelections_EE3p5_EEeta2p2"
# skim = "skimmed_allSelections_EE3p4"
# skim = "skimmed_allSelections_EE3p6"
# skim = "skimmed_allSelections_EE3p5_trackPt0p4"
# skim = "skimmed_allSelections_EE3p5_1track"
# skim = "skimmed_allSelections_EE3p5_deadHEfix"
# skim = "skimmed_allSelections_deltaEtaEE0p8"
skim = "skimmed_allSelections_EE3p5_deltaEtaEE0p25"

input_path = "/nfs/dust/cms/user/jniedzie/light_by_light/ntuples/{}/merged_{}histograms.root"

output_path = f"../combine/significance_histograms_{skim}.root"

hist_name = "diphoton_acoplanarity"

uncertainty_on_zero = 1.84  # 95% CL
# uncertainty_on_zero = 1.14  # 68% CL

systematic_uncertainty = 1.25

processes = ["collisionData", "lbl", "qed", "cep"]

input_files = {}
input_histograms = {}


def load_histograms():
    for process in processes:
        input_files[process] = ROOT.TFile.Open(
            input_path.format(process, skim))
        input_histograms[process] = input_files[process].Get(hist_name)
        if input_histograms[process] is None:
            print(f"ERROR - hist not found: {hist_name}")


def save_output_histograms():
    output_dir = os.path.dirname(output_path)
    os.system(f"mkdir -p {output_dir}")
    output_file = ROOT.TFile(output_path, "recreate")
    output_file.cd()

    for process in processes:
        if process == "lbl":
            input_histograms[process].Scale(luminosity*lbl_scale/n_lbl_events)
        elif process == "qed":
            input_histograms[process].Scale(luminosity*qed_scale/n_qed_events)
        elif process == "cep":
            scale = get_cep_scale(input_histograms["collisionData"],
                                  input_histograms["lbl"],
                                  input_histograms["qed"],
                                  input_histograms["cep"]
                                  )
            print(f"{scale=}")
            input_histograms[process].Scale(scale)

        for i in range(1, input_histograms[process].GetNbinsX()):
            if input_histograms[process].GetBinContent(i) == 0:
                input_histograms[process].SetBinError(i, uncertainty_on_zero)

        input_histograms[process].SetName(process if process != "collisionData" else "data_obs")
        input_histograms[process].Write()

    output_file.Close()


def add_datacard_header(file, observed_rate):
    file += "imax 1  number of channels\n"
    file += "jmax 2  number of backgrounds\n"
    file += "kmax *  number of nuisance parameters (sources of systematical uncertainties)\n"
    file += f"shapes * * {output_path.replace('../combine/', '')}  $PROCESS $PROCESS_$SYSTEMATIC\n"
    file += "bin bin1\n"
    file += f"observation {observed_rate}\n"
    file += "bin            bin1  bin1 bin1\n"
    file += "process        lbl  cep  qed\n"
    file += "process        0      1     2\n"
    return file


def add_datacard_rates(file, lblRate, cepRate, qedRate):
    file += f"rate            {lblRate} {cepRate} {qedRate}\n"
    return file


def add_datacard_nuisances(file):
    file += f"bck_syst     lnN    -  {systematic_uncertainty}  {systematic_uncertainty}\n"
    file += "bin1   autoMCStats  10\n"
    return file


def save_datacard():
    observed_rate = input_histograms["collisionData"].Integral()
    lbl_rate = input_histograms["lbl"].Integral()
    cep_rate = input_histograms["cep"].Integral()
    qed_rate = input_histograms["qed"].Integral()

    output_file = ""

    output_file = add_datacard_header(output_file, observed_rate)
    output_file = add_datacard_rates(output_file, lbl_rate, cep_rate, qed_rate)
    output_file = add_datacard_nuisances(output_file)

    outfile = open(output_path.replace(".root", ".txt"), "w")
    outfile.write(output_file)


def main():
    load_histograms()
    save_output_histograms()
    save_datacard()


if __name__ == "__main__":
    main()
