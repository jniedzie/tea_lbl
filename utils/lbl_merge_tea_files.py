import os

from lbl_paths import base_path, processes

# skim = "initial"
# skim = "skimmed_allSelections"
# skim = "skimmed_allSelections_photonEt2p0"
# skim = "skimmed_allSelections_photonEt2p5"
# skim = "skimmed_allSelections_swissCross0p99"
skim = "skimmed_allSelections_hadCrack"
# skim = "skimmed_allSelections_hadCrack_noZDC"
# skim = "skimmed_qedSelections"
# skim = "skimmed_qedSelections_noZDC"

merge_histograms = True  # False for merging ntuples


def main():
    for process in processes:
        hist_path = "histograms" if merge_histograms else ""
        input_path = f"{base_path}/{process}/{skim}/{hist_path}/*.root"

        hist_path = "_histograms" if merge_histograms else ""
        output_path = f"{base_path}/{process}/merged_{skim}{hist_path}.root"

        print(f"{process=}")
        print(f"{output_path=}")

        os.system(f"rm {output_path}")
        os.system(f"hadd -f -j -k {output_path} {input_path}")


if __name__ == "__main__":
    main()
