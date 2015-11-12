#ifndef LISTEBLOC_H
#define LISTEBLOC_H
#include <iostream>
#include <vector>
#include "Terrain.hpp"
#include <fstream>

class ListeBloc{

public:
std::vector<std::vector<std::unique_ptr< Bloc> > > matriceTerrain;
ListeBloc(int hauteur, int largeur);

std::vector<std::unique_ptr< Bloc> >& operator[](size_t i) { return matriceTerrain[i];}


private:

protected:

};
#endif
