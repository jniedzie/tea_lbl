from lbl_params import *

nEvents = -1
printEveryNevents = 1000

base_path = "/data/dust/user/jniedzie/light_by_light/"

# for LbL analysis:
applyTrigger = False
applyTwoTracksTwoPhotons = False
applyTwoPhotons = True
applySinglePhoton = False
applyThreePhotons = False
applyTwoElectrons = False
sameChargeElectrons = False
applyZeroPhotonElectron = False
applyChargedExclusivity = True
applyNeutralExclusivity = True
applyDiphotonPt = False
applyZDC = True
applyEtDelta = False
applyAcoplanarity = True

# for QED analysis:
# applyTrigger = False
# applyTwoTracksTwoPhotons = False
# applySinglePhoton = False
# applyThreePhotons = False
# applyZeroPhotonElectron = False
# applyTwoPhotons = False
# applyTwoElectrons = True
# sameChargeElectrons = True
# applyDiphotonPt = False
# applyChargedExclusivity = False
# applyNeutralExclusivity = True
# applyZDC = True
# applyEtDelta = False

# for 2 tracks + 2 photons analysis:
# applyTwoTracksTwoPhotons = True
# applyTwoPhotons = False
# applyTwoElectrons = False
# applyDiphotonPt = True
# applyChargedExclusivity = False
# applyNeutralExclusivity = False
# applyZDC = True
# applyEtDelta = False


# sample = "collisionData"
# sample = "lbl"
# sample = "cep"
# sample = "qed"
# sample = "qed_starlight"

# sample = "alps_5"
# sample = "alps_6"
# sample = "alps_9"
sample = "alps_11"
# sample = "alps_14"
# sample = "alps_16"
# sample = "alps_22"
# sample = "alps_30"
# sample = "alps_50"
# sample = "alps_90"

# skim = "skimmed_lblSelections"
# skim = "skimmed_qedSelections"
# input_skim = "initial"
input_skim = "skimmed_lblSelections_final_photonMatchingdeltaPhi0p15"
output_skim = "skimmed_lblSelections_final_photonMatchingdeltaPhi0p15_moreCuts"

inputFilePath = f"{base_path}/ntuples/{sample}/initial/ntuple_0.root"
# inputFilePath = f"{base_path}/ntuples/{sample}/merged_{input_skim}.root"
# inputFilePath = f"{base_path}/ntuples/{sample}/skimmed_allSelections/ntuple_0.root"
# inputFilePath = "./renamed_test.root"

# treeOutputFilePath = inputFilePath.replace("initial", skim)
treeOutputFilePath = f"{base_path}/ntuples/{sample}/merged_{output_skim}.root"
# treeOutputFilePath = "../skimmed_test.root"

# weightsBranchName = "genWeight"
eventsTreeNames = ["Events",]

# define simple event-level selections
eventSelections = {}

specialBranchSizes = {}
branchesToKeep = ["*"]
branchesToRemove = []
