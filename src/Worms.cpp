#include "Worms.hpp"
//Constructeur
Worms::Worms(int x,int y):Bloc(x,y){
  vie=100;
  status=normal;
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

int Worms::getType(){
  return static_cast<int>(status);
}

void Worms::setType(Worms::Status status){
 this->status=status;
}
