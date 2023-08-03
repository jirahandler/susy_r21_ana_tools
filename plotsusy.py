import uproot
import awkward as ak
import hist
import matplotlib.pyplot as plt
import numpy as np

# Step 1: Load histograms from the ROOT files
file1 = uproot.open("a1_410470.root")
file2 = uproot.open("a1_hf_1700.root")

# Assuming 'ntrk_all' and 'ntrk_tag' are at the top level of the ROOT files
hist1_ntrk_all = file1["ntrk_all"].to_numpy()
hist1_ntrk_tag = file1["ntrk_tag"].to_numpy()

hist2_ntrk_all = file2["ntrk_all"].to_numpy()
hist2_ntrk_tag = file2["ntrk_tag"].to_numpy()

# Step 2: Perform the division using loops
ratio1 = []
ratio2 = []

for tag, all_ in zip(hist1_ntrk_tag, hist1_ntrk_all):
    ratio1.append(tag / all_)

for tag, all_ in zip(hist2_ntrk_tag, hist2_ntrk_all):
    ratio2.append(tag / all_)

ratio1 = np.array(ratio1)
ratio2 = np.array(ratio2)

# Step 3: Create a canvas with upper and lower pads using hist
fig, (ax_upper, ax_lower) = plt.subplots(nrows=2, sharex=True, gridspec_kw={'height_ratios': [3, 1]})

# Step 4: Plot the divided histograms on the upper pad with legends
hist.plot1d(hist1_ntrk_tag, ax=ax_upper, color="blue", label="File 1: ntrk_tag")
hist.plot1d(hist2_ntrk_tag, ax=ax_upper, color="red", label="File 2: ntrk_tag")
ax_upper.legend()

# Step 5: Plot the ratio of the divided histograms on the lower pad with legends
hist.plot1d(ratio1, ax=ax_lower, color="blue", label="File 1: ntrk_tag/ntrk_all")
hist.plot1d(ratio2, ax=ax_lower, color="red", label="File 2: ntrk_tag/ntrk_all")
ax_lower.legend()

# Set labels for x and y axes
ax_lower.set_xlabel("x-axis label")
ax_upper.set_ylabel("y-axis label")
ax_lower.set_ylabel("Ratio")

# Save the plot as a PNG file
plt.savefig("output_plot.png")

# Show the plot
plt.show()
