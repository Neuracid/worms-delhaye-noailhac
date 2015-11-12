#include "Etat.hpp"

Etat::Etat():listeBloc(grille.getLargeur(),grille.getHauteur()){
  listeWormsJoueurs.resize(0);
}


void Etat::parseOutMap(){
    std::ofstream fichier("../res/txt/map.txt", std::ios::out | std::ios::trunc);

    if(fichier){
      for(int i=0;i<grille.getHauteur();i++){
        for(int j=0;j<grille.getLargeur();j++)
        fichier<<listeBloc[i][j]->getType()<<' ';
        fichier<<std::endl;
      }
       fichier.close();
    }
    else
            std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
}


void Etat::parseOutWorms(){

  std::ofstream fichier("../res/txt/worms.txt", std::ios::out | std::ios::trunc);
  for(int i=0; i<listeWormsJoueurs.size();i++){
    printf("%d e %d e %d",listeWormsJoueurs[i].worms->getPosition_x(),listeWormsJoueurs[i].worms->getPosition_y(),listeWormsJoueurs[i].worms->getVie());
    fichier<<listeWormsJoueurs[i].worms->getPosition_x()<<' '<<listeWormsJoueurs[i].worms->getPosition_y()<<' '<<listeWormsJoueurs[i].worms->getVie();//<<' '<<listeWormsJoueurs[i].worms->getType()<<' '<<listeWormsJoueurs[i].joueur->getTeam()<<std::endl;
  }
  fichier.close();

}

void Etat::parseOutProperties(){
  std::ofstream fichier("../res/txt/Properties.txt", std::ios::out | std::ios::trunc);
  fichier<<grille.getLargeur()<<' '<<grille.getHauteur()<<' '<<listeWormsJoueurs.size()<<' '<<placeWormsActif;
  fichier.close();
}

void Etat::setWormsJoueur(int x, int y, Joueur::Team color){
  Worms worms(x,y);
  WormsJoueur wormsJoueur;
  wormsJoueur.setWorms(&worms);
  bool verifJoueurExiste=false;
  int i=0;
  while(i<listeWormsJoueurs.size()&&verifJoueurExiste==false){
    if(color==listeWormsJoueurs[i].joueur->getTeam())
      verifJoueurExiste=true;
    else
      i++;
  }
  if(verifJoueurExiste==false){
    Joueur joueur(color);
    wormsJoueur.setJoueur(&joueur);
  }
  else wormsJoueur.setJoueur(&*listeWormsJoueurs[i].joueur);
    printf("%d\n",wormsJoueur.worms->getPosition_x());
    listeWormsJoueurs.push_back(wormsJoueur);
    printf("%d\n", listeWormsJoueurs[0].worms->getPosition_x());
}
