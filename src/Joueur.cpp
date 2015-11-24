#include "Joueur.hpp"

Joueur::Joueur(Team a){
  team=a;
  vieEquipe=100;
}

Joueur::~Joueur(){

}

Joueur::Team Joueur::getTeam(){
  return team;
}

int Joueur::getVie(){
  return vieEquipe;
}

void Joueur::addVie(int vie){
  this->vieEquipe+=vie;
}

void Joueur::oteVie(int nombre){
  this->vieEquipe-=nombre;
  if(this->vieEquipe<0)
  this->vieEquipe=0;
}
