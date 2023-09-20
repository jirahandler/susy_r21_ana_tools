#include <TFile.h>
#include <TH1.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLatex.h>
#include "AtlasStyle.C"

int binned_lxy_ntrk_plot()
{
    SetAtlasStyle();
    gStyle->SetOptStat(0);

    // Input and output file names
    const int numFiles = 3;
    const char *inpfnames[numFiles] = {
        "a1_410470_new.root",
        "a1_hf_1700_new_w.root",
        "a1_hf_1700_old_w.root"
    };

    const char *histNames[3] = {
        "ntrk",
        "ntrk_npw_inc",
        "ntrk_npw_inc"
    };

    const char *hist2DNames[2] = {
        "ntr_lxy",
        "ntr_lxy",
    };

    const char *outputFileName = "Beff_vs_ntrk_weighted_npinc_hf_new-tt.png";

    // Load histograms from the ROOT files
    TFile *files[numFiles];
    for (int i = 0; i < numFiles; i++)
    {
        files[i] = TFile::Open(inpfnames[i]);
    }
    const int numHist = sizeof(histNames) / sizeof(const char *);
    TH1 *hall[numHist];
    TH1 *htag[numHist];

    const int numHist2D = sizeof(hist2DNames) / sizeof(const char *);
    TH2 *hprojall[numHist2D];
    TH2 *hprojtag[numHist2D];

    for (int i = 0; i < sizeof(histNames) / sizeof(const char *); i++)
    {
        hall[i] = static_cast<TH1F *> (files[i]->Get(TString(histNames[i]) + "_all"));
        htag[i] = static_cast<TH1F *> (files[i]->Get(TString(histNames[i]) + "_tag"));
    }

    for (int i = 0; i < sizeof(hist2DNames) / sizeof(const char *); i++)
    {
        hprojall[i] = static_cast<TH2F *> (files[i]->Get(TString(hist2DNames[i]) + "_all"));
        hprojtag[i] = static_cast<TH2F *> (files[i]->Get(TString(hist2DNames[i]) + "_tag"));
    }

    TH1D *ratio[numHist];

    try
    {
        const int icol[] = {2, 4, 8, 1, 6, 5};

        TCanvas *canvas = new TCanvas("canvas", "Canvas", 1200, 1100);
        canvas->cd();

        TPad *pad_upper = new TPad("pad_upper", "pad_upper", 0, 0.3, 1, 1);
        pad_upper->SetTopMargin(0.02);
        pad_upper->Draw();
        pad_upper->cd();

        pad_upper->SetGridx();
        pad_upper->SetGridy();

        pad_upper->SetBottomMargin(0.05);

        for (int i = 0; i < numFiles; i++)
        {
            ratio[i] = static_cast<TH1D *>(htag[i]->Clone());
            ratio[i]->Divide(htag[i], hall[i], 1.0, 1.0, "B");
            if(i==0){
                ratio[i]->GetYaxis()->SetTitle("b-tag Efficiency");
                ratio[i]->GetYaxis()->SetRangeUser(0, 1.1);
            }
            ratio[i]->SetLineColor(icol[i]);
            ratio[i]->GetXaxis()->SetRangeUser(0, 25);
            if (i==0)
                {ratio[i]->Draw("HIST");}
            else
                {ratio[i]->Draw("HIST SAME");}
        }


        TString legtextprett = "t#bar{t} ";
        TString legtextposttt = " (single-b) ";

        TString legtextpre = "SUSY HF, weighted ";
        TString latexpart = " m_{#tilde{g}} ";
        TString legtextpostnp = " = 1700 GeV non prompt (single-b), ";

        //TString legtextpostnpcond = " #left|bip#right| > 10^{-5} , #left|bip#right| #leq 0.2, #DeltaR #leq 0.1  ";
        TString legtextpostnpcond_inc = " #left|bip#right| > 10^{-5} inclusive ";

        TString s1 = legtextprett + legtextposttt;
        TString s2 = legtextpre + latexpart + legtextpostnp + legtextpostnpcond_inc;
        TString s3 = legtextpre + latexpart + legtextpostnp + legtextpostnpcond_inc + "(ip3d def)";

        TString leglabel[3]={s1,s2,s3};

        TLegend *l = new TLegend(0.18, 0.86, 0.4, 0.96);
        l->SetMargin(0.2);
        l->SetBorderSize(0);
        l->SetFillStyle(0);
        l->SetTextFont(42);
        l->SetTextSize(0.03);
        for (int i = 0; i < sizeof(ratio) / sizeof(TH1D *); i++)
        {
            l->AddEntry(ratio[i], leglabel[i], "l");
        }
        l->Draw();

        canvas->cd();
        TPad *pad_lower = new TPad("pad_lower", "pad_lower", 0, 0, 1, .3);
        pad_lower->SetTopMargin(0.1);
        pad_lower->SetBottomMargin(0.3);
        pad_lower->Draw();
        pad_lower->cd();

        pad_lower->SetGridx();
        pad_lower->SetGridy();

        TH1D *l_ratio[(sizeof(ratio) / sizeof(TH1D *)) - 1];

        for (int i = 0; i < sizeof(ratio) / sizeof(TH1D *) -1; i++)
        {
            l_ratio[i] = static_cast<TH1D *>(ratio[i+1]->Clone());
            l_ratio[i]->Divide(static_cast<TH1D *>(ratio[0]->Clone()));
            l_ratio[i]->SetStats(0); // Disable statistics box for the lower ratio pad
            l_ratio[i]->SetLineColor(icol[i]);
            l_ratio[i]->SetMarkerColor(icol[i]);
            l_ratio[i]->GetYaxis()->SetRangeUser(0, 2.5);
            if(i==0)
                l_ratio[i]->Draw();
            else
                l_ratio[i]->Draw("SAME");
        }

        TString lp_leglabel[(sizeof(ratio) / sizeof(TH1D *)) - 1] = {
            "HF non-prompt inclusive",
            "HF non-prompt inclusive (ip3d def)"};

        TLegend *l1 = new TLegend(0.2, 0.5, 0.4, 0.8);
        l1->SetMargin(0.2);
        l1->SetBorderSize(0);
        l1->SetFillStyle(0);
        l1->SetTextFont(42);
        l1->SetTextSize(0.08);
        for (int i = 0; i < (sizeof(ratio) / sizeof(TH1D *)) - 1; i++)
        {
            l1->AddEntry(l_ratio[i], lp_leglabel[i], "l");
        }
        l1->Draw();

        TString xTitle = "Num Tracks";
        TString yTitle = "Ratio";
        double xTitlePos = 0.9; // Position of X-axis title on the pad (0 = left, 1 = right)
        double yTitlePos = 0.2; // Position of y-axis title on the pad (0 = bottom, 1 = top)
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