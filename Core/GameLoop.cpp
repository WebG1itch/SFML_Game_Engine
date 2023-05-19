//
// Created by Jake on 5/17/2023.
//

#include "GameLoop.h"

GameLoop::GameLoop() : gameWindow("Game Window", sf::Vector2u(150, 100)) {
    // TODO: Set up members
}

void GameLoop::Update() {

    // TODO: Call Update and tick functoins

    gameWindow.Update();
}

void GameLoop::Render() {
    gameWindow.BeginDraw();
    // TODO: Add renderables here... perhaps an array or vector of renderables
    gameWindow.EndDraw();
}