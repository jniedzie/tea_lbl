import ROOT
from Sample import Sample, SampleType
from Legend import Legend
from Histogram import Histogram, Histogram2D
from HistogramNormalizer import NormalizationType
from lbl_helpers import get_cep_scale
from lbl_params import luminosity, crossSections, scaleFactors, nGenEvents
from lbl_paths import base_path, processes

# skim = "initial"
skim = "skimmed_allSelections"

output_path = "../plots/first_test/"

samples = [
    Sample(
        name="lbl",
        file_path=f"{base_path}/lbl/merged_{skim}_histograms.root",
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
        file_path=f"{base_path}/cep/merged_{skim}_histograms.root",
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
        file_path=f"{base_path}/qed/merged_{skim}_histograms.root",
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
        file_path=f"{base_path}/collisionData/merged_{skim}_histograms.root",
        type=SampleType.data,
        line_color=ROOT.kBlack,
        line_style=ROOT.kSolid,
        marker_style=20,
        marker_size=1.0,
        marker_color=ROOT.kBlack,
        fill_alpha=0.0,
        legend_description="data",
        custom_legend=Legend(0.7, 0.85, 0.80, 0.90, "pl"),
    ),
]

custom_stacks_order = ["cep", "qed", "lbl", "data"]

alp_colors = (
    ROOT.kGray+2,
    ROOT.kCyan+1,
    ROOT.kCyan,
    ROOT.kMagenta,
    ROOT.kViolet,
    ROOT.kBlue,
    ROOT.kGreen,
    ROOT.kYellow+1,
    ROOT.kOrange,
    ROOT.kRed,
)

legend_width = 0.10
legend_min_x = 0.40
legend_max_x = 0.80

legend_height = 0.05
legend_max_y = 0.90


alp_scale = 2.0
alp_index = 0
for process in processes:
    if "alps" not in process:
        continue

    legend_x_0 = 0.33 if alp_index < 5 else 0.50
    legend_x_1 = 0.43 if alp_index < 5 else 0.60
    
    legend_y_0 = 0.85 - alp_index*legend_height if alp_index < 5 else 0.85 - (alp_index-5)*legend_height
    legend_y_1 = 0.90 - alp_index*legend_height if alp_index < 5 else 0.90 - (alp_index-5)*legend_height

    samples.append(
        Sample(
            name=process,
            file_path=f"{base_path}/{process}/merged_{skim}_histograms.root",
            type=SampleType.signal,
            cross_section=crossSections[process]*scaleFactors[process]*alp_scale,
            initial_weight_sum=nGenEvents[process],
            line_color=alp_colors[alp_index],
            line_style=ROOT.kSolid,
            line_width=3,
            fill_style=0,
            fill_alpha=0.0,
            marker_size=0.0,
            legend_description=process.replace("alps_", "m_{a} = ")+" GeV",
            custom_legend=Legend(legend_x_0, legend_y_0, legend_x_1, legend_y_1, "l")
        )
    )
    custom_stacks_order.append(process)
    alp_index += 1

y_label = "# events (2018)"

histograms = (
    #           name                  title logx logy    norm_type                    rebin xmin   xmax  ymin    ymax,    xlabel                ylabel            suffix
    Histogram("electron_PFChIso", "", False, True, NormalizationType.to_one, 1,   0, 0.1, 1e-10, 1e0, "Electron PFChIso", y_label),
    Histogram("electron_PFPhoIso", "", False, True, NormalizationType.to_one, 1,   0, 0.1, 1e-10, 1e0, "Electron PFPhoIso", y_label),
    Histogram("electron_PFNeuIso", "", False, True, NormalizationType.to_one, 1,   0, 0.1, 1e-10, 1e0, "Electron PFNeuIso", y_label),

    Histogram("diphoton_acoplanarity200", "", False, False, NormalizationType.to_lumi, 1,   0, 0.1, 0, 25, "A_{#phi}^{#gamma#gamma}", y_label),
    Histogram("diphoton_acoplanarity300", "", False, False, NormalizationType.to_lumi, 1,   0, 0.1, 0, 25, "A_{#phi}^{#gamma#gamma}", y_label),
    Histogram("diphoton_acoplanarity400", "", False, False, NormalizationType.to_lumi, 1,   0, 0.1, 0, 25, "A_{#phi}^{#gamma#gamma}", y_label),
    Histogram("diphoton_acoplanarity500", "", False, False, NormalizationType.to_lumi, 1,   0, 0.1, 0, 15, "A_{#phi}^{#gamma#gamma}", y_label),
    Histogram("diphoton_acoplanarity600", "", False, False, NormalizationType.to_lumi, 1,   0, 0.1, 0, 15, "A_{#phi}^{#gamma#gamma}", y_label),

    Histogram("diphoton_mass100", "", True, False, NormalizationType.to_lumi, 1,   4.0, 100, 0, 20, "m^{#gamma#gamma} (GeV)", y_label),
    Histogram("diphoton_mass200", "", True, False, NormalizationType.to_lumi, 1,   4.0, 100, 0, 20, "m^{#gamma#gamma} (GeV)", y_label),

    Histogram("cutFlow", "", False, True, NormalizationType.to_lumi, 1, 0, 10, 1e1, 1e7, "Selection", "#sum genWeight"),
)




n_signal = len([s for s in samples if s.type ==
               SampleType.signal and s.custom_legend is None])
n_data = len([s for s in samples if s.type ==
             SampleType.data and s.custom_legend is None])
n_background = len([s for s in samples if s.type ==
                   SampleType.background and s.custom_legend is None])

# here default legends per sample type are defined. If you want to override them, specify custom_legend in the sample
legends = {
    SampleType.signal: Legend(legend_min_x, legend_max_y - n_signal*legend_height, legend_min_x+legend_width, legend_max_y, "l"),
    SampleType.data: Legend(legend_max_x-legend_width, legend_max_y - legend_height, legend_max_x, legend_max_y-legend_height, "pl"),
    SampleType.background: Legend(legend_max_x-legend_width, legend_max_y - (n_background+1)*legend_height, legend_max_x, legend_max_y-legend_height, "f"),
}

plotting_options = {
    SampleType.background: "hist",
    SampleType.signal: "hist nostack",
    SampleType.data: "nostack pe",
}

canvas_size = (800, 600)
show_ratio_plots = False
ratio_limits = (0.7, 1.3)
