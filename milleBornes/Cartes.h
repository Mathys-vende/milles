#pragma once
#include <iostream>
#include <string>
using namespace std;

class Cartes
{
protected:
    string nom;
    int bornes;
    string bottes;
    string attaque;
    string parade;

public:
    string getNom() { return this->nom; }
    void setNom(string nom) { this->nom = nom; }

    Cartes(string nom);

    virtual void afficher(int );
    virtual int getBornes() { return this->bornes; }
    virtual string getBottes() { return this->bottes; }
    virtual string getAttaque() { return this->attaque; }
    virtual string getParade() { return this->parade; }

    ~Cartes();
};


