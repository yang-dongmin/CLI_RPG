// 전체 게임 루프·흐름 제어 (메뉴·전투·이동)
#pragma once
#include "Character.h"
#include "Monster.h"
#include "BattleSystem.h"
#include "SaveManager.h"
#include <vector>
#include <string>

class Game {
private:
    Character* player;
    SaveManager saveManager;

    void mainMenu();
    void newGame();
    void loadGame();

    void gameLoop();
    void printStatus();
    void goAdventure();

    Character* createCharacter();
    Monster* createMonster();   // 랜덤 몬스터 생성

public:
    Game();
    ~Game();

    void run();
};