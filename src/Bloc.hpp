class Bloc {
public:
 Bloc(int x,int y);
 ~Bloc();

setPosition_y(int y);
setPosition_x(int x);

int getPosition_x();
int getPosition_y();

private:
  int position_x,position_y;

protected:

};
