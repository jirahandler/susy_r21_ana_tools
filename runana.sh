for f in 410470/410470.root; do ./bin/tt_ana $f ; done
for f0 in lf_all/*.root; do ./bin/sus_ana $f0 ; done
for f1 in hf_all/*.root; do ./bin/sus_ana $f1 ; done
