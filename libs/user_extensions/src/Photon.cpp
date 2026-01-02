#include "Photon.hpp"

#include "ConfigManager.hpp"

using namespace std;

Photon::Photon(std::shared_ptr<PhysicsObject> physicsObject_) : physicsObject(physicsObject_) {
  auto &config = ConfigManager::GetInstance();
  config.GetMap("photonCuts", photonCuts);
  config.GetMap("detectorParams", detectorParams);
  config.GetMap("caloEtaEdges", caloEtaEdges);
  config.GetMap("electronPhotonMatching", electronPhotonMatching);

  eta = Get("eta");
  phi = Get("phi");
  absEta = fabs(eta);

  try {
    etaSC = Get("SCEta");
    phiSC = Get("SCPhi");
    absEtaSC = fabs(etaSC);
  } catch (const std::exception &e) {
    warn() << "No photon supercluster information found. Using regular eta and phi" << endl;
    etaSC = eta;
    phiSC = phi;
    absEtaSC = absEta;
  }

  detRegion = absEta < caloEtaEdges["maxEB"] ? "barrel" : "endcap";
}

float Photon::GetSwissCross() {
  float swissCross = 0;
  swissCross += (float)Get("energyTop");
  swissCross += (float)Get("energyBottom");
  swissCross += (float)Get("energyLeft");
  swissCross += (float)Get("energyRight");
  swissCross /= (float)Get("maxEnergyCrystal");

  return 1 - swissCross;
}

bool Photon::IsInHEM() {
  return (etaSC > detectorParams["hem_etaStart"] && etaSC < detectorParams["hem_etaEnd"] && phiSC > detectorParams["hem_phiStart"] &&
          phiSC < detectorParams["hem_phiEnd"]);
}

bool Photon::IsEtaAboveLimit() { return absEta > photonCuts["max_absEta"]; }

bool Photon::IsInCrack() { return (absEtaSC > detectorParams["crack_start"] && absEtaSC < detectorParams["crack_end"]); }

bool Photon::IsInHotSpot() {
  if (phi > 2.20 && phi < 2.27 && eta > -1.87 && eta < -1.83) return true;
  if (phi > -2.78 && phi < -2.70 && eta > -1.62 && eta < -1.58) return true;

  if (phi > 2.17 && phi < 2.21 && eta > -1.60 && eta < -1.58) return true;
  if (phi > 0.09 && phi < 0.13 && eta > 2.12 && eta < 2.14) return true;

  return false;
}

bool Photon::PassesShowerShape() {
  if ((float)Get("SCEtaWidth") > photonCuts["max_SCEtaWidth_" + detRegion]) return false;
  if ((float)Get("sigmaIEtaIEta2012") > photonCuts["max_sigmaIEtaIEta_" + detRegion]) return false;
  if ((float)Get("sigmaIEtaIEta2012") < photonCuts["min_sigmaIEtaIEta_" + detRegion]) return false;
  if ((float)Get("SCEtaWidth") < photonCuts["min_SCEtaWidth"]) return false;
  if ((float)Get("SCPhiWidth") < photonCuts["min_SCPhiWidth"]) return false;
  if ((float)Get("SCPhiWidth") > photonCuts["max_SCPhiWidth"]) return false;

  if (GetVerticalOverCentralEnergy() < photonCuts["min_verticalOverCentral"]) return false;
  if (GetHorizontalOverCentralEnergy() < photonCuts["min_horizontalOverCentral"]) return false;

  return true;
}

bool Photon::PassesHoverE() { return (float)Get("hOverE") < photonCuts["max_hOverE_" + detRegion]; }

bool Photon::PassesSwissCross() {
  float swissCross = GetSwissCross();
  if (swissCross > 1) {
    warn() << "Swiss cross cannot be calculated. The event will pass this selection automatically" << endl;
    return true;
  }

  return swissCross < photonCuts["max_swissCross"];
}

bool Photon::PassesEtCuts() { return (float)Get("et") > photonCuts["min_et"]; }

bool Photon::PassesSeedTimeCuts() { return fabs((float)Get("seedTime")) < photonCuts["max_seedTime"]; }

bool Photon::PassesConversionCuts() { return !(int)Get("hasConversionTracks"); }
