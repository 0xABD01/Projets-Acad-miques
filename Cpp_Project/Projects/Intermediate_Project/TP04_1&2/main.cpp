#include<iostream>
#include<math.h>
#include"tp4.h"
using namespace std;

int main(){
    Monome M1(8,2);
    Monome M2(8,2);
    Monome M3(8,2);
    Monome M4(8,2);
    Monome M5(8,2);
    Monome M6(8,2);

    // Monome M2(16,2);
    // //cout<<M1.getcoefficient()<<"x^"<<M1.getdegree()<<"\n";
    // /*cin>>M1;
    // cout<<M1;
    // cin>>M2;
    // cout<<M2;*/
    // Monome Addition= M2 + M1;
    // cout<<M1<<" + "<<M2<<" = ";
    // cout<<Addition<<"\n";
    // Monome Multiplication= M2 * M1;
    // cout<<M1<<" * "<<M2<<" = ";
    // cout<<Multiplication<<"\n";
    // if(M1<M2) cout<<"\n"<<M1<<" est inferieure de "<<M2<<" en terme de degres.\n";
    // else if(M2<M1) cout<<"\n"<<M2<<" est inferieure de "<<M1<<" en terme de degres.\n";
    // else cout<<"\n"<<M1<<" est egale a "<<M2<<" en terme de degres.\n";
    // if(M1==M2) cout<<M1<<" est egale a "<<M2<<" en tous!\n";
    // else cout<<M1<<" n'est pas egale du tous a "<<M2<<"!\n";
    // if(!M1) cout<<M1<<" a un coefficient nul!\n";
    // else cout<<M1<<" n'a pas un coefficient nul!\n";
    // if(!M2) cout<<M2<<" a un coefficient nul!\n";
    // else cout<<M2<<" n'a pas un coefficient nul!\n";
    // Monome Derive1= ~M1;
    // Monome Derive2= ~M2;
    // cout<<"Le derive de "<<M1<<"est: "<<Derive1<<"\n";
    // cout<<"Le derive de "<<M2<<"est: "<<Derive2<<"\n";


    Monome arr[] = {Monome(3, 2), Monome(5, 1), Monome(1, 3)};
    pooly P(3, arr);

    cout << "Before sorting: " << P << endl;

    P.trier();

    cout << "After sorting: " << P << endl;


    return 0;
}