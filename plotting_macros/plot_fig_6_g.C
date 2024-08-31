#ifdef __CLING__
#pragma cling optimize(0)
#endif

#include "style.h"

void plot_fig_6_g() {
  gROOT->SetBatch(kTRUE);
  //=========Macro generated from canvas: eventSR3_cosThetaStar/eventSR3_cosThetaStar
  //=========  (Sun Mar 31 12:51:37 2024) by ROOT version 6.26/08
  TCanvas *eventSR3_cosThetaStar = new TCanvas("eventSR3_cosThetaStar", "eventSR3_cosThetaStar", 0, 0, 800, 600);
  gStyle->SetOptFit(1);
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  eventSR3_cosThetaStar->SetHighLightColor(2);
  eventSR3_cosThetaStar->Range(0, 0, 1, 1);
  eventSR3_cosThetaStar->SetFillColor(0);
  eventSR3_cosThetaStar->SetBorderMode(0);
  eventSR3_cosThetaStar->SetBorderSize(2);
  eventSR3_cosThetaStar->SetTickx(1);
  eventSR3_cosThetaStar->SetTicky(1);
  eventSR3_cosThetaStar->SetLeftMargin(0.16);
  eventSR3_cosThetaStar->SetRightMargin(0.15);
  eventSR3_cosThetaStar->SetTopMargin(0.06);
  eventSR3_cosThetaStar->SetBottomMargin(0.3);
  eventSR3_cosThetaStar->SetFrameFillStyle(0);
  eventSR3_cosThetaStar->SetFrameBorderMode(0);

  // ------------>Primitives in pad: eventSR3_cosThetaStar_1
  TPad *eventSR3_cosThetaStar_1 = new TPad("eventSR3_cosThetaStar_1", "eventSR3_cosThetaStar_1", 0, 0.3, 1, 1);
  eventSR3_cosThetaStar_1->Draw();
  eventSR3_cosThetaStar_1->cd();
  eventSR3_cosThetaStar_1->Range(-0.231884, 0, 1.217391, 27.47253);
  eventSR3_cosThetaStar_1->SetFillColor(0);
  eventSR3_cosThetaStar_1->SetBorderMode(0);
  eventSR3_cosThetaStar_1->SetBorderSize(2);
  eventSR3_cosThetaStar_1->SetLeftMargin(0.16);
  eventSR3_cosThetaStar_1->SetRightMargin(0.15);
  eventSR3_cosThetaStar_1->SetBottomMargin(0.05);
  eventSR3_cosThetaStar_1->SetFrameFillStyle(0);
  eventSR3_cosThetaStar_1->SetFrameBorderMode(0);
  eventSR3_cosThetaStar_1->SetFrameFillStyle(0);
  eventSR3_cosThetaStar_1->SetFrameLineWidth(2);
  eventSR3_cosThetaStar_1->SetFrameBorderMode(0);
  eventSR3_cosThetaStar_1->SetFrameBorderSize(2);

  THStack *eventSR3_cosThetaStarbackground = new THStack();
  eventSR3_cosThetaStarbackground->SetName("eventSR3_cosThetaStarbackground");
  eventSR3_cosThetaStarbackground->SetTitle("");
  eventSR3_cosThetaStarbackground->SetMaximum(25);

  TH1F *eventSR3_cosThetaStarbackground_stack_19 = new TH1F("eventSR3_cosThetaStarbackground_stack_19", "", 3, 0, 1);
  eventSR3_cosThetaStarbackground_stack_19->SetMinimum(0);
  eventSR3_cosThetaStarbackground_stack_19->SetMaximum(25);
  eventSR3_cosThetaStarbackground_stack_19->SetDirectory(0);
  eventSR3_cosThetaStarbackground_stack_19->SetStats(0);
  eventSR3_cosThetaStarbackground_stack_19->SetLineStyle(0);
  eventSR3_cosThetaStarbackground_stack_19->GetXaxis()->SetTitle("|cos #theta*|");
  eventSR3_cosThetaStarbackground_stack_19->GetXaxis()->SetLabelFont(42);
  eventSR3_cosThetaStarbackground_stack_19->GetXaxis()->SetLabelOffset(0.007);
  eventSR3_cosThetaStarbackground_stack_19->GetXaxis()->SetLabelSize(0.0);
  eventSR3_cosThetaStarbackground_stack_19->GetXaxis()->SetTitleSize(fig_6_x_title_size);
  eventSR3_cosThetaStarbackground_stack_19->GetXaxis()->SetTitleOffset(1.7);
  eventSR3_cosThetaStarbackground_stack_19->GetXaxis()->SetTitleFont(42);
  eventSR3_cosThetaStarbackground_stack_19->GetYaxis()->SetTitle("Events / 0.33");
  eventSR3_cosThetaStarbackground_stack_19->GetYaxis()->CenterTitle(true);
  eventSR3_cosThetaStarbackground_stack_19->GetYaxis()->SetNdivisions(505);
  eventSR3_cosThetaStarbackground_stack_19->GetYaxis()->SetLabelFont(42);
  eventSR3_cosThetaStarbackground_stack_19->GetYaxis()->SetLabelOffset(0.007);
  eventSR3_cosThetaStarbackground_stack_19->GetYaxis()->SetLabelSize(0.06);
  eventSR3_cosThetaStarbackground_stack_19->GetYaxis()->SetTitleSize(fig_6_y_title_size);
  eventSR3_cosThetaStarbackground_stack_19->GetYaxis()->SetTitleOffset(1.0);
  eventSR3_cosThetaStarbackground_stack_19->GetYaxis()->SetTitleFont(42);
  eventSR3_cosThetaStarbackground_stack_19->GetZaxis()->SetLabelFont(42);
  eventSR3_cosThetaStarbackground_stack_19->GetZaxis()->SetLabelOffset(0.007);
  eventSR3_cosThetaStarbackground_stack_19->GetZaxis()->SetLabelSize(0.05);
  eventSR3_cosThetaStarbackground_stack_19->GetZaxis()->SetTitleSize(0.06);
  eventSR3_cosThetaStarbackground_stack_19->GetZaxis()->SetTitleOffset(1);
  eventSR3_cosThetaStarbackground_stack_19->GetZaxis()->SetTitleFont(42);
  eventSR3_cosThetaStarbackground->SetHistogram(eventSR3_cosThetaStarbackground_stack_19);

  TH1D *eventSR3_cosThetaStar_stack_1 = new TH1D("eventSR3_cosThetaStar_stack_1", "eventSR3_cosThetaStar", 3, 0, 1);
  eventSR3_cosThetaStar_stack_1->SetBinContent(1, 5.86169);
  eventSR3_cosThetaStar_stack_1->SetBinContent(2, 3.627724);
  eventSR3_cosThetaStar_stack_1->SetBinContent(3, 0.6153292);
  eventSR3_cosThetaStar_stack_1->SetBinError(1, 0.1203554);
  eventSR3_cosThetaStar_stack_1->SetBinError(2, 0.09468283);
  eventSR3_cosThetaStar_stack_1->SetBinError(3, 0.0389949);
  eventSR3_cosThetaStar_stack_1->SetEntries(4089);
  eventSR3_cosThetaStar_stack_1->SetDirectory(0);

  Int_t ci;       // for color index setting
  TColor *color;  // for color definition with alpha
  ci = TColor::GetColor("#6699ff");
  eventSR3_cosThetaStar_stack_1->SetFillColor(ci);

  ci = TColor::GetColor("#000000");
  eventSR3_cosThetaStar_stack_1->SetLineColor(ci);
  eventSR3_cosThetaStar_stack_1->SetMarkerStyle(20);
  eventSR3_cosThetaStar_stack_1->GetXaxis()->SetRange(1, 3);
  eventSR3_cosThetaStar_stack_1->GetXaxis()->SetLabelFont(42);
  eventSR3_cosThetaStar_stack_1->GetXaxis()->SetTitleOffset(1);
  eventSR3_cosThetaStar_stack_1->GetXaxis()->SetTitleFont(42);
  eventSR3_cosThetaStar_stack_1->GetYaxis()->SetLabelFont(42);
  eventSR3_cosThetaStar_stack_1->GetYaxis()->SetTitleFont(42);
  eventSR3_cosThetaStar_stack_1->GetZaxis()->SetLabelFont(42);
  eventSR3_cosThetaStar_stack_1->GetZaxis()->SetTitleOffset(1);
  eventSR3_cosThetaStar_stack_1->GetZaxis()->SetTitleFont(42);
  eventSR3_cosThetaStarbackground->Add(eventSR3_cosThetaStar_stack_1, "");

  TH1D *eventSR3_cosThetaStar_stack_2 = new TH1D("eventSR3_cosThetaStar_stack_2", "eventSR3_cosThetaStar", 3, 0, 1);
  eventSR3_cosThetaStar_stack_2->SetBinContent(1, 0.1149937);
  eventSR3_cosThetaStar_stack_2->SetBinContent(2, 0.5174719);
  eventSR3_cosThetaStar_stack_2->SetBinContent(3, 0.1149937);
  eventSR3_cosThetaStar_stack_2->SetBinError(1, 0.08131286);
  eventSR3_cosThetaStar_stack_2->SetBinError(2, 0.1724906);
  eventSR3_cosThetaStar_stack_2->SetBinError(3, 0.08131286);
  eventSR3_cosThetaStar_stack_2->SetEntries(13);
  eventSR3_cosThetaStar_stack_2->SetDirectory(0);

  ci = TColor::GetColor("#ffff00");
  eventSR3_cosThetaStar_stack_2->SetFillColor(ci);

  ci = TColor::GetColor("#ffff00");
  eventSR3_cosThetaStar_stack_2->SetLineColor(ci);
  eventSR3_cosThetaStar_stack_2->SetMarkerStyle(20);
  eventSR3_cosThetaStar_stack_2->SetMarkerSize(0);
  eventSR3_cosThetaStar_stack_2->GetXaxis()->SetRange(1, 3);
  eventSR3_cosThetaStar_stack_2->GetXaxis()->SetLabelFont(42);
  eventSR3_cosThetaStar_stack_2->GetXaxis()->SetTitleOffset(1);
  eventSR3_cosThetaStar_stack_2->GetXaxis()->SetTitleFont(42);
  eventSR3_cosThetaStar_stack_2->GetYaxis()->SetLabelFont(42);
  eventSR3_cosThetaStar_stack_2->GetYaxis()->SetTitleFont(42);
  eventSR3_cosThetaStar_stack_2->GetZaxis()->SetLabelFont(42);
  eventSR3_cosThetaStar_stack_2->GetZaxis()->SetTitleOffset(1);
  eventSR3_cosThetaStar_stack_2->GetZaxis()->SetTitleFont(42);
  eventSR3_cosThetaStarbackground->Add(eventSR3_cosThetaStar_stack_2, "");

  TH1D *eventSR3_cosThetaStar_stack_3 = new TH1D("eventSR3_cosThetaStar_stack_3", "eventSR3_cosThetaStar", 3, 0, 1);
  eventSR3_cosThetaStar_stack_3->SetBinContent(1, 0.5774609);
  eventSR3_cosThetaStar_stack_3->SetBinContent(2, 0.2165479);
  eventSR3_cosThetaStar_stack_3->SetBinContent(3, 0.3609131);
  eventSR3_cosThetaStar_stack_3->SetBinError(1, 0.2041633);
  eventSR3_cosThetaStar_stack_3->SetBinError(2, 0.125024);
  eventSR3_cosThetaStar_stack_3->SetBinError(3, 0.1614052);
  eventSR3_cosThetaStar_stack_3->SetEntries(16);
  eventSR3_cosThetaStar_stack_3->SetDirectory(0);

  ci = TColor::GetColor("#ffff00");
  eventSR3_cosThetaStar_stack_3->SetFillColor(ci);

  ci = TColor::GetColor("#000000");
  eventSR3_cosThetaStar_stack_3->SetLineColor(ci);
  eventSR3_cosThetaStar_stack_3->SetMarkerStyle(20);
  eventSR3_cosThetaStar_stack_3->SetMarkerSize(0);
  eventSR3_cosThetaStar_stack_3->GetXaxis()->SetRange(1, 3);
  eventSR3_cosThetaStar_stack_3->GetXaxis()->SetLabelFont(42);
  eventSR3_cosThetaStar_stack_3->GetXaxis()->SetTitleOffset(1);
  eventSR3_cosThetaStar_stack_3->GetXaxis()->SetTitleFont(42);
  eventSR3_cosThetaStar_stack_3->GetYaxis()->SetLabelFont(42);
  eventSR3_cosThetaStar_stack_3->GetYaxis()->SetTitleFont(42);
  eventSR3_cosThetaStar_stack_3->GetZaxis()->SetLabelFont(42);
  eventSR3_cosThetaStar_stack_3->GetZaxis()->SetTitleOffset(1);
  eventSR3_cosThetaStar_stack_3->GetZaxis()->SetTitleFont(42);
  eventSR3_cosThetaStarbackground->Add(eventSR3_cosThetaStar_stack_3, "");

  TH1D *eventSR3_cosThetaStar_stack_4 = new TH1D("eventSR3_cosThetaStar_stack_4", "eventSR3_cosThetaStar", 3, 0, 1);
  eventSR3_cosThetaStar_stack_4->SetBinContent(1, 6.170612);
  eventSR3_cosThetaStar_stack_4->SetBinContent(2, 5.095986);
  eventSR3_cosThetaStar_stack_4->SetBinContent(3, 1.555379);
  eventSR3_cosThetaStar_stack_4->SetBinError(1, 0.1868168);
  eventSR3_cosThetaStar_stack_4->SetBinError(2, 0.1697719);
  eventSR3_cosThetaStar_stack_4->SetBinError(3, 0.09379287);
  eventSR3_cosThetaStar_stack_4->SetEntries(2267);
  eventSR3_cosThetaStar_stack_4->SetDirectory(0);

  ci = TColor::GetColor("#ff9933");
  eventSR3_cosThetaStar_stack_4->SetFillColor(ci);

  ci = TColor::GetColor("#000000");
  eventSR3_cosThetaStar_stack_4->SetLineColor(ci);
  eventSR3_cosThetaStar_stack_4->SetMarkerStyle(20);
  eventSR3_cosThetaStar_stack_4->GetXaxis()->SetRange(1, 3);
  eventSR3_cosThetaStar_stack_4->GetXaxis()->SetLabelFont(42);
  eventSR3_cosThetaStar_stack_4->GetXaxis()->SetTitleOffset(1);
  eventSR3_cosThetaStar_stack_4->GetXaxis()->SetTitleFont(42);
  eventSR3_cosThetaStar_stack_4->GetYaxis()->SetLabelFont(42);
  eventSR3_cosThetaStar_stack_4->GetYaxis()->SetTitleFont(42);
  eventSR3_cosThetaStar_stack_4->GetZaxis()->SetLabelFont(42);
  eventSR3_cosThetaStar_stack_4->GetZaxis()->SetTitleOffset(1);
  eventSR3_cosThetaStar_stack_4->GetZaxis()->SetTitleFont(42);
  eventSR3_cosThetaStarbackground->Add(eventSR3_cosThetaStar_stack_4, "");
  eventSR3_cosThetaStarbackground->Draw("hist");

  Double_t Graph0_fx3007[3] = {0.1666667, 0.5, 0.8333333};
  Double_t Graph0_fy3007[3] = {17, 6, 3};
  Double_t Graph0_felx3007[3] = {0.1666667, 0.1666667, 0.1666667};
  Double_t Graph0_fely3007[3] = {4.082184, 2.379931, 1.632705};
  Double_t Graph0_fehx3007[3] = {0.1666667, 0.1666667, 0.1666667};
  Double_t Graph0_fehy3007[3] = {5.203719, 3.583642, 2.918186};
  TGraphAsymmErrors *grae =
      new TGraphAsymmErrors(3, Graph0_fx3007, Graph0_fy3007, Graph0_felx3007, Graph0_fehx3007, Graph0_fely3007, Graph0_fehy3007);
  grae->SetName("Graph0");
  grae->SetTitle("Graph");
  grae->SetFillStyle(1000);
  grae->SetMarkerStyle(20);

  TH1F *Graph_Graph03007 = new TH1F("Graph_Graph03007", "Graph", 100, 0.1, 0.9);
  Graph_Graph03007->SetMinimum(1.230566);
  Graph_Graph03007->SetMaximum(24.28736);
  Graph_Graph03007->SetDirectory(0);
  Graph_Graph03007->SetStats(0);
  Graph_Graph03007->SetLineStyle(0);
  Graph_Graph03007->GetXaxis()->SetLabelFont(42);
  Graph_Graph03007->GetXaxis()->SetLabelOffset(0.007);
  Graph_Graph03007->GetXaxis()->SetLabelSize(0.05);
  Graph_Graph03007->GetXaxis()->SetTitleSize(0.06);
  Graph_Graph03007->GetXaxis()->SetTitleOffset(0.9);
  Graph_Graph03007->GetXaxis()->SetTitleFont(42);
  Graph_Graph03007->GetYaxis()->SetLabelFont(42);
  Graph_Graph03007->GetYaxis()->SetLabelOffset(0.007);
  Graph_Graph03007->GetYaxis()->SetLabelSize(0.05);
  Graph_Graph03007->GetYaxis()->SetTitleSize(0.06);
  Graph_Graph03007->GetYaxis()->SetTitleOffset(1.25);
  Graph_Graph03007->GetYaxis()->SetTitleFont(42);
  Graph_Graph03007->GetZaxis()->SetLabelFont(42);
  Graph_Graph03007->GetZaxis()->SetLabelOffset(0.007);
  Graph_Graph03007->GetZaxis()->SetLabelSize(0.05);
  Graph_Graph03007->GetZaxis()->SetTitleSize(0.06);
  Graph_Graph03007->GetZaxis()->SetTitleOffset(1);
  Graph_Graph03007->GetZaxis()->SetTitleFont(42);
  grae->SetHistogram(Graph_Graph03007);

  grae->Draw("pe");

  

  TH1D *backgrounds_unc_eventSR3_cosThetaStar__19 = new TH1D("backgrounds_unc_eventSR3_cosThetaStar__19", "eventSR3_cosThetaStar", 3, 0, 1);
  backgrounds_unc_eventSR3_cosThetaStar__19->SetBinContent(1, 12.72476);
  backgrounds_unc_eventSR3_cosThetaStar__19->SetBinContent(2, 9.45773);
  backgrounds_unc_eventSR3_cosThetaStar__19->SetBinContent(3, 2.646615);
  backgrounds_unc_eventSR3_cosThetaStar__19->SetBinError(1, 2.943335);
  backgrounds_unc_eventSR3_cosThetaStar__19->SetBinError(2, 2.194312);
  backgrounds_unc_eventSR3_cosThetaStar__19->SetBinError(3, 0.6430575);
  backgrounds_unc_eventSR3_cosThetaStar__19->SetEntries(6385);

  ci = 1561;
  color = new TColor(ci, 0, 0, 0, " ", 0.3);
  backgrounds_unc_eventSR3_cosThetaStar__19->SetFillColorAlpha(ci, 0.5);
  backgrounds_unc_eventSR3_cosThetaStar__19->SetFillStyle(3004);
  backgrounds_unc_eventSR3_cosThetaStar__19->SetMarkerStyle(20);
  backgrounds_unc_eventSR3_cosThetaStar__19->SetMarkerSize(0);
  backgrounds_unc_eventSR3_cosThetaStar__19->GetXaxis()->SetRange(1, 3);
  backgrounds_unc_eventSR3_cosThetaStar__19->GetXaxis()->SetLabelFont(42);
  backgrounds_unc_eventSR3_cosThetaStar__19->GetXaxis()->SetTitleOffset(1);
  backgrounds_unc_eventSR3_cosThetaStar__19->GetXaxis()->SetTitleFont(42);
  backgrounds_unc_eventSR3_cosThetaStar__19->GetYaxis()->SetLabelFont(42);
  backgrounds_unc_eventSR3_cosThetaStar__19->GetYaxis()->SetTitleFont(42);
  backgrounds_unc_eventSR3_cosThetaStar__19->GetZaxis()->SetLabelFont(42);
  backgrounds_unc_eventSR3_cosThetaStar__19->GetZaxis()->SetTitleOffset(1);
  backgrounds_unc_eventSR3_cosThetaStar__19->GetZaxis()->SetTitleFont(42);
  backgrounds_unc_eventSR3_cosThetaStar__19->Draw("same e2");

  auto leg = get_lbl_legend();
  // leg->Draw();

  TH1F *eventSR3_cosThetaStarbackground_copy__20 = new TH1F("eventSR3_cosThetaStarbackground_copy__20", "", 3, 0, 1);
  eventSR3_cosThetaStarbackground_copy__20->SetMinimum(0);
  eventSR3_cosThetaStarbackground_copy__20->SetMaximum(25);
  eventSR3_cosThetaStarbackground_copy__20->SetDirectory(0);
  eventSR3_cosThetaStarbackground_copy__20->SetStats(0);
  eventSR3_cosThetaStarbackground_copy__20->SetLineStyle(0);
  eventSR3_cosThetaStarbackground_copy__20->GetXaxis()->SetTitle("|cos #theta*|");
  eventSR3_cosThetaStarbackground_copy__20->GetXaxis()->SetLabelFont(42);
  eventSR3_cosThetaStarbackground_copy__20->GetXaxis()->SetLabelOffset(0.007);
  eventSR3_cosThetaStarbackground_copy__20->GetXaxis()->SetLabelSize(fig_6_x_label_size);
  eventSR3_cosThetaStarbackground_copy__20->GetXaxis()->SetTitleSize(0.06);
  eventSR3_cosThetaStarbackground_copy__20->GetXaxis()->SetTitleOffset(1.7);
  eventSR3_cosThetaStarbackground_copy__20->GetXaxis()->SetTitleFont(42);
  eventSR3_cosThetaStarbackground_copy__20->GetYaxis()->SetTitle("Events / 0.33");
  eventSR3_cosThetaStarbackground_copy__20->GetYaxis()->CenterTitle(true);
  eventSR3_cosThetaStarbackground_copy__20->GetYaxis()->SetNdivisions(505);
  eventSR3_cosThetaStarbackground_copy__20->GetYaxis()->SetLabelFont(42);
  eventSR3_cosThetaStarbackground_copy__20->GetYaxis()->SetLabelOffset(0.007);
  eventSR3_cosThetaStarbackground_copy__20->GetYaxis()->SetLabelSize(fig_6_y_label_size);
  eventSR3_cosThetaStarbackground_copy__20->GetYaxis()->SetTitleSize(0.05);
  eventSR3_cosThetaStarbackground_copy__20->GetYaxis()->SetTitleOffset(1.0);
  eventSR3_cosThetaStarbackground_copy__20->GetYaxis()->SetTitleFont(42);
  eventSR3_cosThetaStarbackground_copy__20->GetZaxis()->SetLabelFont(42);
  eventSR3_cosThetaStarbackground_copy__20->GetZaxis()->SetLabelOffset(0.007);
  eventSR3_cosThetaStarbackground_copy__20->GetZaxis()->SetLabelSize(0.05);
  eventSR3_cosThetaStarbackground_copy__20->GetZaxis()->SetTitleSize(0.06);
  eventSR3_cosThetaStarbackground_copy__20->GetZaxis()->SetTitleOffset(1);
  eventSR3_cosThetaStarbackground_copy__20->GetZaxis()->SetTitleFont(42);
  eventSR3_cosThetaStarbackground_copy__20->Draw("sameaxis");
  eventSR3_cosThetaStar_1->Modified();
  eventSR3_cosThetaStar->cd();

  // ------------>Primitives in pad: eventSR3_cosThetaStar_2
  TPad *eventSR3_cosThetaStar_2 = new TPad("eventSR3_cosThetaStar_2", "eventSR3_cosThetaStar_2", 0, 0, 1, 0.3);
  eventSR3_cosThetaStar_2->Draw();
  eventSR3_cosThetaStar_2->cd();
  eventSR3_cosThetaStar_2->Range(-0.231884, -0.8571429, 1.217391, 2);
  eventSR3_cosThetaStar_2->SetFillColor(0);
  eventSR3_cosThetaStar_2->SetBorderMode(0);
  eventSR3_cosThetaStar_2->SetBorderSize(2);
  eventSR3_cosThetaStar_2->SetLeftMargin(0.16);
  eventSR3_cosThetaStar_2->SetRightMargin(0.15);
  eventSR3_cosThetaStar_2->SetTopMargin(0.05);
  eventSR3_cosThetaStar_2->SetBottomMargin(fig_6_ratio_bottom_margin);
  eventSR3_cosThetaStar_2->SetFrameFillStyle(0);
  eventSR3_cosThetaStar_2->SetFrameBorderMode(0);
  eventSR3_cosThetaStar_2->SetFrameFillStyle(0);
  eventSR3_cosThetaStar_2->SetFrameBorderMode(0);

  auto ratio_stack_eventSR3_cosThetaStar = new THStack();
  ratio_stack_eventSR3_cosThetaStar->SetName("ratio_stack_eventSR3_cosThetaStar");
  ratio_stack_eventSR3_cosThetaStar->SetTitle("");
  ratio_stack_eventSR3_cosThetaStar->SetMinimum(0);
  ratio_stack_eventSR3_cosThetaStar->SetMaximum(2);

  TH1F *ratio_stack_eventSR3_cosThetaStar_stack_21 = new TH1F("ratio_stack_eventSR3_cosThetaStar_stack_21", "", 3, 0, 1);
  ratio_stack_eventSR3_cosThetaStar_stack_21->SetMinimum(0);
  ratio_stack_eventSR3_cosThetaStar_stack_21->SetMaximum(2);
  ratio_stack_eventSR3_cosThetaStar_stack_21->SetDirectory(0);
  ratio_stack_eventSR3_cosThetaStar_stack_21->SetStats(0);
  ratio_stack_eventSR3_cosThetaStar_stack_21->SetLineStyle(0);
  ratio_stack_eventSR3_cosThetaStar_stack_21->GetXaxis()->SetTitle("|cos #theta*|");
  ratio_stack_eventSR3_cosThetaStar_stack_21->GetXaxis()->SetLabelFont(42);
  ratio_stack_eventSR3_cosThetaStar_stack_21->GetXaxis()->SetLabelOffset(0.007);
  ratio_stack_eventSR3_cosThetaStar_stack_21->GetXaxis()->SetLabelSize(fig_6_x_ratio_label_size);
  ratio_stack_eventSR3_cosThetaStar_stack_21->GetXaxis()->SetTitleSize(fig_6_x_ratio_title_size);
  ratio_stack_eventSR3_cosThetaStar_stack_21->GetXaxis()->SetTitleOffset(1);
  ratio_stack_eventSR3_cosThetaStar_stack_21->GetXaxis()->SetTitleFont(42);
  ratio_stack_eventSR3_cosThetaStar_stack_21->GetYaxis()->SetTitle("Data/MC");
  ratio_stack_eventSR3_cosThetaStar_stack_21->GetYaxis()->CenterTitle();
  ratio_stack_eventSR3_cosThetaStar_stack_21->GetYaxis()->CenterTitle(true);
  ratio_stack_eventSR3_cosThetaStar_stack_21->GetYaxis()->SetNdivisions(505);
  ratio_stack_eventSR3_cosThetaStar_stack_21->GetYaxis()->SetLabelFont(42);
  ratio_stack_eventSR3_cosThetaStar_stack_21->GetYaxis()->SetLabelOffset(0.007);
  ratio_stack_eventSR3_cosThetaStar_stack_21->GetYaxis()->SetLabelSize(fig_6_y_ratio_label_size);
  ratio_stack_eventSR3_cosThetaStar_stack_21->GetYaxis()->SetTitleSize(fig_6_y_ratio_title_size);
  ratio_stack_eventSR3_cosThetaStar_stack_21->GetYaxis()->SetTitleOffset(0.5);
  ratio_stack_eventSR3_cosThetaStar_stack_21->GetYaxis()->SetTitleFont(42);
  ratio_stack_eventSR3_cosThetaStar_stack_21->GetZaxis()->SetLabelFont(42);
  ratio_stack_eventSR3_cosThetaStar_stack_21->GetZaxis()->SetLabelOffset(0.007);
  ratio_stack_eventSR3_cosThetaStar_stack_21->GetZaxis()->SetLabelSize(0.05);
  ratio_stack_eventSR3_cosThetaStar_stack_21->GetZaxis()->SetTitleSize(0.06);
  ratio_stack_eventSR3_cosThetaStar_stack_21->GetZaxis()->SetTitleOffset(1);
  ratio_stack_eventSR3_cosThetaStar_stack_21->GetZaxis()->SetTitleFont(42);
  ratio_stack_eventSR3_cosThetaStar->SetHistogram(ratio_stack_eventSR3_cosThetaStar_stack_21);

  TH1D *ratio_eventSR3_cosThetaStar_stack_1 = new TH1D("ratio_eventSR3_cosThetaStar_stack_1", "eventSR3_cosThetaStar", 3, 0, 1);
  ratio_eventSR3_cosThetaStar_stack_1->SetBinContent(1, 1.335978);
  ratio_eventSR3_cosThetaStar_stack_1->SetBinContent(2, 0.6344017);
  ratio_eventSR3_cosThetaStar_stack_1->SetBinContent(3, 1.133523);
  ratio_eventSR3_cosThetaStar_stack_1->SetBinError(1, 0.3256796);
  ratio_eventSR3_cosThetaStar_stack_1->SetBinError(2, 0.2597149);
  ratio_eventSR3_cosThetaStar_stack_1->SetBinError(3, 0.6604362);
  ratio_eventSR3_cosThetaStar_stack_1->SetEntries(15.8017);

  ci = 1494;
  color = new TColor(ci, 0, 1, 0, " ", 0);
  ratio_eventSR3_cosThetaStar_stack_1->SetFillColor(ci);

  ci = TColor::GetColor("#000000");
  ratio_eventSR3_cosThetaStar_stack_1->SetLineColor(ci);
  ratio_eventSR3_cosThetaStar_stack_1->SetMarkerStyle(20);
  ratio_eventSR3_cosThetaStar_stack_1->GetXaxis()->SetRange(1, 3);
  ratio_eventSR3_cosThetaStar_stack_1->GetXaxis()->SetLabelFont(42);
  ratio_eventSR3_cosThetaStar_stack_1->GetXaxis()->SetTitleOffset(1);
  ratio_eventSR3_cosThetaStar_stack_1->GetXaxis()->SetTitleFont(42);
  ratio_eventSR3_cosThetaStar_stack_1->GetYaxis()->SetLabelFont(42);
  ratio_eventSR3_cosThetaStar_stack_1->GetYaxis()->SetTitleFont(42);
  ratio_eventSR3_cosThetaStar_stack_1->GetZaxis()->SetLabelFont(42);
  ratio_eventSR3_cosThetaStar_stack_1->GetZaxis()->SetTitleOffset(1);
  ratio_eventSR3_cosThetaStar_stack_1->GetZaxis()->SetTitleFont(42);
  ratio_stack_eventSR3_cosThetaStar->Add(ratio_eventSR3_cosThetaStar_stack_1, "");
  ratio_stack_eventSR3_cosThetaStar->Draw("pe1");
  TLine *line = new TLine(0, 1, 1, 1);
  line->SetLineStyle(2);
  line->Draw();

  TH1D *ratio_uncertainty_eventSR3_cosThetaStar__21 =
      new TH1D("ratio_uncertainty_eventSR3_cosThetaStar__21", "eventSR3_cosThetaStar", 3, 0, 1);
  ratio_uncertainty_eventSR3_cosThetaStar__21->SetBinContent(1, 1);
  ratio_uncertainty_eventSR3_cosThetaStar__21->SetBinContent(2, 1);
  ratio_uncertainty_eventSR3_cosThetaStar__21->SetBinContent(3, 1);
  ratio_uncertainty_eventSR3_cosThetaStar__21->SetBinError(1, 0.3271185);
  ratio_uncertainty_eventSR3_cosThetaStar__21->SetBinError(2, 0.3281153);
  ratio_uncertainty_eventSR3_cosThetaStar__21->SetBinError(3, 0.3436165);
  ratio_uncertainty_eventSR3_cosThetaStar__21->SetEntries(27.04827);

  ci = 1561;
  color = new TColor(ci, 0, 0, 0, " ", 0.3);
  ratio_uncertainty_eventSR3_cosThetaStar__21->SetFillColorAlpha(ci, 0.5);
  ratio_uncertainty_eventSR3_cosThetaStar__21->SetFillStyle(3004);
  ratio_uncertainty_eventSR3_cosThetaStar__21->SetMarkerStyle(20);
  ratio_uncertainty_eventSR3_cosThetaStar__21->SetMarkerSize(0);
  ratio_uncertainty_eventSR3_cosThetaStar__21->GetXaxis()->SetRange(1, 3);
  ratio_uncertainty_eventSR3_cosThetaStar__21->GetXaxis()->SetLabelFont(42);
  ratio_uncertainty_eventSR3_cosThetaStar__21->GetXaxis()->SetTitleOffset(1);
  ratio_uncertainty_eventSR3_cosThetaStar__21->GetXaxis()->SetTitleFont(42);
  ratio_uncertainty_eventSR3_cosThetaStar__21->GetYaxis()->SetLabelFont(42);
  ratio_uncertainty_eventSR3_cosThetaStar__21->GetYaxis()->SetTitleFont(42);
  ratio_uncertainty_eventSR3_cosThetaStar__21->GetZaxis()->SetLabelFont(42);
  ratio_uncertainty_eventSR3_cosThetaStar__21->GetZaxis()->SetTitleOffset(1);
  ratio_uncertainty_eventSR3_cosThetaStar__21->GetZaxis()->SetTitleFont(42);
  ratio_uncertainty_eventSR3_cosThetaStar__21->Draw("same e2");
  eventSR3_cosThetaStar_2->Modified();
  eventSR3_cosThetaStar->cd();
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
  eventSR3_cosThetaStar->Modified();
  eventSR3_cosThetaStar->cd();
  eventSR3_cosThetaStar->SetSelected(eventSR3_cosThetaStar);
  eventSR3_cosThetaStar->SaveAs("figures/Figure_006_g.pdf");
}
