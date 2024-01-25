import ROOT
from ROOT import TColor
from Sample import Sample, SampleType
from Legend import Legend
from Histogram import Histogram, Histogram2D
from HistogramNormalizer import NormalizationType

base_path = "/nfs/dust/cms/user/jniedzie/light_by_light/ntuples/"

# skim = "initial"
# skim = "skimmed_allSelections"
# skim = "skimmed_allSelections_track3validHits"
# skim = "skimmed_allSelections_maxDiphotonPt2"
# skim = "skimmed_allSelections_nTowers1"
# skim = "skimmed_allSelections_swissCross99"
# skim = "skimmed_allSelections_eta2p4"
# skim = "skimmed_allSelections_seedTime3p6"
# skim = "skimmed_allSelections_electron0missingHits1"
# skim = "skimmed_allSelections_trackEta2p2"
# skim = "skimmed_allSelections_HF7"
# skim = "skimmed_allSelections_HB3"
# skim = "skimmed_allSelections_trackPt1p0"
# skim = "skimmed_allSelections_trackPt0p5"
# skim = "skimmed_allSelections_HE1p2"
# skim = "skimmed_allSelections_EB1p0"
# skim = "skimmed_allSelections_EE3p5"
# skim = "skimmed_allSelections_EE4p0"
# skim = "skimmed_allSelections_EE3p3"
# skim = "skimmed_allSelections_EE3p7"
# skim = "skimmed_allSelections_hadronCrack"
# skim = "skimmed_allSelections_emCrack"
# skim = "skimmed_allSelections_HFedge3p0"
# skim = "skimmed_allSelections_diphotonMass4p5"
# skim = "skimmed_allSelections_eleIso5p0"
# skim = "skimmed_allSelections_eleIso2p0"
# skim = "skimmed_allSelections_eleIso0p01"
# skim = "skimmed_allSelections_caloEta2p2"
# skim = "skimmed_allSelections_EE7p5"
# skim = "skimmed_allSelections_swissCross99_EE3p5_EEeta2p2"
# skim = "skimmed_allSelections_swissCross99_EE3p5"
# skim = "skimmed_allSelections_EE3p5_EEeta2p2"
# skim = "skimmed_allSelections_EE3p4"
# skim = "skimmed_allSelections_EE3p6"
# skim = "skimmed_allSelections_EE3p5_trackPt0p4"
# skim = "skimmed_allSelections_EE3p5_1track"
# skim = "skimmed_allSelections_deltaEtaEE0p8"
skim = "skimmed_allSelections_EE3p5_deltaEtaEE0p25"

output_path = "../plots/first_test/"

# luminosity = 63670. # pb^-1 (2018)
luminosity = 1647.228136  # μb^-1

samples = (
    Sample(
        name="lbl",
        file_path=f"{base_path}/lbl/merged_{skim}histograms.root",
        type=SampleType.background,
        cross_section=2.59 * 0.8477 * 0.9322 * 0.9771**2 * 0.8643 * 1.0006,  # xsec * SFs
        initial_weight_sum=466000,
        fill_color=ROOT.kOrange,
        fill_alpha=1.0,
        legend_description="LbL",
        # if you add a custom legend for this sample, it will override the default legend.
        # custom_legend = Legend(0.5, 0.5, 0.7, 0.8, "f"),
    ),
    Sample(
        name="cep",
        file_path=f"{base_path}/cep/merged_{skim}histograms.root",
        type=SampleType.background,
        # cross_section=0.0012475821798342804,  # skimmed_allSelections
        # cross_section=0.0012035152249622865,  # skimmed_allSelections_track3validHits
        # cross_section=0.003523094841360086,  # skimmed_allSelections_maxDiphotonPt2
        # cross_section=0.0023894074046104516,  # skimmed_allSelections_nTowers1
        # cross_section=0.00122889749919257,  # skimmed_allSelections_swissCross99
        # cross_section=0.0010904607848947396,  # skimmed_allSelections_eta2p4
        # cross_section=0.001227444694473201,  # skimmed_allSelections_seedTime3p6
        # cross_section=0.0015730224870729916,  # skimmed_allSelections_electron0missingHits1
        # cross_section=0.0013122790436204425,  # skimmed_allSelections_trackEta2p2
        # cross_section=0.0014926282885804288,  # skimmed_allSelections_HF7
        # cross_section=0.0012471839729463665,  # skimmed_allSelections_HB3
        # cross_section=0.0042178592368409306,  # skimmed_allSelections_trackPt1p0
        # cross_section=0.001265173783074215,  # skimmed_allSelections_trackPt0p5
        # cross_section=0.0014008076308232077,  # skimmed_allSelections_HE1p2
        # cross_section=0.0013415883329877566,  # skimmed_allSelections_EB1p0
        # cross_section=0.0012403218878132365,  # skimmed_allSelections_EE3p5
        # cross_section=0.0012370496160534928,  # skimmed_allSelections_EE4p0
        # cross_section=0.0012431123213221347,  # skimmed_allSelections_EE3p3
        # cross_section=0.0012387772577478315,  # skimmed_allSelections_EE3p7
        # cross_section=0.0012476105991983536,  # skimmed_allSelections_hadronCrack
        # cross_section=0.0012464167134574938,  # skimmed_allSelections_emCrack
        # cross_section=0.0012476105991983536,  # skimmed_allSelections_HFedge3p0
        # cross_section=0.001274175263904672,  # skimmed_allSelections_diphotonMass4p5
        # cross_section=0.0012476105991983536,  # skimmed_allSelections_eleIso5p0
        # cross_section=0.0012476105991983536,  # skimmed_allSelections_eleIso2p0
        # cross_section=0.001411945882617873,  # skimmed_allSelections_eleIso0p01
        # cross_section=0.0012311015742562203,  # skimmed_allSelections_caloEta2p2
        # cross_section=0.0012320072716834188,  # skimmed_allSelections_EE7p5
        # cross_section=0.0012126449966437002,  # skimmed_allSelections_swissCross99_EE3p5_EEeta2p2
        # cross_section=0.001221749317786385,  # skimmed_allSelections_swissCross99_EE3p5
        # cross_section=0.0012311015742562203,  # skimmed_allSelections_EE3p5_EEeta2p2
        # cross_section=0.0012676998364120912,  # skimmed_allSelections_EE3p4
        # cross_section=0.0012393011090038831,  # skimmed_allSelections_EE3p6
        # cross_section=0.0012273745802867295,  # skimmed_allSelections_EE3p5_trackPt0p4
        # cross_section=0.002545940970344399,  # skimmed_allSelections_EE3p5_1track
        # cross_section=0.0012403501417911046,  # skimmed_allSelections_deltaEtaEE0p8
        cross_section=0.0012403501417911046,  # skimmed_allSelections_EE3p5_deltaEtaEE0p25
        initial_weight_sum=luminosity,
        fill_color=ROOT.kBlue,
        fill_alpha=1.0,
        legend_description="CEP",
        # custom_legend = Legend(0.7, 0.5, 0.9, 0.8, "f"),
    ),
    Sample(
        name="qed",
        file_path=f"{base_path}/qed/merged_{skim}histograms.root",
        type=SampleType.background,
        cross_section=8827.220 * 0.8477 * 0.9322 * 0.952**2 * 0.8643 * 1.0006,  # xsec * SFs
        initial_weight_sum=59260000,
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

# You can specify custom order for stacks. If you don't, they will be ordered by cross-section
# custom_stacks_order = ("DY", "tt", "ttZ", "data")

y_label = "# events (2018)"

histograms = (
    #           name                  title logy    norm_type                    rebin xmin   xmax  ymin    ymax,    xlabel                ylabel            suffix
    Histogram("electron_PFChIso", "", True, NormalizationType.to_one, 1,   0, 0.1, 1e-10, 1e0, "Electron PFChIso", y_label),
    Histogram("electron_PFPhoIso", "", True, NormalizationType.to_one, 1,   0, 0.1, 1e-10, 1e0, "Electron PFPhoIso", y_label),
    Histogram("electron_PFNeuIso", "", True, NormalizationType.to_one, 1,   0, 0.1, 1e-10, 1e0, "Electron PFNeuIso", y_label),
    
    Histogram("diphoton_acoplanarity", "", False, NormalizationType.to_lumi, 1,   0, 0.1, 0, 25, "A_{#phi}^{#gamma#gamma}", y_label),
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
