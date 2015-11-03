#include "SfmlWorms.hpp"

//Constructeur , destructeur
SfmlWorms::SfmlWorms(int largeur, int hauteur){
nombre=largeur*hauteur;
tab=new int[nombre];
parseTxt();
load("../res/waccuse11.png", sf::Vector2u(64, 64), 16, 8);
}

SfmlWorms::~SfmlWorms(){

}

//Méthodes
bool SfmlWorms::load(const std::string& tileset, sf::Vector2u tileSize, unsigned int width, unsigned int height)
{
    // on charge la texture du tileset
    if (!m_tileset.loadFromFile(tileset))
        return false;

    // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4);

    // on remplit le tableau de vertex, avec un quad par tuile
    for (unsigned int i = 0; i < width; ++i)
        for (unsigned int j = 0; j < height; ++j)
        {
            // on récupère le numéro de tuile courant
            int tileNumber = tab[i + j * width];

            // on en déduit sa position dans la texture du tileset
            int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
            int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

            // on récupère un pointeur vers le quad à définir dans le tableau de vertex
            sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

            // on définit ses quatre coins
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            // on définit ses quatre coordonnées de texture
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }

    return true;
}


// //Méthodes
// bool SfmlWorms::load(const std::string& tileset, sf::Vector2u tileSize, unsigned int position, unsigned int x, unsigned int y){
//
//   // création d'un quad
//   sf::VertexArray quad(sf::Quads, 4);
//
//   // on le définit comme un rectangle, placé en (10, 10) et de taille 100x100
//   quad[0].position = sf::Vector2f(10, 10);
//   quad[1].position = sf::Vector2f(110, 10);
//   quad[2].position = sf::Vector2f(110, 110);
//   quad[3].position = sf::Vector2f(10, 110);
//
//   // et on définit la zone de texture à lui appliquer comme étant le rectangle de 25x50 démarrant en (0, 0)
//   quad[0].texCoords = sf::Vector2f(0, 0);
//   quad[1].texCoords = sf::Vector2f(25, 0);
//   quad[2].texCoords = sf::Vector2f(25, 50);
//   quad[3].texCoords = sf::Vector2f(0, 50);
//
//   return true;
// }

void SfmlWorms::parseTxt(){
  std::ifstream fichier("../res/txt/worms.txt", std::ios::in);
  if(fichier)
  {

    int rec;
    for(int i=0; i<nombre; i++){
      fichier >> rec;
      tab[i]=rec;
    }
    fichier.close();
  }
  else
  {
    std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
  }
}

 int** SfmlWorms::parseTxt1(){
   std::ifstream fichier("../res/txt/WormsOut.txt", std::ios::in);
   if(fichier)
   { int nombre;
     fichier>>nombre;
     int x,y,pv,etat,team;
     int **tabMap;
     tabMap=new int* [nombre];
     for(int i=0; i<nombre; i++){
       fichier >>x>>y>>pv>>etat>>team;
       tabMap[i]=new int[5];
       tabMap[i][0]=x;
       tabMap[i][1]=y;
       tabMap[i][2]=pv;
       tabMap[i][3]=etat;
       tabMap[i][4]=team;
     }
     fichier.close();
     return tabMap;
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
