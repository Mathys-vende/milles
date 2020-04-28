#ifndef CARTESATTAQUE_H
#define CARTESATTAQUE_H

#include <string>
#include"Cartes.h"
#include <iostream>

using namespace std;


class cartesAttaque : public Cartes
{
public:
    cartesAttaque(string nom, string attaque);
    string getAttaque() { return this->attaque; }
    virtual void afficher(int);
    void attaquer();

protected:

private:
    string attaque;
};

#endif // CARTESATTAQUE_H

