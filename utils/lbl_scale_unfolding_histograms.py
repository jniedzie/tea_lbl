import ROOT
from lbl_params import luminosity, crossSections, get_scale_factor, nGenEvents, n_acoplanarity_bins
from lbl_helpers import get_cep_scale
from lbl_paths import merged_histograms_path, processes, skim, acoplanarity_histogram_name


samples = processes


def main():
    files = {}
    hists = {}
    hists_up = {}
    hists_low = {}
    variables = ["mass", "pt", "absRap", "absRap3", "rap3", "rap4",
                 "costhetastar2", "costhetastar3", "costhetastar4", "aco"]

    for variable in variables:
        hists[variable] = {}
        hists_up[variable] = {}
        hists_low[variable] = {}

    photon_sf, _ = get_scale_factor(photon=True)

    for sample in samples:
        print(
            f"Processing file: {merged_histograms_path.format(sample, skim)}")
        files[sample] = ROOT.TFile.Open(
            merged_histograms_path.format(sample, skim))
        output_file = ROOT.TFile(
            f"unfoldingHistograms_{sample}.root", "recreate")

        for variable in variables:
            if variable == "aco":
                name = acoplanarity_histogram_name.format(n_acoplanarity_bins)
            else:
                name = f"unfoldingPhoton_{variable}"

            hists[variable][sample] = files[sample].Get(name)
            hists[variable][sample].SetBinErrorOption(ROOT.TH1.kPoisson)

            err_low = {}
            err_up = {}

            for i in range(1, hists[variable][sample].GetNbinsX()+1):
                err_low[i] = hists[variable][sample].GetBinErrorLow(i)
                err_up[i] = hists[variable][sample].GetBinErrorUp(i)

            if sample == "collisionData":
                scale = 1
            elif sample == "lbl" or "qed" in sample:
                scale = luminosity * \
                    crossSections[sample]*photon_sf/nGenEvents[sample]
            elif sample == "cep":
                scale = get_cep_scale(skim)[0]

            hists[variable][sample].Scale(scale)

            hists_up[variable][sample] = hists[variable][sample].Clone()
            hists_low[variable][sample] = hists[variable][sample].Clone()

            hists_up[variable][sample].SetName(name+"_errUp")
            hists_low[variable][sample].SetName(name+"_errLow")

            for i in range(1, hists[variable][sample].GetNbinsX()+1):
                hists_low[variable][sample].SetBinError(i, err_low[i]*scale)
                hists_up[variable][sample].SetBinError(i, err_up[i]*scale)

            output_file.cd()
            hists[variable][sample].Write()
            hists_low[variable][sample].Write()
            hists_up[variable][sample].Write()

        output_file.Close()


if __name__ == "__main__":
    main()
