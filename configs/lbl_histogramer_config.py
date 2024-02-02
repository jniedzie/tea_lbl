from scale_factors_config import *
from lbl_params import *

nEvents = -1
printEveryNevents = 1000

base_path = "/nfs/dust/cms/user/jniedzie/light_by_light/"

sample = "collisionData"
# sample = "lbl"
# sample = "cep"
# sample = "qed"

# skim = "initial"
skim = "skimmed_allSelections"
# skim = "skimmed_qedSelections"

# inputFilePath = f"{base_path}/ntuples/{sample}/{skim}/ntuple_0.root"
inputFilePath = f"{base_path}/ntuples/{sample}/merged_{skim}.root"
histogramsOutputFilePath = "./histograms_data.root"

defaultHistParams = (
  # collection      variable          bins    xmin     xmax     dir
  ("goodPhoton"  , "et"            , 100,    0,       200,     ""  ),
  ("goodPhoton"  , "eta"           , 100,    -2.5,    2.5,     ""  ),
  ("goodPhoton"  , "phi"           , 100,    -2.5,    2.5,     ""  ),
  ("electron"    , "PFChIso"           , 1000,    0,    10,     ""  ),
  ("electron"    , "PFPhoIso"           , 1000,    0,    10,     ""  ),
  ("electron"    , "PFNeuIso"           , 1000,    0,    10,     ""  ),
  # ("Event"       , "nGoodLeptons"  , 50,     0,       50,      ""  ),
)

histParams = (
  ("diphoton"     , "pt"            , 100, 0, 100, ""),
  ("diphoton"     , "mass200"          , 200, 0, 200, ""),
  ("diphoton"     , "mass100"          , 100, 0, 200, ""),
  ("diphoton"     , "acoplanarity200"  , 200, 0, 1, ""),
  ("diphoton"     , "acoplanarity300"  , 300, 0, 1, ""),
  ("diphoton"     , "acoplanarity400"  , 400, 0, 1, ""),
  ("diphoton"     , "acoplanarity500"  , 500, 0, 1, ""),
  ("diphoton"     , "acoplanarity600"  , 600, 0, 1, ""),
  
  ("dielectron"   , "pt"            , 100, 0, 1, ""),
  ("dielectron"   , "mass"          , 200, 0, 200, ""),
  ("dielectron"   , "acoplanarity"  , 1000, 0, 1, ""),
)

eventsTreeNames = ["Events",]
specialBranchSizes = {}
