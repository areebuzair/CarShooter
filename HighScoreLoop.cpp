#include <SFML/Graphics.hpp>
#include "MainGameFunctions.h"
#include <iostream>
#include <string>
#include "FileManager.h"
#include <cstring>

int highScoreLoop(sf::RenderWindow& window, int score){

    HighScore hscore;
    if(score <= hscore.Least()){
        std::cout<<score;
        return 0;
    }
    //else{
        //std::cout<<"High";
    //}
    std::cout<<score<<std::endl<<hscore.Least()<<std::endl;
    bool loopIsRunning = true;
    float windowLength = 400;
    setWindowView(window, windowLength);

    std::string Name = "";

    sf::Font font;
    if (!font.loadFromFile("text.otf"))
    {
        std::cout<<"Error";
    }
    sf::Text text;
    // select the font
    text.setFont(font); // font is a sf::Font
    // set the string to display
    text.setString("");
    // set the character size
    text.setCharacterSize(40); // in pixels, not points!
    // set the color
    text.setFillColor(sf::Color::White);
    text.setPosition(windowLength/2, windowLength/2);

    while (loopIsRunning && window.isOpen())
    {
        sf::Event event;
         while(window.pollEvent(event))
        {
            //close the window

            if(event.type==sf::Event::Closed)
            {
                window.close();

            }
            else if(event.type==sf::Event::Resized){
				setWindowView(window, windowLength);
            }
            else if (event.type == sf::Event::KeyPressed){
                int code = event.key.code;
                if(code == sf::Keyboard::Escape){
                    window.close();
                    window.create(sf::VideoMode(800,450),"Dino Surfers", sf::Style::Default);
                    setWindowView(window, windowLength);
                }
                else if(code == sf::Keyboard::F11){
                    window.close();
                    window.create(sf::VideoMode(400,400),"Dino Surfers", sf::Style::Fullscreen);
                    setWindowView(window, windowLength);
                }
                else if(code == sf::Keyboard::Enter){
                    loopIsRunning = false;
                }
                else if(sf::Keyboard::A <= code && code <= sf::Keyboard::Z){
                    if(Name.length()<10) Name.push_back(65+code);
                }
                else if(code == sf::Keyboard::Backspace){
                    if(Name.length()) Name.pop_back();
                }
            }
        }
        window.clear();
        text.setString(Name + "_");
        text.setOrigin(text.getGlobalBounds().width/2, text.getGlobalBounds().height/2);
        window.draw(text);
        if(!loopIsRunning) window.clear();
        window.display();
    }
//    char* char_arr = &Name[0];
//    insertInFile(fileName, char_arr, score);
    hscore.addHigh(Name, score);
    hscore.displayHigh();
    return 1;
}

