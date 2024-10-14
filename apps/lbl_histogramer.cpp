#include "ConfigManager.hpp"
#include "CutFlowManager.hpp"
#include "EventReader.hpp"
#include "ExtensionsHelpers.hpp"
#include "HistogramsFiller.hpp"
#include "HistogramsHandler.hpp"
#include "LbLHistogramsFiller.hpp"
#include "LbLObjectsManager.hpp"
#include "Logger.hpp"
#include "ArgsManager.hpp"

using namespace std;

int main(int argc, char **argv) {
  auto args = make_unique<ArgsManager>(argc, argv);

  if (!args->GetString("config").has_value()) {
    fatal() << "No config file provided" << endl;
    exit(1);
  }

  ConfigManager::Initialize(args->GetString("config").value());
  auto &config = ConfigManager::GetInstance();

  if (args->GetString("input_path").has_value()) {
    config.SetInputPath(args->GetString("input_path").value());
  }

  if (args->GetString("output_hists_path").has_value()) {
    config.SetHistogramsOutputPath(args->GetString("output_hists_path").value());
  }


  info() << "Creating objects" << endl;
  auto eventReader = make_shared<EventReader>();
  auto histogramsHandler = make_shared<HistogramsHandler>();
  auto cutFlowManager = make_shared<CutFlowManager>(eventReader);
  auto histogramsFiller = make_unique<HistogramsFiller>(histogramsHandler);
  auto lblHistogramsFiller = make_unique<LbLHistogramsFiller>(histogramsHandler);
  auto lblObjectsManager = make_unique<LbLObjectsManager>();

  cutFlowManager->RegisterCut("initial");

  info() << "Starting event loop" << endl;
  for (int iEvent = 0; iEvent < eventReader->GetNevents(); iEvent++) {
    auto event = eventReader->GetEvent(iEvent);

    lblObjectsManager->InsertGoodPhotonsCollection(event);
    lblObjectsManager->InsertGoodElectronsCollection(event);

    lblObjectsManager->InsertGenPhotonsCollection(event);
    lblObjectsManager->InsertGenElectronsCollection(event);

    cutFlowManager->UpdateCutFlow("initial");
    histogramsFiller->FillDefaultVariables(event);
    lblHistogramsFiller->Fill(event);
  }

  info() << "Finishing up" << endl;
  cutFlowManager->Print();
  histogramsFiller->FillCutFlow(cutFlowManager);
  histogramsHandler->SaveHistograms();

  auto &logger = Logger::GetInstance();
  logger.Print();
  return 0;
}