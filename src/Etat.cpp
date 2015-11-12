#include "Etat.hpp"

Etat::Etat():listeBloc(grille.getLargeur(),grille.getHauteur()){
  listeWormsJoueurs.resize(0);
  //joueurs.resize(0);
}


void Etat::parseOutMap(){
    std::ofstream fichier("../res/Map.txt", std::ios::out | std::ios::trunc);

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

  std::ofstream fichier("../res/Worms.txt", std::ios::out | std::ios::trunc);
  fichier<<listeWormsJoueurs.size()<<std::endl;
  for(int i=0; i<listeWormsJoueurs.size();i++){
    fichier<<listeWormsJoueurs[i].worms->getPosition_x()<<' '<<listeWormsJoueurs[i].worms->getPosition_y()<<' '<<listeWormsJoueurs[i].worms->getVie()<<' '<<listeWormsJoueurs[i].worms->getType()<<' '<<listeWormsJoueurs[i].joueur->getTeam()<<std::endl;
  }
  fichier.close();

}

void Etat::parseOutJoueurs(){
  std::ofstream fichier("../res/JoueursOut.txt", std::ios::out | std::ios::trunc);
  fichier<<joueurs.size()<<std::endl;
  for(int i=0; i<joueurs.size();i++){
    fichier<<joueurs[i].getTeam()<<' '<<joueurs[i].getVie()<<' '<<std::endl;
  }
  fichier.close();
}

void Etat::parseOutProperties(){
  std::ofstream fichier("../res/Properties.txt", std::ios::out | std::ios::trunc);
  fichier<<grille.getLargeur()<<' '<<grille.getHauteur()<<' '<<listeWormsJoueurs.size()<<' '<<placeWormsActif;
  fichier.close();
}

void Etat::setWormsJoueur(int x, int y,Joueur::Team a){
    Worms worms(x,y);
    WormsJoueur wormsJoueur;
    wormsJoueur.setWorms(worms);
    bool verifJoueurExiste=false;
    int i=0;
    while(i<joueurs.size()||verifJoueurExiste==false){
      if(a==joueurs[i].getTeam())
        verifJoueurExiste=true;
      else
        i++;
    }
    if(verifJoueurExiste==false)
      setJoueurListe(a);
    wormsJoueur.setJoueur(joueurs[i]);
    listeWormsJoueurs.push_back(wormsJoueur);
}

void Etat::setJoueurListe(Joueur::Team a){
  Joueur joueur(a);
  joueurs.push_back(joueur);
}
