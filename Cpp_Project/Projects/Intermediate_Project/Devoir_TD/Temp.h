#include <iostream>
using namespace std;

class Temps {
private:
    int heures;
    int minutes;
    int secondes;

    void normaliser();

public:
    // Constructeurs
    Temps();
    Temps(int h, int m, int s);

    // Méthodes
    void setTemps(int h, int m, int s);
    void afficher() const;
    void afficher(bool mode24h) const;

    // Opérateurs surchargés
    Temps operator+(const Temps& t) const;
    Temps operator-(const Temps& t) const;

    bool operator==(const Temps& t) const;
    bool operator!=(const Temps& t) const;
    bool operator<(const Temps& t) const;
    bool operator<=(const Temps& t) const;
    bool operator>(const Temps& t) const;
    bool operator>=(const Temps& t) const;

    // Méthodes supplémentaires
    void ajouter(const Temps& t);
    void ajouter(int h, int m, int s);
    void soustraire(const Temps& t);

    int convertirEnSecondes() const;
    Temps convertirDepuisSecondes(int totalSecondes);
    int comparer(const Temps& t) const;
};
