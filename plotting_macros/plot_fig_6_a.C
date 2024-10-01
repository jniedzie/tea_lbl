#ifdef __CLING__
#pragma cling optimize(0)
#endif

#include "style.h"

void plot_fig_6_a() {
  gROOT->SetBatch(kTRUE);
  //=========Macro generated from canvas: goodPhotonSR_et/goodPhotonSR_et
  //=========  (Sun Mar 31 12:51:37 2024) by ROOT version 6.26/08
  TCanvas *goodPhotonSR_et = new TCanvas("goodPhotonSR_et", "goodPhotonSR_et", 0, 0, 800, 600);
  gStyle->SetOptFit(1);
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  goodPhotonSR_et->SetHighLightColor(2);
  goodPhotonSR_et->Range(0, 0, 1, 1);
  goodPhotonSR_et->SetFillColor(0);
  goodPhotonSR_et->SetBorderMode(0);
  goodPhotonSR_et->SetBorderSize(2);
  goodPhotonSR_et->SetTickx(1);
  goodPhotonSR_et->SetTicky(1);
  goodPhotonSR_et->SetLeftMargin(0.16);
  goodPhotonSR_et->SetRightMargin(0.15);
  goodPhotonSR_et->SetTopMargin(0.06);
  goodPhotonSR_et->SetBottomMargin(0.3);
  goodPhotonSR_et->SetFrameFillStyle(0);
  goodPhotonSR_et->SetFrameBorderMode(0);

  // ------------>Primitives in pad: goodPhotonSR_et_1
  TPad *goodPhotonSR_et_1 = new TPad("goodPhotonSR_et_1", "goodPhotonSR_et_1", 0, 0.3, 1, 1);
  goodPhotonSR_et_1->Draw();
  goodPhotonSR_et_1->cd();
  goodPhotonSR_et_1->Range(0.6086958, 0, 9.304348, 38.46154);
  goodPhotonSR_et_1->SetFillColor(0);
  goodPhotonSR_et_1->SetBorderMode(0);
  goodPhotonSR_et_1->SetBorderSize(2);
  goodPhotonSR_et_1->SetLeftMargin(0.16);
  goodPhotonSR_et_1->SetRightMargin(0.15);
  goodPhotonSR_et_1->SetBottomMargin(0.05);
  goodPhotonSR_et_1->SetFrameFillStyle(0);
  goodPhotonSR_et_1->SetFrameBorderMode(0);
  goodPhotonSR_et_1->SetFrameFillStyle(0);
  goodPhotonSR_et_1->SetFrameLineWidth(2);
  goodPhotonSR_et_1->SetFrameBorderMode(0);
  goodPhotonSR_et_1->SetFrameBorderSize(2);

  THStack *goodPhotonSR_etbackground = new THStack();
  goodPhotonSR_etbackground->SetName("goodPhotonSR_etbackground");
  goodPhotonSR_etbackground->SetTitle("");
  goodPhotonSR_etbackground->SetMaximum(35);

  TH1F *goodPhotonSR_etbackground_stack_1 = new TH1F("goodPhotonSR_etbackground_stack_1", "", 5, 2, 8);
  goodPhotonSR_etbackground_stack_1->SetMinimum(0);
  goodPhotonSR_etbackground_stack_1->SetMaximum(35);
  goodPhotonSR_etbackground_stack_1->SetDirectory(0);
  goodPhotonSR_etbackground_stack_1->SetStats(0);
  goodPhotonSR_etbackground_stack_1->SetLineStyle(0);
  goodPhotonSR_etbackground_stack_1->GetXaxis()->SetTitle("E_{T}^{#gamma} (GeV)");
  goodPhotonSR_etbackground_stack_1->GetXaxis()->SetLabelFont(42);
  goodPhotonSR_etbackground_stack_1->GetXaxis()->SetLabelOffset(0.007);
  goodPhotonSR_etbackground_stack_1->GetXaxis()->SetLabelSize(0.0);
  goodPhotonSR_etbackground_stack_1->GetXaxis()->SetTitleSize(fig_6_x_title_size);
  goodPhotonSR_etbackground_stack_1->GetXaxis()->SetTitleOffset(1.7);
  goodPhotonSR_etbackground_stack_1->GetXaxis()->SetTitleFont(42);
  goodPhotonSR_etbackground_stack_1->GetYaxis()->SetTitle("Entries / 1.2 (GeV^{-1})");
  goodPhotonSR_etbackground_stack_1->GetYaxis()->CenterTitle(true);
  goodPhotonSR_etbackground_stack_1->GetYaxis()->SetNdivisions(505);
  goodPhotonSR_etbackground_stack_1->GetYaxis()->SetLabelFont(42);
  goodPhotonSR_etbackground_stack_1->GetYaxis()->SetLabelOffset(0.007);
  goodPhotonSR_etbackground_stack_1->GetYaxis()->SetLabelSize(0.06);
  goodPhotonSR_etbackground_stack_1->GetYaxis()->SetTitleSize(fig_6_y_title_size);
  goodPhotonSR_etbackground_stack_1->GetYaxis()->SetTitleOffset(1.0);
  goodPhotonSR_etbackground_stack_1->GetYaxis()->SetTitleFont(42);
  goodPhotonSR_etbackground_stack_1->GetZaxis()->SetLabelFont(42);
  goodPhotonSR_etbackground_stack_1->GetZaxis()->SetLabelOffset(0.007);
  goodPhotonSR_etbackground_stack_1->GetZaxis()->SetLabelSize(0.05);
  goodPhotonSR_etbackground_stack_1->GetZaxis()->SetTitleSize(0.06);
  goodPhotonSR_etbackground_stack_1->GetZaxis()->SetTitleOffset(1);
  goodPhotonSR_etbackground_stack_1->GetZaxis()->SetTitleFont(42);
  goodPhotonSR_etbackground->SetHistogram(goodPhotonSR_etbackground_stack_1);

  // CEP
  TH1D *goodPhotonSR_et_stack_1 = new TH1D("goodPhotonSR_et_stack_1", "goodPhotonSR_et", 5, 2, 8);
  goodPhotonSR_et_stack_1->SetBinContent(1, 7.885605);
  goodPhotonSR_et_stack_1->SetBinContent(2, 7.472914);
  goodPhotonSR_et_stack_1->SetBinContent(3, 2.710908);
  goodPhotonSR_et_stack_1->SetBinContent(4, 1.097214);
  goodPhotonSR_et_stack_1->SetBinContent(5, 0.5436644);
  goodPhotonSR_et_stack_1->SetBinContent(6, 0.4991827);
  goodPhotonSR_et_stack_1->SetBinError(1, 0.1395956);
  goodPhotonSR_et_stack_1->SetBinError(2, 0.1358936);
  goodPhotonSR_et_stack_1->SetBinError(3, 0.08184865);
  goodPhotonSR_et_stack_1->SetBinError(4, 0.05207145);
  goodPhotonSR_et_stack_1->SetBinError(5, 0.03665384);
  goodPhotonSR_et_stack_1->SetBinError(6, 0.03512238);
  goodPhotonSR_et_stack_1->SetEntries(8178);
  goodPhotonSR_et_stack_1->SetDirectory(0);

  Int_t ci;       // for color index setting
  TColor *color;  // for color definition with alpha
  ci = TColor::GetColor("#6699ff");
  goodPhotonSR_et_stack_1->SetFillColor(ci);

  ci = TColor::GetColor("#000000");
  goodPhotonSR_et_stack_1->SetLineColor(ci);
  goodPhotonSR_et_stack_1->SetMarkerStyle(20);
  goodPhotonSR_et_stack_1->GetXaxis()->SetRange(1, 5);
  goodPhotonSR_et_stack_1->GetXaxis()->SetLabelFont(42);
  goodPhotonSR_et_stack_1->GetXaxis()->SetTitleOffset(1);
  goodPhotonSR_et_stack_1->GetXaxis()->SetTitleFont(42);
  goodPhotonSR_et_stack_1->GetYaxis()->SetLabelFont(42);
  goodPhotonSR_et_stack_1->GetYaxis()->SetTitleFont(42);
  goodPhotonSR_et_stack_1->GetZaxis()->SetLabelFont(42);
  goodPhotonSR_et_stack_1->GetZaxis()->SetTitleOffset(1);
  goodPhotonSR_et_stack_1->GetZaxis()->SetTitleFont(42);
  goodPhotonSR_etbackground->Add(goodPhotonSR_et_stack_1, "");

  // QED 1
  TH1D *goodPhotonSR_et_stack_2 = new TH1D("goodPhotonSR_et_stack_2", "goodPhotonSR_et", 5, 2, 8);
  goodPhotonSR_et_stack_2->SetBinContent(1, 0.5749687);
  goodPhotonSR_et_stack_2->SetBinContent(2, 0.5174719);
  goodPhotonSR_et_stack_2->SetBinContent(3, 0.3449812);
  goodPhotonSR_et_stack_2->SetBinContent(4, 0.05749687);
  // goodPhotonSR_et_stack_2->SetBinContent(5, 0.0);
  // goodPhotonSR_et_stack_2->SetBinContent(6, 0.0);

  goodPhotonSR_et_stack_2->SetBinError(1, 0.1818211);
  goodPhotonSR_et_stack_2->SetBinError(2, 0.1724906);
  goodPhotonSR_et_stack_2->SetBinError(3, 0.140838);
  goodPhotonSR_et_stack_2->SetBinError(4, 0.05749687);
  // goodPhotonSR_et_stack_2->SetBinError(5, 2.0);
  // goodPhotonSR_et_stack_2->SetBinError(6, 2.0);
  goodPhotonSR_et_stack_2->SetEntries(26);
  goodPhotonSR_et_stack_2->SetDirectory(0);

  ci = TColor::GetColor("#ffff00");
  goodPhotonSR_et_stack_2->SetFillColor(ci);

  ci = TColor::GetColor("#ffff00");
  goodPhotonSR_et_stack_2->SetLineColor(ci);
  goodPhotonSR_et_stack_2->SetMarkerStyle(20);
  goodPhotonSR_et_stack_2->SetMarkerSize(0);
  goodPhotonSR_et_stack_2->GetXaxis()->SetRange(1, 5);
  goodPhotonSR_et_stack_2->GetXaxis()->SetLabelFont(42);
  goodPhotonSR_et_stack_2->GetXaxis()->SetTitleOffset(1);
  goodPhotonSR_et_stack_2->GetXaxis()->SetTitleFont(42);
  goodPhotonSR_et_stack_2->GetYaxis()->SetLabelFont(42);
  goodPhotonSR_et_stack_2->GetYaxis()->SetTitleFont(42);
  goodPhotonSR_et_stack_2->GetZaxis()->SetLabelFont(42);
  goodPhotonSR_et_stack_2->GetZaxis()->SetTitleOffset(1);
  goodPhotonSR_et_stack_2->GetZaxis()->SetTitleFont(42);
  goodPhotonSR_etbackground->Add(goodPhotonSR_et_stack_2, "");

  // QED 2
  TH1D *goodPhotonSR_et_stack_3 = new TH1D("goodPhotonSR_et_stack_3", "goodPhotonSR_et", 5, 2, 8);
  goodPhotonSR_et_stack_3->SetBinContent(1, 0.7218262);
  goodPhotonSR_et_stack_3->SetBinContent(2, 0.8661914);
  goodPhotonSR_et_stack_3->SetBinContent(3, 0.2887305);
  goodPhotonSR_et_stack_3->SetBinContent(4, 0.2165479);
  goodPhotonSR_et_stack_3->SetBinContent(5, 0.07218262);
  goodPhotonSR_et_stack_3->SetBinContent(6, 0.1443652);
  goodPhotonSR_et_stack_3->SetBinError(1, 0.2282615);
  goodPhotonSR_et_stack_3->SetBinError(2, 0.2500479);
  goodPhotonSR_et_stack_3->SetBinError(3, 0.1443652);
  goodPhotonSR_et_stack_3->SetBinError(4, 0.125024);
  goodPhotonSR_et_stack_3->SetBinError(5, 0.07218262);
  goodPhotonSR_et_stack_3->SetBinError(6, 0.1020816);
  goodPhotonSR_et_stack_3->SetEntries(32);
  goodPhotonSR_et_stack_3->SetDirectory(0);

  ci = TColor::GetColor("#ffff00");
  goodPhotonSR_et_stack_3->SetFillColor(ci);

  ci = TColor::GetColor("#000000");
  goodPhotonSR_et_stack_3->SetLineColor(ci);
  goodPhotonSR_et_stack_3->SetMarkerStyle(20);
  goodPhotonSR_et_stack_3->SetMarkerSize(0);
  goodPhotonSR_et_stack_3->GetXaxis()->SetRange(1, 5);
  goodPhotonSR_et_stack_3->GetXaxis()->SetLabelFont(42);
  goodPhotonSR_et_stack_3->GetXaxis()->SetTitleOffset(1);
  goodPhotonSR_et_stack_3->GetXaxis()->SetTitleFont(42);
  goodPhotonSR_et_stack_3->GetYaxis()->SetLabelFont(42);
  goodPhotonSR_et_stack_3->GetYaxis()->SetTitleFont(42);
  goodPhotonSR_et_stack_3->GetZaxis()->SetLabelFont(42);
  goodPhotonSR_et_stack_3->GetZaxis()->SetTitleOffset(1);
  goodPhotonSR_et_stack_3->GetZaxis()->SetTitleFont(42);
  goodPhotonSR_etbackground->Add(goodPhotonSR_et_stack_3, "");

  // LbL
  TH1D *goodPhotonSR_et_stack_4 = new TH1D("goodPhotonSR_et_stack_4", "goodPhotonSR_et", 5, 2, 8);
  goodPhotonSR_et_stack_4->SetBinContent(1, 8.370766);
  goodPhotonSR_et_stack_4->SetBinContent(2, 8.845863);
  goodPhotonSR_et_stack_4->SetBinContent(3, 4.304157);
  goodPhotonSR_et_stack_4->SetBinContent(4, 1.538411);
  goodPhotonSR_et_stack_4->SetBinContent(5, 0.9106036);
  goodPhotonSR_et_stack_4->SetBinContent(6, 1.674153);
  goodPhotonSR_et_stack_4->SetBinError(1, 0.2175877);
  goodPhotonSR_et_stack_4->SetBinError(2, 0.2236773);
  goodPhotonSR_et_stack_4->SetBinError(3, 0.1560256);
  goodPhotonSR_et_stack_4->SetBinError(4, 0.09327987);
  goodPhotonSR_et_stack_4->SetBinError(5, 0.07176561);
  goodPhotonSR_et_stack_4->SetBinError(6, 0.09730817);
  goodPhotonSR_et_stack_4->SetEntries(4534);
  goodPhotonSR_et_stack_4->SetDirectory(0);

  ci = TColor::GetColor("#ff9933");
  goodPhotonSR_et_stack_4->SetFillColor(ci);

  ci = TColor::GetColor("#000000");
  goodPhotonSR_et_stack_4->SetLineColor(ci);
  goodPhotonSR_et_stack_4->SetMarkerStyle(20);
  goodPhotonSR_et_stack_4->GetXaxis()->SetRange(1, 5);
  goodPhotonSR_et_stack_4->GetXaxis()->SetLabelFont(42);
  goodPhotonSR_et_stack_4->GetXaxis()->SetTitleOffset(1);
  goodPhotonSR_et_stack_4->GetXaxis()->SetTitleFont(42);
  goodPhotonSR_et_stack_4->GetYaxis()->SetLabelFont(42);
  goodPhotonSR_et_stack_4->GetYaxis()->SetTitleFont(42);
  goodPhotonSR_et_stack_4->GetZaxis()->SetLabelFont(42);
  goodPhotonSR_et_stack_4->GetZaxis()->SetTitleOffset(1);
  goodPhotonSR_et_stack_4->GetZaxis()->SetTitleFont(42);
  goodPhotonSR_etbackground->Add(goodPhotonSR_et_stack_4, "");
  goodPhotonSR_etbackground->Draw("hist");

  // Data points
  Double_t Graph0_fx3001[5] = {2.6, 3.8, 5, 6.2, 7.4};
  Double_t Graph0_fy3001[5] = {15, 24, 6, 7, 0};
  Double_t Graph0_felx3001[5] = {0.6, 0.6, 0.6, 0.6, 0.6};
  Double_t Graph0_fely3001[5] = {3.82938, 4.864612, 2.379931, 2.58147, 0};
  Double_t Graph0_fehx3001[5] = {0.6, 0.6, 0.6, 0.6, 0.6};
  Double_t Graph0_fehy3001[5] = {4.958738, 5.966932, 3.583642, 3.770281, 1.841022};
  TGraphAsymmErrors *grae =
      new TGraphAsymmErrors(5, Graph0_fx3001, Graph0_fy3001, Graph0_felx3001, Graph0_fehx3001, Graph0_fely3001, Graph0_fehy3001);
  grae->SetName("Graph0");
  grae->SetTitle("Graph");
  grae->SetFillStyle(1000);
  grae->SetMarkerStyle(20);

  TH1F *Graph_Graph03001 = new TH1F("Graph_Graph03001", "Graph", 100, 2.12, 7.88);
  Graph_Graph03001->SetMinimum(0);
  Graph_Graph03001->SetMaximum(32.96363);
  Graph_Graph03001->SetDirectory(0);
  Graph_Graph03001->SetStats(0);
  Graph_Graph03001->SetLineStyle(0);
  Graph_Graph03001->GetXaxis()->SetLabelFont(42);
  Graph_Graph03001->GetXaxis()->SetLabelOffset(0.007);
  Graph_Graph03001->GetXaxis()->SetLabelSize(0.05);
  Graph_Graph03001->GetXaxis()->SetTitleSize(0.06);
  Graph_Graph03001->GetXaxis()->SetTitleOffset(0.9);
  Graph_Graph03001->GetXaxis()->SetTitleFont(42);
  Graph_Graph03001->GetYaxis()->SetLabelFont(42);
  Graph_Graph03001->GetYaxis()->SetLabelOffset(0.007);
  Graph_Graph03001->GetYaxis()->SetLabelSize(0.05);
  Graph_Graph03001->GetYaxis()->SetTitleSize(0.06);
  Graph_Graph03001->GetYaxis()->SetTitleOffset(1.25);
  Graph_Graph03001->GetYaxis()->SetTitleFont(42);
  Graph_Graph03001->GetZaxis()->SetLabelFont(42);
  Graph_Graph03001->GetZaxis()->SetLabelOffset(0.007);
  Graph_Graph03001->GetZaxis()->SetLabelSize(0.05);
  Graph_Graph03001->GetZaxis()->SetTitleSize(0.06);
  Graph_Graph03001->GetZaxis()->SetTitleOffset(1);
  Graph_Graph03001->GetZaxis()->SetTitleFont(42);
  grae->SetHistogram(Graph_Graph03001);

  grae->Draw("pe");

  TH1D *backgrounds_unc_goodPhotonSR_et__1 = new TH1D("backgrounds_unc_goodPhotonSR_et__1", "goodPhotonSR_et", 5, 2, 8);
  backgrounds_unc_goodPhotonSR_et__1->SetBinContent(1, 17.55317);
  backgrounds_unc_goodPhotonSR_et__1->SetBinContent(2, 17.70244);
  backgrounds_unc_goodPhotonSR_et__1->SetBinContent(3, 7.648777);
  backgrounds_unc_goodPhotonSR_et__1->SetBinContent(4, 2.909669);
  backgrounds_unc_goodPhotonSR_et__1->SetBinContent(5, 1.526451);
  backgrounds_unc_goodPhotonSR_et__1->SetBinContent(6, 2.317701);
  backgrounds_unc_goodPhotonSR_et__1->SetBinError(1, 4.056008);
  backgrounds_unc_goodPhotonSR_et__1->SetBinError(2, 4.091257);
  backgrounds_unc_goodPhotonSR_et__1->SetBinError(3, 1.779486);
  backgrounds_unc_goodPhotonSR_et__1->SetBinError(4, 0.6915274);
  backgrounds_unc_goodPhotonSR_et__1->SetBinError(5, 0.3673743);
  backgrounds_unc_goodPhotonSR_et__1->SetBinError(6, 0.145338);
  backgrounds_unc_goodPhotonSR_et__1->SetEntries(12770);

  ci = 1555;
  color = new TColor(ci, 0, 0, 0, " ", 0.3);
  backgrounds_unc_goodPhotonSR_et__1->SetFillColorAlpha(ci, 0.5);
  backgrounds_unc_goodPhotonSR_et__1->SetFillStyle(3004);
  backgrounds_unc_goodPhotonSR_et__1->SetMarkerStyle(20);
  backgrounds_unc_goodPhotonSR_et__1->SetMarkerSize(0);
  backgrounds_unc_goodPhotonSR_et__1->GetXaxis()->SetRange(1, 5);
  backgrounds_unc_goodPhotonSR_et__1->GetXaxis()->SetLabelFont(42);
  backgrounds_unc_goodPhotonSR_et__1->GetXaxis()->SetTitleOffset(1);
  backgrounds_unc_goodPhotonSR_et__1->GetXaxis()->SetTitleFont(42);
  backgrounds_unc_goodPhotonSR_et__1->GetYaxis()->SetLabelFont(42);
  backgrounds_unc_goodPhotonSR_et__1->GetYaxis()->SetTitleFont(42);
  backgrounds_unc_goodPhotonSR_et__1->GetZaxis()->SetLabelFont(42);
  backgrounds_unc_goodPhotonSR_et__1->GetZaxis()->SetTitleOffset(1);
  backgrounds_unc_goodPhotonSR_et__1->GetZaxis()->SetTitleFont(42);
  backgrounds_unc_goodPhotonSR_et__1->Draw("same e2");

  auto leg = get_lbl_legend();
  // leg->Draw();

  TH1F *goodPhotonSR_etbackground_copy__2 = new TH1F("goodPhotonSR_etbackground_copy__2", "", 5, 2, 8);
  goodPhotonSR_etbackground_copy__2->SetMinimum(0);
  goodPhotonSR_etbackground_copy__2->SetMaximum(35);
  goodPhotonSR_etbackground_copy__2->SetDirectory(0);
  goodPhotonSR_etbackground_copy__2->SetStats(0);
  goodPhotonSR_etbackground_copy__2->SetLineStyle(0);
  goodPhotonSR_etbackground_copy__2->GetXaxis()->SetTitle("E_{T}^{#gamma} (GeV)");
  goodPhotonSR_etbackground_copy__2->GetXaxis()->SetLabelFont(42);
  goodPhotonSR_etbackground_copy__2->GetXaxis()->SetLabelOffset(0.007);
  goodPhotonSR_etbackground_copy__2->GetXaxis()->SetLabelSize(fig_6_x_label_size);
  goodPhotonSR_etbackground_copy__2->GetXaxis()->SetTitleSize(0.06);
  goodPhotonSR_etbackground_copy__2->GetXaxis()->SetTitleOffset(1.7);
  goodPhotonSR_etbackground_copy__2->GetXaxis()->SetTitleFont(42);
  goodPhotonSR_etbackground_copy__2->GetYaxis()->SetTitle("Entries / 1.2 (GeV^{-1})");
  goodPhotonSR_etbackground_copy__2->GetYaxis()->CenterTitle(true);
  goodPhotonSR_etbackground_copy__2->GetYaxis()->SetNdivisions(505);
  goodPhotonSR_etbackground_copy__2->GetYaxis()->SetLabelFont(42);
  goodPhotonSR_etbackground_copy__2->GetYaxis()->SetLabelOffset(0.007);
  goodPhotonSR_etbackground_copy__2->GetYaxis()->SetLabelSize(fig_6_y_label_size);
  goodPhotonSR_etbackground_copy__2->GetYaxis()->SetTitleSize(0.05);
  goodPhotonSR_etbackground_copy__2->GetYaxis()->SetTitleOffset(1.0);
  goodPhotonSR_etbackground_copy__2->GetYaxis()->SetTitleFont(42);
  goodPhotonSR_etbackground_copy__2->GetZaxis()->SetLabelFont(42);
  goodPhotonSR_etbackground_copy__2->GetZaxis()->SetLabelOffset(0.007);
  goodPhotonSR_etbackground_copy__2->GetZaxis()->SetLabelSize(0.05);
  goodPhotonSR_etbackground_copy__2->GetZaxis()->SetTitleSize(0.06);
  goodPhotonSR_etbackground_copy__2->GetZaxis()->SetTitleOffset(1);
  goodPhotonSR_etbackground_copy__2->GetZaxis()->SetTitleFont(42);
  goodPhotonSR_etbackground_copy__2->Draw("sameaxis");
  goodPhotonSR_et_1->Modified();
  goodPhotonSR_et->cd();

  // ------------>Primitives in pad: goodPhotonSR_et_2
  TPad *goodPhotonSR_et_2 = new TPad("goodPhotonSR_et_2", "goodPhotonSR_et_2", 0, 0, 1, 0.3);
  goodPhotonSR_et_2->Draw();
  goodPhotonSR_et_2->cd();
  goodPhotonSR_et_2->Range(0.6086958, -0.8571429, 9.304348, 2);
  goodPhotonSR_et_2->SetFillColor(0);
  goodPhotonSR_et_2->SetBorderMode(0);
  goodPhotonSR_et_2->SetBorderSize(2);
  goodPhotonSR_et_2->SetLeftMargin(0.16);
  goodPhotonSR_et_2->SetRightMargin(0.15);
  goodPhotonSR_et_2->SetTopMargin(0.05);
  goodPhotonSR_et_2->SetBottomMargin(fig_6_ratio_bottom_margin);
  goodPhotonSR_et_2->SetFrameFillStyle(0);
  goodPhotonSR_et_2->SetFrameBorderMode(0);
  goodPhotonSR_et_2->SetFrameFillStyle(0);
  goodPhotonSR_et_2->SetFrameBorderMode(0);

  auto ratio_stack_goodPhotonSR_et = new THStack();
  ratio_stack_goodPhotonSR_et->SetName("ratio_stack_goodPhotonSR_et");
  ratio_stack_goodPhotonSR_et->SetTitle("");
  ratio_stack_goodPhotonSR_et->SetMinimum(0);
  ratio_stack_goodPhotonSR_et->SetMaximum(2);

  TH1F *ratio_stack_goodPhotonSR_et_stack_3 = new TH1F("ratio_stack_goodPhotonSR_et_stack_3", "", 5, 2, 8);
  ratio_stack_goodPhotonSR_et_stack_3->SetMinimum(0);
  ratio_stack_goodPhotonSR_et_stack_3->SetMaximum(2);
  ratio_stack_goodPhotonSR_et_stack_3->SetDirectory(0);
  ratio_stack_goodPhotonSR_et_stack_3->SetStats(0);
  ratio_stack_goodPhotonSR_et_stack_3->SetLineStyle(0);
  ratio_stack_goodPhotonSR_et_stack_3->GetXaxis()->SetTitle("E_{T}^{#gamma} (GeV)");
  ratio_stack_goodPhotonSR_et_stack_3->GetXaxis()->SetLabelFont(42);
  ratio_stack_goodPhotonSR_et_stack_3->GetXaxis()->SetLabelOffset(0.007);
  ratio_stack_goodPhotonSR_et_stack_3->GetXaxis()->SetLabelSize(fig_6_x_ratio_label_size);
  ratio_stack_goodPhotonSR_et_stack_3->GetXaxis()->SetTitleSize(fig_6_x_ratio_title_size);
  ratio_stack_goodPhotonSR_et_stack_3->GetXaxis()->SetTitleOffset(1);
  ratio_stack_goodPhotonSR_et_stack_3->GetXaxis()->SetTitleFont(42);
  ratio_stack_goodPhotonSR_et_stack_3->GetYaxis()->SetTitle("Data/MC");
  ratio_stack_goodPhotonSR_et_stack_3->GetYaxis()->CenterTitle();
  ratio_stack_goodPhotonSR_et_stack_3->GetYaxis()->CenterTitle(true);
  ratio_stack_goodPhotonSR_et_stack_3->GetYaxis()->SetNdivisions(505);
  ratio_stack_goodPhotonSR_et_stack_3->GetYaxis()->SetLabelFont(42);
  ratio_stack_goodPhotonSR_et_stack_3->GetYaxis()->SetLabelOffset(0.007);
  ratio_stack_goodPhotonSR_et_stack_3->GetYaxis()->SetLabelSize(fig_6_y_ratio_label_size);
  ratio_stack_goodPhotonSR_et_stack_3->GetYaxis()->SetTitleSize(fig_6_y_ratio_title_size);
  ratio_stack_goodPhotonSR_et_stack_3->GetYaxis()->SetTitleOffset(0.5);
  ratio_stack_goodPhotonSR_et_stack_3->GetYaxis()->SetTitleFont(42);
  ratio_stack_goodPhotonSR_et_stack_3->GetZaxis()->SetLabelFont(42);
  ratio_stack_goodPhotonSR_et_stack_3->GetZaxis()->SetLabelOffset(0.007);
  ratio_stack_goodPhotonSR_et_stack_3->GetZaxis()->SetLabelSize(0.05);
  ratio_stack_goodPhotonSR_et_stack_3->GetZaxis()->SetTitleSize(0.06);
  ratio_stack_goodPhotonSR_et_stack_3->GetZaxis()->SetTitleOffset(1);
  ratio_stack_goodPhotonSR_et_stack_3->GetZaxis()->SetTitleFont(42);
  ratio_stack_goodPhotonSR_et->SetHistogram(ratio_stack_goodPhotonSR_et_stack_3);

  TH1D *ratio_goodPhotonSR_et_stack_1 = new TH1D("ratio_goodPhotonSR_et_stack_1", "goodPhotonSR_et", 5, 2, 8);
  ratio_goodPhotonSR_et_stack_1->SetBinContent(1, 0.8545467);
  ratio_goodPhotonSR_et_stack_1->SetBinContent(2, 1.355745);
  ratio_goodPhotonSR_et_stack_1->SetBinContent(3, 0.7844391);
  ratio_goodPhotonSR_et_stack_1->SetBinContent(4, 2.405772);
  ratio_goodPhotonSR_et_stack_1->SetBinContent(5, 0.0);
  ratio_goodPhotonSR_et_stack_1->SetBinError(1, 0.2214578);
  ratio_goodPhotonSR_et_stack_1->SetBinError(2, 0.2784389);
  ratio_goodPhotonSR_et_stack_1->SetBinError(3, 0.3214215);
  ratio_goodPhotonSR_et_stack_1->SetBinError(4, 0.9206343);
  ratio_goodPhotonSR_et_stack_1->SetBinError(5, 1.84);
  ratio_goodPhotonSR_et_stack_1->SetEntries(27.06891);

  ci = 1482;
  color = new TColor(ci, 0, 1, 0, " ", 0);
  ratio_goodPhotonSR_et_stack_1->SetFillColor(ci);

  ci = TColor::GetColor("#000000");
  ratio_goodPhotonSR_et_stack_1->SetLineColor(ci);
  ratio_goodPhotonSR_et_stack_1->SetMarkerStyle(20);
  ratio_goodPhotonSR_et_stack_1->GetXaxis()->SetRange(1, 5);
  ratio_goodPhotonSR_et_stack_1->GetXaxis()->SetLabelFont(42);
  ratio_goodPhotonSR_et_stack_1->GetXaxis()->SetTitleOffset(1);
  ratio_goodPhotonSR_et_stack_1->GetXaxis()->SetTitleFont(42);
  ratio_goodPhotonSR_et_stack_1->GetYaxis()->SetLabelFont(42);
  ratio_goodPhotonSR_et_stack_1->GetYaxis()->SetTitleFont(42);
  ratio_goodPhotonSR_et_stack_1->GetZaxis()->SetLabelFont(42);
  ratio_goodPhotonSR_et_stack_1->GetZaxis()->SetTitleOffset(1);
  ratio_goodPhotonSR_et_stack_1->GetZaxis()->SetTitleFont(42);
  ratio_stack_goodPhotonSR_et->Add(ratio_goodPhotonSR_et_stack_1, "");
  ratio_stack_goodPhotonSR_et->Draw("pe1");
  TLine *line = new TLine(2, 1, 8, 1);
  line->SetLineStyle(2);
  line->Draw();

  TH1D *ratio_uncertainty_goodPhotonSR_et__3 = new TH1D("ratio_uncertainty_goodPhotonSR_et__3", "goodPhotonSR_et", 5, 2, 8);
  ratio_uncertainty_goodPhotonSR_et__3->SetBinContent(1, 1);
  ratio_uncertainty_goodPhotonSR_et__3->SetBinContent(2, 1);
  ratio_uncertainty_goodPhotonSR_et__3->SetBinContent(3, 1);
  ratio_uncertainty_goodPhotonSR_et__3->SetBinContent(4, 1);
  ratio_uncertainty_goodPhotonSR_et__3->SetBinContent(5, 1);
  ratio_uncertainty_goodPhotonSR_et__3->SetBinContent(6, 1);
  ratio_uncertainty_goodPhotonSR_et__3->SetBinError(1, 0.3267822);
  ratio_uncertainty_goodPhotonSR_et__3->SetBinError(2, 0.3268426);
  ratio_uncertainty_goodPhotonSR_et__3->SetBinError(3, 0.3290164);
  ratio_uncertainty_goodPhotonSR_et__3->SetBinError(4, 0.3361095);
  ratio_uncertainty_goodPhotonSR_et__3->SetBinError(5, 0.3403619);
  ratio_uncertainty_goodPhotonSR_et__3->SetBinError(6, 0.08868224);
  ratio_uncertainty_goodPhotonSR_et__3->SetEntries(45.39839);

  ci = 1555;
  color = new TColor(ci, 0, 0, 0, " ", 0.3);
  ratio_uncertainty_goodPhotonSR_et__3->SetFillColorAlpha(ci, 0.5);
  ratio_uncertainty_goodPhotonSR_et__3->SetFillStyle(3004);
  ratio_uncertainty_goodPhotonSR_et__3->SetMarkerStyle(20);
  ratio_uncertainty_goodPhotonSR_et__3->SetMarkerSize(0);
  ratio_uncertainty_goodPhotonSR_et__3->GetXaxis()->SetRange(1, 5);
  ratio_uncertainty_goodPhotonSR_et__3->GetXaxis()->SetLabelFont(42);
  ratio_uncertainty_goodPhotonSR_et__3->GetXaxis()->SetTitleOffset(1);
  ratio_uncertainty_goodPhotonSR_et__3->GetXaxis()->SetTitleFont(42);
  ratio_uncertainty_goodPhotonSR_et__3->GetYaxis()->SetLabelFont(42);
  ratio_uncertainty_goodPhotonSR_et__3->GetYaxis()->SetTitleFont(42);
  ratio_uncertainty_goodPhotonSR_et__3->GetZaxis()->SetLabelFont(42);
  ratio_uncertainty_goodPhotonSR_et__3->GetZaxis()->SetTitleOffset(1);
  ratio_uncertainty_goodPhotonSR_et__3->GetZaxis()->SetTitleFont(42);
  ratio_uncertainty_goodPhotonSR_et__3->Draw("same e2");
  
  auto fake_ratio_graph = new TGraphAsymmErrors();
  fake_ratio_graph->SetPoint(0, 6.2, 1.9999999);
  fake_ratio_graph->SetPointError(0, 0, 0, 2-1.5185675177, 0);
  fake_ratio_graph->SetMarkerStyle(20);
  fake_ratio_graph->SetMarkerSize(0);
  fake_ratio_graph->SetLineColor(kBlack);
  fake_ratio_graph->Draw("same e");

  goodPhotonSR_et_2->Modified();
  goodPhotonSR_et->cd();

  // auto tex = new TLatex(0.16, 0.95, "#bf{CMS} #it{Preliminary}");
  auto tex = new TLatex(0.16, 0.95, "#bf{CMS}");
  tex->SetNDC();
  tex->SetTextFont(42);
  tex->SetTextSize(0.05);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(0.45, 0.95, "#scale[0.8]{PbPb, 1.65 nb^{-1} (#sqrt{s_{NN}} = 5.02 TeV)}");
  tex->SetNDC();
  tex->SetTextFont(42);
  tex->SetTextSize(0.05);
  tex->SetLineWidth(2);
  tex->Draw();

  goodPhotonSR_et->Modified();
  goodPhotonSR_et->cd();
  goodPhotonSR_et->SetSelected(goodPhotonSR_et);
  goodPhotonSR_et->SaveAs("figures/Figure_006_a.pdf");
}
