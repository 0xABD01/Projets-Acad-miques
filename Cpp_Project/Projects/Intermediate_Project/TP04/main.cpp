#include"nComplexe.h"
using namespace std;

int nComplexe::compteur = 0;


int main(){
     
    //constructeur initialisation par defaut
    nComplexe n1;

    //constructeur d'initialisation
    nComplexe n2(2.2,7.1);

    //constructeur par defaut
    nComplexe n3 = n2;

    //constructeur de copie
    nComplexe n4(n1);

    //afficher nbr complexe
    cout<<"n1 :" << n1.getReel()<<" +i"<<n1.getImaginaire()<<endl;
    cout<<"n2 :" << n2.getReel()<<" +i"<<n2.getImaginaire()<<endl;
    cout<<"n3 :" << n3.getReel()<<" +i"<<n3.getImaginaire()<<endl;
     

    //calculer le module de chaque nombre complexe
    cout<<"|n1| = "<<n1.calculateModule()<<endl;
    cout<<"|n2| = "<<n2.calculateModule()<<endl;
    cout<<"|n3| = "<<n3.calculateModule()<<endl;




    //afficher le nombre d'objet creé
    cout<<"le nombre d'objet est : "<<nComplexe::getCompteur()<<endl;

    int n = 2;   // la taille du tableau

    nComplexe* tab = new nComplexe[n];

    nComplexe::remplirTc(tab,n);
    nComplexe::afficherTc(tab,n);


    
    return 0;
}
