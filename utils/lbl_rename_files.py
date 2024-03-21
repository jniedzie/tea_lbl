import os
import glob
from lbl_paths import base_path, processes

dry_run = False


def main():
    # for process in processes:
    #     if "alp" not in process:
    #         continue

    process = "qed_sc_noPhotos"
    skim = "bad_names_afterTrigger"

    path = f"{base_path}/{process}/{skim}/*.root"
    print("Renaming files in: ", path)

    files = glob.glob(path)
    files.sort()

    # rename each file
    for i, file in enumerate(files):
        if dry_run:
            print(
                f"Would rename {file} to {base_path}/{process}/{skim}/ntuple_{i}.root")
        else:
            os.rename(
                file, f"{base_path}/{process}/{skim}/ntuple_{i}.root")


if __name__ == "__main__":
    main()
