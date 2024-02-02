#include "LbLHistogramsFiller.hpp"

#include "ConfigManager.hpp"
#include "ExtensionsHelpers.hpp"

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
    histogramsHandler->Fill("diphoton_acoplanarity200", acoplanarity, GetWeight(event));
    histogramsHandler->Fill("diphoton_acoplanarity300", acoplanarity, GetWeight(event));
    histogramsHandler->Fill("diphoton_acoplanarity400", acoplanarity, GetWeight(event));
    histogramsHandler->Fill("diphoton_acoplanarity500", acoplanarity, GetWeight(event));
    histogramsHandler->Fill("diphoton_acoplanarity600", acoplanarity, GetWeight(event));
  }

  auto electrons = event->GetCollection("goodElectron");
  if (electrons->size() == 2) {
    auto electron1 = electrons->at(0);
    auto electron2 = electrons->at(1);
    TLorentzVector electron1vec, electron2vec;
    electron1vec.SetPtEtaPhiM(electron1->Get("pt"), electron1->Get("eta"), electron1->Get("phi"), 0);
    electron2vec.SetPtEtaPhiM(electron2->Get("pt"), electron2->Get("eta"), electron2->Get("phi"), 0);

    auto dielectron = electron1vec + electron2vec;

    double deltaPhi = electron1vec.DeltaPhi(electron2vec);
    double acoplanarity = 1 - (fabs(deltaPhi) / TMath::Pi());

    histogramsHandler->Fill("dielectron_pt", dielectron.Pt(), GetWeight(event));
    histogramsHandler->Fill("dielectron_mass", dielectron.M(), GetWeight(event));
    histogramsHandler->Fill("dielectron_acoplanarity", acoplanarity, GetWeight(event));
  }

}
