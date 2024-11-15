
#include <iostream>
#include "biblioteque.h"
using namespace std;

int main()
{
    rationnel r;

    //a
    cout<<endl;
    r = saisir();

    //b
    cout<<endl;
    afficher_inverse(r);

    //c
    cout<<endl;
    afficher(r);

    //d
    cout<<endl;
    afficher_irreductible(r);

    //e
    rationnel rr;
    cout<<endl;
    rr = saisir();

    //f
    cout<<endl;
    afficher(r);
    afficher(rr);

}