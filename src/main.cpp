#include "SfmlWindow.hpp"
#include "Engine.hpp"
//#include "SfmlWindowProperties.hpp"

int main() {
  Etat etat;
  etat.setWormsJoueur(0,1,Joueur::rouge);
  etat.setWormsJoueur(7,6,Joueur::bleu);
  etat.setWormsJoueur(10,6,Joueur::jaune);
  etat.setWormsJoueur(4,4,Joueur::vert);
  etat.listeWormsJoueurs[0].worms->setType(Worms::kungfu);
  etat.placeWormsActif=2;
  Engine engine;
  engine.deplacementGauche(&etat);
  etat.placeWormsActif=1;
  engine.deplacementGauche(&etat);
  engine.regleGravite(&etat);
  etat.placeWormsActif=0;
  SfmlWindow window(&etat, "worms",30);
  window.displayWindow();
}
