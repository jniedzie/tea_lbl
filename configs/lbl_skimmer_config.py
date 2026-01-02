from lbl_params import *

nEvents = -1
printEveryNevents = 1000

base_initial_path = "/data/dust/user/jniedzie/light_by_light/"
base_path = "/data/dust/user/jniedzie/monophoton/"

applyTrigger = False

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

input_skim = "initial"
output_skim = "skimmed"

inputFilePath = f"{base_initial_path}/ntuples/{sample}/initial/ntuple_0.root"
# inputFilePath = f"{base_path}/ntuples/{sample}/merged_{input_skim}.root"

# treeOutputFilePath = inputFilePath.replace("initial", skim)
treeOutputFilePath = f"{base_path}/ntuples/{sample}/merged_{output_skim}.root"

# weightsBranchName = "genWeight"
eventsTreeNames = ["Events",]

# define simple event-level selections
eventSelections = {}

specialBranchSizes = {}
branchesToKeep = ["*"]
branchesToRemove = []
