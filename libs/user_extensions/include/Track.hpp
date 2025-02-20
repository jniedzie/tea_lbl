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
  
  template <typename T>
  T GetAs(std::string branchName) { return physicsObject->GetAs<T>(branchName); }
  std::string GetOriginalCollection() { return physicsObject->GetOriginalCollection(); }
  void Reset() { physicsObject->Reset(); }

  bool PassesPtCuts();
  bool IsEtaAboveLimit();
  bool PassesValidHitsCuts();
  bool PassesChi2Cuts();
  bool PassesDistanceToPVCuts();

  bool OverlapsWithOtherObjects(std::shared_ptr<PhysicsObjects> otherObjects) {
    for (auto otherObject : *otherObjects) {
      float deltaEta = fabs((float)otherObject->Get("eta") - eta);
      float deltaPhi = fabs(TVector2::Phi_mpi_pi((float)otherObject->Get("phi") - phi));
      if (deltaEta < electronTrackMatching.at("maxDeltaEta") && deltaPhi < electronTrackMatching.at("maxDeltaPhi")) return true;
    }
    return false;
  }

 private:
  std::shared_ptr<PhysicsObject> physicsObject;
  
  std::map<std::string, float> trackCuts, detectorParams, caloEtaEdges, electronTrackMatching;
  float eta, phi, absEta;
};

#endif /* Track_hpp */
