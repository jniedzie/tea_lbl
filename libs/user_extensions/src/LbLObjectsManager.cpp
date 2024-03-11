#include "LbLObjectsManager.hpp"

#include "ConfigManager.hpp"
#include "Logger.hpp"

using namespace std;

LbLObjectsManager::LbLObjectsManager() {
  auto& config = ConfigManager::GetInstance();
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

bool LbLObjectsManager::IsGoodElectron(const shared_ptr<Electron> electron) {
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

bool LbLObjectsManager::IsGoodTrack(const shared_ptr<Track> track) {
  if (!track->PassesPtCuts()) return false;
  if (track->IsEtaAboveLimit()) return false;
  if (!track->PassesValidHitsCuts()) return false;
  if (!track->PassesChi2Cuts()) return false;
  if (!track->PassesDistanceToPVCuts()) return false;

  return true;
}

bool LbLObjectsManager::IsGoodMuon(const shared_ptr<Muon> muon) {
  if (!muon->PassesPtCuts()) return false;
  if (muon->IsEtaAboveLimit()) return false;

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

  for (auto physicsObject : *electrons) {
    auto electron = asElectron(physicsObject);
    if (!IsGoodElectron(electron)) continue;
    goodElectrons->push_back(physicsObject);
  }

  event->AddCollection("goodElectron", goodElectrons);
}

void LbLObjectsManager::InsertGoodTracksCollection(shared_ptr<Event> event) {
  auto tracks = event->GetCollection("track");
  auto goodTracks = make_shared<PhysicsObjects>();

  for (auto physicsObject : *tracks) {
    auto track = asTrack(physicsObject);
    if (!IsGoodTrack(track)) continue;
    goodTracks->push_back(physicsObject);
  }

  event->AddCollection("goodTrack", goodTracks);
}

void LbLObjectsManager::InsertGoodMuonsCollection(shared_ptr<Event> event) {
  auto muons = event->GetCollection("muon");
  auto goodMuons = make_shared<PhysicsObjects>();

  for (auto physicsObject : *muons) {
    auto muon = asMuon(physicsObject);
    if (!IsGoodMuon(muon)) continue;
    goodMuons->push_back(physicsObject);
  }

  event->AddCollection("goodMuon", goodMuons);
}

void LbLObjectsManager::InsertGenPhotonsCollection(shared_ptr<Event> event) {
  auto genParticles = event->GetCollection("genParticle");
  auto genPhotons = GetGenParticles(event, 22);
  event->AddCollection("genPhoton", genPhotons);
}

void LbLObjectsManager::InsertGenElectronsCollection(shared_ptr<Event> event) {
  auto genParticles = event->GetCollection("genParticle");
  auto genPhotons = GetGenParticles(event, 11);
  event->AddCollection("genElectron", genPhotons);
}

shared_ptr<PhysicsObjects> LbLObjectsManager::GetGenParticles(const shared_ptr<Event> event, int pid) {
  auto mcParticles = event->GetCollection("genParticle");
  auto genParticles = make_shared<PhysicsObjects>();

  for (auto particle : *mcParticles) {
    int particlePid = GetParticlePid(particle);
    if (abs(particlePid) == pid) genParticles->push_back(particle);
  }
  return genParticles;
}

int LbLObjectsManager::GetParticlePid(const shared_ptr<PhysicsObject> particle) {
  int particlePid = particle->Get("pid");

  // this is a hack needed because pid was stored as float in the tree
  // float *floatPtr = reinterpret_cast<float *>(&particlePid);
  // float floatValue = *floatPtr;
  // particlePid = round(floatValue);

  return particlePid;
}