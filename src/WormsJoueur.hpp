#ifndef WORMSJOUEUR_H
#define WORMSJOUEUR_H
#include <iostream>
#include <vector>
#include "Joueur.hpp"
#include "Worms.hpp"



class WormsJoueur{

public:
  Joueur* joueur;
  Worms* worms;
  void setJoueur(Joueur* nouveau);
  void setWorms(Worms* nouveau);
  WormsJoueur();
  ~WormsJoueur();

private:

protected:


};
#endif
