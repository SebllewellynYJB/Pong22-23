
#ifndef PONG_GAME_H
#define PONG_GAME_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"
class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  GameObject Ball;
  GameObject PaddleR;
  GameObject PaddleB;
  sf::Texture PaddleR_texture;
  sf::Texture PaddleB_texture;
  sf::Texture Ball_texture;
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);
  sf::Font font;
  sf::Text title_text;
  bool play_selected = true;
  bool in_menu;
  sf::Text play;
  sf::Text quit;
  sf::Text quitany;
  sf::Text instructions;
  sf::Text redi;
  sf::Text bluei;
  sf::Text menui;
  sf::Text score;
  sf::Text timer;

 private:
  sf::RenderWindow& window;
  sf::FloatRect RectangleShape;
  bool intersects(const sf::RectangleShape & rect1, const sf::RectangleShape & rect2);
  int blue = 0;

};

#endif // PONG_GAME_H