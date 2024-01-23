import ROOT
from collections import OrderedDict

base_path = "/nfs/dust/cms/user/jniedzie/light_by_light/ntuples"

samples = (
    "collisionData",
    "lbl",
    "cep",
    "qed",
)

# skim = "skimmed_twoPhotons"
# skim = "skimmed_neutralExclusivity"
skim = "skimmed_allSelections"


luminosity = 1647.228136  # μb^-1

scale = {
    "collisionData": 1,
    # lumi * xsec * SFs / n_gen
    "lbl": luminosity * 2.59 * 0.8477 * 0.9322 * 0.9771**2 * 0.8643 * 1.0006 / 466000,
    # lumi * xsec * SFs / n_gen
    "qed": luminosity * 8827.220 * 0.8477 * 0.9322 * 0.952**2 * 0.8643 * 1.0006 / 59260000,
    "cep": 0.0012475821798342804,
}


def main():
    ROOT.gROOT.SetBatch(True)

    for sample in samples:
        input_path = f"{base_path}/{sample}/merged_{skim}.root"
        print(f"Analyzing file: {input_path}")

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
            print(f"{key:30} {value:10}\t\t{value*scale[sample]:.4f}")


if __name__ == "__main__":
    main()
