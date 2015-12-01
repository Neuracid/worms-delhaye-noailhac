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

bool IA::activeIA(){
  for(int i=0;i<mainState->listeJoueursIA.size();i++){
    if(mainState->listeJoueursIA[i]==team){
      return true;
    }
  }
  return false;
}
