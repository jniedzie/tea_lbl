from teaHelpers import get_facility

processes = (
    "collisionData",
    "lbl",
    "cep",
    "qed_superchic",
    "qed_starlight",
    # "qed_MG_ee_a",
    # "qed_MG_ee_aa"
    # "qed_sc_noPhotos",

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
    # "collisionDataZeroBias",
)

qed_names = ["qed_superchic", "qed_starlight"]

# this is the final final skim:
# input_skim = "initial"
input_skim = "initial_doubleEG2"

# skim = "skimmed_lblSelections_final_photonMatchingdeltaPhi0p15"
# skim = "skimmed_lblSelections_final_photonMatchingdeltaPhi0p15_test"
# skim = "skimmed_lblSelections_final_photonMatchingdeltaPhi0p15_test_tightCuts"
# skim = "skimmed_lblSelections_final_photonMatchingdeltaPhi0p15_test_noTimingCut"
skim = "skimmed_lblSelections_final_photonMatchingdeltaPhi0p15_testNewNtuples"

# input_skim = "skimmed_lblSelections_final_photonMatchingdeltaPhi0p15"
# skim = "skimmed_lblSelections_final_photonMatchingdeltaPhi0p15_withAco"

# skim = "initial"
# skim = "skimmed_lblSelections_final_HF3p139"
# skim = "allSelections_exceptHFnee"

# skim = "afterTrigger"

# skim = "skimmed_1gammaSelections"
# skim = "skimmed_3gammaSelections"
# skim = "skimmed_3gammaSelections_merged"

# skim = "skimmed_lblSelections_photonIDtests"
# skim = "skimmed_lblSelections_photonIDtests_10percentRelaxAll"
# skim = "skimmed_lblSelections_photonIDtests_50percentRelaxAll"

# this is the final final skim with updated NEE thresholds, SFs, and ranges:
# skim = "skimmed_lblSelections_final_newNEE"
# skim = "skimmed_lblSelections_final_newNEE_oldThresholds"
# skim = "skimmed_lblSelections_final_newNEE_oldEtaRange"
# skim = "skimmed_lblSelections_final_oldReproduce"
# skim = "skimmed_lblSelections_final_oldReproduce_noEGammaOverlapInHF_fixed"
# skim = "skimmed_lblSelections_final_reproduce"

# skim = "skimmed_lblSelections_final_photonMatchingdeltaPhi0p15_0n0n"
# skim = "skimmed_lblSelections_final_photonMatchingdeltaPhi0p15_0n0n_1n0n_1n1n"
# skim = "skimmed_lblSelections_final_photonMatchingdeltaPhi0p15_noNEE"
# skim = "skimmed_lblSelections_final_photonMatchingdeltaPhi0p15_noCHE"
# skim = "skimmed_lblSelections_final_photonMatchingdeltaPhi0p15_ptgaga2p5"

# skim = "skimmed_lblSelections_final_twoPhotons"
# skim = "skimmed_lblSelections_final_twoPhotons_CHE"
# skim = "skimmed_lblSelections_final_twoPhotons_CHE_NEE"
# skim = "skimmed_lblSelections_final_twoPhotons_CHE_NEE_diphotonPt"
# skim = "skimmed_lblSelections_final_twoPhotons_CHE_NEE_diphotonPt_ZDC"

# skim = "skimmed_lblSelections_finalXn0n"
# skim = "skimmed_lblSelections_finalXn1n"
# skim = "skimmed_lblSelections_final_2n2n"
# skim = "skimmed_lblSelections_final_photonMatchingdeltaPhi0p15_noZDC"
# skim = "skimmed_lblSelections_final"
# skim = "skimmed_lblSelections_final_andZDC"
# skim = "skimmed_lblSelections_final_andZDC3n"
# skim = "skimmed_lblSelections_final_andZDC2n"
# skim = "skimmed_lblSelections_final_andZDC1n"
# skim = "skimmed_lblSelections_final_noZDC"
# skim = "skimmed_lblSelections_onlyNee"

# skim = "skimmed_qedSelections"
# skim = "skimmed_qedSelections_noHoverEcut"
# skim = "skimmed_qedSelections_noPtCut"
# skim = "skimmed_qedSelections_noZDC"

# skim = "skimmed_qedSelections_sameSign"
# skim = "skimmed_qedSelections_sameSign_noPtCut"

# skim = "skimmed_tracksPhotonsSelections"
# skim = "skimmed_tracksPhotonsSelectionsWithDiphotonPt"
# skim = "skimmed_tracksPhotonsSelectionsWithDiphotonPtNoNEE"

acoplanarity_histogram_name = "diphoton_acoplanarity{}"
# mass_histogram_name = "diphoton_mass{}"
mass_histogram_name = "diphotonSR_mass{}"

facility = get_facility()

if facility == "naf":
    base_path = "/data/dust/user/jniedzie/light_by_light/ntuples"
elif facility == "lxplus":
    # base_path = "/eos/cms/store/cmst3/group/lightbylight/tea_samples"
    base_path = "/eos/cms/store/cmst3/group/lightbylight/new_tea_samples"

merged_histograms_path = base_path + "/{}/merged_{}_histograms.root"
