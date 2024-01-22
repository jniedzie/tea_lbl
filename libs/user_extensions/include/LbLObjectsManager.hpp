#include "CutFlowManager.hpp"
#include "Event.hpp"
#include "Helpers.hpp"
#include "UserExtensionsHelpers.hpp"

class LbLObjectsManager {
 public:
  LbLObjectsManager();
  ~LbLObjectsManager() = default;

  void InsertGoodPhotonsCollection(std::shared_ptr<Event> event);
  void InsertGoodElectronsCollection(std::shared_ptr<Event> event);
  void InsertGoodTracksCollection(std::shared_ptr<Event> event);
  void InsertGoodMuonsCollection(std::shared_ptr<Event> event);

 private:
  bool IsGoodPhoton(const std::shared_ptr<Photon> photon);
  bool IsGoodElectron(const std::shared_ptr<Electron> electron);
  bool IsGoodTrack(const std::shared_ptr<Track> track);
  bool IsGoodMuon(const std::shared_ptr<Muon> track);

  std::map<std::string, float> detectorParams, caloEtaEdges;
};
