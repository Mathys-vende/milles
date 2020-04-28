#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#ifdef _WIN32
#include <windows.h>
#endif
#include <algorithm>
#include <string>
#include <iomanip>
#include <random>
#include "joueur.h"
#include "listeJoueurs.h"

#include "plateau.h"



plateau::plateau(int largeur, int hauteur) {


    this->largeur = largeur;
    this->hauteur = hauteur;
    tableau.resize(largeur * hauteur, 0);                           // création du vector tableau rempli de 0


    for (int x = 0; x <= 40; x++) {
        
        this->set(x, 0, x*25);
    }

}

int plateau::get(int x, int y) {                                    //pour récup la case
    return this->tableau[this->getIndice(x, y)];
        
}

int plateau::getIndice(int x, int y) {                              // pour récup la valeur de la case


    return y * largeur + x;

}

void plateau::set(int x, int y, int value) {                          //pour mettre une valeur dans une case 

    this->tableau[this->getIndice(x, y)] = value;
}


void plateau::afficher(int stade, int joueur,int i, listeJoueurs* Joueurs) {                    // pour afficher le tableau 
    int valeur = 0;
    int division = stade / 25;

    int leJoueur;
    leJoueur = joueur - 1;
    if (leJoueur == 0) {
        leJoueur = i;
    }

    for (int x = 0; x <= 40; x++) {                                             // pour remmettre la valeur precedente de la ou il etait a 0         

           this->set(x, leJoueur, 0);
    }
    

    this->set(division, leJoueur, stade);


    for (int y = 0; y < this->hauteur; y++) {                                   //pour l'afficher les lignes
        if (y == 0) {
            cout << " Score   ";
        }
        else
        {
            string nom = Joueurs->getJoueurs()[y-1]->getNom();          //le nom du joueur 
            
            printf(" %-8s", nom.c_str());                               
        }
            
        for (int x = 0; x < this->largeur; x++) {

            
            valeur = this->get(x, y);                               //recup la valeur dans la case 
            cout << "|";
            if (valeur == 0) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            }
            printf("%4d",valeur);                                       //et l'afficher en fonction et avec de la couleur si c'est pas 0
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);


        }
        cout <<"|"<< endl;
        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }
    cout << endl << endl;
}

