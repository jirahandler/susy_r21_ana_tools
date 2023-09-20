#include <TFile.h>
#include <TH1.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLatex.h>
#include "AtlasStyle.C"

int plot2d()
{
    SetAtlasStyle();
    gStyle->SetOptStat(0);

    // Input and output file names
    const int numFiles = 2;
    const char *inpfnames[numFiles] = {
        "a1_410470.root",
        "a1_hf_1700.root"
        };

    const char *hist2DNames[numFiles] = {
        "ntr_jpt",
        "ntr_jpt"

    };

    const char *outputFileName[numFiles] = {
        "jpt_vs_ntr-tt.pdf",
        "jpt_vs_ntr-hf.pdf"

    };

    // Load histograms from the ROOT files
    TFile *files[numFiles];
    for (int i = 0; i < numFiles; i++)
    {
        files[i] = TFile::Open(inpfnames[i]);
    }

    const int numHist2D = sizeof(hist2DNames) / sizeof(const char *);
    TH2 *h2dall[numHist2D];
    TH2 *h2dtag[numHist2D];

    for (int i = 0; i < sizeof(inpfnames) / sizeof(const char *); i++)
    {
        h2dall[i] = static_cast<TH2D *>(files[i]->Get(TString(hist2DNames[i]) + "_all"));
        h2dtag[i] = static_cast<TH2D *>(files[i]->Get(TString(hist2DNames[i]) + "_tag"));
    }

    TH1D *ratio[numHist2D];

    try
    {

        TString legtextprett = "t#bar{t} ";
        TString legtextposttt = " (single-b) ";

        TString legtextpre = "SUSY HF ";
        TString latexpart = " m_{#tilde{g}} ";
        TString legtextpostnp = " = 1700 GeV non prompt (single-b), ";

        // TString legtextpostnpcond = " #left|bip#right| > 10^{-5} , #left|bip#right| #leq 0.2, #DeltaR #leq 0.1  ";
        TString legtextpostnpcond_inc = " #left|bip#right| > 10^{-5} inclusive ";

        TString s1 = legtextprett + legtextposttt;
        TString s2 = "SUSY HF, m_{#tilde{g}} = 1700 GeV non prompt #left|bip#right| > 10^{-5} inclusive";

        TString leglabel[2] = {s1, s2};

        for (int i = 0; i < numFiles; i++)
        {

            TCanvas *c1 = new TCanvas("c1", "c1", 1400, 1400);
            c1->cd();

            TLegend *l = new TLegend(0.18, 0.86, 0.4, 0.96);
            l->SetMargin(0.2);
            l->SetBorderSize(0);
            l->SetFillStyle(0);
            l->SetTextFont(42);
            l->SetTextSize(0.03);

            h2dall[i]->SaveAs("c2all");
            h2dtag[i]->SaveAs("c2tag");

            ratio[i] = static_cast<TH1D *>(h2dall[i]->Clone());
            ratio[i]->Divide(h2dtag[i], h2dall[i]);
            ratio[i]->GetYaxis()->SetTitle("Jet p_{T} (GeV)");
            ratio[i]->GetXaxis()->SetTitle("Num Tracks");
            ratio[i]->SaveAs("ratiotext");
            ratio[i]->GetYaxis()->SetRangeUser(20., 250.);
            //ratio[i]->GetXaxis()->SetRangeUser(0, 20.);

            ratio[i]->Draw("COLZ");

            l->AddEntry(ratio[i], leglabel[i], "l");
            l->Draw();
            c1->SaveAs(outputFileName[i]);
            c1->Close();
        }

    }
    catch (const std::exception &ex)
    {
        std::cout << "EMPTY HISTOGRAMS BRUHHHHHHHHH??" << ex.what() << std::endl;
    }

    return 0;
}