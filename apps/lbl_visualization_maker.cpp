#include "ConfigManager.hpp"
#include "CutFlowManager.hpp"
#include "EventReader.hpp"
#include "ExtensionsHelpers.hpp"
#include "HistogramsFiller.hpp"
#include "HistogramsHandler.hpp"
#include "LbLHistogramsFiller.hpp"
#include "LbLObjectsManager.hpp"
#include "Logger.hpp"

using namespace std;

void drawShapes(vector<pair<float, float>> phiAndEt, string outputFileName) {
  TCanvas *c1 = new TCanvas(outputFileName.c_str(), outputFileName.c_str(), 800, 800);
  c1->Range(-3.0, -3.0, 3.0, 3.0);  // Adjust canvas range to fully view the circle and rectangle
  double circleRadius = 1.0;
  TEllipse *circle = new TEllipse(0, 0, circleRadius);
  circle->Draw();

  double trapezoidInnerWidth = 0.10;  // Width of the trapezoid at the circle edge

  vector<TGraph *> trapezoids;

  float maxEt = 0;
  float refPhi = 0;
  for (auto &[phi, et] : phiAndEt) {
    if (et > maxEt) {
        maxEt = et;
        refPhi = phi;
    }
  }

  for (auto &[phi, et] : phiAndEt) {
    double trapezoidHeight = et / maxEt;
    double trapezoidOuterWidth = trapezoidInnerWidth + 0.1 * trapezoidHeight;


    info() << "Phi: " << phi << "\tet: " << et << endl;

    double angle_rad = phi - refPhi;
    double baseX = circleRadius * TMath::Cos(angle_rad);
    double baseY = circleRadius * TMath::Sin(angle_rad);

    double verticesX[5], verticesY[5];

    verticesX[0] = baseX - (trapezoidInnerWidth / 2.0) * TMath::Sin(angle_rad);
    verticesY[0] = baseY + (trapezoidInnerWidth / 2.0) * TMath::Cos(angle_rad);
    verticesX[1] = baseX + (trapezoidInnerWidth / 2.0) * TMath::Sin(angle_rad);
    verticesY[1] = baseY - (trapezoidInnerWidth / 2.0) * TMath::Cos(angle_rad);

    // Outer vertices (wider end)
    verticesX[2] =
        verticesX[1] + trapezoidHeight * TMath::Cos(angle_rad) + (trapezoidOuterWidth - trapezoidInnerWidth) / 2.0 * TMath::Sin(angle_rad);
    verticesY[2] =
        verticesY[1] + trapezoidHeight * TMath::Sin(angle_rad) - (trapezoidOuterWidth - trapezoidInnerWidth) / 2.0 * TMath::Cos(angle_rad);
    verticesX[3] =
        verticesX[0] + trapezoidHeight * TMath::Cos(angle_rad) - (trapezoidOuterWidth - trapezoidInnerWidth) / 2.0 * TMath::Sin(angle_rad);
    verticesY[3] =
        verticesY[0] + trapezoidHeight * TMath::Sin(angle_rad) + (trapezoidOuterWidth - trapezoidInnerWidth) / 2.0 * TMath::Cos(angle_rad);

    // Closing the trapezoid
    verticesX[4] = verticesX[0];
    verticesY[4] = verticesY[0];

    // Draw the trapezoid
    trapezoids.push_back(new TGraph(5, verticesX, verticesY));
    trapezoids.back()->SetFillColorAlpha(kBlue, 0.3);
    trapezoids.back()->SetFillStyle(1001);
    trapezoids.back()->Draw("f");
  }

  c1->Update();
  c1->SaveAs(outputFileName.c_str());
}

void CheckArgs(int argc, char **argv) {
  if (argc != 2) {
    fatal() << "Usage: " << argv[0] << " config_path" << endl;
    exit(1);
  }
}

int main(int argc, char **argv) {
  CheckArgs(argc, argv);
  ConfigManager::Initialize(argv[1]);
  auto &config = ConfigManager::GetInstance();

  info() << "Creating objects" << endl;
  auto eventReader = make_shared<EventReader>();

  auto lblObjectsManager = make_unique<LbLObjectsManager>();

  info() << "Starting event loop" << endl;
  for (int iEvent = 0; iEvent < eventReader->GetNevents(); iEvent++) {
    auto event = eventReader->GetEvent(iEvent);

    lblObjectsManager->InsertGoodPhotonsCollection(event);

    auto photons = event->GetCollection("goodPhoton");

    auto photon1 = photons->at(0);
    auto photon2 = photons->at(1);
    TLorentzVector photon1vec, photon2vec;
    photon1vec.SetPtEtaPhiM(photon1->Get("et"), photon1->Get("eta"), photon1->Get("phi"), 0);
    photon2vec.SetPtEtaPhiM(photon2->Get("et"), photon2->Get("eta"), photon2->Get("phi"), 0);

    auto diphoton = photon1vec + photon2vec;
    info() << "Diphoton pt: " << diphoton.Pt() << endl;

    double deltaPhi = photon1vec.DeltaPhi(photon2vec);
    double acoplanarity = 1 - (fabs(deltaPhi) / TMath::Pi());
    if (acoplanarity > 0.01) continue;

    auto towers = event->GetCollection("CaloTower");
    vector<pair<float, float>> phiAndEt;

    for (auto physicsObject : *towers) {
      auto tower = asCaloTower(physicsObject);
      if (tower->IsDead()) continue;
      if (tower->IsEtaAboveLimit()) continue;
      if (tower->IsInHEM()) continue;
      if (tower->IsInElectromagneticCrack()) continue;

      //   if (tower->OverlapsWithOtherObjects(event->GetCollection("goodPhoton"))) continue;
      //   if (tower->OverlapsWithOtherObjects(event->GetCollection("goodElectron"))) continue;

    //   if (!tower->IsElectromagneticEnergyAboveNoiseThreshold()) continue;

      float phi = tower->Get("phi");
      float et = tower->Get("et");
      phiAndEt.push_back({phi, et});
    }

    drawShapes(phiAndEt, "../plots/visualizations/event_" + to_string(iEvent) + ".pdf");
  }

  info() << "Finishing up" << endl;
  auto &logger = Logger::GetInstance();
  logger.Print();
  return 0;
}