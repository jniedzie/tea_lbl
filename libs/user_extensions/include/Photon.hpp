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

 private:
  std::shared_ptr<PhysicsObject> physicsObject;

  std::map<std::string, float> photonCuts, detectorParams, caloEtaEdges, electronPhotonMatching;
  float eta, phi, absEta, etaSC, phiSC, absEtaSC;

  std::string detRegion;
};

#endif /* Photon_hpp */
