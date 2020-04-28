#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "joueur.h"

class listeJoueurs
{
	private:
		
	public:
		vector<joueur*> Joueurs;
		listeJoueurs();
		void distribution(Deck*, int);
		vector<joueur*> getJoueurs() {return this->Joueurs;}
};

