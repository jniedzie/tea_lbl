nEvents = -1
printEveryNevents = 1000

base_path = "/nfs/dust/cms/user/jniedzie/light_by_light/"

applyTwoPhotons = True
applyChargedExclusivity = True
applyNeutralExclusivity = True
applyZDC = False

sample = "collisionData"
# sample = "lbl"
# sample = "cep"
# sample = "qed"

skim = "skimmed_twoPhotons"
# skim = "skimmed_neutralExclusivity"

inputFilePath = f"{base_path}/ntuples/{sample}/initial/ntuple_0.root"
treeOutputFilePath = inputFilePath.replace("initial", skim)

# weightsBranchName = "genWeight"
eventsTreeNames = ["Events",]

extraEventCollections = {
    # EM calo towers
    "PassingEBtower":       {"inputCollections": ("CaloTower",), "eta": (-1.4442 , 1.4442), "et": (0.7, 9999999.)},
    "PassingEEtowerPlus":   {"inputCollections": ("CaloTower",), "eta": (1.566   , 2.6   ), "et": (3.0, 9999999.)},
    "PassingEEtowerMinus":  {"inputCollections": ("CaloTower",), "eta": (-2.6    , 1.566 ), "et": (3.0, 9999999.)},

    # Had calo towers
    "PassingHBtower":       {"inputCollections": ("CaloTower",), "eta": (-1.305  , 1.305 ), "et": (2.8, 9999999.)},
    "PassingHEtowerPlus":   {"inputCollections": ("CaloTower",), "eta": (1.41    , 3.0   ), "et": (1.0, 9999999.)},
    "PassingHEtowerMinus":  {"inputCollections": ("CaloTower",), "eta": (-3.0    , 1.41  ), "et": (1.0, 9999999.)},

    # Forward calo towers
    "PassingHFtowerPlus":   {"inputCollections": ("CaloTower",), "eta": (3.15    , 5.2   ), "et": (6.0, 9999999.)},
    "PassingHFtowerMinus":  {"inputCollections": ("CaloTower",), "eta": (-5.2    , 3.15  ), "et": (6.0, 9999999.)},

    "PassingZDCcounts":  {"inputCollections": ("ZDC",), "energy": (10.0, 9999999.)},
}

# define simple event-level selections
eventSelections = {}

specialBranchSizes = {
    "Particle": "Event_numberP",
}

branchesToKeep = ["*"]
branchesToRemove = []
