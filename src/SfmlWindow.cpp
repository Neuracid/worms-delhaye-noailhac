#include "SfmlWindow.hpp"

SfmlWindow::SfmlWindow(int largeurPix,int hauteurPix, std::string name, int frameRateLimit) : videoMode(largeurPix,hauteurPix),window(videoMode, name){
  this->window.setFramerateLimit(frameRateLimit);
}

int SfmlWindow::setFond(){
  if (!textureFond.loadFromFile("../res/fonds/image.jpg"))
    return -1;

  spriteFond.setTexture(textureFond);



}

void SfmlWindow::displayWindow(){
  while (window.isOpen())
  {
      // on gère les évènements
      sf::Event event;
      while (window.pollEvent(event))
      {
          if(event.type == sf::Event::Closed || ((event.type == sf::Event::KeyPressed) && (event.key.code==sf::Keyboard::Escape)) )
              window.close();
      }

      // on dessine le niveau
      window.clear();
      window.draw(spriteFond);
      window.display();
  }
}
