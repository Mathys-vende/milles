#include <iostream>
#include <string>
#include "cartes.h"

using namespace std;

Cartes::Cartes(string nom)
{
	this->nom = nom;
}

void Cartes::afficher(int x)
{

	cout << " nom : " << this->getNom() << endl;
}

Cartes::~Cartes() {}

