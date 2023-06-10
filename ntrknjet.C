#include <iostream>
#include <filesystem>
#include <TFile.h>
#include <TCanvas.h>
#include <TH1.h>
#include <TLegend.h>
#include <TGraphErrors.h>
#include <TPad.h>
#include <TStyle.h>
#include <vector>
#include <string>

#include "AtlasStyle.C" // Include the ATLAS style header file

namespace fs = std::filesystem;

void plotHistogramsAndRatio(const std::string fileName, std::vector<TH1 *> &histograms, const std::vector<std::string> &names, const std::string &title, const std::string &saveName, std::vector<TH1 *> &referenceHist, const std::string &referenceFileName, bool enableRatioPlot = false)
{
    SetAtlasStyle(); // Set the ATLAS style

    TCanvas *canvas = new TCanvas("canvas", "Histograms", 800, 800);
    // canvas->SetMargin(0.1, 0.1, 0.1, 0.1);
    const int icol[] = {1, 2, 4, 3, 6, 51};
    const int icolref[] = {7, 9, 11, 15, 17, 62};

    TPad *lowerPad = nullptr;
    TPad *upperPad = nullptr;
    TH1 *ratioHist = nullptr;

    if (enableRatioPlot)
    {
        lowerPad = new TPad("cl", "", 0, 0, 1., 0.375);
        upperPad = new TPad("cu", "", 0, 0.375, 1., 1.);
        lowerPad->SetTopMargin(0.02);
        lowerPad->SetBottomMargin(0.3);
        upperPad->SetBottomMargin(0.02);

        canvas->cd();
        upperPad->Draw();
        lowerPad->Draw();
        upperPad->cd();

        referenceHist[0]->SetTitle(title.c_str());
        referenceHist[0]->GetXaxis()->SetLabelSize(0);
        referenceHist[0]->GetXaxis()->SetTitleSize(0);
        referenceHist[0]->SetMarkerStyle(8);
        referenceHist[0]->SetMarkerSize(1.2);
        referenceHist[0]->SetMarkerColor(icolref[0]);
        referenceHist[0]->SetLineColor(icolref[0]);
        referenceHist[0]->GetYaxis()->SetTitle("Number of entries");
        referenceHist[0]->Draw("HIST");

        for (size_t i = 1; i < referenceHist.size(); ++i)
        {
            double maxBinContent = TMath::Max(referenceHist[0]->GetMaximum(), referenceHist[i]->GetMaximum());
            double scalingFactor1 = maxBinContent / referenceHist[0]->GetMaximum();
            double scalingFactor2 = maxBinContent / referenceHist[i]->GetMaximum();
            referenceHist[i]->Scale(scalingFactor2 / scalingFactor1);
            referenceHist[i]->SetTitle(title.c_str());
            referenceHist[i]->GetXaxis()->SetLabelSize(0);
            referenceHist[i]->GetXaxis()->SetTitleSize(0);
            referenceHist[i]->SetMarkerStyle(8);
            referenceHist[i]->SetMarkerSize(1.2);
            referenceHist[i]->SetMarkerColor(icolref[i]);
            referenceHist[i]->SetLineColor(icolref[i]);
            referenceHist[i]->Draw("HIST SAME");
        }

        for (size_t i = 0; i < histograms.size(); ++i)
        {
            double maxBinContent = TMath::Max(referenceHist[0]->GetMaximum(), histograms[i]->GetMaximum());
            double scalingFactor1 = maxBinContent / referenceHist[0]->GetMaximum();
            double scalingFactor2 = maxBinContent / histograms[i]->GetMaximum();
            histograms[i]->Scale(scalingFactor2 / scalingFactor1);
            histograms[i]->SetMarkerStyle(8);
            histograms[i]->SetMarkerSize(1.2);
            histograms[i]->SetMarkerColor(icol[i + 1]);
            histograms[i]->SetLineColor(icol[i + 1]);
            histograms[i]->Draw("HIST SAME");
        }

        TLegend *legend = new TLegend(0.7, 0.2, 0.85, 0.35);
        legend->SetMargin(0.2);
        legend->SetBorderSize(0);
        legend->SetFillStyle(0);
        legend->SetTextFont(42);
        legend->SetTextSize(0.015);
        legend->SetNColumns(1);
        for (size_t i = 0; i < referenceHist.size(); ++i)
        {
            legend->AddEntry(referenceHist[i], (std::string(referenceHist[i]->GetName()) + " , " + fs::path(referenceFileName).stem().string().substr(3)).c_str(), "l");
        }

        for (size_t i = 0; i < histograms.size(); ++i)
        {
            legend->AddEntry(histograms[i], (std::string(histograms[i]->GetName()) + " , " + fs::path(fileName).stem().string().substr(3)).c_str(), "l");
        }

        legend->Draw();

        canvas->cd();
        lowerPad->cd();
        gPad->SetGridx();
        gPad->SetGridy();

        ratioHist = (TH1 *)histograms[0]->Clone("ratioHist");
        ratioHist->Divide(referenceHist[0]);
        ratioHist->GetYaxis()->SetNdivisions(505);
        ratioHist->GetYaxis()->SetTitle("Ratio to Reference");
        ratioHist->GetYaxis()->SetTitleOffset(0.8);
        ratioHist->GetYaxis()->SetTitleSize(0.085);
        ratioHist->GetYaxis()->SetLabelSize(0.085);
        ratioHist->GetXaxis()->SetTitleSize(0.085);
        ratioHist->GetXaxis()->SetLabelSize(0.085);
        ratioHist->SetMinimum(0.1);
        ratioHist->SetMaximum(2.5);
        ratioHist->SetStats(0); // Disable the statistics box
        ratioHist->Draw();
    }
    else
    {
        canvas->cd();
        canvas->SetGridx();
        canvas->SetGridy();
        canvas->SetLogx();
        cout << "Size of hist array:" << histograms.size() << endl;

        referenceHist[0]->SetTitle(title.c_str());
        referenceHist[0]->SetMarkerStyle(8);
        referenceHist[0]->SetMarkerSize(1.2);
        referenceHist[0]->SetMarkerColor(icolref[0]);
        referenceHist[0]->SetLineColor(icolref[0]);
        referenceHist[0]->GetYaxis()->SetTitle("Number of entries");
        referenceHist[0]->Draw("HIST");

        /**
        for (size_t i = 1; i < referenceHist.size(); ++i)
        {
            double maxBinContent = TMath::Max(referenceHist[0]->GetMaximum(), referenceHist[i]->GetMaximum());
            double scalingFactor1 = maxBinContent / referenceHist[0]->GetMaximum();
            double scalingFactor2 = maxBinContent / referenceHist[i]->GetMaximum();
            referenceHist[i]->Scale(scalingFactor2 / scalingFactor1);
            referenceHist[i]->SetTitle(title.c_str());
            referenceHist[i]->GetXaxis()->SetLabelSize(0);
            referenceHist[i]->GetXaxis()->SetTitleSize(0);
            referenceHist[i]->SetMarkerStyle(8);
            referenceHist[i]->SetMarkerSize(1.2);
            referenceHist[i]->SetMarkerColor(icolref[i]);
            referenceHist[i]->SetLineColor(icolref[i]);
            referenceHist[i]->Draw("HIST SAME");
        }
        */
        double maxBinContent = referenceHist[0]->GetMaximum();

        for (size_t i = 1; i < referenceHist.size(); ++i)
        {
            double scalingFactor = maxBinContent / referenceHist[i]->GetMaximum();
            if (scalingFactor < 1.0)
            {
                referenceHist[i]->Scale(scalingFactor);
            }
            else
            {
                referenceHist[i]->Scale(1.0 / scalingFactor);
            }

            referenceHist[i]->SetTitle(title.c_str());
            referenceHist[i]->GetXaxis()->SetLabelSize(0);
            referenceHist[i]->GetXaxis()->SetTitleSize(0);
            referenceHist[i]->SetMarkerStyle(8);
            referenceHist[i]->SetMarkerSize(1.2);
            referenceHist[i]->SetMarkerColor(icolref[i]);
            referenceHist[i]->SetLineColor(icolref[i]);
            referenceHist[i]->Draw("HIST SAME");
        }

        cout << "Size of hist array:" << histograms.size() << endl;

        for (size_t i = 0; i < histograms.size(); ++i)
        {
            double maxBinContent = TMath::Max(referenceHist[0]->GetMaximum(), histograms[i]->GetMaximum());
            double scalingFactor1 = maxBinContent / referenceHist[0]->GetMaximum();
            double scalingFactor2 = maxBinContent / histograms[i]->GetMaximum();
            histograms[i]->Scale(scalingFactor2 / scalingFactor1);
            histograms[i]->SetMarkerStyle(8);
            histograms[i]->SetMarkerSize(1.2);
            histograms[i]->SetMarkerColor(icol[i + 1]);
            histograms[i]->SetLineColor(icol[i + 1]);
            histograms[i]->Draw("HIST SAME");
        }

        TLegend *legend = new TLegend(0.7, 0.2, 0.85, 0.35);
        legend->SetMargin(0.2);
        legend->SetBorderSize(0);
        legend->SetFillStyle(0);
        legend->SetTextFont(42);
        legend->SetTextSize(0.015);
        legend->SetNColumns(1);
        for (size_t i = 0; i < referenceHist.size(); ++i)
        {
            legend->AddEntry(referenceHist[i], (std::string(referenceHist[i]->GetName()) + " , " + fs::path(referenceFileName).stem().string().substr(3)).c_str(), "l");
        }

        for (size_t i = 0; i < histograms.size(); ++i)
        {
            legend->AddEntry(histograms[i], (std::string(histograms[i]->GetName()) + " , " + fs::path(fileName).stem().string().substr(3)).c_str(), "l");
        }

        legend->Draw();
        canvas->Modified();
        canvas->SaveAs(saveName.c_str());

        delete canvas;
        if (lowerPad)
            delete lowerPad;
        if (upperPad)
            delete upperPad;
        if (ratioHist)
            delete ratioHist;
    }
}
int ntrknjet()
{
    std::vector<std::string> fileNames = {
        "a1_hfall.root",
        "a1_503822.root",
        "a1_503823.root",
        "a1_503824.root",
        "a1_503825.root"};

    std::string referenceFileName = "a1_410470.root";

    fs::path referenceFilePath(referenceFileName);
    std::string referenceFileBaseName = referenceFilePath.stem().string();

    TFile *referenceFile = TFile::Open(referenceFileName.c_str(), "READ");

    std::vector<std::string> referencejetHistogramNames = {"nbjet"};
    std::vector<std::string> referencejetptHistogramNames = {"jetpt_2_all"};
    std::vector<std::string> referencejetlxyHistogramNames = {"lxy_all"};
    std::vector<std::string> referencejetbipHistogramNames = {"bip_all"};
    std::vector<std::string> referenceTrackHistogramNames = {"ntrk", "bjet_ntrk"};

    std::vector<TH1 *> referencejetHistograms;
    std::vector<std::string> referencejetNames;
    std::vector<TH1 *> referencejetptHistograms;
    std::vector<std::string> referencejetptNames;
    std::vector<TH1 *> referencejetlxyHistograms;
    std::vector<std::string> referencejetlxyNames;
    std::vector<TH1 *> referencejetbipHistograms;
    std::vector<std::string> referencejetbipNames;
    std::vector<TH1 *> referenceTrackHistograms;
    std::vector<std::string> referenceTrackNames;

    for (const auto &histName : referencejetHistogramNames)
    {
        TH1 *histogram = (TH1 *)referenceFile->Get(histName.c_str());
        referencejetHistograms.push_back(histogram);
        referencejetNames.push_back(histName);
    }
    for (const auto &histName : referencejetptHistogramNames)
    {
        TH1 *histogram = (TH1 *)referenceFile->Get(histName.c_str());
        referencejetptHistograms.push_back(histogram);
        referencejetptNames.push_back(histName);
    }
    for (const auto &histName : referencejetlxyHistogramNames)
    {
        TH1 *histogram = (TH1 *)referenceFile->Get(histName.c_str());
        referencejetlxyHistograms.push_back(histogram);
        referencejetlxyNames.push_back(histName);
    }
    for (const auto &histName : referencejetbipHistogramNames)
    {
        TH1 *histogram = (TH1 *)referenceFile->Get(histName.c_str());
        referencejetbipHistograms.push_back(histogram);
        referencejetbipNames.push_back(histName);
    }
    for (const auto &histName : referenceTrackHistogramNames)
    {
        TH1 *histogram = (TH1 *)referenceFile->Get(histName.c_str());
        referenceTrackHistograms.push_back(histogram);
        referenceTrackNames.push_back(histName);
    }

    // Loop through the other files
    for (const auto &fileName : fileNames)
    {
        TFile *file = TFile::Open(fileName.c_str());

        std::vector<TH1 *> jetHistograms;
        std::vector<std::string> jetNames;
        std::vector<TH1 *> jetptHistograms;
        std::vector<std::string> jetptNames;
        std::vector<TH1 *> jetlxyHistograms;
        std::vector<std::string> jetlxyNames;
        std::vector<TH1 *> jetbipHistograms;
        std::vector<std::string> jetbipNames;
        std::vector<TH1 *> trackHistograms;
        std::vector<std::string> trackNames;

        // Fetch jet histograms from current file
        std::vector<std::string> jetHistogramNames = {"nbjet", "nbpromptjet", "nbdisplacedjet"};
        for (const auto &histName : jetHistogramNames)
        {
            TH1 *histogram = (TH1 *)file->Get(histName.c_str());
            jetHistograms.push_back(histogram);
            jetNames.push_back(histName);
        }
        std::vector<std::string> jetptHistogramNames = {"jetpt_2_all",
                                                      "jetpt_2_prompt",
                                                      "jetpt_2_displaced"};
        for (const auto &histName : jetptHistogramNames)
        {
            TH1 *histogram = (TH1 *)file->Get(histName.c_str());
            jetptHistograms.push_back(histogram);
            jetptNames.push_back(histName);
        }

        std::vector<std::string> jetlxyHistogramNames = {"lxy_all",
                                                         "lxy_llp_all"};
        for (const auto &histName : jetlxyHistogramNames)
        {
            TH1 *histogram = (TH1 *)file->Get(histName.c_str());
            jetlxyHistograms.push_back(histogram);
            jetlxyNames.push_back(histName);
        }
        std::vector<std::string> jetbipHistogramNames = {"bip_all",
                                                         "bip_prompt_all",
                                                         "bip_displaced_all"}; //, "bip_all","bip_displaced_all", "bip_prompt_all"};
        for (const auto &histName : jetbipHistogramNames)
        {
            TH1 *histogram = (TH1 *)file->Get(histName.c_str());
            jetbipHistograms.push_back(histogram);
            jetbipNames.push_back(histName);
        }

        // Fetch track histograms from current file
        std::vector<std::string> trackHistogramNames = {"ntrk",
                                                        "bjet_ntrk",
                                                        "bpromptntrk",
                                                        "bdisplacedntrk"};
        for (const auto &histName : trackHistogramNames)
        {
            TH1 *histogram = (TH1 *)file->Get(histName.c_str());
            trackHistograms.push_back(histogram);
            trackNames.push_back(histName);
        }
        // Plot jet histograms on the same canvas and scale them mutually
        std::string jetTitle = "jet Histograms for " + fs::path(fileName).stem().string();
        std::string jetSaveName = "jet_histograms_" + fs::path(fileName).stem().string() + ".png";
        plotHistogramsAndRatio(fileName, jetHistograms, jetNames, jetTitle, jetSaveName, referencejetHistograms, referenceFileName, false);

        std::string jetptTitle = "jet pt Histograms for " + fs::path(fileName).stem().string();
        std::string jetptSaveName = "jet_pt_histograms_" + fs::path(fileName).stem().string() + ".png";
        plotHistogramsAndRatio(fileName, jetptHistograms, jetptNames, jetptTitle, jetptSaveName, referencejetptHistograms, referenceFileName, false);

        std::string jetlxyTitle = "jet lxy Histograms for " + fs::path(fileName).stem().string();
        std::string jetlxySaveName = "jet_lxy_histograms_" + fs::path(fileName).stem().string() + ".png";
        plotHistogramsAndRatio(fileName, jetlxyHistograms, jetlxyNames, jetlxyTitle, jetlxySaveName, referencejetlxyHistograms, referenceFileName, false);

        std::string jetbipTitle = "jet bip Histograms for " + fs::path(fileName).stem().string();
        std::string jetbipSaveName = "jet_bip_histograms_" + fs::path(fileName).stem().string() + ".png";
        plotHistogramsAndRatio(fileName, jetbipHistograms, jetbipNames, jetbipTitle, jetbipSaveName, referencejetbipHistograms, referenceFileName, false);

        // Plot track histograms on the same canvas
        std::string trackTitle = "Track Histograms for " + fs::path(fileName).stem().string();
        std::string trackSaveName = "track_histograms_" + fs::path(fileName).stem().string() + ".png";
        plotHistogramsAndRatio(fileName, trackHistograms, trackNames, trackTitle, trackSaveName, referenceTrackHistograms, referenceFileName, false);

        // Clean up
        delete file;
    }

    // Clean up
    delete referenceFile;

    return 0;
}