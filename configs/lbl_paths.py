qed_superchic = "qed"
qed_mg1gamma = "qed_MG_ee_a"
qed_mg2gamma = "qed_MG_ee_aa"
qed_starlight = "qed_starlight"

processes = (
    "collisionData",
    "lbl",
    "cep",
    qed_superchic,
    # qed_starlight,
    # qed_mg1gamma,
    # qed_mg2gamma,

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

# skim = "initial"

# skim = "skimmed_lblSelections_finalXn0n"
# skim = "skimmed_lblSelections_finalXn1n"
# skim = "skimmed_lblSelections_final_2n2n"
skim = "skimmed_lblSelections_final_photonMatchingdeltaPhi0p15"
# skim = "skimmed_lblSelections_final"
# skim = "skimmed_lblSelections_final_andZDC"
# skim = "skimmed_lblSelections_final_andZDC3n"
# skim = "skimmed_lblSelections_final_andZDC2n"
# skim = "skimmed_lblSelections_final_andZDC1n"
# skim = "skimmed_lblSelections_final_noZDC"
# skim = "skimmed_lblSelections_onlyNee"

# skim = "skimmed_qedSelections"
# skim = "skimmed_qedSelections_noPtCut"
# skim = "skimmed_qedSelections_noZDC"

# skim = "skimmed_tracksPhotonsSelections"
# skim = "skimmed_tracksPhotonsSelectionsWithDiphotonPt"
# skim = "skimmed_tracksPhotonsSelectionsWithDiphotonPtNoNEE"

acoplanarity_histogram_name = "diphoton_acoplanarity{}"
# mass_histogram_name = "diphoton_mass{}"
mass_histogram_name = "diphotonSR_mass{}"

base_path = "/nfs/dust/cms/user/jniedzie/light_by_light/ntuples/"
merged_histograms_path = base_path + "/{}/merged_{}_histograms.root"
