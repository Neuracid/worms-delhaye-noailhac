#include "Terrain.hpp"
//Constructeur
Terrain::Terrain(int x,int y,Type s):Bloc(x,y){
  type=s;
}

//Destructeur
Terrain::~Terrain(){
}

int Terrain::getType(){
  return static_cast<int>(type);
}

void Terrain::setType(Type s){
  type=s;
}
