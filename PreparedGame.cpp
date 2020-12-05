#include "Map.h"
#include <string>
#include <iostream>
#include "PreparedGame.h"

//WTF
Game::Game(){};

PreparedGame::PreparedGame(std::string path){ 
    JSON game_data = JSON::parseFromFile(path);

    if(game_data.count("map") && game_data.count("hero") && game_data.count("monster-1") && game_data.count("monster-2") && game_data.count("monster-3")){        
        map = new MarkedMap(game_data.get<std::string>("map"));
        Hero h = Hero::parse(game_data.get<std::string>("hero"));
        Monster monster_1 = Monster::parse(game_data.get<std::string>("monster-1"));
        Monster monster_2 = Monster::parse(game_data.get<std::string>("monster-2"));
        Monster monster_3 = Monster::parse(game_data.get<std::string>("monster-3"));
    }else{
        throw InsufficientGamedataInput();
    }
}