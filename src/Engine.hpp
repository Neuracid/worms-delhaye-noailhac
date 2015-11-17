#ifndef ENGINE_H
#define ENGINE_H
#include "Etat.hpp"
#include <vector>

class Engine {

public:

  bool deplacementDroite(Etat* etat);
  bool deplacementGauche(Etat* etat);
  void gravite(Etat* etat);

private:


};
#endif
