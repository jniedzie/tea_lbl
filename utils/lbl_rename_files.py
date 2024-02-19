import os
import glob
from lbl_paths import base_path, processes

dry_run = False


def main():
    # for process in processes:
    #     if "alp" not in process:
    #         continue

    process = "qed_noTrigger"

    path = f"{base_path}/{process}/bad_names/*.root"
    print("Renaming files in: ", path)

    files = glob.glob(path)
    files.sort()

    # rename each file
    for i, file in enumerate(files):
        if dry_run:
            print(
                f"Would rename {file} to {base_path}/{process}/bad_names/ntuple_{i}.root")
        else:
            os.rename(
                file, f"{base_path}/{process}/bad_names/ntuple_{i}.root")


if __name__ == "__main__":
    main()
