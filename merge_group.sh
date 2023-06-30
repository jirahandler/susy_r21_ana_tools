#!/bin/bash
unset output_file_prefix
unset file_start
unset file_end
unset increment
unset filename_increment

hadd merged_file_1100.root a1_503822.root a1_503823.root a1_503824.root a1_503825.root

output_file_prefix="merged_file"
file_start=503827
file_end=503856
increment=5
filename_increment=100

# Loop through the file numbers in groups of 5
for ((i=file_start; i<=file_end; i+=increment)); do
	    output_file_number=$(( (i - file_start) / increment * filename_increment + 1200 ))
		    output_file="${output_file_prefix}_${output_file_number}.root"

			    # Execute hadd command
				    hadd -f "$output_file" "a1_${i}.root" "a1_$((i+1)).root" "a1_$((i+2)).root" "a1_$((i+3)).root" "a1_$((i+4)).root"
					done
