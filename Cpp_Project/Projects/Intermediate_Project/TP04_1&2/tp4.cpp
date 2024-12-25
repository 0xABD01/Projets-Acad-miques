#include <iostream>
#include <math.h>
#include "tp4.h"
using namespace std;

Monome::Monome()
{
    this->a = 0;
    this->n = 0;
}

Monome::Monome(float a, int n)
{
    this->a = a;
    this->n = n;
}

ostream &operator<<(ostream &out, Monome &M)
{
    cout << M.a << "x^" << M.n;
    return out;
}

istream &operator>>(istream &in, Monome &M)
{
    cout << "Entrez le coefficient: ";
    in >> M.a;
    cout << "Entrez le degrés: ";
    in >> M.n;
    return in;
}

Monome Monome::operator+(const Monome &M) const
{
    if (this->n != M.n)
    {
        throw invalid_argument("Les monômes doivent avoir le même exposant pour être additionnés.");
    }
    return Monome(this->a + M.a, this->n);
}

Monome Monome::operator*(const Monome &M) const
{
    return Monome(this->a * M.a, this->n * M.n);
}

bool Monome::operator<(const Monome &M) const
{
    return this->n < M.n;
}

bool Monome::operator==(const Monome &M) const
{
    return (this->a == M.a) && (this->n == M.n);
}

bool Monome::operator!() const
{
    return (this->a == 0);
}

Monome Monome::operator~() const
{
    return Monome(this->a * n, this->n - 1);
}

// Pooly
pooly::pooly()
{
    size = 6;
    T = new Monome[size];
}
pooly::pooly(int size, Monome *tab)
{
    this->size = size;
    T = new Monome[size];
    for (int i = 0; i < size; i++)
    {
        T[i] = tab[i];
    }
}

void pooly::trier()
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (!(T[i] < T[j]))
            { // Swap if out of order
                Monome temp = T[i];
                T[i] = T[j];
                T[j] = temp;
            }
        }
    }
}

// Overloading << for printing
ostream &operator<<(ostream &out, pooly &P)
{
    for (int i = 0; i < P.size; i++)
    {
        out << P.T[i];
        if (i < P.size - 1)
        {
            out << " + ";
        }
    }
    return out;
}

pooly::~pooly()
{
    delete[] T;
}