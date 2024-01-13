#pragma once
#include "TexturedSprite.h"
#include "Player.h"
#include <vector>
#include <cmath>
#include "Health.h"
#define PI 3.141592653589793238

class Enemy: public TexturedSprite, public HasHealth
{
private:
    double findAngle(int x1, int y1, int x2, int y2);
protected:
    int radius;
    int x, y, v;
    sf::RectangleShape sprite;
    void setRadius(int val);
    void setVel(int val);
public:
    Enemy(int _x, int _y);
    void setPosition(int x, int y);
    void draw(sf::RenderWindow& window);
    void follow(sf::RenderWindow& window, _Player *p);
    virtual void reset(sf::RenderWindow& window, _Player *p);
    void shotAt(sf::Vector2f pos, sf::RenderWindow& window, _Player *p);
};

class HunterDrone: public Enemy
{
public:
    HunterDrone(int _x, int _y);
    void reset(sf::RenderWindow& window, _Player *p);
    //void draw(sf::RenderWindow& window);
};
class GhostDrone: public Enemy
{
public:
    GhostDrone(int _x, int _y);
    void reset(sf::RenderWindow& window, _Player *p);
    //void draw(sf::RenderWindow& window);
};
class HeavyDrone: public Enemy
{
public:
    HeavyDrone(int _x, int _y);
    void reset(sf::RenderWindow& window, _Player *p);
    //void draw(sf::RenderWindow& window);
};

class EnemyManager
{
private:
    _Player *plr;
    sf::Vector2f bulletPos;
    bool bullet;
public:
    std::vector<Enemy*> enemies;
    EnemyManager(_Player *p);
    ~EnemyManager();
    void spawn(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window, _Player *plr);
    void setBulletPos(sf::Vector2f pos);
    sf::Vector2f getBulletPos();
    void setBullet(bool b);
};
