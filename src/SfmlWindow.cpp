#include "SfmlWindow.hpp"

SfmlWindow::SfmlWindow(SfmlWindowProperties windowProperties, std::string name, int frameRateLimit) : videoMode(windowProperties->largeurGrille*64,windowProperties->hauteurGrille*64),window(videoMode, name){
  this->window.setFramerateLimit(frameRateLimit);
}

void SfmlWindow::setFond(){
  textureFond.loadFromFile("../res/fonds/image.jpg");
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
