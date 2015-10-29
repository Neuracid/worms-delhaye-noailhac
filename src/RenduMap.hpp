#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <fstream>
#include <vector>


class RenduMap : public sf::Drawable, public sf::Transformable
{
public:

  RenduMap(int largeur,int hauteur);
  ~RenduMap();
  int* tab;
  int nombre;
  bool load(const std::string& tileset, sf::Vector2u tileSize, unsigned int width, unsigned int height);
  void parseTxt();

private:

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


  sf::VertexArray m_vertices;
  sf::Texture m_tileset;
};
