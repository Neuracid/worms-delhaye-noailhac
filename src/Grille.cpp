#include "Grille.hpp"
#include <iostream>
#include <vector>

Grille::Grille(){
  std::ifstream fichier("../res/txt/MapType0.txt", std::ios::in);
  if(fichier)
  {
  fichier >>largeur>>hauteur;
    fichier.close();
  }
  else
  {
    std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
  }
}

int Grille::getHauteur(){
  return this->hauteur;
}

int Grille::getLargeur(){
  return this->largeur;
}

void Grille::setLargeur(int largeur){
  this->largeur=largeur;
}
void Grille::setHauteur(int hauteur){
  this->hauteur=hauteur;
}
