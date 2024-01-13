#pragma once
#include "Player.h"
#include <SFML/Graphics.hpp>
#include "MainGameFunctions.h"
#include <iostream>
#include <string>
#include <vector>
#include<cmath>
#include "TexturedSprite.h"
#define PI 3.141592653589793238



class _BuildingMap: public TexturedSprite
{
private:
    int gap;
    _Player* plr;
    sf::RectangleShape Building;
    std::vector<sf::FloatRect> BuildingBounds;
    bool checkCollision(const sf::FloatRect axisAlignedRectBounds);
public:
    _BuildingMap(_Player *p);
    sf::Vector3i customHash(int input1, int input2);
    void draw(sf::RenderWindow& window);
    void drawDeathScreen(sf::RenderWindow& window);
    bool Collision();
};
