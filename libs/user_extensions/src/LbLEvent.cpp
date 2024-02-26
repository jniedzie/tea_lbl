#include "LbLEvent.hpp"
#include "ExtensionsHelpers.hpp"
#include "UserExtensionsHelpers.hpp"

using namespace std;

float LbLEvent::GetDeltaEt() {
  auto photons = GetCollection("goodPhoton");

  if(photons->size() != 2) {
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

float LbLEvent::GetCosThetaStar()
{
  auto photons = GetCollection("goodPhoton");

  if(photons->size() != 2) {
    warn() << "Couldn't calculate cosThetaStar -- number of photons in the event != 2" << endl;
    return -1;
  }

  TLorentzVector photon1 = asPhoton(photons->at(0))->GetFourMomentum();
  TLorentzVector photon2 = asPhoton(photons->at(1))->GetFourMomentum();
  auto diphoton = photon1 + photon2;

  float costhetastarCS = 2.*(diphoton.E()*photon1.Pz()-diphoton.Pz()*photon1.E())/(diphoton.M()*diphoton.Mt());
  return costhetastarCS;

}

float LbLEvent::GetDiphotonAcoplanarity() {
    auto photons = event->GetCollection("goodPhoton");
    if(photons->size() != 2) return -1;

    double deltaPhi = asPhoton(photons->at(0))->GetFourMomentum().DeltaPhi(asPhoton(photons->at(1))->GetFourMomentum());
    double acoplanarity = 1 - (fabs(deltaPhi) / TMath::Pi());

    return acoplanarity;
  }