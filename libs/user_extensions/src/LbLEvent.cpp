#include "LbLEvent.hpp"

#include "ExtensionsHelpers.hpp"
#include "UserExtensionsHelpers.hpp"

using namespace std;

float LbLEvent::GetDeltaEt() {
  auto photons = GetCollection("goodPhoton");

  if (photons->size() != 2) {
    warn() << "Couldn't calculate deltaEt -- number of photons in the event != 2" << endl;
    return -1;
  }

  auto towers = GetCollection("CaloTower");

  auto photon1 = photons->at(0);
  auto photon2 = photons->at(1);

  float photon1Et = photon1->Get("et");
  float photon2Et = photon2->Get("et");

  float photon1Phi = photon1->Get("phi");
  float photon2Phi = photon2->Get("phi");

  float photon1Eta = photon1->Get("eta");
  float photon2Eta = photon2->Get("eta");

  float maxDeltaR = 1.5;
  float highestTowerEt1 = 0;
  float highestTowerEt2 = 0;

  for (auto physicsObject : *towers) {
    auto tower = asCaloTower(physicsObject);
    if (tower->IsDead()) continue;
    if (tower->IsEtaAboveLimit()) continue;
    if (tower->IsInHEM()) continue;
    if (tower->IsInElectromagneticCrack()) continue;

    float phi = tower->Get("phi");
    float eta = tower->Get("eta");
    float et = tower->Get("et");

    if (sqrt(pow(phi - photon1Phi, 2) + pow(eta - photon1Eta, 2)) < maxDeltaR) {
      if (et > highestTowerEt1) highestTowerEt1 = et;
    }
    if (sqrt(pow(phi - photon2Phi, 2) + pow(eta - photon2Eta, 2)) < maxDeltaR) {
      if (et > highestTowerEt2) highestTowerEt2 = et;
    }
  }

  float deltaEt1 = fabs(photon1Et - highestTowerEt1) / photon1Et;
  float deltaEt2 = fabs(photon2Et - highestTowerEt2) / photon2Et;

  float maxDelta = max(deltaEt1, deltaEt2);
  return maxDelta;
}

float LbLEvent::GetCosThetaStar(bool doElectrons) {
  auto objects = GetCollection(doElectrons ? "goodElectron" : "goodPhoton");

  if (objects->size() != 2) {
    warn() << "Couldn't calculate cosThetaStar -- number of objects in the event != 2" << endl;
    return -1;
  }

  TLorentzVector object1, object2;

  if (doElectrons) {
    object1 = asElectron(objects->at(0))->GetFourMomentum();
    object2 = asElectron(objects->at(1))->GetFourMomentum();
  } else {
    object1 = asPhoton(objects->at(0))->GetFourMomentum();
    object2 = asPhoton(objects->at(1))->GetFourMomentum();
  }
  auto objectsSum = object1 + object2;

  float costhetastarCS = 2. * (objectsSum.E() * object1.Pz() - objectsSum.Pz() * object1.E()) / (objectsSum.M() * objectsSum.Mt());
  return costhetastarCS;
}

float LbLEvent::GetDiphotonAcoplanarity() {
  auto photons = event->GetCollection("goodPhoton");
  if (photons->size() != 2) return -1;

  double deltaPhi = asPhoton(photons->at(0))->GetFourMomentum().DeltaPhi(asPhoton(photons->at(1))->GetFourMomentum());
  double acoplanarity = 1 - (fabs(deltaPhi) / TMath::Pi());

  return acoplanarity;
}