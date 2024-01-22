#include "Muon.hpp"

#include "ConfigManager.hpp"

using namespace std;

Muon::Muon(shared_ptr<PhysicsObject> physicsObject_) : physicsObject(physicsObject_) {
  auto &config = ConfigManager::GetInstance();
  config.GetMap("muonCuts", muonCuts);
  config.GetMap("detectorParams", detectorParams);
  config.GetMap("caloEtaEdges", caloEtaEdges);

  eta = Get("eta");
  phi = Get("phi");
  absEta = fabs(eta);
}

bool Muon::PassesPtCuts() { return (float)Get("pt") > muonCuts["min_pt"]; }

bool Muon::IsEtaAboveLimit() { return absEta > muonCuts["max_absEta"]; }
