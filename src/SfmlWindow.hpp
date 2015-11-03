#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "SfmlMap.hpp"
#include "SfmlWorms.hpp"
#include "SfmlWindowProperties.hpp"
#include <string>

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
  SfmlMap map;

  //worms
  SfmlWorms worms;

  //fond
  sf::Texture textureFond;
  sf::Sprite spriteFond;


};
