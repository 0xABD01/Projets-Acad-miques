#include "Temp.h"

// Méthodes privées
void Temps::normaliser() {
    if (secondes < 0 || minutes < 0 || heures < 0) {
        heures = minutes = secondes = 0;
    }
    minutes += secondes / 60;
    secondes %= 60;
    heures += minutes / 60;
    minutes %= 60;
}

// Constructeurs
Temps::Temps() : heures(0), minutes(0), secondes(0) {}

Temps::Temps(int h, int m, int s) : heures(h), minutes(m), secondes(s) {
    normaliser();
}

// Méthodes
void Temps::setTemps(int h, int m, int s) {
    heures = h;
    minutes = m;
    secondes = s;
    normaliser();
}

void Temps::afficher() const {
    cout << (heures < 10 ? "0" : "") << heures << "h "
         << (minutes < 10 ? "0" : "") << minutes << "min "
         << (secondes < 10 ? "0" : "") << secondes << "s" << endl;
}

void Temps::afficher(bool mode24h) const {
    if (mode24h) {
        afficher();
    } else {
        int h = heures % 12 == 0 ? 12 : heures % 12;
        string am_pm = heures >= 12 ? "PM" : "AM";
        cout << (h < 10 ? "0" : "") << h << "h "
             << (minutes < 10 ? "0" : "") << minutes << "min "
             << (secondes < 10 ? "0" : "") << secondes << "s "
             << am_pm << endl;
    }
}

// Surcharge d'opérateurs
Temps Temps::operator+(const Temps& t) const {
    return Temps(heures + t.heures, minutes + t.minutes, secondes + t.secondes);
}

Temps Temps::operator-(const Temps& t) const {
    int total1 = convertirEnSecondes();
    int total2 = t.convertirEnSecondes();
    return Temps().convertirDepuisSecondes(total1 - total2);
}

bool Temps::operator==(const Temps& t) const { return convertirEnSecondes() == t.convertirEnSecondes(); }
bool Temps::operator!=(const Temps& t) const { return !(*this == t); }
bool Temps::operator<(const Temps& t) const { return convertirEnSecondes() < t.convertirEnSecondes(); }
bool Temps::operator<=(const Temps& t) const { return *this < t || *this == t; }
bool Temps::operator>(const Temps& t) const { return !(*this <= t); }
bool Temps::operator>=(const Temps& t) const { return !(*this < t); }

// Méthodes supplémentaires
void Temps::ajouter(const Temps& t) {
    *this = *this + t;
}

void Temps::ajouter(int h, int m, int s) {
    *this = *this + Temps(h, m, s);
}

void Temps::soustraire(const Temps& t) {
    *this = *this - t;
}

int Temps::convertirEnSecondes() const {
    return heures * 3600 + minutes * 60 + secondes;
}

Temps Temps::convertirDepuisSecondes(int totalSecondes) {
    if (totalSecondes < 0) {
        heures = minutes = secondes = 0;
    } else {
        heures = totalSecondes / 3600;
        minutes = (totalSecondes % 3600) / 60;
        secondes = totalSecondes % 60;
    }
    return *this;
}

int Temps::comparer(const Temps& t) const {
    if (*this < t) return -1;
    if (*this > t) return 1;
    return 0;
}
