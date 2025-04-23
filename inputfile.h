#ifndef INPUTFILE_H
#define INPUTFILE_H

//INITIALIZING EVENT PARAMETERS
double ptmin = 1000.0; //IN MeV
double ptmax = 1000.0;

int N=10; //number of events

double etamin = -0.5;
double etamax = 0.5;


//MASS IN MeV, MAY IMPLEMENT DIRECT READING OF PDG
const double lambdamass=1115.683;
const double protonmass=938.2720813;
const double pionmass=139.57061;

//PARTICLE CHARGES
const int lambdacharge=0;


#endif // INPUTFILE_H
