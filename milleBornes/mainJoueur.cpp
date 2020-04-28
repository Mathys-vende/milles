#include "mainJoueur.h"
#include "Deck.h"
#include "Cartes.h"
#include "cartesBornes.h"
#include "cartesBottes.h"
#include <cstdlib>
#include <string>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <vector>
/*mainJoueur::mainJoueur()
{
    
}

void mainJoueur::ajouterCarte(Cartes* c) {
    this->cartes.push_back(c);
}

Cartes* Deck::prendreCarte() {
    Cartes* cart = this->cartes[0];
    this->cartes.erase(this->cartes.begin());
    return cart;
}


void mainJoueur::pioche() {
    // this->cartesPioche;
    for (int i = 0; i < 4; i++) {
        this->cartesPioche.push_back(cartes[cartes.size() - (1 + i)]);
        this->cartes.pop_back();

    }
}
void mainJoueur::distribuer(Deck* deck) {
    for (int x = 1; x <= 7; x++) {
        this->ajouterCarte(deck->prendreCarte());
    }
}
void mainJoueur::afficher() {
    int x;
    for (x = 0; x < this->cartes.size(); x++) {

        this->cartes[x]->afficher();
    }

}
void mainJoueur::choisir(int tour, int choix, Deck* deck) {
    this->cartes.erase(this->cartes.begin() + choix - 1);
    this->ajouterCarte(deck->prendreCarte());


}*/
