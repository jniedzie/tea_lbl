# Welcome to CMS Light-by-light (Run 2) analysis

## Prerequisites

The analysis framework is based on `tea` - please have a look at the general setup instructions here: [cern.ch/tea](https://jniedzie.github.io/tea/docs/build/).

**You don't need to install `tea` though, it will come automatically when you install `tea_lbl`!!**

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

All apps and configs are in the `bin` directory - that's where you should run all commands.

### Renaming

The first step is to format ntuples in a way that `tea` can easily understand, also getting rid of some ambiguity in the original HIForest branch names.
You can see the input and output branch names, together with their types, in `lbl_renamer_config.py` - typically there's no need to modify this file.

The input/output paths are defined in `lbl_renamer_list.py` - you may need to adjust them, especially the output path.

Finally, have a look at `lbl_paths.py` - this is where we decide, among other things, which samples to run on. For instance, to use the example samples,
you can comment out everything except for "lbl" in the `processes` tuple.

When all paths look good, you can run the renaming. It's always a good idea to first try locally (and for this tiny sample it will be fast enough to just run it locally anyway):

```
python3 submitter.py --app lbl_renamer --config lbl_renamer_config.py --files_config lbl_renamer_list.py --local
```

You can now check that new files have been created in the output directory, which contain the `Events` tree with updated branch names.

As an excercise, you can also replace the `--local` flag with `--condor` to see how to run things on the grid. It will automatically schedule 1 job per file and produce the same output files as a result.

### Histogramming


