for f in /eos/user/s/sgoswami/public/syst_samples/410470/410*.root; do ./bin/tt_ana $f ; done
for f0 in /eos/user/s/sgoswami/public/syst_samples/lf_all/*/*.root; do ./bin/sus_ana $f0 ; done
for f1 in /eos/user/s/sgoswami/public/syst_samples/hf_all/*/*.root; do ./bin/sus_ana $f1 ; done