#ifdef __CLING__
#pragma cling optimize(0)
#endif
void plot_fig_6_g()
{
   gROOT->SetBatch(kTRUE);
//=========Macro generated from canvas: eventSR3_cosThetaStar/eventSR3_cosThetaStar
//=========  (Sun Mar 31 12:51:37 2024) by ROOT version 6.26/08
   TCanvas *eventSR3_cosThetaStar = new TCanvas("eventSR3_cosThetaStar", "eventSR3_cosThetaStar",0,0,800,600);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   eventSR3_cosThetaStar->SetHighLightColor(2);
   eventSR3_cosThetaStar->Range(0,0,1,1);
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
   TPad *eventSR3_cosThetaStar_1 = new TPad("eventSR3_cosThetaStar_1", "eventSR3_cosThetaStar_1",0,0.3,1,1);
   eventSR3_cosThetaStar_1->Draw();
   eventSR3_cosThetaStar_1->cd();
   eventSR3_cosThetaStar_1->Range(-0.231884,0,1.217391,27.47253);
   eventSR3_cosThetaStar_1->SetFillColor(0);
   eventSR3_cosThetaStar_1->SetBorderMode(0);
   eventSR3_cosThetaStar_1->SetBorderSize(2);
   eventSR3_cosThetaStar_1->SetLeftMargin(0.16);
   eventSR3_cosThetaStar_1->SetRightMargin(0.15);
   eventSR3_cosThetaStar_1->SetBottomMargin(0);
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
   
   TH1F *eventSR3_cosThetaStarbackground_stack_19 = new TH1F("eventSR3_cosThetaStarbackground_stack_19","",3,0,1);
   eventSR3_cosThetaStarbackground_stack_19->SetMinimum(0);
   eventSR3_cosThetaStarbackground_stack_19->SetMaximum(25);
   eventSR3_cosThetaStarbackground_stack_19->SetDirectory(0);
   eventSR3_cosThetaStarbackground_stack_19->SetStats(0);
   eventSR3_cosThetaStarbackground_stack_19->SetLineStyle(0);
   eventSR3_cosThetaStarbackground_stack_19->GetXaxis()->SetTitle("|cos #theta*|");
   eventSR3_cosThetaStarbackground_stack_19->GetXaxis()->SetLabelFont(42);
   eventSR3_cosThetaStarbackground_stack_19->GetXaxis()->SetLabelOffset(0.007);
   eventSR3_cosThetaStarbackground_stack_19->GetXaxis()->SetLabelSize(0.06);
   eventSR3_cosThetaStarbackground_stack_19->GetXaxis()->SetTitleSize(0.06);
   eventSR3_cosThetaStarbackground_stack_19->GetXaxis()->SetTitleOffset(1.7);
   eventSR3_cosThetaStarbackground_stack_19->GetXaxis()->SetTitleFont(42);
   eventSR3_cosThetaStarbackground_stack_19->GetYaxis()->SetTitle("Events / 0.33");
   eventSR3_cosThetaStarbackground_stack_19->GetYaxis()->CenterTitle(true);
   eventSR3_cosThetaStarbackground_stack_19->GetYaxis()->SetNdivisions(505);
   eventSR3_cosThetaStarbackground_stack_19->GetYaxis()->SetLabelFont(42);
   eventSR3_cosThetaStarbackground_stack_19->GetYaxis()->SetLabelOffset(0.007);
   eventSR3_cosThetaStarbackground_stack_19->GetYaxis()->SetLabelSize(0.06);
   eventSR3_cosThetaStarbackground_stack_19->GetYaxis()->SetTitleSize(0.05);
   eventSR3_cosThetaStarbackground_stack_19->GetYaxis()->SetTitleOffset(1.5);
   eventSR3_cosThetaStarbackground_stack_19->GetYaxis()->SetTitleFont(42);
   eventSR3_cosThetaStarbackground_stack_19->GetZaxis()->SetLabelFont(42);
   eventSR3_cosThetaStarbackground_stack_19->GetZaxis()->SetLabelOffset(0.007);
   eventSR3_cosThetaStarbackground_stack_19->GetZaxis()->SetLabelSize(0.05);
   eventSR3_cosThetaStarbackground_stack_19->GetZaxis()->SetTitleSize(0.06);
   eventSR3_cosThetaStarbackground_stack_19->GetZaxis()->SetTitleOffset(1);
   eventSR3_cosThetaStarbackground_stack_19->GetZaxis()->SetTitleFont(42);
   eventSR3_cosThetaStarbackground->SetHistogram(eventSR3_cosThetaStarbackground_stack_19);
   
   
   TH1D *eventSR3_cosThetaStar_stack_1 = new TH1D("eventSR3_cosThetaStar_stack_1","eventSR3_cosThetaStar",3,0,1);
   eventSR3_cosThetaStar_stack_1->SetBinContent(1,5.86169);
   eventSR3_cosThetaStar_stack_1->SetBinContent(2,3.627724);
   eventSR3_cosThetaStar_stack_1->SetBinContent(3,0.6153292);
   eventSR3_cosThetaStar_stack_1->SetBinError(1,0.1203554);
   eventSR3_cosThetaStar_stack_1->SetBinError(2,0.09468283);
   eventSR3_cosThetaStar_stack_1->SetBinError(3,0.0389949);
   eventSR3_cosThetaStar_stack_1->SetEntries(4089);
   eventSR3_cosThetaStar_stack_1->SetDirectory(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#6699ff");
   eventSR3_cosThetaStar_stack_1->SetFillColor(ci);

   ci = TColor::GetColor("#000000");
   eventSR3_cosThetaStar_stack_1->SetLineColor(ci);
   eventSR3_cosThetaStar_stack_1->SetMarkerStyle(20);
   eventSR3_cosThetaStar_stack_1->GetXaxis()->SetRange(1,3);
   eventSR3_cosThetaStar_stack_1->GetXaxis()->SetLabelFont(42);
   eventSR3_cosThetaStar_stack_1->GetXaxis()->SetTitleOffset(1);
   eventSR3_cosThetaStar_stack_1->GetXaxis()->SetTitleFont(42);
   eventSR3_cosThetaStar_stack_1->GetYaxis()->SetLabelFont(42);
   eventSR3_cosThetaStar_stack_1->GetYaxis()->SetTitleFont(42);
   eventSR3_cosThetaStar_stack_1->GetZaxis()->SetLabelFont(42);
   eventSR3_cosThetaStar_stack_1->GetZaxis()->SetTitleOffset(1);
   eventSR3_cosThetaStar_stack_1->GetZaxis()->SetTitleFont(42);
   eventSR3_cosThetaStarbackground->Add(eventSR3_cosThetaStar_stack_1,"");
   
   TH1D *eventSR3_cosThetaStar_stack_2 = new TH1D("eventSR3_cosThetaStar_stack_2","eventSR3_cosThetaStar",3,0,1);
   eventSR3_cosThetaStar_stack_2->SetBinContent(1,0.1149937);
   eventSR3_cosThetaStar_stack_2->SetBinContent(2,0.5174719);
   eventSR3_cosThetaStar_stack_2->SetBinContent(3,0.1149937);
   eventSR3_cosThetaStar_stack_2->SetBinError(1,0.08131286);
   eventSR3_cosThetaStar_stack_2->SetBinError(2,0.1724906);
   eventSR3_cosThetaStar_stack_2->SetBinError(3,0.08131286);
   eventSR3_cosThetaStar_stack_2->SetEntries(13);
   eventSR3_cosThetaStar_stack_2->SetDirectory(0);

   ci = TColor::GetColor("#ffff00");
   eventSR3_cosThetaStar_stack_2->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   eventSR3_cosThetaStar_stack_2->SetLineColor(ci);
   eventSR3_cosThetaStar_stack_2->SetMarkerStyle(20);
   eventSR3_cosThetaStar_stack_2->SetMarkerSize(0);
   eventSR3_cosThetaStar_stack_2->GetXaxis()->SetRange(1,3);
   eventSR3_cosThetaStar_stack_2->GetXaxis()->SetLabelFont(42);
   eventSR3_cosThetaStar_stack_2->GetXaxis()->SetTitleOffset(1);
   eventSR3_cosThetaStar_stack_2->GetXaxis()->SetTitleFont(42);
   eventSR3_cosThetaStar_stack_2->GetYaxis()->SetLabelFont(42);
   eventSR3_cosThetaStar_stack_2->GetYaxis()->SetTitleFont(42);
   eventSR3_cosThetaStar_stack_2->GetZaxis()->SetLabelFont(42);
   eventSR3_cosThetaStar_stack_2->GetZaxis()->SetTitleOffset(1);
   eventSR3_cosThetaStar_stack_2->GetZaxis()->SetTitleFont(42);
   eventSR3_cosThetaStarbackground->Add(eventSR3_cosThetaStar_stack_2,"");
   
   TH1D *eventSR3_cosThetaStar_stack_3 = new TH1D("eventSR3_cosThetaStar_stack_3","eventSR3_cosThetaStar",3,0,1);
   eventSR3_cosThetaStar_stack_3->SetBinContent(1,0.5774609);
   eventSR3_cosThetaStar_stack_3->SetBinContent(2,0.2165479);
   eventSR3_cosThetaStar_stack_3->SetBinContent(3,0.3609131);
   eventSR3_cosThetaStar_stack_3->SetBinError(1,0.2041633);
   eventSR3_cosThetaStar_stack_3->SetBinError(2,0.125024);
   eventSR3_cosThetaStar_stack_3->SetBinError(3,0.1614052);
   eventSR3_cosThetaStar_stack_3->SetEntries(16);
   eventSR3_cosThetaStar_stack_3->SetDirectory(0);

   ci = TColor::GetColor("#ffff00");
   eventSR3_cosThetaStar_stack_3->SetFillColor(ci);

   ci = TColor::GetColor("#000000");
   eventSR3_cosThetaStar_stack_3->SetLineColor(ci);
   eventSR3_cosThetaStar_stack_3->SetMarkerStyle(20);
   eventSR3_cosThetaStar_stack_3->SetMarkerSize(0);
   eventSR3_cosThetaStar_stack_3->GetXaxis()->SetRange(1,3);
   eventSR3_cosThetaStar_stack_3->GetXaxis()->SetLabelFont(42);
   eventSR3_cosThetaStar_stack_3->GetXaxis()->SetTitleOffset(1);
   eventSR3_cosThetaStar_stack_3->GetXaxis()->SetTitleFont(42);
   eventSR3_cosThetaStar_stack_3->GetYaxis()->SetLabelFont(42);
   eventSR3_cosThetaStar_stack_3->GetYaxis()->SetTitleFont(42);
   eventSR3_cosThetaStar_stack_3->GetZaxis()->SetLabelFont(42);
   eventSR3_cosThetaStar_stack_3->GetZaxis()->SetTitleOffset(1);
   eventSR3_cosThetaStar_stack_3->GetZaxis()->SetTitleFont(42);
   eventSR3_cosThetaStarbackground->Add(eventSR3_cosThetaStar_stack_3,"");
   
   TH1D *eventSR3_cosThetaStar_stack_4 = new TH1D("eventSR3_cosThetaStar_stack_4","eventSR3_cosThetaStar",3,0,1);
   eventSR3_cosThetaStar_stack_4->SetBinContent(1,6.170612);
   eventSR3_cosThetaStar_stack_4->SetBinContent(2,5.095986);
   eventSR3_cosThetaStar_stack_4->SetBinContent(3,1.555379);
   eventSR3_cosThetaStar_stack_4->SetBinError(1,0.1868168);
   eventSR3_cosThetaStar_stack_4->SetBinError(2,0.1697719);
   eventSR3_cosThetaStar_stack_4->SetBinError(3,0.09379287);
   eventSR3_cosThetaStar_stack_4->SetEntries(2267);
   eventSR3_cosThetaStar_stack_4->SetDirectory(0);

   ci = TColor::GetColor("#ff9933");
   eventSR3_cosThetaStar_stack_4->SetFillColor(ci);

   ci = TColor::GetColor("#000000");
   eventSR3_cosThetaStar_stack_4->SetLineColor(ci);
   eventSR3_cosThetaStar_stack_4->SetMarkerStyle(20);
   eventSR3_cosThetaStar_stack_4->GetXaxis()->SetRange(1,3);
   eventSR3_cosThetaStar_stack_4->GetXaxis()->SetLabelFont(42);
   eventSR3_cosThetaStar_stack_4->GetXaxis()->SetTitleOffset(1);
   eventSR3_cosThetaStar_stack_4->GetXaxis()->SetTitleFont(42);
   eventSR3_cosThetaStar_stack_4->GetYaxis()->SetLabelFont(42);
   eventSR3_cosThetaStar_stack_4->GetYaxis()->SetTitleFont(42);
   eventSR3_cosThetaStar_stack_4->GetZaxis()->SetLabelFont(42);
   eventSR3_cosThetaStar_stack_4->GetZaxis()->SetTitleOffset(1);
   eventSR3_cosThetaStar_stack_4->GetZaxis()->SetTitleFont(42);
   eventSR3_cosThetaStarbackground->Add(eventSR3_cosThetaStar_stack_4,"");
   eventSR3_cosThetaStarbackground->Draw("hist");
   
   auto eventSR3_cosThetaStardata = new THStack();
   eventSR3_cosThetaStardata->SetName("eventSR3_cosThetaStardata");
   eventSR3_cosThetaStardata->SetTitle("");
   eventSR3_cosThetaStardata->SetMaximum(25);
   
   TH1F *eventSR3_cosThetaStardata_stack_20 = new TH1F("eventSR3_cosThetaStardata_stack_20","",3,0,1);
   eventSR3_cosThetaStardata_stack_20->SetMinimum(0);
   eventSR3_cosThetaStardata_stack_20->SetMaximum(25);
   eventSR3_cosThetaStardata_stack_20->SetDirectory(0);
   eventSR3_cosThetaStardata_stack_20->SetStats(0);
   eventSR3_cosThetaStardata_stack_20->SetLineStyle(0);
   eventSR3_cosThetaStardata_stack_20->GetXaxis()->SetTitle("|cos #theta*|");
   eventSR3_cosThetaStardata_stack_20->GetXaxis()->SetLabelFont(42);
   eventSR3_cosThetaStardata_stack_20->GetXaxis()->SetLabelOffset(0.007);
   eventSR3_cosThetaStardata_stack_20->GetXaxis()->SetLabelSize(0.06);
   eventSR3_cosThetaStardata_stack_20->GetXaxis()->SetTitleSize(0.06);
   eventSR3_cosThetaStardata_stack_20->GetXaxis()->SetTitleOffset(1.7);
   eventSR3_cosThetaStardata_stack_20->GetXaxis()->SetTitleFont(42);
   eventSR3_cosThetaStardata_stack_20->GetYaxis()->SetTitle("Events / 0.33");
   eventSR3_cosThetaStardata_stack_20->GetYaxis()->CenterTitle(true);
   eventSR3_cosThetaStardata_stack_20->GetYaxis()->SetNdivisions(505);
   eventSR3_cosThetaStardata_stack_20->GetYaxis()->SetLabelFont(42);
   eventSR3_cosThetaStardata_stack_20->GetYaxis()->SetLabelOffset(0.007);
   eventSR3_cosThetaStardata_stack_20->GetYaxis()->SetLabelSize(0.06);
   eventSR3_cosThetaStardata_stack_20->GetYaxis()->SetTitleSize(0.05);
   eventSR3_cosThetaStardata_stack_20->GetYaxis()->SetTitleOffset(1.5);
   eventSR3_cosThetaStardata_stack_20->GetYaxis()->SetTitleFont(42);
   eventSR3_cosThetaStardata_stack_20->GetZaxis()->SetLabelFont(42);
   eventSR3_cosThetaStardata_stack_20->GetZaxis()->SetLabelOffset(0.007);
   eventSR3_cosThetaStardata_stack_20->GetZaxis()->SetLabelSize(0.05);
   eventSR3_cosThetaStardata_stack_20->GetZaxis()->SetTitleSize(0.06);
   eventSR3_cosThetaStardata_stack_20->GetZaxis()->SetTitleOffset(1);
   eventSR3_cosThetaStardata_stack_20->GetZaxis()->SetTitleFont(42);
   eventSR3_cosThetaStardata->SetHistogram(eventSR3_cosThetaStardata_stack_20);
   
   
   eventSR3_cosThetaStar_stack_1 = new TH1D("eventSR3_cosThetaStar_stack_1","eventSR3_cosThetaStar",3,0,1);
   eventSR3_cosThetaStar_stack_1->SetBinContent(1,17);
   eventSR3_cosThetaStar_stack_1->SetBinContent(2,6);
   eventSR3_cosThetaStar_stack_1->SetBinContent(3,3);
   eventSR3_cosThetaStar_stack_1->SetBinError(1,4.123106);
   eventSR3_cosThetaStar_stack_1->SetBinError(2,2.44949);
   eventSR3_cosThetaStar_stack_1->SetBinError(3,1.732051);
   eventSR3_cosThetaStar_stack_1->SetEntries(26);
   eventSR3_cosThetaStar_stack_1->SetDirectory(0);

   ci = 1494;
   color = new TColor(ci, 0, 1, 0, " ", 0);
   eventSR3_cosThetaStar_stack_1->SetFillColor(ci);

   ci = TColor::GetColor("#000000");
   eventSR3_cosThetaStar_stack_1->SetLineColor(ci);
   eventSR3_cosThetaStar_stack_1->SetMarkerStyle(20);
   eventSR3_cosThetaStar_stack_1->GetXaxis()->SetRange(1,3);
   eventSR3_cosThetaStar_stack_1->GetXaxis()->SetLabelFont(42);
   eventSR3_cosThetaStar_stack_1->GetXaxis()->SetTitleOffset(1);
   eventSR3_cosThetaStar_stack_1->GetXaxis()->SetTitleFont(42);
   eventSR3_cosThetaStar_stack_1->GetYaxis()->SetLabelFont(42);
   eventSR3_cosThetaStar_stack_1->GetYaxis()->SetTitleFont(42);
   eventSR3_cosThetaStar_stack_1->GetZaxis()->SetLabelFont(42);
   eventSR3_cosThetaStar_stack_1->GetZaxis()->SetTitleOffset(1);
   eventSR3_cosThetaStar_stack_1->GetZaxis()->SetTitleFont(42);
   eventSR3_cosThetaStardata->Add(eventSR3_cosThetaStar_stack_1,"");
   eventSR3_cosThetaStardata->Draw("nostack pe0 same");
   
   TH1D *backgrounds_unc_eventSR3_cosThetaStar__19 = new TH1D("backgrounds_unc_eventSR3_cosThetaStar__19","eventSR3_cosThetaStar",3,0,1);
   backgrounds_unc_eventSR3_cosThetaStar__19->SetBinContent(1,12.72476);
   backgrounds_unc_eventSR3_cosThetaStar__19->SetBinContent(2,9.45773);
   backgrounds_unc_eventSR3_cosThetaStar__19->SetBinContent(3,2.646615);
   backgrounds_unc_eventSR3_cosThetaStar__19->SetBinError(1,2.943335);
   backgrounds_unc_eventSR3_cosThetaStar__19->SetBinError(2,2.194312);
   backgrounds_unc_eventSR3_cosThetaStar__19->SetBinError(3,0.6430575);
   backgrounds_unc_eventSR3_cosThetaStar__19->SetEntries(6385);

   ci = 1561;
   color = new TColor(ci, 0, 0, 0, " ", 0.3);
   backgrounds_unc_eventSR3_cosThetaStar__19->SetFillColor(ci);
   backgrounds_unc_eventSR3_cosThetaStar__19->SetFillStyle(3244);
   backgrounds_unc_eventSR3_cosThetaStar__19->SetMarkerStyle(20);
   backgrounds_unc_eventSR3_cosThetaStar__19->SetMarkerSize(0);
   backgrounds_unc_eventSR3_cosThetaStar__19->GetXaxis()->SetRange(1,3);
   backgrounds_unc_eventSR3_cosThetaStar__19->GetXaxis()->SetLabelFont(42);
   backgrounds_unc_eventSR3_cosThetaStar__19->GetXaxis()->SetTitleOffset(1);
   backgrounds_unc_eventSR3_cosThetaStar__19->GetXaxis()->SetTitleFont(42);
   backgrounds_unc_eventSR3_cosThetaStar__19->GetYaxis()->SetLabelFont(42);
   backgrounds_unc_eventSR3_cosThetaStar__19->GetYaxis()->SetTitleFont(42);
   backgrounds_unc_eventSR3_cosThetaStar__19->GetZaxis()->SetLabelFont(42);
   backgrounds_unc_eventSR3_cosThetaStar__19->GetZaxis()->SetTitleOffset(1);
   backgrounds_unc_eventSR3_cosThetaStar__19->GetZaxis()->SetTitleFont(42);
   backgrounds_unc_eventSR3_cosThetaStar__19->Draw("same e2");
   
   TLegend *leg = new TLegend(0.62,0.7,0.82,0.75,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.035);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("eventSR3_cosThetaStar_stack_3","#gamma#gamma#rightarrowe^{+}e^{-}","f");

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
   entry=leg->AddEntry("eventSR3_cosThetaStar_stack_1","Data","pl");

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
   entry=leg->AddEntry("eventSR3_cosThetaStar_stack_4","#gamma#gamma#rightarrow#gamma#gamma","f");

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
   entry=leg->AddEntry("eventSR3_cosThetaStar_stack_1","gg#rightarrow#gamma#gamma","f");

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
   
   TH1F *eventSR3_cosThetaStarbackground_copy__20 = new TH1F("eventSR3_cosThetaStarbackground_copy__20","",3,0,1);
   eventSR3_cosThetaStarbackground_copy__20->SetMinimum(0);
   eventSR3_cosThetaStarbackground_copy__20->SetMaximum(25);
   eventSR3_cosThetaStarbackground_copy__20->SetDirectory(0);
   eventSR3_cosThetaStarbackground_copy__20->SetStats(0);
   eventSR3_cosThetaStarbackground_copy__20->SetLineStyle(0);
   eventSR3_cosThetaStarbackground_copy__20->GetXaxis()->SetTitle("|cos #theta*|");
   eventSR3_cosThetaStarbackground_copy__20->GetXaxis()->SetLabelFont(42);
   eventSR3_cosThetaStarbackground_copy__20->GetXaxis()->SetLabelOffset(0.007);
   eventSR3_cosThetaStarbackground_copy__20->GetXaxis()->SetLabelSize(0.06);
   eventSR3_cosThetaStarbackground_copy__20->GetXaxis()->SetTitleSize(0.06);
   eventSR3_cosThetaStarbackground_copy__20->GetXaxis()->SetTitleOffset(1.7);
   eventSR3_cosThetaStarbackground_copy__20->GetXaxis()->SetTitleFont(42);
   eventSR3_cosThetaStarbackground_copy__20->GetYaxis()->SetTitle("Events / 0.33");
   eventSR3_cosThetaStarbackground_copy__20->GetYaxis()->CenterTitle(true);
   eventSR3_cosThetaStarbackground_copy__20->GetYaxis()->SetNdivisions(505);
   eventSR3_cosThetaStarbackground_copy__20->GetYaxis()->SetLabelFont(42);
   eventSR3_cosThetaStarbackground_copy__20->GetYaxis()->SetLabelOffset(0.007);
   eventSR3_cosThetaStarbackground_copy__20->GetYaxis()->SetLabelSize(0.06);
   eventSR3_cosThetaStarbackground_copy__20->GetYaxis()->SetTitleSize(0.05);
   eventSR3_cosThetaStarbackground_copy__20->GetYaxis()->SetTitleOffset(1.5);
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
   TPad *eventSR3_cosThetaStar_2 = new TPad("eventSR3_cosThetaStar_2", "eventSR3_cosThetaStar_2",0,0,1,0.3);
   eventSR3_cosThetaStar_2->Draw();
   eventSR3_cosThetaStar_2->cd();
   eventSR3_cosThetaStar_2->Range(-0.231884,-0.8571429,1.217391,2);
   eventSR3_cosThetaStar_2->SetFillColor(0);
   eventSR3_cosThetaStar_2->SetBorderMode(0);
   eventSR3_cosThetaStar_2->SetBorderSize(2);
   eventSR3_cosThetaStar_2->SetLeftMargin(0.16);
   eventSR3_cosThetaStar_2->SetRightMargin(0.15);
   eventSR3_cosThetaStar_2->SetTopMargin(0);
   eventSR3_cosThetaStar_2->SetBottomMargin(0.3);
   eventSR3_cosThetaStar_2->SetFrameFillStyle(0);
   eventSR3_cosThetaStar_2->SetFrameBorderMode(0);
   eventSR3_cosThetaStar_2->SetFrameFillStyle(0);
   eventSR3_cosThetaStar_2->SetFrameBorderMode(0);
   
   auto ratio_stack_eventSR3_cosThetaStar = new THStack();
   ratio_stack_eventSR3_cosThetaStar->SetName("ratio_stack_eventSR3_cosThetaStar");
   ratio_stack_eventSR3_cosThetaStar->SetTitle("");
   ratio_stack_eventSR3_cosThetaStar->SetMinimum(0);
   ratio_stack_eventSR3_cosThetaStar->SetMaximum(2);
   
   TH1F *ratio_stack_eventSR3_cosThetaStar_stack_21 = new TH1F("ratio_stack_eventSR3_cosThetaStar_stack_21","",3,0,1);
   ratio_stack_eventSR3_cosThetaStar_stack_21->SetMinimum(0);
   ratio_stack_eventSR3_cosThetaStar_stack_21->SetMaximum(2);
   ratio_stack_eventSR3_cosThetaStar_stack_21->SetDirectory(0);
   ratio_stack_eventSR3_cosThetaStar_stack_21->SetStats(0);
   ratio_stack_eventSR3_cosThetaStar_stack_21->SetLineStyle(0);
   ratio_stack_eventSR3_cosThetaStar_stack_21->GetXaxis()->SetTitle("|cos #theta*|");
   ratio_stack_eventSR3_cosThetaStar_stack_21->GetXaxis()->SetLabelFont(42);
   ratio_stack_eventSR3_cosThetaStar_stack_21->GetXaxis()->SetLabelOffset(0.007);
   ratio_stack_eventSR3_cosThetaStar_stack_21->GetXaxis()->SetLabelSize(0.1);
   ratio_stack_eventSR3_cosThetaStar_stack_21->GetXaxis()->SetTitleSize(0.12);
   ratio_stack_eventSR3_cosThetaStar_stack_21->GetXaxis()->SetTitleOffset(1);
   ratio_stack_eventSR3_cosThetaStar_stack_21->GetXaxis()->SetTitleFont(42);
   ratio_stack_eventSR3_cosThetaStar_stack_21->GetYaxis()->SetTitle("Data/MC");
   ratio_stack_eventSR3_cosThetaStar_stack_21->GetYaxis()->CenterTitle(true);
   ratio_stack_eventSR3_cosThetaStar_stack_21->GetYaxis()->SetNdivisions(505);
   ratio_stack_eventSR3_cosThetaStar_stack_21->GetYaxis()->SetLabelFont(42);
   ratio_stack_eventSR3_cosThetaStar_stack_21->GetYaxis()->SetLabelOffset(0.007);
   ratio_stack_eventSR3_cosThetaStar_stack_21->GetYaxis()->SetLabelSize(0.1);
   ratio_stack_eventSR3_cosThetaStar_stack_21->GetYaxis()->SetTitleSize(0.1);
   ratio_stack_eventSR3_cosThetaStar_stack_21->GetYaxis()->SetTitleOffset(0.5);
   ratio_stack_eventSR3_cosThetaStar_stack_21->GetYaxis()->SetTitleFont(42);
   ratio_stack_eventSR3_cosThetaStar_stack_21->GetZaxis()->SetLabelFont(42);
   ratio_stack_eventSR3_cosThetaStar_stack_21->GetZaxis()->SetLabelOffset(0.007);
   ratio_stack_eventSR3_cosThetaStar_stack_21->GetZaxis()->SetLabelSize(0.05);
   ratio_stack_eventSR3_cosThetaStar_stack_21->GetZaxis()->SetTitleSize(0.06);
   ratio_stack_eventSR3_cosThetaStar_stack_21->GetZaxis()->SetTitleOffset(1);
   ratio_stack_eventSR3_cosThetaStar_stack_21->GetZaxis()->SetTitleFont(42);
   ratio_stack_eventSR3_cosThetaStar->SetHistogram(ratio_stack_eventSR3_cosThetaStar_stack_21);
   
   
   TH1D *ratio_eventSR3_cosThetaStar_stack_1 = new TH1D("ratio_eventSR3_cosThetaStar_stack_1","eventSR3_cosThetaStar",3,0,1);
   ratio_eventSR3_cosThetaStar_stack_1->SetBinContent(1,1.335978);
   ratio_eventSR3_cosThetaStar_stack_1->SetBinContent(2,0.6344017);
   ratio_eventSR3_cosThetaStar_stack_1->SetBinContent(3,1.133523);
   ratio_eventSR3_cosThetaStar_stack_1->SetBinError(1,0.3256796);
   ratio_eventSR3_cosThetaStar_stack_1->SetBinError(2,0.2597149);
   ratio_eventSR3_cosThetaStar_stack_1->SetBinError(3,0.6604362);
   ratio_eventSR3_cosThetaStar_stack_1->SetEntries(15.8017);

   ci = 1494;
   color = new TColor(ci, 0, 1, 0, " ", 0);
   ratio_eventSR3_cosThetaStar_stack_1->SetFillColor(ci);

   ci = TColor::GetColor("#000000");
   ratio_eventSR3_cosThetaStar_stack_1->SetLineColor(ci);
   ratio_eventSR3_cosThetaStar_stack_1->SetMarkerStyle(20);
   ratio_eventSR3_cosThetaStar_stack_1->GetXaxis()->SetRange(1,3);
   ratio_eventSR3_cosThetaStar_stack_1->GetXaxis()->SetLabelFont(42);
   ratio_eventSR3_cosThetaStar_stack_1->GetXaxis()->SetTitleOffset(1);
   ratio_eventSR3_cosThetaStar_stack_1->GetXaxis()->SetTitleFont(42);
   ratio_eventSR3_cosThetaStar_stack_1->GetYaxis()->SetLabelFont(42);
   ratio_eventSR3_cosThetaStar_stack_1->GetYaxis()->SetTitleFont(42);
   ratio_eventSR3_cosThetaStar_stack_1->GetZaxis()->SetLabelFont(42);
   ratio_eventSR3_cosThetaStar_stack_1->GetZaxis()->SetTitleOffset(1);
   ratio_eventSR3_cosThetaStar_stack_1->GetZaxis()->SetTitleFont(42);
   ratio_stack_eventSR3_cosThetaStar->Add(ratio_eventSR3_cosThetaStar_stack_1,"");
   ratio_stack_eventSR3_cosThetaStar->Draw("p");
   TLine *line = new TLine(0,1,1,1);
   line->SetLineStyle(2);
   line->Draw();
   
   TH1D *ratio_uncertainty_eventSR3_cosThetaStar__21 = new TH1D("ratio_uncertainty_eventSR3_cosThetaStar__21","eventSR3_cosThetaStar",3,0,1);
   ratio_uncertainty_eventSR3_cosThetaStar__21->SetBinContent(1,1);
   ratio_uncertainty_eventSR3_cosThetaStar__21->SetBinContent(2,1);
   ratio_uncertainty_eventSR3_cosThetaStar__21->SetBinContent(3,1);
   ratio_uncertainty_eventSR3_cosThetaStar__21->SetBinError(1,0.3271185);
   ratio_uncertainty_eventSR3_cosThetaStar__21->SetBinError(2,0.3281153);
   ratio_uncertainty_eventSR3_cosThetaStar__21->SetBinError(3,0.3436165);
   ratio_uncertainty_eventSR3_cosThetaStar__21->SetEntries(27.04827);

   ci = 1561;
   color = new TColor(ci, 0, 0, 0, " ", 0.3);
   ratio_uncertainty_eventSR3_cosThetaStar__21->SetFillColor(ci);
   ratio_uncertainty_eventSR3_cosThetaStar__21->SetFillStyle(3244);
   ratio_uncertainty_eventSR3_cosThetaStar__21->SetMarkerStyle(20);
   ratio_uncertainty_eventSR3_cosThetaStar__21->SetMarkerSize(0);
   ratio_uncertainty_eventSR3_cosThetaStar__21->GetXaxis()->SetRange(1,3);
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
   eventSR3_cosThetaStar->Modified();
   eventSR3_cosThetaStar->cd();
   eventSR3_cosThetaStar->SetSelected(eventSR3_cosThetaStar);
   eventSR3_cosThetaStar->SaveAs("Figure_006_g.pdf");
}
