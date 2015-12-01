#include "SfmlWindow.hpp"
#include "Engine.hpp"
//#include "SfmlWindowProperties.hpp"
#include "DumbIA.hpp"
#include <future>
#define NUM_THREADS     1

bool jeuActif=true;

void lanceThreadIA(DumbIA* ia, Etat* etat,Engine* engine)
{
  while(jeuActif){
    ia->initActif(etat);
    ia->findWormsProche();
    engine->changementDeJoueur(etat);
  }
}

int main() {

  Etat etat;
  Engine engine;
  etat.setWormsJoueur(29,9,Joueur::rouge);
  etat.setWormsJoueur(25,8,Joueur::bleu);
  etat.setWormsJoueur(10,5,Joueur::jaune);
  etat.setWormsJoueur(4,9,Joueur::vert);
  DumbIA dumb(&etat);

  std::future<void> result( std::async(lanceThreadIA,&dumb,&etat,&engine));


  SfmlWindow window(&etat, "worms",30);
  window.displayWindow();
  jeuActif=false;


}
