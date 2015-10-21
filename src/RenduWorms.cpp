#include "RenduWorms.hpp"

//Constructeur , destructeur
RenduWorms::RenduWorms(){

}

RenduWorms::~RenduWorms(){

}

//Méthodes
bool RenduWorms::load(const std::string& tileset, sf::Vector2u tileSize, unsigned int position, unsigned int x, unsigned int y){

  // création d'un quad
  sf::VertexArray quad(sf::Quads, 4);

  // on le définit comme un rectangle, placé en (10, 10) et de taille 100x100
  quad[0].position = sf::Vector2f(10, 10);
  quad[1].position = sf::Vector2f(110, 10);
  quad[2].position = sf::Vector2f(110, 110);
  quad[3].position = sf::Vector2f(10, 110);

  // et on définit la zone de texture à lui appliquer comme étant le rectangle de 25x50 démarrant en (0, 0)
  quad[0].texCoords = sf::Vector2f(0, 0);
  quad[1].texCoords = sf::Vector2f(25, 0);
  quad[2].texCoords = sf::Vector2f(25, 50);
  quad[3].texCoords = sf::Vector2f(0, 50);

  return true;


}