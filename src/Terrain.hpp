class Terrain:public Bloc{

public:
  enum Type{eau=0,air=1,gaz=2,terre=3,roche=4,metal=5};

  Terrain(int x,int y,Type type);
  ~Terrain();

  Type getType();
  setType(Type);

private:
  Type type;

protected:

};
