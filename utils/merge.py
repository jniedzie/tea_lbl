import os

base_path = "/nfs/dust/cms/user/jniedzie/light_by_light/ntuples/"

skim = "skimmed_twoPhotons"
# skim = "skimmed_neutralExclusivity"

hist_path = ""

sample_paths = (
    "collisionData",
    "lbl",
    "cep",
    "qed",
)


def main():
    for sample_path in sample_paths:
        input_path = f"{base_path}/{sample_path}/{skim}/{hist_path}/*.root"
        output_path = input_path.replace("*.root", f"../merged_{skim}.root")

        print(f"{sample_path=}")
        print(f"{output_path=}")

        os.system(f"rm {output_path}")
        os.system(f"hadd -f -j -k {output_path} {input_path}")


if __name__ == "__main__":
    main()
