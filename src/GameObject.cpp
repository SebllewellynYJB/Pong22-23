#include "GameObject.h"
#include <iostream>

GameObject::GameObject()
{
  sprite = new sf::Sprite();
}

GameObject::~GameObject()
{
  delete sprite;
}

bool GameObject::initialiseSprite(sf::Texture& texture, std::string filename)
{
  if (!texture.loadFromFile(filename))
  {
    std::cout  <<"texture did not load";
  }
  sprite->setTexture(texture);
}

sf::Sprite* GameObject::getSprite()
{
  return sprite;
}

// Code for this section was taken from my work last year
// C:\Users\sebll\OneDrive - UWE Bristol\platformer-21-22-SebllewellynYJB