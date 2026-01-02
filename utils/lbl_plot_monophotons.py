import ROOT
import dataclasses
from dataclasses import dataclass


@dataclass
class Photon:
  et: float
  eta: float
  phi: float
  maxEnergyCrystal: float
  energyTop: float
  energyBottom: float
  energyLeft: float
  energyRight: float


photon_params = [
  "et", "eta", "phi", "maxEnergyCrystal", "energyTop", "energyBottom",
  "energyLeft", "energyRight"
]


def append_photon_dict(photon_dict, line, value):
  for param in photon_params:
    if line.startswith(f"photon_{param}"):
      photon_dict[param] = value
      return


def load_events():
  input_patter = "../photon_info*.txt"

  # open all files matching the patter:
  import glob
  files = glob.glob(input_patter)
  if not files:
    print(f"No files found matching pattern: {input_patter}")
    return []

  events = []

  for file in files:
    with open(file, 'r') as f:
      good_photon_found = False
      all_photons_found = False
      e_gammas_found = False

      good_photon = None
      all_photons = []
      e_gammas = []

      for line in f:
        if "Photon information" in line:
          good_photon_found = True
          continue

        if "All photons information" in line:
          all_photons_found = True
          continue

        if "EGamma objects information" in line:
          e_gammas_found = True
          continue

        try:
          value = float(line.strip().split(":")[-1])
        except ValueError:
          continue

        # read the good photon info
        if good_photon_found and not all_photons_found:
          if line.startswith("photon_et:"):
            et = value
          if line.startswith("photon_eta:"):
            eta = value
          if line.startswith("photon_phi"):
            phi = value
          if line.startswith("photon_maxEnergyCrystal"):
            maxEnergyCrystal = value
          if line.startswith("photon_energyTop"):
            energyTop = value
          if line.startswith("photon_energyBottom"):
            energyBottom = value
          if line.startswith("photon_energyLeft"):
            energyLeft = value
          if line.startswith("photon_energyRight"):
            energyRight = value
            good_photon = Photon(
              et=et,
              eta=eta,
              phi=phi,
              maxEnergyCrystal=maxEnergyCrystal,
              energyTop=energyTop,
              energyBottom=energyBottom,
              energyLeft=energyLeft,
              energyRight=energyRight
            )

        if all_photons_found and not e_gammas_found:
          if line.startswith("photon_et:"):
            et = value
          if line.startswith("photon_eta:"):
            eta = value
          if line.startswith("photon_phi"):
            phi = value
          if line.startswith("photon_maxEnergyCrystal"):
            maxEnergyCrystal = value
          if line.startswith("photon_energyTop"):
            energyTop = value
          if line.startswith("photon_energyBottom"):
            energyBottom = value
          if line.startswith("photon_energyLeft"):
            energyLeft = value
          if line.startswith("photon_energyRight"):
            energyRight = value
            all_photons.append(
              Photon(
                et=et,
                eta=eta,
                phi=phi,
                maxEnergyCrystal=maxEnergyCrystal,
                energyTop=energyTop,
                energyBottom=energyBottom,
                energyLeft=energyLeft,
                energyRight=energyRight
              )
            )

        if e_gammas_found:
          if line.startswith("eGamma_et"):
            et = value
          if line.startswith("eGamma_eta"):
            eta = value
          if line.startswith("eGamma_phi"):
            phi = value
            e_gammas.append(
              Photon(
                et=et,
                eta=eta,
                phi=phi,
                maxEnergyCrystal=0.0,
                energyTop=0.0,
                energyBottom=0.0,
                energyLeft=0.0,
                energyRight=0.0
              )
            )

      events.append({
        "goodPhoton": good_photon,
        "allPhotons": all_photons,
        "eGammas": e_gammas
      })

  return events


def main():
  ROOT.gROOT.SetBatch(True)
  ROOT.gStyle.SetOptStat(0)

  canvas = ROOT.TCanvas("canvas", "canvas", 1000, 2000)
  canvas.Divide(1, 2)

  events = load_events()

  graphs_photon = []
  graphs_all_photons = []
  graphs_egamma = []

  photon_energy = ROOT.TH2D(
    "photon_energy", "Photon Energy", 50, -3, 3, 50, -3.5, 3.5
  )

  colors = [
    ROOT.kRed,
    ROOT.kBlue,
    ROOT.kGreen+1,
    ROOT.kCyan+1,
    ROOT.kMagenta,
    ROOT.kYellow+1,
    ROOT.kOrange,
    ROOT.kBlack,
    ROOT.kGreen + 2,
  ]

  for i, event in enumerate(events):
    graphs_photon.append(ROOT.TGraph())
    graphs_egamma.append(ROOT.TGraph())
    graphs_all_photons.append(ROOT.TGraph())

    graphs_photon[-1].SetMarkerStyle(25)
    graphs_photon[-1].SetMarkerSize(2.5)
    graphs_photon[-1].SetMarkerColor(colors[i])

    graphs_egamma[-1].SetMarkerStyle(20)
    graphs_egamma[-1].SetMarkerSize(1.2)
    graphs_egamma[-1].SetMarkerColor(colors[i])

    graphs_all_photons[-1].SetMarkerStyle(24)
    graphs_all_photons[-1].SetMarkerSize(1.7)
    graphs_all_photons[-1].SetMarkerColor(colors[i])

    photon = event["goodPhoton"]
    graphs_photon[-1].SetPoint(0, photon.eta, photon.phi)
    
    # add a small label with the photon ET next to the point
    label = ROOT.TLatex(photon.eta + 0.05, photon.phi + 0.05, f"{photon.et:.0f} GeV")
    label.SetTextSize(0.02)
    label.SetTextColor(colors[i])
    label.Draw()
    graphs_photon[-1].GetListOfFunctions().Add(label)
    

    eGammas = event["eGammas"]
    for j, eGamma in enumerate(eGammas):
      graphs_egamma[-1].SetPoint(j, eGamma.eta, eGamma.phi)

    all_photons = event["allPhotons"]
    for j, photon in enumerate(all_photons):
      graphs_all_photons[-1].SetPoint(j, photon.eta, photon.phi)

    for photon in event["allPhotons"]:
      # find bin of eta, phi
      bin_x = photon_energy.GetXaxis().FindBin(photon.eta)
      bin_y = photon_energy.GetYaxis().FindBin(photon.phi)

      # fill the bin with max energy, and then surrounding bins with left/right/top/bottom energies
      photon_energy.SetBinContent(bin_x, bin_y, photon.maxEnergyCrystal)
      photon_energy.SetBinContent(bin_x + 1, bin_y, photon.energyRight)
      photon_energy.SetBinContent(bin_x - 1, bin_y, photon.energyLeft)
      photon_energy.SetBinContent(bin_x, bin_y + 1, photon.energyTop)
      photon_energy.SetBinContent(bin_x, bin_y - 1, photon.energyBottom)

  canvas.cd(1)
  dummy = ROOT.TH2D("dummy", "dummy", 100, -3, 3, 100, -3.5, 3.5)
  dummy.SetTitle("")
  dummy.GetXaxis().SetTitle("Eta")
  dummy.GetYaxis().SetTitle("Phi")
  dummy.Draw()

  for graph in graphs_photon:
    graph.DrawClone("P SAME")

  for graph in graphs_egamma:
    graph.DrawClone("P SAME")

  for graph in graphs_all_photons:
    graph.DrawClone("P SAME")

  legend = ROOT.TLegend(0.1, 0.7, 0.3, 0.9)
  legend.AddEntry(graphs_photon[7], "Reco+ID #gamma", "p")
  legend.AddEntry(graphs_all_photons[7], "Reco #gamma", "p")
  legend.AddEntry(graphs_egamma[7], "e/#gamma objects", "p")
  legend.Draw()

  canvas.cd(2)
  photon_energy.SetTitle("Reco #gamma E")
  photon_energy.GetXaxis().SetTitle("Eta")
  photon_energy.GetYaxis().SetTitle("Phi")

  photon_energy.Draw("colz")

  canvas.SaveAs("../etaphi_monophotons.pdf")


if __name__ == "__main__":
  main()
