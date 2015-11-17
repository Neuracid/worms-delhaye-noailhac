#ifndef LISTEBLOC_H
#define LISTEBLOC_H
#include <iostream>
#include <vector>
#include "Terrain.hpp"
#include <fstream>

class Map {

public:
std::vector<std::vector<std::unique_ptr< Terrain> > > matriceTerrain;
int hauteur;
int largeur;

Map();

int getHauteur();
int getLargeur();
void setLargeur(int largeur);
void setHauteur(int hauteur);

std::vector<std::unique_ptr< Terrain> >& operator[](size_t i) { return matriceTerrain[i];}


private:

protected:

};
#endif
