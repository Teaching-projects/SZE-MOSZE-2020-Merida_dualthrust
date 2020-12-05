/**
 * @file Game.h
 * @author LilikF
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
#include "MarkedMap.h"
#include "Monster.h"
#include "JSON.h"

class Game
{
 private:

    std::map<int,std::map<int, std::list<Monster>>> monster_map;

    Map* map=NULL; //Sets initial value to NULL

    Hero* hero=NULL; //Sets initial value to NULL
    /**
     * @brief Checks if there are any monsters alive on the map
     * 
     * @return bool 
     * 
     */
    bool anyMonstersAlive(/**There's no input parameter here.*/);
 public:
    /**
     * @brief Constructor for a game with no map.
     * 
     * @return Game 
     * 
     */
    Game(/**There's no input parameter here.*/);
    /**
     * @brief Destructor for a game object. Deletes the map, preventing a memory leak. 
     * 
     */
    ~Game();
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
             * @brief We may not place a unit - monster(s) or hero - on an invalid tile. 
             * 
            */
		    OccupiedException(/**There's no input parameter here.*/){}
	};
    class AlreadyHasHeroException : std::exception
	{
		public:
            /**
             * @brief If there is already a hero on the map, we may not place a second one on it.
             * 
            */
		    AlreadyHasHeroException(/**There's no input parameter here.*/){}
	};
    class AlreadyHasUnitsException : std::exception
	{
		public:
            /**
             * @brief If there are still units on the map, we may not set a new map.
             * 

            */
		    AlreadyHasUnitsException(/**There's no input parameter here.*/){}
	};
    
    class NotInitializedException : std::exception
	{
		public:
            /**
             * @brief If we have no map, or no hero on the map, we may not run the game.
             * 
             */
		    NotInitializedException(/**There's no input parameter here.*/){}
	};
    
    class GameAlreadyStartedException : std::exception
	{
		public:
            /**
             * @brief If the game is already running with a set map and hero, we may not set a new map or hero.
             * 
            */
		    GameAlreadyStartedException(/**There's no input parameter here.*/){}
	};

};
#endif // GAME_HEADER