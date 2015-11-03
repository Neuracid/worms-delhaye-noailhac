#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>

class SfmlWorms : public sf::Drawable, public sf::Transformable
{
public:

  SfmlWorms(int largeur, int hauteur, int nombreDeWorms);
  ~SfmlWorms();
  bool load(const std::string& tileset, sf::Vector2u tileSize, unsigned int x, unsigned int y,int numéroWorms);

  int* tab;
  int nombre;
  int **tabWorms;
  void parseTxt1();
  void parseTxt();

private:


  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

  sf::VertexArray m_vertices;

  sf::Texture m_tileset;
};
