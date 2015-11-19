#include "Etat.hpp"

Etat::Etat():map(){
  listeWormsJoueurs.resize(0);
}

void Etat::setWormsJoueur(int x, int y, Joueur::Team color){
  Worms* worms = new Worms(x,y);
  WormsJoueur wormsJoueur;
  wormsJoueur.setWorms(worms);
  bool verifJoueurExiste=false;
  int i=0;
  while(i<listeWormsJoueurs.size()&&verifJoueurExiste==false){
    if(color==listeWormsJoueurs[i].joueur->getTeam())
      verifJoueurExiste=true;
    else
      i++;
  }
  if(verifJoueurExiste==false){
    Joueur* joueur = new Joueur(color);
    wormsJoueur.setJoueur(joueur);
  }
  else wormsJoueur.setJoueur(&*listeWormsJoueurs[i].joueur);
    listeWormsJoueurs.push_back(wormsJoueur);
}

float Etat::getTime(){
  time_t arrivee=time(&arrivee);
  return difftime(arrivee, depart);
}

void Etat::setTimeToZero(){
  depart=time(&depart);
}
