import math
import ROOT

from Logger import info, warn, fatal

from lbl_params import luminosity, crossSections, scaleFactors, nGenEvents
from lbl_params import n_acoplanarity_bins, cep_scaling_min_acoplanarity, n_mass_bins
from lbl_paths import processes, merged_histograms_path
from lbl_paths import acoplanarity_histogram_name, mass_histogram_name


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

        except OSError:
            warn(f"File not found: {file_path}")
            continue

        aco_hist_name = acoplanarity_histogram_name.format(n_acoplanarity_bins)
        mass_hist_name = mass_histogram_name.format(n_mass_bins)

        input_aco_histograms[process] = input_files[process].Get(aco_hist_name)
        input_mass_histograms[process] = input_files[process].Get(
            mass_hist_name)

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


cep_scale = -1
cep_scale_err = -1


def get_cep_scale(skim):
    global cep_scale
    global cep_scale_err
    
    if cep_scale > 0:
        return cep_scale, cep_scale_err

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
    
    cep_scale = integral_data / integral_cep

    integral_data_err = integral_data**0.5
    integral_cep_err = integral_cep**0.5
    
    cep_scale_err = cep_scale * (
        (integral_data_err/integral_data)**2 +
        (integral_cep_err/integral_cep)**2
    )**0.5

    return cep_scale, cep_scale_err


def get_alp_coupling(mass, cross_section):
    slope = 0.498809
    interstect = {
        5.0: 1.3352627780449595e-05,
        6.0: 1.459208443729578e-05,
        9.0: 1.8432339658251058e-05,
        11.0: 2.051773548082086e-05,
        14.0: 2.4387325416686648e-05,
        16.0: 2.643930742885861e-05,
        22.0: 3.323868088097294e-05,
        30.0: 4.4114845375054456e-05,
        50.0: 7.817673899208805e-05,
        90.0: 0.00019612635077675486,
    }

    return 10**(slope * math.log10(cross_section) + math.log10(interstect[mass]))
