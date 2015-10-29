#include "SfmlWindowProperties.hpp"


SfmlWindowProperties::SfmlWindowProperties(){
  parseGrille();
}


void SfmlWindowProperties::parseGrille(){
  std::ifstream fichier("../res/txt/Grille.txt", std::ios::in);
  if(fichier)
  {
    fichier>>largeurGrille>>hauteurGrille>>nombreDeWorms;
    fichier.close();
  }
  else
  {
    std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
  }
}
