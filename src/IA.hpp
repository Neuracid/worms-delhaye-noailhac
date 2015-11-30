#ifndef IA_H
#define IA_H
#include "Etat.hpp"
#include "Engine.hpp"

class IA {
public:
  IA(Etat* mainState);
  virtual void initActif (Etat* mainState);

protected:
  Etat* mainState;
  int x;
  int y;
  Joueur::Team team;

};
#endif
