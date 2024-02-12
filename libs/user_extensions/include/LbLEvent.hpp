#ifndef LbLEvent_hpp
#define LbLEvent_hpp

#include "Event.hpp"
#include "Helpers.hpp"

class LbLEvent {
 public:
  LbLEvent(std::shared_ptr<Event> event_) : event(event_) {}

  auto Get(std::string branchName) { return event->Get(branchName); }
  float GetAsFloat(std::string branchName) { return event->GetAsFloat(branchName); }
  std::shared_ptr<PhysicsObjects> GetCollection(std::string name) const { return event->GetCollection(name); }
  void AddExtraCollections() { event->AddExtraCollections(); }

  float GetDeltaEt();

 private:
  std::shared_ptr<Event> event;
};

#endif /* LbLEvent_hpp */
