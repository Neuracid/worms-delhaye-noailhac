#include "SfmlWindow.hpp"

SfmlWindow::SfmlWindow(int largeurPix,int hauteurPix, std::string name, int frameRateLimit){
  this->videoMode.width=largeurPix;
  this->videoMode.height=hauteurPix;

  this->window = sf::RenderWindow window(videoMode, name);
  this->window.setFramerateLimit(frameRateLimit);
}
