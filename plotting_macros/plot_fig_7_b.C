#ifdef __CLING__
#pragma cling optimize(0)
#endif
void plot_fig_7_b()
{
   gROOT->SetBatch(kTRUE);
//=========Macro generated from canvas: c6/Diphoton mass
//=========  (Sun Mar 31 15:01:59 2024) by ROOT version 6.28/06
   TCanvas *c6 = new TCanvas("c6", "Diphoton mass",50,78,600,670);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c6->Range(0,0,1,1);
   c6->SetFillColor(0);
   c6->SetBorderMode(0);
   c6->SetBorderSize(2);
   c6->SetLeftMargin(0.18);
   c6->SetRightMargin(0.04);
   c6->SetTopMargin(0.08);
   c6->SetBottomMargin(0.18);
   c6->SetFrameFillStyle(0);
   c6->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: pad11
   TPad *pad11 = new TPad("pad11", "pad11",0,0.3,1,1);
   pad11->Draw();
   pad11->cd();
   pad11->Range(1.631579,-0.5703748,22.68421,2.223511);
   pad11->SetFillColor(0);
   pad11->SetBorderMode(0);
   pad11->SetBorderSize(2);
   // pad11->SetLogy();
   pad11->SetTickx(1);
   pad11->SetTicky(1);
   pad11->SetLeftMargin(0.16);
   pad11->SetRightMargin(0.08);
   pad11->SetTopMargin(0.08);
   pad11->SetBottomMargin(0.017);
   pad11->SetFrameFillStyle(0);
   pad11->SetFrameBorderMode(0);
   pad11->SetFrameFillStyle(0);
   pad11->SetFrameBorderMode(0);
   Double_t xAxis3[5] = {5, 9, 13, 17, 21}; 
   
   TH1D *hUnfoDataInvmass_xSec__11 = new TH1D("hUnfoDataInvmass_xSec__11","",4, xAxis3);
   hUnfoDataInvmass_xSec__11->SetBinContent(1,20.10558);
   hUnfoDataInvmass_xSec__11->SetBinContent(2,5.333797);
   hUnfoDataInvmass_xSec__11->SetBinContent(3,1.310625);
   hUnfoDataInvmass_xSec__11->SetBinContent(4,0);
   
   hUnfoDataInvmass_xSec__11->SetBinError(1,4.825339);
   hUnfoDataInvmass_xSec__11->SetBinError(2,1.280111);
   hUnfoDataInvmass_xSec__11->SetBinError(3,0.3145499);
   hUnfoDataInvmass_xSec__11->SetBinError(4,1.84);
   
   // hUnfoDataInvmass_xSec__11->SetMinimum(0.3);
   hUnfoDataInvmass_xSec__11->SetMinimum(0.0);
   // hUnfoDataInvmass_xSec__11->SetMaximum(100);
   hUnfoDataInvmass_xSec__11->SetMaximum(30);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = 1179;
   color = new TColor(ci, 0, 0, 0, " ", 0.5);
   hUnfoDataInvmass_xSec__11->SetFillColor(ci);
   hUnfoDataInvmass_xSec__11->SetFillStyle(3005);
   hUnfoDataInvmass_xSec__11->SetLineWidth(2);
   hUnfoDataInvmass_xSec__11->SetMarkerStyle(20);
   hUnfoDataInvmass_xSec__11->GetXaxis()->SetTitle("m^{#gamma#gamma} (GeV)");
   hUnfoDataInvmass_xSec__11->GetXaxis()->SetRange(1,4);
   hUnfoDataInvmass_xSec__11->GetXaxis()->SetLabelFont(42);
   hUnfoDataInvmass_xSec__11->GetXaxis()->SetLabelOffset(0.007);
   hUnfoDataInvmass_xSec__11->GetXaxis()->SetLabelSize(0);
   hUnfoDataInvmass_xSec__11->GetXaxis()->SetTitleSize(0.06);
   hUnfoDataInvmass_xSec__11->GetXaxis()->SetTitleOffset(1);
   hUnfoDataInvmass_xSec__11->GetXaxis()->SetTitleFont(42);
   hUnfoDataInvmass_xSec__11->GetYaxis()->SetTitle("#frac{d#sigma^{#gamma#gamma}}{dm^{#gamma#gamma}} (nb / 4 GeV)");
   hUnfoDataInvmass_xSec__11->GetYaxis()->SetLabelFont(42);
   hUnfoDataInvmass_xSec__11->GetYaxis()->SetLabelOffset(0.007);
   hUnfoDataInvmass_xSec__11->GetYaxis()->SetLabelSize(0.05);
   hUnfoDataInvmass_xSec__11->GetYaxis()->SetTitleSize(0.06);
   hUnfoDataInvmass_xSec__11->GetYaxis()->SetTitleOffset(1.1);
   hUnfoDataInvmass_xSec__11->GetYaxis()->SetTitleFont(42);
   hUnfoDataInvmass_xSec__11->GetZaxis()->SetLabelFont(42);
   hUnfoDataInvmass_xSec__11->GetZaxis()->SetLabelOffset(0.007);
   hUnfoDataInvmass_xSec__11->GetZaxis()->SetLabelSize(0.05);
   hUnfoDataInvmass_xSec__11->GetZaxis()->SetTitleSize(0.06);
   hUnfoDataInvmass_xSec__11->GetZaxis()->SetTitleOffset(1);
   hUnfoDataInvmass_xSec__11->GetZaxis()->SetTitleFont(42);
   hUnfoDataInvmass_xSec__11->Draw("e2");
   Double_t xAxis4[5] = {5, 9, 13, 17, 21}; 
   
   TH1D *hUnfoDataInvmass_xSec__12 = new TH1D("hUnfoDataInvmass_xSec__12","",4, xAxis4);
   hUnfoDataInvmass_xSec__12->SetBinContent(1,20.10558);
   hUnfoDataInvmass_xSec__12->SetBinContent(2,5.333797);
   hUnfoDataInvmass_xSec__12->SetBinContent(3,1.310625);
   hUnfoDataInvmass_xSec__12->SetBinContent(4,0);
   
   hUnfoDataInvmass_xSec__12->SetBinError(1,9.579709);
   hUnfoDataInvmass_xSec__12->SetBinError(2,3.517862);
   hUnfoDataInvmass_xSec__12->SetBinError(3,1.564104);
   hUnfoDataInvmass_xSec__12->SetBinError(4,1.48);

   hUnfoDataInvmass_xSec__12->SetMinimum(0.3);
   hUnfoDataInvmass_xSec__12->SetMaximum(100);
   
   hUnfoDataInvmass_xSec__12->SetLineWidth(2);
   hUnfoDataInvmass_xSec__12->SetMarkerStyle(20);
   hUnfoDataInvmass_xSec__12->GetXaxis()->SetTitle("m^{#gamma#gamma} (GeV)");
   hUnfoDataInvmass_xSec__12->GetXaxis()->SetLabelFont(42);
   hUnfoDataInvmass_xSec__12->GetXaxis()->SetLabelOffset(0.007);
   hUnfoDataInvmass_xSec__12->GetXaxis()->SetLabelSize(0.05);
   hUnfoDataInvmass_xSec__12->GetXaxis()->SetTitleSize(0.06);
   hUnfoDataInvmass_xSec__12->GetXaxis()->SetTitleOffset(1);
   hUnfoDataInvmass_xSec__12->GetXaxis()->SetTitleFont(42);
   hUnfoDataInvmass_xSec__12->GetYaxis()->SetTitle("#frac{d#sigma^{#gamma#gamma}}{dm^{#gamma#gamma}} (nb / 4 GeV)");
   hUnfoDataInvmass_xSec__12->GetYaxis()->SetLabelFont(42);
   hUnfoDataInvmass_xSec__12->GetYaxis()->SetLabelOffset(0.007);
   hUnfoDataInvmass_xSec__12->GetYaxis()->SetLabelSize(0.05);
   hUnfoDataInvmass_xSec__12->GetYaxis()->SetTitleSize(0.06);
   hUnfoDataInvmass_xSec__12->GetYaxis()->SetTitleOffset(1.1);
   hUnfoDataInvmass_xSec__12->GetYaxis()->SetTitleFont(42);
   hUnfoDataInvmass_xSec__12->GetZaxis()->SetLabelFont(42);
   hUnfoDataInvmass_xSec__12->GetZaxis()->SetLabelOffset(0.007);
   hUnfoDataInvmass_xSec__12->GetZaxis()->SetLabelSize(0.05);
   hUnfoDataInvmass_xSec__12->GetZaxis()->SetTitleSize(0.06);
   hUnfoDataInvmass_xSec__12->GetZaxis()->SetTitleOffset(1);
   hUnfoDataInvmass_xSec__12->GetZaxis()->SetTitleFont(42);
   hUnfoDataInvmass_xSec__12->Draw("psameex");
   Double_t xAxis5[5] = {5, 9, 13, 17, 21}; 
   
   TH1D *hGenInvmass_xSec__13 = new TH1D("hGenInvmass_xSec__13","",4, xAxis5);
   hGenInvmass_xSec__13->SetBinContent(1,16.72245);
   hGenInvmass_xSec__13->SetBinContent(2,4.207361);
   hGenInvmass_xSec__13->SetBinContent(3,1.304726);
   hGenInvmass_xSec__13->SetBinContent(4,0.5307833);
   
   hGenInvmass_xSec__13->SetBinError(1,0.1524323);
   hGenInvmass_xSec__13->SetBinError(2,0.07645956);
   hGenInvmass_xSec__13->SetBinError(3,0.04257814);
   hGenInvmass_xSec__13->SetBinError(4,0.02715723);
   
   

   ci = TColor::GetColor("#009999");
   hGenInvmass_xSec__13->SetLineColor(ci);
   hGenInvmass_xSec__13->SetLineWidth(2);

   ci = TColor::GetColor("#009999");
   hGenInvmass_xSec__13->SetMarkerColor(ci);
   hGenInvmass_xSec__13->SetMarkerStyle(2);
   hGenInvmass_xSec__13->GetXaxis()->SetTitle("m^{#gamma#gamma} (GeV)");
   hGenInvmass_xSec__13->GetXaxis()->SetLabelFont(42);
   hGenInvmass_xSec__13->GetXaxis()->SetLabelOffset(0.007);
   hGenInvmass_xSec__13->GetXaxis()->SetLabelSize(0.05);
   hGenInvmass_xSec__13->GetXaxis()->SetTitleSize(0.06);
   hGenInvmass_xSec__13->GetXaxis()->SetTitleOffset(1);
   hGenInvmass_xSec__13->GetXaxis()->SetTitleFont(42);
   hGenInvmass_xSec__13->GetYaxis()->SetTitle("#frac{d#sigma^{#gamma#gamma}}{dm^{#gamma#gamma}} (nb / 4 GeV)");
   hGenInvmass_xSec__13->GetYaxis()->SetLabelFont(42);
   hGenInvmass_xSec__13->GetYaxis()->SetLabelOffset(0.007);
   hGenInvmass_xSec__13->GetYaxis()->SetLabelSize(0.05);
   hGenInvmass_xSec__13->GetYaxis()->SetTitleSize(0.06);
   hGenInvmass_xSec__13->GetYaxis()->SetTitleOffset(1.1);
   hGenInvmass_xSec__13->GetYaxis()->SetTitleFont(42);
   hGenInvmass_xSec__13->GetZaxis()->SetLabelFont(42);
   hGenInvmass_xSec__13->GetZaxis()->SetLabelOffset(0.007);
   hGenInvmass_xSec__13->GetZaxis()->SetLabelSize(0.05);
   hGenInvmass_xSec__13->GetZaxis()->SetTitleSize(0.06);
   hGenInvmass_xSec__13->GetZaxis()->SetTitleOffset(1);
   hGenInvmass_xSec__13->GetZaxis()->SetTitleFont(42);
   hGenInvmass_xSec__13->Draw("psame");
   Double_t xAxis6[5] = {5, 9, 13, 17, 21}; 
   
   TH1D *hGenInvmass_xSec__14 = new TH1D("hGenInvmass_xSec__14","",4, xAxis6);
   hGenInvmass_xSec__14->SetBinContent(1,16.72245);
   hGenInvmass_xSec__14->SetBinContent(2,4.207361);
   hGenInvmass_xSec__14->SetBinContent(3,1.304726);
   hGenInvmass_xSec__14->SetBinContent(4,0.5307833);
   
   hGenInvmass_xSec__14->SetBinError(1,0.1524323);
   hGenInvmass_xSec__14->SetBinError(2,0.07645956);
   hGenInvmass_xSec__14->SetBinError(3,0.04257814);
   hGenInvmass_xSec__14->SetBinError(4,0.02715723);
   
   

   ci = TColor::GetColor("#009999");
   hGenInvmass_xSec__14->SetLineColor(ci);
   hGenInvmass_xSec__14->SetLineWidth(2);

   ci = TColor::GetColor("#009999");
   hGenInvmass_xSec__14->SetMarkerColor(ci);
   hGenInvmass_xSec__14->SetMarkerStyle(2);
   hGenInvmass_xSec__14->GetXaxis()->SetTitle("m^{#gamma#gamma} (GeV)");
   hGenInvmass_xSec__14->GetXaxis()->SetLabelFont(42);
   hGenInvmass_xSec__14->GetXaxis()->SetLabelOffset(0.007);
   hGenInvmass_xSec__14->GetXaxis()->SetLabelSize(0.05);
   hGenInvmass_xSec__14->GetXaxis()->SetTitleSize(0.06);
   hGenInvmass_xSec__14->GetXaxis()->SetTitleOffset(1);
   hGenInvmass_xSec__14->GetXaxis()->SetTitleFont(42);
   hGenInvmass_xSec__14->GetYaxis()->SetTitle("#frac{d#sigma^{#gamma#gamma}}{dm^{#gamma#gamma}} (nb / 4 GeV)");
   hGenInvmass_xSec__14->GetYaxis()->SetLabelFont(42);
   hGenInvmass_xSec__14->GetYaxis()->SetLabelOffset(0.007);
   hGenInvmass_xSec__14->GetYaxis()->SetLabelSize(0.05);
   hGenInvmass_xSec__14->GetYaxis()->SetTitleSize(0.06);
   hGenInvmass_xSec__14->GetYaxis()->SetTitleOffset(1.1);
   hGenInvmass_xSec__14->GetYaxis()->SetTitleFont(42);
   hGenInvmass_xSec__14->GetZaxis()->SetLabelFont(42);
   hGenInvmass_xSec__14->GetZaxis()->SetLabelOffset(0.007);
   hGenInvmass_xSec__14->GetZaxis()->SetLabelSize(0.05);
   hGenInvmass_xSec__14->GetZaxis()->SetTitleSize(0.06);
   hGenInvmass_xSec__14->GetZaxis()->SetTitleOffset(1);
   hGenInvmass_xSec__14->GetZaxis()->SetTitleFont(42);
   hGenInvmass_xSec__14->Draw("histsame");
   Double_t xAxis7[5] = {5, 9, 13, 17, 21}; 
   
   TH1D *hUnfoDataInvmass_xSec__15 = new TH1D("hUnfoDataInvmass_xSec__15","",4, xAxis7);
   
   hUnfoDataInvmass_xSec__15->SetBinContent(1,20.10558);
   hUnfoDataInvmass_xSec__15->SetBinContent(2,5.333797);
   hUnfoDataInvmass_xSec__15->SetBinContent(3,1.310625);
   hUnfoDataInvmass_xSec__15->SetBinContent(4,0);

   hUnfoDataInvmass_xSec__15->SetBinError(1,9.579709);
   hUnfoDataInvmass_xSec__15->SetBinError(2,3.517862);
   hUnfoDataInvmass_xSec__15->SetBinError(3,1.564104);
   hUnfoDataInvmass_xSec__15->SetBinError(4,1.84);

   hUnfoDataInvmass_xSec__15->SetMinimum(0.3);
   hUnfoDataInvmass_xSec__15->SetMaximum(100);
   
   hUnfoDataInvmass_xSec__15->SetLineWidth(2);
   hUnfoDataInvmass_xSec__15->SetMarkerStyle(20);
   hUnfoDataInvmass_xSec__15->GetXaxis()->SetTitle("m^{#gamma#gamma} (GeV)");
   hUnfoDataInvmass_xSec__15->GetXaxis()->SetLabelFont(42);
   hUnfoDataInvmass_xSec__15->GetXaxis()->SetLabelOffset(0.007);
   hUnfoDataInvmass_xSec__15->GetXaxis()->SetLabelSize(0.05);
   hUnfoDataInvmass_xSec__15->GetXaxis()->SetTitleSize(0.06);
   hUnfoDataInvmass_xSec__15->GetXaxis()->SetTitleOffset(1);
   hUnfoDataInvmass_xSec__15->GetXaxis()->SetTitleFont(42);
   hUnfoDataInvmass_xSec__15->GetYaxis()->SetTitle("#frac{d#sigma^{#gamma#gamma}}{dm^{#gamma#gamma}} (nb / 4 GeV)");
   hUnfoDataInvmass_xSec__15->GetYaxis()->SetLabelFont(42);
   hUnfoDataInvmass_xSec__15->GetYaxis()->SetLabelOffset(0.007);
   hUnfoDataInvmass_xSec__15->GetYaxis()->SetLabelSize(0.05);
   hUnfoDataInvmass_xSec__15->GetYaxis()->SetTitleSize(0.06);
   hUnfoDataInvmass_xSec__15->GetYaxis()->SetTitleOffset(1.1);
   hUnfoDataInvmass_xSec__15->GetYaxis()->SetTitleFont(42);
   hUnfoDataInvmass_xSec__15->GetZaxis()->SetLabelFont(42);
   hUnfoDataInvmass_xSec__15->GetZaxis()->SetLabelOffset(0.007);
   hUnfoDataInvmass_xSec__15->GetZaxis()->SetLabelSize(0.05);
   hUnfoDataInvmass_xSec__15->GetZaxis()->SetTitleSize(0.06);
   hUnfoDataInvmass_xSec__15->GetZaxis()->SetTitleOffset(1);
   hUnfoDataInvmass_xSec__15->GetZaxis()->SetTitleFont(42);
   hUnfoDataInvmass_xSec__15->Draw("psameex0");
   Double_t xAxis8[5] = {5, 9, 13, 17, 21}; 
   
   TH1F *hgammaUPC_LbL_Invmass__16 = new TH1F("hgammaUPC_LbL_Invmass__16","d#sigma/dm_{inv} (pb/GeV) photon pairs (after cuts) [LbL]",4, xAxis8);
   hgammaUPC_LbL_Invmass__16->SetBinContent(1,17.17089);
   hgammaUPC_LbL_Invmass__16->SetBinContent(2,4.355528);
   hgammaUPC_LbL_Invmass__16->SetBinContent(3,1.342409);
   hgammaUPC_LbL_Invmass__16->SetBinContent(4,0.5182647);
   

   hgammaUPC_LbL_Invmass__16->SetBinError(1,0.03195681);
   hgammaUPC_LbL_Invmass__16->SetBinError(2,0.01609487);
   hgammaUPC_LbL_Invmass__16->SetBinError(3,0.008935306);
   hgammaUPC_LbL_Invmass__16->SetBinError(4,0.005551915);
   
   ci = TColor::GetColor("#000099");
   hgammaUPC_LbL_Invmass__16->SetLineColor(ci);
   hgammaUPC_LbL_Invmass__16->SetLineWidth(2);

   ci = TColor::GetColor("#000099");
   hgammaUPC_LbL_Invmass__16->SetMarkerColor(ci);
   hgammaUPC_LbL_Invmass__16->SetMarkerStyle(2);
   hgammaUPC_LbL_Invmass__16->GetXaxis()->SetTitle("m^{#gamma#gamma} (GeV)");
   hgammaUPC_LbL_Invmass__16->GetXaxis()->SetRange(1,500);
   hgammaUPC_LbL_Invmass__16->GetXaxis()->SetLabelFont(42);
   hgammaUPC_LbL_Invmass__16->GetXaxis()->SetLabelOffset(0.007);
   hgammaUPC_LbL_Invmass__16->GetXaxis()->SetLabelSize(0.05);
   hgammaUPC_LbL_Invmass__16->GetXaxis()->SetTitleSize(0.06);
   hgammaUPC_LbL_Invmass__16->GetXaxis()->SetTitleOffset(1);
   hgammaUPC_LbL_Invmass__16->GetXaxis()->SetTitleFont(42);
   hgammaUPC_LbL_Invmass__16->GetYaxis()->SetTitle("#frac{d#sigma^{#gamma#gamma}}{dm^{#gamma#gamma}} (nb / 4 GeV)");
   hgammaUPC_LbL_Invmass__16->GetYaxis()->SetLabelFont(42);
   hgammaUPC_LbL_Invmass__16->GetYaxis()->SetLabelOffset(0.007);
   hgammaUPC_LbL_Invmass__16->GetYaxis()->SetLabelSize(0.05);
   hgammaUPC_LbL_Invmass__16->GetYaxis()->SetTitleSize(0.06);
   hgammaUPC_LbL_Invmass__16->GetYaxis()->SetTitleOffset(1.1);
   hgammaUPC_LbL_Invmass__16->GetYaxis()->SetTitleFont(42);
   hgammaUPC_LbL_Invmass__16->GetZaxis()->SetLabelFont(42);
   hgammaUPC_LbL_Invmass__16->GetZaxis()->SetLabelOffset(0.007);
   hgammaUPC_LbL_Invmass__16->GetZaxis()->SetLabelSize(0.05);
   hgammaUPC_LbL_Invmass__16->GetZaxis()->SetTitleSize(0.06);
   hgammaUPC_LbL_Invmass__16->GetZaxis()->SetTitleOffset(1);
   hgammaUPC_LbL_Invmass__16->GetZaxis()->SetTitleFont(42);
   hgammaUPC_LbL_Invmass__16->Draw("histsame");
   Double_t xAxis9[5] = {5, 9, 13, 17, 21}; 
   
   TH1F *hgammaUPC_LbL_Invmass__17 = new TH1F("hgammaUPC_LbL_Invmass__17","d#sigma/dm_{inv} (pb/GeV) photon pairs (after cuts) [LbL]",4, xAxis9);
   hgammaUPC_LbL_Invmass__17->SetBinContent(1,17.17089);
   hgammaUPC_LbL_Invmass__17->SetBinContent(2,4.355528);
   hgammaUPC_LbL_Invmass__17->SetBinContent(3,1.342409);
   hgammaUPC_LbL_Invmass__17->SetBinContent(4,0.5182647);
   
   hgammaUPC_LbL_Invmass__17->SetBinError(1,0.03195681);
   hgammaUPC_LbL_Invmass__17->SetBinError(2,0.01609487);
   hgammaUPC_LbL_Invmass__17->SetBinError(3,0.008935306);
   hgammaUPC_LbL_Invmass__17->SetBinError(4,0.005551915);
   
   ci = TColor::GetColor("#000099");
   hgammaUPC_LbL_Invmass__17->SetLineColor(ci);
   hgammaUPC_LbL_Invmass__17->SetLineWidth(2);

   ci = TColor::GetColor("#000099");
   hgammaUPC_LbL_Invmass__17->SetMarkerColor(ci);
   hgammaUPC_LbL_Invmass__17->SetMarkerStyle(2);
   hgammaUPC_LbL_Invmass__17->GetXaxis()->SetTitle("m^{#gamma#gamma} (GeV)");
   hgammaUPC_LbL_Invmass__17->GetXaxis()->SetRange(1,500);
   hgammaUPC_LbL_Invmass__17->GetXaxis()->SetLabelFont(42);
   hgammaUPC_LbL_Invmass__17->GetXaxis()->SetLabelOffset(0.007);
   hgammaUPC_LbL_Invmass__17->GetXaxis()->SetLabelSize(0.05);
   hgammaUPC_LbL_Invmass__17->GetXaxis()->SetTitleSize(0.06);
   hgammaUPC_LbL_Invmass__17->GetXaxis()->SetTitleOffset(1);
   hgammaUPC_LbL_Invmass__17->GetXaxis()->SetTitleFont(42);
   hgammaUPC_LbL_Invmass__17->GetYaxis()->SetTitle("#frac{d#sigma^{#gamma#gamma}}{dm^{#gamma#gamma}} (nb / 4 GeV)");
   hgammaUPC_LbL_Invmass__17->GetYaxis()->SetLabelFont(42);
   hgammaUPC_LbL_Invmass__17->GetYaxis()->SetLabelOffset(0.007);
   hgammaUPC_LbL_Invmass__17->GetYaxis()->SetLabelSize(0.05);
   hgammaUPC_LbL_Invmass__17->GetYaxis()->SetTitleSize(0.06);
   hgammaUPC_LbL_Invmass__17->GetYaxis()->SetTitleOffset(1.1);
   hgammaUPC_LbL_Invmass__17->GetYaxis()->SetTitleFont(42);
   hgammaUPC_LbL_Invmass__17->GetZaxis()->SetLabelFont(42);
   hgammaUPC_LbL_Invmass__17->GetZaxis()->SetLabelOffset(0.007);
   hgammaUPC_LbL_Invmass__17->GetZaxis()->SetLabelSize(0.05);
   hgammaUPC_LbL_Invmass__17->GetZaxis()->SetTitleSize(0.06);
   hgammaUPC_LbL_Invmass__17->GetZaxis()->SetTitleOffset(1);
   hgammaUPC_LbL_Invmass__17->GetZaxis()->SetTitleFont(42);
   hgammaUPC_LbL_Invmass__17->Draw("psamex0");
   
   TLegend *leg = new TLegend(0.4,0.68,0.9,0.9,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(43);
   leg->SetTextSize(20);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("NULL","#gamma#gamma#rightarrow #gamma#gamma","h");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(43);
   entry=leg->AddEntry("hUnfoDataRap_xSec","Data ","EP");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(43);
   entry=leg->AddEntry("hUnfoDataRap_xSec","gamma-UPC@NLO","pl");

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#000099");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(22);
   entry->SetMarkerSize(1);
   entry->SetTextFont(43);
   entry=leg->AddEntry("hUnfoDataRap_xSec","SUPERCHIC","pl");

   ci = TColor::GetColor("#009999");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#009999");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(43);
   leg->Draw();
   pad11->Modified();
   c6->cd();
   TLatex *   tex = new TLatex(0.16,0.96,"#bf{CMS} #it{Preliminary}");
   tex->SetTextFont(42);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.52,0.96,"#scale[0.8]{PbPb, 1.64 nb^{-1} (#sqrt{s_{NN}} = 5.02 TeV)}");
   tex->SetTextFont(42);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
  
// ------------>Primitives in pad: pad12
   TPad *pad12 = new TPad("pad12", "pad12",0,0.06,1,0.28);
   pad12->Draw();
   pad12->cd();
   pad12->Range(1.631579,-2.494433,22.68421,3.270974);
   pad12->SetFillColor(0);
   pad12->SetBorderMode(0);
   pad12->SetBorderSize(2);
   pad12->SetTickx(1);
   pad12->SetTicky(1);
   pad12->SetLeftMargin(0.16);
   pad12->SetRightMargin(0.08);
   pad12->SetTopMargin(0.047);
   pad12->SetBottomMargin(0.45);
   pad12->SetFrameFillStyle(0);
   pad12->SetFrameBorderMode(0);
   pad12->SetFrameFillStyle(0);
   pad12->SetFrameBorderMode(0);
   Double_t xAxis10[6] = {5, 9, 13, 17, 21, 25}; 
   
   TH1D *hUnfoDataInvmass_xSec__18 = new TH1D("hUnfoDataInvmass_xSec__18","",5, xAxis10);
   hUnfoDataInvmass_xSec__18->SetBinContent(1,1.20231);
   hUnfoDataInvmass_xSec__18->SetBinContent(2,1.26773);
   hUnfoDataInvmass_xSec__18->SetBinContent(3,1.004521);
   hUnfoDataInvmass_xSec__18->SetBinError(1,0.5729699);
   hUnfoDataInvmass_xSec__18->SetBinError(2,0.8364382);
   hUnfoDataInvmass_xSec__18->SetBinError(3,1.199247);
   hUnfoDataInvmass_xSec__18->SetBinError(4,2.788332);
   hUnfoDataInvmass_xSec__18->SetMinimum(0.1);
   hUnfoDataInvmass_xSec__18->SetMaximum(3);
   hUnfoDataInvmass_xSec__18->SetEntries(1.178858);

   ci = TColor::GetColor("#009999");
   hUnfoDataInvmass_xSec__18->SetLineColor(ci);
   hUnfoDataInvmass_xSec__18->SetLineWidth(2);

   ci = TColor::GetColor("#009999");
   hUnfoDataInvmass_xSec__18->SetMarkerColor(ci);
   hUnfoDataInvmass_xSec__18->SetMarkerStyle(20);
   hUnfoDataInvmass_xSec__18->GetXaxis()->SetTitle("m^{#gamma#gamma} (GeV)");
   hUnfoDataInvmass_xSec__18->GetXaxis()->SetRange(1,4);
   hUnfoDataInvmass_xSec__18->GetXaxis()->SetLabelFont(43);
   hUnfoDataInvmass_xSec__18->GetXaxis()->SetLabelOffset(0.007);
   hUnfoDataInvmass_xSec__18->GetXaxis()->SetLabelSize(20);
   hUnfoDataInvmass_xSec__18->GetXaxis()->SetTitleSize(20);
   hUnfoDataInvmass_xSec__18->GetXaxis()->SetTitleOffset(1);
   hUnfoDataInvmass_xSec__18->GetXaxis()->SetTitleFont(43);
   hUnfoDataInvmass_xSec__18->GetYaxis()->SetTitle(" #frac{Data}{Exp.}");
   hUnfoDataInvmass_xSec__18->GetYaxis()->SetNdivisions(5);
   hUnfoDataInvmass_xSec__18->GetYaxis()->SetLabelFont(43);
   hUnfoDataInvmass_xSec__18->GetYaxis()->SetLabelOffset(0.007);
   hUnfoDataInvmass_xSec__18->GetYaxis()->SetLabelSize(20);
   hUnfoDataInvmass_xSec__18->GetYaxis()->SetTitleSize(22);
   hUnfoDataInvmass_xSec__18->GetYaxis()->SetTitleOffset(2);
   hUnfoDataInvmass_xSec__18->GetYaxis()->SetTitleFont(43);
   hUnfoDataInvmass_xSec__18->GetZaxis()->SetLabelFont(42);
   hUnfoDataInvmass_xSec__18->GetZaxis()->SetLabelOffset(0.007);
   hUnfoDataInvmass_xSec__18->GetZaxis()->SetLabelSize(0.05);
   hUnfoDataInvmass_xSec__18->GetZaxis()->SetTitleSize(0.06);
   hUnfoDataInvmass_xSec__18->GetZaxis()->SetTitleOffset(1);
   hUnfoDataInvmass_xSec__18->GetZaxis()->SetTitleFont(42);
   hUnfoDataInvmass_xSec__18->Draw("pex0");
   Double_t xAxis11[6] = {5, 9, 13, 17, 21, 25}; 
   
   TH1D *hUnfoDataInvmass_xSec__19 = new TH1D("hUnfoDataInvmass_xSec__19","",5, xAxis11);
   hUnfoDataInvmass_xSec__19->SetBinContent(1,1.170911);
   hUnfoDataInvmass_xSec__19->SetBinContent(2,1.224604);
   hUnfoDataInvmass_xSec__19->SetBinContent(3,0.9763231);
   hUnfoDataInvmass_xSec__19->SetBinError(1,0.5579083);
   hUnfoDataInvmass_xSec__19->SetBinError(2,0.8076901);
   hUnfoDataInvmass_xSec__19->SetBinError(3,1.165165);
   hUnfoDataInvmass_xSec__19->SetBinError(4,2.855684);
   hUnfoDataInvmass_xSec__19->SetMinimum(0);
   hUnfoDataInvmass_xSec__19->SetMaximum(4);
   hUnfoDataInvmass_xSec__19->SetEntries(1.085253);

   ci = TColor::GetColor("#000099");
   hUnfoDataInvmass_xSec__19->SetLineColor(ci);
   hUnfoDataInvmass_xSec__19->SetLineWidth(2);

   ci = TColor::GetColor("#000099");
   hUnfoDataInvmass_xSec__19->SetMarkerColor(ci);
   hUnfoDataInvmass_xSec__19->SetMarkerStyle(22);
   hUnfoDataInvmass_xSec__19->GetXaxis()->SetTitle("m^{#gamma#gamma} (GeV)");
   hUnfoDataInvmass_xSec__19->GetXaxis()->SetLabelFont(42);
   hUnfoDataInvmass_xSec__19->GetXaxis()->SetLabelOffset(0.007);
   hUnfoDataInvmass_xSec__19->GetXaxis()->SetLabelSize(0.05);
   hUnfoDataInvmass_xSec__19->GetXaxis()->SetTitleSize(0.06);
   hUnfoDataInvmass_xSec__19->GetXaxis()->SetTitleOffset(1);
   hUnfoDataInvmass_xSec__19->GetXaxis()->SetTitleFont(42);
   hUnfoDataInvmass_xSec__19->GetYaxis()->SetTitle("#frac{d#sigma^{#gamma#gamma}}{dm^{#gamma#gamma}} (nb / 4 GeV)");
   hUnfoDataInvmass_xSec__19->GetYaxis()->SetNdivisions(5);
   hUnfoDataInvmass_xSec__19->GetYaxis()->SetLabelFont(42);
   hUnfoDataInvmass_xSec__19->GetYaxis()->SetLabelOffset(0.007);
   hUnfoDataInvmass_xSec__19->GetYaxis()->SetLabelSize(0.05);
   hUnfoDataInvmass_xSec__19->GetYaxis()->SetTitleSize(0.06);
   hUnfoDataInvmass_xSec__19->GetYaxis()->SetTitleOffset(1.1);
   hUnfoDataInvmass_xSec__19->GetYaxis()->SetTitleFont(42);
   hUnfoDataInvmass_xSec__19->GetZaxis()->SetLabelFont(42);
   hUnfoDataInvmass_xSec__19->GetZaxis()->SetLabelOffset(0.007);
   hUnfoDataInvmass_xSec__19->GetZaxis()->SetLabelSize(0.05);
   hUnfoDataInvmass_xSec__19->GetZaxis()->SetTitleSize(0.06);
   hUnfoDataInvmass_xSec__19->GetZaxis()->SetTitleOffset(1);
   hUnfoDataInvmass_xSec__19->GetZaxis()->SetTitleFont(42);
   hUnfoDataInvmass_xSec__19->Draw("pex0same");
   Double_t xAxis12[6] = {5, 9, 13, 17, 21, 25}; 
   
   TH1D *hUnfoDataInvmass_xSec__20 = new TH1D("hUnfoDataInvmass_xSec__20","",5, xAxis12);
   hUnfoDataInvmass_xSec__20->SetBinContent(1,1);
   hUnfoDataInvmass_xSec__20->SetBinContent(2,1);
   hUnfoDataInvmass_xSec__20->SetBinContent(3,1);
   hUnfoDataInvmass_xSec__20->SetBinError(1,0.3394113);
   hUnfoDataInvmass_xSec__20->SetBinError(2,0.3394113);
   hUnfoDataInvmass_xSec__20->SetBinError(3,0.3394113);
   hUnfoDataInvmass_xSec__20->SetMinimum(0.3);
   hUnfoDataInvmass_xSec__20->SetMaximum(100);
   hUnfoDataInvmass_xSec__20->SetEntries(26.04167);

   ci = 1179;
   color = new TColor(ci, 0, 0, 0, " ", 0.5);
   hUnfoDataInvmass_xSec__20->SetFillColor(ci);
   hUnfoDataInvmass_xSec__20->SetFillStyle(3005);

   ci = TColor::GetColor("#009999");
   hUnfoDataInvmass_xSec__20->SetLineColor(ci);
   hUnfoDataInvmass_xSec__20->SetLineStyle(2);
   hUnfoDataInvmass_xSec__20->SetLineWidth(2);

   ci = TColor::GetColor("#009999");
   hUnfoDataInvmass_xSec__20->SetMarkerColor(ci);
   hUnfoDataInvmass_xSec__20->SetMarkerStyle(0);
   hUnfoDataInvmass_xSec__20->GetXaxis()->SetTitle("m^{#gamma#gamma} (GeV)");
   hUnfoDataInvmass_xSec__20->GetXaxis()->SetRange(1,4);
   hUnfoDataInvmass_xSec__20->GetXaxis()->SetLabelFont(42);
   hUnfoDataInvmass_xSec__20->GetXaxis()->SetLabelOffset(0.007);
   hUnfoDataInvmass_xSec__20->GetXaxis()->SetLabelSize(0.05);
   hUnfoDataInvmass_xSec__20->GetXaxis()->SetTitleSize(0.06);
   hUnfoDataInvmass_xSec__20->GetXaxis()->SetTitleOffset(1);
   hUnfoDataInvmass_xSec__20->GetXaxis()->SetTitleFont(42);
   hUnfoDataInvmass_xSec__20->GetYaxis()->SetTitle("#frac{d#sigma^{#gamma#gamma}}{dm^{#gamma#gamma}} (nb / 4 GeV)");
   hUnfoDataInvmass_xSec__20->GetYaxis()->SetLabelFont(42);
   hUnfoDataInvmass_xSec__20->GetYaxis()->SetLabelOffset(0.007);
   hUnfoDataInvmass_xSec__20->GetYaxis()->SetLabelSize(0.05);
   hUnfoDataInvmass_xSec__20->GetYaxis()->SetTitleSize(0.06);
   hUnfoDataInvmass_xSec__20->GetYaxis()->SetTitleOffset(1.1);
   hUnfoDataInvmass_xSec__20->GetYaxis()->SetTitleFont(42);
   hUnfoDataInvmass_xSec__20->GetZaxis()->SetLabelFont(42);
   hUnfoDataInvmass_xSec__20->GetZaxis()->SetLabelOffset(0.007);
   hUnfoDataInvmass_xSec__20->GetZaxis()->SetLabelSize(0.05);
   hUnfoDataInvmass_xSec__20->GetZaxis()->SetTitleSize(0.06);
   hUnfoDataInvmass_xSec__20->GetZaxis()->SetTitleOffset(1);
   hUnfoDataInvmass_xSec__20->GetZaxis()->SetTitleFont(42);
   hUnfoDataInvmass_xSec__20->Draw("e2same");
   
   TF1 *line2 = new TF1("line","1",-100,100, TF1::EAddToList::kDefault);
   line2->SetFillColor(19);
   line2->SetFillStyle(0);
   line2->SetMarkerStyle(20);
   line2->SetLineStyle(2);
   line2->SetLineWidth(1);
   line2->GetXaxis()->SetLabelFont(42);
   line2->GetXaxis()->SetLabelOffset(0.007);
   line2->GetXaxis()->SetLabelSize(0.05);
   line2->GetXaxis()->SetTitleSize(0.06);
   line2->GetXaxis()->SetTitleOffset(0.9);
   line2->GetXaxis()->SetTitleFont(42);
   line2->GetYaxis()->SetLabelFont(42);
   line2->GetYaxis()->SetLabelOffset(0.007);
   line2->GetYaxis()->SetLabelSize(0.05);
   line2->GetYaxis()->SetTitleSize(0.06);
   line2->GetYaxis()->SetTitleOffset(1);
   line2->GetYaxis()->SetTitleFont(42);
   line2->Draw("same");
   pad12->Modified();
   c6->cd();
   c6->Modified();
   c6->cd();
   c6->SetSelected(c6);
   c6->SaveAs("figures/Figure_007_b.pdf");  
}
