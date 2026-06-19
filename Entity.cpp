#include "Entity.h"
#include <iostream>

Entity::Entity(const std::string& name, int hp, int attack, int defense)
    : name(name), hp(hp), maxHp(hp), attack(attack), defense(defense) {}

void Entity::takeDamage(int damage)
{
    int actual = damage - defense;
    if (actual < 1)
        actual = 1; // 최소 1 데미지
    hp -= actual;
    if (hp < 0)
        hp = 0;
}

bool Entity::isAlive()
{
    return hp > 0;
}

std::string Entity::getName(){ return name; }
int Entity::getHp(){ return hp; }
int Entity::getMaxHp(){ return maxHp; }
int Entity::getAttack(){ return attack; }
int Entity::getDefense(){ return defense; }