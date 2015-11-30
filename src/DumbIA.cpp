#include "DumbIA.hpp"

DumbIA::DumbIA(Etat* mainState): IA(mainState) {

}

void DumbIA::findWormsProche() {
  int i = 0;

  while(i<mainState->listeWormsJoueurs.size()) {
    if ( mainState->listeWormsJoueurs[i].worms->getPosition_x() + mainState->listeWormsJoueurs[i].worms->getPosition_y() < wormsProche->getPosition_x() + wormsProche->getPosition_y()) {
      wormsProche=mainState->listeWormsJoueurs[i].worms;
      i++;
    } else {
      i++;
    }
  }
}

bool DumbIA::deplacement () {

  if (wormsProche->getPosition_x() > mainState->listeWormsJoueurs[mainState->placeWormsActif].worms->getPosition_x()){
    
  }


}
