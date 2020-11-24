#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <exception> // Might include useless stuff as i copied this from another header, will delete later
#include <iostream>
#include <map>

#include "Game.h"

Game::Game(std::string map_file_path){
    map = new Map(map_file_path);
    
}

void Game::setMap(Map* incoming_map)
{
    map = incoming_map;
}; // Set the map

void Game::putHero(Hero *incoming_hero, int x, int y)
{
    //map gettel lekérdezni hogy az adott helyen van-e valami, ha igen akkor exception. Ha van már hero a mapon, exception.
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

void Game::putMonster(Monster *monster, int x, int y)
{
    //map gettel lekérdezni hogy az adott helyen van-e valami, ha igen akkor exception.
    if(map->get(x,y)==Map::type::Free){
        monsters_on_map.push_back(monster);
        
        //TODO: ha több szörny van, akkor 4-es type-ra állítani -> több szörnyre írni egy checket
        map->setTile(x,y,3);

        monster->setPosition(x,y);
    }else{
        throw OccupiedException();
    }
}

void Game::run()
{
/* Legyen egy

void Game::run();
fuggveny, mely levezenyli a jatekot, de dob egy Game::NotInitializedException-t, ha meg nincs beallitva terkep, vagy nincs Hero a palyan.  */
    std::map<std::string, std::pair<int,int>> steps{
        {"north",std::make_pair(-1,0)},
        {"east",std::make_pair(0,1)},
        {"south",std::make_pair(1,0)},
        {"west",std::make_pair(0,-1)}
    };


    if(hero && map){

        while (monsters_on_map.size() > 0 && hero->isAlive())
        {
            //Map kirajzolása
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

            if(tile==Map::type::Free || tile==Map::type::Monster || tile==Map::type::Monsters){
                //Ahonnan elépett a hero, az üres kell legyen -> ha szörny volt legyőzte, ha nem volt, üres volt
                //Visszaállítjuk a map adott mezőjét tehát üresre
                map->setTile(hero->getPosition().first,hero->getPosition().second,0);
                //Beállítjuk az új hero pozíciót és frissítjük a mapot is
                hero->setPosition(new_x, new_y);
                map->setTile(new_x,new_y,2);
            }

            /* 
            A loop-ban north, south, east, west parancsokat var a stadard bemenetrol a program, amivel a Herot mozgatja, ha lehetseges (falra nem tud menni, palyarol nem lehet lemenni). 
            Ha olyan mezore lep a hero, ahol monsterek vannak, akkor azokkal megcsatazik. (A monsterekkel abban a sorrendben, ahogy a jatekhoz hozza lettek adva.)

            Ha a hosunk meghal, akkor egy The hero died. kimenettel veget er a loop, es ebben az esetben Addig nem lehet ujra elinditani, amig egy masik Herot fel nem pakolunk ra.
            */
        }
    }else{
        throw NotInitializedException();
    }
}
