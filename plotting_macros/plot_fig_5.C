#ifdef __CLING__
#pragma cling optimize(0)
#endif

#include <TGraphAsymmErrors.h>
#include <TMath.h>

#include <vector>

TGraphAsymmErrors *AverageVariableNPoints(const TGraphAsymmErrors *original, const std::vector<int> &aggregationLengths) {
  // Prepare vectors to hold averaged points and errors
  std::vector<double> x_avg, y_avg, exl_avg, exh_avg, eyl_avg, eyh_avg;

  int nPoints = original->GetN();
  double x, y, exl, exh, eyl, eyh;

  // Index for aggregation lengths
  size_t aggIndex = 0;
  int pointsToAggregate = aggregationLengths[aggIndex];

  // Temporary variables to accumulate values
  double x_sum = 0, y_sum = 0, exl_sum = 0, exh_sum = 0, eyl_sum2 = 0, eyh_sum2 = 0;
  int count = 0;

  Double_t binEdges[41] = {0.001, 0.0025, 0.005, 0.0075, 0.01,  0.0125, 0.015, 0.0175, 0.02,  0.0225, 0.025, 0.0275, 0.03,  0.0325,
                         0.035, 0.0375, 0.04,  0.0425, 0.045, 0.0475, 0.05,  0.0525, 0.055, 0.0575, 0.06,  0.0625, 0.065, 0.0675,
                         0.07,  0.0725, 0.075, 0.0775, 0.08,  0.0825, 0.085, 0.0875, 0.09,  0.0925, 0.095, 0.0975, 0.1};

      int currentBinEdgeIndex = 0;

  for (int i = 0; i < nPoints; ++i) {
    original->GetPoint(i, x, y);
    exl = original->GetErrorXlow(i);
    exh = original->GetErrorXhigh(i);
    eyl = original->GetErrorYlow(i);
    eyh = original->GetErrorYhigh(i);

    // Accumulate sums
    x_sum += x;
    if (y > 0) y_sum += y;
    exl_sum += exl;
    exh_sum += exh;
    if (y > 0)
      eyl_sum2 += eyl * eyl;
    else
      eyl_sum2 += 1.84;
    if (y > 0)
      eyh_sum2 += eyh * eyh;
    else
      eyh_sum2 += 1.84;
    count++;

    // Check if we reached the number of points to aggregate
    if (count == pointsToAggregate) {
      double logLowerEdge = std::log(binEdges[currentBinEdgeIndex]);
      double logUpperEdge = std::log(binEdges[currentBinEdgeIndex + count]);
      double avg_log_x = (logLowerEdge + logUpperEdge) / 2;
      double avg_x = std::exp(avg_log_x);  // Convert back to linear scale

      // double avg_x = x_sum / pointsToAggregate;

      x_avg.push_back(avg_x);
      y_avg.push_back(y_sum / pointsToAggregate);
      // exl_avg.push_back(exl_sum / pointsToAggregate);
      // exh_avg.push_back(exh_sum / pointsToAggregate);

      exl_avg.push_back(avg_x - binEdges[currentBinEdgeIndex]);
      exh_avg.push_back(binEdges[currentBinEdgeIndex + count] - avg_x);

      eyl_avg.push_back(TMath::Sqrt(eyl_sum2) / pointsToAggregate);
      eyh_avg.push_back(TMath::Sqrt(eyh_sum2) / pointsToAggregate);

       currentBinEdgeIndex += count;
      // Reset for next batch
      x_sum = y_sum = exl_sum = exh_sum = eyl_sum2 = eyh_sum2 = 0;
      count = 0;

      // Move to the next aggregation length
      if (aggIndex < aggregationLengths.size() - 1) {
        aggIndex++;
        pointsToAggregate = aggregationLengths[aggIndex];
      }
    }
  }

  // Check if there are leftover points that did not reach the full aggregate count
  if (count > 0) {
    x_avg.push_back(x_sum / count);
    y_avg.push_back(y_sum / count);
    exl_avg.push_back(exl_sum / count);
    exh_avg.push_back(exh_sum / count);
    eyl_avg.push_back(TMath::Sqrt(eyl_sum2) / count);
    eyh_avg.push_back(TMath::Sqrt(eyh_sum2) / count);
  }

  // Create a new graph with averaged data
  TGraphAsymmErrors *averagedGraph = new TGraphAsymmErrors(x_avg.size());
  for (size_t i = 0; i < x_avg.size(); ++i) {
    cout << "Setting point: " << x_avg[i] << "\t" << y_avg[i] << endl;
    averagedGraph->SetPoint(i, x_avg[i], y_avg[i]);
    averagedGraph->SetPointError(i, exl_avg[i], exh_avg[i], eyl_avg[i], eyh_avg[i]);
  }

  return averagedGraph;
}

void plot_fig_5() {
  gROOT->SetBatch(kTRUE);
  //=========Macro generated from canvas: canvas/canvas
  //=========  (Sun Mar 31 12:42:21 2024) by ROOT version 6.26/08
  TCanvas *canvas = new TCanvas("canvas", "canvas", 0, 0, 800, 600);
  gStyle->SetOptStat(0);
  canvas->SetHighLightColor(2);
  canvas->Range(0, 0, 1, 1);
  canvas->SetFillColor(0);
  canvas->SetBorderMode(0);
  canvas->SetBorderSize(2);
  canvas->SetFrameBorderMode(0);

  // ------------>Primitives in pad: pad1
  TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1);
  pad1->Draw();
  pad1->cd();
  pad1->Range(-3.25, -0.4235561, -0.75, 24.49151);
  pad1->SetFillColor(0);
  pad1->SetBorderMode(0);
  pad1->SetBorderSize(2);
  pad1->SetLogx();
  pad1->SetBottomMargin(0.017);
  pad1->SetFrameBorderMode(0);
  pad1->SetFrameBorderMode(0);

  THStack *stack = new THStack();
  stack->SetName("stack");
  stack->SetTitle("");
  stack->SetMinimum(0);
  stack->SetMaximum(24);
  Double_t xAxis1[41] = {0.001, 0.0025, 0.005, 0.0075, 0.01,  0.0125, 0.015, 0.0175, 0.02,  0.0225, 0.025, 0.0275, 0.03,  0.0325,
                         0.035, 0.0375, 0.04,  0.0425, 0.045, 0.0475, 0.05,  0.0525, 0.055, 0.0575, 0.06,  0.0625, 0.065, 0.0675,
                         0.07,  0.0725, 0.075, 0.0775, 0.08,  0.0825, 0.085, 0.0875, 0.09,  0.0925, 0.095, 0.0975, 0.105};

  TH1F *stack_stack_1 = new TH1F("stack_stack_1", "", 40, xAxis1);
  stack_stack_1->SetMinimum(0);
  stack_stack_1->SetMaximum(24);
  stack_stack_1->SetDirectory(0);
  stack_stack_1->SetStats(0);

  Int_t ci;       // for color index setting
  TColor *color;  // for color definition with alpha
  ci = TColor::GetColor("#000099");
  stack_stack_1->SetLineColor(ci);
  stack_stack_1->GetXaxis()->SetLabelFont(42);
  stack_stack_1->GetXaxis()->SetLabelSize(0);
  stack_stack_1->GetXaxis()->SetTitleOffset(1);
  stack_stack_1->GetXaxis()->SetTitleFont(42);
  stack_stack_1->GetYaxis()->SetTitle("Events / 0.0025");
  stack_stack_1->GetYaxis()->SetLabelFont(43);
  stack_stack_1->GetYaxis()->SetLabelSize(20);
  stack_stack_1->GetYaxis()->SetTitleSize(20);
  stack_stack_1->GetYaxis()->SetTitleOffset(1.55);
  stack_stack_1->GetYaxis()->SetTitleFont(43);
  stack_stack_1->GetZaxis()->SetLabelFont(42);
  stack_stack_1->GetZaxis()->SetTitleOffset(1);
  stack_stack_1->GetZaxis()->SetTitleFont(42);
  stack->SetHistogram(stack_stack_1);

  Double_t xAxis2[41] = {0.001, 0.0025, 0.005, 0.0075, 0.01,  0.0125, 0.015, 0.0175, 0.02,  0.0225, 0.025, 0.0275, 0.03,  0.0325,
                         0.035, 0.0375, 0.04,  0.0425, 0.045, 0.0475, 0.05,  0.0525, 0.055, 0.0575, 0.06,  0.0625, 0.065, 0.0675,
                         0.07,  0.0725, 0.075, 0.0775, 0.08,  0.0825, 0.085, 0.0875, 0.09,  0.0925, 0.095, 0.0975, 0.105};

  TH1D *cep_stack_1 = new TH1D("cep_stack_1", "diphoton_acoplanarity40", 40, xAxis2);
  cep_stack_1->SetBinContent(1, 2.659694);
  cep_stack_1->SetBinContent(2, 2.604906);
  cep_stack_1->SetBinContent(3, 2.532686);
  cep_stack_1->SetBinContent(4, 2.385755);
  cep_stack_1->SetBinContent(5, 2.485369);
  cep_stack_1->SetBinContent(6, 2.360852);
  cep_stack_1->SetBinContent(7, 2.263728);
  cep_stack_1->SetBinContent(8, 2.104346);
  cep_stack_1->SetBinContent(9, 2.236334);
  cep_stack_1->SetBinContent(10, 2.101855);
  cep_stack_1->SetBinContent(11, 2.169095);
  cep_stack_1->SetBinContent(12, 1.85033);
  cep_stack_1->SetBinContent(13, 1.648612);
  cep_stack_1->SetBinContent(14, 1.593824);
  cep_stack_1->SetBinContent(15, 1.449384);
  cep_stack_1->SetBinContent(16, 1.367202);
  cep_stack_1->SetBinContent(17, 1.327357);
  cep_stack_1->SetBinContent(18, 1.240194);
  cep_stack_1->SetBinContent(19, 1.110696);
  cep_stack_1->SetBinContent(20, 0.99614);
  cep_stack_1->SetBinContent(21, 0.9836883);
  cep_stack_1->SetBinContent(22, 0.9662558);
  cep_stack_1->SetBinContent(23, 0.8168348);
  cep_stack_1->SetBinContent(24, 0.6798656);
  cep_stack_1->SetBinContent(25, 0.6524717);
  cep_stack_1->SetBinContent(26, 0.590213);
  cep_stack_1->SetBinContent(27, 0.5653095);
  cep_stack_1->SetBinContent(28, 0.4806376);
  cep_stack_1->SetBinContent(29, 0.4233595);
  cep_stack_1->SetBinContent(30, 0.3611008);
  cep_stack_1->SetBinContent(31, 0.3436683);
  cep_stack_1->SetBinContent(32, 0.3212552);
  cep_stack_1->SetBinContent(33, 0.291371);
  cep_stack_1->SetBinContent(34, 0.3262359);
  cep_stack_1->SetBinContent(35, 0.2216412);
  cep_stack_1->SetBinContent(36, 0.1842859);
  cep_stack_1->SetBinContent(37, 0.1568921);
  cep_stack_1->SetBinContent(38, 0.149421);
  cep_stack_1->SetBinContent(39, 0.1195368);
  cep_stack_1->SetBinContent(40, 0.1120658);
  cep_stack_1->SetBinError(1, 0.08138531);
  cep_stack_1->SetBinError(2, 0.08054271);
  cep_stack_1->SetBinError(3, 0.07941835);
  cep_stack_1->SetBinError(4, 0.07708026);
  cep_stack_1->SetBinError(5, 0.07867299);
  cep_stack_1->SetBinError(6, 0.07667691);
  cep_stack_1->SetBinError(7, 0.07508313);
  cep_stack_1->SetBinError(8, 0.0723917);
  cep_stack_1->SetBinError(9, 0.07462745);
  cep_stack_1->SetBinError(10, 0.07234885);
  cep_stack_1->SetBinError(11, 0.07349698);
  cep_stack_1->SetBinError(12, 0.06788203);
  cep_stack_1->SetBinError(13, 0.06407512);
  cep_stack_1->SetBinError(14, 0.06300143);
  cep_stack_1->SetBinError(15, 0.06007889);
  cep_stack_1->SetBinError(16, 0.05835077);
  cep_stack_1->SetBinError(17, 0.0574942);
  cep_stack_1->SetBinError(18, 0.05557444);
  cep_stack_1->SetBinError(19, 0.05259299);
  cep_stack_1->SetBinError(20, 0.049807);
  cep_stack_1->SetBinError(21, 0.04949473);
  cep_stack_1->SetBinError(22, 0.04905421);
  cep_stack_1->SetBinError(23, 0.04510216);
  cep_stack_1->SetBinError(24, 0.04114734);
  cep_stack_1->SetBinError(25, 0.04030984);
  cep_stack_1->SetBinError(26, 0.03833845);
  cep_stack_1->SetBinError(27, 0.03752091);
  cep_stack_1->SetBinError(28, 0.03459705);
  cep_stack_1->SetBinError(29, 0.03247019);
  cep_stack_1->SetBinError(30, 0.02998779);
  cep_stack_1->SetBinError(31, 0.02925499);
  cep_stack_1->SetBinError(32, 0.02828494);
  cep_stack_1->SetBinError(33, 0.02693726);
  cep_stack_1->SetBinError(34, 0.02850336);
  cep_stack_1->SetBinError(35, 0.02349392);
  cep_stack_1->SetBinError(36, 0.0214228);
  cep_stack_1->SetBinError(37, 0.01976654);
  cep_stack_1->SetBinError(38, 0.01929017);
  cep_stack_1->SetBinError(39, 0.01725365);
  cep_stack_1->SetBinError(40, 0.01670578);
  cep_stack_1->SetEntries(40);

  ci = TColor::GetColor("#6699ff");
  cep_stack_1->SetFillColor(ci);

  ci = TColor::GetColor("#000099");
  cep_stack_1->SetLineColor(ci);
  cep_stack_1->GetXaxis()->SetLabelFont(42);
  cep_stack_1->GetXaxis()->SetTitleOffset(1);
  cep_stack_1->GetXaxis()->SetTitleFont(42);
  cep_stack_1->GetYaxis()->SetLabelFont(42);
  cep_stack_1->GetYaxis()->SetTitleFont(42);
  cep_stack_1->GetZaxis()->SetLabelFont(42);
  cep_stack_1->GetZaxis()->SetTitleOffset(1);
  cep_stack_1->GetZaxis()->SetTitleFont(42);
  stack->Add(cep_stack_1, "");
  Double_t xAxis3[41] = {0.001, 0.0025, 0.005, 0.0075, 0.01,  0.0125, 0.015, 0.0175, 0.02,  0.0225, 0.025, 0.0275, 0.03,  0.0325,
                         0.035, 0.0375, 0.04,  0.0425, 0.045, 0.0475, 0.05,  0.0525, 0.055, 0.0575, 0.06,  0.0625, 0.065, 0.0675,
                         0.07,  0.0725, 0.075, 0.0775, 0.08,  0.0825, 0.085, 0.0875, 0.09,  0.0925, 0.095, 0.0975, 0.105};

  TH1D *qed_stack_2 = new TH1D("qed_stack_2", "diphoton_acoplanarity40", 40, xAxis3);
  qed_stack_2->SetBinContent(1, 0.2945051);
  qed_stack_2->SetBinContent(2, 0.4417576);
  qed_stack_2->SetBinContent(3, 0.2392854);
  qed_stack_2->SetBinContent(4, 0.2945051);
  qed_stack_2->SetBinContent(5, 0.3681314);
  qed_stack_2->SetBinContent(6, 0.4049445);
  qed_stack_2->SetBinContent(7, 0.2392854);
  qed_stack_2->SetBinContent(8, 0.3313182);
  qed_stack_2->SetBinContent(9, 0.4601642);
  qed_stack_2->SetBinContent(10, 0.4233511);
  qed_stack_2->SetBinContent(11, 0.2576919);
  qed_stack_2->SetBinContent(12, 0.4417576);
  qed_stack_2->SetBinContent(13, 0.3681314);
  qed_stack_2->SetBinContent(14, 0.3313182);
  qed_stack_2->SetBinContent(15, 0.2024722);
  qed_stack_2->SetBinContent(16, 0.3497248);
  qed_stack_2->SetBinContent(17, 0.128846);
  qed_stack_2->SetBinContent(18, 0.2576919);
  qed_stack_2->SetBinContent(19, 0.2208788);
  qed_stack_2->SetBinContent(20, 0.2024722);
  qed_stack_2->SetBinContent(21, 0.2024722);
  qed_stack_2->SetBinContent(22, 0.09203284);
  qed_stack_2->SetBinContent(23, 0.1472525);
  qed_stack_2->SetBinContent(24, 0.128846);
  qed_stack_2->SetBinContent(25, 0.0552197);
  qed_stack_2->SetBinContent(26, 0.07362627);
  qed_stack_2->SetBinContent(27, 0.1104394);
  qed_stack_2->SetBinContent(28, 0.03681314);
  qed_stack_2->SetBinContent(29, 0.03681314);
  qed_stack_2->SetBinContent(30, 0.07362627);
  qed_stack_2->SetBinContent(34, 0.03681314);
  qed_stack_2->SetBinContent(35, 0.01840657);
  qed_stack_2->SetBinContent(37, 0.03681314);
  qed_stack_2->SetBinContent(38, 0.01840657);
  qed_stack_2->SetBinContent(39, 0.01840657);
  qed_stack_2->SetBinContent(40, 0.01840657);
  qed_stack_2->SetBinError(1, 0.07362627);
  qed_stack_2->SetBinError(2, 0.0901734);
  qed_stack_2->SetBinError(3, 0.06636582);
  qed_stack_2->SetBinError(4, 0.07362627);
  qed_stack_2->SetBinError(5, 0.08231667);
  qed_stack_2->SetBinError(6, 0.08633445);
  qed_stack_2->SetBinError(7, 0.06636582);
  qed_stack_2->SetBinError(8, 0.07809245);
  qed_stack_2->SetBinError(9, 0.09203284);
  qed_stack_2->SetBinError(10, 0.0882748);
  qed_stack_2->SetBinError(11, 0.06887107);
  qed_stack_2->SetBinError(12, 0.0901734);
  qed_stack_2->SetBinError(13, 0.08231667);
  qed_stack_2->SetBinError(14, 0.07809245);
  qed_stack_2->SetBinError(15, 0.06104768);
  qed_stack_2->SetBinError(16, 0.08023237);
  qed_stack_2->SetBinError(17, 0.0486992);
  qed_stack_2->SetBinError(18, 0.06887107);
  qed_stack_2->SetBinError(19, 0.06376222);
  qed_stack_2->SetBinError(20, 0.06104768);
  qed_stack_2->SetBinError(21, 0.06104768);
  qed_stack_2->SetBinError(22, 0.04115834);
  qed_stack_2->SetBinError(23, 0.05206164);
  qed_stack_2->SetBinError(24, 0.0486992);
  qed_stack_2->SetBinError(25, 0.03188111);
  qed_stack_2->SetBinError(26, 0.03681314);
  qed_stack_2->SetBinError(27, 0.0450867);
  qed_stack_2->SetBinError(28, 0.02603082);
  qed_stack_2->SetBinError(29, 0.02603082);
  qed_stack_2->SetBinError(30, 0.03681314);
  qed_stack_2->SetBinError(31, 1.84);
  qed_stack_2->SetBinError(32, 1.84);
  qed_stack_2->SetBinError(33, 1.84);
  qed_stack_2->SetBinError(34, 0.02603082);
  qed_stack_2->SetBinError(35, 0.01840657);
  qed_stack_2->SetBinError(36, 1.84);
  qed_stack_2->SetBinError(37, 0.02603082);
  qed_stack_2->SetBinError(38, 0.01840657);
  qed_stack_2->SetBinError(39, 0.01840657);
  qed_stack_2->SetBinError(40, 0.01840657);
  qed_stack_2->SetEntries(40);

  ci = TColor::GetColor("#ffff00");
  qed_stack_2->SetFillColor(ci);

  ci = TColor::GetColor("#ffff00");
  qed_stack_2->SetLineColor(ci);
  qed_stack_2->GetXaxis()->SetLabelFont(42);
  qed_stack_2->GetXaxis()->SetTitleOffset(1);
  qed_stack_2->GetXaxis()->SetTitleFont(42);
  qed_stack_2->GetYaxis()->SetLabelFont(42);
  qed_stack_2->GetYaxis()->SetTitleFont(42);
  qed_stack_2->GetZaxis()->SetLabelFont(42);
  qed_stack_2->GetZaxis()->SetTitleOffset(1);
  qed_stack_2->GetZaxis()->SetTitleFont(42);
  stack->Add(qed_stack_2, "");
  Double_t xAxis4[41] = {0.001, 0.0025, 0.005, 0.0075, 0.01,  0.0125, 0.015, 0.0175, 0.02,  0.0225, 0.025, 0.0275, 0.03,  0.0325,
                         0.035, 0.0375, 0.04,  0.0425, 0.045, 0.0475, 0.05,  0.0525, 0.055, 0.0575, 0.06,  0.0625, 0.065, 0.0675,
                         0.07,  0.0725, 0.075, 0.0775, 0.08,  0.0825, 0.085, 0.0875, 0.09,  0.0925, 0.095, 0.0975, 0.105};

  TH1D *qed_starlight_stack_3 = new TH1D("qed_starlight_stack_3", "diphoton_acoplanarity40", 40, xAxis4);
  qed_starlight_stack_3->SetBinContent(1, 0.2443617);
  qed_starlight_stack_3->SetBinContent(2, 0.330607);
  qed_starlight_stack_3->SetBinContent(3, 0.1437422);
  qed_starlight_stack_3->SetBinContent(4, 0.2587359);
  qed_starlight_stack_3->SetBinContent(5, 0.2731102);
  qed_starlight_stack_3->SetBinContent(6, 0.2443617);
  qed_starlight_stack_3->SetBinContent(7, 0.330607);
  qed_starlight_stack_3->SetBinContent(8, 0.2299875);
  qed_starlight_stack_3->SetBinContent(9, 0.3593555);
  qed_starlight_stack_3->SetBinContent(10, 0.2587359);
  qed_starlight_stack_3->SetBinContent(11, 0.2587359);
  qed_starlight_stack_3->SetBinContent(12, 0.330607);
  qed_starlight_stack_3->SetBinContent(13, 0.3593555);
  qed_starlight_stack_3->SetBinContent(14, 0.3881039);
  qed_starlight_stack_3->SetBinContent(15, 0.2012391);
  qed_starlight_stack_3->SetBinContent(16, 0.2443617);
  qed_starlight_stack_3->SetBinContent(17, 0.1724906);
  qed_starlight_stack_3->SetBinContent(18, 0.1581164);
  qed_starlight_stack_3->SetBinContent(19, 0.1149937);
  qed_starlight_stack_3->SetBinContent(20, 0.1724906);
  qed_starlight_stack_3->SetBinContent(21, 0.1724906);
  qed_starlight_stack_3->SetBinContent(22, 0.1006195);
  qed_starlight_stack_3->SetBinContent(23, 0.07187109);
  qed_starlight_stack_3->SetBinContent(24, 0.07187109);
  qed_starlight_stack_3->SetBinContent(25, 0.02874844);
  qed_starlight_stack_3->SetBinContent(26, 0.05749687);
  qed_starlight_stack_3->SetBinContent(27, 0.01437422);
  qed_starlight_stack_3->SetBinContent(28, 0.01437422);
  qed_starlight_stack_3->SetBinContent(30, 0.01437422);
  qed_starlight_stack_3->SetBinContent(31, 0.05749687);
  qed_starlight_stack_3->SetBinContent(33, 0.01437422);
  qed_starlight_stack_3->SetBinContent(34, 0.01437422);
  qed_starlight_stack_3->SetBinContent(36, 0.02874844);
  qed_starlight_stack_3->SetBinContent(40, 0.01437422);
  qed_starlight_stack_3->SetBinError(1, 0.05926642);
  qed_starlight_stack_3->SetBinError(2, 0.06893633);
  qed_starlight_stack_3->SetBinError(3, 0.04545527);
  qed_starlight_stack_3->SetBinError(4, 0.06098464);
  qed_starlight_stack_3->SetBinError(5, 0.06265577);
  qed_starlight_stack_3->SetBinError(6, 0.05926642);
  qed_starlight_stack_3->SetBinError(7, 0.06893633);
  qed_starlight_stack_3->SetBinError(8, 0.05749687);
  qed_starlight_stack_3->SetBinError(9, 0.07187109);
  qed_starlight_stack_3->SetBinError(10, 0.06098464);
  qed_starlight_stack_3->SetBinError(11, 0.06098464);
  qed_starlight_stack_3->SetBinError(12, 0.06893633);
  qed_starlight_stack_3->SetBinError(13, 0.07187109);
  qed_starlight_stack_3->SetBinError(14, 0.07469063);
  qed_starlight_stack_3->SetBinError(15, 0.0537834);
  qed_starlight_stack_3->SetBinError(16, 0.05926642);
  qed_starlight_stack_3->SetBinError(17, 0.04979375);
  qed_starlight_stack_3->SetBinError(18, 0.04767389);
  qed_starlight_stack_3->SetBinError(19, 0.04065643);
  qed_starlight_stack_3->SetBinError(20, 0.04979375);
  qed_starlight_stack_3->SetBinError(21, 0.04979375);
  qed_starlight_stack_3->SetBinError(22, 0.03803061);
  qed_starlight_stack_3->SetBinError(23, 0.03214173);
  qed_starlight_stack_3->SetBinError(24, 0.03214173);
  qed_starlight_stack_3->SetBinError(25, 0.02032821);
  qed_starlight_stack_3->SetBinError(26, 0.02874844);
  qed_starlight_stack_3->SetBinError(27, 0.01437422);
  qed_starlight_stack_3->SetBinError(28, 0.01437422);
  qed_starlight_stack_3->SetBinError(29, 1.84);
  qed_starlight_stack_3->SetBinError(30, 0.01437422);
  qed_starlight_stack_3->SetBinError(31, 0.02874844);
  qed_starlight_stack_3->SetBinError(32, 1.84);
  qed_starlight_stack_3->SetBinError(33, 0.01437422);
  qed_starlight_stack_3->SetBinError(34, 0.01437422);
  qed_starlight_stack_3->SetBinError(35, 1.84);
  qed_starlight_stack_3->SetBinError(36, 0.02032821);
  qed_starlight_stack_3->SetBinError(37, 1.84);
  qed_starlight_stack_3->SetBinError(38, 1.84);
  qed_starlight_stack_3->SetBinError(39, 1.84);
  qed_starlight_stack_3->SetBinError(40, 0.01437422);
  qed_starlight_stack_3->SetEntries(40);

  ci = TColor::GetColor("#ffff00");
  qed_starlight_stack_3->SetFillColor(ci);

  ci = TColor::GetColor("#000099");
  qed_starlight_stack_3->SetLineColor(ci);
  qed_starlight_stack_3->GetXaxis()->SetLabelFont(42);
  qed_starlight_stack_3->GetXaxis()->SetTitleOffset(1);
  qed_starlight_stack_3->GetXaxis()->SetTitleFont(42);
  qed_starlight_stack_3->GetYaxis()->SetLabelFont(42);
  qed_starlight_stack_3->GetYaxis()->SetTitleFont(42);
  qed_starlight_stack_3->GetZaxis()->SetLabelFont(42);
  qed_starlight_stack_3->GetZaxis()->SetTitleOffset(1);
  qed_starlight_stack_3->GetZaxis()->SetTitleFont(42);
  stack->Add(qed_starlight_stack_3, "");
  Double_t xAxis5[41] = {0.001, 0.0025, 0.005, 0.0075, 0.01,  0.0125, 0.015, 0.0175, 0.02,  0.0225, 0.025, 0.0275, 0.03,  0.0325,
                         0.035, 0.0375, 0.04,  0.0425, 0.045, 0.0475, 0.05,  0.0525, 0.055, 0.0575, 0.06,  0.0625, 0.065, 0.0675,
                         0.07,  0.0725, 0.075, 0.0775, 0.08,  0.0825, 0.085, 0.0875, 0.09,  0.0925, 0.095, 0.0975, 0.105};

  TH1D *lbl_stack_4 = new TH1D("lbl_stack_4", "diphoton_acoplanarity40", 40, xAxis5);
  lbl_stack_4->SetBinContent(1, 9.0721);
  lbl_stack_4->SetBinContent(2, 2.488606);
  lbl_stack_4->SetBinContent(3, 0.8710121);
  lbl_stack_4->SetBinContent(4, 0.3902587);
  lbl_stack_4->SetBinContent(5, 0.2884521);
  lbl_stack_4->SetBinContent(6, 0.220581);
  lbl_stack_4->SetBinContent(7, 0.1866455);
  lbl_stack_4->SetBinContent(8, 0.1018066);
  lbl_stack_4->SetBinContent(9, 0.1300862);
  lbl_stack_4->SetBinContent(10, 0.09615069);
  lbl_stack_4->SetBinContent(11, 0.08483884);
  lbl_stack_4->SetBinContent(12, 0.06221515);
  lbl_stack_4->SetBinContent(13, 0.06787107);
  lbl_stack_4->SetBinContent(14, 0.01696777);
  lbl_stack_4->SetBinContent(15, 0.03959146);
  lbl_stack_4->SetBinContent(16, 0.02827961);
  lbl_stack_4->SetBinContent(17, 0.02262369);
  lbl_stack_4->SetBinContent(18, 0.01696777);
  lbl_stack_4->SetBinContent(19, 0.01696777);
  lbl_stack_4->SetBinContent(20, 0.005655923);
  lbl_stack_4->SetBinContent(21, 0.02262369);
  lbl_stack_4->SetBinContent(22, 0.04524738);
  lbl_stack_4->SetBinContent(23, 0.01696777);
  lbl_stack_4->SetBinContent(24, 0.005655923);
  lbl_stack_4->SetBinContent(25, 0.005655923);
  lbl_stack_4->SetBinContent(26, 0.005655923);
  lbl_stack_4->SetBinContent(27, 0.01131185);
  lbl_stack_4->SetBinError(1, 0.2265195);
  lbl_stack_4->SetBinError(2, 0.1186396);
  lbl_stack_4->SetBinError(3, 0.07018816);
  lbl_stack_4->SetBinError(4, 0.04698162);
  lbl_stack_4->SetBinError(5, 0.04039137);
  lbl_stack_4->SetBinError(6, 0.03532123);
  lbl_stack_4->SetBinError(7, 0.0324908);
  lbl_stack_4->SetBinError(8, 0.02399605);
  lbl_stack_4->SetBinError(9, 0.02712485);
  lbl_stack_4->SetBinError(10, 0.02331997);
  lbl_stack_4->SetBinError(11, 0.02190529);
  lbl_stack_4->SetBinError(12, 0.01875857);
  lbl_stack_4->SetBinError(13, 0.01959269);
  lbl_stack_4->SetBinError(14, 0.009796346);
  lbl_stack_4->SetBinError(15, 0.01496417);
  lbl_stack_4->SetBinError(16, 0.01264703);
  lbl_stack_4->SetBinError(17, 0.01131185);
  lbl_stack_4->SetBinError(18, 0.009796346);
  lbl_stack_4->SetBinError(19, 0.009796346);
  lbl_stack_4->SetBinError(20, 0.005655923);
  lbl_stack_4->SetBinError(21, 0.01131185);
  lbl_stack_4->SetBinError(22, 0.01599737);
  lbl_stack_4->SetBinError(23, 0.009796346);
  lbl_stack_4->SetBinError(24, 0.005655923);
  lbl_stack_4->SetBinError(25, 0.005655923);
  lbl_stack_4->SetBinError(26, 0.005655923);
  lbl_stack_4->SetBinError(27, 0.007998683);
  lbl_stack_4->SetBinError(28, 1.84);
  lbl_stack_4->SetBinError(29, 1.84);
  lbl_stack_4->SetBinError(30, 1.84);
  lbl_stack_4->SetBinError(31, 1.84);
  lbl_stack_4->SetBinError(32, 1.84);
  lbl_stack_4->SetBinError(33, 1.84);
  lbl_stack_4->SetBinError(34, 1.84);
  lbl_stack_4->SetBinError(35, 1.84);
  lbl_stack_4->SetBinError(36, 1.84);
  lbl_stack_4->SetBinError(37, 1.84);
  lbl_stack_4->SetBinError(38, 1.84);
  lbl_stack_4->SetBinError(39, 1.84);
  lbl_stack_4->SetEntries(40);

  ci = TColor::GetColor("#ff9933");
  lbl_stack_4->SetFillColor(ci);

  ci = TColor::GetColor("#000099");
  lbl_stack_4->SetLineColor(ci);
  lbl_stack_4->GetXaxis()->SetLabelFont(42);
  lbl_stack_4->GetXaxis()->SetTitleOffset(1);
  lbl_stack_4->GetXaxis()->SetTitleFont(42);
  lbl_stack_4->GetYaxis()->SetLabelFont(42);
  lbl_stack_4->GetYaxis()->SetTitleFont(42);
  lbl_stack_4->GetZaxis()->SetLabelFont(42);
  lbl_stack_4->GetZaxis()->SetTitleOffset(1);
  lbl_stack_4->GetZaxis()->SetTitleFont(42);
  stack->Add(lbl_stack_4, "");
  stack->Draw("hist");
  Double_t xAxis6[41] = {0.001, 0.0025, 0.005, 0.0075, 0.01,  0.0125, 0.015, 0.0175, 0.02,  0.0225, 0.025, 0.0275, 0.03,  0.0325,
                         0.035, 0.0375, 0.04,  0.0425, 0.045, 0.0475, 0.05,  0.0525, 0.055, 0.0575, 0.06,  0.0625, 0.065, 0.0675,
                         0.07,  0.0725, 0.075, 0.0775, 0.08,  0.0825, 0.085, 0.0875, 0.09,  0.0925, 0.095, 0.0975, 0.105};

  TH1D *cep__1 = new TH1D("cep__1", "diphoton_acoplanarity40", 40, xAxis6);
  cep__1->SetBinContent(1, 12.27066);
  cep__1->SetBinContent(2, 5.865877);
  cep__1->SetBinContent(3, 3.786726);
  cep__1->SetBinContent(4, 3.329255);
  cep__1->SetBinContent(5, 3.415063);
  cep__1->SetBinContent(6, 3.230739);
  cep__1->SetBinContent(7, 3.020266);
  cep__1->SetBinContent(8, 2.767458);
  cep__1->SetBinContent(9, 3.18594);
  cep__1->SetBinContent(10, 2.880093);
  cep__1->SetBinContent(11, 2.770362);
  cep__1->SetBinContent(12, 2.68491);
  cep__1->SetBinContent(13, 2.44397);
  cep__1->SetBinContent(14, 2.330214);
  cep__1->SetBinContent(15, 1.892687);
  cep__1->SetBinContent(16, 1.989568);
  cep__1->SetBinContent(17, 1.651317);
  cep__1->SetBinContent(18, 1.67297);
  cep__1->SetBinContent(19, 1.463536);
  cep__1->SetBinContent(20, 1.376759);
  cep__1->SetBinContent(21, 1.381275);
  cep__1->SetBinContent(22, 1.204156);
  cep__1->SetBinContent(23, 1.052926);
  cep__1->SetBinContent(24, 0.8862386);
  cep__1->SetBinContent(25, 0.7420958);
  cep__1->SetBinContent(26, 0.726992);
  cep__1->SetBinContent(27, 0.7014349);
  cep__1->SetBinContent(28, 0.5318249);
  cep__1->SetBinContent(29, 0.4601727);
  cep__1->SetBinContent(30, 0.4491013);
  cep__1->SetBinContent(31, 0.4011652);
  cep__1->SetBinContent(32, 0.3212552);
  cep__1->SetBinContent(33, 0.3057452);
  cep__1->SetBinContent(34, 0.3774232);
  cep__1->SetBinContent(35, 0.2400477);
  cep__1->SetBinContent(36, 0.2130343);
  cep__1->SetBinContent(37, 0.1937052);
  cep__1->SetBinContent(38, 0.1678276);
  cep__1->SetBinContent(39, 0.1379434);
  cep__1->SetBinContent(40, 0.1448465);
  cep__1->SetBinError(1, 2.822252);
  cep__1->SetBinError(2, 1.349152);
  cep__1->SetBinError(3, 0.8709469);
  cep__1->SetBinError(4, 0.7657287);
  cep__1->SetBinError(5, 0.7854645);
  cep__1->SetBinError(6, 0.74307);
  cep__1->SetBinError(7, 0.6946612);
  cep__1->SetBinError(8, 0.6365154);
  cep__1->SetBinError(9, 0.7327663);
  cep__1->SetBinError(10, 0.6624214);
  cep__1->SetBinError(11, 0.6371832);
  cep__1->SetBinError(12, 0.6175293);
  cep__1->SetBinError(13, 0.562113);
  cep__1->SetBinError(14, 0.5359492);
  cep__1->SetBinError(15, 0.4353179);
  cep__1->SetBinError(16, 0.4576007);
  cep__1->SetBinError(17, 0.3798029);
  cep__1->SetBinError(18, 0.3847832);
  cep__1->SetBinError(19, 0.3366134);
  cep__1->SetBinError(20, 0.3166545);
  cep__1->SetBinError(21, 0.3176932);
  cep__1->SetBinError(22, 0.2769558);
  cep__1->SetBinError(23, 0.242173);
  cep__1->SetBinError(24, 0.2038349);
  cep__1->SetBinError(25, 0.170682);
  cep__1->SetBinError(26, 0.1672082);
  cep__1->SetBinError(27, 0.16133);
  cep__1->SetBinError(28, 0.1223197);
  cep__1->SetBinError(29, 0.1058397);
  cep__1->SetBinError(30, 0.1032933);
  cep__1->SetBinError(31, 0.09226799);
  cep__1->SetBinError(32, 0.07388869);
  cep__1->SetBinError(33, 0.07032139);
  cep__1->SetBinError(34, 0.08680734);
  cep__1->SetBinError(35, 0.05521098);
  cep__1->SetBinError(36, 0.0489979);
  cep__1->SetBinError(37, 0.04455219);
  cep__1->SetBinError(38, 0.03860034);
  cep__1->SetBinError(39, 0.03172698);
  cep__1->SetBinError(40, 0.0333147);
  cep__1->SetEntries(160);
  cep__1->SetFillColorAlpha(1, 0.5);
  cep__1->SetFillStyle(3004);

  ci = TColor::GetColor("#000099");
  cep__1->SetLineColor(ci);
  cep__1->GetXaxis()->SetLabelFont(42);
  cep__1->GetXaxis()->SetTitleOffset(1);
  cep__1->GetXaxis()->SetTitleFont(42);
  cep__1->GetYaxis()->SetLabelFont(42);
  cep__1->GetYaxis()->SetTitleFont(42);
  cep__1->GetZaxis()->SetLabelFont(42);
  cep__1->GetZaxis()->SetTitleOffset(1);
  cep__1->GetZaxis()->SetTitleFont(42);
  cep__1->Draw("e2same");

  Double_t Graph0_fx3001[40] = {0.001581139, 0.003535534, 0.006123724, 0.008660254, 0.01118034, 0.01369306, 0.01620185, 0.01870829,
                                0.0212132,   0.02371708,  0.02622022,  0.02872281,  0.03122499, 0.03372684, 0.03622844, 0.03872983,
                                0.04123106,  0.04373214,  0.04623311,  0.04873397,  0.05123475, 0.05373546, 0.05623611, 0.0587367,
                                0.06123724,  0.06373774,  0.06623821,  0.06873864,  0.07123904, 0.07373941, 0.07623975, 0.07874008,
                                0.08124039,  0.08374067,  0.08624094,  0.0887412,   0.09124144, 0.09374167, 0.09624188, 0.09874209};
  Double_t Graph0_fy3001[40] = {16,   5, 3, 2, 9, 3, 2,    7,    4,    1,    5,    1, 2,    -999, 4,    -999, 3,    1,    1,    -999,
                                -999, 1, 4, 1, 1, 3, -999, -999, -999, -999, -999, 1, -999, -999, -999, -999, -999, -999, -999, 1};
  Double_t Graph0_felx3001[40] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  Double_t Graph0_fely3001[40] = {3.957801, 2.159691,  1.632705, 1.291815,  2.943461,  1.632705, 1.291815, 2.58147,   1.914339,  0.8272462,
                                  2.159691, 0.8272462, 1.291815, 0,         1.914339,  0,        1.632705, 0.8272462, 0.8272462, 0,
                                  0,        0.8272462, 1.914339, 0.8272462, 0.8272462, 1.632705, 0,        0,         0,         0,
                                  0,        0.8272462, 0,        0,         0,         0,        0,        0,         0,         0.8272462};
  Double_t Graph0_fehx3001[40] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  Double_t Graph0_fehy3001[40] = {5.083066, 3.382473, 2.918186, 2.63786,  4.110204, 2.918186, 2.63786,  3.770281, 3.162753, 2.299527,
                                  3.382473, 2.299527, 2.63786,  0,        3.162753, 0,        2.918186, 2.299527, 2.299527, 0,
                                  0,        2.299527, 3.162753, 2.299527, 2.299527, 2.918186, 0,        0,        0,        0,
                                  0,        2.299527, 0,        0,        0,        0,        0,        0,        0,        2.299527};
  TGraphAsymmErrors *grae =
      new TGraphAsymmErrors(40, Graph0_fx3001, Graph0_fy3001, Graph0_felx3001, Graph0_fehx3001, Graph0_fely3001, Graph0_fehy3001);
  grae->SetName("Graph0");
  grae->SetTitle("Graph");
  grae->SetFillStyle(3004);
  grae->SetMarkerStyle(20);
  grae->SetMarkerSize(1.2);

  TH1F *Graph_Graph03001 = new TH1F("Graph_Graph03001", "Graph", 100, 0.001423025, 0.1084582);
  Graph_Graph03001->SetMinimum(-1100.9);
  Graph_Graph03001->SetMaximum(121.9);
  Graph_Graph03001->SetDirectory(0);
  Graph_Graph03001->SetStats(0);

  ci = TColor::GetColor("#000099");
  Graph_Graph03001->SetLineColor(ci);
  Graph_Graph03001->GetXaxis()->SetLabelFont(42);
  Graph_Graph03001->GetXaxis()->SetTitleOffset(1);
  Graph_Graph03001->GetXaxis()->SetTitleFont(42);
  Graph_Graph03001->GetYaxis()->SetLabelFont(42);
  Graph_Graph03001->GetYaxis()->SetTitleFont(42);
  Graph_Graph03001->GetZaxis()->SetLabelFont(42);
  Graph_Graph03001->GetZaxis()->SetTitleOffset(1);
  Graph_Graph03001->GetZaxis()->SetTitleFont(42);
  grae->SetHistogram(Graph_Graph03001);

  grae->Draw("pe");

  TLegend *leg = new TLegend(0.27, 0.49, 0.94, 0.915, NULL, "brNDC");
  leg->SetBorderSize(0);
  leg->SetLineColor(1);
  leg->SetLineStyle(1);
  leg->SetLineWidth(1);
  leg->SetFillColor(0);
  leg->SetFillStyle(0);

  // reduce size of the legend markers, while increasing the size of the text
  leg->SetMargin(0.1);
  leg->SetTextSize(0.043);
  leg->SetColumnSeparation(0.01);
  leg->SetNColumns(1);

  


  TLegendEntry *entry = leg->AddEntry("data_obs", "Data", "PE");
  entry->SetLineColor(1);
  entry->SetLineStyle(1);
  entry->SetLineWidth(1);
  entry->SetMarkerColor(1);
  entry->SetMarkerStyle(20);
  entry->SetMarkerSize(1.2);
  entry->SetTextFont(42);
  entry = leg->AddEntry("lbl_stack_4", "#gamma#gamma #rightarrow #gamma#gamma (SUPERCHIC 3.03)", "F");

  ci = TColor::GetColor("#ff9933");
  entry->SetFillColor(ci);
  entry->SetFillStyle(1001);

  ci = TColor::GetColor("#000099");
  entry->SetLineColor(ci);
  entry->SetLineStyle(1);
  entry->SetLineWidth(1);
  entry->SetMarkerColor(1);
  entry->SetMarkerStyle(21);
  entry->SetMarkerSize(1);
  entry->SetTextFont(42);
  entry = leg->AddEntry("qed_starlight_stack_3", "#gamma#gamma #rightarrow e^{+}e^{-} (SUPERCHIC 3.03 and STARLIGHT 3.13 averaged)", "F");

  ci = TColor::GetColor("#ffff00");
  entry->SetFillColor(ci);
  entry->SetFillStyle(1001);

  ci = TColor::GetColor("#000099");
  entry->SetLineColor(ci);
  entry->SetLineStyle(1);
  entry->SetLineWidth(1);
  entry->SetMarkerColor(1);
  entry->SetMarkerStyle(21);
  entry->SetMarkerSize(1);
  entry->SetTextFont(42);
  entry = leg->AddEntry("cep_stack_1", "gg #rightarrow #gamma#gamma (SUPERCHIC 3.03, scaled to data)", "F");

  ci = TColor::GetColor("#6699ff");
  entry->SetFillColor(ci);
  entry->SetFillStyle(1001);

  ci = TColor::GetColor("#000099");
  entry->SetLineColor(ci);
  entry->SetLineStyle(1);
  entry->SetLineWidth(1);
  entry->SetMarkerColor(1);
  entry->SetMarkerStyle(21);
  entry->SetMarkerSize(1);
  entry->SetTextFont(42);
  leg->Draw();

  // auto tex = new TLatex(0.10, 0.92, "#bf{CMS} #it{Preliminary}");
  auto tex = new TLatex(0.10, 0.92, "#bf{CMS}");
  tex->SetNDC();
  tex->SetTextFont(42);
  tex->SetTextSize(0.06);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(0.565, 0.92, "#scale[0.8]{PbPb, 1.65 nb^{-1} (#sqrt{s_{NN}} = 5.02 TeV)}");
  tex->SetNDC();
  tex->SetTextFont(42);
  tex->SetTextSize(0.06);
  tex->SetLineWidth(2);
  tex->Draw();

  pad1->Modified();
  canvas->cd();

  // ------------>Primitives in pad: pad2
  TPad *pad2 = new TPad("pad2", "pad2", 0, 0, 1, 0.3);
  pad2->Draw();
  pad2->cd();
  pad2->Range(-3.25, -1.493412, -0.75, 3.484627);
  pad2->SetFillColor(0);
  pad2->SetBorderMode(0);
  pad2->SetBorderSize(2);
  pad2->SetLogx();
  pad2->SetTopMargin(0.017);
  pad2->SetBottomMargin(0.3);
  pad2->SetFrameBorderMode(0);
  pad2->SetFrameBorderMode(0);
  Double_t xAxis7[41] = {0.001, 0.0025, 0.005, 0.0075, 0.01,  0.0125, 0.015, 0.0175, 0.02,  0.0225, 0.025, 0.0275, 0.03,  0.0325,
                         0.035, 0.0375, 0.04,  0.0425, 0.045, 0.0475, 0.05,  0.0525, 0.055, 0.0575, 0.06,  0.0625, 0.065, 0.0675,
                         0.07,  0.0725, 0.075, 0.0775, 0.08,  0.0825, 0.085, 0.0875, 0.09,  0.0925, 0.095, 0.0975, 0.105};

  TH1D *cep__2 = new TH1D("cep__2", "", 40, xAxis7);
  cep__2->SetBinContent(1, 1);
  cep__2->SetBinContent(2, 1);
  cep__2->SetBinContent(3, 1);
  cep__2->SetBinContent(4, 1);
  cep__2->SetBinContent(5, 1);
  cep__2->SetBinContent(6, 1);
  cep__2->SetBinContent(7, 1);
  cep__2->SetBinContent(8, 1);
  cep__2->SetBinContent(9, 1);
  cep__2->SetBinContent(10, 1);
  cep__2->SetBinContent(11, 1);
  cep__2->SetBinContent(12, 1);
  cep__2->SetBinContent(13, 1);
  cep__2->SetBinContent(14, 1);
  cep__2->SetBinContent(15, 1);
  cep__2->SetBinContent(16, 1);
  cep__2->SetBinContent(17, 1);
  cep__2->SetBinContent(18, 1);
  cep__2->SetBinContent(19, 1);
  cep__2->SetBinContent(20, 1);
  cep__2->SetBinContent(21, 1);
  cep__2->SetBinContent(22, 1);
  cep__2->SetBinContent(23, 1);
  cep__2->SetBinContent(24, 1);
  cep__2->SetBinContent(25, 1);
  cep__2->SetBinContent(26, 1);
  cep__2->SetBinContent(27, 1);
  cep__2->SetBinContent(28, 1);
  cep__2->SetBinContent(29, 1);
  cep__2->SetBinContent(30, 1);
  cep__2->SetBinContent(31, 1);
  cep__2->SetBinContent(32, 1);
  cep__2->SetBinContent(33, 1);
  cep__2->SetBinContent(34, 1);
  cep__2->SetBinContent(35, 1);
  cep__2->SetBinContent(36, 1);
  cep__2->SetBinContent(37, 1);
  cep__2->SetBinContent(38, 1);
  cep__2->SetBinContent(39, 1);
  cep__2->SetBinContent(40, 1);
  cep__2->SetBinError(1, 0.3252691);
  cep__2->SetBinError(2, 0.3252691);
  cep__2->SetBinError(3, 0.3252691);
  cep__2->SetBinError(4, 0.3252691);
  cep__2->SetBinError(5, 0.3252691);
  cep__2->SetBinError(6, 0.3252691);
  cep__2->SetBinError(7, 0.3252691);
  cep__2->SetBinError(8, 0.3252691);
  cep__2->SetBinError(9, 0.3252691);
  cep__2->SetBinError(10, 0.3252691);
  cep__2->SetBinError(11, 0.3252691);
  cep__2->SetBinError(12, 0.3252691);
  cep__2->SetBinError(13, 0.3252691);
  cep__2->SetBinError(14, 0.3252691);
  cep__2->SetBinError(15, 0.3252691);
  cep__2->SetBinError(16, 0.3252691);
  cep__2->SetBinError(17, 0.3252691);
  cep__2->SetBinError(18, 0.3252691);
  cep__2->SetBinError(19, 0.3252691);
  cep__2->SetBinError(20, 0.3252691);
  cep__2->SetBinError(21, 0.3252691);
  cep__2->SetBinError(22, 0.3252691);
  cep__2->SetBinError(23, 0.3252691);
  cep__2->SetBinError(24, 0.3252691);
  cep__2->SetBinError(25, 0.3252691);
  cep__2->SetBinError(26, 0.3252691);
  cep__2->SetBinError(27, 0.3252691);
  cep__2->SetBinError(28, 0.3252691);
  cep__2->SetBinError(29, 0.3252691);
  cep__2->SetBinError(30, 0.3252691);
  cep__2->SetBinError(31, 0.3252691);
  cep__2->SetBinError(32, 0.3252691);
  cep__2->SetBinError(33, 0.3252691);
  cep__2->SetBinError(34, 0.3252691);
  cep__2->SetBinError(35, 0.3252691);
  cep__2->SetBinError(36, 0.3252691);
  cep__2->SetBinError(37, 0.3252691);
  cep__2->SetBinError(38, 0.3252691);
  cep__2->SetBinError(39, 0.3252691);
  cep__2->SetBinError(40, 0.3252691);
  cep__2->SetMinimum(0);
  cep__2->SetMaximum(3.4);
  cep__2->SetEntries(378.0718);
  cep__2->SetFillColorAlpha(1, 0.5);
  cep__2->SetFillStyle(3004);

  ci = TColor::GetColor("#000099");
  cep__2->SetLineColor(ci);
  cep__2->GetXaxis()->SetTitle("A^{#gamma#gamma}_{#phi}");
  cep__2->GetXaxis()->SetRange(1, 40);
  cep__2->GetXaxis()->SetMoreLogLabels();
  cep__2->GetXaxis()->SetNoExponent();
  cep__2->GetXaxis()->SetNdivisions(505);
  cep__2->GetXaxis()->SetLabelFont(43);
  cep__2->GetXaxis()->SetLabelOffset(0.03);
  cep__2->GetXaxis()->SetLabelSize(20);
  cep__2->GetXaxis()->SetTitleSize(20);
  cep__2->GetXaxis()->SetTitleOffset(1.2);
  cep__2->GetXaxis()->SetTitleFont(43);
  cep__2->GetYaxis()->SetTitle("Data/MC");
  cep__2->GetYaxis()->CenterTitle();
  cep__2->GetYaxis()->SetNdivisions(505);
  cep__2->GetYaxis()->SetLabelFont(43);
  cep__2->GetYaxis()->SetLabelSize(20);
  cep__2->GetYaxis()->SetTitleSize(20);
  cep__2->GetYaxis()->SetTitleOffset(1.55);
  cep__2->GetYaxis()->SetTitleFont(43);
  cep__2->GetZaxis()->SetLabelFont(42);
  cep__2->GetZaxis()->SetTitleOffset(1);
  cep__2->GetZaxis()->SetTitleFont(42);
  cep__2->SetMarkerSize(0);
  cep__2->SetMarkerStyle(20);
  cep__2->Draw("e2");

  // Draw a line at 1.0
  TLine *line = new TLine(0.001, 1.0, 0.105, 1.0);
  line->SetLineStyle(2);
  line->Draw("same");

  Double_t Graph0_fx3002[40] = {0.001581139, 0.003535534, 0.006123724, 0.008660254, 0.01118034, 0.01369306, 0.01620185, 0.01870829,
                                0.0212132,   0.02371708,  0.02622022,  0.02872281,  0.03122499, 0.03372684, 0.03622844, 0.03872983,
                                0.04123106,  0.04373214,  0.04623311,  0.04873397,  0.05123475, 0.05373546, 0.05623611, 0.0587367,
                                0.06123724,  0.06373774,  0.06623821,  0.06873864,  0.07123904, 0.07373941, 0.07623975, 0.07874008,
                                0.08124039,  0.08374067,  0.08624094,  0.0887412,   0.09124144, 0.09374167, 0.09624188, 0.09874209};
  Double_t Graph0_fy3002[40] = {1.303923,  0.8523875, 0.7922412, 0.600735,  2.635383,  0.9285801, 0.6621933, 2.529397,
                                1.255516,  0.347211,  1.804819,  0.372452,  0.8183408, -428.716,  2.113398,  -502.119,
                                1.816732,  0.5977392, 0.6832764, -725.6173, -723.2449, 0.8304575, 3.798937,  1.128364,
                                1.347535,  4.126593,  -1424.223, -1878.438, -2170.924, -2224.443, -2490.246, 3.11279,
                                -3267.427, -2646.896, -4161.672, -4689.385, -5157.322, -5952.538, -7242.102, 6.903858};
  Double_t Graph0_felx3002[40] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  Double_t Graph0_fely3002[40] = {0.4429502, 0.4286585, 0.4923595, 0.44669,   1.067285,  0.5770909, 0.4923887, 1.119118,
                                  0.6909904, 0.3562764, 0.9076281, 0.3821764, 0.6084957, 0,         1.163137,  0,
                                  1.129057,  0.6133456, 0.7011162, 0,         0,         0.85214,   2.090796,  1.157825,
                                  1.382718,  2.564581,  0,         0,         0,         0,         0,         3.194063,
                                  0,         0,         0,         0,         0,         0,         0,         7.084112};
  Double_t Graph0_fehx3002[40] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  Double_t Graph0_fehy3002[40] = {0.4429502, 0.4286585, 0.4923595, 0.44669,   1.067285,  0.5770909, 0.4923887, 1.119118,
                                  0.6909904, 0.3562764, 0.9076281, 0.3821764, 0.6084957, 0,         1.163137,  0,
                                  1.129057,  0.6133456, 0.7011162, 0,         0,         0.85214,   2.090796,  1.157825,
                                  1.382718,  2.564581,  0,         0,         0,         0,         0,         3.194063,
                                  0,         0,         0,         0,         0,         0,         0,         7.084112};
  grae = new TGraphAsymmErrors(40, Graph0_fx3002, Graph0_fy3002, Graph0_felx3002, Graph0_fehx3002, Graph0_fely3002, Graph0_fehy3002);
  grae->SetName("Graph0");
  grae->SetTitle("Graph");
  grae->SetFillStyle(3004);
  grae->SetMarkerStyle(20);
  grae->SetMarkerSize(1.2);

  TH1F *Graph_Graph03002 = new TH1F("Graph_Graph03002", "Graph", 100, 0.001423025, 0.1084582);
  Graph_Graph03002->SetMinimum(-9799.963);
  Graph_Graph03002->SetMaximum(906.1653);
  Graph_Graph03002->SetDirectory(0);
  Graph_Graph03002->SetStats(0);

  ci = TColor::GetColor("#000099");
  Graph_Graph03002->SetLineColor(ci);
  Graph_Graph03002->GetXaxis()->SetLabelFont(42);
  Graph_Graph03002->GetXaxis()->SetTitleOffset(1);
  Graph_Graph03002->GetXaxis()->SetTitleFont(42);
  Graph_Graph03002->GetYaxis()->SetLabelFont(42);
  Graph_Graph03002->GetYaxis()->SetTitleFont(42);
  Graph_Graph03002->GetZaxis()->SetLabelFont(42);
  Graph_Graph03002->GetZaxis()->SetTitleOffset(1);
  Graph_Graph03002->GetZaxis()->SetTitleFont(42);

  grae->SetHistogram(Graph_Graph03002);

  // go over grae graph and create a graph that has N times less points by averaging out N neighboring points.
  // this is done to reduce the number of points in the graph and make it look smoother

  auto grae2 = AverageVariableNPoints(grae, {1, 1, 1, 3, 4, 4, 5, 8, 13});
  grae2->SetMarkerStyle(20);
  grae2->SetMarkerSize(1.2);

  grae->Draw("pe0");

  pad2->Modified();
  canvas->cd();
  canvas->Modified();
  canvas->cd();
  canvas->SetSelected(canvas);
  canvas->SaveAs("figures/Figure_005.pdf");
}
