#include "SfmlWindow.hpp"

SfmlWindow::SfmlWindow(Etat* etat,std::string name, int frameRateLimit) : videoMode(etat->map.getLargeur()*64,etat->map.getHauteur()*64), window(videoMode, name), map(etat,etat->map.getLargeur(),etat->map.getHauteur()){
  this->etat = etat;
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
  Engine engine;
  while (window.isOpen())
  {
      // on dessine le niveau
      window.clear();
      window.draw(spriteFond);
      window.draw(map);
      drawText();
      drawWorms();
      engine.regleGravite(etat);
      window.display();

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
                      case sf::Keyboard::Down:
                                //drawWorms();
                                //window.draw(*worms[0]);
                                drawText();
                                break;

                      case sf::Keyboard::Up:
                                //map.parseMap();
                                //map.load("../res/blocs/terrain.png", sf::Vector2u(64, 64), etat->largeurmap, etat->hauteurmap);
                                update();

                                //worms[0].reset(new SfmlWorms(etat->tabWorms[0],"../res/waccuse11.png"));
                                break;
                      case sf:: Keyboard::Right:
                                engine.deplacementDroite(etat);
                                update();
                                break;
                      case sf:: Keyboard::Left:
                                engine.deplacementGauche(etat);
                                update();
                                break;


                      default: break;
                  }
                  engine.regleGravite(etat);
              }
          }
      }
  }
}

void SfmlWindow::setWorms(){
  worms.resize(etat->listeWormsJoueurs.size());
  for(int i=0;i<etat->listeWormsJoueurs.size();i++){
    worms[i].reset(new SfmlWorms(etat->listeWormsJoueurs[i].worms,"../res/WormsGeneral/Worms/wbackflp.png"));
  }
  worms[2].reset(new SfmlWorms(etat->listeWormsJoueurs[2].worms,"../res/WormsGeneral/Worms/wpnctop.png"));
  worms[3].reset(new SfmlWorms(etat->listeWormsJoueurs[3].worms,"../res/WormsGeneral/Worms/wbowlnk.png"));
}

void SfmlWindow::drawWorms(){
  for(int i=0;i<worms.size();i++){
    worms[i]->load(sf::Vector2u(64, 64));
    window.draw(*worms[i]);
  }
}

void SfmlWindow::setText(){
  textActif.setString("actif");
  textActif.setCharacterSize(21);
  textActif.setColor(sf::Color::White);
  textActif.setFont(font);
  textActif.setPosition(64*etat->listeWormsJoueurs[etat->placeWormsActif].worms->getPosition_x()+6,64*etat->listeWormsJoueurs[etat->placeWormsActif].worms->getPosition_y()+64);
  text.resize(etat->listeWormsJoueurs.size());
  for(int i=0;i<text.size();i++){
    text[i].setFont(font);
    std::string myString =std::to_string(etat->listeWormsJoueurs[i].worms->getVie());
    text[i].setString(myString);
    text[i].setCharacterSize(18);
    switch (etat->listeWormsJoueurs[i].joueur->getTeam()) {
     case 0:text[i].setColor(sf::Color::Red);
     break;
     case 1:text[i].setColor(sf::Color::Yellow);
     break;
     case 2:text[i].setColor(sf::Color::Green);
     break;
     case 3:text[i].setColor(sf::Color::Blue);
     break;
    }
    text[i].setPosition(64*etat->listeWormsJoueurs[i].worms->getPosition_x()+18,64*etat->listeWormsJoueurs[i].worms->getPosition_y());
  }
}

void SfmlWindow::drawText(){
  for(int i=0;i<text.size();i++){
    window.draw(text[i]);
    window.draw(textActif);
  }
}

void SfmlWindow::update(){
  //map
  setWorms();
  setFond();
  setText();
}
