#include <SFML/Graphics.hpp>
#include "MainGameFunctions.h"
#include "Player.h"
#include "BuildingMap.h"
#include "Enemies.h"
#include <string>
#include <vector>
#include "Gun.h"
int gameLoop(sf::RenderWindow& window)
{
    _Player Player;
    _BuildingMap BuildingMap(&Player);
    EnemyManager enm(&Player);
    enm.spawn(window);
    int windowLength = 1000;
    bool loopIsRunning = true, gameOver = false, mouseFlag = true;
    sf::View view(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));
    sf::Cursor cursor;
    if (cursor.loadFromSystem(sf::Cursor::Cross))
        window.setMouseCursor(cursor);
    Gun gun;
//    sf::CircleShape flash;
//    flash.setRadius(Player.getWindowLength()/25);
//    flash.setOrigin(Player.getWindowLength()/25, Player.getWindowLength()/25);
//    flash.setFillColor(sf::Color::Yellow);
//    flash.setScale(0.f, 0.f);
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
            else if(event.type==sf::Event::Resized)
            {
                view.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                int code = event.key.code;
                resizeEvent(code, window, windowLength);
                if(code == sf::Keyboard::Enter && gameOver)
                {
                    loopIsRunning = false;
                }
                else if(!gameOver)
                {
                    if(code == sf::Keyboard::A)
                    {
                        Player.setRotationAmount(-1);
                    }
                    if(code == sf::Keyboard::D)
                    {
                        Player.setRotationAmount(1);
                    }
                    if(code == sf::Keyboard::S)
                    {
                        Player.move(windowLength/1000);
                    }
                    if(code == sf::Keyboard::W)
                    {
                        Player.move(-windowLength/1000);
                    }
                }
            }
            else if (event.type == sf::Event::KeyReleased)
            {
                int code = event.key.code;
                if(code == sf::Keyboard::W || code == sf::Keyboard::S )
                {
                    Player.move(0);

                }
                if(code == sf::Keyboard::A || code == sf::Keyboard::D )
                {
                    Player.setRotationAmount(0);

                }
            }
        }


        view.setCenter(Player.getPosition());
        view.setRotation(Player.getRotation());
        window.setView(view);
        gun.fire(window, &enm, &view);
//        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !mouseFlag)
//        {
//
//            // get the current mouse position in the window
//            sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
//
//            // convert it to world coordinates
//            enm.setBulletPos(window.mapPixelToCoords(pixelPos));
//            enm.setBullet(true);
////            mouseFlag = true;
////            flash.setScale(1.f, 1.f);
////            flash.setPosition(enm.getBulletPos());
//        }
//        else if(!sf::Mouse::isButtonPressed(sf::Mouse::Left))
//        {
//            mouseFlag = false;
//        }




        if(!gameOver)
        {
            int color = (Player.getHealth()<0?0:Player.getHealth());
            window.clear(sf::Color(color, color, color));
            //BuildingMap.update(Player);

            Player.draw(window);

            BuildingMap.draw(window);

            gameOver = BuildingMap.Collision();

            enm.draw(window, &Player);
            Player.update();
            if(Player.getHealth() <= 0) gameOver = true;
//            window.draw(flash);
//            flash.setScale(0.f, 0.f);
            gun.draw(window);
        }
        else
        {
            Player.setRotationAmount(0);
            Player.move(0);
            BuildingMap.drawDeathScreen(window);
            Player.draw(window);
        }
        //std::cout << gameView.getCenter().x << " " << gameView.getCenter().y << std::endl;
        //BuildingMap.draw(window, Player);
        window.display();
    }
    return Player.getScore();

}

