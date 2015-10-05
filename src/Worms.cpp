#include "Worms.hpp"
//Constructeur
Worms::Worms(int x,int y){
  position_x=x;
  position_y=y;
  vie=100;
  status=1;
}

//Destructeur
Worms::~Worms(){
}

int getVie(){
  return vie;
}

setVie(int x){
  vie=x;
}
