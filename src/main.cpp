#include "SfmlWindow.hpp"
#include "Engine.hpp"
//#include "SfmlWindowProperties.hpp"
#include "NormalIA.hpp"
#include <future>
#include <unistd.h>

#define NUM_THREADS     1

bool jeuActif=true;

void lanceThreadIA(NormalIA* ia, Etat* etat,Engine* engine)
{
  while(jeuActif){
    usleep(5000000);
    ia->initActif(etat);
    if(ia->activeIA()==true){
      ia->findWormsProche();
      if(ia->attaque()==false && ia->deplacement()==false){
        engine->changementDeJoueur(etat);
      }
    }
  }
}

int main() {

  Etat etat;
  Engine engine;
  etat.setWormsJoueur(27,9,Joueur::rouge);
  etat.setWormsJoueur(25,8,Joueur::bleu);
  etat.setWormsJoueur(10,5,Joueur::jaune);
  etat.setWormsJoueur(4,9,Joueur::vert);
  etat.setWormsJoueur(24,7,Joueur::rouge);
  etat.listeJoueursIA.push_back(Joueur::vert);
  etat.listeJoueursIA.push_back(Joueur::rouge);
  NormalIA dumb(&etat,&engine);
  SfmlWindow window(&etat, "worms",30,&engine);
  std::future<void> IA( std::async(lanceThreadIA,&dumb,&etat,&engine));
  window.displayWindow();
  jeuActif=false;
}
