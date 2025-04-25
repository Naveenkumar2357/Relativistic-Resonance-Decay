#include "event_generator.h"
#include "inputfile.h"
#include <cmath>
#include <ctime>
#include "TLorentzVector.h"

using ROOT::Math::LorentzVector;

eventgenerator::eventgenerator() {
    mineta = etamin;
    maxeta = etamax;
    random_sampling.SetSeed(time(0));
}

eventgenerator::~eventgenerator() {}

void eventgenerator::generate_event() {
    double m_lambda = lambdamass;
    double m_proton = protonmass;
    double m_pion = pionmass;

    double eta_L = random_sampling.Uniform(mineta, maxeta);
    double pt_L = random_sampling.Uniform(ptmin, ptmax);
    double phi_L = random_sampling.Uniform(0, 2 * M_PI);

    double pz_L = pt_L * sinh(eta_L);
    double px_L = pt_L * cos(phi_L);
    double py_L = pt_L * sin(phi_L);

    track.setP4_L(px_L, py_L, pz_L, m_lambda);
    track.seteta_L(eta_L);
    track.setphi_L(phi_L);
    track.setpt_L(pt_L);

    double p3_magnitude = sqrt((m_lambda * m_lambda - pow(m_proton + m_pion, 2)) *
                               (m_lambda * m_lambda - pow(m_proton - m_pion, 2))) / (2 * m_lambda);

    double phi_p = random_sampling.Uniform(0, 2 * M_PI);
    double theta_p = random_sampling.Uniform(0, M_PI);

    double px_p_rest = p3_magnitude * sin(theta_p) * cos(phi_p);
    double py_p_rest = p3_magnitude * sin(theta_p) * sin(phi_p);
    double pz_p_rest = p3_magnitude * cos(theta_p);

    double px_pi_rest = -px_p_rest;
    double py_pi_rest = -py_p_rest;
    double pz_pi_rest = -pz_p_rest;

    TLorentzVector proton_4mom(px_p_rest, py_p_rest, pz_p_rest, sqrt(p3_magnitude * p3_magnitude + m_proton * m_proton));
    TLorentzVector pion_4mom(px_pi_rest, py_pi_rest, pz_pi_rest, sqrt(p3_magnitude * p3_magnitude + m_pion * m_pion));

    TLorentzVector lambda_4mom = track.getP4_L();
    TVector3 boostvec = lambda_4mom.BoostVector();

    proton_4mom.Boost(boostvec);
    pion_4mom.Boost(boostvec);

    track.setP4_p(proton_4mom.Px(), proton_4mom.Py(), proton_4mom.Pz(), m_proton);
    track.setP4_pi(pion_4mom.Px(), pion_4mom.Py(), pion_4mom.Pz(), m_pion);
    track.setphi_p(phi_p);
    track.settheta_p(theta_p);


    TLorentzVector after_decay = proton_4mom + pion_4mom;
    double E = after_decay.E();
    double p2 = after_decay.Vect().Mag2();
    double inv_mass = sqrt(E * E - p2);

    track.setinvariantmass(inv_mass);

    track.print_track();
    cout<<endl;
}

Track eventgenerator::getTrack() const {
    return track;
}



