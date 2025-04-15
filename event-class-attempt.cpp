#include inputfile.h
#include <Math/Vector4D.h>
#include <iostream>

//Can creat particle class inheriting from TLOrentz

ClassImp(event)
	
using namespace std;

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