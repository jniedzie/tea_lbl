# event cuts
eventCuts = {
    "max_ZDCenergyPerSide": 10000.0,

    "min_Nphotons": 2,
    "max_Nphotons": 2,
    "min_diphotonMass": 5.0,
    "max_diphotonPt": 1.0,

    "max_Ntracks": 0,
    "max_Nelectrons": 0,
    "max_Nmuons": 0,
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

muonCuts = {
    "min_pt": 2.5,
    "max_absEta": 2.4,
}


# calorimeter cuts
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

    "crackHadron_start": 1.305,
    "crackHadron_end": 1.41,

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


#  scaling parameters

luminosity = 1647.180726  # μb^-1, with ZDC
# luminosity = 1609.910015010; // from brilcalc, 1/μb
# luminosity = 1639.207543; // from Ruchi, 1/μb

crossSections = {
    "lbl": 2.59,  # μb
    "qed": 8827.220,  # μb
    "cep": -1,  # we scale it to data
}

scaleFactors = {
    # photon ET > 2.5 GeV, diphoton pt < 1 GeV
    #      NE       ChE      HFveto   L1EG     Reco+ID
    "lbl": 0.8477 * 0.9322 * 0.8643 * 1.0006 * 0.9771**2,
    "qed": 0.8477 * 0.9322 * 0.8643 * 1.0006 * 0.952**2,
    "cep": -1,  # we scale it to data

    # photon ET > 2.0 GeV, diphoton pt < 2 GeV
    #      NE     ChE    HFveto  L1EG    Reco+ID
    # "lbl": 0.85 * 0.93 * 0.866 * 1.008 * 1.037**2,
    # "qed": 0.85 * 0.93 * 0.866 * 1.008 * 0.976**2,
    # "cep": -1,  # we scale it to data
}

nGenEvents = {
    "lbl": 466000,
    "qed": 59260000,
    "cep": -1,  # we scale it to data
}

cep_scaling_min_acoplanarity = 0.02
# cep_scaling_min_acoplanarity = 0.018
# cep_scaling_min_acoplanarity = 0.016


#  significance & limits parameters

n_acoplanarity_bins = 500
uncertainty_on_zero = 1.84  # 95% CL
# uncertainty_on_zero = 1.14  # 68% CL

systematic_uncertainty = 1.25
