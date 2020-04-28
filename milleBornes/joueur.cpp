#include <iostream>
#include <string>
#include <Windows.h>
#include <stdlib.h>
#include "joueur.h"
#include "Deck.h"
#include "mainJoueur.h"
#include "cartesBornes.h"
#include "carteParade.h"
#include "cartesAttaque.h"
#include "cartesBottes.h"
#include "Cartes.h"
#include "listeJoueurs.h"

using namespace std;
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

void joueur::afficherJoueur() {
    cout << "Le joueur " << this->nom << " / " << this->couleur << " au point " << this->stade << endl;
}

void joueur::afficherEtat() {
    //récup des Attaques
    int creve = this->getCreve();
    string infoCreve;
    int accident = this->getAccident();
    string infoAccident;
    int feuRouge = this->getFeuRouge();
    string infofeuRouge;
    int essence = this->getEssence();
    string infoEssence;
    int limitation = this->getLimitation();
    string infoLimitation;

    //récup Bottes
    int antiCreve = this->getAntiCreve();
    string infoAntiCreve;
    int antiAcci = this->getAntiAcci();
    string infoAntiAcci;
    int antiEssen = this->getAntiEssen();
    string infoAntiEssen;
    int antiFeu = this->getAntiFeu();
    string infoAntiFeu;

    int stade = this->getStade();

    // Les messages 
    if (creve == 1) {
        infoCreve = "Tu as les pneus creve";
    }
    else
    {
        infoCreve = "";
    }

    if (accident== 1) {
        infoAccident = "Tu as un accident";
    }
    else
    {
        infoAccident = "";
    }

    if (feuRouge == 1) {
        infofeuRouge = "Il y a un feu rouge";
    }
    else
    {
        infofeuRouge= "";
    }

    if (essence== 1) {
        infoEssence = "Tu n'as plus d'essence";
    }
    else
    {
        infoEssence = "";
    }

    if (limitation == 1) {
        infoLimitation = "Tu a une limitation a 50km/h";
    }
    else
    {
        infoLimitation = "";
    }

    if (antiCreve == 1) {
        infoAntiCreve = "TU ne peux plus crever";
    }
    else
    {
        infoAntiCreve = "";
    }

    if (antiAcci== 1) {
        infoAntiAcci = "TU ne peux plus avoir d'accident";
    }
    else
    {
        infoAntiAcci = "";
    }

    if (antiEssen == 1) {
        infoAntiEssen = "Tu ne peux plus avoir de panne d'essence";
    }
    else
    {
        infoAntiEssen = "";
    }

    if (antiFeu== 1) {
        infoAntiFeu = "Plus rien ne t'arrete ni feu ni limitation";
    }
    else
    {
        infoAntiFeu = "";
    }
    string blanc;


    cout << "                                                      ------------------------------------------------------------------------------" << endl;
    cout << "                                                      |                               |                                            |" << endl;                                 //affichage du Tableau 
    cout << "                                                      |";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf("%-30s", infofeuRouge.c_str());
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << " |";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    printf(" %-43s", infoAntiFeu.c_str());
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << "| " << endl;
    cout << "                                                      |";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);                                                                    
    printf("%-30s", infoAccident.c_str());
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << " |";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    printf(" %-43s", infoAntiAcci.c_str());
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << "| " << endl;
    cout << "                                                      |";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf("%-30s", infoCreve.c_str());

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << " |";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    printf(" %-43s", infoAntiCreve.c_str());
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << "| " << endl;
    cout << "                                                      |";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf("%-30s", infoEssence.c_str());

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << " |";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    printf(" %-43s", infoAntiEssen.c_str());
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << "| " << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << "                                                      |";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf("%-30s", infoLimitation.c_str());
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    printf(" |%-43s |\n", blanc.c_str());
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << "                                                      |                               |                                            |" << endl;
    cout << "                                                      ------------------------------------------------------------------------------" << endl;
    printf("                                                      |           Tu es a %d", stade);
    printf(" bornes, plus que %-d ", 1000-stade);
    printf("pour la victoire!                |\n");
    cout << "                                                      ------------------------------------------------------------------------------" << endl;

}




void joueur::ajouterCarte(Cartes* c) {       //ajoute une carte dans la main du joueur 
    this->main.push_back(c);
}

Cartes* Deck::prendreCarte() {              //prend une carte depuis le deck
    Cartes* cart = this->cartes[0];
    this->cartes.erase(this->cartes.begin());
    return cart;
}

void joueur::distribuer(Deck* deck) {   //distribue une main à chaque joueur 
    for (int x = 1; x <= 7; x++) {
        this->ajouterCarte(deck->prendreCarte());
    }
}
void joueur::afficherMain() {       //affiche la main des joueurs
    int x;
    for (x = 0; x < this->main.size(); x++) {

        this->main[x]->afficher(x);
    }

}
void joueur::choisir(int tour, int choix, Deck* deck) {     //lorsque le joueur choisi quelle carte jouer
   
   int vide = deck->deckVide();
   if (vide == 0) {
       this->main.erase(this->main.begin() + choix - 1);
       this->ajouterCarte(deck->prendreCarte());
   }
   else
   {
       
   }

}







