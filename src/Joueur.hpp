#ifndef JOUEUR_H
#define JOUEUR_H
class Joueur{

public:

  enum Team{rouge=0,jaune=1,vert=2,bleu=3};
  Joueur(Team a);
  ~Joueur();
  Team getTeam();
  int getVie();
  void addVie(int vie);
  void oteVie(int nombre);
private:
  int vieEquipe;
  Team team;

protected:

};
#endif
