#ifndef NORMAL_H
#define NORMAL_H
#include "IA.hpp"

class NormalIA: public IA {
public:
  NormalIA(Etat* mainState, Engine* engine);
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
