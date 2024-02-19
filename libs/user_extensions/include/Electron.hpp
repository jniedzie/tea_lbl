#ifndef Electron_hpp
#define Electron_hpp

#include "Helpers.hpp"
#include "PhysicsObject.hpp"

class Electron;
typedef Collection<std::shared_ptr<Electron>> Electrons;

class Electron {
 public:
  Electron(std::shared_ptr<PhysicsObject> physicsObject_);

  auto Get(std::string branchName) { return physicsObject->Get(branchName); }
  float GetAsFloat(std::string branchName) { return physicsObject->GetAsFloat(branchName); }
  std::string GetOriginalCollection() { return physicsObject->GetOriginalCollection(); }
  void Reset() { physicsObject->Reset(); }

  bool PassesPtCuts();
  bool IsEtaAboveLimit();
  bool IsInCrack();
  bool IsInHEM();
  bool PassesMissingHitsCuts();
  bool PassesHoverE();
  bool PassesDeltaEtaAtVertex();
  bool PassesIsolationCuts();

  TLorentzVector GetFourMomentum() {
    TLorentzVector fourMomentum;
    fourMomentum.SetPtEtaPhiM(Get("pt"), Get("eta"), Get("phi"), 0.000511);
    return fourMomentum;
  }

 private:
  std::shared_ptr<PhysicsObject> physicsObject;

  std::map<std::string, float> electronCuts, detectorParams, caloEtaEdges;
  float eta, phi, absEta, etaSC, phiSC, absEtaSC;

  std::string detRegion;
};

#endif /* Electron_hpp */
