#ifndef ETAT_H
#define ETAT_H
#include <vector>
#include "WormsJoueur.hpp"
#include "ListeBloc.hpp"
#include "Grille.hpp"
#include <ctime>
#include <iostream>
#include <fstream>

class Etat{
public:
  std::vector<WormsJoueur> listeWormsJoueurs;
  int placeWormsActif=0;

  Grille grille;
  ListeBloc listeBloc;

  std::vector<Joueur> joueurs;

  //std::time_t result = std::time(NULL);

  Etat();
  void parseOutMap();
  void parseOutWorms();
  void parseOutJoueurs();
  void parseOutProperties();
  void setWormsJoueur(int x, int y,Joueur::Team a);
  void setJoueurListe(Joueur::Team a);

protected:

private:

};
#endif
