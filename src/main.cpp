#include "SfmlWindow.hpp"
#include "Commandes.hpp"
//#include "SfmlWindowProperties.hpp"

int main() {
  Etat etat;
  etat.setWormsJoueur(5,8,Joueur::rouge);
  etat.setWormsJoueur(7,10,Joueur::bleu);
  Commandes commande;
  commande.deplacementDroite(etat);
  etat.parseOutWorms();
  SfmlWindow window("worms",30);
  window.displayWindow();
}
