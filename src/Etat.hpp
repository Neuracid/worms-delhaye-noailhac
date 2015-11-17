#ifndef ETAT_H
#define ETAT_H
#include <vector>
#include "WormsJoueur.hpp"
#include "Map.hpp"
#include <ctime>
#include <iostream>
#include <fstream>

class Etat{
public:
  std::vector<WormsJoueur> listeWormsJoueurs;
  int placeWormsActif=0;

  Map map;

  //std::time_t result = std::time(NULL);

  Etat();
  void setWormsJoueur(int x, int y,Joueur::Team a);

protected:

private:

};
#endif
