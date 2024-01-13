#include <SFML/Graphics.hpp>
#include "MainGameFunctions.h"
#include <iostream>
#include <string>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Bike Shooter");
    int menuChoice, score = 0;

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




