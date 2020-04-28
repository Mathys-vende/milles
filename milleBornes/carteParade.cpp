#include "carteParade.h"
#include "Cartes.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <stdio.h>

using namespace std;


carteParade::carteParade(string nom, string parade) :Cartes(nom), parade(parade)
{

}
void carteParade::afficher(int x)
{

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    cout << " ------------------------- " << endl;
    cout << " |                       |" << endl;
    cout << " |C'est une carte Parade |" << endl;
    printf(" |%-23s|", this->parade.c_str()); //11                          // nom de la carte parade
    cout << ">" << x + 1 << endl;                                            // le numéro de la carte dans ta main 
    cout << " |                       |" << endl;
    cout << " ------------------------- " << endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

