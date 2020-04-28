#include "cartesAttaque.h"
#include "Cartes.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <stdio.h>




using namespace std;



cartesAttaque::cartesAttaque(string nom, string attaque) :Cartes(nom), attaque(attaque)
{

}

void cartesAttaque::afficher(int x)
{

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    
    
    cout << " ------------------------- " << endl;
    cout << " |                       |" << endl;
    cout << " |C'est une carte Attaque|" << endl;
    printf(" |%-23s|", this->attaque.c_str()); //11                 //nom de la carte attaque 
    cout << ">" << x + 1 << endl;                                            // le numéro de la carte dans ta main 
    cout << " |                       |" << endl;
    cout << " ------------------------- " << endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
