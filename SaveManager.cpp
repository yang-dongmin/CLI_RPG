#include "SaveManager.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

SaveManager::SaveManager(const std::string& filePath) : filePath(filePath) {}

SaveManager::~SaveManager() {}

void SaveManager::save(Character& character) {
    std::ofstream file(filePath);
    if (!file.is_open())
        throw std::runtime_error("세이브 파일을 열 수 없습니다.");

    file << character.getName()    << "\n";
    file << character.getJobName() << "\n";
    file << character.getHp()      << "\n";
    file << character.getMaxHp()   << "\n";
    file << character.getAttack()  << "\n";
    file << character.getDefense() << "\n";
    file << character.getLevel()   << "\n";
    file << character.getExp()     << "\n";

    // 인벤토리 저장
    Inventory& inv = const_cast<Character&>(character).getInventory();
    file << inv.getSize() << "\n";
    for (int i = 0; i < inv.getSize(); i++) {
        Item item = inv.getItem(i);
        file << item.getName()  << "\n";
        file << item.getType()  << "\n";
        file << item.getValue() << "\n";
    }

    std::cout << "저장 완료!\n";
}

Character* SaveManager::load() {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cout << "세이브 파일이 없습니다.\n";
        return nullptr;
    }

    std::string name, jobName;
    int hp, maxHp, attack, defense, level, exp;

    std::getline(file, name);
    std::getline(file, jobName);
    file >> hp >> maxHp >> attack >> defense >> level >> exp;

    // 직업명으로 파생 클래스 생성
    Character* character = nullptr;
    if      (jobName == "전사")   character = new Warrior(name);
    else if (jobName == "마법사") character = new Mage(name);
    else if (jobName == "도적")   character = new Rogue(name);
    else if (jobName == "팔라딘") character = new Paladin(name);
    else throw std::runtime_error("알 수 없는 직업입니다.");

    // 인벤토리 로드
    int invSize;
    file >> invSize;
    file.ignore();  // 개행 무시

    for (int i = 0; i < invSize; i++) {
        std::string itemName;
        int itemType, itemValue;
        std::getline(file, itemName);
        file >> itemType >> itemValue;
        file.ignore();
        character->getInventory().addItem(Item(itemName, itemType, itemValue));
    }

    std::cout << "불러오기 완료! 어서오세요, " << name << "님!\n";
    return character;
}