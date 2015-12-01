#include "DumbIA.hpp"

DumbIA::DumbIA(Etat* mainState, Engine* engine): IA(mainState, engine) {

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
  Worms::Direction d=(wormsProche->getPosition_x()-x<0)?Worms::left : Worms::right;
  engine->changementDeDirection(mainState,d);

  if(barricaderPosible()==true){
    return engine->barricader(mainState);
  }
  if (deplacementPossible()==true){
    return engine->deplacement(mainState,placeWormsActif);
  }
  if(grimperPossible()==true){
    return engine->grappin(mainState);
  }
  return false;
}

bool DumbIA::attaque() {
  if (tirPossible(1)) {
    mainState->listeWormsJoueurs[mainState->placeWormsActif].worms->setDirection(Worms::right);
    engine.tir(mainState);
  }
  else if (tirPossible(-1)) {
    mainState->listeWormsJoueurs[mainState->placeWormsActif].worms->setDirection(Worms::left);
    engine.tir(mainState);
  }
  else if (kungFuPossible(1)) {
    mainState->listeWormsJoueurs[mainState->placeWormsActif].worms->setDirection(Worms::right);
    engine.kungfu(mainState);
  }
  else if (kungFuPossible(-1)) {
    mainState->listeWormsJoueurs[mainState->placeWormsActif].worms->setDirection(Worms::left);
    engine.kungfu(mainState);
  }
  else {
    return false;
  }
  return true;
}

bool DumbIA::tirPossible(int direction) {
  int x=mainState->listeWormsJoueurs[mainState->placeWormsActif].worms->getPosition_x();
  int y=mainState->listeWormsJoueurs[mainState->placeWormsActif].worms->getPosition_y();
  bool obstacle=false;
  bool worms=false;
  x+=direction;

  while(x>=0 && x<mainState->map.getLargeur() && obstacle==false){
    for(int i=0; i<mainState->listeWormsJoueurs.size() ;i++){
      if(x==mainState->listeWormsJoueurs[i].worms->getPosition_x() && y==mainState->listeWormsJoueurs[i].worms->getPosition_y() ){
        worms=true;
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
  return worms;
}

bool DumbIA::kungFuPossible(int direction) {
  int x=mainState->listeWormsJoueurs[mainState->placeWormsActif].worms->getPosition_x();
  int y=mainState->listeWormsJoueurs[mainState->placeWormsActif].worms->getPosition_y();
  for(int i=0; i<mainState->listeWormsJoueurs.size();i++){
    if(mainState->listeWormsJoueurs[i].worms->getPosition_x()==x+direction && mainState->listeWormsJoueurs[i].worms->getPosition_y()==y){
        return true;
    }
  }
  return false;
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

bool DumbIA::deplacementPossible(){
int d=(wormsProche->getPosition_x()-x<0)?-1:1;

  //[x+d][y] vide
  if(x+d<0 || x+d>=mainState->map.getLargeur()) return false;
  if(mainState->map[x+d][y]->getType()<2){

    //[x+d][y+1] vide & [x+d][y+2] non vide
    if(x+d<0 || x+d>=mainState->map.getLargeur() || y+2>=mainState->map.getHauteur()) return false;
    if((mainState->map[x+d][y+1]->getType()<2) && (mainState->map[x+d][y+2]->getType()>2))
    return true;

    //[x+d][y+1] non vide
    if(y+1>=mainState->map.getHauteur() || x+d<0 || x+d>=mainState->map.getLargeur()) return false;
    if(mainState->map[x+d][y+1]->getType()>2)
    return true;

    else
    return false;
  }
  else{
    //[x+d][y-1] vide & [x][y-1] vide
    if(y-1<0 || x+d<0 || x+d>=mainState->map.getLargeur()) return false;
    if((mainState->map[x+d][y-1]->getType()<2) && (mainState->map[x][y-1]->getType()<2))
    return true;

    else
    return false;
  }
  return false;
}


bool DumbIA::barricaderPosible(){
int d=(wormsProche->getPosition_x()-x<0)?-1:1;

  //[x+d][y] vide & [x+d][y+1] vide & [x+d+d][y+1] non vide
  if(y+1>=mainState->map.getHauteur() || x+d+d<0 || x+d+d>=mainState->map.getLargeur()) return false;
  if((mainState->map[x+d][y]->getType()<2) && (mainState->map[x+d][y+1]->getType()<3) && (mainState->map[x+d+d][y+1]->getType()>2))
  return true;

  //[x+d][y] vide & [x+2d][y] non vide & [x+2d][y-1] non vide & [x+2d][y-2] vide
  if(y-2<0 || x+d+d<0 || x+d+d>=mainState->map.getLargeur()) return false;
  if((mainState->map[x+d][y]->getType()<2) && (mainState->map[x+d+d][y]->getType()>2) && (mainState->map[x+d+d][y-1]->getType()>2) && (mainState->map[x+d+d][y-2]->getType()<2))
  return true;

  return false;
}
