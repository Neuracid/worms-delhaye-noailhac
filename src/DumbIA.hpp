#ifndef DUMBIA_H
#define DUMBIA_H
#include "IA.hpp"

class DumbIA: public IA {
public:
  DumbIA(Etat* mainState, Engine* engine);
  void findWormsProche();
  bool deplacement();
  bool attaque();


private:
  bool grimperPossible();
  bool deplacementPossible();
  bool kungFuPossible(int direction);
  bool tirPossible(int direction);
  bool barricaderPosible();
  Worms* wormsProche;

};
#endif
