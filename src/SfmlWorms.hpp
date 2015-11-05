#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <vector>

class SfmlWorms : public sf::Drawable, public sf::Transformable
{
public:
  SfmlWorms(std::vector<int> worms,const std::string& tiles);
  ~SfmlWorms();
  bool load( sf::Vector2u tileSize);
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  std::string tileset;
  int x,y,etat,team,pv;

  sf::VertexArray m_vertices;
  sf::Texture m_tileset;

};
