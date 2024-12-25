#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "Chambre.h"
#include "Client.h"
#include "Reservation.h"
#include "Hotel.h"
using namespace std;

// Fonction pour mettre une pause avant de nettoyer l ecran
void pause() {
    cout << "Appuyez sur une touche pour continuer...";
    cin.ignore();  // Ignore tout reste d entree dans le buffer
    cin.get();     // Attendre que l utilisateur appuie sur une touche
    system("cls"); // Effacer l ecran
}

int main() {
    Hotel hotel("Grand Hôtel", "123 Rue Exemple");

    // Ajout de chambres
    hotel.ajouterChambre(Chambre(101, "simple", 50));
    hotel.ajouterChambre(Chambre(102, "double", 80));
    hotel.ajouterChambre(Chambre(103, "suite", 150));

    // Ajout de clients
    hotel.ajouterClient(Client("Abderrazzak", "ESSALMI", "0676662777", "Abderrazzak.esl@gmail.com"));
    hotel.ajouterClient(Client("Mohamed Ali", "Tarrouzi", "0987654321", "medalitarrouzi748@gmail.com "));

    // Menu principal
    int choix;
    do {
        cout << "\n1. Afficher les chambres\n"
             << "2. Ajouter une chambre\n"
             << "3. Supprimer une chambre\n"
             << "4. Afficher les clients\n"
             << "5. Ajouter un client\n"
             << "6. Supprimer un client\n"
             << "7. Afficher les reservations\n"
             << "8. Creer une reservation\n"
             << "9. Confirmer une reservation\n"
             << "10. Annuler une reservation\n"
             << "11. Afficher le revenu total\n"
             << "0. Quitter\n"
             << "Choisissez une option: ";
        cin >> choix;

        switch (choix) {
        case 1:
            hotel.afficherChambresDisponibles();
            pause(); // Ajouter une pause après l affichage
            break;
        case 2: {
            int num;
            string type;
            float prix;
            cout << "Numero de la chambre: ";
            cin >> num;
            cout << "Type (simple, double, suite): ";
            cin >> type;
            cout << "Prix par nuit: ";
            cin >> prix;
            hotel.ajouterChambre(Chambre(num, type, prix));
            pause(); // Ajouter une pause après l ajout
            break;
        }
        case 3: {
            int num;
            cout << "Numero de la chambre a supprimer: ";
            cin >> num;
            hotel.supprimerChambre(num);
            pause(); // Ajouter une pause après la suppression
            break;
        }
        case 4:
            hotel.afficherClients();
            pause(); // Ajouter une pause après l affichage
            break;
        case 5: {
            string nom, prenom, telephone, email;
            cout << "Nom: ";
            cin >> nom;
            cout << "Prenom: ";
            cin >> prenom;
            cout << "Telephone: ";
            cin >> telephone;
            cout << "Email: ";
            cin >> email;
            hotel.ajouterClient(Client(nom, prenom, telephone, email));
            pause(); // Ajouter une pause après l ajout
            break;
        }
        case 6: {
            string nom;
            cout << "Nom du client a supprimer: ";
            cin >> nom;
            hotel.supprimerClient(nom);
            pause(); // Ajouter une pause après la suppression
            break;
        }
        case 7:
            hotel.afficherReservations();
            pause(); // Ajouter une pause après l affichage
            break;
        case 8: {
            string nomClient, typeChambre, dateArrivee, dateDepart;
            cout << "Nom du client: ";
            cin >> nomClient;
            cout << "Type de chambre (simple, double, suite): ";
            cin >> typeChambre;
            cout << "Date d arrivee (YYYY-MM-DD): ";
            cin >> dateArrivee;
            cout << "Date de depart (YYYY-MM-DD): ";
            cin >> dateDepart;

            Client* client = nullptr;
            for (auto& c : hotel.clients) {
                if (c.nom == nomClient) {
                    client = &c;
                    break;
                }
            }

            Chambre* chambre = nullptr;
            for (auto& ch : hotel.chambres) {
                if (ch.typeChambre == typeChambre && ch.disponible) {
                    chambre = &ch;
                    break;
                }
            }

            if (client && chambre) {
                hotel.ajouterReservation(Reservation(*client, *chambre, dateArrivee, dateDepart));
            } else {
                cout << "Client ou chambre non trouve(e).\n";
            }
            pause(); // Ajouter une pause après la creation de la reservation
            break;
        }
        case 9: {
            int numChambre;
            cout << "Numero de la chambre a confirmer: ";
            cin >> numChambre;
            for (auto& reservation : hotel.reservations) {
                if (reservation.chambre.numChambre == numChambre && !reservation.confirmee) {
                    reservation.confirmer();
                    break;
                }
            }
            pause(); // Ajouter une pause après confirmation
            break;
        }
        case 10: {
            int numChambre;
            cout << "Numero de la chambre a annuler: ";
            cin >> numChambre;
            for (auto& reservation : hotel.reservations) {
                if (reservation.chambre.numChambre == numChambre && reservation.confirmee) {
                    reservation.annuler();
                    break;
                }
            }
            pause(); // Ajouter une pause après annulation
            break;
        }
        case 11:
            hotel.afficherRevenuTotal();
            pause(); // Ajouter une pause après l affichage du revenu
            break;
        case 0:
            cout << "Au revoir!\n";
            break;
        default:
            cout << "Option invalide.\n";
        }
    } while (choix != 0);

    return 0;
}
