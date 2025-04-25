#ifndef INPUTFILE_H
#define INPUTFILE_H

//INITIALIZING EVENT PARAMETERS
extern double ptmin; //IN MeV
extern double ptmax;

extern int N; //number of events

extern double etamin;
extern double etamax;


//MASS IN MeV, MAY IMPLEMENT DIRECT READING OF PDG
extern double lambdamass;
const double protonmass=938.2720813;
const double pionmass=139.57061;

//PARTICLE CHARGES
const int lambdacharge=0;

#endif // INPUTFILE_H

