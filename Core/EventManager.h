//
// Created by Jake on 5/17/2023.
//

#ifndef SFML_GAME_ENGINE_EVENTMANAGER_H
#define SFML_GAME_ENGINE_EVENTMANAGER_H

#include <vector>
#include <SFML/Window/Event.hpp>
#include <unordered_map>
#include <functional>
#include <SFML/Graphics/RenderWindow.hpp>

enum class EventType {
    KeyDown = sf::Event::KeyPressed,
    KeyUp = sf::Event::KeyReleased,
    MButtonDown = sf::Event::MouseButtonPressed,
    MButtonUp = sf::Event::MouseButtonReleased,
    MouseWheel = sf::Event::MouseWheelMoved,
    WindowResized = sf::Event::Resized,
    GainedFocus = sf::Event::GainedFocus,
    LostFocus = sf::Event::LostFocus,
    MouseEntered = sf::Event::MouseEntered,
    MouseLeft = sf::Event::MouseLeft,
    Closed = sf::Event::Closed,
    TextEntered = sf::Event::TextEntered,
    Keyboard = sf::Event::Count +1, Mouse, Joystick
};

struct EventInfo {
    EventInfo() { eventCode = 0; }
    EventInfo(int event) { eventCode = event; }
    union {
        int eventCode;
    };
};

using Events = std::vector<std::pair<EventType, EventInfo>>;

struct EventDetails {
    EventDetails(const std::string& bindName) : eventName(bindName) {
        Clear();
    }

    std::string eventName;

    sf::Vector2i size;
    sf::Uint32 textEntered;
    sf::Vector2i mousePosition;
    int mouseWheelDelta;
    int keyCode;

    void Clear() {
        size = sf::Vector2i(0, 0);
        textEntered = 0;
        mousePosition = sf::Vector2i(0, 0);
        mouseWheelDelta = 0;
        keyCode = 0;
    }
};

struct Binding {
    Binding(const std::string& bindingName) : name(bindingName), details(bindingName), numberOfBindings(0) {}

    void BindEvent(EventType type, EventInfo info = EventInfo()) {
        events.emplace_back(type, info);
    }

    Events events;
    std::string name;
    int numberOfBindings;

    EventDetails details;
};

using Bindings = std::unordered_map<std::string, Binding*>;

using Callbacks = std::unordered_map<std::string, std::function<void(EventDetails*)>>;

class EventManager {
public:
    EventManager();
    ~EventManager();

    bool AddBinding(Binding *binding);
    bool RemoveBinding(std::string name);
    void SetFocus(const bool& focus);

    template<class T>
    bool AddCallback(const std::string& name, void(T::*function) (EventDetails*), T* instance) {
        auto temp = std::bind(function, instance, std::placeholders::_1);
        return callbacks.emplace(name, temp).second;
    }

    void RemoveCallback(const std::string& name) {
        callbacks.erase(name);
    }

    void HandleEvent(sf::Event& event);
    void Update();

    sf::Vector2i GetMousePos(sf::RenderWindow* window = nullptr) {
        return (window ? sf::Mouse::getPosition(*window) : sf::Mouse::getPosition());
    }

private:
    void LoadBindings();

    Bindings bindings;
    Callbacks callbacks;
    bool hasFocus;
};


#endif //SFML_GAME_ENGINE_EVENTMANAGER_H
