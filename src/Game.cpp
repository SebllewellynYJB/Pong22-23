
#include "Game.h"
#include <iostream>
#include "string"

Game::Game(sf::RenderWindow& game_window) : window(game_window)
{
  srand(time(NULL));

}

Game::~Game()
{

}

bool Game::init()
{
  in_menu = true;
  //Font information
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "font did not load \n";
  }
  // Menu text info
  title_text.setString("Pong");
  title_text.setFont(font);
  title_text.setCharacterSize(70);
  title_text.setFillColor(sf::Color(255,0,0));
  title_text.setPosition(430,0);

  play.setString("Play");
  play.setFont(font);
  play.setCharacterSize(40);
  play.setFillColor(sf::Color(0, 100, 0));
  play.setPosition(360,200);

  quit.setString("Quit");
  quit.setFont(font);
  quit.setCharacterSize(40);
  quit.setFillColor(sf::Color(100, 0, 0));
  quit.setPosition(560,200);

  menui.setString("Use left and right arrows to navigate menu, press enter to move on");
  menui.setFont(font);
  menui.setCharacterSize(20);
  menui.setFillColor(sf::Color(200,200,200));
  menui.setPosition(10,350);

  quitany.setString("Press Q to quit at any time");
  quitany.setFont(font);
  quitany.setCharacterSize(20);
  quitany.setFillColor(sf::Color(100,0,200));
  quitany.setPosition(10,500);

  instructions.setString("How to play");
  instructions.setFont(font);
  instructions.setCharacterSize(40);
  instructions.setFillColor(sf::Color(200,50,20));
  instructions.setPosition(10,275);

  redi.setString("Red paddle- UP arrow to move up, Down arrow to move down");
  redi.setFont(font);
  redi.setCharacterSize(20);
  redi.setFillColor(sf::Color(200,0,0));
  redi.setPosition(10,400);

  bluei.setString("Blue paddle- W to move up, S to move down");
  bluei.setFont(font);
  bluei.setCharacterSize(20);
  bluei.setFillColor(sf::Color(0,0,200));
  bluei.setPosition(10,450);
  //Textures information
  timer.setString("Timer:");
  timer.setFont(font);
  timer.setCharacterSize(40);
  timer.setPosition(100,50);

  score.setString("Score - ");
  score.setFont(font);
  score.setCharacterSize(40);
  score.setPosition(800,50);

  // Textures information
  PaddleR.initialiseSprite(PaddleR_texture, "Data/Images/paddleRed.png");
  PaddleR.getSprite()->setPosition(900,300);
  PaddleR.getSprite()->rotate(90);

  PaddleB.initialiseSprite(PaddleB_texture, "Data/Images/paddleBlue.png");
  PaddleB.getSprite()->setPosition(100,300);
  PaddleB.getSprite()->rotate(90);

  Ball.initialiseSprite(Ball_texture, "Data/Images/ballBlue.png");
  Ball.getSprite()->setPosition(400,350);
  return true;

}
bool intersects(const sf::RectangleShape & rect1, const sf::RectangleShape & rect2)
{

}

void Game::update(float dt)
//Ball movement/ collision
{
  Ball.getSprite()->move(3.0f,0.0f);
  if (PaddleR.getSprite()->getGlobalBounds().intersects(Ball.getSprite()->getGlobalBounds()))
  {
    std::cout << "Collision" << std::endl;
    Ball.getSprite()->move(-700.0f,0.0f);
  }
  if (PaddleB.getSprite()->getGlobalBounds().intersects(Ball.getSprite()->getGlobalBounds()))
  {
    std:: cout << "Collision" << std::endl;
  }
  return;

}

void Game::render()
{
  if (in_menu)
    //Text that is rendered to the menu
  {
    window.draw(title_text);
    window.draw(play);
    window.draw(quit);
    window.draw(menui);
    window.draw(quitany);
    window.draw(instructions);
    window.draw(redi);
    window.draw(bluei);
  }
  else
    //Textures and time + score that are rendered to the game screen
  {
    window.draw(timer);
    window.draw(score);
    window.draw(*PaddleR.getSprite());
    window.draw(*PaddleB.getSprite());
    window.draw(*Ball.getSprite());
  }
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);
}

void Game::keyPressed(sf::Event event)
{
  //menu keys for play and quit
  if (
    (event.key.code == sf::Keyboard::Left) ||
    (event.key.code == sf::Keyboard::Right))
  {
    play_selected = !play_selected;
    if (play_selected)
    {
      play.setString("> Play <");
      quit.setString("Quit");
    }
    else
    {
      play.setString("Play");
      quit.setString("> Quit <");
    }
  }
  else if (event.key.code == sf::Keyboard::Enter)
  {
    if (play_selected)
    {
      in_menu = false;
    }
    else
    {
      window.close();
    }
  }
  //Game keys for paddle movements
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
  {
    PaddleB.getSprite()->move(0.0f,3);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
  {
    PaddleB.getSprite()->move(0,-3);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
  {
    PaddleR.getSprite()->move(0.0f,3);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  {
    PaddleR.getSprite()->move(0.0f,-3);
  }
  //Key to quit the game
  if (event.key.code == sf::Keyboard::Q)
  {
    window.close();
  }
}



