
#include "StepAct.hh"
#include "G4SystemOfUnits.hh"


StepAct::StepAct(EventAct *eventAct):event(eventAct)
{

}

void StepAct::UserSteppingAction(const G4Step *aStep) {

//{
//    if ( (aStep->GetTrack()->GetVolume()->GetLogicalVolume()->GetName() =="scin_YAP_log")
//         &&
//            (aStep->GetTrack()->GetParticleDefinition()->GetParticleName() == "gamma")
//            )
//    {
//        event->AddEnDep1(aStep->GetTotalEnergyDeposit());
//    };

    if (aStep->GetTrack()->GetVolume()->GetLogicalVolume()->GetName() == "scin_YAP_log") {
        event->AddEnDep1(aStep->GetTotalEnergyDeposit());
    };
    if (aStep->GetTrack()->GetVolume()->GetLogicalVolume()->GetName() == "scin_LaBr_log") {
        event->AddEnDep2(aStep->GetTotalEnergyDeposit());
    };
    if (aStep->GetTrack()->GetVolume()->GetLogicalVolume()->GetName() == "scin_CeBr_log") {
        event->AddEnDep3(aStep->GetTotalEnergyDeposit());
    };
    if (aStep->GetTrack()->GetVolume()->GetLogicalVolume()->GetName() == "scin_LYSO_log") {
        event->AddEnDep4(aStep->GetTotalEnergyDeposit());
    };
    if (aStep->GetTrack()->GetVolume()->GetLogicalVolume()->GetName() == "scin_LSO_log") {
        event->AddEnDep5(aStep->GetTotalEnergyDeposit());
    };
    if (aStep->GetTrack()->GetVolume()->GetLogicalVolume()->GetName() == "scin_LAO_log") {
        event->AddEnDep6(aStep->GetTotalEnergyDeposit());
    };
    if (aStep->GetTrack()->GetVolume()->GetLogicalVolume()->GetName() == "scin_CH_log") {
        event->AddEnDep7(aStep->GetTotalEnergyDeposit());
    };
}


//
//        cout << "VertexKineticEnergy =  " << aStep->GetTrack()->GetVertexKineticEnergy()<< '\n';
//        cout << "Step Lenght = " << aStep->GetStepLength()<< '\n';
//        cout << "Track Lenght = " << aStep->GetTrack()->GetTrackLength() << '\n';
//        cout << "ParticleName  " << aStep->GetTrack()->GetDynamicParticle()->GetDefinition()->GetParticleName() << '\n';
//        cout << "Kinetic Energy = " << aStep->GetTrack()->GetKineticEnergy() << '\n';
//        cout << "Total Energy Deposit = " << aStep->GetTotalEnergyDeposit() << '\n';
//        cout << "Number of Secondaries in current step = " << aStep->GetNumberOfSecondariesInCurrentStep() << '\n';
//        cout << "DeltaEnergy = " << aStep->GetDeltaEnergy() << '\n';
//        cout << "Total track energy " << aStep->GetTrack()->GetTotalEnergy()<< '\n';
//        cout << '\n';


