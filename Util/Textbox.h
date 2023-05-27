//
// Created by Jake on 5/26/2023.
//

#ifndef SFML_GAME_ENGINE_TEXTBOX_H
#define SFML_GAME_ENGINE_TEXTBOX_H

#include <string>
#include <vector>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Textbox {

public:
    Textbox() { Setup(9, 200, sf::Vector2f(0, 0)); }
    Textbox(int charSize, int width, sf::Vector2f screenPos) { Setup(charSize, width, screenPos); }
    ~Textbox() = default;

    void Setup(int charSize, int width, sf::Vector2f screenPos);
    void SetText(const std::string& message);
    void SetTextColor(sf::Color color) { content.setFillColor(color); }
    void SetBackgroundColor(sf::Color color) { background.setFillColor(color); }
    void SetPosition(sf::Vector2f position);
    void SetVisible(bool visible) { bVisible = visible; }
    void SetFont(const std::string& filename) { font.loadFromFile(filename); content.setFont(font); }

    void Render(sf::RenderWindow& window);

private:
    bool bVisible = true;

    sf::RectangleShape background;
    sf::Font font;
    sf::Text content;

    float paddingLeft = 0;
    float paddingTop = 0;
    float paddingRight = 0;
    float paddingBottom = 0;
};

#endif //SFML_GAME_ENGINE_TEXTBOX_H
