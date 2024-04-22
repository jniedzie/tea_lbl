#ifdef __CLING__
#pragma cling optimize(0)
#endif
void plot_fig_3() {

  float markerSize = 1.5;

  gROOT->SetBatch(kTRUE);
  //=========Macro generated from canvas: ratios/ratios
  //=========  (Sun Mar 31 12:30:41 2024) by ROOT version 6.26/08
  TCanvas *ratios = new TCanvas("ratios", "ratios", 0, 0, 800, 600);
  gStyle->SetOptStat(0);
  ratios->SetHighLightColor(2);
  ratios->Range(-1.2, -4.153846, 6.8, 0.4615385);
  ratios->SetFillColor(0);
  ratios->SetBorderMode(0);
  ratios->SetBorderSize(2);
  ratios->SetLogy();
  ratios->SetLeftMargin(0.15);
  ratios->SetBottomMargin(0.25);
  ratios->SetFrameBorderMode(0);
  ratios->SetFrameBorderMode(0);

  TH1D *ratio_superchic__1 = new TH1D("ratio_superchic__1", "", 6, 0, 6);
  ratio_superchic__1->SetBinContent(1, 0.766);
  ratio_superchic__1->SetBinContent(2, 0.186);
  ratio_superchic__1->SetBinContent(3, 0.0485);
  ratio_superchic__1->SetBinContent(4, 0.064);
  ratio_superchic__1->SetBinContent(5, 0.0298);
  ratio_superchic__1->SetBinContent(6, 0.0045);
  ratio_superchic__1->SetBinError(1, 0.0096);
  ratio_superchic__1->SetBinError(2, 0.0022);
  ratio_superchic__1->SetBinError(3, 0.00061);
  ratio_superchic__1->SetBinError(4, 0.00078);
  ratio_superchic__1->SetBinError(5, 0.00036);
  ratio_superchic__1->SetBinError(6, 6e-05);
  ratio_superchic__1->SetMinimum(0.001);
  ratio_superchic__1->SetMaximum(1);
  ratio_superchic__1->SetEntries(5);

  Int_t ci;       // for color index setting
  TColor *color;  // for color definition with alpha
  ci = TColor::GetColor("#990000");
  ratio_superchic__1->SetLineColor(ci);

  ci = TColor::GetColor("#990000");
  ratio_superchic__1->SetMarkerColor(ci);
  ratio_superchic__1->SetMarkerStyle(21);
  ratio_superchic__1->SetMarkerSize(markerSize);
  ratio_superchic__1->GetXaxis()->SetTitle("Neutron multiplicity category");
  ratio_superchic__1->GetXaxis()->SetBinLabel(1, "0n0n");
  ratio_superchic__1->GetXaxis()->SetBinLabel(2, "0nXn + Xn0n");
  ratio_superchic__1->GetXaxis()->SetBinLabel(4, "0n1n + 1n0n");
  ratio_superchic__1->GetXaxis()->SetBinLabel(3, "XnXn");
  ratio_superchic__1->GetXaxis()->SetBinLabel(5, "1nXn + Xn1n");
  ratio_superchic__1->GetXaxis()->SetBinLabel(6, "1n1n");
  ratio_superchic__1->GetXaxis()->CenterTitle(true);
  ratio_superchic__1->GetXaxis()->SetLabelFont(42);
  ratio_superchic__1->GetXaxis()->SetLabelOffset(0.01);
  ratio_superchic__1->GetXaxis()->SetLabelSize(0.06);
  ratio_superchic__1->GetXaxis()->SetTitleSize(0.055);
  ratio_superchic__1->GetXaxis()->SetTitleOffset(1.8);
  ratio_superchic__1->GetXaxis()->SetTitleFont(42);
  ratio_superchic__1->GetYaxis()->SetTitle("Probability");
  ratio_superchic__1->GetYaxis()->CenterTitle(true);
  ratio_superchic__1->GetYaxis()->SetLabelFont(42);
  ratio_superchic__1->GetYaxis()->SetLabelOffset(0.01);
  ratio_superchic__1->GetYaxis()->SetLabelSize(0.05);
  ratio_superchic__1->GetYaxis()->SetTitleSize(0.06);
  ratio_superchic__1->GetYaxis()->SetTitleFont(42);
  ratio_superchic__1->GetZaxis()->SetLabelFont(42);
  ratio_superchic__1->GetZaxis()->SetTitleOffset(1);
  ratio_superchic__1->GetZaxis()->SetTitleFont(42);
  ratio_superchic__1->Draw("PE");

  TH1D *ratio_starlight__2 = new TH1D("ratio_starlight__2", "ratio_starlight", 6, 0, 6);
  ratio_starlight__2->SetBinContent(1, 0.745);
  ratio_starlight__2->SetBinContent(2, 0.191);
  ratio_starlight__2->SetBinContent(3, 0.059);
  ratio_starlight__2->SetBinContent(6, 0.0037);
  ratio_starlight__2->SetBinError(1, 0.01);
  ratio_starlight__2->SetBinError(2, 0.01);
  ratio_starlight__2->SetBinError(3, 0.005);
  ratio_starlight__2->SetBinError(6, 0.001);
  ratio_starlight__2->SetEntries(4);

  ci = TColor::GetColor("#009900");
  ratio_starlight__2->SetLineColor(ci);

  ci = TColor::GetColor("#009900");
  ratio_starlight__2->SetMarkerColor(ci);
  ratio_starlight__2->SetMarkerStyle(22);
  ratio_starlight__2->SetMarkerSize(markerSize);
  ratio_starlight__2->GetXaxis()->SetLabelFont(42);
  ratio_starlight__2->GetXaxis()->SetTitleOffset(1);
  ratio_starlight__2->GetXaxis()->SetTitleFont(42);
  ratio_starlight__2->GetYaxis()->SetLabelFont(42);
  ratio_starlight__2->GetYaxis()->SetTitleFont(42);
  ratio_starlight__2->GetZaxis()->SetLabelFont(42);
  ratio_starlight__2->GetZaxis()->SetTitleOffset(1);
  ratio_starlight__2->GetZaxis()->SetTitleFont(42);
  ratio_starlight__2->Draw("PE SAME");

  TH1D *ratio_data__3 = new TH1D("ratio_data__3", "ratio_data", 6, 0, 6);
  ratio_data__3->SetBinContent(0, 1);
  ratio_data__3->SetBinContent(1, 0.7402792);
  ratio_data__3->SetBinContent(2, 0.1977022);
  ratio_data__3->SetBinContent(3, 0.0617186);
  ratio_data__3->SetBinContent(4, 0.04542396);
  ratio_data__3->SetBinContent(5, 0.03739869);
  ratio_data__3->SetBinContent(6, 0.00537688);
  ratio_data__3->SetBinError(0, 0.009959991);
  ratio_data__3->SetBinError(1, 0.007414662);
  ratio_data__3->SetBinError(2, 0.004759062);
  ratio_data__3->SetBinError(3, 0.001808592);
  ratio_data__3->SetBinError(4, 0.002208303);
  ratio_data__3->SetBinError(5, 0.001381021);
  ratio_data__3->SetBinError(6, 0.000393379);
  ratio_data__3->SetEntries(7);
  ratio_data__3->SetMarkerStyle(20);
  ratio_data__3->SetMarkerSize(markerSize);
  ratio_data__3->SetMarkerColor(kBlack);
  ratio_data__3->SetLineColor(kBlack);
  ratio_data__3->GetXaxis()->SetLabelFont(42);
  ratio_data__3->GetXaxis()->SetTitleOffset(1);
  ratio_data__3->GetXaxis()->SetTitleFont(42);
  ratio_data__3->GetYaxis()->SetLabelFont(42);
  ratio_data__3->GetYaxis()->SetTitleFont(42);
  ratio_data__3->GetZaxis()->SetLabelFont(42);
  ratio_data__3->GetZaxis()->SetTitleOffset(1);
  ratio_data__3->GetZaxis()->SetTitleFont(42);
  ratio_data__3->Draw("PE same");

  TLegend *leg = new TLegend(0.6, 0.70, 0.89, 0.89, NULL, "brNDC");
  leg->SetHeader("#gamma#gamma #rightarrow e^{+}e^{-}");
  leg->SetBorderSize(0);
  leg->SetLineColor(1);
  leg->SetLineStyle(1);
  leg->SetLineWidth(1);
  leg->SetFillColor(0);
  leg->SetFillStyle(1001);
  TLegendEntry *entry = leg->AddEntry("ratio_data", "Data", "PEL");
  entry->SetLineColor(1);
  entry->SetLineStyle(1);
  entry->SetLineWidth(1);
  entry->SetMarkerColor(1);
  entry->SetMarkerStyle(20);
  entry->SetMarkerSize(1.2);
  entry->SetTextFont(42);
  entry = leg->AddEntry("ratio_superchic", "SUPERCHIC 4.2", "PEL");

  ci = TColor::GetColor("#990000");
  entry->SetLineColor(ci);
  entry->SetLineStyle(1);
  entry->SetLineWidth(1);

  ci = TColor::GetColor("#990000");
  entry->SetMarkerColor(ci);
  entry->SetMarkerStyle(21);
  entry->SetMarkerSize(1.2);
  entry->SetTextFont(42);
  entry = leg->AddEntry("ratio_starlight", "STARLIGHT 3.13", "PEL");

  ci = TColor::GetColor("#009900");
  entry->SetLineColor(ci);
  entry->SetLineStyle(1);
  entry->SetLineWidth(1);

  ci = TColor::GetColor("#009900");
  entry->SetMarkerColor(ci);
  entry->SetMarkerStyle(22);
  entry->SetMarkerSize(1.2);
  entry->SetTextFont(42);
  leg->Draw();

  // auto tex = new TLatex(0.15, 0.92, "#bf{CMS} #it{Preliminary}");
  auto tex = new TLatex(0.15, 0.92, "#bf{CMS}");
  tex->SetNDC();
  tex->SetTextFont(42);
  tex->SetTextSize(0.04);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(0.55, 0.92, "#scale[0.8]{PbPb, 1.65 nb^{-1} (#sqrt{s_{NN}} = 5.02 TeV)}");
  tex->SetNDC();
  tex->SetTextFont(42);
  tex->SetTextSize(0.04);
  tex->SetLineWidth(2);
  tex->Draw();

  ratios->Modified();
  ratios->cd();
  ratios->SetSelected(ratios);
  ratios->SaveAs("figures/Figure_003.pdf");
}
