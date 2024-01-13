#include "Player.h"
extern int windowLength;

_Player::_Player()
{
    x = 0;
    y = 0;
    v = 0;
    a = 0;
    rotation = 0;
    score = 0;
    rotationAmount = 0;
    setHealth(100);
    Car.setSize(sf::Vector2f(windowLength/40, windowLength/20));
    Car.setOrigin(Car.getSize().x/2, Car.getSize().y/2);
    //Car.setFillColor(sf::Color::Red);
    Car.setPosition(x, y);
    Car.setTexture(&texture);
    Car.setTextureRect(sf::IntRect(512 * 3, 512 * 3, 256, 512));
}
void _Player::draw(sf::RenderWindow& window)
{
    Car.setPosition(x, y);
    window.draw(Car);
    //std::cout << x << std::endl;
}
void _Player::move(int val)
{
    a = val;
}
void _Player::update()
{
    if(a!=0 && abs(v) < windowLength/50) v += a;
    else if(a==0 && v != 0)
    {
        v = v/1.05;
        //std::cout << v << std::endl;
    }
    y += cos(rotation * PI/180) * v;
    x -= sin(rotation * PI/180) * v;

    if(rotationAmount != 0 && a!=0)
    {
        rotation += rotationAmount;
        Car.rotate(rotationAmount);
        if(rotation > 360) rotation -= 360;
        else if(rotation < 0) rotation += 360;
    }
}

void _Player::setRotationAmount(float val)
{
    rotationAmount = val * 3;
}
sf::Vector2f _Player::getPosition()
{
    return Car.getPosition();
}
float _Player::getRotation()
{
    return Car.getRotation();
}
void _Player::increaseScore()
{
    score++;
}
int _Player::getScore()
{
    return score;
}
