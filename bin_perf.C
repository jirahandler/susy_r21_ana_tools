#include "AtlasStyle.C"

void bin_perf()
{
  SetAtlasStyle();

  bool calc_eff = true;
  bool plot_ratio = false;

  int dofit = 0;

  ///

  //const char* chfile[] = {"hf_std"};
  //const char* chopt[] = {"n"};
  //const char* chname[] = {"HF non prompt"};

  const char *chfile[] = {"410470_new", "hf_1700_new_w"};
  //const char* chopt[] = {"",""};
  const char* chname[] = {"tt","HF"};

  //const char* chfile[] = {"tt","hf","hf_rew"};
  //const char* chopt[] = {"p","n","n"};
  //const char* chname[] = {"tt","HF","HF rew"};

  //const char* chfile[] = {"tt_std","hf_std","hf_sim"};
  //const char* chopt[] = {"p","n","n"};
  //const char* chname[] = {"tt","HF non-prompt","HF non-prompt fit"};

  const int icol[] = {2,4,8,1,6,5};

  ///

  const char* chvar = "ntr_lxy";
  const char* chtitl = "Lxy [mm]";
  bool logx = true, logy = false;
  double ymin = 0, ymax = 1.1;
  double xleg = 0.2, yleg = 0.7;
  const int iy1 = 6, iy2 = 15;

  const int nf = sizeof(chfile)/sizeof(const char*);
  const int ix1 = 1, ix2 = 20;

  const int nx = ix2-ix1+1;
  TH1* h[nf*nx];

  for (int kf = 0; kf<nf; ++kf) {
    TFile* ff = new TFile(TString("a1_")+chfile[kf]+".root");
    TH2* hall = (TH2*)ff->Get(TString(chvar)+"_all");
    TH2* htag = 0;
    if (calc_eff) htag = (TH2*)ff->Get(TString(chvar)+"_tag");
    for (int ix = ix1; ix<=ix2; ++ix ) {
      int ih = kf*nx+ix-ix1;
      h[ih] = hall->ProjectionY(TString("all_")+ih,ix,ix);
      if (calc_eff) {
	TH1* htag1 = htag->ProjectionY(TString("tag_")+ih,ix,ix);
	h[ih]->Divide(htag1,h[ih],1.,1.,"B");
      } else {
	h[ih]->Scale(1./h[ih]->GetEntries());
      }
      h[ih]->GetXaxis()->SetRange(iy1,iy2);
    }
  }

  // Draw plots

  int ic = 0;
  for (int ix = ix1; ix<=ix2; ++ix ) {

    TCanvas* c1;
    TString sc = TString("c")+(++ic);

    TPad *lowerPad, *upperPad;

    if (plot_ratio) {
      c1 = new TCanvas(sc,sc,700,800);
      lowerPad = new TPad("cl","",0,0,1.,0.375);
      upperPad = new TPad("cu","",0,0.375,1.,1.);
      if (logx) upperPad->SetLogx();
      if (logx) lowerPad->SetLogx();
      if (logy) upperPad->SetLogy();
      lowerPad->Draw();
      upperPad->Draw();

      upperPad->cd();
      upperPad->SetGridx();
      upperPad->SetGridy();

      lowerPad->SetTopMargin(0.03);
      lowerPad->SetBottomMargin(0.29);
    } else {
      c1 = new TCanvas(sc,sc,700,500);
      c1->SetGridx();
      c1->SetGridy();
      if (logx) c1->SetLogx();
      if (logy) c1->SetLogy();
    }

    TLegend* l = new TLegend(xleg,yleg,xleg+0.5,yleg+0.05*(nf+1));
    l->SetMargin(0.2);
    l->SetBorderSize(0);
    l->SetFillStyle(0);
    l->SetTextFont(42);

    for (int kf = 0; kf<nf; ++kf) {
      int ih0 = kf*nx, ih = ih0+ix-ix1;
      h[ih]->SetMarkerStyle(8);
      h[ih]->SetMarkerSize(1.2);
      h[ih]->SetMarkerColor(icol[kf]);
      h[ih]->SetLineColor(icol[kf]);
      if (calc_eff) {
	if (kf==0) {
	  h[ih]->GetYaxis()->SetTitle("Tagging efficiency");
	  h[ih]->SetMinimum(ymin);
	  h[ih]->SetMaximum(ymax);
	  h[ih]->Draw("e0");
	} else {
	  h[ih]->Draw("e0same");
	}
      } else {
	h[ih]->SetLineWidth(3);
	if (kf==0) {
	  h[ih]->GetYaxis()->SetTitle("Arbitrary units");
	  h[ih]->GetYaxis()->SetNdivisions(505);
	  h[ih]->SetMinimum(ymin);
	  ymax = h[ih]->GetMaximum();
	  h[ih]->Draw("hist");
	} else {
	  h[ih]->Draw("histsame");
	  if (ymax<h[ih]->GetMaximum()) ymax = h[ih]->GetMaximum();
	}
      }
      l->AddEntry(h[ih],chname[kf],"l");
    }
    if (!calc_eff) h[ix-ix1]->SetMaximum(1.1*ymax);

    if (plot_ratio) {
      h[ix-ix1]->GetXaxis()->SetLabelSize(0);
      h[ix-ix1]->GetXaxis()->SetTitleSize(0);
    } else {
      h[ix-ix1]->GetXaxis()->SetTitle(chtitl);
      //h[ix-ix1]->GetXaxis()->SetMoreLogLabels();
    }

    l->Draw();

    if (plot_ratio) {

      lowerPad->cd();
      lowerPad->SetGridx();
      lowerPad->SetGridy();

      for (int kf = 1; kf<nf; ++kf) {
	int ih0 = kf*nx, ih = ih0+ix-ix1;

	TH1* hhr = (TH1*)h[ih]->Clone(TString(h[ih]->GetName())+"_ratio");
	hhr->Divide(hhr,h[ih0]);

	if (kf==1) {
	  hhr->GetYaxis()->SetNdivisions(505);
	  hhr->GetYaxis()->SetTitle("Ratio to nominal");
	  hhr->GetYaxis()->SetTitleOffset(0.8);
	  hhr->GetYaxis()->SetTitleSize(0.085);
	  hhr->GetYaxis()->SetLabelSize(0.085);
	  hhr->GetXaxis()->SetTitleSize(0.085);
	  hhr->GetXaxis()->SetLabelSize(0.085);
	  hhr->GetXaxis()->SetTitle(chtitl);
	  //hhr->GetXaxis()->SetMoreLogLabels();
	  hhr->GetXaxis()->SetTickLength(0.05);
	  hhr->SetMinimum(0.);
	  hhr->SetMaximum(1.9);
	  hhr->Draw();
	} else {
	  hhr->Draw("same");
	}

	if (dofit) {

	  TString sfun = "pol0";

	  //TString sfun = "fitfun"; sfun += kf;
	  //TF1* fitfun = new TF1(sfun,"1++log(x)++log(x)*log(x)",20.,200.);

	  hhr->Fit(sfun,"q0");
	  TF1* fun = hhr->GetFunction(sfun);
	  fun->SetLineColor(hhr->GetLineColor());
	  fun->Draw("same");
	  if (dofit&1) {
	    double p0 = fun->GetParameter(0);
	    double e0 = fun->GetParError(0);
	    TLatex* tt = new TLatex();
	    tt->SetNDC();
	    tt->SetTextFont(42);
	    tt->SetTextSize(0.08);
	    tt->DrawLatex(0.2,0.95-kf*0.1,TString::Format("p0 = %.3f #pm %.3f",p0,e0));
	  }
	  if (dofit&2) {
	    TFile* fout = new TFile("fitfun.root","RECREATE");
	    fun->Write();
	    fout->Close();
	  }
	}
      }
    }

    c1->Modified();

    TString sp = "relaxedipcut_modified_tagrate";
    for (int kf = 0; kf<nf; ++kf) {
      sp += "_"; sp += chfile[kf];
    }
    sp += "_"; sp += ix;
    sp += ".pdf";
    c1->Print(sp);
  }
}
