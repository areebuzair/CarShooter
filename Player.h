#pragma once

#include <SFML/Graphics.hpp>
#include "MainGameFunctions.h"
#include "TexturedSprite.h"
#include <iostream>
#include <string>
#include <vector>
#include<cmath>
#include "Health.h"
#define PI 3.141592653589793238

class _Player: public TexturedSprite, public HasHealth
{
private:
    int x, y, v, a, score;
    float rotation, rotationAmount;
    sf::RectangleShape Car;
public:
    _Player();
    void draw(sf::RenderWindow& window);
    void move(int val);
    void update();
    void increaseScore();
    int getScore();
    void setRotationAmount(float val);
    sf::Vector2f getPosition();
    float getRotation();
    friend class _BuildingMap;
};
