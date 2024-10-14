#ifdef __CLING__
#pragma cling optimize(0)
#endif

#include "style.h"

void plot_fig_8_a() {
  gROOT->SetBatch(kTRUE);

  //=========Macro generated from canvas: diphotonSR_mass100/diphotonSR_mass100
  //=========  (Fri Sep 27 10:17:40 2024) by ROOT version 6.26/08
  TCanvas *canvas = new TCanvas("canvas", "canvas", 0, 0, 800, 600);
  gStyle->SetOptFit(1);
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  canvas->SetHighLightColor(2);
  canvas->Range(0, 0, 1, 1);
  canvas->SetFillColor(0);
  canvas->SetBorderMode(0);
  canvas->SetBorderSize(2);
  canvas->SetTickx(1);
  canvas->SetTicky(1);
  // canvas->SetLeftMargin(0.16);
  // canvas->SetRightMargin(0.10);
  // canvas->SetTopMargin(0.06);
  // canvas->SetBottomMargin(0.3);
  canvas->SetFrameFillStyle(0);
  canvas->SetFrameBorderMode(0);

  // ------------>Primitives in pad: diphotonSR_mass100_1
  TPad *diphotonSR_mass100_1 = new TPad("diphotonSR_mass100_1", "diphotonSR_mass100_1", 0.01, 0.01, 0.99, 0.99);
  diphotonSR_mass100_1->Draw();
  diphotonSR_mass100_1->cd();
  diphotonSR_mass100_1->Range(0.2779, -5.633803, 2.3039, 22.53521);
  diphotonSR_mass100_1->SetFillColor(0);
  diphotonSR_mass100_1->SetBorderMode(0);
  diphotonSR_mass100_1->SetBorderSize(2);
  diphotonSR_mass100_1->SetLogx();
  diphotonSR_mass100_1->SetLeftMargin(0.10);
  diphotonSR_mass100_1->SetRightMargin(0.02);
  diphotonSR_mass100_1->SetBottomMargin(0.15);
  diphotonSR_mass100_1->SetTopMargin(0.10);
  diphotonSR_mass100_1->SetFrameFillStyle(0);
  diphotonSR_mass100_1->SetFrameBorderMode(0);
  diphotonSR_mass100_1->SetFrameFillStyle(0);
  diphotonSR_mass100_1->SetFrameLineWidth(2);
  diphotonSR_mass100_1->SetFrameBorderMode(0);
  diphotonSR_mass100_1->SetFrameBorderSize(2);

  THStack *diphotonSR_mass100background = new THStack();
  diphotonSR_mass100background->SetName("diphotonSR_mass100background");
  diphotonSR_mass100background->SetTitle("");
  diphotonSR_mass100background->SetMinimum(0);
  diphotonSR_mass100background->SetMaximum(20);
  Double_t xAxis349[49] = {4,  6,  8,  10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52,
                           54, 56, 58, 60, 62, 64, 66, 68, 70, 72, 74, 76, 78, 80, 82, 84, 86, 88, 90, 92, 94, 96, 98, 100};

  TH1F *diphotonSR_mass100background_stack_88 = new TH1F("diphotonSR_mass100background_stack_88", "", 48, xAxis349);
  diphotonSR_mass100background_stack_88->SetMinimum(0);
  diphotonSR_mass100background_stack_88->SetMaximum(20);
  diphotonSR_mass100background_stack_88->SetDirectory(0);
  diphotonSR_mass100background_stack_88->SetStats(0);
  diphotonSR_mass100background_stack_88->SetLineStyle(0);
  diphotonSR_mass100background_stack_88->GetXaxis()->SetTitle("m^{#gamma#gamma} (GeV)");
  diphotonSR_mass100background_stack_88->GetXaxis()->SetLabelFont(42);
  diphotonSR_mass100background_stack_88->GetXaxis()->SetLabelOffset(0.007);
  diphotonSR_mass100background_stack_88->GetXaxis()->SetLabelSize(0.04);
  diphotonSR_mass100background_stack_88->GetXaxis()->SetTitleSize(0.05);
  diphotonSR_mass100background_stack_88->GetXaxis()->SetTitleOffset(1.1);
  diphotonSR_mass100background_stack_88->GetXaxis()->SetTitleFont(42);
  diphotonSR_mass100background_stack_88->GetXaxis()->SetMoreLogLabels();
  diphotonSR_mass100background_stack_88->GetYaxis()->SetTitle("Events / 2 (GeV^{-1})");
  diphotonSR_mass100background_stack_88->GetYaxis()->CenterTitle(false);
  diphotonSR_mass100background_stack_88->GetYaxis()->SetNdivisions(505);
  diphotonSR_mass100background_stack_88->GetYaxis()->SetLabelFont(42);
  diphotonSR_mass100background_stack_88->GetYaxis()->SetLabelOffset(0.007);
  diphotonSR_mass100background_stack_88->GetYaxis()->SetLabelSize(0.04);
  diphotonSR_mass100background_stack_88->GetYaxis()->SetTitleSize(0.05);
  diphotonSR_mass100background_stack_88->GetYaxis()->SetTitleOffset(1.1);
  diphotonSR_mass100background_stack_88->GetYaxis()->SetTitleFont(42);
  diphotonSR_mass100background_stack_88->GetZaxis()->SetLabelFont(42);
  diphotonSR_mass100background_stack_88->GetZaxis()->SetLabelOffset(0.007);
  diphotonSR_mass100background_stack_88->GetZaxis()->SetLabelSize(0.05);
  diphotonSR_mass100background_stack_88->GetZaxis()->SetTitleSize(0.06);
  diphotonSR_mass100background_stack_88->GetZaxis()->SetTitleOffset(1);
  diphotonSR_mass100background_stack_88->GetZaxis()->SetTitleFont(42);
  diphotonSR_mass100background->SetHistogram(diphotonSR_mass100background_stack_88);

  Double_t xAxis350[49] = {4,  6,  8,  10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52,
                           54, 56, 58, 60, 62, 64, 66, 68, 70, 72, 74, 76, 78, 80, 82, 84, 86, 88, 90, 92, 94, 96, 98, 100};

  TH1F *diphotonSR_mass100_stack_1 = new TH1F("diphotonSR_mass100_stack_1", "diphotonSR_mass100", 48, xAxis350);
  diphotonSR_mass100_stack_1->SetBinContent(1, 1.907768);
  diphotonSR_mass100_stack_1->SetBinContent(2, 3.946509);
  diphotonSR_mass100_stack_1->SetBinContent(3, 2.093108);
  diphotonSR_mass100_stack_1->SetBinContent(4, 0.9365854);
  diphotonSR_mass100_stack_1->SetBinContent(5, 0.4843555);
  diphotonSR_mass100_stack_1->SetBinContent(6, 0.306429);
  diphotonSR_mass100_stack_1->SetBinContent(7, 0.1556857);
  diphotonSR_mass100_stack_1->SetBinContent(8, 0.1037905);
  diphotonSR_mass100_stack_1->SetBinContent(9, 0.06919365);
  diphotonSR_mass100_stack_1->SetBinContent(10, 0.03953923);
  diphotonSR_mass100_stack_1->SetBinContent(11, 0.01729841);
  diphotonSR_mass100_stack_1->SetBinContent(12, 0.01482721);
  diphotonSR_mass100_stack_1->SetBinContent(13, 0.002471202);
  diphotonSR_mass100_stack_1->SetBinContent(14, 0.004942403);
  diphotonSR_mass100_stack_1->SetBinContent(15, 0.004942403);
  diphotonSR_mass100_stack_1->SetBinContent(16, 0.004942403);
  diphotonSR_mass100_stack_1->SetBinContent(17, 0.002471202);
  diphotonSR_mass100_stack_1->SetBinContent(20, 0.007413605);
  diphotonSR_mass100_stack_1->SetBinContent(21, 0.002471202);
  diphotonSR_mass100_stack_1->SetBinError(1, 0.06866206);
  diphotonSR_mass100_stack_1->SetBinError(2, 0.09875535);
  diphotonSR_mass100_stack_1->SetBinError(3, 0.07192004);
  diphotonSR_mass100_stack_1->SetBinError(4, 0.04810916);
  diphotonSR_mass100_stack_1->SetBinError(5, 0.03459682);
  diphotonSR_mass100_stack_1->SetBinError(6, 0.02751814);
  diphotonSR_mass100_stack_1->SetBinError(7, 0.01961456);
  diphotonSR_mass100_stack_1->SetBinError(8, 0.01601522);
  diphotonSR_mass100_stack_1->SetBinError(9, 0.01307637);
  diphotonSR_mass100_stack_1->SetBinError(10, 0.009884807);
  diphotonSR_mass100_stack_1->SetBinError(11, 0.006538185);
  diphotonSR_mass100_stack_1->SetBinError(12, 0.006053183);
  diphotonSR_mass100_stack_1->SetBinError(13, 0.002471202);
  diphotonSR_mass100_stack_1->SetBinError(14, 0.003494807);
  diphotonSR_mass100_stack_1->SetBinError(15, 0.003494807);
  diphotonSR_mass100_stack_1->SetBinError(16, 0.003494807);
  diphotonSR_mass100_stack_1->SetBinError(17, 0.002471202);
  diphotonSR_mass100_stack_1->SetBinError(20, 0.004280247);
  diphotonSR_mass100_stack_1->SetBinError(21, 0.002471202);
  diphotonSR_mass100_stack_1->SetEntries(48);
  diphotonSR_mass100_stack_1->SetDirectory(0);

  Int_t ci;       // for color index setting
  TColor *color;  // for color definition with alpha
  ci = TColor::GetColor("#6699ff");
  diphotonSR_mass100_stack_1->SetFillColor(ci);

  ci = TColor::GetColor("#000000");
  diphotonSR_mass100_stack_1->SetLineColor(ci);
  diphotonSR_mass100_stack_1->SetMarkerStyle(20);
  diphotonSR_mass100_stack_1->GetXaxis()->SetRange(1, 48);
  diphotonSR_mass100_stack_1->GetXaxis()->SetLabelFont(42);
  diphotonSR_mass100_stack_1->GetXaxis()->SetLabelOffset(0.007);
  diphotonSR_mass100_stack_1->GetXaxis()->SetLabelSize(0.05);
  diphotonSR_mass100_stack_1->GetXaxis()->SetTitleSize(0.06);
  diphotonSR_mass100_stack_1->GetXaxis()->SetTitleOffset(0.9);
  diphotonSR_mass100_stack_1->GetXaxis()->SetTitleFont(42);
  diphotonSR_mass100_stack_1->GetYaxis()->SetLabelFont(42);
  diphotonSR_mass100_stack_1->GetYaxis()->SetLabelOffset(0.007);
  diphotonSR_mass100_stack_1->GetYaxis()->SetLabelSize(0.05);
  diphotonSR_mass100_stack_1->GetYaxis()->SetTitleSize(0.06);
  diphotonSR_mass100_stack_1->GetYaxis()->SetTitleOffset(1.25);
  diphotonSR_mass100_stack_1->GetYaxis()->SetTitleFont(42);
  diphotonSR_mass100_stack_1->GetZaxis()->SetLabelFont(42);
  diphotonSR_mass100_stack_1->GetZaxis()->SetLabelOffset(0.007);
  diphotonSR_mass100_stack_1->GetZaxis()->SetLabelSize(0.05);
  diphotonSR_mass100_stack_1->GetZaxis()->SetTitleSize(0.06);
  diphotonSR_mass100_stack_1->GetZaxis()->SetTitleOffset(1);
  diphotonSR_mass100_stack_1->GetZaxis()->SetTitleFont(42);
  diphotonSR_mass100background->Add(diphotonSR_mass100_stack_1, "");
  Double_t xAxis351[49] = {4,  6,  8,  10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52,
                           54, 56, 58, 60, 62, 64, 66, 68, 70, 72, 74, 76, 78, 80, 82, 84, 86, 88, 90, 92, 94, 96, 98, 100};

  TH1F *diphotonSR_mass100_stack_2 = new TH1F("diphotonSR_mass100_stack_2", "diphotonSR_mass100", 48, xAxis351);
  diphotonSR_mass100_stack_2->SetBinContent(1, 0.1149938);
  diphotonSR_mass100_stack_2->SetBinContent(2, 0.2299875);
  diphotonSR_mass100_stack_2->SetBinContent(3, 0.05749688);
  diphotonSR_mass100_stack_2->SetBinContent(4, 0.3449813);
  diphotonSR_mass100_stack_2->SetBinError(1, 0.08131286);
  diphotonSR_mass100_stack_2->SetBinError(2, 0.1149937);
  diphotonSR_mass100_stack_2->SetBinError(3, 0.05749687);
  diphotonSR_mass100_stack_2->SetBinError(4, 0.140838);
  diphotonSR_mass100_stack_2->SetEntries(48);
  diphotonSR_mass100_stack_2->SetDirectory(0);

  ci = TColor::GetColor("#ffff00");
  diphotonSR_mass100_stack_2->SetFillColor(ci);

  ci = TColor::GetColor("#ffff00");
  diphotonSR_mass100_stack_2->SetLineColor(ci);
  diphotonSR_mass100_stack_2->SetMarkerStyle(20);
  diphotonSR_mass100_stack_2->SetMarkerSize(0);
  diphotonSR_mass100_stack_2->GetXaxis()->SetRange(1, 48);
  diphotonSR_mass100_stack_2->GetXaxis()->SetLabelFont(42);
  diphotonSR_mass100_stack_2->GetXaxis()->SetLabelOffset(0.007);
  diphotonSR_mass100_stack_2->GetXaxis()->SetLabelSize(0.05);
  diphotonSR_mass100_stack_2->GetXaxis()->SetTitleSize(0.06);
  diphotonSR_mass100_stack_2->GetXaxis()->SetTitleOffset(0.9);
  diphotonSR_mass100_stack_2->GetXaxis()->SetTitleFont(42);
  diphotonSR_mass100_stack_2->GetYaxis()->SetLabelFont(42);
  diphotonSR_mass100_stack_2->GetYaxis()->SetLabelOffset(0.007);
  diphotonSR_mass100_stack_2->GetYaxis()->SetLabelSize(0.05);
  diphotonSR_mass100_stack_2->GetYaxis()->SetTitleSize(0.06);
  diphotonSR_mass100_stack_2->GetYaxis()->SetTitleOffset(1.25);
  diphotonSR_mass100_stack_2->GetYaxis()->SetTitleFont(42);
  diphotonSR_mass100_stack_2->GetZaxis()->SetLabelFont(42);
  diphotonSR_mass100_stack_2->GetZaxis()->SetLabelOffset(0.007);
  diphotonSR_mass100_stack_2->GetZaxis()->SetLabelSize(0.05);
  diphotonSR_mass100_stack_2->GetZaxis()->SetTitleSize(0.06);
  diphotonSR_mass100_stack_2->GetZaxis()->SetTitleOffset(1);
  diphotonSR_mass100_stack_2->GetZaxis()->SetTitleFont(42);
  diphotonSR_mass100background->Add(diphotonSR_mass100_stack_2, "");
  Double_t xAxis352[49] = {4,  6,  8,  10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52,
                           54, 56, 58, 60, 62, 64, 66, 68, 70, 72, 74, 76, 78, 80, 82, 84, 86, 88, 90, 92, 94, 96, 98, 100};

  TH1F *diphotonSR_mass100_stack_3 = new TH1F("diphotonSR_mass100_stack_3", "diphotonSR_mass100", 48, xAxis352);
  diphotonSR_mass100_stack_3->SetBinContent(1, 0.1443652);
  diphotonSR_mass100_stack_3->SetBinContent(2, 0.2165478);
  diphotonSR_mass100_stack_3->SetBinContent(3, 0.4330957);
  diphotonSR_mass100_stack_3->SetBinContent(5, 0.07218262);
  diphotonSR_mass100_stack_3->SetBinContent(6, 0.07218262);
  diphotonSR_mass100_stack_3->SetBinContent(9, 0.07218262);
  diphotonSR_mass100_stack_3->SetBinContent(13, 0.07218262);
  diphotonSR_mass100_stack_3->SetBinContent(15, 0.07218262);
  diphotonSR_mass100_stack_3->SetBinError(1, 0.1020816);
  diphotonSR_mass100_stack_3->SetBinError(2, 0.125024);
  diphotonSR_mass100_stack_3->SetBinError(3, 0.1768106);
  diphotonSR_mass100_stack_3->SetBinError(5, 0.07218262);
  diphotonSR_mass100_stack_3->SetBinError(6, 0.07218262);
  diphotonSR_mass100_stack_3->SetBinError(9, 0.07218262);
  diphotonSR_mass100_stack_3->SetBinError(13, 0.07218262);
  diphotonSR_mass100_stack_3->SetBinError(15, 0.07218262);
  diphotonSR_mass100_stack_3->SetEntries(48);
  diphotonSR_mass100_stack_3->SetDirectory(0);

  ci = TColor::GetColor("#ffff00");
  diphotonSR_mass100_stack_3->SetFillColor(ci);

  ci = TColor::GetColor("#000000");
  diphotonSR_mass100_stack_3->SetLineColor(ci);
  diphotonSR_mass100_stack_3->SetMarkerStyle(20);
  diphotonSR_mass100_stack_3->SetMarkerSize(0);
  diphotonSR_mass100_stack_3->GetXaxis()->SetRange(1, 48);
  diphotonSR_mass100_stack_3->GetXaxis()->SetLabelFont(42);
  diphotonSR_mass100_stack_3->GetXaxis()->SetLabelOffset(0.007);
  diphotonSR_mass100_stack_3->GetXaxis()->SetLabelSize(0.05);
  diphotonSR_mass100_stack_3->GetXaxis()->SetTitleSize(0.06);
  diphotonSR_mass100_stack_3->GetXaxis()->SetTitleOffset(0.9);
  diphotonSR_mass100_stack_3->GetXaxis()->SetTitleFont(42);
  diphotonSR_mass100_stack_3->GetYaxis()->SetLabelFont(42);
  diphotonSR_mass100_stack_3->GetYaxis()->SetLabelOffset(0.007);
  diphotonSR_mass100_stack_3->GetYaxis()->SetLabelSize(0.05);
  diphotonSR_mass100_stack_3->GetYaxis()->SetTitleSize(0.06);
  diphotonSR_mass100_stack_3->GetYaxis()->SetTitleOffset(1.25);
  diphotonSR_mass100_stack_3->GetYaxis()->SetTitleFont(42);
  diphotonSR_mass100_stack_3->GetZaxis()->SetLabelFont(42);
  diphotonSR_mass100_stack_3->GetZaxis()->SetLabelOffset(0.007);
  diphotonSR_mass100_stack_3->GetZaxis()->SetLabelSize(0.05);
  diphotonSR_mass100_stack_3->GetZaxis()->SetTitleSize(0.06);
  diphotonSR_mass100_stack_3->GetZaxis()->SetTitleOffset(1);
  diphotonSR_mass100_stack_3->GetZaxis()->SetTitleFont(42);
  diphotonSR_mass100background->Add(diphotonSR_mass100_stack_3, "");
  Double_t xAxis353[49] = {4,  6,  8,  10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52,
                           54, 56, 58, 60, 62, 64, 66, 68, 70, 72, 74, 76, 78, 80, 82, 84, 86, 88, 90, 92, 94, 96, 98, 100};

  TH1F *diphotonSR_mass100_stack_4 = new TH1F("diphotonSR_mass100_stack_4", "diphotonSR_mass100", 48, xAxis353);
  diphotonSR_mass100_stack_4->SetBinContent(1, 1.742024);
  diphotonSR_mass100_stack_4->SetBinContent(2, 4.089232);
  diphotonSR_mass100_stack_4->SetBinContent(3, 2.66394);
  diphotonSR_mass100_stack_4->SetBinContent(4, 1.640218);
  diphotonSR_mass100_stack_4->SetBinContent(5, 0.8087969);
  diphotonSR_mass100_stack_4->SetBinContent(6, 0.5542804);
  diphotonSR_mass100_stack_4->SetBinContent(7, 0.3902587);
  diphotonSR_mass100_stack_4->SetBinContent(8, 0.2488606);
  diphotonSR_mass100_stack_4->SetBinContent(9, 0.1979573);
  diphotonSR_mass100_stack_4->SetBinContent(10, 0.1527099);
  diphotonSR_mass100_stack_4->SetBinContent(11, 0.09049477);
  diphotonSR_mass100_stack_4->SetBinContent(12, 0.05655923);
  diphotonSR_mass100_stack_4->SetBinContent(13, 0.02262369);
  diphotonSR_mass100_stack_4->SetBinContent(14, 0.03393554);
  diphotonSR_mass100_stack_4->SetBinContent(15, 0.03393554);
  diphotonSR_mass100_stack_4->SetBinContent(16, 0.01131185);
  diphotonSR_mass100_stack_4->SetBinContent(17, 0.01696777);
  diphotonSR_mass100_stack_4->SetBinContent(18, 0.01131185);
  diphotonSR_mass100_stack_4->SetBinContent(19, 0.01696777);
  diphotonSR_mass100_stack_4->SetBinContent(21, 0.01131185);
  diphotonSR_mass100_stack_4->SetBinContent(22, 0.005655923);
  diphotonSR_mass100_stack_4->SetBinContent(25, 0.005655923);
  diphotonSR_mass100_stack_4->SetBinContent(26, 0.01131185);
  diphotonSR_mass100_stack_4->SetBinError(1, 0.09926104);
  diphotonSR_mass100_stack_4->SetBinError(2, 0.1520802);
  diphotonSR_mass100_stack_4->SetBinError(3, 0.1227479);
  diphotonSR_mass100_stack_4->SetBinError(4, 0.09631689);
  diphotonSR_mass100_stack_4->SetBinError(5, 0.067635);
  diphotonSR_mass100_stack_4->SetBinError(6, 0.05599078);
  diphotonSR_mass100_stack_4->SetBinError(7, 0.04698162);
  diphotonSR_mass100_stack_4->SetBinError(8, 0.03751715);
  diphotonSR_mass100_stack_4->SetBinError(9, 0.03346089);
  diphotonSR_mass100_stack_4->SetBinError(10, 0.02938904);
  diphotonSR_mass100_stack_4->SetBinError(11, 0.02262369);
  diphotonSR_mass100_stack_4->SetBinError(12, 0.0178856);
  diphotonSR_mass100_stack_4->SetBinError(13, 0.01131185);
  diphotonSR_mass100_stack_4->SetBinError(14, 0.01385412);
  diphotonSR_mass100_stack_4->SetBinError(15, 0.01385412);
  diphotonSR_mass100_stack_4->SetBinError(16, 0.007998683);
  diphotonSR_mass100_stack_4->SetBinError(17, 0.009796346);
  diphotonSR_mass100_stack_4->SetBinError(18, 0.007998683);
  diphotonSR_mass100_stack_4->SetBinError(19, 0.009796346);
  diphotonSR_mass100_stack_4->SetBinError(21, 0.007998683);
  diphotonSR_mass100_stack_4->SetBinError(22, 0.005655923);
  diphotonSR_mass100_stack_4->SetBinError(25, 0.005655923);
  diphotonSR_mass100_stack_4->SetBinError(26, 0.007998683);
  diphotonSR_mass100_stack_4->SetEntries(48);
  diphotonSR_mass100_stack_4->SetDirectory(0);

  ci = TColor::GetColor("#ff9933");
  diphotonSR_mass100_stack_4->SetFillColor(ci);

  ci = TColor::GetColor("#000000");
  diphotonSR_mass100_stack_4->SetLineColor(ci);
  diphotonSR_mass100_stack_4->SetMarkerStyle(20);
  diphotonSR_mass100_stack_4->GetXaxis()->SetRange(1, 48);
  diphotonSR_mass100_stack_4->GetXaxis()->SetLabelFont(42);
  diphotonSR_mass100_stack_4->GetXaxis()->SetLabelOffset(0.007);
  diphotonSR_mass100_stack_4->GetXaxis()->SetLabelSize(0.05);
  diphotonSR_mass100_stack_4->GetXaxis()->SetTitleSize(0.06);
  diphotonSR_mass100_stack_4->GetXaxis()->SetTitleOffset(0.9);
  diphotonSR_mass100_stack_4->GetXaxis()->SetTitleFont(42);
  diphotonSR_mass100_stack_4->GetYaxis()->SetLabelFont(42);
  diphotonSR_mass100_stack_4->GetYaxis()->SetLabelOffset(0.007);
  diphotonSR_mass100_stack_4->GetYaxis()->SetLabelSize(0.05);
  diphotonSR_mass100_stack_4->GetYaxis()->SetTitleSize(0.06);
  diphotonSR_mass100_stack_4->GetYaxis()->SetTitleOffset(1.25);
  diphotonSR_mass100_stack_4->GetYaxis()->SetTitleFont(42);
  diphotonSR_mass100_stack_4->GetZaxis()->SetLabelFont(42);
  diphotonSR_mass100_stack_4->GetZaxis()->SetLabelOffset(0.007);
  diphotonSR_mass100_stack_4->GetZaxis()->SetLabelSize(0.05);
  diphotonSR_mass100_stack_4->GetZaxis()->SetTitleSize(0.06);
  diphotonSR_mass100_stack_4->GetZaxis()->SetTitleOffset(1);
  diphotonSR_mass100_stack_4->GetZaxis()->SetTitleFont(42);
  diphotonSR_mass100background->Add(diphotonSR_mass100_stack_4, "");
  diphotonSR_mass100background->Draw("hist");

  auto diphotonSR_mass100data = new THStack();
  diphotonSR_mass100data->SetName("diphotonSR_mass100data");
  diphotonSR_mass100data->SetTitle("");
  diphotonSR_mass100data->SetMinimum(0);
  diphotonSR_mass100data->SetMaximum(20);
  Double_t xAxis354[49] = {4,  6,  8,  10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52,
                           54, 56, 58, 60, 62, 64, 66, 68, 70, 72, 74, 76, 78, 80, 82, 84, 86, 88, 90, 92, 94, 96, 98, 100};

  TH1F *diphotonSR_mass100data_stack_89 = new TH1F("diphotonSR_mass100data_stack_89", "", 48, xAxis354);
  diphotonSR_mass100data_stack_89->SetMinimum(0);
  diphotonSR_mass100data_stack_89->SetMaximum(20);
  diphotonSR_mass100data_stack_89->SetDirectory(0);
  diphotonSR_mass100data_stack_89->SetStats(0);
  diphotonSR_mass100data_stack_89->SetLineStyle(0);
  diphotonSR_mass100data->SetHistogram(diphotonSR_mass100data_stack_89);

  Double_t xAxis355[49] = {4,  6,  8,  10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52,
                           54, 56, 58, 60, 62, 64, 66, 68, 70, 72, 74, 76, 78, 80, 82, 84, 86, 88, 90, 92, 94, 96, 98, 100};

  diphotonSR_mass100_stack_1 = new TH1F("diphotonSR_mass100_stack_1", "diphotonSR_mass100", 48, xAxis355);
  diphotonSR_mass100_stack_1->SetBinContent(1, 4);
  diphotonSR_mass100_stack_1->SetBinContent(2, 9);
  diphotonSR_mass100_stack_1->SetBinContent(3, 6);
  diphotonSR_mass100_stack_1->SetBinContent(4, 2);
  diphotonSR_mass100_stack_1->SetBinContent(5, 4);
  diphotonSR_mass100_stack_1->SetBinContent(6, 1);

  diphotonSR_mass100_stack_1->SetBinError(1, 2);
  diphotonSR_mass100_stack_1->SetBinError(2, 3);
  diphotonSR_mass100_stack_1->SetBinError(3, 2.44949);
  diphotonSR_mass100_stack_1->SetBinError(4, 1.414214);
  diphotonSR_mass100_stack_1->SetBinError(5, 2);
  diphotonSR_mass100_stack_1->SetBinError(6, 1);

  for (int i = 7; i <= diphotonSR_mass100_stack_1->GetNbinsX(); i++) {
    diphotonSR_mass100_stack_1->SetBinContent(i, 0);
    diphotonSR_mass100_stack_1->SetBinError(i, 1.84);
  }

  diphotonSR_mass100_stack_1->SetEntries(48);
  diphotonSR_mass100_stack_1->SetDirectory(0);

  ci = 1710;
  color = new TColor(ci, 0, 1, 0, " ", 0);
  diphotonSR_mass100_stack_1->SetFillColor(ci);

  ci = TColor::GetColor("#000000");
  diphotonSR_mass100_stack_1->SetLineColor(ci);
  diphotonSR_mass100_stack_1->SetMarkerStyle(20);
  diphotonSR_mass100_stack_1->GetXaxis()->SetRange(1, 48);
  diphotonSR_mass100_stack_1->GetXaxis()->SetLabelFont(42);
  diphotonSR_mass100_stack_1->GetXaxis()->SetLabelOffset(0.007);
  diphotonSR_mass100_stack_1->GetXaxis()->SetLabelSize(0.05);
  diphotonSR_mass100_stack_1->GetXaxis()->SetTitleSize(0.06);
  diphotonSR_mass100_stack_1->GetXaxis()->SetTitleOffset(0.9);
  diphotonSR_mass100_stack_1->GetXaxis()->SetTitleFont(42);
  diphotonSR_mass100_stack_1->GetYaxis()->SetLabelFont(42);
  diphotonSR_mass100_stack_1->GetYaxis()->SetLabelOffset(0.007);
  diphotonSR_mass100_stack_1->GetYaxis()->SetLabelSize(0.05);
  diphotonSR_mass100_stack_1->GetYaxis()->SetTitleSize(0.06);
  diphotonSR_mass100_stack_1->GetYaxis()->SetTitleOffset(1.25);
  diphotonSR_mass100_stack_1->GetYaxis()->SetTitleFont(42);
  diphotonSR_mass100_stack_1->GetZaxis()->SetLabelFont(42);
  diphotonSR_mass100_stack_1->GetZaxis()->SetLabelOffset(0.007);
  diphotonSR_mass100_stack_1->GetZaxis()->SetLabelSize(0.05);
  diphotonSR_mass100_stack_1->GetZaxis()->SetTitleSize(0.06);
  diphotonSR_mass100_stack_1->GetZaxis()->SetTitleOffset(1);
  diphotonSR_mass100_stack_1->GetZaxis()->SetTitleFont(42);
  diphotonSR_mass100data->Add(diphotonSR_mass100_stack_1, "");
  diphotonSR_mass100data->Draw("nostack pe0 same");

  auto diphotonSR_mass100signal = new THStack();
  diphotonSR_mass100signal->SetName("diphotonSR_mass100signal");
  diphotonSR_mass100signal->SetTitle("");
  diphotonSR_mass100signal->SetMinimum(0);
  diphotonSR_mass100signal->SetMaximum(20);
  Double_t xAxis356[49] = {4,  6,  8,  10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52,
                           54, 56, 58, 60, 62, 64, 66, 68, 70, 72, 74, 76, 78, 80, 82, 84, 86, 88, 90, 92, 94, 96, 98, 100};

  TH1F *diphotonSR_mass100signal_stack_90 = new TH1F("diphotonSR_mass100signal_stack_90", "", 48, xAxis356);
  diphotonSR_mass100signal_stack_90->SetMinimum(0);
  diphotonSR_mass100signal_stack_90->SetMaximum(20);
  diphotonSR_mass100signal_stack_90->SetDirectory(0);
  diphotonSR_mass100signal_stack_90->SetStats(0);
  diphotonSR_mass100signal_stack_90->SetLineStyle(0);
  diphotonSR_mass100signal_stack_90->GetXaxis()->SetTitle("m^{#gamma#gamma} (GeV)");
  diphotonSR_mass100signal->SetHistogram(diphotonSR_mass100signal_stack_90);

  Double_t xAxis357[8] = {8,  10, 12, 14, 16, 18, 20, 22};

  // ALP 14 GeV
  diphotonSR_mass100_stack_1 = new TH1F("diphotonSR_mass100_stack_1", "diphotonSR_mass100", 7, xAxis357);
  diphotonSR_mass100_stack_1->SetBinContent(1, 0.1046461);
  diphotonSR_mass100_stack_1->SetBinContent(2, 0.5423657);
  diphotonSR_mass100_stack_1->SetBinContent(3, 9.419194);
  diphotonSR_mass100_stack_1->SetBinContent(4, 9.102266);
  diphotonSR_mass100_stack_1->SetBinContent(5, 0.4016915);
  diphotonSR_mass100_stack_1->SetBinContent(6, 0.07100984);
  diphotonSR_mass100_stack_1->SetBinContent(7, 0.0005979777);
  

  diphotonSR_mass100_stack_1->SetFillColorAlpha(kGray + 2, 0.2);
  diphotonSR_mass100_stack_1->SetLineColor(kGray + 2);

  diphotonSR_mass100_stack_1->SetLineWidth(3);
  diphotonSR_mass100_stack_1->SetMarkerStyle(20);
  diphotonSR_mass100_stack_1->SetMarkerSize(0);
  diphotonSR_mass100_stack_1->GetXaxis()->SetRange(1, 48);
  diphotonSR_mass100_stack_1->GetXaxis()->SetLabelFont(42);
  diphotonSR_mass100_stack_1->GetXaxis()->SetLabelOffset(0.007);
  diphotonSR_mass100_stack_1->GetXaxis()->SetLabelSize(0.05);
  diphotonSR_mass100_stack_1->GetXaxis()->SetTitleSize(0.06);
  diphotonSR_mass100_stack_1->GetXaxis()->SetTitleOffset(0.9);
  diphotonSR_mass100_stack_1->GetXaxis()->SetTitleFont(42);
  diphotonSR_mass100_stack_1->GetYaxis()->SetLabelFont(42);
  diphotonSR_mass100_stack_1->GetYaxis()->SetLabelOffset(0.007);
  diphotonSR_mass100_stack_1->GetYaxis()->SetLabelSize(0.05);
  diphotonSR_mass100_stack_1->GetYaxis()->SetTitleSize(0.06);
  diphotonSR_mass100_stack_1->GetYaxis()->SetTitleOffset(1.25);
  diphotonSR_mass100_stack_1->GetYaxis()->SetTitleFont(42);
  diphotonSR_mass100_stack_1->GetZaxis()->SetLabelFont(42);
  diphotonSR_mass100_stack_1->GetZaxis()->SetLabelOffset(0.007);
  diphotonSR_mass100_stack_1->GetZaxis()->SetLabelSize(0.05);
  diphotonSR_mass100_stack_1->GetZaxis()->SetTitleSize(0.06);
  diphotonSR_mass100_stack_1->GetZaxis()->SetTitleOffset(1);
  diphotonSR_mass100_stack_1->GetZaxis()->SetTitleFont(42);
  diphotonSR_mass100signal->Add(diphotonSR_mass100_stack_1, "");
  
  Double_t xAxis358[6] = {24, 26, 28, 30, 32, 34};

  // ALP 30 GeV
  diphotonSR_mass100_stack_2 = new TH1F("diphotonSR_mass100_stack_2", "diphotonSR_mass100", 5, xAxis358);
  diphotonSR_mass100_stack_2->SetBinContent(1, 0.05481279);
  diphotonSR_mass100_stack_2->SetBinContent(2, 0.287598);
  diphotonSR_mass100_stack_2->SetBinContent(3, 4.15914);
  diphotonSR_mass100_stack_2->SetBinContent(4, 3.809376);
  diphotonSR_mass100_stack_2->SetBinContent(5, 0.2068901);
  diphotonSR_mass100_stack_2->SetDirectory(0);

  ci = 1946;
  color = new TColor(ci, 1, 0, 0, " ", 0.2);
  diphotonSR_mass100_stack_2->SetFillColor(ci);

  ci = TColor::GetColor("#ff0000");
  diphotonSR_mass100_stack_2->SetLineColor(ci);
  diphotonSR_mass100_stack_2->SetLineWidth(3);
  diphotonSR_mass100_stack_2->SetMarkerStyle(20);
  diphotonSR_mass100_stack_2->SetMarkerSize(0);
  diphotonSR_mass100_stack_2->GetXaxis()->SetRange(1, 48);
  diphotonSR_mass100_stack_2->GetXaxis()->SetLabelFont(42);
  diphotonSR_mass100_stack_2->GetXaxis()->SetLabelOffset(0.007);
  diphotonSR_mass100_stack_2->GetXaxis()->SetLabelSize(0.05);
  diphotonSR_mass100_stack_2->GetXaxis()->SetTitleSize(0.06);
  diphotonSR_mass100_stack_2->GetXaxis()->SetTitleOffset(0.9);
  diphotonSR_mass100_stack_2->GetXaxis()->SetTitleFont(42);
  diphotonSR_mass100_stack_2->GetYaxis()->SetLabelFont(42);
  diphotonSR_mass100_stack_2->GetYaxis()->SetLabelOffset(0.007);
  diphotonSR_mass100_stack_2->GetYaxis()->SetLabelSize(0.05);
  diphotonSR_mass100_stack_2->GetYaxis()->SetTitleSize(0.06);
  diphotonSR_mass100_stack_2->GetYaxis()->SetTitleOffset(1.25);
  diphotonSR_mass100_stack_2->GetYaxis()->SetTitleFont(42);
  diphotonSR_mass100_stack_2->GetZaxis()->SetLabelFont(42);
  diphotonSR_mass100_stack_2->GetZaxis()->SetLabelOffset(0.007);
  diphotonSR_mass100_stack_2->GetZaxis()->SetLabelSize(0.05);
  diphotonSR_mass100_stack_2->GetZaxis()->SetTitleSize(0.06);
  diphotonSR_mass100_stack_2->GetZaxis()->SetTitleOffset(1);
  diphotonSR_mass100_stack_2->GetZaxis()->SetTitleFont(42);
  diphotonSR_mass100signal->Add(diphotonSR_mass100_stack_2, "");
  diphotonSR_mass100signal->Draw("hist nostack same");
  Double_t xAxis359[49] = {4,  6,  8,  10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52,
                           54, 56, 58, 60, 62, 64, 66, 68, 70, 72, 74, 76, 78, 80, 82, 84, 86, 88, 90, 92, 94, 96, 98, 100};

  TH1F *backgrounds_unc_diphotonSR_mass100__59 = new TH1F("backgrounds_unc_diphotonSR_mass100__59", "diphotonSR_mass100", 48, xAxis359);
  backgrounds_unc_diphotonSR_mass100__59->SetBinContent(1, 3.909151);
  backgrounds_unc_diphotonSR_mass100__59->SetBinContent(2, 8.482277);
  backgrounds_unc_diphotonSR_mass100__59->SetBinContent(3, 5.24764);
  backgrounds_unc_diphotonSR_mass100__59->SetBinContent(4, 2.921784);
  backgrounds_unc_diphotonSR_mass100__59->SetBinContent(5, 1.365335);
  backgrounds_unc_diphotonSR_mass100__59->SetBinContent(6, 0.932892);
  backgrounds_unc_diphotonSR_mass100__59->SetBinContent(7, 0.5459444);
  backgrounds_unc_diphotonSR_mass100__59->SetBinContent(8, 0.3526511);
  backgrounds_unc_diphotonSR_mass100__59->SetBinContent(9, 0.3393335);
  backgrounds_unc_diphotonSR_mass100__59->SetBinContent(10, 0.1922491);
  backgrounds_unc_diphotonSR_mass100__59->SetBinContent(11, 0.1077932);
  backgrounds_unc_diphotonSR_mass100__59->SetBinContent(12, 0.07138644);
  backgrounds_unc_diphotonSR_mass100__59->SetBinContent(13, 0.09727751);
  backgrounds_unc_diphotonSR_mass100__59->SetBinContent(14, 0.03887794);
  backgrounds_unc_diphotonSR_mass100__59->SetBinContent(15, 0.1110606);
  backgrounds_unc_diphotonSR_mass100__59->SetBinContent(16, 0.01625425);
  backgrounds_unc_diphotonSR_mass100__59->SetBinContent(17, 0.01943897);
  backgrounds_unc_diphotonSR_mass100__59->SetBinContent(18, 0.01131185);
  backgrounds_unc_diphotonSR_mass100__59->SetBinContent(19, 0.01696777);
  backgrounds_unc_diphotonSR_mass100__59->SetBinContent(20, 0.007413605);
  backgrounds_unc_diphotonSR_mass100__59->SetBinContent(21, 0.01378305);
  backgrounds_unc_diphotonSR_mass100__59->SetBinContent(22, 0.005655923);
  backgrounds_unc_diphotonSR_mass100__59->SetBinContent(25, 0.005655923);
  backgrounds_unc_diphotonSR_mass100__59->SetBinContent(26, 0.01131185);
  backgrounds_unc_diphotonSR_mass100__59->SetBinError(1, 0.9165091);
  backgrounds_unc_diphotonSR_mass100__59->SetBinError(2, 1.966682);
  backgrounds_unc_diphotonSR_mass100__59->SetBinError(3, 1.229452);
  backgrounds_unc_diphotonSR_mass100__59->SetBinError(4, 0.6949998);
  backgrounds_unc_diphotonSR_mass100__59->SetBinError(5, 0.331051);
  backgrounds_unc_diphotonSR_mass100__59->SetBinError(6, 0.2348207);
  backgrounds_unc_diphotonSR_mass100__59->SetBinError(7, 0.1354959);
  backgrounds_unc_diphotonSR_mass100__59->SetBinError(8, 0.09078994);
  backgrounds_unc_diphotonSR_mass100__59->SetBinError(9, 0.1122152);
  backgrounds_unc_diphotonSR_mass100__59->SetBinError(10, 0.05400551);
  backgrounds_unc_diphotonSR_mass100__59->SetBinError(11, 0.03419421);
  backgrounds_unc_diphotonSR_mass100__59->SetBinError(12, 0.0250223);
  backgrounds_unc_diphotonSR_mass100__59->SetBinError(13, 0.07645249);
  backgrounds_unc_diphotonSR_mass100__59->SetBinError(14, 0.01685552);
  backgrounds_unc_diphotonSR_mass100__59->SetBinError(15, 0.07789078);
  backgrounds_unc_diphotonSR_mass100__59->SetBinError(16, 0.009495726);
  backgrounds_unc_diphotonSR_mass100__59->SetBinError(17, 0.01104829);
  backgrounds_unc_diphotonSR_mass100__59->SetBinError(18, 0.008411177);
  backgrounds_unc_diphotonSR_mass100__59->SetBinError(19, 0.01054507);
  backgrounds_unc_diphotonSR_mass100__59->SetBinError(20, 0.004607383);
  backgrounds_unc_diphotonSR_mass100__59->SetBinError(21, 0.008951832);
  backgrounds_unc_diphotonSR_mass100__59->SetBinError(22, 0.005803594);
  backgrounds_unc_diphotonSR_mass100__59->SetBinError(25, 0.005803594);
  backgrounds_unc_diphotonSR_mass100__59->SetBinError(26, 0.008411177);
  backgrounds_unc_diphotonSR_mass100__59->SetEntries(192);

  ci = 2034;
  color = new TColor(ci, 0, 0, 0, " ", 0.3);
  backgrounds_unc_diphotonSR_mass100__59->SetFillColor(ci);
  backgrounds_unc_diphotonSR_mass100__59->SetFillStyle(3244);
  backgrounds_unc_diphotonSR_mass100__59->SetMarkerStyle(20);
  backgrounds_unc_diphotonSR_mass100__59->SetMarkerSize(0);
  backgrounds_unc_diphotonSR_mass100__59->GetXaxis()->SetRange(1, 48);
  backgrounds_unc_diphotonSR_mass100__59->GetXaxis()->SetLabelFont(42);
  backgrounds_unc_diphotonSR_mass100__59->GetXaxis()->SetLabelOffset(0.007);
  backgrounds_unc_diphotonSR_mass100__59->GetXaxis()->SetLabelSize(0.05);
  backgrounds_unc_diphotonSR_mass100__59->GetXaxis()->SetTitleSize(0.06);
  backgrounds_unc_diphotonSR_mass100__59->GetXaxis()->SetTitleOffset(0.9);
  backgrounds_unc_diphotonSR_mass100__59->GetXaxis()->SetTitleFont(42);
  backgrounds_unc_diphotonSR_mass100__59->GetYaxis()->SetLabelFont(42);
  backgrounds_unc_diphotonSR_mass100__59->GetYaxis()->SetLabelOffset(0.007);
  backgrounds_unc_diphotonSR_mass100__59->GetYaxis()->SetLabelSize(0.05);
  backgrounds_unc_diphotonSR_mass100__59->GetYaxis()->SetTitleSize(0.06);
  backgrounds_unc_diphotonSR_mass100__59->GetYaxis()->SetTitleOffset(1.25);
  backgrounds_unc_diphotonSR_mass100__59->GetYaxis()->SetTitleFont(42);
  backgrounds_unc_diphotonSR_mass100__59->GetZaxis()->SetLabelFont(42);
  backgrounds_unc_diphotonSR_mass100__59->GetZaxis()->SetLabelOffset(0.007);
  backgrounds_unc_diphotonSR_mass100__59->GetZaxis()->SetLabelSize(0.05);
  backgrounds_unc_diphotonSR_mass100__59->GetZaxis()->SetTitleSize(0.06);
  backgrounds_unc_diphotonSR_mass100__59->GetZaxis()->SetTitleOffset(1);
  backgrounds_unc_diphotonSR_mass100__59->GetZaxis()->SetTitleFont(42);
  backgrounds_unc_diphotonSR_mass100__59->Draw("same e2");

  TLegend *leg = new TLegend(0.62, 0.7, 0.82, 0.75, NULL, "brNDC");
  leg->SetBorderSize(0);
  leg->SetTextSize(0.035);
  leg->SetLineColor(1);
  leg->SetLineStyle(1);
  leg->SetLineWidth(1);
  leg->SetFillColor(0);
  leg->SetFillStyle(1001);
  TLegendEntry *entry = leg->AddEntry("diphotonSR_mass100_stack_3", "#gamma#gamma#rightarrowe^{+}e^{-}", "FL");

  ci = TColor::GetColor("#ffff00");
  entry->SetFillColor(ci);
  entry->SetFillStyle(1001);

  ci = TColor::GetColor("#000000");
  entry->SetLineColor(ci);
  entry->SetLineStyle(1);
  entry->SetLineWidth(1);
  entry->SetMarkerColor(1);
  entry->SetMarkerStyle(21);
  entry->SetMarkerSize(1);
  entry->SetTextFont(42);
  leg->Draw();

  leg = new TLegend(0.72, 0.75, 0.82, 0.8, NULL, "brNDC");
  leg->SetBorderSize(0);
  leg->SetTextSize(0.035);
  leg->SetLineColor(1);
  leg->SetLineStyle(1);
  leg->SetLineWidth(1);
  leg->SetFillColor(0);
  leg->SetFillStyle(1001);
  leg->Draw();

  leg = new TLegend(0.62, 0.8, 0.82, 0.89, NULL, "brNDC");
  leg->SetBorderSize(0);
  leg->SetTextSize(0.035);
  leg->SetLineColor(1);
  leg->SetLineStyle(1);
  leg->SetLineWidth(1);
  leg->SetFillColor(0);
  leg->SetFillStyle(1001);
  entry = leg->AddEntry("diphotonSR_mass100_stack_1", "Data", "pl");

  ci = TColor::GetColor("#000000");
  entry->SetLineColor(ci);
  entry->SetLineStyle(1);
  entry->SetLineWidth(1);
  entry->SetMarkerColor(1);
  entry->SetMarkerStyle(20);
  entry->SetMarkerSize(1);
  entry->SetTextFont(42);
  leg->Draw();

  leg = new TLegend(0.62, 0.75, 0.82, 0.8, NULL, "brNDC");
  leg->SetBorderSize(0);
  leg->SetTextSize(0.035);
  leg->SetLineColor(1);
  leg->SetLineStyle(1);
  leg->SetLineWidth(1);
  leg->SetFillColor(0);
  leg->SetFillStyle(1001);
  entry = leg->AddEntry("diphotonSR_mass100_stack_4", "#gamma#gamma#rightarrow#gamma#gamma", "FL");

  ci = TColor::GetColor("#ff9933");
  entry->SetFillColor(ci);
  entry->SetFillStyle(1001);

  ci = TColor::GetColor("#000000");
  entry->SetLineColor(ci);
  entry->SetLineStyle(1);
  entry->SetLineWidth(1);
  entry->SetMarkerColor(1);
  entry->SetMarkerStyle(21);
  entry->SetMarkerSize(1);
  entry->SetTextFont(42);
  leg->Draw();

  leg = new TLegend(0.62, 0.65, 0.82, 0.7, NULL, "brNDC");
  leg->SetBorderSize(0);
  leg->SetTextSize(0.035);
  leg->SetLineColor(1);
  leg->SetLineStyle(1);
  leg->SetLineWidth(1);
  leg->SetFillColor(0);
  leg->SetFillStyle(1001);
  entry = leg->AddEntry("diphotonSR_mass100_stack_1", "gg#rightarrow#gamma#gamma", "FL");

  ci = TColor::GetColor("#6699ff");
  entry->SetFillColor(ci);
  entry->SetFillStyle(1001);

  ci = TColor::GetColor("#000000");
  entry->SetLineColor(ci);
  entry->SetLineStyle(1);
  entry->SetLineWidth(1);
  entry->SetMarkerColor(1);
  entry->SetMarkerStyle(21);
  entry->SetMarkerSize(1);
  entry->SetTextFont(42);
  leg->Draw();

  TLatex latex;
  latex.SetTextSize(0.03);  // Adjust the text size if needed
  latex.SetTextFont(42);
  latex.DrawLatexNDC(0.21, 0.85, "Injected ALP signals");  // First line
  // latex.DrawLatexNDC(0.21, 0.81, "(#sigma_{#gamma#gamma#rightarrow a #rightarrow#gamma#gamma} = 100 nb)"); // Second line, adjust
  // position accordingly
  latex.DrawLatexNDC(0.21, 0.81, "(g_{a#gamma} = 0.25 TeV^{-1})");  // Second line, adjust position accordingly

  leg = new TLegend(0.2, 0.72, 0.47, 0.77, NULL, "brNDC");
  leg->SetBorderSize(0);
  leg->SetTextSize(0.035);
  leg->SetLineColor(1);
  leg->SetLineStyle(1);
  leg->SetLineWidth(1);
  leg->SetFillColor(0);
  leg->SetFillStyle(1001);
  entry = leg->AddEntry(diphotonSR_mass100_stack_1, "m_{a} = 14 GeV", "fl");

  ci = TColor::GetColor("#cc00ff");
  entry->SetLineColor(ci);
  entry->SetLineStyle(1);
  entry->SetLineWidth(3);
  entry->SetMarkerColor(1);
  entry->SetMarkerStyle(21);
  entry->SetMarkerSize(1);
  entry->SetTextFont(42);
  leg->Draw();

  leg = new TLegend(0.2, 0.67, 0.47, 0.72, NULL, "brNDC");
  leg->SetBorderSize(0);
  leg->SetTextSize(0.035);
  leg->SetLineColor(1);
  leg->SetLineStyle(1);
  leg->SetLineWidth(1);
  leg->SetFillColor(0);
  leg->SetFillStyle(1001);
  entry = leg->AddEntry(diphotonSR_mass100_stack_2, "m_{a} = 30 GeV", "fl");

  ci = TColor::GetColor("#ff0000");
  entry->SetLineColor(ci);
  entry->SetLineStyle(1);
  entry->SetLineWidth(3);
  entry->SetMarkerColor(1);
  entry->SetMarkerStyle(21);
  entry->SetMarkerSize(1);
  entry->SetTextFont(42);
  leg->Draw();
  Double_t xAxis360[49] = {4,  6,  8,  10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52,
                           54, 56, 58, 60, 62, 64, 66, 68, 70, 72, 74, 76, 78, 80, 82, 84, 86, 88, 90, 92, 94, 96, 98, 100};

  TH1F *diphotonSR_mass100background_copy__60 = new TH1F("diphotonSR_mass100background_copy__60", "", 48, xAxis360);
  diphotonSR_mass100background_copy__60->SetMinimum(0);
  diphotonSR_mass100background_copy__60->SetMaximum(20);
  diphotonSR_mass100background_copy__60->SetDirectory(0);
  diphotonSR_mass100background_copy__60->SetStats(0);
  diphotonSR_mass100background_copy__60->SetLineStyle(0);
  diphotonSR_mass100background_copy__60->Draw("sameaxis");
  diphotonSR_mass100_1->Modified();
  canvas->cd();

  auto tex = new TLatex(0.11, 0.92, "#bf{CMS}");
  tex->SetNDC();
  tex->SetTextFont(42);
  tex->SetTextSize(0.05);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(0.58, 0.92, "#scale[0.8]{PbPb, 1.65 nb^{-1} (#sqrt{s_{NN}} = 5.02 TeV)}");
  tex->SetNDC();
  tex->SetTextFont(42);
  tex->SetTextSize(0.05);
  tex->SetLineWidth(2);
  tex->Draw();

  gPad->Modified();
  canvas->cd();

  // place a white square on top of x-axis labels 7, 9, 50, 70 to cover them
  TBox *box = new TBox(0.25, 0.0, 0.27, 0.14);
  box->SetFillColor(10);
  box->Draw();
  box = new TBox(0.3, 0.0, 0.34, 0.14);
  box->SetFillColor(10);
  box->Draw();
  box = new TBox(0.75, 0.0, 0.80, 0.14);
  box->SetFillColor(10);
  box->Draw();
  box = new TBox(0.85, 0.1, 0.90, 0.14);
  box->SetFillColor(10);
  box->Draw();


  canvas->Modified();
  canvas->cd();
  canvas->SetSelected(canvas);
  canvas->SaveAs("figures/Figure_008_a.pdf");
}
