//
// Created by Jake on 5/17/2023.
//

#include "Window.h"

Window::Window() {
    windowTitle = "Window";
    windowSize = { 600, 800 };
    bFullscreen = false;
    Create();
}

Window::Window(const std::string &title, sf::Vector2u size, bool fullscreen) {
    windowTitle = title;
    windowSize = size;
    this->bFullscreen = fullscreen;
    Create();
}

void Window::Create() {
    auto style = bFullscreen ? sf::Style::Fullscreen : sf::Style::Default;
    renderWindow.create({windowSize.x, windowSize.y, 32}, windowTitle, style);
}

void Window::Update() {
    sf::Event event{};
    while (renderWindow.pollEvent(event)) {
        if (event.type == sf::Event::LostFocus) {
            bIsFocused = false;
            eventManager.SetFocus(false);
        } else if (event.type == sf::Event::GainedFocus) {
            bIsFocused = true;
            eventManager.SetFocus(true);
        }
        eventManager.HandleEvent(event);
    }
    eventManager.Update();
}

void Window::ToggleFullScreen(EventDetails* details) {
    bFullscreen = !bFullscreen;
    Destroy();
    Create();
}