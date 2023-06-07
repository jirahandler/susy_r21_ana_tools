"""
 # @file my_susy_plots.py
 # @author SammyG
 # @brief Get SUSY perf plots, but using pyroot
 # @version 0.2
 # @date 2023-06-04
 """
import ROOT


def main():
    ROOT.gROOT.SetStyle("ATLAS")

    plot_type = [
        "lxy",
        "bip",
        "jetpt_2",
        "ntrk",
    ]

    plot_title = [
        "Lxy [mm]",
        "b-impact parameter [mm]",
        "b-jet p_{T} [GeV]",
        "number of tracks",
    ]

    filelist = [
        "hfall",
        "503822",
        "503823",
        "503824",
        "503825",
        "410470",
        "410470",
        "410470",
        "410470",
        "410470",
    ]

    plctrsz = len(plot_type)

    for plctr in range(plctrsz):
        btag = True  # False
        dofit = True  # False
        plot_ratio = True
        """
        if plctr == 0 or plctr == 1:
            btag = True
        if plctr == 0 or plctr == 1:
            dofit = True
        """
        if plctr == 3:
            btag = False
        chvar = plot_type[plctr]
        print(chvar)
        chtitl = plot_title[plctr]
        print(chtitl)
        fctr = len(filelist) // 2

        for fpctr in range(fctr):
            # if plctr == 5 and fpctr == 3:
            #    continue

            chfile = [filelist[fpctr], filelist[fpctr + 5]]
            nf = len(chfile)
            print(nf)
            h = []
            hall = []
            icol = [1, 2, 4, 3, 6, 51]

            for kf in range(nf):
                print(f"a1_{chfile[kf]}.root")
                ff = ROOT.TFile(f"a1_{chfile[kf]}.root", "open")
                ROOT.TH1.AddDirectory(0)
                if plctr != 3:
                    print(f"{chvar}_all")
                    hall_temp = ff.Get(f"{chvar}_all")
                    hall.append(hall_temp)
                    print(f"{chvar}_tag")
                    h_temp = ff.Get(f"{chvar}_tag")
                    h.append(h_temp)
                if plctr == 3:
                    print(f"{chvar}")
                    h_temp = ff.Get(f"{chvar}")
                    h.append(h_temp)

                # hall.SetDirectory(gROOT)

                ff.Close()
            for kf in range(nf):
                if plctr != 3:
                    if (not hall[kf]) or (not h[kf]):
                        print("Entered forbidden loop.")
                        continue
                    h[kf].Divide(h[kf], hall[kf], 1.0, 1.0, "B")
                

            if plot_ratio:
                c1 = ROOT.TCanvas("c1", "c1", 700, 800)
                lowerPad = ROOT.TPad("cl", "", 0, 0, 1.0, 0.375)
                upperPad = ROOT.TPad("cu", "", 0, 0.375, 1.0, 1.0)
                upperPad.SetLogx()
                lowerPad.SetLogx()
                if not btag:
                    upperPad.SetLogy()
                lowerPad.Draw()
                upperPad.Draw()

                upperPad.cd()
                upperPad.SetGridx()
                upperPad.SetGridy()

                lowerPad.SetTopMargin(0.03)
                lowerPad.SetBottomMargin(0.29)
            else:
                c1 = ROOT.TCanvas("c1", "c1", 700, 500)
                c1.SetGridx()
                c1.SetGridy()
                c1.SetLogx()

            l = ROOT.TLegend(0.7, 0.2, 0.85, 0.35)
            l.SetMargin(0.2)
            l.SetBorderSize(0)
            l.SetFillStyle(0)
            l.SetTextFont(42)

            for kf in range(nf):
                if not h[kf]:
                    print("Entered forbidden loop.")
                    continue

                h[kf].SetMarkerStyle(8)
                h[kf].SetMarkerSize(1.2)
                h[kf].SetMarkerColor(icol[kf])
                h[kf].SetLineColor(icol[kf])
                if kf == 0:
                    if (plctr!=3):
                        h[kf].GetYaxis().SetTitle("Tagging efficiency")
                    if (plctr==3):
                        h[kf].GetYaxis().SetTitle("Number of tracks")
                    if btag:
                        h[kf].SetMinimum(0)
                        h[kf].SetMaximum(1.1)
                    else:
                        h[kf].SetMinimum(1e-4)
                        h[kf].SetMaximum(1)
                    h[kf].Draw("e0")
                else:
                    h[kf].Draw("e0same")
                l.AddEntry(h[kf], chfile[kf], "l")

            if plot_ratio:
                h[0].GetXaxis().SetLabelSize(0)
                h[0].GetXaxis().SetTitleSize(0)
            else:
                h[0].GetXaxis().SetTitle(chtitl)
                h[0].GetXaxis().SetMoreLogLabels()

            l.Draw()

            if plot_ratio:
                lowerPad.cd()
                lowerPad.SetGridx()
                lowerPad.SetGridy()

                for kf in range(1, nf):
                    if not h[kf]:
                        continue
                    hhr = h[kf].Clone(f"{h[kf].GetName()}_ratio")
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
                        tt = ROOT.TLatex()
                        tt.SetNDC()
                        tt.SetTextFont(42)
                        tt.SetTextSize(0.08)
                        tt.DrawLatex(0.2, 0.95 - kf * 0.1, f"p0 = {p0:.3f}\pm{e0:.3f}")

            c1.Modified()

            sp = "tagrate_" + chvar
            for kf in range(nf):
                sp += "_" + chfile[kf]
            sp += ".png"
            c1.SaveAs(sp)
            del c1


if __name__ == "__main__":
    main()
