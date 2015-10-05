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
return this->type;
}

setType(Type s){
  this->type=s;
}
