#ifndef WORMSJOUEUR_H
#define WORMSJOUEUR_H
#include <iostream>
#include <vector>
#include "Joueur.hpp"
#include "Worms.hpp"



class WormsJoueur{

public:
  std::unique_ptr<Joueur> joueur;
  std::unique_ptr<Worms> worms;
  void setJoueur(Joueur nouveau);
  void setWorms(Worms nouveau);

private:

protected:


};
#endif
