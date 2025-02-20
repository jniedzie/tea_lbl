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
  
  template <typename T>
  T GetAs(std::string branchName) { return physicsObject->GetAs<T>(branchName); }
  std::string GetOriginalCollection() { return physicsObject->GetOriginalCollection(); }
  void Reset() { physicsObject->Reset(); }

  float GetEnergy() { return Get("energy");}
  int GetSide() { return Get("zSide");}

  float GetSaturation() { return Get("saturation");}
  int GetSection() { return Get("section");}
  int GetChannel() { return Get("channel");}

 private:
  std::shared_ptr<PhysicsObject> physicsObject;
};

#endif /* ZDCEnergy_hpp */
