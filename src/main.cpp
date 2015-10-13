#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


using namespace sf;
using namespace std;


int main()
{
  sf::VideoMode videoMode(800,600);
  sf::RenderWindow window(videoMode, "Worms");

  // Load a music to play
  sf::Music music;
  if (!music.openFromFile("../res/musiques/Red.ogg"))
    return EXIT_FAILURE;

  // joue la musique
  music.play();

  // Load a texture from a file
  sf::Texture texture;
  if (!texture.loadFromFile("../res/fonds/image.jpg"))
      return -1;

  // Assign it to a sprite
  sf::Sprite sprite;
  sprite.setTexture(texture);

  // on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
  while (window.isOpen())
  {
      window.clear();
      // window.draw(triangle);
      // Draw the textured sprite
      window.draw(sprite);
      window.display();
      // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
      sf::Event event;
      while (window.pollEvent(event))
      {
          // évènement "fermeture demandée" : on ferme la fenêtre
          if ((event.type == Event::Closed) || ((event.type == Event::KeyPressed) && (event.key.code==Keyboard::Escape)) )
              window.close();
      }
  }
    return 0;

}
