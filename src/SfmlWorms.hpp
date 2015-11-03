#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <vector>

class SfmlWorms : public sf::Drawable, public sf::Transformable
{
public:

  SfmlWorms(int nombreDeWorms);
  ~SfmlWorms();
  bool load(const std::string& tileset, sf::Vector2u tileSize, unsigned int x, unsigned int y,int numeroWorms);
  int nombreDeWorms;
  int **tabWorms;
  void parseTxt();
  std::vector<sf::Text> text;
  std::vector<sf::Texture> texture;

private:

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};
