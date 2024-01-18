base_path = "/nfs/dust/cms/user/jniedzie/light_by_light/"

# for renaming
# input_directory = f"{base_path}/ntuples_pranati/collisionData/"
# output_dir = f"{base_path}/ntuples/collisionData/initial/"

# input_directory = f"{base_path}/ntuples_pranati/lbl/"
# output_dir = f"{base_path}/ntuples/lbl/initial/"

# input_directory = f"{base_path}/ntuples_pranati/qed/"
# output_dir = f"{base_path}/ntuples/qed/initial/"

# input_directory = f"{base_path}/ntuples_pranati/cep/"
# output_dir = f"{base_path}/ntuples/cep/initial/"


# neutral exclusivity
sample = "collisionData"
# sample = "lbl"
# sample = "cep"
# sample = "qed"

skim = "skimmed_twoPhotons"
# skim = "skimmed_neutralExclusivity"

input_directory = f"{base_path}/ntuples/{sample}/initial/"
output_dir = f"{base_path}/ntuples/{sample}/{skim}/"
