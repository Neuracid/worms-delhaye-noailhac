#include "Commandes.hpp"


bool Commandes::deplacementDroite(Etat &etat){
  bool verif=false;
  int x=etat.listeWormsJoueurs[etat.placeWormsActif].worms->getPosition_x();
  int y=etat.listeWormsJoueurs[etat.placeWormsActif].worms->getPosition_y();
  if(x>=0 && x<etat.grille.getLargeur()-1){
    int type=etat.listeBloc.matriceTerrain[x+1][y]->getType();
    switch (type) {
      case 0: etat.listeWormsJoueurs[etat.placeWormsActif].worms->setPosition_x(x+1);verif=true;break; //air
      case 1: etat.listeWormsJoueurs[etat.placeWormsActif].worms->setPosition_x(x+1);verif=true;break; //gaz
      case 2: etat.listeWormsJoueurs[etat.placeWormsActif].worms->setPosition_x(x+1);verif=true;break; //eau
      default: //terre ou roche ou metal
              if(y>0 && y<etat.grille.getHauteur()){
                type=etat.listeBloc.matriceTerrain[x-1][y+1]->getType();
                switch (type) {
                  case 0: etat.listeWormsJoueurs[etat.placeWormsActif].worms->setPosition_x(x+1);etat.listeWormsJoueurs[etat.placeWormsActif].worms->setPosition_y(y+1);verif=true;break; //air
                  case 1: etat.listeWormsJoueurs[etat.placeWormsActif].worms->setPosition_x(x+1);etat.listeWormsJoueurs[etat.placeWormsActif].worms->setPosition_y(y+1);verif=true;break; //gaz
                  case 2: etat.listeWormsJoueurs[etat.placeWormsActif].worms->setPosition_x(x+1);etat.listeWormsJoueurs[etat.placeWormsActif].worms->setPosition_y(y+1);verif=true;break; //eau
                  default : break;
                }
              }
      }
    }
    return verif;
}

bool Commandes::deplacementGauche(Etat &etat){
  bool verif=false;
  int x=etat.listeWormsJoueurs[etat.placeWormsActif].worms->getPosition_x();
  int y=etat.listeWormsJoueurs[etat.placeWormsActif].worms->getPosition_y();
  if(x>0 && x<etat.grille.getLargeur()){
    int type=etat.listeBloc.matriceTerrain[x-1][y]->getType();
    switch (type) {
      case 0: etat.listeWormsJoueurs[etat.placeWormsActif].worms->setPosition_x(x-1);verif=true;break; //air
      case 1: etat.listeWormsJoueurs[etat.placeWormsActif].worms->setPosition_x(x-1);verif=true;break; //gaz
      case 2: etat.listeWormsJoueurs[etat.placeWormsActif].worms->setPosition_x(x-1);verif=true;break; //eau
      default: //terre ou roche ou metal
              if(y>0 && y<etat.grille.getHauteur()){
                type=etat.listeBloc.matriceTerrain[x-1][y+1]->getType();
                switch (type) {
                  case 0: etat.listeWormsJoueurs[etat.placeWormsActif].worms->setPosition_x(x-1);etat.listeWormsJoueurs[etat.placeWormsActif].worms->setPosition_y(y+1);verif=true;break; //air
                  case 1: etat.listeWormsJoueurs[etat.placeWormsActif].worms->setPosition_x(x-1);etat.listeWormsJoueurs[etat.placeWormsActif].worms->setPosition_y(y+1);verif=true;break; //gaz
                  case 2: etat.listeWormsJoueurs[etat.placeWormsActif].worms->setPosition_x(x-1);etat.listeWormsJoueurs[etat.placeWormsActif].worms->setPosition_y(y+1);verif=true;break; //eau
                  default : break;
                }
              }
    }
  }
  return verif;
}
