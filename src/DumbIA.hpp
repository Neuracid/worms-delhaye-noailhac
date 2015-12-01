#ifndef DUMBIA_H
#define DUMBIA_H
#include "IA.hpp"

class DumbIA: public IA {
public:
  DumbIA(Etat* mainState);
  void findWormsProche();

private:
  bool deplacement();
  bool attaque();
  bool tirPossible();
  bool grimperPossible();
  Worms* wormsProche;

};
#endif
