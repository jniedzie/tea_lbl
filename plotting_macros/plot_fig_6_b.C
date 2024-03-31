#ifdef __CLING__
#pragma cling optimize(0)
#endif
void plot_fig_6_b()
{
   gROOT->SetBatch(kTRUE);
//=========Macro generated from canvas: diphotonSR_pt/diphotonSR_pt
//=========  (Sun Mar 31 12:51:37 2024) by ROOT version 6.26/08
   TCanvas *diphotonSR_pt = new TCanvas("diphotonSR_pt", "diphotonSR_pt",0,0,800,600);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   diphotonSR_pt->SetHighLightColor(2);
   diphotonSR_pt->Range(0,0,1,1);
   diphotonSR_pt->SetFillColor(0);
   diphotonSR_pt->SetBorderMode(0);
   diphotonSR_pt->SetBorderSize(2);
   diphotonSR_pt->SetTickx(1);
   diphotonSR_pt->SetTicky(1);
   diphotonSR_pt->SetLeftMargin(0.16);
   diphotonSR_pt->SetRightMargin(0.15);
   diphotonSR_pt->SetTopMargin(0.06);
   diphotonSR_pt->SetBottomMargin(0.3);
   diphotonSR_pt->SetFrameFillStyle(0);
   diphotonSR_pt->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: diphotonSR_pt_1
   TPad *diphotonSR_pt_1 = new TPad("diphotonSR_pt_1", "diphotonSR_pt_1",0,0.3,1,1);
   diphotonSR_pt_1->Draw();
   diphotonSR_pt_1->cd();
   diphotonSR_pt_1->Range(-0.231884,0,1.217391,19.78022);
   diphotonSR_pt_1->SetFillColor(0);
   diphotonSR_pt_1->SetBorderMode(0);
   diphotonSR_pt_1->SetBorderSize(2);
   diphotonSR_pt_1->SetLeftMargin(0.16);
   diphotonSR_pt_1->SetRightMargin(0.15);
   diphotonSR_pt_1->SetBottomMargin(0);
   diphotonSR_pt_1->SetFrameFillStyle(0);
   diphotonSR_pt_1->SetFrameBorderMode(0);
   diphotonSR_pt_1->SetFrameFillStyle(0);
   diphotonSR_pt_1->SetFrameLineWidth(2);
   diphotonSR_pt_1->SetFrameBorderMode(0);
   diphotonSR_pt_1->SetFrameBorderSize(2);
   
   THStack *diphotonSR_ptbackground = new THStack();
   diphotonSR_ptbackground->SetName("diphotonSR_ptbackground");
   diphotonSR_ptbackground->SetTitle("");
   diphotonSR_ptbackground->SetMaximum(18);
   
   TH1F *diphotonSR_ptbackground_stack_10 = new TH1F("diphotonSR_ptbackground_stack_10","",5,0,1);
   diphotonSR_ptbackground_stack_10->SetMinimum(0);
   diphotonSR_ptbackground_stack_10->SetMaximum(18);
   diphotonSR_ptbackground_stack_10->SetDirectory(0);
   diphotonSR_ptbackground_stack_10->SetStats(0);
   diphotonSR_ptbackground_stack_10->SetLineStyle(0);
   diphotonSR_ptbackground_stack_10->GetXaxis()->SetTitle("p_{T}^{#gamma#gamma} (GeV)");
   diphotonSR_ptbackground_stack_10->GetXaxis()->SetLabelFont(42);
   diphotonSR_ptbackground_stack_10->GetXaxis()->SetLabelOffset(0.007);
   diphotonSR_ptbackground_stack_10->GetXaxis()->SetLabelSize(0.06);
   diphotonSR_ptbackground_stack_10->GetXaxis()->SetTitleSize(0.06);
   diphotonSR_ptbackground_stack_10->GetXaxis()->SetTitleOffset(1.7);
   diphotonSR_ptbackground_stack_10->GetXaxis()->SetTitleFont(42);
   diphotonSR_ptbackground_stack_10->GetYaxis()->SetTitle("Events / 0.2 GeV");
   diphotonSR_ptbackground_stack_10->GetYaxis()->CenterTitle(true);
   diphotonSR_ptbackground_stack_10->GetYaxis()->SetNdivisions(505);
   diphotonSR_ptbackground_stack_10->GetYaxis()->SetLabelFont(42);
   diphotonSR_ptbackground_stack_10->GetYaxis()->SetLabelOffset(0.007);
   diphotonSR_ptbackground_stack_10->GetYaxis()->SetLabelSize(0.06);
   diphotonSR_ptbackground_stack_10->GetYaxis()->SetTitleSize(0.05);
   diphotonSR_ptbackground_stack_10->GetYaxis()->SetTitleOffset(1.5);
   diphotonSR_ptbackground_stack_10->GetYaxis()->SetTitleFont(42);
   diphotonSR_ptbackground_stack_10->GetZaxis()->SetLabelFont(42);
   diphotonSR_ptbackground_stack_10->GetZaxis()->SetLabelOffset(0.007);
   diphotonSR_ptbackground_stack_10->GetZaxis()->SetLabelSize(0.05);
   diphotonSR_ptbackground_stack_10->GetZaxis()->SetTitleSize(0.06);
   diphotonSR_ptbackground_stack_10->GetZaxis()->SetTitleOffset(1);
   diphotonSR_ptbackground_stack_10->GetZaxis()->SetTitleFont(42);
   diphotonSR_ptbackground->SetHistogram(diphotonSR_ptbackground_stack_10);
   
   
   TH1D *diphotonSR_pt_stack_1 = new TH1D("diphotonSR_pt_stack_1","diphotonSR_pt",5,0,1);
   diphotonSR_pt_stack_1->SetBinContent(1,3.04452);
   diphotonSR_pt_stack_1->SetBinContent(2,2.89872);
   diphotonSR_pt_stack_1->SetBinContent(3,1.984375);
   diphotonSR_pt_stack_1->SetBinContent(4,1.408585);
   diphotonSR_pt_stack_1->SetBinContent(5,0.7685437);
   diphotonSR_pt_stack_1->SetBinError(1,0.08673883);
   diphotonSR_pt_stack_1->SetBinError(2,0.0846364);
   diphotonSR_pt_stack_1->SetBinError(3,0.07002707);
   diphotonSR_pt_stack_1->SetBinError(4,0.05899913);
   diphotonSR_pt_stack_1->SetBinError(5,0.04358012);
   diphotonSR_pt_stack_1->SetEntries(4089);
   diphotonSR_pt_stack_1->SetDirectory(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#6699ff");
   diphotonSR_pt_stack_1->SetFillColor(ci);

   ci = TColor::GetColor("#000000");
   diphotonSR_pt_stack_1->SetLineColor(ci);
   diphotonSR_pt_stack_1->SetMarkerStyle(20);
   diphotonSR_pt_stack_1->GetXaxis()->SetRange(1,5);
   diphotonSR_pt_stack_1->GetXaxis()->SetLabelFont(42);
   diphotonSR_pt_stack_1->GetXaxis()->SetTitleOffset(1);
   diphotonSR_pt_stack_1->GetXaxis()->SetTitleFont(42);
   diphotonSR_pt_stack_1->GetYaxis()->SetLabelFont(42);
   diphotonSR_pt_stack_1->GetYaxis()->SetTitleFont(42);
   diphotonSR_pt_stack_1->GetZaxis()->SetLabelFont(42);
   diphotonSR_pt_stack_1->GetZaxis()->SetTitleOffset(1);
   diphotonSR_pt_stack_1->GetZaxis()->SetTitleFont(42);
   diphotonSR_ptbackground->Add(diphotonSR_pt_stack_1,"");
   
   TH1D *diphotonSR_pt_stack_2 = new TH1D("diphotonSR_pt_stack_2","diphotonSR_pt",5,0,1);
   diphotonSR_pt_stack_2->SetBinContent(1,0.1724906);
   diphotonSR_pt_stack_2->SetBinContent(2,0.4024781);
   diphotonSR_pt_stack_2->SetBinContent(3,0.1149937);
   diphotonSR_pt_stack_2->SetBinContent(4,0.05749687);
   diphotonSR_pt_stack_2->SetBinError(1,0.09958751);
   diphotonSR_pt_stack_2->SetBinError(2,0.1521224);
   diphotonSR_pt_stack_2->SetBinError(3,0.08131286);
   diphotonSR_pt_stack_2->SetBinError(4,0.05749687);
   diphotonSR_pt_stack_2->SetEntries(13);
   diphotonSR_pt_stack_2->SetDirectory(0);

   ci = TColor::GetColor("#ffff00");
   diphotonSR_pt_stack_2->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   diphotonSR_pt_stack_2->SetLineColor(ci);
   diphotonSR_pt_stack_2->SetMarkerStyle(20);
   diphotonSR_pt_stack_2->SetMarkerSize(0);
   diphotonSR_pt_stack_2->GetXaxis()->SetRange(1,5);
   diphotonSR_pt_stack_2->GetXaxis()->SetLabelFont(42);
   diphotonSR_pt_stack_2->GetXaxis()->SetTitleOffset(1);
   diphotonSR_pt_stack_2->GetXaxis()->SetTitleFont(42);
   diphotonSR_pt_stack_2->GetYaxis()->SetLabelFont(42);
   diphotonSR_pt_stack_2->GetYaxis()->SetTitleFont(42);
   diphotonSR_pt_stack_2->GetZaxis()->SetLabelFont(42);
   diphotonSR_pt_stack_2->GetZaxis()->SetTitleOffset(1);
   diphotonSR_pt_stack_2->GetZaxis()->SetTitleFont(42);
   diphotonSR_ptbackground->Add(diphotonSR_pt_stack_2,"");
   
   TH1D *diphotonSR_pt_stack_3 = new TH1D("diphotonSR_pt_stack_3","diphotonSR_pt",5,0,1);
   diphotonSR_pt_stack_3->SetBinContent(1,0.2887305);
   diphotonSR_pt_stack_3->SetBinContent(2,0.2165479);
   diphotonSR_pt_stack_3->SetBinContent(3,0.2887305);
   diphotonSR_pt_stack_3->SetBinContent(4,0.1443652);
   diphotonSR_pt_stack_3->SetBinContent(5,0.2165479);
   diphotonSR_pt_stack_3->SetBinError(1,0.1443652);
   diphotonSR_pt_stack_3->SetBinError(2,0.125024);
   diphotonSR_pt_stack_3->SetBinError(3,0.1443652);
   diphotonSR_pt_stack_3->SetBinError(4,0.1020816);
   diphotonSR_pt_stack_3->SetBinError(5,0.125024);
   diphotonSR_pt_stack_3->SetEntries(16);
   diphotonSR_pt_stack_3->SetDirectory(0);

   ci = TColor::GetColor("#ffff00");
   diphotonSR_pt_stack_3->SetFillColor(ci);

   ci = TColor::GetColor("#000000");
   diphotonSR_pt_stack_3->SetLineColor(ci);
   diphotonSR_pt_stack_3->SetMarkerStyle(20);
   diphotonSR_pt_stack_3->SetMarkerSize(0);
   diphotonSR_pt_stack_3->GetXaxis()->SetRange(1,5);
   diphotonSR_pt_stack_3->GetXaxis()->SetLabelFont(42);
   diphotonSR_pt_stack_3->GetXaxis()->SetTitleOffset(1);
   diphotonSR_pt_stack_3->GetXaxis()->SetTitleFont(42);
   diphotonSR_pt_stack_3->GetYaxis()->SetLabelFont(42);
   diphotonSR_pt_stack_3->GetYaxis()->SetTitleFont(42);
   diphotonSR_pt_stack_3->GetZaxis()->SetLabelFont(42);
   diphotonSR_pt_stack_3->GetZaxis()->SetTitleOffset(1);
   diphotonSR_pt_stack_3->GetZaxis()->SetTitleFont(42);
   diphotonSR_ptbackground->Add(diphotonSR_pt_stack_3,"");
   
   TH1D *diphotonSR_pt_stack_4 = new TH1D("diphotonSR_pt_stack_4","diphotonSR_pt",5,0,1);
   diphotonSR_pt_stack_4->SetBinContent(1,6.532591);
   diphotonSR_pt_stack_4->SetBinContent(2,3.7725);
   diphotonSR_pt_stack_4->SetBinContent(3,1.628906);
   diphotonSR_pt_stack_4->SetBinContent(4,0.6051837);
   diphotonSR_pt_stack_4->SetBinContent(5,0.2827961);
   diphotonSR_pt_stack_4->SetBinError(1,0.1922182);
   diphotonSR_pt_stack_4->SetBinError(2,0.1460718);
   diphotonSR_pt_stack_4->SetBinError(3,0.09598419);
   diphotonSR_pt_stack_4->SetBinError(4,0.05850532);
   diphotonSR_pt_stack_4->SetBinError(5,0.03999341);
   diphotonSR_pt_stack_4->SetEntries(2267);
   diphotonSR_pt_stack_4->SetDirectory(0);

   ci = TColor::GetColor("#ff9933");
   diphotonSR_pt_stack_4->SetFillColor(ci);

   ci = TColor::GetColor("#000000");
   diphotonSR_pt_stack_4->SetLineColor(ci);
   diphotonSR_pt_stack_4->SetMarkerStyle(20);
   diphotonSR_pt_stack_4->GetXaxis()->SetRange(1,5);
   diphotonSR_pt_stack_4->GetXaxis()->SetLabelFont(42);
   diphotonSR_pt_stack_4->GetXaxis()->SetTitleOffset(1);
   diphotonSR_pt_stack_4->GetXaxis()->SetTitleFont(42);
   diphotonSR_pt_stack_4->GetYaxis()->SetLabelFont(42);
   diphotonSR_pt_stack_4->GetYaxis()->SetTitleFont(42);
   diphotonSR_pt_stack_4->GetZaxis()->SetLabelFont(42);
   diphotonSR_pt_stack_4->GetZaxis()->SetTitleOffset(1);
   diphotonSR_pt_stack_4->GetZaxis()->SetTitleFont(42);
   diphotonSR_ptbackground->Add(diphotonSR_pt_stack_4,"");
   diphotonSR_ptbackground->Draw("hist");
   
   auto diphotonSR_ptdata = new THStack();
   diphotonSR_ptdata->SetName("diphotonSR_ptdata");
   diphotonSR_ptdata->SetTitle("");
   diphotonSR_ptdata->SetMaximum(18);
   
   TH1F *diphotonSR_ptdata_stack_11 = new TH1F("diphotonSR_ptdata_stack_11","",5,0,1);
   diphotonSR_ptdata_stack_11->SetMinimum(0);
   diphotonSR_ptdata_stack_11->SetMaximum(18);
   diphotonSR_ptdata_stack_11->SetDirectory(0);
   diphotonSR_ptdata_stack_11->SetStats(0);
   diphotonSR_ptdata_stack_11->SetLineStyle(0);
   diphotonSR_ptdata_stack_11->GetXaxis()->SetTitle("p_{T}^{#gamma#gamma} (GeV)");
   diphotonSR_ptdata_stack_11->GetXaxis()->SetLabelFont(42);
   diphotonSR_ptdata_stack_11->GetXaxis()->SetLabelOffset(0.007);
   diphotonSR_ptdata_stack_11->GetXaxis()->SetLabelSize(0.06);
   diphotonSR_ptdata_stack_11->GetXaxis()->SetTitleSize(0.06);
   diphotonSR_ptdata_stack_11->GetXaxis()->SetTitleOffset(1.7);
   diphotonSR_ptdata_stack_11->GetXaxis()->SetTitleFont(42);
   diphotonSR_ptdata_stack_11->GetYaxis()->SetTitle("Events / 0.2 GeV");
   diphotonSR_ptdata_stack_11->GetYaxis()->CenterTitle(true);
   diphotonSR_ptdata_stack_11->GetYaxis()->SetNdivisions(505);
   diphotonSR_ptdata_stack_11->GetYaxis()->SetLabelFont(42);
   diphotonSR_ptdata_stack_11->GetYaxis()->SetLabelOffset(0.007);
   diphotonSR_ptdata_stack_11->GetYaxis()->SetLabelSize(0.06);
   diphotonSR_ptdata_stack_11->GetYaxis()->SetTitleSize(0.05);
   diphotonSR_ptdata_stack_11->GetYaxis()->SetTitleOffset(1.5);
   diphotonSR_ptdata_stack_11->GetYaxis()->SetTitleFont(42);
   diphotonSR_ptdata_stack_11->GetZaxis()->SetLabelFont(42);
   diphotonSR_ptdata_stack_11->GetZaxis()->SetLabelOffset(0.007);
   diphotonSR_ptdata_stack_11->GetZaxis()->SetLabelSize(0.05);
   diphotonSR_ptdata_stack_11->GetZaxis()->SetTitleSize(0.06);
   diphotonSR_ptdata_stack_11->GetZaxis()->SetTitleOffset(1);
   diphotonSR_ptdata_stack_11->GetZaxis()->SetTitleFont(42);
   diphotonSR_ptdata->SetHistogram(diphotonSR_ptdata_stack_11);
   
   
   diphotonSR_pt_stack_1 = new TH1D("diphotonSR_pt_stack_1","diphotonSR_pt",5,0,1);
   diphotonSR_pt_stack_1->SetBinContent(1,10);
   diphotonSR_pt_stack_1->SetBinContent(2,7);
   diphotonSR_pt_stack_1->SetBinContent(3,4);
   diphotonSR_pt_stack_1->SetBinContent(4,3);
   diphotonSR_pt_stack_1->SetBinContent(5,2);
   diphotonSR_pt_stack_1->SetBinError(1,3.162278);
   diphotonSR_pt_stack_1->SetBinError(2,2.645751);
   diphotonSR_pt_stack_1->SetBinError(3,2);
   diphotonSR_pt_stack_1->SetBinError(4,1.732051);
   diphotonSR_pt_stack_1->SetBinError(5,1.414214);
   diphotonSR_pt_stack_1->SetEntries(26);
   diphotonSR_pt_stack_1->SetDirectory(0);

   ci = 1488;
   color = new TColor(ci, 0, 1, 0, " ", 0);
   diphotonSR_pt_stack_1->SetFillColor(ci);

   ci = TColor::GetColor("#000000");
   diphotonSR_pt_stack_1->SetLineColor(ci);
   diphotonSR_pt_stack_1->SetMarkerStyle(20);
   diphotonSR_pt_stack_1->GetXaxis()->SetRange(1,5);
   diphotonSR_pt_stack_1->GetXaxis()->SetLabelFont(42);
   diphotonSR_pt_stack_1->GetXaxis()->SetTitleOffset(1);
   diphotonSR_pt_stack_1->GetXaxis()->SetTitleFont(42);
   diphotonSR_pt_stack_1->GetYaxis()->SetLabelFont(42);
   diphotonSR_pt_stack_1->GetYaxis()->SetTitleFont(42);
   diphotonSR_pt_stack_1->GetZaxis()->SetLabelFont(42);
   diphotonSR_pt_stack_1->GetZaxis()->SetTitleOffset(1);
   diphotonSR_pt_stack_1->GetZaxis()->SetTitleFont(42);
   diphotonSR_ptdata->Add(diphotonSR_pt_stack_1,"");
   diphotonSR_ptdata->Draw("nostack pe0 same");
   
   TH1D *backgrounds_unc_diphotonSR_pt__10 = new TH1D("backgrounds_unc_diphotonSR_pt__10","diphotonSR_pt",5,0,1);
   backgrounds_unc_diphotonSR_pt__10->SetBinContent(1,10.03833);
   backgrounds_unc_diphotonSR_pt__10->SetBinContent(2,7.290246);
   backgrounds_unc_diphotonSR_pt__10->SetBinContent(3,4.017005);
   backgrounds_unc_diphotonSR_pt__10->SetBinContent(4,2.215631);
   backgrounds_unc_diphotonSR_pt__10->SetBinContent(5,1.267888);
   backgrounds_unc_diphotonSR_pt__10->SetBinError(1,2.325051);
   backgrounds_unc_diphotonSR_pt__10->SetBinError(2,1.696698);
   backgrounds_unc_diphotonSR_pt__10->SetBinError(3,0.9461404);
   backgrounds_unc_diphotonSR_pt__10->SetBinError(4,0.5294502);
   backgrounds_unc_diphotonSR_pt__10->SetBinError(5,0.3227515);
   backgrounds_unc_diphotonSR_pt__10->SetEntries(6385);

   ci = 1558;
   color = new TColor(ci, 0, 0, 0, " ", 0.3);
   backgrounds_unc_diphotonSR_pt__10->SetFillColor(ci);
   backgrounds_unc_diphotonSR_pt__10->SetFillStyle(3244);
   backgrounds_unc_diphotonSR_pt__10->SetMarkerStyle(20);
   backgrounds_unc_diphotonSR_pt__10->SetMarkerSize(0);
   backgrounds_unc_diphotonSR_pt__10->GetXaxis()->SetRange(1,5);
   backgrounds_unc_diphotonSR_pt__10->GetXaxis()->SetLabelFont(42);
   backgrounds_unc_diphotonSR_pt__10->GetXaxis()->SetTitleOffset(1);
   backgrounds_unc_diphotonSR_pt__10->GetXaxis()->SetTitleFont(42);
   backgrounds_unc_diphotonSR_pt__10->GetYaxis()->SetLabelFont(42);
   backgrounds_unc_diphotonSR_pt__10->GetYaxis()->SetTitleFont(42);
   backgrounds_unc_diphotonSR_pt__10->GetZaxis()->SetLabelFont(42);
   backgrounds_unc_diphotonSR_pt__10->GetZaxis()->SetTitleOffset(1);
   backgrounds_unc_diphotonSR_pt__10->GetZaxis()->SetTitleFont(42);
   backgrounds_unc_diphotonSR_pt__10->Draw("same e2");
   
   TLegend *leg = new TLegend(0.62,0.7,0.82,0.75,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.035);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("diphotonSR_pt_stack_3","#gamma#gamma#rightarrowe^{+}e^{-}","f");

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
   
   leg = new TLegend(0.72,0.75,0.82,0.8,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.035);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   leg->Draw();
   
   leg = new TLegend(0.62,0.8,0.82,0.9,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.035);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   entry=leg->AddEntry("diphotonSR_pt_stack_1","Data","pl");

   ci = TColor::GetColor("#000000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   leg = new TLegend(0.62,0.75,0.82,0.8,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.035);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   entry=leg->AddEntry("diphotonSR_pt_stack_4","#gamma#gamma#rightarrow#gamma#gamma","f");

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
   
   leg = new TLegend(0.62,0.65,0.82,0.7,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.035);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   entry=leg->AddEntry("diphotonSR_pt_stack_1","gg#rightarrow#gamma#gamma","f");

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
   
   TH1F *diphotonSR_ptbackground_copy__11 = new TH1F("diphotonSR_ptbackground_copy__11","",5,0,1);
   diphotonSR_ptbackground_copy__11->SetMinimum(0);
   diphotonSR_ptbackground_copy__11->SetMaximum(18);
   diphotonSR_ptbackground_copy__11->SetDirectory(0);
   diphotonSR_ptbackground_copy__11->SetStats(0);
   diphotonSR_ptbackground_copy__11->SetLineStyle(0);
   diphotonSR_ptbackground_copy__11->GetXaxis()->SetTitle("p_{T}^{#gamma#gamma} (GeV)");
   diphotonSR_ptbackground_copy__11->GetXaxis()->SetLabelFont(42);
   diphotonSR_ptbackground_copy__11->GetXaxis()->SetLabelOffset(0.007);
   diphotonSR_ptbackground_copy__11->GetXaxis()->SetLabelSize(0.06);
   diphotonSR_ptbackground_copy__11->GetXaxis()->SetTitleSize(0.06);
   diphotonSR_ptbackground_copy__11->GetXaxis()->SetTitleOffset(1.7);
   diphotonSR_ptbackground_copy__11->GetXaxis()->SetTitleFont(42);
   diphotonSR_ptbackground_copy__11->GetYaxis()->SetTitle("Events / 0.2 GeV");
   diphotonSR_ptbackground_copy__11->GetYaxis()->CenterTitle(true);
   diphotonSR_ptbackground_copy__11->GetYaxis()->SetNdivisions(505);
   diphotonSR_ptbackground_copy__11->GetYaxis()->SetLabelFont(42);
   diphotonSR_ptbackground_copy__11->GetYaxis()->SetLabelOffset(0.007);
   diphotonSR_ptbackground_copy__11->GetYaxis()->SetLabelSize(0.06);
   diphotonSR_ptbackground_copy__11->GetYaxis()->SetTitleSize(0.05);
   diphotonSR_ptbackground_copy__11->GetYaxis()->SetTitleOffset(1.5);
   diphotonSR_ptbackground_copy__11->GetYaxis()->SetTitleFont(42);
   diphotonSR_ptbackground_copy__11->GetZaxis()->SetLabelFont(42);
   diphotonSR_ptbackground_copy__11->GetZaxis()->SetLabelOffset(0.007);
   diphotonSR_ptbackground_copy__11->GetZaxis()->SetLabelSize(0.05);
   diphotonSR_ptbackground_copy__11->GetZaxis()->SetTitleSize(0.06);
   diphotonSR_ptbackground_copy__11->GetZaxis()->SetTitleOffset(1);
   diphotonSR_ptbackground_copy__11->GetZaxis()->SetTitleFont(42);
   diphotonSR_ptbackground_copy__11->Draw("sameaxis");
   diphotonSR_pt_1->Modified();
   diphotonSR_pt->cd();
  
// ------------>Primitives in pad: diphotonSR_pt_2
   TPad *diphotonSR_pt_2 = new TPad("diphotonSR_pt_2", "diphotonSR_pt_2",0,0,1,0.3);
   diphotonSR_pt_2->Draw();
   diphotonSR_pt_2->cd();
   diphotonSR_pt_2->Range(-0.231884,-0.8571429,1.217391,2);
   diphotonSR_pt_2->SetFillColor(0);
   diphotonSR_pt_2->SetBorderMode(0);
   diphotonSR_pt_2->SetBorderSize(2);
   diphotonSR_pt_2->SetLeftMargin(0.16);
   diphotonSR_pt_2->SetRightMargin(0.15);
   diphotonSR_pt_2->SetTopMargin(0);
   diphotonSR_pt_2->SetBottomMargin(0.3);
   diphotonSR_pt_2->SetFrameFillStyle(0);
   diphotonSR_pt_2->SetFrameBorderMode(0);
   diphotonSR_pt_2->SetFrameFillStyle(0);
   diphotonSR_pt_2->SetFrameBorderMode(0);
   
   auto ratio_stack_diphotonSR_pt = new THStack();
   ratio_stack_diphotonSR_pt->SetName("ratio_stack_diphotonSR_pt");
   ratio_stack_diphotonSR_pt->SetTitle("");
   ratio_stack_diphotonSR_pt->SetMinimum(0);
   ratio_stack_diphotonSR_pt->SetMaximum(2);
   
   TH1F *ratio_stack_diphotonSR_pt_stack_12 = new TH1F("ratio_stack_diphotonSR_pt_stack_12","",5,0,1);
   ratio_stack_diphotonSR_pt_stack_12->SetMinimum(0);
   ratio_stack_diphotonSR_pt_stack_12->SetMaximum(2);
   ratio_stack_diphotonSR_pt_stack_12->SetDirectory(0);
   ratio_stack_diphotonSR_pt_stack_12->SetStats(0);
   ratio_stack_diphotonSR_pt_stack_12->SetLineStyle(0);
   ratio_stack_diphotonSR_pt_stack_12->GetXaxis()->SetTitle("p_{T}^{#gamma#gamma} (GeV)");
   ratio_stack_diphotonSR_pt_stack_12->GetXaxis()->SetLabelFont(42);
   ratio_stack_diphotonSR_pt_stack_12->GetXaxis()->SetLabelOffset(0.007);
   ratio_stack_diphotonSR_pt_stack_12->GetXaxis()->SetLabelSize(0.1);
   ratio_stack_diphotonSR_pt_stack_12->GetXaxis()->SetTitleSize(0.12);
   ratio_stack_diphotonSR_pt_stack_12->GetXaxis()->SetTitleOffset(1);
   ratio_stack_diphotonSR_pt_stack_12->GetXaxis()->SetTitleFont(42);
   ratio_stack_diphotonSR_pt_stack_12->GetYaxis()->SetTitle("Data/MC");
   ratio_stack_diphotonSR_pt_stack_12->GetYaxis()->CenterTitle(true);
   ratio_stack_diphotonSR_pt_stack_12->GetYaxis()->SetNdivisions(505);
   ratio_stack_diphotonSR_pt_stack_12->GetYaxis()->SetLabelFont(42);
   ratio_stack_diphotonSR_pt_stack_12->GetYaxis()->SetLabelOffset(0.007);
   ratio_stack_diphotonSR_pt_stack_12->GetYaxis()->SetLabelSize(0.1);
   ratio_stack_diphotonSR_pt_stack_12->GetYaxis()->SetTitleSize(0.1);
   ratio_stack_diphotonSR_pt_stack_12->GetYaxis()->SetTitleOffset(0.5);
   ratio_stack_diphotonSR_pt_stack_12->GetYaxis()->SetTitleFont(42);
   ratio_stack_diphotonSR_pt_stack_12->GetZaxis()->SetLabelFont(42);
   ratio_stack_diphotonSR_pt_stack_12->GetZaxis()->SetLabelOffset(0.007);
   ratio_stack_diphotonSR_pt_stack_12->GetZaxis()->SetLabelSize(0.05);
   ratio_stack_diphotonSR_pt_stack_12->GetZaxis()->SetTitleSize(0.06);
   ratio_stack_diphotonSR_pt_stack_12->GetZaxis()->SetTitleOffset(1);
   ratio_stack_diphotonSR_pt_stack_12->GetZaxis()->SetTitleFont(42);
   ratio_stack_diphotonSR_pt->SetHistogram(ratio_stack_diphotonSR_pt_stack_12);
   
   
   TH1D *ratio_diphotonSR_pt_stack_1 = new TH1D("ratio_diphotonSR_pt_stack_1","diphotonSR_pt",5,0,1);
   ratio_diphotonSR_pt_stack_1->SetBinContent(1,0.9961814);
   ratio_diphotonSR_pt_stack_1->SetBinContent(2,0.9601871);
   ratio_diphotonSR_pt_stack_1->SetBinContent(3,0.9957668);
   ratio_diphotonSR_pt_stack_1->SetBinContent(4,1.354016);
   ratio_diphotonSR_pt_stack_1->SetBinContent(5,1.577427);
   ratio_diphotonSR_pt_stack_1->SetBinError(1,0.316194);
   ratio_diphotonSR_pt_stack_1->SetBinError(2,0.3645208);
   ratio_diphotonSR_pt_stack_1->SetBinError(3,0.5004421);
   ratio_diphotonSR_pt_stack_1->SetBinError(4,0.7866541);
   ratio_diphotonSR_pt_stack_1->SetBinError(5,1.128604);
   ratio_diphotonSR_pt_stack_1->SetEntries(14.57003);

   ci = 1488;
   color = new TColor(ci, 0, 1, 0, " ", 0);
   ratio_diphotonSR_pt_stack_1->SetFillColor(ci);

   ci = TColor::GetColor("#000000");
   ratio_diphotonSR_pt_stack_1->SetLineColor(ci);
   ratio_diphotonSR_pt_stack_1->SetMarkerStyle(20);
   ratio_diphotonSR_pt_stack_1->GetXaxis()->SetRange(1,5);
   ratio_diphotonSR_pt_stack_1->GetXaxis()->SetLabelFont(42);
   ratio_diphotonSR_pt_stack_1->GetXaxis()->SetTitleOffset(1);
   ratio_diphotonSR_pt_stack_1->GetXaxis()->SetTitleFont(42);
   ratio_diphotonSR_pt_stack_1->GetYaxis()->SetLabelFont(42);
   ratio_diphotonSR_pt_stack_1->GetYaxis()->SetTitleFont(42);
   ratio_diphotonSR_pt_stack_1->GetZaxis()->SetLabelFont(42);
   ratio_diphotonSR_pt_stack_1->GetZaxis()->SetTitleOffset(1);
   ratio_diphotonSR_pt_stack_1->GetZaxis()->SetTitleFont(42);
   ratio_stack_diphotonSR_pt->Add(ratio_diphotonSR_pt_stack_1,"");
   ratio_stack_diphotonSR_pt->Draw("p");
   TLine *line = new TLine(0,1,1,1);
   line->SetLineStyle(2);
   line->Draw();
   
   TH1D *ratio_uncertainty_diphotonSR_pt__12 = new TH1D("ratio_uncertainty_diphotonSR_pt__12","diphotonSR_pt",5,0,1);
   ratio_uncertainty_diphotonSR_pt__12->SetBinContent(1,1);
   ratio_uncertainty_diphotonSR_pt__12->SetBinContent(2,1);
   ratio_uncertainty_diphotonSR_pt__12->SetBinContent(3,1);
   ratio_uncertainty_diphotonSR_pt__12->SetBinContent(4,1);
   ratio_uncertainty_diphotonSR_pt__12->SetBinContent(5,1);
   ratio_uncertainty_diphotonSR_pt__12->SetBinError(1,0.3275563);
   ratio_uncertainty_diphotonSR_pt__12->SetBinError(2,0.3291376);
   ratio_uncertainty_diphotonSR_pt__12->SetBinError(3,0.3330951);
   ratio_uncertainty_diphotonSR_pt__12->SetBinError(4,0.3379424);
   ratio_uncertainty_diphotonSR_pt__12->SetBinError(5,0.36);
   ratio_uncertainty_diphotonSR_pt__12->SetEntries(43.83027);

   ci = 1558;
   color = new TColor(ci, 0, 0, 0, " ", 0.3);
   ratio_uncertainty_diphotonSR_pt__12->SetFillColor(ci);
   ratio_uncertainty_diphotonSR_pt__12->SetFillStyle(3244);
   ratio_uncertainty_diphotonSR_pt__12->SetMarkerStyle(20);
   ratio_uncertainty_diphotonSR_pt__12->SetMarkerSize(0);
   ratio_uncertainty_diphotonSR_pt__12->GetXaxis()->SetRange(1,5);
   ratio_uncertainty_diphotonSR_pt__12->GetXaxis()->SetLabelFont(42);
   ratio_uncertainty_diphotonSR_pt__12->GetXaxis()->SetTitleOffset(1);
   ratio_uncertainty_diphotonSR_pt__12->GetXaxis()->SetTitleFont(42);
   ratio_uncertainty_diphotonSR_pt__12->GetYaxis()->SetLabelFont(42);
   ratio_uncertainty_diphotonSR_pt__12->GetYaxis()->SetTitleFont(42);
   ratio_uncertainty_diphotonSR_pt__12->GetZaxis()->SetLabelFont(42);
   ratio_uncertainty_diphotonSR_pt__12->GetZaxis()->SetTitleOffset(1);
   ratio_uncertainty_diphotonSR_pt__12->GetZaxis()->SetTitleFont(42);
   ratio_uncertainty_diphotonSR_pt__12->Draw("same e2");
   diphotonSR_pt_2->Modified();
   diphotonSR_pt->cd();
   TLatex *   tex = new TLatex(0.85,0.928,"1.6 nb^{-1} ( PbPb @ 5.02 TeV)");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextFont(42);
   tex->SetTextSize(0.036);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.19105,0.9176,"CMS");
   tex->SetTextAlign(13);
   tex->SetTextFont(61);
   tex->SetTextSize(0.045);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.19105,0.8636,"Preliminary");
   tex->SetTextAlign(13);
   tex->SetTextFont(52);
   tex->SetTextSize(0.0342);
   tex->SetLineWidth(2);
   tex->Draw();
   diphotonSR_pt->Modified();
   diphotonSR_pt->cd();
   diphotonSR_pt->SetSelected(diphotonSR_pt);
   diphotonSR_pt->SaveAs("Figure_006_b.pdf");
}
