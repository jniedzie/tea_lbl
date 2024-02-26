from scale_factors_config import *
from lbl_params import *
import ROOT

nEvents = -1
printEveryNevents = 1000

base_path = "/nfs/dust/cms/user/jniedzie/light_by_light/"

# sample = "collisionData"
sample = "lbl"
# sample = "cep"
# sample = "qed"
# sample = "emptyBeams"

skim = "initial"
# skim = "skimmed_allSelections_photonEt2p0"
# skim = "skimmed_allSelections"
# skim = "skimmed_qedSelections"
# skim = "skimmed_allSelections_hadCrack"
# skim = "skimmed_lblSelections_final"

# inputFilePath = f"{base_path}/ntuples/{sample}/{skim}/ntuple_0.root"
inputFilePath = f"{base_path}/ntuples/{sample}/merged_{skim}.root"
# inputFilePath = "./renamed_test.root"
# inputFilePath = "./skimmed_test.root"
print(f"{inputFilePath=}")

histogramsOutputFilePath = f"../{skim}_{sample}_histograms.root"

defaultHistParams = (
    # collection      variable          bins    xmin     xmax     dir
    ("goodPhoton", "et", 200,    0,       100,     ""),
    ("goodPhoton", "eta", 12,    -2.2,    2.2,     ""),
    ("goodPhoton", "phi", 12,    -3.14,    3.14,     ""),
    ("goodPhoton", "seedTime", 100,    -5,    5,     ""),

    ("goodElectron", "pt", 200,    0,       100,     ""),
    ("goodElectron", "eta", 20,    -2.2,    2.2,     ""),
    ("goodElectron", "phi", 20,    -3.14,    3.14,     ""),
    ("electron", "PFChIso", 1000,    0,    10,     ""),
    ("electron", "PFPhoIso", 1000,    0,    10,     ""),
    ("electron", "PFNeuIso", 1000,    0,    10,     ""),

    ("convertedPhoton", "et", 200,    0,       100,     ""),
    ("convertedPhoton", "eta", 100,    -2.2,    2.2,     ""),
    ("convertedPhoton", "phi", 100,    -3.14,    3.14,     ""),

    ("unconvertedPhoton", "et", 200,    0,       100,     ""),
    ("unconvertedPhoton", "eta", 100,    -2.2,    2.2,     ""),
    ("unconvertedPhoton", "phi", 100,    -3.14,    3.14,     ""),

    ("conversionElectron", "pt", 200,    0,       50,     ""),
    ("conversionElectron", "eta", 100,    -2.2,    2.2,     ""),
    ("conversionElectron", "phi", 100,    -3.14,    3.14,     ""),
    ("conversionElectron", "nMissHits", 20,    0,    20,     ""),
    ("conversionElectron", "hOverE", 100,    0,    0.5,     ""),
    ("conversionElectron", "deltaEtaAtVertex", 100,    0,    0.5,     ""),
    
    ("unconversionElectron", "pt", 200,    0,       50,     ""),
    ("unconversionElectron", "eta", 100,    -2.2,    2.2,     ""),
    ("unconversionElectron", "phi", 100,    -3.14,    3.14,     ""),
    ("unconversionElectron", "nMissHits", 20,    0,    20,     ""),
    ("unconversionElectron", "hOverE", 100,    0,    0.5,     ""),
    ("unconversionElectron", "deltaEtaAtVertex", 100,    0,    0.5,     ""),

)

histParams = (
    # photons
    ("unfoldingPhoton", "pt", 5, 0, 1, ""),
    ("unfoldingPhoton", "mass", 5, 5, 25, ""),
    ("unfoldingPhoton", "absRap", 2, 0, 2.2, ""),
    ("unfoldingPhoton", "rap3", 3, -2.2, 2.2, ""),
    ("unfoldingPhoton", "rap4", 4, -2.2, 2.2, ""),

    ("goodPhotonSR", "et", 200,    0,       100,     ""),
    ("goodPhotonSR", "eta", 12,    -2.2,    2.2,     ""),
    ("goodPhotonSR", "phi", 12,    -3.14,    3.14,     ""),

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

    ("diphotonSR", "pt", 5, 0, 1, ""),
    ("diphotonSR", "rapidity", 12, -2.2, 2.2, ""),
    ("diphotonSR", "mass", 10, 0, 50, ""),
    ("diphotonSR", "mass200", 200, 0, 200, ""),
    ("diphotonSR", "mass100", 100, 0, 200, ""),

    # electrons
    ("goodElectronSR", "pt", 200,    0,       100,     ""),
    ("goodElectronSR", "eta", 20,    -2.2,    2.2,     ""),
    ("goodElectronSR", "phi", 20,    -3.14,    3.14,     ""),

    ("dielectron", "acoplanarity", 1000, 0, 1, ""),
    ("dielectron", "pt", 100, 0, 1, ""),
    ("dielectron", "mass", 200, 0, 200, ""),
    ("dielectron", "rapidity", 100, -2.2, 2.2, ""),
    ("dielectron", "deltaPhi", 100, 0, ROOT.TMath.Pi(), ""),

    ("dielectronSR", "pt", 100, 0, 1, ""),
    ("dielectronSR", "mass", 200, 0, 200, ""),
    ("dielectronSR", "rapidity", 100, -2.2, 2.2, ""),
    ("dielectronSR", "deltaPhi", 100, 0, ROOT.TMath.Pi(), ""),

    ("genDielectron", "deltaPhi", 100, 0, ROOT.TMath.Pi(), ""),

    # calo
    ("caloTowerHE", "energyHad", 100, 0, 5, ""),
    ("caloTowerHE", "energyTransverse", 100, 0, 5, ""),
    ("caloTowerHE", "energy", 100, 0, 5, ""),
    ("goodCaloTowerHE", "energyHad", 100, 0, 5, ""),
    ("goodCaloTowerHE", "energyTransverse", 100, 0, 5, ""),
    ("goodCaloTowerHE", "energy", 100, 0, 5, ""),

    # gen-level
    ("genPhoton", "et", 200,    0,       10,     ""),
    ("genPhoton", "energy", 200,    0,       10,     ""),

    ("leadingGenPhoton", "energy", 200,    0,       10,     ""),
    ("leadingGenPhotonBarrel", "energy", 200,    0,       10,     ""),
    ("leadingGenPhotonBarrelEndcap", "energy", 200,    0,       10,     ""),

    # event
    ("event", "deltaEt", 100, 0, 1, ""),
    ("event", "cosThetaStar", 10, 0, 1, ""),
    ("eventSR10", "cosThetaStar", 10, 0, 1, ""),
    ("eventSR5", "cosThetaStar", 5, 0, 1, ""),
    ("eventSR4", "cosThetaStar", 4, 0, 1, ""),
    ("eventSR3", "cosThetaStar", 3, 0, 1, ""),
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

extraEventCollections = {
    "convertedPhoton": {
        "inputCollections": ("photon",),
        "hasConversionTracks": True,
    },
    "unconvertedPhoton": {
        "inputCollections": ("photon",),
        "hasConversionTracks": False,
    },
    "conversionElectron": {
        "inputCollections": ("electron",),
        "conversionVeto": False,
    },
    "unconversionElectron": {
        "inputCollections": ("electron",),
        "conversionVeto": True,
    },
}
