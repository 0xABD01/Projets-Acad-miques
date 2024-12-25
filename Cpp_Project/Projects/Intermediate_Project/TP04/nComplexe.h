#include <iostream>
#include<cmath>
using namespace std;

class nComplexe
{
private:
    float reel; 
    float imginaire;
    static int compteur;
public:
    //constructeur d'initialisation
    nComplexe(float reel ,float imaginaire);

    //constructeur initialisation avec parametre
    nComplexe(const nComplexe& autre);

    //constructeur d'initilisation par defaut
    nComplexe();


    //geters
    float getReel();
    float getImaginaire();
    static int getCompteur();

    //seters
    static void remplirTc(nComplexe* tc, int n);
    static void afficherTc(nComplexe* tc, int n);
    

     

    //other
    float calculateModule();


    nComplexe& GetMin(nComplexe* tc, int n);
    void AfficherReel(nComplexe* tc, int n);


    ~nComplexe();
};
