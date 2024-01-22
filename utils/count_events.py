import ROOT
import glob
import os


def count_tree_entries(directory, pattern, tree_name):
    total_entries = 0
    path_pattern = os.path.join(directory, pattern)

    file_paths = glob.glob(path_pattern)

    print(f"Found {len(file_paths)} files matching pattern {path_pattern}")

    for filename in file_paths:
        print(f"Processing file: {filename}")
        root_file = ROOT.TFile.Open(filename, "READ")
        if root_file.IsOpen():
            tree = root_file.Get(tree_name)
            if tree:
                total_entries += tree.GetEntries()
            else:
                print(f"Failed to open tree {tree_name}")
            root_file.Close()
        else:
            print(f"Failed to open {filename}")

    return total_entries


def main():
    # Example usage
    directory = "/eos/cms/store/cmst3/group/lightbylight/Pranati/Final_afterTrigger/Data/Data_29thJune"
    pattern = "ntuples_loose_selections_*.root"
    tree_name = "ggHiNtuplizer/EventTree"

    total = count_tree_entries(directory, pattern, tree_name)
    print(f"Total entries in all trees: {total}")


if __name__ == "__main__":
    main()
