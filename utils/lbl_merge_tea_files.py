import os

from lbl_paths import base_path, processes

# skim = "initial"
# skim = "skimmed_qedSelections"
# skim = "skimmed_qedSelections_noZDC"
# skim = "skimmed_lblSelections_final"
# skim = "skimmed_lblSelections_final_andZDC"
# skim = "skimmed_lblSelections_final_andZDC3n"
skim = "skimmed_lblSelections_final_andZDC2n"
# skim = "skimmed_lblSelections_final_noZDC"
# skim = "skimmed_lblSelections_onlyNee"

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
