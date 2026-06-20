// 몬스터 기반 클래스 + Slime·Goblin·Dragon 등
#pragma once
#include "Entity.h"
#include "Item.h"
#include <string>
#include <vector>

class Monster : public Entity {
protected:
    int expReward;      // 처치 시 경험치
    std::vector<Item> dropTable;  // 드롭 아이템 목록

public:
    Monster(const std::string& name, int hp, int attack, int defense, int expReward);
    virtual ~Monster();

    void attackTarget(Entity& target) override;
    virtual void printStatus() override;
    virtual std::string getMonsterType() const = 0;  // 몬스터 종류 반환 (순수 가상)

    int getExpReward();
    std::vector<Item> drop();  // 드롭 아이템 반환
    void addDrop(const Item& item);
};


class Slime : public Monster {
public:
    Slime();
    void attackTarget(Entity& target) override;  // 기본 공격
    void printStatus() override;
    std::string getMonsterType() const override { return "슬라임"; }
};

class Goblin : public Monster {
public:
    Goblin();
    void attackTarget(Entity& target) override;  // 빠른 연속 공격 (2회)
    void printStatus() override;
    std::string getMonsterType() const override { return "고블린"; }
};

class Orc : public Monster {
public:
    Orc();
    void attackTarget(Entity& target) override;  // 강타 (데미지 1.5배)
    void printStatus() override;
    std::string getMonsterType() const override { return "오크"; }
};

class Dragon : public Monster {
public:
    Dragon();
    void attackTarget(Entity& target) override;  // 화염 (방어력 무시)
    void printStatus() override;
    std::string getMonsterType() const override { return "드래곤"; }
};