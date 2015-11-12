#include "ListeBloc.hpp"

ListeBloc::ListeBloc(int hauteur,int largeur) : matriceTerrain(largeur*hauteur){
  std::ifstream fichier("../res/txt/MapType0.txt", std::ios::in);
  matriceTerrain.resize(largeur);
  if(fichier)
  {
  int x,hauteur,largeur;
  fichier >>largeur>>hauteur;
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
