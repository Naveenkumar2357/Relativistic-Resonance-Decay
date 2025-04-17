#include inputfile.h
#include <Math/Vector4D.h>
#include <iostream>
 

//Can creat particle class inheriting from TLOrentz

ClassImp(event)
	
using namespace std;


// read N from the input file (number of events to be generated)
//
//create a Ttree file in root Name of the TTree file  (lambda_#mass_pt_#_N)
//
//loop over Number of events
        // 1) run event generator
	        // {which gives trackobject named Track_i (track of every information corresponds to event 1) }
		
        // 2) store the results of events in a branch named EVENT_1 
	//
	// 3) leaf_0 write all four momentum (it would be lorentz 4 vector)
	//    leaf_1 eta, phi, phi1, theta1
	//    leaf_2 invariant mass
	














event::event()
{
eventNumber=-1;
TLorentzVector v1;
TLorentzArray=new TObjArray();
// Set explicitly that the array is the owner!
// This is important to properly allow to delete memory !!!!
// This is a caveat/inconsistency in ROOT, so the best way is to
// play around and try to create a memory leak/error to truly
// understand this aspect!!!
vec2dArray->SetOwner(kTRUE);
}

event::event(int nEv)
{
//user defined constructor
//cout<<" event: user defined constructor called"<<endl;
eventNumber=nEv;
vec2dArray=new TObjArray(50);
vec2dArray->SetOwner(kTRUE);
}

event::~event()
{
//cout<<" event: default destructor called"<<endl;
vec2dArray->Delete();
delete vec2dArray;
};

void event::AddTLorentz(double ..., double ...,.....)
{
vec2d *v=new vec2d(mx,my);
vec2dArray->AddLast(v);

void event::Print()
{
cout<<"Event Class:"<<endl;
cout<<"Event # = "<<eventNumber<<endl;
cout<<"# vec2d = "<<vec2dArray->GetEntries()<<endl;
cout<<endl;
}
void event::PrintTracks()
{
cout<<"Event Class:"<<endl;
cout<<"Event # = "<<eventNumber<<endl;
cout<<"# vec2d = "<<vec2dArray->GetEntries()<<endl;
for (int i=0;i<(int) vec2dArray->GetEntries();i++)
{
cout<<"Track "<<i<<" with length "
<<GetTrack(i)->Length()<<endl;
}
cout<<endl;
}
