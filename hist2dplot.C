#include <TCanvas.h>
#include <TH2.h>
#include <TFile.h>

void plot2DHistograms(const char *file1, const char *file2, const char *histName1, const char *histName2)
{
    // Open the input files
    TFile *f1 = TFile::Open(file1);
    TFile *f2 = TFile::Open(file2);

    // Get the histograms from the input files
    TH2 *h1 = dynamic_cast<TH2 *>(f1->Get(histName1));
    TH2 *h2 = dynamic_cast<TH2 *>(f2->Get(histName2));
    h1->GetYaxis()->SetTitle("lxy");
    h1->GetXaxis()->SetTitle("bip");
    h2->GetYaxis()->SetTitle("lxy");
    h2->GetXaxis()->SetTitle("bip");
    h1->SetStats(0);
    h2->SetStats(0);

    h1->GetXaxis()->SetRangeUser(0, 6);
    h1->GetYaxis()->SetRangeUser(0, 70);

    h2->GetXaxis()->SetRangeUser(0, 100);
    h2->GetYaxis()->SetRangeUser(0, 100);

    h1->SetTitle("tt-bar");
    h2->SetTitle("SUSY HF Combined");

    // Create a canvas to display the histograms
    TCanvas *canvas = new TCanvas("canvas", "2D Histograms", 800, 800);

    // Divide the canvas into two pads
    canvas->Divide(1, 2);

    // Upper pad for the first histogram
    canvas->cd(1);
    h1->Draw("colz");
    gPad->SetLogz(); // Set logarithmic scale for the color axis if desired

    // Lower pad for the second histogram
    canvas->cd(2);
    h2->Draw("colz");
    gPad->SetLogz(); // Set logarithmic scale for the color axis if desired

    // Save the canvas as a PNG image
    canvas->SaveAs("bip_lxy_histograms.png");

    // Clean up
    delete canvas;
    delete f1;
    delete f2;
}

void hist2dplot()
{
    const char *file1 = "a1_410470.root";
    const char *file2 = "a1_hfall.root";
    const char *histName1 = "bip_lxy_all";
    const char *histName2 = "bip_lxy_all";
    plot2DHistograms(file1, file2, histName1, histName2);
}
