#ifndef GRILLE_H
#define GRILLE_H
#include <iostream>
#include <vector>
#include <fstream>
class Grille{
public:
  Grille();
  int getHauteur();
  int getLargeur();
  void setLargeur(int largeur);
  void setHauteur(int hauteur);
protected:

private:
  int hauteur;
  int largeur;
};
#endif
