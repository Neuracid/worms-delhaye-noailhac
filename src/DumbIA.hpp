#ifndef DUMBIA_H
#define DUMBIA_H
#include "IA.hpp"

class DumbIA: public IA {
public:
  DumbIA(Etat* mainState, Engine* engine);
  void findWormsProche();
  bool tirPossible(int direction);
  bool barricaderPosible();
  bool deplacement();
  bool attaque();
  bool grimperPossible();
  bool deplacementPossible();
  bool kungFuPossible(int direction);

private:

  Worms* wormsProche;

};
#endif
