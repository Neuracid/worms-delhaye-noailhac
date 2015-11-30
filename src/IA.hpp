#ifndef IA_H
#define IA_H
#include "Etat.hpp"
#include "Engine.hpp"
#include <complex>

class IA {
public:
  IA(Etat* mainState);
  virtual void initActif (Etat* mainState);

protected:
  Etat* mainState;
  int x;
  int y;
  int placeWormsActif;
  Joueur::Team team;

};
#endif
