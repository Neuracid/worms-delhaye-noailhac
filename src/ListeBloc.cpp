#include "ListeBloc.hpp"

ListeBloc::ListeBloc(int hauteur,int largeur) : matriceTerrain(largeur*hauteur){
  std::ifstream fichier("../res/txt/MapType0.txt", std::ios::in);
  if(fichier)
  {
  int x,hauteur,largeur;
  fichier >>largeur>>hauteur;
    for(int i=0; i<largeur; i++){
      for(int j=0;j<hauteur;j++){
        fichier >>x;
        matriceTerrain[i][j] = new Terrain(i % largeur,i / hauteur,static_cast<Terrain::Type>(x));
      }
    }
    //std::cout << matriceTerrain[0][0]->getType();
    fichier.close();
  }
  else
  {
    std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
  }
}
