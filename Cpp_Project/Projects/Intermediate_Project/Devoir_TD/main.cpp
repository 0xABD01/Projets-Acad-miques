#include "Temp.h"

int main() {
    Temps t1(2, 5, 9); // 02h 05min 09s
    Temps t2(12, 45, 30); // 12h 45min 30s

    cout << "Temps 1 (format 24h) : ";
    t1.afficher();

    cout << "Temps 2 (format 12h) : ";
    t2.afficher(false);

    Temps somme = t1 + t2;
    cout << "Somme des deux temps : ";
    somme.afficher();

    Temps diff = t1 - t2;
    cout << "Différence des deux temps : ";
    diff.afficher();

    cout << "Comparaison : ";
    if (t1 > t2) cout << "Temps 1 est plus grand que Temps 2" << endl;
    else if (t1 < t2) cout << "Temps 1 est plus petit que Temps 2" << endl;
    else cout << "Les deux temps sont égaux" << endl;

    return 0;
}
