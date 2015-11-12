#include "SfmlWindowProperties.hpp"


SfmlWindowProperties::SfmlWindowProperties(){
  parseProperties();
  parseWorms();
}


void SfmlWindowProperties::parseProperties(){
  std::ifstream fichier("../res/txt/Properties.txt", std::ios::in);
  if(fichier)
  {
    fichier>>largeurGrille>>hauteurGrille>>nombreDeWorms>>wormsActif;
    fichier.close();
  }
  else
  {
    std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
  }
}

void SfmlWindowProperties::parseWorms(){
  std::ifstream fichier("../res/txt/worms.txt", std::ios::in);
  if(fichier)
  {
    int x,y,pv,etat,team;
    std::vector<int> nouveau(5);
    tabWorms.resize(0);
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
