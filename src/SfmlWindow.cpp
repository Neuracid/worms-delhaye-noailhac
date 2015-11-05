#include "SfmlWindow.hpp"

SfmlWindow::SfmlWindow(std::string name, int frameRateLimit) : map(windowProperties.largeurGrille,windowProperties.hauteurGrille), videoMode(windowProperties.largeurGrille*64,windowProperties.hauteurGrille*64),window(videoMode, name){
 this->window.setFramerateLimit(frameRateLimit);
  setWorms( );
  setFond();
  
}

void SfmlWindow::setFond(){
  textureFond.loadFromFile("../res/fonds/bleu.jpg");
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
      window.draw(map);
      drawWorms();
      window.display();
  }
}

void SfmlWindow::setWorms(){
  for(int i=0;i<windowProperties.nombreDeWorms;i++){
    SfmlWorms nouveau(windowProperties.tabWorms[i],"../res/waccuse11.png");
    worms.push_back(nouveau);
  }
}

void SfmlWindow::drawWorms(){
  for(int i=0;i<windowProperties.nombreDeWorms;i++){
    window.draw(worms[i]);
  }
}
