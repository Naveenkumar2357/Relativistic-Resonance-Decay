#ifndef INPUTFILE_H
#define INPUTFILE_H

//INITIALIZING EVENT PARAMETERS
double ptmin = 1000.0; //IN MeV
double ptmax = 1000.0;
double eta = 1.0; //IN RADIANS
double phi = 1.0; //IN RADIANS
double theta = 1.0; //
int event = 0;

double etamin = -0.5;
double etamax = 0.5;


//MASS IN MeV, MAY IMPLEMENT DIRECT READING OF PDG
const double lambdamass=1115.683;
const double protonmass=938.2720813;
const double pionmass=139.57061;

//PARTICLE CHARGES
const int lambdacharge=0;
etc...

#endif // INPUTFILE_H
