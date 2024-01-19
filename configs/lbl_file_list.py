base_path = "/nfs/dust/cms/user/jniedzie/light_by_light/"

sample = "collisionData"
# sample = "lbl"
# sample = "cep"
# sample = "qed"

# skim = "skimmed_twoPhotons"
# skim = "skimmed_neutralExclusivity"
skim = "skimmed_allSelections"

# for renaming
# input_directory = f"{base_path}/ntuples_pranati/{sample}/"
# output_dir = f"{base_path}/ntuples/{sample}/initial/"

# for skimming
input_directory = f"{base_path}/ntuples/{sample}/initial/"
output_dir = f"{base_path}/ntuples/{sample}/{skim}/"

# for histogramming
# input_directory = f"{base_path}/ntuples/{sample}/{skim}/"
# output_dir = f"{base_path}/ntuples/{sample}/{skim}/histograms/"
