

#include<iostream>
#include<string.h>
using namespace std;
class Compte{
    private:
    int num_compte;
    int code_pin;
    string nom;
    double solde;
    public:
    Compte(int id,string n,int c, double s){
       this->num_compte=id;
       this->code_pin=c;
       this->nom=n;
       this->solde=s;
    }
    bool authentification_code_pin(int code_pin){
        if(this->code_pin==code_pin) return true;
        cout<<"Code pin erone";
        return false;
    }
    void crer_compte(){

    cout<<"\n----------Creation du compte----------- \n";
    cout<<"Saisir les information du compte \n";
    cout<<"Nom Complet: ";
    cin>>this->nom;
    cout<<"Numero du compte: ";
    cin>>this->num_compte;
    cout<<"Code : ";
    cin>>this->code_pin;
    cout<<"Votre solde initiale: ";
    cin>>this->solde;

    cout<<"Votre cpmte a ete creer avec sucee\n";

};