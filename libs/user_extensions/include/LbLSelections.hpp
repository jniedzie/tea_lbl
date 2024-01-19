#include "CutFlowManager.hpp"
#include "Event.hpp"
#include "Helpers.hpp"

class LbLSelections {
 public:
  LbLSelections() = default;
  ~LbLSelections() = default;

  bool PassesNeutralExclusivity(std::shared_ptr<Event> event, std::shared_ptr<CutFlowManager> cutFlowManager);
  bool PassesDiphotonSelection(std::shared_ptr<Event> event, std::shared_ptr<CutFlowManager> cutFlowManager);
  bool PassesChargedExclusivity(std::shared_ptr<Event> event, std::shared_ptr<CutFlowManager> cutFlowManager);
  bool PassesDiphotonPt(std::shared_ptr<Event> event, std::shared_ptr<CutFlowManager> cutFlowManager);

 private:
  bool OverlapsWithOtherObjects(std::shared_ptr<PhysicsObject> physicsObject, std::shared_ptr<PhysicsObjects> otherObjects,
                                float maxDeltaEta, float maxDeltaPhi);

  std::vector<float> etaEdges;
  int EtaToIeta(float eta);
  bool IsAnyTowerAlive(std::shared_ptr<PhysicsObjects> towers, std::vector<int> deadEtas);
  bool IsAnyECalTowerGood(std::string towersCollectionName, std::shared_ptr<Event> event, float maxDeltaEta, float maxDeltaPhi, bool checkHem);
};