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
protected:

private:
  int hauteur;
  int largeur;
};
#endif
