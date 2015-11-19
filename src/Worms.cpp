#include "Worms.hpp"
//Constructeur
Worms::Worms(int x,int y):Bloc(x,y){
  vie=100;
  status=normal;
  direction=right;
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

int Worms::getDirection(){
  return static_cast<int>(direction);
}

void Worms::setDirection(Worms::Direction direction){
 this->direction=direction;
}
