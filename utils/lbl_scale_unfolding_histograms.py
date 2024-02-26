import ROOT
from lbl_params import luminosity, crossSections, get_scale_factor, nGenEvents
from lbl_helpers import get_cep_scale
from lbl_paths import merged_histograms_path


samples = ["collisionData", "lbl", "cep", "qed"]
skim = "skimmed_lblSelections_final"


def main():
    files = {}

    hists_mass = {}
    hists_pt = {}
    hists_rap = {}
    hists_rap3 = {}
    hists_rap4 = {}

    photon_sf, _ = get_scale_factor(photon=True)

    for sample in samples:
        files[sample] = ROOT.TFile.Open(merged_histograms_path.format(sample, skim))

        hists_mass[sample] = files[sample].Get("unfoldingPhoton_mass")
        hists_pt[sample] = files[sample].Get("unfoldingPhoton_pt")
        hists_rap[sample] = files[sample].Get("unfoldingPhoton_absRap")
        hists_rap3[sample] = files[sample].Get("unfoldingPhoton_rap3")
        hists_rap4[sample] = files[sample].Get("unfoldingPhoton_rap4")

        if sample == "data":
            pass
        elif sample == "lbl" or sample == "qed":
            hists_mass[sample].Scale(
                luminosity*crossSections[sample]*photon_sf/nGenEvents[sample])
            hists_pt[sample].Scale(
                luminosity*crossSections[sample]*photon_sf/nGenEvents[sample])
            hists_rap[sample].Scale(
                luminosity*crossSections[sample]*photon_sf/nGenEvents[sample])
            hists_rap3[sample].Scale(
                luminosity*crossSections[sample]*photon_sf/nGenEvents[sample])
            hists_rap4[sample].Scale(
                luminosity*crossSections[sample]*photon_sf/nGenEvents[sample])
            
        elif sample == "cep":
            hists_mass[sample].Scale(get_cep_scale(skim)[0])
            hists_pt[sample].Scale(get_cep_scale(skim)[0])
            hists_rap[sample].Scale(get_cep_scale(skim)[0])
            hists_rap3[sample].Scale(get_cep_scale(skim)[0])
            hists_rap4[sample].Scale(get_cep_scale(skim)[0])
            
        output_file = ROOT.TFile(f"unfoldingHistograms_{sample}.root", "recreate")
        output_file.cd()
        hists_mass[sample].Write()
        hists_pt[sample].Write()
        hists_rap[sample].Write()
        hists_rap3[sample].Write()
        hists_rap4[sample].Write()
        
        output_file.Close()


if __name__ == "__main__":
    main()
