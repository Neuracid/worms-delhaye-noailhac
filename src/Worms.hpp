class Worms:public Bloc{
public:
enum Status{mort=0,vivant=1,empoisonné=2};
Worms();
~Worms();

int getVie();
setVie(int x);

private:
int vie;
Status status;
protected:


};
