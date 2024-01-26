import ROOT
from lbl_params import luminosity, crossSections, scaleFactors, nGenEvents
from lbl_params import n_acoplanarity_bins, cep_scaling_min_acoplanarity
from lbl_paths import processes, merged_histograms_path
from lbl_paths import acoplanarity_histogram_name, mass_histogram_name
from Logger import info, warn, fatal


input_files = {}
input_aco_histograms = {}
input_mass_histograms = {}

qed_and_lbl_scaled = False


def silence_root():
    ROOT.gErrorIgnoreLevel = ROOT.kFatal


def unsilence_root():
    ROOT.gErrorIgnoreLevel = ROOT.kInfo


def load_histograms(skim):
    if len(input_files) > 0:
        return

    silence_root()

    for process in processes:
        file_path = merged_histograms_path.format(process, skim)

        try:
            input_files[process] = ROOT.TFile.Open(file_path)

        except (OSError):
            warn(f"File not found: {file_path}")
            continue

        aco_hist_name = acoplanarity_histogram_name.format(n_acoplanarity_bins)

        input_aco_histograms[process] = input_files[process].Get(aco_hist_name)
        input_mass_histograms[process] = input_files[process].Get(
            mass_histogram_name)

        if any([input_aco_histograms[process] is None,
                type(input_aco_histograms[process]) is ROOT.TObject,
                input_mass_histograms[process] is None,
                type(input_mass_histograms[process]) is ROOT.TObject]):
            fatal(f"Some histograms not found in file: {file_path}")
            exit()

    unsilence_root()


def scale_non_cep_histograms():
    if not hasattr(scale_non_cep_histograms, "called"):
        scale_non_cep_histograms.called = True
    else:
        warn("scale_lbl_and_qed_histograms() called more than once!")
        return

    print("Scaling qed and lbl histograms...")
    for process in processes:
        if process == "cep" or process == "collisionData":
            continue

        if process not in input_aco_histograms:
            continue

        scale = luminosity*crossSections[process]*scaleFactors[process]
        scale /= nGenEvents[process]

        input_aco_histograms[process].Scale(scale)
        input_mass_histograms[process].Scale(scale)


def get_cep_scale(skim):
    load_histograms(skim)
    scale_non_cep_histograms()

    hist_data_no_background = input_aco_histograms["collisionData"].Clone()
    hist_data_no_background.Add(input_aco_histograms["lbl"], -1)
    hist_data_no_background.Add(input_aco_histograms["qed"], -1)

    integral_data = hist_data_no_background.Integral(
        hist_data_no_background.FindBin(cep_scaling_min_acoplanarity),
        hist_data_no_background.GetNbinsX()
    )

    integral_cep = input_aco_histograms["cep"].Integral(
        input_aco_histograms["cep"].FindBin(cep_scaling_min_acoplanarity),
        input_aco_histograms["cep"].GetNbinsX()
    )

    return integral_data / integral_cep
