
#include "RunAct.hh"
#include "EventAct.hh"
#include "StepAct.hh"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

RunAct::RunAct()
{
    result1 = new map<G4double, G4int>;
    result2 = new map<G4double, G4int>;
    result3 = new map<G4double, G4int>;
    result4 = new map<G4double, G4int>;
    result5 = new map<G4double, G4int>;
    result6 = new map<G4double, G4int>;
    result7 = new map<G4double, G4int>;
}

RunAct::~RunAct()
{
    delete result1;
    delete result2;
    delete result3;
    delete result4;
    delete result5;
    delete result6;
    delete result7;
}

void RunAct::BeginOfRunAction(const G4Run *aRun)
{
    result1->clear();
    result2->clear();
    result3->clear();
    result4->clear();
    result5->clear();
    result6->clear();
    result7->clear();

    Sum1=0;
    Sum2=0;
    Sum3=0;
    Sum4=0;
    Sum5=0;
    Sum6=0;
    Sum7=0;

    for (int i=0; i <nStep; i++) result1->insert(std::pair<G4double, G4int> (i *Emax / nStep, 0));
    for (int i=0; i <nStep; i++) result2->insert(std::pair<G4double, G4int> (i *Emax / nStep, 0));
    for (int i=0; i <nStep; i++) result3->insert(std::pair<G4double, G4int> (i *Emax / nStep, 0));
    for (int i=0; i <nStep; i++) result4->insert(std::pair<G4double, G4int> (i *Emax / nStep, 0));
    for (int i=0; i <nStep; i++) result5->insert(std::pair<G4double, G4int> (i *Emax / nStep, 0));
    for (int i=0; i <nStep; i++) result6->insert(std::pair<G4double, G4int> (i *Emax / nStep, 0));
    for (int i=0; i <nStep; i++) result7->insert(std::pair<G4double, G4int> (i *Emax / nStep, 0));
}

void RunAct::EndOfRunAction(const G4Run *aRun) { //    fstream fout1("/mnt/hgfs/VMplayer/Test2/Source.txt", ios::out);

    fstream fout1("../YAP.txt", ios::out);
    for (auto it1: *result1)
        fout1 << it1.first << " " << it1.second << '\n';
    fout1.close();

    fstream fout2("../LaBr.txt", ios::out);
    for (auto it2: *result2)
        fout2 << it2.first << " " << it2.second << '\n';
    fout2.close();

    fstream fout3("../CeBr.txt", ios::out);
    for (auto it3: *result3)
        fout3 << it3.first << " " << it3.second << '\n';
    fout3.close();

    fstream fout4("../LYSO.txt", ios::out);
    for (auto it4: *result4)
        fout4 << it4.first << " " << it4.second << '\n';
    fout4.close();

    fstream fout5("../LSO.txt", ios::out);
    for (auto it5: *result5)
        fout5 << it5.first << " " << it5.second << '\n';
    fout5.close();

    fstream fout6("../LAO.txt", ios::out);
    for (auto it6: *result6)
        fout6 << it6.first << " " << it6.second << '\n';
    fout6.close();

    fstream fout7("../CH.txt", ios::out);
    for (auto it7: *result7)
        fout7 << it7.first << " " << it7.second << '\n';
    fout7.close();

    fstream fout8("../ENERGY", ios::out);
    fout8<<"ЭНЕРГОВЫДЕЛЕНИЕ, МЭВ__ СВЕТОВЫХОД ФОТОН "<<'\n';
    fout8<<"YAP = " <<Sum1<<" МэВ,  "<<Sum1*SVYAP<<'\n';
    fout8<<"LaBr = "<<Sum2<<" МэВ,  "<<Sum2*SVLaBr<<'\n';
    fout8<<"CeBr = "<<Sum3<<" МэВ,  "<<Sum3*SVCeBr<<'\n';
    fout8<<"LYSO = "<<Sum4<<" МэВ,  "<<Sum4*SVLYSO<<'\n';
    fout8<<"LSO = " <<Sum5<<" МэВ,  "<<Sum5*SVLSO<<'\n';
    fout8<<"LAO = " <<Sum6<<" МэВ,  "<<Sum6*SVLAO<<'\n';
    fout8<<"CH = " <<Sum7<<" МэВ,  "<<Sum7*SVCH<<'\n';
    fout8.close();
}

    void RunAct::AddEvent1(G4double energy1) {
        auto it1 = result1->lower_bound(energy1);
        Sum1+=energy1;
        it1->second++; }
    void RunAct::AddEvent2(G4double energy2) {
        auto it2 = result2->lower_bound(energy2);
        Sum2+=energy2;
        it2->second++; }
    void RunAct::AddEvent3(G4double energy3) {
        auto it3 = result3->lower_bound(energy3);
        Sum3+=energy3;
        it3->second++; }
    void RunAct::AddEvent4(G4double energy4) {
        auto it4 = result4->lower_bound(energy4);
        Sum4+=energy4;
        it4->second++; }
    void RunAct::AddEvent5(G4double energy5) {
        auto it5 = result5->lower_bound(energy5);
        Sum5+=energy5;
        it5->second++; }
    void RunAct::AddEvent6(G4double energy6) {
        auto it6 = result6->lower_bound(energy6);
        Sum6+=energy6;
        it6->second++; }
    void RunAct::AddEvent7(G4double energy7) {
     auto it7 = result7->lower_bound(energy7);
      Sum7+=energy7;
      it7->second++; }


//    auto P1 = new double *[nStep];
//    for (int i = 0; i < nStep; i++) {
//        P1[i] = new double[nStep];
//    }
//
//    auto Sigma = new double[nStep];
//    auto Energy = new double[nStep];
//    auto Counts = new double[nStep];
//    auto NormCounts = new double[nStep];
//    auto NormCounts_1 = new double[nStep];

//   double E, Cnt;

//    double PI = 3.1415;

//    ifstream infile1;
//
//    infile1.open("/mnt/hgfs/VMplayer/Test2/Detector.txt");
//
//    for (int i = 0; i < nStep; i++) {
//        infile1 >> E >> Cnt;
//        Energy[i] = E;
//        Counts[i] = Cnt;
//    }
//
//    infile1.close();

//    double delta = Energy[10]-Energy[9];
//
//    for (int i=0; i<nStep; i++)
//    {
//        //Sigma[i] = a+b/sqrt(Energy[i]);
//        Sigma[i] = 0.00005;
//    }
//
//    for (int i = 0; i < nStep; i++)
//    {
//        for (int j = 0; j < nStep; j++)
//        {
//
//            P1[i][j] = (delta*Counts[j] / (sqrt(2 * PI * Sigma[i]))) *
//                       exp(-1*(((Energy[i] - Energy[j]) * (Energy[i] - Energy[j])) /
//                               (2 * Sigma[i])));
//
//        }
//
//    }
//
//    double sum1 = 0;
//
//    for (int i = 0; i < nStep; i++)
//    {
//        for (int j = 0; j < nStep; j++)
//        {
//            sum1 += P1[i][j];
//        }
//
//        NormCounts_1[i] = sum1;
//        sum1 = 0;
//
//    }
//
//    double sum2 =0;
//
//    for (int i=0; i<nStep; i++)
//    {
//        sum2+=delta*Counts[i];
//    }
//
//    double sum3 =0;
//
//    for (int i=0; i<nStep; i++)
//    {
//        sum3+=delta*NormCounts_1[i];
//    }
//
//    for (int i=0; i<nStep; i++)
//    {
//        NormCounts[i]=(sum2/sum3)*NormCounts_1[i];
//    }



//        fstream fout3 ("/mnt/hgfs/VMplayer/Test2/DetectorNorm.txt", ios::out);
//
//
//        for (int i = 0; i < nStep; i++) {
//
//        fout3 << Energy[i] << '\t'<< NormCounts[i] << '\n';
//
//        }
//        fout3.close();
//
//
//    for (int i = 0; i < nStep; i++) { delete[] P1[i]; }
//
//    delete [] Energy;
//    delete [] Counts;
//    delete [] NormCounts;
//    delete [] NormCounts_1;
//    delete [] Sigma;







