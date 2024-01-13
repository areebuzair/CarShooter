#include <SFML/Graphics.hpp>
#include "MainGameFunctions.h"
#include "fileManager.h"
#include <iostream>
#include <string>

int highScoreDisplayLoop(sf::RenderWindow& window)
{
    bool loopIsRunning = true;
    float windowLength = 700;
    int choice = 0;
    setWindowView(window, windowLength);
    HighScore hscore;
    //changing background
    /*sf::Texture texture;
    texture.loadFromFile("images/back.png");
    sf::Sprite sprite(texture);*/

    sf::Texture texture;
    texture.loadFromFile("images/BG_blurry.jpg");
    sf::Sprite sprite(texture);

    sf::Font font;
    font.loadFromFile("text.otf");

    // First text
    sf::Text text1;
    text1.setFont(font);
    text1.setString("High score");
    text1.setPosition(140, 90);
    text1.setCharacterSize(55);
    text1.setColor(sf::Color::White);

    // Second text (centered)
    sf::Text text2;
    text2.setFont(font);

    text2.setString(hscore.StringValue());
    std::cout << hscore.StringValue() << std::endl;

    // center the text
    sf::FloatRect text2Bounds = text2.getLocalBounds();
    text2.setPosition((windowLength - text2Bounds.width) / 2.0f, (windowLength - text2Bounds.height) / 2.0f);

    text2.setCharacterSize(35);
    text2.setColor(sf::Color::Black);





    while (window.isOpen() && loopIsRunning)
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type==sf::Event::Closed)
            {
                window.close();
            }
            else if(event.type==sf::Event::Resized)
            {
                setWindowView(window, windowLength);
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                int code = event.key.code;
                resizeEvent(code, window, windowLength);
                if(code == sf::Keyboard::Enter)
                {
                    loopIsRunning = false;
                }
                if(code == sf::Keyboard::Down)
                {
                    //choice++;
                    //if(choice==4) choice = 0;
                }
                if(code == sf::Keyboard::Up)
                {
                    //choice--;
                    //if(choice==-1) choice = 3;
                }

            }

        }
        window.clear(sf::Color::White);
        window.draw(sprite);
        window.draw(text1);
        window.draw(text2);
        window.display();

    }
    return 0;




//having fun

}


