#define sus_cxx
#include "sus.h"

#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TVector3.h>

#include <iostream>
#include <cmath>
#include <map>

using namespace std;

double delR(double eta1, double eta2, double phi1, double phi2)
{
    double deta = eta1 - eta2;
    double dphi = phi1 - phi2;
    if (dphi < -M_PI)
        dphi += 2 * M_PI;
    else if (dphi >= M_PI)
        dphi -= 2 * M_PI;
    return sqrt(deta * deta + dphi * dphi);
}

void sus::Loop()
{

    if (fChain == 0)
        return;

    // book histograms
    TH1 *h_njet = new TH1I("njet", "", 10, 0., 10.);
    TH1 *h_nbjet = new TH1I("nbjet", "", 10, 0., 10.);
    TH1 *h_nbbjet = new TH1I("nbbjet", "", 100, 0., 100.);
    TH1 *h_nbcjet = new TH1I("nbcjet", "", 100, 0., 100.);

    TH1 *h_jetflav = new TH1I("jetflav", "", 10, 0., 100.);

    double xdiv[] = {0.0001, 0.001, 0.01, 0.1, 0.2, 0.5, 1., 2., 5., 10., 20., 50., 100.};
    double xdiv1[] = {-20., -15., -10., -7.5, -5, -4.5, -4, -3.5, -3, -2.5, -2, -1.5, -1, -0.8, -0.5, -0.2, -0.1, -0.01, 0, 0.01, 0.1, 0.2, 0.5, 0.8, 1., 1.5, 2., 2.5, 3, 3.5, 4, 4.5, 5., 7.5, 10., 15., 20.};
    const int ndiv = sizeof(xdiv) / sizeof(double) - 1;
    const int ndiv1 = sizeof(xdiv1) / sizeof(double) - 1;

    TH1 *h_ntrk_p_all = new TH1D("ntrk_p_all", "", 40, 0., 40.);
    TH1 *h_ntrk_p_tag = (TH1 *)h_ntrk_p_all->Clone("ntrk_p_tag");

    TH1 *h_ntrk_np_all = new TH1D("ntrk_np_all", "", 40, 0., 40.);
    TH1 *h_ntrk_np_tag = (TH1 *)h_ntrk_np_all->Clone("ntrk_np_tag");

    TH1 *h_ntrk_np_inc_all = new TH1D("ntrk_np_inc_all", "", 40, 0., 40.);
    TH1 *h_ntrk_np_inc_tag = (TH1 *)h_ntrk_np_inc_all->Clone("ntrk_np_inc_tag");
    ///////////////////////////////////////////////////////////////////////////////////////////
    TH1 *h_ntrk_pw_all = new TH1D("ntrk_pw_all", "", 40, 0., 40.);
    TH1 *h_ntrk_pw_tag = (TH1 *)h_ntrk_pw_all->Clone("ntrk_pw_tag");

    TH1 *h_ntrk_npw_all = new TH1D("ntrk_npw_all", "", 40, 0., 40.);
    TH1 *h_ntrk_npw_tag = (TH1 *)h_ntrk_npw_all->Clone("ntrk_npw_tag");

    TH1 *h_ntrk_npw_inc_all = new TH1D("ntrk_npw_inc_all", "", 40, 0., 40.);
    TH1 *h_ntrk_npw_inc_tag = (TH1 *)h_ntrk_npw_inc_all->Clone("ntrk_npw_inc_tag");
    ////////////////////////////////////////////////////////////////////////////////////////////
    TH1 *h_lxy_p_all = new TH1D("lxy_p_all", "", ndiv, xdiv);
    TH1 *h_lxy_np_all = new TH1D("lxy_np_all", "", ndiv, xdiv);
    TH1 *h_lxy_np_inc_all = new TH1D("lxy_np_inc_all", "", ndiv, xdiv);
    TH1 *h_lxy_p_tag = (TH1 *)h_lxy_p_all->Clone("lxy_p_tag");
    TH1 *h_lxy_np_tag = (TH1 *)h_lxy_np_all->Clone("lxy_np_tag");
    TH1 *h_lxy_np_inc_tag = (TH1 *)h_lxy_np_inc_all->Clone("lxy_np_inc_tag");

    // TH2 *h_bip_lxy_all = new TH2F("bip_lxy_all", "", ndiv1, xdiv1,ndiv,xdiv);
    // TH2 *h_bip_lxy_tag = (TH2F *)h_bip_lxy_all->Clone("bip_lxy_tag");

    const int njf = 3;

    double xpdiv[] = {20, 30, 40, 50, 60, 75, 90, 110, 140, 200, 250, 300};
    const int npdiv = sizeof(xpdiv) / sizeof(double) - 1;

    TH1 *h_jetpt_p_all = new TH1D("jetpt_p_all", "", npdiv, xpdiv);
    TH1 *h_jetpt_np_all = new TH1D("jetpt_np_all", "", npdiv, xpdiv);
    TH1 *h_jetpt_np_inc_all = new TH1D("jetpt_np_inc_all", "", npdiv, xpdiv);
    TH1 *h_jetpt_p_tag = (TH1 *)h_jetpt_p_all->Clone("jetpt_p_tag");
    TH1 *h_jetpt_np_tag = (TH1 *)h_jetpt_np_all->Clone("jetpt_np_tag");
    TH1 *h_jetpt_np_inc_tag = (TH1 *)h_jetpt_np_inc_all->Clone("jetpt_np_inc_tag");

    TFile *f_rew_in = new TFile("rw_lxy_new.root", "READ");
    TH1 *h_w_p = (TH1 *)f_rew_in->Get("lxy_rw_p");
    TH1 *h_w_np = (TH1 *)f_rew_in->Get("lxy_rw_np");
    TH1 *h_w_np_inc = (TH1 *)f_rew_in->Get("lxy_rw_np_inc");
    // f_rew_in->Close();

    Long64_t nentries = fChain->GetEntriesFast();

    for (Long64_t jentry = 0; jentry < nentries; jentry++)
    {
        Long64_t ientry = LoadTree(jentry);
        if (ientry < 0)
            break;
        if (jentry % 1000 == 0)
            cout << jentry << '\r';
        cout.flush();
        fChain->GetEntry(jentry);

        int njet = 0;
        if (jet_pt)
            njet = jet_pt->size();
        h_njet->Fill(njet);
        if (njet == 0)
            continue;

        for (int i = 0; i < nmmc; ++i)
        {
            if ((*mymc_pdgId)[i] == 1000022)
            {
                float dvR = sqrt(pow((*mymc_decayVtx_x)[i] - truth_PVx, 2) + pow((*mymc_decayVtx_y)[i] - truth_PVy, 2));
                for (int ix = (*mymc_ix1)[i]; ix < (*mymc_ix2)[i]; ++ix)
                {
                    double etaq = (*mymc1_eta)[ix];
                    double phiq = (*mymc1_phi)[ix];

                    for (int ijet = 0; ijet < njet; ++ijet)
                    {

                        double etaj = (*jet_eta)[ijet];
                        double phij = (*jet_phi)[ijet];

                        // jet selection
                        if ((*jet_pt)[ijet] < 20e3 || fabs((*jet_eta)[ijet]) > 2.5)
                            continue;
                        if ((*jet_pt)[ijet] < 60e3 && (*jet_JVT)[ijet] < 0.2)
                            continue;
                        if ((*jet_aliveAfterOR)[ijet] == 0)
                            continue;
                        if ((*jet_aliveAfterORmu)[ijet] == 0)
                            continue;

                        int jf = (*jet_LabDr_HadF)[ijet];
                        if (jf == 4)
                            jf = 1;
                        else if (jf == 5)
                            jf = 2;
                        else if (jf != 0)
                            continue;

                        int jfext = (*jet_DoubleHadLabel)[ijet];
                        cout << "The extended flavor labelling is:" << jfext << endl;

                        if (jfext == 55)
                            h_nbbjet->Fill(jfext);
                        else if (jfext == 54)
                            h_nbcjet->Fill(jfext);
                        h_jetflav->Fill(jfext);

                        int nb = (*jet_bH_Lxy)[ijet].size();
                        h_nbjet->Fill(nb);

                        if (jf != 2 || nb > 1)
                            continue; // only consider single B-hadron cases

                        int ntrk = 0;
                        if (jet_trk_d0)
                        {
                            int ntr = (*jet_trk_d0)[ijet].size();
                            for (int itr = 0; itr < ntr; ++itr)
                            {
                                double d0 = (*jet_trk_d0)[ijet][itr];
                                double z0 = (*jet_trk_z0)[ijet][itr];
                                z0 *= sin((*jet_trk_theta)[ijet][itr]);
                                if (fabs(d0) > 1. || fabs(z0) > 1.5)
                                    continue;
                                int nb = (*jet_trk_nBLHits)[ijet][itr];
                                int np = (*jet_trk_nPixHits)[ijet][itr];
                                int ns = (*jet_trk_nSCTHits)[ijet][itr];
                                if (nb < 1)
                                    continue;
                                if (np < 1)
                                    continue;
                                if (np + ns < 7)
                                    continue;
                                ++ntrk;
                            }
                        }

                        // jet tagging
                        const double frac_c = 0.030;
                        double a = (*jet_dl1r_pb)[ijet];
                        double b = frac_c * (*jet_dl1r_pc)[ijet] + (1 - frac_c) * (*jet_dl1r_pu)[ijet];
                        double w_dl1r = -99;
                        if (a > 0 && b > 0)
                        {
                            w_dl1r = log(a / b);
                        }
                        bool tagged = w_dl1r > 2.20; // FixedCutBEff_77
                        // bool tagged = w_dl1r>1.27; // FixedCutBEff_85

                        // b-hadron decay position
                        double jetlxy = (*jet_bH_Lxy)[ijet][0];
                        // b-hadron IP
                        double jetbip = (*jet_bH_Lxy)[ijet][0] * sin(atan2((*jet_bH_y)[ijet][0] - truth_PVy, (*jet_bH_x)[ijet][0] - truth_PVx) - (*jet_bH_phi)[ijet][0]);

                        TVector3 v_llp((*jet_truthLLP_Decay_x)[ijet] - truth_PVx, (*jet_truthLLP_Decay_y)[ijet] - truth_PVy, (*jet_truthLLP_Decay_z)[ijet] - truth_PVz);
                        TVector3 v_bh((*jet_bH_x)[ijet][0] - truth_PVx, (*jet_bH_y)[ijet][0] - truth_PVy, (*jet_bH_z)[ijet][0] - truth_PVz);
                        double dr = v_llp.DeltaR(v_bh);

                        double jetpt = (*jet_pt)[ijet] / 1e3;

                        if (fabs(jetbip) <= 1e-5)
                        {
                            int ibin = h_w_p->GetXaxis()->FindBin(jetlxy);
                            double scale = h_w_p->GetBinContent(ibin);

                            h_lxy_p_all->Fill(jetlxy);
                            h_jetpt_p_all->Fill(jetpt);
                            h_ntrk_p_all->Fill(ntrk);
                            h_ntrk_pw_all->Fill(ntrk, scale);
                            if (tagged)
                            {
                                h_jetpt_p_tag->Fill(jetpt);
                                h_lxy_p_tag->Fill(jetlxy);
                                h_ntrk_p_tag->Fill(ntrk);
                                h_ntrk_pw_tag->Fill(ntrk, scale);
                            }
                        }
                        else if (fabs(jetbip) > 1e-5 && fabs(jetbip) < 0.2 && dr < 0.1)
                        {
                            int ibin = h_w_np->GetXaxis()->FindBin(jetlxy);
                            double scale = h_w_np->GetBinContent(ibin);

                            h_lxy_np_all->Fill(jetlxy);
                            h_jetpt_np_all->Fill(jetpt);
                            h_ntrk_np_all->Fill(ntrk);
                            h_ntrk_npw_all->Fill(ntrk, scale);
                            if (tagged)
                            {
                                h_jetpt_np_tag->Fill(jetpt);
                                h_lxy_np_tag->Fill(jetlxy);
                                h_ntrk_np_tag->Fill(ntrk);
                                h_ntrk_npw_tag->Fill(ntrk, scale);
                            }
                        }
                        else if (fabs(jetbip) > 1e-5)
                        {
                            int ibin = h_w_np_inc->GetXaxis()->FindBin(jetlxy);
                            double scale = h_w_np_inc->GetBinContent(ibin);

                            h_lxy_np_inc_all->Fill(jetlxy);
                            h_jetpt_np_inc_all->Fill(jetpt);
                            h_ntrk_np_inc_all->Fill(ntrk);
                            h_ntrk_npw_inc_all->Fill(ntrk, scale);
                            if (tagged)
                            {
                                h_jetpt_np_inc_tag->Fill(jetpt);
                                h_lxy_np_inc_tag->Fill(jetlxy);
                                h_ntrk_np_inc_tag->Fill(ntrk);
                                h_ntrk_npw_inc_tag->Fill(ntrk, scale);
                            }
                        }
                    }
                }
            }
        }
    }
}
