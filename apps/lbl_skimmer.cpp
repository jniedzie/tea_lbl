#include "ConfigManager.hpp"
#include "CutFlowManager.hpp"
#include "EventProcessor.hpp"
#include "EventReader.hpp"
#include "EventWriter.hpp"
#include "ExtensionsHelpers.hpp"
#include "HistogramsFiller.hpp"
#include "HistogramsHandler.hpp"
#include "LbLObjectsManager.hpp"
#include "LbLSelections.hpp"
#include "Logger.hpp"
#include "Profiler.hpp"
#include "UserExtensionsHelpers.hpp"

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
    config.SetTreesOutputPath(argv[3]);
  }

  auto eventReader = make_shared<EventReader>();
  auto eventWriter = make_shared<EventWriter>(eventReader);
  auto eventProcessor = make_unique<EventProcessor>();
  auto cutFlowManager = make_shared<CutFlowManager>(eventReader, eventWriter);
  auto lblSelections = make_unique<LbLSelections>();
  auto lblObjectsManager = make_unique<LbLObjectsManager>();

  bool applyTrigger, applyTwoPhotons, applyChargedExclusivity, applyNeutralExclusivity, applyDiphotonPt, applyZDC, applyTwoElectrons,
      applyEtDelta, applyTwoTracksTwoPhotons, applySinglePhoton, applyThreePhotons;
  config.GetValue("applyTrigger", applyTrigger);
  config.GetValue("applyTwoPhotons", applyTwoPhotons);
  config.GetValue("applySinglePhoton", applySinglePhoton);
  config.GetValue("applyThreePhotons", applyThreePhotons);
  config.GetValue("applyTwoElectrons", applyTwoElectrons);
  config.GetValue("applyChargedExclusivity", applyChargedExclusivity);
  config.GetValue("applyNeutralExclusivity", applyNeutralExclusivity);
  config.GetValue("applyDiphotonPt", applyDiphotonPt);
  config.GetValue("applyZDC", applyZDC);
  config.GetValue("applyEtDelta", applyEtDelta);
  config.GetValue("applyTwoTracksTwoPhotons", applyTwoTracksTwoPhotons);

  info() << "applyTrigger: " << applyTrigger << endl;
  info() << "applyTwoPhotons: " << applyTwoPhotons << endl;
  info() << "applySinglePhotons: " << applySinglePhoton << endl;
  info() << "applyThreePhotons: " << applyThreePhotons << endl;
  info() << "applyTwoElectrons: " << applyTwoElectrons << endl;
  info() << "applyChargedExclusivity: " << applyChargedExclusivity << endl;
  info() << "applyNeutralExclusivity: " << applyNeutralExclusivity << endl;
  info() << "applyDiphotonPt: " << applyDiphotonPt << endl;
  info() << "applyZDC: " << applyZDC << endl;
  info() << "applyEtDelta: " << applyEtDelta << endl;
  info() << "applyTwoTracksTwoPhotons: " << applyTwoTracksTwoPhotons << endl;

  cutFlowManager->RegisterCut("initial");

  if (applyTrigger) {
    cutFlowManager->RegisterCut("trigger");
  }
  if (applyTwoPhotons) {
    cutFlowManager->RegisterCut("twoGoodPhotons");
    cutFlowManager->RegisterCut("diphotonMass");
  }
  if (applySinglePhoton) {
    cutFlowManager->RegisterCut("singlePhoton");
  }
  if (applyThreePhotons) {
    cutFlowManager->RegisterCut("threePhotons");
  }
  if (applyTwoElectrons) {
    cutFlowManager->RegisterCut("twoGoodElectrons");
    cutFlowManager->RegisterCut("electronCharge");
    cutFlowManager->RegisterCut("nTracks");
    cutFlowManager->RegisterCut("dielectronMass");
    cutFlowManager->RegisterCut("dielectronPt");
  }
  if (applyTwoTracksTwoPhotons) {
    cutFlowManager->RegisterCut("twoGoodPhotons");
    cutFlowManager->RegisterCut("diphotonMass");
    cutFlowManager->RegisterCut("twoGoodTracks");
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
  if (applyZDC) {
    cutFlowManager->RegisterCut("ZDC+");
    cutFlowManager->RegisterCut("ZDC-");
    cutFlowManager->RegisterCut("ZDC");
  }
  if (applyEtDelta) cutFlowManager->RegisterCut("etDelta");

  vector<string> eventsTreeNames;
  config.GetVector("eventsTreeNames", eventsTreeNames);

  auto &profiler = Profiler::GetInstance();
  profiler.Start("total");

  info() << "N events: " << eventReader->GetNevents() << endl;

  for (int iEvent = 0; iEvent < eventReader->GetNevents(); iEvent++) {
    auto event = eventReader->GetEvent(iEvent);
    lblObjectsManager->InsertGoodPhotonsCollection(event);
    lblObjectsManager->InsertGoodElectronsCollection(event);
    lblObjectsManager->InsertGoodTracksCollection(event);
    lblObjectsManager->InsertGoodMuonsCollection(event);

    cutFlowManager->UpdateCutFlow("initial");

    if (applyTrigger) {
      try {
        if (!(int)event->Get("DoubleEG2")) continue;
      }
      catch(Exception & e) { warn() << e.what() << endl; }
      cutFlowManager->UpdateCutFlow("trigger");
    }

    if (applyTwoPhotons) {
      if (!lblSelections->PassesDiphotonSelection(event, cutFlowManager)) continue;
    }
    if (applySinglePhoton) {
      if (!lblSelections->PassesSinglePhotonSelection(event, cutFlowManager)) continue;
    }
    if (applyThreePhotons) {
      if (!lblSelections->PassesThreePhotonsSelection(event, cutFlowManager)) continue;
    }

    if (applyTwoElectrons) {
      if (!lblSelections->PassesDielectronSelection(event, cutFlowManager)) continue;
    }

    if (applyTwoTracksTwoPhotons) {
      if (!lblSelections->PassesTracksPlusPhotonsSelection(event, cutFlowManager)) continue;
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