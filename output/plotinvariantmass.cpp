#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TCanvas.h>
#include <TAxis.h>
#include <TRandom3.h>
#include <iostream>

void plotInvariantMassHistogram() {
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
    tree->SetBranchAddress("invariantmass", &invariantmass);
    std::cout << "Branch 'invariantmass' connected successfully." << std::endl;

    TH1F *hist = new TH1F("histInvariantMass", "Invariant Mass Distribution (Gaussian Smeared)", 100, 1115.66, 1115.70);
    std::cout << "Histogram created." << std::endl;

    Long64_t nEntries = tree->GetEntries();
    std::cout << "Number of entries in the tree: " << nEntries << std::endl;

    TRandom3 randGen(0); // Seed 0 for random seed
    double sigma = 0.002; // Smearing width (in MeV)

    for (Long64_t i = 0; i < nEntries; ++i) {
        tree->GetEntry(i);

        // Apply Gaussian smearing
        double smearedMass = randGen.Gaus(invariantmass, sigma);

        hist->Fill(smearedMass);

        std::cout << "invariantmass[" << i << "] = " << invariantmass
                  << ", smeared = " << smearedMass << std::endl;
    }

    std::cout << "Finished filling the histogram." << std::endl;

    TCanvas *canvas = new TCanvas("canvas", "Invariant Mass Histogram", 800, 600);
    std::cout << "Canvas created." << std::endl;

    hist->GetXaxis()->SetTitle("Invariant Mass (MeV/c^{2})");
    hist->GetYaxis()->SetTitle("Counts");
    hist->Draw();

    canvas->SaveAs("2000_invariant_mass_histogram.png");
    std::cout << "Histogram saved as invariant_mass_histogram.png." << std::endl;

    delete canvas;
    delete hist;
    file->Close();
    std::cout << "Memory cleaned and file closed." << std::endl;
}

int main() {
    plotInvariantMassHistogram();
    return 0;
}

