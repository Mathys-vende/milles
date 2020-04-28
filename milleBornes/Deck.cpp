#include "Deck.h"
#include "Cartes.h"
#include "cartesBornes.h"
#include "cartesBottes.h"
#include "cartesAttaque.h"
#include "carteParade.h"
#include <cstdlib>
#include <string>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <vector>



Deck::Deck()
{}


void Deck::chargerDeck() {
                                                                            // pour éviter de donén le mettre le nom à chaque fois c'est rentré dans des tableaux plus facilement modifiables 
    string nom[4] = { "Bornes","Parade","Attaque","Bottes" };
    int borne[5] = { 25,50,75,100,200 };
    string botte[4] = { "Prioritaire","Camion Citerne","Increvable","As du volant" };
    string attaque[5] = { "Crevaison","Feu rouge","Panne d'essence","Accident","Limitation 50" };
    string parade[5] = { "Feu vert","Fin de limitation","Essence","Roue de secours","Reparation" };


    int n;


    for (n = 0; n < 106; n++) {                                                         //ajout des 106 cartes dans le deck 
        
        int x;
        x = n - 46;

        if (n < 10) {
            cartes.push_back(new cartesBornes(nom[0], borne[0]));
        }
        if (n < 20 && n >= 10) {
            cartes.push_back(new cartesBornes(nom[0], borne[1]));
        }
        if (n < 30 && n >= 20) {
            cartes.push_back(new cartesBornes(nom[0], borne[2]));
        }
        if (n < 42 && n >= 30) {
            cartes.push_back(new cartesBornes(nom[0], borne[3]));
        }
        if (n < 46 && n >= 42) {
            cartes.push_back(new cartesBornes(nom[0], borne[4]));
        }
        if (n < 50 && n >= 46) {
            cartes.push_back(new cartesBottes(nom[3], botte[x]));
        }
        if (n < 53 && n >= 50) {
            cartes.push_back(new cartesAttaque(nom[2], attaque[0]));
        }
        if (n < 58 && n >= 53) {
            cartes.push_back(new cartesAttaque(nom[2], attaque[1]));
        }
        if (n < 61 && n >= 58) {
            cartes.push_back(new cartesAttaque(nom[2], attaque[2]));
        }
        if (n < 64 && n >= 61) {
            cartes.push_back(new cartesAttaque(nom[2], attaque[3]));
        }
        if (n < 68 && n >= 64) {
            cartes.push_back(new cartesAttaque(nom[2], attaque[4]));
        }
        if (n < 82 && n >= 68) {
            cartes.push_back(new carteParade(nom[1], parade[0]));
        }
        if (n < 88 && n >= 82) {
            cartes.push_back(new carteParade(nom[1], parade[1]));
        }
        if (n < 94 && n >= 88) {
            cartes.push_back(new carteParade(nom[1], parade[2]));
        }
        if (n < 100 && n >= 94) {
            cartes.push_back(new carteParade(nom[1], parade[3]));
        }
        if (n < 106 && n >= 100) {
            cartes.push_back(new carteParade(nom[1], parade[4]));
        }
    }
}


void Deck::melange() {                                                  

    random_shuffle(this->cartes.begin(), this->cartes.end());       //melange le deck 

}
void Deck::afficherdeck() {                                     //affichage plus pour du deboguage 
    int x;
    for (x = 0; x < this->cartes.size(); x++) {
        this->cartes[x]->afficher(x);
    }

}
void Deck::afficherNombreCarte() {                              //affichage plus pour du debiguage 
    int x;
    x = this->cartes.size();
    cout << "Il reste " << x << "cartes dans le deck" << endl;
}

int Deck::deckVide() {                                                          //gestion si le deck en vide 
    int vide = 0;

    if (cartes.empty()) {
        system("cls");
        cout << "Le deck est vide" << endl;
        system("pause");
        vide = 1;
    }
    else
    {
        vide = 0;
    }
    return vide;


}

