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

void Engine::regleGravite (Etat* etat) {
  for (int i = 0; i < etat->listeWormsJoueurs.size() ; i++) {
    int nbCasesVides=0;
    int x=etat->listeWormsJoueurs[i].worms->getPosition_x();
    int y=etat->listeWormsJoueurs[i].worms->getPosition_y();
    int pv=etat->listeWormsJoueurs[i].worms->getVie();
    while (y+1<etat->map.getHauteur() && etat->map[x][y+1]->getType() <3 ){
      nbCasesVides++;
      y++;
    }
    if (nbCasesVides == 1){
      etat->listeWormsJoueurs[i].worms->setPosition_y(y);
    }
    if (nbCasesVides > 1 ){
      etat->listeWormsJoueurs[i].worms->setPosition_y(y);
      etat->listeWormsJoueurs[i].worms->setVie(pv-(nbCasesVides-1)*10);
    }
  }
}

void Engine::regleChangementDeJoueur(Etat* etat){
    int nombreDeWorms=etat->listeWormsJoueurs.size();
    int position=(etat->placeWormsActif+1)%nombreDeWorms;
    int start=etat->placeWormsActif;
    while(etat->listeWormsJoueurs[position%nombreDeWorms].worms->getVie()<=0 && start!=position){
      position=(position+1)%nombreDeWorms;
    }
    if(start==position && etat->listeWormsJoueurs[position%nombreDeWorms].worms->getVie()==0)
    std::cout << "Plus de worms disponible" << std::endl;
    etat->placeWormsActif=position%nombreDeWorms;
}

void Engine::regleDeTerrain(Etat* etat){
  int x,y,pv;
  for(int i=0; i<etat->listeWormsJoueurs.size();i++){
    x=etat->listeWormsJoueurs[i].worms->getPosition_x();
    y=etat->listeWormsJoueurs[i].worms->getPosition_y();
    pv=etat->listeWormsJoueurs[i].worms->getVie();
    switch (etat->map[x][y]->getType()) {
      case 0:break;
      case 1:etat->listeWormsJoueurs[i].worms->setVie((pv-10<0)?0:(pv-10));break;
      case 2:etat->listeWormsJoueurs[i].worms->setVie(0); break;
      case 3:std::cout << "probleme car le worms est dans de la terre" << std::endl;break;
      case 4:std::cout << "probleme car le worms est dans de la roche" << std::endl;break;
      case 5:std::cout << "probleme car le worms est dans du metal" << std::endl;break;
      default: std::cout << "probleme car le worms est dans un type de terrain qui est inconnue" << std::endl;break;
    }
  }
}

void Engine::fonctionPourDebutNewEtat(Etat* etat){
  regleGravite(etat);
  regleDeTerrain(etat);
  regleChangementDeJoueur(etat);
}
