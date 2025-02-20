#include "LbLHistogramsFiller.hpp"

#include "ConfigManager.hpp"
#include "ExtensionsHelpers.hpp"
#include "UserExtensionsHelpers.hpp"

using namespace std;

LbLHistogramsFiller::LbLHistogramsFiller(shared_ptr<HistogramsHandler> histogramsHandler_) : histogramsHandler(histogramsHandler_) {
  // Create a config manager
  auto &config = ConfigManager::GetInstance();

  // Try to read weights branch
  try {
    config.GetValue("weightsBranchName", weightsBranchName);
  } catch (const Exception &e) {
    info() << "Weights branch not specified -- will assume weight is 1 for all events" << endl;
  }

  config.GetMap("caloEtaEdges", caloEtaEdges);

  eventProcessor = make_unique<EventProcessor>();

  acoplanarityFunction = new TF1("fit_fun", "[0] * exp([1]*x) + [2] * exp([3]*x)", 0, 0.1);
  vector<float> params = {102020, -798.6, 693.552, -112.731};
  for (int i = 0; i < 4; i++) {
    acoplanarityFunction->SetParameter(i, params[i]);
  }

  // auto file = TFile::Open("/afs/desy.de/user/j/jniedzie/tea_lbl/merged_afterTrigger_histograms_default.root");
  // genDielectronDeltaPt = (TH1D *)file->Get("genDielectron_deltaPt");
}

LbLHistogramsFiller::~LbLHistogramsFiller() {}

float LbLHistogramsFiller::GetWeight(const shared_ptr<Event> event) {
  // Try to get event weight, otherwise set to 1.0
  float weight = 1.0;
  try {
    weight = event->Get(weightsBranchName);
  } catch (const Exception &e) {
  }
  return weight;
}

void LbLHistogramsFiller::FillCaloHistograms(const shared_ptr<Event> event) {
  GetWeight(event);
  auto towers = event->GetCollection("CaloTower");

  float maxEnergyHE = -1, maxEnergyHFplus = -1, maxEnergyHFminus = -1;
  shared_ptr<CaloTower> leadingTowerHE, leadingTowerHFplus, leadingTowerHFminus;

  // info() << "Event number: " << (int)event->Get("eventNumber") << "\trun: " << (int)event->Get("runNumber") << endl;
  
  for (auto physicsObject : *towers) {
    auto tower = asCaloTower(physicsObject);

    if (tower->IsDead()) continue;
    if (tower->IsInHadronicCrack()) continue;
    if (tower->IsInHEM()) continue;

    float eta = (float)physicsObject->Get("eta");
    float energy = physicsObject->Get("energy");

    // HE
    if ((fabs(eta) > caloEtaEdges["minHE"] && fabs(eta) < caloEtaEdges["maxHE"])){
      if (energy > maxEnergyHE) {
        maxEnergyHE = energy;
        leadingTowerHE = tower;
      }
    }

    // HF+
    if (eta > caloEtaEdges["minHF"] && eta < caloEtaEdges["maxHF"]) {
      if (energy > maxEnergyHFplus) {
        maxEnergyHFplus = energy;
        leadingTowerHFplus = tower;
      }
    }

    // HF-
    if (eta > -caloEtaEdges["maxHF"] && eta < -caloEtaEdges["minHF"]) {
      if (energy > maxEnergyHFminus) {
        maxEnergyHFminus = energy;
        leadingTowerHFminus = tower;
      }
    }
  }

  if (maxEnergyHE > 0) {
    histogramsHandler->Fill("goodCaloTowerHE_energyHad", leadingTowerHE->GetAs<float>("hadE"), GetWeight(event));
    histogramsHandler->Fill("goodCaloTowerHE_energyTransverse", leadingTowerHE->GetAs<float>("et"), GetWeight(event));
    histogramsHandler->Fill("goodCaloTowerHE_energy", leadingTowerHE->GetAs<float>("energy"), GetWeight(event));
  }
  
  if (maxEnergyHFplus > 0) {
    // info() << (int)event->Get("eventNumber") << "\t" << leadingTowerHFplus->GetAs<float>("eta") << "\t" << leadingTowerHFplus->GetAs<float>("energy") << endl;
    histogramsHandler->Fill("goodCaloTowerHFplus_energyHad", leadingTowerHFplus->GetAs<float>("hadE"), GetWeight(event));
    histogramsHandler->Fill("goodCaloTowerHFplus_energyTransverse", leadingTowerHFplus->GetAs<float>("et"), GetWeight(event));
    histogramsHandler->Fill("goodCaloTowerHFplus_energy", leadingTowerHFplus->GetAs<float>("energy"), GetWeight(event));
  }

  if (maxEnergyHFminus > 0) {
    // info() << "Filling HF- tower with eta: " << leadingTowerHFminus->GetAs<float>("eta") << "\tenergy: " << leadingTowerHFminus->GetAs<float>("energy") << endl;
    histogramsHandler->Fill("goodCaloTowerHFminus_energyHad", leadingTowerHFminus->GetAs<float>("hadE"), GetWeight(event));
    histogramsHandler->Fill("goodCaloTowerHFminus_energyTransverse", leadingTowerHFminus->GetAs<float>("et"), GetWeight(event));
    histogramsHandler->Fill("goodCaloTowerHFminus_energy", leadingTowerHFminus->GetAs<float>("energy"), GetWeight(event));
  }
}

void LbLHistogramsFiller::FillThreePhotonHistograms(const shared_ptr<Event> event) {
  auto photons = event->GetCollection("goodPhoton");
  if (photons->size() != 3) return;

  auto photon1 = photons->at(0);
  auto photon2 = photons->at(1);
  TLorentzVector photon1vec, photon2vec;
  photon1vec.SetPtEtaPhiM(photon1->Get("et"), photon1->Get("eta"), photon1->Get("phi"), 0);
  photon2vec.SetPtEtaPhiM(photon2->Get("et"), photon2->Get("eta"), photon2->Get("phi"), 0);
  auto diphoton = photon1vec + photon2vec;

  histogramsHandler->Fill("diphotonThreePhoton_mass", diphoton.M(), GetWeight(event));

  photon1 = photons->at(0);
  photon2 = photons->at(2);
  photon1vec.SetPtEtaPhiM(photon1->Get("et"), photon1->Get("eta"), photon1->Get("phi"), 0);
  photon2vec.SetPtEtaPhiM(photon2->Get("et"), photon2->Get("eta"), photon2->Get("phi"), 0);
  diphoton = photon1vec + photon2vec;
  histogramsHandler->Fill("diphotonThreePhoton_mass", diphoton.M(), GetWeight(event));

  photon1 = photons->at(1);
  photon2 = photons->at(2);
  photon1vec.SetPtEtaPhiM(photon1->Get("et"), photon1->Get("eta"), photon1->Get("phi"), 0);
  photon2vec.SetPtEtaPhiM(photon2->Get("et"), photon2->Get("eta"), photon2->Get("phi"), 0);
  diphoton = photon1vec + photon2vec;
  histogramsHandler->Fill("diphotonThreePhoton_mass", diphoton.M(), GetWeight(event));

}

void LbLHistogramsFiller::FillPhotonHistograms(const shared_ptr<Event> event) {
  auto photons = event->GetCollection("goodPhoton");
  if (photons->size() != 2) return;
  auto photon1 = photons->at(0);
  auto photon2 = photons->at(1);
  TLorentzVector photon1vec, photon2vec;
  photon1vec.SetPtEtaPhiM(photon1->Get("et"), photon1->Get("eta"), photon1->Get("phi"), 0);
  photon2vec.SetPtEtaPhiM(photon2->Get("et"), photon2->Get("eta"), photon2->Get("phi"), 0);

  auto diphoton = photon1vec + photon2vec;

  double deltaPhi = photon1vec.DeltaPhi(photon2vec);
  double acoplanarity = 1 - (fabs(deltaPhi) / TMath::Pi());

  histogramsHandler->Fill("diphoton_pt", diphoton.Pt(), GetWeight(event));
  histogramsHandler->Fill("diphoton_mass100", diphoton.M(), GetWeight(event));
  histogramsHandler->Fill("diphoton_mass200", diphoton.M(), GetWeight(event));
  histogramsHandler->Fill("diphoton_mass", diphoton.M(), GetWeight(event));
  histogramsHandler->Fill("diphoton_rapidity", diphoton.Rapidity(), GetWeight(event));
  histogramsHandler->Fill("diphoton_acoplanarity20", acoplanarity, GetWeight(event));
  histogramsHandler->Fill("diphoton_acoplanarity25", acoplanarity, GetWeight(event));
  histogramsHandler->Fill("diphoton_acoplanarity30", acoplanarity, GetWeight(event));
  histogramsHandler->Fill("diphoton_acoplanarity32", acoplanarity, GetWeight(event));
  histogramsHandler->Fill("diphoton_acoplanarity33", acoplanarity, GetWeight(event));
  histogramsHandler->Fill("diphoton_acoplanarity34", acoplanarity, GetWeight(event));
  histogramsHandler->Fill("diphoton_acoplanarity35", acoplanarity, GetWeight(event));
  histogramsHandler->Fill("diphoton_acoplanarity40", acoplanarity, GetWeight(event));
  histogramsHandler->Fill("diphoton_acoplanarity45", acoplanarity, GetWeight(event));
  histogramsHandler->Fill("diphoton_acoplanarity50", acoplanarity, GetWeight(event));
  histogramsHandler->Fill("diphoton_acoplanarity55", acoplanarity, GetWeight(event));
  histogramsHandler->Fill("diphoton_acoplanarity60", acoplanarity, GetWeight(event));

  auto tracks = event->GetCollection("track");
  auto electrons = event->GetCollection("goodElectron");
  shared_ptr<Track> track1 = nullptr;

  for (auto physicsObject : *tracks) {
    auto track = asTrack(physicsObject);
    if (track->OverlapsWithOtherObjects(photons) && !track->OverlapsWithOtherObjects(electrons)) {
      if (track1 == nullptr) {
        track1 = track;
        break;
      }
    }
  }
  if (track1) {
    float trackPt = track1->Get("pt");
    if (trackPt < 0.3) histogramsHandler->Fill("diphoton_acoplanarityTrack0to0p3", acoplanarity, GetWeight(event));
    if (trackPt > 0.3 && trackPt < 0.65) histogramsHandler->Fill("diphoton_acoplanarityTrack0p3to0p65", acoplanarity, GetWeight(event));
    if (trackPt > 0.6 && trackPt < 2.0) histogramsHandler->Fill("diphoton_acoplanarityTrack0p65to2p0", acoplanarity, GetWeight(event));
    if (trackPt > 2.0) histogramsHandler->Fill("diphoton_acoplanarityTrack2p0toInf", acoplanarity, GetWeight(event));
  }
  histogramsHandler->Fill("diphoton_acoplanarity1040", acoplanarity, GetWeight(event));

  auto hist = histogramsHandler->GetHistogram1D("diphoton_acoplanarity1");
  float binWidth1 = hist->GetBinWidth(1);
  float binWidth = hist->GetBinWidth(hist->GetXaxis()->FindFixBin(acoplanarity));
  // histogramsHandler->Fill("diphoton_acoplanarity1", acoplanarity, GetWeight(event)*binWidth1/binWidth);
  // histogramsHandler->Fill("diphoton_acoplanarity1", acoplanarity, GetWeight(event)/binWidth);
  histogramsHandler->Fill("diphoton_acoplanarity1", acoplanarity, GetWeight(event));

  hist = histogramsHandler->GetHistogram1D("diphoton_acoplanarity2");
  binWidth1 = hist->GetBinWidth(1);
  binWidth = hist->GetBinWidth(hist->GetXaxis()->FindFixBin(acoplanarity));
  // histogramsHandler->Fill("diphoton_acoplanarity2", acoplanarity, GetWeight(event)*binWidth1/binWidth);
  histogramsHandler->Fill("diphoton_acoplanarity2", acoplanarity, GetWeight(event));

  hist = histogramsHandler->GetHistogram1D("diphoton_acoplanarity3");
  binWidth1 = hist->GetBinWidth(1);
  binWidth = hist->GetBinWidth(hist->GetXaxis()->FindFixBin(acoplanarity));
  // histogramsHandler->Fill("diphoton_acoplanarity3", acoplanarity, GetWeight(event)*binWidth1/binWidth);
  histogramsHandler->Fill("diphoton_acoplanarity3", acoplanarity, GetWeight(event));

  hist = histogramsHandler->GetHistogram1D("diphoton_acoplanarity4");
  binWidth1 = hist->GetBinWidth(1);
  binWidth = hist->GetBinWidth(hist->GetXaxis()->FindFixBin(acoplanarity));
  // histogramsHandler->Fill("diphoton_acoplanarity4", acoplanarity, GetWeight(event)*binWidth1/binWidth);
  histogramsHandler->Fill("diphoton_acoplanarity4", acoplanarity, GetWeight(event));

  hist = histogramsHandler->GetHistogram1D("diphoton_acoplanarity5");
  binWidth1 = hist->GetBinWidth(1);
  binWidth = hist->GetBinWidth(hist->GetXaxis()->FindFixBin(acoplanarity));
  // histogramsHandler->Fill("diphoton_acoplanarity4", acoplanarity, GetWeight(event)*binWidth1/binWidth);
  histogramsHandler->Fill("diphoton_acoplanarity5", acoplanarity, GetWeight(event));

  histogramsHandler->Fill("diphoton_seedTime", photon1->Get("seedTime"), photon2->Get("seedTime"), GetWeight(event));

  if (acoplanarity < 0.01) {
    histogramsHandler->Fill("diphotonSR_pt", diphoton.Pt(), GetWeight(event));
    histogramsHandler->Fill("diphotonSR_mass", diphoton.M(), GetWeight(event));
    histogramsHandler->Fill("diphotonSR_mass100", diphoton.M(), GetWeight(event));
    histogramsHandler->Fill("diphotonSR_mass200", diphoton.M(), GetWeight(event));
    histogramsHandler->Fill("diphotonSR_rapidity", diphoton.Rapidity(), GetWeight(event));

    histogramsHandler->Fill("goodPhotonSR_et", photon1->Get("et"), GetWeight(event));
    histogramsHandler->Fill("goodPhotonSR_eta", photon1->Get("eta"), GetWeight(event));
    histogramsHandler->Fill("goodPhotonSR_phi", photon1->Get("phi"), GetWeight(event));
    histogramsHandler->Fill("goodPhotonSR_et", photon2->Get("et"), GetWeight(event));
    histogramsHandler->Fill("goodPhotonSR_eta", photon2->Get("eta"), GetWeight(event));
    histogramsHandler->Fill("goodPhotonSR_phi", photon2->Get("phi"), GetWeight(event));

    histogramsHandler->Fill("diphoton_seedTimeSR", photon1->Get("seedTime"), photon2->Get("seedTime"), GetWeight(event));
    histogramsHandler->Fill("unfoldingPhoton_pt", diphoton.Pt(), GetWeight(event));
    histogramsHandler->Fill("unfoldingPhoton_mass", diphoton.M(), GetWeight(event));
    histogramsHandler->Fill("unfoldingPhoton_absRap", fabs(diphoton.Rapidity()), GetWeight(event));
    histogramsHandler->Fill("unfoldingPhoton_absRap3", fabs(diphoton.Rapidity()), GetWeight(event));
    histogramsHandler->Fill("unfoldingPhoton_rap3", diphoton.Rapidity(), GetWeight(event));
    histogramsHandler->Fill("unfoldingPhoton_rap4", diphoton.Rapidity(), GetWeight(event));
  }
}

void LbLHistogramsFiller::FillGenLevelHistograms(const shared_ptr<Event> event) {
  float leadingPhotonEnergy = 99999;
  float leadingPhotonEnergyBarrel = 99999;
  float leadingPhotonEnergyBarrelEndcap = 99999;

  float leadingPhotonEt = 0;
  float leadingPhotonEtBarrel = 0;
  float leadingPhotonEtBarrelEndcap = 0;

  auto photons = event->GetCollection("genPhoton");
  auto electrons = event->GetCollection("genElectron");

  for (auto physObject : *photons) {
    auto photon = asPhoton(physObject)->GetFourMomentum();

    if (fabs(photon.Eta()) > 5.2) continue;
    if (GetDielectronAcoplanarity(event) > 0.01) continue;

    bool overlapsWithElectron = false;

    for (auto electron : *electrons) {
      if (photon.DeltaR(asElectron(electron)->GetFourMomentum()) < 0.1) {
        overlapsWithElectron = true;
        break;
      }
    }
    if (overlapsWithElectron) continue;

    histogramsHandler->Fill("genPhoton_et", photon.Pt(), GetWeight(event));
    histogramsHandler->Fill("genPhoton_energy", photon.E(), GetWeight(event));

    if (photon.Pt() > leadingPhotonEt) {
      leadingPhotonEt = photon.Pt();
      leadingPhotonEnergy = photon.E();
    }
    if (photon.Pt() > leadingPhotonEtBarrel && fabs(photon.Eta()) < 1.4442) {
      leadingPhotonEtBarrel = photon.Pt();
      leadingPhotonEnergyBarrel = photon.E();
    }

    if (photon.Pt() > leadingPhotonEtBarrelEndcap && fabs(photon.Eta()) < 3.0) {
      leadingPhotonEtBarrelEndcap = photon.Pt();
      leadingPhotonEnergyBarrelEndcap = photon.E();
    }
  }
  if (GetDielectronAcoplanarity(event) < 0.01) {
    histogramsHandler->Fill("leadingGenPhoton_energy", leadingPhotonEnergy, GetWeight(event));
    histogramsHandler->Fill("leadingGenPhotonBarrel_energy", leadingPhotonEnergyBarrel, GetWeight(event));
    histogramsHandler->Fill("leadingGenPhotonBarrelEndcap_energy", leadingPhotonEnergyBarrelEndcap, GetWeight(event));
  }

  
  if (electrons->size() == 2) {
    auto electron_1 = asElectron(electrons->at(0));
    auto electron_2 = asElectron(electrons->at(1));

    float deltaPhi = GetPhiModulation(electron_1, electron_2);
    float deltaPt = electron_1->GetFourMomentum().Pt() - electron_2->GetFourMomentum().Pt();

    histogramsHandler->Fill("genDielectron_deltaPhi", deltaPhi, GetWeight(event));
    histogramsHandler->Fill("genDielectron_deltaPt", deltaPt, GetWeight(event));
    histogramsHandler->Fill("genDielectron_pt", genDielectron.Pt(), GetWeight(event));

    if (GetDielectronAcoplanarity(event) < 0.01) {
      histogramsHandler->Fill("genDielectronSR_deltaPhi", deltaPhi, GetWeight(event));  
      histogramsHandler->Fill("genDielectronSR_deltaPt", deltaPt, GetWeight(event));
    }
  }
}

float LbLHistogramsFiller::GetDielectronAcoplanarity(const shared_ptr<Event> event) {
  auto electrons = event->GetCollection("goodElectron");
  if (electrons->size() != 2) return 1000;
  return GetDielectronAcoplanarity(asElectron(electrons->at(0)), asElectron(electrons->at(1)));
}

float LbLHistogramsFiller::GetDielectronAcoplanarity(const shared_ptr<Electron> &electron1, const shared_ptr<Electron> &electron2) {
  auto electron1vec = electron1->GetFourMomentum();
  auto electron2vec = electron2->GetFourMomentum();
  double deltaPhi = electron1vec.DeltaPhi(electron2vec);
  double acoplanarity = 1 - (fabs(deltaPhi) / TMath::Pi());
  return acoplanarity;
}

float LbLHistogramsFiller::GetPhiModulation(const shared_ptr<Electron> &electron1, const shared_ptr<Electron> &electron2) {
  TLorentzVector electron, positron;
  if (electron1->GetCharge() > 0) {
    positron = electron1->GetFourMomentum();
    electron = electron2->GetFourMomentum();
  } else {
    positron = electron2->GetFourMomentum();
    electron = electron1->GetFourMomentum();
  }

  // add a little random gaussian spread to pt of electron and positron
  // electron.SetPtEtaPhiM(electron.Pt() + gRandom->Gaus(0, 0.007*electron.Pt()), electron.Eta(), electron.Phi(), electron.M());
  // positron.SetPtEtaPhiM(positron.Pt() + gRandom->Gaus(0, 0.007*positron.Pt()), positron.Eta(), positron.Phi(), positron.M());

  // draw random sign (+1 or -1)
  // int sign = gRandom->Rndm() > 0.5 ? 1 : -1;
  // positron.SetPtEtaPhiM(electron.Pt() + sign * 0.01712, positron.Eta(), positron.Phi(), positron.M());

  // positron.SetPtEtaPhiM(electron.Pt() + genDielectronDeltaPt->GetRandom(), positron.Eta(), positron.Phi(), positron.M());

  TLorentzVector dielectron = electron + positron;

  float deltaPhi = fabs(dielectron.Phi() - electron.Phi());
  if (deltaPhi > TMath::Pi()) deltaPhi = 2. * TMath::Pi() - deltaPhi;
  return deltaPhi;
}

void LbLHistogramsFiller::FillElectronHistograms(const shared_ptr<Event> event) {
  auto electrons = event->GetCollection("goodElectron");

  if (electrons->size() != 2) return;

  auto electron1 = asElectron(electrons->at(0));
  auto electron2 = asElectron(electrons->at(1));
  float acoplanarity = GetDielectronAcoplanarity(electron1, electron2);
  float deltaPhi = GetPhiModulation(electron1, electron2);
  float deltaPt = fabs(electron1->GetFourMomentum().Pt() - electron2->GetFourMomentum().Pt());

  histogramsHandler->Fill("dielectron_pt", dielectron.Pt(), GetWeight(event));
  histogramsHandler->Fill("dielectron_mass", dielectron.M(), GetWeight(event));
  histogramsHandler->Fill("dielectron_rapidity", dielectron.Rapidity(), GetWeight(event));
  histogramsHandler->Fill("dielectron_acoplanarity", acoplanarity, GetWeight(event));

  histogramsHandler->Fill("dielectron_deltaPt", deltaPt, GetWeight(event));
  histogramsHandler->Fill("electrons_deltaPhi", electron1->GetFourMomentum().Phi() - electron2->GetFourMomentum().Phi(), GetWeight(event));

  float theta = electron1->GetFourMomentum().Phi() - electron2->GetFourMomentum().Phi();
  histogramsHandler->Fill("dielectron_theta", theta, GetWeight(event));

  float acoWeight = 1 / acoplanarityFunction->Eval(acoplanarity);

  histogramsHandler->Fill("dielectron_deltaPhi", deltaPhi, GetWeight(event));
  histogramsHandler->Fill("dielectron_deltaPhiAcoWeighted", deltaPhi, acoWeight * GetWeight(event));
  if ((float)electron1->Get("pt") > 6) {
    histogramsHandler->Fill("dielectron_deltaPhiPtGt6GeV", deltaPhi, GetWeight(event));
  }

  if (acoplanarity > 0.01) {
    histogramsHandler->Fill("dielectron_deltaPhi0p01", deltaPhi, GetWeight(event));
  }

  if (acoplanarity > 0.005) {
    histogramsHandler->Fill("dielectron_deltaPhi0p005", deltaPhi, GetWeight(event));
  }

  if (acoplanarity > 0.001) {
    histogramsHandler->Fill("dielectron_deltaPhi0p001", deltaPhi, GetWeight(event));
  }

  histogramsHandler->Fill("dielectron_acoplanarityAcoWeighted", acoplanarity, acoWeight * GetWeight(event));

  if (acoplanarity > 0.01) {
    histogramsHandler->Fill("dielectronSR_pt", dielectron.Pt(), GetWeight(event));
    histogramsHandler->Fill("dielectronSR_mass", dielectron.M(), GetWeight(event));
    histogramsHandler->Fill("dielectronSR_rapidity", dielectron.Rapidity(), GetWeight(event));
    histogramsHandler->Fill("dielectronSR_deltaPt", deltaPt, GetWeight(event));

    histogramsHandler->Fill("goodElectronSR_pt", electron1->Get("pt"), GetWeight(event));
    histogramsHandler->Fill("goodElectronSR_eta", electron1->Get("eta"), GetWeight(event));
    histogramsHandler->Fill("goodElectronSR_phi", electron1->Get("phi"), GetWeight(event));

    histogramsHandler->Fill("goodElectronSR_pt", electron2->Get("pt"), GetWeight(event));
    histogramsHandler->Fill("goodElectronSR_eta", electron2->Get("eta"), GetWeight(event));
    histogramsHandler->Fill("goodElectronSR_phi", electron2->Get("phi"), GetWeight(event));
  }
}

void LbLHistogramsFiller::FillEventLevelHistograms(const shared_ptr<Event> event) {
  auto lblEvent = asLbLEvent(event);
  float deltaEt = lblEvent->GetDeltaEt();
  histogramsHandler->Fill("event_deltaEt", deltaEt, GetWeight(event));

  auto photons = event->GetCollection("goodPhoton");

  if (photons->size() == 2) {
    double deltaPhi = asPhoton(photons->at(0))->GetFourMomentum().DeltaPhi(asPhoton(photons->at(1))->GetFourMomentum());
    double acoplanarity = 1 - (fabs(deltaPhi) / TMath::Pi());
    float cosThetaStar = fabs(lblEvent->GetCosThetaStar(false));

    histogramsHandler->Fill("event_cosThetaStar", cosThetaStar, GetWeight(event));

    if (acoplanarity < 0.01) {
      histogramsHandler->Fill("eventSR3_cosThetaStar", cosThetaStar, GetWeight(event));
      histogramsHandler->Fill("eventSR4_cosThetaStar", cosThetaStar, GetWeight(event));
      histogramsHandler->Fill("eventSR5_cosThetaStar", cosThetaStar, GetWeight(event));
      histogramsHandler->Fill("eventSR10_cosThetaStar", cosThetaStar, GetWeight(event));

      histogramsHandler->Fill("unfoldingPhoton_costhetastar2", cosThetaStar, GetWeight(event));
      histogramsHandler->Fill("unfoldingPhoton_costhetastar3", cosThetaStar, GetWeight(event));
      histogramsHandler->Fill("unfoldingPhoton_costhetastar4", cosThetaStar, GetWeight(event));
    }
  }

  auto electrons = event->GetCollection("goodElectron");
  if (electrons->size() == 2) {
    double deltaPhi = asElectron(electrons->at(0))->GetFourMomentum().DeltaPhi(asElectron(electrons->at(1))->GetFourMomentum());
    double acoplanarity = 1 - (fabs(deltaPhi) / TMath::Pi());
    float cosThetaStar = fabs(asLbLEvent(event)->GetCosThetaStar(true));

    histogramsHandler->Fill("event_electronsCosThetaStar", cosThetaStar, GetWeight(event));

    if (acoplanarity < 0.01) {
      histogramsHandler->Fill("eventSR_electronsCosThetaStar", cosThetaStar, GetWeight(event));
    }
  }

  try {
    auto zdcEnergies = event->GetCollection("ZDC");

    float totalEnergyPlus = 0;
    float totalEnergyMinus = 0;

    for (auto physicsObject : *zdcEnergies) {
      auto zdcEnergy = asZDCEnergy(physicsObject);

      if (zdcEnergy->GetSide() > 0) {
        totalEnergyPlus += zdcEnergy->GetEnergy();
      } else if (zdcEnergy->GetSide() < 0) {
        totalEnergyMinus += zdcEnergy->GetEnergy();
      }
    }
    histogramsHandler->Fill("event_ZDCenergyPlus", totalEnergyPlus, GetWeight(event));
    histogramsHandler->Fill("event_ZDCenergyMinus", totalEnergyMinus, GetWeight(event));
  } catch (const Exception &e) {
    warn() << "Cannot fill ZDC histograms, since ZDC collection was not found." << endl;
  }
}

void LbLHistogramsFiller::Fill(const shared_ptr<Event> event) {
  // if (!(int)event->Get("DoubleEG2")) return;


  auto electrons = event->GetCollection("goodElectron");
  if (electrons->size() == 2) {
    auto electron_1 = asElectron(electrons->at(0));
    auto electron_2 = asElectron(electrons->at(1));
    dielectron = electron_1->GetFourMomentum() + electron_2->GetFourMomentum();
  }
  auto genElectrons = event->GetCollection("genElectron");
  if (genElectrons->size() == 2) {
    auto electron_1 = asElectron(genElectrons->at(0));
    auto electron_2 = asElectron(genElectrons->at(1));
    genDielectron = electron_1->GetFourMomentum() + electron_2->GetFourMomentum();
  }

  FillCaloHistograms(event);
  FillPhotonHistograms(event);
  FillThreePhotonHistograms(event);
  FillElectronHistograms(event);
  FillEventLevelHistograms(event);
  FillGenLevelHistograms(event);
}
