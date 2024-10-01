#ifdef __CLING__
#pragma cling optimize(0)
#endif

#include "style.h"

void plot_fig_6_d() {
  gROOT->SetBatch(kTRUE);
  //=========Macro generated from canvas: diphotonSR_rapidity/diphotonSR_rapidity
  //=========  (Sun Mar 31 12:51:37 2024) by ROOT version 6.26/08
  TCanvas *diphotonSR_rapidity = new TCanvas("diphotonSR_rapidity", "diphotonSR_rapidity", 0, 0, 800, 600);
  gStyle->SetOptFit(1);
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  diphotonSR_rapidity->SetHighLightColor(2);
  diphotonSR_rapidity->Range(0, 0, 1, 1);
  diphotonSR_rapidity->SetFillColor(0);
  diphotonSR_rapidity->SetBorderMode(0);
  diphotonSR_rapidity->SetBorderSize(2);
  diphotonSR_rapidity->SetTickx(1);
  diphotonSR_rapidity->SetTicky(1);
  diphotonSR_rapidity->SetLeftMargin(0.16);
  diphotonSR_rapidity->SetRightMargin(0.15);
  diphotonSR_rapidity->SetTopMargin(0.06);
  diphotonSR_rapidity->SetBottomMargin(0.3);
  diphotonSR_rapidity->SetFrameFillStyle(0);
  diphotonSR_rapidity->SetFrameBorderMode(0);

  // ------------>Primitives in pad: diphotonSR_rapidity_1
  TPad *diphotonSR_rapidity_1 = new TPad("diphotonSR_rapidity_1", "diphotonSR_rapidity_1", 0, 0.3, 1, 1);
  diphotonSR_rapidity_1->Draw();
  diphotonSR_rapidity_1->cd();
  diphotonSR_rapidity_1->Range(-3.22029, 0, 3.156522, 16.48352);
  diphotonSR_rapidity_1->SetFillColor(0);
  diphotonSR_rapidity_1->SetBorderMode(0);
  diphotonSR_rapidity_1->SetBorderSize(2);
  diphotonSR_rapidity_1->SetLeftMargin(0.16);
  diphotonSR_rapidity_1->SetRightMargin(0.15);
  diphotonSR_rapidity_1->SetBottomMargin(0.05);
  diphotonSR_rapidity_1->SetFrameFillStyle(0);
  diphotonSR_rapidity_1->SetFrameBorderMode(0);
  diphotonSR_rapidity_1->SetFrameFillStyle(0);
  diphotonSR_rapidity_1->SetFrameLineWidth(2);
  diphotonSR_rapidity_1->SetFrameBorderMode(0);
  diphotonSR_rapidity_1->SetFrameBorderSize(2);

  THStack *diphotonSR_rapiditybackground = new THStack();
  diphotonSR_rapiditybackground->SetName("diphotonSR_rapiditybackground");
  diphotonSR_rapiditybackground->SetTitle("");
  diphotonSR_rapiditybackground->SetMaximum(17);

  TH1F *diphotonSR_rapiditybackground_stack_13 = new TH1F("diphotonSR_rapiditybackground_stack_13", "", 7, -2.2, 2.2);
  diphotonSR_rapiditybackground_stack_13->SetMinimum(0);
  diphotonSR_rapiditybackground_stack_13->SetMaximum(17);
  diphotonSR_rapiditybackground_stack_13->SetDirectory(0);
  diphotonSR_rapiditybackground_stack_13->SetStats(0);
  diphotonSR_rapiditybackground_stack_13->SetLineStyle(0);
  diphotonSR_rapiditybackground_stack_13->GetXaxis()->SetTitle("y^{#gamma#gamma}");
  diphotonSR_rapiditybackground_stack_13->GetXaxis()->SetLabelFont(42);
  diphotonSR_rapiditybackground_stack_13->GetXaxis()->SetLabelOffset(0.007);
  diphotonSR_rapiditybackground_stack_13->GetXaxis()->SetLabelSize(0.0);
  diphotonSR_rapiditybackground_stack_13->GetXaxis()->SetTitleSize(fig_6_x_title_size);
  diphotonSR_rapiditybackground_stack_13->GetXaxis()->SetTitleOffset(1.7);
  diphotonSR_rapiditybackground_stack_13->GetXaxis()->SetTitleFont(42);
  diphotonSR_rapiditybackground_stack_13->GetYaxis()->SetTitle("Events / 0.63");
  diphotonSR_rapiditybackground_stack_13->GetYaxis()->CenterTitle(true);
  diphotonSR_rapiditybackground_stack_13->GetYaxis()->SetNdivisions(505);
  diphotonSR_rapiditybackground_stack_13->GetYaxis()->SetLabelFont(42);
  diphotonSR_rapiditybackground_stack_13->GetYaxis()->SetLabelOffset(0.007);
  diphotonSR_rapiditybackground_stack_13->GetYaxis()->SetLabelSize(0.06);
  diphotonSR_rapiditybackground_stack_13->GetYaxis()->SetTitleSize(fig_6_y_title_size);
  diphotonSR_rapiditybackground_stack_13->GetYaxis()->SetTitleOffset(1.0);
  
  diphotonSR_rapiditybackground_stack_13->GetYaxis()->SetTitleFont(42);
  diphotonSR_rapiditybackground_stack_13->GetZaxis()->SetLabelFont(42);
  diphotonSR_rapiditybackground_stack_13->GetZaxis()->SetLabelOffset(0.007);
  diphotonSR_rapiditybackground_stack_13->GetZaxis()->SetLabelSize(0.05);
  diphotonSR_rapiditybackground_stack_13->GetZaxis()->SetTitleSize(0.06);
  diphotonSR_rapiditybackground_stack_13->GetZaxis()->SetTitleOffset(1);
  diphotonSR_rapiditybackground_stack_13->GetZaxis()->SetTitleFont(42);
  diphotonSR_rapiditybackground->SetHistogram(diphotonSR_rapiditybackground_stack_13);

  // CEP
  TH1D *diphotonSR_rapidity_stack_1 = new TH1D("diphotonSR_rapidity_stack_1", "diphotonSR_rapidity", 7, -2.2, 2.2);
  diphotonSR_rapidity_stack_1->SetBinContent(1, 0.2668898);
  diphotonSR_rapidity_stack_1->SetBinContent(2, 0.9514126);
  diphotonSR_rapidity_stack_1->SetBinContent(3, 2.233966);
  diphotonSR_rapidity_stack_1->SetBinContent(4, 3.091473);
  diphotonSR_rapidity_stack_1->SetBinContent(5, 2.229024);
  diphotonSR_rapidity_stack_1->SetBinContent(6, 0.9958943);
  diphotonSR_rapidity_stack_1->SetBinContent(7, 0.3360834);
  diphotonSR_rapidity_stack_1->SetBinError(1, 0.02568148);
  diphotonSR_rapidity_stack_1->SetBinError(2, 0.04848848);
  diphotonSR_rapidity_stack_1->SetBinError(3, 0.07430061);
  diphotonSR_rapidity_stack_1->SetBinError(4, 0.08740511);
  diphotonSR_rapidity_stack_1->SetBinError(5, 0.07421838);
  diphotonSR_rapidity_stack_1->SetBinError(6, 0.04960903);
  diphotonSR_rapidity_stack_1->SetBinError(7, 0.02881892);
  diphotonSR_rapidity_stack_1->SetEntries(4089);
  diphotonSR_rapidity_stack_1->SetDirectory(0);

  Int_t ci;       // for color index setting
  TColor *color;  // for color definition with alpha
  ci = TColor::GetColor("#6699ff");
  diphotonSR_rapidity_stack_1->SetFillColor(ci);

  ci = TColor::GetColor("#000000");
  diphotonSR_rapidity_stack_1->SetLineColor(ci);
  diphotonSR_rapidity_stack_1->SetMarkerStyle(20);
  diphotonSR_rapidity_stack_1->GetXaxis()->SetRange(1, 7);
  diphotonSR_rapidity_stack_1->GetXaxis()->SetLabelFont(42);
  diphotonSR_rapidity_stack_1->GetXaxis()->SetTitleOffset(1);
  diphotonSR_rapidity_stack_1->GetXaxis()->SetTitleFont(42);
  diphotonSR_rapidity_stack_1->GetYaxis()->SetLabelFont(42);
  diphotonSR_rapidity_stack_1->GetYaxis()->SetTitleFont(42);
  diphotonSR_rapidity_stack_1->GetZaxis()->SetLabelFont(42);
  diphotonSR_rapidity_stack_1->GetZaxis()->SetTitleOffset(1);
  diphotonSR_rapidity_stack_1->GetZaxis()->SetTitleFont(42);
  diphotonSR_rapiditybackground->Add(diphotonSR_rapidity_stack_1, "");

  // QCD 1
  TH1D *diphotonSR_rapidity_stack_2 = new TH1D("diphotonSR_rapidity_stack_2", "diphotonSR_rapidity", 7, -2.2, 2.2);
  diphotonSR_rapidity_stack_2->SetBinContent(1, 0.05749687);
  diphotonSR_rapidity_stack_2->SetBinContent(2, 0.1149937);
  diphotonSR_rapidity_stack_2->SetBinContent(3, 0.1724906);
  diphotonSR_rapidity_stack_2->SetBinContent(4, 0.1724906);
  diphotonSR_rapidity_stack_2->SetBinContent(5, 0.05749687);
  diphotonSR_rapidity_stack_2->SetBinContent(6, 0.1724906);
  diphotonSR_rapidity_stack_2->SetBinError(1, 0.05749687);
  diphotonSR_rapidity_stack_2->SetBinError(2, 0.08131286);
  diphotonSR_rapidity_stack_2->SetBinError(3, 0.09958751);
  diphotonSR_rapidity_stack_2->SetBinError(4, 0.09958751);
  diphotonSR_rapidity_stack_2->SetBinError(5, 0.05749687);
  diphotonSR_rapidity_stack_2->SetBinError(6, 0.09958751);
  diphotonSR_rapidity_stack_2->SetEntries(13);
  diphotonSR_rapidity_stack_2->SetDirectory(0);

  ci = TColor::GetColor("#ffff00");
  diphotonSR_rapidity_stack_2->SetFillColor(ci);

  ci = TColor::GetColor("#ffff00");
  diphotonSR_rapidity_stack_2->SetLineColor(ci);
  diphotonSR_rapidity_stack_2->SetMarkerStyle(20);
  diphotonSR_rapidity_stack_2->SetMarkerSize(0);
  diphotonSR_rapidity_stack_2->GetXaxis()->SetRange(1, 7);
  diphotonSR_rapidity_stack_2->GetXaxis()->SetLabelFont(42);
  diphotonSR_rapidity_stack_2->GetXaxis()->SetTitleOffset(1);
  diphotonSR_rapidity_stack_2->GetXaxis()->SetTitleFont(42);
  diphotonSR_rapidity_stack_2->GetYaxis()->SetLabelFont(42);
  diphotonSR_rapidity_stack_2->GetYaxis()->SetTitleFont(42);
  diphotonSR_rapidity_stack_2->GetZaxis()->SetLabelFont(42);
  diphotonSR_rapidity_stack_2->GetZaxis()->SetTitleOffset(1);
  diphotonSR_rapidity_stack_2->GetZaxis()->SetTitleFont(42);
  diphotonSR_rapiditybackground->Add(diphotonSR_rapidity_stack_2, "");

  // QED 2
  TH1D *diphotonSR_rapidity_stack_3 = new TH1D("diphotonSR_rapidity_stack_3", "diphotonSR_rapidity", 7, -2.2, 2.2);
  diphotonSR_rapidity_stack_3->SetBinContent(1, 0.07218262);
  diphotonSR_rapidity_stack_3->SetBinContent(2, 0.07218262);
  diphotonSR_rapidity_stack_3->SetBinContent(3, 0.2165479);
  diphotonSR_rapidity_stack_3->SetBinContent(4, 0.2165479);
  diphotonSR_rapidity_stack_3->SetBinContent(5, 0.2165479);
  diphotonSR_rapidity_stack_3->SetBinContent(6, 0.2887305);
  diphotonSR_rapidity_stack_3->SetBinContent(7, 0.07218262);
  diphotonSR_rapidity_stack_3->SetBinError(1, 0.07218262);
  diphotonSR_rapidity_stack_3->SetBinError(2, 0.07218262);
  diphotonSR_rapidity_stack_3->SetBinError(3, 0.125024);
  diphotonSR_rapidity_stack_3->SetBinError(4, 0.125024);
  diphotonSR_rapidity_stack_3->SetBinError(5, 0.125024);
  diphotonSR_rapidity_stack_3->SetBinError(6, 0.1443652);
  diphotonSR_rapidity_stack_3->SetBinError(7, 0.07218262);
  diphotonSR_rapidity_stack_3->SetEntries(16);
  diphotonSR_rapidity_stack_3->SetDirectory(0);

  ci = TColor::GetColor("#ffff00");
  diphotonSR_rapidity_stack_3->SetFillColor(ci);

  ci = TColor::GetColor("#000000");
  diphotonSR_rapidity_stack_3->SetLineColor(ci);
  diphotonSR_rapidity_stack_3->SetMarkerStyle(20);
  diphotonSR_rapidity_stack_3->SetMarkerSize(0);
  diphotonSR_rapidity_stack_3->GetXaxis()->SetRange(1, 7);
  diphotonSR_rapidity_stack_3->GetXaxis()->SetLabelFont(42);
  diphotonSR_rapidity_stack_3->GetXaxis()->SetTitleOffset(1);
  diphotonSR_rapidity_stack_3->GetXaxis()->SetTitleFont(42);
  diphotonSR_rapidity_stack_3->GetYaxis()->SetLabelFont(42);
  diphotonSR_rapidity_stack_3->GetYaxis()->SetTitleFont(42);
  diphotonSR_rapidity_stack_3->GetZaxis()->SetLabelFont(42);
  diphotonSR_rapidity_stack_3->GetZaxis()->SetTitleOffset(1);
  diphotonSR_rapidity_stack_3->GetZaxis()->SetTitleFont(42);
  diphotonSR_rapiditybackground->Add(diphotonSR_rapidity_stack_3, "");

  // LbL
  TH1D *diphotonSR_rapidity_stack_4 = new TH1D("diphotonSR_rapidity_stack_4", "diphotonSR_rapidity", 7, -2.2, 2.2);
  diphotonSR_rapidity_stack_4->SetBinContent(1, 0.1583658);
  diphotonSR_rapidity_stack_4->SetBinContent(2, 1.114217);
  diphotonSR_rapidity_stack_4->SetBinContent(3, 2.991983);
  diphotonSR_rapidity_stack_4->SetBinContent(4, 4.07792);
  diphotonSR_rapidity_stack_4->SetBinContent(5, 3.025919);
  diphotonSR_rapidity_stack_4->SetBinContent(6, 1.159464);
  diphotonSR_rapidity_stack_4->SetBinContent(7, 0.294108);
  diphotonSR_rapidity_stack_4->SetBinError(1, 0.02992833);
  diphotonSR_rapidity_stack_4->SetBinError(2, 0.07938466);
  diphotonSR_rapidity_stack_4->SetBinError(3, 0.1300862);
  diphotonSR_rapidity_stack_4->SetBinError(4, 0.1518697);
  diphotonSR_rapidity_stack_4->SetBinError(5, 0.1308219);
  diphotonSR_rapidity_stack_4->SetBinError(6, 0.08098049);
  diphotonSR_rapidity_stack_4->SetBinError(7, 0.04078544);
  diphotonSR_rapidity_stack_4->SetEntries(2267);
  diphotonSR_rapidity_stack_4->SetDirectory(0);

  ci = TColor::GetColor("#ff9933");
  diphotonSR_rapidity_stack_4->SetFillColor(ci);

  ci = TColor::GetColor("#000000");
  diphotonSR_rapidity_stack_4->SetLineColor(ci);
  diphotonSR_rapidity_stack_4->SetMarkerStyle(20);
  diphotonSR_rapidity_stack_4->GetXaxis()->SetRange(1, 7);
  diphotonSR_rapidity_stack_4->GetXaxis()->SetLabelFont(42);
  diphotonSR_rapidity_stack_4->GetXaxis()->SetTitleOffset(1);
  diphotonSR_rapidity_stack_4->GetXaxis()->SetTitleFont(42);
  diphotonSR_rapidity_stack_4->GetYaxis()->SetLabelFont(42);
  diphotonSR_rapidity_stack_4->GetYaxis()->SetTitleFont(42);
  diphotonSR_rapidity_stack_4->GetZaxis()->SetLabelFont(42);
  diphotonSR_rapidity_stack_4->GetZaxis()->SetTitleOffset(1);
  diphotonSR_rapidity_stack_4->GetZaxis()->SetTitleFont(42);
  diphotonSR_rapiditybackground->Add(diphotonSR_rapidity_stack_4, "");
  diphotonSR_rapiditybackground->Draw("hist");

  Double_t Graph0_fx3005[7] = {-1.885714, -1.257143, -0.6285714, -2.775558e-16, 0.6285714, 1.257143, 1.885714};
  Double_t Graph0_fy3005[7] = {0, 5, 5, 8, 5, 2, 1};
  Double_t Graph0_felx3005[7] = {0.3142857, 0.3142857, 0.3142857, 0.3142857, 0.3142857, 0.3142857, 0.3142857};
  Double_t Graph0_fely3005[7] = {0, 2.159691, 2.159691, 2.768386, 2.159691, 1.291815, 0.8272462};
  Double_t Graph0_fehx3005[7] = {0.3142857, 0.3142857, 0.3142857, 0.3142857, 0.3142857, 0.3142857, 0.3142857};
  Double_t Graph0_fehy3005[7] = {1.841022, 3.382473, 3.382473, 3.945142, 3.382473, 2.63786, 2.299527};
  TGraphAsymmErrors *grae =
      new TGraphAsymmErrors(7, Graph0_fx3005, Graph0_fy3005, Graph0_felx3005, Graph0_fehx3005, Graph0_fely3005, Graph0_fehy3005);
  grae->SetName("Graph0");
  grae->SetTitle("Graph");
  grae->SetFillStyle(1000);
  grae->SetMarkerStyle(20);

  TH1F *Graph_Graph03005 = new TH1F("Graph_Graph03005", "Graph", 100, -2.262857, 2.262857);
  Graph_Graph03005->SetMinimum(0);
  Graph_Graph03005->SetMaximum(13.13966);
  Graph_Graph03005->SetDirectory(0);
  Graph_Graph03005->SetStats(0);
  Graph_Graph03005->SetLineStyle(0);
  Graph_Graph03005->GetXaxis()->SetLabelFont(42);
  Graph_Graph03005->GetXaxis()->SetLabelOffset(0.007);
  Graph_Graph03005->GetXaxis()->SetLabelSize(0.05);
  Graph_Graph03005->GetXaxis()->SetTitleSize(0.06);
  Graph_Graph03005->GetXaxis()->SetTitleOffset(0.9);
  Graph_Graph03005->GetXaxis()->SetTitleFont(42);
  Graph_Graph03005->GetYaxis()->SetLabelFont(42);
  Graph_Graph03005->GetYaxis()->SetLabelOffset(0.007);
  Graph_Graph03005->GetYaxis()->SetLabelSize(0.05);
  Graph_Graph03005->GetYaxis()->SetTitleSize(0.06);
  Graph_Graph03005->GetYaxis()->SetTitleOffset(1.25);
  Graph_Graph03005->GetYaxis()->SetTitleFont(42);
  Graph_Graph03005->GetZaxis()->SetLabelFont(42);
  Graph_Graph03005->GetZaxis()->SetLabelOffset(0.007);
  Graph_Graph03005->GetZaxis()->SetLabelSize(0.05);
  Graph_Graph03005->GetZaxis()->SetTitleSize(0.06);
  Graph_Graph03005->GetZaxis()->SetTitleOffset(1);
  Graph_Graph03005->GetZaxis()->SetTitleFont(42);
  grae->SetHistogram(Graph_Graph03005);

  grae->Draw("pe");

  

  TH1D *backgrounds_unc_diphotonSR_rapidity__13 = new TH1D("backgrounds_unc_diphotonSR_rapidity__13", "diphotonSR_rapidity", 7, -2.2, 2.2);
  backgrounds_unc_diphotonSR_rapidity__13->SetBinContent(1, 0.5549351);
  backgrounds_unc_diphotonSR_rapidity__13->SetBinContent(2, 2.252806);
  backgrounds_unc_diphotonSR_rapidity__13->SetBinContent(3, 5.614988);
  backgrounds_unc_diphotonSR_rapidity__13->SetBinContent(4, 7.558432);
  backgrounds_unc_diphotonSR_rapidity__13->SetBinContent(5, 5.528987);
  backgrounds_unc_diphotonSR_rapidity__13->SetBinContent(6, 2.61658);
  backgrounds_unc_diphotonSR_rapidity__13->SetBinContent(7, 0.702374);
  backgrounds_unc_diphotonSR_rapidity__13->SetBinError(1, 0.1623643);
  backgrounds_unc_diphotonSR_rapidity__13->SetBinError(2, 0.5375405);
  backgrounds_unc_diphotonSR_rapidity__13->SetBinError(3, 1.309896);
  backgrounds_unc_diphotonSR_rapidity__13->SetBinError(4, 1.754544);
  backgrounds_unc_diphotonSR_rapidity__13->SetBinError(5, 1.287904);
  backgrounds_unc_diphotonSR_rapidity__13->SetBinError(6, 0.6340009);
  backgrounds_unc_diphotonSR_rapidity__13->SetBinError(7, 0.1838517);
  backgrounds_unc_diphotonSR_rapidity__13->SetEntries(6385);

  ci = 1559;
  color = new TColor(ci, 0, 0, 0, " ", 0.3);
  backgrounds_unc_diphotonSR_rapidity__13->SetFillColorAlpha(ci, 0.5);
  backgrounds_unc_diphotonSR_rapidity__13->SetFillStyle(3004);
  backgrounds_unc_diphotonSR_rapidity__13->SetMarkerStyle(20);
  backgrounds_unc_diphotonSR_rapidity__13->SetMarkerSize(0);
  backgrounds_unc_diphotonSR_rapidity__13->GetXaxis()->SetRange(1, 7);
  backgrounds_unc_diphotonSR_rapidity__13->GetXaxis()->SetLabelFont(42);
  backgrounds_unc_diphotonSR_rapidity__13->GetXaxis()->SetTitleOffset(1);
  backgrounds_unc_diphotonSR_rapidity__13->GetXaxis()->SetTitleFont(42);
  backgrounds_unc_diphotonSR_rapidity__13->GetYaxis()->SetLabelFont(42);
  backgrounds_unc_diphotonSR_rapidity__13->GetYaxis()->SetTitleFont(42);
  backgrounds_unc_diphotonSR_rapidity__13->GetZaxis()->SetLabelFont(42);
  backgrounds_unc_diphotonSR_rapidity__13->GetZaxis()->SetTitleOffset(1);
  backgrounds_unc_diphotonSR_rapidity__13->GetZaxis()->SetTitleFont(42);
  backgrounds_unc_diphotonSR_rapidity__13->Draw("same e2");

  auto leg = get_lbl_legend();
  // leg->Draw();

  TH1F *diphotonSR_rapiditybackground_copy__14 = new TH1F("diphotonSR_rapiditybackground_copy__14", "", 7, -2.2, 2.2);
  diphotonSR_rapiditybackground_copy__14->SetMinimum(0);
  diphotonSR_rapiditybackground_copy__14->SetMaximum(17);
  diphotonSR_rapiditybackground_copy__14->SetDirectory(0);
  diphotonSR_rapiditybackground_copy__14->SetStats(0);
  diphotonSR_rapiditybackground_copy__14->SetLineStyle(0);
  diphotonSR_rapiditybackground_copy__14->GetXaxis()->SetTitle("y^{#gamma#gamma}");
  diphotonSR_rapiditybackground_copy__14->GetXaxis()->SetLabelFont(42);
  diphotonSR_rapiditybackground_copy__14->GetXaxis()->SetLabelOffset(0.007);
  diphotonSR_rapiditybackground_copy__14->GetXaxis()->SetLabelSize(fig_6_x_label_size);
  diphotonSR_rapiditybackground_copy__14->GetXaxis()->SetTitleSize(0.06);
  diphotonSR_rapiditybackground_copy__14->GetXaxis()->SetTitleOffset(1.7);
  diphotonSR_rapiditybackground_copy__14->GetXaxis()->SetTitleFont(42);
  diphotonSR_rapiditybackground_copy__14->GetYaxis()->SetTitle("Events / 0.63");
  diphotonSR_rapiditybackground_copy__14->GetYaxis()->CenterTitle(true);
  diphotonSR_rapiditybackground_copy__14->GetYaxis()->SetNdivisions(505);
  diphotonSR_rapiditybackground_copy__14->GetYaxis()->SetLabelFont(42);
  diphotonSR_rapiditybackground_copy__14->GetYaxis()->SetLabelOffset(0.007);
  diphotonSR_rapiditybackground_copy__14->GetYaxis()->SetLabelSize(fig_6_y_label_size);
  diphotonSR_rapiditybackground_copy__14->GetYaxis()->SetTitleSize(0.05);
  diphotonSR_rapiditybackground_copy__14->GetYaxis()->SetTitleOffset(1.0);
  
  diphotonSR_rapiditybackground_copy__14->GetYaxis()->SetTitleFont(42);
  diphotonSR_rapiditybackground_copy__14->GetZaxis()->SetLabelFont(42);
  diphotonSR_rapiditybackground_copy__14->GetZaxis()->SetLabelOffset(0.007);
  diphotonSR_rapiditybackground_copy__14->GetZaxis()->SetLabelSize(0.05);
  diphotonSR_rapiditybackground_copy__14->GetZaxis()->SetTitleSize(0.06);
  diphotonSR_rapiditybackground_copy__14->GetZaxis()->SetTitleOffset(1);
  diphotonSR_rapiditybackground_copy__14->GetZaxis()->SetTitleFont(42);
  diphotonSR_rapiditybackground_copy__14->Draw("sameaxis");
  diphotonSR_rapidity_1->Modified();
  diphotonSR_rapidity->cd();

  // ------------>Primitives in pad: diphotonSR_rapidity_2
  TPad *diphotonSR_rapidity_2 = new TPad("diphotonSR_rapidity_2", "diphotonSR_rapidity_2", 0, 0, 1, 0.3);
  diphotonSR_rapidity_2->Draw();
  diphotonSR_rapidity_2->cd();
  diphotonSR_rapidity_2->Range(-3.22029, -0.8571429, 3.156522, 2);
  diphotonSR_rapidity_2->SetFillColor(0);
  diphotonSR_rapidity_2->SetBorderMode(0);
  diphotonSR_rapidity_2->SetBorderSize(2);
  diphotonSR_rapidity_2->SetLeftMargin(0.16);
  diphotonSR_rapidity_2->SetRightMargin(0.15);
  diphotonSR_rapidity_2->SetTopMargin(0.05);
  diphotonSR_rapidity_2->SetBottomMargin(fig_6_ratio_bottom_margin);
  diphotonSR_rapidity_2->SetFrameFillStyle(0);
  diphotonSR_rapidity_2->SetFrameBorderMode(0);
  diphotonSR_rapidity_2->SetFrameFillStyle(0);
  diphotonSR_rapidity_2->SetFrameBorderMode(0);

  auto ratio_stack_diphotonSR_rapidity = new THStack();
  ratio_stack_diphotonSR_rapidity->SetName("ratio_stack_diphotonSR_rapidity");
  ratio_stack_diphotonSR_rapidity->SetTitle("");
  ratio_stack_diphotonSR_rapidity->SetMinimum(0);
  ratio_stack_diphotonSR_rapidity->SetMaximum(2);

  TH1F *ratio_stack_diphotonSR_rapidity_stack_15 = new TH1F("ratio_stack_diphotonSR_rapidity_stack_15", "", 7, -2.2, 2.2);
  ratio_stack_diphotonSR_rapidity_stack_15->SetMinimum(0);
  ratio_stack_diphotonSR_rapidity_stack_15->SetMaximum(2);
  ratio_stack_diphotonSR_rapidity_stack_15->SetDirectory(0);
  ratio_stack_diphotonSR_rapidity_stack_15->SetStats(0);
  ratio_stack_diphotonSR_rapidity_stack_15->SetLineStyle(0);
  ratio_stack_diphotonSR_rapidity_stack_15->GetXaxis()->SetTitle("y^{#gamma#gamma}");
  ratio_stack_diphotonSR_rapidity_stack_15->GetXaxis()->SetLabelFont(42);
  ratio_stack_diphotonSR_rapidity_stack_15->GetXaxis()->SetLabelOffset(0.007);
  ratio_stack_diphotonSR_rapidity_stack_15->GetXaxis()->SetLabelSize(fig_6_x_ratio_label_size);
  ratio_stack_diphotonSR_rapidity_stack_15->GetXaxis()->SetTitleSize(fig_6_x_ratio_title_size);
  ratio_stack_diphotonSR_rapidity_stack_15->GetXaxis()->SetTitleOffset(1);
  ratio_stack_diphotonSR_rapidity_stack_15->GetXaxis()->SetTitleFont(42);
  ratio_stack_diphotonSR_rapidity_stack_15->GetYaxis()->SetTitle("Data/MC");
  ratio_stack_diphotonSR_rapidity_stack_15->GetYaxis()->CenterTitle();
  ratio_stack_diphotonSR_rapidity_stack_15->GetYaxis()->CenterTitle(true);
  ratio_stack_diphotonSR_rapidity_stack_15->GetYaxis()->SetNdivisions(505);
  ratio_stack_diphotonSR_rapidity_stack_15->GetYaxis()->SetLabelFont(42);
  ratio_stack_diphotonSR_rapidity_stack_15->GetYaxis()->SetLabelOffset(0.007);
  ratio_stack_diphotonSR_rapidity_stack_15->GetYaxis()->SetLabelSize(fig_6_y_ratio_label_size);
  ratio_stack_diphotonSR_rapidity_stack_15->GetYaxis()->SetTitleSize(fig_6_y_ratio_title_size);
  ratio_stack_diphotonSR_rapidity_stack_15->GetYaxis()->SetTitleOffset(0.5);
  ratio_stack_diphotonSR_rapidity_stack_15->GetYaxis()->SetTitleFont(42);
  ratio_stack_diphotonSR_rapidity_stack_15->GetZaxis()->SetLabelFont(42);
  ratio_stack_diphotonSR_rapidity_stack_15->GetZaxis()->SetLabelOffset(0.007);
  ratio_stack_diphotonSR_rapidity_stack_15->GetZaxis()->SetLabelSize(0.05);
  ratio_stack_diphotonSR_rapidity_stack_15->GetZaxis()->SetTitleSize(0.06);
  ratio_stack_diphotonSR_rapidity_stack_15->GetZaxis()->SetTitleOffset(1);
  ratio_stack_diphotonSR_rapidity_stack_15->GetZaxis()->SetTitleFont(42);
  ratio_stack_diphotonSR_rapidity->SetHistogram(ratio_stack_diphotonSR_rapidity_stack_15);

  TH1D *ratio_diphotonSR_rapidity_stack_1 = new TH1D("ratio_diphotonSR_rapidity_stack_1", "diphotonSR_rapidity", 7, -2.2, 2.2);
  ratio_diphotonSR_rapidity_stack_1->SetBinContent(1, 0.0);
  ratio_diphotonSR_rapidity_stack_1->SetBinContent(2, 2.219455);
  ratio_diphotonSR_rapidity_stack_1->SetBinContent(3, 0.8904739);
  ratio_diphotonSR_rapidity_stack_1->SetBinContent(4, 1.058421);
  ratio_diphotonSR_rapidity_stack_1->SetBinContent(5, 0.9043247);
  ratio_diphotonSR_rapidity_stack_1->SetBinContent(6, 0.7643567);
  ratio_diphotonSR_rapidity_stack_1->SetBinContent(7, 1.423743);
  ratio_diphotonSR_rapidity_stack_1->SetBinError(1, 1.84);
  ratio_diphotonSR_rapidity_stack_1->SetBinError(2, 1.002531);
  ratio_diphotonSR_rapidity_stack_1->SetBinError(3, 0.3997446);
  ratio_diphotonSR_rapidity_stack_1->SetBinError(4, 0.3756791);
  ratio_diphotonSR_rapidity_stack_1->SetBinError(5, 0.4057985);
  ratio_diphotonSR_rapidity_stack_1->SetBinError(6, 0.5436129);
  ratio_diphotonSR_rapidity_stack_1->SetBinError(7, 1.434817);
  ratio_diphotonSR_rapidity_stack_1->SetEntries(13.78311);

  ci = 1490;
  color = new TColor(ci, 0, 1, 0, " ", 0);
  ratio_diphotonSR_rapidity_stack_1->SetFillColor(ci);

  ci = TColor::GetColor("#000000");
  ratio_diphotonSR_rapidity_stack_1->SetLineColor(ci);
  ratio_diphotonSR_rapidity_stack_1->SetMarkerStyle(20);
  ratio_diphotonSR_rapidity_stack_1->GetXaxis()->SetRange(1, 7);
  ratio_diphotonSR_rapidity_stack_1->GetXaxis()->SetLabelFont(42);
  ratio_diphotonSR_rapidity_stack_1->GetXaxis()->SetTitleOffset(1);
  ratio_diphotonSR_rapidity_stack_1->GetXaxis()->SetTitleFont(42);
  ratio_diphotonSR_rapidity_stack_1->GetYaxis()->SetLabelFont(42);
  ratio_diphotonSR_rapidity_stack_1->GetYaxis()->SetTitleFont(42);
  ratio_diphotonSR_rapidity_stack_1->GetZaxis()->SetLabelFont(42);
  ratio_diphotonSR_rapidity_stack_1->GetZaxis()->SetTitleOffset(1);
  ratio_diphotonSR_rapidity_stack_1->GetZaxis()->SetTitleFont(42);
  ratio_stack_diphotonSR_rapidity->Add(ratio_diphotonSR_rapidity_stack_1, "");
  ratio_stack_diphotonSR_rapidity->Draw("pe1");
  TLine *line = new TLine(-2.2, 1, 2.2, 1);
  line->SetLineStyle(2);
  line->Draw();

  TH1D *ratio_uncertainty_diphotonSR_rapidity__15 =
      new TH1D("ratio_uncertainty_diphotonSR_rapidity__15", "diphotonSR_rapidity", 7, -2.2, 2.2);
  ratio_uncertainty_diphotonSR_rapidity__15->SetBinContent(1, 1);
  ratio_uncertainty_diphotonSR_rapidity__15->SetBinContent(2, 1);
  ratio_uncertainty_diphotonSR_rapidity__15->SetBinContent(3, 1);
  ratio_uncertainty_diphotonSR_rapidity__15->SetBinContent(4, 1);
  ratio_uncertainty_diphotonSR_rapidity__15->SetBinContent(5, 1);
  ratio_uncertainty_diphotonSR_rapidity__15->SetBinContent(6, 1);
  ratio_uncertainty_diphotonSR_rapidity__15->SetBinContent(7, 1);
  ratio_uncertainty_diphotonSR_rapidity__15->SetBinError(1, 0.4137742);
  ratio_uncertainty_diphotonSR_rapidity__15->SetBinError(2, 0.3374445);
  ratio_uncertainty_diphotonSR_rapidity__15->SetBinError(3, 0.3299157);
  ratio_uncertainty_diphotonSR_rapidity__15->SetBinError(4, 0.3282823);
  ratio_uncertainty_diphotonSR_rapidity__15->SetBinError(5, 0.3294222);
  ratio_uncertainty_diphotonSR_rapidity__15->SetBinError(6, 0.3426659);
  ratio_uncertainty_diphotonSR_rapidity__15->SetBinError(7, 0.370181);
  ratio_uncertainty_diphotonSR_rapidity__15->SetEntries(56.66938);

  ci = 1559;
  color = new TColor(ci, 0, 0, 0, " ", 0.3);
  ratio_uncertainty_diphotonSR_rapidity__15->SetFillColorAlpha(ci, 0.5);
  ratio_uncertainty_diphotonSR_rapidity__15->SetFillStyle(3004);
  ratio_uncertainty_diphotonSR_rapidity__15->SetMarkerStyle(20);
  ratio_uncertainty_diphotonSR_rapidity__15->SetMarkerSize(0);
  ratio_uncertainty_diphotonSR_rapidity__15->GetXaxis()->SetRange(1, 7);
  ratio_uncertainty_diphotonSR_rapidity__15->GetXaxis()->SetLabelFont(42);
  ratio_uncertainty_diphotonSR_rapidity__15->GetXaxis()->SetTitleOffset(1);
  ratio_uncertainty_diphotonSR_rapidity__15->GetXaxis()->SetTitleFont(42);
  ratio_uncertainty_diphotonSR_rapidity__15->GetYaxis()->SetLabelFont(42);
  ratio_uncertainty_diphotonSR_rapidity__15->GetYaxis()->SetTitleFont(42);
  ratio_uncertainty_diphotonSR_rapidity__15->GetZaxis()->SetLabelFont(42);
  ratio_uncertainty_diphotonSR_rapidity__15->GetZaxis()->SetTitleOffset(1);
  ratio_uncertainty_diphotonSR_rapidity__15->GetZaxis()->SetTitleFont(42);
  ratio_uncertainty_diphotonSR_rapidity__15->Draw("same e2");

  auto fake_ratio_graph = new TGraphAsymmErrors();
  fake_ratio_graph->SetPoint(0, -1.257143, 1.9999999);
  fake_ratio_graph->SetPointError(0, 0, 0, 2-1.2607872586, 0);
  fake_ratio_graph->SetMarkerStyle(20);
  fake_ratio_graph->SetMarkerSize(0);
  fake_ratio_graph->SetLineColor(kBlack);
  fake_ratio_graph->Draw("same e");

  diphotonSR_rapidity_2->Modified();
  diphotonSR_rapidity->cd();
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
  diphotonSR_rapidity->Modified();
  diphotonSR_rapidity->cd();
  diphotonSR_rapidity->SetSelected(diphotonSR_rapidity);
  diphotonSR_rapidity->SaveAs("figures/Figure_006_d.pdf");
}
