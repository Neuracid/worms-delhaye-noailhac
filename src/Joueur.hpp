class Joueur{

public:
  enum Team{rouge=0,jaune=1,vert=2,bleu=3};
  Joueur(Team a);
  ~Joueur();

private:
  int vieEquipe;
  Team team;

protected:

};