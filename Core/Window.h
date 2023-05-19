//
// Created by Jake on 5/17/2023.
//

#include <string>
#include "SFML/Graphics.hpp"
#include "EventManager.h"

#ifndef SFML_GAME_ENGINE_WINDOW_H
#define SFML_GAME_ENGINE_WINDOW_H


class Window {

public:
    Window();
    Window(const std::string& title, sf::Vector2u size, bool fullscreen = false);
    ~Window() { Destroy(); }

    // Beginning of frame calculation. Clears previous frame
    void BeginDraw() { renderWindow.clear(sf::Color::Black); }

    // End of frame calculation. Displays new frame to be rendered
    void EndDraw() { renderWindow.display(); }

    // Updating for events
    void Update();

    // Destroys the window and recreates in the new bFullscreen mode
    void ToggleFullScreen(EventDetails* details);

    bool IsFocused();
    EventManager* GetEventManager();

    void Close(EventDetails* details = nullptr) { bIsDone = true; }


private:
    // Creates a new window with current properties
    void Create();

    // Clears window and preps for delete
    void Destroy() { renderWindow.clear(); }

    EventManager eventManager;

    sf::RenderWindow renderWindow;
    sf::Vector2u windowSize;
    std::string windowTitle;

    bool bIsFocused;
    bool bFullscreen;
    bool bIsDone;
};


#endif //SFML_GAME_ENGINE_WINDOW_H
