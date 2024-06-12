#include <SFML/Graphics.hpp>
#include "MainGameFunctions.h"
#include <iostream>
#include <string>

sf::View setWindowView(sf::RenderWindow& window, float length)
{
    sf::View gameView(sf::FloatRect(0.f, 0.f, length, length));
    float w = window.getSize().x;
    float h = window.getSize().y;
    if(w<=h)
    {
        gameView.setViewport(sf::FloatRect(0.f, (h-w)/(2*h), 1.f, w/h));
    }
    else
    {s
        gameView.setViewport(sf::FloatRect((w-h)/(2*w), 0.f, h/w, 1.f));
    }
    window.setView(gameView);
    window.setVerticalSyncEnabled(true);
    auto icon = sf::Image{};

    if (!icon.loadFromFile("icon.png"))

    {

        std::cout << "Failure" << std::endl;

    }

    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    //window.setMouseCursorVisible(false);
//    std::cout << gameView.getCenter().x << " " << gameView.getCenter().y << std::endl;
    return gameView;
}

void resizeEvent(int code, sf::RenderWindow& window, int windowLength)
{
//    if(code == sf::Keyboard::Escape)
//    {
//        window.close();
//        window.create(sf::VideoMode(800,450),"Car Shooter", sf::Style::Default);
//        setWindowView(window, windowLength);
//    }
//    if(code == sf::Keyboard::F11)
//    {
//        window.close();
//        window.create(sf::VideoMode(400,400),"Car Shooter", sf::Style::Fullscreen);
//        setWindowView(window, windowLength);
//    }
}

