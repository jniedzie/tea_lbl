import ROOT
from collections import OrderedDict

from lbl_params import luminosity, crossSections, scaleFactors, nGenEvents
from lbl_cep_scale_calculator import get_cep_scale


base_path = "/nfs/dust/cms/user/jniedzie/light_by_light/ntuples"

samples = (
    "collisionData",
    "lbl",
    "cep",
    "qed",
)

# skim = "skimmed_twoPhotons"
# skim = "skimmed_neutralExclusivity"
# skim = "skimmed_allSelections"
skim = "skimmed_allSelections_photonEt2p0"


def main():
    ROOT.gROOT.SetBatch(True)

    for sample in samples:
        input_path = f"{base_path}/{sample}/merged_{skim}.root"
        print(f"Analyzing file: {input_path}")

        if sample == "cep":
            scale = get_cep_scale(skim)
        elif sample == "collisionData":
            scale = 1
        else:
            scale = luminosity*crossSections[sample]*scaleFactors[sample]
            scale /= nGenEvents[sample]

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
            print(f"{key:30} {value:10}\t\t{value*scale:.4f}")


if __name__ == "__main__":
    main()
