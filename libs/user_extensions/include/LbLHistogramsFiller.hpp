#ifndef LbLHistogramsFiller_hpp
#define LbLHistogramsFiller_hpp

#include "Event.hpp"
#include "EventProcessor.hpp"
#include "Helpers.hpp"
#include "HistogramsHandler.hpp"
#include "UserExtensionsHelpers.hpp"

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
  float GetDielectronAcoplanarity(const std::shared_ptr<Electron> &electron1, const std::shared_ptr<Electron> &electron2);
  float GetPhiModulation(const std::shared_ptr<Electron> &electron1, const std::shared_ptr<Electron> &electron2);

  void FillCaloHistograms(const std::shared_ptr<Event> event);
  void FillPhotonHistograms(const std::shared_ptr<Event> event);
  void FillGenLevelHistograms(const std::shared_ptr<Event> event);
  void FillElectronHistograms(const std::shared_ptr<Event> event);
  void FillEventLevelHistograms(const std::shared_ptr<Event> event);
  void FillThreePhotonHistograms(const std::shared_ptr<Event> event);

  TF1 *acoplanarityFunction;
  TLorentzVector dielectron, genDielectron;
  TH1D *genDielectronDeltaPt;

  std::map<std::string, float> caloEtaEdges;
};

#endif /* LbLHistogramsFiller_hpp */
