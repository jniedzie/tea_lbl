#include "LbLSelections.hpp"

#include "ConfigManager.hpp"
#include "Logger.hpp"
#include "UserExtensionsHelpers.hpp"

using namespace std;

bool LbLSelections::PassesNeutralExclusivity(shared_ptr<Event> event, shared_ptr<CutFlowManager> cutFlowManager) {
  auto towers = event->GetCollection("CaloTower");

  for (auto physicsObject : *towers) {
    auto tower = asCaloTower(physicsObject);
    if (tower->IsDead()) continue;

    if (tower->IsHadronicEnergyAboveNoiseThreshold()) return false;

    if (tower->IsEtaAboveLimit()) continue;
    if (tower->IsInHEM()) continue;
    if (tower->OverlapsWithOtherObjects(event->GetCollection("goodPhoton"))) continue;
    if (tower->OverlapsWithOtherObjects(event->GetCollection("goodElectron"))) continue;

    if (tower->IsElectromagneticEnergyAboveNoiseThreshold()) return false;
  }
  cutFlowManager->UpdateCutFlow("neutralExclusivity");

  return true;
}

bool LbLSelections::OverlapsWithOtherObjects(shared_ptr<PhysicsObject> physicsObject, shared_ptr<PhysicsObjects> otherObjects,
                                             float maxDeltaEta, float maxDeltaPhi) {
  float eta = physicsObject->Get("eta");
  float phi = physicsObject->Get("phi");

  for (auto otherObject : *otherObjects) {
    float deltaEta = fabs((float)otherObject->Get("SCEta") - eta);
    float deltaPhi = fabs(TVector2::Phi_mpi_pi((float)otherObject->Get("SCPhi") - phi));
    if (deltaEta < maxDeltaEta && deltaPhi < maxDeltaPhi) return true;
  }
  return false;
}

bool LbLSelections::PassesDiphotonSelection(shared_ptr<Event> event, shared_ptr<CutFlowManager> cutFlowManager) {
  if (event->GetCollection("goodPhoton")->size() != 2) return false;
  cutFlowManager->UpdateCutFlow("twoGoodPhotons");

  auto photon1 = event->GetCollection("goodPhoton")->at(0);
  auto photon2 = event->GetCollection("goodPhoton")->at(1);
  TLorentzVector photon1vec, photon2vec;
  photon1vec.SetPtEtaPhiM(photon1->Get("et"), photon1->Get("eta"), photon1->Get("phi"), 0);
  photon2vec.SetPtEtaPhiM(photon2->Get("et"), photon2->Get("eta"), photon2->Get("phi"), 0);

  auto diphoton = photon1vec + photon2vec;
  if (diphoton.M() < 5) return false;
  cutFlowManager->UpdateCutFlow("diphotonMass");

  return true;
}

bool LbLSelections::PassesChargedExclusivity(shared_ptr<Event> event, shared_ptr<CutFlowManager> cutFlowManager) {
  int nElectrons = event->GetCollection("goodElectron")->size();
  if (nElectrons > 0) return false;
  cutFlowManager->UpdateCutFlow("nElectrons");

  int nTracks = event->GetCollection("goodTrack")->size();
  if (nTracks > 0) return false;
  cutFlowManager->UpdateCutFlow("nTracks");

  return true;
}

bool LbLSelections::PassesDiphotonPt(shared_ptr<Event> event, shared_ptr<CutFlowManager> cutFlowManager) {
  if (event->GetCollection("goodPhoton")->size() != 2) return false;

  auto photon1 = event->GetCollection("goodPhoton")->at(0);
  auto photon2 = event->GetCollection("goodPhoton")->at(1);
  TLorentzVector photon1vec, photon2vec;
  photon1vec.SetPtEtaPhiM(photon1->Get("et"), photon1->Get("eta"), photon1->Get("phi"), 0);
  photon2vec.SetPtEtaPhiM(photon2->Get("et"), photon2->Get("eta"), photon2->Get("phi"), 0);

  auto diphoton = photon1vec + photon2vec;
  if (diphoton.Pt() > 1) return false;
  cutFlowManager->UpdateCutFlow("diphotonPt");

  return true;
}