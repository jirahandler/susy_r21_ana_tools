#include <TCanvas.h>
#include <TH1.h>
#include <TFile.h>
#include <TLegend.h>
#include <TString.h>

void CreateRatioPlot(const char *files[], const TString histNames[])
{
    // Open the input files
    TFile *f[3];
    for (int i = 0; i < 3; ++i)
    {
        f[i] = TFile::Open(files[i]);
    }

    // Get the histograms from the input files
    TH1 *h[6];
    for (int i = 0; i <6; ++i)
    {
        h[i] = dynamic_cast<TH1 *>(f[i/2]->Get(histNames[i]));
    }
    //canvas->SetLogy();

    // Divide h[0] by h[1] and store the result in hblxy
    TH1 *hblxy = dynamic_cast<TH1 *>(h[0]->Clone("hblxy"));
    hblxy->Divide(h[1]);
    hblxy->SetLineColor(kRed);
    hblxy->SetMarkerColor(kRed);
    hblxy->SetMarkerStyle(20);
    hblxy->SetMarkerSize(1.2);
    hblxy->GetYaxis()->SetTitle("Tagging efficiency");
    hblxy->GetYaxis()->SetTitleSize(0.06);
    // hblxy->SetTitle(histNames[0] + " / " + histNames[1]);
    hblxy->SetStats(0); // Disable the stats box
    hblxy->SetMinimum(0.0001);
    // hblxy->SetMaximum(1.0);

    TH1 *hblxy_wc = dynamic_cast<TH1 *>(h[4]->Clone("hblxy_wc"));
    hblxy_wc->Divide(h[5]);
    hblxy_wc->SetLineColor(kBlue);
    hblxy_wc->SetMarkerColor(kBlue);
    hblxy_wc->SetMarkerStyle(20);
    hblxy_wc->SetMarkerSize(1.2);
    hblxy_wc->GetYaxis()->SetTitleSize(0.06);
    hblxy_wc->SetStats(0);
    hblxy_wc->SetMinimum(0.0001);


    // Divide h[2] by h[3] and store the result in hcxy
    TH1 *hcxy = dynamic_cast<TH1 *>(h[2]->Clone("hcxy"));
    hcxy->Divide(h[3]);
    hcxy->SetLineColor(kGreen);
    hcxy->SetMarkerColor(kGreen);
    hcxy->SetMarkerStyle(8);
    hcxy->SetMarkerSize(1.2);
    hcxy->SetStats(0);
    hcxy->SetMinimum(0.0001);
    hcxy->SetMaximum(1.0);
    hcxy->GetXaxis()->SetTitle("Lxy");
    hcxy->GetXaxis()->SetMoreLogLabels();

    // Create a canvas to display the histograms and ratio plot
    TCanvas *canvas = new TCanvas("canvas", "Ratio Plot", 1200, 800);
    canvas->SetGridx();
    canvas->SetGridy();
    //canvas->SetLogx();


    TPad *lowerPad, *upperPad;
    lowerPad = new TPad("cl", "", 0, 0, 1., 0.375);
    upperPad = new TPad("cu", "", 0, 0.375, 1., 1.);

    upperPad->SetLogx();
    upperPad->SetLogy();
    lowerPad->SetLogx();

    lowerPad->Draw();
    upperPad->Draw();

    upperPad->cd();
    upperPad->SetGridx();
    upperPad->SetGridy();

    lowerPad->SetTopMargin(0.03);
    lowerPad->SetBottomMargin(0.29);


    // Draw hblxy and hcxy on the canvas
    hblxy->Draw("HIST");
    hblxy_wc->Draw("HIST SAME");
    hcxy->Draw("HIST SAME");
    canvas->SetTitle("b-eff vs Lxy vs c-eff vs Lxy");
    canvas->Modified();

    // Create a legend to display the histogram names
    TLegend *l = new TLegend(0.7, 0.2, 0.85, 0.35);
    l->SetMargin(0.2);
    l->SetBorderSize(0);
    l->SetFillStyle(0);
    l->SetTextFont(42);
    l->AddEntry(hblxy, histNames[0] + " / " + histNames[1], "l");
    l->AddEntry(hcxy, histNames[2] + " / " + histNames[3], "l");
    l->AddEntry(hblxy_wc, histNames[4] + " / " + histNames[5], "l");
    l->Draw();


    // Switch to lower pad
    lowerPad->cd();

    // Create a histogram for the ratio of hblxy divided by hcxy
    TH1* hhr[2];

    hhr[0] = dynamic_cast<TH1 *>(hblxy->Clone("h_blxy_cxy"));
    hhr[0]->Divide(hblxy,hcxy,1,1,"B");
    hhr[0]->SetLineColor(kRed);
    hhr[0]->SetMarkerColor(kRed);
    hhr[0]->SetTitle("Tagging efficiency plots for tt-bar");
    hhr[0]->GetYaxis()->SetNdivisions(505);
    hhr[0]->GetYaxis()->SetTitle("Ratio to nominal");
    hhr[0]->GetYaxis()->SetTitleOffset(0.5);
    hhr[0]->GetYaxis()->SetTitleSize(0.085);
    hhr[0]->GetYaxis()->SetLabelSize(0.085);
    hhr[0]->GetXaxis()->SetTitleSize(0.085);
    hhr[0]->GetXaxis()->SetLabelSize(0.085);
    hhr[0]->GetXaxis()->SetTitle("Lxy");
    hhr[0]->GetXaxis()->SetMoreLogLabels();
    hhr[0]->GetXaxis()->SetTickLength(0.05);
    hhr[0]->Draw("E");

    hhr[1] = dynamic_cast<TH1 *>(hblxy->Clone("h_blxy_wc_cxy"));
    hhr[1]->Divide(hblxy_wc, hcxy, 1, 1, "B");
    hhr[1]->SetLineColor(kBlue);
    hhr[1]->SetMarkerColor(kBlue);
    hhr[1]->Draw("E SAME");

    // Save the canvas as a PNG image
    canvas->SaveAs("ratio_plot_beff_ceff_vs_lxy.png");

    // Clean up
    delete canvas;
    for (int i = 0; i < 2; ++i)
    {
        delete f[i];
    }
}

void plotHist()
{
    const char *files[] = {"a1_410470.root", "a1_410470.root", "a1_410470.root" };
    TString histNames[] = {"lxy_tag", "lxy_all", "cxy_tag", "cxy_all","lxy_wc_tag","lxy_wc_all"};
    CreateRatioPlot(files, histNames);
}
