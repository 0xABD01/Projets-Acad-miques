#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*******************************************
 * Completez le programme a partir d'ici.
 *******************************************/
// Chaines de caractÃ¨res Ã  utiliser pour les affichages:
/*

Ã©tÃ© jetÃ©

d'un

n'est

L'oeuvre

bibliothÃ¨que

dÃ©truit

*/

// Classe Auteur
class Auteur {
private:
    string nom;
    bool prime;

public:
    // Constructeur
    Auteur(string nom, bool prime = false) : nom(nom), prime(prime) {}

    // Méthode pour obtenir le nom de l'auteur
    string getNom() const {
        return nom;
    }

    // Méthode pour savoir si l'auteur est primé
    bool getPrix() const {
        return prime;
    }

    // Empêcher la copie
    Auteur(const Auteur&) = delete;
    Auteur& operator=(const Auteur&) = delete;
};

// Classe Oeuvre
class Oeuvre {
private:
    string titre;
    const Auteur& auteur;
    string langue;

public:
    // Constructeur
    Oeuvre(string titre, const Auteur& auteur, string langue) 
        : titre(titre), auteur(auteur), langue(langue) {}

    // Méthode pour obtenir le titre
    string getTitre() const {
        return titre;
    }

    // Méthode pour obtenir l'auteur
    const Auteur& getAuteur() const {
        return auteur;
    }

    // Méthode pour obtenir la langue
    string getLangue() const {
        return langue;
    }

    // Méthode pour afficher l'œuvre
    void affiche() const {
        cout << titre << ", " << auteur.getNom() << ", en " << langue << endl;
    }

    // Destructeur
    ~Oeuvre() {
        cout << "L'oeuvre \"" << titre << ", " << auteur.getNom() 
             << ", en " << langue << "\" n'est plus disponible." << endl;
    }

    // Empêcher la copie
    Oeuvre(const Oeuvre&) = delete;
    Oeuvre& operator=(const Oeuvre&) = delete;
};

// Classe Exemplaire
class Exemplaire {
private:
    const Oeuvre& oeuvre;

public:
    // Constructeur
    Exemplaire(const Oeuvre& oeuvre) : oeuvre(oeuvre) {
        cout << "Nouvel exemplaire de : " << oeuvre.getTitre() 
             << ", " << oeuvre.getAuteur().getNom() 
             << ", en " << oeuvre.getLangue() << endl;
    }

    // Constructeur de copie
    Exemplaire(const Exemplaire& autre) : oeuvre(autre.oeuvre) {
        cout << "Copie d'un exemplaire de : " << oeuvre.getTitre() 
             << ", " << oeuvre.getAuteur().getNom() 
             << ", en " << oeuvre.getLangue() << endl;
    }

    // Méthode pour obtenir l'œuvre
    const Oeuvre& getOeuvre() const {
        return oeuvre;
    }

    // Méthode pour afficher l'exemplaire
    void affiche() const {
        cout << "Exemplaire de : " << oeuvre.getTitre() 
             << ", " << oeuvre.getAuteur().getNom() 
             << ", en " << oeuvre.getLangue();
    }

    // Destructeur
    ~Exemplaire() {
        cout << "Un exemplaire de \"" << oeuvre.getTitre() 
             << ", " << oeuvre.getAuteur().getNom() 
             << ", en " << oeuvre.getLangue() << "\" a été jeté !" << endl;
    }
};

// Classe Bibliotheque
class Bibliotheque {
private:
    string nom;
    vector<Exemplaire*> exemplaires;

public:
    // Constructeur
    Bibliotheque(string nom) : nom(nom) {
        cout << "La bibliothèque " << nom << " est ouverte !" << endl;
    }

    // Méthode pour obtenir le nom
    string getNom() const {
        return nom;
    }

    // Méthode pour stocker des exemplaires
    void stocker(const Oeuvre& oeuvre, int n = 1) {
        for (int i = 0; i < n; i++) {
            exemplaires.push_back(new Exemplaire(oeuvre));
        }
    }

    // Méthode pour lister les exemplaires
    void lister_exemplaires(string langue = "") const {
        for (const auto& exemplaire : exemplaires) {
            if (langue.empty() || exemplaire->getOeuvre().getLangue() == langue) {
                exemplaire->affiche();
                cout << endl;
            }
        }
    }

    // Méthode pour compter les exemplaires d'une œuvre
    int compter_exemplaires(const Oeuvre& oeuvre) const {
        int count = 0;
        for (const auto& exemplaire : exemplaires) {
            if (&(exemplaire->getOeuvre()) == &oeuvre) {
                count++;
            }
        }
        return count;
    }

    // Méthode pour afficher les auteurs
    void afficher_auteurs(bool primed = false) const {
        for (const auto& exemplaire : exemplaires) {
            const Auteur& auteur = exemplaire->getOeuvre().getAuteur();
            if (!primed || (primed && auteur.getPrix())) {
                cout << auteur.getNom() << endl;
            }
        }
    }

    // Destructeur
    ~Bibliotheque() {
        cout << "La bibliothèque " << nom << " ferme ses portes," << endl;
        cout << "et détruit ses exemplaires :" << endl;
        for (auto exemplaire : exemplaires) {
            delete exemplaire;
        }
    }
};
/*******************************************
 * Ne rien modifier apres cette ligne.
 *******************************************/

int main()
{
  Auteur a1("Victor Hugo"),
         a2("Alexandre Dumas"),
         a3("Raymond Queneau", true);

  Oeuvre o1("Les Misérables"           , a1, "français" ),
         o2("L'Homme qui rit"          , a1, "français" ),
         o3("Le Comte de Monte-Cristo" , a2, "français" ),
         o4("Zazie dans le métro"      , a3, "français" ),
         o5("The Count of Monte-Cristo", a2, "anglais" );

  Bibliotheque biblio("municipale");
  biblio.stocker(o1, 2);
  biblio.stocker(o2);
  biblio.stocker(o3, 3);
  biblio.stocker(o4);
  biblio.stocker(o5);

  cout << "La bibliothèque " << biblio.getNom()
       << " offre les exemplaires suivants :" << endl;
  biblio.lister_exemplaires();

  const string langue("anglais");
  cout << " Les exemplaires en "<< langue << " sont :" << endl;
  biblio.lister_exemplaires(langue);

  cout << " Les auteurs à succès sont :" << endl;
  biblio.afficher_auteurs(true);

  cout << " Il y a " << biblio.compter_exemplaires(o3) << " exemplaires de "
       << o3.getTitre() << endl;

  return 0;
}