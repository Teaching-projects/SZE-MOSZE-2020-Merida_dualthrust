/**
 * @file Game.h
 * @author LilikF
 * @brief Game class
 * 
 * This class contains methods used for controlling our game.
 * 
 * 
 * @version 2.0
 * @date 2020-12-08
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
#include "Hero.h"
#include "MarkedMap.h"
#include "Monster.h"
#include "JSON.h"
#include "Renderer.h"

class Game
{
 protected:
    /**
     * @brief "Map" that stores our monsters by location.
     * Each "tile" is represented by a list which holds the monsters on said tile.
     * 
     */
    std::map<int,std::map<int, std::list<Monster>>> monster_map; 

    /**
     * @brief Pointer to our map. Sets initial value to NULL.
     * 
     */
    Map* map=NULL;

    /**
     * @brief Pointer to our hero. Sets initial value to NULL.
     * 
     */
    Hero* hero=NULL;

    /**
     * @brief Checks if there are any monsters alive on the map
     * 
     * @return bool 
     * 
     */
    bool anyMonstersAlive(/**There's no input parameter here.*/);

    std::vector<Renderer *> renderers = std::vector<Renderer *>();
    void render();

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
     * @brief Copy constructor for the Game class
     * 
     */
    Game(const Game &g2) : monster_map(g2.monster_map),map(new Map(*g2.map)),hero(g2.hero),renderers(g2.renderers){} 

    Game & operator=(const Game& g2) {
        monster_map=g2.monster_map;
        setMap(g2.map);
        hero=g2.hero;
        renderers=g2.renderers;
        return *this;
    }

    /**
     * @brief Method for registering a renderer attached to a Game instance.
     * 
     */
    void registerRenderer(Renderer *renderer);

    Monster getMonsterByPosition(int col, int row) const{
        //.front()-ot használok, mert csak 1 szörny lehet 1 mezőn - LF
        return monster_map.at(col).at(row).front();
    }

    Map* getMap() const{return this->map;};
    Hero* getHero() const{return this->hero;};

    /**
     * @brief Constructor for a game with a map initialized.
     * 
     * @param MAPFILEPATH Name of the input file, from which the map is generated.
     * 
     * @return Game 
     * 
     */
    explicit Game(std::string);

    /**
     * @brief Sets a map in a game with no map.
     * 
     * @param INCOMINGMAP Takes a pointer to a map.
     * 
     */
    void setMap(Map*);
    
    /**
     * @brief Puts a hero to a given - and valid - coordinate on a map - on a map with no heroes, in case there is already a hero there is an exception.
     * 
     * @param Pointer to a hero that has to be put somewhere.
     * @param ROW coordinate on the map.
     * @param COLUMN coordinate on the map.
     * 
     */
    void putHero(Hero*, int, int);

    /**
     * @brief Puts a monster to a given - and valid - coordinate on a map. 
     * 
     * If a monster is already on a certain coordinate, the function will add the monster to the vector of monster(s) on the coordinate.
     * 
     * @param Pointer to a monster that has to be put somewhere.
     * @param ROW coordinate on the map.
     * @param COLUMN coordinate on the map.
     * 
     */
    virtual void putMonster(Monster, int, int);

    /**
     * @brief Runs the game. Handles movement on the map, draws the map.
     * @param IS_TEST. If the -test argument is used, we will take inputs from a file.
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