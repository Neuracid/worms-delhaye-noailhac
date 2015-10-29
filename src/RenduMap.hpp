#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class RenduMap : public sf::Drawable, public sf::Transformable
{
public:

  RenduMap();
  ~RenduMap();
  bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
  int* parseTxt();
  int getLargeur();
  int getLongueur();

private:

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


  sf::VertexArray m_vertices;
  sf::Texture m_tileset;
};
