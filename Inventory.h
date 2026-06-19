// 아이템 목록 관리 (추가·사용·조회)
#pragma once
#include "Item.h"
#include <vector>
#include <string>

class Inventory {
private:
    std::vector<Item> items;
    int maxSize;

public:
    Inventory(int maxSize = 10);
    ~Inventory();

    bool addItem(const Item& item);     // 아이템 추가 (꽉 차면 false)
    bool useItem(int index, int& hp, int& attack, int& defense);  // 아이템 사용
    void removeItem(int index);         // 아이템 제거
    void printInventory();        // 인벤토리 출력

    int getSize();
    bool isFull();
    bool isEmpty();
    Item getItem(int index);
};