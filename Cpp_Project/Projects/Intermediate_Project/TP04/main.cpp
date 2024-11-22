#include"nComplexe.h"
using namespace std;



int main(){

    nComplexe n1;

    nComplexe n2(2.2,7.1);

    nComplexe n3 = n2;
    nComplexe n4(n1);

    cout<<"n1 :" << n1.getReel()<<" +i"<<n1.getImaginaire()<<endl;
    cout<<"n2 :" << n2.getReel()<<" +i"<<n2.getImaginaire()<<endl;
    cout<<"n3 :" << n3.getReel()<<" +i"<<n3.getImaginaire()<<endl;

    return 0;
}
