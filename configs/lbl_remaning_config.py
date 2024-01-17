nEvents = 10
printEveryNevents = 10

inputFilePath = "/eos/cms/store/cmst3/group/lightbylight/Pranati/Final_afterTrigger/Data/Data_29thJune/merged/merged_ntuples_2.root"
treeOutputFilePath = "./test_renamed.root"

branchesNames = {
  
  "run"                   : ("runNumber"                  , "runNumber/I"  ),
  "lumis"                 : ("lumiSection"                , "lumiSection/I"),
  "event"                 : ("eventNumber"                , "eventNumber/I"),
  
  "xVtx"                  : ("vertex_x"                   , "vector<float>"),
  "yVtx"                  : ("vertex_y"                   , "vector<float>"),
  "zVtx"                  : ("vertex_z"                   , "vector<float>"),
    
  "mcEta"                 : ("genParticle_eta"            , "vector<float>"),
  "mcPhi"                 : ("genParticle_phi"            , "vector<float>"),
  "mcEt"                  : ("genParticle_et"             , "vector<float>"),
  "mcPID"                 : ("genParticle_pid"            , "vector<float>"),
  
  "phoE"                  : ("photon_energy"              , "vector<float>"),
  "phoEt"                 : ("photon_et"                  , "vector<float>"),
  "phoEta"                : ("photon_eta"                 , "vector<float>"),
  "phoPhi"                : ("photon_phi"                 , "vector<float>"),
  "phoHoverE"             : ("photon_hOverE"              , "vector<float>"),
  "phoSigmaEtaEta_2012"   : ("photon_SigmaEta2012"        , "vector<float>"),
  "phoSigmaIEtaIEta_2012" : ("photon_SigmaIEtaIEta2012"   , "vector<float>"),
  "phoMaxEnergyXtal"      : ("photon_maxEnergyXtal"       , "vector<float>"),
  "phoETop"               : ("photon_energyTop"           , "vector<float>"),
  "phoEBottom"            : ("photon_energyBottom"        , "vector<float>"),
  "phoELeft"              : ("photon_energyLeft"          , "vector<float>"),
  "phoERight"             : ("photon_energyRight"         , "vector<float>"),
  "phoHasConversionTracks": ("photon_hasConversionTracks" , "vector<float>"),
  "pho_seedTime"          : ("photon_seedTime"            , "vector<float>"),
  "phoSCE"                : ("photon_SCEnergy"            , "vector<float>"),
  "phoSCEt"               : ("photon_SCEt"                , "vector<float>"),
  "phoSCEta"              : ("photon_SCEta"               , "vector<float>"),
  "phoSCPhi"              : ("photon_SCPhi"               , "vector<float>"),
  "phoSCEtaWidth"         : ("photon_SCEtaWidth"          , "vector<float>"),
  "phoSCPhiWidth"         : ("photon_SCPhiWidth"          , "vector<float>"),
  
  "CaloTower_e"           : ("CaloTower_energy"           , "vector<float>"),
  "CaloTower_et"          : ("CaloTower_et"               , "vector<float>"),
  "CaloTower_eta"         : ("CaloTower_eta"              , "vector<float>"),
  "CaloTower_phi"         : ("CaloTower_phi"              , "vector<float>"),
  "CaloTower_hadE"        : ("CaloTower_hadE"             , "vector<float>"),
  "CaloTower_emE"         : ("CaloTower_emE"              , "vector<float>"),
  
  
  "trkPt"                 : ("track_pt"                   , "vector<float>"),
  "trkP"                  : ("track_momentum"             , "vector<float>"),
  "trkEta"                : ("track_eta"                  , "vector<float>"),
  "trkPhi"                : ("track_phi"                  , "vector<float>"),
  "trkcharge"             : ("track_charge"               , "vector<float>"),
  "trkValidHits"          : ("track_nValidHits"           , "vector<float>"),
  "trkMissHits"           : ("track_nMissHits"            , "vector<float>"),
  "trkPurity"             : ("track_purity"               , "vector<float>"),
  "trknormchi2"           : ("track_normalizedChi2"       , "vector<float>"),
  "trkd0"                 : ("track_d0"                   , "vector<float>"),
  "trkdxy"                : ("track_dxy"                  , "vector<float>"),
  "trkdz"                 : ("track_dz"                   , "vector<float>"),
  "trkdxyError"           : ("track_dxyError"             , "vector<float>"),
  "trkdzError"            : ("track_dzError"              , "vector<float>"),
  "trkvx"                 : ("track_vx"                   , "vector<float>"),
  "trkvy"                 : ("track_vy"                   , "vector<float>"),
  "trkvz"                 : ("track_vz"                   , "vector<float>"),
  
  "eleEn"                 : ("electron_energy"            , "vector<float>"),
  "elePt"                 : ("electron_pt"                , "vector<float>"),
  "eleEta"                : ("electron_eta"               , "vector<float>"),
  "elePhi"                : ("electron_phi"               , "vector<float>"),
  "eleCharge"             : ("electron_charge"            , "vector<float>"),
  "eleMissHits"           : ("electron_nMissHits"         , "vector<float>"),
  "eleHoverE"             : ("electron_hOverE"            , "vector<float>"),
  "eleEoverP"             : ("electron_eOverP"            , "vector<float>"),
  "elePFRelIsoWithEA"     : ("electron_PFRelIsoWithEA"    , "vector<float>"),
  "eledEtaAtVtx"          : ("electron_deltaEtaAtVertex"  , "vector<float>"),
  "elePFChIso"            : ("electron_PFChIso"           , "vector<float>"),
  "elePFPhoIso"           : ("electron_PFPhoIso"          , "vector<float>"),
  "elePFNeuIso"           : ("electron_PFNeuIso"          , "vector<float>"),
  "eleConvVeto"           : ("electron_ConversionVeto"    , "vector<float>"),
  "eleSCEt"               : ("electron_SCEt"              , "vector<float>"),
  "eleSCEta"              : ("electron_SCEta"             , "vector<float>"),
  "eleSCPhi"              : ("electron_SCPhi"             , "vector<float>"),
  "eleSCEn"               : ("electron_SCEnergy"          , "vector<float>"),  
  
  "muPt"                  : ("muon_Pt"                    , "vector<float>"),
  "muEta"                 : ("muon_Eta"                   , "vector<float>"),
  "muPhi"                 : ("muon_Phi"                   , "vector<float>"),
  "muCharge"              : ("muon_charge"                , "vector<float>"),
  "muHoverE"              : ("muon_hOverE"                , "vector<float>"),
  "muMissHits"            : ("muon_nMissHits"             , "vector<float>"),
  "muPFRelIsoWithEA"      : ("muon_PFRelIsoWithEA"        , "vector<float>"),
  "mudEtaAtVtx"           : ("muon_deltaEtaAtVertex"      , "vector<float>"),
  "muPFChIso"             : ("muon_PFChIso"               , "vector<float>"),
  "muPFPhoIso"            : ("muon_PFPhoIso"              , "vector<float>"),
  "muPFNeuIso"            : ("muon_PFNeuIso"              , "vector<float>"),
  "muSCEta"               : ("muon_SCEta"                 , "vector<float>"),
  "muSCEt"                : ("muon_SCEt"                  , "vector<float>"),
  "muSCPhi"               : ("muon_SCPhi"                 , "vector<float>"),
  "muSCEn"                : ("muon_SCEn"                  , "vector<float>"),
  
  "egEt"                  : ("egamma_et"                  , "vector<float>"),
  "egEta"                 : ("egamma_eta"                 , "vector<float>"),
  "egPhi"                 : ("egamma_phi"                 , "vector<float>"),
  
  "nDisplacedTracks"      : ("nDisplacedTracks"           , "nDisplacedTracks/I"),
  "nPixelClusters"        : ("nPixelClusters"             , "nPixelClusters/I"),
  "nPixelRecHits"         : ("nPixelRecHits"              , "nPixelRecHits/I"),
  "nDedxHits"             : ("nDedxHits"                  , "nDedxHits/I"),
  
  "n"           : ("nZDC"           , "nZDC/I"),
  "e"           : ("ZDC_energy"     , "ZDC_energy[nZDC]/F"),
  "saturation"  : ("ZDC_saturation" , "ZDC_saturation[nZDC]/F"),
  "zside"       : ("ZDC_zSide"      , "ZDC_zSide[nZDC]/F"),
  "section"     : ("ZDC_section"    , "ZDC_section[nZDC]/F"),
  "channel"     : ("ZDC_channel"    , "ZDC_channel[nZDC]/F"),
  
    # "nCastorTower": ("nCastorTower", "vector<float>"),
  # "CastorTower_hadE": ("CastorTower_hadE", "vector<float>"),
  # "CastorTower_emE": ("CastorTower_emE", "vector<float>"),
  # "CastorTower_p4": ("CastorTower_p4", "vector<float>"),
  # //"C: (//"C, "vector<float>"),
  
  # pixelTree->SetBranchAddress("nPix"            , &nPhysObjects.at(EPhysObjType::kPixelTrack));
  # pixelTree->SetBranchAddress("pixPt"           , &pixelTrackPt);
  # pixelTree->SetBranchAddress("pixP"            , &pixelTrackP);
  # pixelTree->SetBranchAddress("pixEta"          , &pixelTrackEta);
  # pixelTree->SetBranchAddress("pixPhi"          , &pixelTrackPhi);
  # pixelTree->SetBranchAddress("pixcharge"       , &pixelTrackCharge);
  # pixelTree->SetBranchAddress("pixValidHits"    , &pixelTrackValidHits);
  # pixelTree->SetBranchAddress("pixMissHits"     , &pixelTrackMissingHits);
  # pixelTree->SetBranchAddress("pixPurity"       , &pixelTrackPurity);
  # pixelTree->SetBranchAddress("pixnormchi2"     , &pixelTrackChi2);
  # pixelTree->SetBranchAddress("pixdxy"          , &pixelTrackDxy);
  # pixelTree->SetBranchAddress("pixdz"           , &pixelTrackDz);
  # pixelTree->SetBranchAddress("pixdxyError"     , &pixelTrackDxyErr);
  # pixelTree->SetBranchAddress("pixdzError"      , &pixelTrackDzErr);
  # pixelTree->SetBranchAddress("pixvx"           , &pixelTrackVertexX);
  # pixelTree->SetBranchAddress("pixvy"           , &pixelTrackVertexY);
  # pixelTree->SetBranchAddress("pixvz"           , &pixelTrackVertexZ);  
}
