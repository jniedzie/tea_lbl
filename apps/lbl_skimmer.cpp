#include "ArgsManager.hpp"
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

int main(int argc, char** argv) {
  auto args = make_unique<ArgsManager>(argc, argv);

  if (!args->GetString("config").has_value()) {
    fatal() << "No config file provided" << endl;
    exit(1);
  }

  ConfigManager::Initialize(args->GetString("config").value());
  auto& config = ConfigManager::GetInstance();

  if (args->GetString("input_path").has_value()) {
    config.SetInputPath(args->GetString("input_path").value());
  }

  if (args->GetString("output_trees_path").has_value()) {
    config.SetTreesOutputPath(args->GetString("output_trees_path").value());
  }

  auto eventReader = make_shared<EventReader>();
  auto eventWriter = make_shared<EventWriter>(eventReader);
  auto eventProcessor = make_unique<EventProcessor>();
  auto cutFlowManager = make_shared<CutFlowManager>(eventReader, eventWriter);
  auto lblSelections = make_unique<LbLSelections>();
  auto lblObjectsManager = make_unique<LbLObjectsManager>();

  bool applyTrigger, applyTwoPhotons, applyChargedExclusivity, applyNeutralExclusivity, applyDiphotonPt, applyZDC, applyTwoElectrons,
      applyEtDelta, applyTwoTracksTwoPhotons, applySinglePhoton, applyThreePhotons, applyZeroPhotonElectron, sameChargeElectrons,
      applyAcoplanarity;
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
  config.GetValue("applyZeroPhotonElectron", applyZeroPhotonElectron);
  config.GetValue("sameChargeElectrons", sameChargeElectrons);
  config.GetValue("applyAcoplanarity", applyAcoplanarity);

  info() << "applyTrigger: " << applyTrigger << endl;
  info() << "applyTwoPhotons: " << applyTwoPhotons << endl;
  info() << "applySinglePhotons: " << applySinglePhoton << endl;
  info() << "applyThreePhotons: " << applyThreePhotons << endl;
  info() << "applyTwoElectrons: " << applyTwoElectrons << "(same charge: " << sameChargeElectrons << ")" << endl;
  info() << "applyChargedExclusivity: " << applyChargedExclusivity << endl;
  info() << "applyNeutralExclusivity: " << applyNeutralExclusivity << endl;
  info() << "applyDiphotonPt: " << applyDiphotonPt << endl;
  info() << "applyZDC: " << applyZDC << endl;
  info() << "applyEtDelta: " << applyEtDelta << endl;
  info() << "applyTwoTracksTwoPhotons: " << applyTwoTracksTwoPhotons << endl;
  info() << "applyZeroPhotonElectron: " << applyZeroPhotonElectron << endl;
  info() << "applyAcoplanarity: " << applyAcoplanarity << endl;

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
  if (applyZeroPhotonElectron) {
    cutFlowManager->RegisterCut("zeroPhotonElectron");
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
    // cutFlowManager->RegisterCut("ZDC+");
    // cutFlowManager->RegisterCut("ZDC-");
    cutFlowManager->RegisterCut("ZDC");
  }
  if (applyEtDelta) cutFlowManager->RegisterCut("etDelta");
  if (applyAcoplanarity) {
    cutFlowManager->RegisterCut("diphotonAcoplanarity");
  }

  vector<string> eventsTreeNames;
  config.GetVector("eventsTreeNames", eventsTreeNames);

  auto& profiler = Profiler::GetInstance();
  profiler.Start("total");

  info() << "N events: " << eventReader->GetNevents() << endl;

  auto singlePhotonCutFlow = make_shared<map<string, int>>(map<string, int>{
      {"00_initial", 0},
      {"01_genMatched", 0},
      {"02_conversionCuts", 0},
      {"03_etCuts", 0},
      {"04_swissCross", 0},
      {"05_etaCuts", 0},
      {"06_crackCuts", 0},
      {"07_hotSpotCuts", 0},
      {"08_HEMCuts", 0},
      {"09_showerShape", 0},
      {"10_hoverE", 0},
      {"11_seedTime", 0},
  });

  for (int iEvent = 0; iEvent < eventReader->GetNevents(); iEvent++) {
    auto event = eventReader->GetEvent(iEvent);
    lblObjectsManager->InsertGoodPhotonsCollection(event);
    lblObjectsManager->InsertGoodElectronsCollection(event);
    if (!applyZeroPhotonElectron) {
      lblObjectsManager->InsertGoodTracksCollection(event);
      lblObjectsManager->InsertGoodMuonsCollection(event);
    }
    if (applyChargedExclusivity) {
      lblObjectsManager->InsertGoodTracksCollection(event);
      lblObjectsManager->InsertGoodMuonsCollection(event);
    }

    cutFlowManager->UpdateCutFlow("initial");

    if (applyTrigger) {
      try {
        if (!(int)event->Get("DoubleEG2")) continue;
      } catch (Exception& e) {
        warn() << e.what() << endl;
      }
      cutFlowManager->UpdateCutFlow("trigger");
    }

    if (applyTwoPhotons) {
      if (!lblSelections->PassesDiphotonSelection(event, cutFlowManager, singlePhotonCutFlow)) continue;
    }
    if (applySinglePhoton) {
      if (!lblSelections->PassesSinglePhotonSelection(event, cutFlowManager)) continue;
    }
    if (applyThreePhotons) {
      if (!lblSelections->PassesThreePhotonsSelection(event, cutFlowManager)) continue;
    }

    if (applyTwoElectrons) {
      if (!lblSelections->PassesDielectronSelection(event, cutFlowManager, sameChargeElectrons)) continue;
    }

    if (applyZeroPhotonElectron) {
      if (!lblSelections->PassesZeroPhotonAndElectronSelection(event, cutFlowManager)) continue;
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

    if (applyAcoplanarity) {
      if (!lblSelections->PassesAcoplanaritySelection(event, cutFlowManager)) continue;
    }

    for (string eventsTreeName : eventsTreeNames) {
      eventWriter->AddCurrentEvent(eventsTreeName);
    }
  }

  profiler.Stop("total");

  cutFlowManager->SaveCutFlow();
  cutFlowManager->Print();
  eventWriter->Save();

  // print single photon cut flow
  int previousCount = 0;

  info() << "Single photon cut flow:" << endl;
  for (const auto& [cutName, count] : *singlePhotonCutFlow) {
    // info() << "  " << cutName << ": " << count << "\t" << count/(float)previousCount << endl;
    info() << count << "\t" << count/(float)previousCount << endl;
    previousCount = count;
  }

  auto& logger = Logger::GetInstance();
  logger.Print();

  profiler.Print();

  return 0;
}