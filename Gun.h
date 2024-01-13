#include "TexturedSprite.h"
#include "Enemies.h"
#include <SFML/Graphics.hpp>

class Gun: public TexturedSprite
{
private:
    //sf::Vector2f pos;
    sf::RectangleShape flash;
    bool mouseFlag;
    int radius;
public:
    Gun()
    {
        mouseFlag = false;
        radius = getWindowLength()/25;
        flash.setSize(sf::Vector2f(2*radius, 2*radius));
        flash.setOrigin(sf::Vector2f(radius, radius));
        flash.setScale(0.f, 0.f);
        flash.setTexture(&texture);
        flash.setTextureRect(sf::IntRect(512*3.5, 512*3, 256, 256));
    }
    void fire(sf::RenderWindow& window, EnemyManager *enm, sf::View *view)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !mouseFlag)
        {

            // get the current mouse position in the window
            sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

            // convert it to world coordinates
            enm->setBulletPos(window.mapPixelToCoords(pixelPos, *view));
            enm->setBullet(true);
            mouseFlag = true;
            flash.setScale(1.f, 1.f);
            flash.setPosition(enm->getBulletPos());
        }
        else if(!sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            mouseFlag = false;
        }
    }
    void draw(sf::RenderWindow& window)
    {
        window.draw(flash);
        flash.setScale(0.f, 0.f);
    }

};
