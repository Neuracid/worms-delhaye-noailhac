#ifndef DUMBIA_H
#define DUMBIA_H
#include "IA.hpp"

class DumbIA: public IA {
public:
  DumbIA(Etat* mainState);
  void findWormsProche();
  bool tirPossible(int direction);
  bool barricaderPosiible();
  bool deplacement();
  bool attaque();
  bool grimperPossible();
  bool deplacementPossible();

private:

  Worms* wormsProche;

};
#endif
