#include "hotel.hpp"
#include <algorithm>
#include <stdexcept>

// Définition des méthodes de la classe Chambre
Chambre::Chambre(int num, string type, double prix, bool dispo)
    : numChambre(num), typeChambre(type), prixParNuit(prix), disponible(dispo) {}

int Chambre::getNumChambre() const { return numChambre; }
string Chambre::getTypeChambre() const { return typeChambre; }
double Chambre::getPrixParNuit() const { return prixParNuit; }
bool Chambre::isDisponible() const { return disponible; }

void Chambre::setDisponible(bool dispo) { disponible = dispo; }

ostream &operator<<(ostream &os, const Chambre &ch) {
    os << "Chambre " << ch.numChambre << " (" << ch.typeChambre
       << ") - Prix: " << ch.prixParNuit << "/nuit, Disponible: " << (ch.disponible ? "Oui" : "Non");
    return os;
}

bool Chambre::operator==(const Chambre &ch) const {
    return numChambre == ch.numChambre;
}

// Définition des méthodes de la classe Client
Client::Client(string nom, string prenom, string tel, string mail)
    : nom(nom), prenom(prenom), telephone(tel), email(mail) {}

string Client::getNom() const { return nom; }

ostream &operator<<(ostream &os, const Client &cl) {
    os << "Client: " << cl.nom << " " << cl.prenom << ", Tel: " << cl.telephone << ", Email: " << cl.email;
    return os;
}

bool Client::operator==(const Client &cl) const {
    return nom == cl.nom && prenom == cl.prenom;
}

// Définition des méthodes de la classe Reservation
Reservation::Reservation(Client c, Chambre ch, string arrivee, string depart)
    : client(c), chambre(ch), dateArrivee(arrivee), dateDepart(depart), confirmee(false) {}

void Reservation::confirmer() {
    confirmee = true;
    chambre.setDisponible(false);
}

void Reservation::annuler() {
    confirmee = false;
    chambre.setDisponible(true);
}

Chambre Reservation::getChambre() const { return chambre; }

int Reservation::duree() const {
    std::tm tmArrivee = {};
    std::tm tmDepart = {};

    std::istringstream ssArrivee(dateArrivee);
    std::istringstream ssDepart(dateDepart);

    ssArrivee >> std::get_time(&tmArrivee, "%Y-%m-%d");
    ssDepart >> std::get_time(&tmDepart, "%Y-%m-%d");

    if (ssArrivee.fail() || ssDepart.fail()) throw std::runtime_error("Erreur de format de date.");

    std::time_t timeArrivee = std::mktime(&tmArrivee);
    std::time_t timeDepart = std::mktime(&tmDepart);

    return static_cast<int>(std::difftime(timeDepart, timeArrivee) / (60 * 60 * 24));
}

ostream &operator<<(ostream &os, const Reservation &res) {
    os << res.client << "\n" << res.chambre << "\nDates: " << res.dateArrivee << " - " << res.dateDepart
       << ", Confirmée: " << (res.confirmee ? "Oui" : "Non");
    return os;
}

bool Reservation::operator==(const Reservation &res) const {
    return client == res.client && chambre == res.chambre && dateArrivee == res.dateArrivee && dateDepart == res.dateDepart;
}

// Définition des méthodes de la classe Hotel
Hotel::Hotel(string n, string addr) : nom(n), adresse(addr) {}

void Hotel::ajouterChambre(const Chambre &chambre) {
    chambres.push_back(chambre);
}

void Hotel::ajouterClient(const Client &client) {
    clients.push_back(client);
}

void Hotel::ajouterReservation(const Reservation &reservation) {
    if (!reservation.getChambre().isDisponible()) throw std::runtime_error("Chambre indisponible !");
    reservations.push_back(reservation);
}

vector<Chambre> Hotel::chambresDisponibles(const string &type) const {
    vector<Chambre> dispo;
    for (const auto &ch : chambres) {
        if (ch.getTypeChambre() == type && ch.isDisponible()) dispo.push_back(ch);
    }
    return dispo;
}

vector<Reservation> Hotel::historiqueReservations(const Client &client) const {
    vector<Reservation> historique;
    for (const auto &res : reservations) {
        if (res.getChambre().getTypeChambre() == client.getNom()) historique.push_back(res);
    }
    return historique;
}

double Hotel::calculerRevenuTotal() const {
    double revenu = 0;
    for (const auto &res : reservations) {
        revenu += res.getChambre().getPrixParNuit() * res.duree();
    }
    return revenu;
}

ostream &operator<<(ostream &os, const Hotel &hotel) {
    os << "Hôtel: " << hotel.nom << ", Adresse: " << hotel.adresse;
    return os;
}
