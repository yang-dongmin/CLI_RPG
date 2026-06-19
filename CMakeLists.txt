cmake_minimum_required(VERSION 3.10)  
project(rpg)                          
set(CMAKE_CXX_STANDARD 17)            

add_executable(rpg
    main.cpp
    Entity.cpp
    Character.cpp
    Monster.cpp
    Item.cpp
    Inventory.cpp
    BattleSystem.cpp
    SaveManager.cpp
    Game.cpp
)