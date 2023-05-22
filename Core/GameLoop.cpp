//
// Created by Jake on 5/17/2023.
//

#include <iostream>
#include "GameLoop.h"


GameLoop::GameLoop() : gameWindow("Game Window", sf::Vector2u(800, 600)) {
    clock.restart();
    srand(time(nullptr));

    // TODO: Set up members
}

void GameLoop::Update() {

    // TODO: Call Update and tick functoins

    gameWindow.Update();
}

void GameLoop::Render() {
    gameWindow.BeginDraw();
    gameWindow.GetRenderWindow()->draw(sprite);
    // TODO: Add renderables here... perhaps an array or vector of renderables
    gameWindow.EndDraw();
}