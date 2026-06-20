#include <iostream>
#include "Character.h"
#include "Monster.h"
#include "Inventory.h"

void test(const std::string& name, bool result) {
    std::cout << (result ? "[PASS] " : "[FAIL] ") << name << "\n";
}

// 데미지 테스트
void test_takeDamage_shouldDecreaseHp() {
    Slime s;
    s.takeDamage(10);
    int expected = 32;
    int actual = s.getHp();
    if (actual == expected)
        std::cout << "[PASS] 데미지_10_방어력2_HP감소\n";
    else
        std::cout << "[FAIL] 데미지_10_방어력2_HP감소"
                  << " (기대: " << expected << ", 실제: " << actual << ")\n";
}

// 최소 데미지 테스트
void test_takeDamage_minDamage_shouldBeOne() {
    Slime s;
    s.takeDamage(1);
    int expected = 39;
    int actual = s.getHp();
    if (actual == expected)
        std::cout << "[PASS] 최소_1데미지\n";
    else
        std::cout << "[FAIL] 최소_1데미지"
                  << " (기대: " << expected << ", 실제: " << actual << ")\n";
}

// 인벤토리 꽉 찼을 때
void test_inventory_full_shouldReturnFalse() {
    Inventory inv(2);
    inv.addItem(Item("포션", ITEM_HEAL, 30));
    inv.addItem(Item("포션", ITEM_HEAL, 30));
    bool result = inv.addItem(Item("포션", ITEM_HEAL, 30));
    if (!result)
        std::cout << "[PASS] 인벤토리_꽉찼을때_추가불가\n";
    else
        std::cout << "[FAIL] 인벤토리_꽉찼을때_추가불가"
                  << " (기대: false, 실제: true)\n";
}

// 레벨업 테스트
void test_gainExp_shouldLevelUp() {
    Warrior w("테스트");
    w.gainExp(100);
    int expected = 2;
    int actual = w.getLevel();
    if (actual == expected)
        std::cout << "[PASS] 경험치100_레벨업_LV2\n";
    else
        std::cout << "[FAIL] 경험치100_레벨업_LV2"
                  << " (기대: " << expected << ", 실제: " << actual << ")\n";
}

// 최대 체력 초과 방지
void test_setHp_shouldNotExceedMaxHp() {
    Warrior w("테스트");
    w.setHp(9999);
    int expected = w.getMaxHp();
    int actual = w.getHp();
    if (actual == expected)
        std::cout << "[PASS] setHp_maxHp초과_안함\n";
    else
        std::cout << "[FAIL] setHp_maxHp초과_안함"
                  << " (기대: " << expected << ", 실제: " << actual << ")\n";
}

int main() {
    std::cout << "단위 테스트\n";
    test_takeDamage_shouldDecreaseHp();
    test_takeDamage_minDamage_shouldBeOne();
    test_inventory_full_shouldReturnFalse();
    test_gainExp_shouldLevelUp();
    test_setHp_shouldNotExceedMaxHp();
    return 0;
}