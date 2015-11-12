#include "SfmlWindow.hpp"
#include "Commandes.hpp"
//#include "SfmlWindowProperties.hpp"

int main() {
  Etat etat;
  Commandes commande;
  commande.deplacementDroite(etat);
  etat.parseOutWorms();
  SfmlWindow window("worms",30);
  window.displayWindow();
}
