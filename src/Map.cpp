#include "Map.hpp"

Map::Map() {
  std::ifstream fichier("../res/txt/MapType0.txt", std::ios::in);
  matriceTerrain.resize(largeur);
  if(fichier)
  {
  int x;
  fichier >>this->largeur>>this->hauteur;
  matriceTerrain.resize(largeur*hauteur);
    for(int i=0; i<largeur; i++){
      matriceTerrain[i].resize(hauteur);
      for(int j=0;j<hauteur;j++){
        fichier >>x;
         matriceTerrain[i][j].reset(new Terrain(i % largeur,i / hauteur,static_cast<Terrain::Type>(x)));
      }
    }
    fichier.close();
  }
  else
  {
    std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
  }
}

int Map::getHauteur(){
  return this->hauteur;
}

int Map::getLargeur(){
  return this->largeur;
}

void Map::setLargeur(int largeur){
  this->largeur=largeur;
}
void Map::setHauteur(int hauteur){
  this->hauteur=hauteur;
}
