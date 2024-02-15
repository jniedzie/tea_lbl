from lbl_params import *

nEvents = -1
printEveryNevents = 1000

base_path = "/nfs/dust/cms/user/jniedzie/light_by_light/"

# for LbL analysis:
applyTwoPhotons = True
applyDiphotonPt = True
applyChargedExclusivity = True

# for QED analysis:
applyTwoElectrons = False

# for both analyses:
applyNeutralExclusivity = True
applyZDC = True

# for final cleanup only
applyEtDelta = False


# sample = "collisionData"
sample = "lbl"
# sample = "cep"
# sample = "qed"

# skim = "skimmed_allSelections"
skim = "skimmed_qedSelections"

inputFilePath = f"{base_path}/ntuples/{sample}/initial/ntuple_0.root"
# inputFilePath = f"{base_path}/ntuples/{sample}/skimmed_allSelections/ntuple_0.root"
# inputFilePath = "./renamed_test.root"
# treeOutputFilePath = inputFilePath.replace("initial", skim)
treeOutputFilePath = "./skimmed_test.root"

# weightsBranchName = "genWeight"
eventsTreeNames = ["Events",]

# define simple event-level selections
eventSelections = {}

specialBranchSizes = {}
branchesToKeep = ["*"]
branchesToRemove = []
