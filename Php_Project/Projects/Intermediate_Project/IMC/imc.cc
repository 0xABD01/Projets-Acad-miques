#include <iostream>
using namespace std;

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

class Patient {
private:
    double masse;
    double hauteur;

public:
    // Méthode init
    void init(double poids, double taille) {
        if (poids > 0 && taille > 0) {
            masse = poids;
            hauteur = taille;
        } else {
            masse = 0;
            hauteur = 0;
        }
    }

    // Méthode afficher
    void afficher() const {
        cout << "Patient : " << masse << " kg pour " << hauteur << " m" << endl;
    }

    // Méthode poids
    double poids() const {
        return masse;
    }

    // Méthode taille
    double taille() const {
        return hauteur;
    }

    // Méthode imc
    double imc() const {
        if (hauteur == 0) return 0;
        return masse / (hauteur * hauteur);
    }
};

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Patient quidam;
  double poids, taille;
  do {
    cout << "Entrez un poids (kg) et une taille (m) : ";
    cin >> poids >> taille;
    quidam.init(poids, taille);
    quidam.afficher();
    cout << "IMC : " << quidam.imc() << endl;
  } while (poids * taille != 0.0);
  return 0;
}
