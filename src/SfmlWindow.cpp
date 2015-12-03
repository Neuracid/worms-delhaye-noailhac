#include "SfmlWindow.hpp"

SfmlWindow::SfmlWindow(Etat* etat,std::string name, int frameRateLimit, Engine* engine) : videoMode(etat->map.getLargeur()*64,etat->map.getHauteur()*64), window(videoMode, name), map(etat,etat->map.getLargeur(),etat->map.getHauteur()){
  this->etat = etat;
  this->window.setFramerateLimit(frameRateLimit);
  setWorms();
  setFond();
  font.loadFromFile("../res/ttf/ComicSansMs.ttf");
  setText();
  this->engine=engine;
}

void SfmlWindow::setFond(){
  textureFond.loadFromFile("../res/fonds/bleu.jpg");
  spriteFond.setTexture(textureFond);
}

void SfmlWindow::displayWindow(){
  engine->regleGravite(etat);
  engine->regleDeTerrain(etat);
  while (window.isOpen())
  {
      // on dessine le niveau
      window.clear();
      engine->regleGravite(etat);
      engine->regleDeTerrain(etat);
      update();
      window.draw(spriteFond);
      window.draw(map);
      drawText();
      drawWorms();
      window.display();

      // on gère les évènements
      sf::Event event;
      while (window.pollEvent(event))
      {
          if(event.type == sf::Event::Closed || ((event.type == sf::Event::KeyPressed) && (event.key.code==sf::Keyboard::Escape)) ){
            window.close();
          }
          else{
            if (event.type == sf::Event::KeyPressed) {
              switch(event.key.code){
                case sf::Keyboard::P:
                          engine->changementDeJoueur(etat);
                          break;
                case sf::Keyboard::G:
                          engine->mineGaz(etat);
                          break;
                case sf::Keyboard::C:
                          engine->creuser(etat);
                          break;
                case sf::Keyboard::B:
                          engine->barricader(etat);
                          break;
                case sf::Keyboard::K:
                          engine->kungfu(etat);
                          break;
                case sf::Keyboard::T:
                          engine->tir(etat);
                          break;
                case sf:: Keyboard::Right:
                          if(etat->listeWormsJoueurs[etat->placeWormsActif].worms->getDirection()==1)
                          engine->deplacement(etat,etat->placeWormsActif);
                          engine->changementDeDirection(etat,Worms::right);
                          //printf("%d",engine->getNbDeplacements());
                          break;
                case sf::Keyboard::E:
                          engine->grappin(etat);
                          break;
                case sf:: Keyboard::Left:
                          if(etat->listeWormsJoueurs[etat->placeWormsActif].worms->getDirection()==-1)
                          engine->deplacement(etat,etat->placeWormsActif);
                          engine->changementDeDirection(etat,Worms::left);
                          //printf("%d",engine->getNbDeplacements());
                          break;


                default: break;
              }
            }
          }
        }
        if (engine->finTour(etat)){
          engine->changementDeJoueur(etat);
        }
      }
    }

void SfmlWindow::setWorms(){
  worms.resize(etat->listeWormsJoueurs.size());
  for(size_t i=0;i<etat->listeWormsJoueurs.size();i++){
    worms[i]=new SfmlWorms(etat->listeWormsJoueurs[i].worms);
  }
}

void SfmlWindow::updateWorms(){
  for(size_t i=0;i<etat->listeWormsJoueurs.size();i++){
    worms[i]->update(etat->listeWormsJoueurs[i].worms);
  }
}

void SfmlWindow::drawWorms(){
  for(size_t i=0;i<worms.size();i++){
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
  for(size_t i=0;i<text.size();i++){
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
  horloge.setString(std::to_string(((etat->getTempTour()-(int)etat->getTime())/60))+":"+std::to_string(((etat->getTempTour()-(int)etat->getTime())%60)));
  horloge.setCharacterSize(21);
  horloge.setColor(sf::Color::White);
  horloge.setFont(font);
  horloge.setPosition(0,0);
}

void SfmlWindow::drawText(){
  for(size_t i=0;i<text.size();i++){
    window.draw(text[i]);
  }
  window.draw(textActif);
  window.draw(horloge);
}

void SfmlWindow::update(){
  //map
  updateWorms();
  setFond();
  setText();
  map.update(etat);
}
