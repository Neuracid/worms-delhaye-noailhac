#include "SfmlWindow.hpp"
#include "Commandes.hpp"
//#include "SfmlWindowProperties.hpp"

int main() {
  Etat etat;
  etat.setWormsJoueur(5,8,Joueur::rouge);
  etat.setWormsJoueur(6,7,Joueur::bleu);
  etat.setWormsJoueur(6,10,Joueur::bleu);
  etat.setWormsJoueur(8,3,Joueur::bleu);
  etat.placeWormsActif=2;
  etat.parseOutProperties();
  etat.parseOutMap();
  Commandes commande;
  commande.deplacementDroite(etat);
  etat.parseOutWorms();
  SfmlWindow window("worms",30);
  window.displayWindow();
}
