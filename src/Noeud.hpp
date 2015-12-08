#ifndef NOEUD_H
#define NOEUD_H
#include "Etat.hpp"
class Noeud {

public:

private:
  int nbDeplacement;
  bool actionUtilize;
  Etat etat;
  int level;
  std::vector< std::shared_ptr< Etat > >;

protected:

};
#endif
