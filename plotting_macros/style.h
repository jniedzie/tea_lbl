string output_path = "figures";

double fig_6_x_label_size = 0.2;
double fig_6_y_label_size = 0.2;

double fig_6_x_ratio_label_size = 0.13;
double fig_6_y_ratio_label_size = 0.13;

double fig_6_x_title_size = 0.06;
double fig_6_y_title_size = 0.07;

double fig_6_x_ratio_title_size = 0.15;
double fig_6_y_ratio_title_size = 0.13;

double fig_6_ratio_bottom_margin = 0.4;

void draw_cms_labels() {
  auto tex = new TLatex(0.15, 0.92, "#bf{CMS} #it{Preliminary}");
  tex->SetNDC();
  tex->SetTextFont(42);
  tex->SetTextSize(0.06);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(0.55, 0.92, "#scale[0.8]{PbPb, 1.64 nb^{-1} (#sqrt{s_{NN}} = 5.02 TeV)}");
  tex->SetNDC();
  tex->SetTextFont(42);
  tex->SetTextSize(0.06);
  tex->SetLineWidth(2);
  tex->Draw();
}

void prepare_canvas(TCanvas* canvas) {
  canvas->Range(0, 0, 1, 1);
  canvas->SetFillColor(0);
  canvas->SetBorderMode(0);
  canvas->SetBorderSize(2);
  canvas->SetLeftMargin(0.14);
  canvas->SetRightMargin(0.04);
  canvas->SetTopMargin(0.08);
  canvas->SetBottomMargin(0.14);
  canvas->SetFrameFillStyle(0);
  canvas->SetFrameBorderMode(0);
}

TPad* get_top_pad() {
  TPad* TopPad = new TPad("TopPad", "TopPad", 0.01, 0.26, 1, 1);
  TopPad->Draw();
  TopPad->cd();
  TopPad->Range(-6.003889, -1.367676, 52.3335, 5.434321);
  TopPad->SetFillColor(0);
  TopPad->SetBorderMode(0);
  TopPad->SetBorderSize(2);
  TopPad->SetLogy();
  TopPad->SetTickx(1);
  TopPad->SetTicky(1);
  TopPad->SetLeftMargin(0.1372);
  TopPad->SetRightMargin(0.04);
  TopPad->SetBottomMargin(0.05405406);
  TopPad->SetFrameFillStyle(0);
  TopPad->SetFrameBorderMode(0);
  TopPad->SetFrameFillStyle(0);
  TopPad->SetFrameBorderMode(0);

  return TopPad;
}

TLegend* get_lbl_legend() {
  // TLegend* leg = new TLegend(0.45, 0.65, 0.80, 0.89, NULL, "brNDC");
  TLegend* leg = new TLegend(0.05, 0.5, 0.80, 0.89, NULL, "brNDC");
  leg->SetBorderSize(0);
  leg->SetTextSize(0.035);
  auto entry = leg->AddEntry("", "Data", "ple");

  entry->SetLineColor(kBlack);
  entry->SetLineStyle(1);
  entry->SetLineWidth(1);
  entry->SetMarkerColor(1);
  entry->SetMarkerStyle(20);
  entry->SetMarkerSize(1);
  entry->SetTextFont(42);

  entry = leg->AddEntry("", "#gamma#gamma#rightarrow#gamma#gamma (SUPERCHIC 3.03)", "f");
  auto ci = TColor::GetColor("#ff9933");
  entry->SetFillColor(ci);
  entry->SetFillStyle(1001);
  entry->SetLineColor(kBlack);
  entry->SetLineStyle(1);
  entry->SetLineWidth(1);
  entry->SetMarkerColor(1);
  entry->SetMarkerSize(1);
  entry->SetMarkerStyle(21);
  entry->SetTextFont(42);

  entry = leg->AddEntry("", "#gamma#gamma#rightarrowe^{+}e^{-} (SC 3.03 and SL 3.13 averaged)", "f");
  ci = TColor::GetColor("#ffff00");
  entry->SetFillColor(ci);
  entry->SetFillStyle(1001);
  entry->SetLineColor(kBlack);
  entry->SetLineStyle(1);
  entry->SetLineWidth(1);
  entry->SetMarkerColor(1);
  entry->SetMarkerStyle(21);
  entry->SetMarkerSize(1);
  entry->SetTextFont(42);

  

  entry = leg->AddEntry("", "gg#rightarrow#gamma#gamma (SUPERCHIC 3.03, scaled to data)", "f");

  ci = TColor::GetColor("#6699ff");
  entry->SetFillColor(ci);
  entry->SetFillStyle(1001);
  entry->SetLineColor(kBlack);
  entry->SetLineStyle(1);
  entry->SetLineWidth(1);
  entry->SetMarkerColor(1);
  entry->SetMarkerStyle(21);
  entry->SetMarkerSize(1);
  entry->SetTextFont(42);

  return leg;
}