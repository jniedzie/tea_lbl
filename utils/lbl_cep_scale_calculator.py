import ROOT
from lbl_params import luminosity, crossSections, scaleFactors, nGenEvents
from lbl_params import n_acoplanarity_bins, cep_scaling_min_acoplanarity
from lbl_paths import processes, merged_histograms_path
from lbl_paths import acoplanarity_histogram_name
from Logger import warn


input_files = {}
input_histograms = {}

qed_and_lbl_scaled = False


def load_histograms(skim):
    if len(input_files) > 0:
        return
    
    for process in processes:
        file_path = merged_histograms_path.format(process, skim)
        input_files[process] = ROOT.TFile.Open(file_path)

        hist_name = acoplanarity_histogram_name.format(n_acoplanarity_bins)

        input_histograms[process] = input_files[process].Get(hist_name)
        if input_histograms[process] is None or type(input_histograms[process]) is ROOT.TObject:
            print(f"ERROR - hist {hist_name} not found in file: {file_path}")
            exit()


def scale_lbl_and_qed_histograms():
    if not hasattr(scale_lbl_and_qed_histograms, "called"):
        scale_lbl_and_qed_histograms.called = True
    else:
        warn("scale_lbl_and_qed_histograms() called more than once!")
        return

    print("Scaling qed and lbl histograms...")
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
