#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include <iostream>
#include "Chambre.h"
#include "Client.h"
using namespace std;

class Reservation {
public:
    Client client;
    Chambre chambre;
    string dateArrivee;
    string dateDepart;
    bool confirmee;

    Reservation(Client c, Chambre ch, string arrivee, string depart)
        : client(c), chambre(ch), dateArrivee(arrivee), dateDepart(depart), confirmee(false) {}

    void confirmer() {
        confirmee = true;
    }

    void annuler() {
        confirmee = false;
    }

    void afficher() const {
        cout << "Reservation: " << client.nom << " " << client.prenom << " - Chambre #" << chambre.numChambre
             << " - Du " << dateArrivee << " au " << dateDepart << " - "
             << (confirmee ? "Confirmee" : "Non confirmee") << endl;
    }
};

#endif
