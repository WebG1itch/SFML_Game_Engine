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
    void HandleInput();

private:

    Window gameWindow;

};


#endif //SFML_GAME_ENGINE_GAMELOOP_H
