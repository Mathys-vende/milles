#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#ifdef _WIN32
#include <windows.h>
#endif
#include <algorithm>
#include <string>
#include <iomanip>
#include <random>
#include "joueur.h"
#include"listeJoueurs.h"

using namespace std;


class plateau


{
private:
    vector<int> tableau;
    int largeur;
    int hauteur;



public:
    int getIndice(int x, int y);
    plateau(int largeur, int hauteur);


    void set(int x, int y, int value);
    int get(int x, int y);
    void afficher(int, int,int, listeJoueurs*);



};

