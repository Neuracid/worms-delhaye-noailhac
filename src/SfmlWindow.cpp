#include "SfmlWindow.hpp"

SfmlWindow::SfmlWindow(SfmlWindowProperties windowProperties, std::string name, int frameRateLimit) : worms(windowProperties.largeurGrille,windowProperties.hauteurGrille,windowProperties.nombreDeWorms), map(windowProperties.largeurGrille,windowProperties.hauteurGrille), videoMode(windowProperties.largeurGrille*64,windowProperties.hauteurGrille*64),window(videoMode, name){
  this->window.setFramerateLimit(frameRateLimit);
}

void SfmlWindow::setFond(){
  textureFond.loadFromFile("../res/fonds/bleu.jpg");
  spriteFond.setTexture(textureFond);
}

void SfmlWindow::displayWindow(){
  while (window.isOpen())
  {
      // Create a text
      sf::Text text;
      // Declare a new font
      sf::Font font;
      // Load it from a file
      if (!font.loadFromFile("../res/fonts/arial.ttf"))
      {
          // error...
      }
      text.setFont(font);
      text.setString("Hello world");
      text.setCharacterSize(64);
      text.setPosition(0,64*7);
      text.setStyle(sf::Text::Bold);
      text.setColor(sf::Color::Red);

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
      window.draw(worms);
      window.draw(text);
      window.display();
  }
}
