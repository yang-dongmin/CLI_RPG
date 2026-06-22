#include "Character.h"
#include <iostream>

Character::Character(const std::string& name, int hp, int attack, int defense)
    : Entity(name, hp, attack, defense), level(1), exp(0) {}

Character::~Character() {}

void Character::attackTarget(Entity& target) {
    target.takeDamage(attack);
}

void Character::printStatus() {
    std::cout << "\n[" << getJobName() << "] " << name
              << " | HP: " << hp << "/" << maxHp
              << " | ATK: " << attack
              << " | DEF: " << defense
              << " | LV: " << level << "\n";
}

void Character::gainExp(int amount) {
    exp += amount;
    if (exp >= level * 100) levelUp();
}

void Character::levelUp() {
    level++;
    exp = 0;
    maxHp += 10;
    hp = maxHp;
    attack += 3;
    defense += 2;
    std::cout << name << " 레벨 업! → LV." << level << "\n";
}

int Character::getLevel() { return level; }
int Character::getExp() { return exp; }
Inventory& Character::getInventory() { return inventory; }

void Character::setHp(int h)      { hp = (h > maxHp) ? maxHp : h; }
void Character::setAttack(int a)  { attack = a; }
void Character::setDefense(int d) { defense = d; }
void Character::setLevel(int lv)    { level = lv; }
void Character::setExp(int e)       { exp = e; }
void Character::setMaxHp(int m)     { maxHp = m; }

Warrior::Warrior(const std::string& name) // 전사
    : Character(name, 150, 20, 15) {}

void Warrior::attackTarget(Entity& target) {
    target.takeDamage(static_cast<int>(attack * 1.5));  // 강타
}

void Warrior::printStatus() {
    Character::printStatus();
}

Mage::Mage(const std::string& name) // 마법사
    : Character(name, 90, 30, 5) {}

void Mage::attackTarget(Entity& target) {
    target.takeDamage(attack + 10);  // 마법 공격 (방어력 무시)
}

void Mage::printStatus() {
    Character::printStatus();
}

Rogue::Rogue(const std::string& name) // 도적
    : Character(name, 100, 25, 8) {}

void Rogue::attackTarget(Entity& target) {
    int dmg = (rand() % 100 < 30) ? attack * 2 : attack;  // 30% 확률 급소
    target.takeDamage(dmg);
}

void Rogue::printStatus() {
    Character::printStatus();
}

Paladin::Paladin(const std::string& name) // 팔라딘
    : Character(name, 120, 18, 20) {}

void Paladin::attackTarget(Entity& target) {
    target.takeDamage(attack);
}

void Paladin::printStatus() {
    Character::printStatus();
}