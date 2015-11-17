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
  int x, y, etat;
  void image();

  sf::VertexArray m_vertices;
  sf::Texture m_tileset;

};
#endif
