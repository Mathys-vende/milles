#include "cartesBornes.h"
#include "Cartes.h"
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

cartesBornes::cartesBornes(string nom, int bornes) :Cartes(nom), bornes(bornes)
{

}

void cartesBornes::afficher(int x)
{
    cout << " ------------------------- " << endl;
    cout << " |                       |" << endl;
    cout << " |C'est une carte borne  |" << endl;
    printf(" |%-23d|", this->bornes); //11                          //nom de la carte bornes 
    cout << ">" << x + 1 << endl;                                            // le numéro de la carte dans ta main 
    cout << " |                       |" << endl;
    cout << " ------------------------- " << endl;
}
