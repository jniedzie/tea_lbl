#include "LbLObjectsManager.hpp"

#include "ConfigManager.hpp"
#include "Logger.hpp"

using namespace std;

LbLObjectsManager::LbLObjectsManager() {
  auto &config = ConfigManager::GetInstance();
  config.GetMap("detectorParams", detectorParams);
  config.GetMap("caloEtaEdges", caloEtaEdges);
}

bool LbLObjectsManager::IsGoodPhoton(const shared_ptr<Photon> photon) {
  if (!photon->PassesConversionCuts()) return false;
  if (!photon->PassesEtCuts()) return false;
  if (!photon->PassesSwissCross()) return false;

  if (photon->IsEtaAboveLimit()) return false;
  if (photon->IsInCrack()) return false;
  if (photon->IsInHEM()) return false;

  if (!photon->PassesShowerShape()) return false;
  if (!photon->PassesHoverE()) return false;
  if (!photon->PassesSeedTimeCuts()) return false;

  return true;
}

bool LbLObjectsManager::IsGoodElectron(const std::shared_ptr<PhysicsObject> physicsObject) {
  auto electron = asElectron(physicsObject);

  if (!electron->PassesPtCuts()) return false;

  if (electron->IsInCrack()) return false;
  if (electron->IsEtaAboveLimit()) return false;
  if (electron->IsInHEM()) return false;

  if (!electron->PassesMissingHitsCuts()) return false;
  if (!electron->PassesHoverE()) return false;
  if (!electron->PassesDeltaEtaAtVertex()) return false;
  if (!electron->PassesIsolationCuts()) return false;

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

  for (auto physicsObject : *photons) {
    auto photon = asPhoton(physicsObject);
    if (!IsGoodPhoton(photon)) continue;
    goodPhotons->push_back(physicsObject);
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
