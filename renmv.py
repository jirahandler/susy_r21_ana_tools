import os
import shutil

def main():
  # Get the list of all folders
  folders = os.listdir()

  # Iterate over the folders
  for folder in folders:
    # Get the six digit number from the folder name
    six_digit_number = folder.split(".")[0][-6:]

    # Create a new folder with the six digit number as the folder name
    new_folder = os.path.join(os.getcwd(), six_digit_number)
    os.makedirs(new_folder)

    # Move all root files from the original folder to the new folder
    files = os.listdir(folder)
    for file in files:
      if file.endswith(".root"):
        shutil.move(os.path.join(folder, file), new_folder)

    # Run hadd on the new folder and save the merged root files with the following name <six digit foldername.root>
    command = "hadd {} {}".format(six_digit_number + ".root", os.path.join(new_folder, "*.root"))
    os.system(command)

if __name__ == "__main__":
  main()
