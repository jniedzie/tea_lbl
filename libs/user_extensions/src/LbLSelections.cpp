#include "LbLSelections.hpp"

#include "ConfigManager.hpp"
#include "Logger.hpp"

using namespace std;

LbLSelections::LbLSelections() {
  etaEdges = {0.000, 0.087, 0.174, 0.261, 0.348, 0.435, 0.522, 0.609, 0.696, 0.783, 0.870, 0.957, 1.044, 1.131,
              1.218, 1.305, 1.392, 1.479, 1.566, 1.653, 1.740, 1.830, 1.930, 2.043, 2.172, 2.322, 2.500, 2.650,
              2.853, 3.000, 3.139, 3.314, 3.489, 3.664, 3.839, 4.013, 4.191, 4.363, 4.538, 4.716, 4.889, 5.191};
}

void LbLSelections::InsertGoodPhotonsCollection(std::shared_ptr<Event> event) {
  auto &config = ConfigManager::GetInstance();

  auto photons = event->GetCollection("photon");
  auto goodPhotons = make_shared<PhysicsObjects>();

  for (auto photon : *photons) {
    if ((float)photon->Get("et") < 2.5) continue;

    float absEta = fabs((float)photon->Get("eta"));
    if (absEta > 2.2) continue;

    // Check the crack
    float absEtaSC = fabs((float)photon->Get("SCEta"));
    if (absEtaSC > 1.4442 && absEtaSC < 1.566) continue;

    // // Check η shower shape
    if (absEta < 1.479 && (float)photon->Get("SCEtaWidth") > 0.0106)
      continue;
    else if (absEta < 3.0 && (float)photon->Get("SCEtaWidth") > 0.0272)
      continue;

    // Check H/E
    if (absEta < 1.479 && (float)photon->Get("hOverE") > 0.04596)
      continue;
    else if (absEta < 3.0 && (float)photon->Get("hOverE") > 0.0590)
      continue;

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
    } else if (swissCross >= 0.95)
      continue;

    // Check for conversions
    if ((int)photon->Get("hasConversionTracks")) continue;

    // Check sigma ietaieta
    if (absEta < 1.479 && (float)photon->Get("sigmaIEtaIEta2012") > 0.02)
      continue;
    else if (absEta < 3.0 && (float)photon->Get("sigmaIEtaIEta2012") > 0.06)
      continue;

    // Check seed time
    if (fabs((float)photon->Get("seedTime") > 3.0)) continue;

    // check HEM
    float etaSC = photon->Get("SCEta");
    float phiSC = photon->Get("SCPhi");
    if (etaSC > -2.4 && etaSC < -1.39 && phiSC > -1.6 && phiSC < -0.9) continue;

    goodPhotons->push_back(photon);
  }

  event->AddCollection("goodPhoton", goodPhotons);
}

void LbLSelections::InsertGoodElectronsCollection(std::shared_ptr<Event> event) {
  auto &config = ConfigManager::GetInstance();

  auto electrons = event->GetCollection("electron");
  auto goodElectrons = make_shared<PhysicsObjects>();

  for (auto electron : *electrons) {
    if ((float)electron->Get("pt") <= 2.0) continue;

    float absEta = fabs((float)electron->Get("eta"));
    if (absEta > 2.2) continue;

    // Check the crack
    float absEtaSC = fabs((float)electron->Get("SCEta"));
    if (absEtaSC > 1.4442 && absEtaSC < 1.566) continue;

    // Check missing hits
    if ((int)electron->Get("nMissHits") > 1) continue;

    // Check delta eta at vertex
    if (abs((float)electron->Get("deltaEtaAtVertex")) >= 0.1) continue;

    // Check H/E
    if ((float)electron->Get("hOverE") > 0.005) continue;

    // check HEM
    float etaSC = electron->Get("SCEta");
    float phiSC = electron->Get("SCPhi");
    if (etaSC > -2.4 && etaSC < -1.39 && phiSC > -1.6 && phiSC < -0.9) continue;

    goodElectrons->push_back(electron);
  }

  event->AddCollection("goodElectron", goodElectrons);
}

int LbLSelections::EtaToIeta(float eta) {
  int iEta = 1;
  float absEta = fabs(eta);

  while (absEta > etaEdges[iEta] && iEta < etaEdges.size() - 1) iEta++;
  if (eta < 0) iEta = -iEta;

  return iEta;
}

bool LbLSelections::IsAnyTowerAlive(shared_ptr<PhysicsObjects> towers, vector<int> deadEtas) {
  for (auto tower : *towers) {
    int ieta = EtaToIeta((float)tower->Get("eta"));
    if (find(deadEtas.begin(), deadEtas.end(), ieta) != deadEtas.end()) continue;
    return true;
  }
  return false;
}

bool LbLSelections::IsAnyECalTowerGood(string towersCollectionName, shared_ptr<Event> event, float maxDeltaEta, float maxDeltaPhi) {
  auto towers = event->GetCollection(towersCollectionName);

  for (auto tower : *towers) {
    if (OverlapsWithOtherObjects(tower, event->GetCollection("goodPhoton"), 0.15, 0.4)) continue;
    if (OverlapsWithOtherObjects(tower, event->GetCollection("goodElectron"), 0.15, 0.4)) continue;

    // Check HEM
    float etaSC = tower->Get("eta");
    float phiSC = tower->Get("phi");
    if (etaSC > -2.4 && etaSC < -1.39 && phiSC > -1.6 && phiSC < -0.9) continue;

    return true;
  }
  return false;
}

bool LbLSelections::HasAdditionalTowers(shared_ptr<Event> event, shared_ptr<CutFlowManager> cutFlowManager) {
  if (event->GetCollection("PassingHBtower")->size() != 0) return true;
  cutFlowManager->UpdateCutFlow("HBtowers");

  if (IsAnyTowerAlive(event->GetCollection("PassingHEtowerPlus"), {16})) return true;
  if (IsAnyTowerAlive(event->GetCollection("PassingHEtowerMinus"), {-16})) return true;
  cutFlowManager->UpdateCutFlow("HEtowers");

  if (IsAnyTowerAlive(event->GetCollection("PassingHFtowerPlus"), {29, 30})) return true;
  if (IsAnyTowerAlive(event->GetCollection("PassingHFtowerMinus"), {-29, -30})) return true;
  cutFlowManager->UpdateCutFlow("HFtowers");

  if (IsAnyECalTowerGood("PassingEBtower", event, 0.15, 0.7)) return true;
  cutFlowManager->UpdateCutFlow("EBtowers");

  if (IsAnyECalTowerGood("PassingEEtowerPlus", event, 0.15, 0.4)) return true;
  if (IsAnyECalTowerGood("PassingEEtowerMinus", event, 0.15, 0.4)) return true;
  cutFlowManager->UpdateCutFlow("EEtowers");

  return false;
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