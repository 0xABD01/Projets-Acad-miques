#include<iostream>
#include <vector>

using namespace std;


class Ville
{
private:
    int code;
    string name;
    int nbrDay;
public:
    Ville();
    Ville(int code,string name,int nbrDay);
    ~Ville();
    //seters
    void setCode(int code);
    void setName(string name);
    void setNbrDay(int nbrDay);
     
    //geters 
    int getCode();
    string getName();
    int getNbrDay();



};

int compareWithCode(Ville ville1, Ville ville2);
bool compareWithName(Ville ville1, Ville ville2);




class Cuircuit
{
private:
    string name;
    int nbrVille;
    vector<Ville> villes;


public:
    Cuircuit();
    ~Cuircuit();
    //seters

    void setName(string name);
    void addVille(Ville ville);

    void removeVille(Ville ville);

    //geters 
    string getName();
    int getNbrVille();

    bool existVille(Ville ville);
    int getPeriodOfCuircuit();

    void displayCuircuit();
    
};






