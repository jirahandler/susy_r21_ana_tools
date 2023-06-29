setupATLAS -q
lsetup "root 6.28.00-x86_64-centos7-gcc11-opt"
make  clean
make

#for f in /eos/user/s/sgoswami/public/syst_samples/410470/410*.root; do ./bin/tt_ana $f ; done
#for f0 in /eos/user/s/sgoswami/public/syst_samples/lf_all/*/*.root; do ./bin/sus_ana $f0 ; done
#for f1 in /eos/user/s/sgoswami/public/syst_samples/hf_all/*/*.root; do ./bin/sus_ana $f1 ; done

#!/bin/bash


# Array to store the background process IDs
pids=()

# Iterate over the folders in the directory
directory_path="/eos/user/s/sgoswami/public/syst_samples/hf_all"

# Path to the directory containing the 'sus_ana' executable
executable_directory="./bin"

# Iterate over the folders in the directory
for folder_name in "$directory_path"/5*; do
    if [[ -d "$folder_name" ]]; then
        if [[ $(basename "$folder_name") =~ ^[0-9]{6}$ ]]; then
            six_digit_number=$(basename "$folder_name")

            # Find the root file in the folder
            root_file=$(find "$folder_name" -maxdepth 1 -name '*.root' -type f -print -quit)

            if [[ -n "$root_file" ]]; then
                # Perform the desired task with 'sus_ana' using the root file as an argument
                "$executable_directory/sus_ana" "$root_file" &
            fi
        fi
    fi
done

#foreground
#wait

#background
# Wait for all background processes to finish
for pid in "${pids[@]}"; do
    wait "$pid"
done
