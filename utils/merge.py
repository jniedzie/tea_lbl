import os

base_path = "/nfs/dust/cms/user/jniedzie/light_by_light/ntuples/"

# skim = "initial"
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
# skim = "skimmed_allSelections_EE3p5"
# skim = "skimmed_allSelections_EE4p0"
# skim = "skimmed_allSelections_EE3p3"
# skim = "skimmed_allSelections_EE3p7"
# skim = "skimmed_allSelections_hadronCrack"
# skim = "skimmed_allSelections_emCrack"
# skim = "skimmed_allSelections_HFedge3p0"
# skim = "skimmed_allSelections_diphotonMass4p5"
# skim = "skimmed_allSelections_eleIso5p0"
# skim = "skimmed_allSelections_eleIso2p0"
# skim = "skimmed_allSelections_eleIso0p01"
# skim = "skimmed_allSelections_caloEta2p2"
# skim = "skimmed_allSelections_EE7p5"
# skim = "skimmed_allSelections_swissCross99_EE3p5_EEeta2p2"
# skim = "skimmed_allSelections_swissCross99_EE3p5"
# skim = "skimmed_allSelections_EE3p5_EEeta2p2"
# skim = "skimmed_allSelections_EE3p4"
# skim = "skimmed_allSelections_EE3p6"
# skim = "skimmed_allSelections_EE3p5_trackPt0p4"
# skim = "skimmed_allSelections_EE3p5_1track"
# skim = "skimmed_allSelections_EE3p5_deadHEfix"
# skim = "skimmed_allSelections_deltaEtaEE0p8"
skim = "skimmed_allSelections_EE3p5_deltaEtaEE0p25"

# hist_path = ""
hist_path = "histograms"

sample_paths = (
    "collisionData",
    "lbl",
    "cep",
    "qed",
)


def main():
    for sample_path in sample_paths:
        input_path = f"{base_path}/{sample_path}/{skim}/{hist_path}/*.root"
        output_path = f"{base_path}/{sample_path}/merged_{skim}{hist_path}.root"

        print(f"{sample_path=}")
        print(f"{output_path=}")

        os.system(f"rm {output_path}")
        os.system(f"hadd -f -j -k {output_path} {input_path}")


if __name__ == "__main__":
    main()
