#include "Health.h"

void HasHealth::operator--(int){
    health--;
}
void HasHealth::setHealth(int val){
    health = val;
}
int HasHealth::getHealth(){
    return health;
}
