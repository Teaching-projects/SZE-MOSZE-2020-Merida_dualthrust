#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <exception>
#include <iostream>
#include <map>
#include <algorithm>
#include "Game.h"


Game::Game(std::string map_file_path)
{
    map = new Map(map_file_path);
}

Game::~Game()
{
    delete map;
}

void Game::setMap(Map* incoming_map)
{
    if (Game::anyMonstersAlive())
    {
        throw AlreadyHasUnitsException();
    }
    else
    {
        map = incoming_map;
    }
};

void Game::putHero(Hero *incoming_hero, int x, int y)
{
    if(hero != nullptr)
    {
        throw AlreadyHasHeroException();
    }
    
    if(map->get(x,y) == Map::type::Free)
    {
        hero = incoming_hero;
        map->setTile(x,y,2);
        hero->setPosition(x,y);
    }
    else
    {
        throw OccupiedException();
    }
}

bool Game::anyMonstersAlive()
{
    for( auto const& [key, val] : monster_map )
    {
        for( auto const& [key_2, val_2] : val )
        {
            if(val_2.size()>0)
            {
                return true;
            }
        }
    }
    return false;
}

void Game::putMonster(Monster *monster, int x, int y)
{
    if(map->get(x,y) != Map::type::Wall && map->get(x,y) != Map::type::Hero)
    {
        monster->setPosition(x,y);
        //We set the monsters pointer to a certain tile
        monster_map[x][y].push_back(*monster);

        //If there are MONSTERS on a certain tile we set its type to 4. If there were no monsters on the tile and now there will be ONE, we set it to 3.
        int tile = (monster_map[x][y].size()>1) ? 4 : 3;
        map->setTile(x,y,tile);
    }
    else
    {
        throw OccupiedException();
    }
}

void Game::run(bool is_test)
{
    std::vector<std::string> test_input;
    if(is_test)
    {
        std::ifstream f("test_input.txt");
        std::stringstream s;
		s << f.rdbuf();
		std::string fileContents = s.str();
		f.close();
        test_input=JSON::split(fileContents,'\n');
    }

    std::map<std::string, std::pair<int,int>> steps
    {
        {"north",   std::make_pair(-1,0)},
        {"east",    std::make_pair(0,1)},
        {"south",   std::make_pair(1,0)},
        {"west",    std::make_pair(0,-1)},
        {"w",   std::make_pair(-1,0)},
        {"d",    std::make_pair(0,1)},
        {"s",   std::make_pair(1,0)},
        {"a",    std::make_pair(0,-1)} // WASD controls are only here for local testing
    };

    if(hero && map)
    {

        while (hero->isAlive() && anyMonstersAlive())
        {
            map->drawMap();
            std::cout<<"[north] [east] [south] [west]\n"<<std::endl;
            std::cout<<"Choose a direction:"<<std::endl;

            //Takes the hero action - movement at the moment.
            std::string hero_action;
            if(is_test)
            {
                hero_action=test_input.front();
		        hero_action.erase(std::remove(hero_action.begin(), hero_action.end(), '\n'), hero_action.end());
                hero_action.erase(std::remove(hero_action.begin(), hero_action.end(), '\r'), hero_action.end());
                test_input.erase(test_input.begin());
            }
            else
            {
                std::getline(std::cin,hero_action);
            }
            //Sets the new position based on the hero's action.
            int new_x=hero->getPosition().first+steps[hero_action].first;
            int new_y=hero->getPosition().second+steps[hero_action].second;
            //Gets the type of the tile to which we wish to move.
            Map::type tile = map->get(new_x,new_y);

            if(tile!=Map::type::Wall)
            {

                if(tile==Map::type::Monster || tile==Map::type::Monsters)
                {
                    while (hero->isAlive() && !monster_map[new_x][new_y].empty())
                    {
                        std::cout 
                            << hero->getName() << "(" << hero->getLevel()<<")"
                            << " vs "
                            << monster_map[new_x][new_y].front().getName()
                            <<std::endl;
                        hero->fightTilDeath(monster_map[new_x][new_y].front());
                        if (!monster_map[new_x][new_y].front().isAlive()) monster_map[new_x][new_y].pop_front();

                    }

                }

                //We set the tile from which the hero moved to empty
                map->setTile(hero->getPosition().first,hero->getPosition().second,0);
                //Set the new hero position and update the map
                hero->setPosition(new_x, new_y);
                map->setTile(new_x,new_y,2);
            }
        }
        std::cout << (hero->isAlive() ? hero->getName() + " cleared the map." : "The hero died.") << std::endl;

        if(!hero->isAlive()){
            int tile = (monster_map[hero->getPosition().first][hero->getPosition().second].size()>1) ? 4 : 3;
            map->setTile(hero->getPosition().first,hero->getPosition().second,tile);
            hero = nullptr;

            std::string new_hero_path;
            std::cout<<"Please enter a path to a new Hero.json if you'd like to continue playing:\n[Or just press Enter to end the game]\n";
            std::getline(std::cin,new_hero_path);

            if(new_hero_path!="")
            {
                Hero new_hero{Hero::parse(new_hero_path)};
                putHero(&new_hero,1,1);
                Game::run(is_test); 
            }
        }
    }
    else
    {
        throw NotInitializedException();
    }
}