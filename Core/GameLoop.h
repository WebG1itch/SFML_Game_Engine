//
// Created by Jake on 5/17/2023.
//
#include "Window.h"
#include "EventManager.h"
#ifndef SFML_GAME_ENGINE_GAMELOOP_H
#define SFML_GAME_ENGINE_GAMELOOP_H


class GameLoop {

public:
    GameLoop();
    ~GameLoop() = default;

    void Update();
    void Render();

    sf::Time GetElapsed() { return clock.getElapsedTime(); }
    void RestartClock() { clock.restart();}

    Window* GetWindow() { return &gameWindow; }
private:

    Window gameWindow;
    sf::Clock clock;

    sf::Texture texture;
    sf::Sprite sprite;

    sf::RectangleShape House;
    sf::RectangleShape Door;
    sf::RectangleShape Roof;
    sf::RectangleShape RoofCut;

    sf::CircleShape Hill;
    sf::CircleShape Hill1;
    sf::CircleShape Hill2;

    sf::CircleShape Hill3;
    sf::CircleShape Hill4;
    sf::CircleShape Hill5;

    sf::CircleShape Hill6;
    sf::CircleShape Hill7;
    sf::CircleShape Hill8;
};


#endif //SFML_GAME_ENGINE_GAMELOOP_H
