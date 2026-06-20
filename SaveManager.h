// 게임 데이터 .txt 저장·불러오기
#pragma once
#include "Character.h"
#include <string>

class SaveManager {
private:
    std::string filePath;

public:
    SaveManager(const std::string& filePath = "save.txt");
    ~SaveManager();

    void save(Character& character);
    Character* load();
};