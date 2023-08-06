#include <TFile.h>
#include <TH1.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLatex.h>
#include "AtlasStyle.C"

int hfplotsntrk()
{
    SetAtlasStyle();
    gStyle->SetOptStat(0);

    // Input and output file names
    const char *inputFile1 = "a1_410470.root";
    const char *inputFile2 = "a1_hf_1700.root";
    const char *outputFileName = "Beff_vs_ntrk_p_np_npinc_hf-tt.png";

    // Load histograms from the ROOT files
    TFile *file1 = TFile::Open(inputFile1);
    TFile *file2 = TFile::Open(inputFile2);

    TH1F *hist1_ntrk_all = static_cast<TH1F *>(file1->Get("ntrk_all"));
    TH1F *hist1_ntrk_tag = static_cast<TH1F *>(file1->Get("ntrk_tag"));

    TH1F *hist2_ntrk_all = static_cast<TH1F *>(file2->Get("ntrk_np_all"));
    TH1F *hist2_ntrk_tag = static_cast<TH1F *>(file2->Get("ntrk_np_tag"));

    TH1F *hist3_ntrk_all = static_cast<TH1F *>(file2->Get("ntrk_p_all"));
    TH1F *hist3_ntrk_tag = static_cast<TH1F *>(file2->Get("ntrk_p_tag"));

    TH1F *hist4_ntrk_all = static_cast<TH1F *>(file2->Get("ntrk_np_inc_all"));
    TH1F *hist4_ntrk_tag = static_cast<TH1F *>(file2->Get("ntrk_np_inc_tag"));

    try
    {
        if (hist1_ntrk_all->GetEntries() == 0 || hist2_ntrk_all->GetEntries() == 0)
        {
            throw std::runtime_error("One or both histograms are empty. Skipping efficiency calculation. Aborting... I'll be bacc.");
        }

        TH1D *ratio1 = static_cast<TH1D *>(hist1_ntrk_tag->Clone());
        ratio1->Divide(hist1_ntrk_tag, hist1_ntrk_all, 1.0, 1.0, "B");

        TH1D *ratio2 = static_cast<TH1D *>(hist2_ntrk_tag->Clone());
        ratio2->Divide(hist2_ntrk_tag, hist2_ntrk_all, 1.0, 1.0, "B");

        TH1D *ratio3 = static_cast<TH1D *>(hist3_ntrk_tag->Clone());
        ratio3->Divide(hist3_ntrk_tag, hist3_ntrk_all, 1.0, 1.0, "B");

        TH1D *ratio4 = static_cast<TH1D *>(hist4_ntrk_tag->Clone());
        ratio4->Divide(hist4_ntrk_tag, hist4_ntrk_all, 1.0, 1.0, "B");

        TCanvas *canvas = new TCanvas("canvas", "Canvas", 1200, 1100);
        canvas->cd();

        TPad *pad_upper = new TPad("pad_upper", "pad_upper", 0, 0.3, 1, 1);
        pad_upper->SetTopMargin(0.02);
        pad_upper->Draw();
        pad_upper->cd();

        pad_upper->SetGridx();
        pad_upper->SetGridy();

        pad_upper->SetBottomMargin(0.05);

        ratio1->GetYaxis()->SetTitle("b-tag Efficiency");
        ratio1->GetYaxis()->SetRangeUser(0, 1.1);

        ratio1->SetLineColor(kBlue);
        ratio2->SetLineColor(kRed);
        ratio3->SetLineColor(kGreen);
        ratio4->SetLineColor(kMagenta);

        ratio1->GetXaxis()->SetRangeUser(0, 25);
        ratio2->GetXaxis()->SetRangeUser(0, 25);
        ratio3->GetXaxis()->SetRangeUser(0, 25);
        ratio4->GetXaxis()->SetRangeUser(0, 25);

        ratio1->Draw("HIST");
        ratio2->Draw("HIST SAME");
        ratio3->Draw("HIST SAME");
        ratio4->Draw("HIST SAME");

        TString legtextprett = "t#bar{t} ";
        TString legtextpre = "SUSY HF ";
        TString latexpart = " m_{#tilde{g}} ";
        TString legtextpostnp = " = 1700 GeV non prompt (single-b), ";
        TString legtextpostp = " = 1700 GeV prompt (single-b), ";
        TString legtextpostnpcond = " #left|bip#right| > 10^{-5} , #left|bip#right| #leq 0.2, #DeltaR #leq 0.1  ";
        TString legtextpostnpcond_inc = " #left|bip#right| > 10^{-5} ";
        TString legtextpostpcond = " #left|bip#right| #leq 10^{-5} ";
        TString legtextposttt = " (single-b) ";

        TString rat1 = legtextprett + legtextposttt;
        TString rat2 = legtextpre + latexpart + legtextpostnp + legtextpostnpcond;
        TString rat3 = legtextpre + latexpart + legtextpostp + legtextpostpcond;
        TString rat4 = legtextpre + latexpart + legtextpostnp + legtextpostnpcond_inc;

        TLegend *l = new TLegend(0.18, 0.86, 0.4, 0.96);
        l->SetMargin(0.2);
        l->SetBorderSize(0);
        l->SetFillStyle(0);
        l->SetTextFont(42);
        l->SetTextSize(0.03);
        l->AddEntry(ratio1, rat1, "l");
        l->AddEntry(ratio2, rat2, "l");
        l->AddEntry(ratio3, rat3, "l");
        l->AddEntry(ratio4, rat4, "l");
        l->Draw();

        canvas->cd();
        TPad *pad_lower = new TPad("pad_lower", "pad_lower", 0, 0, 1, .3);
        pad_lower->SetTopMargin(0.1);
        pad_lower->SetBottomMargin(0.3);
        pad_lower->Draw();
        pad_lower->cd();

        pad_lower->SetGridx();
        pad_lower->SetGridy();

        TH1F *ratio_lower = static_cast<TH1F *>(ratio2->Clone());
        ratio_lower->Divide(static_cast<TH1F *>(ratio1->Clone()));
        ratio_lower->SetStats(0); // Disable statistics box for the ratio_lower
        ratio_lower->SetLineColor(kRed);
        ratio_lower->SetMarkerColor(kRed);
        ratio_lower->Draw();

        TH1F *ratio_lower_1 = static_cast<TH1F *>(ratio3->Clone());
        ratio_lower_1->Divide(static_cast<TH1F *>(ratio1->Clone()));
        ratio_lower_1->SetStats(0); // Disable statistics box for the ratio_lower
        ratio_lower_1->SetLineColor(kGreen);
        ratio_lower_1->SetMarkerColor(kGreen);
        ratio_lower_1->GetYaxis()->SetRangeUser(0, 2.5);
        ratio_lower_1->Draw("SAME");

        TH1F *ratio_lower_2 = static_cast<TH1F *>(ratio4->Clone());
        ratio_lower_2->Divide(static_cast<TH1F *>(ratio1->Clone()));
        ratio_lower_2->SetStats(0); // Disable statistics box for the ratio_lower
        ratio_lower_2->SetLineColor(kMagenta);
        ratio_lower_2->SetMarkerColor(kMagenta);
        ratio_lower_2->GetYaxis()->SetRangeUser(0, 2.5);
        ratio_lower_2->Draw("SAME");

        TLegend *l1 = new TLegend(0.2, 0.5, 0.4, 0.8);
        l1->SetMargin(0.2);
        l1->SetBorderSize(0);
        l1->SetFillStyle(0);
        l1->SetTextFont(42);
        l1->SetTextSize(0.08);
        l1->AddEntry(ratio_lower, "HF non-prompt", "l");
        l1->AddEntry(ratio_lower_1, "HF prompt", "l");
        l1->AddEntry(ratio_lower_2, "HF non-prompt inclusive", "l");
        l1->Draw();

        TString xTitle = "Num Tracks";
        TString yTitle = "Ratio";
        double xTitlePos = 0.9;  // Position of X-axis title on the pad (0 = left, 1 = right)
        double yTitlePos = 0.2; // Position of X-axis title on the pad (0 = bottom, 1 = top)
        double xTitleSize = 0.08;
        double yTitleSize = 0.08;
        TLatex *latex = new TLatex();
        latex->SetTextFont(42);
        latex->SetTextSize(0.08);
        latex->SetTextAlign(22); // Center alignment
        pad_lower->cd();
        double xTitleNDC = pad_lower->GetX1() + (pad_lower->GetX2() - pad_lower->GetX1()) * xTitlePos;
        double yTitleNDC = pad_lower->GetY1() + (pad_lower->GetY2() - pad_lower->GetY1()) * yTitlePos;
        latex->DrawLatexNDC(xTitleNDC, yTitleNDC, xTitle); // X-axis title for the lower pad

        canvas->SaveAs(outputFileName);
    }
    catch (const std::exception &ex)
    {
        std::cout << "EMPTY HISTOGRAMS BRUHHHHHHHHH??" << ex.what() << std::endl;
    }

    return 0;
}
