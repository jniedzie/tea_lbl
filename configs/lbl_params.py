# event cuts

eventCuts = {
 "max_ZDCenergy": 10.0,   
 
 "min_Nphotons": 2,
 "max_Nphotons": 2,
 "min_diphotonMass": 5.0,
 "max_diphotonPt": 1.0,
 
 "max_Ntracks": 0,
 "max_Nelectrons": 0,
 "max_Ntowers": 0,
}

# good object definitions
photonCuts = {
    "min_et": 2.5,
    "max_swissCross": 0.95,
    "max_absEta": 2.2,
    "max_SCEtaWidth_barrel": 0.0106,
    "max_SCEtaWidth_endcap": 0.0272,
    "max_hOverE_barrel": 0.04596,
    "max_hOverE_endcap": 0.0590,
    "max_sigmaIEtaIEta_barrel": 0.02,
    "max_sigmaIEtaIEta_endcap": 0.06,
    "max_seedTime": 3.0,
}

electronCuts = {
    "min_pt": 2.0,
    "max_absEtaSC": 2.2,

    "max_nMissingHits": 1,
    "max_hOverE": 0.005,
    "max_deltaEtaAtVertex": 0.1,

    "max_PFChIso_barrel": 999999,
    "max_PFPhoIso_barrel": 999999,
    "max_PFNeuIso_barrel": 999999,

    "max_PFChIso_endcap": 999999,
    "max_PFPhoIso_endcap": 999999,
    "max_PFNeuIso_endcap": 999999,
}

trackCuts = {
    "min_pt": 0.3,
    "max_absEta": 2.4,
    "min_nValidHits": 4,
    
    "max_normalizedChi2": 999999,
    "max_dxy": 999999,
    "max_dz": 999999,
    "max_dxyOverError": 999999,
    "max_dzOverError": 999999,
}

# calorimeter cuts
extraEventCollections = {
    "PassingZDCcounts":  {"inputCollections": ("ZDC",), "energy": (eventCuts["max_ZDCenergy"], 9999999.)},
}

caloNoiseThresholds = {
    "HFm": 6.0,
    "HFp": 6.0,
    "HB": 2.8,
    "HE": 1.0,
    "EB": 0.7,
    "EE": 3.0,
}

caloNoiseVariables = {
    "HFm": "energy",
    "HFp": "energy",
    "HB": "hadE",
    "HE": "hadE",
    "EB": "emE",
    "EE": "emE",
}


# detector parameters
deadEtas = {
    "HFp": (29, 30),
    "HFm": (-29, -30),
    "HE": (-16, 16),
}

caloEtaEdges = {
    "maxEB": 1.479,
    "minEE": 1.479,
    "maxEE": 3.0,

    "maxHB": 1.305,
    "minHE": 1.305,
    "maxHE": 3.0,

    "minHF": 2.9,
    "maxHF": 5.2,
}

detectorParams = {
    "crack_start": 1.4442,
    "crack_end": 1.566,

    "hem_etaStart": -3.0,
    "hem_etaEnd": -1.39,
    "hem_phiStart": -1.6,
    "hem_phiEnd": -0.9,

    "caloTower_etaMax": 2.4,
}


# matching between calorimeters and photons/electrons
caloMatching = {
    "maxDeltaEta_EB": 0.15,
    "maxDeltaPhi_EB": 0.7,
    "maxDeltaEta_EE": 0.15,
    "maxDeltaPhi_EE": 0.4,
}
