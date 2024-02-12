from scale_factors_config import *
from lbl_params import *
import ROOT

nEvents = -1
printEveryNevents = 1000

base_path = "/nfs/dust/cms/user/jniedzie/light_by_light/"

sample = "collisionData"
# sample = "lbl"
# sample = "cep"
# sample = "qed"

# skim = "initial"
skim = "skimmed_allSelections"
# skim = "skimmed_qedSelections"

# inputFilePath = f"{base_path}/ntuples/{sample}/{skim}/ntuple_0.root"
inputFilePath = f"{base_path}/ntuples/{sample}/merged_{skim}.root"
histogramsOutputFilePath = "./histograms_data.root"

defaultHistParams = (
    # collection      variable          bins    xmin     xmax     dir
    ("goodPhoton", "et", 100,    0,       200,     ""),
    ("goodPhoton", "eta", 100,    -2.5,    2.5,     ""),
    ("goodPhoton", "phi", 100,    -2.5,    2.5,     ""),
    ("goodPhoton", "seedTime", 100,    -5,    5,     ""),
    ("electron", "PFChIso", 1000,    0,    10,     ""),
    ("electron", "PFPhoIso", 1000,    0,    10,     ""),
    ("electron", "PFNeuIso", 1000,    0,    10,     ""),
    # ("Event"       , "nGoodLeptons"  , 50,     0,       50,      ""  ),
)

histParams = (
    ("diphoton", "pt", 100, 0, 100, ""),
    ("diphoton", "mass200", 200, 0, 200, ""),
    ("diphoton", "mass100", 100, 0, 200, ""),
    ("diphoton", "acoplanarity200", 200, 0, 1, ""),
    ("diphoton", "acoplanarity300", 300, 0, 1, ""),
    ("diphoton", "acoplanarity400", 400, 0, 1, ""),
    ("diphoton", "acoplanarity500", 500, 0, 1, ""),
    ("diphoton", "acoplanarity600", 600, 0, 1, ""),

    ("dielectron", "pt", 100, 0, 1, ""),
    ("dielectron", "mass", 200, 0, 200, ""),
    ("dielectron", "acoplanarity", 1000, 0, 1, ""),
    
    ("event", "deltaEt", 100, 0, 1, ""),
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
