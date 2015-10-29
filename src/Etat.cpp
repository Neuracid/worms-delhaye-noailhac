#include "Etat.hpp"

Etat::Etat(int nombreJoueur,int nombreWorms,int hauteur,int largeur):grille( hauteur, largeur)/*,listeBloc(hauteur,largeur)*/{
}

void Etat::parseOutMap(){
    // std::ofstream fichier("../res/MapOut.txt", std::ios::out | std::ios::trunc);
    // int largeur,hauteur,valeur;
    // largeur=this->grille.getLargeur();
    // hauteur=this->grille.getHauteur();
    //
    // if(fichier){
    //   fichier<<hauteur<<' '<<largeur<<std::endl;
    //   for(int i=0;i<hauteur;i++){
    //     for(int j=0;j<largeur;j++)
    //     valeur=j+i*largeur;
    //     fichier<<this->listeBloc[valeur]<<' ';
    //     fichier<<std::endl;
    //   }
    //    fichier.close();
    // }
    // else
    //         std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
}

void Etat::parseOutWorms(){
  std::ofstream fichier("../res/WormsOut.txt", std::ios::out | std::ios::trunc);
  fichier<<v.size()<<std::endl;
  for(int i=0; i<v.size();i++){
    fichier<<v[i]->worms.getPosition_x()<<' '<<v[i]->worms.getPosition_y()<<' '<<v[i]->worms.getVie()<<' '<<v[i]->worms.getStatus()<<' '<<v[i]->joueurs.getTeam()<<std::endl;
  }
  fichier.close();
}

void Etat::parseOutJoueurs(){
  std::ofstream fichier("../res/JoueursOut.txt", std::ios::out | std::ios::trunc);


}
