#include "Bloc.hpp"

//Constructeur
Bloc::Bloc(int x,int y){
  position_x=x;
  position_y=y;
}

int Bloc::getPosition_x(){
  return position_x;
}

int Bloc::getPosition_y(){
  return position_y;
}

void Bloc::setPosition_x(int x){
  position_x=x;
}

void Bloc::setPosition_y(int y){
  position_y=y;
}

//Destructeur
Bloc::~Bloc(){

}
