#include <iostream>
#include <vector>
class Grille{
public:
  Grille(int hauteur,int largeur);
  int getHauteur();
  int getLargeur();
protected:

private:
  int hauteur=12;
  int largeur=32;
};
