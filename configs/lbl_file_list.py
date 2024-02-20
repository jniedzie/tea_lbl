base_path = "/nfs/dust/cms/user/jniedzie/light_by_light/"

samples = (
    "collisionData",
    "lbl",
    # "lbl_noTrigger",
    "cep",
    "qed",
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
# skim = "skimmed_allSelections"
# skim = "skimmed_allSelections_photonEt2p0"
# skim = "skimmed_allSelections_photonEt2p5"
# skim = "skimmed_allSelections_noSeedTime"
# skim = "skimmed_allSelections_swissCross0p99"
# skim = "skimmed_allSelections_deltaEt"
# skim = "skimmed_allSelections_deltaEt0p65"
skim = "skimmed_allSelections_hadCrack"
# skim = "skimmed_allSelections_hadCrack_noZDC"


# skim = "skimmed_qedSelections"
# skim = "skimmed_qedSelections_noZDC"

# for renaming
# input_directory = f"{base_path}/ntuples/{sample_path}/bad_names/"
# output_dir = f"{base_path}/ntuples/{sample_path}/initial/"

# for skimming
# input_directory = f"{base_path}/ntuples/{sample_path}/initial/"
# output_dir = f"{base_path}/ntuples/{sample_path}/{skim}/"

# for histogramming
input_directory = f"{base_path}/ntuples/{sample_path}/{skim}/"
output_dir = f"{base_path}/ntuples/{sample_path}/{skim}/histograms/"
