#include "Joueur.hpp"

Joueur::Joueur(Team a){
  team=a;
}

Joueur::~Joueur(){

}

Team Joueur::getTeam(){
  return team;
}
