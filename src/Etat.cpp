#include "Etat.hpp"

Etat::Etat(int nombreJoueur,int nombreWorms,int hauteur,int largeur):v(nombreWorms*nombreJoueur),grille( hauteur, largeur),listeBloc(hauteur,largeur){
}

void parseOutMap(){
    std::ofstream fichier("../res/MapOut.txt", std::ios::out | std::ios::trunc);
    int largeur,hauteur;
    largeur=this.grille.getLargeur();
    hauteur=this->grille.getHauteur();

    if(fichier){
      fichier<<hauteur<<' '<<largeur<<std::endl;
      for(int i=0;i<hauteur;i++){
        for(int j=0;j<largeur;j++)
        fichier<<this->listeBloc[j+i*largeur]<<' ';
        fichier<<std::endl;
      }
       fichier.close();
    }
    else
            std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
}
