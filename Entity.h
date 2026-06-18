#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>

class Entity{
protected:
    std::string name; // 이름
    int hp, atk, def, level; // 체력 공격력 방어력 레벨
public:
    Entity(std::string name, int hp, int atk, int def, int level);

    virtual void showStatus(); // 상태 출력
    virtual void attack(Entity& target); // 공격, 매개변수로 타겟 지정

    bool isDead(); // 사망 여부 반환

    virtual void getType() = 0; // 순수 가상 함수
};

#endif