#include"nComplexe.h"
using namespace std;

//constructeur d'initialisation
nComplexe::nComplexe(float reel ,float imaginaire){
    this->imginaire=imaginaire;
    this->reel=reel;

}

//constructeur d'initilisation par defaut
nComplexe::nComplexe(){
    this->imginaire=1;
    this->reel=1;

}
//constructeur initialisation avec parametre
nComplexe::nComplexe(const nComplexe& autre):imginaire(autre.imginaire),reel(autre.reel){}


nComplexe::~nComplexe(){}



//geters
float nComplexe::getReel(){
    return reel;
}
float nComplexe::getImaginaire(){
    return imginaire;
}
