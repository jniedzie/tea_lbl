## specify how many events to run on (and how often to print current event number)
nEvents = 1000
printEveryNevents = 100

# inputFilePath = "/eos/cms/store/cmst3/group/lightbylight/Pranati/Final_afterTrigger/Data/Data_29thJune/merged/merged_ntuples_2.root"
inputFilePath = "./test_renamed.root"
treeOutputFilePath = "./test_skimmed.root"

weightsBranchName = "genWeight"
eventsTreeNames = [
    "Events",
]

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