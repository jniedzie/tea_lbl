from scale_factors_config import *
from lbl_params import *
import numpy as np
from numpy import pi

nEvents = -1
eventsOffset = 0
printEveryNevents = 1000

base_path = "/data/dust/user/jniedzie/light_by_light/"

sample = "collisionData"
# sample = "lbl"
# sample = "cep"
# sample = "qed"
# sample = "qed_MG_ee_a"
# sample = "emptyBeams"
# sample = "qed_sc_noPhotos"

# skim = "initial"
# skim = "afterTrigger"
# skim = "skimmed_lblSelections_final"
# skim = "skimmed_lblSelections_final_andZDC3n"
skim = "skimmed_lblSelections_final_photonMatchingdeltaPhi0p15"
# skim = "skimmed_lblSelections_final_twoPhotons"
# skim = "skimmed_qedSelections"
# skim = "skimmed_tracksPhotonsSelections"
# skim = "skimmed_lblSelections_final_photonMatchingdeltaPhi0p15_withAco"

# inputFilePath = "./renamed_test.root"
# inputFilePath = "./skimmed_test.root"
# inputFilePath = f"{base_path}/ntuples/{sample}/{skim}/ntuple_0.root"
inputFilePath = f"{base_path}/ntuples/{sample}/merged_{skim}.root"

histogramsOutputFilePath = f"../{skim}_{sample}_histograms.root"

defaultHistParams = (
  # collection      variable          bins    xmin     xmax     dir
  ("goodPhoton", "SCEnergy", 1000, 0, 1000, ""),
  ("goodPhoton", "SCEt", 1000, 0, 1000, ""),
  ("goodPhoton", "SCEta", 100, -5, 5, ""),
  ("goodPhoton", "SCEtaWidth", 100, 0, 0.1, ""),
  ("goodPhoton", "SCPhi", 100, -5, 5, ""),
  ("goodPhoton", "SCPhiWidth", 1000, 0, 0.2, ""),
  # ("goodPhoton", "ecalClusterIsoR2", 100, 0, 1, ""),
  # ("goodPhoton", "ecalClusterIsoR3", 100, 0, 1, ""),
  # ("goodPhoton", "ecalClusterIsoR4", 100, 0, 1, ""),
  # ("goodPhoton", "ecalClusterIsoR5", 100, 0, 1, ""),
  ("goodPhoton", "energy", 1000, 0, 1000, ""),
  ("goodPhoton", "energyBottom", 1000, 0, 1000, ""),
  ("goodPhoton", "energyLeft", 1000, 0, 1000, ""),
  ("goodPhoton", "energyRight", 1000, 0, 1000, ""),
  ("goodPhoton", "energyTop", 1000, 0, 1000, ""),
  # ("goodPhoton", "et", 1000, 0, 1000, ""),  # removing from here for blinding (custom filling)
  ("goodPhoton", "eta", 100, -5, 5, ""),
  ("goodPhoton", "hOverE", 1000, 0, 1.0, ""),
  ("goodPhoton", "hasConversionTracks", 2, 0, 1, ""),
  # ("goodPhoton", "hcalRechitIsoR1", 100, 0, 1, ""),
  # ("goodPhoton", "hcalRechitIsoR2", 100, 0, 1, ""),
  # ("goodPhoton", "hcalRechitIsoR3", 100, 0, 1, ""),
  # ("goodPhoton", "hcalRechitIsoR4", 100, 0, 1, ""),
  # ("goodPhoton", "hcalRechitIsoR5", 100, 0, 1, ""),
  ("goodPhoton", "maxEnergyCrystal", 1000, 0, 1000, ""),
  ("goodPhoton", "phi", 100, -5, 5, ""),
  # ("goodPhoton", "seedTime", 100, -5, 5, ""),  # removing from here for blinding (custom filling)
  ("goodPhoton", "sigmaEta2012", 100, 0, 0.1, ""),
  ("goodPhoton", "sigmaIEtaIEta2012", 100, 0, 0.1, ""),
  
  ("goodElectron", "pt", 200, 0, 100, ""),
  ("goodElectron", "eta", 20, -2.2, 2.2, ""),
  ("goodElectron", "phi", 20, -3.14, 3.14, ""),
  ("goodElectron", "charge", 10, -5, 5, ""),
  ("goodElectron", "nMissHits", 100, 0, 100, ""),
  ("goodElectron", "hOverE", 400, 0, 1, ""),
  ("goodElectron", "eOverP", 100, 0, 1, ""),
  ("goodElectron", "PFRelIsoWithEA", 100, 0, 100, ""),
  ("goodElectron", "deltaEtaAtVertex", 100, 0, 1, ""),
  ("goodElectron", "PFChIso", 100, 0, 1, ""),
  ("goodElectron", "PFPhoIso", 100, 0, 1, ""),
  ("goodElectron", "PFNeuIso", 100, 0, 1, ""),
  ("goodElectron", "conversionVeto", 10, 0, 10, ""),
  ("electron", "PFChIso", 1000, 0, 10, ""),
  ("electron", "PFPhoIso", 1000, 0, 10, ""),
  ("electron", "PFNeuIso", 1000, 0, 10, ""),
  ("convertedPhoton", "et", 200, 0, 100, ""),
  ("convertedPhoton", "eta", 100, -2.2, 2.2, ""),
  ("convertedPhoton", "phi", 100, -3.14, 3.14, ""),
  ("unconvertedPhoton", "et", 200, 0, 100, ""),
  ("unconvertedPhoton", "eta", 100, -2.2, 2.2, ""),
  ("unconvertedPhoton", "phi", 100, -3.14, 3.14, ""),
  ("conversionElectron", "pt", 200, 0, 50, ""),
  ("conversionElectron", "eta", 100, -2.2, 2.2, ""),
  ("conversionElectron", "phi", 100, -3.14, 3.14, ""),
  ("conversionElectron", "nMissHits", 20, 0, 20, ""),
  ("conversionElectron", "hOverE", 100, 0, 0.5, ""),
  ("conversionElectron", "deltaEtaAtVertex", 100, 0, 0.5, ""),
  ("unconversionElectron", "pt", 200, 0, 50, ""),
  ("unconversionElectron", "eta", 100, -2.2, 2.2, ""),
  ("unconversionElectron", "phi", 100, -3.14, 3.14, ""),
  ("unconversionElectron", "nMissHits", 20, 0, 20, ""),
  ("unconversionElectron", "hOverE", 100, 0, 0.5, ""),
  ("unconversionElectron", "deltaEtaAtVertex", 100, 0, 0.5, ""),
  ("Event", "runNumber", 1000, 320000, 335000, ""),
)

histParams = (
  # photons
  ("unfoldingPhoton", "pt", 5, 0, 1, ""),
  ("unfoldingPhoton", "mass", 5, 5, 25, ""),
  ("unfoldingPhoton", "absRap", 2, 0, 2.2, ""),
  ("unfoldingPhoton", "absRap3", 3, 0, 2.2, ""),
  ("unfoldingPhoton", "rap3", 3, -2.2, 2.2, ""),
  ("unfoldingPhoton", "rap4", 4, -2.2, 2.2, ""),
  ("unfoldingPhoton", "costhetastar2", 2, 0, 1, ""),
  ("unfoldingPhoton", "costhetastar3", 3, 0, 1, ""),
  ("unfoldingPhoton", "costhetastar4", 4, 0, 1, ""),
  ("goodPhotonSR", "et", 5, 2, 8, ""),
  ("goodPhotonSR", "eta", 5, -2.2, 2.2, ""),
  ("goodPhotonSR", "phi", 6, -3.14, 3.14, ""),
  ("diphoton", "pt", 5, 0, 1, ""),
  ("diphoton", "rapidity", 12, -2.2, 2.2, ""),
  ("diphoton", "mass", 10, 0, 50, ""),
  ("diphoton", "mass200", 200, 0, 200, ""),
  ("diphoton", "massNew", 100, 5, 205, ""),
  ("diphoton", "mass100", 100, 0, 200, ""),
  ("diphoton", "acoplanarity20", 20, 0, 0.1, ""),
  ("diphoton", "acoplanarity25", 25, 0, 0.1, ""),
  ("diphoton", "acoplanarity30", 30, 0, 0.1, ""),
  ("diphoton", "acoplanarity32", 32, 0, 0.1, ""),
  ("diphoton", "acoplanarity33", 33, 0, 0.1, ""),
  ("diphoton", "acoplanarity34", 34, 0, 0.1, ""),
  ("diphoton", "acoplanarity35", 35, 0, 0.1, ""),
  ("diphoton", "acoplanarity40", 40, 0, 0.1, ""),
  ("diphoton", "acoplanarity45", 45, 0, 0.1, ""),
  ("diphoton", "acoplanarity50", 50, 0, 0.1, ""),
  ("diphoton", "acoplanarity55", 55, 0, 0.1, ""),
  ("diphoton", "acoplanarity60", 60, 0, 0.1, ""),
  ("diphoton", "acoplanarity1040", 20, 0, 0.05, ""),
  ("diphotonThreePhoton", "mass", 10, 0, 50, ""),
  ("diphotonThreePhoton", "massClosestDeltaR", 100, 0, 50, ""),
  ("triphoton", "eta", 10, -5, 5, ""),
  ("triphoton", "mass", 5, 0, 50, ""),
  ("triphoton", "phi", 10, -5, 5, ""),
  ("triphoton", "pt", 25, 0, 50, ""),
  ("diphoton", "acoplanarityTrack0to0p3", 400, 0, 1.0, ""),
  ("diphoton", "acoplanarityTrack0p3to0p65", 400, 0, 1.0, ""),
  ("diphoton", "acoplanarityTrack0p65to2p0", 400, 0, 1.0, ""),
  ("diphoton", "acoplanarityTrack2p0toInf", 400, 0, 1.0, ""),
  ("diphotonSR", "pt", 5, 0, 1, ""),
  ("diphotonSR", "rapidity", 7, -2.2, 2.2, ""),
  ("diphotonSR", "mass", 10, 0, 50, ""),
  ("diphotonSR", "mass200", 200, 0, 200, ""),
  ("diphotonSR", "massNew", 100, 5, 205, ""),
  ("diphotonSR", "mass100", 100, 0, 200, ""),
  
  ("goodPhoton", "et", 2000, 0, 1000, ""),
  ("goodPhoton", "logEt", 200, -1, 3, ""),
  ("goodPhoton", "seedTime", 1000, -50, 50, ""),
  
  ("goodPhoton", "topOverCentral", 1000, 0, 10, ""),
  ("goodPhoton", "bottomOverCentral", 1000, 0, 10, ""),
  ("goodPhoton", "leftOverCentral", 1000, 0, 10, ""),
  ("goodPhoton", "rightOverCentral", 1000, 0, 10, ""),
  ("goodPhoton", "minOverCentral", 1000, 0, 1.0, ""),
  ("goodPhoton", "verticalOverCentral", 10000, 0, 10, ""),
  ("goodPhoton", "horizontalOverCentral", 10000, 0, 10, ""),
  
  ("goodPhoton", "horizontalImbalance", 100, -2, 2, ""),
  ("goodPhoton", "verticalImbalance", 100, -2, 2, ""),
  

  # electrons
  ("goodElectronSR", "pt", 200, 0, 100, ""),
  ("goodElectronSR", "eta", 20, -2.2, 2.2, ""),
  ("goodElectronSR", "phi", 20, -3.14, 3.14, ""),
  ("dielectron", "acoplanarity", 1000, 0, 1, ""),
  ("dielectron", "pt", 100, 0, 1, ""),
  ("dielectron", "mass", 200, 0, 200, ""),
  ("dielectron", "rapidity", 100, -2.2, 2.2, ""),
  ("dielectronPP", "mass", 200, 0, 200, ""),
  ("dielectronMM", "mass", 200, 0, 200, ""),
  ("dielectronacoLt0p01", "mass", 200, 0, 200, ""),
  ("dielectronPPacoLt0p01", "mass", 200, 0, 200, ""),
  ("dielectronMMacoLt0p01", "mass", 200, 0, 200, ""),
  ("dielectron", "deltaPhi", 100, 0, pi, ""),
  ("electrons", "deltaPhi", 100, -2 * pi, 2 * pi, ""),
  ("dielectron", "deltaPhiPtGt6GeV", 100, 0, pi, ""),
  ("dielectron", "deltaPhiAcoWeighted", 100, 0, pi, ""),
  ("dielectron", "acoplanarityAcoWeighted", 1000, 0, 1, ""),
  ("dielectron", "deltaPt", 100, 0, 10, ""),
  ("dielectronSR", "pt", 100, 0, 1, ""),
  ("dielectronSR", "mass", 200, 0, 200, ""),
  ("dielectronSR", "rapidity", 100, -2.2, 2.2, ""),
  ("dielectronSR", "deltaPhi", 100, 0, pi, ""),
  ("dielectronSR", "deltaPt", 100, 0, 10, ""),
  ("dielectron", "theta", 100, -2 * pi, 2 * pi, ""),
  ("dielectron", "deltaPhi0p01", 100, 0, pi, ""),
  ("dielectron", "deltaPhi0p005", 100, 0, pi, ""),
  ("dielectron", "deltaPhi0p001", 100, 0, pi, ""),
  ("genDielectron", "deltaPhi", 400, -2 * pi, 2 * pi, ""),
  ("genDielectronSR", "deltaPhi", 100, 0, pi, ""),
  ("genDielectron", "deltaPt", 2000, -1, 1, ""),
  ("genDielectronSR", "deltaPt", 2000, -1, 1, ""),
  ("genDielectron", "pt", 1000, 0, 10, ""),

  # calo
  ("caloTowerHE", "energyHad", 100, 0, 5, ""),
  ("caloTowerHE", "energyTransverse", 100, 0, 5, ""),
  ("caloTowerHE", "energy", 100, 0, 5, ""),
  ("goodCaloTowerHE", "energyHad", 100, 0, 5, ""),
  ("goodCaloTowerHE", "energyTransverse", 100, 0, 5, ""),
  ("goodCaloTowerHE", "energy", 100, 0, 5, ""),
  ("caloTowerHFplus", "energyHad", 100, 0, 10, ""),
  ("caloTowerHFplus", "energyTransverse", 100, 0, 10, ""),
  ("caloTowerHFplus", "energy", 100, 0, 10, ""),
  ("goodCaloTowerHFplus", "energyHad", 1000, 0, 100, ""),
  ("goodCaloTowerHFplus", "energyTransverse", 1000, 0, 100, ""),
  ("goodCaloTowerHFplus", "energy", 1000, 0, 100, ""),
  ("caloTowerHFminus", "energyHad", 100, 0, 10, ""),
  ("caloTowerHFminus", "energyTransverse", 100, 0, 10, ""),
  ("caloTowerHFminus", "energy", 100, 0, 10, ""),
  ("goodCaloTowerHFminus", "energyHad", 1000, 0, 100, ""),
  ("goodCaloTowerHFminus", "energyTransverse", 1000, 0, 100, ""),
  ("goodCaloTowerHFminus", "energy", 1000, 0, 100, ""),

  # gen-level
  ("genPhoton", "et", 200, 0, 10, ""),
  ("genPhoton", "energy", 200, 0, 10, ""),
  ("leadingGenPhoton", "energy", 200, 0, 10, ""),
  ("leadingGenPhotonBarrel", "energy", 200, 0, 10, ""),
  ("leadingGenPhotonBarrelEndcap", "energy", 200, 0, 10, ""),

  # event
  ("event", "deltaEt", 100, 0, 1, ""),
  ("event", "cosThetaStar", 10, 0, 1, ""),
  ("event", "electronsCosThetaStar", 100, 0, 1, ""),
  ("eventSR", "electronsCosThetaStar", 100, 0, 1, ""),
  ("eventSR10", "cosThetaStar", 10, 0, 1, ""),
  ("eventSR5", "cosThetaStar", 5, 0, 1, ""),
  ("eventSR4", "cosThetaStar", 4, 0, 1, ""),
  ("eventSR3", "cosThetaStar", 3, 0, 1, ""),
  ("event", "ZDCenergyPlus", 10000, 0, 20000, ""),
  ("event", "ZDCenergyMinus", 10000, 0, 20000, ""),
  ("monophoton", "egamma_deltaEta", 1000, -10, 10, ""),
  ("monophoton", "egamma_deltaPhi", 1000, -10, 10, ""),
  ("monophoton", "egamma_deltaR", 1000, -10, 10, ""),
  ("monophoton", "egamma_deltaEta_gt50GeV", 1000, -10, 10, ""),
  ("monophoton", "egamma_deltaPhi_gt50GeV", 1000, -10, 10, ""),
  ("monophoton", "egamma_deltaR_gt50GeV", 1000, -10, 10, ""),
)

bins = [0]
bin_width = 0.1 / 35
rebin_start = 0.037

for i in range(1, 100):
  edge = i * bin_width
  if edge > rebin_start:
    bins.append(0.1)
    break
  bins.append(edge)


def get_log_bins(min_exp, max_exp, points_per_decade=(1, )):
  bins = []

  for exponent in range(min_exp, max_exp):
    for point in points_per_decade:
      bins.append(point * 10**exponent)

  return bins


log_bins_10 = list(np.logspace(-3, -1, 11, base=10))
log_bins_10[0] = 0

log_bins_14 = list(np.logspace(-3, -1, 15, base=10))
log_bins_14[0] = 0

log_bins_18 = list(np.logspace(-3, -1, 19, base=10))
log_bins_18[0] = 0

log_bins_20 = list(np.logspace(-3, -1, 21, base=10))
log_bins_20[0] = 0

log_bins_22 = list(np.logspace(-3, -1, 23, base=10))
log_bins_22[0] = 0

log_bins_30 = list(np.logspace(-3, -1, 31, base=10))
log_bins_30[0] = 0

log_bins_40 = list(np.logspace(-3, -1, 41, base=10))
log_bins_40[0] = 0

log_bins_10and20 = list(np.logspace(-3, -2, 11, base=10)) + \
    list(np.logspace(-2, -1, 21, base=10))
log_bins_10and20[0] = 0
log_bins_10and20 = list(dict.fromkeys(log_bins_10and20))

log_bins_5and35 = list(np.logspace(-3, -2, 6, base=10)) + \
    list(np.logspace(-2, -1, 36, base=10))
log_bins_5and35[0] = 0
log_bins_5and35 = list(dict.fromkeys(log_bins_5and35))

irregularHistParams = (
  ("diphoton", "acoplanarity1", log_bins_14, ""),
  ("diphoton", "acoplanarity2", log_bins_18, ""),
  ("diphoton", "acoplanarity3", log_bins_20, ""),
  ("diphoton", "acoplanarity4", log_bins_30, ""),
  ("diphoton", "acoplanarity5", log_bins_40, ""),

  # ("diphoton", "acoplanarity4",
  #  [0.0, 0.002, 0.004, 0.006, 0.008, 0.01, 0.012, 0.014, 0.016, 0.018, 0.02, 0.035, 0.050, 0.065, 0.1],
  #  ""),
)

histParams2D = (
  ("diphoton_seedTime", 100, -10, 10, 100, -10, 10, ""),
  ("diphoton_seedTimeSR", 100, -10, 10, 100, -10, 10, ""),
  ("goodPhoton_absEta_vs_et", 100, 0, 3.0, 1000, 0, 1000, ""),
  ("goodPhoton_eta_vs_et", 100, -3.0, 3.0, 1000, 0, 1000, ""),
  ("goodPhoton_eta_vs_phi", 1000, -3.0, 3.0, 1000, -4.0, 4.0, ""),
  ("goodPhoton_eta_vs_phi_vs_et", 1000, -3.0, 3.0, 1000, -4.0, 4.0, ""),
  ("goodPhoton_eta_vs_phi_gt50GeV", 100, -3.0, 3.0, 100, -4.0, 4.0, ""),
  
  ("egamma_et_vs_goodPhoton_et", 1000, 0, 1000, 1000, 0, 1000, ""),
)

eventsTreeNames = [
  "Events",
]
specialBranchSizes = {}

visualizationParams = {
  "normalizeMomenta": True,
  "maxTowerHeight": 6.0,
  "normalizeRotation": True,
  "circleRadius": 1.0,
  "circleColor": 1,  # black
  "towerInnerWidth": 0.08,
  "towerOuterWidthScale": 0.05,
  "towerColor": -1,
  # "towerColorR": 0.45,
  # "towerColorG": 0.97,
  # "towerColorB": 0.35,
  # nice red-pink
  "towerColorR": 0.72,
  "towerColorG": 0.21,
  "towerColorB": 0.31,
  # complemenatry green:
  # "towerColorR": 0.53,
  # "towerColorG": 0.88,
  # "towerColorB": 0.13,
  "towerAlpha": 0.2,
  # "towerAlpha": 1.0,
  "towerFillStyle": 1001,
  "backgroundColor": 0,  # white
  "canvasSize": 8.0,
  "trackColor": -1,
  "trackColorR": 0.72,
  "trackColorG": 0.21,
  "trackColorB": 0.31,
  "trackWidth": 1,
}

extraEventCollections = {
  "convertedPhoton": {
    "inputCollections": ("photon", ),
    "hasConversionTracks": True,
  },
  "unconvertedPhoton": {
    "inputCollections": ("photon", ),
    "hasConversionTracks": False,
  },
  "conversionElectron": {
    "inputCollections": ("electron", ),
    "conversionVeto": False,
  },
  "unconversionElectron": {
    "inputCollections": ("electron", ),
    "conversionVeto": True,
  },
}
