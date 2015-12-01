#include "Engine.hpp"

//COMMANDES
bool Engine::deplacement(Etat* etat, int i){
  bool verif=false;
  int x=etat->listeWormsJoueurs[i].worms->getPosition_x();
  int y=etat->listeWormsJoueurs[i].worms->getPosition_y();
  int d=etat->listeWormsJoueurs[i].worms->getDirection();

  //cas actif
  if(i==etat->placeWormsActif){
    if(nbDeplacements > 0 && x+d>=0 && x+d<etat->map.getLargeur()){
      if(etat->map[x+d][y]->getType()==Terrain::air || etat->map[x+d][y]->getType()==Terrain::gaz || etat->map[x+d][y]->getType()==Terrain::eau){
        etat->listeWormsJoueurs[i].worms->setPosition_x(x+d);verif=true;nbDeplacements--;
      }
      else{
        if(y>0){
          if((etat->map[x+d][y-1]->getType()==Terrain::air || etat->map[x+d][y-1]->getType()==Terrain::gaz || etat->map[x+d][y-1]->getType()==Terrain::eau) && (etat->map[x][y-1]->getType()==Terrain::air || etat->map[x][y-1]->getType()==Terrain::gaz || etat->map[x][y-1]->getType()==Terrain::eau)){
            etat->listeWormsJoueurs[i].worms->setPosition_x(x+d);
            etat->listeWormsJoueurs[i].worms->setPosition_y(y-1);
            nbDeplacements--;
            verif=true;
          }
        }
      }
    }
  }

  //cas autre
  else{
    if(nbDeplacements > 0 && x+d>=0 && x+d<etat->map.getLargeur()){
      if(etat->map[x+d][y]->getType()==Terrain::air || etat->map[x+d][y]->getType()==Terrain::gaz || etat->map[x+d][y]->getType()==Terrain::eau){
        etat->listeWormsJoueurs[i].worms->setPosition_x(x+d);
      }
      else{
        if(y>0){
          if((etat->map[x+d][y-1]->getType()==Terrain::air || etat->map[x+d][y-1]->getType()==Terrain::gaz || etat->map[x+d][y-1]->getType()==Terrain::eau) && (etat->map[x][y-1]->getType()==Terrain::air || etat->map[x][y-1]->getType()==Terrain::gaz || etat->map[x][y-1]->getType()==Terrain::eau)){
            etat->listeWormsJoueurs[i].worms->setPosition_x(x+d);
            etat->listeWormsJoueurs[i].worms->setPosition_y(y-1);
          }
        }
      }
    }
  }

  return verif;
}

void Engine::changementDeDirection(Etat* etat,Worms::Direction direction){
  etat->listeWormsJoueurs[etat->placeWormsActif].worms->setDirection(direction);
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
  if (capaUtilise == false){
    int x=etat->listeWormsJoueurs[etat->placeWormsActif].worms->getPosition_x();
    int y=etat->listeWormsJoueurs[etat->placeWormsActif].worms->getPosition_y();
    int direction=etat->listeWormsJoueurs[etat->placeWormsActif].worms->getDirection();
    etat->listeWormsJoueurs[etat->placeWormsActif].worms->setType(Worms::kungfu);
    for(int i=0; i<etat->listeWormsJoueurs.size();i++){
      if(etat->listeWormsJoueurs[i].worms->getPosition_x()==x+direction && etat->listeWormsJoueurs[i].worms->getPosition_y()==y){
          etat->listeWormsJoueurs[i].worms->setDirection(((direction==1)?Worms::right : Worms::left));
          deplacement(etat,i);
          etat->listeWormsJoueurs[i].oteVie(50);break;
      }
    }
    capaUtilise=true;
  }
}

void Engine::mineGaz(Etat* etat){
  if (capaUtilise == false){
    int x=etat->listeWormsJoueurs[etat->placeWormsActif].worms->getPosition_x();
    int y=etat->listeWormsJoueurs[etat->placeWormsActif].worms->getPosition_y();
    if (etat->map[x+etat->listeWormsJoueurs[etat->placeWormsActif].worms->getDirection()][y]->getType() == Terrain::air){
      etat->map[x+etat->listeWormsJoueurs[etat->placeWormsActif].worms->getDirection()][y]->setType(Terrain::gaz);
      capaUtilise=true;
    }
  }
}

void Engine::creuser(Etat* etat){
  if (capaUtilise == false){
    int x=etat->listeWormsJoueurs[etat->placeWormsActif].worms->getPosition_x();
    int y=etat->listeWormsJoueurs[etat->placeWormsActif].worms->getPosition_y();
    switch (etat->map[x+etat->listeWormsJoueurs[etat->placeWormsActif].worms->getDirection()][y]->getType()){
      case Terrain::metal:
      etat->map[x+etat->listeWormsJoueurs[etat->placeWormsActif].worms->getDirection()][y]->setType(Terrain::roche);
      capaUtilise=true;
      break;
      case Terrain::roche:
      etat->map[x+etat->listeWormsJoueurs[etat->placeWormsActif].worms->getDirection()][y]->setType(Terrain::terre);
      capaUtilise=true;
      break;
      case Terrain::terre:
      etat->map[x+etat->listeWormsJoueurs[etat->placeWormsActif].worms->getDirection()][y]->setType(Terrain::air);
      capaUtilise=true;
      break;
      default:
      capaUtilise=false;
      break;
    }
  }
}

bool Engine::barricader(Etat* etat){
  if (capaUtilise == false){
    int x=etat->listeWormsJoueurs[etat->placeWormsActif].worms->getPosition_x();
    int y=etat->listeWormsJoueurs[etat->placeWormsActif].worms->getPosition_y();
    int d=etat->listeWormsJoueurs[etat->placeWormsActif].worms->getDirection();

    if(etat->map[x+d][y+1]->getType()==Terrain::air || etat->map[x+d][y+1]->getType()==Terrain::eau || etat->map[x+d][y+1]->getType()==Terrain::gaz){
      etat->map[x+d][y+1]->setType(Terrain::terre);
      capaUtilise=true;}
    else{
      switch (etat->map[x+d][y]->getType()) {
        case Terrain::air : etat->map[x+d][y]->setType(Terrain::terre);
                            capaUtilise=true;
                            break;
        case Terrain::gaz : etat->map[x+d][y]->setType(Terrain::terre);
                            capaUtilise=true;
                            break;
        case Terrain::eau : etat->map[x+d][y]->setType(Terrain::terre);
                            capaUtilise=true;
                            break;
        case Terrain::terre : etat->map[x+d][y]->setType(Terrain::roche);
                            capaUtilise=true;
                            break;
        case Terrain::roche : etat->map[x+d][y]->setType(Terrain::metal);
                            capaUtilise=true;
                            break;
        default: break;
      }
  }
  return true;
  }
  return false;
}

void Engine::tir(Etat* etat){
  if(capaUtilise == false){
    int x=etat->listeWormsJoueurs[etat->placeWormsActif].worms->getPosition_x();
    int y=etat->listeWormsJoueurs[etat->placeWormsActif].worms->getPosition_y();
    int direction=etat->listeWormsJoueurs[etat->placeWormsActif].worms->getDirection();
    etat->listeWormsJoueurs[etat->placeWormsActif].worms->setType(Worms::tir);
    bool find=false;
    x+=direction;

    while(x>=0 && x<etat->map.getLargeur() && find==false){
      for(int i=0; i<etat->listeWormsJoueurs.size() ;i++){
        if(x==etat->listeWormsJoueurs[i].worms->getPosition_x() && y==etat->listeWormsJoueurs[i].worms->getPosition_y() ){
          etat->listeWormsJoueurs[i].worms->oteVie(25);
          find=true;
        }
      }
      switch (etat->map[x][y]->getType()){
        case Terrain::metal:
        etat->map[x][y]->setType(Terrain::roche);
        find=true;
        break;
        case Terrain::roche:
        etat->map[x][y]->setType(Terrain::terre);
        find=true;
        break;
        case Terrain::terre:
        etat->map[x][y]->setType(Terrain::air);
        find=true;
        break;
        default:
        break;
      }
      x+=direction;
    }
    capaUtilise=true;
  }
}

bool Engine::grappin(Etat* etat){
  if(capaUtilise==false){
    int x=etat->listeWormsJoueurs[etat->placeWormsActif].worms->getPosition_x();
    int y=etat->listeWormsJoueurs[etat->placeWormsActif].worms->getPosition_y();
    int direction=etat->listeWormsJoueurs[etat->placeWormsActif].worms->getDirection();
    while(etat->map[x+direction][y]->getType()==Terrain::terre || etat->map[x+direction][y]->getType()==Terrain::roche || etat->map[x+direction][y]->getType()==Terrain::metal)
    y-=1;
    etat->listeWormsJoueurs[etat->placeWormsActif].worms->setPosition_x(x+direction);
    etat->listeWormsJoueurs[etat->placeWormsActif].worms->setPosition_y(y);
    capaUtilise=true;
    return true;
  }
  return false;
}


//REGLES
void Engine::regleGravite (Etat* etat) {
  for (int i = 0; i < etat->listeWormsJoueurs.size() ; i++) {
    int nbCasesVides=0;
    int x=etat->listeWormsJoueurs[i].worms->getPosition_x();
    int y=etat->listeWormsJoueurs[i].worms->getPosition_y();
    while (y+1<etat->map.getHauteur() && etat->map[x][y+1]->getType() <3 ){
      nbCasesVides++;
      y++;
    }
    if (nbCasesVides == 1){
      etat->listeWormsJoueurs[i].worms->setPosition_y(y);
    }
    if (nbCasesVides > 1 ){
      etat->listeWormsJoueurs[i].worms->setPosition_y(y);
      etat->listeWormsJoueurs[i].oteVie((nbCasesVides-1)*10);
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
      case 1:if(i==etat->placeWormsActif){etat->listeWormsJoueurs[i].oteVie(2);}break;
      case 2:etat->listeWormsJoueurs[i].oteVie(etat->listeWormsJoueurs[i].worms->getVie()); break;
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
  if (nbDeplacements == 0 && capaUtilise == true) {
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
