#include"nComplexe.h"
using namespace std;

//constructeur d'initialisation avec parametre
nComplexe::nComplexe(float reel ,float imaginaire){
    this->imginaire=imaginaire;
    this->reel=reel;
    compteur++;

}

//constructeur d'initilisation par defaut
nComplexe::nComplexe(){
    this->imginaire=1;
    this->reel=1;
    compteur ++;

}
//constructeur initialisation avec parametre
nComplexe::nComplexe(const nComplexe& autre):imginaire(autre.imginaire),reel(autre.reel){compteur++;}


nComplexe::~nComplexe(){compteur--;}



//geters
float nComplexe::getReel(){
    return reel;
}
float nComplexe::getImaginaire(){
    return imginaire;
}
int nComplexe::getCompteur(){
    return compteur;
}


//seters

void nComplexe::remplirTc(nComplexe* tc, int n){

    for(int i=0 ;i<n;i++){
        double R,I;
        cout<<"nComplexe["<<i+1<<"] :"<<endl;
        cout << "R = " ;
        cin >> R;
        cout << "I = " ;
        cin >> I;
        
        tc[i] = nComplexe(R,I);       
    }

}

void nComplexe::afficherTc(nComplexe* tc, int n){
    for(int i=0 ;i<n;i++){
        cout<<"nComplexe["<<i+1<<"] : "<< tc[i].getReel()<<" +i"<<tc[i].getImaginaire()<<endl;
    }
}






//others

float nComplexe::calculateModule(){
    return sqrt(pow(getReel(),2)+pow(getImaginaire(),2));
}



nComplexe& nComplexe::GetMin(nComplexe* tc, int n) {
    if (n <= 0) {
        throw std::invalid_argument("Le tableau est vide ou invalide.");
    }

    int minIndex = 0;
    float minModule = tc[0].calculateModule();

    for (int i = 1; i < n; i++) {
        if (tc[i].calculateModule() < minModule) {
            minIndex = i;
            minModule = tc[i].calculateModule();
        }
    }

    return tc[minIndex];
}


void nComplexe::AfficherReel(nComplexe* tc, int n) {
    if (n <= 0) {
        throw std::invalid_argument("Le tableau est vide ou invalide.");
    }

    int maxIndex = 0;
    float maxReel = tc[0].getReel();

    for (int i = 1; i < n; i++) {
        if (tc[i].getReel() > maxReel) {
            maxIndex = i;
            maxReel = tc[i].getReel();
        }
    }

    cout << "Le complexe avec la plus grande partie réelle est : " 
         << tc[maxIndex].getReel() << " + i" << tc[maxIndex].getImaginaire() << endl;
}
