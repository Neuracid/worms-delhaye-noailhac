#include "IA.hpp"

IA::IA(Etat* mainState,Engine* engine){
  initActif(mainState);
  this->mainState = mainState;
  this->engine=engine;
}

void IA::initActif(Etat* mainState){
  this->x = mainState->listeWormsJoueurs[mainState->placeWormsActif].worms->getPosition_x();
  this->y = mainState->listeWormsJoueurs[mainState->placeWormsActif].worms->getPosition_y();
  this->team = mainState->listeWormsJoueurs[mainState->placeWormsActif].joueur->getTeam();
  this->placeWormsActif=mainState->placeWormsActif;
}
