#ifndef EVENTGENERATOR
#define EVENTGENERATOR

#include <vector>
#include <ctime>
#include <cmath>
#include "track.h"
#include "inputfile.h"
#include "TRandom3.h"

using namespace std;
using namespace ROOT::Math;

class eventgenerator {
public:
    eventgenerator();          
    ~eventgenerator();          

    void generate_event();
    Track getTrack() const; 
  

private:
    Track track;                

    double mineta;              //  (from input file)
    double maxeta;              

    TRandom3 random_sampling;               
};

#endif

