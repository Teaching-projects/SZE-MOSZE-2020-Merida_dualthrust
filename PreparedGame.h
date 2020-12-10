/**
 * @file PreparedGame.h
 * @author LilikF
 * @brief PreparedGame class
 * 
 * This class contains methods for initializing a game from a file.
 * 
 * @version 1.0
 * @date 2020-12-05
 * 
 */
#ifndef PREPAREDGAME_HEADER
#define PREPAREDGAME_HEADER

#include "Game.h"
#include "JSON.h"
#include "MarkedMap.h"
#include <string>

class PreparedGame : public Game
{
public:
    /**
     * @brief Constructor for empty Prepared Game object
     * 
     */
    PreparedGame();

    /**
     * @brief Destructor for Prepared Game object
     * 
     */
    ~PreparedGame();

    /**
     * @brief Constructor for filled Prepared Game object
     * 
     */
    explicit PreparedGame(std::string);

    class InsufficientGamedataInput : std::exception
	{
		public:
            /**
             * @brief The game cannot be initialized if the input json doesn't contain a map, a hero and at least one monster.
             * 
             */
		    InsufficientGamedataInput(/**There's no input parameter here.*/){}
	};

};
#endif
