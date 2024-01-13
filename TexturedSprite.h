#pragma once
#include <SFML/Graphics.hpp>
//#define windowLength 1000

class TexturedSprite{
protected:
    int windowLength;
public:
    static sf::Texture texture;
    TexturedSprite();
    void draw(sf::RenderWindow& window);
    int getWindowLength();
};
