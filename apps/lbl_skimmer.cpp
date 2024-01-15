#include "ConfigManager.hpp"
#include "CutFlowManager.hpp"
#include "EventReader.hpp"
#include "EventWriter.hpp"
#include "ExtensionsHelpers.hpp"
#include "HistogramsHandler.hpp"
#include "Profiler.hpp"
#include "HistogramsFiller.hpp"
#include "EventProcessor.hpp"

// If you also created a histogram filler, you can include it here
// #include "MyHistogramsFiller.hpp"

using namespace std;

void CheckArgs(int argc, char **argv) {
  if (argc != 2 && argc != 4) {
    fatal() << "Usage: " << argv[0] << " config_path"<<endl;
    fatal() << "or"<<endl;
    fatal() << argv[0] << " config_path input_path output_path"<<endl;
    exit(1);
  }
}

int main(int argc, char **argv) {
  CheckArgs(argc, argv);
  
  // Initialize ConfigManager with the path passed as an argument to the app
  ConfigManager::Initialize(argv[1]);

  auto &config = ConfigManager::GetInstance();

  // If you want to override input/output paths, you can do it here  
  if(argc == 4){    
    config.SetInputPath(argv[2]);
    config.SetOutputPath(argv[3]);
  }

  // Create event reader and writer, which will handle input/output trees for you
  auto eventReader = make_shared<EventReader>();
  auto eventWriter = make_shared<EventWriter>(eventReader);
  auto eventProcessor = make_unique<EventProcessor>();

  // Create a CutFlowManager to keep track of how many events passed selections
  auto cutFlowManager = make_shared<CutFlowManager>(eventReader, eventWriter);

 
  cutFlowManager->RegisterCut("initial");
  // cutFlowManager->RegisterCut("trigger");
  cutFlowManager->RegisterCut("nPassingEBtower");
  cutFlowManager->RegisterCut("nPassingTower");

  string eventsTreeName;
  config.GetValue("eventsTreeName", eventsTreeName);

  // Start the event loop
  for (int iEvent = 0; iEvent < eventReader->GetNevents(); iEvent++) {
    // Get the event
    auto event = eventReader->GetEvent(iEvent);

    // info() << "N tower: " << (int)event->Get("nTower") << endl;
    // info() << "Calo towers: " << event->GetCollection("CaloTower")->size() << endl;

    // info() << "N passing EB towers: " << event->GetCollection("PassingEBtower")->size() << endl;
    // info() << "N passing towers: " << event->GetCollection("PassingTower")->size() << endl;

    // auto towersAboveThreshold = event->GetCollection("PassingTower");
    // for(auto tower : *towersAboveThreshold){
    //   info() << "Tower energy: " << (float)tower->Get("et") << "\teta: " << (float)tower->Get("eta") << "\toriginal collection: " << tower->GetOriginalCollection() << endl;
    // }

    cutFlowManager->UpdateCutFlow("initial");

    // bool passesTrigger = event->Get("DoubleEG2 NotMBHF2AND");
    // if(!passesTrigger) continue;
    // cutFlowManager->UpdateCutFlow("trigger");

    if(!eventProcessor->PassesEventSelections(event, cutFlowManager)) continue;

    // If you want to store this event in the output tree, add it to the eventWriter
    eventWriter->AddCurrentEvent(eventsTreeName);
  }

  // Tell CutFlowManager to save the cut flow
  cutFlowManager->SaveCutFlow();
  cutFlowManager->Print();

  // Tell EventWriter to save the output tree
  eventWriter->Save();

  return 0;
}