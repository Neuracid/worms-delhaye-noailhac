#include "DumbIA.hpp"

DumbIA::DumbIA(Etat* mainState, Engine* engine): IA(mainState, engine) {

}

void DumbIA::findWormsProche() {
  size_t i = 0;
  Worms* wormsIni = new Worms(10000,10000);
  wormsProche=wormsIni;

  for(i=0;i<mainState->listeWormsJoueurs.size();i++) {
    if ( team != mainState->listeWormsJoueurs[i].joueur->getTeam() && (int)i != placeWormsActif && std::sqrt(std::pow(mainState->listeWormsJoueurs[i].worms->getPosition_x()-x,2) + std::pow(mainState->listeWormsJoueurs[i].worms->getPosition_y()-y,2)) < std::sqrt(std::pow(wormsProche->getPosition_x()-x,2) + std::pow(wormsProche->getPosition_y()-y,2)) ){
      wormsProche=mainState->listeWormsJoueurs[i].worms;
    } else {
    }
  }
  printf("worms proche : x: %d y: %d\n",wormsProche->getPosition_x(), wormsProche->getPosition_y() );
}

bool DumbIA::deplacement (){
  Worms::Direction d=(wormsProche->getPosition_x()-x<0)?Worms::left : Worms::right;
  engine->changementDeDirection(mainState,d);

  if(engine->getNbDeplacements()>0){
    if (deplacementPossible()==true){
      return engine->deplacement(mainState,placeWormsActif);
    }
  }
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
