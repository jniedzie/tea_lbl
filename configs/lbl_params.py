# event cuts
eventCuts = {
    "max_ZDCenergyPerSide": 10000.0,

    "min_Nphotons": 2,  # 2 for LbL analysis, 0 for QED analysis
    "max_Nphotons": 2,  # 2 for LbL analysis, 0 for QED analysis

    "min_diphotonMass": 5.0,  # only used in LbL analysis
    "max_diphotonPt": 1.0,  # only used in LbL analysis

    "min_Nelectrons": 0,  # 0 for LbL analysis, 2 for QED analysis
    "max_Nelectrons": 0,  # 0 for LbL analysis, 2 for QED analysis

    "min_dielectronMass": 5.0,  # only used in QED analysis
    "max_dielectronPt": 1.0,  # only used in QED analysis

    "max_Ntracks": 0,
    "max_Nmuons": 0,
    "max_Ntowers": 0,
}


# good object definitions
photonCuts = {
    "min_et": 2.0,
    "max_absEta": 2.2,
    "max_swissCross": 0.95,
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

    # we don't apply electron isolation:
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

    # we don't apply these track selections:
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


# matching between photons and electrons
electronPhotonMatching = {
    "maxDeltaEta": 0.5,  # ???
    "maxDeltaPhi": 0.5,  # ???
}

# matching between tracks and electrons
electronTrackMatching = {
    "maxDeltaEta": 0.15,
    "maxDeltaPhi": 0.7,
}


#  scaling parameters

luminosity = 1647.180726  # μb^-1, with ZDC
luminosity_err = luminosity * 0.019  # 1.9% uncertainty

# luminosity = 1609.910015010; // from brilcalc, 1/μb
# luminosity = 1639.207543; // from Ruchi, 1/μb

reference_alp_cross_section = 10e-3  # μb

crossSections = {
    "lbl": 2.59,  # μb
    "qed": 8827.220,  # μb
    "cep": 5.8e-3,  # we scale it to data

    "alps_5": reference_alp_cross_section,
    "alps_6": reference_alp_cross_section,
    "alps_9": reference_alp_cross_section,
    "alps_11": reference_alp_cross_section,
    "alps_14": reference_alp_cross_section,
    "alps_16": reference_alp_cross_section,
    "alps_22": reference_alp_cross_section,
    "alps_30": reference_alp_cross_section,
    "alps_50": reference_alp_cross_section,
    "alps_90": reference_alp_cross_section,
}


# photon ET > 2.0 GeV, diphoton pt < 1 GeV
#                       NE       ChE      HFveto   L1EG     Reco+ID
photon_scale_factor = 0.8497 * 0.9339 * 0.8696 * 1.0089 * (0.957*0.9612)**2
electron_scale_factor = 0.8497 * 0.9339 * 0.8696 * 1.0089 * 0.943**2

scale_factors = {
    "nee": 0.8497,
    "che": 0.9339,
    "l1hf": 0.8696,
    "l1eg": 1.0089,
    "photonReco": 0.957,
    "photonID": 0.9612,
    "electronRecoID": 0.943,
}

scale_factor_errors = {
    "nee": 0.0089,
    "che": 0.0093,
    "l1hf": 0.081,
    "l1eg": 0.002,
    "photonReco": 0.0433,
    "photonID": 0.0976,
    "electronRecoID": 0.0085,
}


def get_scale_factor(photon=True):
    value = 1
    error = 0

    to_skip = "electron" if photon else "photon"
    squared = "photon" if photon else "electron"

    for variable in scale_factors:
        if to_skip in variable:
            continue

        error += (scale_factor_errors[variable] / scale_factors[variable])**2
        value *= scale_factors[variable]
        
        if squared in variable:
            error += (scale_factor_errors[variable] / scale_factors[variable])**2
            value *= scale_factors[variable]

    sf_error = value * error**(1/2)

    return value, sf_error


# scaleFactors = {
#     "lbl": photon_scale_factor,
#     "qed": photon_scale_factor,  # for LbL analysis
#     # "qed": electron_scale_factor, # for QED analysis
#     "cep": photon_scale_factor,  # we scale it to data

#     "alps_5": photon_scale_factor,
#     "alps_6": photon_scale_factor,
#     "alps_9": photon_scale_factor,
#     "alps_11": photon_scale_factor,
#     "alps_14": photon_scale_factor,
#     "alps_16": photon_scale_factor,
#     "alps_22": photon_scale_factor,
#     "alps_30": photon_scale_factor,
#     "alps_50": photon_scale_factor,
#     "alps_90": photon_scale_factor,
# }

nGenEvents = {
    "lbl": 466000,
    "qed": 59260000,
    "cep": 668000,  # we scale it to data

    "alps_5": 754000,
    "alps_6": 729000,
    "alps_9": 722000,
    "alps_11": 692000,
    "alps_14": 712000,
    "alps_16": 682000,
    "alps_22": 694000,
    "alps_30": 719000,
    "alps_50": 511000,
    "alps_90": 449000,
}

# cep_scaling_min_acoplanarity = 0.02
# cep_scaling_min_acoplanarity = 0.018
cep_scaling_min_acoplanarity = 0.016

#  significance & limits parameters

n_acoplanarity_bins = 500
n_mass_bins = 200

uncertainty_on_zero = 1.84  # 95% CL
# uncertainty_on_zero = 1.14  # 68% CL

systematic_uncertainty = 1.26
alp_mc_uncertainty = 1.03
