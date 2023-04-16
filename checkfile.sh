for line in `cat dataset_search_RPV_HF.txt`; do rucio list-files $line; done
for line in `cat dataset_search_RPV_LF.txt`; do rucio list-files $line; done
