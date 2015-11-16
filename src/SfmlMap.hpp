#ifndef SFMLMAP_H
#define SFMLMAP_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "Etat.hpp"
#include <fstream>
#include <vector>


class SfmlMap : public sf::Drawable, public sf::Transformable
{
public:

  SfmlMap(Etat* etat,int largeur,int hauteur);
  ~SfmlMap();
  int* tab;
  int nombre;
  bool load(const std::string& tileset, sf::Vector2u tileSize, unsigned int width, unsigned int height);
  //void parseMap();

private:

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


  sf::VertexArray m_vertices;
  sf::Texture m_tileset;
};
#endif
