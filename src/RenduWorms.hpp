#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class RenduWorms : public sf::Drawable, public sf::Transformable
{
public:

  RenduWorms();
  ~RenduWorms();
  bool load(const std::string& tileset, sf::Vector2u tileSize, unsigned int position, unsigned int x, unsigned int y);

  int** parseTxt();

private:

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

  sf::Texture m_tileset;
};
