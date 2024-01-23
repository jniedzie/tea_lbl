luminosity = 1647.228136  # μb^-1

lbl_scale = 2.59 * 0.8477 * 0.9322 * 0.9771**2 * 0.8643 * 1.0006  # xsec * SFs
n_lbl_events = 466000

qed_scale = 8827.220 * 0.8477 * 0.9322 * 0.952**2 * 0.8643 * 1.0006  # xsec * SFs
n_qed_events = 59260000


def get_cep_scale(hist_data, hist_lbl, hist_qed, hist_cep):
    hist_data_no_background = hist_data.Clone()
    hist_data_no_background.Add(hist_lbl, -1)
    hist_data_no_background.Add(hist_qed, -1)

    # get integral of data histogram above 0.02
    integral_data = hist_data_no_background.Integral(
        hist_data_no_background.FindBin(0.02), hist_data_no_background.GetNbinsX())
    integral_cep = hist_cep.Integral(
        hist_cep.FindBin(0.02), hist_cep.GetNbinsX())

    scale = integral_data / integral_cep
    return scale
