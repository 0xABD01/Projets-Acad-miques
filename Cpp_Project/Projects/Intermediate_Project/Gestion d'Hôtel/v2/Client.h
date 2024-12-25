#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Client {
public:
    string nom;
    string prenom;
    string telephone;
    string email;
    vector<string> historiqueReservations;

    Client(string n, string p, string t, string e)
        : nom(n), prenom(p), telephone(t), email(e) {}

    void afficher() const {
        cout << "Client: " << nom << " " << prenom << " - " << telephone << " - " << email << endl;
    }

    void ajouterReservation(const string& reservation) {
        historiqueReservations.push_back(reservation);
    }

    void afficherHistorique() const {
        cout << "Historique des reservations:" << endl;
        for (const auto& reservation : historiqueReservations) {
            cout << reservation << endl;
        }
    }
};

#endif
