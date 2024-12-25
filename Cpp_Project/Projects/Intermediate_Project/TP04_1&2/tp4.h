#include <iostream>
#include <math.h>
using namespace std;

class Monome
{
private:
    float a;
    int n;

public:
    Monome();

    Monome(float a, int n);
    Monome(const Monome &autre) : a(autre.a), n(autre.n) {}
    float getcoefficient() { return a; }
    int getdegree() { return n; }
    friend ostream &operator<<(ostream &out, Monome &M);
    friend istream &operator>>(istream &in, Monome &M);
    Monome operator+(const Monome &other) const;
    Monome operator*(const Monome &M) const;
    bool operator<(const Monome &M) const;
    bool operator==(const Monome &M) const;
    bool operator!() const;
    Monome operator~() const;
};

class pooly
{
private:
    Monome *T;
    int size;

public:
    pooly();
    pooly(int size, Monome *tab);
    void trier();
    friend ostream &operator<<(ostream &out, pooly &P);

    ~pooly();



};
