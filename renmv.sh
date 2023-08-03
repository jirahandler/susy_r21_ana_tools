for i in {503822..503825}; do
  for rofl in $(ls "user.sgoswami.mc16_13TeV.$i."*/*.root); do
    cp "$(readlink -e "$rofl")" "$i/"
  done
done


# Directory containing the folders
folder_dir="."

# Array of folder names
folders=("503822" "503823" "503824" "503825")

# Iterate over the folder names
for foldername in "${folders[@]}"; do
      folder="$folder_dir/$foldername"

          # Check if the folder exists
            if [ -d "$folder" ]; then
                    merged_file="${foldername}.root"

                            # Run hadd on all root files within the folder
                                hadd -f "$folder/$merged_file" "$folder"/*.root

                                        # Delete all remaining root files except the merged file
                                            find "$folder" -type f -not -name "$merged_file" -name "*.root" -exec rm {} \;
                                              fi
                                              done