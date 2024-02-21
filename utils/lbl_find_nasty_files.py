import ROOT

base_path = "/nfs/dust/cms/user/jniedzie/light_by_light/ntuples/"

initial_path = f"{base_path}/collisionData/initial/"
skimmed_path = f"{base_path}/collisionData/skimmed_lblSelections_final/"

corrupted_files = []
nasty_files = []

for i in range(212):
    initial_file = ROOT.TFile.Open(f"{initial_path}/ntuple_{i}.root")
    skimmed_file = ROOT.TFile.Open(f"{skimmed_path}/ntuple_{i}.root")

    try:
        n_initial = initial_file.Get("Events").GetEntries()
        n_skimmed = skimmed_file.Get("CutFlow/0_initial").GetBinContent(1)
    except Exception:
        corrupted_files.append(i)
        continue

    if n_initial != n_skimmed:
        nasty_files.append(i)

print(f"{nasty_files=}")
print(f"{corrupted_files=}")
