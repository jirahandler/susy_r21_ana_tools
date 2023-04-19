/**
 * @file my_susyllp_plots.C
 * @author SammyG , Alexander Khanov
 * @brief Get SUSY llp jets perf plots
 * @version 0.1
 * @date 2023-04-16
 */
#include "AtlasStyle.C"
void draw_plots(bool plot_ratio, bool btag, bool dofit, TH1 *h1, TH1 *h2, TString l1, TString l2, TString l3, TString l4, const int icol1[], const char *chfile1[]);
void my_llpsusy_plots()
{
    // Set ATLAS style
    SetAtlasStyle();

    // put DSIDs here of the analysis ntuple files you obtained after running d_ana
    // after running d_ana, you should have gotten output files of the form a1_<dsid>.root
    const char *filelist[] = {"503767",
                              "503768",
                              "503769",
                              "503770",
                              "503822",
                              "503823",
                              "503824",
                              "503825"};
    // Get total size of the char array; div by 2 because ... pairs
    int fctr = (sizeof(filelist) / sizeof(filelist[0])) / 2;

    // Number of colors go here
    // No of colors are provided for max 6 datasets, you can put more distinct colors
    const int icol[] = {1, 2, 4, 3, 6, 51};

    // define plot types here
    // must match the partial names of histos found in a1_<dsid>.root
    const char *plot_type[] = {
        "jetpt_2",
        "jetpt_0",
        "jetpt_2_llp",
        "jetpt_0_llp",
        "dvR_2_llp",
        "dvR_0_llp",

    };
    // define plot titles here
    const char *plot_title[] = {
        "b-jet p_{T} [GeV]",
        "light jet p_{T} [GeV]",
        "b-jet (llp jets)  p_{T} [GeV]",
        "light (llp jets) jet p_{T} [GeV]",
        "LLP decay radius (b-jets) [mm]",
        "LLP decay radius (light-jets) [mm]",
    };
    // Get number of plots to make
    int plctrsz = (sizeof(plot_type) / sizeof(plot_type[0]));

    // btag: b-tagging is turned on or off
    // dofit: fitting between two different datasets in ratio plot sub-canvas
    // plot_ratio: plot ratio in the lower pad
    bool btag = false;
    bool dofit = false;
    bool plot_ratio = true;

    for (int fpctr = 0; fpctr < fctr; fpctr++)
    {
        // This contains the list of files you want to compare
        const char *chfile[] = {filelist[fpctr], filelist[fpctr + 4]};
        const int nf = sizeof(chfile) / sizeof(const char *);
        // Book file array
        TFile *f[2];
        f[0] = new TFile(TString("a1_") + chfile[0] + ".root");
        f[1] = new TFile(TString("a1_") + chfile[1] + ".root");

        // Book histo array. Suffix: a=all, t=tagged, res = division result of two hists
        TH1 *h1a[plctrsz];
        TH1 *h1t[plctrsz];
        TH1 *h2a[plctrsz];
        TH1 *h2t[plctrsz];
        TH1 *hres1[plctrsz];
        TH1 *hres2[plctrsz];
        for (int plctr = 0; plctr < plctrsz; plctr++)
        {
            // Safeguard for certain datasets and plots
            // They have some missing stuff
            //if (plctr == 3 && fpctr == 3)
            //    continue;

            const char *chvar = plot_type[plctr];
            const char *chtitl = plot_title[plctr];
            // load histograms and calculate efficiency
            // loop over pairs of datasets hf & lf (in this case)
            // fpctr = file pair counter
            h1a[plctr] = (TH1 *)f[0]->Get(TString(chvar) + "_all");
            h1t[plctr] = (TH1 *)f[0]->Get(TString(chvar) + "_tag");
            h2a[plctr] = (TH1 *)f[1]->Get(TString(chvar) + "_all");
            h2t[plctr] = (TH1 *)f[1]->Get(TString(chvar) + "_tag");
            if (!h1a[plctr]) { continue;}
            else    {hres1[plctr] = (TH1 *)h1a[plctr]->Clone(TString(chvar) + "_ratio");}
            if (!h2a[plctr]) {continue;}
            else    {hres2[plctr] = (TH1 *)h2a[plctr]->Clone(TString(chvar) + "_ratio");}

            // The Divide functions calculate efficiency
            if (!h1a[plctr] || !h1t[plctr]) {continue;}
           else {
                hres1[plctr]->Divide(h1t[plctr], h1a[plctr], 1., 1., "B");
            }
            if (!h2a[plctr] || !h2t[plctr]) {continue;}
            else {
                hres2[plctr]->Divide(h2t[plctr], h2a[plctr], 1., 1., "B");
            }
        }
        // Drawing function calls here
        // The temp strings have to do with the title/legends of the plot 
        // and filenames with which the plots are saved
        
        TString temp1 = "prompt_b_LF";
        TString temp2 = "b_from_n1_HF";
        //safeguard for empty histos
        if (!hres1[0] || !hres2[2]) continue;
        draw_plots(true, true, true, hres1[0], hres2[2], temp1, temp2, TString(hres1[0]->GetName()), TString(hres2[2]->GetName()), icol, chfile);

        temp1.TString::ReplaceAll(temp1, "prompt_light_LF");
        temp2.TString::ReplaceAll(temp2, "b_from_n1_HF");
        //safeguard for empty histos
        if (!hres1[1] || !hres2[2]) continue;
        draw_plots(true, true, true, hres1[1], hres2[2], temp1, temp2, TString(hres1[1]->GetName()), TString(hres2[2]->GetName()), icol, chfile);

        temp1.TString::ReplaceAll(temp1, "light_from_n1_LF");
        temp2.TString::ReplaceAll(temp2, "b_from_n1_HF");
        //safeguard for empty histos
        if (!hres1[3] || !hres2[2]) continue;
        draw_plots(true, true, true, hres1[3], hres2[2], temp1, temp2, TString(hres1[3]->GetName()), TString(hres2[2]->GetName()), icol, chfile);

        temp1.TString::ReplaceAll(temp1, "light_dvR_from_n1_LF");
        temp2.TString::ReplaceAll(temp2, "b_dvR_from_n1_HF");
        //safeguard for empty histos
        if (!hres1[5] || !hres2[4]) continue;
        draw_plots(true, true, true, hres1[5], hres2[4], temp1, temp2, TString(hres1[5]->GetName()), TString(hres2[4]->GetName()), icol, chfile);
    }
}

void draw_plots(bool plot_ratio, bool btag, bool dofit, TH1 *h1, TH1 *h2, TString l1, TString l2, TString l3, TString l4, const int icol1[], const char *chfile1[])
{
    TCanvas *c1;
    TPad *lowerPad, *upperPad;
    TH1 *h[2];

    h[0] = (TH1 *)h1->Clone(l3 + "_ratio");
    h[1] = (TH1 *)h2->Clone(l4 + "_ratio");

    if (plot_ratio)
    {
        c1 = new TCanvas("c1", "c1", 700, 800);
        lowerPad = new TPad("cl", "", 0, 0, 1., 0.375);
        upperPad = new TPad("cu", "", 0, 0.375, 1., 1.);
        upperPad->SetLogx();
        lowerPad->SetLogx();
        if (!btag)
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
        c1->SetLogx();
    }

    TLegend *l = new TLegend(0.7, 0.2, 0.85, 0.35);
    l->SetMargin(0.2);
    l->SetBorderSize(0);
    l->SetFillStyle(0);
    l->SetTextFont(42);

    for (int kf = 0; kf < 2; ++kf)
    {
        // Put empty histo safeguard
        if (!h[kf])
            continue;

        h[kf]->SetMarkerStyle(8);
        h[kf]->SetMarkerSize(1.2);
        h[kf]->SetMarkerColor(icol1[kf]);
        h[kf]->SetLineColor(icol1[kf]);
        if (kf == 0)
        {
            h[kf]->GetYaxis()->SetTitle("Tagging efficiency");
            if (btag)
            {
                h[kf]->SetMinimum(0);
                h[kf]->SetMaximum(1.1);
            }
            else
            {
                h[kf]->SetMinimum(1e-4);
                h[kf]->SetMaximum(1);
            }
            h[kf]->Draw("e0");
        }
        else
        {
            h[kf]->Draw("e0same");
        }
        if (kf==0)
        {
        l->AddEntry(h[0], l3,"l");
        l->AddEntry(h[1], l4,"l");
        }
    }
    if (plot_ratio)
    {
        h[0]->GetXaxis()->SetLabelSize(0);
        h[0]->GetXaxis()->SetTitleSize(0);
    }
    else
    {
        TString temp3 = l1 + "_" + l2;
        h[0]->GetXaxis()->SetTitle(temp3);
        h[0]->GetXaxis()->SetMoreLogLabels();
    }

    l->Draw();

    if (plot_ratio)
    {

        lowerPad->cd();
        lowerPad->SetGridx();
        lowerPad->SetGridy();

        for (int kf = 1; kf < 2; ++kf)
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
                hhr->GetXaxis()->SetTitle(l1+"_"+l2);
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

    TString sp = TString("tagrate_") + l1 +"_"+ l2;
    for (int kf = 0; kf < 2; ++kf)
    {
        sp += "_";
        sp += chfile1[kf];
        sp += "_";
    }
    sp += ".png";
    c1->SaveAs(sp);
    delete c1;
}

