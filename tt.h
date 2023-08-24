//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Aug  7 18:39:41 2023 by ROOT version 6.28/04
// from TTree bTag_AntiKt4EMPFlowJets_BTagging201810/bTagAntiKt4EMPFlowJets_BTagging201810
// found on file: flav_Akt4EMPf_BTagging201810.root
//////////////////////////////////////////////////////////

#ifndef tt_h
#define tt_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"

using namespace std;

class tt {
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
   vector<float>   *jet_pt;
   vector<float>   *jet_eta;
   vector<float>   *jet_phi;
   vector<float>   *jet_E;
   vector<float>   *jet_pt_orig;
   vector<float>   *jet_eta_orig;
   vector<float>   *jet_phi_orig;
   vector<float>   *jet_E_orig;
   vector<int>     *jet_LabDr_HadF;
   vector<int>     *jet_DoubleHadLabel;
   vector<float>   *jet_JVT;
   vector<float>   *jet_m;
   vector<float>   *jet_nConst;
   vector<float>   *jet_dRiso;
   vector<int>     *jet_truthMatch;
   vector<int>     *jet_isPU;
   vector<int>     *jet_aliveAfterOR;
   vector<int>     *jet_aliveAfterORmu;
   vector<int>     *jet_isBadMedium;
   vector<float>   *jet_truthPt;
   vector<float>   *jet_dRminToB;
   vector<float>   *jet_dRminToC;
   vector<float>   *jet_dRminToT;
   vector<int>     *jet_isLLPDecayProd;
   vector<float>   *jet_dRtoLLPDecayProd;
   vector<int>     *jet_truthLLPJetLabel;
   vector<float>   *jet_truthLLP_Decay_x;
   vector<float>   *jet_truthLLP_Decay_y;
   vector<float>   *jet_truthLLP_Decay_z;
   vector<double>  *jet_dl1_pb;
   vector<double>  *jet_dl1_pc;
   vector<double>  *jet_dl1_pu;
   vector<double>  *jet_dl1rmu_pb;
   vector<double>  *jet_dl1rmu_pc;
   vector<double>  *jet_dl1rmu_pu;
   vector<double>  *jet_dl1r_pb;
   vector<double>  *jet_dl1r_pc;
   vector<double>  *jet_dl1r_pu;
   vector<double>  *jet_mv2c10;
   vector<double>  *jet_mv2c10mu;
   vector<double>  *jet_mv2c10rnn;
   vector<double>  *jet_mv2c100;
   vector<double>  *jet_mv2cl100;
   vector<float>   *jet_ip2d_pb;
   vector<float>   *jet_ip2d_pc;
   vector<float>   *jet_ip2d_pu;
   vector<float>   *jet_ip2d_llr;
   vector<float>   *jet_ip3d_pb;
   vector<float>   *jet_ip3d_pc;
   vector<float>   *jet_ip3d_pu;
   vector<float>   *jet_ip3d_llr;
   vector<float>   *jet_ip2;
   vector<float>   *jet_ip2_c;
   vector<float>   *jet_ip2_cu;
   vector<float>   *jet_ip2_nan;
   vector<float>   *jet_ip2_c_nan;
   vector<float>   *jet_ip2_cu_nan;
   vector<float>   *jet_ip3;
   vector<float>   *jet_ip3_c;
   vector<float>   *jet_ip3_cu;
   vector<float>   *jet_ip3_nan;
   vector<float>   *jet_ip3_c_nan;
   vector<float>   *jet_ip3_cu_nan;
   vector<float>   *jet_rnnip_pb;
   vector<float>   *jet_rnnip_pc;
   vector<float>   *jet_rnnip_pu;
   vector<float>   *jet_rnnip_ptau;
   Float_t         PV_jf_x;
   Float_t         PV_jf_y;
   Float_t         PV_jf_z;
   vector<vector<int> > *jet_trk_jf_Vertex;
   vector<float>   *jet_jf_pb;
   vector<float>   *jet_jf_pc;
   vector<float>   *jet_jf_pu;
   vector<float>   *jet_jf_llr;
   vector<float>   *jet_jf_m;
   vector<float>   *jet_jf_mUncorr;
   vector<float>   *jet_jf_efc;
   vector<float>   *jet_jf_deta;
   vector<float>   *jet_jf_dphi;
   vector<float>   *jet_jf_dR;
   vector<float>   *jet_jf_dRFlightDir;
   vector<float>   *jet_jf_ntrkAtVx;
   vector<float>   *jet_jf_nvtx;
   vector<float>   *jet_jf_sig3d;
   vector<float>   *jet_jf_nvtx1t;
   vector<float>   *jet_jf_n2t;
   vector<float>   *jet_jf_VTXsize;
   vector<vector<float> > *jet_jf_vtx_chi2;
   vector<vector<float> > *jet_jf_vtx_ndf;
   vector<vector<int> > *jet_jf_vtx_ntrk;
   vector<vector<float> > *jet_jf_vtx_L3D;
   vector<vector<float> > *jet_jf_vtx_sig3D;
   vector<float>   *jet_jf_phi;
   vector<float>   *jet_jf_theta;
   vector<vector<float> > *jet_jf_vtx_sigTrans;
   vector<vector<float> > *jet_jf_vtx_x;
   vector<vector<float> > *jet_jf_vtx_x_err;
   vector<vector<float> > *jet_jf_vtx_y;
   vector<vector<float> > *jet_jf_vtx_y_err;
   vector<vector<float> > *jet_jf_vtx_z;
   vector<vector<float> > *jet_jf_vtx_z_err;
   vector<float>   *jet_jf_theta_err;
   vector<float>   *jet_jf_phi_err;
   vector<float>   *nTrk_vtx1;
   vector<float>   *mass_first_vtx;
   vector<float>   *e_first_vtx;
   vector<float>   *e_frac_vtx1;
   vector<float>   *closestVtx_L3D;
   vector<float>   *JF_Lxy1;
   vector<float>   *vtx1_MaxTrkRapidity;
   vector<float>   *vtx1_AvgTrkRapidity;
   vector<float>   *vtx1_MinTrkRapidity;
   vector<float>   *nTrk_vtx2;
   vector<float>   *mass_second_vtx;
   vector<float>   *e_second_vtx;
   vector<float>   *e_frac_vtx2;
   vector<float>   *second_closestVtx_L3D;
   vector<float>   *JF_Lxy2;
   vector<float>   *vtx2_MaxTrkRapidity;
   vector<float>   *vtx2_AvgTrkRapidity;
   vector<float>   *vtx2_MinTrkRapidity;
   vector<float>   *MaxTrkRapidity;
   vector<float>   *MinTrkRapidity;
   vector<float>   *AvgTrkRapidity;
   vector<int>     *jet_sv1_Nvtx;
   vector<float>   *jet_sv1_ntrkv;
   vector<float>   *jet_sv1_n2t;
   vector<float>   *jet_sv1_m;
   vector<float>   *jet_sv1_efc;
   vector<float>   *jet_sv1_sig3d;
   vector<float>   *sv1_llr;
   vector<float>   *jet_sv1_normdist;
   vector<float>   *jet_sv1_deltaR;
   vector<float>   *jet_sv1_Lxy;
   vector<float>   *jet_sv1_L3d;
   vector<vector<float> > *jet_sv1_vtx_x;
   vector<vector<float> > *jet_sv1_vtx_y;
   vector<vector<float> > *jet_sv1_vtx_z;
   vector<int>     *jet_nBHadr;
   vector<int>     *jet_nCHadr;
   vector<vector<int> > *jet_bH_pdgId;
   vector<vector<int> > *jet_bH_parent_pdgId;
   vector<vector<float> > *jet_bH_pt;
   vector<vector<float> > *jet_bH_eta;
   vector<vector<float> > *jet_bH_phi;
   vector<vector<float> > *jet_bH_E;
   vector<vector<float> > *jet_bH_charge;
   vector<vector<float> > *jet_bH_Lxy;
   vector<vector<float> > *jet_bH_x;
   vector<vector<float> > *jet_bH_y;
   vector<vector<float> > *jet_bH_z;
   vector<vector<float> > *jet_bH_dRjet;
   vector<vector<int> > *jet_cH_pdgId;
   vector<vector<int> > *jet_cH_parent_pdgId;
   vector<vector<float> > *jet_cH_pt;
   vector<vector<float> > *jet_cH_eta;
   vector<vector<float> > *jet_cH_phi;
   vector<vector<float> > *jet_cH_E;
   vector<vector<float> > *jet_cH_charge;
   vector<vector<float> > *jet_cH_Lxy;
   vector<vector<float> > *jet_cH_x;
   vector<vector<float> > *jet_cH_y;
   vector<vector<float> > *jet_cH_z;
   vector<vector<float> > *jet_cH_dRjet;
   vector<vector<float> > *jet_trk_pt;
   vector<vector<float> > *jet_trk_eta;
   vector<vector<float> > *jet_trk_theta;
   vector<vector<float> > *jet_trk_phi;
   vector<vector<float> > *jet_trk_qoverp;
   vector<vector<float> > *jet_trk_charge;
   vector<vector<float> > *jet_trk_chi2;
   vector<vector<float> > *jet_trk_ndf;
   vector<vector<int> > *jet_trk_nNextToInnHits;
   vector<vector<int> > *jet_trk_nInnHits;
   vector<vector<int> > *jet_trk_nBLHits;
   vector<vector<int> > *jet_trk_nsharedBLHits;
   vector<vector<int> > *jet_trk_nsplitBLHits;
   vector<vector<int> > *jet_trk_nPixHits;
   vector<vector<int> > *jet_trk_nPixHoles;
   vector<vector<int> > *jet_trk_nsharedPixHits;
   vector<vector<int> > *jet_trk_nsplitPixHits;
   vector<vector<int> > *jet_trk_nSCTHits;
   vector<vector<int> > *jet_trk_nSCTHoles;
   vector<vector<int> > *jet_trk_nsharedSCTHits;
   vector<vector<int> > *jet_trk_expectBLayerHit;
   vector<vector<int> > *jet_trk_expectInnermostPixelLayerHit;
   vector<vector<int> > *jet_trk_expectNextToInnermostPixelLayerHit;
   vector<vector<float> > *jet_trk_d0;
   vector<vector<float> > *jet_trk_z0;
   vector<vector<float> > *jet_trk_ip3d_d0;
   vector<vector<float> > *jet_trk_ip3d_d02D;
   vector<vector<float> > *jet_trk_ip3d_z0;
   vector<vector<float> > *jet_trk_ip3d_d0sig;
   vector<vector<float> > *jet_trk_ip3d_z0sig;
   vector<vector<int> > *jet_trk_algo;
   vector<vector<float> > *jet_trk_vtx_X;
   vector<vector<float> > *jet_trk_vtx_Y;
   vector<vector<float> > *jet_trk_vtx_Z;
   vector<vector<int> > *jet_trk_pdg_id;
   vector<vector<int> > *jet_trk_barcode;
   vector<vector<int> > *jet_trk_parent_pdgid;
   vector<int>     *jet_btag_ntrk;
   vector<int>     *jet_ip3d_ntrk;
   vector<vector<int> > *jet_trk_ip3d_grade;
   vector<vector<float> > *jet_trk_ip3d_llr;
   Int_t           nmmc;
   vector<float>   *mymc_pt;
   vector<float>   *mymc_eta;
   vector<float>   *mymc_phi;
   vector<int>     *mymc_pdgId;
   vector<float>   *mymc_decayVtx_x;
   vector<float>   *mymc_decayVtx_y;
   vector<float>   *mymc_decayVtx_z;
   vector<int>     *mymc_ix1;
   vector<int>     *mymc_ix2;
   Int_t           nmmc1;
   vector<float>   *mymc1_pt;
   vector<float>   *mymc1_eta;
   vector<float>   *mymc1_phi;
   vector<int>     *mymc1_pdgId;

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
   TBranch        *b_jet_ip2d_pb;   //!
   TBranch        *b_jet_ip2d_pc;   //!
   TBranch        *b_jet_ip2d_pu;   //!
   TBranch        *b_jet_ip2d_llr;   //!
   TBranch        *b_jet_ip3d_pb;   //!
   TBranch        *b_jet_ip3d_pc;   //!
   TBranch        *b_jet_ip3d_pu;   //!
   TBranch        *b_jet_ip3d_llr;   //!
   TBranch        *b_jet_ip2;   //!
   TBranch        *b_jet_ip2_c;   //!
   TBranch        *b_jet_ip2_cu;   //!
   TBranch        *b_jet_ip2_nan;   //!
   TBranch        *b_jet_ip2_c_nan;   //!
   TBranch        *b_jet_ip2_cu_nan;   //!
   TBranch        *b_jet_ip3;   //!
   TBranch        *b_jet_ip3_c;   //!
   TBranch        *b_jet_ip3_cu;   //!
   TBranch        *b_jet_ip3_nan;   //!
   TBranch        *b_jet_ip3_c_nan;   //!
   TBranch        *b_jet_ip3_cu_nan;   //!
   TBranch        *b_jet_rnnip_pb;   //!
   TBranch        *b_jet_rnnip_pc;   //!
   TBranch        *b_jet_rnnip_pu;   //!
   TBranch        *b_jet_rnnip_ptau;   //!
   TBranch        *b_PV_jf_x;   //!
   TBranch        *b_PV_jf_y;   //!
   TBranch        *b_PV_jf_z;   //!
   TBranch        *b_jet_trk_jf_Vertex;   //!
   TBranch        *b_jet_jf_pb;   //!
   TBranch        *b_jet_jf_pc;   //!
   TBranch        *b_jet_jf_pu;   //!
   TBranch        *b_jet_jf_llr;   //!
   TBranch        *b_jet_jf_m;   //!
   TBranch        *b_jet_jf_mUncorr;   //!
   TBranch        *b_jet_jf_efc;   //!
   TBranch        *b_jet_jf_deta;   //!
   TBranch        *b_jet_jf_dphi;   //!
   TBranch        *b_jet_jf_dR;   //!
   TBranch        *b_jet_jf_dRFlightDir;   //!
   TBranch        *b_jet_jf_ntrkAtVx;   //!
   TBranch        *b_jet_jf_nvtx;   //!
   TBranch        *b_jet_jf_sig3d;   //!
   TBranch        *b_jet_jf_nvtx1t;   //!
   TBranch        *b_jet_jf_n2t;   //!
   TBranch        *b_jet_jf_VTXsize;   //!
   TBranch        *b_jet_jf_vtx_chi2;   //!
   TBranch        *b_jet_jf_vtx_ndf;   //!
   TBranch        *b_jet_jf_vtx_ntrk;   //!
   TBranch        *b_jet_jf_vtx_L3D;   //!
   TBranch        *b_jet_jf_vtx_sig3D;   //!
   TBranch        *b_jet_jf_phi;   //!
   TBranch        *b_jet_jf_theta;   //!
   TBranch        *b_jet_jf_vtx_sigTrans;   //!
   TBranch        *b_jet_jf_vtx_x;   //!
   TBranch        *b_jet_jf_vtx_x_err;   //!
   TBranch        *b_jet_jf_vtx_y;   //!
   TBranch        *b_jet_jf_vtx_y_err;   //!
   TBranch        *b_jet_jf_vtx_z;   //!
   TBranch        *b_jet_jf_vtx_z_err;   //!
   TBranch        *b_jet_jf_theta_err;   //!
   TBranch        *b_jet_jf_phi_err;   //!
   TBranch        *b_nTrk_vtx1;   //!
   TBranch        *b_mass_first_vtx;   //!
   TBranch        *b_e_first_vtx;   //!
   TBranch        *b_e_frac_vtx1;   //!
   TBranch        *b_closestVtx_L3D;   //!
   TBranch        *b_JF_Lxy1;   //!
   TBranch        *b_vtx1_MaxTrkRapidity;   //!
   TBranch        *b_vtx1_AvgTrkRapidity;   //!
   TBranch        *b_vtx1_MinTrkRapidity;   //!
   TBranch        *b_nTrk_vtx2;   //!
   TBranch        *b_mass_second_vtx;   //!
   TBranch        *b_e_second_vtx;   //!
   TBranch        *b_e_frac_vtx2;   //!
   TBranch        *b_second_closestVtx_L3D;   //!
   TBranch        *b_JF_Lxy2;   //!
   TBranch        *b_vtx2_MaxTrkRapidity;   //!
   TBranch        *b_vtx2_AvgTrkRapidity;   //!
   TBranch        *b_vtx2_MinTrkRapidity;   //!
   TBranch        *b_MaxTrkRapidity;   //!
   TBranch        *b_MinTrkRapidity;   //!
   TBranch        *b_AvgTrkRapidity;   //!
   TBranch        *b_jet_sv1_Nvtx;   //!
   TBranch        *b_jet_sv1_ntrkv;   //!
   TBranch        *b_jet_sv1_n2t;   //!
   TBranch        *b_jet_sv1_m;   //!
   TBranch        *b_jet_sv1_efc;   //!
   TBranch        *b_jet_sv1_sig3d;   //!
   TBranch        *b_sv1_llr;   //!
   TBranch        *b_jet_sv1_normdist;   //!
   TBranch        *b_jet_sv1_deltaR;   //!
   TBranch        *b_jet_sv1_Lxy;   //!
   TBranch        *b_jet_sv1_L3d;   //!
   TBranch        *b_jet_sv1_vtx_x;   //!
   TBranch        *b_jet_sv1_vtx_y;   //!
   TBranch        *b_jet_sv1_vtx_z;   //!
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
   TBranch        *b_jet_trk_pt;   //!
   TBranch        *b_jet_trk_eta;   //!
   TBranch        *b_jet_trk_theta;   //!
   TBranch        *b_jet_trk_phi;   //!
   TBranch        *b_jet_trk_qoverp;   //!
   TBranch        *b_jet_trk_charge;   //!
   TBranch        *b_jet_trk_chi2;   //!
   TBranch        *b_jet_trk_ndf;   //!
   TBranch        *b_jet_trk_nNextToInnHits;   //!
   TBranch        *b_jet_trk_nInnHits;   //!
   TBranch        *b_jet_trk_nBLHits;   //!
   TBranch        *b_jet_trk_nsharedBLHits;   //!
   TBranch        *b_jet_trk_nsplitBLHits;   //!
   TBranch        *b_jet_trk_nPixHits;   //!
   TBranch        *b_jet_trk_nPixHoles;   //!
   TBranch        *b_jet_trk_nsharedPixHits;   //!
   TBranch        *b_jet_trk_nsplitPixHits;   //!
   TBranch        *b_jet_trk_nSCTHits;   //!
   TBranch        *b_jet_trk_nSCTHoles;   //!
   TBranch        *b_jet_trk_nsharedSCTHits;   //!
   TBranch        *b_jet_trk_expectBLayerHit;   //!
   TBranch        *b_jet_trk_expectInnermostPixelLayerHit;   //!
   TBranch        *b_jet_trk_expectNextToInnermostPixelLayerHit;   //!
   TBranch        *b_jet_trk_d0;   //!
   TBranch        *b_jet_trk_z0;   //!
   TBranch        *b_jet_trk_ip3d_d0;   //!
   TBranch        *b_jet_trk_ip3d_d02D;   //!
   TBranch        *b_jet_trk_ip3d_z0;   //!
   TBranch        *b_jet_trk_ip3d_d0sig;   //!
   TBranch        *b_jet_trk_ip3d_z0sig;   //!
   TBranch        *b_jet_trk_algo;   //!
   TBranch        *b_jet_trk_vtx_X;   //!
   TBranch        *b_jet_trk_vtx_Y;   //!
   TBranch        *b_jet_trk_vtx_Z;   //!
   TBranch        *b_jet_trk_pdg_id;   //!
   TBranch        *b_jet_trk_barcode;   //!
   TBranch        *b_jet_trk_parent_pdgid;   //!
   TBranch        *b_jet_btag_ntrk;   //!
   TBranch        *b_jet_ip3d_ntrk;   //!
   TBranch        *b_jet_trk_ip3d_grade;   //!
   TBranch        *b_jet_trk_ip3d_llr;   //!
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

   tt(TTree *tree=0);
   virtual ~tt();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef tt_cxx
tt::tt(TTree *tree) : fChain(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("flav_Akt4EMPf_BTagging201810.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("flav_Akt4EMPf_BTagging201810.root");
      }
      f->GetObject("bTag_AntiKt4EMPFlowJets_BTagging201810",tree);

   }
   Init(tree);
}

tt::~tt()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t tt::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t tt::LoadTree(Long64_t entry)
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

void tt::Init(TTree *tree)
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
   jet_ip2d_pb = 0;
   jet_ip2d_pc = 0;
   jet_ip2d_pu = 0;
   jet_ip2d_llr = 0;
   jet_ip3d_pb = 0;
   jet_ip3d_pc = 0;
   jet_ip3d_pu = 0;
   jet_ip3d_llr = 0;
   jet_ip2 = 0;
   jet_ip2_c = 0;
   jet_ip2_cu = 0;
   jet_ip2_nan = 0;
   jet_ip2_c_nan = 0;
   jet_ip2_cu_nan = 0;
   jet_ip3 = 0;
   jet_ip3_c = 0;
   jet_ip3_cu = 0;
   jet_ip3_nan = 0;
   jet_ip3_c_nan = 0;
   jet_ip3_cu_nan = 0;
   jet_rnnip_pb = 0;
   jet_rnnip_pc = 0;
   jet_rnnip_pu = 0;
   jet_rnnip_ptau = 0;
   jet_trk_jf_Vertex = 0;
   jet_jf_pb = 0;
   jet_jf_pc = 0;
   jet_jf_pu = 0;
   jet_jf_llr = 0;
   jet_jf_m = 0;
   jet_jf_mUncorr = 0;
   jet_jf_efc = 0;
   jet_jf_deta = 0;
   jet_jf_dphi = 0;
   jet_jf_dR = 0;
   jet_jf_dRFlightDir = 0;
   jet_jf_ntrkAtVx = 0;
   jet_jf_nvtx = 0;
   jet_jf_sig3d = 0;
   jet_jf_nvtx1t = 0;
   jet_jf_n2t = 0;
   jet_jf_VTXsize = 0;
   jet_jf_vtx_chi2 = 0;
   jet_jf_vtx_ndf = 0;
   jet_jf_vtx_ntrk = 0;
   jet_jf_vtx_L3D = 0;
   jet_jf_vtx_sig3D = 0;
   jet_jf_phi = 0;
   jet_jf_theta = 0;
   jet_jf_vtx_sigTrans = 0;
   jet_jf_vtx_x = 0;
   jet_jf_vtx_x_err = 0;
   jet_jf_vtx_y = 0;
   jet_jf_vtx_y_err = 0;
   jet_jf_vtx_z = 0;
   jet_jf_vtx_z_err = 0;
   jet_jf_theta_err = 0;
   jet_jf_phi_err = 0;
   nTrk_vtx1 = 0;
   mass_first_vtx = 0;
   e_first_vtx = 0;
   e_frac_vtx1 = 0;
   closestVtx_L3D = 0;
   JF_Lxy1 = 0;
   vtx1_MaxTrkRapidity = 0;
   vtx1_AvgTrkRapidity = 0;
   vtx1_MinTrkRapidity = 0;
   nTrk_vtx2 = 0;
   mass_second_vtx = 0;
   e_second_vtx = 0;
   e_frac_vtx2 = 0;
   second_closestVtx_L3D = 0;
   JF_Lxy2 = 0;
   vtx2_MaxTrkRapidity = 0;
   vtx2_AvgTrkRapidity = 0;
   vtx2_MinTrkRapidity = 0;
   MaxTrkRapidity = 0;
   MinTrkRapidity = 0;
   AvgTrkRapidity = 0;
   jet_sv1_Nvtx = 0;
   jet_sv1_ntrkv = 0;
   jet_sv1_n2t = 0;
   jet_sv1_m = 0;
   jet_sv1_efc = 0;
   jet_sv1_sig3d = 0;
   sv1_llr = 0;
   jet_sv1_normdist = 0;
   jet_sv1_deltaR = 0;
   jet_sv1_Lxy = 0;
   jet_sv1_L3d = 0;
   jet_sv1_vtx_x = 0;
   jet_sv1_vtx_y = 0;
   jet_sv1_vtx_z = 0;
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
   jet_trk_pt = 0;
   jet_trk_eta = 0;
   jet_trk_theta = 0;
   jet_trk_phi = 0;
   jet_trk_qoverp = 0;
   jet_trk_charge = 0;
   jet_trk_chi2 = 0;
   jet_trk_ndf = 0;
   jet_trk_nNextToInnHits = 0;
   jet_trk_nInnHits = 0;
   jet_trk_nBLHits = 0;
   jet_trk_nsharedBLHits = 0;
   jet_trk_nsplitBLHits = 0;
   jet_trk_nPixHits = 0;
   jet_trk_nPixHoles = 0;
   jet_trk_nsharedPixHits = 0;
   jet_trk_nsplitPixHits = 0;
   jet_trk_nSCTHits = 0;
   jet_trk_nSCTHoles = 0;
   jet_trk_nsharedSCTHits = 0;
   jet_trk_expectBLayerHit = 0;
   jet_trk_expectInnermostPixelLayerHit = 0;
   jet_trk_expectNextToInnermostPixelLayerHit = 0;
   jet_trk_d0 = 0;
   jet_trk_z0 = 0;
   jet_trk_ip3d_d0 = 0;
   jet_trk_ip3d_d02D = 0;
   jet_trk_ip3d_z0 = 0;
   jet_trk_ip3d_d0sig = 0;
   jet_trk_ip3d_z0sig = 0;
   jet_trk_algo = 0;
   jet_trk_vtx_X = 0;
   jet_trk_vtx_Y = 0;
   jet_trk_vtx_Z = 0;
   jet_trk_pdg_id = 0;
   jet_trk_barcode = 0;
   jet_trk_parent_pdgid = 0;
   jet_btag_ntrk = 0;
   jet_ip3d_ntrk = 0;
   jet_trk_ip3d_grade = 0;
   jet_trk_ip3d_llr = 0;
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
   fChain->SetBranchAddress("jet_ip2d_pb", &jet_ip2d_pb, &b_jet_ip2d_pb);
   fChain->SetBranchAddress("jet_ip2d_pc", &jet_ip2d_pc, &b_jet_ip2d_pc);
   fChain->SetBranchAddress("jet_ip2d_pu", &jet_ip2d_pu, &b_jet_ip2d_pu);
   fChain->SetBranchAddress("jet_ip2d_llr", &jet_ip2d_llr, &b_jet_ip2d_llr);
   fChain->SetBranchAddress("jet_ip3d_pb", &jet_ip3d_pb, &b_jet_ip3d_pb);
   fChain->SetBranchAddress("jet_ip3d_pc", &jet_ip3d_pc, &b_jet_ip3d_pc);
   fChain->SetBranchAddress("jet_ip3d_pu", &jet_ip3d_pu, &b_jet_ip3d_pu);
   fChain->SetBranchAddress("jet_ip3d_llr", &jet_ip3d_llr, &b_jet_ip3d_llr);
   fChain->SetBranchAddress("jet_ip2", &jet_ip2, &b_jet_ip2);
   fChain->SetBranchAddress("jet_ip2_c", &jet_ip2_c, &b_jet_ip2_c);
   fChain->SetBranchAddress("jet_ip2_cu", &jet_ip2_cu, &b_jet_ip2_cu);
   fChain->SetBranchAddress("jet_ip2_nan", &jet_ip2_nan, &b_jet_ip2_nan);
   fChain->SetBranchAddress("jet_ip2_c_nan", &jet_ip2_c_nan, &b_jet_ip2_c_nan);
   fChain->SetBranchAddress("jet_ip2_cu_nan", &jet_ip2_cu_nan, &b_jet_ip2_cu_nan);
   fChain->SetBranchAddress("jet_ip3", &jet_ip3, &b_jet_ip3);
   fChain->SetBranchAddress("jet_ip3_c", &jet_ip3_c, &b_jet_ip3_c);
   fChain->SetBranchAddress("jet_ip3_cu", &jet_ip3_cu, &b_jet_ip3_cu);
   fChain->SetBranchAddress("jet_ip3_nan", &jet_ip3_nan, &b_jet_ip3_nan);
   fChain->SetBranchAddress("jet_ip3_c_nan", &jet_ip3_c_nan, &b_jet_ip3_c_nan);
   fChain->SetBranchAddress("jet_ip3_cu_nan", &jet_ip3_cu_nan, &b_jet_ip3_cu_nan);
   fChain->SetBranchAddress("jet_rnnip_pb", &jet_rnnip_pb, &b_jet_rnnip_pb);
   fChain->SetBranchAddress("jet_rnnip_pc", &jet_rnnip_pc, &b_jet_rnnip_pc);
   fChain->SetBranchAddress("jet_rnnip_pu", &jet_rnnip_pu, &b_jet_rnnip_pu);
   fChain->SetBranchAddress("jet_rnnip_ptau", &jet_rnnip_ptau, &b_jet_rnnip_ptau);
   fChain->SetBranchAddress("PV_jf_x", &PV_jf_x, &b_PV_jf_x);
   fChain->SetBranchAddress("PV_jf_y", &PV_jf_y, &b_PV_jf_y);
   fChain->SetBranchAddress("PV_jf_z", &PV_jf_z, &b_PV_jf_z);
   fChain->SetBranchAddress("jet_trk_jf_Vertex", &jet_trk_jf_Vertex, &b_jet_trk_jf_Vertex);
   fChain->SetBranchAddress("jet_jf_pb", &jet_jf_pb, &b_jet_jf_pb);
   fChain->SetBranchAddress("jet_jf_pc", &jet_jf_pc, &b_jet_jf_pc);
   fChain->SetBranchAddress("jet_jf_pu", &jet_jf_pu, &b_jet_jf_pu);
   fChain->SetBranchAddress("jet_jf_llr", &jet_jf_llr, &b_jet_jf_llr);
   fChain->SetBranchAddress("jet_jf_m", &jet_jf_m, &b_jet_jf_m);
   fChain->SetBranchAddress("jet_jf_mUncorr", &jet_jf_mUncorr, &b_jet_jf_mUncorr);
   fChain->SetBranchAddress("jet_jf_efc", &jet_jf_efc, &b_jet_jf_efc);
   fChain->SetBranchAddress("jet_jf_deta", &jet_jf_deta, &b_jet_jf_deta);
   fChain->SetBranchAddress("jet_jf_dphi", &jet_jf_dphi, &b_jet_jf_dphi);
   fChain->SetBranchAddress("jet_jf_dR", &jet_jf_dR, &b_jet_jf_dR);
   fChain->SetBranchAddress("jet_jf_dRFlightDir", &jet_jf_dRFlightDir, &b_jet_jf_dRFlightDir);
   fChain->SetBranchAddress("jet_jf_ntrkAtVx", &jet_jf_ntrkAtVx, &b_jet_jf_ntrkAtVx);
   fChain->SetBranchAddress("jet_jf_nvtx", &jet_jf_nvtx, &b_jet_jf_nvtx);
   fChain->SetBranchAddress("jet_jf_sig3d", &jet_jf_sig3d, &b_jet_jf_sig3d);
   fChain->SetBranchAddress("jet_jf_nvtx1t", &jet_jf_nvtx1t, &b_jet_jf_nvtx1t);
   fChain->SetBranchAddress("jet_jf_n2t", &jet_jf_n2t, &b_jet_jf_n2t);
   fChain->SetBranchAddress("jet_jf_VTXsize", &jet_jf_VTXsize, &b_jet_jf_VTXsize);
   fChain->SetBranchAddress("jet_jf_vtx_chi2", &jet_jf_vtx_chi2, &b_jet_jf_vtx_chi2);
   fChain->SetBranchAddress("jet_jf_vtx_ndf", &jet_jf_vtx_ndf, &b_jet_jf_vtx_ndf);
   fChain->SetBranchAddress("jet_jf_vtx_ntrk", &jet_jf_vtx_ntrk, &b_jet_jf_vtx_ntrk);
   fChain->SetBranchAddress("jet_jf_vtx_L3D", &jet_jf_vtx_L3D, &b_jet_jf_vtx_L3D);
   fChain->SetBranchAddress("jet_jf_vtx_sig3D", &jet_jf_vtx_sig3D, &b_jet_jf_vtx_sig3D);
   fChain->SetBranchAddress("jet_jf_phi", &jet_jf_phi, &b_jet_jf_phi);
   fChain->SetBranchAddress("jet_jf_theta", &jet_jf_theta, &b_jet_jf_theta);
   fChain->SetBranchAddress("jet_jf_vtx_sigTrans", &jet_jf_vtx_sigTrans, &b_jet_jf_vtx_sigTrans);
   fChain->SetBranchAddress("jet_jf_vtx_x", &jet_jf_vtx_x, &b_jet_jf_vtx_x);
   fChain->SetBranchAddress("jet_jf_vtx_x_err", &jet_jf_vtx_x_err, &b_jet_jf_vtx_x_err);
   fChain->SetBranchAddress("jet_jf_vtx_y", &jet_jf_vtx_y, &b_jet_jf_vtx_y);
   fChain->SetBranchAddress("jet_jf_vtx_y_err", &jet_jf_vtx_y_err, &b_jet_jf_vtx_y_err);
   fChain->SetBranchAddress("jet_jf_vtx_z", &jet_jf_vtx_z, &b_jet_jf_vtx_z);
   fChain->SetBranchAddress("jet_jf_vtx_z_err", &jet_jf_vtx_z_err, &b_jet_jf_vtx_z_err);
   fChain->SetBranchAddress("jet_jf_theta_err", &jet_jf_theta_err, &b_jet_jf_theta_err);
   fChain->SetBranchAddress("jet_jf_phi_err", &jet_jf_phi_err, &b_jet_jf_phi_err);
   fChain->SetBranchAddress("nTrk_vtx1", &nTrk_vtx1, &b_nTrk_vtx1);
   fChain->SetBranchAddress("mass_first_vtx", &mass_first_vtx, &b_mass_first_vtx);
   fChain->SetBranchAddress("e_first_vtx", &e_first_vtx, &b_e_first_vtx);
   fChain->SetBranchAddress("e_frac_vtx1", &e_frac_vtx1, &b_e_frac_vtx1);
   fChain->SetBranchAddress("closestVtx_L3D", &closestVtx_L3D, &b_closestVtx_L3D);
   fChain->SetBranchAddress("JF_Lxy1", &JF_Lxy1, &b_JF_Lxy1);
   fChain->SetBranchAddress("vtx1_MaxTrkRapidity", &vtx1_MaxTrkRapidity, &b_vtx1_MaxTrkRapidity);
   fChain->SetBranchAddress("vtx1_AvgTrkRapidity", &vtx1_AvgTrkRapidity, &b_vtx1_AvgTrkRapidity);
   fChain->SetBranchAddress("vtx1_MinTrkRapidity", &vtx1_MinTrkRapidity, &b_vtx1_MinTrkRapidity);
   fChain->SetBranchAddress("nTrk_vtx2", &nTrk_vtx2, &b_nTrk_vtx2);
   fChain->SetBranchAddress("mass_second_vtx", &mass_second_vtx, &b_mass_second_vtx);
   fChain->SetBranchAddress("e_second_vtx", &e_second_vtx, &b_e_second_vtx);
   fChain->SetBranchAddress("e_frac_vtx2", &e_frac_vtx2, &b_e_frac_vtx2);
   fChain->SetBranchAddress("second_closestVtx_L3D", &second_closestVtx_L3D, &b_second_closestVtx_L3D);
   fChain->SetBranchAddress("JF_Lxy2", &JF_Lxy2, &b_JF_Lxy2);
   fChain->SetBranchAddress("vtx2_MaxTrkRapidity", &vtx2_MaxTrkRapidity, &b_vtx2_MaxTrkRapidity);
   fChain->SetBranchAddress("vtx2_AvgTrkRapidity", &vtx2_AvgTrkRapidity, &b_vtx2_AvgTrkRapidity);
   fChain->SetBranchAddress("vtx2_MinTrkRapidity", &vtx2_MinTrkRapidity, &b_vtx2_MinTrkRapidity);
   fChain->SetBranchAddress("MaxTrkRapidity", &MaxTrkRapidity, &b_MaxTrkRapidity);
   fChain->SetBranchAddress("MinTrkRapidity", &MinTrkRapidity, &b_MinTrkRapidity);
   fChain->SetBranchAddress("AvgTrkRapidity", &AvgTrkRapidity, &b_AvgTrkRapidity);
   fChain->SetBranchAddress("jet_sv1_Nvtx", &jet_sv1_Nvtx, &b_jet_sv1_Nvtx);
   fChain->SetBranchAddress("jet_sv1_ntrkv", &jet_sv1_ntrkv, &b_jet_sv1_ntrkv);
   fChain->SetBranchAddress("jet_sv1_n2t", &jet_sv1_n2t, &b_jet_sv1_n2t);
   fChain->SetBranchAddress("jet_sv1_m", &jet_sv1_m, &b_jet_sv1_m);
   fChain->SetBranchAddress("jet_sv1_efc", &jet_sv1_efc, &b_jet_sv1_efc);
   fChain->SetBranchAddress("jet_sv1_sig3d", &jet_sv1_sig3d, &b_jet_sv1_sig3d);
   fChain->SetBranchAddress("sv1_llr", &sv1_llr, &b_sv1_llr);
   fChain->SetBranchAddress("jet_sv1_normdist", &jet_sv1_normdist, &b_jet_sv1_normdist);
   fChain->SetBranchAddress("jet_sv1_deltaR", &jet_sv1_deltaR, &b_jet_sv1_deltaR);
   fChain->SetBranchAddress("jet_sv1_Lxy", &jet_sv1_Lxy, &b_jet_sv1_Lxy);
   fChain->SetBranchAddress("jet_sv1_L3d", &jet_sv1_L3d, &b_jet_sv1_L3d);
   fChain->SetBranchAddress("jet_sv1_vtx_x", &jet_sv1_vtx_x, &b_jet_sv1_vtx_x);
   fChain->SetBranchAddress("jet_sv1_vtx_y", &jet_sv1_vtx_y, &b_jet_sv1_vtx_y);
   fChain->SetBranchAddress("jet_sv1_vtx_z", &jet_sv1_vtx_z, &b_jet_sv1_vtx_z);
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
   fChain->SetBranchAddress("jet_trk_pt", &jet_trk_pt, &b_jet_trk_pt);
   fChain->SetBranchAddress("jet_trk_eta", &jet_trk_eta, &b_jet_trk_eta);
   fChain->SetBranchAddress("jet_trk_theta", &jet_trk_theta, &b_jet_trk_theta);
   fChain->SetBranchAddress("jet_trk_phi", &jet_trk_phi, &b_jet_trk_phi);
   fChain->SetBranchAddress("jet_trk_qoverp", &jet_trk_qoverp, &b_jet_trk_qoverp);
   fChain->SetBranchAddress("jet_trk_charge", &jet_trk_charge, &b_jet_trk_charge);
   fChain->SetBranchAddress("jet_trk_chi2", &jet_trk_chi2, &b_jet_trk_chi2);
   fChain->SetBranchAddress("jet_trk_ndf", &jet_trk_ndf, &b_jet_trk_ndf);
   fChain->SetBranchAddress("jet_trk_nNextToInnHits", &jet_trk_nNextToInnHits, &b_jet_trk_nNextToInnHits);
   fChain->SetBranchAddress("jet_trk_nInnHits", &jet_trk_nInnHits, &b_jet_trk_nInnHits);
   fChain->SetBranchAddress("jet_trk_nBLHits", &jet_trk_nBLHits, &b_jet_trk_nBLHits);
   fChain->SetBranchAddress("jet_trk_nsharedBLHits", &jet_trk_nsharedBLHits, &b_jet_trk_nsharedBLHits);
   fChain->SetBranchAddress("jet_trk_nsplitBLHits", &jet_trk_nsplitBLHits, &b_jet_trk_nsplitBLHits);
   fChain->SetBranchAddress("jet_trk_nPixHits", &jet_trk_nPixHits, &b_jet_trk_nPixHits);
   fChain->SetBranchAddress("jet_trk_nPixHoles", &jet_trk_nPixHoles, &b_jet_trk_nPixHoles);
   fChain->SetBranchAddress("jet_trk_nsharedPixHits", &jet_trk_nsharedPixHits, &b_jet_trk_nsharedPixHits);
   fChain->SetBranchAddress("jet_trk_nsplitPixHits", &jet_trk_nsplitPixHits, &b_jet_trk_nsplitPixHits);
   fChain->SetBranchAddress("jet_trk_nSCTHits", &jet_trk_nSCTHits, &b_jet_trk_nSCTHits);
   fChain->SetBranchAddress("jet_trk_nSCTHoles", &jet_trk_nSCTHoles, &b_jet_trk_nSCTHoles);
   fChain->SetBranchAddress("jet_trk_nsharedSCTHits", &jet_trk_nsharedSCTHits, &b_jet_trk_nsharedSCTHits);
   fChain->SetBranchAddress("jet_trk_expectBLayerHit", &jet_trk_expectBLayerHit, &b_jet_trk_expectBLayerHit);
   fChain->SetBranchAddress("jet_trk_expectInnermostPixelLayerHit", &jet_trk_expectInnermostPixelLayerHit, &b_jet_trk_expectInnermostPixelLayerHit);
   fChain->SetBranchAddress("jet_trk_expectNextToInnermostPixelLayerHit", &jet_trk_expectNextToInnermostPixelLayerHit, &b_jet_trk_expectNextToInnermostPixelLayerHit);
   fChain->SetBranchAddress("jet_trk_d0", &jet_trk_d0, &b_jet_trk_d0);
   fChain->SetBranchAddress("jet_trk_z0", &jet_trk_z0, &b_jet_trk_z0);
   fChain->SetBranchAddress("jet_trk_ip3d_d0", &jet_trk_ip3d_d0, &b_jet_trk_ip3d_d0);
   fChain->SetBranchAddress("jet_trk_ip3d_d02D", &jet_trk_ip3d_d02D, &b_jet_trk_ip3d_d02D);
   fChain->SetBranchAddress("jet_trk_ip3d_z0", &jet_trk_ip3d_z0, &b_jet_trk_ip3d_z0);
   fChain->SetBranchAddress("jet_trk_ip3d_d0sig", &jet_trk_ip3d_d0sig, &b_jet_trk_ip3d_d0sig);
   fChain->SetBranchAddress("jet_trk_ip3d_z0sig", &jet_trk_ip3d_z0sig, &b_jet_trk_ip3d_z0sig);
   fChain->SetBranchAddress("jet_trk_algo", &jet_trk_algo, &b_jet_trk_algo);
   fChain->SetBranchAddress("jet_trk_vtx_X", &jet_trk_vtx_X, &b_jet_trk_vtx_X);
   fChain->SetBranchAddress("jet_trk_vtx_Y", &jet_trk_vtx_Y, &b_jet_trk_vtx_Y);
   fChain->SetBranchAddress("jet_trk_vtx_Z", &jet_trk_vtx_Z, &b_jet_trk_vtx_Z);
   fChain->SetBranchAddress("jet_trk_pdg_id", &jet_trk_pdg_id, &b_jet_trk_pdg_id);
   fChain->SetBranchAddress("jet_trk_barcode", &jet_trk_barcode, &b_jet_trk_barcode);
   fChain->SetBranchAddress("jet_trk_parent_pdgid", &jet_trk_parent_pdgid, &b_jet_trk_parent_pdgid);
   fChain->SetBranchAddress("jet_btag_ntrk", &jet_btag_ntrk, &b_jet_btag_ntrk);
   fChain->SetBranchAddress("jet_ip3d_ntrk", &jet_ip3d_ntrk, &b_jet_ip3d_ntrk);
   fChain->SetBranchAddress("jet_trk_ip3d_grade", &jet_trk_ip3d_grade, &b_jet_trk_ip3d_grade);
   fChain->SetBranchAddress("jet_trk_ip3d_llr", &jet_trk_ip3d_llr, &b_jet_trk_ip3d_llr);
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

Bool_t tt::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void tt::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t tt::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef tt_cxx
