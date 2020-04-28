#include "listeJoueurs.h"
#include "joueur.h"
#include "jeu.h"
#include <vector>

listeJoueurs::listeJoueurs()										
{
	Joueurs.push_back(new joueur("Joueur 1", 1, 0));
	Joueurs.push_back(new joueur("Joueur 2", 2, 0));
	Joueurs.push_back(new joueur("Joueur 3", 3, 0));
	Joueurs.push_back(new joueur("Joueur 4", 4, 0));
	Joueurs.push_back(new joueur("Joueur 5", 5, 0));
}
void listeJoueurs::distribution(Deck* deck, int i )// pour la distribution à chaque joueur 
{
	for (int n = 0; n <= i; n++) {
		Joueurs[n]->distribuer(deck);
	}
}

