import os

command = "combine -M AsymptoticLimits limits_histograms_skimmed_allSelections_nBins{}alps_{}_.txt"
n_bins = 200


def run(n_bins, mass):
    print(f"\n\nRunning combine for mass: {mass} GeV")
    output = os.popen(command.format(n_bins, mass)).read()
    lines = output.split("\n")

    for line in lines:
        if "Observed Limit:" in line:
            observed_limit = float(line.split("<")[-1].strip())
        elif "Expected  2.5%:" in line:
            expected_m2sigma = float(line.split("<")[-1].strip())
        elif "Expected 16.0%:" in line:
            expected_m1sigma = float(line.split("<")[-1].strip())
        elif "Expected 50.0%:" in line:
            expected_median = float(line.split("<")[-1].strip())
        elif "Expected 84.0%:" in line:
            expected_p1sigma = float(line.split("<")[-1].strip())
        elif "Expected 97.5%:" in line:
            expected_p2sigma = float(line.split("<")[-1].strip())

    return observed_limit, expected_m2sigma, expected_m1sigma, expected_median, expected_p1sigma, expected_p2sigma


def main():

    limits = {}

    for mass in (5, 6, 9, 11, 14, 16, 22, 30, 50, 90):
        limits[mass] = run(n_bins, mass)

    print(f"{limits=}")


if __name__ == "__main__":
    main()
