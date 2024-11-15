#include "Agence.h"

int main()
{
    //partie 01

    // Ville V1(4, "Rabat", 5);
    // Ville V2(6, "Casablanca", 7);

    // cout << "N : " << V1.getCode() << " ,Nom : " << V1.getName() << " ,Le nbr de jour pour a passer : " << V1.getName() << endl;
    // cout << "N : " << V2.getCode() << " ,Nom : " << V2.getName() << " ,Le nbr de jour pour a passer : " << V2.getName() << endl;

    // if (compareWithName(V1, V2))
    //     cout << "les deux villes ont le meme nom ."<<endl;
    // else{
    //     if(compareWithCode(V1,V2)==1)
    //         cout << "N : " << V1.getCode() << " ,Nom : " << V1.getName() << " ,Le nbr de jour pour a passer : " << V1.getName() << endl;
    //     else
    //         cout << "N : " << V2.getCode() << " ,Nom : " << V2.getName() << " ,Le nbr de jour pour a passer : " << V2.getName() << endl;
    // }


    //partie 02 
    Ville Marrakech (4, "Marrakech ", 1);
    Ville Boumalene(6, "Boumalene ", 3);
    Ville Imilchil(6, "Imilchil", 2);
    Ville Ouarzazate(6, "Ouarzazate ", 4);
    Ville Telouet(6, "Telouet ", 10);
    Ville elouet(6, "Telout ", 10);
    Ville Tlouet(6, "Telo uet ", 10);
    Ville Teouet(6, "Telo u et ", 10);


    Cuircuit C1;
    C1.setName("Atlas et Sud");

    C1.addVille(Marrakech);
    C1.addVille(Boumalene);
    C1.addVille(Imilchil);
    C1.addVille(Ouarzazate);
    C1.addVille(Telouet);
    

    cout<<"le nbr de ville est : "<<C1.getNbrVille()<<endl;


    // if(C1.existVille(Telouet))
    //   cout<<"la ville est trouveé";
    // else 
    //   cout<<"la ville n a pas trouveé";

    // C1.addVille(Telouet);
    // C1.addVille(elouet);
    // C1.addVille(Tlouet);
    // C1.addVille(Teouet);
    // cout<<"le nbr de ville est : "<<C1.getNbrVille()<<endl;

     
    // cout<<"la periode du cuircuit est :"<<C1.getPeriodOfCuircuit()<<endl;    
    

    // C1.removeVille(Imilchil);
    // cout<<"le nbr de ville est : "<<C1.getNbrVille()<<endl;

    C1.displayCuircuit();



    return 0;
}