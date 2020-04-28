#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <string>
#include <vector>
#include "Cartes.h"

using namespace std;


class Deck
{
public:
    Deck();


    void chargerDeck();
    void melange();
    void afficherdeck();
    int deckVide();
    void afficherNombreCarte();
    Cartes* prendreCarte();


protected:

private:
    vector<Cartes*> cartes;


};

#endif // DECK_H
