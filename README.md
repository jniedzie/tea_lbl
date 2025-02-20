# Welcome to CMS Light-by-light (Run 2) analysis

## Prerequisites

The analysis framework is based on `tea` - please have a look at the general setup instructions here: [cern.ch/tea](https://jniedzie.github.io/tea/docs/build/).

If you're going to run on lxplus, just remember to use lxplus9, install the `correctionlib`, and use `python3`.

## Installation

To clone the repo, together with all submodules, run:

```bash
git clone --recurse-submodules git@github.com:jniedzie/tea_lbl.git
```

Then, simply run `. tea/build.sh` from the `tea_lbl` directory.

## Example samples

To test things on lxplus, we share LbL MC ntuples that can be found here:
`/eos/cms/store/cmst3/group/lightbylight/tea_samples/lbl/bad_names/`

## How to run

The analysis involves a few steps:
1. Preparing ntuples with names that `tea` can understand out of the HIForest ntuples.
2. Creating histograms.
3. Plotting.
4. Statistical analysis.

### Renaming

