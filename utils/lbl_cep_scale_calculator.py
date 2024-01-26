import ROOT
from lbl_params import luminosity, crossSections, scaleFactors, nGenEvents
from lbl_params import n_acoplanarity_bins, cep_scaling_min_acoplanarity

processes = ["collisionData", "lbl", "qed", "cep"]
hist_name = "diphoton_acoplanarity{}"
input_path = "/nfs/dust/cms/user/jniedzie/light_by_light/ntuples/{}/merged_{}histograms.root"

input_files = {}
input_histograms = {}


def load_histograms(skim):
    for process in processes:
        input_files[process] = ROOT.TFile.Open(
            input_path.format(process, skim))
        input_histograms[process] = input_files[process].Get(
            hist_name.format(n_acoplanarity_bins))
        if input_histograms[process] is None or type(input_histograms[process]) == ROOT.TObject:
            print(f"ERROR - hist {hist_name.format(n_acoplanarity_bins)} not found in file: {input_path.format(process, skim)}")
            exit()


def scale_lbl_and_qed_histograms():
    for process in processes:
        if process != "lbl" and process != "qed":
            continue

        scale = luminosity*crossSections[process]*scaleFactors[process]
        scale /= nGenEvents[process]
        input_histograms[process].Scale(scale)


def get_cep_scale(skim):
    load_histograms(skim)
    scale_lbl_and_qed_histograms()

    hist_data_no_background = input_histograms["collisionData"].Clone()
    hist_data_no_background.Add(input_histograms["lbl"], -1)
    hist_data_no_background.Add(input_histograms["qed"], -1)

    integral_data = hist_data_no_background.Integral(
        hist_data_no_background.FindBin(cep_scaling_min_acoplanarity),
        hist_data_no_background.GetNbinsX()
    )

    integral_cep = input_histograms["cep"].Integral(
        input_histograms["cep"].FindBin(cep_scaling_min_acoplanarity),
        input_histograms["cep"].GetNbinsX()
    )

    return integral_data / integral_cep
