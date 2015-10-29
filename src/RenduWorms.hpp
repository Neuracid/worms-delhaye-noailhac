#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>

class RenduWorms : public sf::Drawable, public sf::Transformable
{
public:

  RenduWorms(int largeur, int hauteur);
  ~RenduWorms();
  bool load(const std::string& tileset, sf::Vector2u tileSize, unsigned int x, unsigned int y);

  int* tab;
  int nombre;
  int** parseTxt1();
  void parseTxt();

private:

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

  sf::VertexArray m_vertices;
  sf::Texture m_tileset;
};
