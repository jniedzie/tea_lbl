#ifdef __CLING__
#pragma cling optimize(0)
#endif

#include "style.h"

void plot_fig_6_legend() {
  gROOT->SetBatch(kTRUE);
  
  auto goodPhotonSR_et = new TCanvas("", "", 0, 0, 800, 600);
  gStyle->SetOptStat(0);
  
  auto leg = get_lbl_legend();
  leg->Draw();

  goodPhotonSR_et->Modified();
  goodPhotonSR_et->SaveAs("figures/Figure_006_legend.pdf");
}
