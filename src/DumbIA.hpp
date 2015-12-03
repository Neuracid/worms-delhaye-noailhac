#ifndef NORMAL_H
#define NORMAL_H
#include "IA.hpp"

class DumbIA: public IA {
public:
  DumbIA(Etat* mainState, Engine* engine);
  void findWormsProche();
  bool deplacement();


private:
  bool deplacementPossible();
  Worms* wormsProche;

};
#endif
