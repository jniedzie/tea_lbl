#include "CutFlowManager.hpp"
#include "Event.hpp"
#include "Helpers.hpp"

class LbLSelections {
 public:
  LbLSelections();
  ~LbLSelections() = default;

  bool PassesNeutralExclusivity(std::shared_ptr<Event> event, std::shared_ptr<CutFlowManager> cutFlowManager);
  bool PassesDiphotonSelection(std::shared_ptr<Event> event, std::shared_ptr<CutFlowManager> cutFlowManager);
  bool PassesChargedExclusivity(std::shared_ptr<Event> event, std::shared_ptr<CutFlowManager> cutFlowManager);
  bool PassesDiphotonPt(std::shared_ptr<Event> event, std::shared_ptr<CutFlowManager> cutFlowManager);
  bool PassesZDC(std::shared_ptr<Event> event, std::shared_ptr<CutFlowManager> cutFlowManager);

private:
  std::map<std::string, float> eventCuts;
};