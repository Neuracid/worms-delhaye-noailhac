#ifndef SFMLWINDOW_H
#define SFMLWINDOW_H
#include <iostream>
#include <cstdlib>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "SfmlMap.hpp"
#include "SfmlWorms.hpp"
#include "SfmlWindowProperties.hpp"
#include <string>
#include <vector>

class SfmlWindow{
public:
  SfmlWindowProperties windowProperties;
  sf::VideoMode videoMode;
  sf::RenderWindow window;
  std::vector<std::unique_ptr<SfmlWorms> > worms;
  //map
  SfmlMap map;
  //fond
  sf::Texture textureFond;
  sf::Sprite spriteFond;
  sf::Font font;
  std::vector<sf::Text> text;
  //Constructeur , destructeur
  SfmlWindow( std::string name, int frameRateLimit);


  void setFond();

  void displayWindow();
  void setWorms();
  void drawWorms();
  void setText();
  void drawText();

protected:

};
#endif
