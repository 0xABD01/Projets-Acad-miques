#include <iostream>
using namespace std;

class nComplexe
{
private:
    float reel; 
    float imginaire;
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

    //seters





    ~nComplexe();
};
