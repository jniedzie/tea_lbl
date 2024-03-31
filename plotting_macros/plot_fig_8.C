#ifdef __CLING__
#pragma cling optimize(0)
#endif
void plot_fig_8()
{
   gROOT->SetBatch(kTRUE);
//=========Macro generated from canvas: canvas/
//=========  (Sun Mar 31 12:55:07 2024) by ROOT version 6.26/08
   TCanvas *canvas = new TCanvas("canvas", "",0,0,800,600);
   canvas->SetHighLightColor(2);
   canvas->Range(0.438764,-1.19794,2.173471,4.135393);
   canvas->SetFillColor(0);
   canvas->SetBorderMode(0);
   canvas->SetBorderSize(2);
   canvas->SetLogx();
   canvas->SetLogy();
   canvas->SetLeftMargin(0.15);
   canvas->SetBottomMargin(0.15);
   canvas->SetFrameBorderMode(0);
   canvas->SetFrameBorderMode(0);
   
   Double_t _fx3001[9] = {
   5,
   6,
   9,
   11,
   14,
   16,
   22,
   30,
   90};
   Double_t _fy3001[9] = {
   276.25,
   66.875,
   25.312,
   18.75,
   12.031,
   9.102,
   6.914,
   5.195,
   4.746};
   Double_t _felx3001[9] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3001[9] = {
   142.441,
   35.005,
   13.743,
   10.327,
   6.955,
   5.902,
   4.483,
   3.49,
   3.337};
   Double_t _fehx3001[9] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3001[9] = {
   338.679,
   84.664,
   34.545,
   26.544,
   19.178,
   16.819,
   13.563,
   10.555,
   9.645};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(9,_fx3001,_fy3001,_felx3001,_fehx3001,_fely3001,_fehy3001);
   grae->SetName("");
   grae->SetTitle("");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#cccc00");
   grae->SetFillColor(ci);
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   
   TH1F *Graph_Graph3001 = new TH1F("Graph_Graph3001","",100,5,100);
   Graph_Graph3001->SetMinimum(0.4);
   Graph_Graph3001->SetMaximum(4000);
   Graph_Graph3001->SetDirectory(0);
   Graph_Graph3001->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph3001->SetLineColor(ci);
   Graph_Graph3001->GetXaxis()->SetTitle("m_{a} (GeV)");
   Graph_Graph3001->GetXaxis()->SetMoreLogLabels();
   Graph_Graph3001->GetXaxis()->SetLabelFont(42);
   Graph_Graph3001->GetXaxis()->SetLabelSize(0.04);
   Graph_Graph3001->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph3001->GetXaxis()->SetTitleOffset(1.1);
   Graph_Graph3001->GetXaxis()->SetTitleFont(42);
   Graph_Graph3001->GetYaxis()->SetTitle("#sigma_{#gamma #gamma #rightarrow a #rightarrow #gamma #gamma} (nb)");
   Graph_Graph3001->GetYaxis()->SetLabelFont(42);
   Graph_Graph3001->GetYaxis()->SetLabelSize(0.04);
   Graph_Graph3001->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph3001->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph3001->GetYaxis()->SetTitleFont(42);
   Graph_Graph3001->GetZaxis()->SetLabelFont(42);
   Graph_Graph3001->GetZaxis()->SetTitleOffset(1);
   Graph_Graph3001->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3001);
   
   grae->Draw("a3");
   
   Double_t _fx3002[9] = {
   5,
   6,
   9,
   11,
   14,
   16,
   22,
   30,
   90};
   Double_t _fy3002[9] = {
   276.25,
   66.875,
   25.312,
   18.75,
   12.031,
   9.102,
   6.914,
   5.195,
   4.746};
   Double_t _felx3002[9] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3002[9] = {
   90.139,
   22.152,
   8.804,
   6.616,
   4.51,
   3.873,
   2.942,
   2.345,
   2.268};
   Double_t _fehx3002[9] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3002[9] = {
   143.149,
   35.986,
   14.53,
   10.987,
   7.769,
   6.747,
   5.347,
   4.432,
   4.427};
   grae = new TGraphAsymmErrors(9,_fx3002,_fy3002,_felx3002,_fehx3002,_fely3002,_fehy3002);
   grae->SetName("");
   grae->SetTitle("");

   ci = TColor::GetColor("#00cc00");
   grae->SetFillColor(ci);
   grae->SetFillStyle(1000);
   grae->SetLineWidth(0);
   
   TH1F *Graph_Graph3002 = new TH1F("Graph_Graph3002","",100,4.5,98.5);
   Graph_Graph3002->SetMinimum(2.2302);
   Graph_Graph3002->SetMaximum(461.0911);
   Graph_Graph3002->SetDirectory(0);
   Graph_Graph3002->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph3002->SetLineColor(ci);
   Graph_Graph3002->GetXaxis()->SetLabelFont(42);
   Graph_Graph3002->GetXaxis()->SetTitleOffset(1);
   Graph_Graph3002->GetXaxis()->SetTitleFont(42);
   Graph_Graph3002->GetYaxis()->SetLabelFont(42);
   Graph_Graph3002->GetYaxis()->SetTitleFont(42);
   Graph_Graph3002->GetZaxis()->SetLabelFont(42);
   Graph_Graph3002->GetZaxis()->SetTitleOffset(1);
   Graph_Graph3002->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3002);
   
   grae->Draw("3");
   
   Double_t _fx3003[9] = {
   5,
   6,
   9,
   11,
   14,
   16,
   22,
   30,
   90};
   Double_t _fy3003[9] = {
   276.25,
   66.875,
   25.312,
   18.75,
   12.031,
   9.102,
   6.914,
   5.195,
   4.746};
   Double_t _felx3003[9] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3003[9] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t _fehx3003[9] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3003[9] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   grae = new TGraphAsymmErrors(9,_fx3003,_fy3003,_felx3003,_fehx3003,_fely3003,_fehy3003);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillStyle(1000);
   grae->SetLineStyle(2);
   grae->SetLineWidth(2);
   
   TH1F *Graph_Graph3003 = new TH1F("Graph_Graph3003","",100,4.5,98.5);
   Graph_Graph3003->SetMinimum(4.2714);
   Graph_Graph3003->SetMaximum(303.4004);
   Graph_Graph3003->SetDirectory(0);
   Graph_Graph3003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph3003->SetLineColor(ci);
   Graph_Graph3003->GetXaxis()->SetLabelFont(42);
   Graph_Graph3003->GetXaxis()->SetTitleOffset(1);
   Graph_Graph3003->GetXaxis()->SetTitleFont(42);
   Graph_Graph3003->GetYaxis()->SetLabelFont(42);
   Graph_Graph3003->GetYaxis()->SetTitleFont(42);
   Graph_Graph3003->GetZaxis()->SetLabelFont(42);
   Graph_Graph3003->GetZaxis()->SetTitleOffset(1);
   Graph_Graph3003->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3003);
   
   grae->Draw("l");
   
   Double_t _fx1[9] = {
   5,
   6,
   9,
   11,
   14,
   16,
   22,
   30,
   90};
   Double_t _fy1[9] = {
   230.219,
   56.454,
   19.312,
   20.954,
   11.689,
   8.599,
   5.565,
   4.708,
   4.746};
   TGraph *graph = new TGraph(9,_fx1,_fy1);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillStyle(1000);
   graph->SetLineWidth(2);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","",100,4.5,98.5);
   Graph_Graph1->SetMinimum(4.2372);
   Graph_Graph1->SetMaximum(252.7701);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1->SetLineColor(ci);
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetTitleOffset(1);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetTitleOffset(1);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph1);
   
   graph->Draw("l");
   
   TLegend *leg = new TLegend(0.55,0.65,0.9,0.9,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.04);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("","Observed","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("","Expected","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(2);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("","Expected #pm 1 #sigma","F");

   ci = TColor::GetColor("#00cc00");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1000);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("","Expected #pm 2 #sigma","F");

   ci = TColor::GetColor("#cccc00");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1000);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   TLatex *   tex = new TLatex(0.1,0.92,"CMS Preliminary");
tex->SetNDC();
   tex->SetTextFont(61);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.9,0.92,"(1.6 + 0.4) nb^{-1} (PbPb @ 5.02 TeV)");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextFont(52);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
   canvas->Modified();
   canvas->cd();
   canvas->SetSelected(canvas);
   canvas->SaveAs("Figure_008.pdf");
}
