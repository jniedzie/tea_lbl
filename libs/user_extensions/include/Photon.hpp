#ifndef Photon_hpp
#define Photon_hpp

#include "Helpers.hpp"
#include "PhysicsObject.hpp"

class Photon;
typedef Collection<std::shared_ptr<Photon>> Photons;

class Photon {
 public:
  Photon(std::shared_ptr<PhysicsObject> physicsObject_);

  auto Get(std::string branchName) { return physicsObject->Get(branchName); }
  
  template <typename T>
  T GetAs(std::string branchName) { return physicsObject->GetAs<T>(branchName); }
  std::string GetOriginalCollection() { return physicsObject->GetOriginalCollection(); }
  void Reset() { physicsObject->Reset(); }

  float GetSwissCross();

  bool IsInHEM();
  bool IsEtaAboveLimit();
  bool IsInCrack();
  bool IsInHotSpot();
  bool PassesShowerShape();
  bool PassesHoverE();
  bool PassesSwissCross();
  bool PassesEtCuts();
  bool PassesSeedTimeCuts();
  bool PassesConversionCuts();

  bool OverlapsWithOtherObjects(std::shared_ptr<PhysicsObjects> otherObjects) {
    for (auto otherObject : *otherObjects) {
      float deltaEta = fabs((float)otherObject->Get("SCEta") - etaSC);
      float deltaPhi = fabs(TVector2::Phi_mpi_pi((float)otherObject->Get("SCPhi") - phiSC));
      if (deltaEta < electronPhotonMatching.at("maxDeltaEta") && deltaPhi < electronPhotonMatching.at("maxDeltaPhi")) return true;
    }
    return false;
  }

  TLorentzVector GetFourMomentum() {
    TLorentzVector fourMomentum;
    fourMomentum.SetPtEtaPhiM(Get("et"), eta, phi, 0);
    return fourMomentum;
  }

  float GetVerticalOverCentralEnergy() {
    float energyTop = GetAs<float>("energyTop");
    float energyBottom = GetAs<float>("energyBottom");
    float energyCentral = GetAs<float>("maxEnergyCrystal");
    return (energyTop + energyBottom) / (2 * energyCentral);
  }

  float GetHorizontalOverCentralEnergy() {
    float energyLeft = GetAs<float>("energyLeft");
    float energyRight = GetAs<float>("energyRight");
    float energyCentral = GetAs<float>("maxEnergyCrystal");
    return (energyLeft + energyRight) / (2 * energyCentral);
  }

  float GetHorizontalImpalance() {
    float energyLeft = GetAs<float>("energyLeft");
    float energyRight = GetAs<float>("energyRight");

    float imbalance = (energyLeft - energyRight) / (energyLeft + energyRight);

    if (energyLeft == 0 || energyRight == 0) imbalance = 1.5;
    if (energyLeft == 0 && energyRight == 0) imbalance = -1.5;
    return imbalance;
  }

  float GetVerticalImbalance() {
    float energyTop = GetAs<float>("energyTop");
    float energyBottom = GetAs<float>("energyBottom");

    float imbalance = (energyTop - energyBottom) / (energyTop + energyBottom);

    if (energyTop == 0 || energyBottom == 0) imbalance = 1.5;
    if (energyTop == 0 && energyBottom == 0) imbalance = -1.5;
    return imbalance;
  }

 private:
  std::shared_ptr<PhysicsObject> physicsObject;

  std::map<std::string, float> photonCuts, detectorParams, caloEtaEdges, electronPhotonMatching;
  float eta, phi, absEta, etaSC, phiSC, absEtaSC;

  std::string detRegion;
};

#endif /* Photon_hpp */
