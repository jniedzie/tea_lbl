import ROOT
from lbl_params import luminosity, crossSections, get_scale_factor, nGenEvents, n_acoplanarity_bins
from lbl_helpers import get_cep_scale
from lbl_paths import merged_histograms_path, processes, skim, acoplanarity_histogram_name


samples = processes

def main():
    files = {}

    hists_mass = {}
    hists_pt = {}
    hists_rap = {}
    hists_rap3 = {}
    hists_rap4 = {}
    hists_costheta2 = {}
    hists_costheta3 = {}
    hists_costheta4 = {}
    
    hists_aco = {}

    photon_sf, _ = get_scale_factor(photon=True)

    for sample in samples:
        files[sample] = ROOT.TFile.Open(merged_histograms_path.format(sample, skim))

        hists_mass[sample] = files[sample].Get("unfoldingPhoton_mass")
        hists_pt[sample] = files[sample].Get("unfoldingPhoton_pt")
        hists_rap[sample] = files[sample].Get("unfoldingPhoton_absRap")
        hists_rap3[sample] = files[sample].Get("unfoldingPhoton_rap3")
        hists_rap4[sample] = files[sample].Get("unfoldingPhoton_rap4")
        hists_costheta2[sample] = files[sample].Get("unfoldingPhoton_costhetastar2")
        hists_costheta3[sample] = files[sample].Get("unfoldingPhoton_costhetastar3")
        hists_costheta4[sample] = files[sample].Get("unfoldingPhoton_costhetastar4")
        
        hists_aco[sample] = files[sample].Get(acoplanarity_histogram_name.format(n_acoplanarity_bins))

        if sample == "collisionData":
            pass
        elif sample == "lbl" or "qed" in sample:
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
            
            hists_costheta2[sample].Scale(luminosity*crossSections[sample]*photon_sf/nGenEvents[sample])
            hists_costheta3[sample].Scale(luminosity*crossSections[sample]*photon_sf/nGenEvents[sample])
            hists_costheta4[sample].Scale(luminosity*crossSections[sample]*photon_sf/nGenEvents[sample])
            
            hists_aco[sample].Scale(luminosity*crossSections[sample]*photon_sf/nGenEvents[sample])
            
        elif sample == "cep":
            cep_scale = get_cep_scale(skim)[0]
            hists_mass[sample].Scale(cep_scale)
            hists_pt[sample].Scale(cep_scale)
            hists_rap[sample].Scale(cep_scale)
            hists_rap3[sample].Scale(cep_scale)
            hists_rap4[sample].Scale(cep_scale)
            hists_costheta2[sample].Scale(cep_scale)
            hists_costheta3[sample].Scale(cep_scale)
            hists_costheta4[sample].Scale(cep_scale)
            hists_aco[sample].Scale(cep_scale)
            
        output_file = ROOT.TFile(f"unfoldingHistograms_{sample}.root", "recreate")
        output_file.cd()
        hists_mass[sample].Write()
        hists_pt[sample].Write()
        hists_rap[sample].Write()
        hists_rap3[sample].Write()
        hists_rap4[sample].Write()
        hists_costheta2[sample].Write()
        hists_costheta3[sample].Write()
        hists_costheta4[sample].Write()
        hists_aco[sample].Write()
        
        output_file.Close()


if __name__ == "__main__":
    main()
