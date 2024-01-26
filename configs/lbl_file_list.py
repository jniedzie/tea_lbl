base_path = "/nfs/dust/cms/user/jniedzie/light_by_light/"

samples = (
    "collisionData",
    "lbl",
    "cep",
    "qed",
)

sample_path = ""

# skim = "initial"
# skim = "skimmed_allSelections"
skim = "skimmed_allSelections_swissCross0p99"

# for renaming
# input_directory = f"{base_path}/ntuples/{sample}/bad_names/"
# output_dir = f"{base_path}/ntuples/{sample}/initial/"

# for skimming
# input_directory = f"{base_path}/ntuples/{sample_path}/initial/"
# output_dir = f"{base_path}/ntuples/{sample_path}/{skim}/"

# for histogramming
input_directory = f"{base_path}/ntuples/{sample_path}/{skim}/"
output_dir = f"{base_path}/ntuples/{sample_path}/{skim}/histograms/"
