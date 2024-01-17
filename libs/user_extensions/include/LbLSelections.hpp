#include "CutFlowManager.hpp"
#include "Event.hpp"
#include "Helpers.hpp"

class LbLSelections {
 public:
  LbLSelections();
  ~LbLSelections() = default;

  void RegisterCuts(std::shared_ptr<CutFlowManager> cutFlowManager);

  void InsertGoodPhotonsCollection(std::shared_ptr<Event> event);
  void InsertGoodElectronsCollection(std::shared_ptr<Event> event);

  bool HasAdditionalTowers(std::shared_ptr<Event> event, std::shared_ptr<CutFlowManager> cutFlowManager);

 private:
  bool OverlapsWithOtherObjects(std::shared_ptr<PhysicsObject> physicsObject, std::shared_ptr<PhysicsObjects> otherObjects,
                                float maxDeltaEta, float maxDeltaPhi);

  std::vector<float> etaEdges;
  int EtaToIeta(float eta);
  bool IsAnyTowerAlive(std::shared_ptr<PhysicsObjects> towers, std::vector<int> deadEtas);
  bool IsAnyECalTowerGood(std::string towersCollectionName, std::shared_ptr<Event> event, float maxDeltaEta, float maxDeltaPhi);
};