/**
 * @file PreparedGame.h
 * @author LilikF
 * @brief PreparedGame class
 * 
 * This class contains basic methods for handling our marked maps.
 * 
 * @version 1.0
 * @date 2020-12-05
 * 
 */
#ifndef PREPAREDGAME_HEADER
#define PREPAREDGAME_HEADER

#include "Game.h"
#include <string>

class PreparedGame : public Game
{
public:
    //Constructors, destructor
    PreparedGame(std::string);
    ~PreparedGame();

};
#endif
