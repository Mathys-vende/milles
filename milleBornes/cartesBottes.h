#ifndef CARTESBOTTES_H
#define CARTESBOTTES_H

#include <string>
#include "Cartes.h"
#include <iostream>

using namespace std;

class cartesBottes : public Cartes
{
public:
    cartesBottes(string nom, string bottes);
    string getBottes() { return this->bottes; }
    virtual void afficher(int );

protected:

private:
    string bottes;
};

#endif // CARTESBOTTES_H
