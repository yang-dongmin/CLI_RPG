#include "Entity.h"

Entity::Entity(std::string name, int hp, int atk, int def, int level) : name(name), hp(hp), atk(atk), def(def), level(level) {};

void Entity::showStatus() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "HP: " << hp << std::endl;
    std::cout << "ATK: " << atk << std::endl;
    std::cout << "DEF: " << def << std::endl;
    std::cout << "Level: " << level << std::endl;
}

void Entity::attack(Entity& target) {
    int damage = atk - target.def;
    if (damage < 0) damage = 0;
    target.hp -= damage;
}

bool Entity::isDead() {
    return hp <= 0;
}