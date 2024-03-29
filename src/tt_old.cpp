#define tt_cxx
#include "tt.h"

#include <iostream>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void tt::Loop()
{
   if (fChain == 0)
      return;

   // book histograms
   TH1 *h_njet = new TH1I("njet", "", 10, 0., 10.);
   TH1 *h_jet_ntrk = new TH1I("ntrk", "", 40, 0., 40.);
   TH1 *h_bjet_ntrk = new TH1I("bjet_ntrk", "", 40, 0., 40.);
   TH1 *h_jetflav = new TH1I("jetflav", "", 10, 0., 100.);
   TH1 *h_nbjet = new TH1I("nbjet", "", 10, 0., 10.);
   TH1 *h_nbbjet = new TH1I("nbbjet", "", 100, 0., 100.);
   TH1 *h_nbcjet = new TH1I("nbcjet", "", 100, 0., 100.);

   double xdiv[] = {0.0001,0.001,0.01,0.1, 0.2, 0.5, 1., 2., 5., 10., 20., 50., 100.};
   double xdiv1[] = {-5, -4.5, -4, -3.5, -3, -2.5, -2, -1.5, -1, -0.8, -0.5, -0.2, -0.1, 0, 0.1, 0.2, 0.5, 0.8, 1., 1.5, 2., 2.5, 3, 3.5, 4, 4.5, 5.};
   const int ndiv = sizeof(xdiv) / sizeof(double) - 1;
   const int ndiv1 = sizeof(xdiv1) / sizeof(double) - 1;

   TH1 *h_ip3d_ntrk_all = new TH1D("ntrk_all", "", 40, 0., 40.);
   TH1 *h_ip3d_ntrk_tag = (TH1 *)h_ip3d_ntrk_all->Clone("ntrk_tag");

   TH1 *h_ntrk_jf_all = new TH1D("ntrk_jf_all", "", 40, 0., 40.);
   TH1 *h_ntrk_jf_tag = (TH1 *)h_ip3d_ntrk_all->Clone("ntrk_jf_tag");

   TH1 *h_lxy_all = new TH1D("lxy_all", "", ndiv, xdiv);
   TH1 *h_lxy_tag = (TH1 *)h_lxy_all->Clone("lxy_tag");

   TH1 *h_lxy_wc_all = new TH1D("lxy_wc_all", "", ndiv, xdiv);
   TH1 *h_lxy_wc_tag = (TH1 *)h_lxy_all->Clone("lxy_wc_tag");

   TH1 *h_cxy_all = new TH1D("cxy_all", "", ndiv, xdiv);
   TH1 *h_cxy_tag = (TH1 *)h_cxy_all->Clone("cxy_tag");

   TH1 *h_bip_all = new TH1D("bip_all", "", ndiv1, xdiv1);
   TH1 *h_bip_tag = (TH1 *)h_bip_all->Clone("bip_tag");

   TH2 *h_bip_lxy_all = new TH2F("bip_lxy_all", "", ndiv1, xdiv1, ndiv, xdiv);
   TH2 *h_bip_lxy_tag = (TH2F *)h_bip_lxy_all->Clone("bip_lxy_tag");

   const int njf = 3;

   double xpdiv[] = {20, 30, 40, 50, 60, 75, 90, 110, 140, 200, 250, 300};
   const int npdiv = sizeof(xpdiv) / sizeof(double) - 1;

   TH1 *h_jetpt_all[njf];
   TH1 *h_jetpt_tag[njf];

   for (int jf = 0; jf < njf; ++jf)
   {
      h_jetpt_all[jf] = new TH1D(TString("jetpt_") + jf + "_all", "", npdiv, xpdiv);
      h_jetpt_tag[jf] = (TH1 *)h_jetpt_all[jf]->Clone(TString("jetpt_") + jf + "_tag");
   }

   Long64_t nentries = fChain->GetEntriesFast();

   for (Long64_t jentry = 0; jentry < nentries; jentry++)
   {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0)
         break;
      if (jentry % 1000 == 0)
         std::cout << jentry << '\r';
      std::cout.flush();
      fChain->GetEntry(jentry);

      int njet = 0;
      if (jet_pt)
         njet = jet_pt->size();
      h_njet->Fill(njet);
      if (njet == 0)
         continue;

      for (int ijet = 0; ijet < njet; ++ijet)
      {
         // jet selection
         if ((*jet_pt)[ijet] < 20e3 || fabs((*jet_eta)[ijet]) > 2.5)
            continue;
         if ((*jet_pt)[ijet] < 60e3 && (*jet_JVT)[ijet] < 0.2)
            continue;
         if ((*jet_aliveAfterOR)[ijet] == 0)
            continue;
         if ((*jet_aliveAfterORmu)[ijet] == 0)
            continue;

         int ntrk = (*jet_ip3d_ntrk)[ijet];

         //  jet flavor
         int jf = (*jet_LabDr_HadF)[ijet];
         if (jf == 4)
            jf = 1;
         else if (jf == 5)
            jf = 2;
         else if (jf != 0)
            continue;
         if (jf == 2)
         {
            h_bjet_ntrk->Fill(ntrk);
         }
         int jfext = (*jet_DoubleHadLabel)[ijet];
         std::cout << "The extended flavor labelling is:" << jfext << std::endl;
         if (jfext == 5)
            h_nbjet->Fill(jfext);
         else if (jfext == 55)
            h_nbbjet->Fill(jfext);
         else if (jfext == 54)
            h_nbcjet->Fill(jfext);
         h_jetflav->Fill(jfext);

         int nbjet = (*jet_bH_Lxy)[ijet].size();
         if (nbjet > 1)
            continue; // only consider single B-hadron cases

         // jet tagging
         const double frac_c = 0.030;
         double a = (*jet_dl1r_pb)[ijet];
         double b = frac_c * (*jet_dl1r_pc)[ijet] + (1 - frac_c) * (*jet_dl1r_pu)[ijet];
         double w_dl1r = -99;

         if (a > 0 && b > 0)
            w_dl1r = log(a / b);
         bool tagged = w_dl1r > 2.20; // FixedCutBEff_77
         // bool tagged = w_dl1r>1.27; // FixedCutBEff_85
         bool tagged_jf = (*jet_jf_llr)[ijet] > 0;

         // Lxy for all b-jets
         if (jf == 2 && jet_bH_Lxy && !(*jet_bH_Lxy)[ijet].empty())
         {
            int nbjet = (*jet_bH_Lxy)[ijet].size();
            if (nbjet > 1)
               continue;

            float lxy = (*jet_bH_Lxy)[ijet][0];
            h_lxy_all->Fill(lxy);
            h_ip3d_ntrk_all->Fill(ntrk);
            h_ntrk_jf_all->Fill(ntrk);

            if (tagged){
               h_lxy_tag->Fill(lxy);
               h_ip3d_ntrk_tag->Fill(ntrk);
            }
            if (tagged_jf){
               h_ntrk_jf_tag->Fill(ntrk);
            }

         }
         // Lxy for all c-jets
         if (jf == 1 && jet_cH_Lxy && !(*jet_cH_Lxy)[ijet].empty())
         {
            float cxy = (*jet_cH_Lxy)[ijet][0];
            h_cxy_all->Fill(cxy);
            if (tagged)
               h_cxy_tag->Fill(cxy);
         }
         // Lxy for all b-jets minus bc jets
         if ((jfext == 5) && jet_bH_Lxy && !(*jet_bH_Lxy)[ijet].empty())
         {  cout<<"Entered forbidden cheese."<<endl;
            float lxy = (*jet_bH_Lxy)[ijet][0];
            h_lxy_wc_all->Fill(lxy);
            if (tagged)
               h_lxy_wc_tag->Fill(lxy);
         }

         if ((jf == 2) && jet_bH_Lxy && !(*jet_bH_Lxy)[ijet].empty() && !(*jet_bH_x)[ijet].empty() && !(*jet_bH_y)[ijet].empty())
         {
            float bip = (*jet_bH_Lxy)[ijet][0] * sin(atan2((*jet_bH_y)[ijet][0] - truth_PVy, (*jet_bH_x)[ijet][0] - truth_PVx) - (*jet_bH_phi)[ijet][0]);
            float lxy = (*jet_bH_Lxy)[ijet][0];
            h_bip_lxy_all->Fill(bip, lxy);
            if (tagged)
            {
               h_bip_lxy_tag->Fill(bip, lxy);
            }
         }

         // pT plots
         double jetpt = (*jet_pt)[ijet] / 1e3;
         h_jetpt_all[jf]->Fill(jetpt);
         if (tagged)
         {
            h_jetpt_tag[jf]->Fill(jetpt);
         }

         // This has to do with bip; without this we can't get the angle between b Hadron and the LLP
         if ((jf == 2) && jet_bH_Lxy && !(*jet_bH_Lxy)[ijet].empty() && !(*jet_bH_x)[ijet].empty() && !(*jet_bH_y)[ijet].empty())
         {
            float bip = (*jet_bH_Lxy)[ijet][0] * sin(atan2((*jet_bH_y)[ijet][0] - truth_PVy, (*jet_bH_x)[ijet][0] - truth_PVx) - (*jet_bH_phi)[ijet][0]);
            h_bip_all->Fill(bip);
            if (tagged)
            {
               h_bip_tag->Fill(bip);
            }
         }
      }
   }
}
