#include "SfmlWorms.hpp"

//Constructeur , destructeur
SfmlWorms::SfmlWorms(int nombreDeWorms) :  text(nombreDeWorms),quads(nombreDeWorms){
  this->nombreDeWorms=nombreDeWorms;
  tabWorms=new int* [nombreDeWorms];
  for(int i;i<nombreDeWorms;i++){
    tabWorms[i]=new int[5];
    quads[i].setPrimitiveType(sf::Quads);}
  parseTxt();
  load("../res/waccuse11.png", sf::Vector2u(64, 64),2);
}

SfmlWorms::~SfmlWorms(){
}

//Méthodes
bool SfmlWorms::load(const std::string& tileset, sf::Vector2u tileSize, int positionTabWorms)
{
    // on charge la texture du tileset
    if (!m_tileset.loadFromFile(tileset))
        return false;

            // on en déduit sa position dans la texture du tileset
            int tileNumber = tabWorms[positionTabWorms][3];

            // on récupère un pointeur vers le quad à définir dans le tableau de vertex
            sf::Vertex* quad = &(quads[positionTabWorms]);

            // on définit ses quatre coins
            quad[0].position = sf::Vector2f(10, 10);
            quad[1].position = sf::Vector2f(110, 10);
            quad[2].position = sf::Vector2f(110, 110);
            quad[3].position = sf::Vector2f(10, 110);

            // on définit ses quatre coordonnées de texture
            quad[0].texCoords = sf::Vector2f(0, 0);
            quad[1].texCoords = sf::Vector2f(25, 0);
            quad[2].texCoords = sf::Vector2f(25, 50);
            quad[3].texCoords = sf::Vector2f(0, 50);

    return true;
}

 void SfmlWorms::parseTxt(){
   std::ifstream fichier("../res/txt/WormsOut.txt", std::ios::in);
   if(fichier)
   {
     int x,y,pv,etat,team;
     for(int i=0; i<nombreDeWorms; i++){
       fichier >>x>>y>>pv>>etat>>team;
       tabWorms[i][0]=x;
       tabWorms[i][1]=y;
       tabWorms[i][2]=pv;
       tabWorms[i][3]=etat;
       tabWorms[i][4]=team;
     }
     fichier.close();
   }
   else
   {
     std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
   }
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
