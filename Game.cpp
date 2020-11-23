#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <exception> // Might include useless stuff as i copied this from another header, will delete later

#include "Hero.h"
#include "Monster.h"
#include "Map.h"
#include "Game.h"

Game::Game(){}

Game::Game(std::string map_file_path){
    Map incoming_map(map_file_path);
    map=incoming_map;
}

void Game::setMap(Map incoming_map)
{
    map = incoming_map;
}; // Set the map

void Game::putHero(Hero hero, int x, int y)
{
    //map gettel lekérdezni hogy az adott helyen van-e valami, ha igen akkor exception. Ha van már hero a mapon, exception.
}

void Game::putMonster(Monster monster, int x, int y)
{
    //map gettel lekérdezni hogy az adott helyen van-e valami, ha igen akkor exception. 
}

void Game::run()
{
/* Legyen egy

void Game::run();
fuggveny, mely levezenyli a jatekot, de dob egy Game::NotInitializedException-t, ha meg nincs beallitva terkep, vagy nincs Hero a palyan.  */

    while (true)
    {
        /* 
        A loop-ban north, south, east, west parancsokat var a stadard bemenetrol a program, amivel a Herot mozgatja, ha lehetseges (falra nem tud menni, palyarol nem lehet lemenni). 
        Ha olyan mezore lep a hero, ahol monsterek vannak, akkor azokkal megcsatazik. (A monsterekkel abban a sorrendben, ahogy a jatekhoz hozza lettek adva.)

        Ha a hosunk meghal, akkor egy The hero died. kimenettel veget er a loop, es ebben az esetben Addig nem lehet ujra elinditani, amig egy masik Herot fel nem pakolunk ra.
        */
    }
    
}