/**
 * @file pl_perf.C
 * @author Alexander Khanov , SammyG
 * @brief Get SUSY perf plots
 * @version 0.1
 * @date 2023-04-16
 */
#include "AtlasStyle.C"

void pl_perf()
{
  SetAtlasStyle();

  bool plot_ratio = false;

  const char* chvar = "lxy";
  const char* chtitl = "Lxy [mm]";
  bool btag = true, dofit = false;

  //const char* chvar = "jetpt_2";
  //const char* chtitl = "b-jet p_{T} [GeV]";
  //bool btag = true, dofit = true;

  //const char* chvar = "jetpt_0";
  //const char* chtitl = "light jet p_{T} [GeV]";
  //bool btag = true, dofit = true;

  // load histograms and calculate efficiency

  const char* chfile[] = {"410470"};
  //const char* chfile[] = {"410470","410472","410480","410482","411356","412116"};
  //const char* chfile[] = {"hf","lf"};
  const int nf = sizeof(chfile)/sizeof(const char*);
  TH1* h[nf];

  const int icol[] = {1,2,4,3,6,51};

  for (int kf = 0; kf<nf; ++kf) {
    TFile* ff = new TFile(TString("a1_")+chfile[kf]+".root");
    TH1* hall = (TH1*)ff->Get(TString(chvar)+"_all");
    h[kf] = (TH1*)ff->Get(TString(chvar)+"_tag");
    h[kf]->Divide(h[kf],hall,1.,1.,"B");
  }

  // Draw plots

  TCanvas* c1;
  TPad *lowerPad, *upperPad;

  if (plot_ratio) {
    c1 = new TCanvas("c1","c1",700,800);
    lowerPad = new TPad("cl","",0,0,1.,0.375);
    upperPad = new TPad("cu","",0,0.375,1.,1.);
    upperPad->SetLogx();
    lowerPad->SetLogx();
    if (!btag) upperPad->SetLogy();
    lowerPad->Draw();
    upperPad->Draw();

    upperPad->cd();
    upperPad->SetGridx();
    upperPad->SetGridy();

    lowerPad->SetTopMargin(0.03);
    lowerPad->SetBottomMargin(0.29);
  } else {
    c1 = new TCanvas("c1","c1",700,500);
    c1->SetGridx();
    c1->SetGridy();
    c1->SetLogx();
  }

  TLegend* l = new TLegend(0.7,0.2,0.85,0.35);
  l->SetMargin(0.2);
  l->SetBorderSize(0);
  l->SetFillStyle(0);
  l->SetTextFont(42);

  for (int kf = 0; kf<nf; ++kf) {
    h[kf]->SetMarkerStyle(8);
    h[kf]->SetMarkerSize(1.2);
    h[kf]->SetMarkerColor(icol[kf]);
    h[kf]->SetLineColor(icol[kf]);
    if (kf==0) {
      h[kf]->GetYaxis()->SetTitle("Tagging efficiency");
      if (btag) {
	h[kf]->SetMinimum(0);
	h[kf]->SetMaximum(1.1);
  //h[kf]->GetXaxis()->SetRangeUser(1e-4, 1e2);
      } else {
	h[kf]->SetMinimum(1e-4);
	h[kf]->SetMaximum(1e-2);
      }
      h[kf]->Draw("e0");
    } else {
      h[kf]->Draw("e0same");
    }
    l->AddEntry(h[kf],chfile[kf],"l");
  }

  if (plot_ratio) {
    h[0]->GetXaxis()->SetLabelSize(0);
    h[0]->GetXaxis()->SetTitleSize(0);
  } else {
    h[0]->GetXaxis()->SetTitle(chtitl);
    h[0]->GetXaxis()->SetMoreLogLabels();
  }

  l->Draw();

  if (plot_ratio) {

    lowerPad->cd();
    lowerPad->SetGridx();
    lowerPad->SetGridy();

    for (int kf = 1; kf<nf; ++kf) {

      TH1* hhr = (TH1*)h[kf]->Clone(TString(h[kf]->GetName())+"_ratio");
      hhr->Divide(hhr,h[0]);

      if (kf==1) {
	hhr->GetYaxis()->SetNdivisions(505);
	hhr->GetYaxis()->SetTitle("Ratio to nominal");
	hhr->GetYaxis()->SetTitleOffset(0.8);
	hhr->GetYaxis()->SetTitleSize(0.085);
	hhr->GetYaxis()->SetLabelSize(0.085);
	hhr->GetXaxis()->SetTitleSize(0.085);
	hhr->GetXaxis()->SetLabelSize(0.085);
	hhr->GetXaxis()->SetTitle(chtitl);
	hhr->GetXaxis()->SetMoreLogLabels();
	hhr->GetXaxis()->SetTickLength(0.05);
	hhr->SetMinimum(0.1);
	hhr->SetMaximum(2.5);
	hhr->Draw();
      } else {
	hhr->Draw("same");
      }

      if (dofit) {
	hhr->Fit("pol0","q0");
	TF1* fun = hhr->GetFunction("pol0");
	fun->SetLineColor(hhr->GetLineColor());
	fun->Draw("same");
	double p0 = fun->GetParameter(0);
	double e0 = fun->GetParError(0);
	TLatex* tt = new TLatex();
	tt->SetNDC();
	tt->SetTextFont(42);
	tt->SetTextSize(0.08);
	tt->DrawLatex(0.2,0.95-kf*0.1,TString::Format("p0 = %.3f #pm %.3f",p0,e0));
      }
    }
  }

  c1->Modified();

  TString sp = "tagrate_"; sp += chvar;
  for (int kf = 0; kf<nf; ++kf) {
    sp += "_"; sp += chfile[kf];
  }
  sp += ".png";
  c1->SaveAs(sp);
}
