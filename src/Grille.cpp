#include "Grille.hpp"
#include <iostream>
#include <vector>

Grille::Grille(int hauteur,int largeur){
  this->hauteur=hauteur;
  this->largeur=largeur;
}

int Grille::getHauteur(){
  return this->hauteur;
}

int Grille::getLargeur(){
  return this->largeur;
}
