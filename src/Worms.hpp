#ifndef WORMS_H
#define WORMS_H
#include "Bloc.hpp"
class Worms:public Bloc{
public:
  enum Status{die=0,archer=2,normal=4,kungfu=1,saut=2};
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
