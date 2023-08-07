#include <TFile.h>
#include <TH1.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLatex.h>
#include "AtlasStyle.C"

int reweight()
{
    SetAtlasStyle();
    gStyle->SetOptStat(0);

    // Input and output file names
    const char *inputFile1 = "a1_410470.root";
    const char *inputFile2 = "a1_hf_1700.root";
    const char *outputFileName = "rw_lxy.root";

    // Load histograms from the ROOT files
    TFile *file1 = TFile::Open(inputFile1,"READ");
    TFile *file2 = TFile::Open(inputFile2, "READ");
    TFile *file3 = TFile::Open(outputFileName, "RECREATE");

    TH1F *hist1_lxy_all = static_cast<TH1F *>(file1->Get("lxy_all"));
    TH1F *hist2_lxy_all = static_cast<TH1F *>(file2->Get("lxy_p_all"));
    TH1F *hist3_lxy_all = static_cast<TH1F *>(file2->Get("lxy_np_all"));
    TH1F *hist4_lxy_all = static_cast<TH1F *>(file2->Get("lxy_np_inc_all"));

    try
    {
        TH1D *ratio1 = static_cast<TH1D *>(hist2_lxy_all->Clone("lxy_rw_p"));
        ratio1->Divide(hist1_lxy_all, hist2_lxy_all, 1.0, 1.0, "B");

        TH1D *ratio2 = static_cast<TH1D *>(hist3_lxy_all->Clone("lxy_rw_np"));
        ratio2->Divide(hist1_lxy_all, hist3_lxy_all, 1.0, 1.0, "B");

        TH1D *ratio3 = static_cast<TH1D *>(hist4_lxy_all->Clone("lxy_rw_np_inc"));
        ratio3->Divide(hist1_lxy_all, hist4_lxy_all, 1.0, 1.0, "B");

        ratio1->Write();
        ratio2->Write();
        ratio3->Write();
    }
    catch (const std::exception &ex)
    {
        std::cout << "EMPTY HISTOGRAMS BRUHHHHHHHHH??" << ex.what() << std::endl;
    }

    return 0;
}
