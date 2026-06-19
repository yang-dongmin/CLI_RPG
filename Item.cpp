#include "Item.h"
#include <iostream>

Item::Item(const std::string& name, int type, int value)
    : name(name), type(type), value(value) {}

Item::~Item() {}

std::string Item::getName(){ return name; }
int Item::getType(){ return type; }
int Item::getValue(){ return value; }

void Item::printInfo(){
    std::string typeStr;
    switch (type) {
        case 0 : typeStr = "회복";        break;
        case 1 : typeStr = "공격력 증가";  break;
        case 2 : typeStr = "방어력 증가";  break;
        default : typeStr = "알 수 없음";   break;
    }
    std::cout << name << " [" << typeStr << " +" << value << "]\n";
}