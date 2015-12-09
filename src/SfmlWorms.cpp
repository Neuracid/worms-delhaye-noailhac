#include "SfmlWorms.hpp"


SfmlWorms::SfmlWorms(Worms* worms){
  positionSprite = 0;
  y_new=worms->getPosition_y();
  y_old=y_new;
  x_new=worms->getPosition_x();
  x_old=x_new;
  etat_new=worms->getType();
  etat_old=etat_new;
  direction_new=worms->getDirection();
  direction_old=direction_new;
  pv_new=worms->getVie();
  pv_old=pv_new;
  // on charge la texture du tileset
  image();

  // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
  m_vertices.setPrimitiveType(sf::Quads);
  m_vertices.resize(4);
  load(sf::Vector2u(64, 64));
}

SfmlWorms::~SfmlWorms(){
}

bool SfmlWorms::load( sf::Vector2u tileSize){
            positionSprite++;
            if((size_t)positionSprite>=(m_tileset.getSize().y / tileSize.y))
            positionSprite=0;
            //on en déduit sa position dans la texture du tileset
            int tu = positionSprite % (m_tileset.getSize().x / tileSize.x);
            int tv = positionSprite / (m_tileset.getSize().x / tileSize.x);
            // int mod=64/(m_tileset.getSize().y / tileSize.y);
            // test+=mod;
            // test=test%64;

            switch(direction_new){
              case 1:// on définit ses quatre coins
                    m_vertices[1].position = sf::Vector2f(x_new * tileSize.x, y_new * tileSize.y+18);
                    m_vertices[0].position = sf::Vector2f((x_new + 1) * tileSize.x, y_new * tileSize.y+18);
                    m_vertices[3].position = sf::Vector2f((x_new + 1) * tileSize.x+test, (y_new + 1) * tileSize.y+18);
                    m_vertices[2].position = sf::Vector2f(x_new * tileSize.x, (y_new + 1) * tileSize.y+18);
                    break;
              default:// on définit ses quatre coins
                    m_vertices[0].position = sf::Vector2f(x_new * tileSize.x, y_new * tileSize.y+18);
                    m_vertices[1].position = sf::Vector2f((x_new + 1) * tileSize.x, y_new* tileSize.y+18);
                    m_vertices[2].position = sf::Vector2f((x_new + 1) * tileSize.x, (y_new + 1) * tileSize.y+18);
                    m_vertices[3].position = sf::Vector2f(x_new * tileSize.x, (y_new + 1) * tileSize.y+18);
                    break;
            }

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

 void SfmlWorms::update(Worms* worms){
   y_old=y_new;
   x_old=x_new;
   etat_old=etat_new;
   direction_old=direction_new;
   pv_old=pv_new;
   x_new=worms->getPosition_x();
   y_new=worms->getPosition_y();
   etat_new=worms->getType();
   direction_new=worms->getDirection();
   pv_new=worms->getVie();
   // on charge la texture du tileset
   image();

   load(sf::Vector2u(64, 64));
 }

 void SfmlWorms::image(){
   switch (etat_new) {
     case 0:m_tileset.loadFromFile("../res/WormsGeneral/Worms/wdie.png");break;
     case 1:m_tileset.loadFromFile("../res/WormsGeneral/Worms/wpnctop.png");break;
     case 2:m_tileset.loadFromFile("../res/WormsGeneral/Worms/wbowlnk.png");break;
     case 3:m_tileset.loadFromFile("../res/WormsGeneral/Worms/wbackflp.png");break;
     case 4:m_tileset.loadFromFile("../res/WormsGeneral/Worms/waccuse.png");break;
     case 5:m_tileset.loadFromFile("../res/WormsGeneral/Worms/wmgnlnk.png");break;
     default:m_tileset.loadFromFile("../res/WormsGeneral/Worms/wbackflp.png");break;
   }
   if(pv_old>0 && pv_new<=0)
   m_tileset.loadFromFile("../res/WormsGeneral/Worms/wdie.png");
 }
