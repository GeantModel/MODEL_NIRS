

#ifndef CPROJECT_RUNACT_HH
#define CPROJECT_RUNACT_HH

#include <G4UserRunAction.hh>
#include <G4SystemOfUnits.hh>
#include "Run.hh"
#include "EventAct.hh"
#include <map>

using namespace std;

class G4Run;


class RunAct : public G4UserRunAction {
public:

    RunAct();
    ~RunAct();
    void BeginOfRunAction(const G4Run *aRun);
    void EndOfRunAction(const G4Run *aRun);

    void AddEvent1(G4double energy1);
    void AddEvent2(G4double energy2);
    void AddEvent3(G4double energy3);
    void AddEvent4(G4double energy4);
    void AddEvent5(G4double energy5);
    void AddEvent6(G4double energy6);
    void AddEvent7(G4double energy7);

    G4double Sum7 =0;
    G4double Sum1=0;
    G4double Sum2=0;
    G4double Sum3=0;
    G4double Sum4=0;
    G4double Sum5=0;
    G4double Sum6=0;

    G4double SVYAP  = 25000;
    G4double SVLaBr = 73000;
    G4double SVCeBr = 60000;
    G4double SVLYSO = 25000;
    G4double SVLSO  = 27000;
    G4double SVLAO  = 10000;
    G4double SVCH   = 12000;

    int nStep = 1000;
    G4double Emax = 2.0*MeV;
   // double a = 1;
   // double b = 5;


private:

    map <G4double, G4int> *result1;
    map <G4double, G4int> *result2;
    map <G4double, G4int> *result3;
    map <G4double, G4int> *result4;
    map <G4double, G4int> *result5;
    map <G4double, G4int> *result6;
    map <G4double, G4int> *result7;

};

#endif //CPROJECT_RUNACT_HH
