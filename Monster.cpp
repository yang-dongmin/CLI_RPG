#include "Monster.h"
#include <iostream>

// ===== Monster =====
Monster::Monster(const std::string& name, int hp, int attack, int defense, int expReward)
    : Entity(name, hp, attack, defense), expReward(expReward) {}

Monster::~Monster() {}

void Monster::attackTarget(Entity& target) {
    target.takeDamage(attack);
}

void Monster::printStatus() {
    std::cout << "[" << getMonsterType() << "] " << name
              << " | HP: " << hp << "/" << maxHp
              << " | ATK: " << attack
              << " | DEF: " << defense << "\n";
}

int Monster::getExpReward() { return expReward; }

void Monster::addDrop(const Item& item) {
    dropTable.push_back(item);
}

std::vector<Item> Monster::drop() {
    std::vector<Item> dropped;
    for (const Item& item : dropTable) {
        if (rand() % 100 < 50)  // 50% 확률로 드롭
            dropped.push_back(item);
    }
    return dropped;
}

// ===== Slime =====
Slime::Slime()
    : Monster("슬라임", 40, 8, 2, 20) {}

void Slime::attackTarget(Entity& target) {
    target.takeDamage(attack);
}

void Slime::printStatus() { Monster::printStatus(); }

// ===== Goblin =====
Goblin::Goblin()
    : Monster("고블린", 60, 12, 5, 40) {}

void Goblin::attackTarget(Entity& target) {
    target.takeDamage(attack);  // 1회
    target.takeDamage(attack);  // 2회 연속
}

void Goblin::printStatus() { Monster::printStatus(); }

// ===== Orc =====
Orc::Orc()
    : Monster("오크", 100, 18, 10, 70) {}

void Orc::attackTarget(Entity& target) {
    target.takeDamage(attack * 1.5);  // 강타
}

void Orc::printStatus() { Monster::printStatus(); }

// ===== Dragon =====
Dragon::Dragon()
    : Monster("드래곤", 200, 30, 20, 150) {}

void Dragon::attackTarget(Entity& target) {
    target.takeDamage(attack + 20);  // 화염 (방어력 무시 효과)
}

void Dragon::printStatus() { Monster::printStatus(); }