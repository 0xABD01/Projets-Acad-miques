#ifndef CHAMBRE_H
#define CHAMBRE_H
#include <iostream>
#include <string>
using namespace std;

class Chambre {
public:
    int numChambre;
    string typeChambre;
    float prixParNuit;
    bool disponible;

    Chambre(int num, string type, float prix)
        : numChambre(num), typeChambre(type), prixParNuit(prix), disponible(true) {}

    bool operator==(const Chambre& other) const {
        return numChambre == other.numChambre;
    }

    void afficher() const {
        cout << "Chambre #" << numChambre << " (" << typeChambre << ") - Prix: " << prixParNuit << " DH- "
             << (disponible ? "Disponible" : "Indisponible") << endl;
    }

    void reserver() {
        disponible = false;
    }

    void liberer() {
        disponible = true;
    }
};

#endif
