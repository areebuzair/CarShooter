#include <SFML/Graphics.hpp>
#include "MainGameFunctions.h"
#include <iostream>
#include <string>

int highScoreDisplayLoop(sf::RenderWindow& window, sf::Sprite &sprite, sf::Font &font);

int mainMenuLoop(sf::RenderWindow& window){
    bool loopIsRunning = true, showInstructions = false;;
    float windowLength = 1024;
    int choice = 0;
    setWindowView(window, windowLength);
    //changing background
    sf::Texture texture;
    texture.loadFromFile("images/back.jpg");
    sf::Sprite sprite(texture);

    sf::Texture insTexture;
    insTexture.loadFromFile("images/Instructions.jpg");
    sf::Sprite instructions(insTexture);


    //drawing the semi-transparent rectangles
    sf::RectangleShape rectangle(sf::Vector2f(500,150));
    rectangle.setFillColor(sf::Color(0,0,0,90));
    rectangle.setPosition(260,90);
    rectangle.setOrigin(rectangle.getSize().x/2,rectangle.getSize().y/2);


    //lets make the text
  //1ST TEXT
     sf::Font font;
     font.loadFromFile("text.otf");

    sf::Text text1;
    text1.setFont(font);
    text1.setString("PLAY");
    text1.setPosition(140,45);
    text1.setCharacterSize(69);

    text1.setColor(sf::Color::White);


    //high score part (2nd text)
     sf::Text text2;
    text2.setFont(font);
    text2.setString("HIGH SCORE");
    text2.setPosition(25,225);
    text2.setCharacterSize(59);
    text2.setColor(sf::Color::White);


    //instructions part 3rd text
     sf::Text text3;
    text3.setFont(font);
    text3.setString("INSTRUCTIONS");
    text3.setPosition(30,420);
    text3.setCharacterSize(50);
    text3.setColor(sf::Color::White);

    //quit since its a full screen game

     sf::Text text4;
    text4.setFont(font);
    text4.setString("QUIT");
    text4.setPosition(140,595);
    text4.setCharacterSize(69);
    text4.setColor(sf::Color::White);




    while (window.isOpen() && loopIsRunning)
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type==sf::Event::Closed)
            {
                window.close();
            }
            else if(event.type==sf::Event::Resized){
				setWindowView(window, windowLength);
            }
            else if (event.type == sf::Event::KeyPressed){
                int code = event.key.code;
                if(code == sf::Keyboard::Enter){
                    if(showInstructions){
                        showInstructions = false;
                    }
                    else{
                        switch(choice){
                        case 0:
                            loopIsRunning = false;
                            break;
                        case 1:
                            loopIsRunning = false;
                            break;
                        case 2:
                            showInstructions = true;
                            break;
                        case 3:
                            window.close();
                        }
                    }
                }
                resizeEvent(code, window, windowLength);
                if(code == sf::Keyboard::Down){
                    choice++;
                    if(choice==4) choice = 0;
                }
                if(code == sf::Keyboard::Up){
                    choice--;
                    if(choice==-1) choice = 3;
                }

            }

        }
        window.clear(sf::Color::Black);
        window.draw(sprite);
        rectangle.setPosition(265,90); //here copying the same rectangle 4 times 4 four options
        rectangle.setFillColor((choice==0)?(sf::Color(0, 0, 0)):(sf::Color(0,0,0,90)));
        window.draw(rectangle);
        rectangle.setPosition(265,270);
        rectangle.setFillColor((choice==1)?(sf::Color(10, 0, 0)):(sf::Color(0,0,0,90)));
        window.draw(rectangle);
        rectangle.setPosition(265,450);
        rectangle.setFillColor((choice==2)?(sf::Color(0, 0, 0)):(sf::Color(0,0,0,90)));
        window.draw(rectangle);
        rectangle.setPosition(265,630);
        rectangle.setFillColor((choice==3)?(sf::Color(0, 0, 0)):(sf::Color(0,0,0,90)));
        window.draw(rectangle);
        window.draw(text1);
        window.draw(text2);
        window.draw(text3);
        window.draw(text4);

        if(showInstructions) window.draw(instructions);

        window.display();

    }
    return choice;




//having fun

}
