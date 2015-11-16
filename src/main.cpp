#include "SfmlWindow.hpp"
#include "Engine.hpp"
//#include "SfmlWindowProperties.hpp"

int main() {
  Etat etat;
  etat.setWormsJoueur(5,8,Joueur::rouge);
  etat.setWormsJoueur(6,7,Joueur::bleu);
  etat.setWormsJoueur(6,10,Joueur::bleu);
  etat.setWormsJoueur(8,3,Joueur::bleu);
  etat.placeWormsActif=1;
  etat.parseOutProperties();
  etat.parseOutMap();
  Engine engine;
  engine.deplacementGauche(&etat);
  etat.placeWormsActif=0;
  engine.deplacementGauche(&etat);
  etat.parseOutWorms();
  SfmlWindow window("worms",30);
  window.displayWindow(&etat);
}
