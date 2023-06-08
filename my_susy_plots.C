/**
 * @file my_susy_plots.C
 * @author SammyG
 * @brief Get SUSY perf plots
 * @version 0.2
 * @date 2023-04-16
 */
#include "AtlasStyle.C"
// The package above is a local working directory include
void my_susy_plots()
{
    // Set ATLAS style
    SetAtlasStyle();

    // define plot types here
    // must match the partial names of histos found in a1_<dsid>.root
    const char *plot_type[] = {
        //"lxy",
        //"bip",
        //"jetpt_2",
        "ntrk",
        //"jetpt_0",
        //"jetpt_2_llp",
        //"jetpt_0_llp",
        //"dvR_2_llp",
        //"dvR_0_llp",

    };
    // define plot titles here
    const char *plot_title[] = {
        //"Lxy [mm]",
        //"b-impact parameter [mm]",
        //"b-jet p_{T} [GeV]",
        "number of tracks",
        //"light jet p_{T} [GeV]",
        //"b-jet (llp jets)  p_{T} [GeV]",
        //"light (llp jets) jet p_{T} [GeV]",
        //"LLP decay radius (b-jets) [mm]",
        //"LLP decay radius (light-jets) [mm]",
    };
    // Get number of plots to make
    int plctrsz = (sizeof(plot_type) / sizeof(plot_type[0]));

    // loop over different kinds of plot
    for (int plctr = 0; plctr < plctrsz; plctr++)
    {
        // btag: b-tagging is turned on or off
        // dofit: fitting between two different datasets in ratio plot sub-canvas
        bool btag = true;
        bool dofit = true;
        bool plot_ratio = true;
        /**
        if (plctr == 0 || plctr == 1) //|| plctr == 3 || plctr ==5)
            btag = true;
        if (plctr == 0 || plctr == 1) //|| plctr == 3 || plctr == 5)
            dofit = true;
        */
        if (plctr == 0)
        {
            btag = false;
            plot_ratio = false;
        }
        const char *chvar = plot_type[plctr];
        const char *chtitl = plot_title[plctr];

        // put DSIDs here of the analysis ntuple files you obtained after running d_ana
        // after running d_ana, you should have gotten output files of the form a1_<dsid>.root

        const char *filelist[] = {
            "503822",
            "503823",
            "503824",
            "503825",
            "410470",
            "410470",
            "410470",
            "410470"};

        /**
        const char *filelist[] = {
            "503767",
            "503768",
            "503769",
            "503770",
            "503771",
            "410470",
            "410470",
            "410470",
            "410470",
            "410470",
        };
        */
        // Get total size of the char array; div by 2 because ... pairs
        int fctr = (sizeof(filelist) / sizeof(filelist[0])) / 2;

        // load histograms and calculate efficiency
        // loop over pairs of datasets hf & lf (in this case)
        // fpctr=file pair counter

        for (int fpctr = 0; fpctr < fctr; fpctr++)
        {
            // Safeguard for certain datasets and plots
            // They have some missing stuff
            // if (plctr == 5 && fpctr == 3) continue;
            // if (plctr == 1 && fpctr == 2) continue;

            // This contains the list of files you want to compare
            const char *
                chfile[] = {filelist[fpctr], filelist[fpctr + 4]};
            const int nf = sizeof(chfile) / sizeof(const char *);
            TH1 *h[nf];

            // Number of colors go here
            // No of colors are provided for max 6 datasets, you can put more distinct colors
            const int icol[] = {1, 2, 4, 3, 6, 51};

            // Loop over files
            for (int kf = 0; kf < nf; ++kf)
            {
                TFile *ff = new TFile(TString("a1_") + chfile[kf] + ".root", "READ");
                if (plctr != 0)
                {
                    TH1 *hall = (TH1 *)ff->Get(TString(chvar) + "_all");
                    h[kf] = (TH1 *)ff->Get(TString(chvar) + "_tag");
                    if (!hall || !h[kf])
                    {
                        continue;
                    }
                    else
                    {
                        h[kf]->Divide(h[kf], hall, 1., 1., "B");
                    }
                }
                if (plctr == 0)
                {
                    cout << "chvar is: " << chvar << endl;
                    h[kf] = (TH1I *)ff->Get(TString(chvar));
                    if (!h[kf])
                    {

                        printf("Histogram is empty\n");
                        continue;
                    }
                    else
                    {
                        printf("Histogram is not empty\n");
                    }
                }
            }

            // Draw plots

            TCanvas *c1;
            TPad *lowerPad, *upperPad;

            if (plot_ratio)
            {
                c1 = new TCanvas("c1", "c1", 700, 800);
                lowerPad = new TPad("cl", "", 0, 0, 1., 0.375);
                upperPad = new TPad("cu", "", 0, 0.375, 1., 1.);
                if (plctr != 0)
                {
                    upperPad->SetLogx();
                    lowerPad->SetLogx();
                }
                if (!btag)
                    if (plctr != 0)
                        upperPad->SetLogy();
                lowerPad->Draw();
                upperPad->Draw();

                upperPad->cd();
                upperPad->SetGridx();
                upperPad->SetGridy();

                lowerPad->SetTopMargin(0.03);
                lowerPad->SetBottomMargin(0.29);
            }
            else
            {
                c1 = new TCanvas("c1", "c1", 700, 500);
                c1->SetGridx();
                c1->SetGridy();
                if (plctr != 0)
                    c1->SetLogx();
            }

            TLegend *l = new TLegend(0.7, 0.2, 0.85, 0.35);
            l->SetMargin(0.2);
            l->SetBorderSize(0);
            l->SetFillStyle(0);
            l->SetTextFont(42);

            for (int kf = 0; kf < nf; ++kf)
            {
                // Put empty histo safeguard
                if (plctr != 0)
                    if (!h[kf])
                        continue;

                h[kf]->SetMarkerStyle(8);
                h[kf]->SetMarkerSize(1.2);
                h[kf]->SetMarkerColor(icol[kf]);
                h[kf]->SetLineColor(icol[kf]);

                if (plctr == 0)
                {
                    double maxBinContent = TMath::Max(h[0]->GetMaximum(), h[1]->GetMaximum());

                    double scalingFactor1 = maxBinContent / h[0]->GetMaximum();
                    double scalingFactor2 = maxBinContent / h[1]->GetMaximum();

                    h[0]->Scale(scalingFactor1);
                    h[1]->Scale(scalingFactor2);
                }

                if (kf == 0)
                {
                    if (plctr != 0)
                        h[kf]->GetYaxis()->SetTitle("Tagging efficiency");
                    if (plctr == 0)
                        h[kf]->GetYaxis()->SetTitle("Number of entries");
                    if (btag)
                    {
                        h[kf]->SetMinimum(0);
                        h[kf]->SetMaximum(1.1);
                    }
                    else
                    {
                        if (plctr != 0)
                        {

                            h[kf]->SetMinimum(1e-4);
                            h[kf]->SetMaximum(1);
                        }
                        if (plctr == 0)
                        {

                            h[kf]->SetMinimum(0);
                            // h[kf]->SetMaximum(4e6);
                        }
                    }
                    if (plctr != 0)

                        h[kf]->Draw("e0");
                    if (plctr == 0)
                        h[kf]->Draw("H");
                }
                else
                {
                    if (plctr != 0)
                        h[kf]->Draw("e0same");
                    if (plctr == 0)
                        h[kf]->Draw("H same");
                }
                l->AddEntry(h[kf], chfile[kf], "l");
            }
            if (plot_ratio)
            {
                h[0]->GetXaxis()->SetLabelSize(0);
                h[0]->GetXaxis()->SetTitleSize(0);
            }
            else
            {
                h[0]->GetXaxis()->SetTitle(chtitl);
                if (plctr != 0)
                    h[0]->GetXaxis()->SetMoreLogLabels();
            }

            l->Draw();

            if (plot_ratio)
            {

                lowerPad->cd();
                lowerPad->SetGridx();
                lowerPad->SetGridy();

                for (int kf = 1; kf < nf; ++kf)
                {
                    if (!h[kf])
                        continue;
                    TH1 *hhr = (TH1 *)h[kf]->Clone(TString(h[kf]->GetName()) + "_ratio");
                    hhr->Divide(hhr, h[0]);

                    if (kf == 1)
                    {
                        hhr->GetYaxis()->SetNdivisions(505);
                        hhr->GetYaxis()->SetTitle("Ratio to nominal");
                        hhr->GetYaxis()->SetTitleOffset(0.8);
                        hhr->GetYaxis()->SetTitleSize(0.085);
                        hhr->GetYaxis()->SetLabelSize(0.085);
                        hhr->GetXaxis()->SetTitleSize(0.085);
                        hhr->GetXaxis()->SetLabelSize(0.085);
                        hhr->GetXaxis()->SetTitle(chtitl);
                        if (plctr != 0)
                            hhr->GetXaxis()->SetMoreLogLabels();
                        hhr->GetXaxis()->SetTickLength(0.05);
                        hhr->SetMinimum(0.1);
                        hhr->SetMaximum(2.5);
                        hhr->Draw();
                    }
                    else
                    {
                        hhr->Draw("same");
                    }

                    if (dofit)
                    {
                        hhr->Fit("pol0", "q0");
                        TF1 *fun = hhr->GetFunction("pol0");
                        fun->SetLineColor(hhr->GetLineColor());
                        fun->Draw("same");
                        double p0 = fun->GetParameter(0);
                        double e0 = fun->GetParError(0);
                        TLatex *tt = new TLatex();
                        tt->SetNDC();
                        tt->SetTextFont(42);
                        tt->SetTextSize(0.08);
                        tt->DrawLatex(0.2, 0.95 - kf * 0.1, TString::Format("p0 = %.3f #pm %.3f", p0, e0));
                    }
                }
            }

            c1->Modified();

            TString sp = "tagrate_";
            sp += chvar;
            for (int kf = 0; kf < nf; ++kf)
            {
                sp += "_";
                sp += chfile[kf];
            }
            sp += ".png";
            c1->SaveAs(sp);
            delete c1;
        }
    }
}