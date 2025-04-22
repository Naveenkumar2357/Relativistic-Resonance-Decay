

#ifndef TRACK
#define TRACK

#include <Math/Vector4D.h>
#include <iostream>
#include "input.h"  


using namespace ROOT::Math;
using namespace std;

class Track {
public:

    LorentzVector<PxPyPzE4D<double>> P4_L;  // 4-momentum of Lambda
    LorentzVector<PxPyPzE4D<double>> P4_p;  // 4-momentum of proton
    LorentzVector<PxPyPzE4D<double>> P4_pi; // 4-momentum of pion

    
    double eta_L; // eta for Lambda
    double phi_p; // phi for proton/piomn
    double theta_p; //theta for proton/pion
    double invariantmass; //invarinat mass after decay



    // Constructor 
    Track() {
        // Initialize 4-momentum and angles
        P4_L.SetPxPyPzE(0, 0, 0, 0);
        P4_p.SetPxPyPzE(0, 0, 0, 0);
        P4_pi.SetPxPyPzE(0, 0, 0, 0);

        eta_L = 0;
        phi_p = 0;
        theta_p = 0;
	invariantmass= 0;
    }

   ~Track() {
   }


    //setter functions for Lambda, proton, and pion 4-momentum and angles
    void setP4_L(double px_L, double py_L, double pz_L, double E_L) {
        P4_L.SetPxPyPzE(px_L, py_L, pz_L, E_L);
    }

    void setP4_p(double px_p, double py_p, double pz_p, double E_p) {
        P4_p.SetPxPyPzE(px_p, py_p, pz_p, E_p);
    }

    void setP4_pi(double px_pi, double py_pi, double pz_pi, double E_pi) {
        P4_pi.SetPxPyPzE(px_pi, py_pi, pz_pi, E_pi);
    }
 
    void seteta_L(double eta_L_value) {
        eta_L = eta_L_value;
    }

    void setphi_p(double phi_p_value) {
        phi_p = phi_p_value;
    }

    void settheta_pi(double theta_pi_value) {
        theta_pi = theta_pi_value;
    }

    void setinvariantmass(double mass) {
    invariantmass = mass;
    }





    // Getter functions
    LorentzVector<PxPyPzE4D<double>> getP4_L() const { return P4_L; }
    LorentzVector<PxPyPzE4D<double>> getP4_p() const { return P4_p; }
    LorentzVector<PxPyPzE4D<double>> getP4_pi() const { return P4_pi; }


    double geteta_L() const { return eta_L; }
    double getphi_p() const { return phi_p; }
    double gettheta_pi() const { return theta_pi; }
    double getinvariantmass() const { return invariantmass; }





    // Print method to display the information (for debugging)
    void printInfo() const {
        cout << "Lambda 4-momentum: (" << P4_L.Px() << ", " << P4_L.Py() << ", " << P4_L.Pz() << ", " << P4_L.E() << ")\n";
        cout << "Proton 4-momentum: (" << P4_p.Px() << ", " << P4_p.Py() << ", " << P4_p.Pz() << ", " << P4_p.E() << ")\n";
        cout << "Pion 4-momentum: (" << P4_pi.Px() << ", " << P4_pi.Py() << ", " << P4_pi.Pz() << ", " << P4_pi.E() << ")\n";
        cout << "Lambda eta: " << eta_L << "\n";
        cout << "Proton_pion phi: " << phi_p << "\n";
        cout << "proton_Pion theta: " << theta_pi << "\n";
    }
};

#endif

