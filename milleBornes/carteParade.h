#pragma once
#ifndef CARTEPARADE_H
#define CARTEPARADE_H

#include <string>
#include <iostream>
#include "Cartes.h"
using namespace std;


class carteParade : public Cartes
{
public:
    carteParade(string nom, string parade);
    string getParade() { return this->parade; }
    virtual void afficher(int );


protected:

private:
    string parade;
};

#endif // CARTEPARADE_H
