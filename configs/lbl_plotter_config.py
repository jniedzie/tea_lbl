import ROOT
from Sample import Sample, SampleType
from Legend import Legend
from Histogram import Histogram, Histogram2D
from HistogramNormalizer import NormalizationType
from lbl_helpers import get_cep_scale
from lbl_params import luminosity, crossSections, scaleFactors, nGenEvents
from lbl_paths import base_path

# skim = "initial"
skim = "skimmed_allSelections"

output_path = "../plots/first_test/"

samples = (
    Sample(
        name="lbl",
        file_path=f"{base_path}/lbl/merged_{skim}histograms.root",
        type=SampleType.background,
        cross_section=crossSections["lbl"]*scaleFactors["lbl"],
        initial_weight_sum=nGenEvents["lbl"],
        fill_color=ROOT.kOrange+1,
        fill_alpha=1.0,
        legend_description="LbL",
        # if you add a custom legend for this sample, it will override the default legend.
        # custom_legend = Legend(0.5, 0.5, 0.7, 0.8, "f"),
    ),
    Sample(
        name="cep",
        file_path=f"{base_path}/cep/merged_{skim}histograms.root",
        type=SampleType.background,
        cross_section=get_cep_scale(skim),
        initial_weight_sum=luminosity,
        fill_color=ROOT.kAzure-4,
        fill_alpha=1.0,
        legend_description="CEP",
        # custom_legend = Legend(0.7, 0.5, 0.9, 0.8, "f"),
    ),
    Sample(
        name="qed",
        file_path=f"{base_path}/qed/merged_{skim}histograms.root",
        type=SampleType.background,
        cross_section=crossSections["qed"]*scaleFactors["qed"],
        initial_weight_sum=nGenEvents["qed"],
        line_style=ROOT.kSolid,
        fill_color=ROOT.kYellow,
        fill_alpha=1.0,
        marker_size=0.0,
        legend_description="QED"
    ),
    Sample(
        name="data",
        file_path=f"{base_path}/collisionData/merged_{skim}histograms.root",
        type=SampleType.data,
        line_color=ROOT.kBlack,
        line_style=ROOT.kSolid,
        marker_style=20,
        marker_size=1.0,
        marker_color=ROOT.kBlack,
        fill_alpha=0.0,
        legend_description="data (2018)"
    ),
)

custom_stacks_order = ("cep", "qed", "lbl", "data")

y_label = "# events (2018)"

histograms = (
    #           name                  title logy    norm_type                    rebin xmin   xmax  ymin    ymax,    xlabel                ylabel            suffix
    Histogram("electron_PFChIso", "", True, NormalizationType.to_one, 1,   0, 0.1, 1e-10, 1e0, "Electron PFChIso", y_label),
    Histogram("electron_PFPhoIso", "", True, NormalizationType.to_one, 1,   0, 0.1, 1e-10, 1e0, "Electron PFPhoIso", y_label),
    Histogram("electron_PFNeuIso", "", True, NormalizationType.to_one, 1,   0, 0.1, 1e-10, 1e0, "Electron PFNeuIso", y_label),
    
    Histogram("diphoton_acoplanarity200", "", False, NormalizationType.to_lumi, 1,   0, 0.1, 0, 25, "A_{#phi}^{#gamma#gamma}", y_label),
    Histogram("diphoton_acoplanarity300", "", False, NormalizationType.to_lumi, 1,   0, 0.1, 0, 25, "A_{#phi}^{#gamma#gamma}", y_label),
    Histogram("diphoton_acoplanarity400", "", False, NormalizationType.to_lumi, 1,   0, 0.1, 0, 25, "A_{#phi}^{#gamma#gamma}", y_label),
    Histogram("diphoton_acoplanarity500", "", False, NormalizationType.to_lumi, 1,   0, 0.1, 0, 15, "A_{#phi}^{#gamma#gamma}", y_label),
    Histogram("diphoton_acoplanarity600", "", False, NormalizationType.to_lumi, 1,   0, 0.1, 0, 15, "A_{#phi}^{#gamma#gamma}", y_label),
    
    Histogram("diphoton_mass", "", False, NormalizationType.to_lumi, 1,   0, 100, 0, 20, "m^{#gamma#gamma} (GeV)", y_label),
    
    
    Histogram("cutFlow", "", True, NormalizationType.to_lumi, 1, 0, 10, 1e1, 1e7, "Selection", "#sum genWeight"),
)


legend_width = 0.15
legend_min_x = 0.40
legend_max_x = 0.80

legend_height = 0.05
legend_max_y = 0.85

n_signal = len([s for s in samples if s.type ==
               SampleType.signal and s.custom_legend is None])
n_data = len([s for s in samples if s.type ==
             SampleType.data and s.custom_legend is None])
n_background = len([s for s in samples if s.type ==
                   SampleType.background and s.custom_legend is None])

# here default legends per sample type are defined. If you want to override them, specify custom_legend in the sample
legends = {
    SampleType.signal: Legend(legend_min_x, legend_max_y - n_signal*legend_height, legend_min_x+legend_width, legend_max_y, "l"),
    SampleType.data: Legend(legend_min_x, legend_max_y - (n_signal+n_data)*legend_height, legend_min_x+legend_width, legend_max_y-n_signal*legend_height, "pl"),
    SampleType.background: Legend(legend_max_x-legend_width, legend_max_y - n_background*legend_height, legend_max_x, legend_max_y, "f"),
}

plotting_options = {
    SampleType.background: "hist",
    SampleType.signal: "nostack e",
    SampleType.data: "nostack pe",
}

canvas_size = (800, 600)
show_ratio_plots = False
ratio_limits = (0.7, 1.3)
