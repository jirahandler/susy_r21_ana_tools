/**
 * @file a.C
 * @author SammyG
 * @brief Skeleton C++ code/script; make your own changes
 * @version 0.1
 * @date 2023-04-16
 */
#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include "TF1.h"
#include "TCanvas.h"
#include "d.h"

int a()
{
    std::string path = ".";
    for (const auto &entry : std::filesystem::directory_iterator(path))
        std::cout << entry.path() << std::endl;
    /**
     * std::string hf[] = {
            "hf_all/user.sgoswami .503822.6224.MGPy8EG.FTAG1..PFlow_newTagger_TRK_RES_D0_MEAS_negTag_Extrapol_Akt4EMPf_BTagging201810",
            "hf_all/user.sgoswami .503822.6644.MGPy8EG.FTAG1..PFlow_newTagger_TRK_RES_D0_MEAS_negTag_Extrapol_Akt4EMPf_BTagging201810",
            "hf_all/user.sgoswami .503822.6826.MGPy8EG.FTAG1..PFlow_newTagger_TRK_RES_D0_MEAS_negTag_Extrapol_Akt4EMPf_BTagging201810",
            "hf_all/user.sgoswami .503823.3597.MGPy8EG.FTAG1..PFlow_newTagger_TRK_RES_D0_MEAS_negTag_Extrapol_Akt4EMPf_BTagging201810",
            "hf_all/user.sgoswami .503823.8650.MGPy8EG.FTAG1..PFlow_newTagger_TRK_RES_D0_MEAS_negTag_Extrapol_Akt4EMPf_BTagging201810",
            "hf_all/user.sgoswami .503823.9702.MGPy8EG.FTAG1..PFlow_newTagger_TRK_RES_D0_MEAS_negTag_Extrapol_Akt4EMPf_BTagging201810",
            "hf_all/user.sgoswami .503824.1943.MGPy8EG.FTAG1..PFlow_newTagger_TRK_RES_D0_MEAS_negTag_Extrapol_Akt4EMPf_BTagging201810",
            "hf_all/user.sgoswami .503824.8615.MGPy8EG.FTAG1..PFlow_newTagger_TRK_RES_D0_MEAS_negTag_Extrapol_Akt4EMPf_BTagging201810",
            "hf_all/user.sgoswami .503824.9423.MGPy8EG.FTAG1..PFlow_newTagger_TRK_RES_D0_MEAS_negTag_Extrapol_Akt4EMPf_BTagging201810",
            "hf_all/user.sgoswami .503825.1389.MGPy8EG.FTAG1..PFlow_newTagger_TRK_RES_D0_MEAS_negTag_Extrapol_Akt4EMPf_BTagging201810",
            "hf_all/user.sgoswami .503825.6548.MGPy8EG.FTAG1..PFlow_newTagger_TRK_RES_D0_MEAS_negTag_Extrapol_Akt4EMPf_BTagging201810",
            "hf_all/user.sgoswami .503825.6554.MGPy8EG.FTAG1..PFlow_newTagger_TRK_RES_D0_MEAS_negTag_Extrapol_Akt4EMPf_BTagging201810"
        };
     * std::string lf[] = {
        "lf_all/user.sgoswami .503767.10517.MGPy8EG.FTAG1..PFlow_newTagger_TRK_RES_D0_MEAS_negTag_Extrapol_Akt4EMPf_BTagging201810",
        "lf_all/user.sgoswami .503767.10520.MGPy8EG.FTAG1..PFlow_newTagger_TRK_RES_D0_MEAS_negTag_Extrapol_Akt4EMPf_BTagging201810",
        "lf_all/user.sgoswami .503767.4377.MGPy8EG.FTAG1..PFlow_newTagger_TRK_RES_D0_MEAS_negTag_Extrapol_Akt4EMPf_BTagging201810",
        "lf_all/user.sgoswami .503768.10990.MGPy8EG.FTAG1..PFlow_newTagger_TRK_RES_D0_MEAS_negTag_Extrapol_Akt4EMPf_BTagging201810",
        "lf_all/user.sgoswami .503768.8006.MGPy8EG.FTAG1..PFlow_newTagger_TRK_RES_D0_MEAS_negTag_Extrapol_Akt4EMPf_BTagging201810",
        "lf_all/user.sgoswami .503768.8462.MGPy8EG.FTAG1..PFlow_newTagger_TRK_RES_D0_MEAS_negTag_Extrapol_Akt4EMPf_BTagging201810",
        "lf_all/user.sgoswami .503769.10978.MGPy8EG.FTAG1..PFlow_newTagger_TRK_RES_D0_MEAS_negTag_Extrapol_Akt4EMPf_BTagging201810",
        "lf_all/user.sgoswami .503769.5853.MGPy8EG.FTAG1..PFlow_newTagger_TRK_RES_D0_MEAS_negTag_Extrapol_Akt4EMPf_BTagging201810",
        "lf_all/user.sgoswami .503769.7090.MGPy8EG.FTAG1..PFlow_newTagger_TRK_RES_D0_MEAS_negTag_Extrapol_Akt4EMPf_BTagging201810",
        "lf_all/user.sgoswami .503770.1507.MGPy8EG.FTAG1..PFlow_newTagger_TRK_RES_D0_MEAS_negTag_Extrapol_Akt4EMPf_BTagging201810",
        "lf_all/user.sgoswami .503770.3769.MGPy8EG.FTAG1..PFlow_newTagger_TRK_RES_D0_MEAS_negTag_Extrapol_Akt4EMPf_BTagging201810",
        "lf_all/user.sgoswami .503770.4380.MGPy8EG.FTAG1..PFlow_newTagger_TRK_RES_D0_MEAS_negTag_Extrapol_Akt4EMPf_BTagging201810",
        "lf_all/user.sgoswami .503771.1838.MGPy8EG.FTAG1..PFlow_newTagger_TRK_RES_D0_MEAS_negTag_Extrapol_Akt4EMPf_BTagging201810",
        "lf_all/user.sgoswami .503771.7483.MGPy8EG.FTAG1..PFlow_newTagger_TRK_RES_D0_MEAS_negTag_Extrapol_Akt4EMPf_BTagging201810",
        "lf_all/user.sgoswami .503771.9289.MGPy8EG.FTAG1..PFlow_newTagger_TRK_RES_D0_MEAS_negTag_Extrapol_Akt4EMPf_BTagging201810"
        };
     *
     */

    std::string hf[] = {"5038822.root",
                              "503823.root",
                              "503824.root",
                              "503825.root"};

    std::string lf[] = {"503767",
                              "503768.root",
                              "503769.root",
                              "503770.root",
                              "503771.root"};
    auto c1 = new TCanvas("c1", "Candle Decay", 800, 600);
    TF1 f1("f1", "sin(x)/x", 0., 10.);
    f1.Draw("c1");
    c1->SaveAs("myfile.png");
    return 0;
}
