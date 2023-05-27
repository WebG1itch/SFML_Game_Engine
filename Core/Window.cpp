//
// Created by Jake on 5/17/2023.
//

#include <iostream>
#include "Window.h"

Window::Window() {
    Setup("Window", {600, 800}, false);
}

Window::Window(const std::string &title, sf::Vector2u size, bool fullscreen) {
    Setup(title, size, fullscreen);
}

void Window::Setup(const std::string &title, sf::Vector2u size, bool fullscreen) {
    windowTitle = title;
    windowSize = size;
    bFullscreen = fullscreen;

    bIsDone = false;
    bIsFocused = true;

    eventManager.AddCallback("Fullscreen_toggle", &Window::ToggleFullScreen, this);
    eventManager.AddCallback("Window_close", &Window::Close, this);



    Create();
}

void Window::Create() {
    auto style = bFullscreen ? sf::Style::Fullscreen : sf::Style::Default;
    renderWindow.create(sf::VideoMode(windowSize.x, windowSize.y, 32), windowTitle, style);
}

void Window::Update() {
    sf::Event event;
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
    renderWindow.close();
    Create();
}

