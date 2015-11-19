#include "SfmlWindow.hpp"
#include "Engine.hpp"
//#include "SfmlWindowProperties.hpp"

int main() {
  Etat etat;
  etat.setWormsJoueur(29,9,Joueur::rouge);
  etat.setWormsJoueur(25,8,Joueur::bleu);
  etat.setWormsJoueur(10,5,Joueur::jaune);
  etat.setWormsJoueur(4,9,Joueur::vert);
  SfmlWindow window(&etat, "worms",30);
  window.displayWindow();
}
