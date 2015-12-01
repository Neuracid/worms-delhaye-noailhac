#ifndef IA_H
#define IA_H
#include "Etat.hpp"
#include <cmath>
#include "engine.hpp"

class IA {
public:
  IA(Etat* mainState, Engine* engine);
  virtual void initActif (Etat* mainState);

protected:
  Etat* mainState;
  Engine* engine;
  int x;
  int y;
  int placeWormsActif;
  Joueur::Team team;

};
#endif
