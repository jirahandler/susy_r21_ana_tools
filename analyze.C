#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TCanvas.h>
#include "tt.h"

void analyze()
{
    TFile *ff = new TFile("flav_Akt4EMPf_BTagging201810.root", "READ");
    TTree *tree = (TTree *)ff->Get("bTag_AntiKt4EMPFlowJets_BTagging201810");

    // set branches
    vector<float> *jet_pt = 0;
    vector<float> *jet_jf_llr = 0;

    // gInterpreter->GenerateDictionary("vector<vector<float> >", "vector");
    // vector<vector<float>>*  jet_bH_Lxy = 0;
    tree->SetBranchAddress("jet_pt", &jet_pt);
    tree->SetBranchAddress("jet_jf_llr", &jet_jf_llr);

    TH1D *histogram = new TH1D("jet_jf_llr", "jet_jf_llr", 200, -100, 100);

    for (Long64_t entry = 0; entry < tree->GetEntries(); ++entry)
    {
        tree->GetEntry(entry);

        int njet = 0;
        if (jet_pt)
            njet = jet_pt->size();

        if (njet == 0)
            continue;

        for (int j = 0; j < njet; ++j)
        {
            histogram->Fill((*jet_jf_llr)[j]);
        }
    }

    TCanvas *canvas = new TCanvas("canvas", "Canvas", 800, 600);
    histogram->Draw();
    canvas->SaveAs("jet_jf_llr_ttb.png");

    double integral_1 = histogram->Integral(0, -1);
    double integral_2 = histogram->Integral(0, histogram->FindBin(-2.5));
    double ratio = integral_2/integral_1;
    std::cout << "Ratio " << " is " << ratio << std::endl;

    delete histogram;
    delete canvas;

    ff->Close();
}