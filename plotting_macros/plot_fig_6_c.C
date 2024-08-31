#ifdef __CLING__
#pragma cling optimize(0)
#endif

#include "style.h"

void plot_fig_6_c()
{
   gROOT->SetBatch(kTRUE);
//=========Macro generated from canvas: goodPhotonSR_eta/goodPhotonSR_eta
//=========  (Sun Mar 31 12:51:37 2024) by ROOT version 6.26/08
   TCanvas *goodPhotonSR_eta = new TCanvas("goodPhotonSR_eta", "goodPhotonSR_eta",0,0,800,600);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   goodPhotonSR_eta->SetHighLightColor(2);
   goodPhotonSR_eta->Range(0,0,1,1);
   goodPhotonSR_eta->SetFillColor(0);
   goodPhotonSR_eta->SetBorderMode(0);
   goodPhotonSR_eta->SetBorderSize(2);
   goodPhotonSR_eta->SetTickx(1);
   goodPhotonSR_eta->SetTicky(1);
   goodPhotonSR_eta->SetLeftMargin(0.16);
   goodPhotonSR_eta->SetRightMargin(0.15);
   goodPhotonSR_eta->SetTopMargin(0.06);
   goodPhotonSR_eta->SetBottomMargin(0.3);
   goodPhotonSR_eta->SetFrameFillStyle(0);
   goodPhotonSR_eta->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: goodPhotonSR_eta_1
   TPad *goodPhotonSR_eta_1 = new TPad("goodPhotonSR_eta_1", "goodPhotonSR_eta_1",0,0.3,1,1);
   goodPhotonSR_eta_1->Draw();
   goodPhotonSR_eta_1->cd();
   goodPhotonSR_eta_1->Range(-3.22029,0,3.156522,38.46154);
   goodPhotonSR_eta_1->SetFillColor(0);
   goodPhotonSR_eta_1->SetBorderMode(0);
   goodPhotonSR_eta_1->SetBorderSize(2);
   goodPhotonSR_eta_1->SetLeftMargin(0.16);
   goodPhotonSR_eta_1->SetRightMargin(0.15);
   goodPhotonSR_eta_1->SetBottomMargin(0.05);
   goodPhotonSR_eta_1->SetFrameFillStyle(0);
   goodPhotonSR_eta_1->SetFrameBorderMode(0);
   goodPhotonSR_eta_1->SetFrameFillStyle(0);
   goodPhotonSR_eta_1->SetFrameLineWidth(2);
   goodPhotonSR_eta_1->SetFrameBorderMode(0);
   goodPhotonSR_eta_1->SetFrameBorderSize(2);
   
   THStack *goodPhotonSR_etabackground = new THStack();
   goodPhotonSR_etabackground->SetName("goodPhotonSR_etabackground");
   goodPhotonSR_etabackground->SetTitle("");
   goodPhotonSR_etabackground->SetMaximum(37);
   
   TH1F *goodPhotonSR_etabackground_stack_4 = new TH1F("goodPhotonSR_etabackground_stack_4","",5,-2.2,2.2);
   goodPhotonSR_etabackground_stack_4->SetMinimum(0);
   goodPhotonSR_etabackground_stack_4->SetMaximum(37);
   goodPhotonSR_etabackground_stack_4->SetDirectory(0);
   goodPhotonSR_etabackground_stack_4->SetStats(0);
   goodPhotonSR_etabackground_stack_4->SetLineStyle(0);
   goodPhotonSR_etabackground_stack_4->GetXaxis()->SetTitle("#eta^{#gamma}");
   goodPhotonSR_etabackground_stack_4->GetXaxis()->SetLabelFont(42);
   goodPhotonSR_etabackground_stack_4->GetXaxis()->SetLabelOffset(0.007);
   goodPhotonSR_etabackground_stack_4->GetXaxis()->SetLabelSize(0.0);
   goodPhotonSR_etabackground_stack_4->GetXaxis()->SetTitleSize(fig_6_x_title_size);
   goodPhotonSR_etabackground_stack_4->GetXaxis()->SetTitleOffset(1.7);
   goodPhotonSR_etabackground_stack_4->GetXaxis()->SetTitleFont(42);
   goodPhotonSR_etabackground_stack_4->GetYaxis()->SetTitle("Entries / 0.88");
   goodPhotonSR_etabackground_stack_4->GetYaxis()->CenterTitle(true);
   goodPhotonSR_etabackground_stack_4->GetYaxis()->SetNdivisions(505);
   goodPhotonSR_etabackground_stack_4->GetYaxis()->SetLabelFont(42);
   goodPhotonSR_etabackground_stack_4->GetYaxis()->SetLabelOffset(0.007);
   goodPhotonSR_etabackground_stack_4->GetYaxis()->SetLabelSize(0.06);
   goodPhotonSR_etabackground_stack_4->GetYaxis()->SetTitleSize(fig_6_y_title_size);
   goodPhotonSR_etabackground_stack_4->GetYaxis()->SetTitleOffset(1.0);
   
   goodPhotonSR_etabackground_stack_4->GetYaxis()->SetTitleFont(42);
   goodPhotonSR_etabackground_stack_4->GetZaxis()->SetLabelFont(42);
   goodPhotonSR_etabackground_stack_4->GetZaxis()->SetLabelOffset(0.007);
   goodPhotonSR_etabackground_stack_4->GetZaxis()->SetLabelSize(0.05);
   goodPhotonSR_etabackground_stack_4->GetZaxis()->SetTitleSize(0.06);
   goodPhotonSR_etabackground_stack_4->GetZaxis()->SetTitleOffset(1);
   goodPhotonSR_etabackground_stack_4->GetZaxis()->SetTitleFont(42);
   goodPhotonSR_etabackground->SetHistogram(goodPhotonSR_etabackground_stack_4);
   
   
   TH1D *goodPhotonSR_eta_stack_1 = new TH1D("goodPhotonSR_eta_stack_1","goodPhotonSR_eta",5,-2.2,2.2);
   goodPhotonSR_eta_stack_1->SetBinContent(1,1.413527);
   goodPhotonSR_eta_stack_1->SetBinContent(2,4.850969);
   goodPhotonSR_eta_stack_1->SetBinContent(3,7.255448);
   goodPhotonSR_eta_stack_1->SetBinContent(4,5.048665);
   goodPhotonSR_eta_stack_1->SetBinContent(5,1.640878);
   goodPhotonSR_eta_stack_1->SetBinError(1,0.05910255);
   goodPhotonSR_eta_stack_1->SetBinError(2,0.1094885);
   goodPhotonSR_eta_stack_1->SetBinError(3,0.1339017);
   goodPhotonSR_eta_stack_1->SetBinError(4,0.1116972);
   goodPhotonSR_eta_stack_1->SetBinError(5,0.06367841);
   goodPhotonSR_eta_stack_1->SetEntries(8178);
   goodPhotonSR_eta_stack_1->SetDirectory(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#6699ff");
   goodPhotonSR_eta_stack_1->SetFillColor(ci);

   ci = TColor::GetColor("#000000");
   goodPhotonSR_eta_stack_1->SetLineColor(ci);
   goodPhotonSR_eta_stack_1->SetMarkerStyle(20);
   goodPhotonSR_eta_stack_1->GetXaxis()->SetRange(1,5);
   goodPhotonSR_eta_stack_1->GetXaxis()->SetLabelFont(42);
   goodPhotonSR_eta_stack_1->GetXaxis()->SetTitleOffset(1);
   goodPhotonSR_eta_stack_1->GetXaxis()->SetTitleFont(42);
   goodPhotonSR_eta_stack_1->GetYaxis()->SetLabelFont(42);
   goodPhotonSR_eta_stack_1->GetYaxis()->SetTitleFont(42);
   goodPhotonSR_eta_stack_1->GetZaxis()->SetLabelFont(42);
   goodPhotonSR_eta_stack_1->GetZaxis()->SetTitleOffset(1);
   goodPhotonSR_eta_stack_1->GetZaxis()->SetTitleFont(42);
   goodPhotonSR_etabackground->Add(goodPhotonSR_eta_stack_1,"");
   
   TH1D *goodPhotonSR_eta_stack_2 = new TH1D("goodPhotonSR_eta_stack_2","goodPhotonSR_eta",5,-2.2,2.2);
   goodPhotonSR_eta_stack_2->SetBinContent(1,0.2874844);
   goodPhotonSR_eta_stack_2->SetBinContent(2,0.4024781);
   goodPhotonSR_eta_stack_2->SetBinContent(3,0.3449812);
   goodPhotonSR_eta_stack_2->SetBinContent(4,0.2299875);
   goodPhotonSR_eta_stack_2->SetBinContent(5,0.2299875);
   goodPhotonSR_eta_stack_2->SetBinError(1,0.1285669);
   goodPhotonSR_eta_stack_2->SetBinError(2,0.1521224);
   goodPhotonSR_eta_stack_2->SetBinError(3,0.140838);
   goodPhotonSR_eta_stack_2->SetBinError(4,0.1149937);
   goodPhotonSR_eta_stack_2->SetBinError(5,0.1149937);
   goodPhotonSR_eta_stack_2->SetEntries(26);
   goodPhotonSR_eta_stack_2->SetDirectory(0);

   ci = TColor::GetColor("#ffff00");
   goodPhotonSR_eta_stack_2->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   goodPhotonSR_eta_stack_2->SetLineColor(ci);
   goodPhotonSR_eta_stack_2->SetMarkerStyle(20);
   goodPhotonSR_eta_stack_2->SetMarkerSize(0);
   goodPhotonSR_eta_stack_2->GetXaxis()->SetRange(1,5);
   goodPhotonSR_eta_stack_2->GetXaxis()->SetLabelFont(42);
   goodPhotonSR_eta_stack_2->GetXaxis()->SetTitleOffset(1);
   goodPhotonSR_eta_stack_2->GetXaxis()->SetTitleFont(42);
   goodPhotonSR_eta_stack_2->GetYaxis()->SetLabelFont(42);
   goodPhotonSR_eta_stack_2->GetYaxis()->SetTitleFont(42);
   goodPhotonSR_eta_stack_2->GetZaxis()->SetLabelFont(42);
   goodPhotonSR_eta_stack_2->GetZaxis()->SetTitleOffset(1);
   goodPhotonSR_eta_stack_2->GetZaxis()->SetTitleFont(42);
   goodPhotonSR_etabackground->Add(goodPhotonSR_eta_stack_2,"");
   
   TH1D *goodPhotonSR_eta_stack_3 = new TH1D("goodPhotonSR_eta_stack_3","goodPhotonSR_eta",5,-2.2,2.2);
   goodPhotonSR_eta_stack_3->SetBinContent(1,0.4330957);
   goodPhotonSR_eta_stack_3->SetBinContent(2,0.2165479);
   goodPhotonSR_eta_stack_3->SetBinContent(3,0.3609131);
   goodPhotonSR_eta_stack_3->SetBinContent(4,0.7940088);
   goodPhotonSR_eta_stack_3->SetBinContent(5,0.5052783);
   goodPhotonSR_eta_stack_3->SetBinError(1,0.1768106);
   goodPhotonSR_eta_stack_3->SetBinError(2,0.125024);
   goodPhotonSR_eta_stack_3->SetBinError(3,0.1614052);
   goodPhotonSR_eta_stack_3->SetBinError(4,0.2394027);
   goodPhotonSR_eta_stack_3->SetBinError(5,0.1909773);
   goodPhotonSR_eta_stack_3->SetEntries(32);
   goodPhotonSR_eta_stack_3->SetDirectory(0);

   ci = TColor::GetColor("#ffff00");
   goodPhotonSR_eta_stack_3->SetFillColor(ci);

   ci = TColor::GetColor("#000000");
   goodPhotonSR_eta_stack_3->SetLineColor(ci);
   goodPhotonSR_eta_stack_3->SetMarkerStyle(20);
   goodPhotonSR_eta_stack_3->SetMarkerSize(0);
   goodPhotonSR_eta_stack_3->GetXaxis()->SetRange(1,5);
   goodPhotonSR_eta_stack_3->GetXaxis()->SetLabelFont(42);
   goodPhotonSR_eta_stack_3->GetXaxis()->SetTitleOffset(1);
   goodPhotonSR_eta_stack_3->GetXaxis()->SetTitleFont(42);
   goodPhotonSR_eta_stack_3->GetYaxis()->SetLabelFont(42);
   goodPhotonSR_eta_stack_3->GetYaxis()->SetTitleFont(42);
   goodPhotonSR_eta_stack_3->GetZaxis()->SetLabelFont(42);
   goodPhotonSR_eta_stack_3->GetZaxis()->SetTitleOffset(1);
   goodPhotonSR_eta_stack_3->GetZaxis()->SetTitleFont(42);
   goodPhotonSR_etabackground->Add(goodPhotonSR_eta_stack_3,"");
   
   TH1D *goodPhotonSR_eta_stack_4 = new TH1D("goodPhotonSR_eta_stack_4","goodPhotonSR_eta",5,-2.2,2.2);
   goodPhotonSR_eta_stack_4->SetBinContent(1,1.77596);
   goodPhotonSR_eta_stack_4->SetBinContent(2,6.396849);
   goodPhotonSR_eta_stack_4->SetBinContent(3,9.230466);
   goodPhotonSR_eta_stack_4->SetBinContent(4,6.000934);
   goodPhotonSR_eta_stack_4->SetBinContent(5,2.239745);
   goodPhotonSR_eta_stack_4->SetBinError(1,0.1002232);
   goodPhotonSR_eta_stack_4->SetBinError(2,0.1902106);
   goodPhotonSR_eta_stack_4->SetBinError(3,0.2284881);
   goodPhotonSR_eta_stack_4->SetBinError(4,0.1842303);
   goodPhotonSR_eta_stack_4->SetBinError(5,0.1125514);
   goodPhotonSR_eta_stack_4->SetEntries(4534);
   goodPhotonSR_eta_stack_4->SetDirectory(0);

   ci = TColor::GetColor("#ff9933");
   goodPhotonSR_eta_stack_4->SetFillColor(ci);

   ci = TColor::GetColor("#000000");
   goodPhotonSR_eta_stack_4->SetLineColor(ci);
   goodPhotonSR_eta_stack_4->SetMarkerStyle(20);
   goodPhotonSR_eta_stack_4->GetXaxis()->SetRange(1,5);
   goodPhotonSR_eta_stack_4->GetXaxis()->SetLabelFont(42);
   goodPhotonSR_eta_stack_4->GetXaxis()->SetTitleOffset(1);
   goodPhotonSR_eta_stack_4->GetXaxis()->SetTitleFont(42);
   goodPhotonSR_eta_stack_4->GetYaxis()->SetLabelFont(42);
   goodPhotonSR_eta_stack_4->GetYaxis()->SetTitleFont(42);
   goodPhotonSR_eta_stack_4->GetZaxis()->SetLabelFont(42);
   goodPhotonSR_eta_stack_4->GetZaxis()->SetTitleOffset(1);
   goodPhotonSR_eta_stack_4->GetZaxis()->SetTitleFont(42);
   goodPhotonSR_etabackground->Add(goodPhotonSR_eta_stack_4,"");
   goodPhotonSR_etabackground->Draw("hist");
   
   Double_t Graph0_fx3002[5] = {-1.76, -0.88, 5.551115e-17, 0.88, 1.76};
  Double_t Graph0_fy3002[5] = {5, 13, 20, 9, 5};
  Double_t Graph0_felx3002[5] = {0.44, 0.44, 0.44, 0.44, 0.44};
  Double_t Graph0_fely3002[5] = {2.159691, 3.558662, 4.434448, 2.943461, 2.159691};
  Double_t Graph0_fehx3002[5] = {0.44, 0.44, 0.44, 0.44, 0.44};
  Double_t Graph0_fehy3002[5] = {3.382473, 4.697573, 5.546519, 4.110204, 3.382473};
  TGraphAsymmErrors *grae =
      new TGraphAsymmErrors(5, Graph0_fx3002, Graph0_fy3002, Graph0_felx3002, Graph0_fehx3002, Graph0_fely3002, Graph0_fehy3002);
  grae->SetName("Graph0");
  grae->SetTitle("Graph");
  grae->SetFillStyle(1000);
  grae->SetMarkerStyle(20);

  TH1F *Graph_Graph03002 = new TH1F("Graph_Graph03002", "Graph", 100, -2.112, 2.112);
  Graph_Graph03002->SetMinimum(0.5696878);
  Graph_Graph03002->SetMaximum(27.81714);
  Graph_Graph03002->SetDirectory(0);
  Graph_Graph03002->SetStats(0);
  Graph_Graph03002->SetLineStyle(0);
  Graph_Graph03002->GetXaxis()->SetLabelFont(42);
  Graph_Graph03002->GetXaxis()->SetLabelOffset(0.007);
  Graph_Graph03002->GetXaxis()->SetLabelSize(0.05);
  Graph_Graph03002->GetXaxis()->SetTitleSize(0.06);
  Graph_Graph03002->GetXaxis()->SetTitleOffset(0.9);
  Graph_Graph03002->GetXaxis()->SetTitleFont(42);
  Graph_Graph03002->GetYaxis()->SetLabelFont(42);
  Graph_Graph03002->GetYaxis()->SetLabelOffset(0.007);
  Graph_Graph03002->GetYaxis()->SetLabelSize(0.05);
  Graph_Graph03002->GetYaxis()->SetTitleSize(0.06);
  Graph_Graph03002->GetYaxis()->SetTitleOffset(1.25);
  Graph_Graph03002->GetYaxis()->SetTitleFont(42);
  Graph_Graph03002->GetZaxis()->SetLabelFont(42);
  Graph_Graph03002->GetZaxis()->SetLabelOffset(0.007);
  Graph_Graph03002->GetZaxis()->SetLabelSize(0.05);
  Graph_Graph03002->GetZaxis()->SetTitleSize(0.06);
  Graph_Graph03002->GetZaxis()->SetTitleOffset(1);
  Graph_Graph03002->GetZaxis()->SetTitleFont(42);
  grae->SetHistogram(Graph_Graph03002);

  grae->Draw("pe");
   
   TH1D *backgrounds_unc_goodPhotonSR_eta__4 = new TH1D("backgrounds_unc_goodPhotonSR_eta__4","goodPhotonSR_eta",5,-2.2,2.2);
   backgrounds_unc_goodPhotonSR_eta__4->SetBinContent(1,3.910067);
   backgrounds_unc_goodPhotonSR_eta__4->SetBinContent(2,11.86684);
   backgrounds_unc_goodPhotonSR_eta__4->SetBinContent(3,17.19181);
   backgrounds_unc_goodPhotonSR_eta__4->SetBinContent(4,12.0736);
   backgrounds_unc_goodPhotonSR_eta__4->SetBinContent(5,4.615889);
   backgrounds_unc_goodPhotonSR_eta__4->SetBinError(1,0.9327902);
   backgrounds_unc_goodPhotonSR_eta__4->SetBinError(2,2.745255);
   backgrounds_unc_goodPhotonSR_eta__4->SetBinError(3,3.96876);
   backgrounds_unc_goodPhotonSR_eta__4->SetBinError(4,2.797906);
   backgrounds_unc_goodPhotonSR_eta__4->SetBinError(5,1.092487);
   backgrounds_unc_goodPhotonSR_eta__4->SetEntries(12770);

   ci = 1556;
   color = new TColor(ci, 0, 0, 0, " ", 0.3);
   backgrounds_unc_goodPhotonSR_eta__4->SetFillColorAlpha(ci, 0.5);
   backgrounds_unc_goodPhotonSR_eta__4->SetFillStyle(3004);
   backgrounds_unc_goodPhotonSR_eta__4->SetMarkerStyle(20);
   backgrounds_unc_goodPhotonSR_eta__4->SetMarkerSize(0);
   backgrounds_unc_goodPhotonSR_eta__4->GetXaxis()->SetRange(1,5);
   backgrounds_unc_goodPhotonSR_eta__4->GetXaxis()->SetLabelFont(42);
   backgrounds_unc_goodPhotonSR_eta__4->GetXaxis()->SetTitleOffset(1);
   backgrounds_unc_goodPhotonSR_eta__4->GetXaxis()->SetTitleFont(42);
   backgrounds_unc_goodPhotonSR_eta__4->GetYaxis()->SetLabelFont(42);
   backgrounds_unc_goodPhotonSR_eta__4->GetYaxis()->SetTitleFont(42);
   backgrounds_unc_goodPhotonSR_eta__4->GetZaxis()->SetLabelFont(42);
   backgrounds_unc_goodPhotonSR_eta__4->GetZaxis()->SetTitleOffset(1);
   backgrounds_unc_goodPhotonSR_eta__4->GetZaxis()->SetTitleFont(42);
   backgrounds_unc_goodPhotonSR_eta__4->Draw("same e2");
   
   auto leg = get_lbl_legend();
//   leg->Draw();
   
   TH1F *goodPhotonSR_etabackground_copy__5 = new TH1F("goodPhotonSR_etabackground_copy__5","",5,-2.2,2.2);
   goodPhotonSR_etabackground_copy__5->SetMinimum(0);
   goodPhotonSR_etabackground_copy__5->SetMaximum(37);
   goodPhotonSR_etabackground_copy__5->SetDirectory(0);
   goodPhotonSR_etabackground_copy__5->SetStats(0);
   goodPhotonSR_etabackground_copy__5->SetLineStyle(0);
   goodPhotonSR_etabackground_copy__5->GetXaxis()->SetTitle("#eta^{#gamma}");
   goodPhotonSR_etabackground_copy__5->GetXaxis()->SetLabelFont(42);
   goodPhotonSR_etabackground_copy__5->GetXaxis()->SetLabelOffset(0.007);
   goodPhotonSR_etabackground_copy__5->GetXaxis()->SetLabelSize(fig_6_x_label_size);
   goodPhotonSR_etabackground_copy__5->GetXaxis()->SetTitleSize(0.06);
   goodPhotonSR_etabackground_copy__5->GetXaxis()->SetTitleOffset(1.7);
   goodPhotonSR_etabackground_copy__5->GetXaxis()->SetTitleFont(42);
   goodPhotonSR_etabackground_copy__5->GetYaxis()->SetTitle("Entries / 0.88");
   goodPhotonSR_etabackground_copy__5->GetYaxis()->CenterTitle(true);
   goodPhotonSR_etabackground_copy__5->GetYaxis()->SetNdivisions(505);
   goodPhotonSR_etabackground_copy__5->GetYaxis()->SetLabelFont(42);
   goodPhotonSR_etabackground_copy__5->GetYaxis()->SetLabelOffset(0.007);
   goodPhotonSR_etabackground_copy__5->GetYaxis()->SetLabelSize(fig_6_y_label_size);
   goodPhotonSR_etabackground_copy__5->GetYaxis()->SetTitleSize(0.05);
   goodPhotonSR_etabackground_copy__5->GetYaxis()->SetTitleOffset(1.0);
   
   goodPhotonSR_etabackground_copy__5->GetYaxis()->SetTitleFont(42);
   goodPhotonSR_etabackground_copy__5->GetZaxis()->SetLabelFont(42);
   goodPhotonSR_etabackground_copy__5->GetZaxis()->SetLabelOffset(0.007);
   goodPhotonSR_etabackground_copy__5->GetZaxis()->SetLabelSize(0.05);
   goodPhotonSR_etabackground_copy__5->GetZaxis()->SetTitleSize(0.06);
   goodPhotonSR_etabackground_copy__5->GetZaxis()->SetTitleOffset(1);
   goodPhotonSR_etabackground_copy__5->GetZaxis()->SetTitleFont(42);
   goodPhotonSR_etabackground_copy__5->Draw("sameaxis");
   goodPhotonSR_eta_1->Modified();
   goodPhotonSR_eta->cd();
  
// ------------>Primitives in pad: goodPhotonSR_eta_2
   TPad *goodPhotonSR_eta_2 = new TPad("goodPhotonSR_eta_2", "goodPhotonSR_eta_2",0,0,1,0.3);
   goodPhotonSR_eta_2->Draw();
   goodPhotonSR_eta_2->cd();
   goodPhotonSR_eta_2->Range(-3.22029,-0.8571429,3.156522,2);
   goodPhotonSR_eta_2->SetFillColor(0);
   goodPhotonSR_eta_2->SetBorderMode(0);
   goodPhotonSR_eta_2->SetBorderSize(2);
   goodPhotonSR_eta_2->SetLeftMargin(0.16);
   goodPhotonSR_eta_2->SetRightMargin(0.15);
   goodPhotonSR_eta_2->SetTopMargin(0.05);
   goodPhotonSR_eta_2->SetBottomMargin(fig_6_ratio_bottom_margin);
   goodPhotonSR_eta_2->SetFrameFillStyle(0);
   goodPhotonSR_eta_2->SetFrameBorderMode(0);
   goodPhotonSR_eta_2->SetFrameFillStyle(0);
   goodPhotonSR_eta_2->SetFrameBorderMode(0);
   
   auto ratio_stack_goodPhotonSR_eta = new THStack();
   ratio_stack_goodPhotonSR_eta->SetName("ratio_stack_goodPhotonSR_eta");
   ratio_stack_goodPhotonSR_eta->SetTitle("");
   ratio_stack_goodPhotonSR_eta->SetMinimum(0);
   ratio_stack_goodPhotonSR_eta->SetMaximum(2);
   
   TH1F *ratio_stack_goodPhotonSR_eta_stack_6 = new TH1F("ratio_stack_goodPhotonSR_eta_stack_6","",5,-2.2,2.2);
   ratio_stack_goodPhotonSR_eta_stack_6->SetMinimum(0);
   ratio_stack_goodPhotonSR_eta_stack_6->SetMaximum(2);
   ratio_stack_goodPhotonSR_eta_stack_6->SetDirectory(0);
   ratio_stack_goodPhotonSR_eta_stack_6->SetStats(0);
   ratio_stack_goodPhotonSR_eta_stack_6->SetLineStyle(0);
   ratio_stack_goodPhotonSR_eta_stack_6->GetXaxis()->SetTitle("#eta^{#gamma}");
   ratio_stack_goodPhotonSR_eta_stack_6->GetXaxis()->SetLabelFont(42);
   ratio_stack_goodPhotonSR_eta_stack_6->GetXaxis()->SetLabelOffset(0.007);
   ratio_stack_goodPhotonSR_eta_stack_6->GetXaxis()->SetLabelSize(fig_6_x_ratio_label_size);
   ratio_stack_goodPhotonSR_eta_stack_6->GetXaxis()->SetTitleSize(fig_6_x_ratio_title_size);
   ratio_stack_goodPhotonSR_eta_stack_6->GetXaxis()->SetTitleOffset(1);
   ratio_stack_goodPhotonSR_eta_stack_6->GetXaxis()->SetTitleFont(42);
   ratio_stack_goodPhotonSR_eta_stack_6->GetYaxis()->SetTitle("Data/MC");
  ratio_stack_goodPhotonSR_eta_stack_6->GetYaxis()->CenterTitle();
   ratio_stack_goodPhotonSR_eta_stack_6->GetYaxis()->CenterTitle(true);
   ratio_stack_goodPhotonSR_eta_stack_6->GetYaxis()->SetNdivisions(505);
   ratio_stack_goodPhotonSR_eta_stack_6->GetYaxis()->SetLabelFont(42);
   ratio_stack_goodPhotonSR_eta_stack_6->GetYaxis()->SetLabelOffset(0.007);
   ratio_stack_goodPhotonSR_eta_stack_6->GetYaxis()->SetLabelSize(fig_6_y_ratio_label_size);
   ratio_stack_goodPhotonSR_eta_stack_6->GetYaxis()->SetTitleSize(fig_6_y_ratio_title_size);
   ratio_stack_goodPhotonSR_eta_stack_6->GetYaxis()->SetTitleOffset(0.5);
   ratio_stack_goodPhotonSR_eta_stack_6->GetYaxis()->SetTitleFont(42);
   ratio_stack_goodPhotonSR_eta_stack_6->GetZaxis()->SetLabelFont(42);
   ratio_stack_goodPhotonSR_eta_stack_6->GetZaxis()->SetLabelOffset(0.007);
   ratio_stack_goodPhotonSR_eta_stack_6->GetZaxis()->SetLabelSize(0.05);
   ratio_stack_goodPhotonSR_eta_stack_6->GetZaxis()->SetTitleSize(0.06);
   ratio_stack_goodPhotonSR_eta_stack_6->GetZaxis()->SetTitleOffset(1);
   ratio_stack_goodPhotonSR_eta_stack_6->GetZaxis()->SetTitleFont(42);
   ratio_stack_goodPhotonSR_eta->SetHistogram(ratio_stack_goodPhotonSR_eta_stack_6);
   
   
   TH1D *ratio_goodPhotonSR_eta_stack_1 = new TH1D("ratio_goodPhotonSR_eta_stack_1","goodPhotonSR_eta",5,-2.2,2.2);
   ratio_goodPhotonSR_eta_stack_1->SetBinContent(1,1.27875);
   ratio_goodPhotonSR_eta_stack_1->SetBinContent(2,1.095489);
   ratio_goodPhotonSR_eta_stack_1->SetBinContent(3,1.163345);
   ratio_goodPhotonSR_eta_stack_1->SetBinContent(4,0.7454283);
   ratio_goodPhotonSR_eta_stack_1->SetBinContent(5,1.083215);
   ratio_goodPhotonSR_eta_stack_1->SetBinError(1,0.5775812);
   ratio_goodPhotonSR_eta_stack_1->SetBinError(2,0.3050509);
   ratio_goodPhotonSR_eta_stack_1->SetBinError(3,0.261151);
   ratio_goodPhotonSR_eta_stack_1->SetBinError(4,0.2493716);
   ratio_goodPhotonSR_eta_stack_1->SetBinError(5,0.4881891);
   ratio_goodPhotonSR_eta_stack_1->SetEntries(36.205);

   ci = 1484;
   color = new TColor(ci, 0, 1, 0, " ", 0);
   ratio_goodPhotonSR_eta_stack_1->SetFillColor(ci);

   ci = TColor::GetColor("#000000");
   ratio_goodPhotonSR_eta_stack_1->SetLineColor(ci);
   ratio_goodPhotonSR_eta_stack_1->SetMarkerStyle(20);
   ratio_goodPhotonSR_eta_stack_1->GetXaxis()->SetRange(1,5);
   ratio_goodPhotonSR_eta_stack_1->GetXaxis()->SetLabelFont(42);
   ratio_goodPhotonSR_eta_stack_1->GetXaxis()->SetTitleOffset(1);
   ratio_goodPhotonSR_eta_stack_1->GetXaxis()->SetTitleFont(42);
   ratio_goodPhotonSR_eta_stack_1->GetYaxis()->SetLabelFont(42);
   ratio_goodPhotonSR_eta_stack_1->GetYaxis()->SetTitleFont(42);
   ratio_goodPhotonSR_eta_stack_1->GetZaxis()->SetLabelFont(42);
   ratio_goodPhotonSR_eta_stack_1->GetZaxis()->SetTitleOffset(1);
   ratio_goodPhotonSR_eta_stack_1->GetZaxis()->SetTitleFont(42);
   ratio_stack_goodPhotonSR_eta->Add(ratio_goodPhotonSR_eta_stack_1,"");
   ratio_stack_goodPhotonSR_eta->Draw("pe1");
   TLine *line = new TLine(-2.2,1,2.2,1);
   line->SetLineStyle(2);
   line->Draw();
   
   TH1D *ratio_uncertainty_goodPhotonSR_eta__6 = new TH1D("ratio_uncertainty_goodPhotonSR_eta__6","goodPhotonSR_eta",5,-2.2,2.2);
   ratio_uncertainty_goodPhotonSR_eta__6->SetBinContent(1,1);
   ratio_uncertainty_goodPhotonSR_eta__6->SetBinContent(2,1);
   ratio_uncertainty_goodPhotonSR_eta__6->SetBinContent(3,1);
   ratio_uncertainty_goodPhotonSR_eta__6->SetBinContent(4,1);
   ratio_uncertainty_goodPhotonSR_eta__6->SetBinContent(5,1);
   ratio_uncertainty_goodPhotonSR_eta__6->SetBinError(1,0.3373764);
   ratio_uncertainty_goodPhotonSR_eta__6->SetBinError(2,0.3271617);
   ratio_uncertainty_goodPhotonSR_eta__6->SetBinError(3,0.3264738);
   ratio_uncertainty_goodPhotonSR_eta__6->SetBinError(4,0.3277264);
   ratio_uncertainty_goodPhotonSR_eta__6->SetBinError(5,0.3347157);
   ratio_uncertainty_goodPhotonSR_eta__6->SetEntries(45.7137);

   ci = 1556;
   color = new TColor(ci, 0, 0, 0, " ", 0.3);
   ratio_uncertainty_goodPhotonSR_eta__6->SetFillColorAlpha(ci, 0.5);
   ratio_uncertainty_goodPhotonSR_eta__6->SetFillStyle(3004);
   ratio_uncertainty_goodPhotonSR_eta__6->SetMarkerStyle(20);
   ratio_uncertainty_goodPhotonSR_eta__6->SetMarkerSize(0);
   ratio_uncertainty_goodPhotonSR_eta__6->GetXaxis()->SetRange(1,5);
   ratio_uncertainty_goodPhotonSR_eta__6->GetXaxis()->SetLabelFont(42);
   ratio_uncertainty_goodPhotonSR_eta__6->GetXaxis()->SetTitleOffset(1);
   ratio_uncertainty_goodPhotonSR_eta__6->GetXaxis()->SetTitleFont(42);
   ratio_uncertainty_goodPhotonSR_eta__6->GetYaxis()->SetLabelFont(42);
   ratio_uncertainty_goodPhotonSR_eta__6->GetYaxis()->SetTitleFont(42);
   ratio_uncertainty_goodPhotonSR_eta__6->GetZaxis()->SetLabelFont(42);
   ratio_uncertainty_goodPhotonSR_eta__6->GetZaxis()->SetTitleOffset(1);
   ratio_uncertainty_goodPhotonSR_eta__6->GetZaxis()->SetTitleFont(42);
   ratio_uncertainty_goodPhotonSR_eta__6->Draw("same e2");
   goodPhotonSR_eta_2->Modified();
   goodPhotonSR_eta->cd();
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
   goodPhotonSR_eta->Modified();
   goodPhotonSR_eta->cd();
   goodPhotonSR_eta->SetSelected(goodPhotonSR_eta);
   goodPhotonSR_eta->SaveAs("figures/Figure_006_c.pdf");
}
