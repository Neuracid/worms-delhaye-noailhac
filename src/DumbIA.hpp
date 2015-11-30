#ifndef DUMBIA_H
#define DUMBIA_H
#include "IA.hpp"

class DumbIA: public IA{
public:
  DumbIA(Etat* mainState);
private:
  bool deplacement();
  bool attaque();
  bool tirPossible();
  void findWormsProche();
  Worms* wormsProche;

};
#endif
