#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "RenduMap.hpp"

class SfmlWindow{

public:
  //Constructeur , destructeur
  SfmlWindow(int largeurPix,int hauteurPix, std::string name, int frameRateLimit);
  ~SfmlWindow();

  void displayWindow();

protected:
  sf::VideoMode videoMode;
  sf::RenderWindow window;

  //map
  RenduMap map;

  //fond
  sf::Texture texture;
  sf::Sprite spriteFond;


};
