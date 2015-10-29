#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "RenduMap.hpp"
#include "SfmlWindowProperties.hpp"

class SfmlWindow{

public:
  //Constructeur , destructeur
  SfmlWindow(SfmlWindowProperties windowProperties, std::string name, int frameRateLimit);

  void setFond();
  void displayWindow();

protected:

  sf::VideoMode videoMode;
  sf::RenderWindow window;

  //map
  //RenduMap map(largeurGrille,hauteurGrille);

  //fond
  sf::Texture textureFond;
  sf::Sprite spriteFond;


};
