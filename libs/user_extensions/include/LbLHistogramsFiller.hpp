#ifndef LbLHistogramsFiller_hpp
#define LbLHistogramsFiller_hpp

#include "Event.hpp"
#include "EventProcessor.hpp"
#include "Helpers.hpp"
#include "HistogramsHandler.hpp"

class LbLHistogramsFiller {
 public:
  LbLHistogramsFiller(std::shared_ptr<HistogramsHandler> histogramsHandler_);
  ~LbLHistogramsFiller();

  void Fill(const std::shared_ptr<Event> event);

 private:
  std::shared_ptr<HistogramsHandler> histogramsHandler;
  std::unique_ptr<EventProcessor> eventProcessor;
  std::string weightsBranchName;

  float GetWeight(const std::shared_ptr<Event> event);
  float GetDielectronAcoplanarity(const std::shared_ptr<Event> event);
  
  void FillCaloHistograms(const std::shared_ptr<Event> event);
  void FillPhotonHistograms(const std::shared_ptr<Event> event);
  void FillGenLevelHistograms(const std::shared_ptr<Event> event);
  void FillElectronHistograms(const std::shared_ptr<Event> event);
  void FillEventLevelHistograms(const std::shared_ptr<Event> event);
};

#endif /* LbLHistogramsFiller_hpp */
