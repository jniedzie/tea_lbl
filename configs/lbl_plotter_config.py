import ROOT
from Sample import Sample, SampleType
from Legend import Legend
from Histogram import Histogram, Histogram2D
from HistogramNormalizer import NormalizationType
from lbl_helpers import get_cep_scale
from lbl_params import luminosity, crossSections, nGenEvents, get_scale_factor, total_uncertainty_qed, total_uncertainty_lbl_run2
from lbl_paths import base_path, processes, qed_superchic, skim, qed_starlight, qed_mg1gamma, qed_mg2gamma


output_path = f"../plots/{skim.replace('skimmed_', '')}/"
# output_path = f"../plots/{skim.replace('skimmed_', '')}_withALPs/"

# output_path = f"../plots/{skim.replace('skimmed_', '')}_1gamma/"
# output_path = f"../plots/{skim.replace('skimmed_', '')}_2gamma/"
# output_path = f"../plots/{skim.replace('skimmed_', '')}_MG5/"
# output_path = f"../plots/{skim.replace('skimmed_', '')}_MG5_noPtCut/"
# output_path = f"../plots/{skim.replace('skimmed_', '')}_comparison/"
# output_path = f"../plots/{skim.replace('skimmed_', '')}_SCvsSL/"


do_photons = True
do_alps = False

lbl_error = total_uncertainty_lbl_run2 - 1
qed_error = total_uncertainty_qed - 1

scale = 1.0

print(f"{get_scale_factor(do_photons)=}")

samples = [
    Sample(
        name=qed_superchic,
        file_path=f"{base_path}/{qed_superchic}/merged_{skim}_histograms.root",
        type=SampleType.background,

        cross_section=scale*crossSections[qed_superchic]*get_scale_factor(do_photons)[0],
        initial_weight_sum=nGenEvents[qed_superchic],

        # line_style=ROOT.kSolid,
        # line_color=ROOT.kRed,
        # fill_alpha=0.0,
        
        fill_color=ROOT.kYellow,
        fill_alpha=1.0,
        
        marker_size=0.0,
        
        legend_description="#gamma#gamma#rightarrowe^{+}e^{-}",
        custom_legend=Legend(0.62, 0.70, 0.82, 0.75, "FL"),
        # legend_description="QED"
    ),
    Sample(
        name=qed_starlight,
        file_path=f"{base_path}/{qed_starlight}/merged_{skim}_histograms.root",
        type=SampleType.background,

        cross_section=scale*crossSections[qed_starlight]*get_scale_factor(do_photons)[0],
        initial_weight_sum=nGenEvents[qed_starlight],

        # line_style=ROOT.kSolid,
        # line_color=ROOT.kBlue,
        # fill_alpha=0.0,
        
        fill_color=ROOT.kYellow,
        line_color=ROOT.kYellow,
        fill_alpha=1.0,
        
        marker_size=0.0,
        legend_description=""
    ),
    #  Sample(
    #     name=qed_mg1gamma,
    #     file_path=f"{base_path}/qed/merged_{skim}_histograms.root",
    #     type=SampleType.signal,

    #     cross_section=scale*crossSections[qed_mg1gamma]*get_scale_factor(do_photons)[0],
    #     initial_weight_sum=nGenEvents[qed_mg1gamma],

    #     # line_style=ROOT.kSolid,
    #     # line_color=ROOT.kBlue,
    #     # fill_alpha=0.0,
        
    #     fill_color=ROOT.kBlue,
    #     fill_alpha=1.0,
        
    #     marker_size=0.0,
    #     legend_description="QED (MG+1gamma)"
    # ),
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
        legend_description="Data",
        custom_legend=Legend(0.62, 0.80, 0.82, 0.90, "pl", ""),
        # custom_legend=Legend(0.62, 0.80, 0.82, 0.90, "pl", "#gamma#gamma#rightarrow#gamma#gamma"),
        # custom_legend=Legend(0.7, 0.80, 0.80, 0.90, "pl", "#gamma#gamma#rightarrowe^{+}e^{-}(#gamma)(#gamma)"),
    ),
]

if do_photons:
    samples.append(
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
            legend_description="#gamma#gamma#rightarrow#gamma#gamma",
            custom_legend=Legend(0.62, 0.75, 0.82, 0.80, "FL"),
        )
    )
    samples.append(
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
            legend_description="gg#rightarrow#gamma#gamma",
            custom_legend=Legend(0.62, 0.65, 0.82, 0.70, "FL"),
        )
    )

custom_stacks_order = ["cep", qed_starlight, qed_superchic, "lbl", "data"]

alp_colors = (
    # ROOT.kGray+2,
    # ROOT.kCyan+1,
    # ROOT.kCyan,
    # ROOT.kMagenta,
    ROOT.kViolet,
    # ROOT.kBlue,
    # ROOT.kGreen,
    # ROOT.kYellow+1,
    # ROOT.kOrange,
    ROOT.kRed,
)

legend_width = 0.05
legend_min_x = 0.72
legend_max_x = 0.82

legend_height = 0.05
legend_max_y = 0.85


if do_alps:
    alp_scale = 1.0
    alp_index = 0
    for process in processes:
        if "alps" not in process:
            continue

        legend_x_0 = 0.40 if alp_index < 5 else 0.55
        legend_x_1 = 0.47 if alp_index < 5 else 0.62
        
        legend_y_0 = 0.85 - alp_index*legend_height if alp_index < 5 else 0.85 - (alp_index-5)*legend_height
        legend_y_1 = 0.90 - alp_index*legend_height if alp_index < 5 else 0.90 - (alp_index-5)*legend_height

        samples.append(
            Sample(
                name=process,
                file_path=f"{base_path}/{process}/merged_{skim}_histograms.root",
                type=SampleType.signal,
                cross_section=crossSections[process]*get_scale_factor(do_photons)[0]*alp_scale,
                initial_weight_sum=nGenEvents[process],
                line_color=alp_colors[alp_index],
                line_style=ROOT.kSolid,
                line_width=3,
                # fill_style=0,
                fill_color=alp_colors[alp_index],
                fill_alpha=0.2,
                marker_size=0.0,
                legend_description=process.replace("alps_", "m_{a} = ")+" GeV",
                custom_legend=Legend(legend_x_0, legend_y_0, legend_x_1, legend_y_1, "l")
            )
        )
        custom_stacks_order.append(process)
        alp_index += 1

y_label = "Events"

histograms = (
    #           name                  title logx logy    norm_type                    rebin xmin   xmax  ymin    ymax,    xlabel                ylabel            suffix

    # photons
    Histogram("goodPhotonSR_et", "", False, False, NormalizationType.to_lumi, 1,   2, 8, 0, 35, "E_{T}^{#gamma} (GeV)", "Events / 1.2 GeV", "", lbl_error),
    Histogram("goodPhotonSR_eta", "", False, False, NormalizationType.to_lumi, 1,   -2.2, 2.2, 0, 35, "#eta^{#gamma}", "Events / 0.88", "", lbl_error),
    Histogram("goodPhotonSR_phi", "", False, False, NormalizationType.to_lumi, 1,   -3.14, 3.14, 0, 20, "#phi^{#gamma}", "Events / 1.57", "", lbl_error),
    
    Histogram("diphotonSR_pt", "", False, False, NormalizationType.to_lumi, 1,   0, 1, 0, 18, "p_{T}^{#gamma#gamma} (GeV)", "Events / 0.2 GeV", "", lbl_error),
    Histogram("diphotonSR_rapidity", "", False, False, NormalizationType.to_lumi, 1,   -2.2, 2.2, 0, 15, "y^{#gamma#gamma}", "Events / 0.63", "", lbl_error),
    Histogram("diphotonSR_mass", "", False, True, NormalizationType.to_lumi, 1,   0, 25, 2e-1, 1e2, "m^{#gamma#gamma} (GeV)", "Events / 5 GeV", "", lbl_error),
    
    Histogram("eventSR3_cosThetaStar", "", False, False, NormalizationType.to_lumi, 1,   0, 1, 0, 25, "|cos #theta*|", "Events / 0.33", "", lbl_error),


    # Histogram("goodPhoton_eta", "", False, True, NormalizationType.to_lumi, 1,   -2.2, 2.2, 1e-1, 1e5, "#eta^{#gamma}", y_label, "", lbl_error),
    # Histogram("goodPhoton_phi", "", False, True, NormalizationType.to_lumi, 1,   -3.14, 3.14, 1e-1, 1e6, "#phi^{#gamma}", y_label, "", lbl_error),
    # Histogram("goodPhoton_et", "", False, True, NormalizationType.to_lumi, 1,   0, 10, 1e-1, 1e4, "E_{T}^{#gamma} (GeV)", y_label, "", lbl_error),
    Histogram("goodPhoton_seedTime", "", False, True, NormalizationType.to_one, 1,   -5, 5, -1, -1, "Photon seed time", y_label, "", lbl_error),

    Histogram("goodPhoton_et", "", False, False, NormalizationType.to_lumi, 1,   0, 10, 0, 15, "E_{T}^{#gamma} (GeV)", y_label, "", lbl_error),
    Histogram("goodPhoton_eta", "", False, False, NormalizationType.to_lumi, 1,   -2.2, 2.2, 0, 20, "#eta^{#gamma}", y_label, "", lbl_error),
    Histogram("goodPhoton_phi", "", False, False, NormalizationType.to_lumi, 1,   -3.14, 3.14, 0, 20, "#phi^{#gamma}", y_label, "", lbl_error),
    

    Histogram("diphoton_acoplanarity20", "", False, False, NormalizationType.to_lumi, 1,   0, 0.1, 0, 25, "A_{#phi}^{#gamma#gamma}", y_label, "", lbl_error),
    Histogram("diphoton_acoplanarity30", "", False, False, NormalizationType.to_lumi, 1,   0, 0.1, 0, 25, "A_{#phi}^{#gamma#gamma}", y_label, "", lbl_error),
    Histogram("diphoton_acoplanarity32", "", False, False, NormalizationType.to_lumi, 1,   0, 0.1, 0, 25, "A_{#phi}^{#gamma#gamma}", y_label, "", lbl_error),
    Histogram("diphoton_acoplanarity33", "", False, False, NormalizationType.to_lumi, 1,   0, 0.1, 0, 25, "A_{#phi}^{#gamma#gamma}", y_label, "", lbl_error),
    Histogram("diphoton_acoplanarity34", "", False, False, NormalizationType.to_lumi, 1,   0, 0.1, 0, 25, "A_{#phi}^{#gamma#gamma}", y_label, "", lbl_error),


    Histogram("diphoton_acoplanarity35", "", False, False, NormalizationType.to_lumi, 1,   1e-4, 0.1, 0, 25, "A_{#phi}^{#gamma#gamma}", y_label, "", lbl_error),
    Histogram("diphoton_acoplanarity40", "", False, False, NormalizationType.to_lumi, 1,   0, 0.1, 0, 25, "A_{#phi}^{#gamma#gamma}", y_label, "", lbl_error),
    Histogram("diphoton_acoplanarity60", "", False, False, NormalizationType.to_lumi, 1,   0, 0.1, 0, 15, "A_{#phi}^{#gamma#gamma}", y_label, "", lbl_error),

    Histogram("diphoton_acoplanarity50", "", False, False, NormalizationType.to_lumi, 1,   0, 0.1, 0, 15, "A_{#phi}^{#gamma#gamma}", y_label, "", lbl_error),
    Histogram("diphoton_acoplanarity1", "", False, False, NormalizationType.to_lumi, 1,   0, 0.1, 0, 25, "A_{#phi}^{#gamma#gamma}", y_label, "", lbl_error),
    Histogram("diphoton_acoplanarity2", "", False, False, NormalizationType.to_lumi, 1,   0, 0.1, 0, 25, "A_{#phi}^{#gamma#gamma}", y_label, "", lbl_error),
    Histogram("diphoton_acoplanarity3", "", False, False, NormalizationType.to_lumi, 1,   0, 0.1, 0, 25, "A_{#phi}^{#gamma#gamma}", y_label, "", lbl_error),
    Histogram("diphoton_acoplanarity4", "", False, False, NormalizationType.to_lumi, 1,   0, 0.1, 0, 25, "A_{#phi}^{#gamma#gamma}", y_label, "", lbl_error),

    Histogram("diphoton_rapidity", "", False, False, NormalizationType.to_lumi, 1,   -2.2, 2.2, 0, 15, "y^{#gamma#gamma}", y_label, "", lbl_error),
    Histogram("diphoton_mass", "", False, False, NormalizationType.to_lumi, 1,   0, 50, 0, 70, "m^{#gamma#gamma} (GeV)", y_label, "", lbl_error),
    Histogram("diphoton_pt", "", False, False, NormalizationType.to_lumi, 1, 0, 1, 0, 30, "p_{T}^{#gamma#gamma} (GeV)", y_label, "", lbl_error),
    Histogram("diphoton_mass100", "", True, False, NormalizationType.to_lumi, 1,   4.0, 100, 0, 20, "m^{#gamma#gamma} (GeV)", y_label, "", lbl_error),
    Histogram("diphoton_mass200", "", True, False, NormalizationType.to_lumi, 1,   5.0, 100, 0, 20, "m^{#gamma#gamma} (GeV)", y_label, "", lbl_error),

    Histogram("diphotonThreePhoton_mass", "", False, False, NormalizationType.to_lumi, 1,   0, 50, 0, 30, "m^{#gamma#gamma} (GeV)", y_label, "", lbl_error),

    Histogram("diphotonSR_mass100", "", True, False, NormalizationType.to_lumi, 1,   4.0, 100, 0, 20, "m^{#gamma#gamma} (GeV)", y_label, "", lbl_error),
    Histogram("diphotonSR_mass200", "", True, False, NormalizationType.to_lumi, 1,   4.0, 100, 0, 10, "m^{#gamma#gamma} (GeV)", y_label, "", lbl_error),


    # electrons
    Histogram("goodElectron_eta", "", False, False, NormalizationType.to_data, 1,   -2.2, 2.2, 0, -1, "#eta^{e}", y_label, "", qed_error),
    Histogram("goodElectron_phi", "", False, False, NormalizationType.to_data, 1,   -3.14, 3.14, 0, -1, "#phi^{e}", y_label, "", qed_error),
    Histogram("goodElectron_pt", "", False, True, NormalizationType.to_data, 1,   0, 10, 1e1, 1e5, "p_{T}^{e} (GeV)", y_label, "", qed_error),
    Histogram("goodElectronSR_eta", "", False, False, NormalizationType.to_data, 1,   -2.2, 2.2, 0, 5000, "#eta^{e}", y_label, "", qed_error),
    Histogram("goodElectronSR_phi", "", False, False, NormalizationType.to_data, 1,   -3.14, 3.14, 0, 3000, "#phi^{e}", y_label, "", qed_error),
    Histogram("goodElectronSR_pt", "", False, True, NormalizationType.to_data, 10,   0, 50, 1e-1, 6000, "p_{T}^{e} (GeV)", y_label, "", qed_error),
    Histogram("electron_PFChIso", "", False, True, NormalizationType.to_data, 1,   0, 0.1, 1e-10, 1e0, "Electron PFChIso", y_label, "", qed_error),
    Histogram("electron_PFPhoIso", "", False, True, NormalizationType.to_data, 1,   0, 0.1, 1e-10, 1e0, "Electron PFPhoIso", y_label, "", qed_error),
    Histogram("electron_PFNeuIso", "", False, True, NormalizationType.to_data, 1,   0, 0.1, 1e-10, 1e0, "Electron PFNeuIso", y_label, "", qed_error),


    Histogram("goodElectron_deltaEtaAtVertex", "", False, True, NormalizationType.to_lumi, 1,  -0.02, 0.1, 1e0, 1e5, "#Delta#eta_{e} seed", y_label, "", qed_error),
    Histogram("goodElectron_hOverE", "", False, True, NormalizationType.to_lumi, 1,   0, 0.006, 1e0, 1e6, "H/E_{e}", y_label, "", qed_error),
    Histogram("goodElectron_nMissHits", "", False, True, NormalizationType.to_lumi, 1,   0, 5, 1e3, 1e6, "N_{e}^{misHits}", y_label, "", qed_error),

    Histogram("dielectron_acoplanarity", "", False, True, NormalizationType.to_data, 40,   0, 1.0, 1e-2, 1e5, "A_{#phi}^{ee}", y_label, "", qed_error),
    Histogram("dielectron_mass", "", False, True, NormalizationType.to_data, 1,   4.0, 100, 1e-1, 3e3, "m^{ee} (GeV)", y_label, "", qed_error),
    Histogram("dielectron_pt", "", False, True, NormalizationType.to_data, 1,   0, 2, -1, 1e4, "p_{T}^{ee} (GeV)", y_label, "", qed_error),
    Histogram("dielectron_rapidity", "", False, True, NormalizationType.to_data, 1,   -2.2, 2.2, -1, -1, "y^{ee} (GeV)", y_label, "", qed_error),
    Histogram("dielectronSR_mass", "", False, True, NormalizationType.to_data, 1,   4.0, 100, 1e-1, 3e3, "m^{ee} (GeV)", y_label, "", qed_error),
    Histogram("dielectronSR_pt", "", False, True, NormalizationType.to_data, 1,   0, 1, -1, -1, "m^{ee} (GeV)", y_label, "", qed_error),
    Histogram("dielectronSR_rapidity", "", False, True, NormalizationType.to_data, 1,   -2.2, 2.2, -1, -1, "y^{ee} (GeV)", y_label, "", qed_error),

    Histogram("dielectron_deltaPhi", "", False, False, NormalizationType.to_lumi, 1,   0, 3.1415, 0, 3000, "#Delta#phi^{ee}", y_label, "", qed_error),

    # event
    Histogram("event_deltaEt", "", False, False, NormalizationType.to_data, 5,   0, 1, 1e-2, 10, "#DeltaE_{T}", y_label),
    Histogram("event_cosThetaStar", "", False, False, NormalizationType.to_data, 1,   0, 1, 0, 25, "cos #theta*", y_label),
    Histogram("eventSR10_cosThetaStar", "", False, False, NormalizationType.to_data, 1,   0, 1, 0, 15, "cos #theta*", y_label),
    Histogram("eventSR5_cosThetaStar", "", False, False, NormalizationType.to_data, 1,   0, 1, 0, 25, "cos #theta*", y_label),
    Histogram("eventSR4_cosThetaStar", "", False, False, NormalizationType.to_data, 1,   0, 1, 0, 25, "cos #theta*", y_label),

    Histogram("event_electronsCosThetaStar", "", False, False, NormalizationType.to_data, 5,   0, 1, 0, 350, "|cos #theta*|", y_label),
    Histogram("eventSR_electronsCosThetaStar", "", False, False, NormalizationType.to_data, 1,   0, 1, 0, -1, "|cos #theta*|", y_label),

    Histogram("cutFlow", "", False, True, NormalizationType.to_lumi, 1, 0, 10, 1e1, 1e7, "Selection", "#sum genWeight"),
)


histogramsRatio = []

n_signal = len([s for s in samples if s.type ==
               SampleType.signal and s.custom_legend is None])
n_data = len([s for s in samples if s.type ==
             SampleType.data and s.custom_legend is None])
n_background = len([s for s in samples if s.type ==
                   SampleType.background and s.custom_legend is None])

# here default legends per sample type are defined. If you want to override them, specify custom_legend in the sample
legends = {
    SampleType.signal: Legend(legend_min_x, legend_max_y - n_signal*legend_height, legend_min_x+legend_width, legend_max_y, "l"),
    SampleType.data: Legend(legend_max_x-legend_width, legend_max_y - 2*legend_height, legend_max_x, legend_max_y-legend_height, "pl", title="#gamma#gamma"),
    SampleType.background: Legend(legend_min_x, legend_max_y - (n_background+1)*legend_height, legend_max_x, legend_max_y-legend_height, "f"),
}

plotting_options = {
    SampleType.background: "hist",
    # SampleType.background: "hist nostack e",
    SampleType.signal: "hist nostack",
    SampleType.data: "nostack pe0",
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

# output_formats = ["pdf", "C"]
output_formats = ["pdf"]
