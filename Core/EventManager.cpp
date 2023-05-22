//
// Created by Jake on 5/18/2023.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "EventManager.h"

EventManager::EventManager() : hasFocus(true) { LoadBindings(); }

EventManager::~EventManager() {
    for (auto &itr : bindings) {
        delete itr.second;
        itr.second = nullptr;
    }
}

bool EventManager::AddBinding(Binding *binding) {
    if (bindings.find(binding->name) != bindings.end())
        return false;

    return bindings.emplace(binding->name, binding).second;
}

bool EventManager::RemoveBinding(std::string name) {
    auto itr = bindings.find(name);
    if (itr == bindings.end()) { return false; }
    delete itr->second;
    bindings.erase(itr);
    return true;
}

void EventManager::HandleEvent(sf::Event &event) {
    for (auto &bindingItr : bindings) {
        Binding* bind = bindingItr.second;
        for (auto &eventItr : bind->events) {
            EventType sfmlEvent = (EventType)event.type;
            if (eventItr.first != sfmlEvent) { continue; }
            if (sfmlEvent == EventType::KeyDown || sfmlEvent == EventType::KeyUp) {
                if (eventItr.second.eventCode == event.key.code) {
                    if (bind->details.keyCode != -1) {
                        bind->details.keyCode = eventItr.second.eventCode;
                    }
                    ++(bind->numberOfBindings);
                    break;
                }
            } else if (sfmlEvent == EventType::MButtonDown || sfmlEvent == EventType::MButtonUp) {
                if (eventItr.second.eventCode == event.mouseButton.button) {
                    bind->details.mousePosition.x = event.mouseButton.x;
                    bind->details.mousePosition.y = event.mouseButton.y;
                    if (bind->details.keyCode != -1) {
                        bind->details.keyCode = eventItr.second.eventCode;
                    }
                    ++(bind->numberOfBindings);
                }
            } else {
                if (sfmlEvent == EventType::MouseWheel) {
                    bind->details.mouseWheelDelta = event.mouseWheel.delta;
                } else if (sfmlEvent == EventType::WindowResized) {
                    bind->details.size.x = event.size.width;
                    bind->details.size.y = event.size.height;
                } else if (sfmlEvent == EventType::TextEntered) {
                    bind->details.textEntered = event.text.unicode;
                }
                ++(bind->numberOfBindings);
            }
        }
    }
}

void EventManager::Update() {
    if (!hasFocus) { return; }
    for (auto &bindingItr : bindings) {
        Binding* bind = bindingItr.second;
        for (auto &eventItr : bind->events) {
            switch (eventItr.first) {
                case (EventType::Keyboard) :
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(eventItr.second.eventCode))) {
                        if (bind->details.keyCode != -1) {
                            bind->details.keyCode = eventItr.second.eventCode;
                        }
                        ++(bind->numberOfBindings);
                    }
                break;
                case (EventType::Mouse) :
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Button(eventItr.second.eventCode))) {
                        if (bind->details.keyCode != -1) {
                            bind->details.keyCode = eventItr.second.eventCode;
                        }
                        ++(bind->numberOfBindings);
                    }
                break;
                case (EventType::Joystick) :
                    // TODO: for later expansion in case I wanna add joystick support. We'll see...
                break;
            }
        }

        if (bind->events.size() == bind->numberOfBindings) {
            auto callbackItr = callbacks.find(bind->name);
            if (callbackItr != callbacks.end()) {
                callbackItr->second(&bind->details);
            }
        }

        bind->numberOfBindings = 0;
        bind->details.Clear();
    }
}

void EventManager::LoadBindings() {
    std::string delimiter = ":";

    std::ifstream bindingsFile;
    bindingsFile.open("keys.cfg");
    if (!bindingsFile.is_open()) {
        std::cout << "! Failed loading keys.cfg" << std::endl;
        return;
    }
    std::string line;
    while (std::getline(bindingsFile, line)) {
        std::stringstream keystream(line);
        std::string callbackName;
        keystream >> callbackName;

        Binding* bind = new Binding(callbackName);
        while (!keystream.eof()) {
            std::string keyval;
            keystream >> keyval;
            int start = 0;
            int end = keyval.find(delimiter);
            if (end == std::string::npos) {
                delete bind;
                bind = nullptr;
                break;
            }
            EventType type = EventType(
                    stoi(keyval.substr(start, end - start)));
            int code = stoi(keyval.substr(end + delimiter.length(),
                    keyval.find(delimiter, end + delimiter.length())));
            EventInfo eventInfo;
            eventInfo.eventCode = code;

            bind->BindEvent(type, eventInfo);
        }

        if (!AddBinding(bind)) { delete bind; }
        bind = nullptr;
    }

    bindingsFile.close();
}