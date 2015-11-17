#include "SfmlWindow.hpp"
#include "Engine.hpp"
//#include "SfmlWindowProperties.hpp"

int main() {
  Etat etat;
  printf("%d et %d", etat.map.getLargeur(),etat.map.getHauteur());
  etat.setWormsJoueur(0,1,Joueur::rouge);
  etat.setWormsJoueur(7,6,Joueur::bleu);
  etat.setWormsJoueur(10,6,Joueur::bleu);
  etat.setWormsJoueur(3,8,Joueur::bleu);
  etat.placeWormsActif=1;
  Engine engine;
  engine.deplacementGauche(&etat);
  etat.placeWormsActif=0;
  engine.deplacementGauche(&etat);
  SfmlWindow window(&etat, "worms",30);
  // window.displayWindow();
}
