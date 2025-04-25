#include "event_generator.h"
#include "inputfile.h"
#include "TFile.h"
#include "TTree.h"
#include <string>
#include <iostream>

using namespace std;
using namespace ROOT::Math;

int main() {
    eventgenerator generator;

    // Ttree naming
    string treename = "events_" + to_string(lambdamass) + "_" + to_string(N);  // std string naming
    TTree *tree = new TTree(treename.c_str(), "");                             // changing to C string naming

    string filename = "/home/naveenkumar/Desktop/courses/comp/Relativistic-Resonance-Decay/output/output_lambdaMass_" + to_string(lambdamass) + "_events_" + to_string(N) + ".root";
    TFile *file = new TFile(filename.c_str(), "RECREATE");

    // Variables to be stored in tree structure
    double px_L, py_L, pz_L, M_L;
    double px_p, py_p, pz_p, M_p;
    double px_pi, py_pi, pz_pi, M_pi;

    double eta_L, pt_L, phi_L;
    double theta_p, phi_p;
    double invariantmass;

    // Set branches
    tree->Branch("P4_L", &px_L, "px_L/D:py_L/D:pz_L/D:M_L/D");
    tree->Branch("P4_p", &px_p, "px_p/D:py_p/D:pz_p/D:M_p/D");
    tree->Branch("P4_pi", &px_pi, "px_pi/D:py_pi/D:pz_pi/D:M_pi/D");

    tree->Branch("kinematics_L", &eta_L, "eta_L/D:pt_L/D:phi_L/D");
    tree->Branch("angles_p", &theta_p, "theta_p/D:phi_p/D");
    tree->Branch("invariantmass", &invariantmass, "invariantmass/D");

    // Generate N events
    cout<< "Generating " << N<<" "<<"events "<<endl;
    cout<< "Results are being stored in directory output"<<endl;

    for (int i = 0; i < N; ++i) {
        generator.generate_event();
        Track track = generator.getTrack();

        // Extract values
        auto P4L = track.getP4_L();
        auto P4p = track.getP4_p();
        auto P4pi = track.getP4_pi();

        px_L = P4L.Px(); py_L = P4L.Py(); pz_L = P4L.Pz(); M_L = P4L.M();
        px_p = P4p.Px(); py_p = P4p.Py(); pz_p = P4p.Pz(); M_p = P4p.M();
        px_pi = P4pi.Px(); py_pi = P4pi.Py(); pz_pi = P4pi.Pz(); M_pi = P4pi.M();

        eta_L = track.geteta_L();
        pt_L = track.getpt_L();
        phi_L = track.getphi_L();
        theta_p = track.gettheta_p(); 
        phi_p = track.getphi_p();

        invariantmass = track.getinvariantmass();

        tree->Fill();

	 
         cout << "Event " <<i+1<<" stored in tree: " << treename << endl;

//	 track.print_track();

    }

    // Save tree to file
    tree->Write();
    file->Close();
    
       return 0;
}

