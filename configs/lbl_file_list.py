from lbl_paths import processes, skim

base_path = "/nfs/dust/cms/user/jniedzie/light_by_light/"

samples = processes

sample_path = ""

# for renaming
# input_directory = f"{base_path}/ntuples/{sample_path}/bad_names/"
# output_dir = f"{base_path}/ntuples/{sample_path}/initial/"

# for skimming
# input_directory = f"{base_path}/ntuples/{sample_path}/initial/"
# output_dir = f"{base_path}/ntuples/{sample_path}/{skim}/"

# for histogramming (condor)
input_directory = f"{base_path}/ntuples/{sample_path}/{skim}/"
output_dir = f"{base_path}/ntuples/{sample_path}/{skim}/histograms/"

# for histogramming (local)
# input_output_file_list = (
#     (f"{base_path}/ntuples/{sample_path}/merged_{skim}.root",
#      f"{base_path}/ntuples/{sample_path}/merged_{skim}_histograms.root"
#      ),
# )
