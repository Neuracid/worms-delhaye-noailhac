#ifndef ENGINE_H
#define ENGINE_H
#include "Etat.hpp"
#include <vector>
#include <iostream>

class Engine {

public:

  bool deplacement(Etat* etat,int i);
  bool kungfu(Etat* etat);
  void regleGravite(Etat* etat);
  void changementDeJoueur(Etat* etat);
  void regleDeTerrain(Etat* etat);
  void fonctionPourDebutNewEtat(Etat* etat);
  bool finTour(Etat* etat);
  int getNbDeplacements();
  void setNbDeplacements(int);
  bool getCapaUtilise();
  void setCapaUtilise(bool);
  void mineGaz(Etat* etat);
  void changementDeDirection(Etat* etat,Worms::Direction direction);
  void creuser(Etat* etat);
  bool barricader(Etat* etat);
  bool tir(Etat* etat);
  bool grappin(Etat* etat);

private:
  int nbDeplacements = 2;
  bool capaUtilise = false;


};
#endif
