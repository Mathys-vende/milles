#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <stdio.h>
#include <limits>
#include "joueur.h"
#include "Deck.h"
#include "listeJoueurs.h"
#include "jeu.h"
#include <Mmsystem.h>
#include <conio.h>

#pragma comment(lib, "winmm.lib")

using namespace std;

int main() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	HWND hwnd = GetForegroundWindow();											//permet de lancer le jeu en plein écran ! (le jeu ne ce joue que en plein écran)
	ShowWindow(hwnd, SW_MAXIMIZE);
	MMRESULT result;
	result = waveOutSetVolume(NULL, 0x00300030);								//gestion du vollume de la musique c'est de l'hexa pour chaque oreille 0xDDDDGGGG
	PlaySound(TEXT("Joakim Karud - Canals.wav"), NULL, SND_ASYNC | SND_LOOP);	// la musique forte sympathique qui se joue pendant le jeu et ne l'arrete pas et joue la musique à l'infinie




	jeu* jeux = new jeu;								//cree le jeu 
	listeJoueurs* Joueurs = new listeJoueurs;			//cree la liste de joueur 

	jeux->afficherMenu();
	int i = jeux->init(Joueurs);						//pour initialiser le jeu 



	srand(time(NULL));
	Deck* deck = new Deck;								//cree le deck 
	deck->chargerDeck();								//ajoute les cartes 
	deck->melange();									//le melange 


	//deck->afficherdeck();
	
	


	Joueurs->distribution(deck, i);						//distribution des mains 



	jeux->deroulementJeu(Joueurs, deck, i);			// le jeu commence 

	return 0;


}