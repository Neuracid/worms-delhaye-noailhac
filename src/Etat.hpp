#include <vector>
#include "WormsJoueur.hpp"
#include "Grille.hpp"
#include <ctime>
#include <iostream>

class Etat{
public:
  std::vector<WormsJoueur> v;
  Grille grille;
  std::time_t result = std::time(NULL);
  Etat(int nombreWorms,int nombreJoueur,int hauteur,int largeur);
protected:

private:

};
