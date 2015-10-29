// #include <iostream>
// #include <SFML/Window.hpp>
// #include <SFML/Graphics.hpp>
// #include <SFML/Audio.hpp>
// #include "RenduMap.hpp"
//
//
//
// int main() {
//   sf::VideoMode videoMode(1024,512);
//   sf::RenderWindow window(videoMode, "Worms");
//   window.setFramerateLimit(30); // un appel suffit, après la création de la fenêtre
//
//   // on définit le niveau à l'aide de numéro de tuiles
//   const int level[] =
//   {
//       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//       0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0,
//       0, 0, 0, 0, 3, 2, 2, 3, 3, 3, 3, 1, 3, 0, 0, 0,
//       0, 0, 0, 0, 3, 2, 2, 2, 3, 3, 3, 3, 3, 3, 0, 0,
//       0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0,
//       2, 2, 2, 3, 3, 3, 3, 2, 2, 3, 3, 3, 3, 3, 2, 2,
//       2, 3, 3, 3, 3, 3, 3, 2, 2, 2, 3, 3, 3, 3, 2, 2,
//   };
//
//   // on définit l'emplacement des joueurs à l'aide de numéro de tuiles
//   const int player[] =
//   {
//       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//       0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
//       0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//   };
//
//
//
//   //fond
//   sf::Texture texture;
//   if (!texture.loadFromFile("../res/fonds/image.jpg")){
//     return -1;
//   }
//   sf::Sprite spriteFond;
//   spriteFond.setTexture(texture);
//
//   // Musiques
//   sf::Music music1;
//   if (!music1.openFromFile("../res/musiques/Red.ogg"))
//     return 0;
//
//   sf::Music music2;
//   if (!music2.openFromFile("../res/musiques/What.ogg"))
//     return 0;
//
//
//
//
//
//   // on crée la tilemap avec le niveau précédemment défini
//   RenduMap map;
//   int* level2=map.parseTxt("../res/txt/map.txt");
//   if (!map.load("../res/blocs/terrain.png", sf::Vector2u(64, 64), level2, 16, 8))
//       return -1;
//
//   RenduMap perso;
//   if (!perso.load("../res/WormsGeneral/Worms/waccuse11.png", sf::Vector2u(64, 64), player, 16, 8))
//       return -1;
//
//   // on fait tourner la boucle principale
//   while (window.isOpen())
//   {
//       // on gère les évènements
//       sf::Event event;
//       while (window.pollEvent(event))
//       {
//           if(event.type == sf::Event::Closed || ((event.type == sf::Event::KeyPressed) && (event.key.code==sf::Keyboard::Escape)) )
//               window.close();
//           else
//           {
//               if (event.type == sf::Event::KeyPressed)
//               {
//                   switch(event.key.code)
//                   {
//                       case sf::Keyboard::Up: music2.stop(); music1.play();
//                       break;
//                       case sf::Keyboard::Down: music1.stop(); music2.play();
//                       break;
//                   }
//               }
//           }
//       }
//
//       // on dessine le niveau
//       window.clear();
//       window.draw(spriteFond);
//       window.draw(map);
//       window.draw(perso);
//       window.display();
//   }
//
//   return 0;
// }
