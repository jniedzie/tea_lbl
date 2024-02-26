import ROOT
from collections import OrderedDict

from lbl_params import luminosity, crossSections, nGenEvents, get_scale_factor
from lbl_helpers import get_cep_scale
from lbl_paths import base_path, processes

# skim = "skimmed_qedSelections"
# skim = "skimmed_qedSelections_noZDC"
# skim = "skimmed_lblSelections_final"
# skim = "skimmed_lblSelections_final_andZDC"
# skim = "skimmed_lblSelections_final_andZDC3n"
# skim = "skimmed_lblSelections_final_andZDC2n"
skim = "skimmed_lblSelections_onlyNee"


def main():
    ROOT.gROOT.SetBatch(True)

    photon_sf, _ = get_scale_factor(photon=True)

    for process in processes:
        input_path = f"{base_path}/{process}/merged_{skim}.root"
        print(f"Analyzing file: {input_path}")

        if process == "cep":
            scale, _ = get_cep_scale(skim)
        elif process == "collisionData":
            scale = 1
        else:
            scale = luminosity*crossSections[process]*photon_sf
            scale /= nGenEvents[process]

        file = ROOT.TFile(input_path, "READ")
        dir = file.Get("CutFlow")
        keys = dir.GetListOfKeys()
        hist_dict = OrderedDict()

        for key in keys:
            hist = dir.Get(key.GetName())
            hist_dict[key.GetName()] = hist.GetBinContent(1)

        hist_dict = OrderedDict(
            sorted(hist_dict.items(), key=lambda x: int(x[0].split("_")[0])))

        print("CutFlow:")
        for key, value in hist_dict.items():
            print(f"{key:30}: {value:10}\t\t{value*scale:.4f}")


if __name__ == "__main__":
    main()
