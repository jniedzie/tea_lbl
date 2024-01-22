#include "Muon.hpp"
#include "ConfigManager.hpp"

using namespace std;

Muon::Muon(std::shared_ptr<PhysicsObject> physicsObject_) : physicsObject(physicsObject_) {
  auto &config = ConfigManager::GetInstance();
  config.GetMap("muonCuts", muonCuts);
  config.GetMap("detectorParams", detectorParams);
  config.GetMap("caloEtaEdges", caloEtaEdges);

  eta = Get("eta");
  phi = Get("phi");
  absEta = fabs(eta);
}