#include "jeu.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include "joueur.h"
#include "Deck.h"
#include "plateau.h"
#include "listeJoueurs.h"

#define ARROW_UP        72
#define ARROW_DOWN      80





void jeu::deroulementJeu(listeJoueurs* Joueurs,Deck* deck, int i) {
	int tour;
	int choix;
	int defausse;
    plateau* grille = new plateau(41, i + 1);
    cout << "Pret pour la partie ?? (appuyer sur une touche quand tout le monde est pret!)" << endl;
    system("pause > nul");
	for (tour = 1; tour <= i + 1; tour++) {                                                                 //gestion des tours va jusqu'a le nombre de joueur et revient quand il à atteint le nombre max ( permet de coordonnées les tours avec le jouers qui joue)
		if (tour == i + 1) {                                                                                 //-1 car le vector joueur commence pas 0 et le tour par 1
			tour = 1;
		}

                                                                                                                
        int leJoueur;
        leJoueur = tour - 2;
        if (leJoueur == -1 ) {
            leJoueur = i - 1;                                                                               //Permet de prendre le stade du joueur du tour d'avant pour pouvoir actualisé le tableau instantanément 
        }
        int stade = Joueurs->getJoueurs()[leJoueur]->getStade();
        system("cls");

        grille->afficher(stade, tour, i, Joueurs);                                                              //affiche le tablea
        Joueurs->getJoueurs()[tour - 1]->afficherEtat();                                                        //affiche le tableau d'état du joueur 
        //deck->afficherNombreCarte();
        string nom = Joueurs->getJoueurs()[tour - 1]->getNom();                                                 //affiche le nom du joueur 
		cout << "Voici la main de " << nom << endl;
		Joueurs->getJoueurs()[tour-1]->afficherMain();                                                          //affiche main du joueur 
		cout << "Voulez vous vous defaussez ou jouer une carte ? 1 = jouer une carte 2 = defausse" << endl;     //premier choix si il veut deffausser ou jouer une carte 
        while (!(cin >> defausse) || defausse < 1 || defausse >2) {
            cin.clear();
            cin.ignore(6666, '\n');
            cout << "faites un choix valide entre 1 ou 2 (1 pour jouer une carte 2 pour la defausse)" << endl;
        }
		if (defausse == 1) {
			cout << "Choisissez une carte a jouer" << endl;
            while (!(cin >> choix) || choix < 1 || choix > 7) {
                cin.clear();
                cin.ignore(6666, '\n');
                cout << "faites un choix valide entre 1 et 7" << endl;

            }
			this->jouerCartes(tour, choix, i, deck, Joueurs);                                           //l'envoie vers la fonction de l'effet de la carte
			Joueurs->getJoueurs()[tour - 1]->choisir(tour, choix, deck);                                    
           
            

		}
		else {
			cout << "Quelle carte voulez vous defaussez ?" << endl;
            while (!(cin >> choix) || choix < 1 || choix > 7) {
                cin.clear();
                cin.ignore(6666, '\n');
                cout << "faites un choix valide entre 1 et 7" << endl;

            }
			Joueurs->getJoueurs()[tour - 1]->choisir(tour, choix, deck);                                    //choisi qu'elle carte il va defausser 
		}

	}
}

void jeu::jouerCartes(int tour, int choix, int i, Deck* deck, listeJoueurs* Joueurs) {
    //récupération toute variable

    //récup Etat conduite
    int creve = Joueurs->getJoueurs()[tour-1]->getCreve();
    int accident = Joueurs->getJoueurs()[tour - 1]->getAccident();
    int feuRouge = Joueurs->getJoueurs()[tour - 1]->getFeuRouge();
    int essence = Joueurs->getJoueurs()[tour - 1]->getEssence();
    int limitation = Joueurs->getJoueurs()[tour - 1]->getLimitation();

    //récup Bottes
    int antiCreve = Joueurs->getJoueurs()[tour - 1]->getAntiCreve();
    int antiAcci = Joueurs->getJoueurs()[tour - 1]->getAntiAcci();
    int antiEssen = Joueurs->getJoueurs()[tour - 1]->getAntiEssen();
    int antiFeu = Joueurs->getJoueurs()[tour - 1]->getAntiFeu();

    int stade = Joueurs->getJoueurs()[tour - 1]->getStade();



    string nomCarte = Joueurs->getJoueurs()[tour - 1]->getMainJoueur()[choix - 1]->getNom();



    if (nomCarte == "Bornes") {                                                                         //gestion des cartes bornes 
        if (creve == 1 || accident == 1 || feuRouge == 1 || essence == 1) {
            cout << "Vous ne pouvez pas utilisez cette carte! Utilisez une carte Parade ou defaussez vous ou attaquez un adversaire" << endl;           //verifie qu'il peut avancer
            this->choixCarte(tour, choix,i, deck, Joueurs);                                                                                             // le renvoie vers le choix de carte
            
        }
        else {
            int bornes = Joueurs->getJoueurs()[tour - 1]->getMainJoueur()[choix - 1]->getBornes();                      
            if (limitation == 1) {
                if (bornes >= 50) {                                                                                                             //vérifie qu'il n'est pas limité 
                   
                    Joueurs->getJoueurs()[tour - 1]->setStade(stade + bornes);                                                                  //si c'est bon ajoute la bornes 

                }
                else {
                    cout << "vous ne pouvez pas jouez cette carte vous etes limite a 50. Choississez une autre Cartes" << endl;

                    this->choixCarte(tour, choix,i, deck, Joueurs);                                                                                 // le renvoie vers le choix de carte
                    
                }

            }
            if (bornes + stade > 1000) {                                                                                                            //verifie que ça ne l'envoie pas au dela de 1000 bornes ce qui n'est pas permis 
                cout << "vous ne pouvez pas jouer cette carte elle vous emmene plus loin que 1000" << endl;
                this->choixCarte(tour, choix, i, deck, Joueurs);                                                                                    // le renvoie vers le choix de carte
            }   
            else {
                Joueurs->getJoueurs()[tour - 1]->setStade(stade + bornes);                                                                          // si rien de tout ça le laisse jouer ça carte 
                
            }
            
        }
    }

    if (nomCarte == "Bottes") {                                                                         //gestion carte Bottes
        string Bottes = Joueurs->getJoueurs()[tour - 1]->getMainJoueur()[choix - 1]->getBottes();                                                   
        if (Bottes == "Camion Citerne") {
            
            Joueurs->getJoueurs()[tour - 1]->setAntiEssen(1);                                                   //change la valeur du joueur de ça botte 
            Joueurs->getJoueurs()[tour - 1]->setEssence(0);                                                     //si il était affecté par une attaque la lui enleve 
            cout << "Vous etes maintenant insensible aux pannes d'essence !" << endl;
        }
        if (Bottes == "Prioritaire") {

            Joueurs->getJoueurs()[tour - 1]->setAntiFeu(1);                                                     //same que pour le premier 
            Joueurs->getJoueurs()[tour - 1]->setFeuRouge(0);
            Joueurs->getJoueurs()[tour - 1]->setLimitation(0);
            cout << "Vous etes maintenant insensible aux feu rouges !" << endl;
        }
        if (Bottes == "Increvable") {
            Joueurs->getJoueurs()[tour - 1]->setCreve(0);
            Joueurs->getJoueurs()[tour - 1]->setAntiCreve(1);
            cout << "Vous etes maintenant insensible aux crevaisons !" << endl;
        }
        if (Bottes == "As du volant") {
            Joueurs->getJoueurs()[tour - 1]->setAccident(0);
            Joueurs->getJoueurs()[tour - 1]->setAntiAcci(1);
            cout << "Vous etes maintenant insensible aux accidents!" << endl;
        }
    }

    if (nomCarte == "Attaque") {                                                                                    //gestion carte Attaque 


        string Attaque = Joueurs->getJoueurs()[tour - 1]->getMainJoueur()[choix - 1]->getAttaque();
        int cible;

        if (Attaque == "Crevaison") {

            

            int cible = this->attaqueJoueur(Joueurs, i);


            int checkAttaque = Joueurs->getJoueurs()[cible - 1]->getCreve();                                            
            int checkBotte = Joueurs->getJoueurs()[cible - 1]->getAntiCreve();                                                              //recup de l'état du joueur en fonction de ces bottes et de ces attaques 

            if (checkBotte == 1)
            {
                cout << "vous ne pouvez pas l'attaquer il à utiliser car il a la botte qui le contre" << endl;               //verif si le joueur n'a pas une botte qui fait qu'on en peut pas l'attaquer      
                this->choixCarte(tour, choix, i, deck, Joueurs);                                                                    // le renvoie vers le choix de carte
            }

            if (checkAttaque == 1)
            {
                cout << "vous ne pouvez pas l'attaquer car il à déja cette attaque sur lui" << endl;                   //verif si le joueur n'est pas déja sous cette attaque 
                this->choixCarte(tour, choix, i, deck, Joueurs);                                                            // le renvoie vers le choix de carte
            }
            if (checkAttaque == 0 && checkBotte == 0) {
                Joueurs->getJoueurs()[cible - 1]->setCreve(1);
                cout << "Le joueur " << cible << " ne peux plus avancer" << endl;
            }
        }
        if (Attaque == "Feu rouge") {                                                                                           //same que pour la premiere fonction attaque 

            int cible = this->attaqueJoueur(Joueurs, i);

            int checkBotte = Joueurs->getJoueurs()[cible - 1]->getAntiFeu();
            int checkAttaque = Joueurs->getJoueurs()[cible - 1]->getFeuRouge();
            
            if (checkBotte == 1)
            {
                cout << "vous ne pouvez pas l'attaquer il à utiliser car il a la botte qui le contre" << endl;
                this->choixCarte(tour, choix, i, deck, Joueurs);
            }
            if (checkAttaque == 1)
            {
                cout << "vous ne pouvez pas l'attaquer car il à déja cette attaque sur lui" << endl;
                this->choixCarte(tour, choix, i, deck, Joueurs);
            }
            if (checkAttaque == 0 && checkBotte == 0) {
                Joueurs->getJoueurs()[cible - 1]->setFeuRouge(1);
                cout << "Le joueur " << cible << " ne peux plus avancer" << endl;
            }
        }
        if (Attaque == "Panne d'essence") {

            int cible = this->attaqueJoueur(Joueurs, i);

            int checkBotte = Joueurs->getJoueurs()[cible - 1]->getAntiEssen();
            int checkAttaque = Joueurs->getJoueurs()[cible - 1]->getEssence();

            if (checkBotte == 1)
            {
                cout << "vous ne pouvez pas l'attaquer il à utiliser car il a la botte qui le contre" << endl;
                this->choixCarte(tour, choix, i, deck, Joueurs);
            }
            if (checkAttaque == 1)
            {
                cout << "vous ne pouvez pas l'attaquer car il à déja cette attaque sur lui" << endl;
                this->choixCarte(tour, choix, i, deck, Joueurs);
            }
            if (checkAttaque == 0 && checkBotte == 0) {
                Joueurs->getJoueurs()[cible - 1]->setEssence(1);
                cout << "Le joueur " << cible << " ne peux plus avancer" << endl;
            }
        }

        if (Attaque == "Accident") {

            int cible = this->attaqueJoueur(Joueurs, i);

            int checkBotte = Joueurs->getJoueurs()[cible - 1]->getAntiAcci();
            int checkAttaque = Joueurs->getJoueurs()[cible - 1]->getAccident();

            if (checkBotte == 1)
            {
                cout << "vous ne pouvez pas l'attaquer il à utiliser car il a la botte qui le contre" << endl;
                this->choixCarte(tour, choix, i, deck, Joueurs);
            }
            if (checkAttaque == 1)
            {
                cout << "vous ne pouvez pas l'attaquer car il à déja cette attaque sur lui" << endl;
                this->choixCarte(tour, choix, i, deck, Joueurs);
            }
            if (checkAttaque == 0 && checkBotte == 0) {
                Joueurs->getJoueurs()[cible - 1]->setAccident(1);
                cout << "Le joueur " << cible << " ne peux plus avancer" << endl;
            }
        }

        if (Attaque == "Limitation 50") {

            int cible = this->attaqueJoueur(Joueurs, i);

            int checkBotte = Joueurs->getJoueurs()[cible - 1]->getAntiFeu();
            int checkAttaque = Joueurs->getJoueurs()[cible - 1]->getLimitation();

            if (checkBotte == 1)
            {
                cout << "vous ne pouvez pas l'attaquer il à utiliser car il a la botte qui le contre" << endl;
                this->choixCarte(tour, choix, i, deck, Joueurs);
            }
            if (checkAttaque == 1)
            {
                cout << "vous ne pouvez pas l'attaquer car il à déja cette attaque sur lui" << endl;
                this->choixCarte(tour, choix, i, deck, Joueurs);
            }
            if (checkAttaque == 0 && checkBotte == 0) {
                Joueurs->getJoueurs()[cible - 1]->setLimitation(1);
                cout << "Le joueur " << cible << " ne peux plus avancer" << endl;
            }
        }

    }
    
    if (nomCarte == "Parade") {                                                                                                         //gestion carte parade

        string Parade = Joueurs->getJoueurs()[tour - 1]->getMainJoueur()[choix - 1]->getParade();
        if (Parade == "Feu vert") {
                
            int peutParer = Joueurs->getJoueurs()[tour - 1]->getFeuRouge();                                 //check si il a bien un fey
            if (peutParer == 1)                                                                 
            {

                cout << " vous pouvez de nouveau avancer" << endl;
                Joueurs->getJoueurs()[tour - 1]->setFeuRouge(0);
            }
            else
            {                                                                                              // ne le jeu pas si pas de feu rouge sur le joueur 
                cout << " vous n'avez pas de raison d'utiliser cette carte " << endl;
                this->choixCarte(tour, choix, i, deck, Joueurs);
            }

        }

        if (Parade == "Fin de limitation") {                                                            //same pour tout les autres cartes parades
            int peutParer = Joueurs->getJoueurs()[tour - 1]->getLimitation();
            if (peutParer == 1)
            {

                cout << " vous pouvez de nouveau avancer" << endl;
                Joueurs->getJoueurs()[tour - 1]->setLimitation(0);
            }
            else
            {
                cout << " vous n'avez pas de raison d'utiliser cette carte " << endl;
                this->choixCarte(tour, choix, i, deck, Joueurs);
            }

        }

        if (Parade == "Essence") {
            int peutParer = Joueurs->getJoueurs()[tour - 1]->getEssence();
            if (peutParer == 1)
            {

                cout << " vous pouvez de nouveau avancer" << endl;
                Joueurs->getJoueurs()[tour - 1]->setEssence(0);
            }
            else
            {
                cout << " vous n'avez pas de raison d'utiliser cette carte " << endl;
                this->choixCarte(tour, choix, i, deck, Joueurs);
            }

        }

        if (Parade == "Roue de secours") {
            int peutParer = Joueurs->getJoueurs()[tour - 1]->getCreve();
            if (peutParer == 1)
            {

                cout << " vous pouvez de nouveau avancer" << endl;
                Joueurs->getJoueurs()[tour - 1]->setCreve(0);
            }
            else
            {
                cout << " vous n'avez pas de raison d'utiliser cette carte " << endl;
                this->choixCarte(tour, choix, i, deck, Joueurs);
            }

        }

        if (Parade == "Reparation") {
            int peutParer = Joueurs->getJoueurs()[tour - 1]->getAccident();
            if (peutParer == 1)
            {

                cout << " vous pouvez de nouveau avancer" << endl;
                Joueurs->getJoueurs()[tour - 1]->setAccident(0);
            }
            else
            {
                cout << " vous n'avez pas de raison d'utiliser cette carte " << endl;
                this->choixCarte(tour, choix, i, deck, Joueurs);
            }

        }

    }                                                                                           
 
    int s = Joueurs->getJoueurs()[tour - 1]->getStade();                                                            //verification si à la fin du tour le joueur n'est pas à 1000 bornes et l'envoie vers victoire
    cout << "Vous en etes maintenant a " << s << " bornes" << endl;
    if ( s == 1000 )
    {
        this->victoire(tour, Joueurs);
    }

}

void jeu::choixCarte(int tour, int choix,int i, Deck* deck, listeJoueurs* Joueurs) {
    int defausse;
    system("pause");
    cout << "Vous pouvez choisir une autre carte Jouable ou vous defaussez 2 pour la defausse 1 pour jouer une autre carte" << endl;                                             
    while (!(cin >> defausse) || defausse < 1 || defausse >2) {                                                                             //valeur defausse pour savoir si il veut deffausser ou jouer une carte 
        cin.clear();
        cin.ignore(6666, '\n');
        cout << "faites un choix valide entre 1 ou 2 (1 pour jouer une carte 2 pour la defausse)" << endl;                          
    }
    if (defausse == 1) {
        cout << "Choississez une carte que vous pourrez jouez!" << endl;
        Joueurs->getJoueurs()[tour - 1]->afficherMain();

        while (!(cin >> choix) || choix < 1 || choix > 7) {
            cin.clear();
            cin.ignore(6666, '\n');
            cout << "faites un choix valide entre 1 et 7" << endl;

        }
        this->jouerCartes(tour, choix,i, deck, Joueurs);
    }
    else {
        Joueurs->getJoueurs()[tour - 1]->afficherMain();
        cout << "Quelle carte voulez vous defaussez ?" << endl;
        while (!(cin >> choix) || choix < 1 || choix > 7) {
            cin.clear();
            cin.ignore(6666, '\n');
            cout << "faites un choix valide entre 1 et 7" << endl;

        }
        Joueurs->getJoueurs()[tour - 1]->choisir(tour, choix, deck);
    }
}


void jeu::afficherMenu() {

                                                                     
    int choix;
    int choixDynamique = 1;
    bool gameOn = true;
    bool test = true;
    la:

    while (gameOn != false) {
        while (test == true)
        {
            system("cls");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                cout << "                                                                      _____ ______       ___      ___           ___           _______                      " << endl;
                cout << "                                                                     |\\   _ \\  _   \\    |\\  \\    |\\  \\         |\\  \\         |\\  ___ \\                     " << endl;
                cout << "                                                                     \\ \\  \\\\\\__\\ \\  \\   \\ \\  \\   \\ \\  \\        \\ \\  \\        \\ \\   __/|                    " << endl;
                cout << "                                                                      \\ \\  \\\\|__| \\  \\   \\ \\  \\   \\ \\  \\        \\ \\  \\        \\ \\  \\_|/__                  " << endl;
                cout << "                                                                       \\ \\  \\    \\ \\  \\   \\ \\  \\   \\ \\  \\____    \\ \\  \\____    \\ \\  \\_|\\ \\                 " << endl;
                cout << "                                                                        \\ \\__\\    \\ \\__\\   \\ \\__\\   \\ \\_______\\   \\ \\_______\\   \\ \\_______\\                " << endl;
                cout << "                                                                         \\|__|     \\|__|    \\|__|    \\|_______|    \\|_______|    \\|_______|                " << endl;
                cout << "                                                                                                                                                           " << endl;
                cout << "                                                                                                                                                           " << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                cout << "                                                                                                                                                           " << endl;
                cout << "                                                                      ________      ________      ________      ________       _______       ________      " << endl;
                cout << "                                                                     |\\   __  \\    |\\   __  \\    |\\   __  \\    |\\   ___  \\    |\\  ___ \\     |\\   ____\\     " << endl;
                cout << "                                                                     \\ \\  \\|\\ /_   \\ \\  \\|\\  \\   \\ \\  \\|\\  \\   \\ \\  \\\\ \\  \\   \\ \\   __/|    \\ \\  \\___|_    " << endl;
                cout << "                                                                      \\ \\   __  \\   \\ \\  \\\\\\  \\   \\ \\   _  _\\   \\ \\  \\\\ \\  \\   \\ \\  \\_|/__   \\ \\_____  \\   " << endl;
                cout << "                                                                       \\ \\  \\|\\  \\   \\ \\  \\\\\\  \\   \\ \\  \\\\  \\|   \\ \\  \\\\ \\  \\   \\ \\  \\_|\\ \\   \\|____|\\  \\  " << endl;
                cout << "                                                                        \\ \\_______\\   \\ \\_______\\   \\ \\__\\\\ _\\    \\ \\__\\\\ \\__\\   \\ \\_______\\    ____\\_\\  \\  " << endl;
                cout << "                                                                         \\|_______|    \\|_______|    \\|__|\\|__|    \\|__| \\|__|    \\|_______|   |\\_________\\ " << endl;
                cout << "                                                                                                                                               \\|_________|" << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                                                                  
                                                                  





   

                
                if (choixDynamique == 1) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                }
            cout << endl << endl << endl << endl;
            cout << "                                                                                                --------------------------------- " << endl;
            cout << "                                                                                                |               1               |" << endl;
            cout << "                                                                                                |                               |" << endl;
            cout << "                                                                                                | Commencer une nouvelle partie |" << endl;
            cout << "                                                                                                |                               |" << endl;
            cout << "                                                                                                --------------------------------- " << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            if (choixDynamique == 2) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
            }
            cout << "                                                                                                --------------------------------- " << endl;
            cout << "                                                                                                |               2               |" << endl;
            cout << "                                                                                                |                               |" << endl;
            cout << "                                                                                                |             Regles            |" << endl;
            cout << "                                                                                                |                               |" << endl;
            cout << "                                                                                                --------------------------------- " << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            if (choixDynamique == 3) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
            }
            cout << "                                                                                                --------------------------------- " << endl;
            cout << "                                                                                                |               3               |" << endl;
            cout << "                                                                                                |                               |" << endl;
            cout << "                                                                                                |            A propos           |" << endl;
            cout << "                                                                                                |                               |" << endl;
            cout << "                                                                                                --------------------------------- " << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            if (choixDynamique == 4) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
            }
            cout << "                                                                                                --------------------------------- " << endl;
            cout << "                                                                                                |               4               |" << endl;
            cout << "                                                                                                |                               |" << endl;
            cout << "                                                                                                |    Quittez ce magnifique jeu  |" << endl;
            cout << "                                                                                                |                               |" << endl;
            cout << "                                                                                                --------------------------------- " << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
            cout << "                                                                                     (utiliser les fleches directionnelles et appuyer sur entrer)" << endl;



            int c, ec;  //pour l'utilisation des flèches directionnels 
            c = _getch();
            if (c == 224) { // caractere etendu
                ec = _getch();


                if (ec == ARROW_UP) {
                    choixDynamique --;
                    if (choixDynamique < 1) {
                        choixDynamique = 1;
                    }
             }
                if (ec == ARROW_DOWN) {
                 choixDynamique ++; 
                 if (choixDynamique > 4) {
                     choixDynamique = 4;
                 }
             }
                

           }
            if (c == 13) {
                test = false;
            }
        }


        switch (choixDynamique)                                     //pour le choix 
        {
        case 1:
            cout << "La partie va bientot commencer " << endl;                                                  
            gameOn = false;
            Sleep(1000);
            system("cls");
            break;
        case 2:
            cout << endl << "Le but du jeu, il faut arrive le plus rapidement posssible en evitant et en faisant des coups-fourrés a vous adversaire pour arriver a 1000 Bornes, pas plus pas moins !" << endl;
            cout << endl << "Le mille Bornes est un jeu qui se joue de 2 a 4 joueurs dans le sens des aiguilles d'une montre " << endl;
            cout << "Une carte vous est automatiquement distribué à chaque tour pour en avoir  toujours 7 dans votre main" << endl;
            cout << "Vous devez imperativement avoir une carte Feu vert pour démarer sinon, la défausse est la seule solution !" << endl;
            cout << endl << "Il existe type de cartes : " << endl;
            cout << endl << " - Les cartes Attaques permettent de stopper ou retarder un joueur dans sa course " << endl;
            cout << "   -- Limite de vitesse / Feu rouge / Crevaison / Panne dessence / Accident" << endl;
            cout << endl << " - Les cartes Bornes vous permettent d'avancer de 25 a 200 bornes " << endl;
            cout << "   -- 25 / 50 / 75 / 100 / 200 " << endl;
            cout << endl << " - Les carte Bottes  permettent de vous immunisé contre une attaque bien précise" << endl;
            cout << "   -- Increvable / Citerne d'essence / As du volant / Vehicule Prioriataire" << endl;
            cout << endl << " - Les cartes parades vont vous servir à contrer les attaques de vos adversaires" << endl;
            cout << "   -- Fin de limite de vitesse / Feu vert / Essence / Roue de secours / Reparation" << endl;
            cout << endl << "Que le meilleur gagne" << endl;
            test = true;
            cout << "Appuie sur un touche pour revenir à l'ecran d'accueil" << endl;
            system("pause > nul");
            goto la;
            break;
        case 3:
            cout << endl << "Fait par Mathys Vende" << endl;
            cout << "Musique compose Yohann Durel" << endl;
            cout << "Avec l'aide de Antoine Deyris et Timothee Delamare les wati-bro" << endl;
            cout << "Appuie sur un touche pour revenir à l'ecran d'accueil" << endl;
            test = true;
            system("pause > nul");
            goto la;
            break;
        case 4:
            cout << "Fin du jeu";
            exit(EXIT_FAILURE );
            break;
        default:
            cout << "Veuillez choisir une option valide";
            cout << "Recomencez";
            cin >> choix;
            break;
        }

    }

}



int jeu::init(listeJoueurs* Joueurs) {

    int i;
    cout << "Combien de joueurs etes-vous ? ";
    while (!(cin >> i) || i < 1 || i >4) {
        cin.clear();
        cin.ignore(6666, '\n');
        cout << "Chosis entre un et quatre joueur" << endl;

    }

    for (int n = 0; n < i; n++) {
        string nom;
        cout << "                                                                               Quelle est le nom du joueur "<< n+1 << endl;
        cout << "                                                                                               ";
        cin >> nom;
        Joueurs->getJoueurs()[n]->setNom(nom);
        
    }

    return i;




}


int jeu::attaqueJoueur(listeJoueurs* Joueurs, int i) {
    int cible;

    cout << " Quelle joueur veux tu goumer ?" << endl;
    for (int x = 0; x < i; x++)
    {
        cout << " " << x + 1 << " pour le joueur : " << Joueurs->getJoueurs()[x]->getNom() << endl;  // attaque d'un joueur récup sur la liste et verif que c'est un joueur valide 
    }
    cout << endl;
    cin >> cible;
    while (cible <= 0 || cible >= i + 1) {
        cout << "Choisi un joueur valide " << endl;
        cin >> cible;
    }
    return cible;


}







void jeu::victoire(int joueurs, listeJoueurs* Joueurs) {
    cout << " Bravo à toi " << Joueurs->getJoueurs()[joueurs - 1]->getNom() << " tu remportes la partie" << endl;                                                               
    cout << "c'est ici que se termine l'aventure du milles Bornes si appuie sur une touche je me fermerais :'( n'hésiter pas a y rejouer ! " << endl;       
    system("pause > nul");
    exit(EXIT_FAILURE);


}

