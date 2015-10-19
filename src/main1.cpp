// #include <iostream>
// #include <SFML/Window.hpp>
// #include <SFML/Graphics.hpp>
// #include <SFML/Audio.hpp>
//
//
// using namespace sf;
// using namespace std;
//
//
// int main() {
//   sf::VideoMode videoMode(800,600);
//   sf::RenderWindow window(videoMode, "Worms");
//
//   // Load a music to play
//   sf::Music music1;
//   if (!music1.openFromFile("../res/musiques/Red.ogg"))
//     return 0;
//
//   // Load a music to play
//   sf::Music music2;
//   if (!music2.openFromFile("../res/musiques/What.ogg"))
//     return 0;
//
//   // joue la musique
//   //music1.play();
//
//   // Load a texture from a file
//   sf::Texture texture;
//   if (!texture.loadFromFile("../res/fonds/image.jpg")){
//
//     return -1;
//   }
//
//   //TEST
//   sf::Texture image;
//   if (!image.loadFromFile("../res/Worms General Sprites/Worms/waccuse.png")){
//     return -1;
//   }
//
//   sf::Sprite spriteWorms;
//   spriteWorms.setTexture(image);
//   spriteWorms.setPosition(Vector2f(2,2));
//
//   //FINTEST
//
//
//   // Assign it to a sprite
//   sf::Sprite spriteFond;
//   spriteFond.setTexture(texture);
//
//   // on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
//   while (window.isOpen())
//   {
//       window.clear();
//       // window.draw(triangle);
//       // Draw the textured sprite
//       window.draw(spriteWorms);
//       window.draw(spriteFond);
//       window.display();
//       // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
//       sf::Event event;
//       while (window.pollEvent(event))
//       {
//           // évènement "fermeture demandée" : on ferme la fenêtre
//           if ((event.type == Event::Closed) || ((event.type == Event::KeyPressed) && (event.key.code==Keyboard::Escape)) )
//               window.close();
//           else
//           {
//               if (event.type == Event::KeyPressed)
//               {
//                   switch(event.key.code)
//                   {
//                       case Keyboard::Up: music2.stop(); music1.play();
//                       break;
//                       case Keyboard::Down: music1.stop(); music2.play();
//                       break;
//                   }
//               }
//           }
//       }
//   }
//     return 0;
//
// }
