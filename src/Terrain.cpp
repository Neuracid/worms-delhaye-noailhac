#include "Terrain.hpp"
//Constructeur
Terrain::Terrain(int x,int y,Type s):Bloc(x,y){
  type=s;
}

//Destructeur
Terrain::~Terrain(){
}

Terrain::Type Terrain::getType(){
  return type;
}

void Terrain::setType(Type s){
  type=s;
}
