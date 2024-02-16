#include "LbLHistogramsFiller.hpp"

#include "ConfigManager.hpp"
#include "ExtensionsHelpers.hpp"
#include "UserExtensionsHelpers.hpp"

using namespace std;

LbLHistogramsFiller::LbLHistogramsFiller(shared_ptr<HistogramsHandler> histogramsHandler_) : histogramsHandler(histogramsHandler_) {
  // Create a config manager
  auto &config = ConfigManager::GetInstance();

  // Try to read weights branch
  try {
    config.GetValue("weightsBranchName", weightsBranchName);
  } catch (const Exception &e) {
    info() << "Weights branch not specified -- will assume weight is 1 for all events" << endl;
  }

  // Create an event processor
  eventProcessor = make_unique<EventProcessor>();
}

LbLHistogramsFiller::~LbLHistogramsFiller() {}

float LbLHistogramsFiller::GetWeight(const std::shared_ptr<Event> event) {
  // Try to get event weight, otherwise set to 1.0
  float weight = 1.0;
  try {
    weight = event->Get(weightsBranchName);
  } catch (const Exception &e) {
  }
  return weight;
}

void LbLHistogramsFiller::Fill(const std::shared_ptr<Event> event) {
  auto towers = event->GetCollection("CaloTower");

  float maxEnergy = 0;
  shared_ptr<PhysicsObject> leadingTower;

  for (auto physicsObject : *towers) {
    float eta = fabs((float)physicsObject->Get("eta"));
    if (eta < 1.305 || eta > 3.0) continue;

    float energy = physicsObject->Get("et");
    if (energy > maxEnergy) {
      maxEnergy = energy;
      leadingTower = physicsObject;
    }
  }

  auto tower = asCaloTower(leadingTower);
  float hadEnergy = tower->Get("hadE");
  float energy = tower->Get("energy");
  float transverseEnergy = tower->Get("et");

  if (hadEnergy > 0) {
    histogramsHandler->Fill("caloTowerHE_energyHad", hadEnergy, GetWeight(event));
    histogramsHandler->Fill("caloTowerHE_energyTransverse", transverseEnergy, GetWeight(event));
    histogramsHandler->Fill("caloTowerHE_energy", energy, GetWeight(event));
    if (!tower->IsDead() && !tower->IsInHadronicCrack() && !tower->IsInHEM()) {
      histogramsHandler->Fill("goodCaloTowerHE_energyHad", hadEnergy, GetWeight(event));
      histogramsHandler->Fill("goodCaloTowerHE_energyTransverse", transverseEnergy, GetWeight(event));
      histogramsHandler->Fill("goodCaloTowerHE_energy", energy, GetWeight(event));
    }
  }

  auto photons = event->GetCollection("goodPhoton");
  if (photons->size() == 2) {
    auto photon1 = photons->at(0);
    auto photon2 = photons->at(1);
    TLorentzVector photon1vec, photon2vec;
    photon1vec.SetPtEtaPhiM(photon1->Get("et"), photon1->Get("eta"), photon1->Get("phi"), 0);
    photon2vec.SetPtEtaPhiM(photon2->Get("et"), photon2->Get("eta"), photon2->Get("phi"), 0);

    auto diphoton = photon1vec + photon2vec;

    double deltaPhi = photon1vec.DeltaPhi(photon2vec);
    double acoplanarity = 1 - (fabs(deltaPhi) / TMath::Pi());

    histogramsHandler->Fill("diphoton_pt", diphoton.Pt(), GetWeight(event));
    histogramsHandler->Fill("diphoton_mass100", diphoton.M(), GetWeight(event));
    histogramsHandler->Fill("diphoton_mass200", diphoton.M(), GetWeight(event));
    histogramsHandler->Fill("diphoton_mass", diphoton.M(), GetWeight(event));
    histogramsHandler->Fill("diphoton_rapidity", diphoton.Rapidity(), GetWeight(event));
    histogramsHandler->Fill("diphoton_acoplanarity200", acoplanarity, GetWeight(event));
    histogramsHandler->Fill("diphoton_acoplanarity300", acoplanarity, GetWeight(event));
    histogramsHandler->Fill("diphoton_acoplanarity400", acoplanarity, GetWeight(event));
    histogramsHandler->Fill("diphoton_acoplanarity500", acoplanarity, GetWeight(event));
    histogramsHandler->Fill("diphoton_acoplanarity600", acoplanarity, GetWeight(event));

    histogramsHandler->Fill("diphoton_seedTime", photon1->Get("seedTime"), photon2->Get("seedTime"), GetWeight(event));

    if (acoplanarity < 0.01) {
      histogramsHandler->Fill("diphoton_seedTimeSR", photon1->Get("seedTime"), photon2->Get("seedTime"), GetWeight(event));
      histogramsHandler->Fill("unfoldingPhoton_pt", diphoton.Pt(), GetWeight(event));
      histogramsHandler->Fill("unfoldingPhoton_mass", diphoton.M(), GetWeight(event));
      histogramsHandler->Fill("unfoldingPhoton_absRap", fabs(diphoton.Rapidity()), GetWeight(event));
    }
  }

  auto electrons = event->GetCollection("goodElectron");

  float eleAco = 1000;
  if (electrons->size() == 2) {
    auto electron1 = electrons->at(0);
    auto electron2 = electrons->at(1);
    TLorentzVector electron1vec, electron2vec;
    electron1vec.SetPtEtaPhiM(electron1->Get("pt"), electron1->Get("eta"), electron1->Get("phi"), 0.000511);
    electron2vec.SetPtEtaPhiM(electron2->Get("pt"), electron2->Get("eta"), electron2->Get("phi"), 0.000511);

    auto dielectron = electron1vec + electron2vec;

    double deltaPhi = electron1vec.DeltaPhi(electron2vec);
    double acoplanarity = 1 - (fabs(deltaPhi) / TMath::Pi());
    eleAco = acoplanarity;
    histogramsHandler->Fill("dielectron_pt", dielectron.Pt(), GetWeight(event));
    histogramsHandler->Fill("dielectron_mass", dielectron.M(), GetWeight(event));
    histogramsHandler->Fill("dielectron_rapidity", dielectron.Rapidity(), GetWeight(event));
    histogramsHandler->Fill("dielectron_acoplanarity", acoplanarity, GetWeight(event));

    TLorentzVector electron, positron;
    if ((int)electron1->Get("charge") > 0) {
      positron = electron1vec;
      electron = electron2vec;
    } else {
      positron = electron2vec;
      electron = electron1vec;
    }

    TLorentzVector eleDiff = electron - positron;

    // Calculate delta phi
    // float deltaPhi1 = fabs(dielectron.Phi() - eleDiff.Phi());
    float deltaPhi1 = fabs(dielectron.Phi() - electron.Phi());

    if (deltaPhi1 > TMath::Pi()) deltaPhi1 = 2. * TMath::Pi() - deltaPhi1;

    // bring delta phi between -pi and pi
    // if (deltaPhi1 > TMath::Pi()) deltaPhi1 = deltaPhi1 - 2. * TMath::Pi();
    // if (deltaPhi1 <= -TMath::Pi()) deltaPhi1 = deltaPhi1 + 2. * TMath::Pi();

    // // // Take the absolute value
    // deltaPhi1 = fabs(deltaPhi1);

    // if(electron.Eta() > 1.5 && electron.Pt() > 5 && electron.Pt() < 6){
    histogramsHandler->Fill("dielectron_deltaPhi", deltaPhi1, GetWeight(event));
    // }
  }

  auto lblEvent = asLbLEvent(event);
  float deltaEt = lblEvent->GetDeltaEt();
  histogramsHandler->Fill("event_deltaEt", deltaEt, GetWeight(event));


  if(eleAco > 0.01) return;

  auto mcParticles = event->GetCollection("genParticle");
  float leadingPhotonEnergy = 99999;
  float leadingPhotonEnergyBarrel = 99999;
  float leadingPhotonEnergyBarrelEndcap = 99999;
  
  float leadingPhotonEt = 0;
  float leadingPhotonEtBarrel = 0;
  float leadingPhotonEtBarrelEndcap = 0;

  for(auto particle : *mcParticles){
    int pid = particle->Get("pid");

    // this is a hack needed because pid was stored as float in the tree
    float* floatPtr = reinterpret_cast<float*>(&pid);
    float floatValue = *floatPtr;
    pid = std::round(floatValue);

    // only pick photons
    if(pid != 22) continue;

    TLorentzVector photon;
    photon.SetPtEtaPhiM(particle->Get("et"), particle->Get("eta"), particle->Get("phi"), 0);

    if(fabs(photon.Eta()) > 5.2) continue;

    histogramsHandler->Fill("genPhoton_et", photon.Pt(), GetWeight(event));
    histogramsHandler->Fill("genPhoton_energy", photon.E(), GetWeight(event));

    if(photon.Pt() > leadingPhotonEt){
      leadingPhotonEt = photon.Pt();
      leadingPhotonEnergy = photon.E();
    }
    if(photon.Pt() > leadingPhotonEtBarrel && fabs(photon.Eta()) < 1.4442){
      leadingPhotonEtBarrel = photon.Pt();
      leadingPhotonEnergyBarrel = photon.E();
    }  
    
    if(photon.Pt() > leadingPhotonEtBarrelEndcap && fabs(photon.Eta()) < 3.0){
      leadingPhotonEtBarrelEndcap = photon.Pt();
      leadingPhotonEnergyBarrelEndcap = photon.E();
    }
  }
  histogramsHandler->Fill("leadingGenPhoton_energy", leadingPhotonEnergy, GetWeight(event));
  histogramsHandler->Fill("leadingGenPhotonBarrel_energy", leadingPhotonEnergyBarrel, GetWeight(event));
  histogramsHandler->Fill("leadingGenPhotonBarrelEndcap_energy", leadingPhotonEnergyBarrelEndcap, GetWeight(event));

}
