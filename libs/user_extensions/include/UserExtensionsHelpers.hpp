#ifndef UserExtensionsHelpers_hpp
#define UserExtensionsHelpers_hpp

#include "ExtensionsHelpers.hpp"
#include "CaloTower.hpp"
#include "Photon.hpp"
#include "PhysicsObject.hpp"
#include "Event.hpp"



inline std::shared_ptr<CaloTower> asCaloTower(const std::shared_ptr<PhysicsObject> physicsObject) {
  return std::make_shared<CaloTower>(physicsObject);
}

inline std::shared_ptr<Photon> asPhoton(const std::shared_ptr<PhysicsObject> physicsObject) {
  return std::make_shared<Photon>(physicsObject);
}

#endif /* UserExtensionsHelpers_hpp */
