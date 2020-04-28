#ifndef JOUEUR_H
#define JOUEUR_H
#include <iostream>
#include <string>
#include "Deck.h"
#include "Cartes.h"





using namespace std;

class joueur {


private:
	string nom;
	int couleur;
	int stade;
	vector<Cartes*> main;
	vector<Cartes*> cartesPioche;


	int creve = 0;
	int accident = 0;
	int feuRouge = 1;
	int essence = 0;
	int limitation = 0;

	int antiCreve = 0;
	int antiAcci = 0;
	int antiEssen = 0;
	int antiFeu = 0;

public:


	joueur(string nom, int couleur, int stade) {
		this->nom = nom;
		this->couleur = couleur;
		this->stade = 0;
	}
	string getNom() { return this->nom; }
	void setNom(string n) { nom = n; }
	int getCouleur() { return this->couleur; }

	void setStade(int s) { stade = s; }
	int getStade() { return this->stade; }


	vector<Cartes*> getMainJoueur() {return this->main; }

	//void afficherRègle();
	void afficherJoueur();



	void afficherEtat();
	


	//Etat attaque Getter

	int getCreve() { return this->creve; }
	int getAccident() { return this->accident; }
	int getFeuRouge() { return this->feuRouge; }
	int getEssence() { return this->essence; }
	int getLimitation() { return this->limitation; }

	//Etat attaque Setter

	void setCreve(int c) { creve = c; }
	void setAccident(int a) { accident = a; }
	void setFeuRouge(int fr) { feuRouge = fr; }
	void setEssence(int e) { essence = e; }
	void setLimitation(int l) { limitation = l; }

	//Etat Bottes Getter

	int getAntiCreve() { return this->antiCreve; }
	int getAntiAcci() { return this->antiAcci; }
	int getAntiFeu() { return this->antiFeu; }
	int getAntiEssen() { return this->antiEssen; }
	//Etat Bottes Setter

	void setAntiCreve(int Ac) { antiCreve = Ac; }
	void setAntiAcci(int Aa) { antiAcci = Aa; }
	void setAntiFeu(int Af) { antiFeu = Af; }
	void setAntiEssen(int Ae) { antiEssen = Ae; }

	void ajouterCarte(Cartes*);
	void afficherMain();
	void distribuer(Deck*);

	void choisir(int tour, int choix, Deck* deck);

	vector<Cartes*> getPioche() { return this->cartesPioche; }
	

};

#endif // !JOUEUR_H
