#include "cartesBottes.h"
#include "Cartes.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <stdio.h>

using namespace std;

cartesBottes::cartesBottes(string nom, string bottes) :Cartes(nom), bottes(bottes)
{

}

void cartesBottes::afficher(int x)


{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    cout << " ------------------------- " << endl;
    cout << " |                       |" << endl;
    cout << " |C'est une carte botte  |" << endl;
    printf(" |%-22s |", this->bottes.c_str()); //11                         //pour le nom de la carte bottes 
    cout << ">"<<x+1<< endl;                                            // le numéro de la carte dans ta main 
    cout << " |                       |" << endl;
    cout << " ------------------------- " << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

