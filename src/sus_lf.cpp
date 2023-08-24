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
   TH1 *h_nljet = new TH1I("nljet", "", 10, 0., 10.);
   TH1 *h_jetflav = new TH1I("jetflav", "", 10, 0., 100.);

   double xdiv[] = {0.0001, 0.001, 0.01, 0.1, 0.2, 0.5, 1., 2., 5., 10., 20., 50., 100.};
   double xdiv1[] = {-20., -15., -10., -7.5, -5, -4.5, -4, -3.5, -3, -2.5, -2, -1.5, -1, -0.8, -0.5, -0.2, -0.1, -0.01, 0, 0.01, 0.1, 0.2, 0.5, 0.8, 1., 1.5, 2., 2.5, 3, 3.5, 4, 4.5, 5., 7.5, 10., 15., 20.};
   const int ndiv = sizeof(xdiv) / sizeof(double) - 1;
   const int ndiv1 = sizeof(xdiv1) / sizeof(double) - 1;

   TH1 *h_ip3d_ntrk_all = new TH1D("ntrk_all", "", 40, 0., 40.);
   TH1 *h_ip3d_ntrk_tag = (TH1 *)h_ip3d_ntrk_all->Clone("ntrk_tag");
   TH1 *h_ip3d_ntrk_tag_ip3d = (TH1 *)h_ip3d_ntrk_all->Clone("ntrk_tag_ip3d");
   TH1 *h_ip3d_ntrk_tag_sv1 = (TH1 *)h_ip3d_ntrk_all->Clone("ntrk_tag_sv1");
   TH1 *h_ip3d_ntrk_tag_jf = (TH1 *)h_ip3d_ntrk_all->Clone("ntrk_tag_jf");

   const int njf = 3;

   double xpdiv[] = {20, 30, 40, 50, 60, 75, 90, 110, 140, 200, 300};
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

                  int ntrk = (*jet_ip3d_ntrk)[ijet];

                  int jf = (*jet_LabDr_HadF)[ijet];
                  if (jf == 4)
                     jf = 1;
                  else if (jf == 5)
                     jf = 2;
                  else if (jf != 0)
                     continue;

                  int jfext = (*jet_DoubleHadLabel)[ijet];
                  cout << "The extended flavor labelling is:" << jfext << endl;
                  h_jetflav->Fill(jfext);

                  int llpjf;
                  if (jet_truthLLPJetLabel)
                  {
                     llpjf = (*jet_truthLLPJetLabel)[ijet];
                     if (llpjf == 4)
                        llpjf = 1;
                     else if (llpjf == 5)
                        llpjf = 2;
                     else if (llpjf == 0)
                        llpjf = 0;
                  }

                  if (llpjf != 0)
                     continue; // only consider single B-hadron cases

                  // jet tagging
                  const double frac_c = 0.030;
                  double a = (*jet_dl1r_pb)[ijet];
                  double b = frac_c * (*jet_dl1r_pc)[ijet] + (1 - frac_c) * (*jet_dl1r_pu)[ijet];
                  double w_dl1r = -99;

                  if (a > 0 && b > 0)
                  {
                     w_dl1r = log(a / b);
                  }
                  bool tagged_dl1r = w_dl1r > 2.20; // FixedCutBEff_77
                  bool tagged_ip3d = (*jet_ip3d_llr)[ijet] > 4.;
                  bool tagged_sv1 = (*sv1_llr)[ijet] > 4.; // eff_b~0.77
                  bool tagged_jf = (*jet_jf_llr)[ijet] > -4.5;
                  // bool tagged = w_dl1r>1.27; // FixedCutBEff_85

                  h_ip3d_ntrk_all->Fill(ntrk);
                  if (tagged_dl1r)
                  {
                     h_ip3d_ntrk_tag->Fill(ntrk);
                  }
                  if (tagged_ip3d)
                  {
                     h_ip3d_ntrk_tag_ip3d->Fill(ntrk);
                  }
                  if (tagged_sv1)
                  {
                     h_ip3d_ntrk_tag_sv1->Fill(ntrk);
                  }
                  if (tagged_jf)
                  {
                     h_ip3d_ntrk_tag_jf->Fill(ntrk);
                  }
               }
            }
         }
      }
   }
}
