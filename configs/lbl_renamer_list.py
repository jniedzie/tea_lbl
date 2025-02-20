from lbl_paths import processes, facility
samples = processes
sample_path = ""

if facility == "NAF":
    base_path = "/nfs/dust/cms/user/jniedzie/light_by_light"
    main_dir = "ntuples"
elif facility == "lxplus":
    base_path = "/eos/cms/store/cmst3/group/lightbylight"
    main_dir = "tea_samples"

input_directory = f"{base_path}/{main_dir}/{sample_path}/bad_names/"
output_trees_dir = f"{base_path}/{main_dir}/{sample_path}/initial/"
