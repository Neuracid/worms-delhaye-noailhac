#include "Commandes.hpp"


bool Commandes::deplacementDroite(Worms worm){
  bool verif=false;
  int x=worm.getPosition_x();
  int y=worm.getPosition_y();
  int type=etat.listeBloc[x+1][y]->getType();
  if(x>=0 && x<etat.grille.getLargeur()-1){
    switch (type) {
      case 0: worm.setPosition_x(x+1);verif=true;break; //air
      case 1: worm.setPosition_x(x+1);verif=true;break; //gaz
      case 2: worm.setPosition_x(x+1);verif=true;break; //eau
      default: //terre ou roche ou metal
              if(y>0 && y<etat.grille.getHauteur()){
                type=etat.listeBloc[x-1][y+1]->getType();
                switch (type) {
                  case 0: worm.setPosition_x(x+1);worm.setPosition_y(y+1);verif=true;break; //air
                  case 1: worm.setPosition_x(x+1);worm.setPosition_y(y+1);verif=true;break; //gaz
                  case 2: worm.setPosition_x(x+1);worm.setPosition_y(y+1);verif=true;break; //eau
                  default : break;
                }
              }
      }
    }
    return verif;
}

bool Commandes::deplacementGauche(Worms worm){
  bool verif=false;
  int x=worm.getPosition_x();
  int y=worm.getPosition_y();
  int type=etat.listeBloc[x-1][y]->getType();
  if(x>0 && x<etat.grille.getLargeur()){
    switch (type) {
      case 0: worm.setPosition_x(x-1);verif=true;break; //air
      case 1: worm.setPosition_x(x-1);verif=true;break; //gaz
      case 2: worm.setPosition_x(x-1);verif=true;break; //eau
      default: //terre ou roche ou metal
              if(y>0 && y<etat.grille.getHauteur()){
                type=etat.listeBloc[x-1][y+1]->getType();
                switch (type) {
                  case 0: worm.setPosition_x(x-1);worm.setPosition_y(y+1);verif=true;break; //air
                  case 1: worm.setPosition_x(x-1);worm.setPosition_y(y+1);verif=true;break; //gaz
                  case 2: worm.setPosition_x(x-1);worm.setPosition_y(y+1);verif=true;break; //eau
                  default : break;
                }
              }
    }
  }
  return verif;
}
