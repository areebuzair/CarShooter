#include "BuildingMap.h"
int windowLength = 1000;

_BuildingMap::_BuildingMap(_Player *p):plr(p)
{
    gap = windowLength/2;
    Building.setSize(sf::Vector2f(1.f, 1.f));
    Building.setOrigin(.5f, .5f);
    Building.setTexture(&texture);
}

bool _BuildingMap::checkCollision(const sf::FloatRect axisAlignedRectBounds)
{
    sf::Transform transform = (plr->Car).getTransform();
    sf::FloatRect rotatedRectBounds = transform.transformRect((plr->Car).getLocalBounds());
    //sf::FloatRect axisAlignedRectBounds = axisAlignedRect.getGlobalBounds();

    return rotatedRectBounds.intersects(axisAlignedRectBounds);
}


sf::Vector3i _BuildingMap::customHash(int input1, int input2)
{
    sf::Vector3i val;
    // Use basic arithmetic operations and bitwise shifts for mixing
    int hashValue1 = ((input1 * 17 + input2 * 31) ^ (input1 << 13))/100;
    int hashValue2 = ((input1 + input2 * 19) ^ (input2 << 17))/100;
    int hashValue3 = ((input1 * 23 + input2 * 37) ^ (input1 + input2 << 19))/100;

    // Ensure non-zero outputs
    hashValue1 = hashValue1 == 0 ? 1 : hashValue1;
    hashValue2 = hashValue2 == 0 ? 2 : hashValue2;
    hashValue3 = hashValue3 == 0 ? 3 : hashValue3;

    // Apply modular arithmetic to limit the range of outputs
    val.x = gap/2 + (abs(hashValue1) % (gap/2));
    val.y = gap/2 + (abs(hashValue2) % (gap/2));
    val.z = abs(hashValue3) % 12;

    return val;
}

void _BuildingMap::draw(sf::RenderWindow& window)
{
    int x = floor(plr->getPosition().x / gap) * gap;
    int y = floor(plr->getPosition().y / gap) * gap;
    for(int i = x - 2*gap; i <= x + 2*gap; i+=gap)
    {
        if(i%7==0 || i%13==0) continue;
        for(int j =y - 2*gap; j <= y + 2*gap; j+=gap)
        {
            if(j%17==0 || j%11==0) continue;
            sf::Vector3i val = customHash(i, j);
            Building.setPosition(i, j);
            //Building.setFillColor(sf::Color(val.z/2, val.z/2, val.z));
            Building.setScale(val.x, val.y);
            Building.setTextureRect(sf::IntRect(512 * (val.z%4), 512 * (val.z/4), 512, 512));
            //std::cout << val.z << std::endl;
            window.draw(Building);
            BuildingBounds.push_back(Building.getGlobalBounds());

            //count++;
        }
        //std::cout << count << std::endl;
    }
}
void _BuildingMap::drawDeathScreen(sf::RenderWindow& window){
    sf::RectangleShape screen;
    screen.setSize(sf::Vector2f(window.getSize().x * 2, window.getSize().y  * 2));
    screen.setOrigin(sf::Vector2f(window.getSize().x, window.getSize().y));
    screen.setFillColor(sf::Color(0, 0, 0, 25));
    screen.setPosition(plr->getPosition());
    window.draw(screen);
}
bool _BuildingMap::Collision()
{
    for(int i=0; i<BuildingBounds.size(); i++)
    {
        if(checkCollision(BuildingBounds[i]))
        {
            return true;
        }
    }
    return false;
}
