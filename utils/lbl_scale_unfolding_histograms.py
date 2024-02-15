import ROOT
from lbl_params import luminosity, crossSections, scaleFactors, nGenEvents
from lbl_helpers import get_cep_scale
from lbl_paths import merged_histograms_path


samples = ["collisionData", "lbl", "cep", "qed"]
skim = "skimmed_allSelections_hadCrack"


def main():
    files = {}

    hists_mass = {}
    hists_pt = {}
    hists_rap = {}

    for sample in samples:
        files[sample] = ROOT.TFile.Open(merged_histograms_path.format(sample, skim))

        hists_mass[sample] = files[sample].Get("unfoldingPhoton_mass")
        hists_pt[sample] = files[sample].Get("unfoldingPhoton_pt")
        hists_rap[sample] = files[sample].Get("unfoldingPhoton_absRap")

        if sample == "data":
            pass
        elif sample == "lbl" or sample == "qed":
            hists_mass[sample].Scale(
                luminosity*crossSections[sample]*scaleFactors[sample]/nGenEvents[sample])
            hists_pt[sample].Scale(
                luminosity*crossSections[sample]*scaleFactors[sample]/nGenEvents[sample])
            hists_rap[sample].Scale(
                luminosity*crossSections[sample]*scaleFactors[sample]/nGenEvents[sample])
        elif sample == "cep":
            hists_mass[sample].Scale(get_cep_scale(skim))
            hists_pt[sample].Scale(get_cep_scale(skim))
            hists_rap[sample].Scale(get_cep_scale(skim))
            
        output_file = ROOT.TFile(f"unfoldingHistograms_{sample}.root", "recreate")
        output_file.cd()
        hists_mass[sample].Write()
        hists_pt[sample].Write()
        hists_rap[sample].Write()
        
        output_file.Close()


if __name__ == "__main__":
    main()
