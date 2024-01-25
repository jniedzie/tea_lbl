#include "LbLSelections.hpp"

#include "ConfigManager.hpp"
#include "Logger.hpp"
#include "UserExtensionsHelpers.hpp"

using namespace std;

LbLSelections::LbLSelections() {
  auto &config = ConfigManager::GetInstance();
  config.GetMap("eventCuts", eventCuts);
}

bool LbLSelections::PassesNeutralExclusivity(shared_ptr<Event> event, shared_ptr<CutFlowManager> cutFlowManager) {
  auto towers = event->GetCollection("CaloTower");
  int nPassingTowers = 0;

  for (auto physicsObject : *towers) {
    auto tower = asCaloTower(physicsObject);
    if (tower->IsDead()) continue;
    if (tower->IsHadronicEnergyAboveNoiseThreshold() /* && !tower->IsInHadronicCrack()*/) {
      nPassingTowers++;
      if (nPassingTowers > eventCuts["max_Ntowers"]) return false;
    } else {
      if (tower->IsEtaAboveLimit()) continue;
      if (tower->IsInHEM()) continue;
      // if (tower->IsInElectromagneticCrack()) continue;
      if (tower->OverlapsWithOtherObjects(event->GetCollection("goodPhoton"))) continue;
      if (tower->OverlapsWithOtherObjects(event->GetCollection("goodElectron"))) continue;
      if (tower->IsElectromagneticEnergyAboveNoiseThreshold()) nPassingTowers++;
      if (nPassingTowers > eventCuts["max_Ntowers"]) return false;
    }
  }
  if (nPassingTowers > eventCuts["max_Ntowers"]) return false;

  cutFlowManager->UpdateCutFlow("neutralExclusivity");

  return true;
}

bool LbLSelections::PassesDiphotonSelection(shared_ptr<Event> event, shared_ptr<CutFlowManager> cutFlowManager) {
  int nPhotons = event->GetCollection("goodPhoton")->size();
  if (nPhotons < eventCuts["min_Nphotons"] || nPhotons > eventCuts["max_Nphotons"]) return false;

  cutFlowManager->UpdateCutFlow("twoGoodPhotons");

  auto photon1 = event->GetCollection("goodPhoton")->at(0);
  auto photon2 = event->GetCollection("goodPhoton")->at(1);
  TLorentzVector photon1vec, photon2vec;
  photon1vec.SetPtEtaPhiM(photon1->Get("et"), photon1->Get("eta"), photon1->Get("phi"), 0);
  photon2vec.SetPtEtaPhiM(photon2->Get("et"), photon2->Get("eta"), photon2->Get("phi"), 0);

  auto diphoton = photon1vec + photon2vec;
  if (diphoton.M() < eventCuts["min_diphotonMass"]) return false;
  cutFlowManager->UpdateCutFlow("diphotonMass");

  return true;
}

bool LbLSelections::PassesChargedExclusivity(shared_ptr<Event> event, shared_ptr<CutFlowManager> cutFlowManager) {
  int nElectrons = event->GetCollection("goodElectron")->size();
  if (nElectrons > eventCuts["max_Nelectrons"]) return false;
  cutFlowManager->UpdateCutFlow("nElectrons");

  int nTracks = event->GetCollection("goodTrack")->size();
  if (nTracks > eventCuts["max_Ntracks"]) return false;
  cutFlowManager->UpdateCutFlow("nTracks");

  int nMuons = event->GetCollection("goodMuon")->size();
  if (nMuons > eventCuts["max_Nmuons"]) return false;
  cutFlowManager->UpdateCutFlow("nMuons");

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
  if (diphoton.Pt() > eventCuts["max_diphotonPt"]) return false;
  cutFlowManager->UpdateCutFlow("diphotonPt");

  return true;
}

bool LbLSelections::PassesZDC(shared_ptr<Event> event, shared_ptr<CutFlowManager> cutFlowManager) {
  shared_ptr<PhysicsObjects> zdcEnergies;

  try {
    zdcEnergies = event->GetCollection("ZDC");
  } catch (Exception &e) {
    warn() << "No ZDC collection found in event. Will skip ZDC cuts." << endl;
    cutFlowManager->UpdateCutFlow("ZDC");
    return true;
  }

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

  if (totalEnergyPlus > eventCuts["max_ZDCenergyPerSide"] || totalEnergyMinus > eventCuts["max_ZDCenergyPerSide"]) return false;
  cutFlowManager->UpdateCutFlow("ZDC");

  return true;
}