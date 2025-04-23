#ifndef TRACK
#define TRACK

#include <Math/Vector4D.h>
#include <iostream>
#include "inputfile.h"  

using namespace ROOT::Math;
using namespace std;

class Track {
public:

    LorentzVector<PxPyPzM4D<double>> P4_L;
    LorentzVector<PxPyPzM4D<double>> P4_p;
    LorentzVector<PxPyPzM4D<double>> P4_pi;

    double eta_L;
    double phi_L;
    double phi_p;
    double theta_p;
    double invariantmass;
    double pt_L;

    Track() {
      

        eta_L = 0;
	pt_L= 0;
	phi_L=0;
        phi_p = 0;
        theta_p = 0;
        invariantmass = 0;
    }

    ~Track() {}
 
    void setP4_L(double px_L, double py_L, double pz_L, double mass_L) {
    P4_L.SetPx(px_L);
    P4_L.SetPy(py_L);
    P4_L.SetPz(pz_L);
    P4_L.SetM(mass_L);
    }   

    void setP4_p(double px_p, double py_p, double pz_p, double mass_p) {
    P4_p.SetPx(px_p);
    P4_p.SetPy(py_p);
    P4_p.SetPz(pz_p);
    P4_p.SetM(mass_p);
    } 

    void setP4_pi(double px_pi, double py_pi, double pz_pi, double mass_pi) {
    P4_pi.SetPx(px_pi);
    P4_pi.SetPy(py_pi);
    P4_pi.SetPz(pz_pi);
    P4_pi.SetM(mass_pi);
    }





    void seteta_L(double eta_L_value) {
        eta_L = eta_L_value;
    }
    void setphi_L(double phi_L_value) {
        phi_L = phi_L_value;
    }
    void setpt_L(double pt_L_value) {
        pt_L = pt_L_value;
    }



    void setphi_p(double phi_p_value) {
        phi_p = phi_p_value;
    }
    void settheta_p(double theta_pi_value) {
        theta_p = theta_pi_value;
    }
    void setinvariantmass(double mass) {
        invariantmass = mass;
    }

    LorentzVector<PxPyPzM4D<double>> getP4_L() const { return P4_L; }
    LorentzVector<PxPyPzM4D<double>> getP4_p() const { return P4_p; }
    LorentzVector<PxPyPzM4D<double>> getP4_pi() const { return P4_pi; }

    double geteta_L() const { return eta_L; }
    double getphi_L() const { return phi_L; }
    double getpt_L() const { return  pt_L; }
    double getphi_p() const { return phi_p; }
    double gettheta_p() const { return theta_p; }
    double getinvariantmass() const { return invariantmass; }

    void print_track() const {
        cout << "Lambda 4-momentum: (" << P4_L.Px() << ", " << P4_L.Py() << ", " << P4_L.Pz() << ", " << P4_L.M() << ")\n";
        cout << "Proton 4-momentum: (" << P4_p.Px() << ", " << P4_p.Py() << ", " << P4_p.Pz() << ", " << P4_p.M() << ")\n";
        cout << "Pion 4-momentum: (" << P4_pi.Px() << ", " << P4_pi.Py() << ", " << P4_pi.Pz() << ", " << P4_pi.M() << ")\n";
	cout << "Lambda transverse momentum: "<< pt_L << "\n";
        cout << "Lambda eta: " << eta_L << "\n";
	cout << "Lambda phi: " << phi_L << "\n";
        cout << "Proton/pion phi: " << phi_p << "\n";
        cout << "Proton/pion theta: " << theta_p << "\n";
    }
};

#endif

