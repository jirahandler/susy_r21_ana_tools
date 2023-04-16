/**
 * @brief header file to d.cpp
 * 
 */
//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Apr 11 00:13:29 2023 by ROOT version 6.29/01
// from TTree bTag_AntiKt4EMPFlowJets_BTagging201810/bTagAntiKt4EMPFlowJets_BTagging201810
// found on file: 503767.root
//////////////////////////////////////////////////////////

#ifndef d_h
#define d_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <vector>

// Header file for the classes stored in the TTree if any.
#include "vector"

class d {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           runnb;
   Int_t           eventnb;
   Int_t           mcchan;
   Float_t         mcwg;
   Float_t         avgmu;
   Int_t           actmu;
   Float_t         PVx;
   Float_t         PVy;
   Float_t         PVz;
   Float_t         truth_PVx;
   Float_t         truth_PVy;
   Float_t         truth_PVz;
   Int_t           njets;
   std::vector<float>   *jet_pt;
   std::vector<float>   *jet_eta;
   std::vector<float>   *jet_phi;
   std::vector<float>   *jet_E;
   std::vector<float>   *jet_pt_orig;
   std::vector<float>   *jet_eta_orig;
   std::vector<float>   *jet_phi_orig;
   std::vector<float>   *jet_E_orig;
   std::vector<int>     *jet_LabDr_HadF;
   std::vector<int>     *jet_DoubleHadLabel;
   std::vector<float>   *jet_JVT;
   std::vector<float>   *jet_m;
   std::vector<float>   *jet_nConst;
   std::vector<float>   *jet_dRiso;
   std::vector<int>     *jet_truthMatch;
   std::vector<int>     *jet_isPU;
   std::vector<int>     *jet_aliveAfterOR;
   std::vector<int>     *jet_aliveAfterORmu;
   std::vector<int>     *jet_isBadMedium;
   std::vector<float>   *jet_truthPt;
   std::vector<float>   *jet_dRminToB;
   std::vector<float>   *jet_dRminToC;
   std::vector<float>   *jet_dRminToT;
   std::vector<int>     *jet_isLLPDecayProd;
   std::vector<float>   *jet_dRtoLLPDecayProd;
   std::vector<int>     *jet_truthLLPJetLabel;
   std::vector<float>   *jet_truthLLP_Decay_x;
   std::vector<float>   *jet_truthLLP_Decay_y;
   std::vector<float>   *jet_truthLLP_Decay_z;
   std::vector<double>  *jet_dl1_pb;
   std::vector<double>  *jet_dl1_pc;
   std::vector<double>  *jet_dl1_pu;
   std::vector<double>  *jet_dl1rmu_pb;
   std::vector<double>  *jet_dl1rmu_pc;
   std::vector<double>  *jet_dl1rmu_pu;
   std::vector<double>  *jet_dl1r_pb;
   std::vector<double>  *jet_dl1r_pc;
   std::vector<double>  *jet_dl1r_pu;
   std::vector<double>  *jet_mv2c10;
   std::vector<double>  *jet_mv2c10mu;
   std::vector<double>  *jet_mv2c10rnn;
   std::vector<double>  *jet_mv2c100;
   std::vector<double>  *jet_mv2cl100;
   std::vector<int>     *jet_nBHadr;
   std::vector<int>     *jet_nCHadr;
   std::vector<std::vector<int> > *jet_bH_pdgId;
   std::vector<std::vector<int> > *jet_bH_parent_pdgId;
   std::vector<std::vector<float> > *jet_bH_pt;
   std::vector<std::vector<float> > *jet_bH_eta;
   std::vector<std::vector<float> > *jet_bH_phi;
   std::vector<std::vector<float> > *jet_bH_E;
   std::vector<std::vector<float> > *jet_bH_charge;
   std::vector<std::vector<float> > *jet_bH_Lxy;
   std::vector<std::vector<float> > *jet_bH_x;
   std::vector<std::vector<float> > *jet_bH_y;
   std::vector<std::vector<float> > *jet_bH_z;
   std::vector<std::vector<float> > *jet_bH_dRjet;
   std::vector<std::vector<int> > *jet_cH_pdgId;
   std::vector<std::vector<int> > *jet_cH_parent_pdgId;
   std::vector<std::vector<float> > *jet_cH_pt;
   std::vector<std::vector<float> > *jet_cH_eta;
   std::vector<std::vector<float> > *jet_cH_phi;
   std::vector<std::vector<float> > *jet_cH_E;
   std::vector<std::vector<float> > *jet_cH_charge;
   std::vector<std::vector<float> > *jet_cH_Lxy;
   std::vector<std::vector<float> > *jet_cH_x;
   std::vector<std::vector<float> > *jet_cH_y;
   std::vector<std::vector<float> > *jet_cH_z;
   std::vector<std::vector<float> > *jet_cH_dRjet;
   Int_t           nmmc;
   std::vector<float>   *mymc_pt;
   std::vector<float>   *mymc_eta;
   std::vector<float>   *mymc_phi;
   std::vector<int>     *mymc_pdgId;
   std::vector<float>   *mymc_decayVtx_x;
   std::vector<float>   *mymc_decayVtx_y;
   std::vector<float>   *mymc_decayVtx_z;
   std::vector<int>     *mymc_ix1;
   std::vector<int>     *mymc_ix2;
   Int_t           nmmc1;
   std::vector<float>   *mymc1_pt;
   std::vector<float>   *mymc1_eta;
   std::vector<float>   *mymc1_phi;
   std::vector<int>     *mymc1_pdgId;

   // List of branches
   TBranch        *b_runnb;   //!
   TBranch        *b_eventnb;   //!
   TBranch        *b_mcchan;   //!
   TBranch        *b_mcwg;   //!
   TBranch        *b_avgmu;   //!
   TBranch        *b_actmu;   //!
   TBranch        *b_PVx;   //!
   TBranch        *b_PVy;   //!
   TBranch        *b_PVz;   //!
   TBranch        *b_truth_PVx;   //!
   TBranch        *b_truth_PVy;   //!
   TBranch        *b_truth_PVz;   //!
   TBranch        *b_njets;   //!
   TBranch        *b_jet_pt;   //!
   TBranch        *b_jet_eta;   //!
   TBranch        *b_jet_phi;   //!
   TBranch        *b_jet_E;   //!
   TBranch        *b_jet_pt_orig;   //!
   TBranch        *b_jet_eta_orig;   //!
   TBranch        *b_jet_phi_orig;   //!
   TBranch        *b_jet_E_orig;   //!
   TBranch        *b_jet_LabDr_HadF;   //!
   TBranch        *b_jet_DoubleHadLabel;   //!
   TBranch        *b_jet_JVT;   //!
   TBranch        *b_jet_m;   //!
   TBranch        *b_jet_nConst;   //!
   TBranch        *b_jet_dRiso;   //!
   TBranch        *b_jet_truthMatch;   //!
   TBranch        *b_jet_isPU;   //!
   TBranch        *b_jet_aliveAfterOR;   //!
   TBranch        *b_jet_aliveAfterORmu;   //!
   TBranch        *b_jet_isBadMedium;   //!
   TBranch        *b_jet_truthPt;   //!
   TBranch        *b_jet_dRminToB;   //!
   TBranch        *b_jet_dRminToC;   //!
   TBranch        *b_jet_dRminToT;   //!
   TBranch        *b_jet_isLLPDecayProd;   //!
   TBranch        *b_jet_dRtoLLPDecayProd;   //!
   TBranch        *b_jet_truthLLPJetLabel;   //!
   TBranch        *b_jet_truthLLP_Decay_x;   //!
   TBranch        *b_jet_truthLLP_Decay_y;   //!
   TBranch        *b_jet_truthLLP_Decay_z;   //!
   TBranch        *b_jet_dl1_pb;   //!
   TBranch        *b_jet_dl1_pc;   //!
   TBranch        *b_jet_dl1_pu;   //!
   TBranch        *b_jet_dl1rmu_pb;   //!
   TBranch        *b_jet_dl1rmu_pc;   //!
   TBranch        *b_jet_dl1rmu_pu;   //!
   TBranch        *b_jet_dl1r_pb;   //!
   TBranch        *b_jet_dl1r_pc;   //!
   TBranch        *b_jet_dl1r_pu;   //!
   TBranch        *b_jet_mv2c10;   //!
   TBranch        *b_jet_mv2c10mu;   //!
   TBranch        *b_jet_mv2c10rnn;   //!
   TBranch        *b_jet_mv2c100;   //!
   TBranch        *b_jet_mv2cl100;   //!
   TBranch        *b_jet_nBHadr;   //!
   TBranch        *b_jet_nCHadr;   //!
   TBranch        *b_jet_bH_pdgId;   //!
   TBranch        *b_jet_bH_parent_pdgId;   //!
   TBranch        *b_jet_bH_pt;   //!
   TBranch        *b_jet_bH_eta;   //!
   TBranch        *b_jet_bH_phi;   //!
   TBranch        *b_jet_bH_E;   //!
   TBranch        *b_jet_bH_charge;   //!
   TBranch        *b_jet_bH_Lxy;   //!
   TBranch        *b_jet_bH_x;   //!
   TBranch        *b_jet_bH_y;   //!
   TBranch        *b_jet_bH_z;   //!
   TBranch        *b_jet_bH_dRjet;   //!
   TBranch        *b_jet_cH_pdgId;   //!
   TBranch        *b_jet_cH_parent_pdgId;   //!
   TBranch        *b_jet_cH_pt;   //!
   TBranch        *b_jet_cH_eta;   //!
   TBranch        *b_jet_cH_phi;   //!
   TBranch        *b_jet_cH_E;   //!
   TBranch        *b_jet_cH_charge;   //!
   TBranch        *b_jet_cH_Lxy;   //!
   TBranch        *b_jet_cH_x;   //!
   TBranch        *b_jet_cH_y;   //!
   TBranch        *b_jet_cH_z;   //!
   TBranch        *b_jet_cH_dRjet;   //!
   TBranch        *b_nmmc;   //!
   TBranch        *b_mymc_pt;   //!
   TBranch        *b_mymc_eta;   //!
   TBranch        *b_mymc_phi;   //!
   TBranch        *b_mymc_pdgId;   //!
   TBranch        *b_mymc_decayVtx_x;   //!
   TBranch        *b_mymc_decayVtx_y;   //!
   TBranch        *b_mymc_decayVtx_z;   //!
   TBranch        *b_mymc_ix1;   //!
   TBranch        *b_mymc_ix2;   //!
   TBranch        *b_nmmc1;   //!
   TBranch        *b_mymc1_pt;   //!
   TBranch        *b_mymc1_eta;   //!
   TBranch        *b_mymc1_phi;   //!
   TBranch        *b_mymc1_pdgId;   //!

   d(TTree *tree=0);
   virtual ~d();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef d_cxx
d::d(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("503767.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("503767.root");
      }
      f->GetObject("bTag_AntiKt4EMPFlowJets_BTagging201810",tree);

   }
   Init(tree);
}

d::~d()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t d::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t d::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void d::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   jet_pt = 0;
   jet_eta = 0;
   jet_phi = 0;
   jet_E = 0;
   jet_pt_orig = 0;
   jet_eta_orig = 0;
   jet_phi_orig = 0;
   jet_E_orig = 0;
   jet_LabDr_HadF = 0;
   jet_DoubleHadLabel = 0;
   jet_JVT = 0;
   jet_m = 0;
   jet_nConst = 0;
   jet_dRiso = 0;
   jet_truthMatch = 0;
   jet_isPU = 0;
   jet_aliveAfterOR = 0;
   jet_aliveAfterORmu = 0;
   jet_isBadMedium = 0;
   jet_truthPt = 0;
   jet_dRminToB = 0;
   jet_dRminToC = 0;
   jet_dRminToT = 0;
   jet_isLLPDecayProd = 0;
   jet_dRtoLLPDecayProd = 0;
   jet_truthLLPJetLabel = 0;
   jet_truthLLP_Decay_x = 0;
   jet_truthLLP_Decay_y = 0;
   jet_truthLLP_Decay_z = 0;
   jet_dl1_pb = 0;
   jet_dl1_pc = 0;
   jet_dl1_pu = 0;
   jet_dl1rmu_pb = 0;
   jet_dl1rmu_pc = 0;
   jet_dl1rmu_pu = 0;
   jet_dl1r_pb = 0;
   jet_dl1r_pc = 0;
   jet_dl1r_pu = 0;
   jet_mv2c10 = 0;
   jet_mv2c10mu = 0;
   jet_mv2c10rnn = 0;
   jet_mv2c100 = 0;
   jet_mv2cl100 = 0;
   jet_nBHadr = 0;
   jet_nCHadr = 0;
   jet_bH_pdgId = 0;
   jet_bH_parent_pdgId = 0;
   jet_bH_pt = 0;
   jet_bH_eta = 0;
   jet_bH_phi = 0;
   jet_bH_E = 0;
   jet_bH_charge = 0;
   jet_bH_Lxy = 0;
   jet_bH_x = 0;
   jet_bH_y = 0;
   jet_bH_z = 0;
   jet_bH_dRjet = 0;
   jet_cH_pdgId = 0;
   jet_cH_parent_pdgId = 0;
   jet_cH_pt = 0;
   jet_cH_eta = 0;
   jet_cH_phi = 0;
   jet_cH_E = 0;
   jet_cH_charge = 0;
   jet_cH_Lxy = 0;
   jet_cH_x = 0;
   jet_cH_y = 0;
   jet_cH_z = 0;
   jet_cH_dRjet = 0;
   mymc_pt = 0;
   mymc_eta = 0;
   mymc_phi = 0;
   mymc_pdgId = 0;
   mymc_decayVtx_x = 0;
   mymc_decayVtx_y = 0;
   mymc_decayVtx_z = 0;
   mymc_ix1 = 0;
   mymc_ix2 = 0;
   mymc1_pt = 0;
   mymc1_eta = 0;
   mymc1_phi = 0;
   mymc1_pdgId = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("runnb", &runnb, &b_runnb);
   fChain->SetBranchAddress("eventnb", &eventnb, &b_eventnb);
   fChain->SetBranchAddress("mcchan", &mcchan, &b_mcchan);
   fChain->SetBranchAddress("mcwg", &mcwg, &b_mcwg);
   fChain->SetBranchAddress("avgmu", &avgmu, &b_avgmu);
   fChain->SetBranchAddress("actmu", &actmu, &b_actmu);
   fChain->SetBranchAddress("PVx", &PVx, &b_PVx);
   fChain->SetBranchAddress("PVy", &PVy, &b_PVy);
   fChain->SetBranchAddress("PVz", &PVz, &b_PVz);
   fChain->SetBranchAddress("truth_PVx", &truth_PVx, &b_truth_PVx);
   fChain->SetBranchAddress("truth_PVy", &truth_PVy, &b_truth_PVy);
   fChain->SetBranchAddress("truth_PVz", &truth_PVz, &b_truth_PVz);
   fChain->SetBranchAddress("njets", &njets, &b_njets);
   fChain->SetBranchAddress("jet_pt", &jet_pt, &b_jet_pt);
   fChain->SetBranchAddress("jet_eta", &jet_eta, &b_jet_eta);
   fChain->SetBranchAddress("jet_phi", &jet_phi, &b_jet_phi);
   fChain->SetBranchAddress("jet_E", &jet_E, &b_jet_E);
   fChain->SetBranchAddress("jet_pt_orig", &jet_pt_orig, &b_jet_pt_orig);
   fChain->SetBranchAddress("jet_eta_orig", &jet_eta_orig, &b_jet_eta_orig);
   fChain->SetBranchAddress("jet_phi_orig", &jet_phi_orig, &b_jet_phi_orig);
   fChain->SetBranchAddress("jet_E_orig", &jet_E_orig, &b_jet_E_orig);
   fChain->SetBranchAddress("jet_LabDr_HadF", &jet_LabDr_HadF, &b_jet_LabDr_HadF);
   fChain->SetBranchAddress("jet_DoubleHadLabel", &jet_DoubleHadLabel, &b_jet_DoubleHadLabel);
   fChain->SetBranchAddress("jet_JVT", &jet_JVT, &b_jet_JVT);
   fChain->SetBranchAddress("jet_m", &jet_m, &b_jet_m);
   fChain->SetBranchAddress("jet_nConst", &jet_nConst, &b_jet_nConst);
   fChain->SetBranchAddress("jet_dRiso", &jet_dRiso, &b_jet_dRiso);
   fChain->SetBranchAddress("jet_truthMatch", &jet_truthMatch, &b_jet_truthMatch);
   fChain->SetBranchAddress("jet_isPU", &jet_isPU, &b_jet_isPU);
   fChain->SetBranchAddress("jet_aliveAfterOR", &jet_aliveAfterOR, &b_jet_aliveAfterOR);
   fChain->SetBranchAddress("jet_aliveAfterORmu", &jet_aliveAfterORmu, &b_jet_aliveAfterORmu);
   fChain->SetBranchAddress("jet_isBadMedium", &jet_isBadMedium, &b_jet_isBadMedium);
   fChain->SetBranchAddress("jet_truthPt", &jet_truthPt, &b_jet_truthPt);
   fChain->SetBranchAddress("jet_dRminToB", &jet_dRminToB, &b_jet_dRminToB);
   fChain->SetBranchAddress("jet_dRminToC", &jet_dRminToC, &b_jet_dRminToC);
   fChain->SetBranchAddress("jet_dRminToT", &jet_dRminToT, &b_jet_dRminToT);
   fChain->SetBranchAddress("jet_isLLPDecayProd", &jet_isLLPDecayProd, &b_jet_isLLPDecayProd);
   fChain->SetBranchAddress("jet_dRtoLLPDecayProd", &jet_dRtoLLPDecayProd, &b_jet_dRtoLLPDecayProd);
   fChain->SetBranchAddress("jet_truthLLPJetLabel", &jet_truthLLPJetLabel, &b_jet_truthLLPJetLabel);
   fChain->SetBranchAddress("jet_truthLLP_Decay_x", &jet_truthLLP_Decay_x, &b_jet_truthLLP_Decay_x);
   fChain->SetBranchAddress("jet_truthLLP_Decay_y", &jet_truthLLP_Decay_y, &b_jet_truthLLP_Decay_y);
   fChain->SetBranchAddress("jet_truthLLP_Decay_z", &jet_truthLLP_Decay_z, &b_jet_truthLLP_Decay_z);
   fChain->SetBranchAddress("jet_dl1_pb", &jet_dl1_pb, &b_jet_dl1_pb);
   fChain->SetBranchAddress("jet_dl1_pc", &jet_dl1_pc, &b_jet_dl1_pc);
   fChain->SetBranchAddress("jet_dl1_pu", &jet_dl1_pu, &b_jet_dl1_pu);
   fChain->SetBranchAddress("jet_dl1rmu_pb", &jet_dl1rmu_pb, &b_jet_dl1rmu_pb);
   fChain->SetBranchAddress("jet_dl1rmu_pc", &jet_dl1rmu_pc, &b_jet_dl1rmu_pc);
   fChain->SetBranchAddress("jet_dl1rmu_pu", &jet_dl1rmu_pu, &b_jet_dl1rmu_pu);
   fChain->SetBranchAddress("jet_dl1r_pb", &jet_dl1r_pb, &b_jet_dl1r_pb);
   fChain->SetBranchAddress("jet_dl1r_pc", &jet_dl1r_pc, &b_jet_dl1r_pc);
   fChain->SetBranchAddress("jet_dl1r_pu", &jet_dl1r_pu, &b_jet_dl1r_pu);
   fChain->SetBranchAddress("jet_mv2c10", &jet_mv2c10, &b_jet_mv2c10);
   fChain->SetBranchAddress("jet_mv2c10mu", &jet_mv2c10mu, &b_jet_mv2c10mu);
   fChain->SetBranchAddress("jet_mv2c10rnn", &jet_mv2c10rnn, &b_jet_mv2c10rnn);
   fChain->SetBranchAddress("jet_mv2c100", &jet_mv2c100, &b_jet_mv2c100);
   fChain->SetBranchAddress("jet_mv2cl100", &jet_mv2cl100, &b_jet_mv2cl100);
   fChain->SetBranchAddress("jet_nBHadr", &jet_nBHadr, &b_jet_nBHadr);
   fChain->SetBranchAddress("jet_nCHadr", &jet_nCHadr, &b_jet_nCHadr);
   fChain->SetBranchAddress("jet_bH_pdgId", &jet_bH_pdgId, &b_jet_bH_pdgId);
   fChain->SetBranchAddress("jet_bH_parent_pdgId", &jet_bH_parent_pdgId, &b_jet_bH_parent_pdgId);
   fChain->SetBranchAddress("jet_bH_pt", &jet_bH_pt, &b_jet_bH_pt);
   fChain->SetBranchAddress("jet_bH_eta", &jet_bH_eta, &b_jet_bH_eta);
   fChain->SetBranchAddress("jet_bH_phi", &jet_bH_phi, &b_jet_bH_phi);
   fChain->SetBranchAddress("jet_bH_E", &jet_bH_E, &b_jet_bH_E);
   fChain->SetBranchAddress("jet_bH_charge", &jet_bH_charge, &b_jet_bH_charge);
   fChain->SetBranchAddress("jet_bH_Lxy", &jet_bH_Lxy, &b_jet_bH_Lxy);
   fChain->SetBranchAddress("jet_bH_x", &jet_bH_x, &b_jet_bH_x);
   fChain->SetBranchAddress("jet_bH_y", &jet_bH_y, &b_jet_bH_y);
   fChain->SetBranchAddress("jet_bH_z", &jet_bH_z, &b_jet_bH_z);
   fChain->SetBranchAddress("jet_bH_dRjet", &jet_bH_dRjet, &b_jet_bH_dRjet);
   fChain->SetBranchAddress("jet_cH_pdgId", &jet_cH_pdgId, &b_jet_cH_pdgId);
   fChain->SetBranchAddress("jet_cH_parent_pdgId", &jet_cH_parent_pdgId, &b_jet_cH_parent_pdgId);
   fChain->SetBranchAddress("jet_cH_pt", &jet_cH_pt, &b_jet_cH_pt);
   fChain->SetBranchAddress("jet_cH_eta", &jet_cH_eta, &b_jet_cH_eta);
   fChain->SetBranchAddress("jet_cH_phi", &jet_cH_phi, &b_jet_cH_phi);
   fChain->SetBranchAddress("jet_cH_E", &jet_cH_E, &b_jet_cH_E);
   fChain->SetBranchAddress("jet_cH_charge", &jet_cH_charge, &b_jet_cH_charge);
   fChain->SetBranchAddress("jet_cH_Lxy", &jet_cH_Lxy, &b_jet_cH_Lxy);
   fChain->SetBranchAddress("jet_cH_x", &jet_cH_x, &b_jet_cH_x);
   fChain->SetBranchAddress("jet_cH_y", &jet_cH_y, &b_jet_cH_y);
   fChain->SetBranchAddress("jet_cH_z", &jet_cH_z, &b_jet_cH_z);
   fChain->SetBranchAddress("jet_cH_dRjet", &jet_cH_dRjet, &b_jet_cH_dRjet);
   fChain->SetBranchAddress("nmmc", &nmmc, &b_nmmc);
   fChain->SetBranchAddress("mymc_pt", &mymc_pt, &b_mymc_pt);
   fChain->SetBranchAddress("mymc_eta", &mymc_eta, &b_mymc_eta);
   fChain->SetBranchAddress("mymc_phi", &mymc_phi, &b_mymc_phi);
   fChain->SetBranchAddress("mymc_pdgId", &mymc_pdgId, &b_mymc_pdgId);
   fChain->SetBranchAddress("mymc_decayVtx_x", &mymc_decayVtx_x, &b_mymc_decayVtx_x);
   fChain->SetBranchAddress("mymc_decayVtx_y", &mymc_decayVtx_y, &b_mymc_decayVtx_y);
   fChain->SetBranchAddress("mymc_decayVtx_z", &mymc_decayVtx_z, &b_mymc_decayVtx_z);
   fChain->SetBranchAddress("mymc_ix1", &mymc_ix1, &b_mymc_ix1);
   fChain->SetBranchAddress("mymc_ix2", &mymc_ix2, &b_mymc_ix2);
   fChain->SetBranchAddress("nmmc1", &nmmc1, &b_nmmc1);
   fChain->SetBranchAddress("mymc1_pt", &mymc1_pt, &b_mymc1_pt);
   fChain->SetBranchAddress("mymc1_eta", &mymc1_eta, &b_mymc1_eta);
   fChain->SetBranchAddress("mymc1_phi", &mymc1_phi, &b_mymc1_phi);
   fChain->SetBranchAddress("mymc1_pdgId", &mymc1_pdgId, &b_mymc1_pdgId);
   Notify();
}

Bool_t d::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void d::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t d::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef d_cxx
