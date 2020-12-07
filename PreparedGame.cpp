#include "Map.h"
#include <string>
#include <iostream>
#include "PreparedGame.h"
#include <fstream>

//WTF
Game::Game(){};

PreparedGame::~PreparedGame(){
    delete hero;
}

PreparedGame::PreparedGame(std::string path){ 
    JSON game_data = JSON::parseFromFile(path);

    if(game_data.count("map") && game_data.count("hero") && game_data.count("monster-1") && game_data.count("monster-2") && game_data.count("monster-3")){        
        map = new MarkedMap(game_data.get<std::string>("map"));
        Hero h = Hero::parse(game_data.get<std::string>("hero"));
        Monster monster_1 = Monster::parse(game_data.get<std::string>("monster-1"));
        Monster monster_2 = Monster::parse(game_data.get<std::string>("monster-2"));
        Monster monster_3 = Monster::parse(game_data.get<std::string>("monster-3"));

        std::ifstream mapfile(game_data.get<std::string>("map"));
        std::string line;
        int row = 0;
        while (std::getline(mapfile,line)){
          std::vector<int> map_row;
          
          for(unsigned int i=0;i<line.length();i++)
          {
              if(line[i] == 'H'){
                putHero(new Hero(h), row, i);
              }else if(line[i]=='1'){
                putMonster(new Monster(monster_1), row, i);
              }else if(line[i]=='2'){
                putMonster(new Monster(monster_2), row, i);
              }else if(line[i]=='3'){
                putMonster(new Monster(monster_2), row, i);
              }
          }
          row++;
        }

    }else{
        throw InsufficientGamedataInput();
    }
}