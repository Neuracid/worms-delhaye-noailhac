#ifndef ENGINE_H
#define ENGINE_H
#include "Etat.hpp"
#include <vector>
#include <iostream>

class Engine {

public:

  bool deplacementDroite(Etat* etat);
  bool deplacementGauche(Etat* etat);
  void kungfu(Etat* etat);
  void regleGravite(Etat* etat);
  void changementDeJoueur(Etat* etat);
  void regleDeTerrain(Etat* etat);
  void fonctionPourDebutNewEtat(Etat* etat);
  bool finTour(Etat* etat);
  int getNbDeplacements();
  void setNbDeplacements(int);
  bool getCapaUtilise();
  void setCapaUtilise(bool);

private:
  int nbDeplacements = 2;
  bool capaUtilise = false;


};
#endif
