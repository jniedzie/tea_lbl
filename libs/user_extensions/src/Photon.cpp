#include "Photon.hpp"

#include "ConfigManager.hpp"

using namespace std;

Photon::Photon(std::shared_ptr<PhysicsObject> physicsObject_) : physicsObject(physicsObject_) {
  auto &config = ConfigManager::GetInstance();
  config.GetMap("photonCuts", photonCuts);
  config.GetMap("detectorParams", detectorParams);
  config.GetMap("caloEtaEdges", caloEtaEdges);

  eta = Get("eta");
  phi = Get("phi");
  absEta = fabs(eta);

  etaSC = Get("SCEta");
  phiSC = Get("SCPhi");
  absEtaSC = fabs(etaSC);

  detRegion = absEta < caloEtaEdges["maxEB"] ? "barrel" : "endcap";
}

float Photon::GetSwissCross() {
  float swissCross = 0;
  swissCross += (float)Get("energyTop");
  swissCross += (float)Get("energyBottom");
  swissCross += (float)Get("energyLeft");
  swissCross += (float)Get("energyRight");
  swissCross /= (float)Get("maxEnergyCrystal");

  return swissCross;
}

bool Photon::IsInHEM() {
  return (etaSC > detectorParams["hem_etaStart"] && etaSC < detectorParams["hem_etaEnd"] && phiSC > detectorParams["hem_phiStart"] &&
          phiSC < detectorParams["hem_phiEnd"]);
}

bool Photon::IsEtaAboveLimit() { return absEta > photonCuts["max_absEta"]; }

bool Photon::IsInCrack() { return (absEtaSC > detectorParams["crack_start"] && absEtaSC < detectorParams["crack_end"]); }

bool Photon::PassesShowerShape() {
  if ((float)Get("SCEtaWidth") > photonCuts["max_SCEtaWidth_" + detRegion]) return false;
  if ((float)Get("sigmaIEtaIEta2012") > photonCuts["max_sigmaIEtaIEta_" + detRegion]) return false;
  return true;
}

bool Photon::PassesHoverE() {
  if ((float)Get("hOverE") > photonCuts["max_hOverE_" + detRegion]) return false;
  return true;
}

bool Photon::PassesSwissCross() {
  float swissCross = GetSwissCross();
  if (swissCross < 0) {
    warn() << "Swiss cross cannot be calculated. The event will pass this selection automatically" << endl;
    return true;
  } else if (swissCross > photonCuts["max_swissCross"]) {
    return false;
  }

  return true;
}

bool Photon::PassesEtCuts() {
  return (float)Get("et") > photonCuts["min_et"];
}

bool Photon::PassesSeedTimeCuts() {
  return fabs((float)Get("seedTime")) < photonCuts["max_seedTime"];
}

bool Photon::PassesConversionCuts() {
  return !(int)Get("hasConversionTracks");
}
