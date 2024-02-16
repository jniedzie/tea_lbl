#include "ConfigManager.hpp"
#include "CutFlowManager.hpp"
#include "EventProcessor.hpp"
#include "EventReader.hpp"
#include "EventWriter.hpp"
#include "ExtensionsHelpers.hpp"
#include "UserExtensionsHelpers.hpp"
#include "HistogramsFiller.hpp"
#include "HistogramsHandler.hpp"
#include "LbLObjectsManager.hpp"
#include "LbLSelections.hpp"
#include "Logger.hpp"
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
  auto lblObjectsManager = make_unique<LbLObjectsManager>();

  bool applyTwoPhotons, applyChargedExclusivity, applyNeutralExclusivity, applyDiphotonPt, applyZDC, applyTwoElectrons, applyEtDelta;
  config.GetValue("applyTwoPhotons", applyTwoPhotons);
  config.GetValue("applyTwoElectrons", applyTwoElectrons);
  config.GetValue("applyChargedExclusivity", applyChargedExclusivity);
  config.GetValue("applyNeutralExclusivity", applyNeutralExclusivity);
  config.GetValue("applyDiphotonPt", applyDiphotonPt);
  config.GetValue("applyZDC", applyZDC);
  config.GetValue("applyEtDelta", applyEtDelta);

  cutFlowManager->RegisterCut("initial");

  if (applyTwoPhotons) {
    cutFlowManager->RegisterCut("twoGoodPhotons");
    cutFlowManager->RegisterCut("diphotonMass");
  }
  if (applyTwoElectrons) {
    cutFlowManager->RegisterCut("twoGoodElectrons");
    cutFlowManager->RegisterCut("nPhotons");
    cutFlowManager->RegisterCut("electronCharge");
    cutFlowManager->RegisterCut("nTracks");
    cutFlowManager->RegisterCut("dielectronMass");
    cutFlowManager->RegisterCut("dielectronPt");
  }
  if (applyChargedExclusivity) {
    cutFlowManager->RegisterCut("nElectrons");
    cutFlowManager->RegisterCut("nTracks");
    cutFlowManager->RegisterCut("nMuons");
  }
  if (applyNeutralExclusivity) {
    cutFlowManager->RegisterCut("neutralExclusivity");
  }
  if (applyDiphotonPt) {
    cutFlowManager->RegisterCut("diphotonPt");
  }
  if (applyZDC) cutFlowManager->RegisterCut("ZDC");
  if (applyEtDelta) cutFlowManager->RegisterCut("etDelta");

  vector<string> eventsTreeNames;
  config.GetVector("eventsTreeNames", eventsTreeNames);

  auto &profiler = Profiler::GetInstance();
  profiler.Start("total");

  for (int iEvent = 0; iEvent < eventReader->GetNevents(); iEvent++) {
    auto event = eventReader->GetEvent(iEvent);
    lblObjectsManager->InsertGoodPhotonsCollection(event);
    lblObjectsManager->InsertGoodElectronsCollection(event);
    lblObjectsManager->InsertGoodTracksCollection(event);
    lblObjectsManager->InsertGoodMuonsCollection(event);

    cutFlowManager->UpdateCutFlow("initial");

    if (applyTwoPhotons) {
      if (!lblSelections->PassesDiphotonSelection(event, cutFlowManager)) continue;
    }

    if (applyTwoElectrons) {
      if (!lblSelections->PassesDielectronSelection(event, cutFlowManager)) continue;
    }

    if (applyChargedExclusivity) {
      if (!lblSelections->PassesChargedExclusivity(event, cutFlowManager)) continue;
    }

    if (applyNeutralExclusivity) {
      if (!lblSelections->PassesNeutralExclusivity(event, cutFlowManager)) continue;
    }

    if (applyDiphotonPt) {
      if (!lblSelections->PassesDiphotonPt(event, cutFlowManager)) continue;
    }

    if (applyZDC) {
      if (!lblSelections->PassesZDC(event, cutFlowManager)) continue;
    }

    if (applyEtDelta) {
      auto lblEvent = asLbLEvent(event);
      if (lblEvent->GetDeltaEt() > 0.65) continue;
      cutFlowManager->UpdateCutFlow("etDelta");
    }

    for (string eventsTreeName : eventsTreeNames) {
      eventWriter->AddCurrentEvent(eventsTreeName);
    }
  }

  profiler.Stop("total");

  cutFlowManager->SaveCutFlow();
  cutFlowManager->Print();
  eventWriter->Save();

  auto &logger = Logger::GetInstance();
  logger.Print();

  profiler.Print();

  return 0;
}