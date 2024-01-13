#include "TexturedSprite.h"
#include <iostream>

sf::Texture TexturedSprite::texture;

TexturedSprite::TexturedSprite()
{
    windowLength = 1000;
    if(!texture.loadFromFile("images/MainGameSprite2.png"))
    {
        std::cout << "img not found";
    }

}
int TexturedSprite::getWindowLength()
{
    return windowLength;
}
