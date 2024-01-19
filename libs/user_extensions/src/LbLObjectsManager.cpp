#include "LbLObjectsManager.hpp"

#include "ConfigManager.hpp"
#include "Logger.hpp"

using namespace std;

bool LbLObjectsManager::IsGoodPhoton(const shared_ptr<PhysicsObject> photon) {
  if ((float)photon->Get("et") < 2.5) return false;

  float absEta = fabs((float)photon->Get("eta"));
  if (absEta > 2.2) return false;

  // Check the crack
  float absEtaSC = fabs((float)photon->Get("SCEta"));
  if (absEtaSC > 1.4442 && absEtaSC < 1.566) return false;

  // Shower shape, H/E
  if (absEta < 1.479) {  // barrel
    if ((float)photon->Get("SCEtaWidth") > 0.0106) return false;
    if ((float)photon->Get("hOverE") > 0.04596) return false;
    if ((float)photon->Get("sigmaIEtaIEta2012") > 0.02) return false;
  } else if (absEta < 2.2) {  // endcap
    if ((float)photon->Get("SCEtaWidth") > 0.0272) return false;
    if ((float)photon->Get("hOverE") > 0.0590) return false;
    if ((float)photon->Get("sigmaIEtaIEta2012") > 0.06) return false;
  } else{
    return false;
  }

  // Check swiss cross
  float swissCross = 0;
  swissCross += (float)photon->Get("energyTop");
  swissCross += (float)photon->Get("energyBottom");
  swissCross += (float)photon->Get("energyLeft");
  swissCross += (float)photon->Get("energyRight");
  swissCross /= (float)photon->Get("maxEnergyCrystal");
  swissCross = 1 - swissCross;

  if (swissCross > 1) {
    warn() << "Swiss cross cannot be calculated. The event will pass this selection automatically" << endl;
  } else if (swissCross >= 0.95) {
    return false;
  }

  if ((int)photon->Get("hasConversionTracks")) return false;
  if (fabs((float)photon->Get("seedTime") > 3.0)) return false;

  // check HEM
  float etaSC = photon->Get("SCEta");
  float phiSC = photon->Get("SCPhi");
  if (etaSC > -2.2 && etaSC < -1.39 && phiSC > -1.6 && phiSC < -0.9) return false;

  return true;
}

bool LbLObjectsManager::IsGoodElectron(const std::shared_ptr<PhysicsObject> electron) {
  if ((float)electron->Get("pt") <= 2.0) return false;

  float absEtaSC = fabs((float)electron->Get("SCEta"));

  // Check eta and crack
  if (absEtaSC > 1.4442 && absEtaSC < 1.566) return false;
  if (absEtaSC > 2.2) return false;

  // Check for HEM issue
  float etaSC = electron->Get("SCEta");
  float phiSC = electron->Get("SCPhi");
  if (etaSC > -2.4 && etaSC < -1.39 && phiSC > -1.6 && phiSC < -0.9) return false;

  // Check other parameters
  if ((int)electron->Get("nMissHits") > 1) return false;
  if ((float)electron->Get("hOverE") > 0.005) return false;
  if (abs((float)electron->Get("deltaEtaAtVertex")) > 0.1) return false;

  // Check isolation
  if (absEtaSC < 1.479) {  // barrel
    if ((float)electron->Get("PFChIso") > 99999) return false;
    if ((float)electron->Get("PFPhoIso") > 99999) return false;
    if ((float)electron->Get("PFNeuIso") > 99999) return false;
  } else if (absEtaSC < 3.0) {  // endcap
    if ((float)electron->Get("PFChIso") > 99999) return false;
    if ((float)electron->Get("PFPhoIso") > 99999) return false;
    if ((float)electron->Get("PFNeuIso") > 99999) return false;
  }
  return true;
}

bool LbLObjectsManager::IsGoodTrack(const std::shared_ptr<PhysicsObject> track) {
  if ((float)track->Get("pt") < 0.3) return false;
  if (fabs((float)track->Get("eta")) > 2.4) return false;
  if ((int)track->Get("nValidHits") < 4) return false;
  
  // if ((float)track->Get("normalizedChi2") > 999999) return false;
  // if (fabs((float)track->Get("dxy")) > 999999) return false;
  // if (fabs((float)track->Get("dxy") / track->Get("dxyError")) > 999999) return false;
  // if (fabs((float)track->Get("dz")) > 999999) return false;
  // if (fabs((float)track->Get("dz") / track->Get("dzError")) > 999999) return false;

  return true;
}

void LbLObjectsManager::InsertGoodPhotonsCollection(shared_ptr<Event> event) {
  auto photons = event->GetCollection("photon");
  auto goodPhotons = make_shared<PhysicsObjects>();

  for (auto photon : *photons) {
    if (!IsGoodPhoton(photon)) continue;
    goodPhotons->push_back(photon);
  }

  event->AddCollection("goodPhoton", goodPhotons);
}

void LbLObjectsManager::InsertGoodElectronsCollection(shared_ptr<Event> event) {
  auto electrons = event->GetCollection("electron");
  auto goodElectrons = make_shared<PhysicsObjects>();

  for (auto electron : *electrons) {
    if (!IsGoodElectron(electron)) continue;
    goodElectrons->push_back(electron);
  }

  event->AddCollection("goodElectron", goodElectrons);
}

void LbLObjectsManager::InsertGoodTracksCollection(shared_ptr<Event> event) {
  auto tracks = event->GetCollection("track");
  auto goodTracks = make_shared<PhysicsObjects>();

  for (auto track : *tracks) {
    if (!IsGoodTrack(track)) continue;
    goodTracks->push_back(track);
  }

  event->AddCollection("goodTrack", goodTracks);
}
