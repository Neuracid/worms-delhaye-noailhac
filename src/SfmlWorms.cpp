#include "SfmlWorms.hpp"


SfmlWorms::SfmlWorms(std::vector<int> worms,const std::string& tiles){
  pv=worms[2];
  etat=worms[3];
  x=worms[0];
  y=worms[1];
  team=worms[4];
  tileset=tiles;
  // on charge la texture du tileset
  m_tileset.loadFromFile(tileset);

  // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
  m_vertices.setPrimitiveType(sf::Quads);
  m_vertices.resize(4);
  load(sf::Vector2u(64, 64));
}

SfmlWorms::~SfmlWorms(){
}

bool SfmlWorms::load( sf::Vector2u tileSize)
{
            //on en déduit sa position dans la texture du tileset
            int tu = etat % (m_tileset.getSize().x / tileSize.x);
            int tv = etat / (m_tileset.getSize().x / tileSize.x);


            // on définit ses quatre coins
            m_vertices[0].position = sf::Vector2f(x * tileSize.x, y * tileSize.y+18);
            m_vertices[1].position = sf::Vector2f((x + 1) * tileSize.x, y * tileSize.y+18);
            m_vertices[2].position = sf::Vector2f((x + 1) * tileSize.x, (y + 1) * tileSize.y+18);
            m_vertices[3].position = sf::Vector2f(x * tileSize.x, (y + 1) * tileSize.y+18);

            // on définit ses quatre coordonnées de texture
            m_vertices[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            m_vertices[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            m_vertices[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            m_vertices[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);


    return true;
}

 void SfmlWorms::draw(sf::RenderTarget& target, sf::RenderStates states) const
 {
     // on applique la transformation
     states.transform *= getTransform();

     // on applique la texture du tileset
     states.texture = &m_tileset;

     // et on dessine enfin le tableau de vertex
     target.draw(m_vertices, states);
 }

 void SfmlWorms::update(std::vector<int> worms, const std::string& tiles){
   pv=worms[2];
   etat=worms[3];
   x=worms[0];
   y=worms[1];
   team=worms[4];
   tileset=tiles;
   // on charge la texture du tileset
   m_tileset.loadFromFile(tileset);

   load(sf::Vector2u(64, 64));

 }
