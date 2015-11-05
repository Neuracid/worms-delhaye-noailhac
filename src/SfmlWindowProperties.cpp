#include "SfmlWindowProperties.hpp"


SfmlWindowProperties::SfmlWindowProperties(){
  parseGrille();
  parseWorms();
}


void SfmlWindowProperties::parseGrille(){
  std::ifstream fichier("../res/txt/Grille.txt", std::ios::in);
  if(fichier)
  {
    fichier>>largeurGrille>>hauteurGrille>>nombreDeWorms;
    fichier.close();
  }
  else
  {
    std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
  }
}

void SfmlWindowProperties::parseWorms(){
  std::ifstream fichier("../res/txt/Worms.txt", std::ios::in);
  if(fichier)
  {
    int x,y,pv,etat,team;
    std::vector<int> nouveau(5);
    for(int i=0; i<nombreDeWorms; i++){
      fichier >>x>>y>>pv>>etat>>team;
      nouveau[0]=y;
      nouveau[1]=x;
      nouveau[2]=pv;
      nouveau[3]=etat;
      nouveau[4]=team;
      tabWorms.push_back(nouveau);
    }
    fichier.close();
  }
  else
  {
    std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
  }
}
