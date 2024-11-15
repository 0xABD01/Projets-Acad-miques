#include <iostream>
using namespace std;

/*******************************************
 * Complétez le programme à partir d'ici.
 *******************************************/

class Tirelire {
private:
    double montant;

public:
    // Méthode getMontant
    double getMontant() const {
        return montant;
    }

    // Méthode afficher
    void afficher() const {
        if (montant == 0) {
            cout << "Vous etes sans le sou." << endl;
        } else {
            cout << "Vous avez : " << montant << " euros dans votre tirelire." << endl;
        }
    }

    // Méthode secouer
    void secouer() const {
        if (montant > 0) {
            cout << "Bing bing" << endl;
        }
    }

    // Méthode remplir
    void remplir(double ajout) {
        if (ajout > 0) {
            montant += ajout;
        }
    }

    // Méthode vider
    void vider() {
        montant = 0;
    }

    // Méthode puiser
    void puiser(double retrait) {
        if (retrait < 0) return;
        if (retrait >= montant) {
            montant = 0;
        } else {
            montant -= retrait;
        }
    }

    // Méthode montant_suffisant
    bool montant_suffisant(double budget, double &solde) const {
        if (budget <= 0) {
            solde = montant;
            return true;
        }
        if (montant >= budget) {
            solde = montant - budget;
            return true;
        } else {
            solde = budget - montant;
            return false;
        }
    }

    // Méthode calculerSolde
    double calculerSolde(double budget) const {
        if (budget <= 0) return montant;
        return montant - budget;
    }
};



/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Tirelire piggy;

  piggy.vider();
  piggy.secouer();
  piggy.afficher();

  piggy.puiser(20.0);
  piggy.secouer();
  piggy.afficher();

  piggy.remplir(550.0);
  piggy.secouer();
  piggy.afficher();

  piggy.puiser(10.0);
  piggy.puiser(5.0);
  piggy.afficher();

  cout << endl;

  // le budget de vos vacances de rève.
  double budget;

  cout << "Donnez le budget de vos vacances : ";
  cin >> budget;

  // ce qui resterait dans la tirelire après les
  // vacances
  double solde(0.0);

  if (piggy.montant_suffisant(budget, solde)) {
    cout << "Vous êtes assez riche pour partir en vacances !"
         << endl
         << "Il vous restera " << solde << " euros"
         << " à la rentrée." << endl << endl;
    piggy.puiser(budget);
  } else {
    cout << "Il vous manque " << solde << " euros"
         << " pour partir en vacances !" << endl << endl;
  }
  return 0;
}
