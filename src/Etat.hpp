#include <vector>
#include "WormsJoueur.hpp"
//#include "ListeBloc.hpp"
#include "Grille.hpp"
#include <ctime>
#include <iostream>
#include <fstream>

class Etat{
public:
  std::vector<WormsJoueur> v;
  //ListeBloc listeBloc;
  Grille grille;
  //std::time_t result = std::time(NULL);
  Etat(int hauteur,int largeur);
  std::vector<Joueur> joueurs;
  //void parseOutMap();
  void parseOutWorms();
  void parseOutJoueurs();
protected:

private:

};
