#include "Worms.hpp"
//Constructeur
Worms::Worms(){
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
