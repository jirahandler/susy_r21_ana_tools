#include <TFile.h>
#include <TH1.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLatex.h>
#include "AtlasStyle.C"

int lfplotsntrk()
{
    SetAtlasStyle();
    gStyle->SetOptStat(0);

    // Input and output file names
    const char *inputFile1 = "a1_410470.root";
    const char *inputFile2 = "a1_lf_1100.root";
    const char *outputFileName = "eff_vs_ntrk_np_lf-tt.png";

    // Load histograms from the ROOT files
    TFile *file1 = TFile::Open(inputFile1);
    TFile *file2 = TFile::Open(inputFile2);

    TH1F *hist1_ntrk_all = static_cast<TH1F *>(file1->Get("ntrk_all"));
    TH1F *hist1_ntrk_tag = static_cast<TH1F *>(file1->Get("ntrk_tag"));

    TH1F *hist1a_ntrk_tag = static_cast<TH1F *>(file1->Get("ntrk_jf_tag"));

    TH1F *hist2_ntrk_all = static_cast<TH1F *>(file2->Get("ntrk_all"));

    TH1F *hist2_ntrk_tag = static_cast<TH1F *>(file2->Get("ntrk_tag"));
    TH1F *hist3_ntrk_tag = static_cast<TH1F *>(file2->Get("ntrk_tag_ip3d"));
    TH1F *hist4_ntrk_tag = static_cast<TH1F *>(file2->Get("ntrk_tag_sv1"));
    TH1F *hist5_ntrk_tag = static_cast<TH1F *>(file2->Get("ntrk_tag_jf"));

    try
    {
        if (hist1_ntrk_all->GetEntries() == 0 || hist2_ntrk_all->GetEntries() == 0)
        {
            throw std::runtime_error("One or both histograms are empty. Skipping efficiency calculation. Aborting... I'll be bacc.");
        }

        TH1D *ratio1 = static_cast<TH1D *>(hist1_ntrk_tag->Clone());
        ratio1->Divide(hist1_ntrk_tag, hist1_ntrk_all, 1.0, 1.0, "B");

        TH1D *ratio1a = static_cast<TH1D *>(hist1a_ntrk_tag->Clone());
        ratio1a->Divide(hist1a_ntrk_tag, hist1_ntrk_all, 1.0, 1.0, "B");

        TH1D *ratio2 = static_cast<TH1D *>(hist2_ntrk_tag->Clone());
        ratio2->Divide(hist2_ntrk_tag, hist2_ntrk_all, 1.0, 1.0, "B");

        TH1D *ratio3 = static_cast<TH1D *>(hist3_ntrk_tag->Clone());
        ratio3->Divide(hist3_ntrk_tag, hist2_ntrk_all, 1.0, 1.0, "B");

        TH1D *ratio4 = static_cast<TH1D *>(hist4_ntrk_tag->Clone());
        ratio4->Divide(hist4_ntrk_tag, hist2_ntrk_all, 1.0, 1.0, "B");

        TH1D *ratio5 = static_cast<TH1D *>(hist5_ntrk_tag->Clone());
        ratio5->Divide(hist5_ntrk_tag, hist2_ntrk_all, 1.0, 1.0, "B");

        TCanvas *canvas = new TCanvas("canvas", "Canvas", 1200, 1100);
        canvas->cd();

        TPad *pad_upper = new TPad("pad_upper", "pad_upper", 0, 0.3, 1, 1);
        pad_upper->SetTopMargin(0.02);
        pad_upper->Draw();
        pad_upper->cd();

        pad_upper->SetGridx();
        pad_upper->SetGridy();

        pad_upper->SetBottomMargin(0.05);

        ratio1->GetYaxis()->SetTitle("Tag Efficiency");
        ratio1->GetYaxis()->SetRangeUser(0, 1.1);

        ratio1->SetLineColor(kBlue);
        ratio1a->SetLineColor(kTeal);
        ratio2->SetLineColor(kRed);
        ratio3->SetLineColor(kGreen);
        ratio4->SetLineColor(kMagenta);
        ratio5->SetLineColor(kBlack);


        ratio1->GetXaxis()->SetRangeUser(0, 25);
        ratio1a->GetXaxis()->SetRangeUser(0, 25);
        ratio2->GetXaxis()->SetRangeUser(0, 25);
        ratio3->GetXaxis()->SetRangeUser(0, 25);
        ratio4->GetXaxis()->SetRangeUser(0, 25);
        ratio5->GetXaxis()->SetRangeUser(0, 25);

        ratio1->Draw("HIST");
        ratio1a->Draw("HIST SAME");
        ratio2->Draw("HIST SAME");
        ratio3->Draw("HIST SAME");
        ratio4->Draw("HIST SAME");
        ratio5->Draw("HIST SAME");

        TString legtextprett = "t#bar{t} ";
        TString legtextposttt = " (single-b tag eff) ";

        TString legtextpre = "SUSY LF ";
        TString latexpart = " m_{#tilde{g}} ";
        TString legtextpostnp = " = 1100 GeV , non prompt light jet tag eff ";


        TString rat1 = legtextprett + legtextposttt;
        TString rat1a = legtextprett + "JF"+ legtextposttt;
        TString rat2 = legtextpre + "DL1r " + latexpart + legtextpostnp;
        TString rat3 = legtextpre + "IP3d " + latexpart + legtextpostnp;
        TString rat4 = legtextpre + "SV1 " + latexpart + legtextpostnp;
        TString rat5 = legtextpre + "JF " + latexpart + legtextpostnp;

        TLegend *l = new TLegend(0.18, 0.76, 0.4, 0.96);
        l->SetMargin(0.2);
        l->SetBorderSize(0);
        l->SetFillStyle(0);
        l->SetTextFont(42);
        l->SetTextSize(0.03);
        l->AddEntry(ratio1, rat1, "l");
        l->AddEntry(ratio1a, rat1a, "l");
        l->AddEntry(ratio2, rat2, "l");
        l->AddEntry(ratio3, rat3, "l");
        l->AddEntry(ratio4, rat4, "l");
        l->AddEntry(ratio5, rat5, "l");
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
        ratio_lower->GetYaxis()->SetRangeUser(0.1, 2);
        ratio_lower->Draw();

        TH1F *ratio_lower1a = static_cast<TH1F *>(ratio1a->Clone());
        ratio_lower1a->Divide(static_cast<TH1F *>(ratio1->Clone()));
        ratio_lower1a->SetStats(0); // Disable statistics box for the ratio_lower
        ratio_lower1a->SetLineColor(kTeal);
        ratio_lower1a->SetMarkerColor(kTeal);
        ratio_lower1a->GetYaxis()->SetRangeUser(0.1, 2);
        ratio_lower1a->Draw("SAME");

        TH1F *ratio_lower1 = static_cast<TH1F *>(ratio3->Clone());
        ratio_lower1->Divide(static_cast<TH1F *>(ratio1->Clone()));
        ratio_lower1->SetStats(0); // Disable statistics box for the ratio_lower
        ratio_lower1->SetLineColor(kGreen);
        ratio_lower1->SetMarkerColor(kGreen);
        ratio_lower1->GetYaxis()->SetRangeUser(0.1, 2);
        ratio_lower1->Draw("SAME");

        TH1F *ratio_lower2 = static_cast<TH1F *>(ratio4->Clone());
        ratio_lower2->Divide(static_cast<TH1F *>(ratio1->Clone()));
        ratio_lower2->SetStats(0); // Disable statistics box for the ratio_lower
        ratio_lower2->SetLineColor(kMagenta);
        ratio_lower2->SetMarkerColor(kMagenta);
        ratio_lower2->GetYaxis()->SetRangeUser(0.1, 2);
        ratio_lower2->Draw("SAME");

        TH1F *ratio_lower3 = static_cast<TH1F *>(ratio5->Clone());
        ratio_lower3->Divide(static_cast<TH1F *>(ratio1->Clone()));
        ratio_lower3->SetStats(0); // Disable statistics box for the ratio_lower
        ratio_lower3->SetLineColor(kBlack);
        ratio_lower3->SetMarkerColor(kBlack);
        ratio_lower3->GetYaxis()->SetRangeUser(0.1, 2);
        ratio_lower3->Draw("SAME");



        TLegend *l1 = new TLegend(0.2, 0.5, 0.4, 0.8);
        l1->SetMargin(0.2);
        l1->SetBorderSize(0);
        l1->SetFillStyle(0);
        l1->SetTextFont(42);
        l1->SetTextSize(0.08);
        l1->AddEntry(ratio_lower, "LF non-prompt DL1r", "l");
        l1->AddEntry(ratio_lower1, "LF non-prompt IP3d", "l");
        l1->AddEntry(ratio_lower1a, "t#bar{t} prompt JF", "l");
        l1->AddEntry(ratio_lower2, "LF non-prompt SV1", "l");
        l1->AddEntry(ratio_lower3, "LF non-prompt JF", "l");
        l1->Draw();

        TString xTitle = "Num Tracks";
        TString yTitle = "Ratio";
        double xTitlePos = 0.9; // Position of X-axis title on the pad (0 = left, 1 = right)
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
