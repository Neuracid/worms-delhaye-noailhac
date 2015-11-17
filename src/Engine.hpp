#ifndef ENGINE_H
#define ENGINE_H
#include "Etat.hpp"
#include <vector>

class Engine {

public:

  bool deplacementDroite(Etat* etat);
  bool deplacementGauche(Etat* etat);
  void regleGravite(Etat* etat);
  void regleChangementDeJoueur(Etat* etat);


private:


};
#endif
