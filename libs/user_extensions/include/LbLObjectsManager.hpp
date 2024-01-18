#include "CutFlowManager.hpp"
#include "Event.hpp"
#include "Helpers.hpp"

class LbLObjectsManager {
 public:
  LbLObjectsManager() {}
  ~LbLObjectsManager() = default;

  void InsertGoodPhotonsCollection(std::shared_ptr<Event> event);
  void InsertGoodElectronsCollection(std::shared_ptr<Event> event);
  void InsertGoodTracksCollection(std::shared_ptr<Event> event);

 private:
  bool IsGoodPhoton(const std::shared_ptr<PhysicsObject> photon);
  bool IsGoodElectron(const std::shared_ptr<PhysicsObject> electron);
  bool IsGoodTrack(const std::shared_ptr<PhysicsObject> track);
};
