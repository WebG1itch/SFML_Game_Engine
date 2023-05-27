//
// Created by Jake on 5/17/2023.
//

#include <iostream>
#include "GameLoop.h"


GameLoop::GameLoop() : gameWindow("Game Window", sf::Vector2u(800, 600)) {
    clock.restart();
    srand(time(nullptr));

    Hill.setFillColor(sf::Color(0, 180, 0, 255));
    Hill.setRadius(300);
    Hill.setPosition(-175, 300);

    Hill1.setFillColor(sf::Color(0, 210, 0, 255));
    Hill1.setRadius(300);
    Hill1.setPosition(175, 300);

    Hill2.setFillColor(sf::Color(0, 200, 0, 255));
    Hill2.setRadius(300);
    Hill2.setPosition(525, 300);

    Hill3.setFillColor(sf::Color(0, 200, 0, 255));
    Hill3.setRadius(300);
    Hill3.setPosition(-225, 400);

    Hill4.setFillColor(sf::Color(0, 195, 0, 255));
    Hill4.setRadius(300);
    Hill4.setPosition(100, 375);

    Hill5.setFillColor(sf::Color(0, 210, 0, 255));
    Hill5.setRadius(300);
    Hill5.setPosition(400, 375);

    Hill6.setFillColor(sf::Color(0, 210, 0, 255));
    Hill6.setRadius(300);
    Hill6.setPosition(-125, 500);

    Hill7.setFillColor(sf::Color(0, 220, 0, 255));
    Hill7.setRadius(300);
    Hill7.setPosition(200, 490);

    Hill8.setFillColor(sf::Color(0, 200, 0, 255));
    Hill8.setRadius(300);
    Hill8.setPosition(475, 475);

    House.setFillColor(sf::Color(200,170,130, 255));
    House.setSize({60,80});
    House.setPosition(445, 230);

    Door.setFillColor(sf::Color(110,80,40, 255));
    Door.setSize({20,30});
    Door.setPosition(475, 280);

    Roof.setFillColor(sf::Color(110, 80, 40, 255));
    Roof.setSize({60, 60});
    Roof.setPosition(475, 188);
    Roof.setRotation(45);

    RoofCut.setFillColor(sf::Color::Black);
    RoofCut.setSize({100, 20});
    RoofCut.setPosition(425, 230);

    TheTextbox.Setup(20, 1000, {20, 20});
    TheTextbox.SetText("I hope this meets the assignment criteria :)");
    TheTextbox.SetTextColor(sf::Color::White);
    // TODO: Set up members
}

void GameLoop::Update() {

    // TODO: Call Update and tick functions

    gameWindow.Update();
}

void GameLoop::Render() {
    gameWindow.BeginDraw();
    gameWindow.GetRenderWindow()->draw(sprite);

    gameWindow.GetRenderWindow()->draw(Hill);
    gameWindow.GetRenderWindow()->draw(Hill1);
    gameWindow.GetRenderWindow()->draw(Hill2);

    gameWindow.GetRenderWindow()->draw(Hill3);
    gameWindow.GetRenderWindow()->draw(Hill4);
    gameWindow.GetRenderWindow()->draw(Hill5);

    gameWindow.GetRenderWindow()->draw(Hill6);
    gameWindow.GetRenderWindow()->draw(Hill7);
    gameWindow.GetRenderWindow()->draw(Hill8);

    gameWindow.GetRenderWindow()->draw(Roof);
    gameWindow.GetRenderWindow()->draw(RoofCut);
    gameWindow.GetRenderWindow()->draw(House);
    gameWindow.GetRenderWindow()->draw(Door);

    TheTextbox.Render(*gameWindow.GetRenderWindow());
    // TODO: Add renderables here... perhaps an array or vector of renderables
    gameWindow.EndDraw();
}