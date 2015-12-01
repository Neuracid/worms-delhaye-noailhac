#ifndef ETAT_H
#define ETAT_H
#include <vector>
#include "WormsJoueur.hpp"
#include "Map.hpp"
#include <ctime>
#include <iostream>
#include <fstream>
#include <pthread.h>

class Etat{
public:
  std::vector<WormsJoueur> listeWormsJoueurs;
  std::vector<Joueur::Team> listeJoueursIA;
  int placeWormsActif=0;

  Map map;



  Etat();
  void setWormsJoueur(int x, int y,Joueur::Team a);
  float getTime();
  void setTimeToZero();
  int getTempTour();
  void setTempTour(int tempTour);
protected:

private:
    time_t depart=time(&depart);
    int tempTour=120;
};
#endif
