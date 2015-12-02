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
  etat.setWormsJoueur(29,9,Joueur::rouge);
  etat.setWormsJoueur(25,8,Joueur::bleu);
  etat.setWormsJoueur(10,5,Joueur::jaune);
  etat.setWormsJoueur(4,9,Joueur::vert);
  etat.listeJoueursIA.push_back(Joueur::vert);
  etat.listeJoueursIA.push_back(Joueur::rouge);
  DumbIA dumb(&etat,&engine);
  SfmlWindow window(&etat, "worms",30,&engine);
  std::future<void> IA( std::async(lanceThreadIA,&dumb,&etat,&engine));
  window.displayWindow();
  jeuActif=false;
}
