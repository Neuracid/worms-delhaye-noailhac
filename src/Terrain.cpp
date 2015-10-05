#include "Terrain.hpp"
//Constructeur
Terrain::Terrain(int x,int y,Type s){
  position_x=x;
  position_y=y;
  type=s;
}

//Destructeur
Terrain::~Terrain(){
}

Type getType(){
  return type;
}

setType(Type s){
  type=s;
}
