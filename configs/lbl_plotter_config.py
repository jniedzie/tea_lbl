import ROOT
from Sample import Sample, SampleType
from Legend import Legend
from Histogram import Histogram, Histogram2D
from HistogramNormalizer import NormalizationType
from lbl_helpers import get_cep_scale
from lbl_params import luminosity, crossSections, nGenEvents, get_scale_factor
from lbl_paths import base_path, processes

# skim = "initial"
# skim = "skimmed_allSelections"
# skim = "skimmed_allSelections_photonEt2p0"
# skim = "skimmed_allSelections_photonEt2p5"
# skim = "skimmed_allSelections_swissCross0p99"
# skim = "skimmed_allSelections_hadCrack"
# skim = "skimmed_allSelections_hadCrack_noZDC"
# skim = "skimmed_qedSelections"
# skim = "skimmed_qedSelections_noZDC"
skim = "skimmed_lblSelections_final"

output_path = "../plots/lbl_distributions/"
# output_path = "../plots/lbl_distributions_noZDC/"
# output_path = "../plots/qed_distrobutions/"
# output_path = "../plots/qed_distrobutions_noZDC/"


do_photons = True

samples = [
    Sample(
        name="lbl",
        file_path=f"{base_path}/lbl/merged_{skim}_histograms.root",
        type=SampleType.background,
        cross_section=crossSections["lbl"]*get_scale_factor(do_photons)[0],
        initial_weight_sum=nGenEvents["lbl"],
        # line_color=ROOT.kOrange+1,
        fill_color=ROOT.kOrange+1,
        fill_alpha=1.0,
        # fill_alpha=0.0,
        legend_description="LbL",
        # if you add a custom legend for this sample, it will override the default legend.
        # custom_legend = Legend(0.5, 0.5, 0.7, 0.8, "f"),
    ),
    Sample(
        name="cep",
        file_path=f"{base_path}/cep/merged_{skim}_histograms.root",
        type=SampleType.background,
        cross_section=get_cep_scale(skim)[0],
        initial_weight_sum=luminosity,
        
        # cross_section=crossSections["cep"]*get_scale_factor(do_photons)[0]*179.7778874019975,
        # initial_weight_sum=nGenEvents["cep"],
        
        # line_color=ROOT.kAzure-4,
        fill_color=ROOT.kAzure-4,
        fill_alpha=1.0,
        # fill_alpha=0.0,
        legend_description="CEP",
        # custom_legend = Legend(0.7, 0.5, 0.9, 0.8, "f"),
    ),
    Sample(
        name="qed",
        file_path=f"{base_path}/qed/merged_{skim}_histograms.root",
        type=SampleType.background,
        cross_section=crossSections["qed"]*get_scale_factor(do_photons)[0],
        initial_weight_sum=nGenEvents["qed"],
        line_style=ROOT.kSolid,
        # line_color=ROOT.kRed,
        fill_color=ROOT.kYellow,
        fill_alpha=1.0,
        # fill_alpha=0.0,
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


# alp_scale = 2.0
# alp_index = 0
# for process in processes:
#     if "alps" not in process:
#         continue

#     legend_x_0 = 0.33 if alp_index < 5 else 0.50
#     legend_x_1 = 0.43 if alp_index < 5 else 0.60
    
#     legend_y_0 = 0.85 - alp_index*legend_height if alp_index < 5 else 0.85 - (alp_index-5)*legend_height
#     legend_y_1 = 0.90 - alp_index*legend_height if alp_index < 5 else 0.90 - (alp_index-5)*legend_height

#     samples.append(
#         Sample(
#             name=process,
#             file_path=f"{base_path}/{process}/merged_{skim}_histograms.root",
#             type=SampleType.signal,
#             cross_section=crossSections[process]*scaleFactors[process]*alp_scale,
#             initial_weight_sum=nGenEvents[process],
#             line_color=alp_colors[alp_index],
#             line_style=ROOT.kSolid,
#             line_width=3,
#             fill_style=0,
#             fill_alpha=0.0,
#             marker_size=0.0,
#             legend_description=process.replace("alps_", "m_{a} = ")+" GeV",
#             custom_legend=Legend(legend_x_0, legend_y_0, legend_x_1, legend_y_1, "l")
#         )
#     )
#     custom_stacks_order.append(process)
#     alp_index += 1

y_label = "# events"
error = 0.20

histograms = (
    #           name                  title logx logy    norm_type                    rebin xmin   xmax  ymin    ymax,    xlabel                ylabel            suffix

    # photons
    Histogram("goodPhoton_eta"          , "", False , False, NormalizationType.to_lumi, 1,   -2.2 , 2.2  , 0, 30, "#eta^{#gamma}", y_label, "", error),
    Histogram("goodPhoton_phi"          , "", False , False, NormalizationType.to_lumi, 1,   -3.14, 3.14 , 0, 30, "#phi^{#gamma}", y_label, "", error),
    Histogram("goodPhoton_et"           , "", False , False, NormalizationType.to_lumi, 1,   0    , 10   , 0, 50, "E_{T}^{#gamma} (GeV)", y_label, "", error),
    Histogram("goodPhoton_seedTime", "", False, True, NormalizationType.to_one, 1,   -5, 5, -1, -1, "Photon seed time", y_label, "", error),

    Histogram("goodPhotonSR_eta"          , "", False , False, NormalizationType.to_lumi, 1,   -2.2 , 2.2  , 0, 15, "#eta^{#gamma}", y_label, "", error),
    Histogram("goodPhotonSR_phi"          , "", False , False, NormalizationType.to_lumi, 1,   -3.14, 3.14 , 0, 15, "#phi^{#gamma}", y_label, "", error),
    Histogram("goodPhotonSR_et"           , "", False , False, NormalizationType.to_lumi, 1,   0    , 10   , 0, 20, "E_{T}^{#gamma} (GeV)", y_label, "", error),

    Histogram("diphoton_acoplanarity200", "", False, False, NormalizationType.to_lumi, 1,   0, 0.1, 0, 25, "A_{#phi}^{#gamma#gamma}", y_label, "", error),
    Histogram("diphoton_acoplanarity300", "", False, False, NormalizationType.to_lumi, 1,   0, 0.1, 0, 25, "A_{#phi}^{#gamma#gamma}", y_label, "", error),
    Histogram("diphoton_acoplanarity400", "", False, False, NormalizationType.to_lumi, 1,   0, 0.1, 0, 25, "A_{#phi}^{#gamma#gamma}", y_label, "", error),
    Histogram("diphoton_acoplanarity600", "", False, False, NormalizationType.to_lumi, 1,   0, 0.1, 0, 15, "A_{#phi}^{#gamma#gamma}", y_label, "", error),
    Histogram("diphoton_acoplanarity500", "", False, False, NormalizationType.to_lumi, 1,   0, 0.1, 0, 15, "A_{#phi}^{#gamma#gamma}", y_label, "", error),
    Histogram("diphoton_rapidity"       , "", False , False, NormalizationType.to_lumi, 1,   -2.2 , 2.2  , 0, 15, "y^{#gamma#gamma}", y_label, "", error),
    Histogram("diphoton_mass"           , "", False , False, NormalizationType.to_lumi, 1,   0    , 50   , 0, 70, "m^{#gamma#gamma} (GeV)", y_label, "", error),
    Histogram("diphoton_pt"             , "", False , False, NormalizationType.to_lumi, 1,   0    , 1    , 0, 30, "p_{T}^{#gamma#gamma} (GeV)", y_label, "", error),
    Histogram("diphoton_mass100", "", True, False, NormalizationType.to_lumi, 1,   4.0, 100, 0, 20, "m^{#gamma#gamma} (GeV)", y_label, "", error),
    Histogram("diphoton_mass200", "", True, False, NormalizationType.to_lumi, 1,   4.0, 100, 0, 20, "m^{#gamma#gamma} (GeV)", y_label, "", error),
    
    Histogram("diphotonSR_rapidity"       , "", False , False, NormalizationType.to_lumi, 1,   -2.2 , 2.2  , 0, 8, "y^{#gamma#gamma}", y_label, "", error),
    Histogram("diphotonSR_mass"           , "", False , False, NormalizationType.to_lumi, 1,   0    , 50   , 0, 30, "m^{#gamma#gamma} (GeV)", y_label, "", error),
    Histogram("diphotonSR_pt"             , "", False , False, NormalizationType.to_lumi, 1,   0    , 1    , 0, 15, "p_{T}^{#gamma#gamma} (GeV)", y_label, "", error),
    
    # electrons
    Histogram("goodElectron_eta"          , "", False , False, NormalizationType.to_lumi, 1,   -2.2 , 2.2  , 0, 5000, "#eta^{e}", y_label),
    Histogram("goodElectron_phi"          , "", False , False, NormalizationType.to_lumi, 1,   -3.14, 3.14 , 0, 3000, "#phi^{e}", y_label),
    Histogram("goodElectron_pt"           , "", False , False, NormalizationType.to_lumi, 1,   0    , 10   , 0, 6000, "p_{T}^{e} (GeV)", y_label),
    Histogram("goodElectronSR_eta"          , "", False , False, NormalizationType.to_lumi, 1,   -2.2 , 2.2  , 0, 5000, "#eta^{e}", y_label),
    Histogram("goodElectronSR_phi"          , "", False , False, NormalizationType.to_lumi, 1,   -3.14, 3.14 , 0, 3000, "#phi^{e}", y_label),
    Histogram("goodElectronSR_pt"           , "", False , False, NormalizationType.to_lumi, 1,   0    , 10   , 0, 6000, "p_{T}^{e} (GeV)", y_label),
    Histogram("electron_PFChIso", "", False, True, NormalizationType.to_one, 1,   0, 0.1, 1e-10, 1e0, "Electron PFChIso", y_label),
    Histogram("electron_PFPhoIso", "", False, True, NormalizationType.to_one, 1,   0, 0.1, 1e-10, 1e0, "Electron PFPhoIso", y_label),
    Histogram("electron_PFNeuIso", "", False, True, NormalizationType.to_one, 1,   0, 0.1, 1e-10, 1e0, "Electron PFNeuIso", y_label),
    
    Histogram("dielectron_acoplanarity", "", False, True, NormalizationType.to_lumi, 1,   0, 0.06, 1e-1, 1e5, "A_{#phi}^{ee}", y_label),
    Histogram("dielectron_mass", "", False, True, NormalizationType.to_lumi, 1,   4.0, 100, 1e-1, 3e3, "m^{ee} (GeV)", y_label),
    Histogram("dielectron_pt", "", False, True, NormalizationType.to_lumi, 1,   0, 1, -1, -1, "m^{ee} (GeV)", y_label),
    Histogram("dielectron_rapidity", "", False, True, NormalizationType.to_lumi, 1,   -2.2, 2.2, -1, -1, "y^{ee} (GeV)", y_label),
    Histogram("dielectronSR_mass", "", False, True, NormalizationType.to_lumi, 1,   4.0, 100, 1e-1, 3e3, "m^{ee} (GeV)", y_label),
    Histogram("dielectronSR_pt", "", False, True, NormalizationType.to_lumi, 1,   0, 1, -1, -1, "m^{ee} (GeV)", y_label),
    Histogram("dielectronSR_rapidity", "", False, True, NormalizationType.to_lumi, 1,   -2.2, 2.2, -1, -1, "y^{ee} (GeV)", y_label),

    
    # event
    Histogram("event_deltaEt", "", False, False, NormalizationType.to_lumi, 5,   0, 1, 1e-2, 10, "#DeltaE_{T}", y_label),
    Histogram("event_cosThetaStar", "", False, False, NormalizationType.to_lumi, 1,   0, 1, 0, 10, "cos #theta*", y_label),
    Histogram("eventSR10_cosThetaStar", "", False, False, NormalizationType.to_lumi, 1,   0, 1, 0, 10, "cos #theta*", y_label),
    Histogram("eventSR5_cosThetaStar", "", False, False, NormalizationType.to_lumi, 1,   0, 1, 0, 15, "cos #theta*", y_label),
    Histogram("eventSR3_cosThetaStar", "", False, False, NormalizationType.to_lumi, 1,   0, 1, 0, 15, "cos #theta*", y_label),
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
    # SampleType.background: "hist nostack",
    SampleType.signal: "hist nostack",
    SampleType.data: "nostack pe",
}

canvas_size = (800, 600)
show_ratio_plots = False
ratio_limits = (0.0, 2.0)

show_cms_labels = True
extraText = "Preliminary"

beam_label = " PbPb @ 5.02 TeV"
lumi_unit = "nb"
lumi_label_offset = -0.2
# lumi_label_offset = 0.0
