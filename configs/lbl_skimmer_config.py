## specify how many events to run on (and how often to print current event number)
nEvents = 10
printEveryNevents = 1

# inputFilePath = "/eos/cms/store/cmst3/group/lightbylight/Pranati/Final_afterTrigger/Data/Data_29thJune/merged/merged_ntuples_2.root"
inputFilePath = "./test_renamed.root"
treeOutputFilePath = "./test_skimmed.root"

weightsBranchName = "genWeight"
eventsTreeNames = [
    "Events",
]

# define extra collections:
# - give it a name: e.g. GoodLeptons
# - specify inputCollections: only those will be looped over to create your new collection
# - add some requirements on values: e.g. if input collections have fields called pt, i.e. Muon_pt and Electron_pt, 
# you can specify a range for this parameter
extraEventCollections = {
    # EM calo towers
    # "PassingEBtower":       {"inputCollections": ("CaloTower",), "eta": (-1.4442 , 1.4442), "et": (0.7, 9999999.)},
    # "PassingEEtowerPlus":   {"inputCollections": ("CaloTower",), "eta": (1.566   , 2.6   ), "et": (3.0, 9999999.)},
    # "PassingEEtowerMinus":  {"inputCollections": ("CaloTower",), "eta": (-2.6    , 1.566 ), "et": (3.0, 9999999.)},
    
    # # Had calo towers
    # "PassingHBtower":       {"inputCollections": ("CaloTower",), "eta": (-1.305  , 1.305 ), "et": (2.8, 9999999.)},
    # "PassingHEtowerPlus":   {"inputCollections": ("CaloTower",), "eta": (1.41    , 3.0   ), "et": (1.0, 9999999.)},
    # "PassingHEtowerMinus":  {"inputCollections": ("CaloTower",), "eta": (-3.0    , 1.41  ), "et": (1.0, 9999999.)},
    
    # # Forward calo towers
    # "PassingHFtowerPlus":   {"inputCollections": ("CaloTower",), "eta": (3.15    , 5.2   ), "et": (6.0, 9999999.)},
    # "PassingHFtowerMinus":  {"inputCollections": ("CaloTower",), "eta": (-5.2    , 3.15  ), "et": (6.0, 9999999.)},
    
    # "PassingTower":  {"inputCollections": (
    #     "PassingEBtower", 
    #     "PassingEEtowerPlus", 
    #     "PassingEEtowerMinus",
    #     "PassingHBtower",
    #     "PassingHEtowerPlus",
    #     "PassingHEtowerMinus",
    #     "PassingHFtowerPlus",
    #     "PassingHFtowerMinus",)
    # },
    
    "PassingZDCcounts":  {"inputCollections": ("ZDC",), "energy": (10.0, 9999999.)},
    
    "GoodBarrelPhotons": {
        "inputCollections": ("photon",), 
        "et": (2.0, 9999999.), 
        "eta": (-2.2, 2.2),
    },
    
    # photonMinEt: 2.0 
    # photonMaxEta: 2.2 
    # photonMaxHoverEbarrel: 0.04596 
    # photonMaxHoverEendcap: 0.0590 
    # photonMaxEtaWidthBarrel: 0.0106 
    # photonMaxEtaWidthEndcap: 0.0272  
    # photonMinSwissCross: 999
    # photonMaxSwissCross: 0.95
    # diphotonMaxPt: 1.0 
    # diphotonMaxRapidity: 9999999 
    # diphotonMinMass: 5.0 
    # diphotonMaxAco: 0.01 
    # photonRejectConverted: 1
    
}

# define simple event-level selections
eventSelections = {
    # "nPassingTower": (0, 0),
    "nPassingZDCcounts": (0, 0),
}

specialBranchSizes = {
    "Particle": "Event_numberP",
    "e": "n",
    "channel": "n",
    "saturation": "n",
    "section": "n",
    "zside": "n",
}

branchesToKeep = ["*"]
branchesToRemove = []