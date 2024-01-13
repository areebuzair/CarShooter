#pragma once

class HasHealth{
protected:
    int health;
public:
    void setHealth(int val);
    int getHealth();
    void operator--(int);
};
