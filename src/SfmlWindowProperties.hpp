#include <iostream>
#include <fstream>

class SfmlWindowProperties{

public:
  //Constructeur
  SfmlWindowProperties();
  int largeurGrille;
  int hauteurGrille;
  int nombreDeWorms;
  void parseGrille();

};
