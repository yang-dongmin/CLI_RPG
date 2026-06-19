#include "Inventory.h"
#include <iostream>
#include <stdexcept>

Inventory::Inventory(int maxSize) : maxSize(maxSize) {}

Inventory::~Inventory() {}

bool Inventory::addItem(const Item& item) {
    if (isFull()) return false;
    items.push_back(item);
    return true;
}

bool Inventory::useItem(int index, int& hp, int& attack, int& defense) {
    if (index < 0 || index >= (int)items.size())
        throw std::out_of_range("잘못된 아이템 인덱스입니다.");

    Item item = items[index];

    switch (item.getType()) {
        case ITEM_HEAL:
            hp += item.getValue();
            std::cout << item.getName() << " 사용! HP +" << item.getValue() << "\n";
            break;
        case ITEM_ATTACK:
            attack += item.getValue();
            std::cout << item.getName() << " 사용! ATK +" << item.getValue() << "\n";
            break;
        case ITEM_DEFENSE:
            defense += item.getValue();
            std::cout << item.getName() << " 사용! DEF +" << item.getValue() << "\n";
            break;
    }

    removeItem(index);
    return true;
}

void Inventory::removeItem(int index) {
    if (index < 0 || index >= (int)items.size())
        throw std::out_of_range("잘못된 아이템 인덱스입니다.");
    items.erase(items.begin() + index);
}

void Inventory::printInventory(){
    if (isEmpty()) {
        std::cout << "인벤토리가 비어있습니다.\n";
        return;
    }
    std::cout << "=== 인벤토리 [" << items.size() << "/" << maxSize << "] ===\n";
    for (int i = 0; i < (int)items.size(); i++) {
        std::cout << i + 1 << ". ";
        items[i].printInfo();
    }
}

int Inventory::getSize(){ return items.size(); }
bool Inventory::isFull(){ return (int)items.size() >= maxSize; }
bool Inventory::isEmpty(){ return items.empty(); }
Item Inventory::getItem(int index){ return items[index]; }