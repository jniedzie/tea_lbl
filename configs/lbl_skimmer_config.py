from lbl_params import *

nEvents = -1
printEveryNevents = 1000

base_path = "/nfs/dust/cms/user/jniedzie/light_by_light/"

# for LbL analysis:
applyTwoPhotons = False
applyDiphotonPt = False
applyChargedExclusivity = False

# for QED analysis:
applyTwoElectrons = True

# for both analyses:
applyNeutralExclusivity = True
applyZDC = True

# sample = "collisionData"
sample = "lbl"
# sample = "cep"
# sample = "qed"

# skim = "skimmed_allSelections"
skim = "skimmed_qedSelections"

inputFilePath = f"{base_path}/ntuples/{sample}/initial/ntuple_0.root"
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
