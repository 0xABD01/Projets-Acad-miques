#include <iostream>
#include "hotel.hpp"

using namespace std;

// Fonction pour afficher le menu principal
void afficherMenuPrincipal() {
    cout << "\n===== MENU PRINCIPAL =====\n";
    cout << "1. Ajouter une Chambre\n";
    cout << "2. Ajouter un Client\n";
    cout << "3. Faire une Réservation\n";
    cout << "4. Afficher l'historique des Réservations\n";
    cout << "5. Calculer le Revenu Total\n";
    cout << "6. Quitter\n";
    cout << "Choisissez une option: ";
}

// Fonction pour afficher le sous-menu de la gestion des chambres
void afficherSousMenuChambre() {
    cout << "\n===== SOUS-MENU CHAMBRE =====\n";
    cout << "1. Ajouter une Chambre\n";
    cout << "2. Afficher les Chambres Disponibles\n";
    cout << "3. Retour au Menu Principal\n";
    cout << "Choisissez une option: ";
}

// Fonction pour afficher le sous-menu des réservations
void afficherSousMenuReservation() {
    cout << "\n===== SOUS-MENU RÉSERVATION =====\n";
    cout << "1. Faire une Réservation\n";
    cout << "2. Annuler une Réservation\n";
    cout << "3. Retour au Menu Principal\n";
    cout << "Choisissez une option: ";
}

// Fonction pour ajouter une chambre
void ajouterChambre(Hotel &hotel) {
    int num;
    string type;
    double prix;
    bool dispo;
    
    cout << "Numéro de la chambre: ";
    cin >> num;
    cout << "Type de chambre: ";
    cin >> type;
    cout << "Prix par nuit: ";
    cin >> prix;
    cout << "Disponible (1 pour Oui, 0 pour Non): ";
    cin >> dispo;
    
    Chambre chambre(num, type, prix, dispo);
    hotel.ajouterChambre(chambre);
    cout << "Chambre ajoutée avec succès.\n";
}

// Fonction pour ajouter un client
void ajouterClient(Hotel &hotel) {
    string nom, prenom, tel, email;

    cout << "Nom: ";
    cin >> nom;
    cout << "Prénom: ";
    cin >> prenom;
    cout << "Téléphone: ";
    cin >> tel;
    cout << "Email: ";
    cin >> email;

    Client client(nom, prenom, tel, email);
    hotel.ajouterClient(client);
    cout << "Client ajouté avec succès.\n";
}

// Fonction pour effectuer une réservation
void faireReservation(Hotel &hotel) {
    string nomClient, prenomClient, typeChambre, dateArrivee, dateDepart;
    cout << "Nom du client: ";
    cin >> nomClient;
    cout << "Prénom du client: ";
    cin >> prenomClient;

    Client client(nomClient, prenomClient, "", "");

    cout << "Type de chambre: ";
    cin >> typeChambre;

    vector<Chambre> chambresDisponibles = hotel.chambresDisponibles(typeChambre);
    if (chambresDisponibles.empty()) {
        cout << "Aucune chambre disponible de ce type.\n";
        return;
    }

    cout << "Date d'arrivée (YYYY-MM-DD): ";
    cin >> dateArrivee;
    cout << "Date de départ (YYYY-MM-DD): ";
    cin >> dateDepart;

    Chambre chambre = chambresDisponibles[0];  // On prend la première chambre disponible
    Reservation reservation(client, chambre, dateArrivee, dateDepart);
    hotel.ajouterReservation(reservation);
    cout << "Réservation effectuée avec succès.\n";
}

// Fonction pour afficher l'historique des réservations
void afficherHistoriqueReservations(Hotel &hotel) {
    string nomClient, prenomClient;
    cout << "Nom du client: ";
    cin >> nomClient;
    cout << "Prénom du client: ";
    cin >> prenomClient;

    Client client(nomClient, prenomClient, "", "");
    vector<Reservation> historique = hotel.historiqueReservations(client);

    if (historique.empty()) {
        cout << "Aucune réservation trouvée pour ce client.\n";
    } else {
        for (const auto &res : historique) {
            cout << res << endl;
        }
    }
}

// Fonction pour afficher le revenu total
void afficherRevenuTotal(Hotel &hotel) {
    double revenu = hotel.calculerRevenuTotal();
    cout << "Le revenu total de l'hôtel est: " << revenu << "€\n";
}

int main() {
    Hotel hotel("Le Grand Hôtel", "123 Rue de Paris");

    int choixPrincipal, choixSousMenu;
    bool quitter = false;

    while (!quitter) {
        afficherMenuPrincipal();
        cin >> choixPrincipal;

        switch (choixPrincipal) {
            case 1:
                afficherSousMenuChambre();
                cin >> choixSousMenu;
                if (choixSousMenu == 1) {
                    ajouterChambre(hotel);
                } else if (choixSousMenu == 2) {
                    string type;
                    cout << "Type de chambre: ";
                    cin >> type;
                    vector<Chambre> dispo = hotel.chambresDisponibles(type);
                    if (dispo.empty()) {
                        cout << "Aucune chambre disponible de ce type.\n";
                    } else {
                        for (const auto &ch : dispo) {
                            cout << ch << endl;
                        }
                    }
                }
                break;

            case 2:
                ajouterClient(hotel);
                break;

            case 3:
                afficherSousMenuReservation();
                cin >> choixSousMenu;
                if (choixSousMenu == 1) {
                    faireReservation(hotel);
                } else if (choixSousMenu == 2) {
                    cout << "Fonction annulation à implémenter.\n";  // À ajouter selon les besoins
                }
                break;

            case 4:
                afficherHistoriqueReservations(hotel);
                break;

            case 5:
                afficherRevenuTotal(hotel);
                break;

            case 6:
                cout << "Quitter le programme.\n";
                quitter = true;
                break;

            default:
                cout << "Choix invalide. Veuillez réessayer.\n";
        }
    }

    return 0;
}
