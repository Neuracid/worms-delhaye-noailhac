class Bloc {

public:
   Bloc(int x,int y);
   ~Bloc();

  void setPosition_y(int y);
  void setPosition_x(int x);

  int getPosition_x();
  int getPosition_y();
  virtual int getType()=0;
private:


protected:
  int position_x,position_y;
};
