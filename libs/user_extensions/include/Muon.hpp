#ifndef Muon_hpp
#define Muon_hpp

#include "Helpers.hpp"
#include "PhysicsObject.hpp"

class Muon;
typedef Collection<std::shared_ptr<Muon>> Muons;

class Muon {
 public:
  Muon(std::shared_ptr<PhysicsObject> physicsObject_);

  auto Get(std::string branchName) { return physicsObject->Get(branchName); }
  float GetAsFloat(std::string branchName) { return physicsObject->GetAsFloat(branchName); }
  std::string GetOriginalCollection() { return physicsObject->GetOriginalCollection(); }
  void Reset() { physicsObject->Reset(); }

 private:
  std::shared_ptr<PhysicsObject> physicsObject;

  std::map<std::string, float> muonCuts, detectorParams, caloEtaEdges;
  float eta, phi, absEta;
};

#endif /* Muon_hpp */
