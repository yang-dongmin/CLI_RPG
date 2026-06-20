// 플레이어 클래스 + 전사 마법사 도적 팔라딘
#pragma once
#include "Entity.h"
#include "Inventory.h"
#include <string>

class Character : public Entity {
protected:
    int level;
    int exp;
    Inventory inventory;

public:
    Character(const std::string& name, int hp, int attack, int defense);
    virtual ~Character();

    void attackTarget(Entity& target) override;
    virtual void printStatus() override;
    virtual std::string getJobName() = 0;  // 직업 이름 반환 (순수 가상)

    void gainExp(int amount);
    void levelUp();

    int getLevel();
    int getExp();
    Inventory& getInventory();

    void setHp(int hp);
    void setAttack(int atk);
    void setDefense(int def);
    void setLevel(int lv);
    void setExp(int exp);
    void setMaxHp(int maxHp);
};


class Warrior : public Character { // 전사
public:
    Warrior(const std::string& name);
    void attackTarget(Entity& target) override;  // 강타 (데미지 1.5배)
    void printStatus() override;
    std::string getJobName() override { return "전사"; }
};

class Mage : public Character { // 마법사
public:
    Mage(const std::string& name);
    void attackTarget(Entity& target) override;  // 마법 (방어력 무시)
    void printStatus() override;
    std::string getJobName() override { return "마법사"; }
};

class Rogue : public Character { // 도적
public:
    Rogue(const std::string& name);
    void attackTarget(Entity& target) override;  // 급소 (확률적 2배)
    void printStatus() override;
    std::string getJobName() override { return "도적"; }
};

class Paladin : public Character { // 팔라딘
public:
    Paladin(const std::string& name);
    void attackTarget(Entity& target) override;  // 방어+공격 균형
    void printStatus() override;
    std::string getJobName() override { return "팔라딘"; }
};