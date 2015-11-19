#ifndef SFMLWORMS_H
#define SFMLWORMS_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include "Worms.hpp"
#include <vector>

class SfmlWorms : public sf::Drawable, public sf::Transformable
{
public:
  SfmlWorms(Worms* worms);
  ~SfmlWorms();
  bool load( sf::Vector2u tileSize);
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  void update(Worms* worms);
  std::string tileset;
  int positionSprite=0;
  int x_new, y_new, etat_new,direction_new,pv_new;
  int x_old, y_old, etat_old, direction_old, pv_old;
  void image();
  int test=0;

  sf::VertexArray m_vertices;
  sf::Texture m_tileset;

};
#endif
