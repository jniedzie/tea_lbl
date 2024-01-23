from scale_factors_config import *
from lbl_params import *

nEvents = -1
printEveryNevents = 1000

inputFilePath = "./skimmed_data.root"
histogramsOutputFilePath = "./histograms_data.root"

defaultHistParams = (
  # collection      variable          bins    xmin     xmax     dir
  ("goodPhoton"  , "et"            , 100,    0,       200,     ""  ),
  ("goodPhoton"  , "eta"           , 100,    -2.5,    2.5,     ""  ),
  ("goodPhoton"  , "phi"           , 100,    -2.5,    2.5,     ""  ),
  # ("Event"       , "nGoodLeptons"  , 50,     0,       50,      ""  ),
)

histParams = (
  ("diphoton"     , "pt"            , 100, 0, 100, ""),
  ("diphoton"     , "mass"          , 100, 0, 100, ""),
  ("diphoton"     , "acoplanarity"  , 200, 0, 1, ""),
)

eventsTreeNames = ["Events",]
specialBranchSizes = {}
