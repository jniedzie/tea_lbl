import ROOT
from collections import OrderedDict

base_path = "/nfs/dust/cms/user/jniedzie/light_by_light/ntuples"

# sample = "collisionData"
sample = "lbl"
# sample = "cep"
# sample = "qed"

# skim = "skimmed_twoPhotons"
# skim = "skimmed_neutralExclusivity"
skim = "skimmed_allSelections"

# input_path = "../bin/skimmed.root"
# input_path = f"{base_path}/{sample}/merged_{skim}.root"
input_path = f"{base_path}/{sample}/{skim}/ntuple_3.root"

scale = False if sample == "collisionData" else True

luminosity = 1647.228136  # μb^-1

# QED superchic
# n_gen_events = 59260000
# cross_section = 8827.220  # (μb)
# scale_factors = 0.8477 * 0.9322 * 0.952**2 * 1.0006 * 0.8643

# LbL
n_gen_events = 466000
cross_section = 2.59  # (μb)
scale_factors = 0.8477 * 0.9322 * 0.9771**2 * 0.8643 * 1.0006


def main():
    ROOT.gROOT.SetBatch(True)

    print(f"Analyzing file: {input_path}")

    file = ROOT.TFile(input_path, "READ")
    dir = file.Get("CutFlow")
    keys = dir.GetListOfKeys()
    hist_dict = OrderedDict()

    for key in keys:
        hist = dir.Get(key.GetName())
        hist_dict[key.GetName()] = hist.GetBinContent(1)

    hist_dict = OrderedDict(sorted(hist_dict.items(), key=lambda x: int(x[0].split("_")[0])))

    print("CutFlow:")
    initial = -1
    for key, value in hist_dict.items():
        if initial == -1:
            initial = value
        if scale:
            weight = 1/n_gen_events * cross_section * luminosity
            weight *= scale_factors
            print(f"{key:30} {value:10}\t\t{value*weight:.4f}")
        else:
            print(f"{key:30} {value:10}")


if __name__ == "__main__":
    main()
