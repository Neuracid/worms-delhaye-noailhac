#ifndef IA_H
#define IA_H
#include "Etat.hpp"
#include <cmath>
#include "Engine.hpp"

class IA {
public:
  IA(Etat* mainState);
  virtual void initActif (Etat* mainState);

protected:
  Etat* mainState;
  Engine engine;
  int x;
  int y;
  int placeWormsActif;
  Joueur::Team team;

};
#endif
