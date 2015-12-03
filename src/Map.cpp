#include "Map.hpp"

Map::Map() {
  std::ifstream fichier("../res/txt/MapType1.txt", std::ios::in);
  if(fichier)
  {
  int x;
  fichier >>largeur>>hauteur;
  matriceTerrain.resize(largeur);
  for(int i=0;i<largeur;i++)
  matriceTerrain[i].resize(hauteur);
    for(int i=0; i<hauteur; i++){
      for(int j=0;j<largeur;j++){
        fichier >>x;
         matriceTerrain[j][i]=new Terrain(j,i,static_cast<Terrain::Type>(x));
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
