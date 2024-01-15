## specify how many events to run on (and how often to print current event number)
nEvents = 100
printEveryNevents = 10

inputFilePath = "/eos/cms/store/cmst3/group/lightbylight/Pranati/HIForest_LbyL_Signal_MC/LbyLSignal_5p02TeV_SuperChic/reco_mc_lbl_try2/230821_061454/0000/HiForest_SC_LbL_Merged.root"
treeOutputFilePath = "./test_skimmed.root"

weightsBranchName = "genWeight"
eventsTreeName = "ggHiNtuplizer/EventTree"

# define extra collections:
# - give it a name: e.g. GoodLeptons
# - specify inputCollections: only those will be looped over to create your new collection
# - add some requirements on values: e.g. if input collections have fields called pt, i.e. Muon_pt and Electron_pt, 
# you can specify a range for this parameter
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
    
    "PassingTower":  {"inputCollections": (
        "PassingEBtower", 
        "PassingEEtowerPlus", 
        "PassingEEtowerMinus",
        "PassingHBtower",
        "PassingHEtowerPlus",
        "PassingHEtowerMinus",
        "PassingHFtowerPlus",
        "PassingHFtowerMinus",)
    },
}

# define simple event-level selections
eventSelections = {
    "nPassingEBtower": (1, 9999999),
    "nPassingTower": (0, 0),
}

specialBranchSizes = {
    "Particle": "Event_numberP",
}

branchesToKeep = ["*"]
branchesToRemove = []