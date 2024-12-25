#ifndef HOTEL_HPP
#define HOTEL_HPP

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>
using namespace std;

// Classe Chambre
class Chambre {
private:
    int numChambre;
    string typeChambre;
    double prixParNuit;
    bool disponible;

public:
    Chambre(int num, string type, double prix, bool dispo);

    int getNumChambre() const;
    string getTypeChambre() const;
    double getPrixParNuit() const;
    bool isDisponible() const;

    void setDisponible(bool dispo);

    friend ostream &operator<<(ostream &os, const Chambre &ch);
    bool operator==(const Chambre &ch) const;
};

// Classe Client
class Client {
private:
    string nom;
    string prenom;
    string telephone;
    string email;

public:
    Client(string nom, string prenom, string tel, string mail);

    string getNom() const;

    friend ostream &operator<<(ostream &os, const Client &cl);
    bool operator==(const Client &cl) const;
};

// Classe Reservation
class Reservation {
private:
    Client client;
    Chambre chambre;
    string dateArrivee;
    string dateDepart;
    bool confirmee;

public:
    Reservation(Client c, Chambre ch, string arrivee, string depart);

    void confirmer();
    void annuler();

    Chambre getChambre() const;
    int duree() const;

    friend ostream &operator<<(ostream &os, const Reservation &res);
    bool operator==(const Reservation &res) const;
};

// Classe Hotel
class Hotel {
private:
    string nom;
    string adresse;
    vector<Chambre> chambres;
    vector<Client> clients;
    vector<Reservation> reservations;

public:
    Hotel(string n, string addr);

    void ajouterChambre(const Chambre &chambre);
    void ajouterClient(const Client &client);
    void ajouterReservation(const Reservation &reservation);

    vector<Chambre> chambresDisponibles(const string &type) const;
    vector<Reservation> historiqueReservations(const Client &client) const;
    double calculerRevenuTotal() const;

    friend ostream &operator<<(ostream &os, const Hotel &hotel);
};

#endif // HOTEL_HPP
