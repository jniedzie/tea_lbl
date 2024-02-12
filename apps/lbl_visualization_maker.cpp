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

tuple<float, float> findRefEtandPhi(const vector<pair<float, float>> &phiAndEt) {
  float maxTowerEt = 0;
  float refTowerPhi = 0;
  for (auto &[phi, et] : phiAndEt) {
    if (et > maxTowerEt) {
      maxTowerEt = et;
      refTowerPhi = phi;
    }
  }
  return {maxTowerEt, refTowerPhi};
}

tuple<array<float, 5>, array<float, 5>> getVertices(float circleRadius, float trapezoidInnerWidth, float trapezoidOuterWidth,
                                                    float trapezoidHeight, float angle_rad) {
  array<float, 5> verticesX, verticesY;

  double baseX = circleRadius * TMath::Cos(angle_rad);
  double baseY = circleRadius * TMath::Sin(angle_rad);

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

  return {verticesX, verticesY};
}

vector<TGraph *> getTrapezoids(const vector<pair<float, float>> &phiAndEt, const map<string, float> &visualizationParams,
                               float circleRadius, float trapezoidInnerWidth, float maxTowerEt, float refTowerPhi, float maxTowerHeight) {
  vector<TGraph *> trapezoids;
  for (auto &[phi, et] : phiAndEt) {
    double trapezoidHeight = et;

    if (visualizationParams.at("normalizeMomenta")) {
      trapezoidHeight /= maxTowerEt;
      trapezoidHeight *= maxTowerHeight;
    }

    double trapezoidOuterWidth = trapezoidInnerWidth;
    trapezoidOuterWidth += visualizationParams.at("towerOuterWidthScale") * trapezoidHeight;

    double angle_rad = phi;

    if (visualizationParams.at("normalizeRotation")) {
      angle_rad -= refTowerPhi;
    }

    auto [verticesX, verticesY] = getVertices(circleRadius, trapezoidInnerWidth, trapezoidOuterWidth, trapezoidHeight, angle_rad);

    trapezoids.push_back(new TGraph(5, verticesX.data(), verticesY.data()));
  }
  return trapezoids;
}

int getTowerColor(const map<string, float> &visualizationParams) {
  int towerColor;
  if (visualizationParams.at("towerColor") < 0) {
    towerColor = 10;
    auto color = gROOT->GetColor(towerColor);
    color->SetRGB(visualizationParams.at("towerColorR"), visualizationParams.at("towerColorG"), visualizationParams.at("towerColorB"));
  } else {
    towerColor = visualizationParams.at("towerColor");
  }
  return towerColor;
}

void drawShapes(const vector<pair<float, float>> &towersPhiAndEt, const vector<pair<float, float>> &photonsPhiAndEt, string outputFileName,
                const map<string, float> &visualizationParams) {
  auto canvas = new TCanvas(outputFileName.c_str(), outputFileName.c_str(), 800, 800);
  canvas->SetFillColor(visualizationParams.at("backgroundColor"));
  float canvasSize = visualizationParams.at("canvasSize");
  canvas->Range(-canvasSize, -canvasSize, canvasSize, canvasSize);
  double circleRadius = visualizationParams.at("circleRadius");
  TEllipse *circle = new TEllipse(0, 0, circleRadius);
  circle->SetFillColor(visualizationParams.at("backgroundColor"));
  circle->SetFillStyle(1001);
  circle->SetLineColor(visualizationParams.at("circleColor"));
  circle->Draw();

  double trapezoidInnerWidth = visualizationParams.at("towerInnerWidth");
  auto [maxTowerEt, refTowerPhi] = findRefEtandPhi(towersPhiAndEt);
  float maxTowerHeight = visualizationParams.at("maxTowerHeight");

  auto towersTrapezoids = getTrapezoids(towersPhiAndEt, 
  visualizationParams, circleRadius, trapezoidInnerWidth, maxTowerEt, refTowerPhi, maxTowerHeight);

  int towerColor = getTowerColor(visualizationParams);
  for(auto trapezoid : towersTrapezoids) {
    trapezoid->SetFillColorAlpha(towerColor, visualizationParams.at("towerAlpha"));
    trapezoid->SetFillStyle(visualizationParams.at("towerFillStyle"));
    trapezoid->Draw("f");
  }
  

  auto [maxPhotonEt, refPhotonPhi] = findRefEtandPhi(photonsPhiAndEt);
  auto photonsTrapezoids = getTrapezoids(photonsPhiAndEt, visualizationParams, circleRadius, 0.1*trapezoidInnerWidth, maxPhotonEt, refPhotonPhi, maxTowerHeight);
  int photonColor = kBlue;
  for(auto trapezoid : photonsTrapezoids) {
    trapezoid->SetFillColorAlpha(photonColor, 0.5);
    trapezoid->SetFillStyle(1001);
    trapezoid->Draw("f");
  }

  canvas->Update();

  string outputDir = outputFileName.substr(0, outputFileName.find_last_of("/"));
  gSystem->mkdir(outputDir.c_str());
  canvas->SaveAs(outputFileName.c_str());
}

void CheckArgs(int argc, char **argv) {
  if (argc != 2) {
    fatal() << "Usage: " << argv[0] << " config_path" << endl;
    exit(1);
  }
}

float getDiphotonAcoplanarity(const shared_ptr<PhysicsObjects> &photons) {
  auto photon1 = photons->at(0);
  auto photon2 = photons->at(1);
  TLorentzVector photon1vec, photon2vec;
  photon1vec.SetPtEtaPhiM(photon1->Get("et"), photon1->Get("eta"), photon1->Get("phi"), 0);
  photon2vec.SetPtEtaPhiM(photon2->Get("et"), photon2->Get("eta"), photon2->Get("phi"), 0);

  auto diphoton = photon1vec + photon2vec;
  
  double deltaPhi = photon1vec.DeltaPhi(photon2vec);
  double acoplanarity = 1 - (fabs(deltaPhi) / TMath::Pi());

  return acoplanarity;
}

int main(int argc, char **argv) {
  gROOT->SetBatch(true);

  CheckArgs(argc, argv);
  ConfigManager::Initialize(argv[1]);
  auto &config = ConfigManager::GetInstance();

  map<string, float> visualizationParams;
  config.GetMap("visualizationParams", visualizationParams);

  info() << "Creating objects" << endl;
  auto eventReader = make_shared<EventReader>();

  auto lblObjectsManager = make_unique<LbLObjectsManager>();

  auto etaPhiMap = new TH2D("etaPhiMap", "etaPhiMap", 
  100, -2.5, 2.5, 100, -TMath::Pi(), TMath::Pi());
  auto etaPhiMapSR = new TH2D("etaPhiMapSR", "etaPhiMapSR", 
  100, -2.5, 2.5, 100, -TMath::Pi(), TMath::Pi());
  auto etaMap = new TH1D("etaMap", "etaMap", 50, 0, 2.5);

  vector<float> etas;

  info() << "Starting event loop" << endl;
  for (int iEvent = 0; iEvent < eventReader->GetNevents(); iEvent++) {
    auto event = eventReader->GetEvent(iEvent);

    lblObjectsManager->InsertGoodPhotonsCollection(event);

    auto photons = event->GetCollection("goodPhoton");

    float acoplanarity = getDiphotonAcoplanarity(photons);
    if (acoplanarity > 0.01) continue;

    vector<pair<float, float>> tracksPhiAndPt;
    auto tracks = event->GetCollection("track");

    for(auto track : *tracks){
      tracksPhiAndPt.push_back({(float)track->Get("phi"), (float)track->Get("pt")});
    }

    vector<pair<float, float>> photonsPhiAndEt = {{(float)photons->at(0)->Get("phi"), (float)photons->at(0)->Get("et")},
                                                  {(float)photons->at(1)->Get("phi"), (float)photons->at(1)->Get("et")}};

    auto towers = event->GetCollection("CaloTower");
    vector<pair<float, float>> towersPhiAndEt;

    auto photon1 = photons->at(0);
    auto photon2 = photons->at(1);

    float photon1Et = photon1->Get("et");
    float photon2Et = photon2->Get("et");

    float maxDeltaR = 1.5;
    float highestTowerEt1 = 0;
    float highestTowerEt2 = 0;

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

      if(sqrt(pow(phi - (float)photon1->Get("phi"), 2) + pow((float)tower->Get("eta") - (float)photon1->Get("eta"), 2)) < maxDeltaR) {
        if(et > highestTowerEt1) highestTowerEt1 = et;
      }
      if(sqrt(pow(phi - (float)photon2->Get("phi"), 2) + pow((float)tower->Get("eta") - (float)photon2->Get("eta"), 2)) < maxDeltaR) {
        if(et > highestTowerEt2) highestTowerEt2 = et;
      }
      towersPhiAndEt.push_back({phi, et});
    }

    float deltaEt1 = fabs(photon1Et - highestTowerEt1)/photon1Et;
    float deltaEt2 = fabs(photon2Et - highestTowerEt2)/photon2Et;

    float maxDelta = max(deltaEt1, deltaEt2);
    info() << "Max delta: " << maxDelta << endl;

    auto etaPhiMapToFill = (acoplanarity > 0.01) ? etaPhiMap : etaPhiMapSR;

    if(maxDelta > 0.65){
      if(deltaEt1 > deltaEt2) {
        info() << (float)photon1->Get("eta") << " " << (float)photon1->Get("phi") << endl;
        etaPhiMapToFill->Fill((float)photon1->Get("eta"), (float)photon1->Get("phi"));
        etaMap->Fill(fabs((float)photon1->Get("eta")));
        etas.push_back(fabs((float)photon1->Get("eta")));
      } else {
        info() << (float)photon2->Get("eta") << " " << (float)photon2->Get("phi") << endl;
        etaPhiMapToFill->Fill((float)photon2->Get("eta"), (float)photon2->Get("phi"));
        etaMap->Fill(fabs((float)photon2->Get("eta")));
        etas.push_back(fabs((float)photon2->Get("eta")));
      }
    }

    // drawShapes(towersPhiAndEt, photonsPhiAndEt, "../plots/visualizations/event_" + to_string(iEvent) + ".pdf", visualizationParams);
    drawShapes(towersPhiAndEt, {}, "../plots/visualizations/event_" + to_string(iEvent) + ".pdf", visualizationParams);
    // drawShapes(towersPhiAndEt, tracksPhiAndPt, "../plots/visualizations/event_" + to_string(iEvent) + ".pdf", visualizationParams);
  }

  gStyle->SetOptStat(0);
  auto canvas = new TCanvas("canvas", "canvas", 1600, 800);
  canvas->Divide(2, 1);
  canvas->cd(1);
  etaPhiMap->SetMarkerSize(2);
  etaPhiMap->SetMarkerColor(kRed);
  etaPhiMap->SetMarkerStyle(20);
  etaPhiMap->Draw("P");
  etaPhiMap->GetXaxis()->SetTitle("#eta");
  etaPhiMap->GetYaxis()->SetTitle("#phi");

  etaPhiMapSR->SetMarkerSize(2);
  etaPhiMapSR->SetMarkerColor(kBlue);
  etaPhiMapSR->SetMarkerStyle(20);
  etaPhiMapSR->Draw("P SAME");

  canvas->cd(2);
  etaMap->Draw();
  etaMap->GetXaxis()->SetTitle("|#eta|");
  etaMap->GetYaxis()->SetTitle("Events");
  
  canvas->SaveAs("../plots/visualizations/etaPhiMap.pdf");

  for(float eta : etas){
    info() << eta << endl;
  }

  info() << "Finishing up" << endl;
  auto &logger = Logger::GetInstance();
  logger.Print();
  return 0;
}