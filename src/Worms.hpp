#include "Bloc.hpp"
class Worms:public Bloc{
public:
  enum Status{mort=0,vivant=1,empoisonné=2};
  Worms(int x,int y);
  ~Worms();

  int getVie();
  void setVie(int x);
  int getType() override;

private:
  int vie;
  Status status;

protected:


};
