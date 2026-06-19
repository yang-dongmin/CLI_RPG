// 아이템 클래스 (이름·타입·효과값)
#pragma once
#include <string>

const int ITEM_HEAL = 0;
const int ITEM_ATTACK = 1;
const int ITEM_DEFENSE = 2;

class Item {
private:
    std::string name;
    int type;
    int value;  // 회복량, 증가량

public:
    Item(const std::string& name, int type, int value);
    ~Item();

    std::string getName();
    int getType();
    int getValue();

    void printInfo();
};