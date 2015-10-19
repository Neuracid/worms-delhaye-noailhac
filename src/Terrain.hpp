class Terrain:public Bloc{

public:
  enum Type{air=0,gaz=1,eau=2,terre=3,roche=4,metal=5};

  Terrain(int x,int y,Type type);
  ~Terrain();

  Type getType();
  setType(Type);

private:
  Type type;

protected:

};
