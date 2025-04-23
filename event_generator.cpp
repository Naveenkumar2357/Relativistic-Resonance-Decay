#include "event_generator.h"
#include "inputfile.h"
#include <cmath>


//constructor and destructor
eventgenerator::eventgenerator() {
    mineta = etamin;
    maxeta = etamax;
    random_sampling.SetSeed(time(0));
}


eventgenerator::~eventgenerator() {}


//memberfunction
//random sampling // eta, pt, and phi for Lambda
void eventgenerator::generate_event() {

    double m_lambda = lambdamass;  // Lambda, proton, pion mass read from headerinputfile and stored in dummy variable 
    double m_proton = protonmass;  
    double m_pion = pionmass;      


    
    double eta_L = random_sampling.Uniform(mineta, maxeta);
    double pt_L = random_sampling.Uniform(ptmin, ptmax);
    double phi_L = random_sampling.Uniform(0, 2 * M_PI);

    double pz_L = pt_L * sinh(eta_L);    // eta is psueedo rapidity
    double px_L = pt_L * cos(phi_L);
    double py_L = pt_L * sin(phi_L);

    // object track created and all information is being stored
    track.setP4_L(px_L, py_L, pz_L, m_lambda);
    track.seteta_L(eta_L);
    track.setphi_L(phi_L);
    track.setpt_L(pt_L);


      // formula to find the 3 momentum of decaying particles in lambda's rest frame(eta_L , phi_L)
      // P_p = - P_pi = p3_magnitude 
    double p3_magnitude = sqrt( (m_lambda * m_lambda - (m_proton + m_pion) * (m_proton + m_pion)) * (m_lambda * m_lambda - (m_proton - m_pion) * (m_proton - m_pion)) ) / (2 * m_lambda); // magnitude of 3 momentum of proton and pion

    //isotropically performing decay
    //sampling theta and phi for decaying particles
    double phi_p = random_sampling.Uniform(0, 2 * M_PI);  // Azimuthal 
    double theta_p = random_sampling.Uniform(0, M_PI);  // Polar 

    //using spherical co ordinates to find the momentum components
    double px_p_rest = p3_magnitude * sin(theta_p) * cos(phi_p);
    double py_p_rest = p3_magnitude * sin(theta_p) * sin(phi_p);
    double pz_p_rest = p3_magnitude * cos(theta_p);

    // Step 7: Momentum of the pion is opposite to that of the proton
    double px_pi_rest = -px_p_rest;
    double py_pi_rest = -py_p_rest;
    double pz_pi_rest = -pz_p_rest;

    //storing this momentum in rest frame for a moment
    track.setP4_p(px_p_rest, py_p_rest, pz_p_rest, m_proton);
    track.setP4_pi(px_pi_rest, py_pi_rest, pz_pi_rest, m_pion);

    //boosting back to lab frame(eta_L, phi_L)
    track.P4_p.Boost(track.P4_L.Vect());  
    track.P4_pi.Boost(track.P4_L.Vect());

    LorentzVector<PxPyPzM4D<double>> P4_total = P4_p + P4_pi;
    double invariant_mass = P4_total.M();
   

    //invariant mass
    track.setinvariantmass(invariant_mass);


    


    //returning the whole track object
    Track eventgenerator::getTrack() const {
    return track;
}




























}

Track eventgenerator::getTrack() const {
    return track;
}

