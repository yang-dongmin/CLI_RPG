cmake_minimum_required(VERSION 3.10)  
project(rpg)                          
set(CMAKE_CXX_STANDARD 17)       

if(MSVC)
    add_compile_options(/utf-8)
endif()

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
add_executable(test
    test.cpp
    Entity.cpp
    Character.cpp
    Monster.cpp
    Item.cpp
    Inventory.cpp
    SaveManager.cpp
)