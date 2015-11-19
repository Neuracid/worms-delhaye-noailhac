#ifndef WORMS_H
#define WORMS_H
#include "Bloc.hpp"
class Worms:public Bloc{
public:
  enum Status{normal=0,kungfu=1,saut=3};
  enum Direction{left=-1,right=1};
  Worms(int x,int y);
  ~Worms();

  int getVie();
  void setVie(int x);
  int getType() override;
  void setType(Worms::Status status);
  int getDirection();
  void setDirection(Worms::Direction direction);

private:
  int vie;
  Status status;
  Direction direction;

protected:


};
#endif
