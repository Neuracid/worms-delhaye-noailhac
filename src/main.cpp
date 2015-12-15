#include "SfmlWindow.hpp"
#include "Engine.hpp"
//#include "SfmlWindowProperties.hpp"
#include "NormalIA.hpp"
#include <future>
#include <unistd.h>


Etat etat;
Engine engine;

bool jeuActif=true;

void lanceRules(){
  while(jeuActif){
    usleep(50000);
    engine.executeAction(&etat);
    engine.regleGravite(&etat);
    engine.regleDeTerrain(&etat);
    if (engine.finTour(&etat)){
      engine.changementDeJoueur(&etat);
    }
  }
}

void lanceThreadIA(NormalIA* ia)
{
  while(jeuActif){
    usleep(5000000);
    ia->initActif(&etat);
    if(ia->activeIA()==true){
      ia->findWormsProche();
      if(ia->attaque()==false && ia->deplacement()==false){
        engine.changementDeJoueur(&etat);
      }
    }
  }
}

int main() {
  etat.setWormsJoueur(27,9,Joueur::rouge);
  etat.setWormsJoueur(25,8,Joueur::bleu);
  etat.setWormsJoueur(10,5,Joueur::jaune);
  etat.setWormsJoueur(4,9,Joueur::vert);
  etat.setWormsJoueur(24,7,Joueur::rouge);
  etat.listeJoueursIA.push_back(Joueur::vert);
  etat.listeJoueursIA.push_back(Joueur::rouge);
  std::future<void> rulles( std::async(lanceRules));
  NormalIA dumb(&etat,&engine);
  SfmlWindow window(&etat, "worms",30,&engine);
  std::future<void> IA( std::async(lanceThreadIA,&dumb));
  window.displayWindow();
  jeuActif=false;
}
