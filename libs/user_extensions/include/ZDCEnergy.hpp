#ifndef ZDCEnergy_hpp
#define ZDCEnergy_hpp

#include "Helpers.hpp"
#include "PhysicsObject.hpp"

class ZDCEnergy;
typedef Collection<std::shared_ptr<ZDCEnergy>> ZDCEnergys;

class ZDCEnergy {
 public:
  ZDCEnergy(std::shared_ptr<PhysicsObject> physicsObject_) : physicsObject(physicsObject_) {}

  auto Get(std::string branchName) { return physicsObject->Get(branchName); }
  float GetAsFloat(std::string branchName) { return physicsObject->GetAsFloat(branchName); }
  std::string GetOriginalCollection() { return physicsObject->GetOriginalCollection(); }
  void Reset() { physicsObject->Reset(); }

  float GetEnergy() { return Get("energy");}
  int GetSide() { return Get("zSide");}

 private:
  std::shared_ptr<PhysicsObject> physicsObject;
};

#endif /* ZDCEnergy_hpp */
