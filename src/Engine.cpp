#include "Engine.hpp"


bool Engine::deplacementDroite(Etat* etat){
  bool verif=false;
  int x=etat->listeWormsJoueurs[etat->placeWormsActif].worms->getPosition_x();
  int y=etat->listeWormsJoueurs[etat->placeWormsActif].worms->getPosition_y();
  if(x>=0 && x<etat->map.getLargeur()-1){
    int type=etat->map.matriceTerrain[x+1][y]->getType();
    switch (type) {
      case 0: etat->listeWormsJoueurs[etat->placeWormsActif].worms->setPosition_x(x+1);verif=true;break; //air
      case 1: etat->listeWormsJoueurs[etat->placeWormsActif].worms->setPosition_x(x+1);verif=true;break; //gaz
      case 2: etat->listeWormsJoueurs[etat->placeWormsActif].worms->setPosition_x(x+1);verif=true;break; //eau
      default: //terre ou roche ou metal
              if(y>0 && y<etat->map.getHauteur()){
                type=etat->map.matriceTerrain[x+1][y-1]->getType();
                switch (type) {
                  case 0: etat->listeWormsJoueurs[etat->placeWormsActif].worms->setPosition_y(y-1);etat->listeWormsJoueurs[etat->placeWormsActif].worms->setPosition_x(x+1);verif=true;break; //air
                  case 1: etat->listeWormsJoueurs[etat->placeWormsActif].worms->setPosition_y(y-1);etat->listeWormsJoueurs[etat->placeWormsActif].worms->setPosition_x(x+1);verif=true;break; //gaz
                  case 2: etat->listeWormsJoueurs[etat->placeWormsActif].worms->setPosition_y(y-1);etat->listeWormsJoueurs[etat->placeWormsActif].worms->setPosition_x(x+1);verif=true;break; //eau
                  default : break;
                }
              }
      }
    }
    return verif;
}

bool Engine::deplacementGauche(Etat* etat){
  bool verif=false;
  int x=etat->listeWormsJoueurs[etat->placeWormsActif].worms->getPosition_x();
  int y=etat->listeWormsJoueurs[etat->placeWormsActif].worms->getPosition_y();
  if(x>0 && x<etat->map.getLargeur()){
    int type=etat->map.matriceTerrain[x-1][y]->getType();
    switch (type) {
      case 0: etat->listeWormsJoueurs[etat->placeWormsActif].worms->setPosition_x(x-1);verif=true;break; //air
      case 1: etat->listeWormsJoueurs[etat->placeWormsActif].worms->setPosition_x(x-1);verif=true;break; //gaz
      case 2: etat->listeWormsJoueurs[etat->placeWormsActif].worms->setPosition_x(x-1);verif=true;break; //eau
      default: //terre ou roche ou metal
              if(y>0 && y<etat->map.getHauteur()){
                type=etat->map.matriceTerrain[x-1][y-1]->getType();
                switch (type) {
                  case 0: etat->listeWormsJoueurs[etat->placeWormsActif].worms->setPosition_y(y-1);etat->listeWormsJoueurs[etat->placeWormsActif].worms->setPosition_x(x-1);verif=true;break; //air
                  case 1: etat->listeWormsJoueurs[etat->placeWormsActif].worms->setPosition_y(y-1);etat->listeWormsJoueurs[etat->placeWormsActif].worms->setPosition_x(x-1);verif=true;break; //gaz
                  case 2: etat->listeWormsJoueurs[etat->placeWormsActif].worms->setPosition_y(y-1);etat->listeWormsJoueurs[etat->placeWormsActif].worms->setPosition_x(x-1);verif=true;break; //eau
                  default : break;
                }
              }
    }
  }
  return verif;
}
