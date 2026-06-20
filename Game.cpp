#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

Game::Game() : player(nullptr), saveManager("save.txt") {
    srand(time(0));  // 랜덤 시드
}

Game::~Game() {
    delete player;
}

void Game::run() {
    std::cout << "================================\n";
    std::cout << "   [텍스트 RPG 전투 시뮬레이터]\n";
    std::cout << "================================\n";
    mainMenu();
}

void Game::mainMenu() {
    while (true) {
        std::cout << "\n1. 새 게임\n";
        std::cout << "2. 불러오기\n";
        std::cout << "3. 종료\n";
        std::cout << "선택: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: newGame();  break;
            case 2: loadGame(); break;
            case 3:
                std::cout << "게임을 종료합니다.\n";
                return;
            default:
                std::cout << "잘못된 입력입니다.\n";
        }
    }
}

void Game::newGame() {
    player = createCharacter();
    gameLoop();
}

void Game::loadGame() {
    player = saveManager.load();
    if (player == nullptr) {
        std::cout << "새 게임을 시작합니다.\n";
        player = createCharacter();
    }
    gameLoop();
}

Character* Game::createCharacter() {
    std::string name;
    std::cout << "캐릭터 이름을 입력하세요: ";
    std::cin >> name;

    std::cout << "\n직업을 선택하세요\n";
    std::cout << "1 : 전사  (HP 150 / ATK 20 / DEF 15)\n";
    std::cout << "2 : 마법사 (HP  90 / ATK 30 / DEF  5)\n";
    std::cout << "3 : 도적  (HP 100 / ATK 25 / DEF  8)\n";
    std::cout << "4 : 팔라딘 (HP 120 / ATK 18 / DEF 20)\n";
    std::cout << "선택: ";

    int choice;
    std::cin >> choice;

    Character* character = nullptr;
    switch (choice) {
        case 1:{
            character = new Warrior(name);  
            break;
        }
        case 2:{
            character = new Mage(name);
            break;
        }
        case 3:{
            character = new Rogue(name);
            break;
        }
        case 4:{
            character = new Paladin(name);
            break;
        }
        default:{
            std::cout << "잘못된 입력, 전사로 시작합니다.\n";
            character = new Warrior(name);
        }
    }

    std::cout << "\n" << name << " (" << character->getJobName() << ") 생성 완료!\n";
    return character;
}

Monster* Game::createMonster() {
    // 랜덤 몬스터 생성
    std::vector<Monster*> pool = {
        new Slime(),
        new Goblin(),
        new Orc(),
        new Dragon()
    };

    // 플레이어 레벨에 맞는 몬스터만 필터링
    int level = player->getLevel();
    std::vector<Monster*> filtered;
    for (int i = 0; i < pool.size(); i++)
    {
        if (pool[i]->getExpReward() <= level * 60)
        {
            filtered.push_back(pool[i]);
        }
    }

    if (filtered.empty()) filtered = pool;

    // 랜덤 선택
    Monster* selected = filtered[rand() % filtered.size()];

    // 드롭 아이템 등록
    selected->addDrop(Item("회복 포션",   ITEM_HEAL,    30));
    selected->addDrop(Item("공격력 물약", ITEM_ATTACK,  5));
    selected->addDrop(Item("방어력 물약", ITEM_DEFENSE, 5));

    // selected 제외하고 나머지 delete (메모리 누수 방지)
    for (Monster* m : pool) {
        if (m != selected) delete m;
    }

    return selected;
}

void Game::gameLoop() {
    while (player->isAlive()) {
        std::cout << "\n=== 메인 메뉴 ===\n";
        std::cout << "1. 모험 떠나기\n";
        std::cout << "2. 상태 확인\n";
        std::cout << "3. 저장\n";
        std::cout << "4. 메인 메뉴로\n";
        std::cout << "선택: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: goAdventure(); break;
            case 2: printStatus();  break;
            case 3:
                try {
                    saveManager.save(*player);
                } catch (const std::runtime_error& e) {
                    std::cout << e.what() << "\n";
                }
                break;
            case 4: return;
            default:
                std::cout << "잘못된 입력입니다.\n";
        }
    }

    std::cout << "\n=== 게임 오버 ===\n";
}

void Game::printStatus() {
    player->printStatus();
    player->getInventory().printInventory();
}

void Game::goAdventure() {
    Monster* monster = createMonster();
    BattleSystem battle(player, monster);

    int result = battle.startBattle();

    if (result == 0) {  // 패배 = 저장 X, 재도전 가능
        std::cout << "다시 도전하세요!\n";
    } else if (result == 1) {  // 승리
        std::cout << "전투 승리!\n";
        saveManager.save(*player); // 승리 시 저장

    } else {  // 도망
        std::cout << "도망쳤습니다!\n";
        saveManager.save(*player); // 도망 시 저장

    }
    delete monster;
}