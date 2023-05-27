//
// Created by Jake on 5/26/2023.
//


#include "Textbox.h"

void Textbox::Setup(int charSize, int width, sf::Vector2f screenPos) {

    sf::Vector2f l_offset(2.0f, 2.0f);

    font.loadFromFile("OpenSans-Regular.ttf");
    content.setFont(font);
    content.setString("");
    content.setCharacterSize(charSize);
    content.setFillColor(sf::Color::White);
    content.setPosition(screenPos + l_offset);
    content.setFillColor(sf::Color(255, 255, 255, 25));

    background.setSize(sf::Vector2f(width, (charSize * 1.2f)));
    background.setFillColor(sf::Color(90, 90, 90, 255));
    background.setPosition(screenPos);
}

void Textbox::SetText(const std::string& message) {
    content.setString(message);
}

void Textbox::Render(sf::RenderWindow& window) {
    if (bVisible) {
        window.draw(content);
    }
}

void Textbox::SetPosition(sf::Vector2f position) {
    background.setPosition(position);
    content.setPosition(position);
}
