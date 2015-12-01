#ifndef SFMLWINDOW_H
#define SFMLWINDOW_H
#include <iostream>
#include <cstdlib>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "SfmlMap.hpp"
#include "SfmlWorms.hpp"
#include "Engine.hpp"
#include "Etat.hpp"
#include <string>
#include <vector>

class SfmlWindow{
public:
  Etat* etat;
  Engine* engine;
  //window
  sf::VideoMode videoMode;
  sf::RenderWindow window;
  //worms
  std::vector<std::unique_ptr<SfmlWorms> > worms;
  //map
  SfmlMap map;
  //fond
  sf::Texture textureFond;
  sf::Sprite spriteFond;
  //text
  sf::Font font;
  std::vector<sf::Text> text;
  sf::Text textActif;
  sf::Text horloge;
  //Constructeur , destructeur
  SfmlWindow( Etat* etat, std::string name, int frameRateLimit, Engine* engine);
  std::string tileset;

  void initFleche();


  void setFond();

  void displayWindow();
  void setWorms();
  void drawWorms();
  void setText();
  void drawText();
  void update();
  void updateWorms();

protected:

};
#endif
