#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <exception>
#include <iostream>
#include <map>

#include "Game.h"


Game::Game(std::string map_file_path){
    map = new Map(map_file_path);
    
}

void Game::setMap(Map* incoming_map)
{
    map = incoming_map;
};

void Game::putHero(Hero *incoming_hero, int x, int y)
{
    if(hero != nullptr){
        throw AlreadyHasHeroException();
    }
    
    if(map->get(x,y)==Map::type::Free){
        hero = incoming_hero;
        map->setTile(x,y,2);
        hero->setPosition(x,y);
    }else{
        throw OccupiedException();
    }
}

bool Game::anyMonstersAlive(){
    for( auto const& [key, val] : monster_map )
    {
        for( auto const& [key_2, val_2] : val ){
            if(val_2.size()>0){
                return true;
            }
        }
    }
    return false;
}

void Game::putMonster(Monster *monster, int x, int y)
{
    if(map->get(x,y)!=Map::type::Wall && map->get(x,y)!=Map::type::Hero){
        monster->setPosition(x,y);
        //Elrakjuk az adott mezőre a szörny pointerét
        monster_map[x][y].push_back(*monster);

        //ha több szörny van, akkor 4-es type-ra állítjuk a tile-t. Ha csak egy, akkor 3-as type
        int tile = (monster_map[x][y].size()>1) ? 4 : 3;
        map->setTile(x,y,tile);
    }else{
        throw OccupiedException();
    }
}

void Game::run()
{
    std::map<std::string, std::pair<int,int>> steps{
        {"north",std::make_pair(-1,0)},
        {"east",std::make_pair(0,1)},
        {"south",std::make_pair(1   ,0)},
        {"west",std::make_pair(0,-1)}
    };

    if(hero && map){

        while (hero->isAlive() && anyMonstersAlive())
        {
            //map kirajzolása
            map->drawMap();
            std::cout<<"[north] [east] [south] [west]\n"<<std::endl;
            std::cout<<"Choose a direction:"<<std::endl;

            //Hero action bekérése
            std::string hero_action;
            std::cin >> hero_action;
            
            //Új pozíció a lépés alapján
            int new_x=hero->getPosition().first+steps[hero_action].first;
            int new_y=hero->getPosition().second+steps[hero_action].second;
            //A map típusa azon a mezőn
            Map::type tile = map->get(new_x,new_y);

            if(tile!=Map::type::Wall){

                if(tile==Map::type::Monster || tile==Map::type::Monsters){
                    while (hero->isAlive() && !monster_map[new_x][new_y].empty()) {
                        std::cout 
                            << hero->getName() << "(" << hero->getLevel()<<")"
                            << " vs "
                            << monster_map[new_x][new_y].front().getName()
                            <<std::endl;
                        hero->fightTilDeath(monster_map[new_x][new_y].front());
                        if (!monster_map[new_x][new_y].front().isAlive()) monster_map[new_x][new_y].pop_front();
                    }

                }

                //Ahonnan elépett a hero, az üres kell legyen -> ha szörny volt legyőzte, ha nem volt, üres volt
                //Visszaállítjuk a map adott mezőjét tehát üresre
                map->setTile(hero->getPosition().first,hero->getPosition().second,0);
                //Beállítjuk az új hero pozíciót és frissítjük a mapot is
                hero->setPosition(new_x, new_y);
                map->setTile(new_x,new_y,2);
            }
        }
        std::cout << (hero->isAlive() ? "The hero won." : "The hero died.") << std::endl;
    }else{
        throw NotInitializedException();
    }
}
