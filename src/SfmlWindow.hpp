#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "RenduMap.hpp"

class SfmlWindow{

public:
  //Constructeur , destructeur
  SfmlWindow(int largeurPix,int hauteurPix, std::string name, int frameRateLimit);

  void setFond();
  void displayWindow();
  void parseGrille();

protected:


  int largeurGrille;
  int hauteurGrille;
  int nombreWorms;

  sf::VideoMode videoMode;
  sf::RenderWindow window;

  //map
  RenduMap map;

  //fond
  sf::Texture textureFond;
  sf::Sprite spriteFond;


};
