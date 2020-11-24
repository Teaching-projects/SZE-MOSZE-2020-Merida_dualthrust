/**
 * @file Game.h
 * @author NemesTom
 * @brief Game class
 * 
 * This class contains methods used for controlling our game.
 * 
 * 
 * @version 1.0
 * @date 2020-11-22
 * 
 */

#ifndef GAME_HEADER
#define GAME_HEADER

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <exception> // Might include useless stuff as i copied this from another header, will delete later

#include "Hero.h"
#include "Map.h"
#include "Monster.h"

class Game
{
 private:
    Map map;
    Hero* hero;
    std::vector<Monster*> monsters_on_map;
 public:
    Game(); // Empty Game
    Game(std::string); // Game with the Map initialized
    void setMap(Map); // Set the map
    void putHero(Hero, int, int);
    void putMonster(Monster, int, int);
    void run();

    class OccupiedException : std::exception
	{
		public:
            /**
             * @brief Falra nem kerulhet se Monster se Hero. Ugyanarra a szabad mezore azonban kerulhetnek egyszerre, akar tobb Monster is. 
             * @param key A hiba leirasa
            */
		    OccupiedException(){}
	};
    class AlreadyHasHeroException : std::exception
	{
		public:
            /**
             * @brief 
             * @param key A hiba leirasa A harmadikat akkor dobja, ha mar van beallitva hos, es egy masodikat tennenk fel. 
            */
		    AlreadyHasHeroException(){}
	};
    class AlreadyHasUnitsException : std::exception
	{
		public:
            /**
             * @brief 
             * @param key A hiba leirasa Az utolsot pedig akkor, ha terkepet allitanank at, de mar vannak a palyan egysegek. (Elotte akarhanyszor lecserelhetjuk.)

            */
		    AlreadyHasUnitsException(){}
	};
    
    class NotInitializedException : std::exception
	{
		public:
            /**
             * @brief 
             * @param key A hiba leirasa 
             * Legyen egy void Game::run(); fuggveny, mely levezenyli a jatekot, de dob egy Game::NotInitializedException-t, ha meg nincs beallitva terkep, vagy nincs Hero a palyan. 

            */
		    NotInitializedException(){}
	};
    
    class GameAlreadyStartedException : std::exception
	{
		public:
            /**
             * @brief 
             * @param key A hiba leirasa 
             * A loop sikeres elinditasa utan Hero, Map allitas mar nem tortenhet, azok Game::GameAlreadyStartedException-t dobnak. 
            */
		    GameAlreadyStartedException(){}
	};

};

    /* 
    
Ha minden rendben van, elindit egy loop-ot egeszen addig, amig van meg Monster eletben. 
Ha mindegyik monster le lett gyakva, akkor egy "{hero.name} cleared the map. uzenetet kiir, es befejezi a futast.

Monstert viszont barmikor lehet feltenni, es egy lefutott run() utan akar ujra is lehet inditani.

A loop-ban north, south, east, west parancsokat var a stadard bemenetrol a program, amivel a Herot mozgatja, ha lehetseges (falra nem tud menni, palyarol nem lehet lemenni). 
Ha olyan mezore lep a hero, ahol monsterek vannak, akkor azokkal megcsatazik. (A monsterekkel abban a sorrendben, ahogy a jatekhoz hozza lettek adva.)


Ha a hosunk meghal, akkor egy The hero died. kimenettel veget er a loop, es ebben az esetben Addig nem lehet ujra elinditani, amig egy masik Herot fel nem pakolunk ra.

Exceptions to implement for set and put methods.

Ha meg nincs terkep beallitva, akkor az elsot dobja a ket put. 

};
*/
#endif // GAME_HEADER