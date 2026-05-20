import ROOT

input_path = "/eos/cms/store/cmst3/group/lightbylight/tea_samples/emptyBeams/initial/ntuple_{}.root"

n_bins_phi = 20
n_files = 10
energy_max = 2

import math


def get_threshold_with_unc(hist, fraction=0.99):
  total = hist.Integral()
  if total <= 0:
    return 0.0, 0.0

  cumsum = 0.0

  for i in range(1, hist.GetNbinsX() + 1):
    prev = cumsum
    cumsum += hist.GetBinContent(i)

    if cumsum / total >= fraction:
      # --- interpolation inside bin ---
      bin_low = hist.GetBinLowEdge(i)
      bin_width = hist.GetBinWidth(i)
      bin_content = hist.GetBinContent(i)

      if bin_content <= 0:
        return bin_low, bin_width  # fallback

      prev_frac = prev / total
      curr_frac = cumsum / total

      # fractional position inside bin
      t = (fraction - prev_frac) / (curr_frac - prev_frac)
      t = max(0.0, min(1.0, t))

      x_thr = bin_low + t * bin_width

      # --- uncertainty estimate ---
      # sigma_f ~ binomial uncertainty
      sigma_f = math.sqrt(fraction * (1 - fraction) / total)

      # local PDF ≈ bin_content / (total * bin_width)
      pdf = bin_content / (total * bin_width)

      if pdf > 0:
        sigma_x = sigma_f / pdf
      else:
        sigma_x = bin_width  # fallback

      return x_thr, sigma_x

  # if never reached fraction (shouldn’t happen unless weird hist)
  return hist.GetXaxis().GetXmax(), hist.GetBinWidth(hist.GetNbinsX())


def get_threshold(hist, fraction=0.99):
  total = hist.Integral()

  if total == 0:
    print("Empty histogram")
    return 0

  threshold = 0

  for i in range(1, hist.GetNbinsX()):
    if hist.Integral(1, i) / total > fraction:
      threshold = hist.GetBinLowEdge(i)
      break

  print(f"Threshold: {threshold}")
  return threshold


def main():
  ROOT.gROOT.SetBatch(True)
  ROOT.gStyle.SetOptStat(0)

  energy_hist = ROOT.TH1F("energy_hist", "Energy distribution in EB towers;Energy (GeV);Entries", 1000, 0, energy_max)
  phi_hist = ROOT.TH1F("phi_hist", "Phi distribution in EB towers;Phi;Entries", n_bins_phi, -3.14, 3.14)
  phi_vs_energy = ROOT.TH2F("phi_vs_energy", "Phi vs Energy in EB towers;Energy (GeV);Phi", 1000, 0, energy_max, n_bins_phi, -3.14, 3.14)
  phi_hist.Sumw2()

  for i_file in range(n_files):
    print(f"Processing file {i_file}")

    input_file = ROOT.TFile.Open(input_path.format(i_file), "READ")
    tree = input_file.Get("Events")

    for event in tree:
      leading_eb_tower_energy = -1
      leading_eb_tower_phi = -999

      for i in range(100):
        if abs(event.CaloTower_eta[i]) > 1.479:
          continue
        if event.CaloTower_hadE[i] > 0:
          continue
        if event.CaloTower_emE[i] == 0:
          continue

        if event.CaloTower_energy[i] > leading_eb_tower_energy:
          leading_eb_tower_energy = event.CaloTower_energy[i]
          leading_eb_tower_phi = event.CaloTower_phi[i]

      if leading_eb_tower_energy > 0:
        energy_hist.Fill(leading_eb_tower_energy)
        phi_hist.Fill(leading_eb_tower_phi)
        phi_vs_energy.Fill(leading_eb_tower_energy, leading_eb_tower_phi)

  canvas = ROOT.TCanvas("canvas", "canvas", 1000, 1000)
  canvas.Divide(2, 2)

  canvas.cd(1)
  ROOT.gPad.SetLogy()
  energy_hist.Draw()

  threshold = get_threshold(energy_hist, 0.99)
  print(f"99% threshold: {threshold:.2f} GeV")

  canvas.cd(2)
  phi_hist.Draw()
  phi_hist.GetYaxis().SetRangeUser(0, 10000)

  canvas.cd(3)

  # find energy threshold for each bin in phi (x-axis) and plot that threshold as a function of phi
  thresholds_vs_phi = ROOT.TH1F("thresholds_vs_phi", "Energy threshold vs Phi in EB towers;Phi;Energy threshold (GeV)", 20, -3.14, 3.14)

  for i in range(1, phi_hist.GetNbinsX() + 1):
    energy_projection = phi_vs_energy.ProjectionX(f"energy_projection_phi_{i}", i, i)
    threshold, unc = get_threshold_with_unc(energy_projection, 0.99)
    thresholds_vs_phi.SetBinContent(i, threshold)
    thresholds_vs_phi.SetBinError(i, unc)

  rebin = 2
  thresholds_vs_phi.Rebin(rebin)
  thresholds_vs_phi.Scale(1.0 / rebin)
  thresholds_vs_phi.Draw()

  canvas.SaveAs("../plots/energy_distribution_EB.pdf")


if __name__ == "__main__":
  main()
