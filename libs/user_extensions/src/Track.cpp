#include "Track.hpp"
#include "ConfigManager.hpp"

using namespace std;

Track::Track(std::shared_ptr<PhysicsObject> physicsObject_) : physicsObject(physicsObject_) {
  auto &config = ConfigManager::GetInstance();
  config.GetMap("trackCuts", trackCuts);
  config.GetMap("detectorParams", detectorParams);
  config.GetMap("caloEtaEdges", caloEtaEdges);
  config.GetMap("electronTrackMatching", electronTrackMatching);

  eta = Get("eta");
  phi = Get("phi");
  absEta = fabs(eta);
}

bool Track::PassesPtCuts() { return (float)Get("pt") > trackCuts["min_pt"]; }

bool Track::IsEtaAboveLimit() { return absEta > trackCuts["max_absEta"]; }

bool Track::PassesValidHitsCuts() { return (int)Get("nValidHits") >= trackCuts["min_nValidHits"]; }

bool Track::PassesChi2Cuts() { return (float)Get("normalizedChi2") < trackCuts["max_normalizedChi2"]; }

bool Track::PassesDistanceToPVCuts() {
  if (fabs((float)Get("dxy")) > trackCuts["max_dxy"]) return false;
  if (fabs((float)Get("dxy") / (float)Get("dxyError")) > trackCuts["max_dxyOverError"]) return false;
  if (fabs((float)Get("dz")) > trackCuts["max_dz"]) return false;
  if (fabs((float)Get("dz") / (float)Get("dzError")) > trackCuts["max_dzOverError"]) return false;

  return true;
}