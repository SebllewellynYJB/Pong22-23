#ifndef SPACEINVADERS_GAMEOBJECT_H
#define SPACEINVADERS_GAMEOBJECT_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>

class GameObject
{
 public:
  GameObject();
  ~GameObject();
  bool initialiseSprite(sf::Texture &texture, std::string filename);
  sf::Sprite* getSprite();


 private:
  sf::Sprite* sprite = nullptr;
};

// Code for this section was taken from my work last year
// C:\Users\sebll\OneDrive - UWE Bristol\platformer-21-22-SebllewellynYJB

#endif // SPACEINVADERS_GAMEOBJECT_H