#ifndef HOTEL_H
#define HOTEL_H

#include <string>
#include <algorithm>
#include <vector>
#include "Chambre.h"
#include "Client.h"
#include "Reservation.h"
using namespace std;

class Hotel {
public:
    string nom;
    string adresse;
    vector<Chambre> chambres;
    vector<Client> clients;
    vector<Reservation> reservations;

    Hotel(string n, string a) : nom(n), adresse(a) {}

    void ajouterChambre(const Chambre& chambre) {
        chambres.push_back(chambre);
    }

    void supprimerChambre(int num) {
        chambres.erase(remove_if(chambres.begin(), chambres.end(),
                                  [num](const Chambre& c) { return c.numChambre == num; }),
                        chambres.end());
    }
    

    void ajouterClient(const Client& client) {
        clients.push_back(client);
    }

    void supprimerClient(const string& nom) {
        clients.erase(remove_if(clients.begin(), clients.end(),
                                 [&nom](const Client& c) { return c.nom == nom; }),
                      clients.end());
    }

    void ajouterReservation(const Reservation& reservation) {
        reservations.push_back(reservation);
        // Assurez-vous que le client de la réservation peut être modifié
        // Ici, nous devons trouver le client correspondant à la réservation.
        for (auto& client : clients) {
            if (client.nom == reservation.client.nom) {
                client.ajouterReservation("Reservation de chambre #" + to_string(reservation.chambre.numChambre));
                break;
            }
        }
    }

    void afficherChambresDisponibles() const {
        for (const auto& chambre : chambres) {
            chambre.afficher();
        }
    }

    void afficherRevenuTotal() const {
        float revenu = 0;
        for (const auto& reservation : reservations) {
            if (reservation.confirmee) {
                int duree = stoi(reservation.dateDepart.substr(8, 2)) - stoi(reservation.dateArrivee.substr(8, 2));
                revenu += duree * reservation.chambre.prixParNuit;
            }
        }
        cout << "Revenu total genere: " << revenu << " DH" << endl;
    }

    void afficherClients() const {
        for (const auto& client : clients) {
            client.afficher();
        }
    }

    void afficherReservations() const {
        for (const auto& reservation : reservations) {
            reservation.afficher();
        }
    }
};

#endif
