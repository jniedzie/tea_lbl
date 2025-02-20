from lbl_paths import processes, skim, base_path

samples = processes
sample_path = ""

# condor:
input_directory = f"{base_path}/{sample_path}/{skim}/"
output_hists_dir = f"{base_path}/{sample_path}/{skim}/histograms/"


# local:
# input_output_file_list = (
#     (f"{base_path}/ntuples/{sample_path}/merged_{skim}.root",
#      f"{base_path}/ntuples/{sample_path}/merged_{skim}_histograms.root"
#      ),
# )
