#ifndef CARTESBORNES_H
#define CARTESBORNES_H

#include <string>
#include "Cartes.h"
#include <iostream>

using namespace std;

class cartesBornes : public Cartes
{
public:
    cartesBornes(string nom, int bornes);
    int getBornes() { return this->bornes; }
    virtual void afficher(int );

protected:

private:
    int bornes;
};

#endif // CARTESBORNES_H
