#ifndef Track_hpp
#define Track_hpp

#include "Helpers.hpp"
#include "PhysicsObject.hpp"

class Track;
typedef Collection<std::shared_ptr<Track>> Tracks;

class Track {
 public:
  Track(std::shared_ptr<PhysicsObject> physicsObject_);

  auto Get(std::string branchName) { return physicsObject->Get(branchName); }
  float GetAsFloat(std::string branchName) { return physicsObject->GetAsFloat(branchName); }
  std::string GetOriginalCollection() { return physicsObject->GetOriginalCollection(); }
  void Reset() { physicsObject->Reset(); }

  bool PassesPtCuts();
  bool IsEtaAboveLimit();
  bool PassesValidHitsCuts();
  bool PassesChi2Cuts();
  bool PassesDistanceToPVCuts();

 private:
  std::shared_ptr<PhysicsObject> physicsObject;
  
  std::map<std::string, float> trackCuts, detectorParams, caloEtaEdges;
  float eta, phi, absEta;
};

#endif /* Track_hpp */
