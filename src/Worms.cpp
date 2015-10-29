#include "Worms.hpp"
//Constructeur
Worms::Worms(int x,int y):Bloc(x,y){
  vie=100;
  status=vivant;
}

//Destructeur
Worms::~Worms(){
}

int Worms::getVie(){
  return vie;
}

void Worms::setVie(int x){
  vie=x;
}

Worms::Status Worms::getStatus(){
  return status;
}
