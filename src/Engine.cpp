#include "Engine.hpp"

//COMMANDES
bool Engine::deplacementDroite(Etat* etat, int i){
  bool verif=false;
  int x=etat->listeWormsJoueurs[i].worms->getPosition_x();
  int y=etat->listeWormsJoueurs[i].worms->getPosition_y();
  int direction=etat->listeWormsJoueurs[i].worms->getDirection();
  if(direction==-1 && i==etat->placeWormsActif){
    etat->listeWormsJoueurs[i].worms->setDirection(Worms::right);
    return verif;
  }
  if(x>=0 && x<etat->map.getLargeur()-1){
    int type=etat->map.matriceTerrain[x+1][y]->getType();
    switch (type) {
      case 0: etat->listeWormsJoueurs[i].worms->setPosition_x(x+1);verif=true;break; //air
      case 1: etat->listeWormsJoueurs[i].worms->setPosition_x(x+1);verif=true;break; //gaz
      case 2: etat->listeWormsJoueurs[i].worms->setPosition_x(x+1);verif=true;break; //eau
      default: //terre ou roche ou metal
              if(y>0 && y<etat->map.getHauteur()){
                type=etat->map.matriceTerrain[x+1][y-1]->getType();
                switch (type) {
                  case 0: etat->listeWormsJoueurs[i].worms->setPosition_y(y-1);etat->listeWormsJoueurs[i].worms->setPosition_x(x+1);verif=true;break; //air
                  case 1: etat->listeWormsJoueurs[i].worms->setPosition_y(y-1);etat->listeWormsJoueurs[i].worms->setPosition_x(x+1);verif=true;break; //gaz
                  case 2: etat->listeWormsJoueurs[i].worms->setPosition_y(y-1);etat->listeWormsJoueurs[i].worms->setPosition_x(x+1);verif=true;break; //eau
                  default : break;
                }
              }
      }
    }
    return verif;
}

bool Engine::deplacementGauche(Etat* etat,int i){
  bool verif=false;
  int x=etat->listeWormsJoueurs[i].worms->getPosition_x();
  int y=etat->listeWormsJoueurs[i].worms->getPosition_y();
  int direction=etat->listeWormsJoueurs[i].worms->getDirection();
  if(direction==1 && i==etat->placeWormsActif){
    etat->listeWormsJoueurs[i].worms->setDirection(Worms::left);
    return verif;
  }
  if(x>0 && x<etat->map.getLargeur()){
    int type=etat->map.matriceTerrain[x-1][y]->getType();
    switch (type) {
      case 0: etat->listeWormsJoueurs[i].worms->setPosition_x(x-1);verif=true;break; //air
      case 1: etat->listeWormsJoueurs[i].worms->setPosition_x(x-1);verif=true;break; //gaz
      case 2: etat->listeWormsJoueurs[i].worms->setPosition_x(x-1);verif=true;break; //eau
      default: //terre ou roche ou metal
              if(y>0 && y<etat->map.getHauteur()){
                type=etat->map.matriceTerrain[x-1][y-1]->getType();
                switch (type) {
                  case 0: etat->listeWormsJoueurs[i].worms->setPosition_y(y-1);etat->listeWormsJoueurs[i].worms->setPosition_x(x-1);verif=true;break; //air
                  case 1: etat->listeWormsJoueurs[i].worms->setPosition_y(y-1);etat->listeWormsJoueurs[i].worms->setPosition_x(x-1);verif=true;break; //gaz
                  case 2: etat->listeWormsJoueurs[i].worms->setPosition_y(y-1);etat->listeWormsJoueurs[i].worms->setPosition_x(x-1);verif=true;break; //eau
                  default : break;
                }
              }
    }
  }
  return verif;
}

void Engine::changementDeJoueur(Etat* etat){
    int nombreDeWorms=etat->listeWormsJoueurs.size();
    int position=(etat->placeWormsActif+1)%nombreDeWorms;
    int start=etat->placeWormsActif;
    while(etat->listeWormsJoueurs[position%nombreDeWorms].worms->getVie()<=0 && start!=position){
      position=(position+1)%nombreDeWorms;
    }
    if(start==position && etat->listeWormsJoueurs[position%nombreDeWorms].worms->getVie()==0)
    std::cout << "Plus de worms disponible" << std::endl;
    etat->placeWormsActif=position%nombreDeWorms;
    nbDeplacements=2;
    capaUtilise=false;
    etat->setTimeToZero();
}

void Engine::kungfu(Etat* etat){
  int x=etat->listeWormsJoueurs[etat->placeWormsActif].worms->getPosition_x();
  int y=etat->listeWormsJoueurs[etat->placeWormsActif].worms->getPosition_y();
  int direction=etat->listeWormsJoueurs[etat->placeWormsActif].worms->getDirection();
  etat->listeWormsJoueurs[etat->placeWormsActif].worms->setType(Worms::kungfu);
  for(int i=0; i<etat->listeWormsJoueurs.size();i++){
    if(etat->listeWormsJoueurs[i].worms->getPosition_x()==x+direction && etat->listeWormsJoueurs[i].worms->getPosition_y()==y){
      switch (direction) {
        case 1:deplacementDroite(etat,i);
              etat->listeWormsJoueurs[i].worms->setVie(etat->listeWormsJoueurs[i].worms->getVie()-50);break;
        case -1:deplacementGauche(etat,i);
              etat->listeWormsJoueurs[i].worms->setVie(etat->listeWormsJoueurs[i].worms->getVie()-50);break;
      }
    }
  }
  capaUtilise=true;
}

void Engine::mineGaz(Etat* etat){
  int x=etat->listeWormsJoueurs[etat->placeWormsActif].worms->getPosition_x();
  int y=etat->listeWormsJoueurs[etat->placeWormsActif].worms->getPosition_y();
  etat->map[x+etat->listeWormsJoueurs[etat->placeWormsActif].worms->getDirection()][y]->setType(Terrain::gaz);
  capaUtilise=true;
}


//REGLES
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

void Engine::regleDeTerrain(Etat* etat){
  int x,y,pv;
  for(int i=0; i<etat->listeWormsJoueurs.size();i++){
    x=etat->listeWormsJoueurs[i].worms->getPosition_x();
    y=etat->listeWormsJoueurs[i].worms->getPosition_y();
    pv=etat->listeWormsJoueurs[i].worms->getVie();
    switch (etat->map[x][y]->getType()) {
      case 0:break;
      case 1:if(i==etat->placeWormsActif){etat->listeWormsJoueurs[i].worms->setVie((pv-10<0)?0:(pv-2));}break;
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
  changementDeJoueur(etat);
}

bool Engine::finTour(Etat* etat){
  if (nbDeplacements == 0) {
    return true;
  }
  else if ( capaUtilise == true) {
    return true;
  }
  else if (etat->getTime() >= etat->getTempTour()){
    return true;
  }
  else if (etat->listeWormsJoueurs[etat->placeWormsActif].worms->getVie() <= 0){
    return true;
  }
  else {
    return false;
  }

}


//GETSET
int Engine::getNbDeplacements(){
  return nbDeplacements;
}
void Engine::setNbDeplacements(int nb){
  nbDeplacements=nb;
}
bool Engine::getCapaUtilise(){
  return capaUtilise;
}
void Engine::setCapaUtilise(bool capaU){
  capaUtilise=capaU;
}
