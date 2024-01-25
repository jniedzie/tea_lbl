base_path = "/nfs/dust/cms/user/jniedzie/light_by_light/"

samples = (
    "collisionData",
    "lbl",
    "cep",
    "qed",
)

sample_path = ""

# skim = "initial"
# skim = "skimmed_twoPhotons"
# skim = "skimmed_neutralExclusivity"
# skim = "skimmed_allSelections"
# skim = "skimmed_allSelections_track3validHits"
# skim = "skimmed_allSelections_maxDiphotonPt2"
# skim = "skimmed_allSelections_nTowers1"
# skim = "skimmed_allSelections_swissCross99"
# skim = "skimmed_allSelections_eta2p4"
# skim = "skimmed_allSelections_seedTime3p6"
# skim = "skimmed_allSelections_electron0missingHits1"
# skim = "skimmed_allSelections_trackEta2p2"
# skim = "skimmed_allSelections_HF7"
# skim = "skimmed_allSelections_HB3"
# skim = "skimmed_allSelections_trackPt1p0"
# skim = "skimmed_allSelections_trackPt0p5"
# skim = "skimmed_allSelections_HE1p2"
# skim = "skimmed_allSelections_EB1p0"
skim = "skimmed_allSelections_EE3p5"
# skim = "skimmed_allSelections_EE4p0"
# skim = "skimmed_allSelections_EE3p3"
# skim = "skimmed_allSelections_EE3p7"
# skim = "skimmed_allSelections_HEedge1p41"
# skim = "skimmed_allSelections_hadronCrack"
# skim = "skimmed_allSelections_emCrack"
# skim = "skimmed_allSelections_HFedge3p0"
# skim = "skimmed_allSelections_diphotonMass4p5"
# skim = "skimmed_allSelections_eleIso0p01"
# skim = "skimmed_allSelections_caloEta2p2"
# skim = "skimmed_allSelections_EE7p5"
# skim = "skimmed_allSelections_swissCross99_EE3p5_EEeta2p2"
# skim = "skimmed_allSelections_swissCross99_EE3p5"
# skim = "skimmed_allSelections_EE3p5_EEeta2p2"
# skim = "skimmed_allSelections_EE3p4"
# skim = "skimmed_allSelections_EE3p6"
# skim = "skimmed_allSelections_EE3p5_trackPt0p4"
# skim = "skimmed_allSelections_EE3p5_deadHEfix"
# skim = "skimmed_allSelections_deltaEtaEE0p8"
# skim = "skimmed_allSelections_EE3p5_deltaEtaEE0p25"

# for renaming
# input_directory = f"{base_path}/ntuples/{sample}/bad_names/"
# output_dir = f"{base_path}/ntuples/{sample}/initial/"

# for skimming
# input_directory = f"{base_path}/ntuples/{sample_path}/initial/"
# output_dir = f"{base_path}/ntuples/{sample_path}/{skim}/"

# for histogramming
input_directory = f"{base_path}/ntuples/{sample_path}/{skim}/"
output_dir = f"{base_path}/ntuples/{sample_path}/{skim}/histograms/"
