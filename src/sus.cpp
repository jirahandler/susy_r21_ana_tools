#define sus_cxx
#include "sus.h"

#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

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
   TH1 *h_jet_ntrk = new TH1I("ntrk", "", 25, 0., 25.);
   TH1 *h_jetflav = new TH1I("jetflav", "", 10, 0., 100.);
   TH1 *h_nbjet = new TH1I("nbjet", "", 10, 0., 10.);
   TH1 *h_nbbjet = new TH1I("nbbjet", "", 100, 0., 100.);
   TH1 *h_nbcjet = new TH1I("nbcjet", "", 100, 0., 100.);

   double xdiv[] = {0.1, 0.2, 0.5, 1., 2., 5., 10., 20., 50., 100.};
   // double xdiv1[] = {0.1, 0.2, 0.5,0.8, 1.,1.5, 2.,2.5,3,3.5,4,4.5, 5.};
   const int ndiv = sizeof(xdiv) / sizeof(double) - 1;
   // const int ndiv1 = sizeof(xdiv1) / sizeof(double) - 1;

   TH1 *h_lxy_all = new TH1D("lxy_all", "", ndiv, xdiv);
   TH1 *h_lxy_tag = (TH1 *)h_lxy_all->Clone("lxy_tag");

   TH1 *h_bip_all = new TH1D("bip_all", "", ndiv, xdiv);
   TH1 *h_bip_tag = (TH1 *)h_bip_all->Clone("bip_tag");

   TH1 *h_lxy_llp_all = new TH1D("lxy_llp_all", "", ndiv, xdiv);
   TH1 *h_lxy_llp_tag = (TH1 *)h_lxy_llp_all->Clone("lxy_llp_tag");

   const int njf = 3;

   double xpdiv[] = {20, 30, 40, 50, 60, 75, 90, 110, 140, 200, 300};
   const int npdiv = sizeof(xpdiv) / sizeof(double) - 1;

   TH1 *h_jetpt_all[njf];
   TH1 *h_jetpt_tag[njf];

   TH1 *h_jetpt_llp_all[njf];
   TH1 *h_jetpt_llp_tag[njf];

   TH1 *h_dvR_llp_all[njf];
   TH1 *h_dvR_llp_tag[njf];

   for (int jf = 0; jf < njf; ++jf)
   {
      h_jetpt_all[jf] = new TH1D(TString("jetpt_") + jf + "_all", "", npdiv, xpdiv);
      h_jetpt_tag[jf] = (TH1 *)h_jetpt_all[jf]->Clone(TString("jetpt_") + jf + "_tag");

      h_jetpt_llp_all[jf] = new TH1D(TString("jetpt_") + jf + "_llp_all", "", npdiv, xpdiv);
      h_jetpt_llp_tag[jf] = (TH1 *)h_jetpt_all[jf]->Clone(TString("jetpt_") + jf + "_llp_tag");

      h_dvR_llp_all[jf] = new TH1D(TString("dvR_") + jf + "_llp_all", "", ndiv, xdiv);
      h_dvR_llp_tag[jf] = (TH1 *)h_dvR_llp_all[jf]->Clone(TString("dvR_") + jf + "_llp_tag");
   }

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
                  
                  int ntrk = (*jet_trk_ntrk)[ijet];
                  h_jet_ntrk->Fill(ntrk);

                  // if (delR(etaq,etaj,phiq,phij) > 0.3)
                  //{
                  //  jet flavor
                  int jf = (*jet_LabDr_HadF)[ijet];
                  if (jf == 4)
                     jf = 1;
                  else if (jf == 5)
                     jf = 2;
                  else if (jf != 0)
                     continue;

                  int jfext = (*jet_DoubleHadLabel)[ijet];
                  cout << "The extended flavor labelling is:" << jfext << endl;
                  if (jfext == 5)
                     h_nbjet->Fill(jfext);
                  else if (jfext == 55)
                     h_nbbjet->Fill(jfext);
                  else if (jfext == 54)
                     h_nbcjet->Fill(jfext);
                  h_jetflav->Fill(jfext);

                  int llpjf;

                  // llp jet flavor, if jets are from llp
                  // jet flavor would be -ve if jets are not from llp

                  if (jet_truthLLPJetLabel)
                  {
                     int llpjf = (*jet_truthLLPJetLabel)[ijet];
                     if (llpjf == 4)
                        llpjf = 1;
                     else if (llpjf == 5)
                        llpjf = 2;
                     else if (llpjf != 0)
                        continue;
                  }

                  // jet tagging
                  const double frac_c = 0.030;
                  double a = (*jet_dl1r_pb)[ijet];
                  double b = frac_c * (*jet_dl1r_pc)[ijet] + (1 - frac_c) * (*jet_dl1r_pu)[ijet];
                  double w_dl1r = -99;
                  if (a > 0 && b > 0)
                     w_dl1r = log(a / b);
                  bool tagged = w_dl1r > 2.20; // FixedCutBEff_77
                  // bool tagged = w_dl1r>1.27; // FixedCutBEff_85

                  // Lxy for all b-jets
                  if (jf == 2 && jet_bH_Lxy && !(*jet_bH_Lxy)[ijet].empty())
                  {
                     float lxy = (*jet_bH_Lxy)[ijet][0];
                     h_lxy_all->Fill(lxy);
                     if (tagged)
                        h_lxy_tag->Fill(lxy);
                  }

                  // pT plots
                  double jetpt = (*jet_pt)[ijet] / 1e3;
                  h_jetpt_all[jf]->Fill(jetpt);
                  if (tagged)
                  {
                     h_jetpt_tag[jf]->Fill(jetpt);
                  }

                  if (llpjf == 0 || llpjf == 1 || llpjf == 2)
                  {
                     // LLP Lxy for b-jets frrom Neutralino decay
                     if (llpjf == 2 && jet_bH_Lxy && !(*jet_bH_Lxy)[ijet].empty())
                     {
                        float lxy = (*jet_bH_Lxy)[ijet][0];
                        h_lxy_llp_all->Fill(lxy);
                        if (tagged)
                           h_lxy_llp_tag->Fill(lxy);
                     }
                  }

                  // This has to do with bip; without this we can't get the angle between b Hadron and the LLP
                  if ((llpjf == 2 || jf == 2) && jet_bH_Lxy && !(*jet_bH_Lxy)[ijet].empty() && !(*jet_bH_x)[ijet].empty() && !(*jet_bH_y)[ijet].empty())
                  {
                     float bip = (*jet_bH_Lxy)[ijet][0] * sin(atan2((*jet_bH_y)[ijet][0] - truth_PVy, (*jet_bH_x)[ijet][0] - truth_PVx) - (*jet_bH_phi)[ijet][0]);
                     h_bip_all->Fill(bip);
                     if (tagged)
                     {
                        h_bip_tag->Fill(bip);
                     }
                  }
                  /**
                  // Neutralino (parent) decay vertex for all child jets
                  if ((!(*jet_truthLLP_Decay_x).empty()) && (!(*jet_truthLLP_Decay_y).empty()) && (!(*jet_truthLLP_Decay_z).empty()))
                  {

                    float v1 = (truth_PVx - (*jet_truthLLP_Decay_x)[ijet]);
                    float v2 = (truth_PVy - (*jet_truthLLP_Decay_y)[ijet]);
                    float v3 = (truth_PVz - (*jet_truthLLP_Decay_z)[ijet]);
                    // cout << "Truth PV coordinates are: " << truth_PVx << "," << truth_PVy << "," << truth_PVz << endl;
                    // cout << "Decay Vtx coordinates are: " << (*jet_truthLLP_Decay_x)[ijet] << "," << (*jet_truthLLP_Decay_x)[ijet] << "," << (*jet_truthLLP_Decay_x)[ijet] << endl;
                    TVector3 v;
                    v.SetXYZ(v1, v2, v3);
                    double dvR = v.Mag();
                  }
                  */
                  if (llpjf == 0 || llpjf == 1 || llpjf == 2)
                  {
                     h_dvR_llp_all[llpjf]->Fill(dvR);
                     if (tagged)
                     {
                        h_dvR_llp_tag[llpjf]->Fill(dvR);
                     }

                     // LLP pT plots
                     double jetpt = (*jet_pt)[ijet] / 1e3;
                     h_jetpt_llp_all[llpjf]->Fill(jetpt);
                     if (tagged)
                     {
                        h_jetpt_llp_tag[llpjf]->Fill(jetpt);
                     }
                  }
               }
            }
         }
      }
   }
}
