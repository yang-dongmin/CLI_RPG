// 추상 클래스 (HP·ATK·DEF, 순수 가상 함수)
#pragma once // #ifndef, #define와 달리 한줄로 같은 기능을 간단하게 구현 가능, GCC·Clang·MSVC 전부 지원
#include <string>

class Entity{
protected:
    std::string name; // 이름
    int hp; // 체력
    int maxHp; // 최대체력
    int attack; // 공격력
    int defense; // 방어력
public:
    Entity(const std::string& name, int hp, int attack, int defense);
    virtual ~Entity() = default; // default는 구현부에서 생략 가능

    // 순수 가상 함수, 파생 클래스에서 구현
    virtual void attackTarget(Entity& target) = 0;
    virtual void printStatus() = 0;

    // 공통 기능
    void takeDamage(int damage);
    bool isAlive();

    std::string getName();
    int getHp();
    int getMaxHp();
    int getAttack();
    int getDefense();
};