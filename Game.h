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
#include <exception> 
#include <list>
// Might include useless stuff as i copied this from another header, will delete later

#include "Hero.h"
#include "Map.h"
#include "Monster.h"
#include "Json.h"

class Game
{
 private:
    std::map<int,std::map<int, std::list<Monster>>> monster_map;
    Map* map=NULL; //Sets initial value to NULL
    Hero* hero=NULL; //Sets initial value to NULL
    /**
     * @brief Something here.
     * 
     * Something there
     * 
     * @return return 
     * 
     */
    void initMonsterMap();
    /**
     * @brief Something here.
     * 
     * Something there
     * 
     * @return return 
     * 
     */
    bool anyMonstersAlive();
 public:
    /**
     * @brief Constructor for a game with no map.
     * 
     * @return Game 
     * 
     */
    Game();
    /**
     * @brief Constructor for a game with a map initialized.
     * 
     * @param Name of the input file, from which the map is generated.
     * 
     * @return Game 
     * 
     */
    Game(std::string);
    /**
     * @brief Sets a map in a game with no map.
     * 
     * @param Takes a pointer to a map.
     * 
     */
    void setMap(Map*); // Set the map
    /**
     * @brief Puts a hero to a given - and valid - coordinate on a map - on a map with no heroes, in case there is already a hero there is an exception.
     * 
     * 
     * @param Pointer to a hero that has to be put somewhere.
     * @param X coordinate on the map.
     * @param Y coordinate on the map.
     * 
     */
    void putHero(Hero*, int, int);
    /**
     * @brief Puts a monster to a given - and valid - coordinate on a map. 
     * 
     * If a monster is already on a certain coordinate, the function will add the monster to the vector of monster(s) on the coordinate.
     * 
     */
    void putMonster(Monster*, int, int);
    /**
     * @brief Runs the game. Handles movement on the map, draws the map.
     *
     */
    void run(bool);

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
#endif // GAME_HEADER