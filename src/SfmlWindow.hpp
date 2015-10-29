#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "RenduMap.hpp"
#include "RenduWorms.hpp"
#include "SfmlWindowProperties.hpp"
#include <string>

class SfmlWindow{

public:
  //Constructeur , destructeur
  SfmlWindow(SfmlWindowProperties windowProperties, std::string name, int frameRateLimit);

  void setFond();
<<<<<<< HEAD
=======
  //void setMap();
>>>>>>> origin/master
  void displayWindow();

protected:

  sf::VideoMode videoMode;
  sf::RenderWindow window;

  //map
  RenduMap map;

  //worms
  RenduWorms worms;

  //fond
  sf::Texture textureFond;
  sf::Sprite spriteFond;


};
