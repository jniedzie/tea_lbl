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
  float GetAsFloat(std::string branchName) { return physicsObject->GetAsFloat(branchName); }
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

 private:
  std::shared_ptr<PhysicsObject> physicsObject;

  std::map<std::string, float> photonCuts, detectorParams, caloEtaEdges;
  float eta, phi, absEta, etaSC, phiSC, absEtaSC;

  std::string detRegion;
};

#endif /* Photon_hpp */
