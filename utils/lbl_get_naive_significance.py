from lbl_helpers import load_histograms, get_cep_scale
from lbl_helpers import input_aco_histograms

# skim = "skimmed_allSelections"
skim = "skimmed_allSelections_swissCross0p99"


def main():
    cep_scale = get_cep_scale(skim)
    input_aco_histograms["cep"].Scale(cep_scale)

    integrals = {}
    for process, histogram in input_aco_histograms.items():
        integrals[process] = histogram.Integral(
            1, histogram.FindFixBin(0.01)-1)

    for (process, integral) in integrals.items():
        print(f"{process}: {integral:.3f}")

    total_background = integrals["cep"]+integrals["qed"]
    print(f"total background: {total_background:.3f}")

    expected_significance = integrals["lbl"]
    expected_significance /= (integrals["lbl"]+total_background)**(1/2)

    observed_significance = (integrals["collisionData"]-total_background)
    observed_significance /= (integrals["collisionData"])**(1/2)

    print(f"Expected naive significance: {expected_significance:.2f}")
    print(f"Observed naive significance: {observed_significance:.2f}")


if __name__ == "__main__":
    load_histograms(skim)
    main()
