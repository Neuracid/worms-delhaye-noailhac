#include "DumbIA.hpp"

DumbIA::DumbIA(Etat* mainState): IA(mainState) {

}

void DumbIA::findWormsProche() {
  int i = 0;
  Worms* wormsIni = new Worms(10000,10000);
  wormsProche=wormsIni;

  for(i=0;i<mainState->listeWormsJoueurs.size();i++) {
    if ( team != mainState->listeWormsJoueurs[i].joueur->getTeam() && i != placeWormsActif && std::sqrt(std::pow(mainState->listeWormsJoueurs[i].worms->getPosition_x()-x,2) + std::pow(mainState->listeWormsJoueurs[i].worms->getPosition_y()-y,2)) < std::sqrt(std::pow(wormsProche->getPosition_x()-x,2) + std::pow(wormsProche->getPosition_y()-y,2)) ){
      wormsProche=mainState->listeWormsJoueurs[i].worms;
    } else {
    }
  }
}

bool DumbIA::deplacement () {

  if (true){

  }
  return false;
}

bool DumbIA::attaque() {
  if (true) {

  }
  return false;
}

bool DumbIA::tirPossible() {
return false;
}
