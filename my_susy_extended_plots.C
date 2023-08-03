#include "AtlasStyle.C"

void my_susy_extended_plots()
{
    SetAtlasStyle();

    const char *plot_type[] = {
        "ntrk"
        };

    const char *plot_title[] = {
        "Num Tracks"
        };

    const char *filelist[] = {
        "a1_hf_1700"
        };
    const char *ttfile = {"a1_410470"};

    int nplots = (sizeof(plot_type) / sizeof(plot_type[0]));
    int nfiles = (sizeof(filelist) / sizeof(filelist[0]));

    for (int kp = 0; kp < nplots; kp++)
    {
        if (kp == 1)
            continue;
        bool dofit = true;
        // Set some plotting flags
        if (kp == 2)
        {
            dofit = true;
        }
        cout << dofit << endl;

        // Set colors for plotting
        const int icol[] = {1, 2, 4, 3, 6, 51, 65};

        // Reserve nhistograms equal to nfiles

        for (int kf = 0; kf < nfiles; kf++)
        {
            TFile *tt_file = new TFile(TString(ttfile) + ".root", "READ");
            TFile *hf_file = new TFile(TString(filelist[kf]) + ".root", "READ");

            TH1 *hhf[2];
            TH1 *htt;

            TH1 *hf_hall[2];

            hf_hall[0] = (TH1 *)hf_file->Get(TString(plot_type[kp]) + "_all");
            TH1 *htt_hall = (TH1 *)tt_file->Get(TString(plot_type[kp]) + "_all");

            hhf[0] = (TH1 *)hf_file->Get(TString(plot_type[kp]) + "_tag");
            htt = (TH1 *)tt_file->Get(TString(plot_type[kp]) + "_tag");

            hhf[0]->Divide(hhf[0], hf_hall[0], 1., 1., "B");
            htt->Divide(htt, htt_hall, 1., 1., "B");

            // Set Canvas

            TPad *lowerPad, *upperPad;

            TCanvas *c1 = new TCanvas("c1", "c1", 700, 800);

            // Only if you want a ratio pad
            lowerPad = new TPad("cl", "", 0, 0, 1., 0.375);
            upperPad = new TPad("cu", "", 0, 0.375, 1., 1.);

            // upperPad->SetLogy();

            lowerPad->Draw();
            upperPad->Draw();

            upperPad->cd();
            upperPad->SetGridx();
            upperPad->SetGridy();

            lowerPad->SetTopMargin(0.03);
            lowerPad->SetBottomMargin(0.29);

            // Set Legend
            TLegend *l = new TLegend(0.7, 0.2, 0.85, 0.35);
            l->SetMargin(0.2);
            l->SetBorderSize(0);
            l->SetFillStyle(0);
            l->SetTextFont(42);
            l->SetTextSize(0.04);

            htt->SetMarkerStyle(8);
            htt->SetMarkerSize(1.2);
            htt->SetMarkerColor(icol[0]);
            htt->SetLineColor(icol[0]);

            hhf[0]->SetMarkerStyle(8);
            hhf[0]->SetMarkerSize(1.2);
            hhf[0]->SetMarkerColor(icol[1]);
            hhf[0]->SetLineColor(icol[1]);

            htt->GetYaxis()->SetTitle("Tagging efficiency");
            htt->GetXaxis()->SetRangeUser(0.01,100.);
            htt->SetMinimum(0); // or 0, if not log scale
            htt->SetMaximum(1.1);

            hhf[0]->SetMinimum(0); // or 0, if not log scale
            hhf[0]->SetMaximum(1.1);
            hhf[0]->GetXaxis()->SetRangeUser(0.01, 100.);

            htt->Draw("e0");
            hhf[0]->Draw("e0SAME");

            htt->GetXaxis()->SetLabelSize(0);
            htt->GetXaxis()->SetTitleSize(0);

            l->AddEntry(htt, "tt-bar", "l");
            l->AddEntry(hhf[0], filelist[kf], "l");

            l->Draw();

            lowerPad->cd();
            lowerPad->SetGridx();
            lowerPad->SetGridy();

            TH1 *hhr[2];
            hhr[0] = (TH1 *)hhf[0]->Clone(TString(hhf[0]->GetName()) + "_ratio");

            hhr[0]->Divide(hhr[0], htt);

            hhr[0]->GetYaxis()->SetNdivisions(505);
            hhr[0]->GetYaxis()->SetTitle("Ratio to nominal");
            hhr[0]->GetYaxis()->SetTitleOffset(0.8);
            hhr[0]->GetYaxis()->SetTitleSize(0.085);
            hhr[0]->GetYaxis()->SetLabelSize(0.085);
            hhr[0]->GetXaxis()->SetTitleSize(0.085);
            hhr[0]->GetXaxis()->SetLabelSize(0.085);
            hhr[0]->GetXaxis()->SetTitle(plot_title[kp]);
            hhr[0]->GetXaxis()->SetRangeUser(0.01, 100.);

            hhr[0]->GetXaxis()->SetMoreLogLabels();
            hhr[0]->GetXaxis()->SetTickLength(0.05);
            hhr[0]->SetMinimum(0.1);
            hhr[0]->SetMaximum(2.5);
            hhr[0]->Draw();

            TString sp = "new_tagrate_";
            sp += TString(plot_type[kp]) + "_" + TString(filelist[kf]) + "tt" + ".png";
            c1->SaveAs(sp);

            if (dofit)
            {
                hhr[0]->Fit("pol0", "q0");
                TF1 *fun = hhr[0]->GetFunction("pol0");
                fun->SetLineColor(hhr[0]->GetLineColor());
                fun->Draw("same");
                double p0 = fun->GetParameter(0);
                double e0 = fun->GetParError(0);
                TLatex *tt = new TLatex();
                tt->SetNDC();
                tt->SetTextFont(42);
                tt->SetTextSize(0.08);
                tt->DrawLatex(0.2, 0.95 - kf * 0.1, TString::Format("p0 = %.3f #pm %.3f", p0, e0));
            }
            c1->Modified();
            delete c1;
        }
    }
}
