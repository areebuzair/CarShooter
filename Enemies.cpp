#include "Enemies.h"


EnemyManager::EnemyManager(_Player *p)
{
    plr = p;
    srand(time(NULL));
}
void EnemyManager::spawn(sf::RenderWindow& window)
{
    int w = window.getSize().x;
    int h = window.getSize().y;
    float r = sqrt(w*w + h*h);
    for(int i=0; i<10; i++)
    {
        int rp = (1+rand()%7) * r;
        float ang = ((int)rand() % 360) * PI / 180;
        if(i<6)
            enemies.push_back(new HunterDrone(plr->getPosition().x + rp * cos(ang), plr->getPosition().y + rp * sin(ang)));
        else if(i<9)
            enemies.push_back(new GhostDrone(plr->getPosition().x + rp * cos(ang), plr->getPosition().y + rp * sin(ang)));
        else
            enemies.push_back(new HeavyDrone(plr->getPosition().x + rp * cos(ang), plr->getPosition().y + rp * sin(ang)));
    }

}
void EnemyManager::draw(sf::RenderWindow& window, _Player *plr)
{
    for(int i=0; i<enemies.size(); i++)
    {
        enemies[i]->draw(window);
        enemies[i]->follow(window, plr);
        if(bullet) enemies[i]->shotAt(bulletPos, window, plr);
    }
    setBullet(false);
}
EnemyManager::~EnemyManager()
{
    for(int i=0; i<enemies.size(); i++)
    {
        delete enemies[i];
    }
}
void EnemyManager::setBulletPos(sf::Vector2f pos){
    bulletPos = pos;
}
sf::Vector2f EnemyManager::getBulletPos(){
    return bulletPos;
}
void EnemyManager::setBullet(bool b){
    bullet = b;
}
//////////////

double Enemy::findAngle(int x1, int y1, int x2, int y2)
{
    if(y1 == y2 && x1 == x2) return 0;
    // Calculate the angle using atan2
    double angle = atan2(y2 - y1, x2 - x1);

    return angle;
}

void Enemy::setPosition(int _x, int _y)
{
    x = _x;
    y = _y;
    sprite.setPosition(x, y);
}
Enemy::Enemy(int _x, int _y)
{
    x = _x;
    y = _y;
    sprite.setPosition(x, y);
    sprite.setTexture(&texture);
}
void Enemy::setRadius(int val)
{
    radius = val;
    sprite.setSize(sf::Vector2f(radius, radius));
    sprite.setOrigin(radius/2, radius/2);
}
void Enemy::setVel(int val)
{
    v = val;
}
void Enemy::shotAt(sf::Vector2f pos, sf::RenderWindow& window, _Player *plr){
    int D = sqrt( pow(x - pos.x, 2)  + (pow(y - pos.y, 2) ) );
    if(D <= radius + windowLength/25){
        health--;
        plr->increaseScore();
    }
    if(health <= 0) reset(window, plr);
}
void Enemy::follow(sf::RenderWindow& window, _Player *p)
{
    //std::cout << rand() << std::endl;
    float ang = (-5 + rand()%11)/5 + findAngle(x, y, p->getPosition().x, p->getPosition().y);
    x += cos(ang)*v;
    y += sin(ang)*v;
    setPosition(x, y);
    int D = sqrt( pow(x - p->getPosition().x, 2)  + (pow(y - p->getPosition().y, 2) ) );
    if( D < radius/2)
    {
        (*p)--;
        //std::cout << p->getHealth() << std::endl;
    }
    else if( D > windowLength * 5)
    {
        reset(window, p);
    }
}
void Enemy::reset(sf::RenderWindow& window, _Player *plr)
{
    //std::cout << rand() << std::endl;
    int w = window.getSize().x;
    int h = window.getSize().y;
    float r = (1 + rand()%2) * sqrt(w*w + h*h);
    float ang = ((int)rand() % 360) * PI / 180;
    setPosition(plr->getPosition().x + r * cos(ang), plr->getPosition().y + r * sin(ang));

}
void Enemy::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}
//void Enemy::draw(sf::RenderWindow& window) = 0;

//////////////////

HunterDrone::HunterDrone(int _x, int _y): Enemy(_x, _y)
{
    health = 3;
    setRadius(windowLength/12);
    sprite.setTextureRect(sf::IntRect(512 * 1, 512 * 3, 512, 512));
    setVel(windowLength / 200);
}
void HunterDrone::reset(sf::RenderWindow& window, _Player *plr){
    Enemy::reset(window, plr);
    health = 3;
}
HeavyDrone::HeavyDrone(int _x, int _y): Enemy(_x, _y)
{
    health = 10;
    setRadius(windowLength/6);
    sprite.setTextureRect(sf::IntRect(512 * 2, 512 * 3, 512, 512));
    setVel(windowLength / 400);
}
void HeavyDrone::reset(sf::RenderWindow& window, _Player *plr){
    Enemy::reset(window, plr);
    health = 10;
}
GhostDrone::GhostDrone(int _x, int _y): Enemy(_x, _y)
{
    health = 1;
    setRadius(windowLength/24);
    sprite.setTextureRect(sf::IntRect(512 * 0, 512 * 3, 512, 512));
    setVel(windowLength / 150);
}
void GhostDrone::reset(sf::RenderWindow& window, _Player *plr){
    Enemy::reset(window, plr);
    health = 1;
}
