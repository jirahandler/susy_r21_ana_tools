# What is this package?

This package deals with a CERN ATLAS SUSY R-Parity Violating / R-Parity Conserving Long Lived Analysis if you know what that is :P


## How to start?
First the DAOD FTAG1/FTAG2 samples of interest are fed through the light jets MC Calibration framework on the CERN grid. This code is closed, so you need to be a member of the ATLAS collaboration. The package resides in the legacy ATLAS-FTAG space (and also in my Github).
Once you obtain the ntuples, place them into two separate folders `hf_all` & `lf_all` for heavy and light flavor processes respectively. 
By running `hadd` you can combine them if there are more than one ntuple files per dataset.
`hadd` is a CERN ROOT command line utility to merge two root files.
See [hadd](https://manpages.ubuntu.com/manpages/xenial/man1/hadd.1.html) for documentation.
This utility accepts wildcards.


## Installation
First, `make` it in your cwd, provided you have CERN ROOT & Makefile utilities installed along with g++ , gcc & python3 (Mac OS would additionally need xcode installs)

| :warning:  This code uses c++17 standard|
|-----------------------------------------|

```bash
setupATLAS -q

#If you're on lxplus, CERN ROOT would automatically be installed
#Type `lsetup root`, the shell will correctly display the latest one
#Then try the version as shown on the prompt
lsetup "root <version name/number>"

#If you're running locally on a system with ROOT and all dependencies satisfied
make
```

## What do the codes do?

| Code/Folder  | Function |
| ------------- | ------------- |
| `a.C`  | Dummy file with C++/ROOT style template|
| `src/tt.cpp`  | Fills relevant information into the ntuples for tt-bar sample|
| `src/sus.cpp` | Fills relevant information into the ntuples for susy samples |
| `include/tt.h`| Header file containing definitions to `tt.cpp` |
| `include/sus.h`| Header file containing definitions to `sus.cpp` |
| `src/tt_ana` | Your executable to make ntuples to be passed on to the plotting script for tt-bar sample  |
| `src/sus_ana`| Your executable to make ntuples to be passed on to the plotting script for susy samples  |
| `obj/*`| Contains object files post `make` process  |
| `bin/*`| Contains binary executables post `make` process  |
| `AtlasStyle.C` | CERN ATLAS Plotting Style for CERN ROOT |
| `AtlasStyle.h` | Header for CERN ATLAS Plot Style `AtlasStyle.C`  |
| `MAKEFILE`   | compile command instructions for `make`  |
| `runana.sh` | Script to run `tt_ana` & `sus_ana` |
| `pl_perf.C`  | For plotting performance in general scenarios, self explanatory code  |
| `my_susy_plots.C`  | For plotting performance in general scenarios, self explanatory code  |
| `my_susyllp_plots.C`  | For plotting performance in general scenarios for jets from LLPs, self explanatory code  |
| `dataset_search_RPV_HF.txt`  | SUSY RPV HF Samples Gtt |
| `dataset_search_RPV_LF.txt`  | SUSY RPV LF Samples Gqq |
| `checkfile.sh`  | Script to check whether RPV heavy & light flavored samples exist from `dataset_search_RPV_*.txt` |
| `ntuples_RPV_HF.txt`  | ntuples on the grid after DAODs were passed through FTAG Legacy R-21 framework |
| `.vscode`  | Some example Microsoft vscode scripts to run root code locally|
| `gitcommit.sh`  | Edit this for the ease of committing and then `source gitcommit.sh`|

## Usage

```bash
#To get analysis files named a1_<DSID>.root
#Check runana.sh to make changes to your running directory etc
source runana.sh

#To get plots for light and b-jet efficiencies parametrized by kinematics or decay lengths (dv_R, r2v, lxy) etc
root -l -b -q  my_susy_plots.C
#To get plots for light and b-jet efficiencies parametrized by kinematics or decay lengths (dv_R, r2v, lxy) etc
#Using pyroot implementation (buggy, behavior depends on root versions)
python3  my_susy_plots.py
#For pairwise comparison of jet (from LLPs) tagging efficiencies parametrized by kinetmatics or decay lengths (dv_R, r2v, lxy) etc
root -l -b -q  my_susyllp_plots.C
```

## Contributing

I'd appreciate if you contribute major code optimizations and changes to this.

## License & Warranty
Any script out of the standard CERN packages come with the standard licenses, if any, applied to that official code.
The scripts not as a part of standard CERN packages come with no licenses and warranties whatsoever.