#include "BattleSystem.h"
#include <iostream>
#include <stdexcept>

BattleSystem::BattleSystem(Character* player, Monster* monster)
    : player(player), monster(monster) {}

BattleSystem::~BattleSystem() {}

void BattleSystem::printBattleStatus(){
    std::cout << "===========[Turn " << turn++ << "]===========\n";
    player->printStatus();
    monster->printStatus();
    std::cout << "\n==============================\n";
}

bool BattleSystem::playerTurn() {
    std::cout << "\n행동을 선택하세요\n";
    std::cout << "1. 공격\n";
    std::cout << "2. 아이템 사용\n";
    std::cout << "3. 도망\n";

    int choice;
    std::cin >> choice;

    if (choice < 1 || choice > 3)
        throw std::invalid_argument("잘못된 입력입니다.");

    switch (choice) {
        case 1:
            player->attackTarget(*monster);
            std::cout << player->getName() << " 의 공격! "
                      << monster->getName() << " 에게 데미지!\n";
            break;
        case 2: {
            player->getInventory().printInventory();
            if (player->getInventory().isEmpty()) break;

            std::cout << "사용할 아이템 번호: ";
            int idx;
            std::cin >> idx;

            int hp     = player->getHp();
            int atk    = player->getAttack();
            int def    = player->getDefense();
            player->getInventory().useItem(idx - 1, hp, atk, def);

            player->setHp(hp);
            player->setAttack(atk);
            player->setDefense(def);
            break;
        }
        case 3:
            std::cout << player->getName() << " 이/가 도망쳤습니다!\n";
            return true; // 도망
        }
        return false; // 도망 아님
}

void BattleSystem::monsterTurn() {
    if (!monster->isAlive()) return;
    monster->attackTarget(*player);
    std::cout << monster->getName() << " 의 공격! "
              << player->getName() << " 에게 데미지!\n";
}

int BattleSystem::startBattle() { // 0: 패배, 1: 승리, 2: 도망
    std::cout << "\n== 전투 시작! " << monster->getName() << " 등장! ==\n";

    while (player->isAlive() && monster->isAlive()) {
        printBattleStatus();

        try {
            if (playerTurn()) return 2;
        } catch (const std::invalid_argument& e) {
            std::cout << e.what() << " 다시 입력하세요.\n";
            continue;
        } catch (const std::out_of_range& e) {
            std::cout << e.what() << "\n";
            continue;
        }

        // 도망 체크
        if (!monster->isAlive()) break;

        monsterTurn();
    }

    if (!player->isAlive()) {
        std::cout << "\n== 패배... ==\n";
        return 0;
    }
    if (!monster->isAlive()) {
        std::cout << "\n== 승리! ==\n";
        player->gainExp(monster->getExpReward());

        // 드롭 아이템 처리
        std::vector<Item> dropped = monster->drop();
        for (Item& item : dropped) {
            std::cout << item.getName() << " 을/를 획득했습니다!\n";
            player->getInventory().addItem(item);
        }
        return 1; // 승리
    }
    return 2; // 도망
}