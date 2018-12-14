

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

    int nStep = 10000;
    G4double Emax = 10.0*MeV;
    double a = 1;
    double b = 5;


private:

    std::map <G4double, G4int> *result1;

    std::map <G4double, G4int> *result2;

};

#endif //CPROJECT_RUNACT_HH