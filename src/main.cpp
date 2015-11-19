#include "SfmlWindow.hpp"
#include "Engine.hpp"
//#include "SfmlWindowProperties.hpp"

int main() {
  Etat etat;
  etat.setWormsJoueur(0,1,Joueur::rouge);
  etat.setWormsJoueur(7,6,Joueur::bleu);
  etat.setWormsJoueur(10,6,Joueur::jaune);
  etat.setWormsJoueur(4,4,Joueur::vert);
  SfmlWindow window(&etat, "worms",30);
  window.displayWindow();
}
