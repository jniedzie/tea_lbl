#include "ConfigManager.hpp"
#include "CutFlowManager.hpp"
#include "EventProcessor.hpp"
#include "EventReader.hpp"
#include "EventWriter.hpp"
#include "ExtensionsHelpers.hpp"
#include "HistogramsFiller.hpp"
#include "HistogramsHandler.hpp"
#include "LbLSelections.hpp"
#include "Profiler.hpp"

using namespace std;

void CheckArgs(int argc, char **argv) {
  if (argc != 2 && argc != 4) {
    fatal() << "Usage: " << argv[0] << " config_path" << endl;
    fatal() << "or" << endl;
    fatal() << argv[0] << " config_path input_path output_path" << endl;
    exit(1);
  }
}

int main(int argc, char **argv) {
  CheckArgs(argc, argv);
  ConfigManager::Initialize(argv[1]);
  auto &config = ConfigManager::GetInstance();
  if (argc == 4) {
    config.SetInputPath(argv[2]);
    config.SetOutputPath(argv[3]);
  }

  auto eventReader = make_shared<EventReader>();
  auto eventWriter = make_shared<EventWriter>(eventReader);
  auto eventProcessor = make_unique<EventProcessor>();
  auto cutFlowManager = make_shared<CutFlowManager>(eventReader, eventWriter);
  auto lblSelections = make_unique<LbLSelections>();

  cutFlowManager->RegisterCut("initial");
  cutFlowManager->RegisterCut("ZDC");
  lblSelections->RegisterCuts(cutFlowManager);

  vector<string> eventsTreeNames;
  config.GetVector("eventsTreeNames", eventsTreeNames);

  for (int iEvent = 0; iEvent < eventReader->GetNevents(); iEvent++) {
    auto event = eventReader->GetEvent(iEvent);
    lblSelections->InsertGoodPhotonsCollection(event);
    lblSelections->InsertGoodElectronsCollection(event);

    cutFlowManager->UpdateCutFlow("initial");

    if (event->GetCollection("PassingZDCcounts")->size() != 0) continue;
    cutFlowManager->UpdateCutFlow("ZDC");

    if (lblSelections->HasAdditionalTowers(event, cutFlowManager)) continue;

    for (string eventsTreeName : eventsTreeNames) {
      eventWriter->AddCurrentEvent(eventsTreeName);
    }
  }

  cutFlowManager->SaveCutFlow();
  cutFlowManager->Print();
  eventWriter->Save();

  return 0;
}