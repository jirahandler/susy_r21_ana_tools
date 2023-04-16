/**
 * @file d_ana.cpp
 * @author SammyG , Alexander Khanov
 * @brief Main analysis C++ file that loops over events/jets and trees
 * @version 0.1
 * @date 2023-04-16
 */
#include "d.h"

#include <string>
#include <filesystem>
using std::string;
namespace fs = std::filesystem;

int main(int argc, char* argv[])
{
  if (argc<2) return 1;

  const char* chtree = "bTag_AntiKt4EMPFlowJets_BTagging201810";
  TChain* tt = new TChain(chtree);
  for (int i1 = 1; i1<argc; ++i1) {
    tt->Add(argv[i1]);
  }

  TTree* mytree = (TTree*)gROOT->FindObject(chtree);
  Long64_t nentries = mytree->GetEntries();
  d* t = new d(mytree); // all branches are set
  
  TString foutname = std::string("a1_") + std::string(fs::path(argv[1]).filename());
  TFile* fout = new TFile(foutname,"RECREATE");
  t->Loop();
  fout->Write();
  delete fout;
}
