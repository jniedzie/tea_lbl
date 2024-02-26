base_path = "/nfs/dust/cms/user/jniedzie/light_by_light/"

samples = (
    "collisionData",
    "lbl",
    "cep",
    "qed",
    
    # "lbl_noTrigger",
    # "qed_noTrigger",

    # "alps_5",
    # "alps_6",
    # "alps_9",
    # "alps_11",
    # "alps_14",
    # "alps_16",
    # "alps_22",
    # "alps_30",
    # "alps_50",
    # "alps_90",

    # "emptyBeams",
)

sample_path = ""

# skim = "initial"
# skim = "skimmed_lblSelections_final"
# skim = "skimmed_lblSelections_final_andZDC"
# skim = "skimmed_lblSelections_final_andZDC3n"
skim = "skimmed_lblSelections_final_andZDC2n"
# skim = "skimmed_lblSelections_final_noZDC"
# skim = "skimmed_lblSelections_onlyNee"

# skim = "skimmed_qedSelections"
# skim = "skimmed_qedSelections_noZDC"

# for renaming
# input_directory = f"{base_path}/ntuples/{sample_path}/bad_names/"
# output_dir = f"{base_path}/ntuples/{sample_path}/initial/"

# for skimming
input_directory = f"{base_path}/ntuples/{sample_path}/initial/"
output_dir = f"{base_path}/ntuples/{sample_path}/{skim}/"

# for histogramming
# input_directory = f"{base_path}/ntuples/{sample_path}/{skim}/"
# output_dir = f"{base_path}/ntuples/{sample_path}/{skim}/histograms/"
