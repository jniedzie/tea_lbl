#ifdef __CLING__
#pragma cling optimize(0)
#endif
void plot_fig_4_a()
{
   gROOT->SetBatch(kTRUE);
//=========Macro generated from canvas: c2/Delectron pt
//=========  (Sun Mar 31 15:04:18 2024) by ROOT version 6.28/06
   TCanvas *c2 = new TCanvas("c2", "Delectron pt",50,78,600,500);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c2->Range(0,0,1,1);
   c2->SetFillColor(0);
   c2->SetBorderMode(0);
   c2->SetBorderSize(2);
   c2->SetLeftMargin(0.14);
   c2->SetRightMargin(0.04);
   c2->SetTopMargin(0.08);
   c2->SetBottomMargin(0.14);
   c2->SetFrameFillStyle(0);
   c2->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: pad7
   TPad *pad7 = new TPad("pad7", "pad7",0,0.3,1,1);
   pad7->Draw();
   pad7->cd();
   pad7->Range(-0.2105263,-1.774287,1.105263,4.502112);
   pad7->SetFillColor(0);
   pad7->SetBorderMode(0);
   pad7->SetBorderSize(2);
   pad7->SetLogy();
   pad7->SetTickx(1);
   pad7->SetTicky(1);
   pad7->SetLeftMargin(0.16);
   pad7->SetRightMargin(0.08);
   pad7->SetTopMargin(0.08);
   pad7->SetBottomMargin(0.012);
   pad7->SetFrameFillStyle(0);
   pad7->SetFrameBorderMode(0);
   pad7->SetFrameFillStyle(0);
   pad7->SetFrameBorderMode(0);
   
   TH1D *hGenPt_xSec__1 = new TH1D("hGenPt_xSec__1","",7,0,1);
   hGenPt_xSec__1->SetBinContent(1,1676.115);
   hGenPt_xSec__1->SetBinContent(2,70.51274);
   hGenPt_xSec__1->SetBinContent(3,33.0057);
   hGenPt_xSec__1->SetBinContent(4,19.35985);
   hGenPt_xSec__1->SetBinContent(5,12.65528);
   hGenPt_xSec__1->SetBinContent(6,8.77434);
   hGenPt_xSec__1->SetBinContent(7,6.274983);
   hGenPt_xSec__1->SetBinError(1,1.322002);
   hGenPt_xSec__1->SetBinError(2,0.2711527);
   hGenPt_xSec__1->SetBinError(3,0.1855131);
   hGenPt_xSec__1->SetBinError(4,0.1420794);
   hGenPt_xSec__1->SetBinError(5,0.1148725);
   hGenPt_xSec__1->SetBinError(6,0.09565054);
   hGenPt_xSec__1->SetBinError(7,0.08088844);
   hGenPt_xSec__1->SetMinimum(0.02);
   hGenPt_xSec__1->SetMaximum(10000);
   hGenPt_xSec__1->SetEntries(7);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#009999");
   hGenPt_xSec__1->SetLineColor(ci);
   hGenPt_xSec__1->SetLineWidth(2);

   ci = TColor::GetColor("#009999");
   hGenPt_xSec__1->SetMarkerColor(ci);
   hGenPt_xSec__1->SetMarkerStyle(2);
   hGenPt_xSec__1->GetXaxis()->SetTitle("p_{T}^{ee} (GeV) ");
   hGenPt_xSec__1->GetXaxis()->SetLabelFont(40);
   hGenPt_xSec__1->GetXaxis()->SetLabelOffset(0.007);
   hGenPt_xSec__1->GetXaxis()->SetLabelSize(0);
   hGenPt_xSec__1->GetXaxis()->SetTitleSize(0.06);
   hGenPt_xSec__1->GetXaxis()->SetTitleOffset(0.9);
   hGenPt_xSec__1->GetXaxis()->SetTitleFont(42);
   hGenPt_xSec__1->GetYaxis()->SetTitle("#frac{d#sigma^{ee}}{dp_{T}^{ee}} (#mub / 0.142 GeV)");
   hGenPt_xSec__1->GetYaxis()->SetLabelFont(40);
   hGenPt_xSec__1->GetYaxis()->SetLabelOffset(0.007);
   hGenPt_xSec__1->GetYaxis()->SetLabelSize(0.05);
   hGenPt_xSec__1->GetYaxis()->SetTitleSize(0.06);
   hGenPt_xSec__1->GetYaxis()->SetTitleOffset(1);
   hGenPt_xSec__1->GetYaxis()->SetTitleFont(42);
   hGenPt_xSec__1->GetZaxis()->SetLabelFont(40);
   hGenPt_xSec__1->GetZaxis()->SetLabelOffset(0.007);
   hGenPt_xSec__1->GetZaxis()->SetLabelSize(0.05);
   hGenPt_xSec__1->GetZaxis()->SetTitleSize(0.06);
   hGenPt_xSec__1->GetZaxis()->SetTitleOffset(1);
   hGenPt_xSec__1->GetZaxis()->SetTitleFont(42);
   hGenPt_xSec__1->Draw("histx0");
   Double_t xAxis1[8] = {0, 0.1428571, 0.2857143, 0.4285714, 0.5714286, 0.7142857, 0.8571429, 1}; 
   
   TH1F *hgammaUPC_QED_PtPair__2 = new TH1F("hgammaUPC_QED_PtPair__2","d#sigma/dp_{T} (pb/GeV) photon pairs (after cuts) [QED]",7, xAxis1);
   hgammaUPC_QED_PtPair__2->SetBinContent(1,1687.999);
   hgammaUPC_QED_PtPair__2->SetBinContent(2,78.87006);
   hgammaUPC_QED_PtPair__2->SetBinContent(3,38.10772);
   hgammaUPC_QED_PtPair__2->SetBinContent(4,22.1539);
   hgammaUPC_QED_PtPair__2->SetBinContent(5,14.28622);
   hgammaUPC_QED_PtPair__2->SetBinContent(6,10.1934);
   hgammaUPC_QED_PtPair__2->SetBinContent(7,7.666996);
   hgammaUPC_QED_PtPair__2->SetBinError(1,5.087788);
   hgammaUPC_QED_PtPair__2->SetBinError(2,1.094112);
   hgammaUPC_QED_PtPair__2->SetBinError(3,0.7591962);
   hgammaUPC_QED_PtPair__2->SetBinError(4,0.5774625);
   hgammaUPC_QED_PtPair__2->SetBinError(5,0.4615101);
   hgammaUPC_QED_PtPair__2->SetBinError(6,0.389252);
   hgammaUPC_QED_PtPair__2->SetBinError(7,0.3361299);
   hgammaUPC_QED_PtPair__2->SetEntries(121423);

   ci = TColor::GetColor("#000099");
   hgammaUPC_QED_PtPair__2->SetLineColor(ci);
   hgammaUPC_QED_PtPair__2->SetLineWidth(2);

   ci = TColor::GetColor("#000099");
   hgammaUPC_QED_PtPair__2->SetMarkerColor(ci);
   hgammaUPC_QED_PtPair__2->SetMarkerStyle(2);
   hgammaUPC_QED_PtPair__2->GetXaxis()->SetTitle("p_{T}^{ee} (GeV) ");
   hgammaUPC_QED_PtPair__2->GetXaxis()->SetRange(1,1400);
   hgammaUPC_QED_PtPair__2->GetXaxis()->SetLabelFont(40);
   hgammaUPC_QED_PtPair__2->GetXaxis()->SetLabelOffset(0.007);
   hgammaUPC_QED_PtPair__2->GetXaxis()->SetLabelSize(0.05);
   hgammaUPC_QED_PtPair__2->GetXaxis()->SetTitleSize(0.06);
   hgammaUPC_QED_PtPair__2->GetXaxis()->SetTitleOffset(0.9);
   hgammaUPC_QED_PtPair__2->GetXaxis()->SetTitleFont(42);
   hgammaUPC_QED_PtPair__2->GetYaxis()->SetTitle("#frac{d#sigma^{ee}}{dp_{T}^{ee}} (#mub / 0.142 GeV)");
   hgammaUPC_QED_PtPair__2->GetYaxis()->SetLabelFont(40);
   hgammaUPC_QED_PtPair__2->GetYaxis()->SetLabelOffset(0.007);
   hgammaUPC_QED_PtPair__2->GetYaxis()->SetLabelSize(0.05);
   hgammaUPC_QED_PtPair__2->GetYaxis()->SetTitleSize(0.06);
   hgammaUPC_QED_PtPair__2->GetYaxis()->SetTitleOffset(1);
   hgammaUPC_QED_PtPair__2->GetYaxis()->SetTitleFont(42);
   hgammaUPC_QED_PtPair__2->GetZaxis()->SetLabelFont(40);
   hgammaUPC_QED_PtPair__2->GetZaxis()->SetLabelOffset(0.007);
   hgammaUPC_QED_PtPair__2->GetZaxis()->SetLabelSize(0.05);
   hgammaUPC_QED_PtPair__2->GetZaxis()->SetTitleSize(0.06);
   hgammaUPC_QED_PtPair__2->GetZaxis()->SetTitleOffset(1);
   hgammaUPC_QED_PtPair__2->GetZaxis()->SetTitleFont(42);
   hgammaUPC_QED_PtPair__2->Draw("histsamex0");
   Double_t xAxis2[8] = {0, 0.1428571, 0.2857143, 0.4285714, 0.5714286, 0.7142857, 0.8571429, 1}; 
   
   TH1F *hgammaUPC_QED_PtPair__3 = new TH1F("hgammaUPC_QED_PtPair__3","d#sigma/dp_{T} (pb/GeV) photon pairs (after cuts) [QED]",7, xAxis2);
   hgammaUPC_QED_PtPair__3->SetBinContent(1,1687.999);
   hgammaUPC_QED_PtPair__3->SetBinContent(2,78.87006);
   hgammaUPC_QED_PtPair__3->SetBinContent(3,38.10772);
   hgammaUPC_QED_PtPair__3->SetBinContent(4,22.1539);
   hgammaUPC_QED_PtPair__3->SetBinContent(5,14.28622);
   hgammaUPC_QED_PtPair__3->SetBinContent(6,10.1934);
   hgammaUPC_QED_PtPair__3->SetBinContent(7,7.666996);
   hgammaUPC_QED_PtPair__3->SetBinError(1,5.087788);
   hgammaUPC_QED_PtPair__3->SetBinError(2,1.094112);
   hgammaUPC_QED_PtPair__3->SetBinError(3,0.7591962);
   hgammaUPC_QED_PtPair__3->SetBinError(4,0.5774625);
   hgammaUPC_QED_PtPair__3->SetBinError(5,0.4615101);
   hgammaUPC_QED_PtPair__3->SetBinError(6,0.389252);
   hgammaUPC_QED_PtPair__3->SetBinError(7,0.3361299);
   hgammaUPC_QED_PtPair__3->SetEntries(121423);

   ci = TColor::GetColor("#000099");
   hgammaUPC_QED_PtPair__3->SetLineColor(ci);
   hgammaUPC_QED_PtPair__3->SetLineWidth(2);

   ci = TColor::GetColor("#000099");
   hgammaUPC_QED_PtPair__3->SetMarkerColor(ci);
   hgammaUPC_QED_PtPair__3->SetMarkerStyle(2);
   hgammaUPC_QED_PtPair__3->GetXaxis()->SetTitle("p_{T}^{ee} (GeV) ");
   hgammaUPC_QED_PtPair__3->GetXaxis()->SetRange(1,1400);
   hgammaUPC_QED_PtPair__3->GetXaxis()->SetLabelFont(40);
   hgammaUPC_QED_PtPair__3->GetXaxis()->SetLabelOffset(0.007);
   hgammaUPC_QED_PtPair__3->GetXaxis()->SetLabelSize(0.05);
   hgammaUPC_QED_PtPair__3->GetXaxis()->SetTitleSize(0.06);
   hgammaUPC_QED_PtPair__3->GetXaxis()->SetTitleOffset(0.9);
   hgammaUPC_QED_PtPair__3->GetXaxis()->SetTitleFont(42);
   hgammaUPC_QED_PtPair__3->GetYaxis()->SetTitle("#frac{d#sigma^{ee}}{dp_{T}^{ee}} (#mub / 0.142 GeV)");
   hgammaUPC_QED_PtPair__3->GetYaxis()->SetLabelFont(40);
   hgammaUPC_QED_PtPair__3->GetYaxis()->SetLabelOffset(0.007);
   hgammaUPC_QED_PtPair__3->GetYaxis()->SetLabelSize(0.05);
   hgammaUPC_QED_PtPair__3->GetYaxis()->SetTitleSize(0.06);
   hgammaUPC_QED_PtPair__3->GetYaxis()->SetTitleOffset(1);
   hgammaUPC_QED_PtPair__3->GetYaxis()->SetTitleFont(42);
   hgammaUPC_QED_PtPair__3->GetZaxis()->SetLabelFont(40);
   hgammaUPC_QED_PtPair__3->GetZaxis()->SetLabelOffset(0.007);
   hgammaUPC_QED_PtPair__3->GetZaxis()->SetLabelSize(0.05);
   hgammaUPC_QED_PtPair__3->GetZaxis()->SetTitleSize(0.06);
   hgammaUPC_QED_PtPair__3->GetZaxis()->SetTitleOffset(1);
   hgammaUPC_QED_PtPair__3->GetZaxis()->SetTitleFont(42);
   hgammaUPC_QED_PtPair__3->Draw("psame");
   
   TH1D *hGenPt_xSec__4 = new TH1D("hGenPt_xSec__4","",7,0,1);
   hGenPt_xSec__4->SetBinContent(1,1758.764);
   hGenPt_xSec__4->SetBinContent(2,0.3529888);
   hGenPt_xSec__4->SetBinError(1,1.20862);
   hGenPt_xSec__4->SetBinError(2,0.01712247);
   hGenPt_xSec__4->SetEntries(7);

   ci = TColor::GetColor("#ff6666");
   hGenPt_xSec__4->SetLineColor(ci);
   hGenPt_xSec__4->SetLineWidth(2);

   ci = TColor::GetColor("#ff6666");
   hGenPt_xSec__4->SetMarkerColor(ci);
   hGenPt_xSec__4->SetMarkerStyle(2);
   hGenPt_xSec__4->GetXaxis()->SetTitle("p_{T}^{ee} (GeV) ");
   hGenPt_xSec__4->GetXaxis()->SetLabelFont(40);
   hGenPt_xSec__4->GetXaxis()->SetLabelOffset(0.007);
   hGenPt_xSec__4->GetXaxis()->SetLabelSize(0.05);
   hGenPt_xSec__4->GetXaxis()->SetTitleSize(0.06);
   hGenPt_xSec__4->GetXaxis()->SetTitleOffset(0.9);
   hGenPt_xSec__4->GetXaxis()->SetTitleFont(42);
   hGenPt_xSec__4->GetYaxis()->SetTitle("#frac{d#sigma^{ee}}{dp_{T}^{ee}} (#mub / 0.142 GeV)");
   hGenPt_xSec__4->GetYaxis()->SetLabelFont(40);
   hGenPt_xSec__4->GetYaxis()->SetLabelOffset(0.007);
   hGenPt_xSec__4->GetYaxis()->SetLabelSize(0.05);
   hGenPt_xSec__4->GetYaxis()->SetTitleSize(0.06);
   hGenPt_xSec__4->GetYaxis()->SetTitleOffset(1);
   hGenPt_xSec__4->GetYaxis()->SetTitleFont(42);
   hGenPt_xSec__4->GetZaxis()->SetLabelFont(40);
   hGenPt_xSec__4->GetZaxis()->SetLabelOffset(0.007);
   hGenPt_xSec__4->GetZaxis()->SetLabelSize(0.05);
   hGenPt_xSec__4->GetZaxis()->SetTitleSize(0.06);
   hGenPt_xSec__4->GetZaxis()->SetTitleOffset(1);
   hGenPt_xSec__4->GetZaxis()->SetTitleFont(42);
   hGenPt_xSec__4->Draw("histsamex0");
   
   TH1D *hGenPt_xSec__5 = new TH1D("hGenPt_xSec__5","",7,0,1);
   hGenPt_xSec__5->SetBinContent(1,1758.764);
   hGenPt_xSec__5->SetBinContent(2,0.3529888);
   hGenPt_xSec__5->SetBinError(1,1.20862);
   hGenPt_xSec__5->SetBinError(2,0.01712247);
   hGenPt_xSec__5->SetEntries(7);

   ci = TColor::GetColor("#ff6666");
   hGenPt_xSec__5->SetLineColor(ci);
   hGenPt_xSec__5->SetLineWidth(2);

   ci = TColor::GetColor("#ff6666");
   hGenPt_xSec__5->SetMarkerColor(ci);
   hGenPt_xSec__5->SetMarkerStyle(2);
   hGenPt_xSec__5->GetXaxis()->SetTitle("p_{T}^{ee} (GeV) ");
   hGenPt_xSec__5->GetXaxis()->SetLabelFont(40);
   hGenPt_xSec__5->GetXaxis()->SetLabelOffset(0.007);
   hGenPt_xSec__5->GetXaxis()->SetLabelSize(0.05);
   hGenPt_xSec__5->GetXaxis()->SetTitleSize(0.06);
   hGenPt_xSec__5->GetXaxis()->SetTitleOffset(0.9);
   hGenPt_xSec__5->GetXaxis()->SetTitleFont(42);
   hGenPt_xSec__5->GetYaxis()->SetTitle("#frac{d#sigma^{ee}}{dp_{T}^{ee}} (#mub / 0.142 GeV)");
   hGenPt_xSec__5->GetYaxis()->SetLabelFont(40);
   hGenPt_xSec__5->GetYaxis()->SetLabelOffset(0.007);
   hGenPt_xSec__5->GetYaxis()->SetLabelSize(0.05);
   hGenPt_xSec__5->GetYaxis()->SetTitleSize(0.06);
   hGenPt_xSec__5->GetYaxis()->SetTitleOffset(1);
   hGenPt_xSec__5->GetYaxis()->SetTitleFont(42);
   hGenPt_xSec__5->GetZaxis()->SetLabelFont(40);
   hGenPt_xSec__5->GetZaxis()->SetLabelOffset(0.007);
   hGenPt_xSec__5->GetZaxis()->SetLabelSize(0.05);
   hGenPt_xSec__5->GetZaxis()->SetTitleSize(0.06);
   hGenPt_xSec__5->GetZaxis()->SetTitleOffset(1);
   hGenPt_xSec__5->GetZaxis()->SetTitleFont(42);
   hGenPt_xSec__5->Draw("psame");
   
   TH1D *hUnfoDataPt_xSec__6 = new TH1D("hUnfoDataPt_xSec__6","",7,0,1);
   hUnfoDataPt_xSec__6->SetBinContent(1,1734.907);
   hUnfoDataPt_xSec__6->SetBinContent(2,74.25486);
   hUnfoDataPt_xSec__6->SetBinContent(3,35.6896);
   hUnfoDataPt_xSec__6->SetBinContent(4,21.85124);
   hUnfoDataPt_xSec__6->SetBinContent(5,15.14826);
   hUnfoDataPt_xSec__6->SetBinContent(6,10.88751);
   hUnfoDataPt_xSec__6->SetBinContent(7,7.761625);
   hUnfoDataPt_xSec__6->SetBinError(1,119.2425);
   hUnfoDataPt_xSec__6->SetBinError(2,8.97962);
   hUnfoDataPt_xSec__6->SetBinError(3,4.315934);
   hUnfoDataPt_xSec__6->SetBinError(4,2.642465);
   hUnfoDataPt_xSec__6->SetBinError(5,1.831875);
   hUnfoDataPt_xSec__6->SetBinError(6,1.793104);
   hUnfoDataPt_xSec__6->SetBinError(7,1.27829);
   hUnfoDataPt_xSec__6->SetEntries(7);

   ci = 1179;
   color = new TColor(ci, 0, 0, 0, " ", 0.5);
   hUnfoDataPt_xSec__6->SetFillColor(ci);
   hUnfoDataPt_xSec__6->SetFillStyle(3005);
   hUnfoDataPt_xSec__6->SetLineWidth(2);
   hUnfoDataPt_xSec__6->SetMarkerStyle(20);
   hUnfoDataPt_xSec__6->GetXaxis()->SetTitle("p_{T}^{ee} (GeV) ");
   hUnfoDataPt_xSec__6->GetXaxis()->SetLabelFont(40);
   hUnfoDataPt_xSec__6->GetXaxis()->SetLabelOffset(0.007);
   hUnfoDataPt_xSec__6->GetXaxis()->SetLabelSize(0.05);
   hUnfoDataPt_xSec__6->GetXaxis()->SetTitleSize(0.06);
   hUnfoDataPt_xSec__6->GetXaxis()->SetTitleOffset(0.9);
   hUnfoDataPt_xSec__6->GetXaxis()->SetTitleFont(42);
   hUnfoDataPt_xSec__6->GetYaxis()->SetTitle("#frac{d#sigma^{ee}}{dp_{T}^{ee}} (#mub / 0.142 GeV)");
   hUnfoDataPt_xSec__6->GetYaxis()->SetLabelFont(40);
   hUnfoDataPt_xSec__6->GetYaxis()->SetLabelOffset(0.007);
   hUnfoDataPt_xSec__6->GetYaxis()->SetLabelSize(0.05);
   hUnfoDataPt_xSec__6->GetYaxis()->SetTitleSize(0.06);
   hUnfoDataPt_xSec__6->GetYaxis()->SetTitleOffset(1);
   hUnfoDataPt_xSec__6->GetYaxis()->SetTitleFont(42);
   hUnfoDataPt_xSec__6->GetZaxis()->SetLabelFont(40);
   hUnfoDataPt_xSec__6->GetZaxis()->SetLabelOffset(0.007);
   hUnfoDataPt_xSec__6->GetZaxis()->SetLabelSize(0.05);
   hUnfoDataPt_xSec__6->GetZaxis()->SetTitleSize(0.06);
   hUnfoDataPt_xSec__6->GetZaxis()->SetTitleOffset(1);
   hUnfoDataPt_xSec__6->GetZaxis()->SetTitleFont(42);
   hUnfoDataPt_xSec__6->Draw("e2same");
   
   TH1D *hUnfoDataPt_xSec__7 = new TH1D("hUnfoDataPt_xSec__7","",7,0,1);
   hUnfoDataPt_xSec__7->SetBinContent(1,1734.907);
   hUnfoDataPt_xSec__7->SetBinContent(2,74.25486);
   hUnfoDataPt_xSec__7->SetBinContent(3,35.6896);
   hUnfoDataPt_xSec__7->SetBinContent(4,21.85124);
   hUnfoDataPt_xSec__7->SetBinContent(5,15.14826);
   hUnfoDataPt_xSec__7->SetBinContent(6,10.88751);
   hUnfoDataPt_xSec__7->SetBinContent(7,7.761625);
   hUnfoDataPt_xSec__7->SetBinError(1,12.70799);
   hUnfoDataPt_xSec__7->SetBinError(2,0.8296115);
   hUnfoDataPt_xSec__7->SetBinError(3,0.619278);
   hUnfoDataPt_xSec__7->SetBinError(4,0.4786418);
   hUnfoDataPt_xSec__7->SetBinError(5,0.4289138);
   hUnfoDataPt_xSec__7->SetBinError(6,0.3639993);
   hUnfoDataPt_xSec__7->SetBinError(7,0.262884);
   hUnfoDataPt_xSec__7->SetEntries(7);
   hUnfoDataPt_xSec__7->SetLineWidth(2);
   hUnfoDataPt_xSec__7->SetMarkerStyle(20);
   hUnfoDataPt_xSec__7->GetXaxis()->SetTitle("p_{T}^{ee} (GeV) ");
   hUnfoDataPt_xSec__7->GetXaxis()->SetLabelFont(40);
   hUnfoDataPt_xSec__7->GetXaxis()->SetLabelOffset(0.007);
   hUnfoDataPt_xSec__7->GetXaxis()->SetLabelSize(0.05);
   hUnfoDataPt_xSec__7->GetXaxis()->SetTitleSize(0.06);
   hUnfoDataPt_xSec__7->GetXaxis()->SetTitleOffset(0.9);
   hUnfoDataPt_xSec__7->GetXaxis()->SetTitleFont(42);
   hUnfoDataPt_xSec__7->GetYaxis()->SetTitle("#frac{d#sigma^{ee}}{dp_{T}^{ee}} (#mub / 0.142 GeV)");
   hUnfoDataPt_xSec__7->GetYaxis()->SetLabelFont(40);
   hUnfoDataPt_xSec__7->GetYaxis()->SetLabelOffset(0.007);
   hUnfoDataPt_xSec__7->GetYaxis()->SetLabelSize(0.05);
   hUnfoDataPt_xSec__7->GetYaxis()->SetTitleSize(0.06);
   hUnfoDataPt_xSec__7->GetYaxis()->SetTitleOffset(1);
   hUnfoDataPt_xSec__7->GetYaxis()->SetTitleFont(42);
   hUnfoDataPt_xSec__7->GetZaxis()->SetLabelFont(40);
   hUnfoDataPt_xSec__7->GetZaxis()->SetLabelOffset(0.007);
   hUnfoDataPt_xSec__7->GetZaxis()->SetLabelSize(0.05);
   hUnfoDataPt_xSec__7->GetZaxis()->SetTitleSize(0.06);
   hUnfoDataPt_xSec__7->GetZaxis()->SetTitleOffset(1);
   hUnfoDataPt_xSec__7->GetZaxis()->SetTitleFont(42);
   hUnfoDataPt_xSec__7->Draw("psameex0");
   
   TLegend *leg = new TLegend(0.4,0.6,0.91,0.9,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(43);
   leg->SetTextSize(18);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("NULL","#gamma#gamma#rightarrow e^{+}e^{-}","h");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(43);
   entry=leg->AddEntry("hUnfoDataPt_xSec","Data","EP");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(43);
   entry=leg->AddEntry("hUnfoDataPt_xSec","gamma-UPC@NLO+PY8","pl");

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#000099");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(43);
   entry=leg->AddEntry("hUnfoDataPt_xSec","SUPERCHIC+PHOTOS++","pl");

   ci = TColor::GetColor("#009999");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#009999");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(43);
   entry=leg->AddEntry("hUnfoDataPt_xSec","STARLIGHT","pl");

   ci = TColor::GetColor("#ff6666");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#ff6666");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(22);
   entry->SetMarkerSize(1);
   entry->SetTextFont(43);
   leg->Draw();
   pad7->Modified();
   c2->cd();
   TLatex *   tex = new TLatex(0.16,0.96,"#bf{CMS} #it{Preliminary}");
   tex->SetTextFont(42);
   tex->SetTextSize(0.037);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.55,0.96,"#scale[0.8]{PbPb, 1.64 nb^{-1} (#sqrt{s_{NN}} = 5.02 TeV)}");
   tex->SetTextFont(42);
   tex->SetTextSize(0.037);
   tex->SetLineWidth(2);
   tex->Draw();
  
// ------------>Primitives in pad: pad8
   TPad *pad8 = new TPad("pad8", "pad8",0,0.06,1,0.28);
   pad8->Draw();
   pad8->cd();
   pad8->Range(-0.2105263,-0.1941176,1.105263,1.570588);
   pad8->SetFillColor(0);
   pad8->SetBorderMode(0);
   pad8->SetBorderSize(2);
   pad8->SetTickx(1);
   pad8->SetTicky(1);
   pad8->SetLeftMargin(0.16);
   pad8->SetRightMargin(0.08);
   pad8->SetTopMargin(0.04);
   pad8->SetBottomMargin(0.45);
   pad8->SetFrameFillStyle(0);
   pad8->SetFrameBorderMode(0);
   pad8->SetFrameFillStyle(0);
   pad8->SetFrameBorderMode(0);
   
   TH1D *hUnfoDataPt_xSec__8 = new TH1D("hUnfoDataPt_xSec__8","",7,0,1);
   hUnfoDataPt_xSec__8->SetBinContent(1,1.035076);
   hUnfoDataPt_xSec__8->SetBinContent(2,1.05307);
   hUnfoDataPt_xSec__8->SetBinContent(3,1.081316);
   hUnfoDataPt_xSec__8->SetBinContent(4,1.128688);
   hUnfoDataPt_xSec__8->SetBinContent(5,1.196991);
   hUnfoDataPt_xSec__8->SetBinContent(6,1.240835);
   hUnfoDataPt_xSec__8->SetBinContent(7,1.236916);
   hUnfoDataPt_xSec__8->SetBinError(1,0.007625638);
   hUnfoDataPt_xSec__8->SetBinError(2,0.01244281);
   hUnfoDataPt_xSec__8->SetBinError(3,0.01972256);
   hUnfoDataPt_xSec__8->SetBinError(4,0.02607413);
   hUnfoDataPt_xSec__8->SetBinError(5,0.03559108);
   hUnfoDataPt_xSec__8->SetBinError(6,0.04363408);
   hUnfoDataPt_xSec__8->SetBinError(7,0.04482563);
   hUnfoDataPt_xSec__8->SetMinimum(0.6);
   hUnfoDataPt_xSec__8->SetMaximum(1.5);
   hUnfoDataPt_xSec__8->SetEntries(9837.344);

   ci = TColor::GetColor("#009999");
   hUnfoDataPt_xSec__8->SetLineColor(ci);
   hUnfoDataPt_xSec__8->SetLineWidth(2);

   ci = TColor::GetColor("#009999");
   hUnfoDataPt_xSec__8->SetMarkerColor(ci);
   hUnfoDataPt_xSec__8->SetMarkerStyle(21);
   hUnfoDataPt_xSec__8->GetXaxis()->SetTitle("p_{T}^{ee} (GeV)");
   hUnfoDataPt_xSec__8->GetXaxis()->SetLabelFont(43);
   hUnfoDataPt_xSec__8->GetXaxis()->SetLabelOffset(0.007);
   hUnfoDataPt_xSec__8->GetXaxis()->SetLabelSize(18);
   hUnfoDataPt_xSec__8->GetXaxis()->SetTitleSize(22);
   hUnfoDataPt_xSec__8->GetXaxis()->SetTitleOffset(1);
   hUnfoDataPt_xSec__8->GetXaxis()->SetTitleFont(43);
   hUnfoDataPt_xSec__8->GetYaxis()->SetTitle("#frac{Data}{Exp.}");
   hUnfoDataPt_xSec__8->GetYaxis()->SetNdivisions(5);
   hUnfoDataPt_xSec__8->GetYaxis()->SetLabelFont(43);
   hUnfoDataPt_xSec__8->GetYaxis()->SetLabelOffset(0.007);
   hUnfoDataPt_xSec__8->GetYaxis()->SetLabelSize(15);
   hUnfoDataPt_xSec__8->GetYaxis()->SetTitleSize(18);
   hUnfoDataPt_xSec__8->GetYaxis()->SetTitleOffset(2);
   hUnfoDataPt_xSec__8->GetYaxis()->SetTitleFont(43);
   hUnfoDataPt_xSec__8->GetZaxis()->SetLabelFont(40);
   hUnfoDataPt_xSec__8->GetZaxis()->SetLabelOffset(0.007);
   hUnfoDataPt_xSec__8->GetZaxis()->SetLabelSize(0.05);
   hUnfoDataPt_xSec__8->GetZaxis()->SetTitleSize(0.06);
   hUnfoDataPt_xSec__8->GetZaxis()->SetTitleOffset(1);
   hUnfoDataPt_xSec__8->GetZaxis()->SetTitleFont(42);
   hUnfoDataPt_xSec__8->Draw("pex0");
   
   TH1D *hUnfoDataPt_xSec__9 = new TH1D("hUnfoDataPt_xSec__9","",7,0,1);
   hUnfoDataPt_xSec__9->SetBinContent(1,1.027789);
   hUnfoDataPt_xSec__9->SetBinContent(2,0.9414835);
   hUnfoDataPt_xSec__9->SetBinContent(3,0.9365452);
   hUnfoDataPt_xSec__9->SetBinContent(4,0.9863384);
   hUnfoDataPt_xSec__9->SetBinContent(5,1.060341);
   hUnfoDataPt_xSec__9->SetBinContent(6,1.068094);
   hUnfoDataPt_xSec__9->SetBinContent(7,1.012342);
   hUnfoDataPt_xSec__9->SetBinError(1,0.008140883);
   hUnfoDataPt_xSec__9->SetBinError(2,0.01676968);
   hUnfoDataPt_xSec__9->SetBinError(3,0.02474297);
   hUnfoDataPt_xSec__9->SetBinError(4,0.03358252);
   hUnfoDataPt_xSec__9->SetBinError(5,0.0455489);
   hUnfoDataPt_xSec__9->SetBinError(6,0.05421003);
   hUnfoDataPt_xSec__9->SetBinError(7,0.05608417);
   hUnfoDataPt_xSec__9->SetMinimum(0);
   hUnfoDataPt_xSec__9->SetMaximum(2);
   hUnfoDataPt_xSec__9->SetEntries(4827.29);

   ci = TColor::GetColor("#000099");
   hUnfoDataPt_xSec__9->SetLineColor(ci);
   hUnfoDataPt_xSec__9->SetLineWidth(2);

   ci = TColor::GetColor("#000099");
   hUnfoDataPt_xSec__9->SetMarkerColor(ci);
   hUnfoDataPt_xSec__9->SetMarkerStyle(20);
   hUnfoDataPt_xSec__9->GetXaxis()->SetTitle("p_{T}^{ee} (GeV) ");
   hUnfoDataPt_xSec__9->GetXaxis()->SetLabelFont(40);
   hUnfoDataPt_xSec__9->GetXaxis()->SetLabelOffset(0.007);
   hUnfoDataPt_xSec__9->GetXaxis()->SetLabelSize(0.05);
   hUnfoDataPt_xSec__9->GetXaxis()->SetTitleSize(0.06);
   hUnfoDataPt_xSec__9->GetXaxis()->SetTitleOffset(0.9);
   hUnfoDataPt_xSec__9->GetXaxis()->SetTitleFont(42);
   hUnfoDataPt_xSec__9->GetYaxis()->SetTitle("#frac{d#sigma^{ee}}{dp_{T}^{ee}} (#mub / 0.142 GeV)");
   hUnfoDataPt_xSec__9->GetYaxis()->SetNdivisions(5);
   hUnfoDataPt_xSec__9->GetYaxis()->SetLabelFont(40);
   hUnfoDataPt_xSec__9->GetYaxis()->SetLabelOffset(0.007);
   hUnfoDataPt_xSec__9->GetYaxis()->SetLabelSize(0.05);
   hUnfoDataPt_xSec__9->GetYaxis()->SetTitleSize(0.06);
   hUnfoDataPt_xSec__9->GetYaxis()->SetTitleOffset(1);
   hUnfoDataPt_xSec__9->GetYaxis()->SetTitleFont(42);
   hUnfoDataPt_xSec__9->GetZaxis()->SetLabelFont(40);
   hUnfoDataPt_xSec__9->GetZaxis()->SetLabelOffset(0.007);
   hUnfoDataPt_xSec__9->GetZaxis()->SetLabelSize(0.05);
   hUnfoDataPt_xSec__9->GetZaxis()->SetTitleSize(0.06);
   hUnfoDataPt_xSec__9->GetZaxis()->SetTitleOffset(1);
   hUnfoDataPt_xSec__9->GetZaxis()->SetTitleFont(42);
   hUnfoDataPt_xSec__9->Draw("pex0same");
   
   TH1D *hUnfoDataPt_xSec__10 = new TH1D("hUnfoDataPt_xSec__10","",7,0,1);
   hUnfoDataPt_xSec__10->SetBinContent(1,0.9864355);
   hUnfoDataPt_xSec__10->SetBinContent(2,210.3604);
   hUnfoDataPt_xSec__10->SetBinError(1,0.007257251);
   hUnfoDataPt_xSec__10->SetBinError(2,10.47114);
   hUnfoDataPt_xSec__10->SetMinimum(0);
   hUnfoDataPt_xSec__10->SetMaximum(2);
   hUnfoDataPt_xSec__10->SetEntries(407.3832);

   ci = TColor::GetColor("#ff6666");
   hUnfoDataPt_xSec__10->SetLineColor(ci);
   hUnfoDataPt_xSec__10->SetLineWidth(2);

   ci = TColor::GetColor("#ff6666");
   hUnfoDataPt_xSec__10->SetMarkerColor(ci);
   hUnfoDataPt_xSec__10->SetMarkerStyle(22);
   hUnfoDataPt_xSec__10->GetXaxis()->SetTitle("p_{T}^{ee} (GeV) ");
   hUnfoDataPt_xSec__10->GetXaxis()->SetLabelFont(40);
   hUnfoDataPt_xSec__10->GetXaxis()->SetLabelOffset(0.007);
   hUnfoDataPt_xSec__10->GetXaxis()->SetLabelSize(0.05);
   hUnfoDataPt_xSec__10->GetXaxis()->SetTitleSize(0.06);
   hUnfoDataPt_xSec__10->GetXaxis()->SetTitleOffset(0.9);
   hUnfoDataPt_xSec__10->GetXaxis()->SetTitleFont(42);
   hUnfoDataPt_xSec__10->GetYaxis()->SetTitle("#frac{d#sigma^{ee}}{dp_{T}^{ee}} (#mub / 0.142 GeV)");
   hUnfoDataPt_xSec__10->GetYaxis()->SetNdivisions(5);
   hUnfoDataPt_xSec__10->GetYaxis()->SetLabelFont(40);
   hUnfoDataPt_xSec__10->GetYaxis()->SetLabelOffset(0.007);
   hUnfoDataPt_xSec__10->GetYaxis()->SetLabelSize(0.05);
   hUnfoDataPt_xSec__10->GetYaxis()->SetTitleSize(0.06);
   hUnfoDataPt_xSec__10->GetYaxis()->SetTitleOffset(1);
   hUnfoDataPt_xSec__10->GetYaxis()->SetTitleFont(42);
   hUnfoDataPt_xSec__10->GetZaxis()->SetLabelFont(40);
   hUnfoDataPt_xSec__10->GetZaxis()->SetLabelOffset(0.007);
   hUnfoDataPt_xSec__10->GetZaxis()->SetLabelSize(0.05);
   hUnfoDataPt_xSec__10->GetZaxis()->SetTitleSize(0.06);
   hUnfoDataPt_xSec__10->GetZaxis()->SetTitleOffset(1);
   hUnfoDataPt_xSec__10->GetZaxis()->SetTitleFont(42);
   hUnfoDataPt_xSec__10->Draw("pex0same");
   
   TH1D *hUnfoDataPt_xSec__11 = new TH1D("hUnfoDataPt_xSec__11","",7,0,1);
   hUnfoDataPt_xSec__11->SetBinContent(1,1);
   hUnfoDataPt_xSec__11->SetBinContent(2,1);
   hUnfoDataPt_xSec__11->SetBinContent(3,1);
   hUnfoDataPt_xSec__11->SetBinContent(4,1);
   hUnfoDataPt_xSec__11->SetBinContent(5,1);
   hUnfoDataPt_xSec__11->SetBinContent(6,1);
   hUnfoDataPt_xSec__11->SetBinContent(7,1);
   hUnfoDataPt_xSec__11->SetBinError(1,0.09720082);
   hUnfoDataPt_xSec__11->SetBinError(2,0.1710205);
   hUnfoDataPt_xSec__11->SetBinError(3,0.1710205);
   hUnfoDataPt_xSec__11->SetBinError(4,0.1710205);
   hUnfoDataPt_xSec__11->SetBinError(5,0.1710205);
   hUnfoDataPt_xSec__11->SetBinError(6,0.232912);
   hUnfoDataPt_xSec__11->SetBinError(7,0.232912);
   hUnfoDataPt_xSec__11->SetEntries(208.5674);

   ci = 1179;
   color = new TColor(ci, 0, 0, 0, " ", 0.5);
   hUnfoDataPt_xSec__11->SetFillColor(ci);
   hUnfoDataPt_xSec__11->SetFillStyle(3005);

   ci = TColor::GetColor("#009999");
   hUnfoDataPt_xSec__11->SetLineColor(ci);
   hUnfoDataPt_xSec__11->SetLineStyle(2);
   hUnfoDataPt_xSec__11->SetLineWidth(2);

   ci = TColor::GetColor("#009999");
   hUnfoDataPt_xSec__11->SetMarkerColor(ci);
   hUnfoDataPt_xSec__11->SetMarkerStyle(0);
   hUnfoDataPt_xSec__11->GetXaxis()->SetTitle("p_{T}^{ee} (GeV) ");
   hUnfoDataPt_xSec__11->GetXaxis()->SetLabelFont(40);
   hUnfoDataPt_xSec__11->GetXaxis()->SetLabelOffset(0.007);
   hUnfoDataPt_xSec__11->GetXaxis()->SetLabelSize(0.05);
   hUnfoDataPt_xSec__11->GetXaxis()->SetTitleSize(0.06);
   hUnfoDataPt_xSec__11->GetXaxis()->SetTitleOffset(0.9);
   hUnfoDataPt_xSec__11->GetXaxis()->SetTitleFont(42);
   hUnfoDataPt_xSec__11->GetYaxis()->SetTitle("#frac{d#sigma^{ee}}{dp_{T}^{ee}} (#mub / 0.142 GeV)");
   hUnfoDataPt_xSec__11->GetYaxis()->SetLabelFont(40);
   hUnfoDataPt_xSec__11->GetYaxis()->SetLabelOffset(0.007);
   hUnfoDataPt_xSec__11->GetYaxis()->SetLabelSize(0.05);
   hUnfoDataPt_xSec__11->GetYaxis()->SetTitleSize(0.06);
   hUnfoDataPt_xSec__11->GetYaxis()->SetTitleOffset(1);
   hUnfoDataPt_xSec__11->GetYaxis()->SetTitleFont(42);
   hUnfoDataPt_xSec__11->GetZaxis()->SetLabelFont(40);
   hUnfoDataPt_xSec__11->GetZaxis()->SetLabelOffset(0.007);
   hUnfoDataPt_xSec__11->GetZaxis()->SetLabelSize(0.05);
   hUnfoDataPt_xSec__11->GetZaxis()->SetTitleSize(0.06);
   hUnfoDataPt_xSec__11->GetZaxis()->SetTitleOffset(1);
   hUnfoDataPt_xSec__11->GetZaxis()->SetTitleFont(42);
   hUnfoDataPt_xSec__11->Draw("e2same");
   
   TF1 *line1 = new TF1("line","1",-100,100, TF1::EAddToList::kDefault);
   line1->SetFillColor(19);
   line1->SetFillStyle(0);
   line1->SetMarkerStyle(20);
   line1->SetLineStyle(2);
   line1->SetLineWidth(1);
   line1->GetXaxis()->SetLabelFont(42);
   line1->GetXaxis()->SetLabelOffset(0.007);
   line1->GetXaxis()->SetLabelSize(0.05);
   line1->GetXaxis()->SetTitleSize(0.06);
   line1->GetXaxis()->SetTitleOffset(0.9);
   line1->GetXaxis()->SetTitleFont(42);
   line1->GetYaxis()->SetLabelFont(42);
   line1->GetYaxis()->SetLabelOffset(0.007);
   line1->GetYaxis()->SetLabelSize(0.05);
   line1->GetYaxis()->SetTitleSize(0.06);
   line1->GetYaxis()->SetTitleOffset(1);
   line1->GetYaxis()->SetTitleFont(42);
   line1->Draw("same");
   pad8->Modified();
   c2->cd();
   c2->Modified();
   c2->cd();
   c2->SetSelected(c2);
   c2->SaveAs("Figure_004_a.pdf");
}
