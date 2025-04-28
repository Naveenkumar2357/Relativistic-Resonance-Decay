#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TCanvas.h>
#include <TAxis.h>
#include <TRandom3.h>
#include <iostream>

void plotKinematicDistribution() {
    std::cout << "Opening ROOT file..." << std::endl;
    TFile *file = TFile::Open("output_lambdaMass_1115.683000_events_2000.root");

    if (!file || file->IsOpen() == kFALSE) {
        std::cerr << "Error: ROOT file could not be opened!" << std::endl;
        return;
    }
    std::cout << "ROOT file opened successfully." << std::endl;

    TTree *tree;
    file->GetObject("events_1115.683000_2000", tree);

    if (!tree) {
        std::cerr << "Error: Tree 'events_1115.683000_2000' not found in the ROOT file!" << std::endl;
        file->Close();
        return;
    }
    std::cout << "Tree 'events_1115.683000_2000' found successfully." << std::endl;

    Double_t invariantmass;
    tree->SetBranchAddress("kinematics_L", &kinematics_L);
    std::cout << "Branch 'kinematics_L' connected successfully." << std::endl;

    TH1F *hist1 = new TH1F("histKinematicsEta", "Eta Distribution", 100, 0.0, 4.0);
    std::cout << "Histogram 1 created." << std::endl;
	
	TH1F *hist2 = new TH1F("histKinematicsPhi", "Phi Distribution", 100, 0.0, 7.0);
    std::cout << "Histogram 2 created." << std::endl;

    Long64_t nEntries = tree->GetEntries();
    std::cout << "Number of entries in the tree: " << nEntries << std::endl;

    for (Long64_t i = 0; i < nEntries; ++i) {
        tree->GetEntry(i);

        hist1->Fill(eta_L);
		hist2->Fill(phi_L);

    }

    std::cout << "Finished filling the histograms." << std::endl;

    TCanvas *canvas1 = new TCanvas("canvas1", "Eta Dist. Histogram", 800, 600);
    std::cout << "Canvas created." << std::endl;

    hist->GetXaxis()->SetTitle("Eta");
    hist->GetYaxis()->SetTitle("Counts");
    hist->Draw();

    canvas->SaveAs("2000_eta.png");
    std::cout << "Histogram saved as 2000_eta.png." << std::endl;
	
	TCanvas *canvas2 = new TCanvas("canvas2", "Phi Dist. Histogram", 800, 600);
    std::cout << "Canvas created." << std::endl;

    hist->GetXaxis()->SetTitle("Phi");
    hist->GetYaxis()->SetTitle("Counts");
    hist->Draw();

    canvas->SaveAs("2000_eta.png");
    std::cout << "Histogram saved as 2000_phi.png." << std::endl;

    delete canvas;
    delete hist;
    file->Close();
    std::cout << "Memory cleaned and file closed." << std::endl;
}

int main() {
    plotKinematicDistribution();
    return 0;
}

