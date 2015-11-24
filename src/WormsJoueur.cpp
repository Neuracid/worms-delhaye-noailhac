#include "WormsJoueur.hpp"

WormsJoueur::WormsJoueur(){


}

WormsJoueur::~WormsJoueur(){


}


void WormsJoueur::setWorms(Worms* nouveau){
  worms=nouveau;
}

void WormsJoueur::setJoueur(Joueur* nouveau){
  joueur=nouveau;
}

void WormsJoueur::oteVie(int nombre){
  worms->oteVie(nombre);
  joueur->oteVie(nombre);
}
