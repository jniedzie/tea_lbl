#ifdef __CLING__
#pragma cling optimize(0)
#endif

// this macro doesn't work very well. You can go to `bin` directory and run directly `python lbl_plot_alp_limits.py`.

void plot_fig_8_b() {
  //=========Macro generated from canvas: canvas/
  //=========  (Tue Oct  1 15:00:35 2024) by ROOT version 6.26/08
  TCanvas *canvas = new TCanvas("canvas", "", 0, 0, 800, 600);
  canvas->SetHighLightColor(2);
  canvas->Range(0.438764, -1.19794, 2.173471, 4.135393);
  canvas->SetFillColor(0);
  canvas->SetBorderMode(0);
  canvas->SetBorderSize(2);
  canvas->SetLogx();
  canvas->SetLogy();
  canvas->SetLeftMargin(0.15);
  canvas->SetBottomMargin(0.15);
  canvas->SetFrameBorderMode(0);
  canvas->SetFrameBorderMode(0);

  Double_t _fx3001[10] = {5, 6, 9, 11, 14, 16, 22, 30, 90, 100};
  Double_t _fy3001[10] = {276.25, 66.875, 25.312, 18.75, 12.031, 9.102, 6.914, 5.195, 4.746, 4.746};
  Double_t _felx3001[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  Double_t _fely3001[10] = {142.441, 35.005, 13.743, 10.327, 6.955, 5.902, 4.483, 3.49, 3.337, 3.337};
  Double_t _fehx3001[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  Double_t _fehy3001[10] = {338.679, 84.664, 34.545, 26.544, 19.178, 16.819, 13.563, 10.555, 9.645, 9.645};
  TGraphAsymmErrors *grae = new TGraphAsymmErrors(10, _fx3001, _fy3001, _felx3001, _fehx3001, _fely3001, _fehy3001);
  grae->SetName("");
  grae->SetTitle("");

  Int_t ci;       // for color index setting
  TColor *color;  // for color definition with alpha
  ci = TColor::GetColor("#cccc00");
  grae->SetFillColor(ci);
  grae->SetFillStyle(1000);
  grae->SetLineWidth(0);

  TH1F *Graph_Graph3001 = new TH1F("Graph_Graph3001", "", 100, 5, 100);
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
  Graph_Graph3001->GetYaxis()->SetTitle("#sigma_{#gamma#gamma #rightarrow a #rightarrow #gamma#gamma} (nb)");
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

  Double_t _fx3002[10] = {5, 6, 9, 11, 14, 16, 22, 30, 90, 100};
  Double_t _fy3002[10] = {276.25, 66.875, 25.312, 18.75, 12.031, 9.102, 6.914, 5.195, 4.746, 4.746};
  Double_t _felx3002[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  Double_t _fely3002[10] = {90.139, 22.152, 8.804, 6.616, 4.51, 3.873, 2.942, 2.345, 2.268, 2.268};
  Double_t _fehx3002[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  Double_t _fehy3002[10] = {143.149, 35.986, 14.53, 10.987, 7.769, 6.747, 5.347, 4.432, 4.427, 4.427};
  grae = new TGraphAsymmErrors(10, _fx3002, _fy3002, _felx3002, _fehx3002, _fely3002, _fehy3002);
  grae->SetName("");
  grae->SetTitle("");

  ci = TColor::GetColor("#00cc00");
  grae->SetFillColor(ci);
  grae->SetFillStyle(1000);
  grae->SetLineWidth(0);

  TH1F *Graph_Graph3002 = new TH1F("Graph_Graph3002", "", 100, 4.5, 109.5);
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

  Double_t _fx3003[10] = {5, 6, 9, 11, 14, 16, 22, 30, 90, 100};
  Double_t _fy3003[10] = {276.25, 66.875, 25.312, 18.75, 12.031, 9.102, 6.914, 5.195, 4.746, 4.746};
  Double_t _felx3003[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  Double_t _fely3003[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  Double_t _fehx3003[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  Double_t _fehy3003[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  grae = new TGraphAsymmErrors(10, _fx3003, _fy3003, _felx3003, _fehx3003, _fely3003, _fehy3003);
  grae->SetName("");
  grae->SetTitle("");
  grae->SetFillStyle(1000);
  grae->SetLineStyle(2);
  grae->SetLineWidth(2);

  TH1F *Graph_Graph3003 = new TH1F("Graph_Graph3003", "", 100, 4.5, 109.5);
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

  Double_t _fx1[10] = {5, 6, 9, 11, 14, 16, 22, 30, 90, 100};
  Double_t _fy1[10] = {230.219, 56.454, 19.312, 20.954, 11.689, 8.599, 5.565, 4.708, 4.746, 4.746};
  TGraph *graph = new TGraph(10, _fx1, _fy1);
  graph->SetName("");
  graph->SetTitle("");
  graph->SetFillStyle(1000);
  graph->SetLineWidth(2);

  TH1F *Graph_Graph1 = new TH1F("Graph_Graph1", "", 100, 4.5, 109.5);
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

  Double_t _fx2[11] = {5, 6, 9, 11, 14, 16, 22, 30, 50, 90, 100};
  Double_t _fy2[11] = {529.5285, 443.2044, 277.4555, 223.8067, 158.287, 134.6189, 85.0832, 48.23639, 15.31802, 2.423138, 1.686318};
  graph = new TGraph(11, _fx2, _fy2);
  graph->SetName("");
  graph->SetTitle("");
  graph->SetFillStyle(1000);

  ci = TColor::GetColor("#ff0000");
  graph->SetLineColor(ci);
  graph->SetLineStyle(2);
  graph->SetLineWidth(2);

  TH1F *Graph_Graph2 = new TH1F("Graph_Graph2", "", 100, 4.5, 109.5);
  Graph_Graph2->SetMinimum(1.517686);
  Graph_Graph2->SetMaximum(582.3127);
  Graph_Graph2->SetDirectory(0);
  Graph_Graph2->SetStats(0);

  ci = TColor::GetColor("#000099");
  Graph_Graph2->SetLineColor(ci);
  Graph_Graph2->GetXaxis()->SetLabelFont(42);
  Graph_Graph2->GetXaxis()->SetTitleOffset(1);
  Graph_Graph2->GetXaxis()->SetTitleFont(42);
  Graph_Graph2->GetYaxis()->SetLabelFont(42);
  Graph_Graph2->GetYaxis()->SetTitleFont(42);
  Graph_Graph2->GetZaxis()->SetLabelFont(42);
  Graph_Graph2->GetZaxis()->SetTitleOffset(1);
  Graph_Graph2->GetZaxis()->SetTitleFont(42);
  graph->SetHistogram(Graph_Graph2);

  graph->Draw("l");

  Double_t _fx3[11] = {5, 6, 9, 11, 14, 16, 22, 30, 50, 90, 100};
  Double_t _fy3[11] = {58.52863, 48.98726, 30.66707, 24.73729, 17.49542, 14.87938, 9.404222, 5.331554, 1.693096, 0.2678288, 0.1863882};
  graph = new TGraph(11, _fx3, _fy3);
  graph->SetName("");
  graph->SetTitle("");
  graph->SetFillStyle(1000);

  ci = TColor::GetColor("#ff0000");
  graph->SetLineColor(ci);
  graph->SetLineWidth(2);

  TH1F *Graph_Graph3 = new TH1F("Graph_Graph3", "", 100, 4.5, 109.5);
  Graph_Graph3->SetMinimum(0.1677494);
  Graph_Graph3->SetMaximum(64.36286);
  Graph_Graph3->SetDirectory(0);
  Graph_Graph3->SetStats(0);

  ci = TColor::GetColor("#000099");
  Graph_Graph3->SetLineColor(ci);
  Graph_Graph3->GetXaxis()->SetLabelFont(42);
  Graph_Graph3->GetXaxis()->SetTitleOffset(1);
  Graph_Graph3->GetXaxis()->SetTitleFont(42);
  Graph_Graph3->GetYaxis()->SetLabelFont(42);
  Graph_Graph3->GetYaxis()->SetTitleFont(42);
  Graph_Graph3->GetZaxis()->SetLabelFont(42);
  Graph_Graph3->GetZaxis()->SetTitleOffset(1);
  Graph_Graph3->GetZaxis()->SetTitleFont(42);
  graph->SetHistogram(Graph_Graph3);

  graph->Draw("l");

  Double_t _fx4[11] = {5, 6, 9, 11, 14, 16, 22, 30, 50, 90, 100};
  Double_t _fy4[11] = {14.58381, 12.20634, 7.641433, 6.163886, 4.359401, 3.707553, 2.343286, 1.328484, 0.4218753, 0.06673593, 0.04644307};
  graph = new TGraph(11, _fx4, _fy4);
  graph->SetName("");
  graph->SetTitle("");
  graph->SetFillStyle(1000);

  ci = TColor::GetColor("#ff0000");
  graph->SetLineColor(ci);
  graph->SetLineStyle(3);
  graph->SetLineWidth(2);

  TH1F *Graph_Graph4 = new TH1F("Graph_Graph4", "", 100, 4.5, 109.5);
  Graph_Graph4->SetMinimum(0.04179876);
  Graph_Graph4->SetMaximum(16.03754);
  Graph_Graph4->SetDirectory(0);
  Graph_Graph4->SetStats(0);

  ci = TColor::GetColor("#000099");
  Graph_Graph4->SetLineColor(ci);
  Graph_Graph4->GetXaxis()->SetLabelFont(42);
  Graph_Graph4->GetXaxis()->SetTitleOffset(1);
  Graph_Graph4->GetXaxis()->SetTitleFont(42);
  Graph_Graph4->GetYaxis()->SetLabelFont(42);
  Graph_Graph4->GetYaxis()->SetTitleFont(42);
  Graph_Graph4->GetZaxis()->SetLabelFont(42);
  Graph_Graph4->GetZaxis()->SetTitleOffset(1);
  Graph_Graph4->GetZaxis()->SetTitleFont(42);
  graph->SetHistogram(Graph_Graph4);

  graph->Draw("l");

  TLegend *leg = new TLegend(0.25, 0.7, 0.5, 0.9, NULL, "brNDC");
  leg->SetBorderSize(0);
  leg->SetTextSize(0.04);
  leg->SetLineColor(1);
  leg->SetLineStyle(1);
  leg->SetLineWidth(1);
  leg->SetFillColor(0);
  leg->SetFillStyle(0);
  TLegendEntry *entry = leg->AddEntry("", "g_{a#gamma} = 0.3 (TeV^{-1})", "L");

  ci = TColor::GetColor("#ff0000");
  entry->SetLineColor(ci);
  entry->SetLineStyle(2);
  entry->SetLineWidth(2);
  entry->SetMarkerColor(1);
  entry->SetMarkerStyle(21);
  entry->SetMarkerSize(1);
  entry->SetTextFont(42);
  entry = leg->AddEntry("", "g_{a#gamma} = 0.1 (TeV^{-1})", "L");

  ci = TColor::GetColor("#ff0000");
  entry->SetLineColor(ci);
  entry->SetLineStyle(1);
  entry->SetLineWidth(2);
  entry->SetMarkerColor(1);
  entry->SetMarkerStyle(21);
  entry->SetMarkerSize(1);
  entry->SetTextFont(42);
  entry = leg->AddEntry("", "g_{a#gamma} = 0.05 (TeV^{-1})", "L");

  ci = TColor::GetColor("#ff0000");
  entry->SetLineColor(ci);
  entry->SetLineStyle(3);
  entry->SetLineWidth(2);
  entry->SetMarkerColor(1);
  entry->SetMarkerStyle(21);
  entry->SetMarkerSize(1);
  entry->SetTextFont(42);
  leg->Draw();

  leg = new TLegend(0.55, 0.65, 0.9, 0.9, NULL, "brNDC");
  leg->SetBorderSize(0);
  leg->SetTextSize(0.04);
  leg->SetLineColor(1);
  leg->SetLineStyle(1);
  leg->SetLineWidth(1);
  leg->SetFillColor(0);
  leg->SetFillStyle(0);
  entry = leg->AddEntry("", "Observed", "L");
  entry->SetLineColor(1);
  entry->SetLineStyle(1);
  entry->SetLineWidth(2);
  entry->SetMarkerColor(1);
  entry->SetMarkerStyle(21);
  entry->SetMarkerSize(1);
  entry->SetTextFont(42);
  entry = leg->AddEntry("", "Expected", "L");
  entry->SetLineColor(1);
  entry->SetLineStyle(2);
  entry->SetLineWidth(2);
  entry->SetMarkerColor(1);
  entry->SetMarkerStyle(21);
  entry->SetMarkerSize(1);
  entry->SetTextFont(42);
  entry = leg->AddEntry("", "68% expected", "F");

  ci = TColor::GetColor("#00cc00");
  entry->SetFillColor(ci);
  entry->SetFillStyle(1000);
  entry->SetLineColor(1);
  entry->SetLineStyle(1);
  entry->SetMarkerColor(1);
  entry->SetMarkerStyle(21);
  entry->SetMarkerSize(1);
  entry->SetTextFont(42);
  entry = leg->AddEntry("", "95% expected", "F");

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
  TLatex *tex = new TLatex(0.15, 0.92, "#bf{CMS}");
  tex->SetNDC();
  tex->SetTextFont(42);
  tex->SetTextSize(0.045);
  tex->SetLineWidth(2);
  tex->Draw();
  tex = new TLatex(0.45, 0.92, "#scale[0.8]{PbPb, (1.65 + 0.39) nb^{-1} (#sqrt{s_{NN}} = 5.02 TeV)}");
  tex->SetNDC();
  tex->SetTextFont(42);
  tex->SetTextSize(0.045);
  tex->SetLineWidth(2);
  tex->Draw();
  canvas->Modified();
  canvas->cd();
  canvas->SetSelected(canvas);
  canvas->SaveAs("figures/Figure_008_b.pdf");
}
