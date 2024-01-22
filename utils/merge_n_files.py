import glob
import os


def merge_n_files(directory, pattern, output_path, output_pattern, n_to_merge):
    total_entries = 0
    path_pattern = os.path.join(directory, pattern)

    file_paths = glob.glob(path_pattern)
    print(f"Found {len(file_paths)} files matching pattern {path_pattern}")

    files_to_merge = []
    output_ntuple_counter = 0

    for filename in file_paths:
        if len(files_to_merge) == n_to_merge:
            output_filename = output_pattern.format(output_ntuple_counter)
            output_filename = os.path.join(output_path, output_filename)

            print(f"\n\nMerging files: {files_to_merge}")
            print(f"Merging into: {output_filename}")

            os.system(f"hadd -f -j -k {output_filename} {' '.join(files_to_merge)}")

            files_to_merge = []
            output_ntuple_counter += 1
            
        files_to_merge.append(filename)

    if len(files_to_merge) != 0:
        output_filename = output_pattern.format(output_ntuple_counter)
        output_filename = os.path.join(output_path, output_filename)

        print(f"\n\nMerging files: {files_to_merge}")
        print(f"Merging into: {output_filename}")

        os.system(f"hadd -f -j -k {output_filename} {' '.join(files_to_merge)}")

    return total_entries


def main():
    input_path = "/eos/cms/store/cmst3/group/lightbylight/Pranati/Final_afterTrigger/Data/Data_29thJune"
    input_pattern = "ntuples_loose_selections_*.root"

    output_path = "/eos/cms/store/cmst3/group/lightbylight/analysis_jeremi/ntuples/collisionData"
    output_pattern = "ntuple_{}.root"

    merge_n_files(input_path, input_pattern, output_path, output_pattern, 10)


if __name__ == "__main__":
    main()
