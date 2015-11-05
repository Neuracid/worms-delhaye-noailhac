#include <iostream>
#include <fstream>
#include <vector>

class SfmlWindowProperties {
public:
  //Constructeur
  SfmlWindowProperties();
  int largeurGrille;
  int hauteurGrille;
  int nombreDeWorms;
  std::vector<std::vector<int> > tabWorms;
  void parseGrille();
  void parseWorms();

};
