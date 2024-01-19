from lbl_extra_collections import extraEventCollections

nEvents = -1
printEveryNevents = 1000

base_path = "/nfs/dust/cms/user/jniedzie/light_by_light/"

applyTwoPhotons = True
applyChargedExclusivity = True
applyNeutralExclusivity = True
applyDiphotonPt = True
applyZDC = True

# sample = "collisionData"
# sample = "lbl"
# sample = "cep"
sample = "qed"

# skim = "skimmed_twoPhotons"
# skim = "skimmed_neutralExclusivity"
skim = "skimmed_allSelections"

inputFilePath = f"{base_path}/ntuples/{sample}/initial/ntuple_0.root"
# treeOutputFilePath = inputFilePath.replace("initial", skim)
treeOutputFilePath = "./skimmed.root"

# weightsBranchName = "genWeight"
eventsTreeNames = ["Events",]

# define simple event-level selections
eventSelections = {}

specialBranchSizes = {
    "Particle": "Event_numberP",
}

branchesToKeep = ["*"]
branchesToRemove = []
