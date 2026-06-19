// 턴제 전투 로직 (공격·방어·도망·승패 처리)
#pragma once
#include "Character.h"
#include "Monster.h"

class BattleSystem {
private:
    Character* player;
    Monster* monster;

    void playerTurn();
    void monsterTurn();
    void printBattleStatus();

public:
    BattleSystem(Character* player, Monster* monster);
    ~BattleSystem();

    int startBattle();  // 0: 패배, 1: 승리, 2: 도망
};