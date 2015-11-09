#include "SfmlWindow.hpp"

SfmlWindow::SfmlWindow(std::string name, int frameRateLimit) : map(windowProperties.largeurGrille,windowProperties.hauteurGrille), videoMode(windowProperties.largeurGrille*64,windowProperties.hauteurGrille*64),window(videoMode, name){
 this->window.setFramerateLimit(frameRateLimit);
  setWorms();
  setFond();
  font.loadFromFile("../res/ttf/ComicSansMs.ttf");
  setText();
}

void SfmlWindow::setFond(){
  textureFond.loadFromFile("../res/fonds/bleu.jpg");
  spriteFond.setTexture(textureFond);
}

void SfmlWindow::displayWindow(){
  window.clear();
  window.draw(spriteFond);
  window.display();
  while (window.isOpen())
  {
      //test sur les text

      // on gère les évènements
      sf::Event event;
      while (window.pollEvent(event))
      {
          if(event.type == sf::Event::Closed || ((event.type == sf::Event::KeyPressed) && (event.key.code==sf::Keyboard::Escape)) ){
            window.close();
          }
          else
          {
              if (event.type == sf::Event::KeyPressed)
              {
                  switch(event.key.code)
                  {
                      case sf::Keyboard::Down: window.draw(spriteFond); window.draw(map); drawWorms(); drawText();
                      break;
                      case sf::Keyboard::Up: map.parseTxt(); map.load("../res/blocs/terrain.png", sf::Vector2u(64, 64), windowProperties.largeurGrille, windowProperties.hauteurGrille); worms[0]->load(sf::Vector2u(64, 64));
                      break;
                  }
                  window.display();

              }
          }

      }

      // on dessine le niveau
      // window.clear();
      // window.draw(spriteFond);
      // window.draw(map);
      // drawWorms();
      // drawText();

  }
}

void SfmlWindow::setWorms(){
  worms.resize(windowProperties.nombreDeWorms);
  for(int i=0;i<windowProperties.nombreDeWorms;i++){
    worms[i].reset(new SfmlWorms(windowProperties.tabWorms[i],"../res/waccuse11.png"));
  }
}

void SfmlWindow::drawWorms(){
  for(int i=0;i<worms.size();i++){
    window.draw(*worms[i]);
  }
}

void SfmlWindow::setText(){
 text.resize(windowProperties.nombreDeWorms);
 for(int i=0;i<text.size();i++){
   text[i].setFont(font);
   std::string myString =std::to_string(windowProperties.tabWorms[i][2]);;
   text[i].setString(myString);
   text[i].setCharacterSize(18);
   switch (windowProperties.tabWorms[i][4]) {
     case 0:text[i].setColor(sf::Color::Red);
            break;
    case 1:text[i].setColor(sf::Color::Yellow);
           break;
   case 2:text[i].setColor(sf::Color::Green);
          break;
    case 3:text[i].setColor(sf::Color::Blue);
           break;
   }
   text[i].setPosition(64*windowProperties.tabWorms[i][0]+18,64*windowProperties.tabWorms[i][1]);
 }
}

void SfmlWindow::drawText(){
  for(int i=0;i<text.size();i++){
    window.draw(text[i]);
  }
}
