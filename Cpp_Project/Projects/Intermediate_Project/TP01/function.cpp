#include <iostream>
#include "biblioteque.h"
using namespace std;

rationnel saisir()
{
    rationnel R;

    cout << "saisir le numerateur : ";
    cin >> R.num_teur;
    cout << "saisir le denominateur: ";
    cin >> R.de_teur;

    return R;
}
void afficher_inverse(rationnel ration){
    cout<<"l'inverse de la rationnel est :"<<float(ration.num_teur)/(ration.de_teur)<<endl;
}


void afficher(rationnel ration ){
    cout<<"la rationnel est :"<<ration.num_teur<<"/"<<ration.de_teur<<endl;

}


void afficher_irreductible(rationnel ration){
    rationnel temp_ration = ration ;
    int r,temp;
    r=temp_ration.de_teur;
    while(r!=0){
        temp= r;
        r=temp_ration.num_teur%r;
        if(r==0)
            break;
        temp_ration.num_teur = temp;  
    }
    cout<<"la forme irreductible de "<<ration.num_teur<<"/"<<ration.de_teur<<"  est : ";
    cout<<ration.num_teur/temp<<"/"<<ration.de_teur/temp<<endl;
}
