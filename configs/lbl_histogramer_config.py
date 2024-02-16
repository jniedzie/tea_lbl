from scale_factors_config import *
from lbl_params import *
import ROOT

nEvents = -1
printEveryNevents = 1000

base_path = "/nfs/dust/cms/user/jniedzie/light_by_light/"

# sample = "collisionData"
# sample = "lbl"
# sample = "cep"
sample = "qed"
# sample = "emptyBeams"

# skim = "initial"
# skim = "skimmed_allSelections_photonEt2p0"
# skim = "skimmed_allSelections"
skim = "skimmed_qedSelections"
# skim = "skimmed_allSelections_hadCrack"

# inputFilePath = f"{base_path}/ntuples/{sample}/{skim}/ntuple_0.root"
inputFilePath = f"{base_path}/ntuples/{sample}/merged_{skim}.root"
# inputFilePath = "./renamed_test.root"
# inputFilePath = "./skimmed_test.root"
print(f"{inputFilePath=}")

histogramsOutputFilePath = f"./{skim}_{sample}_histograms.root"

defaultHistParams = (
    # collection      variable          bins    xmin     xmax     dir
    ("goodPhoton", "et" , 200,    0,       100,     ""),
    ("goodPhoton", "eta", 12,    -2.2,    2.2,     ""),
    ("goodPhoton", "phi", 12,    -3.14,    3.14,     ""),
    ("goodPhoton", "seedTime", 100,    -5,    5,     ""),
    ("electron", "PFChIso", 1000,    0,    10,     ""),
    ("electron", "PFPhoIso", 1000,    0,    10,     ""),
    ("electron", "PFNeuIso", 1000,    0,    10,     ""),
    # ("Event"       , "nGoodLeptons"  , 50,     0,       50,      ""  ),
    
    ("goodElectron", "pt" , 200,    0,       100,     ""),
    ("goodElectron", "eta", 20,    -2.2,    2.2,     ""),
    ("goodElectron", "phi", 20,    -3.14,    3.14,     ""),
)

histParams = (
    ("diphoton", "pt", 5, 0, 1, ""),
    ("diphoton", "rapidity", 12, -2.2, 2.2, ""),
    ("diphoton", "mass", 10, 0, 50, ""),
    ("diphoton", "mass200", 200, 0, 200, ""),
    ("diphoton", "mass100", 100, 0, 200, ""),
    ("diphoton", "acoplanarity200", 200, 0, 1, ""),
    ("diphoton", "acoplanarity300", 300, 0, 1, ""),
    ("diphoton", "acoplanarity400", 400, 0, 1, ""),
    ("diphoton", "acoplanarity500", 500, 0, 1, ""),
    ("diphoton", "acoplanarity600", 600, 0, 1, ""),

    ("dielectron", "pt", 100, 0, 1, ""),
    ("dielectron", "mass", 200, 0, 200, ""),
    ("dielectron", "rapidity", 100, -2.2, 2.2, ""),
    ("dielectron", "acoplanarity", 1000, 0, 1, ""),
    ("dielectron", "deltaPhi", 20, 0, 3.1415, ""),
    
    ("event", "deltaEt", 100, 0, 1, ""),
    
    ("unfoldingPhoton", "pt", 5, 0, 1, ""),
    ("unfoldingPhoton", "mass", 5, 5, 25, ""),
    ("unfoldingPhoton", "absRap", 2, 0, 2.2, ""),
    
    ("caloTowerHE", "energyHad", 100, 0, 5, ""),
    ("caloTowerHE", "energyTransverse", 100, 0, 5, ""),
    ("caloTowerHE", "energy", 100, 0, 5, ""),
    
    ("goodCaloTowerHE", "energyHad", 100, 0, 5, ""),
    ("goodCaloTowerHE", "energyTransverse", 100, 0, 5, ""),
    ("goodCaloTowerHE", "energy", 100, 0, 5, ""),
    
    ("genPhoton", "et" , 200,    0,       10,     ""),
    ("genPhoton", "energy" , 200,    0,       10,     ""),
    
    ("leadingGenPhoton", "energy" , 200,    0,       10,     ""),
    ("leadingGenPhotonBarrel", "energy" , 200,    0,       10,     ""),
    ("leadingGenPhotonBarrelEndcap", "energy" , 200,    0,       10,     ""),
    
)

histParams2D = (
    ("diphoton_seedTime", 100, -10, 10, 100, -10, 10, ""),
    ("diphoton_seedTimeSR", 100, -10, 10, 100, -10, 10, ""),
)

eventsTreeNames = ["Events",]
specialBranchSizes = {}

visualizationParams = {
    "normalizeMomenta": True,
    "maxTowerHeight": 6.0,
    "normalizeRotation": True,
    "circleRadius": 1.0,
    "circleColor": ROOT.kBlack,
    "towerInnerWidth": 0.08,
    "towerOuterWidthScale": 0.1,
    "towerColor": -1,
    # "towerColorR": 0.45,
    # "towerColorG": 0.97,
    # "towerColorB": 0.35,
    "towerColorR": 0.72,
    "towerColorG": 0.21,
    "towerColorB": 0.31,
    "towerAlpha": 0.5,
    "towerFillStyle": 1001,
    "backgroundColor": ROOT.kWhite,
    "canvasSize": 8.0,
}
