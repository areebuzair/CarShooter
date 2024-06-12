#include <SFML/Graphics.hpp>
#include "MainGameFunctions.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <winver.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Bike Shooter", sf::Style::Titlebar | sf::Style::Close);
    int menuChoice, score = 0;

    auto icon = sf::Image{};

    if (!icon.loadFromFile("icon.png"))

    {

        std::cout << "Failure" << std::endl;

    }

    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    while(window.isOpen()){
        while((menuChoice = mainMenuLoop(window)) && menuChoice==1){
            highScoreDisplayLoop(window);
        }
        score = gameLoop(window);
        window.clear();
        window.display();
        highScoreLoop(window, score);
    }

    window.clear();
    window.close();
    return 0;
}




