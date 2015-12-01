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
  printf("worms proche : x: %d y: %d\n",wormsProche->getPosition_x(), wormsProche->getPosition_y() );
}

bool DumbIA::deplacement () {

  if (true){

  }
  return true;
}

bool DumbIA::attaque() {
  if (true) {

  }
  return true;
}

bool DumbIA::tirPossible(int direction) {
  int x=mainState->listeWormsJoueurs[mainState->placeWormsActif].worms->getPosition_x();
  int y=mainState->listeWormsJoueurs[mainState->placeWormsActif].worms->getPosition_y();
  bool obstacle=false;
  bool joueur=false;
  x+=direction;

  while(x>=0 && x<mainState->map.getLargeur() && obstacle==false){
    for(int i=0; i<mainState->listeWormsJoueurs.size() ;i++){
      if(x==mainState->listeWormsJoueurs[i].worms->getPosition_x() && y==mainState->listeWormsJoueurs[i].worms->getPosition_y() ){
        joueur=true;
      }
    }
    switch (mainState->map[x][y]->getType()){
      case Terrain::metal:
      obstacle=true;
      break;
      case Terrain::roche:
      obstacle=true;
      break;
      case Terrain::terre:
      obstacle=true;
      break;
      default:
      break;
    }
    x+=direction;
  }
  printf(joueur ?"true" : "false");
  return joueur;
}

bool DumbIA::grimperPossible(){
int d=(wormsProche->getPosition_x()-x<0)?-1:1;
  if(y==1 || y== 0)
  return false;

  //[x+d][y] non vide && [x+d][y-1] non vide
  if((mainState->map[x+d][y]->getType()>2) && (mainState->map[x+d][y-1]->getType()>2))
  return true;

  return false;
}
