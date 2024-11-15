#include "Agence.h"

Ville::Ville() {}

Ville::Ville(int code, string name, int nbrDay)
{
    this->code = code;
    this->name = name;
    this->nbrDay = nbrDay;
}
Ville::~Ville() {}
// seters
void Ville::setCode(int code)
{
    this->code = code;
}
void Ville::setName(string name)
{
    this->name = name;
}
void Ville::setNbrDay(int nbrDay)
{
    this->nbrDay = nbrDay;
}

// geters
int Ville::getCode()
{
    return this->code;
}
string Ville::getName()
{
    return name;
}
int Ville::getNbrDay()
{
    return nbrDay;
}

int compareWithCode(Ville ville1, Ville ville2)
{
    if (ville1.getCode() == ville2.getCode())
        return 0;
    else if (ville1.getCode() > ville2.getCode())
        return 1;
    else
        return -1;
}

bool compareWithName(Ville ville1, Ville ville2)
{
    if (ville1.getName() == ville2.getName())
        return 1;
    else
        return 0;
}

// Part 2

Cuircuit::Cuircuit()
{
    this->nbrVille = 0;
}

Cuircuit::~Cuircuit() {}

void Cuircuit::setName(string name)
{
    this->name = name;
}

void Cuircuit::addVille(Ville ville)
{

    if (this->nbrVille < 7 && !this->existVille(ville))
    {
        villes.push_back(ville);
        (this->nbrVille)++;
    }
    else
    {
        if (this->nbrVille >= 7)
            cout << "vous avez  depasser le 7 vile " << endl;
        else
            cout << "la ville exist deja " << endl;
    }
}

int Cuircuit::getNbrVille()
{
    return nbrVille;
}

string Cuircuit::getName()
{
    return name;
}

bool Cuircuit::existVille(Ville ville)
{
    {
        for (int i = 0; i < nbrVille; i++)
        {
            if (compareWithCode(ville, villes[i]) == 0 && compareWithName(ville, villes[i]) && ville.getNbrDay() == villes[i].getNbrDay())
            {
                return true;
            }
        }
    }
    return false;
}


int Cuircuit::getPeriodOfCuircuit()
{
    int period = 0;
    for (int i = 0; i < nbrVille; i++)
    {
        period += villes[i].getNbrDay();
    }
    return period;
}

void Cuircuit::removeVille(Ville ville)
{
    if (this->existVille(ville))
    {
        for (int i = 0; i < nbrVille; i++)
        {
            if (compareWithCode(ville, villes[i]) == 0 && compareWithName(ville, villes[i]) && ville.getNbrDay() == villes[i].getNbrDay())
            {
                for (int j = i; j < nbrVille - 1; j++)
                {
                    villes[j] = villes[j + 1];
                }
                (this->nbrVille)--;
                cout << "la ville a ete suprimer avec succes" << endl;
            }
        }
    }
    else
        cout << "la ville n'existe pas" << endl;
}

void Cuircuit::displayCuircuit()
{
    cout << "Cuircuit : " << this->getName() << endl;
    if (nbrVille > 0)
    {
        for (int i = 0; i < nbrVille; i++)
        {
            cout << "Nom du ville : " << villes[i].getName() << " a visiter dans " << villes[i].getNbrDay() <<" jours "<< endl;
        }
    }
    else 
       cout<<"aucune ville exist dans ce cuircuit";
}
