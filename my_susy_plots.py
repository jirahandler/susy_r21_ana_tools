"""
 # @file my_susy_plots.py
 # @author SammyG
 # @brief Get SUSY perf plots, but using pyroot
 # @version 0.2
 # @date 2023-06-04
 """
import ROOT
from ROOT import TFile, TH1, TCanvas, TPad, TLegend, TMath, TF1, TLatex

def main():
    ROOT.gROOT.SetStyle("ATLAS")
    # define plot types here
    # must match the partial names of histos found in a1_<dsid>.root
    plot_type = [ "ntrk"]

    plot_title = [ "number of tracks"]

    plctrsz = len(plot_type)
    for plctr in range(plctrsz):

        btag = True
        dofit = True
        plot_ratio = True

        if plctr == 0:
            btag = False
            dofit = False
            plot_ratio = False

        chvar = plot_type[plctr]
        chtitl = plot_title[plctr]

        filelist = [
            "503822",
            "503823",
            "503824",
            "503825",
            "410470",
            "410470",
            "410470",
            "410470",
        ]

        fctr = int(len(filelist) / 2)
        for fpctr in range(fctr):
            chfile = [filelist[fpctr], filelist[fpctr + 4]]
            nf = len(chfile)
            h = []
            hall = []
            icol = [1, 2, 4, 3, 6, 51]

            # Loop over files
            for kf in range(nf):
                ff = TFile("a1_" + chfile[kf] + ".root", "READ")
                ROOT.TH1.AddDirectory(0)
                if plctr != 0:
                    hall_temp = ff.Get(chvar + "_all")
                    hall.append(hall_temp)
                    h_temp = ff.Get(chvar + "_tag")
                    h.append(h_temp)
                    if not hall or not h[kf]:
                        continue
                    else:
                        h[kf].Divide(h[kf], hall, 1., 1., "B")
                if plctr == 0:
                    print("chvar is:", chvar)
                    h_temp = ff.Get(chvar)
                    h.append(h_temp)
                    if not h[kf]:
                        print("Histogram is empty")
                        continue
                    else:
                        print("Histogram is not empty")
                ff.Close()
            # Draw plots

            for kf in range(nf):
                if plctr != 0:
                    if (not hall[kf]) or (not h[kf]):
                        print("Entered forbidden loop.")
                        continue
                    h[kf].Divide(h[kf], hall[kf], 1.0, 1.0, "B")

            if plot_ratio:
                c1 = TCanvas("c1", "c1", 700, 800)
                lowerPad = TPad("cl", "", 0, 0, 1., 0.375)
                upperPad = TPad("cu", "", 0, 0.375, 1., 1.)
                if plctr != 0:
                    upperPad.SetLogx()
                    lowerPad.SetLogx()
                if not btag:
                    if plctr != 0:
                        upperPad.SetLogy()
                lowerPad.Draw()
                upperPad.Draw()

                upperPad.cd()
                upperPad.SetGridx()
                upperPad.SetGridy()

                lowerPad.SetTopMargin(0.03)
                lowerPad.SetBottomMargin(0.29)
            else:
                c1 = TCanvas("c1", "c1", 700, 500)
                c1.SetGridx()
                c1.SetGridy()
                if plctr != 0:
                    c1.SetLogx()

            l = TLegend(0.7, 0.2, 0.85, 0.35)
            l.SetMargin(0.2)
            l.SetBorderSize(0)
            l.SetFillStyle(0)
            l.SetTextFont(42)

            for kf in range(nf):
                # Put empty histo safeguard
                if plctr != 0:
                    if not h[kf]:
                        continue

                h[kf].SetMarkerStyle(8)
                h[kf].SetMarkerSize(1.2)
                h[kf].SetMarkerColor(icol[kf])
                h[kf].SetLineColor(icol[kf])

                if plctr == 0:
                    maxBinContent = TMath.Max(h[0].GetMaximum(), h[1].GetMaximum())

                    scalingFactor1 = maxBinContent / h[0].GetMaximum()
                    scalingFactor2 = maxBinContent / h[1].GetMaximum()

                    h[0].Scale(scalingFactor1)
                    h[1].Scale(scalingFactor2)

                if kf == 0:
                    if plctr != 0:
                        h[kf].GetYaxis().SetTitle("Tagging efficiency")
                    if plctr == 0:
                        h[kf].GetYaxis().SetTitle("Number of entries")
                    if btag:
                        h[kf].SetMinimum(0)
                        h[kf].SetMaximum(1.1)
                    else:
                        if plctr != 0:
                            h[kf].SetMinimum(1e-4)
                            h[kf].SetMaximum(1)
                        if plctr == 0:
                            h[kf].SetMinimum(0)
                            # h[kf]->SetMaximum(4e6);
                    if plctr != 0:
                        h[kf].Draw("e0")
                    if plctr == 0:
                        h[kf].Draw("H")
                else:
                    if plctr != 0:
                        h[kf].Draw("e0same")
                    if plctr == 0:
                        h[kf].Draw("H same")
                l.AddEntry(h[kf], chfile[kf], "l")

            if plot_ratio:
                h[0].GetXaxis().SetLabelSize(0)
                h[0].GetXaxis().SetTitleSize(0)
            else:
                h[0].GetXaxis().SetTitle(chtitl)
                if plctr != 0:
                    h[0].GetXaxis().SetMoreLogLabels()

            l.Draw()

            if plot_ratio:

                lowerPad.cd()
                lowerPad.SetGridx()
                lowerPad.SetGridy()

                for kf in range(1, nf):
                    if not h[kf]:
                        continue
                    hhr = TH1(h[kf].Clone(h[kf].GetName() + "_ratio"))
                    hhr.Divide(hhr, h[0])

                    if kf == 1:
                        hhr.GetYaxis().SetNdivisions(505)
                        hhr.GetYaxis().SetTitle("Ratio to nominal")
                        hhr.GetYaxis().SetTitleOffset(0.8)
                        hhr.GetYaxis().SetTitleSize(0.085)
                        hhr.GetYaxis().SetLabelSize(0.085)
                        hhr.GetXaxis().SetTitleSize(0.085)
                        hhr.GetXaxis().SetLabelSize(0.085)
                        hhr.GetXaxis().SetTitle(chtitl)
                        if plctr != 0:
                            hhr.GetXaxis().SetMoreLogLabels()
                        hhr.GetXaxis().SetTickLength(0.05)
                        hhr.SetMinimum(0.1)
                        hhr.SetMaximum(2.5)
                        hhr.Draw()
                    else:
                        hhr.Draw("same")

                    if dofit:
                        hhr.Fit("pol0", "q0")
                        fun = hhr.GetFunction("pol0")
                        fun.SetLineColor(hhr.GetLineColor())
                        fun.Draw("same")
                        p0 = fun.GetParameter(0)
                        e0 = fun.GetParError(0)
                        tt = TLatex()
                        tt.SetNDC()
                        tt.SetTextFont(42)
                        tt.SetTextSize(0.08)
                        tt.DrawLatex(0.2, 0.95 - kf * 0.1, "p0 = %.3f #pm %.3f" % (p0, e0))

            c1.Modified()

            sp = "tagrate_"
            sp += chvar
            for kf in range(nf):
                sp += "_"
                sp += chfile[kf]
            sp += ".png"
            c1.SaveAs(sp)
            del c1

if __name__ == "__main__":
    main()
