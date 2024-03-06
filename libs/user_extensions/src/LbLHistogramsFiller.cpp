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

  // Create an event processor
  eventProcessor = make_unique<EventProcessor>();
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
  auto towers = event->GetCollection("CaloTower");

  float maxEnergy = 0;
  shared_ptr<PhysicsObject> leadingTower;

  for (auto physicsObject : *towers) {
    float eta = fabs((float)physicsObject->Get("eta"));
    if (eta < 1.305 || eta > 3.0) continue;

    float energy = physicsObject->Get("et");
    if (energy > maxEnergy) {
      maxEnergy = energy;
      leadingTower = physicsObject;
    }
  }

  auto tower = asCaloTower(leadingTower);
  float hadEnergy = tower->Get("hadE");
  float energy = tower->Get("energy");
  float transverseEnergy = tower->Get("et");

  if (hadEnergy > 0) {
    histogramsHandler->Fill("caloTowerHE_energyHad", hadEnergy, GetWeight(event));
    histogramsHandler->Fill("caloTowerHE_energyTransverse", transverseEnergy, GetWeight(event));
    histogramsHandler->Fill("caloTowerHE_energy", energy, GetWeight(event));
    if (!tower->IsDead() && !tower->IsInHadronicCrack() && !tower->IsInHEM()) {
      histogramsHandler->Fill("goodCaloTowerHE_energyHad", hadEnergy, GetWeight(event));
      histogramsHandler->Fill("goodCaloTowerHE_energyTransverse", transverseEnergy, GetWeight(event));
      histogramsHandler->Fill("goodCaloTowerHE_energy", energy, GetWeight(event));
    }
  }
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

    auto [deltaPhi, mod] = GetPhiModulation(electron_1, electron_2);
    float deltaPt = fabs(electron_1->GetFourMomentum().Pt() - electron_2->GetFourMomentum().Pt());

    histogramsHandler->Fill("genDielectron_deltaPhi", deltaPhi, mod * GetWeight(event));
    histogramsHandler->Fill("genDielectron_deltaPt", deltaPt, GetWeight(event));

    if (GetDielectronAcoplanarity(event) < 0.01) {
      histogramsHandler->Fill("genDielectronSR_deltaPhi", deltaPhi, mod * GetWeight(event));
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

pair<float, float> LbLHistogramsFiller::GetPhiModulation(const shared_ptr<Electron> &electron1, const shared_ptr<Electron> &electron2) {
  TLorentzVector electron, positron;
  if (electron1->GetCharge() > 0) {
    positron = electron1->GetFourMomentum();
    electron = electron2->GetFourMomentum();
  } else {
    positron = electron2->GetFourMomentum();
    electron = electron1->GetFourMomentum();
  }

  TLorentzVector dielectron = electron + positron;
  TLorentzVector eleDiff = electron - positron;

  // Calculate delta phi
  // float deltaPhi = dielectron.Phi() - electron.Phi();
  float deltaPhi = fabs(dielectron.Phi() - electron.Phi());
  // float deltaPhi = fabs(dielectron.Phi() - eleDiff.Phi());

  if (deltaPhi > TMath::Pi()) deltaPhi = 2. * TMath::Pi() - deltaPhi;

  // bring delta phi between -pi and pi
  // if (deltaPhi > TMath::Pi()) deltaPhi = deltaPhi - 2. * TMath::Pi();
  // if (deltaPhi <= -TMath::Pi()) deltaPhi = deltaPhi + 2. * TMath::Pi();

  // // // Take the absolute value
  // deltaPhi = fabs(deltaPhi);

  // float mag = 1/fabs(deltaPhi/TMath::Pi()-0.5);
  float mag = 1;

  // info() << "deltaPhi: " << deltaPhi << " mag: " << mag << endl;

  return {deltaPhi, mag};
}

void LbLHistogramsFiller::FillElectronHistograms(const shared_ptr<Event> event) {
  auto electrons = event->GetCollection("goodElectron");

  if (electrons->size() != 2) return;

  auto electron1 = asElectron(electrons->at(0));
  auto electron2 = asElectron(electrons->at(1));
  float acoplanarity = GetDielectronAcoplanarity(electron1, electron2);
  auto [deltaPhi, mag] = GetPhiModulation(electron1, electron2);
  TLorentzVector dielectron = electron1->GetFourMomentum() + electron2->GetFourMomentum();
  float deltaPt = fabs(electron1->GetFourMomentum().Pt() - electron2->GetFourMomentum().Pt());

  histogramsHandler->Fill("dielectron_pt", dielectron.Pt(), GetWeight(event));
  histogramsHandler->Fill("dielectron_mass", dielectron.M(), GetWeight(event));
  histogramsHandler->Fill("dielectron_rapidity", dielectron.Rapidity(), GetWeight(event));
  histogramsHandler->Fill("dielectron_acoplanarity", acoplanarity, GetWeight(event));
  histogramsHandler->Fill("dielectron_deltaPhi", deltaPhi, mag * GetWeight(event));
  histogramsHandler->Fill("dielectron_deltaPt", deltaPt, GetWeight(event));

  if (acoplanarity > 0.01) {
    histogramsHandler->Fill("dielectronSR_pt", dielectron.Pt(), GetWeight(event));
    histogramsHandler->Fill("dielectronSR_mass", dielectron.M(), GetWeight(event));
    histogramsHandler->Fill("dielectronSR_rapidity", dielectron.Rapidity(), GetWeight(event));
    histogramsHandler->Fill("dielectronSR_deltaPhi", deltaPhi, mag * GetWeight(event));
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

  float cosThetaStar = fabs(lblEvent->GetCosThetaStar());
  histogramsHandler->Fill("event_cosThetaStar", cosThetaStar, GetWeight(event));

  auto photons = event->GetCollection("goodPhoton");
  if (photons->size() != 2) return;
  double deltaPhi = asPhoton(photons->at(0))->GetFourMomentum().DeltaPhi(asPhoton(photons->at(1))->GetFourMomentum());
  double acoplanarity = 1 - (fabs(deltaPhi) / TMath::Pi());

  if (acoplanarity < 0.01) {
    histogramsHandler->Fill("eventSR3_cosThetaStar", cosThetaStar, GetWeight(event));
    histogramsHandler->Fill("eventSR4_cosThetaStar", cosThetaStar, GetWeight(event));
    histogramsHandler->Fill("eventSR5_cosThetaStar", cosThetaStar, GetWeight(event));
    histogramsHandler->Fill("eventSR10_cosThetaStar", cosThetaStar, GetWeight(event));
  }
}

void LbLHistogramsFiller::Fill(const shared_ptr<Event> event) {
  FillCaloHistograms(event);
  FillPhotonHistograms(event);
  FillElectronHistograms(event);
  FillEventLevelHistograms(event);
  FillGenLevelHistograms(event);
}
